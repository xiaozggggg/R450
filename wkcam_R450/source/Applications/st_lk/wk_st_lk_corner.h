#ifndef __WK_ST_LK_CORNER_H__
#define __WK_ST_LK_CORNER_H__

#include <iostream>
#include <list>
#include <queue>
#include <mutex>
#include <memory>
#include <list>
#include <functional>
#include <sample_comm.h>

#include "wk_corner_info.h"
#include "wk_corner_common.h"
#include "wk_st_lk_app.h"


using namespace std; 


class wk_st_lk_corner_points : public wk_corner_points
{
public:
	using wk_ptr = std::shared_ptr<wk_st_lk_corner_points>;
	static wk_st_lk_corner_points* wk_st_lk_corner_point_get_instance();
	static td_s32 wk_st_lk_corner_points_destroy_instance();
	~wk_st_lk_corner_points();


	/* 获取图像源分辨率 */
	td_bool wk_corner_points_get_image_size(td_u16* _width, td_u16* _hight);
	/* 获取角度数量最大最小值 */
	td_bool wk_corner_points_get_points_num_max_min(td_u16* _max, td_u16* _min);

	/* 设置、获取控制st lk工作状态 */
	td_bool wk_corner_points_set_status(WK_CORNER_POINTS_STATUS_E _status);
	WK_CORNER_POINTS_STATUS_E wk_corner_points_get_status();

	/* 输出算法执行结果 */
	td_bool wk_corner_points_result_export(wk_location_result_s* _result);

private:
	wk_st_lk_corner_points();
	wk_st_lk_corner_points(const wk_st_lk_corner_points&)=delete;
	wk_st_lk_corner_points& operator=(const wk_st_lk_corner_points&)=delete;
	
	static wk_st_lk_corner_points* instance;
};


#endif /* __WK_ST_LK_CORNER_H__ */
