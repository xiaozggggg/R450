#ifndef __WK_ST_LK_DEBUG_H__
#define __WK_ST_LK_DEBUG_H__

#include <VideoList.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sample_comm.h>
#include <sys_utils.h>
#include <pthread.h>

#include "sample_comm.h"
#include "sample_common_ive.h"
#include "wk_corner_info.h"


/* 建立vgs任务，进行图像绘点 */
td_s32 wk_st_lk_vgs_draw_ponits_send_venc_debug(ot_video_frame_info* _frame, wk_points_float_s* _points, td_u32 _points_num);

#endif /* __WK_ST_LK_DEBUG_H__ */
