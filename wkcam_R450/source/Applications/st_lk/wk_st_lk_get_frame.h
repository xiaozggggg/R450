
#ifndef __WK_ST_LK_GET_FRAME__
#define __WK_ST_LK_GET_FRAME__

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <list>
#include <map>
#include <sys_utils.h>

#include "sample_comm.h"


/* 取流回调 */
typedef void (*wk_st_lk_get_frame_cb)(ot_video_frame_info *_frame);

typedef struct {
	/* 线程id */
	bool b_proc_running;
    pthread_t proc_id;

	/* vpss信息 */
	ot_vpss_grp grp;
	ot_vpss_chn chn;

	/* 取流回调 */
	wk_st_lk_get_frame_cb get_frame_callback;
}wk_st_lk_get_frame_mng_s;


/* 取流初始化 */
td_s32 wk_st_lk_get_frame_init(wk_st_lk_get_frame_mng_s* _infor);

/* 取流去初始化 */
td_s32 wk_st_lk_get_frame_deinit(wk_st_lk_get_frame_mng_s* _infor);


#endif /* __WK_ST_LK_GET_FRAME__ */

