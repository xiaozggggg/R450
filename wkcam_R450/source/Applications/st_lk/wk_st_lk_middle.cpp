/*************************************************************************************
*	brief: 该代码用于为算法层提供中间层接口
*	主要实现：
**************************************************************************************/

#include "wk_st_lk_middle.h"




wk_st_lk_middle* wk_st_lk_middle::instance = nullptr;


wk_st_lk_middle::wk_st_lk_middle()
{
	
}

wk_st_lk_middle::~wk_st_lk_middle()
{
	
}

wk_st_lk_middle* wk_st_lk_middle::wk_st_lk_get_instance()
{
	td_s32 u32ret;
	
	if(instance == nullptr) {
		instance = new wk_st_lk_middle();

		u32ret = wk_st_lk_start(0, WK_VIDEO_CHANNEL_PREVIEW);
		if(u32ret != TD_SUCCESS) {
			WK_LOGE("err: wk_st_lk_start error!\n");
			return nullptr;
		}
	}

	return instance;
}

td_s32 wk_st_lk_middle::wk_st_lk_destroy_instance()
{
	td_s32 u32ret;

	if(instance) { 
		delete instance; 
		instance = nullptr;

		u32ret = wk_st_lk_stop();
		if(u32ret != TD_SUCCESS) {
			WK_LOGE("err: wk_st_lk_stop error!\n");
		}		
	} 
	
	return TD_SUCCESS;
}


td_bool wk_st_lk_middle::wk_get_image_size(ot_size* _sensor_size)
{
	return wk_st_lk_get_image_resolution(_sensor_size);
}

td_bool wk_st_lk_middle::wk_get_points_num_max_min(td_u16* _max, td_u16* _min)
{
	return wk_st_lk_get_points_num_max_min(_max, _min);
}

td_bool wk_st_lk_middle::wk_register_get_frame_cb(pfun_wk_get_frame_cb _cb)
{
	return wk_st_lk_register_get_frame_cb(_cb);
}

td_s32 wk_st_lk_middle::wk_corner_reinit()
{
	return wk_st_lk_status_inital_handle();
}

td_bool wk_st_lk_middle::wk_corner_recognize_set_param(td_u16 _quality_level, 
																td_u16 _max_points_num,
																td_u16 _min_points_interval) {
	return wk_st_set_ctrl_param(_quality_level, _max_points_num, _min_points_interval);
}

td_s32 wk_st_lk_middle::wk_corner_recognize(wk_corner_video_frame_s::wk_ptr& _frame, wk_st_points_s::wk_ptr& _points)
{
	return wk_st_get_points(&_frame->frame, _points.get());
}

td_bool wk_st_lk_middle::wk_corner_track_set_param(td_u16 _min_eig_val, td_u16 _iter_cnt, td_u16 _eps)
{
	return wk_lk_set_ctrl_param(_min_eig_val, _iter_cnt, _eps);
}

td_s32 wk_st_lk_middle::wk_corner_track(wk_lk_points_input_s::wk_ptr& _info, wk_lk_points_output_s::wk_ptr& _points)
{
	return wk_lk_get_points(_info.get(), _points.get());
}

td_s32 wk_st_lk_middle::wk_frame_pionts_venc_debug(wk_corner_video_frame_s::wk_ptr& _frame, ot_svp_point_s25q7* _points, td_u32 _points_num)
{
	#ifdef DEBUG_ST_LK_POINTS_PREVIEW
	wk_st_lk_vgs_draw_ponits_send_venc_debug(&_frame->frame, _points, _points_num);
	#endif 
	return TD_SUCCESS;
}

td_s32 wk_st_lk_middle::wk_log_mat(cv::Mat _mat)
{
	td_char* str = NULL, *tmp = NULL;
	std::vector<cv::Mat> mv;

	if(_mat.channels() > 1){
		cv::split(_mat, mv); 
	}
	
	tmp = str = (td_char*)malloc(4*1024);
	for(td_u32 kfor=0; kfor<_mat.channels(); kfor++)
	{
		for(td_u32 ifor=0; ifor<mv[kfor].cols; ifor++)
		{
			for(td_u32 jfor=0; jfor<mv[kfor].rows; jfor++)
			{
				switch (_mat.type())
				{
					case CV_8UC1:
					case CV_8UC2:
					case CV_8UC3:
					case CV_8UC4:
						str += sprintf(str, "%d ", mv[kfor].at<unsigned char>(ifor, jfor));
						break;
					case CV_8SC1:
					case CV_8SC2:
					case CV_8SC3:
					case CV_8SC4:
						str += sprintf(str, "%d ", mv[kfor].at<char>(ifor, jfor));
						break;
					case CV_16UC1:
					case CV_16UC2:
					case CV_16UC3:
					case CV_16UC4:
						str += sprintf(str, "%d ", mv[kfor].at<unsigned short>(ifor, jfor));
						break;
					case CV_16SC1:
					case CV_16SC2:
					case CV_16SC3:
					case CV_16SC4:
						str += sprintf(str, "%d ", mv[kfor].at<short>(ifor, jfor));
						break;
					case CV_32SC1:
					case CV_32SC2:
					case CV_32SC3:
					case CV_32SC4:
						str += sprintf(str, "%d ", mv[kfor].at<int>(ifor, jfor));
						break;
					case CV_32FC1:
					case CV_32FC2:
					case CV_32FC3:
					case CV_32FC4:
						str += sprintf(str, "%.2f ", mv[kfor].at<float>(ifor, jfor));
						break;
					case CV_64FC1:
					case CV_64FC2:
					case CV_64FC3:
					case CV_64FC4:
						str += sprintf(str, "%.2f ", mv[kfor].at<double>(ifor, jfor));
						break;
				}
			}
			*str = '\n';
			str++;
		}
		str += sprintf(str, "%s", "---------------\n");
	}
	*str = '\0'; 
	
	WK_LOGD("Mat -- rows = %d, cols = %d\n%s", _mat.rows, _mat.cols, tmp);
	
	free(tmp);
	return TD_SUCCESS;
}



td_bool wk_st_lk_middle::wk_result_export(wk_location_result_s::wk_ptr& _result)
{
	return wk_st_lk_protocol_handle(_result.get());
}

