#include "wk_ive_st_lk_interface.h"

/* 文件实现：
1. 使用ive提取关键点，功能提供接口
(之后需要实现数据和参数脱离，只提供接口)
*/


#define OT_SAMPLE_IVE_LK_QUERY_SLEEP        10
#define OT_SAMPLE_IVE_LEFT_SHIFT_SEVEN      7
#define OT_SAMPLE_IVE_HOR_SEG_SIZE          2
#define OT_SAMPLE_IVE_ELEM_SIZE             1
#define OT_SAMPLE_IVE_VER_SEG_ROWS          2

td_void wk_ive_st_lk_uninit(wk_ive_st_lk_info *_lk_info);


static td_s32 _wk_ive_st_lk_dma(ot_ive_handle *_ive_handle, ot_svp_src_img *_src,
    ot_svp_dst_img *_dst, ot_ive_dma_ctrl *_dma_ctrl, td_bool _is_instant)
{
    td_s32 ret;
    ot_svp_src_data data_src;
    ot_svp_dst_data data_dst;

    data_src.virt_addr = _src->virt_addr[0];
    data_src.phys_addr = _src->phys_addr[0];
    data_src.width = _src->width;
    data_src.height = _src->height;
    data_src.stride = _src->stride[0];

    data_dst.virt_addr = _dst->virt_addr[0];
    data_dst.phys_addr = _dst->phys_addr[0];
    data_dst.width = _dst->width;
    data_dst.height = _dst->height;
    data_dst.stride = _dst->stride[0];
    ret = ss_mpi_ive_dma(_ive_handle, &data_src, &data_dst, _dma_ctrl, _is_instant);
    sample_svp_check_exps_return(ret != TD_SUCCESS, ret, SAMPLE_SVP_ERR_LEVEL_ERROR,
        "Error(%#x),ss_mpi_ive_dma failed!\n", ret);

    return ret;
}
	
static td_s32 _wk_ive_st_lk_pyr_down(wk_ive_st_lk_info *_lk_info, ot_svp_src_img *_src, ot_svp_dst_img *_dst)
{
	td_s32 ret;
	ot_ive_handle handle;
	ot_ive_dma_ctrl dma_ctrl;
	ot_ive_filter_ctrl filter_ctrl = { { 1, 2, 3, 2, 1, 2, 5, 6, 5, 2, 3, 6, 8, 6, 3, 2, 5, 6, 5, 2, 1, 2, 3, 2, 1,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		7, 5, 5, OT_IVE_PADDING_MODE_EDGE, {0} };
	(td_void)memset_s(&dma_ctrl, sizeof(dma_ctrl), 0, sizeof(dma_ctrl));
	dma_ctrl.mode = OT_IVE_DMA_MODE_INTERVAL_COPY;
	dma_ctrl.hor_seg_size = OT_SAMPLE_IVE_HOR_SEG_SIZE;
	dma_ctrl.elem_size = OT_SAMPLE_IVE_ELEM_SIZE;
	dma_ctrl.ver_seg_rows = OT_SAMPLE_IVE_VER_SEG_ROWS;
	_lk_info->pyr_tmp.width = _src->width;
	_lk_info->pyr_tmp.height = _src->height;

	ret = ss_mpi_ive_filter(&handle, _src, &_lk_info->pyr_tmp, &filter_ctrl, TD_FALSE);
	if(ret != TD_SUCCESS){
		printf("Error(%#x),ss_mpi_ive_filter failed!\n", ret);
		return TD_FAILURE;
	}	

	ret = _wk_ive_st_lk_dma(&handle, &_lk_info->pyr_tmp, _dst, &dma_ctrl, TD_FALSE);
	if(ret != TD_SUCCESS){
		printf("Error(%#x),_wk_ive_st_lk_dma failed!\n", ret);
		return TD_FAILURE;
	}

	return ret;
}

static td_s32 _wk_ive_query_task(ot_ive_handle _handle)
{
	td_s32 ret;
	td_bool is_block = TD_TRUE;
	td_bool is_finish = TD_FALSE;
	ret = ss_mpi_ive_query(_handle, &is_finish, is_block);
	while (ret == OT_ERR_IVE_QUERY_TIMEOUT) {
		usleep(OT_SAMPLE_IVE_LK_QUERY_SLEEP);
		ret = ss_mpi_ive_query(_handle, &is_finish, is_block);
	}
	
	if(ret != TD_SUCCESS){
		printf("Error(%#x),ss_mpi_ive_query failed!\n", ret);
		return TD_FAILURE;
	}	
	
	return TD_SUCCESS;
}

static td_void _wk_ive_st_lk_copy_pyr(ot_svp_src_img _pyr_src[], ot_svp_dst_img _pyr_dst[], td_u8 _max_level)
{
	td_u8 i;
	td_s32 ret;
	ot_ive_handle handle;

	ot_ive_dma_ctrl dma_ctrl;
	(td_void)memset_s(&dma_ctrl, sizeof(dma_ctrl), 0, sizeof(dma_ctrl));
	dma_ctrl.mode = OT_IVE_DMA_MODE_DIRECT_COPY;

	for (i = 0; i <= _max_level; i++) {
		ret = _wk_ive_st_lk_dma(&handle, &_pyr_src[i], &_pyr_dst[i], &dma_ctrl, TD_FALSE);
		if (ret != TD_SUCCESS) {
			printf("_wk_ive_st_lk_dma fail,Error(%d)\n", ret);
			break;
		}
	}
}

static td_s32 _wk_create_user_frame(ot_size *dst_size, sample_vi_user_frame_info *user_frame_info)
{
    td_s32 ret;
    sample_vi_get_frame_vb_cfg vb_cfg;

    vb_cfg.size.width    = dst_size->width;
    vb_cfg.size.height   = dst_size->height;
    vb_cfg.pixel_format  = OT_PIXEL_FORMAT_YVU_SEMIPLANAR_420;
    vb_cfg.video_format  = OT_VIDEO_FORMAT_LINEAR;
    vb_cfg.compress_mode = OT_COMPRESS_MODE_NONE;
    vb_cfg.dynamic_range = OT_DYNAMIC_RANGE_SDR8;

    ret = sample_comm_vi_get_frame_blk(&vb_cfg, user_frame_info, 1);
    if (ret != TD_SUCCESS) {
        sample_print("get user pic frame vb failed!\n");
        return ret;
    }

    return TD_SUCCESS;
}

static td_void _wk_create_user_release_frame_blk(sample_vi_user_frame_info user_frame_info[], td_s32 frame_cnt)
{
    td_s32 i;
    ot_vb_pool pool_id;

    for (i = 0; i < frame_cnt; i++) {
        sample_comm_vi_free_frame_blk(&user_frame_info[i]);
    }

    pool_id = user_frame_info[0].frame_info.pool_id;
    ss_mpi_vb_destroy_pool(pool_id);
}

static td_s32 _wk_scale_task(ot_video_frame_info *src_frame, ot_video_frame_info *dst_frame)
{
    td_s32 ret;
    ot_vgs_handle handle;
    ot_vgs_task_attr vgs_task_attr;

    ret = ss_mpi_vgs_begin_job(&handle);
    if (ret != TD_SUCCESS) {
        sample_print("ss_mpi_vgs_begin_job failed, ret:0x%x", ret);
        return TD_FAILURE;
    }

    if (memcpy_s(&vgs_task_attr.img_in, sizeof(ot_video_frame_info),
        src_frame, sizeof(ot_video_frame_info)) != EOK) {
        sample_print("memcpy_s img_in failed\n");
        return TD_FAILURE;
    }

    if (memcpy_s(&vgs_task_attr.img_out, sizeof(ot_video_frame_info),
        dst_frame, sizeof(ot_video_frame_info)) != EOK) {
        sample_print("memcpy_s img_out failed\n");
        return TD_FAILURE;
    }

    if (ss_mpi_vgs_add_scale_task(handle, &vgs_task_attr, OT_VGS_SCALE_COEF_NORM) != TD_SUCCESS) {
        sample_print("ss_mpi_vgs_add_scale_task failed\n");
        return TD_FAILURE;
    }

    ret = ss_mpi_vgs_end_job(handle);
    if (ret != TD_SUCCESS) {
        ss_mpi_vgs_cancel_job(handle);
        sample_print("ss_mpi_vgs_end_job failed, ret:0x%x", ret);
        return TD_FAILURE;
    }

    return TD_SUCCESS;
}



/* 通过st提取特征点 */
td_s32 wk_ive_st_get_points(wk_ive_st_lk_info *_lk_info, ot_video_frame_info *_frame)
{
	td_u32 k = 0;
    td_s32 ret = OT_ERR_IVE_NULL_PTR;
    ot_ive_handle handle;
    ot_ive_dma_ctrl dma_ctrl;	
	ot_ive_st_corner_info *corner_info = NULL;

	if(_lk_info == NULL || _frame == NULL) {
		printf("param is null\n");
		return TD_FAILURE;
	}
	
    memset(&dma_ctrl, 0, sizeof(dma_ctrl));
    dma_ctrl.mode = OT_IVE_DMA_MODE_DIRECT_COPY;

	/* 图像放大 */
	ot_size frame_size;
	frame_size.width = _lk_info->frame_size.width;
	frame_size.height = _lk_info->frame_size.height;
    sample_vi_user_frame_info pic_frame_info;
    ret = _wk_create_user_frame(&frame_size, &pic_frame_info);
    if (ret != TD_SUCCESS) {
        return ret;
    }
	ret = _wk_scale_task(_frame, &pic_frame_info.frame_info);
    if (ret != TD_SUCCESS) {
        sample_print("add vgs scale task failed.\n");
		goto task_err;
    }
	

	/* 转换frame格式 */
	ret = sample_common_ive_dma_image(&pic_frame_info.frame_info, (ot_svp_dst_img*)&_lk_info->src_yuv, TD_FALSE);
	if(ret != TD_SUCCESS){
		printf("Error(%#x),sample_common_ive_dma_image failed!\n", ret);
		goto task_err;
	}

	/* 复制src_yuv到next_pyr金字塔底层 */
    ret = _wk_ive_st_lk_dma(&handle, &_lk_info->src_yuv, &_lk_info->next_pyr[0], &dma_ctrl, TD_FALSE);
	if(ret != TD_SUCCESS){
		printf("Error(%#x),_wk_ive_st_lk_dma failed!\n", ret);
		goto task_err;
	}
	
	/* 循环构建next_pyr图像金字塔 */
	for (k = 1; k <= _lk_info->lk_pyr_ctrl.max_level; k++) {
		ret = _wk_ive_st_lk_pyr_down(_lk_info, &_lk_info->next_pyr[k - 1], &_lk_info->next_pyr[k]);
		if(ret != TD_SUCCESS){
			printf("Error(%#x),_wk_ive_st_lk_pyr_down %u failed!\n", ret, k);
			goto task_err;
		}
	}

	/* st提取点识别 */
 	corner_info = sample_svp_convert_addr_to_ptr(ot_ive_st_corner_info, _lk_info->corner.virt_addr);
	
	//ret = ss_mpi_ive_st_cand_corner(&handle, &_lk_info->next_pyr[0], &_lk_info->dst, &_lk_info->cand_corner_ctrl, TD_TRUE);  
    ret = ss_mpi_ive_st_cand_corner(&handle, &_lk_info->next_pyr[1], &_lk_info->dst, &_lk_info->cand_corner_ctrl, TD_TRUE); // 使用缩小1倍的分辨率
	if(ret != TD_SUCCESS){
		printf("Error(%#x),ss_mpi_ive_st_cand_corner failed!\n", ret);
		goto task_err;
	}

    ret = _wk_ive_query_task(handle);
	if(ret != TD_SUCCESS){
		printf("Error(%#x),_wk_ive_query_task failed!\n", ret);
		goto task_err;
	}

    ret = ss_mpi_ive_st_corner(&_lk_info->dst, &_lk_info->corner, &_lk_info->corner_ctrl);
	if(ret != TD_SUCCESS){
		printf("Error(%#x),ss_mpi_ive_st_corner failed!\n", ret);
		goto task_err;
	}

	/* 角点输出保存 */
	memset(&_lk_info->curr_corner_points, 0, sizeof(_lk_info->curr_corner_points));
    _lk_info->points_cnt =  corner_info->corner_num;
    for (k = 0; k < _lk_info->points_cnt; k++) {
		//_lk_info->curr_corner_points[k].x  = (td_s32)(corner_info->corner[k].x << OT_SAMPLE_IVE_LEFT_SHIFT_SEVEN);
        //_lk_info->curr_corner_points[k].y  = (td_s32)(corner_info->corner[k].y << OT_SAMPLE_IVE_LEFT_SHIFT_SEVEN);
	
        _lk_info->curr_corner_points[k].x = (td_s32)(corner_info->corner[k].x << OT_SAMPLE_IVE_LEFT_SHIFT_SEVEN)*2;  // 使用缩小1倍的分辨率
        _lk_info->curr_corner_points[k].y = (td_s32)(corner_info->corner[k].y << OT_SAMPLE_IVE_LEFT_SHIFT_SEVEN)*2;

		/* 缩小角点坐标倍数 */
		_lk_info->curr_corner_points[k].x *= ((_frame->video_frame.height*1.0)/(_lk_info->frame_size.height*1.0));
	}

task_err:
	_wk_create_user_release_frame_blk(&pic_frame_info, 1);
	return ret;
}


/* 通过lk提取特征点 */
td_s32 wk_ive_lk_get_points(wk_ive_st_lk_info *_lk_info, 
								ot_video_frame_info *_curr_frame, 
								ot_video_frame_info *_prev_frame,
								ot_svp_point_s25q7* _prev_points_src,
								td_u16 _points_num)
{
	td_u32 k = 0, rect_num = 0;
    td_s32 ret = OT_ERR_IVE_NULL_PTR;
    ot_ive_handle handle;
    ot_ive_dma_ctrl dma_ctrl;	
	ot_ive_st_corner_info *corner_info = NULL;
	ot_svp_point_s25q7 *next_points =  NULL;
	ot_svp_point_s25q7 *prev_points =  NULL;
	td_u8* pstatus = NULL;
	td_u9q7* perr = NULL;

	if(_lk_info == NULL || _curr_frame == NULL || _prev_frame == NULL) {
		printf("param is null\n");
		return TD_FAILURE;
	}
	
    memset(&dma_ctrl, 0, sizeof(dma_ctrl));
    dma_ctrl.mode = OT_IVE_DMA_MODE_DIRECT_COPY;

	/* _prev_frame 转换frame格式 ，并构建金字塔 */
	// 图像放大
	ot_size frame_size;
	frame_size.width = _lk_info->frame_size.width;
	frame_size.height = _lk_info->frame_size.height;
    sample_vi_user_frame_info prev_frame_info;
    ret = _wk_create_user_frame(&frame_size, &prev_frame_info);
    if (ret != TD_SUCCESS) {
        return ret;
    }
	ret = _wk_scale_task(_prev_frame, &prev_frame_info.frame_info);
    if (ret != TD_SUCCESS) {
        sample_print("add vgs scale task failed.\n");
		goto task_err;
    }
	
	ret = sample_common_ive_dma_image(&prev_frame_info.frame_info, (ot_svp_dst_img*)&_lk_info->src_yuv, TD_FALSE);
	if(ret != TD_SUCCESS){
		printf("Error(%#x),sample_common_ive_dma_image failed!\n", ret);
		goto task_err;
	}
    ret = _wk_ive_st_lk_dma(&handle, &_lk_info->src_yuv, &_lk_info->prev_pyr[0], &dma_ctrl, TD_FALSE);
	if(ret != TD_SUCCESS){
		printf("Error(%#x),_wk_ive_st_lk_dma failed!\n", ret);
		goto task_err;
	}
	for (k = 1; k <= _lk_info->lk_pyr_ctrl.max_level; k++) {
		ret = _wk_ive_st_lk_pyr_down(_lk_info, &_lk_info->prev_pyr[k - 1], &_lk_info->prev_pyr[k]);
		if(ret != TD_SUCCESS){
			printf("Error(%#x),_wk_ive_st_lk_pyr_down %u failed!\n", ret, k);
			goto task_err;
		}
	}

	/* curr_frame 转换frame格式 ，并构建金字塔 */
	// 放大
    sample_vi_user_frame_info curr_frame_info;
    ret = _wk_create_user_frame(&frame_size, &curr_frame_info);
    if (ret != TD_SUCCESS) {
        goto task_err;
    }
	ret = _wk_scale_task(_curr_frame, &curr_frame_info.frame_info);
    if (ret != TD_SUCCESS) {
        sample_print("add vgs scale task failed.\n");
		goto task_err2;
    }
	
	ret = sample_common_ive_dma_image(&curr_frame_info.frame_info, (ot_svp_dst_img*)&_lk_info->src_yuv, TD_FALSE);
	if(ret != TD_SUCCESS){
		printf("Error(%#x),sample_common_ive_dma_image failed!\n", ret);
		goto task_err2;
	}
    ret = _wk_ive_st_lk_dma(&handle, &_lk_info->src_yuv, &_lk_info->next_pyr[0], &dma_ctrl, TD_FALSE);
	if(ret != TD_SUCCESS){
		printf("Error(%#x),_wk_ive_st_lk_dma failed!\n", ret);
		goto task_err2;
	}
	for (k = 1; k <= _lk_info->lk_pyr_ctrl.max_level; k++) {
		ret = _wk_ive_st_lk_pyr_down(_lk_info, &_lk_info->next_pyr[k - 1], &_lk_info->next_pyr[k]);
		if(ret != TD_SUCCESS){
			printf("Error(%#x),_wk_ive_st_lk_pyr_down %u failed!\n", ret, k);
			goto task_err2;
		}
	}

	/* 角点数据赋值 */
 	corner_info = sample_svp_convert_addr_to_ptr(ot_ive_st_corner_info, _lk_info->corner.virt_addr);
	next_points = sample_svp_convert_addr_to_ptr(ot_svp_point_s25q7, _lk_info->next_points.virt_addr);
	prev_points = sample_svp_convert_addr_to_ptr(ot_svp_point_s25q7, _lk_info->prev_points.virt_addr);
    for (k = 0; k < _points_num; k++) {
		prev_points[k].x = next_points[k].x = _prev_points_src[k].x;
        prev_points[k].y = next_points[k].y = _prev_points_src[k].y * ((_lk_info->frame_size.height*1.0)/(_curr_frame->video_frame.height*1.0));
    }	

	/* lk提取点识别 */
	ret = ss_mpi_ive_lk_optical_flow_pyr(&handle, _lk_info->prev_pyr, _lk_info->next_pyr, &_lk_info->prev_points,
		&_lk_info->next_points, &_lk_info->status, &_lk_info->err, &_lk_info->lk_pyr_ctrl, TD_TRUE);
	if(ret != TD_SUCCESS){
		printf("Error(%#x),ss_mpi_ive_lk_optical_flow_pyr failed!\n", ret);
		goto task_err2;
	}
	
	ret = _wk_ive_query_task(handle);
	if(ret != TD_SUCCESS){
		printf("Error(%#x),_wk_ive_query_task failed!\n", ret);
		goto task_err2;
	}

	/* 角点输出保存 */
	memset(&_lk_info->prev_corner_points, 0, sizeof(_lk_info->prev_corner_points));
	memset(&_lk_info->curr_corner_points, 0, sizeof(_lk_info->curr_corner_points));
	memset(&_lk_info->curr_points_status, 0, sizeof(_lk_info->curr_points_status));
	memset(&_lk_info->curr_points_err, 0, sizeof(_lk_info->curr_points_err));

	_lk_info->points_cnt = _lk_info->lk_pyr_ctrl.points_num;
	pstatus = sample_svp_convert_addr_to_ptr(td_u8, _lk_info->status.virt_addr);
	perr = sample_svp_convert_addr_to_ptr(td_u9q7, _lk_info->err.virt_addr);
    for (k = 0; k < _lk_info->points_cnt; k++) {
		_lk_info->prev_corner_points[k].x = prev_points[k].x;
        _lk_info->prev_corner_points[k].y = prev_points[k].y * ((_curr_frame->video_frame.height*1.0)/(_lk_info->frame_size.height*1.0));
	
		_lk_info->curr_corner_points[k].x = next_points[k].x;
		_lk_info->curr_corner_points[k].y = next_points[k].y * ((_curr_frame->video_frame.height*1.0)/(_lk_info->frame_size.height*1.0));

		_lk_info->curr_points_status[k] = pstatus[k];
		
		_lk_info->curr_points_err[k] = perr[k];
    }	

task_err2:
	_wk_create_user_release_frame_blk(&curr_frame_info, 1);
task_err:
	_wk_create_user_release_frame_blk(&prev_frame_info, 1);
	return ret;	
}


/* st相关参数初始化 */
static td_s32 _wk_ive_lk_param_init(wk_ive_st_lk_info *_lk_info, wk_ive_st_lk_param* _param)
{
    td_s32 ret;
    td_u32 size;
    td_u32 i;
	ot_size _src_size = _param->frame_size;
	
    _lk_info->lk_pyr_ctrl.out_mode = OT_IVE_LK_OPTICAL_FLOW_PYR_OUT_MODE_BOTH;
    _lk_info->lk_pyr_ctrl.use_init_flow = TD_TRUE;
    _lk_info->lk_pyr_ctrl.points_num = _param->max_points_num;
    _lk_info->lk_pyr_ctrl.max_level = _param->max_level;
    _lk_info->lk_pyr_ctrl.min_eig_val_threshold = _param->min_eig_val;
    _lk_info->lk_pyr_ctrl.iter_cnt = _param->iter_cnt;
    _lk_info->lk_pyr_ctrl.eps = _param->eps;
	
    /* 初始化构建金字塔 */
    for (i = 0; i <= _param->max_level; i++) {
        ret = sample_common_ive_create_image(&_lk_info->prev_pyr[i], OT_SVP_IMG_TYPE_U8C1,
            _src_size.width >> i, _src_size.height >> i);
		if(ret != TD_SUCCESS) {
			printf("Error(%#x),Create prevPyr[%u] image failed!\n", ret, i);
			goto lk_init_fail;
		}
		
        ret = sample_common_ive_create_image(&_lk_info->next_pyr[i], OT_SVP_IMG_TYPE_U8C1,
            _lk_info->prev_pyr[i].width, _lk_info->prev_pyr[i].height);
		if(ret != TD_SUCCESS) {
			printf("Error(%#x),Create nextPyr[%u] image failed!\n", ret, i);
			goto lk_init_fail;
		}
    }
	
    /* 初始化存储上帧特征点内存 */
    size = (td_u32)sizeof(ot_svp_point_s25q7) * _param->max_points_num;
    size = sample_common_ive_calc_stride(size, OT_IVE_ALIGN);
    ret = sample_common_ive_create_mem_info(&(_lk_info->prev_points), size);
	if(ret != TD_SUCCESS) {
		printf("Error(%#x),Create prevPts mem info failed!\n", ret);
		goto lk_init_fail;
	}	
	
    /*初始化存储当前帧特征点内存 */
    ret = sample_common_ive_create_mem_info(&(_lk_info->next_points), size);
	if(ret != TD_SUCCESS) {
		printf("Error(%#x),Create nextPts mem info failed!\n", ret);
		goto lk_init_fail;
	}	

    /* 初始化特征点状态 */
    size = (td_u32)sizeof(td_u8) * _param->max_points_num;
    size = sample_common_ive_calc_stride(size, OT_IVE_ALIGN);
    ret = sample_common_ive_create_mem_info(&(_lk_info->status), size);
	if(ret != TD_SUCCESS) {
		printf("Error(%#x),Create status mem info failed!\n", ret);
		goto lk_init_fail;
	}		
	
    /* 初始化特征点错误信息 */
    size = (td_u32)sizeof(td_u9q7) * _param->max_points_num;
    size = sample_common_ive_calc_stride(size, OT_IVE_ALIGN);
    ret = sample_common_ive_create_mem_info(&(_lk_info->err), size);
	if(ret != TD_SUCCESS) {
		printf("Error(%#x),Create err mem info failed!\n", ret);
		goto lk_init_fail;
	}

	return TD_SUCCESS;

lk_init_fail:
    if (ret != TD_SUCCESS) {
        wk_ive_st_lk_uninit(_lk_info);
    }
    return ret;
}

/* st相关参数初始化 */
static td_s32 _wk_ive_st_param_init(wk_ive_st_lk_info *_lk_info,  wk_ive_st_lk_param* _param)
{
    td_s32 ret;
    td_u32 size;
	ot_size _src_size = _param->frame_size;
		
    /* 初始化st特征点提取的图像源和输出 */
    ret = sample_common_ive_create_image(&_lk_info->src, OT_SVP_IMG_TYPE_U8C1, _src_size.width, _src_size.height);
	if(ret != TD_SUCCESS) {
		printf("Error(%#x),Create src image failed!\n", ret);
		goto st_init_fail;
	}

	//ret = sample_common_ive_create_image(&_lk_info->dst, OT_SVP_IMG_TYPE_U8C1, _src_size.width, _src_size.height);
    ret = sample_common_ive_create_image(&_lk_info->dst, OT_SVP_IMG_TYPE_U8C1, _src_size.width/2, _src_size.height/2); // 使用缩小1倍的分辨率
	if(ret != TD_SUCCESS) {
		printf("Error(%#x),Create dst image failed!\n", ret);
		goto st_init_fail;
	}

    _lk_info->cand_corner_ctrl.quality_level = _param->quality_level;
    size = (td_u32)sizeof(td_u32) * sample_common_ive_calc_stride(_src_size.width, OT_IVE_ALIGN) * _src_size.height +
        (td_u32)sizeof(ot_ive_st_max_eig_val);
    ret = sample_common_ive_create_mem_info(&(_lk_info->cand_corner_ctrl.mem), size);
	if(ret != TD_SUCCESS) {
		printf("Error(%#x),Create CandiCornerCtrl.stMem mem info failed!\n", ret);
		goto st_init_fail;
	}	

	/* 初始化存储特征点内存 */
    size = (td_u32)sizeof(ot_ive_st_corner_info);
    ret = sample_common_ive_create_mem_info(&(_lk_info->corner), size);
	if(ret != TD_SUCCESS) {
		printf("Error(%#x),Create corner mem info failed!\n", ret);
		goto st_init_fail;
	}	

    _lk_info->corner_ctrl.max_corner_num = _param->max_points_num;
    _lk_info->corner_ctrl.min_dist = _param->min_points_num;

	return TD_SUCCESS;
	
st_init_fail:
    if (ret != TD_SUCCESS) {
        wk_ive_st_lk_uninit(_lk_info);
    }
    return ret;
}


/* 光流提取特征点初始化 */
td_s32 wk_ive_st_lk_init(wk_ive_st_lk_info* _lk_info, wk_ive_st_lk_param* _param)
{
	td_s32 ret = OT_ERR_IVE_NULL_PTR;
	ot_size src_size = _param->frame_size;
    ot_size pyr_size = _param->frame_size;

	if(_param->max_level >  (WK_IVE_LK_PYR_NUM - 1)){
		printf("max_level can't be larger than %d", (WK_IVE_LK_PYR_NUM - 1));
		return TD_FAILURE;
	}

	memset(_lk_info, 0, sizeof(wk_ive_st_lk_info));
	_lk_info->frame_size = _param->frame_size;

    /* lk相关参数初始化 */
    ret = _wk_ive_lk_param_init(_lk_info, _param);
	if(ret != TD_SUCCESS) {
		printf("sample_ive_lk_param_init failed\n");
		return ret;
	}	

    /* st相关参数初始化 */
    ret = _wk_ive_st_param_init(_lk_info, _param);
	if(ret != TD_SUCCESS) {
		printf("sample_ive_st_param_init failed\n");
		return ret;
	}	

    /* 初始化输入st和lk图像源 */
    ret = sample_common_ive_create_image(&_lk_info->pyr_tmp, OT_SVP_IMG_TYPE_U8C1, pyr_size.width, pyr_size.height);
	if(ret != TD_SUCCESS) {
		printf("Error(%#x),Create pyrTmp image failed!\n", ret);
		goto st_lk_init_fail;
	}	
    ret = sample_common_ive_create_image(&_lk_info->src_yuv, _param->frame_type, src_size.width, src_size.height); 
	if(ret != TD_SUCCESS) {
		printf("Error(%#x),Create srcYuv image failed!\n", ret);
		goto st_lk_init_fail;
	}	
	
    return TD_SUCCESS;

st_lk_init_fail:
    if (ret != TD_SUCCESS) {
        wk_ive_st_lk_uninit(_lk_info);
    }
    return ret;
}

/* 资源释放 */
td_void wk_ive_st_lk_uninit(wk_ive_st_lk_info *_lk_info)
{
    td_u16 i;

	if(_lk_info == TD_NULL) {
		printf("param is null\n");
		return;
	}
    
    for (i = 0; i <= _lk_info->lk_pyr_ctrl.max_level; i++) {
        sample_svp_mmz_free(_lk_info->prev_pyr[i].phys_addr[0], _lk_info->prev_pyr[i].virt_addr[0]);
        sample_svp_mmz_free(_lk_info->next_pyr[i].phys_addr[0], _lk_info->next_pyr[i].virt_addr[0]);
    }

    sample_svp_mmz_free(_lk_info->prev_points.phys_addr, _lk_info->prev_points.virt_addr);
    sample_svp_mmz_free(_lk_info->next_points.phys_addr, _lk_info->next_points.virt_addr);
    sample_svp_mmz_free(_lk_info->status.phys_addr, _lk_info->status.virt_addr);
    sample_svp_mmz_free(_lk_info->err.phys_addr, _lk_info->err.virt_addr);

    sample_svp_mmz_free(_lk_info->src.phys_addr[0], _lk_info->src.virt_addr[0]);
    sample_svp_mmz_free(_lk_info->dst.phys_addr[0], _lk_info->dst.virt_addr[0]);
    sample_svp_mmz_free(_lk_info->corner.phys_addr, _lk_info->corner.virt_addr);

    sample_svp_mmz_free(_lk_info->cand_corner_ctrl.mem.phys_addr, _lk_info->cand_corner_ctrl.mem.virt_addr);

    sample_svp_mmz_free(_lk_info->pyr_tmp.phys_addr[0], _lk_info->pyr_tmp.virt_addr[0]);
    sample_svp_mmz_free(_lk_info->src_yuv.phys_addr[0], _lk_info->src_yuv.virt_addr[0]);
}



