/*
  Copyright (c), 2001-2021, Shenshu Tech. Co., Ltd.
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "ot_mpi_isp.h"
#include "ot_mpi_ae.h"
#include "ot_mpi_awb.h"
#include "securec.h"
#include "ov7251_cmos_ex.h"
#include "ov7251_cmos.h"

#define OV7251_ID                    77
#define SENSOR_OV7251_WIDTH          640
#define SENSOR_OV7251_HEIGHT         480
#define OV7251_BLACK_LEVEL           (0x400)
#define OV7251_RATIO                 64

#define higher_4bits(x) (((x) & 0xf0000) >> 16)
#define high_8bits(x) (((x) & 0xff00) >> 8)
#define low_8bits(x)  ((x) & 0x00ff)

/****************************************************************************
 * global variables                                                            *
 ****************************************************************************/
#define OV7251_sensor_get_ctx(dev, ctx)   ((ctx) = ov7251_get_ctx(dev))
#define ov7251_sensor_set_ctx(dev, ctx)   ((g_ov7251_sns_state[dev]) = (ctx))
#define ov7251_sensor_reset_ctx(dev)      (g_ov7251_sns_state[dev] = TD_NULL)

static ot_isp_fswdr_mode g_fswdr_mode[OT_ISP_MAX_PIPE_NUM] = {
    [0 ... OT_ISP_MAX_PIPE_NUM - 1] = OT_ISP_FSWDR_NORMAL_MODE
};

static td_u8 g_ae_stat_pos[OT_ISP_MAX_PIPE_NUM] = {0};

static td_u32 g_max_time_get_cnt[OT_ISP_MAX_PIPE_NUM] = {0};
static td_u32 g_init_exposure[OT_ISP_MAX_PIPE_NUM]  = {0};
static td_u32 g_lines_per500ms[OT_ISP_MAX_PIPE_NUM] = {0};

static td_u16 g_init_wb_gain[OT_ISP_MAX_PIPE_NUM][OT_ISP_RGB_CHN_NUM] = {{0}};
static td_u16 g_sample_r_gain[OT_ISP_MAX_PIPE_NUM] = {0};
static td_u16 g_sample_b_gain[OT_ISP_MAX_PIPE_NUM] = {0};
static td_bool g_quick_start_en[OT_ISP_MAX_PIPE_NUM] = {TD_FALSE};

static td_bool g_ae_route_ex_valid[OT_ISP_MAX_PIPE_NUM] = {0};
static ot_isp_ae_route g_init_ae_route[OT_ISP_MAX_PIPE_NUM] = {{0}};
static ot_isp_ae_route_ex g_init_ae_route_ex[OT_ISP_MAX_PIPE_NUM] = {{0}};
static ot_isp_ae_route g_init_ae_route_sf[OT_ISP_MAX_PIPE_NUM] = {{0}};
static ot_isp_ae_route_ex g_init_ae_route_sf_ex[OT_ISP_MAX_PIPE_NUM] = {{0}};

typedef struct {
    td_u8       hcg;
    td_u32      brl;
    td_u32      rhs1_max;
    td_u32      delta_rhs1;
} ov7251_state;

ov7251_state g_ov7251_state[OT_ISP_MAX_PIPE_NUM] = {{0}};
ot_isp_sns_commbus g_ov7251_bus_info[OT_ISP_MAX_PIPE_NUM] = {
    [0] = { .i2c_dev = 0},
    [1 ... OT_ISP_MAX_PIPE_NUM - 1] = { .i2c_dev = -1}
};

ot_isp_sns_state *g_ov7251_sns_state[OT_ISP_MAX_PIPE_NUM] = {TD_NULL};

static td_bool blc_clamp_info[OT_ISP_MAX_PIPE_NUM] = {[0 ...(OT_ISP_MAX_PIPE_NUM - 1)] = TD_TRUE};

ot_isp_sns_commbus *ov7251_get_bus_info(ot_vi_pipe vi_pipe)
{
    return &g_ov7251_bus_info[vi_pipe];
}

ot_isp_sns_state *ov7251_get_ctx(ot_vi_pipe vi_pipe)
{
    return g_ov7251_sns_state[vi_pipe];
}

td_void ov7251_set_blc_clamp_value(ot_vi_pipe vi_pipe, td_bool clamp_en)
{
    blc_clamp_info[vi_pipe] = clamp_en;
}

#define OV7251_MAX_FPS	60

const ov7251_video_mode_tbl g_ov7251_mode_tbl[OV7251_MODE_BUTT] = {
    {OV7251_VMAX_480P20_LINEAR_10BIT,   OV7251_FULL_LINES_MAX,          OV7251_MAX_FPS, 0.8,
     640, 480, 0, OT_WDR_MODE_NONE,       "OV7251_SENSOR_480P_60FPS_LINEAR_10BIT"},
};

/****************************************************************************
 * local variables                                                            *
 ****************************************************************************/
/* Imx327 Register Address */
#define OV7251_SHR0_ADDR                  0x3502   // 曝光寄存器

#define OV7251_AGAIN_ADDR_H				  0x3504   // 模拟增益
#define OV7251_AGAIN_ADDR_L				  0x3505

#define OV7251_DGAIN_ADDR_H				  0x350A   // 数字增益
#define OV7251_DGAIN_ADDR_L               0x350B

#define OV7251_PRSH_LENGTH                0x3f3b

#define OV7251_DGAIN_CTL		          0x3ff9
#define OV7251_AGAIN_ADDR                 0x3ff8
#define OV7251_DGAIN_ADDR                 0x020f

#define OV7251_VMAX_ADDR                  0x0341

/* sensor gain */
#define OV7251_AGAIN_MAX                  8096    /* the max again is 31356 */
#define OV7251_DGAIN_MAX                  (8096-1)/* the max dgain is 128913 */

#define OV7251_AGAIN_21X    (21504)

#define OV7251_DGAIN_1X     (1024)
#define OV7251_DGAIN_8X     (8192)
#define OV7251_DGAIN_9X     (9216)
#define OV7251_DGAIN_10X    (10240)
#define OV7251_DGAIN_11X    (11264)
#define OV7251_DGAIN_12X    (12288)
#define OV7251_DGAIN_13X    (13312)
#define OV7251_DGAIN_14X    (14336)
#define OV7251_DGAIN_15X    (15360)
#define OV7251_DGAIN_16X    (16384-1)


static td_u32  g_au32AGain[OT_ISP_MAX_PIPE_NUM] = { [0 ...(OT_ISP_MAX_PIPE_NUM - 1)] = 1024 }; /* again 1024 */
static td_u32  g_au32DGain[OT_ISP_MAX_PIPE_NUM] = { [0 ...(OT_ISP_MAX_PIPE_NUM - 1)] = 1024 }; /* dgain 1024 */




#define ov7251_err_mode_print(sns_image_mode, sns_state) \
    do { \
        isp_err_trace("Not support! Width:%d, Height:%d, Fps:%f, WDRMode:%d\n", \
                      (sns_image_mode)->width,  \
                      (sns_image_mode)->height, \
                      (sns_image_mode)->fps,    \
                      (sns_state)->wdr_mode); \
    } while (0)

static td_void cmos_get_ae_comm_default(ot_vi_pipe vi_pipe, ot_isp_ae_sensor_default *ae_sns_dft,
    const ot_isp_sns_state *sns_state)
{
    ae_sns_dft->full_lines_std = sns_state->fl_std;
    ae_sns_dft->flicker_freq = 50 * 256; /* light flicker freq: 50Hz, accuracy: 256 */
    ae_sns_dft->full_lines_max = OV7251_FULL_LINES_MAX;
    ae_sns_dft->hmax_times = (1000000000) / (sns_state->fl_std * OV7251_MAX_FPS); /* 1000000000ns, 30fps */

    ae_sns_dft->again_accu.accu_type = OT_ISP_AE_ACCURACY_TABLE;
    ae_sns_dft->again_accu.accuracy  = 1;
	ae_sns_dft->int_time_accu.offset = 0;

    ae_sns_dft->dgain_accu.accu_type = OT_ISP_AE_ACCURACY_TABLE;
    ae_sns_dft->dgain_accu.accuracy = 1;

    ae_sns_dft->isp_dgain_shift = 8; /* accuracy: 8 */
    ae_sns_dft->min_isp_dgain_target = 1 << ae_sns_dft->isp_dgain_shift;
    ae_sns_dft->max_isp_dgain_target = 4 << ae_sns_dft->isp_dgain_shift; /* max 2 */
    if (g_lines_per500ms[vi_pipe] == 0) {
        ae_sns_dft->lines_per500ms = sns_state->fl_std * OV7251_MAX_FPS / 2; /* 30fps, div 2 */
    } else {
        ae_sns_dft->lines_per500ms = g_lines_per500ms[vi_pipe];
    }

    ae_sns_dft->max_iris_fno = OT_ISP_IRIS_F_NO_1_0;
    ae_sns_dft->min_iris_fno = OT_ISP_IRIS_F_NO_32_0;

    ae_sns_dft->ae_route_ex_valid = TD_FALSE;
    ae_sns_dft->ae_route_attr.total_num = 0;
    ae_sns_dft->ae_route_attr_ex.total_num = 0;
    ae_sns_dft->quick_start.quick_start_enable = g_quick_start_en[vi_pipe];
    ae_sns_dft->quick_start.black_frame_num = 0;
	ae_sns_dft->ae_stat_pos = g_ae_stat_pos[vi_pipe]; /* 1 use be stat to AE */
	
    return;
}

static td_void cmos_get_ae_linear_default(ot_vi_pipe vi_pipe, ot_isp_ae_sensor_default *ae_sns_dft,
    const ot_isp_sns_state *sns_state)
{
    ae_sns_dft->int_time_accu.accu_type = OT_ISP_AE_ACCURACY_LINEAR;
    ae_sns_dft->int_time_accu.accuracy = 1; /* accuracy 2 */
    ae_sns_dft->int_time_accu.offset = 0.11;

    ae_sns_dft->max_again = OV7251_AGAIN_MAX; /* max 62416 */
    ae_sns_dft->min_again = 1024; /* min 1024 */
    ae_sns_dft->max_again_target = ae_sns_dft->max_again;
    ae_sns_dft->min_again_target = ae_sns_dft->min_again;

    ae_sns_dft->max_dgain = 1024; //OV7251_DGAIN_MAX; /* max 1024 */
    ae_sns_dft->min_dgain = 1024; /* min 1024 */
    ae_sns_dft->max_dgain_target = ae_sns_dft->max_dgain;
    ae_sns_dft->min_dgain_target = ae_sns_dft->min_dgain;

    ae_sns_dft->isp_dgain_shift = 8; /* accuracy: 8 */
    ae_sns_dft->min_isp_dgain_target = 1 << ae_sns_dft->isp_dgain_shift;
    ae_sns_dft->max_isp_dgain_target = 1 << ae_sns_dft->isp_dgain_shift; /* max 255 */

    ae_sns_dft->ae_compensation = 0x38;
    ae_sns_dft->ae_exp_mode = OT_ISP_AE_EXP_HIGHLIGHT_PRIOR;
    ae_sns_dft->init_exposure = g_init_exposure[vi_pipe] ? g_init_exposure[vi_pipe] : 76151; /* init 76151 */

    ae_sns_dft->max_int_time = sns_state->fl_std - 2; /* sub 6 */
    ae_sns_dft->min_int_time = 3; /* min 2 */
    ae_sns_dft->max_int_time_target = 65535; /* max 65535 */
    ae_sns_dft->min_int_time_target = 3; /* min 1 */
    ae_sns_dft->ae_route_ex_valid = g_ae_route_ex_valid[vi_pipe];
    (td_void)memcpy_s(&ae_sns_dft->ae_route_attr, sizeof(ot_isp_ae_route),
                      &g_init_ae_route[vi_pipe],  sizeof(ot_isp_ae_route));
    (td_void)memcpy_s(&ae_sns_dft->ae_route_attr_ex, sizeof(ot_isp_ae_route_ex),
                      &g_init_ae_route_ex[vi_pipe], sizeof(ot_isp_ae_route_ex));
    return;
}

static td_s32 cmos_get_ae_default(ot_vi_pipe vi_pipe, ot_isp_ae_sensor_default *ae_sns_dft)
{
    ot_isp_sns_state *sns_state = TD_NULL;

    sns_check_pointer_return(ae_sns_dft);
    OV7251_sensor_get_ctx(vi_pipe, sns_state);
    sns_check_pointer_return(sns_state);

    (td_void)memset_s(&ae_sns_dft->ae_route_attr, sizeof(ot_isp_ae_route), 0, sizeof(ot_isp_ae_route));

    cmos_get_ae_comm_default(vi_pipe, ae_sns_dft, sns_state);

    switch (sns_state->wdr_mode) {
        case OT_WDR_MODE_NONE:   /* linear mode */
            cmos_get_ae_linear_default(vi_pipe, ae_sns_dft, sns_state);
            break;
        default:
            cmos_get_ae_linear_default(vi_pipe, ae_sns_dft, sns_state);
            break;
    }

    return TD_SUCCESS;
}

/* 换算成曝光时间 */
static td_u32 cmos_vmax2inttime(ot_isp_sns_state *sns_state, td_u32 vmax)
{
	td_u32 lines, lines_max, vmax_tmp;
	td_float max_fps, min_fps;
	const td_u32 fps = OV7251_MAX_FPS;
	td_u32 inttime_max = 0;  // 最大曝光时间
	td_u32 int_time = 0; 

	if(OV7251_MAX_FPS == 30) {
		inttime_max = (1000000/OV7251_MAX_FPS)*0.9;
	}
	else{
		inttime_max = (1000000/OV7251_MAX_FPS)*0.82;
	}

    lines = g_ov7251_mode_tbl[sns_state->img_mode].ver_lines;
    lines_max = g_ov7251_mode_tbl[sns_state->img_mode].max_ver_lines;
    max_fps = g_ov7251_mode_tbl[sns_state->img_mode].max_fps;
    min_fps = g_ov7251_mode_tbl[sns_state->img_mode].min_fps;

    vmax_tmp = lines * max_fps / fps;
    vmax_tmp = (vmax_tmp > lines_max) ? lines_max : vmax_tmp;
    vmax_tmp = vmax_tmp + vmax_tmp % 2; /* mod 2 */

	int_time = (inttime_max/(td_float)vmax_tmp) * vmax;  

	//printf("------- inttime_max = %d, vmax_tmp =%d, vmax = %d, int_time = %x\n", inttime_max, vmax_tmp, vmax, int_time);
	return int_time;
}

static td_void cmos_config_vmax(ot_isp_sns_state *sns_state, td_u32 vmax)
{
    if (sns_state->wdr_mode == OT_WDR_MODE_NONE) {
		td_u32 inttime_prev = ((sns_state->regs_info[0].i2c_data[0].data & 0xff) << 8) | (sns_state->regs_info[0].i2c_data[1].data & 0xff);
		td_u32 inttime_curr = cmos_vmax2inttime(sns_state, vmax);
		if(inttime_prev != inttime_curr){
			sns_state->regs_info[0].i2c_data[0].data = high_8bits(inttime_curr); 
			sns_state->regs_info[0].i2c_data[1].data = low_8bits(inttime_curr); 
		}
    }

    return;
}

static td_void cmos_fps_set(ot_vi_pipe vi_pipe, td_float fps, ot_isp_ae_sensor_default *ae_sns_dft)
{
    td_u32 lines, lines_max, vmax;
    td_bool achieve_fps_flag;
    td_float max_fps, min_fps;
    ot_isp_sns_state *sns_state = TD_NULL;

    sns_check_pointer_void_return(ae_sns_dft);
    OV7251_sensor_get_ctx(vi_pipe, sns_state);
    sns_check_pointer_void_return(sns_state);

    lines = g_ov7251_mode_tbl[sns_state->img_mode].ver_lines;
    lines_max = g_ov7251_mode_tbl[sns_state->img_mode].max_ver_lines;
    max_fps = g_ov7251_mode_tbl[sns_state->img_mode].max_fps;
    min_fps = g_ov7251_mode_tbl[sns_state->img_mode].min_fps;

    if ((fps > max_fps) || (fps < min_fps)) {
        isp_err_trace("Not support Fps: %f\n", fps);
        return;
    }
	
    achieve_fps_flag = TD_TRUE;
    vmax = lines * max_fps / div_0_to_1_float(fps);
    {
        vmax = (vmax > lines_max) ? lines_max : vmax;
        vmax = vmax + vmax % 2; /* mod 2 */
        cmos_config_vmax(sns_state, vmax);
        sns_state->fl_std = vmax;
        ae_sns_dft->lines_per500ms = lines * max_fps / 2; /* div 2 */
    }

    ae_sns_dft->fps = lines * max_fps * 0x40 / vmax / 0x40;
    ae_sns_dft->fps = (achieve_fps_flag) ? fps : ae_sns_dft->fps;

    ae_sns_dft->full_lines_std = sns_state->fl_std;
    ae_sns_dft->max_int_time = sns_state->fl_std - 2;  /* sub 2 */
    sns_state->fl[0] = sns_state->fl_std;
    ae_sns_dft->full_lines = sns_state->fl[0];
    ae_sns_dft->hmax_times =
        (1000000000) / (sns_state->fl_std * div_0_to_1_float(fps)); /* 1000000000ns */
    return;
}

static td_void cmos_slow_framerate_set(ot_vi_pipe vi_pipe, td_u32 full_lines, ot_isp_ae_sensor_default *ae_sns_dft)
{
    td_u32 lines_max, vmax;
    td_bool achieve_fps;
    ot_isp_sns_state *sns_state = TD_NULL;
    sns_check_pointer_void_return(ae_sns_dft);
    OV7251_sensor_get_ctx(vi_pipe, sns_state);
    sns_check_pointer_void_return(sns_state);

    lines_max = g_ov7251_mode_tbl[sns_state->img_mode].max_ver_lines;

    {
        vmax = full_lines;
        vmax = (vmax > lines_max) ? lines_max : vmax;
        sns_state->fl[0] = vmax;
    }
    ot_unused(achieve_fps);
    switch (sns_state->wdr_mode) {
        case OT_WDR_MODE_NONE:
			{
				td_u32 inttime_prev = ((sns_state->regs_info[0].i2c_data[0].data & 0xff) << 8) | (sns_state->regs_info[0].i2c_data[1].data & 0xff);
				td_u32 inttime_curr = cmos_vmax2inttime(sns_state, vmax);
				if(inttime_prev != inttime_curr){
					sns_state->regs_info[0].i2c_data[0].data = high_8bits(inttime_curr); 
					sns_state->regs_info[0].i2c_data[1].data = low_8bits(inttime_curr); 
				}
				break;
			}
        default:
            break;
    }

    ae_sns_dft->full_lines = sns_state->fl[0];
    ae_sns_dft->max_int_time = sns_state->fl[0] - 2; /* max_int_time: Flstd - 2 */

    return;
}

static td_void cmos_inttime_update_linear(ot_vi_pipe vi_pipe, td_u32 int_time)
{
    ot_isp_sns_state *sns_state = TD_NULL;
    td_u32 value;

    OV7251_sensor_get_ctx(vi_pipe, sns_state);
    sns_check_pointer_void_return(sns_state);

	td_u32 inttime_prev = ((sns_state->regs_info[0].i2c_data[0].data & 0xff) << 8) | (sns_state->regs_info[0].i2c_data[1].data & 0xff);
	td_u32 inttime_curr = cmos_vmax2inttime(sns_state, int_time);
	if(inttime_prev != inttime_curr){
		sns_state->regs_info[0].i2c_data[0].data = high_8bits(inttime_curr); 
		sns_state->regs_info[0].i2c_data[1].data = low_8bits(inttime_curr); 
	}

	return;
}

/* while isp notify ae to update sensor regs, ae call these funcs. */
static td_void cmos_inttime_update(ot_vi_pipe vi_pipe, td_u32 int_time)
{
    ot_isp_sns_state *sns_state = TD_NULL;

    OV7251_sensor_get_ctx(vi_pipe, sns_state);
    sns_check_pointer_void_return(sns_state);
   
    {
        cmos_inttime_update_linear(vi_pipe, int_time);
    }

    return;
}


#define GAIN_NODE_NUM   16

/* gain segmentation = 1024 */
static td_u32 g_gain_table[GAIN_NODE_NUM] =
{
	1024, 1494, 1964, 2434, 2904, 3374, 3844, 4314, 
	4784, 5254, 5724, 6194, 6664, 7134, 7604, OV7251_AGAIN_MAX
};


#if 0
#define GAIN_NODE_NUM   32

/* gain segmentation = 1024 */
static td_u32 g_gain_table[GAIN_NODE_NUM] =
{
	1024, 1248, 1472, 1696, 1920, 2144, 2368, 2592, 
	2816, 3040, 3264, 3488, 3712, 3936, 4160, 4384, 
	4608, 4832, 5056, 5280, 5504, 5728, 5952, 6176, 
	6400, 6624, 6848, 7072, 7296, 7520, 7744, 7968
};
#endif



static td_void cmos_again_calc_table(ot_vi_pipe vi_pipe, td_u32 *again_lin, td_u32 *again_db)
{
    int i;
	
		
    ot_unused(vi_pipe);
    sns_check_pointer_void_return(again_lin);
    sns_check_pointer_void_return(again_db);


    if (*again_lin >= g_gain_table[GAIN_NODE_NUM - 1]) {
        *again_lin = g_gain_table[GAIN_NODE_NUM - 1];
        *again_db = GAIN_NODE_NUM - 1;
        goto calc_table_end;
    }

    for (i = 1; i < GAIN_NODE_NUM; i++) {
        if (*again_lin < g_gain_table[i]) {
            *again_lin = g_gain_table[i - 1];
            *again_db = i - 1;
             goto calc_table_end;
        }
    }
	
calc_table_end:
    g_au32AGain[vi_pipe] = *again_lin;

	static td_s8 u8cnt = 0;
	static td_u32 again_delay=0;
	const td_u8 u8level = 4; 
	if(*again_lin >= OV7251_AGAIN_MAX) {
		if(again_delay++ > 5){
			u8cnt++;
			if(u8cnt>=u8level){
				u8cnt = u8level;
			}
			again_delay=0;
		}
	}
	else if(*again_lin <= 1024){
		if(again_delay++ > 5){
			u8cnt--;
			if(u8cnt<=0){
				u8cnt = 0;
			}
			again_delay = 0;
		}
	}
	else{
		again_delay = 0;
	}
		
	if(u8cnt>0){
		*again_db += u8cnt*32 - 16 ;
	}
	
	// printf(" \n ===== again_lin = %d, again_db = %d  u8cnt = %d  ", *again_lin, *again_db, u8cnt);

    return;
}

static td_void cmos_dgain_calc_table(ot_vi_pipe vi_pipe, td_u32 *dgain_lin, td_u32 *dgain_db)
{
    int i;

    ot_unused(vi_pipe);
    sns_check_pointer_void_return(dgain_lin);
    sns_check_pointer_void_return(dgain_db);

    if (*dgain_lin >= g_gain_table[GAIN_NODE_NUM - 1]) {
        *dgain_lin = g_gain_table[GAIN_NODE_NUM - 1];
        *dgain_db = GAIN_NODE_NUM;
        goto calc_table_end;
        return;
    }

    for (i = 1; i < GAIN_NODE_NUM; i++) {
        if (*dgain_lin < g_gain_table[i]) {
            *dgain_lin = g_gain_table[i - 1];
            *dgain_db = i - 1;
            goto calc_table_end;
            break;
        }
    }
calc_table_end:
    g_au32DGain[vi_pipe] = *dgain_lin;
    *dgain_db = *dgain_lin;
    return;
}

static td_void cmos_gains_update(ot_vi_pipe vi_pipe, td_u32 again, td_u32 dgain)
{
    ot_isp_sns_state *sns_state = TD_NULL;

    OV7251_sensor_get_ctx(vi_pipe, sns_state);
    sns_check_pointer_void_return(sns_state);
	td_u32 again_tmp = ((sns_state->regs_info[0].i2c_data[2].data & 0x3) << 8) | (sns_state->regs_info[0].i2c_data[3].data & 0xff);
	
	//printf("======= again = %d, again_tmp = %d    ", again, again_tmp);

	if(again_tmp != again){
		sns_state->regs_info[0].i2c_data[2].data = ((again >> 8) & 0x3);   /* index 2 */
		sns_state->regs_info[0].i2c_data[3].data = (again & 0xFF);		   /* index 3 */
	}
	
    //sns_state->regs_info[0].i2c_data[4].data = ((dgain_tmp >> 8) & 0x3);   /* index 4 */
    //sns_state->regs_info[0].i2c_data[5].data = (dgain_tmp & 0xFF);         /* index 5 */
	
    return;
}

static td_void cmos_get_inttime_max(ot_vi_pipe vi_pipe, td_u16 man_ratio_enable, td_u32 *ratio,
    ot_isp_ae_int_time_range *int_time, td_u32 *lf_max_int_time)
{
    ot_unused(man_ratio_enable);
    ot_isp_sns_state *sns_state = TD_NULL;
    sns_check_pointer_void_return(ratio);
    sns_check_pointer_void_return(int_time);
    sns_check_pointer_void_return(lf_max_int_time);
    OV7251_sensor_get_ctx(vi_pipe, sns_state);
    sns_check_pointer_void_return(sns_state);

    switch (sns_state->wdr_mode) {
        default:
            break;
    }

    return;
}

/* Only used in LINE_WDR mode */
static td_void cmos_ae_fswdr_attr_set(ot_vi_pipe vi_pipe, ot_isp_ae_fswdr_attr *ae_fswdr_attr)
{
    sns_check_pointer_void_return(ae_fswdr_attr);

    g_fswdr_mode[vi_pipe] = ae_fswdr_attr->fswdr_mode;
    g_max_time_get_cnt[vi_pipe] = 0;
    return;
}

static td_s32 cmos_init_ae_exp_function(ot_isp_ae_sensor_exp_func *exp_func)
{
    sns_check_pointer_return(exp_func);

    (td_void)memset_s(exp_func, sizeof(ot_isp_ae_sensor_exp_func), 0, sizeof(ot_isp_ae_sensor_exp_func));

    exp_func->pfn_cmos_get_ae_default    = cmos_get_ae_default;    		/* 获取AE算法库的初始化值 */
    exp_func->pfn_cmos_fps_set           = cmos_fps_set;				/* 设置sensor的帧率 */
    exp_func->pfn_cmos_slow_framerate_set = cmos_slow_framerate_set;	/* 降低sensor帧率 */
    exp_func->pfn_cmos_inttime_update    = cmos_inttime_update;			/* 设置sensor曝光时间 */
    exp_func->pfn_cmos_gains_update      = cmos_gains_update;			/* 设置sensor模拟增益和数字增益 */
    exp_func->pfn_cmos_again_calc_table  = cmos_again_calc_table;		/* 查表方式计算AE模拟增益 */
    exp_func->pfn_cmos_dgain_calc_table  = cmos_dgain_calc_table;		/* 查表方式计算AE数字增益 */
    exp_func->pfn_cmos_get_inttime_max   = cmos_get_inttime_max;		/* WDR模式下，计算短曝光帧的最大曝光时间 */
    exp_func->pfn_cmos_ae_fswdr_attr_set = cmos_ae_fswdr_attr_set;		/* WDR模式下，设置长帧模式 */

    return TD_SUCCESS;
}

/* AWB default parameter and function */
#define CALIBRATE_STATIC_TEMP       5000

#define CALIBRATE_STATIC_WB_R_GAIN  256
#define CALIBRATE_STATIC_WB_GR_GAIN 256
#define CALIBRATE_STATIC_WB_GB_GAIN 256
#define CALIBRATE_STATIC_WB_B_GAIN  256  //470

/* Calibration results for Auto WB Planck */
#define CALIBRATE_AWB_P1            37
#define CALIBRATE_AWB_P2            145
#define CALIBRATE_AWB_Q1            (-74)
#define CALIBRATE_AWB_A1            154453
#define CALIBRATE_AWB_B1            128
#define CALIBRATE_AWB_C1            (-105693)

/* Rgain and Bgain of the golden sample */
#define GOLDEN_RGAIN                0
#define GOLDEN_BGAIN                0

static td_s32 cmos_get_awb_default(ot_vi_pipe vi_pipe, ot_isp_awb_sensor_default *awb_sns_dft)
{
    ot_isp_sns_state *sns_state = TD_NULL;

    sns_check_pointer_return(awb_sns_dft);
    OV7251_sensor_get_ctx(vi_pipe, sns_state);
    sns_check_pointer_return(sns_state);

    (td_void)memset_s(awb_sns_dft, sizeof(ot_isp_awb_sensor_default), 0, sizeof(ot_isp_awb_sensor_default));
    awb_sns_dft->wb_ref_temp = CALIBRATE_STATIC_TEMP; /* wb_ref_temp 4950 */

    awb_sns_dft->gain_offset[0] = CALIBRATE_STATIC_WB_R_GAIN;
    awb_sns_dft->gain_offset[1] = CALIBRATE_STATIC_WB_GR_GAIN;
    awb_sns_dft->gain_offset[2] = CALIBRATE_STATIC_WB_GB_GAIN; /* index 2 */
    awb_sns_dft->gain_offset[3] = CALIBRATE_STATIC_WB_B_GAIN; /* index 3 */

    awb_sns_dft->wb_para[0] = CALIBRATE_AWB_P1;
    awb_sns_dft->wb_para[1] = CALIBRATE_AWB_P2;
    awb_sns_dft->wb_para[2] = CALIBRATE_AWB_Q1; /* index 2 */
    awb_sns_dft->wb_para[3] = CALIBRATE_AWB_A1; /* index 3 */
    awb_sns_dft->wb_para[4] = CALIBRATE_AWB_B1; /* index 4 */
    awb_sns_dft->wb_para[5] = CALIBRATE_AWB_C1; /* index 5 */

    awb_sns_dft->golden_rgain = GOLDEN_RGAIN;
    awb_sns_dft->golden_bgain = GOLDEN_BGAIN;

    switch (sns_state->wdr_mode) {
        case OT_WDR_MODE_NONE:
            (td_void)memcpy_s(&awb_sns_dft->ccm, sizeof(ot_isp_awb_ccm), &g_awb_ccm, sizeof(ot_isp_awb_ccm));
            (td_void)memcpy_s(&awb_sns_dft->agc_tbl, sizeof(ot_isp_awb_agc_table),
                              &g_awb_agc_table, sizeof(ot_isp_awb_agc_table));
            break;

        // case OT_WDR_MODE_2To1_LINE:
        //     (td_void)memcpy_s(&awb_sns_dft->ccm, sizeof(ot_isp_awb_ccm), &g_awb_ccm_wdr, sizeof(ot_isp_awb_ccm));
        //     (td_void)memcpy_s(&awb_sns_dft->agc_tbl, sizeof(ot_isp_awb_agc_table),
        //                       &g_awb_agc_table_wdr, sizeof(ot_isp_awb_agc_table));

            break;

        default:
            (td_void)memcpy_s(&awb_sns_dft->ccm, sizeof(ot_isp_awb_ccm), &g_awb_ccm, sizeof(ot_isp_awb_ccm));
            (td_void)memcpy_s(&awb_sns_dft->agc_tbl, sizeof(ot_isp_awb_agc_table),
                              &g_awb_agc_table, sizeof(ot_isp_awb_agc_table));
            break;
    }

    awb_sns_dft->init_rgain = g_init_wb_gain[vi_pipe][0]; /* 0: Rgain */
    awb_sns_dft->init_ggain = g_init_wb_gain[vi_pipe][1]; /* 1: Ggain */
    awb_sns_dft->init_bgain = g_init_wb_gain[vi_pipe][2]; /* 2: Bgain */
    awb_sns_dft->sample_rgain = g_sample_r_gain[vi_pipe];
    awb_sns_dft->sample_bgain = g_sample_b_gain[vi_pipe];

    return TD_SUCCESS;
}

static td_s32 cmos_init_awb_exp_function(ot_isp_awb_sensor_exp_func *exp_func)
{
    sns_check_pointer_return(exp_func);

    (td_void)memset_s(exp_func, sizeof(ot_isp_awb_sensor_exp_func), 0, sizeof(ot_isp_awb_sensor_exp_func));

    exp_func->pfn_cmos_get_awb_default = cmos_get_awb_default;

    return TD_SUCCESS;
}

static ot_isp_cmos_dng_color_param g_dng_color_param = {{ 378, 256, 430 }, { 439, 256, 439 }};

static td_void cmos_get_isp_dng_default(const ot_isp_sns_state *sns_state, ot_isp_cmos_default *isp_def)
{
    (td_void)memcpy_s(&isp_def->dng_color_param, sizeof(ot_isp_cmos_dng_color_param), &g_dng_color_param,
                      sizeof(ot_isp_cmos_dng_color_param));

    switch (sns_state->img_mode) {
        case OV7251_SENSOR_480P_20FPS_LINEAR_10BIT:
            isp_def->sns_mode.dng_raw_format.bits_per_sample = 10; /* 12bit */
            isp_def->sns_mode.dng_raw_format.white_level = 1023; /* max 4095 */
            break;

        default:
            isp_def->sns_mode.dng_raw_format.bits_per_sample = 10; /* 12bit */
            isp_def->sns_mode.dng_raw_format.white_level = 1023; /* max 4095 */
            break;
    }

    isp_def->sns_mode.dng_raw_format.default_scale.default_scale_hor.denominator = 1;
    isp_def->sns_mode.dng_raw_format.default_scale.default_scale_hor.numerator = 1;
    isp_def->sns_mode.dng_raw_format.default_scale.default_scale_ver.denominator = 1;
    isp_def->sns_mode.dng_raw_format.default_scale.default_scale_ver.numerator = 1;
    isp_def->sns_mode.dng_raw_format.cfa_repeat_pattern_dim.repeat_pattern_dim_row = 2; /* pattern 2 */
    isp_def->sns_mode.dng_raw_format.cfa_repeat_pattern_dim.repeat_pattern_dim_col = 2; /* pattern 2 */
    isp_def->sns_mode.dng_raw_format.black_level_repeat_dim.repeat_row = 2; /* pattern 2 */
    isp_def->sns_mode.dng_raw_format.black_level_repeat_dim.repeat_col = 2; /* pattern 2 */
    isp_def->sns_mode.dng_raw_format.cfa_layout = OT_ISP_CFALAYOUT_TYPE_RECTANGULAR;
    isp_def->sns_mode.dng_raw_format.cfa_plane_color[0] = 0;
    isp_def->sns_mode.dng_raw_format.cfa_plane_color[1] = 1;
    isp_def->sns_mode.dng_raw_format.cfa_plane_color[2] = 2; /* index 2, cfa_plane_color 2 */
    isp_def->sns_mode.dng_raw_format.cfa_pattern[0] = 0;
    isp_def->sns_mode.dng_raw_format.cfa_pattern[1] = 1;
    isp_def->sns_mode.dng_raw_format.cfa_pattern[2] = 1; /* index 2, cfa_pattern 1 */
    isp_def->sns_mode.dng_raw_format.cfa_pattern[3] = 2; /* index 3, cfa_pattern 2 */
    isp_def->sns_mode.valid_dng_raw_format = TD_TRUE;
    return;
}

static void cmos_get_isp_linear_default(ot_isp_cmos_default *isp_def)
{
    isp_def->key.bit1_demosaic         = 1;
    isp_def->demosaic                  = &g_cmos_demosaic;
    isp_def->key.bit1_sharpen          = 1;
    isp_def->sharpen                   = &g_cmos_yuv_sharpen;
    isp_def->key.bit1_drc              = 1;
    isp_def->drc                       = &g_cmos_drc;
    isp_def->key.bit1_bayer_nr         = 1;
    isp_def->bayer_nr                  = &g_cmos_bayer_nr;
    isp_def->key.bit1_anti_false_color = 1;
    isp_def->anti_false_color          = &g_cmos_anti_false_color;
    isp_def->key.bit1_ldci             = 1;
    isp_def->ldci                      = &g_cmos_ldci;
    isp_def->key.bit1_gamma            = 1;
    isp_def->gamma                     = &g_cmos_gamma;
#ifdef CONFIG_OT_ISP_CR_SUPPORT
    isp_def->key.bit1_ge               = 1;
    isp_def->ge                        = &g_cmos_ge;
#endif
    isp_def->key.bit1_dehaze = 1;
    isp_def->dehaze = &g_cmos_dehaze;
    isp_def->key.bit1_ca = 1;
    isp_def->ca = &g_cmos_ca;
    (td_void)memcpy_s(&isp_def->noise_calibration, sizeof(ot_isp_noise_calibration),
                      &g_cmos_noise_calibration, sizeof(ot_isp_noise_calibration));
    return;
}

static void cmos_get_isp_wdr_default(ot_isp_cmos_default *isp_def)
{
//     isp_def->key.bit1_dpc            = 1;
//     isp_def->dpc                     = &g_cmos_dpc_wdr;
//     isp_def->key.bit1_demosaic       = 1;
//     isp_def->demosaic                = &g_cmos_demosaic_wdr;
//     isp_def->key.bit1_sharpen        = 1;
//     isp_def->sharpen                 = &g_cmos_yuv_sharpen_wdr;
//     isp_def->key.bit1_drc            = 1;
//     isp_def->drc                     = &g_cmos_drc_wdr;
//     isp_def->key.bit1_gamma          = 1;
//     isp_def->gamma                   = &g_cmos_gamma_wdr;
// #ifdef CONFIG_OT_ISP_PREGAMMA_SUPPORT
//     isp_def->key.bit1_pregamma       = 1;
//     isp_def->pregamma                = &g_cmos_pregamma;
// #endif
//     isp_def->key.bit1_bayer_nr       = 1;
//     isp_def->bayer_nr                = &g_cmos_bayer_nr_wdr;
// #ifdef CONFIG_OT_ISP_CR_SUPPORT
//     isp_def->key.bit1_ge             = 1;
//     isp_def->ge                      = &g_cmos_ge_wdr;
// #endif
//     isp_def->key.bit1_anti_false_color = 1;
//     isp_def->anti_false_color = &g_cmos_anti_false_color_wdr;
//     isp_def->key.bit1_ldci = 1;
//     isp_def->ldci = &g_cmos_ldci_wdr;
//     isp_def->key.bit1_dehaze = 1;
//     isp_def->dehaze = &g_cmos_dehaze_wdr;
//     //isp_def->key.bit1_crb = 1;
//     //isp_def->crb = &g_cmos_crb_wdr;
//     (td_void)memcpy_s(&isp_def->noise_calibration, sizeof(ot_isp_noise_calibration),
//                       &g_cmos_noise_calibration, sizeof(ot_isp_noise_calibration));
    return;
}

static td_s32 cmos_get_isp_default(ot_vi_pipe vi_pipe, ot_isp_cmos_default *isp_def)
{
    ot_isp_sns_state *sns_state = TD_NULL;

    sns_check_pointer_return(isp_def);
    OV7251_sensor_get_ctx(vi_pipe, sns_state);
    sns_check_pointer_return(sns_state);

    (td_void)memset_s(isp_def, sizeof(ot_isp_cmos_default), 0, sizeof(ot_isp_cmos_default));
#ifdef CONFIG_OT_ISP_CA_SUPPORT
    isp_def->key.bit1_ca      = 0;
    isp_def->ca               = &g_cmos_ca;
#endif
    isp_def->key.bit1_clut    = 1;
    isp_def->clut             = &g_cmos_clut;

    isp_def->key.bit1_dpc     = 1;
    isp_def->dpc              = &g_cmos_dpc;

    isp_def->key.bit1_wdr     = 1;
    isp_def->wdr              = &g_cmos_wdr;

    isp_def->key.bit1_lsc      = 1;
    if(OV7251_SENSOR_480P_20FPS_LINEAR_10BIT == sns_state->img_mode){
        isp_def->lsc               = &g_cmos_lsc;
    }
    else{
        isp_def->lsc               = &g_cmos_lsc_2M;
    }

    isp_def->key.bit1_acs      = 1;
    isp_def->acs               = &g_cmos_acs;

#ifdef CONFIG_OT_ISP_PREGAMMA_SUPPORT
    isp_def->key.bit1_pregamma = 0;
    isp_def->pregamma          = &g_cmos_pregamma;
#endif
    switch (sns_state->wdr_mode) {
        case OT_WDR_MODE_NONE:
            cmos_get_isp_linear_default(isp_def);
            break;

        // case OT_WDR_MODE_2To1_LINE:
        //     cmos_get_isp_wdr_default(isp_def);

            break;

        default:
            cmos_get_isp_linear_default(isp_def);
            break;
    }

    isp_def->wdr_switch_attr.exp_ratio[0] = 0x40;

    if (sns_state->wdr_mode == OT_WDR_MODE_2To1_LINE) {
        isp_def->wdr_switch_attr.exp_ratio[0] = 0x200;
        isp_def->wdr_switch_attr.exp_ratio[1] = 0x200;
    }

    isp_def->sns_mode.sns_id = OV7251_ID;
    isp_def->sns_mode.sns_mode = sns_state->img_mode;
    cmos_get_isp_dng_default(sns_state, isp_def);

    return TD_SUCCESS;
}

static td_s32 cmos_get_isp_black_level(ot_vi_pipe vi_pipe, ot_isp_cmos_black_level *black_level)
{
    td_s32  i;
    ot_isp_sns_state *sns_state = TD_NULL;
    const ot_isp_cmos_black_level *cmos_blc_def = TD_NULL;

    sns_check_pointer_return(black_level);
    OV7251_sensor_get_ctx(vi_pipe, sns_state);
    sns_check_pointer_return(sns_state);

    /* Don't need to update black level when iso change */
    black_level->auto_attr.update = TD_TRUE;

    /* black level of linear mode */
    if (sns_state->wdr_mode == OT_WDR_MODE_NONE) {
        for (i = 0; i < OT_ISP_BAYER_CHN_NUM; i++) {
            black_level->auto_attr.black_level[0][i] = OV7251_BLACK_LEVEL;
        }
    } else { /* black level of DOL mode */
        for (i = 0; i < OT_ISP_WDR_MAX_FRAME_NUM; i++) {
            black_level->auto_attr.black_level[i][0] = OV7251_BLACK_LEVEL;
            black_level->auto_attr.black_level[i][1] = OV7251_BLACK_LEVEL;
            black_level->auto_attr.black_level[i][2] = OV7251_BLACK_LEVEL; /* index 2 */
            black_level->auto_attr.black_level[i][3] = OV7251_BLACK_LEVEL; /* index 3 */
        }
    }

    return TD_SUCCESS;
}

static td_s32 cmos_get_isp_blc_clamp_info(ot_vi_pipe vi_pipe, td_bool *blc_clamp_en)
{
    sns_check_pointer_return(blc_clamp_en);

    *blc_clamp_en = blc_clamp_info[vi_pipe];

    return TD_SUCCESS;
}

static td_void cmos_set_pixel_detect(ot_vi_pipe vi_pipe, td_bool enable)
{
    td_u32 full_lines_5fps, max_int_time_5fps;
    ot_isp_sns_state *sns_state = TD_NULL;

    OV7251_sensor_get_ctx(vi_pipe, sns_state);
    sns_check_pointer_void_return(sns_state);

    if (sns_state->wdr_mode == OT_WDR_MODE_2To1_LINE) {
        return;
    } else {
        if (sns_state->img_mode == OV7251_SENSOR_480P_20FPS_LINEAR_10BIT)  {
            full_lines_5fps = (OV7251_VMAX_480P30_LINEAR_10BIT * 30) / 5; /* 30fps, 5fps */
        }
        else {
            return;
        }
    }

    max_int_time_5fps = 20; /* max_int_time_5fps 6 */
	
	if (enable) { /* setup for ISP pixel calibration mode */
		ov7251_write_registeraaa(vi_pipe, OV7251_AGAIN_ADDR_H, 0x00);
		ov7251_write_registeraaa(vi_pipe, OV7251_AGAIN_ADDR_L, 0x01);
	
		ov7251_write_registeraaa(vi_pipe, OV7251_DGAIN_ADDR_H, 0x00);
		ov7251_write_registeraaa(vi_pipe, OV7251_DGAIN_ADDR_L, 0x01);
		
		ov7251_write_registeraaa(vi_pipe, OV7251_SHR0_ADDR,   low_8bits(cmos_vmax2inttime(sns_state, max_int_time_5fps)));
		ov7251_write_registeraaa(vi_pipe, OV7251_SHR0_ADDR-1, high_8bits(cmos_vmax2inttime(sns_state, max_int_time_5fps)) );
	} else { /* setup for ISP 'normal mode' */
		sns_state->fl_std = (sns_state->fl_std > 0xFFFFF) ? 0xFFFFF : sns_state->fl_std;
		sns_state->sync_init = TD_FALSE;
	}

    return;
}

static td_s32 cmos_set_wdr_mode(ot_vi_pipe vi_pipe, td_u8 mode)
{
    ot_isp_sns_state *sns_state = TD_NULL;

    OV7251_sensor_get_ctx(vi_pipe, sns_state);
    sns_check_pointer_return(sns_state);

    sns_state->sync_init    = TD_FALSE;

    switch (mode & 0x3F) {
        case OT_WDR_MODE_NONE:
            sns_state->wdr_mode = OT_WDR_MODE_NONE;
            printf("linear mode\n");
            break;

        default:
            isp_err_trace("NOT support this mode!\n");
            return TD_FAILURE;
    }

    (td_void)memset_s(sns_state->wdr_int_time, sizeof(sns_state->wdr_int_time), 0, sizeof(sns_state->wdr_int_time));

    return TD_SUCCESS;
}

static td_void cmos_comm_sns_reg_info_init(ot_vi_pipe vi_pipe, ot_isp_sns_state *sns_state)
{
    td_u32 i;
    sns_state->regs_info[0].sns_type = OT_ISP_SNS_TYPE_I2C;
    sns_state->regs_info[0].com_bus.i2c_dev = g_ov7251_bus_info[vi_pipe].i2c_dev;
    sns_state->regs_info[0].cfg2_valid_delay_max = 2; /* delay_max 2 */
    sns_state->regs_info[0].reg_num = 6; /* reg_num 8 */

	/* i2c数据信息 */
    for (i = 0; i < sns_state->regs_info[0].reg_num; i++) {
        sns_state->regs_info[0].i2c_data[i].update = TD_TRUE;
        sns_state->regs_info[0].i2c_data[i].dev_addr = OV7251_I2C_ADDR;
        sns_state->regs_info[0].i2c_data[i].addr_byte_num = OV7251_ADDR_BYTE;
        sns_state->regs_info[0].i2c_data[i].data_byte_num = OV7251_DATA_BYTE;
    }
    
    /* shutter */
	sns_state->regs_info[0].i2c_data[0].delay_frame_num = 0;
    sns_state->regs_info[0].i2c_data[0].reg_addr = OV7251_SHR0_ADDR - 1;
    sns_state->regs_info[0].i2c_data[1].delay_frame_num = 0;
    sns_state->regs_info[0].i2c_data[1].reg_addr = OV7251_SHR0_ADDR;

    /* again */
	sns_state->regs_info[0].i2c_data[2].delay_frame_num = 1;
    sns_state->regs_info[0].i2c_data[2].reg_addr = OV7251_AGAIN_ADDR_H;
    sns_state->regs_info[0].i2c_data[3].delay_frame_num = 0;
    sns_state->regs_info[0].i2c_data[3].reg_addr = OV7251_AGAIN_ADDR_L;

	/* dgain */
	sns_state->regs_info[0].i2c_data[4].delay_frame_num = 1;
    sns_state->regs_info[0].i2c_data[4].reg_addr = OV7251_DGAIN_ADDR_H;
    sns_state->regs_info[0].i2c_data[5].delay_frame_num = 0;
    sns_state->regs_info[0].i2c_data[5].reg_addr = OV7251_DGAIN_ADDR_L;

    return;
}


static td_void cmos_sns_reg_info_update(ot_vi_pipe vi_pipe, ot_isp_sns_state *sns_state)
{
    td_u32 i;
    ot_unused(vi_pipe);

    for (i = 0; i < sns_state->regs_info[0].reg_num; i++) {
        if (sns_state->regs_info[0].i2c_data[i].data ==
            sns_state->regs_info[1].i2c_data[i].data) {
            sns_state->regs_info[0].i2c_data[i].update = TD_FALSE;
        } else {
            sns_state->regs_info[0].i2c_data[i].update = TD_TRUE;
        }
    }
    return;
}

static td_s32 cmos_get_sns_regs_info(ot_vi_pipe vi_pipe, ot_isp_sns_regs_info *sns_regs_info)
{
    ot_isp_sns_state *sns_state = TD_NULL;

    sns_check_pointer_return(sns_regs_info);
    OV7251_sensor_get_ctx(vi_pipe, sns_state);
    sns_check_pointer_return(sns_state);

    if ((sns_state->sync_init == TD_FALSE) || (sns_regs_info->config == TD_FALSE)) {
        cmos_comm_sns_reg_info_init(vi_pipe, sns_state);

        if (sns_state->wdr_mode == OT_WDR_MODE_2To1_LINE) {
        }
        sns_state->sync_init = TD_TRUE;
    } else {
        cmos_sns_reg_info_update(vi_pipe, sns_state);
    }

    sns_regs_info->config = TD_FALSE;
    (td_void)memcpy_s(sns_regs_info, sizeof(ot_isp_sns_regs_info),
                      &sns_state->regs_info[0], sizeof(ot_isp_sns_regs_info));
    (td_void)memcpy_s(&sns_state->regs_info[1], sizeof(ot_isp_sns_regs_info),
                      &sns_state->regs_info[0], sizeof(ot_isp_sns_regs_info));
    sns_state->fl[1] = sns_state->fl[0];

    return TD_SUCCESS;
}

static td_void cmos_config_image_mode_param(ot_vi_pipe vi_pipe, td_u8 sensor_image_mode,
    ot_isp_sns_state *sns_state)
{
    switch (sensor_image_mode) {
        case OV7251_SENSOR_480P_20FPS_LINEAR_10BIT:
            sns_state->fl_std         = OV7251_VMAX_480P30_LINEAR_10BIT;
            g_ov7251_state[vi_pipe].hcg = 0x1;
            break;

        default:
            sns_state->fl_std         = OV7251_VMAX_480P30_LINEAR_10BIT;
            g_ov7251_state[vi_pipe].hcg = 0x1;
            break;
    }
}

static td_s32 cmos_set_image_mode(ot_vi_pipe vi_pipe, const ot_isp_cmos_sns_image_mode *sensor_image_mode)
{
    td_u32 i;
    td_u8 image_mode;
    ot_isp_sns_state *sns_state = TD_NULL;
    sns_check_pointer_return(sensor_image_mode);
    OV7251_sensor_get_ctx(vi_pipe, sns_state);
    sns_check_pointer_return(sns_state);

    image_mode = sns_state->img_mode;
    for (i = 0; i < OV7251_MODE_BUTT; i++) {
        if (sensor_image_mode->fps <= g_ov7251_mode_tbl[i].max_fps &&
            sensor_image_mode->width <= g_ov7251_mode_tbl[i].width &&
            sensor_image_mode->height <= g_ov7251_mode_tbl[i].height &&
            sns_state->wdr_mode == g_ov7251_mode_tbl[i].wdr_mode) {
            image_mode = (ov7251_res_mode)i;
            printf("%s => set[w:%d,h:%d,fps:%.4f], tab[%d][w:%d,h:%d,fps:%.4f]\n"
              , __func__, sensor_image_mode->width, sensor_image_mode->height, sensor_image_mode->fps
              , i, g_ov7251_mode_tbl[i].width, g_ov7251_mode_tbl[i].height, g_ov7251_mode_tbl[i].max_fps);
            break;
        }
    }

    if (i >= OV7251_MODE_BUTT) {
        ov7251_err_mode_print(sensor_image_mode, sns_state);
        return TD_FAILURE;
    }

    cmos_config_image_mode_param(vi_pipe, image_mode, sns_state);

    if ((sns_state->init == TD_TRUE) && (image_mode == sns_state->img_mode)) {
        return OT_ISP_DO_NOT_NEED_SWITCH_IMAGEMODE; /* Don't need to switch image_mode */
    }

    sns_state->sync_init = TD_FALSE;
    sns_state->img_mode = image_mode;
    sns_state->fl[0] = sns_state->fl_std;
    sns_state->fl[1] = sns_state->fl[0];
    return TD_SUCCESS;
}

static td_void sensor_global_init(ot_vi_pipe vi_pipe)
{
    ot_isp_sns_state *sns_state = TD_NULL;

    OV7251_sensor_get_ctx(vi_pipe, sns_state);
    sns_check_pointer_void_return(sns_state);

    sns_state->init = TD_FALSE;
    sns_state->sync_init = TD_FALSE;
    sns_state->img_mode = OV7251_SENSOR_480P_20FPS_LINEAR_10BIT;
    sns_state->wdr_mode = OT_WDR_MODE_NONE;
    sns_state->fl_std  = OV7251_VMAX_480P30_LINEAR_10BIT;
    sns_state->fl[0] = OV7251_VMAX_480P30_LINEAR_10BIT;
    sns_state->fl[1] = OV7251_VMAX_480P30_LINEAR_10BIT;

    (td_void)memset_s(&sns_state->regs_info[0], sizeof(ot_isp_sns_regs_info), 0, sizeof(ot_isp_sns_regs_info));
    (td_void)memset_s(&sns_state->regs_info[1], sizeof(ot_isp_sns_regs_info), 0, sizeof(ot_isp_sns_regs_info));
    return;
}

static td_s32 cmos_init_sensor_exp_function(ot_isp_sns_exp_func *sensor_exp_func)
{
    sns_check_pointer_return(sensor_exp_func);

    (td_void)memset_s(sensor_exp_func, sizeof(ot_isp_sns_exp_func), 0, sizeof(ot_isp_sns_exp_func));

    sensor_exp_func->pfn_cmos_sns_init         = ov7251_init;
    sensor_exp_func->pfn_cmos_sns_exit         = ov7251_exit;
    sensor_exp_func->pfn_cmos_sns_global_init  = sensor_global_init;
    sensor_exp_func->pfn_cmos_set_image_mode      = cmos_set_image_mode;
    sensor_exp_func->pfn_cmos_set_wdr_mode        = cmos_set_wdr_mode;
    sensor_exp_func->pfn_cmos_get_isp_default     = cmos_get_isp_default;
    sensor_exp_func->pfn_cmos_get_isp_black_level = cmos_get_isp_black_level;
    sensor_exp_func->pfn_cmos_get_blc_clamp_info  = cmos_get_isp_blc_clamp_info;
    sensor_exp_func->pfn_cmos_set_pixel_detect    = cmos_set_pixel_detect;
    sensor_exp_func->pfn_cmos_get_sns_reg_info    = cmos_get_sns_regs_info;

    return TD_SUCCESS;
}

static td_s32 ov7251_set_bus_info(ot_vi_pipe vi_pipe, ot_isp_sns_commbus sns_bus_info)
{
    g_ov7251_bus_info[vi_pipe].i2c_dev = sns_bus_info.i2c_dev;

    return TD_SUCCESS;
}

static td_s32 sensor_ctx_init(ot_vi_pipe vi_pipe)
{
    ot_isp_sns_state *sns_state_ctx = TD_NULL;

    OV7251_sensor_get_ctx(vi_pipe, sns_state_ctx);

    if (sns_state_ctx == TD_NULL) {
        sns_state_ctx = (ot_isp_sns_state *)malloc(sizeof(ot_isp_sns_state));
        if (sns_state_ctx == TD_NULL) {
            isp_err_trace("Isp[%d] SnsCtx malloc memory failed!\n", vi_pipe);
            return OT_ERR_ISP_NOMEM;
        }
    }

    (td_void)memset_s(sns_state_ctx, sizeof(ot_isp_sns_state), 0, sizeof(ot_isp_sns_state));

    ov7251_sensor_set_ctx(vi_pipe, sns_state_ctx);

    return TD_SUCCESS;
}

static td_void sensor_ctx_exit(ot_vi_pipe vi_pipe)
{
    ot_isp_sns_state *sns_state_ctx = TD_NULL;

    OV7251_sensor_get_ctx(vi_pipe, sns_state_ctx);
    sns_free(sns_state_ctx);
    ov7251_sensor_reset_ctx(vi_pipe);
    return;
}

static td_s32 sensor_register_callback(ot_vi_pipe vi_pipe, ot_isp_3a_alg_lib *ae_lib, ot_isp_3a_alg_lib *awb_lib)
{
    td_s32 ret;
    ot_isp_sns_register isp_register;
    ot_isp_ae_sensor_register ae_register;
    ot_isp_awb_sensor_register awb_register;
    ot_isp_sns_attr_info sns_attr_info;

    sns_check_pointer_return(ae_lib);
    sns_check_pointer_return(awb_lib);

    ret = sensor_ctx_init(vi_pipe);
    if (ret != TD_SUCCESS) {
        return TD_FAILURE;
    }

    sns_attr_info.sns_id = OV7251_ID;
    ret = cmos_init_sensor_exp_function(&isp_register.sns_exp);
    if (ret != TD_SUCCESS) {
        isp_err_trace("cmos init exp function failed!\n");
        return TD_FAILURE;
    }
    ret = ot_mpi_isp_sensor_reg_callback(vi_pipe, &sns_attr_info, &isp_register);
    if (ret != TD_SUCCESS) {
        isp_err_trace("sensor register callback function failed!\n");
        return ret;
    }

    ret = cmos_init_ae_exp_function(&ae_register.sns_exp);
    if (ret != TD_SUCCESS) {
        isp_err_trace("cmos init ae exp function failed!\n");
        return TD_FAILURE;
    }
    ret = ot_mpi_ae_sensor_reg_callback(vi_pipe, ae_lib, &sns_attr_info, &ae_register);
    if (ret != TD_SUCCESS) {
        isp_err_trace("sensor register callback function to ae lib failed!\n");
        return ret;
    }

    ret = cmos_init_awb_exp_function(&awb_register.sns_exp);
    if (ret != TD_SUCCESS) {
        isp_err_trace("cmos init awb exp function failed!\n");
        return TD_FAILURE;
    }
    ret = ot_mpi_awb_sensor_reg_callback(vi_pipe, awb_lib, &sns_attr_info, &awb_register);
    if (ret != TD_SUCCESS) {
        isp_err_trace("sensor register callback function to awb lib failed!\n");
        return ret;
    }

    return TD_SUCCESS;
}

static td_s32 sensor_unregister_callback(ot_vi_pipe vi_pipe, ot_isp_3a_alg_lib *ae_lib, ot_isp_3a_alg_lib *awb_lib)
{
    td_s32 ret;

    sns_check_pointer_return(ae_lib);
    sns_check_pointer_return(awb_lib);

    ret = ot_mpi_isp_sensor_unreg_callback(vi_pipe, OV7251_ID);
    if (ret != TD_SUCCESS) {
        isp_err_trace("sensor unregister callback function failed!\n");
        return ret;
    }

    ret = ot_mpi_ae_sensor_unreg_callback(vi_pipe, ae_lib, OV7251_ID);
    if (ret != TD_SUCCESS) {
        isp_err_trace("sensor unregister callback function to ae lib failed!\n");
        return ret;
    }

    ret = ot_mpi_awb_sensor_unreg_callback(vi_pipe, awb_lib, OV7251_ID);
    if (ret != TD_SUCCESS) {
        isp_err_trace("sensor unregister callback function to awb lib failed!\n");
        return ret;
    }

    sensor_ctx_exit(vi_pipe);
    return TD_SUCCESS;
}

static td_s32 sensor_set_init(ot_vi_pipe vi_pipe, ot_isp_init_attr *init_attr)
{
    sns_check_pointer_return(init_attr);

    g_init_exposure[vi_pipe]  = init_attr->exposure;
    g_lines_per500ms[vi_pipe] = init_attr->lines_per500ms;
    g_init_wb_gain[vi_pipe][0] = init_attr->wb_r_gain; /* 0: rgain */
    g_init_wb_gain[vi_pipe][1] = init_attr->wb_g_gain; /* 1: ggain */
    g_init_wb_gain[vi_pipe][2] = init_attr->wb_b_gain; /* 2: bgain */
    g_sample_r_gain[vi_pipe] = init_attr->sample_r_gain;
    g_sample_b_gain[vi_pipe] = init_attr->sample_b_gain;
    g_quick_start_en[vi_pipe] = init_attr->quick_start_en;
	g_ae_stat_pos[vi_pipe]       = init_attr->ae_stat_pos;

    g_ae_route_ex_valid[vi_pipe] = init_attr->ae_route_ex_valid;
    (td_void)memcpy_s(&g_init_ae_route[vi_pipe], sizeof(ot_isp_ae_route),
                      &init_attr->ae_route, sizeof(ot_isp_ae_route));
    (td_void)memcpy_s(&g_init_ae_route_ex[vi_pipe], sizeof(ot_isp_ae_route_ex),
                      &init_attr->ae_route_ex, sizeof(ot_isp_ae_route_ex));
    (td_void)memcpy_s(&g_init_ae_route_sf[vi_pipe], sizeof(ot_isp_ae_route),
                      &init_attr->ae_route_sf, sizeof(ot_isp_ae_route));
    (td_void)memcpy_s(&g_init_ae_route_sf_ex[vi_pipe], sizeof(ot_isp_ae_route_ex),
                      &init_attr->ae_route_sf_ex, sizeof(ot_isp_ae_route_ex));

    return TD_SUCCESS;
}



ot_isp_sns_obj g_sns_ov7251_obj = {
    .pfn_register_callback     = sensor_register_callback,
    .pfn_un_register_callback  = sensor_unregister_callback,
    .pfn_standby               = ov7251_standby,
    .pfn_restart               = ov7251_restart,
    .pfn_mirror_flip           = ov7251_mirror_flip,
    .pfn_set_blc_clamp         = ov7251_blc_clamp,
    .pfn_write_reg             = ov7251_write_registeraaa,
    .pfn_read_reg              = ov7251_read_register,
    .pfn_set_bus_info          = ov7251_set_bus_info,
    .pfn_set_init              = sensor_set_init
};
