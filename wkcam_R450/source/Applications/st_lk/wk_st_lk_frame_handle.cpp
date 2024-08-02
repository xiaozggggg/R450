#include "wk_st_lk_frame_handle.h"
#ifdef DEBUG_ST_LK_POINTS_PREVIEW
#include "wk_st_lk_draw_points_venc_debug.h"
#endif

/* 文件实现：
1. 使用libwkmpp接口，实现ive提取关键点
2. 实现状态机，可让使用输出点数组的上层能随时控制识别状态（重新识别、继续使用金字塔识别、停止识别等）
3. 状态错误返回给应用层，由应用层决策处理(或者有应用层注册错误处理回调，发生错误使用回调进行处理)
4. 能进行输出venc调试
*/

typedef struct {
	WK_ST_LK_HANDLE_STATUS_E  e_status;
	wk_ive_st_lk_info st_lk_infor;
}wk_st_lk_info_s;


static wk_st_lk_info_s stmodel_info = {
	.e_status = WK_ST_LK_HANDLE_STATUS_ST_GET_POINTS,
};



/* 初始化状态处理 */
static td_s32 _wk_st_lk_status_inital_handle(ot_video_frame_info *_frame)
{

}

/* 通过st取点处理 */
static td_s32 _wk_st_lk_status_st_get_points_handle(ot_video_frame_info *_frame)
{
	td_s32 s32ret = -1;
	wk_st_lk_info_s* pinfor = &stmodel_info;

	s32ret = wk_ive_st_get_points(&pinfor->st_lk_infor, _frame);
	if(s32ret == TD_SUCCESS){
		/* 获取到点后的处理 */
		ot_svp_point_s25q7* points = NULL;
		td_u32 points_num = 0;
	
		wk_ive_st_lk_get_points(&pinfor->st_lk_infor, &points, &points_num);

		#ifdef DEBUG_ST_LK_POINTS_PREVIEW
		wk_st_lk_vgs_draw_ponits_send_venc_debug(_frame, points, points_num);
		#endif			
	}
	return s32ret;
}

/* 通过lk取点处理*/
static td_s32 _wk_st_lk_status_lk_get_points_handle(ot_video_frame_info *_frame)
{
	td_s32 s32ret = -1;
	wk_st_lk_info_s* pinfor = &stmodel_info;

	s32ret = wk_ive_lk_get_points(&pinfor->st_lk_infor, _frame);
	if(s32ret == TD_SUCCESS){
		/* 获取到点后的处理 */
		ot_svp_point_s25q7* points = NULL;
		td_u32 points_num = 0;
	
		wk_ive_st_lk_get_points(&pinfor->st_lk_infor, &points, &points_num);

		#ifdef DEBUG_ST_LK_POINTS_PREVIEW
		wk_st_lk_vgs_draw_ponits_send_venc_debug(_frame, points, points_num);
		#endif		
	}
	return s32ret;
}

/* 取点暂停处理 */
static td_s32 _wk_st_lk_status_pause_handle(ot_video_frame_info *_frame)
{

}

/* 取点过程发生错误处理 */
static td_s32 _wk_st_lk_status_error_handle(ot_video_frame_info *_frame)
{

}


/* 考虑处理错误是否要回调错误事件给应用层，让应用层处理错误 */
static td_s32 _wk_st_lk_err_event_reported(WK_ST_LK_HANDLE_STATUS_E _stauts, td_s32 _errno)
{
	
}



/* 获取点处理，需要考虑状态机 */
void wk_st_lk_get_frame_handle(ot_video_frame_info *_frame)
{
	wk_st_lk_info_s* pinfor = &stmodel_info;
	td_s32 s32errno = -1;

	/* 状态处理 */
	switch (pinfor->e_status)
	{
		case WK_ST_LK_HANDLE_STATUS_INITIAL:
			s32errno = _wk_st_lk_status_inital_handle(_frame);
			break;
		case WK_ST_LK_HANDLE_STATUS_ST_GET_POINTS:
			s32errno = _wk_st_lk_status_st_get_points_handle(_frame);
			if(s32errno == TD_SUCCESS){
				pinfor->e_status = WK_ST_LK_HANDLE_STATUS_LK_GET_POINTS;
			}
			break;
		case WK_ST_LK_HANDLE_STATUS_LK_GET_POINTS:
			s32errno = _wk_st_lk_status_lk_get_points_handle(_frame);
			break;
		case WK_ST_LK_HANDLE_STATUS_PAUSE:
			s32errno = _wk_st_lk_status_pause_handle(_frame);
			break;
		case WK_ST_LK_HANDLE_STATUS_ERROR:
			s32errno = _wk_st_lk_status_error_handle(_frame);
			break;
		default:
			break;
	}

	/* 错误上报 */
	if(s32errno != 0){
		_wk_st_lk_err_event_reported(pinfor->e_status, s32errno);
	}

	return;
}

/* 设置状态 */
td_s32 wk_st_lk_set_status(WK_ST_LK_HANDLE_STATUS_E _status)
{
	wk_st_lk_info_s* pinfor = &stmodel_info;
	pinfor->e_status = _status;
	
	return TD_SUCCESS;
}


/* 光流识别特征点处理初始化 */
td_s32 wk_st_lk_frame_handle_init(wk_ive_st_lk_param* _param)
{
	td_s32 s32ret = -1;
	wk_st_lk_info_s* pinfor = &stmodel_info;
	
	s32ret = wk_ive_st_lk_init(&pinfor->st_lk_infor, _param);
	if(s32ret != TD_SUCCESS) {
		return s32ret;
	}

	return TD_SUCCESS;
}

/* 光流识别特征点处理去初始化 */
td_s32 wk_st_lk_frame_handle_deinit()
{
	wk_st_lk_info_s* pinfor = &stmodel_info;

	memset(pinfor, 0, sizeof(wk_st_lk_info_s));
	return TD_SUCCESS;
}


