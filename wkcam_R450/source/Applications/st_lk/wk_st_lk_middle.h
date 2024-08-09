#ifndef __WK_ST_LK_MIDDLE_H__
#define __WK_ST_LK_MIDDLE_H__

#include <iostream>
#include <list>
#include <queue>
#include <mutex>
#include <memory>
#include <list>
#include <functional>
#include <sample_comm.h>

#include "wk_corner_info.h"
#include "wk_st_lk_mng.h"
#include "wk_st_lk_debug.h"


using namespace std; 


class wk_st_lk_middle
{
public:
	using wk_ptr = std::shared_ptr<wk_st_lk_middle>;
	static wk_st_lk_middle* wk_st_lk_get_instance();
	static td_s32 wk_st_lk_destroy_instance();
	~wk_st_lk_middle();


	/* 获取图像源分辨率 */
	td_bool wk_get_image_size(td_u16* _width, td_u16* _hight);
	
	/* 获取角度数量最大最小值 */
	td_bool wk_get_points_num_max_min(td_u16* _max, td_u16* _min);

	/* 注册获取图像帧回调 */
	td_bool wk_register_get_frame_cb(pfun_wk_get_frame_cb _cb);

	/* 恢复初始化状态 */
	td_s32 wk_corner_reinit();

	/* 设置识别角点参数 */
	td_bool wk_corner_recognize_set_param(td_u16 _quality_level, td_u16 _max_points_num, td_u16 _min_points_interval);
	
	/* 识别角点 */
	td_s32 wk_corner_recognize(wk_corner_video_frame_s::wk_ptr& _frame, wk_st_points_s::wk_ptr& _points);

	/* 设置跟踪角点参数 */
	td_bool wk_corner_track_set_param(td_u16 _min_eig_val, td_u16 _iter_cnt, td_u16 _eps);

	/* 跟踪角点 */
	td_s32 wk_corner_track(wk_lk_points_input_s::wk_ptr& _info, wk_lk_points_output_s::wk_ptr& _points);

	/* 输出算法执行结果 */
	td_bool wk_result_export(wk_location_result_s::wk_ptr& _result);


	/* 调试性代码,  将帧描点，并送入venc进行编码 */
	td_s32 wk_frame_pionts_venc_debug(wk_corner_video_frame_s::wk_ptr& _frame, ot_svp_point_s25q7* _points, td_u32 _points_num);

private:
	wk_st_lk_middle();
	wk_st_lk_middle(const wk_st_lk_middle&)=delete;
	wk_st_lk_middle& operator=(const wk_st_lk_middle&)=delete;
	
	static wk_st_lk_middle* instance;
};


#endif /* __WK_ST_LK_MIDDLE_H__ */
