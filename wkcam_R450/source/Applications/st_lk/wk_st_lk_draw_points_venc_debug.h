#ifndef __WK_ST_LK_DRAW_POINTS_VENC_DEBUG_H__
#define __WK_ST_LK_DRAW_POINTS_VENC_DEBUG_H__

#include <VideoList.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sample_comm.h>
#include <sys_utils.h>
#include <pthread.h>

#include <list>
#include "sample_comm.h"
#include "sample_common_ive.h"


/* 图像绘点 */
td_s32 wk_st_lk_vgs_draw_ponits_send_venc_debug(ot_video_frame_info* _frame, ot_svp_point_s25q7* _points, td_u32 _points_num);


#endif /* __WK_ST_LK_DRAW_POINTS_VENC_DEBUG_H__ */
