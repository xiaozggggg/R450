#include "wk_imu.h"

#define IMU_SYNC_PTS_CHEAK_TIME			(300)   // 同步时间戳间隔
#define WK_IMU_GYRO_FILIER				(30)	// gyro低通录波参数
#define WK_IMU_ACCEL_FILIER				(200)   // accel低通录波参数

typedef struct {
	td_bool init_flag;

	/* 线程id */
	bool b_proc_running;
    pthread_t proc_id;

	std::list<wk_imu_socket_cmd_e> cmd_list;
}wk_imu_info_s;

static wk_imu_info_s imu_info;

static void _wk_socket_reported_callback(wk_imu_socket_cmd_reply_data_s* _reply_data);


#ifdef DEBUG_SAVE_IMU_FRAME
/*========== 用于标定的调试性代码 =================*/
#define WK_IMU_SAVE_FILE_PATH	"/mnt/sdcard/imu/"
#define WK_IMU_SAVE_FILE_NAME	"imu.csv"
#define WK_IMU_FILE_HANDLE		"#timestamp [ns],w_RS_S_x [rad s^-1],w_RS_S_y [rad s^-1],w_RS_S_z [rad s^-1],a_RS_S_x [m s^-2],a_RS_S_y [m s^-2],a_RS_S_z [m s^-2],cur_pts[ns],pts_diff[ms]\n"

typedef struct {
	pthread_t proc_id;
	pthread_mutex_t mutex;
	
	FILE *pfd;
	td_bool b_save_imu;	/* imu是否保存标志 */

	std::list<wk_imu_data_s> imu_list;
}wk_save_imu_mng;

static wk_save_imu_mng g_simu_mng;

static void * _wk_list_save_imu_in_file(void* _pArgs) 
{
	td_char tmp_cmd[256] = {0};
	wk_save_imu_mng* pmng = &g_simu_mng;
	while(1) {
		while(!pmng->imu_list.empty())
		{
			pthread_mutex_lock(&pmng->mutex);
			wk_imu_data_s data = pmng->imu_list.front();
			pmng->imu_list.pop_front();
			pthread_mutex_unlock(&pmng->mutex);
			
			memset(tmp_cmd, 0, sizeof(tmp_cmd));
			sprintf(tmp_cmd, "%ld,%f,%f,%f,%f,%f,%f,%ld,%d\n",
								data.u64pts*1000, 
								data.gyro_x, data.gyro_y, data.gyro_z,
								data.accel_x, data.accel_y, data.accel_z,
								data.u64curr_pts, (data.u64curr_pts-data.u64pts)/1000);		

			static td_u32 u32cnt = 0;
			if(u32cnt++>1000){
				printf("list_size = %d ---- save imu: %d ----- %s",  pmng->imu_list.size(), strlen(tmp_cmd), tmp_cmd);
				u32cnt = 0;
			}

			fwrite(&tmp_cmd[0], strlen(tmp_cmd), 1, pmng->pfd);
		}
		fflush(pmng->pfd);	
		usleep(20*1000);
	}	
	
	return NULL;
}


td_s32 wk_imu_to_file_enable(td_bool _enalbe)
{	
	td_char tmp_cmd[256] = {0};
	wk_save_imu_mng* pmng = &g_simu_mng;

	if(_enalbe == TD_FAILURE){
		return 0;
	}
	
	/* 判断有无sd卡，无则返回错误 */
#if 0													
	if(_enalbe == TD_TRUE) {
		if(0 != access("/dev/mmcblk0p1", F_OK)) {
			WK_LOGE("No SD card found!\n");
			return TD_FAILURE;
		}
	}

	if(false == is_dir_exist(WK_IMU_SAVE_FILE_PATH)) {
		sprintf(tmp_cmd, "mkdir %s", WK_IMU_SAVE_FILE_PATH);
		system(tmp_cmd);
	}
#endif

	
	if(_enalbe == TD_TRUE){
		pmng->pfd = fopen("./imu.csv", "a+");
		fwrite(WK_IMU_FILE_HANDLE, strlen(WK_IMU_FILE_HANDLE), 1, pmng->pfd);
		fflush(pmng->pfd);
	}

	pthread_mutex_init(&pmng->mutex, NULL);
	std::list<wk_imu_data_s>().swap(pmng->imu_list);
	pthread_create(&pmng->proc_id, NULL, _wk_list_save_imu_in_file, NULL);

	pmng->b_save_imu = _enalbe;
	return TD_SUCCESS;
}

/* 将图像保存为png图，仅调试用于标定使用 */
static td_s32 wk_imu_data_to_in_list(struct wk_imu_data_s* _data)
{
	wk_save_imu_mng* pmng = &g_simu_mng;
	pthread_mutex_lock(&pmng->mutex);
	pmng->imu_list.push_back(*_data);
	pthread_mutex_unlock(&pmng->mutex);

	return TD_SUCCESS; 
}
/*========== 用于标定的调试性代码 end=================*/
#endif


/* 发送开始上报指令 */
static td_s32 _wk_imu_socket_send_start()
{
	wk_imu_socket_cmd_start_stop_s start_reported;
	start_reported.bstart_gyro = true;
	start_reported.bstart_accel = true;
	start_reported.bstart_elect = false;	
	return wk_imu_start_stop_cmd_send(&start_reported, _wk_socket_reported_callback);
}


/* 定时时间同步时间戳 */
static td_s32 _wk_imu_socket_sync_pts()
{
	td_u64 cur_pts_us;
	wk_imu_socket_cmd_sync_pts_s sync_pts;
	static td_u64 u32last_time = 0;
	
	td_u32 currtime = system_time_ms_get();
	if(get_delta_time(currtime, u32last_time) >= IMU_SYNC_PTS_CHEAK_TIME){
		u32last_time = currtime;
		ss_mpi_sys_get_cur_pts(&cur_pts_us);
		sync_pts.u64pts = cur_pts_us/1000;	 // us->ms
		wk_imu_sync_pts_cmd_send(&sync_pts, NULL);
	}
	
	return 0;
}

/* 处理送入陀螺仪传感器数据 */
static td_s32 _wk_imu_gyro_accel_handle(wk_imu_socket_cmd_reply_data_s* _reply_data)
{
	struct wk_imu_data_s data;

	/* 转换后角速度单位：rad/s(弧度每秒) */
	data.gyro_x = _reply_data->st_imu_data.gyro_x;
	data.gyro_y = _reply_data->st_imu_data.gyro_y;
	data.gyro_z = _reply_data->st_imu_data.gyro_z;

	/* 加速度单位：m/s² */
	data.accel_x = _reply_data->st_imu_data.accel_x/100.0;
	data.accel_y = _reply_data->st_imu_data.accel_y/100.0;
	data.accel_z = _reply_data->st_imu_data.accel_z/100.0;
	data.u64pts = _reply_data->st_imu_data.u64pts*1000; 	
	ss_mpi_sys_get_cur_pts(&data.u64curr_pts);


	//WK_LOGD("gyro -- %f\t%f\t%f\t accel ---- %f\t%f\t%f   ----  %ld\n", 
	//		data.gyro_x, data.gyro_y, data.gyro_z, data.accel_x, data.accel_y, data.accel_z,data.u64pts);

	#ifdef DEBUG_SAVE_IMU_FRAME
	#if 0
	static td_u32 diff_cnt=0;
	if(diff_cnt < (data.u64curr_pts-data.u64pts)/1000){
		diff_cnt = (data.u64curr_pts-data.u64pts)/1000;
		WK_LOGI("----- diff_cnt = %d\n", diff_cnt);
	}
	#endif
	if(g_simu_mng.b_save_imu == TD_TRUE) {
		wk_imu_data_to_in_list(&data);
	}
	#endif

	/* 使用单例进行回调 */
	wk_imu_middle::wk_imu_get_instance()->wk_imu_data_reported(data);
	
	return TD_SUCCESS;
}

/* 串口读取回调 */
static void _wk_socket_reported_callback(wk_imu_socket_cmd_reply_data_s* _reply_data)
{
	wk_imu_info_s* pmng = &imu_info;

	if(_reply_data->e_cmd == WK_IMU_SOCKET_START_STOP_CMD) {
		/* 该命令暂无使用，目前设计收到时间同步就会开始发送imu数据 */
		//if(_reply_data->e_result != WK_IMU_SOCKET_ERR_CODE_SUCCESS) {
		//	WK_LOGD("imu socket start error, result = %d. resend cmd.\n", _reply_data->e_result);
		//	pmng->cmd_list.push_back(_reply_data->e_cmd);
		//}
	}
	else if(_reply_data->e_cmd == WK_IMU_SOCKET_SYNC_PTS_CMD) {
		if(_reply_data->e_result != WK_IMU_SOCKET_ERR_CODE_SUCCESS) {
			WK_LOGD("imu socket start error, result = %d. resend cmd.\n", _reply_data->e_result);
			pmng->cmd_list.push_back(_reply_data->e_cmd);
		}
	}
	else if(_reply_data->e_cmd == WK_IMU_SOCKET_SENSER_DATA_CMD) {
		_wk_imu_gyro_accel_handle(_reply_data);
	}

	return;
}

/* 重发单次线程 */
static void * _wk_imu_resend_handle(void* _pArgs)
{
	wk_imu_info_s* pmng = (wk_imu_info_s*)_pArgs;

	while(pmng->b_proc_running == true) {
		_wk_imu_socket_sync_pts();
		
		while(!pmng->cmd_list.empty()) {
			wk_imu_socket_cmd_e cmd = pmng->cmd_list.front();
			if(cmd == WK_IMU_SOCKET_START_STOP_CMD) {
				_wk_imu_socket_send_start();
			}	
			else if(cmd == WK_IMU_SOCKET_SYNC_PTS_CMD) {
				_wk_imu_socket_sync_pts();
			}
			pmng->cmd_list.pop_front();
		}
		usleep(20*1000);
	}
	return NULL;
}

/* imu数据获取功能开启 */
td_s32 wk_imu_rev_start()
{
	td_s32 ret = -1;
	wk_imu_info_s* pmng = &imu_info;

	if(pmng->init_flag == TD_TRUE) {
		WK_LOGI("imu rev reinit\n");
		return TD_SUCCESS;
	}

	/* imu接收socket初始化 */
	ret = wk_imu_socket_init(NULL);
	if(ret < 0) {
		return -1;
	}
	wk_imu_socket_register_imu_data_cb(_wk_socket_reported_callback);	

	std::list<wk_imu_socket_cmd_e>().swap(pmng->cmd_list);
	pmng->b_proc_running = true;
	ret = pthread_create(&pmng->proc_id, NULL, _wk_imu_resend_handle, pmng);
    if (ret != 0) {
        WK_LOGE("initial _wk_imu_resend_handle thread error\r\n");
        goto create_thread_err;
    }	
	
	/* 通知开始发送传感器数据 */
	//usleep(100*1000); 
	//_wk_imu_socket_send_start();    

	pmng->init_flag = TD_TRUE;

	return TD_SUCCESS;
	
create_thread_err:
	wk_imu_socket_deinit();
	return 0;
}

/* imu数据获取功能停止 */
td_s32 wk_imu_rev_stop()
{
	td_s32 ret = -1;
	wk_imu_info_s* pmng = &imu_info;

	pmng->b_proc_running = false;
	if(pmng->proc_id != 0){
		ret = pthread_join(pmng->proc_id, NULL);
	    if (ret != 0) {
	        WK_LOGE("join _wk_imu_resend_handle thread error\r\n");
	        return -1;
	    }			
		pmng->proc_id = 0;
	}	
	
	std::list<wk_imu_socket_cmd_e>().swap(pmng->cmd_list);

	wk_imu_socket_deinit();
	
	pmng->init_flag = TD_FALSE;
	return 0;
}



