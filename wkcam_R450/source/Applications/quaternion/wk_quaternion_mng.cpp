#include "wk_quaternion_mng.h"


typedef struct {
	/* 线程id */
	bool b_proc_running;
    pthread_t proc_id;

	pthread_mutex_t mutex;	
	std::list<wk_quaternion_data_s> q_data;
}wk_quaternion_info_s;

static wk_quaternion_info_s q_info;


/* 添加四元素数据 */
td_s32 wk_quaternion_push_data(td_float q0, td_float q1, td_float q2, td_float q3, td_u64 pts)
{
	wk_quaternion_info_s* pmng = &q_info;
	wk_quaternion_data_s data;

	if(pmng->b_proc_running == TD_FALSE){
		return TD_SUCCESS;
	}

	data.q[0] = q0;
	data.q[1] = q1;
	data.q[2] = q2;
	data.q[3] = q3;
	data.u64pts = pts*1000;

	pthread_mutex_lock(&pmng->mutex);
	pmng->q_data.push_back(data);
	pthread_mutex_unlock(&pmng->mutex);
	
	return TD_SUCCESS;
}


static void * _wk_quaternion_handle(void* _pArgs)
{
	wk_quaternion_info_s* pmng = (wk_quaternion_info_s*)_pArgs;

	while(pmng->b_proc_running == TD_TRUE) {
		while(!pmng->q_data.empty()) {
			/* 链表数据回调 */
			wk_quaternion_data_s data = pmng->q_data.front();
			wk_quaternion_middle::wk_quaternion_get_instance()->wk_quaternion_data_reported(data);
		
			pthread_mutex_lock(&pmng->mutex);
			pmng->q_data.pop_front();
			pthread_mutex_unlock(&pmng->mutex);
		}
		usleep(10*1000);
	}
	return NULL;
}

/* 四元素数据获取功能开启 */
td_s32 wk_quaternion_start()
{
	td_s32 ret = -1;
	wk_quaternion_info_s* pmng = &q_info;

	if(pmng->b_proc_running == TD_TRUE) {
		WK_LOGI("quaternion rev reinit\n");
		return TD_SUCCESS;
	}

	ret = pthread_mutex_init(&pmng->mutex, NULL);
	if(ret != 0) {
		WK_LOGE("ret is %d\n", ret);
		goto exit0;
	}

	std::list<wk_quaternion_data_s>().swap(pmng->q_data);
	pmng->b_proc_running = TD_TRUE;
	ret = pthread_create(&pmng->proc_id, NULL, _wk_quaternion_handle, pmng);
    if (ret != 0) {
        WK_LOGE("initial _wk_quaternion_handle thread error\r\n");
        goto exit1;
    }	
	   
	return TD_SUCCESS;

exit1:
	pthread_mutex_destroy(&pmng->mutex);
	pmng->b_proc_running = TD_FALSE;
exit0:	
	return TD_FAILURE;
}

/* 四元素数据获取功能停止 */
td_s32 wk_quaternion_stop()
{
	td_s32 ret = -1;
	wk_quaternion_info_s* pmng = &q_info;

	pmng->b_proc_running = TD_FALSE;
	if(pmng->proc_id != 0){
		ret = pthread_join(pmng->proc_id, NULL);
	    if (ret != 0) {
	        WK_LOGE("join _wk_quaternion_handle thread error\r\n");
	        return -1;
	    }			
		pmng->proc_id = 0;
	}	

	pthread_mutex_destroy(&pmng->mutex);
	std::list<wk_quaternion_data_s>().swap(pmng->q_data);
	return TD_SUCCESS;
}



