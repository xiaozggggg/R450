
#include "wk_st_lk_get_frame.h"

#include "sample_comm.h"
#include "sample_common_ive.h"
#include "wk_ive_st_lk_interface.h"
#include "wk_st_lk_frame_handle.h"

/* 文件主要实现：
1. 从vpss中获取流数据，并通过回调方式，将当前帧回调到特征点提取层
*/


/* 线程函数 */
static void * _wk_st_lk_get_frame_proc(void* _pArgs) 
{
	wk_st_lk_get_frame_mng_s* pmng = (wk_st_lk_get_frame_mng_s*)_pArgs;
	ot_video_frame_info st_frame_info;
	td_s32 ret = TD_SUCCESS;

	sleep(3);
	while(pmng->b_proc_running == true) {
		memset(&st_frame_info, 0, sizeof(st_frame_info));

		ret = ss_mpi_vpss_get_chn_frame(pmng->grp, pmng->chn, &st_frame_info, 1000);
		if(ret != TD_SUCCESS) {
			printf("OT_MPI_VPSS_GetChnFrame grp:%d chn:%d err:0x%x\n", pmng->grp,  pmng->chn, ret);
			usleep(5*1000);
			continue;
		}

		if(pmng->get_frame_callback != NULL) {
			pmng->get_frame_callback(&st_frame_info);
		}
		
		ss_mpi_vpss_release_chn_frame(pmng->grp, pmng->chn, &st_frame_info);
		usleep(5*1000);
	}

	return NULL;
}


/* 取流初始化 */
td_s32 wk_st_lk_get_frame_init(wk_st_lk_get_frame_mng_s* _infor)
{
	td_s32 ret = -1;

	if(_infor->b_proc_running == true){
		printf("info: st_lk get frame is ready started\n");
		return 0;
	}

	_infor->b_proc_running = true;
	ret = pthread_create(&_infor->proc_id, NULL, _wk_st_lk_get_frame_proc, _infor);
    if (ret != 0) {
        printf("err: initial wk_st_lk_get_frame_init thread error, %d\r\n", ret);
        return ret;
    }	

	printf("info: wk_st_lk_get_frame_init ok!\n");
	return 0;
}


/* 取流去初始化 */
td_s32 wk_st_lk_get_frame_deinit(wk_st_lk_get_frame_mng_s* _infor)
{
	td_s32 ret = -1;
	
	if(_infor->b_proc_running == false){
		return 0;
	}

	_infor->get_frame_callback = NULL;

	_infor->b_proc_running = false;
	if(_infor->proc_id != 0){
		ret = pthread_join(_infor->proc_id, NULL);
	    if (ret != 0) {
	        printf("err: join _wk_st_lk_get_frame_proc thread error\r\n");
	        return -1;
	    }			
		_infor->proc_id = 0;
	}

	printf("info: wk_st_lk_get_frame_deinit ok!\n");
	return 0;
}

