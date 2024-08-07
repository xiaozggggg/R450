#ifndef __WK_CORNER_COMMON_H__
#define __WK_CORNER_COMMON_H__

#include <iostream>
#include <list>
#include <queue>
#include <mutex>
#include <memory>
#include <list>
#include <functional>

#include <sample_comm.h>

#include "wk_corner_info.h"

using namespace std; 


class wk_corner_points
{

public:
    virtual ~wk_corner_points();

	/* 设置、获取角点数据 */
	td_s32 wk_corner_points_list_push(wk_corner_points_s* _points);
	wk_corner_points_s::wk_ptr wk_corner_points_list_front();
	td_s32 wk_corner_points_list_get_size();
	td_s32 wk_corner_points_list_clear();

	/* 获取图像源分辨率 */
	virtual td_bool wk_corner_points_get_image_size(td_u16* _width, td_u16* _hight)=0;
	/* 获取角度数量最大最小值 */
	virtual td_bool wk_corner_points_get_points_num_max_min(td_u16* _max, td_u16* _min)=0;
	/* 设置、获取控制st lk工作状态 */
	virtual td_bool wk_corner_points_set_status(WK_CORNER_POINTS_STATUS_E _status)=0;
	virtual WK_CORNER_POINTS_STATUS_E wk_corner_points_get_status()=0;
	/* 输出算法执行结果 */
	virtual td_bool wk_corner_points_result_export(wk_location_result_s* _result)=0;
	
protected:
	wk_corner_points();

	std::list<wk_corner_points_s::wk_ptr> corner;
	std::mutex mtx;
};

#endif /* __WK_CORNER_COMMON_H__ */
