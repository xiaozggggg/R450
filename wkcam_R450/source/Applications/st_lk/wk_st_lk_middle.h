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
#include "wk_log.h"
#include "core.hpp"

using namespace std; 


class wk_st_lk_middle : public wk_corner_points
{
public:
	using wk_ptr = std::shared_ptr<wk_st_lk_middle>;
	static wk_st_lk_middle* wk_st_lk_get_instance();
	static td_s32 wk_st_lk_destroy_instance();
	~wk_st_lk_middle();

	/**
	 * @brief 获取图像源分辨率
	 * 
	 * @param _ive_size		输出参数，识别和跟踪角点，图像使用的分辨率
	 * @param _sensor_size	输出参数，sensor输出的图像的分辨率
	 */
	td_bool wk_get_image_size(ot_size* _sensor_size);

	/**
	 * @brief 获取角度数量最大最小值
	 * 
	 * @param _max	输出参数，当前设置的角点数量最大值
	 * @param _min	输出参数，当前设置的角点数量最小值
	 */
	td_bool wk_get_points_num_max_min(td_u16* _max, td_u16* _min);

	/**
	 * @brief 注册获取图像帧回调
	 * 
	 * @param _cb	图像回调
	 */
	td_bool wk_register_get_frame_cb(pfun_wk_get_frame_cb _cb);

	/**
	 * @brief 恢复初始化状态
	 */
	td_s32 wk_corner_reinit();

	/**
	 * @brief 设置识别角点参数
	 * 
	 * @param _quality_level		角点质量控制参数
	 * @param _max_points_num 		最大角点数量
	 * @param _min_points_interval	相邻角点最小距离
	 */
	td_bool wk_corner_recognize_set_param(td_u16 _quality_level, td_u16 _max_points_num, td_u16 _min_points_interval);

	/**
	 * @brief 识别角点
	 * 
	 * @param _frame		图像帧
	 * @param _points 		输出参数，识别的角点
	 */	
	td_s32 wk_corner_recognize(wk_corner_video_frame_s::wk_ptr& _frame, wk_st_points_s::wk_ptr& _points);

	/**
	 * @brief 设置跟踪角点参数
	 * 
	 * @param _min_eig_val		最小特征阈值
	 * @param _iter_cnt 		最大迭代次数
	 * @param _eps 				迭代收敛条件
	 */
	td_bool wk_corner_track_set_param(td_u16 _min_eig_val, td_u16 _iter_cnt, td_u16 _eps);

	/**
	 * @brief 跟踪角点
	 * 
	 * @param _info		输入图像和角点信息
	 * @param _points 	输出参数，跟踪的角点结果
	 */
	td_s32 wk_corner_track(wk_lk_points_input_s::wk_ptr& _info, wk_lk_points_output_s::wk_ptr& _points);

	/**
	 * @brief 输出算法执行结果
	 * 
	 * @param _result	算法输出结果
	 */
	td_bool wk_result_export(wk_location_result_s::wk_ptr& _result);


	/**
	 * @brief 打印mat
	 */
	td_s32 wk_log_mat(cv::Mat _mat);

	/**
	 * @brief 调试性代码,  将帧描点，并送入venc进行编码
	 * 
	 * @param _frame		图像帧
	 * @param _points		描绘的角点
	 * @param _points_num	角点个数
	 */
	td_s32 wk_frame_pionts_venc_debug(wk_corner_video_frame_s::wk_ptr& _frame, ot_svp_point_s25q7* _points, td_u32 _points_num);

private:
	wk_st_lk_middle();
	wk_st_lk_middle(const wk_st_lk_middle&)=delete;
	wk_st_lk_middle& operator=(const wk_st_lk_middle&)=delete;
	
	static wk_st_lk_middle* instance;
};


#endif /* __WK_ST_LK_MIDDLE_H__ */
