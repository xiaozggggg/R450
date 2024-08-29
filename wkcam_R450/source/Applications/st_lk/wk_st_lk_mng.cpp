#include "wk_st_lk_mng.h"

#define WK_IVE_SENSOR_PIC_SIZE			PIC_640X480					/* sensor输出图像分辨率 */
#define WK_IVE_LK_D1_PIC_WIDTH          640   		            	/* st lk中使用的图像分辨率 */ 	
#define WK_IVE_LK_D1_PIC_HIGTH          512   		         
#define WK_IVE_ST_LK_SRC_FRAMW_TYPE		OT_SVP_IMG_TYPE_YUV420SP	/* 输入图像类型 */ 
#define WK_IVE_LK_MAX_LEVEL          	(WK_IVE_LK_PYR_NUM-1)       /* 金字塔层数 [0~3] */ 
#define WK_IVE_ST_QUALITY_LEVEL      	80							/* ST特征点质量控制参数 [1~255]*/
#define WK_IVE_ST_LK_MAX_POINTS_NUM     200        					/* 特征点个数最大值 */ 
#define WK_IVE_ST_LK_MIN_POINTS_NUM     20							/* 特征点相邻距离最小值 */
#define WK_IVE_LK_MIN_EIG_VALUE  		100							/* LK最小特征阈值 [1~255] */
#define WK_IVE_LK_ITER_CNT          	12							/* LK最大迭代次数 [1~20] */
#define WK_IVE_LK_EPS                	2							/* LK迭代收敛条件 [1~255] */

#define WK_IVE_SENSOR_VI_PIPE 			0							/* 下视sensor使用的VI PIPE */

typedef struct {
	/* 图像帧采集 */
	bool b_proc_running;
    pthread_t proc_id;
	ot_vpss_grp grp;
	ot_vpss_chn chn;
	pfun_wk_get_frame_cb _cb;

	/* st lk参数和数据 */
	wk_ive_st_lk_param st_lk_param;
	wk_ive_st_lk_info st_lk_infor;
}wk_st_lk_mng_info_s;


static wk_st_lk_mng_info_s g_st_lk_mng_info;


td_bool wk_st_lk_get_image_resolution(ot_size* _sensor_size)
{
	sample_comm_sys_get_pic_size(WK_IVE_SENSOR_PIC_SIZE, _sensor_size);
	return TD_TRUE;
}

td_bool wk_st_lk_get_points_num_max_min(td_u16* _max, td_u16* _min)
{
	*_max = WK_IVE_ST_LK_MAX_POINTS_NUM;
	*_min = WK_IVE_ST_LK_MIN_POINTS_NUM;
	return TD_TRUE;
}

/* 算法注册回调 */
td_bool wk_st_lk_register_get_frame_cb(pfun_wk_get_frame_cb _cb)
{
	if(_cb == NULL) {
		WK_LOGE("param is _cb null\n");
		return TD_FALSE;
	}

	g_st_lk_mng_info._cb = _cb;

	return TD_TRUE;
}

/* 图像帧释放 */
td_bool wk_st_lk_frame_release(ot_video_frame_info* _frame)
{
	wk_st_lk_mng_info_s* pmng = &g_st_lk_mng_info;
	
	ss_mpi_vpss_release_chn_frame(pmng->grp, pmng->chn, _frame);
	return TD_TRUE;
}


/* 光流定位参数初始化 */
static td_s32 _wk_st_lk_set_default_param(wk_ive_st_lk_param* _param)
{
	ot_size in_size;

	if(_param == NULL){
		return TD_FAILURE;
	}

	_param->frame_size.width = WK_IVE_LK_D1_PIC_WIDTH;
	_param->frame_size.height = WK_IVE_LK_D1_PIC_HIGTH;
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



/* 初始化状态处理 */
td_s32 wk_st_lk_status_inital_handle()
{
	td_s32 s32ret = -1;
	wk_st_lk_mng_info_s* pmng = &g_st_lk_mng_info;

	wk_ive_st_lk_uninit(&pmng->st_lk_infor);
	memset(&pmng->st_lk_infor, 0, sizeof(wk_ive_st_lk_info));

	usleep(5);
	
	_wk_st_lk_set_default_param(&pmng->st_lk_param);
	s32ret = wk_ive_st_lk_init(&pmng->st_lk_infor, &pmng->st_lk_param);
	return s32ret;
}


/* 动态设置st参数 */
td_bool wk_st_set_ctrl_param(td_u16 _quality_level, td_u16 _max_points_num, td_u16 _min_points_interval)
{
	wk_st_lk_mng_info_s* pmng = &g_st_lk_mng_info;

	if(_quality_level < 1 || _quality_level > 255){
		WK_LOGE("fail: param illegal, quality_level [1,255]\n");
		return TD_FALSE;
	}

	if(_max_points_num < 1 || _max_points_num > 500){
		WK_LOGE("fail: param illegal, max_points_num [1,500]\n");
		return TD_FALSE;
	}

	if(_min_points_interval < 1 || _min_points_interval > 255){
		WK_LOGE("fail: param illegal, min_points_interval [1,255]\n");
		return TD_FALSE;
	}
	
	pmng->st_lk_infor.cand_corner_ctrl.quality_level = _quality_level;
	pmng->st_lk_infor.corner_ctrl.max_corner_num = _max_points_num;
	pmng->st_lk_infor.corner_ctrl.min_dist = _min_points_interval;

	return TD_TRUE;
}

#if 0
/* s25q7转float */
static td_s32 _wk_s25q7_to_float(ot_svp_point_s25q7* _s25q7_val, wk_points_float_s* _float_val, td_u16 _cnt)
{
	td_float float_value = 0;

	for(td_u16 ifor=0; ifor<_cnt; ifor++)
	{
		/* 转换x坐标 */
	    float_value = copysignf((_s25q7_val[ifor].x & ~(1<<32))/128.0, (_s25q7_val[ifor].x >> 31) & 0x01);
		_float_val[ifor].x = float_value;

		/* 转换y坐标 */
	    float_value = copysignf((_s25q7_val[ifor].y & ~(1<<32))/128.0, (_s25q7_val[ifor].y >> 31) & 0x01);
		_float_val[ifor].y = float_value;
	}
	
	return TD_SUCCESS;
}

/* float转s25q7 */
static td_s32 _wk_float_to_s25q7(wk_points_float_s* _float_val, ot_svp_point_s25q7* _s25q7_val, td_u16 _cnt)
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


/* u9q7转float */
static td_s32 _wk_u9q7_to_float(td_u9q7* _u9q7, td_float* _float, td_u16 _cnt)
{
	td_s32 int_part = 0;		  
	td_s32 float_part = 0;	

	for(td_u16 ifor=0; ifor<_cnt; ifor++)
	{
	    int_part = (_u9q7[ifor] >> 7) & 0x1FF;         
	    float_part = _u9q7[ifor] & 0x7F;          
		_float[ifor] = int_part + float_part/128.0f;
	}	
	
	return TD_SUCCESS;
}
#else
/* s25q7转float */
static td_s32 _wk_s25q7_to_float(ot_svp_point_s25q7* _s25q7_val, wk_points_float_s* _float_val, td_u16 _cnt)
{
	td_float float_value = 0;
	td_s32 int_part = 0;		  
	td_s32 float_part = 0;	

	for(td_u16 ifor=0; ifor<_cnt; ifor++)
	{
		/* 转换x坐标 */
	    int_part = (_s25q7_val[ifor].x >> 7) & 0xFFFFFF;         
	    float_part = _s25q7_val[ifor].x & 0x7F;          
	    float_value = copysignf((float)int_part, (_s25q7_val[ifor].x >> 31) & 0x01);
	    float_value += (td_float)float_part / 128.0f;
		_float_val[ifor].x = float_value;

		/* 转换y坐标 */
		int_part = (_s25q7_val[ifor].y >> 7) & 0xFFFFFF;         
	    float_part = _s25q7_val[ifor].y & 0x7F;          
	    float_value = copysignf((float)int_part, (_s25q7_val[ifor].y >> 31) & 0x01);
	    float_value += (td_float)float_part / 128.0f;
		_float_val[ifor].y = float_value;
	}
	
	return TD_SUCCESS;
}

/* float转s25q7 */
static td_s32 _wk_float_to_s25q7(wk_points_float_s* _float_val, ot_svp_point_s25q7* _s25q7_val, td_u16 _cnt)
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



/* u9q7转float */
static td_s32 _wk_u9q7_to_float(td_u9q7* _u9q7, td_float* _float, td_u16 _cnt)
{
	td_s32 int_part = 0;		  
	td_s32 float_part = 0;	

	for(td_u16 ifor=0; ifor<_cnt; ifor++)
	{
	    int_part = (_u9q7[ifor] >> 7) & 0x1FF;         
	    float_part = _u9q7[ifor] & 0x7F;          
		_float[ifor] = int_part + float_part/128.0f;
	}	
	
	return TD_SUCCESS;
}
#endif

/* 通过st取点处理 */
td_s32 wk_st_get_points(ot_video_frame_info *_frame, wk_st_points_s* _points)
{
	td_s32 s32ret = TD_FAILURE;
	wk_st_lk_mng_info_s* pmng = &g_st_lk_mng_info;

	if(_frame == NULL || _points == NULL) {
		WK_LOGE("fail: wk_st_get_points param illegal\n");
		return TD_FAILURE;
	}

	uint32_t now_ms = system_time_ms_get();
	uint32_t last_ms = now_ms;
	int times = 0;

	s32ret = wk_ive_st_get_points(&pmng->st_lk_infor, _frame);
	if(s32ret == TD_SUCCESS){
		_points->points_cnt = pmng->st_lk_infor.points_cnt;
		_wk_s25q7_to_float(pmng->st_lk_infor.curr_corner_points, _points->points, _points->points_cnt);
	}

	now_ms = system_time_ms_get();
	times = get_delta_time(now_ms, last_ms);
	//WK_LOGI("### wk_st_get_points calculateC times ===> %d [%d]\n", times);
	
	return s32ret;
}

/* 动态设置lk参数 */
td_bool wk_lk_set_ctrl_param(td_u16 _min_eig_val, td_u16 _iter_cnt, td_u16 _eps)
{
	wk_st_lk_mng_info_s* pmng = &g_st_lk_mng_info;

	if(_min_eig_val < 1 || _min_eig_val > 255){
		WK_LOGE("fail: param illegal, _min_eig_val [1,255]\n");
		return TD_FALSE;
	}

	if(_iter_cnt < 1 || _iter_cnt > 20){
		WK_LOGE("fail: param illegal, _iter_cnt [1,20]\n");
		return TD_FALSE;
	}

	if(_eps < 1 || _eps > 255){
		WK_LOGE("fail: param illegal, min_points_interval [1,255]\n");
		return TD_FALSE;
	}
	
	pmng->st_lk_infor.lk_pyr_ctrl.min_eig_val_threshold = _min_eig_val;
	pmng->st_lk_infor.lk_pyr_ctrl.iter_cnt = _iter_cnt;
	pmng->st_lk_infor.lk_pyr_ctrl.eps = _eps;

	return TD_TRUE;
}


/* 通过lk取点处理*/
td_s32 wk_lk_get_points(wk_lk_points_input_s* _info, wk_lk_points_output_s* _points)
{
	td_s32 s32ret = -1;
	ot_svp_point_s25q7* prev_points = NULL;
	wk_st_lk_mng_info_s* pmng = &g_st_lk_mng_info;
	
	if(_info == NULL || _points == NULL) {
		WK_LOGE("fail: wk_st_get_points param illegal\n");
		return TD_FAILURE;
	}

	uint32_t now_ms = system_time_ms_get();
	uint32_t last_ms = now_ms;
	int times = 0;

	prev_points = (ot_svp_point_s25q7*)malloc(sizeof(ot_svp_point_s25q7)*500);
	if(prev_points == NULL) {
		WK_LOGE("malloc err\n");
		return TD_FAILURE;
	}
	memset(prev_points, 0, sizeof(ot_svp_point_s25q7)*500);

	_wk_float_to_s25q7(_info->prev_points, prev_points, _info->points_cnt);

	s32ret = wk_ive_lk_get_points(&pmng->st_lk_infor, _info->curr_frame, _info->prev_frame, prev_points, _info->points_cnt);
	if(s32ret == TD_SUCCESS) {
		_points->points_cnt = _info->points_cnt;
		_wk_s25q7_to_float(pmng->st_lk_infor.prev_corner_points, _points->prev_points, _points->points_cnt);
		_wk_s25q7_to_float(pmng->st_lk_infor.curr_corner_points, _points->curr_points, _points->points_cnt);
		memcpy(_points->status, pmng->st_lk_infor.curr_points_status, sizeof(pmng->st_lk_infor.curr_points_status));
		_wk_u9q7_to_float(pmng->st_lk_infor.curr_points_err, _points->err, _points->points_cnt);
	}

	now_ms = system_time_ms_get();
	times = get_delta_time(now_ms, last_ms);
	//WK_LOGI("### wk_lk_get_points calculateC times ===> %d [%d]\n", times);  

	free(prev_points);
	return s32ret;
}


/* 算法回调 */
void _wk_st_lk_get_frame_cb_handle(ot_vpss_grp grp, ot_vpss_chn chn, ot_video_frame_info* _frame)
{
	wk_corner_video_frame_s::wk_ptr frame_ptr(new wk_corner_video_frame_s);

	if(_frame == NULL) {
		WK_LOGE("param is _frame null\n");
		return;
	}
	
	ot_isp_exp_info exp;
	ss_mpi_isp_query_exposure_info(WK_IVE_SENSOR_VI_PIPE, &exp);

	frame_ptr->grp = grp;
	frame_ptr->chn = chn;
	frame_ptr->frame = *_frame;
	ss_mpi_sys_get_cur_pts(&frame_ptr->pts);
	frame_ptr->ave_lum = exp.ave_lum;

	if(g_st_lk_mng_info._cb != NULL){
		g_st_lk_mng_info._cb(frame_ptr);
	}

	return;
}

/* 线程函数 */
static void * _wk_st_lk_proc(void* _pArgs) 
{
	wk_st_lk_mng_info_s* pmng= (wk_st_lk_mng_info_s*)_pArgs;
	ot_video_frame_info st_frame_info;
	td_s32 ret = TD_SUCCESS;

	while(pmng->b_proc_running == TD_TRUE) {
		memset(&st_frame_info, 0, sizeof(st_frame_info));

		ret = ss_mpi_vpss_get_chn_frame(pmng->grp, pmng->chn, &st_frame_info, 1000);
		if(ret != TD_SUCCESS) {
			WK_LOGE("OT_MPI_VPSS_GetChnFrame grp:%d chn:%d err:0x%x\n", pmng->grp,  pmng->chn, ret);
			usleep(5*1000);
			continue;
		}

		/* 调用算法回调 */
		_wk_st_lk_get_frame_cb_handle(pmng->grp, pmng->chn, &st_frame_info);

		// ss_mpi_vpss_release_chn_frame(pmng->grp, pmng->chn, &st_frame_info); // 算法层释放
		// usleep(5*1000);
	}

	return NULL;
}

/* 开启光流功能处理 */
td_s32 wk_st_lk_start(ot_vpss_grp _grp, ot_vpss_chn _chn)
{
	td_s32 s32ret = -1;
	wk_st_lk_mng_info_s* pinfo = &g_st_lk_mng_info;

	if(pinfo->b_proc_running == TD_TRUE) {
		WK_LOGE("info: wk_st_lk_start already init!\n");
		return TD_SUCCESS;
	}

	/* ST LK 初始化 */
	_wk_st_lk_set_default_param(&pinfo->st_lk_param);
	s32ret = wk_ive_st_lk_init(&pinfo->st_lk_infor, &pinfo->st_lk_param);
	if(s32ret != TD_SUCCESS) {
		WK_LOGE("err: initial _wk_st_lk_proc create error, %d\n", s32ret);
		goto st_lk_init_err;
	}
	
	/* 开启获取图像 */
	pinfo->grp = _grp;
	pinfo->chn = _chn;
	pinfo->_cb = NULL;
	pinfo->b_proc_running = TD_TRUE;
	s32ret = pthread_create(&pinfo->proc_id, NULL, _wk_st_lk_proc, pinfo);
	if(s32ret < 0){
		WK_LOGE("err: initial _wk_st_lk_proc create error, %d\n", s32ret);
		goto frame_init_err;
	}

	WK_LOGI("info: wk_st_lk_app_start ok!\n");
	return TD_SUCCESS;
	
frame_init_err:
	wk_ive_st_lk_uninit(&pinfo->st_lk_infor);
st_lk_init_err:
	return s32ret;
}


/* 关闭光流功能处理 */
td_s32 wk_st_lk_stop()
{
	td_s32 s32ret = -1;
	wk_st_lk_mng_info_s* pinfo = &g_st_lk_mng_info;

	if(pinfo->b_proc_running == TD_FALSE) {
		WK_LOGE("info: wk_st_lk_app none init!\n");
		return TD_SUCCESS;
	}
	
	pinfo->b_proc_running = TD_FALSE;
	if(pinfo->proc_id != 0){
		s32ret = pthread_join(pinfo->proc_id, NULL);
	    if (s32ret != 0) {
	        WK_LOGE("err: join _wk_st_lk_get_frame_proc join error\r\n");
	        return s32ret;
	    }			
		pinfo->proc_id = 0;
	}

	wk_ive_st_lk_uninit(&pinfo->st_lk_infor);
	memset(&pinfo->st_lk_infor, 0, sizeof(wk_ive_st_lk_info));

	WK_LOGI("info: wk_st_lk_app_stop ok!\n");
	return TD_SUCCESS;
}



/* 协议处理函数 */
td_bool wk_st_lk_protocol_handle(wk_location_result_s* _result)
{
	uint16_t length;
    mavlink_message_t msg;
    uint8_t msgbuff[MAVLINK_MAX_PACKET_LEN];
    mavlink_wk_camera_visual_intertial_odometry_data_t wk_location_result;

	memset(&wk_location_result, 0, sizeof(mavlink_wk_camera_visual_intertial_odometry_data_t));
    wk_location_result.x = _result->x;
    wk_location_result.y = _result->y;
	wk_location_result.z = _result->z;
	memcpy(wk_location_result.quaternion, _result->q, sizeof(_result->q));
    wk_location_result.width = _result->frame->frame.video_frame.width;
    wk_location_result.height = _result->frame->frame.video_frame.height;
	wk_location_result.ave_lun = _result->frame->ave_lum;
	wk_location_result.corner = _result->corner_num;
	wk_location_result.timestamp = _result->frame->pts;
	
//    WK_LOGD("x[%f] y[%f] z[%f] q0[%f] q1[%f] q2[%f] q3[%f] W[%d] H[%d] ave_lun[%d] corner[%d] timestamp[%ld]\n",
//         wk_location_result.x, wk_location_result.y, wk_location_result.z, 
//    	 wk_location_result.quaternion[0], wk_location_result.quaternion[1], wk_location_result.quaternion[2], wk_location_result.quaternion[3],
//         wk_location_result.width, wk_location_result.height, 
//         wk_location_result.ave_lun, wk_location_result.corner, wk_location_result.timestamp);

#if 0
	uint32_t now_ms = system_time_ms_get();
	static uint32_t last_ms = 0;
	static uint32_t u32cnt = 0;
	u32cnt++;
	if(get_delta_time(now_ms, last_ms) >= 1000){
		WK_LOGF("u32cnt = %d, time = %d\n", u32cnt, now_ms-last_ms);
		u32cnt = 0;
		last_ms = now_ms;
	}
#endif

    mavlink_msg_wk_camera_visual_intertial_odometry_data_encode(MAVLINK_SYS_ID,WK_MODULE_TYPE_CAMERA, &msg, &wk_location_result);
    length = mavlink_msg_to_send_buffer(msgbuff,&msg);

#if 0
	mavlink_message_t wkmsg;
	mavlink_status_t  wkstatus;
	for(int ifor=0; ifor<length; ifor++) {
		if (mavlink_parse_char(0, msgbuff[ifor], &wkmsg, &wkstatus)) {
			if(wkmsg.msgid == MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA){
				mavlink_wk_camera_visual_intertial_odometry_data_t wk_result;
				mavlink_msg_wk_camera_visual_intertial_odometry_data_decode(&wkmsg, &wk_result);
				WK_LOGD("x[%f] y[%f] z[%f] q0[%f] q1[%f] q2[%f] q3[%f] W[%d] H[%d] ave_lun[%d] corner[%d] timestamp[%ld]\n",
					 wk_result.x, wk_result.y, wk_result.z, 
					 wk_result.quaternion[0], wk_result.quaternion[1], wk_result.quaternion[2], wk_result.quaternion[3],
					 wk_result.width, wk_result.height, 
					 wk_result.ave_lun, wk_result.corner, wk_result.timestamp);
			}
		}
	}
#endif

    CamSendHandle((char *)msgbuff,length);
	return TD_TRUE;
}


