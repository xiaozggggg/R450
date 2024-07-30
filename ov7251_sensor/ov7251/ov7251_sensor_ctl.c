/*
  Copyright (c), 2001-2021, Shenshu Tech. Co., Ltd.
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

#ifdef OT_GPIO_I2C
#include "gpioi2c_ex.h"
#else
#include "ot_i2c.h"
#endif
#include "securec.h"

#include "ov7251_cmos.h"

#ifndef NA
#define NA 0xFFFF
#endif

#define I2C_DEV_FILE_NUM     16
#define I2C_BUF_NUM          8

static int g_fd[OT_ISP_MAX_PIPE_NUM] = {[0 ...(OT_ISP_MAX_PIPE_NUM - 1)] = -1};

int ov7251_i2c_init(ot_vi_pipe vi_pipe)
{
    int ret;
    char dev_file[I2C_DEV_FILE_NUM] = {0};
    td_u8 dev_num;

    if (g_fd[vi_pipe] >= 0) {
        return TD_SUCCESS;
    }
#ifdef OT_GPIO_I2C
    g_fd[vi_pipe] = open("/dev/gpioi2c_ex", O_RDONLY, S_IRUSR);
    if (g_fd[vi_pipe] < 0) {
        isp_err_trace("Open gpioi2c_ex error!\n");
        return TD_FAILURE;
    }
#else
    ot_isp_sns_commbus *ov7251businfo = TD_NULL;
    ov7251businfo = ov7251_get_bus_info(vi_pipe);
    dev_num = ov7251businfo->i2c_dev;
    (td_void)snprintf_s(dev_file, sizeof(dev_file), sizeof(dev_file) - 1, "/dev/i2c-%u", dev_num);

    printf("====== ov7251businfo->i2c_dev[%d]\n", dev_num);

    g_fd[vi_pipe] = open(dev_file, O_RDWR, S_IRUSR | S_IWUSR);
    if (g_fd[vi_pipe] < 0) {
        isp_err_trace("Open /dev/ot_i2c_drv-%u error!\n", dev_num);
        return TD_FAILURE;
    }

    ret = ioctl(g_fd[vi_pipe], OT_I2C_SLAVE_FORCE, (OV7251_I2C_ADDR >> 1));
    if (ret < 0) {
        isp_err_trace("I2C_SLAVE_FORCE error!\n");
        close(g_fd[vi_pipe]);
        g_fd[vi_pipe] = -1;
        return ret;
    }
#endif

    return TD_SUCCESS;
}

int ov7251_i2c_exit(ot_vi_pipe vi_pipe)
{
    if (g_fd[vi_pipe] >= 0) {
        close(g_fd[vi_pipe]);
        g_fd[vi_pipe] = -1;
        return TD_SUCCESS;
    }
    return TD_FAILURE;
}

td_s32 ov7251_read_register(ot_vi_pipe vi_pipe, td_u32 addr)
{
    ot_unused(vi_pipe);
    ot_unused(addr);
    return TD_SUCCESS;
}

td_s32 ov7251_write_registeraaa(ot_vi_pipe vi_pipe, td_u32 addr, td_u32 data)
{
    if (g_fd[vi_pipe] < 0) {
        return TD_SUCCESS;
    }

#ifdef OT_GPIO_I2C
    i2c_data.dev_addr = OV7251_I2C_ADDR;
    i2c_data.reg_addr = addr;
    i2c_data.addr_byte_num = OV7251_ADDR_BYTE;
    i2c_data.data = data;
    i2c_data.data_byte_num = OV7251_DATA_BYTE;

    ret = ioctl(g_fd[vi_pipe], GPIO_I2C_WRITE, &i2c_data);
    if (ret) {
        isp_err_trace("GPIO-I2C write failed!\n");
        return ret;
    }
#else
    td_u32 idx = 0;
    td_s32 ret;
    td_u8 buf[I2C_BUF_NUM];

    printf("==== ----2addr[0x%x] data[0x%x]\n", addr, data);

    if (OV7251_ADDR_BYTE == 2) {  /* 2 byte */
        buf[idx] = (addr >> 8) & 0xff;  /* shift 8 */
        idx++;
        buf[idx] = addr & 0xff;
        idx++;
    } else {
    }

    if (OV7251_DATA_BYTE == 2) {  /* 2 byte */
    } else {
        buf[idx] = data & 0xff;
        idx++;
    }

    ret = write(g_fd[vi_pipe], buf, OV7251_ADDR_BYTE + OV7251_DATA_BYTE);
    if (ret < 0) {
        isp_err_trace("I2C_WRITE error!\n");
        return TD_FAILURE;
    }

#endif
    return TD_SUCCESS;
}

static void delay_ms(int ms)
{
    usleep(ms * 1000); /* 1ms: 1000us */
    return;
}

void ov7251_prog(ot_vi_pipe vi_pipe, const td_u32 *rom)
{
    ot_unused(vi_pipe);
    ot_unused(rom);
    return;
}

td_void ov7251_blc_clamp(ot_vi_pipe vi_pipe, ot_isp_sns_blc_clamp blc_clamp)
{
    td_s32 ret = TD_SUCCESS;

    ov7251_set_blc_clamp_value(vi_pipe, blc_clamp.blc_clamp_en);

	td_u8 u8blc_value = 0x85;
    if (blc_clamp.blc_clamp_en == TD_TRUE) {
        ret += ov7251_write_registeraaa(vi_pipe, 0x5000, u8blc_value);  /* clamp on */
    } else {
		u8blc_value = u8blc_value & 0xFE;
        ret += ov7251_write_registeraaa(vi_pipe, 0x5000, u8blc_value);  /* clamp off */
    }

    if (ret != TD_SUCCESS) {
        isp_err_trace("write register failed!\n");
    }
	
    return;
}

td_void ov7251_mirror_flip(ot_vi_pipe vi_pipe, ot_isp_sns_mirrorflip_type sns_mirror_flip)
{
	td_u8 u8filp_value = 0x00; 	 // ov7251_read_register(vi_pipe, 0x3820);
	td_u8 u8mirror_value = 0x00; //ov7251_read_register(vi_pipe, 0x3821);
	
    switch (sns_mirror_flip) {
        case ISP_SNS_NORMAL:
			u8filp_value = u8filp_value & 0xFB;
			u8mirror_value = u8mirror_value & 0xFB;
            break;
        case ISP_SNS_MIRROR:
			u8filp_value = u8filp_value & 0xFB;
			u8mirror_value = u8mirror_value | (1 << 2);
            break;
        case ISP_SNS_FLIP:
			u8filp_value = u8filp_value | (1 << 2);
			u8mirror_value = u8mirror_value & 0xFB;
            break;
        case ISP_SNS_MIRROR_FLIP:
			u8filp_value = u8filp_value | (1 << 2);
			u8mirror_value = u8mirror_value | (1 << 2);
            break;
        default:
            break;
    }
	
	ov7251_write_registeraaa(vi_pipe, 0x3820, u8filp_value);
	ov7251_write_registeraaa(vi_pipe, 0x3821, u8mirror_value);
    return;
}


void ov7251_standby(ot_vi_pipe vi_pipe)
{
    td_s32 ret = TD_SUCCESS;
    ret += ov7251_write_registeraaa(vi_pipe, 0x0100, 0x00);  /* STANDBY */
    if (ret != TD_SUCCESS) {
        isp_err_trace("write register failed!\n");
    }
    return;
}

void ov7251_restart(ot_vi_pipe vi_pipe)
{
    td_s32 ret = TD_SUCCESS;
    ret += ov7251_write_registeraaa(vi_pipe, 0x0103, 0x01);  /* restart */
    if (ret != TD_SUCCESS) {
        isp_err_trace("write register failed!\n");
    }
    return;
}

static const td_u16 g_au16SensorCfgSeq[][OV7251_MODE_BUTT + 1] =
{    
    { 0x0103, 0x01},
    { 0x0100, 0x00},
    { 0x3005, 0x00},
    { 0x3012, 0xc0},
    { 0x3013, 0xd2},
    { 0x3014, 0x04},
    { 0x3016, 0x10},
    { 0x3017, 0x00},
    { 0x3018, 0x00},
    { 0x301a, 0x00},
    { 0x301b, 0x00},
    { 0x301c, 0x00},
    { 0x3023, 0x05},
    { 0x3037, 0xf0},
    /*** start 时钟PLL相关乘法除法器，配置    mipi_clk(600M) pix_clk(60M) sys_clk(48M) ADC_clk(240M)****/
	{ 0x3098, 0x02},
	{ 0x3099, 0x28},
	{ 0x309a, 0x05},
	{ 0x309b, 0x04},
	{ 0x309d, 0x00},
	{ 0x30b0, 0x0a},
	{ 0x30b1, 0x01},
	{ 0x30b3, 0x32},
	{ 0x30b4, 0x01},
	{ 0x30b5, 0x05},
	/*** end ***/
	{ 0x3106, 0xda},
    { 0x3500, 0x00}, // 0x00  exposure高位寄存器
    { 0x3501, 0x00}, // 0x00  exposure中位寄存器
    { 0x3502, 0x50}, // 0x50  exposure低位寄存器
    { 0x3503, 0x07}, // 0x07  曝光值和增益使能寄存器
    { 0x3509, 0x10}, // 0x10  手动使能增益
    { 0x350b, 0x02}, // 0x02  增益寄存器 
    { 0x3600, 0x1c},
    { 0x3602, 0x62},
    { 0x3620, 0xb7},
    { 0x3622, 0x04},
    { 0x3626, 0x21},
    { 0x3627, 0x30},
    { 0x3630, 0x44},
    { 0x3631, 0x35},
    { 0x3634, 0x60},
    { 0x3636, 0x00},
    { 0x3662, 0x01},
    { 0x3663, 0x70},
    { 0x3664, 0xf0},
    { 0x3666, 0x0a},
    { 0x3669, 0x1a},
    { 0x366a, 0x00},
    { 0x366b, 0x50},
    { 0x3673, 0x01},
    { 0x3674, 0xef},
    { 0x3675, 0x03},
    { 0x3705, 0xc1},
    { 0x3709, 0x40},
    { 0x373c, 0x08},
    { 0x3742, 0x00},
    { 0x3757, 0xb3},
    { 0x3788, 0x00},
    { 0x37a8, 0x01},
    { 0x37a9, 0xc0},
    { 0x3800, 0x00},
    { 0x3801, 0x04},
    { 0x3802, 0x00},
    { 0x3803, 0x04},
    { 0x3804, 0x02},
    { 0x3805, 0x8b},
    { 0x3806, 0x01},
    { 0x3807, 0xeb},
    { 0x3808, 0x02},
    { 0x3809, 0x80},
    { 0x380a, 0x01},
    { 0x380b, 0xe0},
    { 0x380c, 0x03},
    { 0x380d, 0xa0},
    { 0x380e, 0x06}, // fps设置高位寄存器  100fps:0x02 60fps:0x03 30fps:0x06 20fps:0x0a
    { 0x380f, 0xc0}, // fps设置地位寄存器  100fps:0x09 60fps:0x60 30fps:0xc0 20fps:0x10
    { 0x3810, 0x00},
    { 0x3811, 0x04},
    { 0x3812, 0x00},
    { 0x3813, 0x05},
    { 0x3814, 0x11},
    { 0x3815, 0x11},
    { 0x3820, 0x00}, // 控制翻转
    { 0x3821, 0x00}, // 控制镜像
    { 0x382f, 0x0e},
    { 0x3832, 0x00},
    { 0x3833, 0x05},
    { 0x3834, 0x00},
    { 0x3835, 0x0c},
    { 0x3837, 0x00},
    { 0x3b80, 0x00},
    { 0x3b81, 0xa5},
    { 0x3b82, 0x10},
    { 0x3b83, 0x00},
    { 0x3b84, 0x08},
    { 0x3b85, 0x00},
    { 0x3b86, 0x01},
    { 0x3b87, 0x00},
    { 0x3b88, 0x00},
    { 0x3b89, 0x00},
    { 0x3b8a, 0x00},
    { 0x3b8b, 0x05},
    { 0x3b8c, 0x00},
    { 0x3b8d, 0x00},
    { 0x3b8e, 0x00},
    { 0x3b8f, 0x1a},
    { 0x3b94, 0x05},
    { 0x3b95, 0xf2},
    { 0x3b96, 0x40},
    { 0x3c00, 0x89},
    { 0x3c01, 0x63},
    { 0x3c02, 0x01},
    { 0x3c03, 0x00},
    { 0x3c04, 0x00},
    { 0x3c05, 0x03},
    { 0x3c06, 0x00},
    { 0x3c07, 0x06},
    { 0x3c0c, 0x01},
    { 0x3c0d, 0xd0},
    { 0x3c0e, 0x02}, 
    { 0x3c0f, 0x10},   
    { 0x4001, 0x42},
    { 0x4004, 0x04},
    { 0x4005, 0x00},
    { 0x404e, 0x01},
    { 0x4300, 0xff},
    { 0x4301, 0x00},
    { 0x4501, 0x48},
    { 0x4600, 0x00},
    { 0x4601, 0x4e},
    { 0x4801, 0x0f},
    { 0x4806, 0x0f},
    { 0x4819, 0xaa},
    { 0x4823, 0x3e},
    { 0x4837, 0x19},
    { 0x4a0d, 0x00},
    { 0x4a47, 0x7f},
    { 0x4a49, 0xf0},
    { 0x4a4b, 0x30},
    { 0x5000, 0x85}, // 0x85 开启黑电平矫正、关闭awb矫正
    { 0x5001, 0x80},
    { 0x0100, 0x01}
};

static void ov7251_default_reg_init(ot_vi_pipe vi_pipe)
{
    td_u32 i;
    td_s32 ret = TD_SUCCESS;
    ot_isp_sns_state *pastov7251 = TD_NULL;
    pastov7251 = ov7251_get_ctx(vi_pipe);
    for (i = 0; i < pastov7251->regs_info[0].reg_num; i++) {
        ret += ov7251_write_registeraaa(vi_pipe,
                                     pastov7251->regs_info[0].i2c_data[i].reg_addr,
                                     pastov7251->regs_info[0].i2c_data[i].data);
    }
    if (ret != TD_SUCCESS) {
        isp_err_trace("write register failed!\n");
    }
    return;
}

/* 4K@30fps */
static void ov7251_linear_480p20_10bit_init(ot_vi_pipe vi_pipe)
{
    td_s32 ret = TD_SUCCESS;
    td_u32 i, u32SeqEntries;
    td_u8 u16RegData;
    td_u16 u16RegAddr;

    u32SeqEntries = sizeof(g_au16SensorCfgSeq) / sizeof(g_au16SensorCfgSeq[0]);
    for (i = 0; i < u32SeqEntries; i++) {
        u16RegAddr = g_au16SensorCfgSeq[i][0];
        u16RegData = g_au16SensorCfgSeq[i][1];

        if (u16RegData == NA) {
            continue;
        }

        ov7251_write_registeraaa(vi_pipe, u16RegAddr, u16RegData);
    }
	
	ov7251_default_reg_init(vi_pipe);

    printf("=========== write i2c register finish ========= \n");
    if (ret != TD_SUCCESS) {
        isp_err_trace("write register failed!\n");
        return;
    }

    printf("===OV7251 480P 20fps 10bit LINE Init OK!===\n");
}


void ov7251_init(ot_vi_pipe vi_pipe)
{
    ot_wdr_mode wdr_mode;
    td_bool          init;
    td_u8            img_mode;
    td_s32 ret;
    ot_isp_sns_state *pastov7251 = TD_NULL;
    pastov7251 = ov7251_get_ctx(vi_pipe);
    init       = pastov7251->init;
    wdr_mode   = pastov7251->wdr_mode;
    img_mode   = pastov7251->img_mode;

    ret = ov7251_i2c_init(vi_pipe);
    if (ret != TD_SUCCESS) {
        isp_err_trace("i2c init failed!\n");
        return;
    }

    printf("===OV7251 480P 20fps 10bit LINE Init OK![%d]===\n", img_mode);
    /* When sensor first init, config all registers */
    if (init == TD_FALSE) {
        if(OV7251_SENSOR_480P_20FPS_LINEAR_10BIT == img_mode){
            ov7251_linear_480p20_10bit_init(vi_pipe);
        }
    } else {
        /* When sensor switch mode(linear<->WDR or resolution), config different registers(if possible) */
        if(OV7251_SENSOR_480P_20FPS_LINEAR_10BIT == img_mode){
            ov7251_linear_480p20_10bit_init(vi_pipe);
        }
    }

    pastov7251->init = TD_TRUE;
    return;
}

void ov7251_exit(ot_vi_pipe vi_pipe)
{
    td_s32 ret;
    ret = ov7251_i2c_exit(vi_pipe);
    if (ret != TD_SUCCESS) {
        isp_err_trace("ov7251 exit failed!\n");
    }
    return;
}


