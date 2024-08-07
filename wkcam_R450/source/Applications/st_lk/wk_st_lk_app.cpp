#include "wk_st_lk_app.h"

/* 文件实现：
1. 配置st lk参数，并初始化st lk 和帧处理
2. 运行图像帧获取线程
3. 对接算法中间层，为中间层提供接口，以及回调角点数据

1. 使用libwkmpp接口，实现ive提取关键点
2. 实现状态机，可让使用输出点数组的上层能随时控制识别状态（重新识别、继续使用金字塔识别、停止识别等）
3. 状态错误返回给应用层，由应用层决策处理(或者有应用层注册错误处理回调，发生错误使用回调进行处理)
4. 能进行输出venc调试

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

#define WK_ST_LK_ERROR_CNT				3							/* 允许ST LK处理错误次数 */

typedef struct {
	/* 线程id */
	bool b_proc_running;
    pthread_t proc_id;
	pthread_mutex_t mutex;
	
	/* vpss信息 */
	ot_vpss_grp grp;
	ot_vpss_chn chn;

	/* st lk参数和数据 */
	td_u8 u8_err_cnt;
	wk_ive_st_lk_param st_lk_param;
	wk_ive_st_lk_info st_lk_infor;

	/* 状态 */
	WK_CORNER_POINTS_STATUS_E  e_status;
}wk_st_lk_mng_info_s;


static wk_st_lk_mng_info_s g_st_lk_mng_info;


/*
* brief:和算法中间件对接的接口
*/

/* 获取到的点的写入中间层list */
static td_s32 _wk_st_lk_push_corner_points(wk_ive_st_lk_info* _info, td_bool _isbigan)
{	 
	wk_st_lk_corner_points* mid_ins = wk_st_lk_corner_points::wk_st_lk_corner_point_get_instance();
	wk_corner_points_s points;

	if(mid_ins == nullptr){
		return TD_FAILURE;
	}

	/* 点数据填充 */
	points.isbegin = _isbigan;
	points.points_cnt = _info->points_cnt;
	memcpy(points.prev_points, _info->prev_corner_points, sizeof(_info->prev_corner_points));
	memcpy(points.curr_points, _info->curr_corner_points, sizeof(_info->curr_corner_points));
	memcpy(points.status, _info->curr_points_status, sizeof(_info->curr_points_status));
	memcpy(points.err, _info->curr_points_err, sizeof(_info->curr_points_err));

	return mid_ins->wk_corner_points_list_push(&points);
}


td_bool wk_st_lk_get_image_resolution(td_u16* _width, td_u16* _hight)
{
	*_width = WK_IVE_LK_D1_WIDTH;
	*_hight = WK_IVE_LK_D1_HEIGHT;
	return TD_TRUE;
}

td_bool wk_st_lk_get_points_num_max_min(td_u16* _max, td_u16* _min)
{
	*_max = WK_IVE_ST_LK_MAX_POINTS_NUM;
	*_min = WK_IVE_ST_LK_MIN_POINTS_NUM;
	return TD_TRUE;
}

td_bool wk_st_lk_set_status(WK_CORNER_POINTS_STATUS_E _status)
{
	pthread_mutex_lock(&g_st_lk_mng_info.mutex);
	g_st_lk_mng_info.e_status = _status;
	pthread_mutex_unlock(&g_st_lk_mng_info.mutex);
	return TD_TRUE;
}

WK_CORNER_POINTS_STATUS_E wk_st_lk_get_status()
{
	return g_st_lk_mng_info.e_status;
}

/* 协议处理函数 */
td_bool wk_st_lk_protocol_handle(wk_location_result_s* _result)
{

	return TD_TRUE;
}


 /*
 * brief:光流取点状态处理
 */

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

/* 初始化状态处理 */
static td_s32 _wk_st_lk_status_inital_handle(wk_st_lk_mng_info_s* _pmng)
{
	td_s32 s32ret = -1;

	if(_pmng == NULL)	{
		return TD_FAILURE;
	}

	wk_ive_st_lk_uninit(&_pmng->st_lk_infor);
	memset(&_pmng->st_lk_infor, 0, sizeof(wk_ive_st_lk_info));

	usleep(100);
	
	_wk_st_lk_set_default_param(&_pmng->st_lk_param);
	s32ret = wk_ive_st_lk_init(&_pmng->st_lk_infor, &_pmng->st_lk_param);
	return s32ret;
}

/* 通过st取点处理 */
static td_s32 _wk_st_lk_status_st_get_points_handle(ot_video_frame_info *_frame, wk_st_lk_mng_info_s* _pmng)
{
	td_s32 s32ret = -1;

	s32ret = wk_ive_st_get_points(&_pmng->st_lk_infor, _frame);
	if(s32ret == TD_SUCCESS){
		_wk_st_lk_push_corner_points(&_pmng->st_lk_infor, TD_TRUE);
		
		#ifdef DEBUG_ST_LK_POINTS_PREVIEW
		ot_svp_point_s25q7* points = NULL;
		td_u32 points_num = 0;
		wk_ive_st_lk_get_points(&_pmng->st_lk_infor, &points, &points_num);
		wk_st_lk_vgs_draw_ponits_send_venc_debug(_frame, points, points_num);
		#endif			
	}
	return s32ret;
}

/* 通过lk取点处理*/
static td_s32 _wk_st_lk_status_lk_get_points_handle(ot_video_frame_info *_frame, wk_st_lk_mng_info_s* _pmng)
{
	td_s32 s32ret = -1;

	s32ret = wk_ive_lk_get_points(&_pmng->st_lk_infor, _frame);
	if(s32ret == TD_SUCCESS){
		_wk_st_lk_push_corner_points(&_pmng->st_lk_infor, TD_FALSE);

		#ifdef DEBUG_ST_LK_POINTS_PREVIEW
		/* 获取到点后的处理 */
		ot_svp_point_s25q7* points = NULL;
		td_u32 points_num = 0;
		wk_ive_st_lk_get_points(&_pmng->st_lk_infor, &points, &points_num);
		wk_st_lk_vgs_draw_ponits_send_venc_debug(_frame, points, points_num);
		#endif		
	}
	return s32ret;
}

/* 取点暂停处理 */
static td_s32 _wk_st_lk_status_pause_handle(ot_video_frame_info *_frame, wk_st_lk_mng_info_s* _pmng)
{
	if(_frame == NULL || _pmng == NULL)	{
		return TD_FAILURE;
	}
	
	return TD_SUCCESS;	
}

/* 发生错误处理 */
static td_s32 _wk_st_lk_status_error_handle()
{
	uint32_t now_ms = system_time_ms_get();
	static uint32_t last_ms;

	if(get_delta_time(now_ms, last_ms) > 3000) {
		last_ms = now_ms;
		printf("===== ST LK ERROR, PLEASE CHECK IT ======\n");
	}
	
	return TD_SUCCESS;	
}


/* 获取点处理，需要考虑状态机 */
static void _wk_st_lk_get_frame_handle(ot_video_frame_info *_frame, wk_st_lk_mng_info_s* _pmng)
{
	td_s32 s32errno = -1;

	uint32_t now_ms = system_time_ms_get();
	uint32_t last_ms = now_ms;
	int times = 0;

	pthread_mutex_lock(&_pmng->mutex);

rehandle:
	/* 状态处理 */
	switch (_pmng->e_status)
	{
		case WK_CORNER_POINTS_STATUS_INITIAL:
			s32errno = _wk_st_lk_status_inital_handle(_pmng);
			if(s32errno == TD_SUCCESS){
				_pmng->e_status = WK_CORNER_POINTS_STATUS_START_GET_POINTS;
			}			
			break;
		case WK_CORNER_POINTS_STATUS_START_GET_POINTS:
			s32errno = _wk_st_lk_status_st_get_points_handle(_frame, _pmng);
			if(s32errno == TD_SUCCESS){
				_pmng->e_status = WK_CORNER_POINTS_STATUS_GETTING_POINTS;
			}
			break;
		case WK_CORNER_POINTS_STATUS_GETTING_POINTS:
			s32errno = _wk_st_lk_status_lk_get_points_handle(_frame, _pmng);
			break;
		case WK_CORNER_POINTS_STATUS_PAUSE:
			s32errno = _wk_st_lk_status_pause_handle(_frame, _pmng);
			break;
		case WK_CORNER_POINTS_STATUS_ERROR:
			_wk_st_lk_status_error_handle();
			break;
		default:
			break;
	}

	/* 错误处理 */
	if(s32errno != TD_SUCCESS) {
		printf("error: st lk run-time error. _stauts = %d, _errno = %d!!!!!!\n", _pmng->e_status, s32errno);

		if(_pmng->u8_err_cnt <= WK_ST_LK_ERROR_CNT) {
			_pmng->u8_err_cnt++;
			if(_pmng->e_status == WK_CORNER_POINTS_STATUS_GETTING_POINTS) {
				printf("info: reopen ST corner points\n");
				_pmng->e_status = WK_CORNER_POINTS_STATUS_START_GET_POINTS;
				goto rehandle;
			}
			else if(_pmng->e_status == WK_CORNER_POINTS_STATUS_START_GET_POINTS ||
				_pmng->e_status == WK_CORNER_POINTS_STATUS_INITIAL) {
				printf("info: reopen init corner points\n");
				_pmng->e_status = WK_CORNER_POINTS_STATUS_INITIAL;
				goto rehandle;
			}	
		}
		else{
			_pmng->e_status = WK_CORNER_POINTS_STATUS_ERROR;
		}
	}
	else{
		_pmng->u8_err_cnt = 0;
	}
	
	pthread_mutex_unlock(&_pmng->mutex);

	now_ms = system_time_ms_get();
	times = get_delta_time(now_ms, last_ms);
	//printf("-----------------------### calculateC times ===> %d [%d]\n", times);  

	return;
}



/* 线程函数 */
static void * _wk_st_lk_proc(void* _pArgs) 
{
	wk_st_lk_mng_info_s* pmng= (wk_st_lk_mng_info_s*)_pArgs;
	ot_video_frame_info st_frame_info;
	td_s32 ret = TD_SUCCESS;

	sleep(3);
	while(pmng->b_proc_running == TD_TRUE) {
		memset(&st_frame_info, 0, sizeof(st_frame_info));

		ret = ss_mpi_vpss_get_chn_frame(pmng->grp, pmng->chn, &st_frame_info, 1000);
		if(ret != TD_SUCCESS) {
			//printf("OT_MPI_VPSS_GetChnFrame grp:%d chn:%d err:0x%x\n", pmng->grp,  pmng->chn, ret);
			usleep(5*1000);
			continue;
		}

		_wk_st_lk_get_frame_handle(&st_frame_info, pmng);
		
		ss_mpi_vpss_release_chn_frame(pmng->grp, pmng->chn, &st_frame_info);
		usleep(5*1000);
	}

	return NULL;
}

/* 开启光流功能处理 */
td_s32 wk_st_lk_start(ot_vpss_grp _grp, ot_vpss_chn _chn)
{
	td_s32 s32ret = -1;
	wk_st_lk_mng_info_s* pinfo = &g_st_lk_mng_info;

	if(pinfo->b_proc_running == TD_TRUE) {
		printf("info: wk_st_lk_start already init!\n");
		return TD_SUCCESS;
	}

	/* ST LK 初始化 */
	_wk_st_lk_set_default_param(&pinfo->st_lk_param);
	pinfo->e_status = WK_CORNER_POINTS_STATUS_START_GET_POINTS;
	s32ret = wk_ive_st_lk_init(&pinfo->st_lk_infor, &pinfo->st_lk_param);
	if(s32ret != TD_SUCCESS) {
		printf("err: initial _wk_st_lk_proc create error, %d\n", s32ret);
		goto st_lk_init_err;
	}

	s32ret = pthread_mutex_init(&pinfo->mutex, NULL);
	if(s32ret != 0) {
		printf("err: s32ret is %d\n", s32ret);
		goto mutex_init_err;
	}
	
	/* 开启获取图像 */
	pinfo->grp = _grp;
	pinfo->chn = _chn;
	pinfo->b_proc_running = TD_TRUE;
	s32ret = pthread_create(&pinfo->proc_id, NULL, _wk_st_lk_proc, pinfo);
	if(s32ret < 0){
		printf("err: initial _wk_st_lk_proc create error, %d\n", s32ret);
		goto frame_init_err;
	}

	printf("info: wk_st_lk_app_start ok!\n");
	return TD_SUCCESS;
	
frame_init_err:
	pthread_mutex_destroy(&pinfo->mutex);
mutex_init_err:	
	wk_ive_st_lk_uninit(&pinfo->st_lk_infor);
	pinfo->e_status = WK_CORNER_POINTS_STATUS_INITIAL;
st_lk_init_err:
	return s32ret;
}


/* 关闭光流功能处理 */
td_s32 wk_st_lk_stop()
{
	td_s32 s32ret = -1;
	wk_st_lk_mng_info_s* pinfo = &g_st_lk_mng_info;

	if(pinfo->b_proc_running == TD_FALSE) {
		printf("info: wk_st_lk_app none init!\n");
		return TD_SUCCESS;
	}
	
	pinfo->b_proc_running = TD_FALSE;
	if(pinfo->proc_id != 0){
		s32ret = pthread_join(pinfo->proc_id, NULL);
	    if (s32ret != 0) {
	        printf("err: join _wk_st_lk_get_frame_proc join error\r\n");
	        return s32ret;
	    }			
		pinfo->proc_id = 0;
	}

	pthread_mutex_destroy(&pinfo->mutex);
	
	wk_ive_st_lk_uninit(&pinfo->st_lk_infor);
	pinfo->e_status = WK_CORNER_POINTS_STATUS_INITIAL;
	memset(&pinfo->st_lk_infor, 0, sizeof(wk_ive_st_lk_info));

	printf("info: wk_st_lk_app_stop ok!\n");
	return TD_SUCCESS;
}


