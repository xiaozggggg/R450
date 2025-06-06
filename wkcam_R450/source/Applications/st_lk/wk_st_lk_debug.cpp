#include "wk_st_lk_debug.h"


/*************************************************************************************
*	brief: 该代码用于将st lk输出的点描绘在图像上，后推入venc进行编码
*	注意：代码仅用于测试！！！！
**************************************************************************************/

/* 描点图发送至venc中 */
static td_s32 _wk_st_lk_draw_points_send_venc(ot_video_frame_info *_pframe)
{
	td_s32 s32ret = TD_FAILURE;

	if(_pframe == NULL) {
		sample_print_err("_pframe failed, is null!.\n");
		return s32ret;
	}

    s32ret = ss_mpi_venc_send_frame(WK_VIDEO_CHANNEL_PREVIEW, _pframe, -1);
    if (s32ret != TD_SUCCESS){
        sample_print_err("ss_mpi_venc_send_frame failed, s32Ret:0x%x\n", s32ret);
		return s32ret;
    }
	
	return TD_SUCCESS;
}

#if 0
/* float转s25q7 */
static td_s32 _wk_debug_float_to_s25q7(wk_points_float_s* _float_val, ot_svp_point_s25q7* _s25q7_val, td_u16 _cnt)
{
	td_u8 u8sign = 0;

	for(td_u16 ifor=0; ifor<_cnt; ifor++)
	{
		/* 转换x坐标 */
		u8sign = (_float_val[ifor].x > 0) ? 0:1;
		_s25q7_val[ifor].x = _float_val[ifor].x*128.0;
		_s25q7_val[ifor].x |= u8sign<<31;


		/* 转换y坐标 */
		u8sign = (_float_val[ifor].y > 0) ? 0:1;
		_s25q7_val[ifor].y = _float_val[ifor].y*128.0;
		_s25q7_val[ifor].y |= u8sign<<31;
	}	
	
	return TD_SUCCESS;
}
#else
/* float转s25q7 */
static td_s32 _wk_debug_float_to_s25q7(wk_points_float_s* _float_val, ot_svp_point_s25q7* _s25q7_val, td_u16 _cnt)
{
	td_u8 u8sign = 0;
	td_s32 integerPart = 0;
	td_float floatPart = 0.0;
	td_s32 tmppart = 0;

	for(td_u16 ifor=0; ifor<_cnt; ifor++)
	{
		/* 转换x坐标 */
		u8sign = (_float_val[ifor].x > 0) ? 0:1;
		integerPart = (td_s32)_float_val[ifor].x;
		floatPart = _float_val[ifor].x - integerPart;
		tmppart = (td_s32)(floatPart*128);

		_s25q7_val[ifor].x = (integerPart & 0xFFFFFF) << 7;
		_s25q7_val[ifor].x |= u8sign<<31;
		_s25q7_val[ifor].x |= (tmppart & 0x7F);


		/* 转换y坐标 */
		u8sign = (_float_val[ifor].y > 0) ? 0:1;
		integerPart = (td_s32)_float_val[ifor].y;
		floatPart = _float_val[ifor].y - integerPart;
		tmppart = (td_s32)(floatPart*128);

		_s25q7_val[ifor].y = (integerPart & 0xFFFFFF) << 7;
		_s25q7_val[ifor].y |= u8sign<<31;
		_s25q7_val[ifor].y |= (tmppart & 0x7F);
	}	
	
	return TD_SUCCESS;
}
#endif


/* 建立vgs任务，进行图像绘点 */
td_s32 wk_st_lk_vgs_draw_ponits_send_venc_debug(ot_video_frame_info* _frame, wk_points_float_s* _points, td_u32 _points_num)
{
	#define ONE_CYCLE_DRAW_POINT_MAX_NUM	100
    ot_vgs_handle vgs_handle = -1;
   	td_s32 ret = TD_FAILURE;
    ot_vgs_task_attr vgs_task;
    ot_cover vgs_add_cover[ONE_CYCLE_DRAW_POINT_MAX_NUM];
	td_u32 ifor = 0, u32ponits_cnt = 0;
	ot_svp_point_s25q7  ponits[1024] = {0};

	if(_frame == NULL){
		sample_print_err("vgs draw ponits param error!\n");
		return ret;
	}

	/* 无描点，直接发送venc */
	if(_points_num == 0){
		memcpy_s(&vgs_task.img_out, sizeof(ot_video_frame_info),_frame, sizeof(ot_video_frame_info));
		goto scale_handle;
	}

	if( _points == NULL){
		sample_print_err("vgs draw ponits param error!\n");
		return ret;
	}

	/* 循环对图像进行绘点 */
	_wk_debug_float_to_s25q7(_points, ponits, _points_num);
	memcpy_s(&vgs_task.img_in, sizeof(ot_video_frame_info), _frame, sizeof(ot_video_frame_info));
	memcpy_s(&vgs_task.img_out, sizeof(ot_video_frame_info),_frame, sizeof(ot_video_frame_info));
	while(u32ponits_cnt < _points_num)
	{
		td_u8 u8cnt=0;
		if(_points_num - u32ponits_cnt >= ONE_CYCLE_DRAW_POINT_MAX_NUM){
			u8cnt = ONE_CYCLE_DRAW_POINT_MAX_NUM;
		}
		else{
			u8cnt = _points_num - u32ponits_cnt;
		}

		
	    ret = ss_mpi_vgs_begin_job(&vgs_handle);
		if(ret != TD_SUCCESS) {
			sample_print_err("ss_mpi_vgs_begin_job error(%#x)\n", ret);
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

			ponits[u32ponits_cnt].x /= 128;
			ponits[u32ponits_cnt].y /= 128;
			vgs_add_cover[ifor].rect_attr.rect.x = (ponits[u32ponits_cnt].x % 2 > 0) ? 
													ponits[u32ponits_cnt].x+1 : ponits[u32ponits_cnt].x;  
			vgs_add_cover[ifor].rect_attr.rect.y = (ponits[u32ponits_cnt].y % 2 > 0) ?
													ponits[u32ponits_cnt].y+1 : ponits[u32ponits_cnt].y; 
		}
		
		ret = ss_mpi_vgs_add_cover_task(vgs_handle, &vgs_task, vgs_add_cover, ifor);
		if(ret != TD_SUCCESS) {
			sample_print_err("ss_mpi_vgs_add_cover_task error(%#x)\n", ret);
			goto vgs_draw_ponits_fail;
		}

		ret = ss_mpi_vgs_end_job(vgs_handle);
	    if (ret != TD_SUCCESS) {
			sample_print_err("ss_mpi_vgs_end_job error(%#x)\n", ret);
			goto vgs_draw_ponits_fail;
	    }
	}

scale_handle:
	/* 进行图像放大，放大到720p */
	ot_size frame_size;
	frame_size.width = 1280;
	frame_size.height = 720;
    sample_vi_user_frame_info pic_frame_info;
	
    ret = _wk_create_user_frame(&frame_size, &pic_frame_info);
    if (ret != TD_SUCCESS) {
        return ret;
    }
	pic_frame_info.frame_info.mod_id = vgs_task.img_out.mod_id;
	pic_frame_info.frame_info.video_frame.pts = vgs_task.img_out.video_frame.pts;
	pic_frame_info.frame_info.video_frame.time_ref = vgs_task.img_out.video_frame.time_ref;
		
	ret = _wk_scale_task(&vgs_task.img_out, &pic_frame_info.frame_info);
    if (ret != TD_SUCCESS) {
        WK_LOGE("add vgs scale task failed.\n");
		goto task_err;
    }
		
	/* 将经过绘点后图片发送到venc */
	_wk_st_lk_draw_points_send_venc(&pic_frame_info.frame_info);

task_err:
	_wk_create_user_release_frame_blk(&pic_frame_info, 1);
vgs_draw_ponits_fail:
	ss_mpi_vgs_cancel_job(vgs_handle);
	return ret;
}




