/*************************************************************************************
*	brief: 该代码用于为算法层提供中间层接口
*	主要实现：
**************************************************************************************/

#include "wk_st_lk_corner.h"




wk_st_lk_corner_points* wk_st_lk_corner_points::instance = nullptr;


wk_st_lk_corner_points::wk_st_lk_corner_points()
{
	
}

wk_st_lk_corner_points::~wk_st_lk_corner_points()
{
	
}

wk_st_lk_corner_points* wk_st_lk_corner_points::wk_st_lk_corner_point_get_instance()
{
	if(instance==nullptr) {
		instance = new wk_st_lk_corner_points();
	}
	return instance;
}

td_s32 wk_st_lk_corner_points::wk_st_lk_corner_points_destroy_instance()
{
	if(instance) { 
		delete instance; 
	} 

	instance = nullptr;
	return TD_SUCCESS;
}


td_bool wk_st_lk_corner_points::wk_corner_points_get_image_size(td_u16* _width, td_u16* _hight)
{
	return wk_st_lk_get_image_resolution(_width, _hight);
}

td_bool wk_st_lk_corner_points::wk_corner_points_get_points_num_max_min(td_u16* _max, td_u16* _min)
{
	return wk_st_lk_get_points_num_max_min(_max, _min);
}

td_bool wk_st_lk_corner_points::wk_corner_points_set_status(WK_CORNER_POINTS_STATUS_E _status)
{
	if(_status == WK_CORNER_POINTS_STATUS_START_GET_POINTS || 
		_status == WK_CORNER_POINTS_STATUS_INITIAL) {
		wk_corner_points_list_clear();
	}
	else if(_status == WK_CORNER_POINTS_STATUS_PAUSE){
		
	}
	else{
		printf("status(%d) not allowed to set");
	}
	return wk_st_lk_set_status(_status);
}

WK_CORNER_POINTS_STATUS_E wk_st_lk_corner_points::wk_corner_points_get_status()
{
	return wk_st_lk_get_status();
}

td_bool wk_st_lk_corner_points::wk_corner_points_result_export(wk_location_result_s* _result)
{
	return wk_st_lk_protocol_handle(_result);
}

