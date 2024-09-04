#include "wk_imu.h"

#define IMU_SYNC_PTS_CHEAK_TIME			(300)   // 同步时间戳间隔
#define WK_IMU_GYRO_FILIER				(30)	// gyro低通录波参数
#define WK_IMU_ACCEL_FILIER				(200)   // accel低通录波参数

static td_s16 g_fgyro_filter[3];
static td_s16 g_faccel_filter[3];

static void _wk_socket_reported_callback(wk_imu_socket_cmd_reply_data_s* _reply_data);


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

/* 低通滤波 */
td_s16 lowpass_filter(td_s16 *_lpf,td_s16 _raw_data, float _dt, td_u32 _frequency)
{
	*_lpf = *_lpf + (_dt/( (1.0f/ ( 2 * 3.14f * _frequency))+_dt))*(_raw_data - *_lpf);
	return *_lpf;
}


/* 处理送入陀螺仪传感器数据 */
static td_s32 _wk_imu_gyro_accel_handle(wk_imu_socket_cmd_reply_data_s* _reply_data)
{
	struct wk_imu_data_s data;
	volatile td_s16 gyro_x, gyro_y, gyro_z, accel_x, accel_y, accel_z;

	/* imu加速度量程±16g 陀螺仪量程±2000 */
	memset(&data, 0, sizeof(wk_imu_data_s));
	gyro_x = (td_s16)lowpass_filter(&g_fgyro_filter[0], (td_s16)_reply_data->st_imu_data.s16gyro_x, 0.0001f, WK_IMU_GYRO_FILIER);
	data.gyro_x = (td_float)gyro_x/16.4/57.3;
	gyro_y = (td_s16)lowpass_filter(&g_fgyro_filter[1], (td_s16)_reply_data->st_imu_data.s16gyro_y, 0.0001f, WK_IMU_GYRO_FILIER);
	data.gyro_y = (td_float)gyro_y/16.4/57.3;
	gyro_z = (td_s16)lowpass_filter(&g_fgyro_filter[2], (td_s16)_reply_data->st_imu_data.s16gyro_z, 0.0001f, WK_IMU_GYRO_FILIER);
	data.gyro_z = (td_float)gyro_z/16.4/57.3;

	accel_x = (td_s16)lowpass_filter(&g_faccel_filter[0], (td_s16)_reply_data->st_imu_data.s16accel_x, 0.0001f, WK_IMU_ACCEL_FILIER);
	data.accel_x = (td_float)accel_x/2048*9.8;
	accel_y = (td_s16)lowpass_filter(&g_faccel_filter[1], (td_s16)_reply_data->st_imu_data.s16accel_y, 0.0001f, WK_IMU_ACCEL_FILIER);
	data.accel_y = (td_float)accel_y/2048*9.8;
	accel_z = (td_s16)lowpass_filter(&g_faccel_filter[2], (td_s16)_reply_data->st_imu_data.s16accel_z, 0.0001f, WK_IMU_ACCEL_FILIER);
	data.accel_z = (td_float)accel_z/2048*9.8;
					
	data.u64pts = _reply_data->st_imu_data.u64pts*1000; 	

	WK_LOGD("gyro -- %#02x\t%#02x\t%#02x\t accel ---- %#02x\t%#02x\t%#02x   ----  %#02x\n", 
			_reply_data->st_imu_data.s16gyro_x, _reply_data->st_imu_data.s16gyro_y, _reply_data->st_imu_data.s16gyro_z, 
			_reply_data->st_imu_data.s16accel_x, _reply_data->st_imu_data.s16accel_y, _reply_data->st_imu_data.s16accel_z,
			_reply_data->st_imu_data.u64pts);

	WK_LOGD("gyro -- %#02x\t%#02x\t%#02x\t accel ---- %#02x\t%#02x\t%#02x   ----  %#02x\n",
			gyro_x, gyro_y, gyro_z, accel_x, accel_y, accel_z, data.u64pts);		

	//WK_LOGD("gyro -- %f\t%f\t%f\t accel ---- %f\t%f\t%f   ----  %ld\n", 
	//		data.gyro_x, data.gyro_y, data.gyro_z, data.accel_x, data.accel_y, data.accel_z,data.u64pts);

	/* 使用单例进行回调 */
	wk_imu_middle::wk_imu_get_instance()->wk_imu_data_reported(data);
	
	return TD_SUCCESS;
}

/* 重发单次线程 */
static void * _wk_imu_resend_proc_once(void* _pArgs) 
{
	pthread_detach(pthread_self());
	
	td_u8* args = (td_u8*)_pArgs;
	const td_u8* start_cmd = (td_u8*)WK_IMU_SOCKET_START_STOP_CMD;
	const td_u8* pts_cmd = (td_u8*)WK_IMU_SOCKET_SYNC_PTS_CMD;

	if(args == start_cmd) {
		_wk_imu_socket_send_start();
	}	
	else if(args == pts_cmd) {
		_wk_imu_socket_sync_pts();
	}

	return NULL;
}

/* 创建单次发送线程 */
static void _wk_imu_create_once_resend_thread(wk_imu_socket_cmd_e _cmd)
{
	pthread_t thread_id;
	pthread_create(&thread_id, NULL, _wk_imu_resend_proc_once, (void*)_cmd);
	return;
}


/* 串口读取回调 */
static void _wk_socket_reported_callback(wk_imu_socket_cmd_reply_data_s* _reply_data)
{
	if(_reply_data->e_cmd == WK_IMU_SOCKET_START_STOP_CMD) {
		/* 该命令暂无使用，目前设计收到时间同步就会开始发送imu数据 */
		//if(_reply_data->e_result != WK_IMU_SOCKET_ERR_CODE_SUCCESS) {
		//	WK_LOGD("imu socket start error, result = %d. resend cmd.\n", _reply_data->e_result);
		//	_wk_imu_create_once_resend_thread(_reply_data->e_cmd);
		//}
	}
	else if(_reply_data->e_cmd == WK_IMU_SOCKET_SYNC_PTS_CMD) {
		if(_reply_data->e_result != WK_IMU_SOCKET_ERR_CODE_SUCCESS) {
			WK_LOGD("imu socket start error, result = %d. resend cmd.\n", _reply_data->e_result);
			_wk_imu_create_once_resend_thread(_reply_data->e_cmd);
		}
	}
	else if(_reply_data->e_cmd == WK_IMU_SOCKET_SENSER_DATA_CMD) {
		_wk_imu_gyro_accel_handle(_reply_data);
	}

	return;
}


/* 应用注册到socket管理的回调，在mng线程中调用 */
static void _wk_imu_register_in_socket_callback()
{
	_wk_imu_socket_sync_pts(); /* 时间同步改在datalink实现 */
	return;
}

/* imu数据获取功能开启 */
td_s32 wk_imu_rev_start()
{
	td_s32 ret = -1;

	/* imu接收socket初始化 */
	ret = wk_imu_socket_init(_wk_imu_register_in_socket_callback);
	if(ret < 0) {
		return -1;
	}
	wk_imu_socket_register_imu_data_cb(_wk_socket_reported_callback);	

	/* 通知开始发送传感器数据 */
	//usleep(100*1000); 
	//_wk_imu_socket_send_start();    

	return 0;
}

/* imu数据获取功能停止 */
td_s32 wk_imu_rev_stop()
{
	wk_imu_socket_deinit();
	return 0;
}



