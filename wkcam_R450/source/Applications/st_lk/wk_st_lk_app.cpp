#include "wk_st_lk_app.h"

/* 文件实现：
1. 获取到每一帧的关键点，对关键点的使用和管理
2. 对ive获取关键点的状态进行管理
3. 可实现描点和金字塔跟踪的参数配置
4. 特征点提取功能初始化并开启
*/

#define WK_IVE_LK_D1_WIDTH           	720   		              	/* 图像大小 */ 	
#define WK_IVE_LK_D1_HEIGHT          	576
#define WK_IVE_ST_LK_SRC_FRAMW_TYPE		OT_SVP_IMG_TYPE_YUV420SP  	/* 输入图像类型 */ 
#define WK_IVE_LK_MAX_LEVEL          	3         				  	/* 金字塔层数 [0~3] */ 
#define WK_IVE_ST_QUALITY_LEVEL      	25							/* ST特征点质量控制参数 [1~255]*/
#define WK_IVE_ST_LK_MAX_POINTS_NUM     100        					/* 特征点个数最大值 */ 
#define WK_IVE_ST_LK_MIN_POINTS_NUM     5							/* 特征点个数最小值 */
#define WK_IVE_LK_MIN_EIG_VALUE  		100							/* LK最小特征阈值 [1~255] */
#define WK_IVE_LK_ITER_CNT          	10							/* LK最大迭代次数 [1~20] */
#define WK_IVE_LK_EPS                	2							/* LK迭代收敛条件 [1~255] */

typedef struct {
	wk_st_lk_get_frame_mng_s st_get_frame_mng; 
	wk_ive_st_lk_param st_lk_param;
}wk_st_lk_app_mng_info_s;

 static wk_st_lk_app_mng_info_s g_st_lk_mng_info;

/* 光流定位参数初始化 */
static td_s32 _wk_st_lk_set_default_param(wk_ive_st_lk_param* _param)
{
	if(_param == NULL){
		return TD_FAILURE;
	}
	
	_param->frame_size.width = WK_IVE_LK_D1_WIDTH;
	_param->frame_size.height = WK_IVE_LK_D1_HEIGHT;
	_param->frame_type = WK_IVE_ST_LK_SRC_FRAMW_TYPE;
	_param->max_points_num = WK_IVE_ST_LK_MAX_POINTS_NUM;
	_param->min_points_num = WK_IVE_ST_LK_MIN_POINTS_NUM;

	_param->max_level = WK_IVE_LK_MAX_LEVEL;
	_param->min_eig_val = WK_IVE_LK_MIN_EIG_VALUE;
	_param->iter_cnt = WK_IVE_LK_ITER_CNT;
	_param->eps = WK_IVE_LK_EPS;
		
	_param->quality_level = WK_IVE_ST_QUALITY_LEVEL;
	return TD_SUCCESS;
}
	


/* 开启光流功能处理 */
td_s32 wk_st_lk_app_start(ot_vpss_grp _grp, ot_vpss_chn _chn)
{
	td_s32 s32ret = -1;
	wk_st_lk_app_mng_info_s* pinfo = &g_st_lk_mng_info;

	/* ST LK 初始化 */
	_wk_st_lk_set_default_param(&pinfo->st_lk_param);
	s32ret = wk_st_lk_frame_handle_init(&pinfo->st_lk_param);
	if(s32ret<0) {
		goto wk_st_lk_frame_handle_init_err;
	}

	/* 开启获取图像 */
	pinfo->st_get_frame_mng.grp = _grp;
	pinfo->st_get_frame_mng.chn = _chn;
	pinfo->st_get_frame_mng.get_frame_callback = wk_st_lk_get_frame_handle;
	s32ret = wk_st_lk_get_frame_init(&pinfo->st_get_frame_mng);
	if(s32ret<0){
		goto wk_st_lk_get_frame_init_err;
	}

	return TD_SUCCESS;
	
wk_st_lk_get_frame_init_err:
	wk_st_lk_frame_handle_deinit();
wk_st_lk_frame_handle_init_err:
	return s32ret;
}

/* 关闭光流功能处理 */
td_s32 wk_st_lk_app_stop()
{
	td_s32 s32ret = -1;
	wk_st_lk_app_mng_info_s* pinfo = &g_st_lk_mng_info;

	wk_st_lk_get_frame_deinit(&pinfo->st_get_frame_mng);
	wk_st_lk_frame_handle_deinit();
	
	return TD_SUCCESS;
}




