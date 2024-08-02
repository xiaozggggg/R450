/*************************************************************************************
*	brief: 该代码用于将st lk输出的点描绘在图像上，后推入venc进行编码
*	注意：代码仅用于测试！！！！
**************************************************************************************/

#include "wk_st_lk_draw_points_venc_debug.h"

td_s32 g_s32venc_chn = WK_VIDEO_CHANNEL_PREVIEW;

typedef struct {
	ot_video_frame_info* pframe_src;		// 入图
	
	td_u32	ponits_num;
	ot_svp_point_s25q7  ponits[1024];   // 图对应的点
}wk_frame_points_t;


/* 描点图发送至venc中 */
static td_s32 _wk_st_lk_draw_points_send_venc(ot_video_frame_info *_pframe)
{
	td_s32 s32ret = TD_FAILURE;

	if(_pframe == NULL) {
		sample_print("_pframe failed, is null!.\n");
		return s32ret;
	}

    s32ret = ss_mpi_venc_send_frame(g_s32venc_chn, _pframe, -1);
    if (s32ret != TD_SUCCESS){
        sample_print("ss_mpi_venc_send_frame failed, s32Ret:0x%x\n", s32ret);
		return s32ret;
    }
	
	return TD_SUCCESS;
}


/* 建立vgs任务，进行图像绘点 */
static td_s32 _wk_st_lk_vgs_draw_ponits_send_venc(wk_frame_points_t* _pinfo)
{
	#define ONE_CYCLE_DRAW_POINT_MAX_NUM	100
    ot_vgs_handle vgs_handle = -1;
   	td_s32 ret = TD_FAILURE;
    ot_vgs_task_attr vgs_task;
    ot_cover vgs_add_cover[ONE_CYCLE_DRAW_POINT_MAX_NUM];
	td_u32 ifor = 0, u32ponits_cnt = 0;

	if(_pinfo == NULL || _pinfo->pframe_src == NULL){
		printf("vgs draw ponits param error!\n");
		return ret;
	}

	/* 无描点，直接发送venc */
	if(_pinfo->ponits_num == 0){
		_wk_st_lk_draw_points_send_venc(_pinfo->pframe_src);
		return TD_SUCCESS;
	}

	/* 循环对图像进行绘点 */
	memcpy_s(&vgs_task.img_in, sizeof(ot_video_frame_info), _pinfo->pframe_src, sizeof(ot_video_frame_info));
	memcpy_s(&vgs_task.img_out, sizeof(ot_video_frame_info), _pinfo->pframe_src, sizeof(ot_video_frame_info));
	while(u32ponits_cnt < _pinfo->ponits_num)
	{
		td_u8 u8cnt=0;
		if(_pinfo->ponits_num - u32ponits_cnt >= ONE_CYCLE_DRAW_POINT_MAX_NUM){
			u8cnt = ONE_CYCLE_DRAW_POINT_MAX_NUM;
		}
		else{
			u8cnt = _pinfo->ponits_num - u32ponits_cnt;
		}

		
	    ret = ss_mpi_vgs_begin_job(&vgs_handle);
		if(ret != TD_SUCCESS) {
			printf("ss_mpi_vgs_begin_job error(%#x)\n", ret);
			return ret;
		}

		memset(vgs_add_cover, 0, sizeof(ot_cover)*ONE_CYCLE_DRAW_POINT_MAX_NUM);
		for (ifor = 0; ifor < u8cnt; ifor++, u32ponits_cnt++) {
			vgs_add_cover[ifor].type = OT_COVER_RECT;
			vgs_add_cover[ifor].color = 0x0000FF00;  // 绿色
			vgs_add_cover[ifor].rect_attr.is_solid = TD_FALSE;	// 是否实心
			vgs_add_cover[ifor].rect_attr.thick = 2;			// 线宽
			vgs_add_cover[ifor].rect_attr.rect.height = 4;
			vgs_add_cover[ifor].rect_attr.rect.width = 4;

			_pinfo->ponits[u32ponits_cnt].x /= 128;
			_pinfo->ponits[u32ponits_cnt].y /= 128;
			vgs_add_cover[ifor].rect_attr.rect.x = (_pinfo->ponits[u32ponits_cnt].x % 2 > 0) ? 
													_pinfo->ponits[u32ponits_cnt].x+1 : _pinfo->ponits[u32ponits_cnt].x;  
			vgs_add_cover[ifor].rect_attr.rect.y = (_pinfo->ponits[u32ponits_cnt].y % 2 > 0) ?
													_pinfo->ponits[u32ponits_cnt].y+1 : _pinfo->ponits[u32ponits_cnt].y; 
		}
		
		ret = ss_mpi_vgs_add_cover_task(vgs_handle, &vgs_task, vgs_add_cover, ifor);
		if(ret != TD_SUCCESS) {
			printf("ss_mpi_vgs_add_cover_task error(%#x)\n", ret);
			goto vgs_draw_ponits_fail;
		}

		ret = ss_mpi_vgs_end_job(vgs_handle);
	    if (ret != TD_SUCCESS) {
			printf("ss_mpi_vgs_end_job error(%#x)\n", ret);
			goto vgs_draw_ponits_fail;
	    }
	}

	/* 将经过绘点后图片发送到venc */
	_wk_st_lk_draw_points_send_venc(&vgs_task.img_out);
	
vgs_draw_ponits_fail:
	ss_mpi_vgs_cancel_job(vgs_handle);
	return ret;
}


/* 图像绘点 */
td_s32 wk_st_lk_vgs_draw_ponits_send_venc_debug(ot_video_frame_info* _frame, ot_svp_point_s25q7* _points, td_u32 _points_num)
{
	wk_frame_points_t stdraw_info;
	
	memset(&stdraw_info, 0, sizeof(wk_frame_points_t));
	stdraw_info.pframe_src = _frame;
	stdraw_info.ponits_num = _points_num;
	memcpy(stdraw_info.ponits, _points, sizeof(ot_svp_point_s25q7)*stdraw_info.ponits_num);
	
	return _wk_st_lk_vgs_draw_ponits_send_venc(&stdraw_info);

}




