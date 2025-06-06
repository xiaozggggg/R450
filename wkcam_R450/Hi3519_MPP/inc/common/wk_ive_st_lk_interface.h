#ifndef __WK_IVE_ST_LK_INTERFACE_H__
#define __WK_IVE_ST_LK_INTERFACE_H__

#include <stdio.h>
#include <unistd.h>
#include <math.h>

#include "sample_comm.h"
#include "sample_common_ive.h"


#ifdef __cplusplus
extern "C" {
#endif

#define WK_IVE_LK_PYR_NUM            4  		 // 金字塔层数数组个数

/* ive st lk 运行时存储临时数据的数据结构 */
typedef struct {
	/* 用于光流金字塔lk算法，特征点提取 */
    ot_svp_src_img prev_pyr[WK_IVE_LK_PYR_NUM];  		// 前帧图像金字塔图像数组
    ot_svp_src_img next_pyr[WK_IVE_LK_PYR_NUM];  		// 后帧图像金字塔图像数组
    ot_svp_src_mem_info prev_points;   					// （用于保存前一帧特征点）前帧图像特征点
    ot_svp_mem_info next_points;       					// （用于保存当前帧特征点）prev_pts和下帧经过lk光流得到的图像特征点
    ot_svp_dst_mem_info status;     					// next_pts每个特征点追踪状态信息（1：成功, 0:表示失败）   
    ot_svp_dst_mem_info err;        					// next_pts中追踪成功的特征点，对于prev_pts的特征点误差评估
    ot_ive_lk_optical_flow_pyr_ctrl lk_pyr_ctrl;  		// 光流功能配置参数

	/* 用于st特征点提取 */
    ot_svp_src_img src;     							// 图片源
    ot_svp_img dst;         							// 图片输出
    ot_svp_dst_mem_info corner;  						// 角点数据
    ot_ive_st_cand_corner_ctrl cand_corner_ctrl;  		// st选角点计算控制参数
    ot_ive_st_corner_ctrl corner_ctrl;   				// st角点筛选控制参数

	/* 用于图像数据源 */
	ot_size frame_size;  	 // 图像源大小
    ot_svp_img pyr_tmp;
    ot_svp_img src_yuv;   	 // 输入图片

	/* 保存输出点数据 */
	ot_svp_point_s25q7 prev_corner_points[500];   		// 保存上一帧输出的角点
	ot_svp_point_s25q7 curr_corner_points[500];         // 保存当前帧输出角点
	td_u32	points_cnt;							        // 角点数量
	td_u8 curr_points_status[500];                      // 当前帧角点状态
	td_u9q7 curr_points_err[500];	                    // 当前帧已跟踪点的误差
} wk_ive_st_lk_info;

/* ive st lk 配置参数 */
typedef struct {
	ot_size frame_size;  			 // 图像源大小
	ot_svp_img_type frame_type; 	 // 图像源类型
	
	td_u16 max_points_num;           // 提取特征点个数最大值
    td_u16 min_points_num;			 // 提取特征点个数最小值
	
	td_u8 max_level;	 			 // 金字塔层数
	td_u0q8 min_eig_val;			 // 最小特征阈值
	td_u8 iter_cnt;                  // 最大迭代次数
    td_u0q8 eps;					 // 迭代收敛条件
		
	td_u0q8 quality_level;           // st特征点质量控制参数
}wk_ive_st_lk_param;


/* 光流提取特征点初始化 */
td_s32 wk_ive_st_lk_init(wk_ive_st_lk_info* _lk_info, wk_ive_st_lk_param* _param);

/* 资源释放 */
td_void wk_ive_st_lk_uninit(wk_ive_st_lk_info* _lk_info);

/* 通过st提取特征点 */
td_s32 wk_ive_st_get_points(wk_ive_st_lk_info *_lk_info, ot_video_frame_info *_frame);

/* 通过lk提取特征点 */
td_s32 wk_ive_lk_get_points(wk_ive_st_lk_info *_lk_info, 
								ot_video_frame_info *_curr_frame, 
								ot_video_frame_info *_prev_frame,
								ot_svp_point_s25q7* _prev_points_src,
								td_u16 _points_num);

/* 创建用户帧 */
td_s32 _wk_create_user_frame(ot_size *dst_size, sample_vi_user_frame_info *user_frame_info);
/* 释放用户帧 */
td_void _wk_create_user_release_frame_blk(sample_vi_user_frame_info user_frame_info[], td_s32 frame_cnt);
/* 缩放图像帧 */
td_s32 _wk_scale_task(ot_video_frame_info *src_frame, ot_video_frame_info *dst_frame);



#ifdef __cplusplus
}
#endif

#endif /* __WK_IVE_ST_LK_INTERFACE_H__ */
