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

#include "wk_corner_info.h"
#include "wk_st_lk_corner.h"
#include "wk_st_lk_debug.h"
#include "wk_ive_st_lk_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****
*提供给应用层的接口
*****/

/* 开启光流功能处理 */
td_s32 wk_st_lk_start(ot_vpss_grp _grp, ot_vpss_chn _chn);

/* 关闭光流功能处理 */
td_s32 wk_st_lk_stop();



/*****
*提供给算法中间层接口
*****/
/* 获取图像源分辨率 */
td_bool wk_st_lk_get_image_resolution(td_u16* _width, td_u16* _hight);

/* 设置的最大最小角点数量 */
td_bool wk_st_lk_get_points_num_max_min(td_u16* _max, td_u16* _min);

/* 设置和获取当前st lk处理的状态 */
td_bool wk_st_lk_set_status(WK_CORNER_POINTS_STATUS_E _status);
WK_CORNER_POINTS_STATUS_E wk_st_lk_get_status();

/* 协议处理函数 */
td_bool wk_st_lk_protocol_handle(wk_location_result_s* _result);


#ifdef __cplusplus
}
#endif




#endif /* __WK_ST_LK_APP_H__ */
