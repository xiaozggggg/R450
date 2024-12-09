#include "wk_imu.h"

#define IMU_SYNC_PTS_CHEAK_TIME			(300)   // 同步时间戳间隔

#define SOCKET_HEADER_FIRST 			(0xAA)
#define SOCKET_HEADER_SEC  				(0x55)

typedef enum {
	WK_IMU_SOCKET_START_STOP_CMD  = 0x11,  // 开启/停止数据传输
	WK_IMU_SOCKET_SYNC_PTS_CMD    = 0x12,  // 时间同步
	WK_IMU_SOCKET_SENSER_DATA_CMD = 0x21,  // 传输传感器数据上报
	WK_IMU_SOCKET_MCU_DEBUG_CMD	  = 0x22,  // mcu端调试信息（仅用于mcu端调试）
	WK_IMU_SOCKET_CMD_BUTT,
}wk_imu_socket_cmd_e; 

typedef enum {
	WK_IMU_GYRO  = 0x01,
	WK_IMU_ACCEL = 0x02,
	WK_IMU_ELECT = 0x04,
}wk_imu_type_e;
	

typedef struct {
	/* 线程id */
	bool b_proc_running;
    pthread_t proc_id;

	pthread_mutex_t mutex;	
	std::list<wk_imu_data_s> imu_data;
}wk_imu_mng_s;

static wk_imu_mng_s imu_mng;


/* 数据发送接口 */
extern void CamSendHandle(char *buf, int size);
static td_s32 _wk_imu_socket_rw_send(td_u8* _data, td_u8 _length)
{
	CamSendHandle((char*)_data, _length);
	return TD_SUCCESS;
}

/* 求数据帧校验和 */
static td_u8 _wk_imu_socket_rw_checksum(td_u8* _data, td_u8 _length)
{
	td_u8 u8sum = 0;
	if(_data == NULL || _length <= 0) {
		WK_LOGE("_data is null");
		return 0;
	}

	for(td_u8 ifor=0; ifor<_length; ifor++) {
		u8sum += _data[ifor];
	}
	
	return u8sum;
}

/* 开始或停止传感器数据传输命令发送 */
td_s32 wk_imu_start_stop_cmd_send(td_bool bstart_gyro, td_bool bstart_accel, td_bool bstart_elect)
{
	td_s32 ret = -1;
	td_u8 u8tmp[32] = {0};
	td_u8* pdata = u8tmp;

	*pdata++ = SOCKET_HEADER_FIRST;
	*pdata++ = SOCKET_HEADER_SEC;
	*pdata++ = 0x02;
	*pdata++ = WK_IMU_SOCKET_START_STOP_CMD;
	*pdata |= bstart_gyro  ?  WK_IMU_GYRO  : 0;
	*pdata |= bstart_accel ?  WK_IMU_ACCEL : 0;
	*pdata |= bstart_elect ?  WK_IMU_ELECT : 0;
	pdata++;
	*pdata = _wk_imu_socket_rw_checksum(&u8tmp[2], 3);

	ret = _wk_imu_socket_rw_send(u8tmp, 6);
	if(ret < 0) {
		return ret;
	}

	return ret;
}

/* 发送时间戳同步 */
static td_s32 _wk_imu_sync_pts_cmd_send(td_u64 _pts)
{
	td_s32 ret = -1;
	td_u8 u8tmp[32] = {0};
	td_u8* pdata = u8tmp;
	static td_u8 tmp_cnt = 0;

	*pdata++ = SOCKET_HEADER_FIRST;
	*pdata++ = SOCKET_HEADER_SEC;
	*pdata++ = 0x09;
	*pdata++ = WK_IMU_SOCKET_SYNC_PTS_CMD;
	memcpy(pdata, &_pts, sizeof(td_u64));
	pdata += 8;
	*pdata = _wk_imu_socket_rw_checksum(&u8tmp[2], sizeof(td_u64)+2);

	ret = _wk_imu_socket_rw_send(u8tmp, sizeof(td_u64) + 5);
	if(ret < 0) {
		return ret;
	}
	
	return 0;
}


/* 定时时间同步时间戳 */
td_s32 wk_imu_socket_sync_pts()
{
	td_u64 cur_pts_us;
	static td_u64 u32last_time = 0;
	
	td_u32 currtime = system_time_ms_get();
	if(get_delta_time(currtime, u32last_time) >= IMU_SYNC_PTS_CHEAK_TIME){
		u32last_time = currtime;
		ss_mpi_sys_get_cur_pts(&cur_pts_us);
		_wk_imu_sync_pts_cmd_send(cur_pts_us/1000);
	}
	
	return 0;
}

/* 写入imu传感器数据 */
td_s32 wk_imu_push_data(td_float* _imu_data, td_u8 _size, td_u64 _pts)
{
	wk_imu_mng_s* pmng = &imu_mng;
	struct wk_imu_data_s data;

	if(pmng->b_proc_running == TD_FALSE){
		return TD_SUCCESS;
	}

	if(_size != 6) {
		WK_LOGE("imu_data size must 6\n");
		return TD_FAILURE;
	}

	/* 转换后角速度单位：rad/s(弧度每秒) */
	data.gyro_x = _imu_data[0];
	data.gyro_y = _imu_data[1];
	data.gyro_z = _imu_data[2];

	/* 加速度单位：m/s² */
	data.accel_x = _imu_data[3]/100.0;
	data.accel_y = _imu_data[4]/100.0;
	data.accel_z = _imu_data[5]/100.0;
	data.u64pts  = _pts*1000; 	

	//WK_LOGD("gyro -- %f\t%f\t%f\t accel ---- %f\t%f\t%f   ----  %ld\n", 
	//		data.gyro_x, data.gyro_y, data.gyro_z, data.accel_x, data.accel_y, data.accel_z,data.u64pts);

	/* 送入链表 */
	pthread_mutex_lock(&pmng->mutex);
	pmng->imu_data.push_back(data);
	pthread_mutex_unlock(&pmng->mutex);
	
	return TD_SUCCESS;
}


/* imu数据处理线程 */
static void * _wk_imu_data_handle(void* _pArgs)
{
	wk_imu_mng_s* pmng = (wk_imu_mng_s*)_pArgs;

	while(pmng->b_proc_running == TD_TRUE) {
		while(!pmng->imu_data.empty()) {
			/* 链表数据回调 */
			wk_imu_data_s data = pmng->imu_data.front();
			wk_imu_middle::wk_imu_get_instance()->wk_imu_data_reported(data);
		
			pthread_mutex_lock(&pmng->mutex);
			pmng->imu_data.pop_front();
			pthread_mutex_unlock(&pmng->mutex);
		}

		/* 时间同步 */
		wk_imu_socket_sync_pts();
		usleep(10*1000);
	}
	return NULL;
}


/* imu数据获取功能开启 */
td_s32 wk_imu_rev_start()
{
	td_s32 ret = -1;
	wk_imu_mng_s* pmng = &imu_mng;

	if(pmng->b_proc_running == TD_TRUE) {
		WK_LOGI("imu rev reinit\n");
		return TD_SUCCESS;
	}

	ret = pthread_mutex_init(&pmng->mutex, NULL);
	if(ret != 0) {
		WK_LOGE("ret is %d\n", ret);
		goto exit0;
	}

	std::list<wk_imu_data_s>().swap(pmng->imu_data);
	pmng->b_proc_running = TD_TRUE;
	ret = pthread_create(&pmng->proc_id, NULL, _wk_imu_data_handle, pmng);
    if (ret != 0) {
        WK_LOGE("initial _wk_imu_resend_handle thread error\r\n");
		goto exit1;
    }	

	return TD_SUCCESS;
exit1:
	pthread_mutex_destroy(&pmng->mutex);
	pmng->b_proc_running = TD_FALSE;
exit0:	
	return TD_FAILURE;	
}

/* imu数据获取功能停止 */
td_s32 wk_imu_rev_stop()
{
	td_s32 ret = -1;
	wk_imu_mng_s* pmng = &imu_mng;

	pmng->b_proc_running = TD_FALSE;
	if(pmng->proc_id != 0){
		ret = pthread_join(pmng->proc_id, NULL);
	    if (ret != 0) {
	        WK_LOGE("join _wk_imu_resend_handle thread error\r\n");
	        return -1;
	    }			
		pmng->proc_id = 0;
	}	

	pthread_mutex_destroy(&pmng->mutex);
	std::list<wk_imu_data_s>().swap(pmng->imu_data);
	return 0;
}



