/*
  Copyright (c), 2001-2021, Shenshu Tech. Co., Ltd.
 */

#ifndef OV7251_CMOS_H
#define OV7251_CMOS_H

#include "ot_common.h"
#include "ot_common_isp.h"
#include "ot_common_video.h"
#include "ot_sns_ctrl.h"
#include "ot_type.h"
#include "ot_math.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define OV7251_I2C_ADDR    0xC0 //0x34 //0x20
#define OV7251_ADDR_BYTE   2
#define OV7251_DATA_BYTE   1

#define OV7251_FULL_LINES_MAX         0xFFFFF

#define OV7251_INCREASE_LINES         0 /* make real fps less than stand fps because NVR require */

#define OV7251_VMAX_480P20_LINEAR_10BIT   (0x0280 + OV7251_INCREASE_LINES)
#define OV7251_VMAX_480P30_LINEAR_10BIT   (0x0280 + OV7251_INCREASE_LINES)

typedef enum {
    OV7251_SENSOR_480P_20FPS_LINEAR_10BIT = 0,
    OV7251_SENSOR_480P_30FPS_LINEAR_10BIT = 1,
    OV7251_MODE_BUTT
} ov7251_res_mode;

typedef struct {
    td_u32      ver_lines;
    td_u32      max_ver_lines;
    td_float    max_fps;
    td_float    min_fps;
    td_u32      width;
    td_u32      height;
    td_u8       sns_mode;
    ot_wdr_mode wdr_mode;
    const char *mode_name;
} ov7251_video_mode_tbl;

typedef struct {
    td_u32 dec[OT_ISP_WDR_MAX_FRAME_NUM];
    td_u32 inc[OT_ISP_WDR_MAX_FRAME_NUM];
} time_step;

ot_isp_sns_state *ov7251_get_ctx(ot_vi_pipe vi_pipe);

ot_isp_sns_commbus *ov7251_get_bus_info(ot_vi_pipe vi_pipe);

td_void ov7251_init(ot_vi_pipe vi_pipe);
td_void ov7251_exit(ot_vi_pipe vi_pipe);
td_void ov7251_standby(ot_vi_pipe vi_pipe);
td_void ov7251_restart(ot_vi_pipe vi_pipe);
td_void ov7251_set_blc_clamp_value(ot_vi_pipe vi_pipe, td_bool clamp_en);
td_void ov7251_blc_clamp(ot_vi_pipe vi_pipe, ot_isp_sns_blc_clamp blc_clamp);

td_s32  ov7251_write_registeraaa(ot_vi_pipe vi_pipe, td_u32 addr, td_u32 data);
td_s32  ov7251_read_register(ot_vi_pipe vi_pipe, td_u32 addr);
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */
#endif /* OV7251_CMOS_H */
