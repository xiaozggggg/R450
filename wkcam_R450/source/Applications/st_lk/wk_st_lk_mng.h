#ifndef __WK_ST_LK_MNG_H__
#define __WK_ST_LK_MNG_H__

#include <VideoList.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sample_comm.h>
#include <sys_utils.h>
#include <pthread.h>

#include <list>
#include "sample_comm.h"

#include "wk_corner_info.h"
#include "wk_ive_st_lk_interface.h"
#include "wk_st_lk_debug.h"


#ifdef __cplusplus
extern "C" {
#endif

/*****
*提供给算法中间层的接口
*****/

/* 开启光流功能处理 */
td_s32 wk_st_lk_start(ot_vpss_grp _grp, ot_vpss_chn _chn);

/* 关闭光流功能处理 */
td_s32 wk_st_lk_stop();

/* 获取图像源分辨率 */
td_bool wk_st_lk_get_image_resolution(td_u16* _width, td_u16* _hight);

/* 设置的最大最小角点数量 */
td_bool wk_st_lk_get_points_num_max_min(td_u16* _max, td_u16* _min);

/* 恢复初始状态处理 */
td_s32 wk_st_lk_status_inital_handle();

/* 算法注册回调 */
td_bool wk_st_lk_register_get_frame_cb(pfun_wk_get_frame_cb _cb);

/* 图像帧释放 */
td_bool wk_st_lk_frame_release(ot_video_frame_info* _frame);

/* 动态设置st参数 */
td_bool wk_st_set_ctrl_param(td_u16 _quality_level, td_u16 _max_points_num, td_u16 _min_points_interval);

/* 通过st取点处理 */
td_s32 wk_st_get_points(ot_video_frame_info *_frame, wk_st_points_s* _points);

/* 动态设置lk参数 */
td_bool wk_lk_set_ctrl_param(td_u16 _min_eig_val, td_u16 _iter_cnt, td_u16 _eps);

/* 通过lk取点处理*/
td_s32 wk_lk_get_points(wk_lk_points_input_s* _info, wk_lk_points_output_s* _points);




/* 协议处理函数 */
td_bool wk_st_lk_protocol_handle(wk_location_result_s* _result);


#ifdef __cplusplus
}
#endif




#endif /* __WK_ST_LK_MNG_H__ */
