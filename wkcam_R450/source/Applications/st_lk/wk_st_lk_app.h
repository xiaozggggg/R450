#ifndef __WK_ST_LK_APP_H__
#define __WK_ST_LK_APP_H__

#include <VideoList.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sample_comm.h>
#include <sys_utils.h>
#include <pthread.h>

#include <list>
#include "sample_comm.h"

#include "wk_st_lk_get_frame.h"
#include "wk_st_lk_frame_handle.h"

#ifdef __cplusplus
extern "C" {
#endif

/* 开启光流功能处理 */
td_s32 wk_st_lk_app_start(ot_vpss_grp _grp, ot_vpss_chn _chn);


/* 关闭光流功能处理 */
td_s32 wk_st_lk_app_stop();


#ifdef __cplusplus
}
#endif

#endif /* __WK_ST_LK_APP_H__ */
