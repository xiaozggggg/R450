#ifndef __WK_CORNER_INFO_H__
#define __WK_CORNER_INFO_H__

#include <iostream>
#include <memory>

#include "sample_comm.h"
#include "sample_common_ive.h"

using namespace std; 

typedef enum {
	WK_CORNER_POINTS_STATUS_INITIAL,         // 初始状态
	WK_CORNER_POINTS_STATUS_START_GET_POINTS,// 开始提取特征点状态
	WK_CORNER_POINTS_STATUS_GETTING_POINTS,  // 正在提取特征点状态
	WK_CORNER_POINTS_STATUS_PAUSE,           // 停止提取状态
	WK_CORNER_POINTS_STATUS_ERROR,           // 发生错误状态
	WK_CORNER_POINTS_STATUS_BUTT
}WK_CORNER_POINTS_STATUS_E;


/* 角点数据结构 */
struct wk_corner_points_s{
	using wk_ptr = std::shared_ptr<wk_corner_points_s>;
	td_bool isbegin;							// 是否识别的初始帧
	ot_svp_point_s25q7 prev_points[512];   	    // 保存上一帧输出的角点
	ot_svp_point_s25q7 curr_points[512];        // 保存当前帧输出角点
	td_u32	points_cnt;							// 角点数量
	td_u8 	status[512];                    	// 当前帧角点状态
	td_u9q7 err[512];	                    	// 当前帧已跟踪点的误差
};

/* 结果输出数据结构 */
struct wk_location_result_s{
	using wk_ptr = std::shared_ptr<wk_location_result_s>;
	
};


#endif /* __WK_CORNER_INFO_H__ */
