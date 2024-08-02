#ifndef __WK_ST_LK_FRAME_HANDLE_H__
#define __WK_ST_LK_FRAME_HANDLE_H__

#include <VideoList.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sample_comm.h>
#include <sys_utils.h>
#include <pthread.h>

#include "sample_comm.h"
#include "sample_common_ive.h"
#include "wk_ive_st_lk_interface.h"


typedef enum {
	WK_ST_LK_HANDLE_STATUS_INITIAL,        // 初始状态
	WK_ST_LK_HANDLE_STATUS_ST_GET_POINTS,  // st提取特征点状态
	WK_ST_LK_HANDLE_STATUS_LK_GET_POINTS,  // lk提取特征点状态
	WK_ST_LK_HANDLE_STATUS_PAUSE,          // 停止状态
	WK_ST_LK_HANDLE_STATUS_ERROR,          // 发生错误状态
	WK_ST_LK_HANDLE_STATUS_BUTT
}WK_ST_LK_HANDLE_STATUS_E;



/* 光流识别特征点处理初始化 */
td_s32 wk_st_lk_frame_handle_init(wk_ive_st_lk_param* _param);

/* 光流识别特征点处理去初始化 */
td_s32 wk_st_lk_frame_handle_deinit();

/* 设置状态 */
td_s32 wk_st_lk_set_status(WK_ST_LK_HANDLE_STATUS_E _status);

/* 获取点处理，需要考虑状态机 */
void wk_st_lk_get_frame_handle(ot_video_frame_info *_frame);


#endif /* __WK_ST_LK_FRAME_HANDLE_H__ */
