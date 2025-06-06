#ifndef __WK_CORNER_INFO_H__
#define __WK_CORNER_INFO_H__

#include <iostream>
#include <memory>
#include <functional>

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
		if(grp != -1 && chn != -1){
			ss_mpi_vpss_release_chn_frame(grp, chn, &frame);
		}	
	}
		
	ot_video_frame_info frame;					// 图像帧
	td_u64 pts;									// 时间戳
	td_u32 ave_lum;								// 图像亮度
};

/* 浮点坐标值 */
struct wk_points_float_s{
	td_float x;
	td_float y;
};


/* 识别角点数据结构 */
struct wk_st_points_s{
	using wk_ptr = std::shared_ptr<wk_st_points_s>;

	wk_points_float_s points[500];        		// 帧角点
	td_u32	points_cnt;							// 角点数量
};


/* 跟综角点输入数据结构 */
struct wk_lk_points_input_s{
	using wk_ptr = std::shared_ptr<wk_lk_points_input_s>;

	ot_video_frame_info* prev_frame;			// 前图像帧
	wk_points_float_s prev_points[500];       	// 前帧角点
	td_u32	points_cnt;							// 角点数量

	ot_video_frame_info* curr_frame;			// 当前图像帧
};


/* 跟综角点输出数据结构 */
struct wk_lk_points_output_s{
	using wk_ptr = std::shared_ptr<wk_lk_points_output_s>;

	wk_points_float_s prev_points[500];   	    // 前帧角点
	wk_points_float_s curr_points[500];        	// 当前帧角点
	td_u32	points_cnt;							// 角点数量
	td_u8 	status[500];                    	// 当前帧角点状态
	td_float err[500];	                    	// 当前帧已跟踪点的误差
};

/* 结果输出数据结构 */
struct wk_location_result_s{
	using wk_ptr = std::shared_ptr<wk_location_result_s>;

	/* 四元素+平移 */
	td_float x;
	td_float y;
	td_float z;
	td_float q[4];

	td_u16 corner_num;							/* 有效角点数 */
	wk_corner_video_frame_s::wk_ptr frame;  	/* 帧数据 */
};

//typedef void (*pfun_wk_get_frame_cb)(wk_corner_video_frame_s::wk_ptr);
typedef std::function<void(wk_corner_video_frame_s::wk_ptr)> pfun_wk_get_frame_cb;



class wk_corner_points
{

public:
	using wk_ptr = std::shared_ptr<wk_corner_points>;
    virtual ~wk_corner_points();

	virtual td_bool wk_get_image_size(ot_size* _sensor_size)=0;
	virtual td_bool wk_get_points_num_max_min(td_u16* _max, td_u16* _min)=0;
	virtual td_bool wk_register_get_frame_cb(pfun_wk_get_frame_cb _cb)=0;
	virtual td_s32 wk_corner_reinit()=0;
	virtual td_bool wk_corner_recognize_set_param(td_u16 _quality_level, td_u16 _max_points_num, td_u16 _min_points_interval)=0;
	virtual td_s32 wk_corner_recognize(wk_corner_video_frame_s::wk_ptr& _frame, wk_st_points_s::wk_ptr& _points)=0;
	virtual td_bool wk_corner_track_set_param(td_u16 _min_eig_val, td_u16 _iter_cnt, td_u16 _eps)=0;
	virtual td_s32 wk_corner_track(wk_lk_points_input_s::wk_ptr& _info, wk_lk_points_output_s::wk_ptr& _points)=0;
	virtual td_bool wk_result_export(wk_location_result_s::wk_ptr& _result)=0;
	virtual td_s32 wk_frame_pionts_venc_debug(wk_corner_video_frame_s::wk_ptr& _frame, wk_points_float_s* _points, td_u32 _points_num)=0;
	
protected:
	wk_corner_points();
};



#endif /* __WK_CORNER_INFO_H__ */
