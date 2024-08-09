#ifndef __WK_CORNER_INFO_H__
#define __WK_CORNER_INFO_H__

#include <iostream>
#include <memory>

#include "sample_comm.h"
#include "sample_common_ive.h"

using namespace std; 


/* 图像数据结构 */
class wk_corner_video_frame_s {
public:
	using wk_ptr = std::shared_ptr<wk_corner_video_frame_s>;

	ot_vpss_grp grp;
	ot_vpss_chn chn;
	wk_corner_video_frame_s() {
		pts = 0;
		grp = chn = -1;
	}
	
	~wk_corner_video_frame_s() {
		ss_mpi_vpss_release_chn_frame(grp, chn, &frame);
	}
		
	ot_video_frame_info frame;					// 图像帧
	td_u64 pts;									// 时间戳
};


/* 识别角点数据结构 */
struct wk_st_points_s{
	using wk_ptr = std::shared_ptr<wk_st_points_s>;

	ot_svp_point_s25q7 points[500];        		// 帧角点
	td_u32	points_cnt;							// 角点数量
};


/* 跟综角点输入数据结构 */
struct wk_lk_points_input_s{
	using wk_ptr = std::shared_ptr<wk_lk_points_input_s>;

	ot_video_frame_info* prev_frame;			// 前图像帧
	ot_svp_point_s25q7 prev_points[500];        // 前帧角点
	td_u32	points_cnt;							// 角点数量

	ot_video_frame_info* curr_frame;			// 当前图像帧
};


/* 跟综角点输出数据结构 */
struct wk_lk_points_output_s{
	using wk_ptr = std::shared_ptr<wk_lk_points_output_s>;

	ot_svp_point_s25q7 prev_points[500];   	    // 前帧角点
	ot_svp_point_s25q7 curr_points[500];        // 当前帧角点
	td_u32	points_cnt;							// 角点数量
	td_u8 	status[500];                    	// 当前帧角点状态
	td_u9q7 err[500];	                    	// 当前帧已跟踪点的误差
};

/* 结果输出数据结构 */
struct wk_location_result_s{
	using wk_ptr = std::shared_ptr<wk_location_result_s>;



};

typedef void (*pfun_wk_get_frame_cb)(wk_corner_video_frame_s::wk_ptr);

#endif /* __WK_CORNER_INFO_H__ */
