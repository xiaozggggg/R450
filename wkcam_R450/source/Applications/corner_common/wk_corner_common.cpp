#include "wk_corner_common.h"


wk_corner_points::wk_corner_points()
{

}

wk_corner_points::~wk_corner_points()
{
	std::list<wk_corner_points_s::wk_ptr>().swap(corner);
}

/* 将角点数据写入list */
td_s32 wk_corner_points::wk_corner_points_list_push(wk_corner_points_s* _points)
{
	std::lock_guard<std::mutex> lock(mtx);
	
	wk_corner_points_s::wk_ptr pcorner(new wk_corner_points_s);
	*pcorner = *_points;
	corner.push_back(pcorner);
	
	return corner.size();

}

/* 获取角点数据 */
wk_corner_points_s::wk_ptr wk_corner_points::wk_corner_points_list_front()
{
	std::lock_guard<std::mutex> lock(mtx);
	wk_corner_points_s::wk_ptr pcorner = nullptr;
	
	if(corner.size() == 0) {
		return pcorner;
	}

	pcorner = corner.front();
	corner.pop_front();
	return pcorner;
}

/* 当前list大小 */
td_s32 wk_corner_points::wk_corner_points_list_get_size()
{
	return corner.size();
}


td_s32 wk_corner_points::wk_corner_points_list_clear()
{
	std::lock_guard<std::mutex> lock(mtx);
	std::list<wk_corner_points_s::wk_ptr>().swap(corner);
	return TD_SUCCESS;
}






