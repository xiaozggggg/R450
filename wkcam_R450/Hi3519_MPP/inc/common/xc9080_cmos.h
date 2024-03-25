/*
  Copyright (c), 2001-2021, Shenshu Tech. Co., Ltd.
 */

#ifndef XC9080_CMOS_H
#define XC9080_CMOS_H

#include "ot_common.h"
#include "ot_common_isp.h"
#include "ot_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

//add by Kyrie
#define OV7251_I2C_ADDR    0xC0
#define OV7251_ADDR_BYTE   2
#define OV7251_DATA_BYTE   1
////////////////////////////////
#define XC9080_I2C_DEV_NUM          2
#define XC9080_I2C_ADDR    0x36
#define XC9080_ADDR_BYTE   2
#define XC9080_DATA_BYTE   1

td_void xc9080_init(ot_vi_pipe vi_pipe, td_u32 bus_id);
td_void xc9080_exit(ot_vi_pipe vi_pipe);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */
#endif /* XC9080_CMOS_H */
