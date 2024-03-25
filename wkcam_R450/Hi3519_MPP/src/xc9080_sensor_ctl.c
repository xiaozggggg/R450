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

#include "xc9080_cmos.h"

#define I2C_DEV_FILE_NUM     16
#define I2C_BUF_NUM          8

static int g_fd[OT_ISP_MAX_PIPE_NUM] = {[0 ...(OT_ISP_MAX_PIPE_NUM - 1)] = -1};

static td_s32 xc9080_register_init(ot_vi_pipe vi_pipe); 

//add by Kyrie
int xc9080_i2c_bypass_on(ot_vi_pipe vi_pipe)
{
	td_s32 ret = TD_SUCCESS;
	
	xc9080_write_register(vi_pipe, 0xfffd, 0x80);
	xc9080_write_register(vi_pipe, 0xfffe, 0x50);
	xc9080_write_register(vi_pipe, 0x004d, 0x03);
	
	return ret;
}

int xc9080_i2c_bypass_off(ot_vi_pipe vi_pipe)
{
	td_s32 ret = TD_SUCCESS;
	
	xc9080_write_register(vi_pipe, 0xfffd, 0x80);
	xc9080_write_register(vi_pipe, 0xfffe, 0x50);
	xc9080_write_register(vi_pipe, 0x004d, 0x00);
	
	return ret;
}

td_s32 ov7251_write_register(ot_vi_pipe vi_pipe, td_u32 addr, td_u32 data)
{
    if (g_fd[vi_pipe] < 0) {
        return TD_SUCCESS;
    }

    td_u32 idx = 0;
    td_s32 ret;
    td_u8 buf[I2C_BUF_NUM];

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

    return TD_SUCCESS;
}

///////////////

int xc9080_i2c_init(ot_vi_pipe vi_pipe, td_u32 bus_id)
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
	dev_num = bus_id;
	printf("### bus_id = %d\n", bus_id);
	(td_void)snprintf_s(dev_file, sizeof(dev_file), sizeof(dev_file) - 1, "/dev/i2c-%u", dev_num);

	g_fd[vi_pipe] = open(dev_file, O_RDWR, S_IRUSR | S_IWUSR);
	if (g_fd[vi_pipe] < 0) {
        isp_err_trace("Open /dev/ot_i2c_drv-%u error!\n", dev_num);
        return TD_FAILURE;
    }

	ret = ioctl(g_fd[vi_pipe], OT_I2C_SLAVE_FORCE, (XC9080_I2C_ADDR >> 1));
    if (ret < 0) {
        isp_err_trace("I2C_SLAVE_FORCE error!\n");
        close(g_fd[vi_pipe]);
        g_fd[vi_pipe] = -1;
        return ret;
    }
#endif

    return TD_SUCCESS;
}

int xc9080_i2c_exit(ot_vi_pipe vi_pipe)
{
    if (g_fd[vi_pipe] >= 0) {
        close(g_fd[vi_pipe]);
        g_fd[vi_pipe] = -1;
        return TD_SUCCESS;
    }
    return TD_FAILURE;
}

td_s32 xc9080_read_register(ot_vi_pipe vi_pipe, td_u32 addr)
{
    ot_unused(vi_pipe);
    ot_unused(addr);
    return TD_SUCCESS;
}

td_s32 xc9080_write_register(ot_vi_pipe vi_pipe, td_u32 addr, td_u32 data)
{
    if (g_fd[vi_pipe] < 0) {
        return TD_SUCCESS;
    }

#ifdef OT_GPIO_I2C
    i2c_data.dev_addr = XC9080_I2C_ADDR;
    i2c_data.reg_addr = addr;
    i2c_data.addr_byte_num = XC9080_ADDR_BYTE;
    i2c_data.data = data;
    i2c_data.data_byte_num = XC9080_DATA_BYTE;

    ret = ioctl(g_fd[vi_pipe], GPIO_I2C_WRITE, &i2c_data);
    if (ret) {
        isp_err_trace("GPIO-I2C write failed!\n");
        return ret;
    }
#else
    td_u32 idx = 0;
    td_s32 ret;
    td_u8 buf[I2C_BUF_NUM];

    if (XC9080_ADDR_BYTE == 2) {  /* 2 byte */
        buf[idx] = (addr >> 8) & 0xff;  /* shift 8 */
        idx++;
        buf[idx] = addr & 0xff;
        idx++;
    } else {
    }

    if (XC9080_DATA_BYTE == 2) {  /* 2 byte */
    } else {
        buf[idx] = data & 0xff;
        idx++;
    }

    ret = write(g_fd[vi_pipe], buf, XC9080_ADDR_BYTE + XC9080_DATA_BYTE);
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

void xc9080_init(ot_vi_pipe vi_pipe, td_u32 bus_id)
{  
    td_s32 ret;

	ret = xc9080_i2c_init(vi_pipe, bus_id);
	if (ret != TD_SUCCESS) {
        isp_err_trace("i2c init failed!\n");
        return;
    }

	xc9080_register_init(vi_pipe);

    return;
}

void xc9080_exit(ot_vi_pipe vi_pipe)
{
    td_s32 ret;
    ret = xc9080_i2c_exit(vi_pipe);
    if (ret != TD_SUCCESS) {
        isp_err_trace("xc9080 exit failed!\n");
    }
    return;
}

static td_s32 ov7251_register_init(ot_vi_pipe vi_pipe)  //add by Kyrie
{
	td_s32 ret = TD_SUCCESS;
		
	xc9080_i2c_bypass_on(vi_pipe);
	
	ret = ioctl(g_fd[vi_pipe], OT_I2C_SLAVE_FORCE, (OV7251_I2C_ADDR >> 1));
    if (ret < 0) {
        isp_err_trace("I2C_SLAVE_FORCE error!\n");
        close(g_fd[vi_pipe]);
        g_fd[vi_pipe] = -1;
        return ret;
    }
#if 1
	ov7251_write_register(vi_pipe, 0x0103, 0x01);
	ov7251_write_register(vi_pipe, 0x0100, 0x00);
	ov7251_write_register(vi_pipe, 0x3005, 0x00);
	ov7251_write_register(vi_pipe, 0x3012, 0xc0);
	ov7251_write_register(vi_pipe, 0x3013, 0xd2);
	ov7251_write_register(vi_pipe, 0x3014, 0x04);
	ov7251_write_register(vi_pipe, 0x3016, 0x10);
	ov7251_write_register(vi_pipe, 0x3017, 0x00);
	ov7251_write_register(vi_pipe, 0x3018, 0x00);
	ov7251_write_register(vi_pipe, 0x301a, 0x00);
	ov7251_write_register(vi_pipe, 0x301b, 0x00);
	ov7251_write_register(vi_pipe, 0x301c, 0x00);
	ov7251_write_register(vi_pipe, 0x3023, 0x05);
	ov7251_write_register(vi_pipe, 0x3037, 0xf0);
	ov7251_write_register(vi_pipe, 0x3098, 0x04);
	ov7251_write_register(vi_pipe, 0x3099, 0x28);
	ov7251_write_register(vi_pipe, 0x309a, 0x05);
	ov7251_write_register(vi_pipe, 0x309b, 0x04);
	ov7251_write_register(vi_pipe, 0x30b0, 0x0a);
	ov7251_write_register(vi_pipe, 0x30b1, 0x01);
	ov7251_write_register(vi_pipe, 0x30b3, 0x64);
	ov7251_write_register(vi_pipe, 0x30b4, 0x03);
	ov7251_write_register(vi_pipe, 0x30b5, 0x05);
	ov7251_write_register(vi_pipe, 0x3106, 0xda);
	ov7251_write_register(vi_pipe, 0x3500, 0x00);
	ov7251_write_register(vi_pipe, 0x3501, 0x1f);
	ov7251_write_register(vi_pipe, 0x3502, 0x80);
	ov7251_write_register(vi_pipe, 0x3503, 0x07);
	ov7251_write_register(vi_pipe, 0x3509, 0x10);
	ov7251_write_register(vi_pipe, 0x350b, 0x10);
	ov7251_write_register(vi_pipe, 0x3600, 0x1c);
	ov7251_write_register(vi_pipe, 0x3602, 0x62);
	ov7251_write_register(vi_pipe, 0x3620, 0xb7);
	ov7251_write_register(vi_pipe, 0x3622, 0x04);
	ov7251_write_register(vi_pipe, 0x3626, 0x21);
	ov7251_write_register(vi_pipe, 0x3627, 0x30);
	ov7251_write_register(vi_pipe, 0x3630, 0x44);
	ov7251_write_register(vi_pipe, 0x3631, 0x35);
	ov7251_write_register(vi_pipe, 0x3634, 0x60);
	ov7251_write_register(vi_pipe, 0x3636, 0x00);
	ov7251_write_register(vi_pipe, 0x3662, 0x01);
	ov7251_write_register(vi_pipe, 0x3663, 0x70);
	ov7251_write_register(vi_pipe, 0x3664, 0xf0);
	ov7251_write_register(vi_pipe, 0x3666, 0x0a);
	ov7251_write_register(vi_pipe, 0x3669, 0x1a);
	ov7251_write_register(vi_pipe, 0x366a, 0x00);
	ov7251_write_register(vi_pipe, 0x366b, 0x50);
	ov7251_write_register(vi_pipe, 0x3673, 0x01);
	ov7251_write_register(vi_pipe, 0x3674, 0xef);
	ov7251_write_register(vi_pipe, 0x3675, 0x03);
	ov7251_write_register(vi_pipe, 0x3705, 0xc1);
	ov7251_write_register(vi_pipe, 0x3709, 0x40);
	ov7251_write_register(vi_pipe, 0x373c, 0x08);
	ov7251_write_register(vi_pipe, 0x3742, 0x00);
	ov7251_write_register(vi_pipe, 0x3757, 0xb3);
	ov7251_write_register(vi_pipe, 0x3788, 0x00);
	ov7251_write_register(vi_pipe, 0x37a8, 0x01);
	ov7251_write_register(vi_pipe, 0x37a9, 0xc0);
	ov7251_write_register(vi_pipe, 0x3800, 0x00);
	ov7251_write_register(vi_pipe, 0x3801, 0x04);
	ov7251_write_register(vi_pipe, 0x3802, 0x00);
	ov7251_write_register(vi_pipe, 0x3803, 0x04);
	ov7251_write_register(vi_pipe, 0x3804, 0x02);
	ov7251_write_register(vi_pipe, 0x3805, 0x8b);
	ov7251_write_register(vi_pipe, 0x3806, 0x01);
	ov7251_write_register(vi_pipe, 0x3807, 0xeb);
	ov7251_write_register(vi_pipe, 0x3808, 0x02);
	ov7251_write_register(vi_pipe, 0x3809, 0x80);
	ov7251_write_register(vi_pipe, 0x380a, 0x01);
	ov7251_write_register(vi_pipe, 0x380b, 0xe0);
	ov7251_write_register(vi_pipe, 0x380c, 0x03);
	ov7251_write_register(vi_pipe, 0x380d, 0xa0);
	ov7251_write_register(vi_pipe, 0x380e, 0x05); //;02, 0x, 0xfor, 0x20fps
	ov7251_write_register(vi_pipe, 0x380f, 0x10); //;0a
	ov7251_write_register(vi_pipe, 0x3810, 0x00);
	ov7251_write_register(vi_pipe, 0x3811, 0x04);
	ov7251_write_register(vi_pipe, 0x3812, 0x00);
	ov7251_write_register(vi_pipe, 0x3813, 0x05);
	ov7251_write_register(vi_pipe, 0x3814, 0x11);
	ov7251_write_register(vi_pipe, 0x3815, 0x11);
	ov7251_write_register(vi_pipe, 0x3820, 0x40);
	ov7251_write_register(vi_pipe, 0x3821, 0x00);
	ov7251_write_register(vi_pipe, 0x382f, 0x0e);
	ov7251_write_register(vi_pipe, 0x3832, 0x00);
	ov7251_write_register(vi_pipe, 0x3833, 0x05);
	ov7251_write_register(vi_pipe, 0x3834, 0x00);
	ov7251_write_register(vi_pipe, 0x3835, 0x0c);
	ov7251_write_register(vi_pipe, 0x3837, 0x00);
	ov7251_write_register(vi_pipe, 0x3b80, 0x00);
	ov7251_write_register(vi_pipe, 0x3b81, 0xa5);
	ov7251_write_register(vi_pipe, 0x3b82, 0x10);
	ov7251_write_register(vi_pipe, 0x3b83, 0x00);
	ov7251_write_register(vi_pipe, 0x3b84, 0x08);
	ov7251_write_register(vi_pipe, 0x3b85, 0x00);
	ov7251_write_register(vi_pipe, 0x3b86, 0x01);
	ov7251_write_register(vi_pipe, 0x3b87, 0x00);
	ov7251_write_register(vi_pipe, 0x3b88, 0x00);
	ov7251_write_register(vi_pipe, 0x3b89, 0x00);
	ov7251_write_register(vi_pipe, 0x3b8a, 0x00);
	ov7251_write_register(vi_pipe, 0x3b8b, 0x05);
	ov7251_write_register(vi_pipe, 0x3b8c, 0x00);
	ov7251_write_register(vi_pipe, 0x3b8d, 0x00);
	ov7251_write_register(vi_pipe, 0x3b8e, 0x00);
	ov7251_write_register(vi_pipe, 0x3b8f, 0x1a);
	ov7251_write_register(vi_pipe, 0x3b94, 0x05);
	ov7251_write_register(vi_pipe, 0x3b95, 0xf2);
	ov7251_write_register(vi_pipe, 0x3b96, 0x40);
	ov7251_write_register(vi_pipe, 0x3c00, 0x89);
	ov7251_write_register(vi_pipe, 0x3c01, 0x63);
	ov7251_write_register(vi_pipe, 0x3c02, 0x01);
	ov7251_write_register(vi_pipe, 0x3c03, 0x00);
	ov7251_write_register(vi_pipe, 0x3c04, 0x00);
	ov7251_write_register(vi_pipe, 0x3c05, 0x03);
	ov7251_write_register(vi_pipe, 0x3c06, 0x00);
	ov7251_write_register(vi_pipe, 0x3c07, 0x06);
	ov7251_write_register(vi_pipe, 0x3c0c, 0x01);
	ov7251_write_register(vi_pipe, 0x3c0d, 0xd0);
	ov7251_write_register(vi_pipe, 0x3c0e, 0x02);
	ov7251_write_register(vi_pipe, 0x3c0f, 0x0a);
	ov7251_write_register(vi_pipe, 0x4001, 0x42);
	ov7251_write_register(vi_pipe, 0x4004, 0x04);
	ov7251_write_register(vi_pipe, 0x4005, 0x00);
	ov7251_write_register(vi_pipe, 0x404e, 0x01);
	ov7251_write_register(vi_pipe, 0x4300, 0xff);
	ov7251_write_register(vi_pipe, 0x4301, 0x00);
	ov7251_write_register(vi_pipe, 0x4501, 0x48);
	ov7251_write_register(vi_pipe, 0x4600, 0x00);
	ov7251_write_register(vi_pipe, 0x4601, 0x4e);
	ov7251_write_register(vi_pipe, 0x4801, 0x0f);
	ov7251_write_register(vi_pipe, 0x4806, 0x0f);
	ov7251_write_register(vi_pipe, 0x4819, 0xaa);
	ov7251_write_register(vi_pipe, 0x4823, 0x3e);
	ov7251_write_register(vi_pipe, 0x4837, 0x19);
	ov7251_write_register(vi_pipe, 0x4a0d, 0x00);
	ov7251_write_register(vi_pipe, 0x4a47, 0x7f);
	ov7251_write_register(vi_pipe, 0x4a49, 0xf0);
	ov7251_write_register(vi_pipe, 0x4a4b, 0x30);
	ov7251_write_register(vi_pipe, 0x5000, 0x85);
	ov7251_write_register(vi_pipe, 0x5001, 0x80);
	ov7251_write_register(vi_pipe, 0x0100, 0x01);
#endif

// 	ov7251_write_register(vi_pipe, 0x103, 0x01);
// ov7251_write_register(vi_pipe, 0x100, 0x00);
// ov7251_write_register(vi_pipe, 0x3005, 0x00);
// ov7251_write_register(vi_pipe, 0x3012, 0xc0);
// ov7251_write_register(vi_pipe, 0x3013, 0xd2);
// ov7251_write_register(vi_pipe, 0x3014, 0x04);
// ov7251_write_register(vi_pipe, 0x3016, 0x10);
// ov7251_write_register(vi_pipe, 0x3017, 0x00);
// ov7251_write_register(vi_pipe, 0x3018, 0x10);
// ov7251_write_register(vi_pipe, 0x301a, 0x00);
// ov7251_write_register(vi_pipe, 0x301b, 0x00);
// ov7251_write_register(vi_pipe, 0x301c, 0x20);
// ov7251_write_register(vi_pipe, 0x3023, 0x07);
// ov7251_write_register(vi_pipe, 0x3037, 0xf0);
// ov7251_write_register(vi_pipe, 0x3098, 0x04);
// ov7251_write_register(vi_pipe, 0x3099, 0x28);
// ov7251_write_register(vi_pipe, 0x309a, 0x05);
// ov7251_write_register(vi_pipe, 0x309b, 0x04);
// ov7251_write_register(vi_pipe, 0x30b0, 0x0a);
// ov7251_write_register(vi_pipe, 0x30b1, 0x01);
// ov7251_write_register(vi_pipe, 0x30b3, 0x32);
// ov7251_write_register(vi_pipe, 0x30b4, 0x02);
// ov7251_write_register(vi_pipe, 0x30b5, 0x05);
// ov7251_write_register(vi_pipe, 0x3106, 0xda);
// ov7251_write_register(vi_pipe, 0x3500, 0x00);
// ov7251_write_register(vi_pipe, 0x3501, 0x01);
// ov7251_write_register(vi_pipe, 0x3502, 0x80);
// ov7251_write_register(vi_pipe, 0x3503, 0x07);
// ov7251_write_register(vi_pipe, 0x3509, 0x10);
// ov7251_write_register(vi_pipe, 0x350b, 0x10);
// ov7251_write_register(vi_pipe, 0x3600, 0x1c);
// ov7251_write_register(vi_pipe, 0x3602, 0x62);
// ov7251_write_register(vi_pipe, 0x3620, 0xb7);
// ov7251_write_register(vi_pipe, 0x3622, 0x04);
// ov7251_write_register(vi_pipe, 0x3626, 0x21);
// ov7251_write_register(vi_pipe, 0x3627, 0x30);
// ov7251_write_register(vi_pipe, 0x3634, 0x41);
// ov7251_write_register(vi_pipe, 0x3636, 0x00);
// ov7251_write_register(vi_pipe, 0x3662, 0x01);
// ov7251_write_register(vi_pipe, 0x3663, 0x70);
// ov7251_write_register(vi_pipe, 0x3664, 0xf0);
// ov7251_write_register(vi_pipe, 0x3666, 0x0a);
// ov7251_write_register(vi_pipe, 0x3669, 0x1a);
// ov7251_write_register(vi_pipe, 0x366a, 0x00);
// ov7251_write_register(vi_pipe, 0x366b, 0x50);
// ov7251_write_register(vi_pipe, 0x3673, 0x01);
// ov7251_write_register(vi_pipe, 0x3674, 0xff);
// ov7251_write_register(vi_pipe, 0x3675, 0x03);
// ov7251_write_register(vi_pipe, 0x3705, 0x41);
// ov7251_write_register(vi_pipe, 0x3709, 0x40);
// ov7251_write_register(vi_pipe, 0x373c, 0xe8);
// ov7251_write_register(vi_pipe, 0x3742, 0x00);
// ov7251_write_register(vi_pipe, 0x3788, 0x00);
// ov7251_write_register(vi_pipe, 0x37a8, 0x02);
// ov7251_write_register(vi_pipe, 0x37a9, 0x14);
// ov7251_write_register(vi_pipe, 0x3800, 0x00);
// ov7251_write_register(vi_pipe, 0x3801, 0x00);
// ov7251_write_register(vi_pipe, 0x3802, 0x00);
// ov7251_write_register(vi_pipe, 0x3803, 0x00);
// ov7251_write_register(vi_pipe, 0x3804, 0x02);
// ov7251_write_register(vi_pipe, 0x3805, 0x8f);
// ov7251_write_register(vi_pipe, 0x3806, 0x01);
// ov7251_write_register(vi_pipe, 0x3807, 0xef);
// ov7251_write_register(vi_pipe, 0x3808, 0x01);
// ov7251_write_register(vi_pipe, 0x3809, 0x40);
// ov7251_write_register(vi_pipe, 0x380a, 0x00);
// ov7251_write_register(vi_pipe, 0x380b, 0xf0);
// ov7251_write_register(vi_pipe, 0x380c, 0x03);
// ov7251_write_register(vi_pipe, 0x380d, 0x04);
// ov7251_write_register(vi_pipe, 0x380e, 0x06);
// ov7251_write_register(vi_pipe, 0x380f, 0x00);
// ov7251_write_register(vi_pipe, 0x3810, 0x00);
// ov7251_write_register(vi_pipe, 0x3811, 0x04);
// ov7251_write_register(vi_pipe, 0x3812, 0x00);
// ov7251_write_register(vi_pipe, 0x3813, 0x05);
// ov7251_write_register(vi_pipe, 0x3814, 0x31);
// ov7251_write_register(vi_pipe, 0x3815, 0x31);
// ov7251_write_register(vi_pipe, 0x3820, 0x42);
// ov7251_write_register(vi_pipe, 0x3821, 0x01);
// ov7251_write_register(vi_pipe, 0x382f, 0x0e);
// ov7251_write_register(vi_pipe, 0x3832, 0x00);
// ov7251_write_register(vi_pipe, 0x3833, 0x05);
// ov7251_write_register(vi_pipe, 0x3834, 0x00);
// ov7251_write_register(vi_pipe, 0x3835, 0x0c);
// ov7251_write_register(vi_pipe, 0x3837, 0x00);
// ov7251_write_register(vi_pipe, 0x3b80, 0x00);
// ov7251_write_register(vi_pipe, 0x3b81, 0xa5);
// ov7251_write_register(vi_pipe, 0x3b82, 0x10);
// ov7251_write_register(vi_pipe, 0x3b83, 0x00);
// ov7251_write_register(vi_pipe, 0x3b84, 0x08);
// ov7251_write_register(vi_pipe, 0x3b85, 0x00);
// ov7251_write_register(vi_pipe, 0x3b86, 0x01);
// ov7251_write_register(vi_pipe, 0x3b87, 0x00);
// ov7251_write_register(vi_pipe, 0x3b88, 0x00);
// ov7251_write_register(vi_pipe, 0x3b89, 0x00);
// ov7251_write_register(vi_pipe, 0x3b8a, 0x00);
// ov7251_write_register(vi_pipe, 0x3b8b, 0x05);
// ov7251_write_register(vi_pipe, 0x3b8c, 0x00);
// ov7251_write_register(vi_pipe, 0x3b8d, 0x00);
// ov7251_write_register(vi_pipe, 0x3b8e, 0x00);
// ov7251_write_register(vi_pipe, 0x3b8f, 0x1a);
// ov7251_write_register(vi_pipe, 0x3b94, 0x05);
// ov7251_write_register(vi_pipe, 0x3b95, 0xf2);
// ov7251_write_register(vi_pipe, 0x3b96, 0x40);
// ov7251_write_register(vi_pipe, 0x3c00, 0x89);
// ov7251_write_register(vi_pipe, 0x3c01, 0xab);
// ov7251_write_register(vi_pipe, 0x3c02, 0x01);
// ov7251_write_register(vi_pipe, 0x3c03, 0x00);
// ov7251_write_register(vi_pipe, 0x3c04, 0x00);
// ov7251_write_register(vi_pipe, 0x3c05, 0x03);
// ov7251_write_register(vi_pipe, 0x3c06, 0x00);
// ov7251_write_register(vi_pipe, 0x3c07, 0x05);
// ov7251_write_register(vi_pipe, 0x3c0c, 0x00);
// ov7251_write_register(vi_pipe, 0x3c0d, 0x00);
// ov7251_write_register(vi_pipe, 0x3c0e, 0x00);
// ov7251_write_register(vi_pipe, 0x3c0f, 0x00);
// ov7251_write_register(vi_pipe, 0x4001, 0xc0);
// ov7251_write_register(vi_pipe, 0x4004, 0x02);
// ov7251_write_register(vi_pipe, 0x4005, 0x20);
// ov7251_write_register(vi_pipe, 0x404e, 0x01);
// ov7251_write_register(vi_pipe, 0x4241, 0x00);
// ov7251_write_register(vi_pipe, 0x4242, 0x00);
// ov7251_write_register(vi_pipe, 0x4300, 0xff);
// ov7251_write_register(vi_pipe, 0x4301, 0x00);
// ov7251_write_register(vi_pipe, 0x4501, 0x48);
// ov7251_write_register(vi_pipe, 0x4600, 0x00);
// ov7251_write_register(vi_pipe, 0x4601, 0x28);
// ov7251_write_register(vi_pipe, 0x4801, 0x0f);
// ov7251_write_register(vi_pipe, 0x4806, 0x0f);
// ov7251_write_register(vi_pipe, 0x4819, 0xaa);
// ov7251_write_register(vi_pipe, 0x4823, 0x3e);
// ov7251_write_register(vi_pipe, 0x4837, 0x21);
// ov7251_write_register(vi_pipe, 0x4a0d, 0x00);
// ov7251_write_register(vi_pipe, 0x4a47, 0x7f);
// ov7251_write_register(vi_pipe, 0x4a49, 0xf0);
// ov7251_write_register(vi_pipe, 0x4a4b, 0x30);
// ov7251_write_register(vi_pipe, 0x5000, 0x85);
// ov7251_write_register(vi_pipe, 0x5001, 0x80);
// ov7251_write_register(vi_pipe, 0x3600, 0x7c);
// ov7251_write_register(vi_pipe, 0x3757, 0xb3);
// ov7251_write_register(vi_pipe, 0x3630, 0x44);
// ov7251_write_register(vi_pipe, 0x3634, 0x60);
// ov7251_write_register(vi_pipe, 0x3631, 0x35);
// ov7251_write_register(vi_pipe, 0x3600, 0x1c);
// ov7251_write_register(vi_pipe, 0x0100, 0x01);

	ret = ioctl(g_fd[vi_pipe], OT_I2C_SLAVE_FORCE, (XC9080_I2C_ADDR >> 1));
    if (ret < 0) {
        isp_err_trace("I2C_SLAVE_FORCE error!\n");
        close(g_fd[vi_pipe]);
        g_fd[vi_pipe] = -1;
        return ret;
    }

	xc9080_i2c_bypass_off(vi_pipe);
	
	printf("===ov7251 Init OK!===\n");
}


static td_s32 xc9080_register_init(ot_vi_pipe vi_pipe)  //add by Kyrie
{
    td_s32 ret = TD_SUCCESS;
#if 0	
    // XC9080 setting

	xc9080_write_register(vi_pipe, 0xfffd, 0x80);
	xc9080_write_register(vi_pipe, 0xfffe, 0x50);
	xc9080_write_register(vi_pipe, 0x001c, 0xff);
	xc9080_write_register(vi_pipe, 0x001d, 0xff);
	xc9080_write_register(vi_pipe, 0x001e, 0xff);
	xc9080_write_register(vi_pipe, 0x001f, 0xff);
	xc9080_write_register(vi_pipe, 0x0018, 0x00);
	xc9080_write_register(vi_pipe, 0x0019, 0x00);
	xc9080_write_register(vi_pipe, 0x001a, 0x00);
	xc9080_write_register(vi_pipe, 0x001b, 0x00);
	xc9080_write_register(vi_pipe, 0x00bc, 0x19);
	xc9080_write_register(vi_pipe, 0x0030, 0x44);
	xc9080_write_register(vi_pipe, 0x0031, 0x88);
	xc9080_write_register(vi_pipe, 0x0032, 0x34);
	xc9080_write_register(vi_pipe, 0x0033, 0x70);

	xc9080_write_register(vi_pipe, 0x0020, 0x02);
	xc9080_write_register(vi_pipe, 0x0021, 0x0d);
	xc9080_write_register(vi_pipe, 0x0022, 0x01);
	xc9080_write_register(vi_pipe, 0x0023, 0x85);
	xc9080_write_register(vi_pipe, 0x0024, 0x06);
	xc9080_write_register(vi_pipe, 0x0025, 0x00);
	xc9080_write_register(vi_pipe, 0x0026, 0x01);
	xc9080_write_register(vi_pipe, 0x0027, 0x06);
	xc9080_write_register(vi_pipe, 0x0028, 0x01);
	xc9080_write_register(vi_pipe, 0x0029, 0x00);
	xc9080_write_register(vi_pipe, 0x002a, 0x01);
	xc9080_write_register(vi_pipe, 0x002b, 0x06);
	xc9080_write_register(vi_pipe, 0x002e, 0x05);

	xc9080_write_register(vi_pipe, 0xfffe, 0x50);
	xc9080_write_register(vi_pipe, 0x0050, 0x0f);
	xc9080_write_register(vi_pipe, 0x0054, 0x0f);
	xc9080_write_register(vi_pipe, 0x0058, 0x00);
	xc9080_write_register(vi_pipe, 0x0058, 0x0f);
	xc9080_write_register(vi_pipe, 0x00bc, 0x19);
	xc9080_write_register(vi_pipe, 0x0090, 0x38);	//0x38
	xc9080_write_register(vi_pipe, 0x00a8, 0x09);	//0x09

	xc9080_write_register(vi_pipe, 0x0200, 0x0f);
	xc9080_write_register(vi_pipe, 0x0201, 0x00);
	xc9080_write_register(vi_pipe, 0x0202, 0x80);
	xc9080_write_register(vi_pipe, 0x0203, 0x00);
	xc9080_write_register(vi_pipe, 0x0214, 0x0f);
	xc9080_write_register(vi_pipe, 0x0215, 0x00);
	xc9080_write_register(vi_pipe, 0x0216, 0x80);
	xc9080_write_register(vi_pipe, 0x0217, 0x00);

	xc9080_write_register(vi_pipe, 0xfffe, 0x26);
	xc9080_write_register(vi_pipe, 0x8001, 0x80);
	xc9080_write_register(vi_pipe, 0x8002, 0x02);
	xc9080_write_register(vi_pipe, 0x8003, 0xe0);
	xc9080_write_register(vi_pipe, 0x8004, 0x01);
	xc9080_write_register(vi_pipe, 0x8005, 0x40);
	xc9080_write_register(vi_pipe, 0x8006, 0x40);
	xc9080_write_register(vi_pipe, 0x8007, 0x10);
	xc9080_write_register(vi_pipe, 0x8008, 0xf0);
	xc9080_write_register(vi_pipe, 0x800b, 0xff);
	xc9080_write_register(vi_pipe, 0x8000, 0x1d);
	xc9080_write_register(vi_pipe, 0x8041, 0x80);
	xc9080_write_register(vi_pipe, 0x8042, 0x02);
	xc9080_write_register(vi_pipe, 0x8043, 0xe0);
	xc9080_write_register(vi_pipe, 0x8044, 0x01);
	xc9080_write_register(vi_pipe, 0x8045, 0x40);
	xc9080_write_register(vi_pipe, 0x8046, 0x40);
	xc9080_write_register(vi_pipe, 0x8047, 0x10);
	xc9080_write_register(vi_pipe, 0x8048, 0xf0);
	xc9080_write_register(vi_pipe, 0x804b, 0xff);
	xc9080_write_register(vi_pipe, 0x8040, 0x1d);

	xc9080_write_register(vi_pipe, 0x8010, 0x01);
	xc9080_write_register(vi_pipe, 0x8012, 0x80);
	xc9080_write_register(vi_pipe, 0x8013, 0x02);
	xc9080_write_register(vi_pipe, 0x8014, 0xe0);
	xc9080_write_register(vi_pipe, 0x8015, 0x01);
	xc9080_write_register(vi_pipe, 0x8016, 0x00);
	xc9080_write_register(vi_pipe, 0x8017, 0x00);
	xc9080_write_register(vi_pipe, 0x8018, 0x00);
	xc9080_write_register(vi_pipe, 0x8019, 0x00);
	xc9080_write_register(vi_pipe, 0x8050, 0x01);
	xc9080_write_register(vi_pipe, 0x8052, 0x80);
	xc9080_write_register(vi_pipe, 0x8053, 0x02);
	xc9080_write_register(vi_pipe, 0x8054, 0xe0);
	xc9080_write_register(vi_pipe, 0x8055, 0x01);
	xc9080_write_register(vi_pipe, 0x8056, 0x00);
	xc9080_write_register(vi_pipe, 0x8057, 0x00);
	xc9080_write_register(vi_pipe, 0x8058, 0x00);
	xc9080_write_register(vi_pipe, 0x8059, 0x00);

	xc9080_write_register(vi_pipe, 0xfffe, 0x2e);
	xc9080_write_register(vi_pipe, 0x0026, 0xc0);
	xc9080_write_register(vi_pipe, 0x0100, 0x00);
	xc9080_write_register(vi_pipe, 0x0101, 0x00);
	xc9080_write_register(vi_pipe, 0x0102, 0x00);
	xc9080_write_register(vi_pipe, 0x0103, 0x00);
	xc9080_write_register(vi_pipe, 0x0104, 0x02);
	xc9080_write_register(vi_pipe, 0x0105, 0x80);
	xc9080_write_register(vi_pipe, 0x0106, 0x01);
	xc9080_write_register(vi_pipe, 0x0107, 0xe0);
	xc9080_write_register(vi_pipe, 0x0108, 0x01);
	xc9080_write_register(vi_pipe, 0x0200, 0x00);
	xc9080_write_register(vi_pipe, 0x0201, 0x00);
	xc9080_write_register(vi_pipe, 0x0202, 0x00);
	xc9080_write_register(vi_pipe, 0x0203, 0x00);
	xc9080_write_register(vi_pipe, 0x0204, 0x02);
	xc9080_write_register(vi_pipe, 0x0205, 0x80);
	xc9080_write_register(vi_pipe, 0x0206, 0x01);
	xc9080_write_register(vi_pipe, 0x0207, 0xe0);
	xc9080_write_register(vi_pipe, 0x0208, 0x01);

	xc9080_write_register(vi_pipe, 0xfffe, 0x30);
	xc9080_write_register(vi_pipe, 0x0019, 0x08);
	xc9080_write_register(vi_pipe, 0x0050, 0x20);
	xc9080_write_register(vi_pipe, 0x005e, 0x7f);
	xc9080_write_register(vi_pipe, 0x005f, 0x02);
	xc9080_write_register(vi_pipe, 0x0060, 0xdf);
	xc9080_write_register(vi_pipe, 0x0061, 0x01);
	xc9080_write_register(vi_pipe, 0x0064, 0x80);
	xc9080_write_register(vi_pipe, 0x0065, 0x02);
	xc9080_write_register(vi_pipe, 0x0066, 0xe0);
	xc9080_write_register(vi_pipe, 0x0067, 0x01);
	xc9080_write_register(vi_pipe, 0x0006, 0x02);
	xc9080_write_register(vi_pipe, 0x0007, 0x80);
	xc9080_write_register(vi_pipe, 0x0008, 0x01);
	xc9080_write_register(vi_pipe, 0x0009, 0xe0);
	xc9080_write_register(vi_pipe, 0x000a, 0x02);
	xc9080_write_register(vi_pipe, 0x000b, 0x80);
	xc9080_write_register(vi_pipe, 0x000c, 0x01);
	xc9080_write_register(vi_pipe, 0x000d, 0xe0);
	xc9080_write_register(vi_pipe, 0xfffe, 0x31);
	xc9080_write_register(vi_pipe, 0x0019, 0x08);
	xc9080_write_register(vi_pipe, 0x0050, 0x20);
	xc9080_write_register(vi_pipe, 0x005e, 0x7f);
	xc9080_write_register(vi_pipe, 0x005f, 0x02);
	xc9080_write_register(vi_pipe, 0x0060, 0xdf);
	xc9080_write_register(vi_pipe, 0x0061, 0x01);
	xc9080_write_register(vi_pipe, 0x0064, 0x80);
	xc9080_write_register(vi_pipe, 0x0065, 0x02);
	xc9080_write_register(vi_pipe, 0x0066, 0xe0);
	xc9080_write_register(vi_pipe, 0x0067, 0x01);
	xc9080_write_register(vi_pipe, 0x0006, 0x02);
	xc9080_write_register(vi_pipe, 0x0007, 0x80);
	xc9080_write_register(vi_pipe, 0x0008, 0x01);
	xc9080_write_register(vi_pipe, 0x0009, 0xe0);
	xc9080_write_register(vi_pipe, 0x000a, 0x02);
	xc9080_write_register(vi_pipe, 0x000b, 0x80);
	xc9080_write_register(vi_pipe, 0x000c, 0x01);
	xc9080_write_register(vi_pipe, 0x000d, 0xe0);
	xc9080_write_register(vi_pipe, 0xfffe, 0x26);
	xc9080_write_register(vi_pipe, 0x0000, 0x00);
	xc9080_write_register(vi_pipe, 0x0009, 0xc4);
	xc9080_write_register(vi_pipe, 0x1000, 0x00);
	xc9080_write_register(vi_pipe, 0x1009, 0xc4);
	xc9080_write_register(vi_pipe, 0x2019, 0x05);
	xc9080_write_register(vi_pipe, 0x201a, 0x00);
	xc9080_write_register(vi_pipe, 0x201b, 0x01);
	xc9080_write_register(vi_pipe, 0x201c, 0xe0);
	xc9080_write_register(vi_pipe, 0x201d, 0x05);
	xc9080_write_register(vi_pipe, 0x201e, 0x00);
	xc9080_write_register(vi_pipe, 0x201f, 0x01);
	xc9080_write_register(vi_pipe, 0x2020, 0xe0);
	xc9080_write_register(vi_pipe, 0x2015, 0x80);
	xc9080_write_register(vi_pipe, 0x2017, 0x1e);
	xc9080_write_register(vi_pipe, 0x2018, 0x1e);
	xc9080_write_register(vi_pipe, 0x2023, 0x03);
	xc9080_write_register(vi_pipe, 0xfffe, 0x2c);
	xc9080_write_register(vi_pipe, 0x0000, 0x00);
	xc9080_write_register(vi_pipe, 0x0001, 0x05);
	xc9080_write_register(vi_pipe, 0x0002, 0x00);
	xc9080_write_register(vi_pipe, 0x0004, 0x02);
	xc9080_write_register(vi_pipe, 0x0005, 0x80);
	xc9080_write_register(vi_pipe, 0x0008, 0x10);
	xc9080_write_register(vi_pipe, 0x0044, 0x08);
	xc9080_write_register(vi_pipe, 0x0045, 0x04);
	xc9080_write_register(vi_pipe, 0x0048, 0x09);
	xc9080_write_register(vi_pipe, 0x0049, 0xf0);
	xc9080_write_register(vi_pipe, 0x0084, 0x08);
	xc9080_write_register(vi_pipe, 0x0085, 0x04);
	xc9080_write_register(vi_pipe, 0x0088, 0x09);
	xc9080_write_register(vi_pipe, 0x0089, 0xf0);
	xc9080_write_register(vi_pipe, 0xfffe, 0x2e);
	xc9080_write_register(vi_pipe, 0x0000, 0x42);
	xc9080_write_register(vi_pipe, 0x0001, 0xee);
	xc9080_write_register(vi_pipe, 0x0003, 0x01);
	xc9080_write_register(vi_pipe, 0x0004, 0xa0);
	xc9080_write_register(vi_pipe, 0x0006, 0x01);
	xc9080_write_register(vi_pipe, 0x0007, 0xa0);
	xc9080_write_register(vi_pipe, 0x000a, 0x13);
	xc9080_write_register(vi_pipe, 0x000b, 0x04);
	xc9080_write_register(vi_pipe, 0x000c, 0x80);
	xc9080_write_register(vi_pipe, 0x000d, 0x02);
	xc9080_write_register(vi_pipe, 0x1000, 0x0a);
	xc9080_write_register(vi_pipe, 0x1001, 0x00);
	xc9080_write_register(vi_pipe, 0x1002, 0x05);
	xc9080_write_register(vi_pipe, 0x1003, 0x80);
	xc9080_write_register(vi_pipe, 0x1004, 0x02);
	xc9080_write_register(vi_pipe, 0x1005, 0x00);
	xc9080_write_register(vi_pipe, 0x1006, 0x05);
	xc9080_write_register(vi_pipe, 0x1007, 0x80);
	xc9080_write_register(vi_pipe, 0x1008, 0x02);
	xc9080_write_register(vi_pipe, 0x1009, 0x00);
	xc9080_write_register(vi_pipe, 0x100a, 0x05);
	xc9080_write_register(vi_pipe, 0x100b, 0x00);
	xc9080_write_register(vi_pipe, 0x100e, 0x00);
	xc9080_write_register(vi_pipe, 0x100f, 0x01);
	xc9080_write_register(vi_pipe, 0xfffe, 0x26);
	xc9080_write_register(vi_pipe, 0x200b, 0x25);
	xc9080_write_register(vi_pipe, 0x200c, 0x04);

	xc9080_write_register(vi_pipe, 0xfffe, 0x30);
	xc9080_write_register(vi_pipe, 0x0004, 0x10);
	xc9080_write_register(vi_pipe, 0xfffe, 0x31);
	xc9080_write_register(vi_pipe, 0x0004, 0x10);

	// isp0 ae
	xc9080_write_register(vi_pipe, 0xfffe, 0x30);
	xc9080_write_register(vi_pipe, 0x1f00, 0x00);
	xc9080_write_register(vi_pipe, 0x1f01, 0x00);
	xc9080_write_register(vi_pipe, 0x1f02, 0x00);
	xc9080_write_register(vi_pipe, 0x1f03, 0x00);
	xc9080_write_register(vi_pipe, 0x1f04, 0x02);
	xc9080_write_register(vi_pipe, 0x1f05, 0x80);
	xc9080_write_register(vi_pipe, 0x1f06, 0x01);
	xc9080_write_register(vi_pipe, 0x1f07, 0xe0);
	xc9080_write_register(vi_pipe, 0x1f08, 0x03);
	xc9080_write_register(vi_pipe, 0x0051, 0x03);

	xc9080_write_register(vi_pipe, 0xfffe, 0x14);

	xc9080_write_register(vi_pipe, 0x0020, 0x03); // isp1 copy from isp0

	xc9080_write_register(vi_pipe, 0xfffe, 0x14);
	xc9080_write_register(vi_pipe, 0x000e, 0x00);
	xc9080_write_register(vi_pipe, 0x010e, 0xc0);
	xc9080_write_register(vi_pipe, 0x010f, 0x01);
	xc9080_write_register(vi_pipe, 0x0110, 0x00);
	xc9080_write_register(vi_pipe, 0x0111, 0x00);
	xc9080_write_register(vi_pipe, 0x0114, 0x00);
	xc9080_write_register(vi_pipe, 0x0115, 0x00);
	xc9080_write_register(vi_pipe, 0x0116, 0x35);
	xc9080_write_register(vi_pipe, 0x0117, 0x01);
	xc9080_write_register(vi_pipe, 0x0118, 0x35);
	xc9080_write_register(vi_pipe, 0x0119, 0x02);
	xc9080_write_register(vi_pipe, 0x011c, 0x00);
	xc9080_write_register(vi_pipe, 0x011d, 0x00);
	xc9080_write_register(vi_pipe, 0x011e, 0x00);
	xc9080_write_register(vi_pipe, 0x011f, 0xff);
	xc9080_write_register(vi_pipe, 0x0120, 0x00);
	xc9080_write_register(vi_pipe, 0x0121, 0xff);
	xc9080_write_register(vi_pipe, 0x0134, 0x00);
	xc9080_write_register(vi_pipe, 0x0135, 0x00);
	xc9080_write_register(vi_pipe, 0x0136, 0x35);
	xc9080_write_register(vi_pipe, 0x0137, 0x0b);
	xc9080_write_register(vi_pipe, 0x013c, 0x00);
	xc9080_write_register(vi_pipe, 0x013d, 0x00);
	xc9080_write_register(vi_pipe, 0x013e, 0x00);
	xc9080_write_register(vi_pipe, 0x013f, 0xff);
	xc9080_write_register(vi_pipe, 0xfffe, 0x14);
	xc9080_write_register(vi_pipe, 0x004c, 0x00);
	xc9080_write_register(vi_pipe, 0x002b, 0x01);
	xc9080_write_register(vi_pipe, 0x004d, 0x01);
	xc9080_write_register(vi_pipe, 0x00fa, 0x00);
	xc9080_write_register(vi_pipe, 0x00fb, 0x20);
	xc9080_write_register(vi_pipe, 0x00fc, 0x00);
	xc9080_write_register(vi_pipe, 0x00fd, 0x80);	//0x20
	xc9080_write_register(vi_pipe, 0x00e2, 0x08);
	xc9080_write_register(vi_pipe, 0x00e3, 0x00);
	xc9080_write_register(vi_pipe, 0x00de, 0x00);
	xc9080_write_register(vi_pipe, 0x00df, 0x10);
	xc9080_write_register(vi_pipe, 0x00a0, 0x01);
	xc9080_write_register(vi_pipe, 0x00a1, 0xC0);	//0x20
	xc9080_write_register(vi_pipe, 0x0104, 0x00);
	xc9080_write_register(vi_pipe, 0x0105, 0x01);
	xc9080_write_register(vi_pipe, 0x0108, 0x15);
	xc9080_write_register(vi_pipe, 0x0109, 0xa0);
	xc9080_write_register(vi_pipe, 0x0055, 0x04);
	xc9080_write_register(vi_pipe, 0x0056, 0x04);
	xc9080_write_register(vi_pipe, 0x0057, 0x04);
	xc9080_write_register(vi_pipe, 0x0058, 0x04);
	xc9080_write_register(vi_pipe, 0x0059, 0x04);
	xc9080_write_register(vi_pipe, 0x005a, 0x04);
	xc9080_write_register(vi_pipe, 0x005b, 0x04);
	xc9080_write_register(vi_pipe, 0x005c, 0x04);
	xc9080_write_register(vi_pipe, 0x005d, 0x04);
	xc9080_write_register(vi_pipe, 0x005e, 0x04);
	xc9080_write_register(vi_pipe, 0x005f, 0x04);
	xc9080_write_register(vi_pipe, 0x0060, 0x04);
	xc9080_write_register(vi_pipe, 0x0061, 0x04);
	xc9080_write_register(vi_pipe, 0x0062, 0x04);
	xc9080_write_register(vi_pipe, 0x0063, 0x04);
	xc9080_write_register(vi_pipe, 0x0064, 0x04);
	xc9080_write_register(vi_pipe, 0x0065, 0x04);
	xc9080_write_register(vi_pipe, 0x0066, 0x04);
	xc9080_write_register(vi_pipe, 0x0067, 0x04);
	xc9080_write_register(vi_pipe, 0x0068, 0x04);
	xc9080_write_register(vi_pipe, 0x0069, 0x04);
	xc9080_write_register(vi_pipe, 0x006a, 0x04);
	xc9080_write_register(vi_pipe, 0x006b, 0x04);
	xc9080_write_register(vi_pipe, 0x006c, 0x04);
	xc9080_write_register(vi_pipe, 0x006d, 0x04);
	xc9080_write_register(vi_pipe, 0x0088, 0x00);
	xc9080_write_register(vi_pipe, 0x0089, 0x00);
	xc9080_write_register(vi_pipe, 0x008a, 0x00);
	xc9080_write_register(vi_pipe, 0x008b, 0x00);
	xc9080_write_register(vi_pipe, 0x0050, 0x01);
	xc9080_write_register(vi_pipe, 0x00ca, 0x00);
	xc9080_write_register(vi_pipe, 0x00cb, 0x80);
	xc9080_write_register(vi_pipe, 0x01bc, 0x00);
	xc9080_write_register(vi_pipe, 0x01bd, 0xa0);
	xc9080_write_register(vi_pipe, 0x01be, 0x00);
	xc9080_write_register(vi_pipe, 0x01bf, 0x60);
	xc9080_write_register(vi_pipe, 0x00cc, 0x00);
	xc9080_write_register(vi_pipe, 0x00cd, 0x50);
	xc9080_write_register(vi_pipe, 0x00c7, 0x20);
	xc9080_write_register(vi_pipe, 0x00d8, 0x80);
	xc9080_write_register(vi_pipe, 0x00c8, 0x01);
	xc9080_write_register(vi_pipe, 0x0208, 0x02);
	xc9080_write_register(vi_pipe, 0x00da, 0x00);
	xc9080_write_register(vi_pipe, 0x00db, 0xa0);
	xc9080_write_register(vi_pipe, 0x00dc, 0x03);
	xc9080_write_register(vi_pipe, 0x00dd, 0x00);
	xc9080_write_register(vi_pipe, 0x0092, 0x00);
	xc9080_write_register(vi_pipe, 0x0093, 0x07);
	xc9080_write_register(vi_pipe, 0x0094, 0x00);
	xc9080_write_register(vi_pipe, 0x00ad, 0x02);
	xc9080_write_register(vi_pipe, 0x0022, 0x1e);
	xc9080_write_register(vi_pipe, 0x01e4, 0x00);
	xc9080_write_register(vi_pipe, 0x01e5, 0x00);
	xc9080_write_register(vi_pipe, 0x01e6, 0x04);
	xc9080_write_register(vi_pipe, 0x01e7, 0x00);
	xc9080_write_register(vi_pipe, 0x01e8, 0x00);
	xc9080_write_register(vi_pipe, 0x01e9, 0x00);
	xc9080_write_register(vi_pipe, 0x01ea, 0x0c);
	xc9080_write_register(vi_pipe, 0x01eb, 0x00);
	xc9080_write_register(vi_pipe, 0x01ec, 0x00);
	xc9080_write_register(vi_pipe, 0x01ed, 0x00);
	xc9080_write_register(vi_pipe, 0x01ee, 0x24);
	xc9080_write_register(vi_pipe, 0x01ef, 0x00);
	xc9080_write_register(vi_pipe, 0x01f0, 0x00);
	xc9080_write_register(vi_pipe, 0x01f1, 0x00);
	xc9080_write_register(vi_pipe, 0x01f2, 0x6c);
	xc9080_write_register(vi_pipe, 0x01f3, 0x00);
	xc9080_write_register(vi_pipe, 0x01f4, 0x00);
	xc9080_write_register(vi_pipe, 0x01f5, 0x01);
	xc9080_write_register(vi_pipe, 0x01f6, 0x44);
	xc9080_write_register(vi_pipe, 0x01f7, 0x00);
	xc9080_write_register(vi_pipe, 0x01f8, 0x00);
	xc9080_write_register(vi_pipe, 0x01f9, 0x04);
	xc9080_write_register(vi_pipe, 0x01fa, 0x00);
	xc9080_write_register(vi_pipe, 0x01fb, 0x00);
	xc9080_write_register(vi_pipe, 0x00b2, 0x02);
	xc9080_write_register(vi_pipe, 0x00b3, 0xd0);
	xc9080_write_register(vi_pipe, 0x00b4, 0x02);
	xc9080_write_register(vi_pipe, 0x00b5, 0xb0);
	xc9080_write_register(vi_pipe, 0x00b6, 0x02);
	xc9080_write_register(vi_pipe, 0x00b7, 0x90);
	xc9080_write_register(vi_pipe, 0x00b8, 0x02);
	xc9080_write_register(vi_pipe, 0x00b9, 0x00);
	xc9080_write_register(vi_pipe, 0x00ba, 0x01);
	xc9080_write_register(vi_pipe, 0x00bb, 0xb0);
	xc9080_write_register(vi_pipe, 0x00bc, 0x00);
	xc9080_write_register(vi_pipe, 0x00bd, 0xf0);
	xc9080_write_register(vi_pipe, 0x01cd, 0x28);
	xc9080_write_register(vi_pipe, 0x01cb, 0x00);
	xc9080_write_register(vi_pipe, 0x01cc, 0x40);
	xc9080_write_register(vi_pipe, 0x01d6, 0x00);
	xc9080_write_register(vi_pipe, 0x01d7, 0x04);
	xc9080_write_register(vi_pipe, 0x01d8, 0x14);
	xc9080_write_register(vi_pipe, 0x01d9, 0x50);
	xc9080_write_register(vi_pipe, 0x01da, 0x70);
	xc9080_write_register(vi_pipe, 0x01db, 0x90);
	xc9080_write_register(vi_pipe, 0x01c0, 0x08);
	xc9080_write_register(vi_pipe, 0x01c7, 0x06);
	xc9080_write_register(vi_pipe, 0x01c9, 0x02);
	xc9080_write_register(vi_pipe, 0x01ca, 0x30);
	xc9080_write_register(vi_pipe, 0x01d1, 0x40);
	xc9080_write_register(vi_pipe, 0x01b1, 0x30);
	xc9080_write_register(vi_pipe, 0x01b2, 0x01);
	xc9080_write_register(vi_pipe, 0x01b3, 0x00);
	xc9080_write_register(vi_pipe, 0x01b4, 0x06);
	xc9080_write_register(vi_pipe, 0x01b5, 0x00);
	xc9080_write_register(vi_pipe, 0x016e, 0x02);
	xc9080_write_register(vi_pipe, 0x016f, 0x80);
	xc9080_write_register(vi_pipe, 0x01d3, 0x00);
	xc9080_write_register(vi_pipe, 0x01d4, 0x30);
	xc9080_write_register(vi_pipe, 0x016c, 0x00);
	xc9080_write_register(vi_pipe, 0x016d, 0x00);
	xc9080_write_register(vi_pipe, 0x01ba, 0x08);
	xc9080_write_register(vi_pipe, 0x0212, 0x00);
	// isp0 ae

	// isp1 ae
	xc9080_write_register(vi_pipe, 0xfffe, 0x31);
	xc9080_write_register(vi_pipe, 0x1f00, 0x00);
	xc9080_write_register(vi_pipe, 0x1f01, 0x00);
	xc9080_write_register(vi_pipe, 0x1f02, 0x00);
	xc9080_write_register(vi_pipe, 0x1f03, 0x00);
	xc9080_write_register(vi_pipe, 0x1f04, 0x02);
	xc9080_write_register(vi_pipe, 0x1f05, 0x80);
	xc9080_write_register(vi_pipe, 0x1f06, 0x01);
	xc9080_write_register(vi_pipe, 0x1f07, 0xe0);
	xc9080_write_register(vi_pipe, 0x1f08, 0x03);
	xc9080_write_register(vi_pipe, 0x0051, 0x03);
	xc9080_write_register(vi_pipe, 0xfffe, 0x14);
	xc9080_write_register(vi_pipe, 0x000f, 0x01);
	xc9080_write_register(vi_pipe, 0x0ac2, 0xc0);
	xc9080_write_register(vi_pipe, 0x0ac3, 0x01);
	xc9080_write_register(vi_pipe, 0x0ac4, 0x00);
	xc9080_write_register(vi_pipe, 0x0ac5, 0x00);
	xc9080_write_register(vi_pipe, 0x0ac8, 0x00);
	xc9080_write_register(vi_pipe, 0x0ac9, 0x00);
	xc9080_write_register(vi_pipe, 0x0aca, 0x35);
	xc9080_write_register(vi_pipe, 0x0acb, 0x01);
	xc9080_write_register(vi_pipe, 0x0acc, 0x35);
	xc9080_write_register(vi_pipe, 0x0acd, 0x02);
	xc9080_write_register(vi_pipe, 0x0ad0, 0x00);
	xc9080_write_register(vi_pipe, 0x0ad1, 0x00);
	xc9080_write_register(vi_pipe, 0x0ad2, 0x00);
	xc9080_write_register(vi_pipe, 0x0ad3, 0xff);
	xc9080_write_register(vi_pipe, 0x0ad4, 0x00);
	xc9080_write_register(vi_pipe, 0x0ad5, 0xff);
	xc9080_write_register(vi_pipe, 0x0ae8, 0x00);
	xc9080_write_register(vi_pipe, 0x0ae9, 0x00);
	xc9080_write_register(vi_pipe, 0x0aea, 0x35);
	xc9080_write_register(vi_pipe, 0x0aeb, 0x0b);
	xc9080_write_register(vi_pipe, 0x0af0, 0x00);
	xc9080_write_register(vi_pipe, 0x0af1, 0x00);
	xc9080_write_register(vi_pipe, 0x0af2, 0x00);
	xc9080_write_register(vi_pipe, 0x0af3, 0xff);
	xc9080_write_register(vi_pipe, 0xfffe, 0x14);
	xc9080_write_register(vi_pipe, 0x0a00, 0x00);
	xc9080_write_register(vi_pipe, 0x003c, 0x00);
	xc9080_write_register(vi_pipe, 0x0a01, 0x01);
	xc9080_write_register(vi_pipe, 0x0aae, 0x00);
	xc9080_write_register(vi_pipe, 0x0aaf, 0x80);	//0x20
	xc9080_write_register(vi_pipe, 0x0ab0, 0x00);
	xc9080_write_register(vi_pipe, 0x0ab1, 0x20);
	xc9080_write_register(vi_pipe, 0x0a96, 0x08);
	xc9080_write_register(vi_pipe, 0x0a97, 0x00);
	xc9080_write_register(vi_pipe, 0x0a92, 0x00);
	xc9080_write_register(vi_pipe, 0x0a93, 0x10);
	xc9080_write_register(vi_pipe, 0x0a54, 0x01);
	xc9080_write_register(vi_pipe, 0x0a55, 0xC0);	//0x20
	xc9080_write_register(vi_pipe, 0x0ab8, 0x00);
	xc9080_write_register(vi_pipe, 0x0ab9, 0x01);
	xc9080_write_register(vi_pipe, 0x0abc, 0x15);
	xc9080_write_register(vi_pipe, 0x0abd, 0xa0);
	xc9080_write_register(vi_pipe, 0x0a09, 0x04);
	xc9080_write_register(vi_pipe, 0x0a0a, 0x04);
	xc9080_write_register(vi_pipe, 0x0a0b, 0x04);
	xc9080_write_register(vi_pipe, 0x0a0c, 0x04);
	xc9080_write_register(vi_pipe, 0x0a0d, 0x04);
	xc9080_write_register(vi_pipe, 0x0a0e, 0x04);
	xc9080_write_register(vi_pipe, 0x0a0f, 0x04);
	xc9080_write_register(vi_pipe, 0x0a10, 0x04);
	xc9080_write_register(vi_pipe, 0x0a11, 0x04);
	xc9080_write_register(vi_pipe, 0x0a12, 0x04);
	xc9080_write_register(vi_pipe, 0x0a13, 0x04);
	xc9080_write_register(vi_pipe, 0x0a14, 0x04);
	xc9080_write_register(vi_pipe, 0x0a15, 0x04);
	xc9080_write_register(vi_pipe, 0x0a16, 0x04);
	xc9080_write_register(vi_pipe, 0x0a17, 0x04);
	xc9080_write_register(vi_pipe, 0x0a18, 0x04);
	xc9080_write_register(vi_pipe, 0x0a19, 0x04);
	xc9080_write_register(vi_pipe, 0x0a1a, 0x04);
	xc9080_write_register(vi_pipe, 0x0a1b, 0x04);
	xc9080_write_register(vi_pipe, 0x0a1c, 0x04);
	xc9080_write_register(vi_pipe, 0x0a1d, 0x04);
	xc9080_write_register(vi_pipe, 0x0a1e, 0x04);
	xc9080_write_register(vi_pipe, 0x0a1f, 0x04);
	xc9080_write_register(vi_pipe, 0x0a20, 0x04);
	xc9080_write_register(vi_pipe, 0x0a21, 0x04);
	xc9080_write_register(vi_pipe, 0x0a3c, 0x00);
	xc9080_write_register(vi_pipe, 0x0a3d, 0x00);
	xc9080_write_register(vi_pipe, 0x0a3e, 0x00);
	xc9080_write_register(vi_pipe, 0x0a3f, 0x00);
	xc9080_write_register(vi_pipe, 0x0a04, 0x01);
	xc9080_write_register(vi_pipe, 0x0a7e, 0x00);
	xc9080_write_register(vi_pipe, 0x0a7f, 0x80);
	xc9080_write_register(vi_pipe, 0x0b70, 0x00);
	xc9080_write_register(vi_pipe, 0x0b71, 0xa0);
	xc9080_write_register(vi_pipe, 0x0b72, 0x00);
	xc9080_write_register(vi_pipe, 0x0b73, 0x60);
	xc9080_write_register(vi_pipe, 0x0a80, 0x00);
	xc9080_write_register(vi_pipe, 0x0a81, 0x50);
	xc9080_write_register(vi_pipe, 0x0a7b, 0x20);
	xc9080_write_register(vi_pipe, 0x0a8c, 0x80);
	xc9080_write_register(vi_pipe, 0x0a7c, 0x01);
	xc9080_write_register(vi_pipe, 0x0bbc, 0x02);
	xc9080_write_register(vi_pipe, 0x0a8e, 0x00);
	xc9080_write_register(vi_pipe, 0x0a8f, 0xa0);
	xc9080_write_register(vi_pipe, 0x0a90, 0x03);
	xc9080_write_register(vi_pipe, 0x0a91, 0x00);
	xc9080_write_register(vi_pipe, 0x0a46, 0x00);
	xc9080_write_register(vi_pipe, 0x0a47, 0x07);
	xc9080_write_register(vi_pipe, 0x0a48, 0x00);
	xc9080_write_register(vi_pipe, 0x0a61, 0x02);
	xc9080_write_register(vi_pipe, 0x0022, 0x1e);
	xc9080_write_register(vi_pipe, 0x0b98, 0x00);
	xc9080_write_register(vi_pipe, 0x0b99, 0x00);
	xc9080_write_register(vi_pipe, 0x0b9a, 0x04);
	xc9080_write_register(vi_pipe, 0x0b9b, 0x00);
	xc9080_write_register(vi_pipe, 0x0b9c, 0x00);
	xc9080_write_register(vi_pipe, 0x0b9d, 0x00);
	xc9080_write_register(vi_pipe, 0x0b9e, 0x0c);
	xc9080_write_register(vi_pipe, 0x0b9f, 0x00);
	xc9080_write_register(vi_pipe, 0x0ba0, 0x00);
	xc9080_write_register(vi_pipe, 0x0ba1, 0x00);
	xc9080_write_register(vi_pipe, 0x0ba2, 0x24);
	xc9080_write_register(vi_pipe, 0x0ba3, 0x00);
	xc9080_write_register(vi_pipe, 0x0ba4, 0x00);
	xc9080_write_register(vi_pipe, 0x0ba5, 0x00);
	xc9080_write_register(vi_pipe, 0x0ba6, 0x6c);
	xc9080_write_register(vi_pipe, 0x0ba7, 0x00);
	xc9080_write_register(vi_pipe, 0x0ba8, 0x00);
	xc9080_write_register(vi_pipe, 0x0ba9, 0x01);
	xc9080_write_register(vi_pipe, 0x0baa, 0x44);
	xc9080_write_register(vi_pipe, 0x0bab, 0x00);
	xc9080_write_register(vi_pipe, 0x0bac, 0x00);
	xc9080_write_register(vi_pipe, 0x0bad, 0x04);
	xc9080_write_register(vi_pipe, 0x0bae, 0x00);
	xc9080_write_register(vi_pipe, 0x0baf, 0x00);
	xc9080_write_register(vi_pipe, 0x0a66, 0x02);
	xc9080_write_register(vi_pipe, 0x0a67, 0xd0);
	xc9080_write_register(vi_pipe, 0x0a68, 0x02);
	xc9080_write_register(vi_pipe, 0x0a69, 0xb0);
	xc9080_write_register(vi_pipe, 0x0a6a, 0x02);
	xc9080_write_register(vi_pipe, 0x0a6b, 0x90);
	xc9080_write_register(vi_pipe, 0x0a6c, 0x02);
	xc9080_write_register(vi_pipe, 0x0a6d, 0x00);
	xc9080_write_register(vi_pipe, 0x0a6e, 0x01);
	xc9080_write_register(vi_pipe, 0x0a6f, 0xb0);
	xc9080_write_register(vi_pipe, 0x0a70, 0x00);
	xc9080_write_register(vi_pipe, 0x0a71, 0xf0);
	xc9080_write_register(vi_pipe, 0x0b81, 0x28);
	xc9080_write_register(vi_pipe, 0x0b7f, 0x00);
	xc9080_write_register(vi_pipe, 0x0b80, 0x40);
	xc9080_write_register(vi_pipe, 0x0b8a, 0x00);
	xc9080_write_register(vi_pipe, 0x0b8b, 0x04);
	xc9080_write_register(vi_pipe, 0x0b8c, 0x14);
	xc9080_write_register(vi_pipe, 0x0b8d, 0x50);
	xc9080_write_register(vi_pipe, 0x0b8e, 0x70);
	xc9080_write_register(vi_pipe, 0x0b8f, 0x90);
	xc9080_write_register(vi_pipe, 0x0b74, 0x08);
	xc9080_write_register(vi_pipe, 0x0b7b, 0x06);
	xc9080_write_register(vi_pipe, 0x0b7d, 0x02);
	xc9080_write_register(vi_pipe, 0x0b7e, 0x30);
	xc9080_write_register(vi_pipe, 0x0b85, 0x40);
	xc9080_write_register(vi_pipe, 0x0b65, 0x30);
	xc9080_write_register(vi_pipe, 0x0b66, 0x01);
	xc9080_write_register(vi_pipe, 0x0b67, 0x00);
	xc9080_write_register(vi_pipe, 0x0b68, 0x06);
	xc9080_write_register(vi_pipe, 0x0b69, 0x00);
	xc9080_write_register(vi_pipe, 0x0b22, 0x02);
	xc9080_write_register(vi_pipe, 0x0b23, 0x80);
	xc9080_write_register(vi_pipe, 0x0b87, 0x00);
	xc9080_write_register(vi_pipe, 0x0b88, 0x30);
	xc9080_write_register(vi_pipe, 0x0b20, 0x00);
	xc9080_write_register(vi_pipe, 0x0b21, 0x00);
	xc9080_write_register(vi_pipe, 0x0b6e, 0x08);
	xc9080_write_register(vi_pipe, 0x0bc6, 0x00);
	// isp1 ae

	xc9080_write_register(vi_pipe, 0xfffe, 0x14);
	xc9080_write_register(vi_pipe, 0x002b, 0x01);
	xc9080_write_register(vi_pipe, 0x002c, 0x00);
	xc9080_write_register(vi_pipe, 0x0030, 0x01);
	xc9080_write_register(vi_pipe, 0x0620, 0x01);
	xc9080_write_register(vi_pipe, 0x0621, 0x01);
	xc9080_write_register(vi_pipe, 0xfffe, 0x30);
	xc9080_write_register(vi_pipe, 0x0000, 0x47);
	xc9080_write_register(vi_pipe, 0x0001, 0x00);
	xc9080_write_register(vi_pipe, 0x0002, 0x10);
	xc9080_write_register(vi_pipe, 0x0003, 0x00);
	xc9080_write_register(vi_pipe, 0x0004, 0x90);
	xc9080_write_register(vi_pipe, 0x2300, 0x09);
	xc9080_write_register(vi_pipe, 0x0019, 0x0b);
	xc9080_write_register(vi_pipe, 0x0051, 0x01);
	xc9080_write_register(vi_pipe, 0xfffe, 0x14);
	xc9080_write_register(vi_pipe, 0x003c, 0x00);
	xc9080_write_register(vi_pipe, 0x003d, 0x00);
	xc9080_write_register(vi_pipe, 0x0041, 0x01);
	xc9080_write_register(vi_pipe, 0x0fd4, 0x01);
	xc9080_write_register(vi_pipe, 0x0fd5, 0x01);
	xc9080_write_register(vi_pipe, 0xfffe, 0x31);
	xc9080_write_register(vi_pipe, 0x0000, 0x47);
	xc9080_write_register(vi_pipe, 0x0001, 0x00);
	xc9080_write_register(vi_pipe, 0x0002, 0x10);
	xc9080_write_register(vi_pipe, 0x0003, 0x00);
	xc9080_write_register(vi_pipe, 0x0004, 0x90);
	xc9080_write_register(vi_pipe, 0x2300, 0x09);
	xc9080_write_register(vi_pipe, 0x0019, 0x0b);
	xc9080_write_register(vi_pipe, 0x0051, 0x01);

	xc9080_write_register(vi_pipe, 0xfffe, 0x30);
	xc9080_write_register(vi_pipe, 0x0013, 0x40); // blc
	xc9080_write_register(vi_pipe, 0x071b, 0xff);

	// gamma
	xc9080_write_register(vi_pipe, 0xfffe, 0x30);
	xc9080_write_register(vi_pipe, 0x1400, 0x00);
	xc9080_write_register(vi_pipe, 0x1401, 0x05);
	xc9080_write_register(vi_pipe, 0x1402, 0x0a);
	xc9080_write_register(vi_pipe, 0x1403, 0x0f);
	xc9080_write_register(vi_pipe, 0x1404, 0x15);
	xc9080_write_register(vi_pipe, 0x1405, 0x1a);
	xc9080_write_register(vi_pipe, 0x1406, 0x1f);
	xc9080_write_register(vi_pipe, 0x1407, 0x24);
	xc9080_write_register(vi_pipe, 0x1408, 0x29);
	xc9080_write_register(vi_pipe, 0x1409, 0x2e);
	xc9080_write_register(vi_pipe, 0x140a, 0x32);
	xc9080_write_register(vi_pipe, 0x140b, 0x37);
	xc9080_write_register(vi_pipe, 0x140c, 0x3c);
	xc9080_write_register(vi_pipe, 0x140d, 0x40);
	xc9080_write_register(vi_pipe, 0x140e, 0x45);
	xc9080_write_register(vi_pipe, 0x140f, 0x49);
	xc9080_write_register(vi_pipe, 0x1410, 0x4e);
	xc9080_write_register(vi_pipe, 0x1411, 0x52);
	xc9080_write_register(vi_pipe, 0x1412, 0x56);
	xc9080_write_register(vi_pipe, 0x1413, 0x5a);
	xc9080_write_register(vi_pipe, 0x1414, 0x5e);
	xc9080_write_register(vi_pipe, 0x1415, 0x62);
	xc9080_write_register(vi_pipe, 0x1416, 0x65);
	xc9080_write_register(vi_pipe, 0x1417, 0x69);
	xc9080_write_register(vi_pipe, 0x1418, 0x6c);
	xc9080_write_register(vi_pipe, 0x1419, 0x6f);
	xc9080_write_register(vi_pipe, 0x141a, 0x73);
	xc9080_write_register(vi_pipe, 0x141b, 0x76);
	xc9080_write_register(vi_pipe, 0x141c, 0x79);
	xc9080_write_register(vi_pipe, 0x141d, 0x7c);
	xc9080_write_register(vi_pipe, 0x141e, 0x7e);
	xc9080_write_register(vi_pipe, 0x141f, 0x81);
	xc9080_write_register(vi_pipe, 0x1420, 0x84);
	xc9080_write_register(vi_pipe, 0x1421, 0x89);
	xc9080_write_register(vi_pipe, 0x1422, 0x8d);
	xc9080_write_register(vi_pipe, 0x1423, 0x92);
	xc9080_write_register(vi_pipe, 0x1424, 0x96);
	xc9080_write_register(vi_pipe, 0x1425, 0x9a);
	xc9080_write_register(vi_pipe, 0x1426, 0x9d);
	xc9080_write_register(vi_pipe, 0x1427, 0xa1);
	xc9080_write_register(vi_pipe, 0x1428, 0xa4);
	xc9080_write_register(vi_pipe, 0x1429, 0xa7);
	xc9080_write_register(vi_pipe, 0x142a, 0xaa);
	xc9080_write_register(vi_pipe, 0x142b, 0xad);
	xc9080_write_register(vi_pipe, 0x142c, 0xaf);
	xc9080_write_register(vi_pipe, 0x142d, 0xb2);
	xc9080_write_register(vi_pipe, 0x142e, 0xb4);
	xc9080_write_register(vi_pipe, 0x142f, 0xb6);
	xc9080_write_register(vi_pipe, 0x1430, 0xb8);
	xc9080_write_register(vi_pipe, 0x1431, 0xbc);
	xc9080_write_register(vi_pipe, 0x1432, 0xc0);
	xc9080_write_register(vi_pipe, 0x1433, 0xc4);
	xc9080_write_register(vi_pipe, 0x1434, 0xc8);
	xc9080_write_register(vi_pipe, 0x1435, 0xcc);
	xc9080_write_register(vi_pipe, 0x1436, 0xd0);
	xc9080_write_register(vi_pipe, 0x1437, 0xd4);
	xc9080_write_register(vi_pipe, 0x1438, 0xd8);
	xc9080_write_register(vi_pipe, 0x1439, 0xdd);
	xc9080_write_register(vi_pipe, 0x143a, 0xe1);
	xc9080_write_register(vi_pipe, 0x143b, 0xe6);
	xc9080_write_register(vi_pipe, 0x143c, 0xeb);
	xc9080_write_register(vi_pipe, 0x143d, 0xf0);
	xc9080_write_register(vi_pipe, 0x143e, 0xf5);
	xc9080_write_register(vi_pipe, 0x143f, 0xfa);
	xc9080_write_register(vi_pipe, 0x1440, 0xff);

	// advance_raw_dns     20170623
	xc9080_write_register(vi_pipe, 0xfffe, 0x30);

	xc9080_write_register(vi_pipe, 0x2000, 0x14); // s0_sigma_0
	xc9080_write_register(vi_pipe, 0x2001, 0x18);
	xc9080_write_register(vi_pipe, 0x2002, 0x1d);
	xc9080_write_register(vi_pipe, 0x2003, 0x20);
	xc9080_write_register(vi_pipe, 0x2004, 0x28);
	xc9080_write_register(vi_pipe, 0x2005, 0x30); // s0_sigma_5

	xc9080_write_register(vi_pipe, 0x2006, 0x18); // s0_Gsl_0
	xc9080_write_register(vi_pipe, 0x2007, 0x14);
	xc9080_write_register(vi_pipe, 0x2008, 0x10);
	xc9080_write_register(vi_pipe, 0x2009, 0x0a);
	xc9080_write_register(vi_pipe, 0x200a, 0x04);
	xc9080_write_register(vi_pipe, 0x200b, 0x01); // s0_Gsl_5

	xc9080_write_register(vi_pipe, 0x200c, 0x1a); // s0_RBsl_0
	xc9080_write_register(vi_pipe, 0x200d, 0x18);
	xc9080_write_register(vi_pipe, 0x200e, 0x16);
	xc9080_write_register(vi_pipe, 0x200f, 0x10);
	xc9080_write_register(vi_pipe, 0x2010, 0x08);
	xc9080_write_register(vi_pipe, 0x2011, 0x04); // s0_RBsl_5

	xc9080_write_register(vi_pipe, 0x2012, 0x24); // s0_ps00    //sigma_scale 大
	xc9080_write_register(vi_pipe, 0x2013, 0x24);
	xc9080_write_register(vi_pipe, 0x2014, 0x28);
	xc9080_write_register(vi_pipe, 0x2015, 0x30);
	xc9080_write_register(vi_pipe, 0x2016, 0x38);
	xc9080_write_register(vi_pipe, 0x2017, 0x40); // s0_ps05

	xc9080_write_register(vi_pipe, 0x2018, 0x20); // s0_ps10
	xc9080_write_register(vi_pipe, 0x2019, 0x20);
	xc9080_write_register(vi_pipe, 0x201a, 0x24);
	xc9080_write_register(vi_pipe, 0x201b, 0x28);
	xc9080_write_register(vi_pipe, 0x201c, 0x30);
	xc9080_write_register(vi_pipe, 0x201d, 0x38); // s0_ps15

	xc9080_write_register(vi_pipe, 0x201e, 0x18); // s0_ps20
	xc9080_write_register(vi_pipe, 0x201f, 0x1d);
	xc9080_write_register(vi_pipe, 0x2020, 0x20);
	xc9080_write_register(vi_pipe, 0x2021, 0x24);
	xc9080_write_register(vi_pipe, 0x2022, 0x28);
	xc9080_write_register(vi_pipe, 0x2023, 0x30); // s0_ps25

	xc9080_write_register(vi_pipe, 0x2024, 0x10); // s0_ps30
	xc9080_write_register(vi_pipe, 0x2025, 0x12);
	xc9080_write_register(vi_pipe, 0x2026, 0x18);
	xc9080_write_register(vi_pipe, 0x2027, 0x1d);
	xc9080_write_register(vi_pipe, 0x2028, 0x20);
	xc9080_write_register(vi_pipe, 0x2029, 0x28); // s0_ps35

	xc9080_write_register(vi_pipe, 0x202a, 0x28); // s0_pl00     //h2_scale 小
	xc9080_write_register(vi_pipe, 0x202b, 0x20);
	xc9080_write_register(vi_pipe, 0x202c, 0x16);
	xc9080_write_register(vi_pipe, 0x202d, 0x10);
	xc9080_write_register(vi_pipe, 0x202e, 0x0c);
	xc9080_write_register(vi_pipe, 0x202f, 0x08); // s0_pl05

	xc9080_write_register(vi_pipe, 0x2030, 0x30); // s0_pl10
	xc9080_write_register(vi_pipe, 0x2031, 0x28);
	xc9080_write_register(vi_pipe, 0x2032, 0x24);
	xc9080_write_register(vi_pipe, 0x2033, 0x20);
	xc9080_write_register(vi_pipe, 0x2034, 0x1a);
	xc9080_write_register(vi_pipe, 0x2035, 0x16); // s0_pl15

	xc9080_write_register(vi_pipe, 0x2036, 0x38); // s0_pl20
	xc9080_write_register(vi_pipe, 0x2037, 0x30);
	xc9080_write_register(vi_pipe, 0x2038, 0x28);
	xc9080_write_register(vi_pipe, 0x2039, 0x24);
	xc9080_write_register(vi_pipe, 0x203a, 0x20);
	xc9080_write_register(vi_pipe, 0x203b, 0x1a); // s0_pl25

	xc9080_write_register(vi_pipe, 0x203c, 0x3a); // s0_pl30
	xc9080_write_register(vi_pipe, 0x203d, 0x32);
	xc9080_write_register(vi_pipe, 0x203e, 0x2d);
	xc9080_write_register(vi_pipe, 0x203f, 0x28);
	xc9080_write_register(vi_pipe, 0x2040, 0x24);
	xc9080_write_register(vi_pipe, 0x2041, 0x20); // s0_pl35

	xc9080_write_register(vi_pipe, 0x2044, 0x10); // bit[4:0]thre_y

	// UV DNS
	xc9080_write_register(vi_pipe, 0xfffe, 0x30);
	xc9080_write_register(vi_pipe, 0x2100, 0x04); // l_noise_list0
	xc9080_write_register(vi_pipe, 0x2101, 0x0a);
	xc9080_write_register(vi_pipe, 0x2102, 0x10);
	xc9080_write_register(vi_pipe, 0x2103, 0x18);
	xc9080_write_register(vi_pipe, 0x2104, 0x28);
	xc9080_write_register(vi_pipe, 0x2105, 0x48); // l_noise_list5
	xc9080_write_register(vi_pipe, 0x2106, 0x5f); // bit[7]l_noise_man_en; bit[6]l_sdw_ext_en; bit[4:0]l_sdw_ext_ns
	xc9080_write_register(vi_pipe, 0x2107, 0x08); // l_noise_man

	// CIP
	xc9080_write_register(vi_pipe, 0xfffe, 0x30);
	xc9080_write_register(vi_pipe, 0x0f00, 0xff); // bit[7:4] noise_y_slp  bit[3:0] Lsharp
	xc9080_write_register(vi_pipe, 0x0f02, 0x00); // noise_list_0
	xc9080_write_register(vi_pipe, 0x0f03, 0x00);
	xc9080_write_register(vi_pipe, 0x0f04, 0x00);
	xc9080_write_register(vi_pipe, 0x0f05, 0x00);
	xc9080_write_register(vi_pipe, 0x0f06, 0x00);
	xc9080_write_register(vi_pipe, 0x0f07, 0x00);
	xc9080_write_register(vi_pipe, 0x0f08, 0x00);
	xc9080_write_register(vi_pipe, 0x0f09, 0x00); // noise_list_7
	xc9080_write_register(vi_pipe, 0x0f0a, 0x00); // min_shp       //30
	xc9080_write_register(vi_pipe, 0x0f0b, 0x08); // max_shp       //38
	xc9080_write_register(vi_pipe, 0x0f0c, 0x01); // min_detail    //0b
	xc9080_write_register(vi_pipe, 0x0f0d, 0x03); // max_detail    //0d
	xc9080_write_register(vi_pipe, 0x0f0e, 0x0f); // min_shp_gain  //10
	xc9080_write_register(vi_pipe, 0x0f0f, 0x3f); // max_shp_gain  //40

	////////////////////////////////////////////
	// isp1
	xc9080_write_register(vi_pipe, 0xfffe, 0x31);
	xc9080_write_register(vi_pipe, 0x0013, 0x40); // blc
	xc9080_write_register(vi_pipe, 0x071b, 0xff);

	// gamma
	xc9080_write_register(vi_pipe, 0xfffe, 0x31);
	xc9080_write_register(vi_pipe, 0x1400, 0x00);
	xc9080_write_register(vi_pipe, 0x1401, 0x05);
	xc9080_write_register(vi_pipe, 0x1402, 0x0a);
	xc9080_write_register(vi_pipe, 0x1403, 0x0f);
	xc9080_write_register(vi_pipe, 0x1404, 0x15);
	xc9080_write_register(vi_pipe, 0x1405, 0x1a);
	xc9080_write_register(vi_pipe, 0x1406, 0x1f);
	xc9080_write_register(vi_pipe, 0x1407, 0x24);
	xc9080_write_register(vi_pipe, 0x1408, 0x29);
	xc9080_write_register(vi_pipe, 0x1409, 0x2e);
	xc9080_write_register(vi_pipe, 0x140a, 0x32);
	xc9080_write_register(vi_pipe, 0x140b, 0x37);
	xc9080_write_register(vi_pipe, 0x140c, 0x3c);
	xc9080_write_register(vi_pipe, 0x140d, 0x40);
	xc9080_write_register(vi_pipe, 0x140e, 0x45);
	xc9080_write_register(vi_pipe, 0x140f, 0x49);
	xc9080_write_register(vi_pipe, 0x1410, 0x4e);
	xc9080_write_register(vi_pipe, 0x1411, 0x52);
	xc9080_write_register(vi_pipe, 0x1412, 0x56);
	xc9080_write_register(vi_pipe, 0x1413, 0x5a);
	xc9080_write_register(vi_pipe, 0x1414, 0x5e);
	xc9080_write_register(vi_pipe, 0x1415, 0x62);
	xc9080_write_register(vi_pipe, 0x1416, 0x65);
	xc9080_write_register(vi_pipe, 0x1417, 0x69);
	xc9080_write_register(vi_pipe, 0x1418, 0x6c);
	xc9080_write_register(vi_pipe, 0x1419, 0x6f);
	xc9080_write_register(vi_pipe, 0x141a, 0x73);
	xc9080_write_register(vi_pipe, 0x141b, 0x76);
	xc9080_write_register(vi_pipe, 0x141c, 0x79);
	xc9080_write_register(vi_pipe, 0x141d, 0x7c);
	xc9080_write_register(vi_pipe, 0x141e, 0x7e);
	xc9080_write_register(vi_pipe, 0x141f, 0x81);
	xc9080_write_register(vi_pipe, 0x1420, 0x84);
	xc9080_write_register(vi_pipe, 0x1421, 0x89);
	xc9080_write_register(vi_pipe, 0x1422, 0x8d);
	xc9080_write_register(vi_pipe, 0x1423, 0x92);
	xc9080_write_register(vi_pipe, 0x1424, 0x96);
	xc9080_write_register(vi_pipe, 0x1425, 0x9a);
	xc9080_write_register(vi_pipe, 0x1426, 0x9d);
	xc9080_write_register(vi_pipe, 0x1427, 0xa1);
	xc9080_write_register(vi_pipe, 0x1428, 0xa4);
	xc9080_write_register(vi_pipe, 0x1429, 0xa7);
	xc9080_write_register(vi_pipe, 0x142a, 0xaa);
	xc9080_write_register(vi_pipe, 0x142b, 0xad);
	xc9080_write_register(vi_pipe, 0x142c, 0xaf);
	xc9080_write_register(vi_pipe, 0x142d, 0xb2);
	xc9080_write_register(vi_pipe, 0x142e, 0xb4);
	xc9080_write_register(vi_pipe, 0x142f, 0xb6);
	xc9080_write_register(vi_pipe, 0x1430, 0xb8);
	xc9080_write_register(vi_pipe, 0x1431, 0xbc);
	xc9080_write_register(vi_pipe, 0x1432, 0xc0);
	xc9080_write_register(vi_pipe, 0x1433, 0xc4);
	xc9080_write_register(vi_pipe, 0x1434, 0xc8);
	xc9080_write_register(vi_pipe, 0x1435, 0xcc);
	xc9080_write_register(vi_pipe, 0x1436, 0xd0);
	xc9080_write_register(vi_pipe, 0x1437, 0xd4);
	xc9080_write_register(vi_pipe, 0x1438, 0xd8);
	xc9080_write_register(vi_pipe, 0x1439, 0xdd);
	xc9080_write_register(vi_pipe, 0x143a, 0xe1);
	xc9080_write_register(vi_pipe, 0x143b, 0xe6);
	xc9080_write_register(vi_pipe, 0x143c, 0xeb);
	xc9080_write_register(vi_pipe, 0x143d, 0xf0);
	xc9080_write_register(vi_pipe, 0x143e, 0xf5);
	xc9080_write_register(vi_pipe, 0x143f, 0xfa);
	xc9080_write_register(vi_pipe, 0x1440, 0xff);

	// advance_raw_dns     20170623
	xc9080_write_register(vi_pipe, 0xfffe, 0x31);

	xc9080_write_register(vi_pipe, 0x2000, 0x14); // s0_sigma_0
	xc9080_write_register(vi_pipe, 0x2001, 0x18);
	xc9080_write_register(vi_pipe, 0x2002, 0x1d);
	xc9080_write_register(vi_pipe, 0x2003, 0x20);
	xc9080_write_register(vi_pipe, 0x2004, 0x28);
	xc9080_write_register(vi_pipe, 0x2005, 0x30); // s0_sigma_5

	xc9080_write_register(vi_pipe, 0x2006, 0x18); // s0_Gsl_0
	xc9080_write_register(vi_pipe, 0x2007, 0x14);
	xc9080_write_register(vi_pipe, 0x2008, 0x10);
	xc9080_write_register(vi_pipe, 0x2009, 0x0a);
	xc9080_write_register(vi_pipe, 0x200a, 0x04);
	xc9080_write_register(vi_pipe, 0x200b, 0x01); // s0_Gsl_5

	xc9080_write_register(vi_pipe, 0x200c, 0x1a); // s0_RBsl_0
	xc9080_write_register(vi_pipe, 0x200d, 0x18);
	xc9080_write_register(vi_pipe, 0x200e, 0x16);
	xc9080_write_register(vi_pipe, 0x200f, 0x10);
	xc9080_write_register(vi_pipe, 0x2010, 0x08);
	xc9080_write_register(vi_pipe, 0x2011, 0x04); // s0_RBsl_5

	xc9080_write_register(vi_pipe, 0x2012, 0x24); // s0_ps00    //sigma_scale 大
	xc9080_write_register(vi_pipe, 0x2013, 0x24);
	xc9080_write_register(vi_pipe, 0x2014, 0x28);
	xc9080_write_register(vi_pipe, 0x2015, 0x30);
	xc9080_write_register(vi_pipe, 0x2016, 0x38);
	xc9080_write_register(vi_pipe, 0x2017, 0x40); // s0_ps05

	xc9080_write_register(vi_pipe, 0x2018, 0x20); // s0_ps10
	xc9080_write_register(vi_pipe, 0x2019, 0x20);
	xc9080_write_register(vi_pipe, 0x201a, 0x24);
	xc9080_write_register(vi_pipe, 0x201b, 0x28);
	xc9080_write_register(vi_pipe, 0x201c, 0x30);
	xc9080_write_register(vi_pipe, 0x201d, 0x38); // s0_ps15

	xc9080_write_register(vi_pipe, 0x201e, 0x18); // s0_ps20
	xc9080_write_register(vi_pipe, 0x201f, 0x1d);
	xc9080_write_register(vi_pipe, 0x2020, 0x20);
	xc9080_write_register(vi_pipe, 0x2021, 0x24);
	xc9080_write_register(vi_pipe, 0x2022, 0x28);
	xc9080_write_register(vi_pipe, 0x2023, 0x30); // s0_ps25

	xc9080_write_register(vi_pipe, 0x2024, 0x10); // s0_ps30
	xc9080_write_register(vi_pipe, 0x2025, 0x12);
	xc9080_write_register(vi_pipe, 0x2026, 0x18);
	xc9080_write_register(vi_pipe, 0x2027, 0x1d);
	xc9080_write_register(vi_pipe, 0x2028, 0x20);
	xc9080_write_register(vi_pipe, 0x2029, 0x28); // s0_ps35

	xc9080_write_register(vi_pipe, 0x202a, 0x28); // s0_pl00     //h2_scale 小
	xc9080_write_register(vi_pipe, 0x202b, 0x20);
	xc9080_write_register(vi_pipe, 0x202c, 0x16);
	xc9080_write_register(vi_pipe, 0x202d, 0x10);
	xc9080_write_register(vi_pipe, 0x202e, 0x0c);
	xc9080_write_register(vi_pipe, 0x202f, 0x08); // s0_pl05

	xc9080_write_register(vi_pipe, 0x2030, 0x30); // s0_pl10
	xc9080_write_register(vi_pipe, 0x2031, 0x28);
	xc9080_write_register(vi_pipe, 0x2032, 0x24);
	xc9080_write_register(vi_pipe, 0x2033, 0x20);
	xc9080_write_register(vi_pipe, 0x2034, 0x1a);
	xc9080_write_register(vi_pipe, 0x2035, 0x16); // s0_pl15

	xc9080_write_register(vi_pipe, 0x2036, 0x38); // s0_pl20
	xc9080_write_register(vi_pipe, 0x2037, 0x30);
	xc9080_write_register(vi_pipe, 0x2038, 0x28);
	xc9080_write_register(vi_pipe, 0x2039, 0x24);
	xc9080_write_register(vi_pipe, 0x203a, 0x20);
	xc9080_write_register(vi_pipe, 0x203b, 0x1a); // s0_pl25

	xc9080_write_register(vi_pipe, 0x203c, 0x3a); // s0_pl30
	xc9080_write_register(vi_pipe, 0x203d, 0x32);
	xc9080_write_register(vi_pipe, 0x203e, 0x2d);
	xc9080_write_register(vi_pipe, 0x203f, 0x28);
	xc9080_write_register(vi_pipe, 0x2040, 0x24);
	xc9080_write_register(vi_pipe, 0x2041, 0x20); // s0_pl35

	xc9080_write_register(vi_pipe, 0x2044, 0x10); // bit[4:0]thre_y

	// UV DNS
	xc9080_write_register(vi_pipe, 0xfffe, 0x31);
	xc9080_write_register(vi_pipe, 0x2100, 0x04); // l_noise_list0
	xc9080_write_register(vi_pipe, 0x2101, 0x0a);
	xc9080_write_register(vi_pipe, 0x2102, 0x10);
	xc9080_write_register(vi_pipe, 0x2103, 0x18);
	xc9080_write_register(vi_pipe, 0x2104, 0x28);
	xc9080_write_register(vi_pipe, 0x2105, 0x48); // l_noise_list5
	xc9080_write_register(vi_pipe, 0x2106, 0x5f); // bit[7]l_noise_man_en; bit[6]l_sdw_ext_en; bit[4:0]l_sdw_ext_ns
	xc9080_write_register(vi_pipe, 0x2107, 0x08); // l_noise_man

	// CIP
	xc9080_write_register(vi_pipe, 0xfffe, 0x31);
	xc9080_write_register(vi_pipe, 0x0f00, 0xff); // bit[7:4] noise_y_slp  bit[3:0] Lsharp
	xc9080_write_register(vi_pipe, 0x0f02, 0x00); // noise_list_0
	xc9080_write_register(vi_pipe, 0x0f03, 0x00);
	xc9080_write_register(vi_pipe, 0x0f04, 0x00);
	xc9080_write_register(vi_pipe, 0x0f05, 0x00);
	xc9080_write_register(vi_pipe, 0x0f06, 0x00);
	xc9080_write_register(vi_pipe, 0x0f07, 0x00);
	xc9080_write_register(vi_pipe, 0x0f08, 0x00);
	xc9080_write_register(vi_pipe, 0x0f09, 0x00); // noise_list_7
	xc9080_write_register(vi_pipe, 0x0f0a, 0x00); // min_shp       //30
	xc9080_write_register(vi_pipe, 0x0f0b, 0x08); // max_shp       //38
	xc9080_write_register(vi_pipe, 0x0f0c, 0x01); // min_detail    //0b
	xc9080_write_register(vi_pipe, 0x0f0d, 0x03); // max_detail    //0d
	xc9080_write_register(vi_pipe, 0x0f0e, 0x0f); // min_shp_gain  //10
	xc9080_write_register(vi_pipe, 0x0f0f, 0x3f); // max_shp_gain  //40
	xc9080_write_register(vi_pipe, 0xfffe, 0x25);
	xc9080_write_register(vi_pipe, 0x0002, 0x44);
	xc9080_write_register(vi_pipe, 0x1002, 0x44);

	// ISP0  TOP
	xc9080_write_register(vi_pipe, 0xfffe, 0x30); // isp0
	xc9080_write_register(vi_pipe, 0x0000, 0x47); // 57
	xc9080_write_register(vi_pipe, 0x0001, 0x80); // 92
	xc9080_write_register(vi_pipe, 0x0002, 0x10); // 96---90
	xc9080_write_register(vi_pipe, 0x0003, 0x31); // 35----31
	xc9080_write_register(vi_pipe, 0x0004, 0x10);

	xc9080_write_register(vi_pipe, 0x0019, 0x8b);
	xc9080_write_register(vi_pipe, 0x071c, 0x0a);

	xc9080_write_register(vi_pipe, 0x1700, 0x81);
	xc9080_write_register(vi_pipe, 0x1701, 0x40);
	xc9080_write_register(vi_pipe, 0x1702, 0x40);
	xc9080_write_register(vi_pipe, 0x1704, 0x1d);

	// ISP0  TOP
	xc9080_write_register(vi_pipe, 0xfffe, 0x31); // isp0
	xc9080_write_register(vi_pipe, 0x0000, 0x47); // 57
	xc9080_write_register(vi_pipe, 0x0001, 0x80); // 92
	xc9080_write_register(vi_pipe, 0x0002, 0x10); // 96---90
	xc9080_write_register(vi_pipe, 0x0003, 0x31); // 35----31
	xc9080_write_register(vi_pipe, 0x0004, 0x10);

	xc9080_write_register(vi_pipe, 0x0019, 0x8b);
	xc9080_write_register(vi_pipe, 0x071c, 0x0a);

	xc9080_write_register(vi_pipe, 0x1700, 0x81);
	xc9080_write_register(vi_pipe, 0x1701, 0x40);
	xc9080_write_register(vi_pipe, 0x1702, 0x40);
	xc9080_write_register(vi_pipe, 0x1704, 0x1d);

	xc9080_write_register(vi_pipe, 0xfffe, 0x30);
	xc9080_write_register(vi_pipe, 0x006c, 0xa0);
	xc9080_write_register(vi_pipe, 0xfffe, 0x31);
	xc9080_write_register(vi_pipe, 0x006c, 0xa0);
#endif

#if 1
	xc9080_write_register(vi_pipe, 0xfffd, 0x80);
xc9080_write_register(vi_pipe, 0xfffe, 0x50);
xc9080_write_register(vi_pipe, 0x001c, 0xff);
xc9080_write_register(vi_pipe, 0x001d, 0xff);
xc9080_write_register(vi_pipe, 0x001e, 0xff);
xc9080_write_register(vi_pipe, 0x001f, 0xff);
xc9080_write_register(vi_pipe, 0x0018, 0x00);
xc9080_write_register(vi_pipe, 0x0019, 0x00);
xc9080_write_register(vi_pipe, 0x001a, 0x00);
xc9080_write_register(vi_pipe, 0x001b, 0x00);
xc9080_write_register(vi_pipe, 0x00bc, 0x19);
xc9080_write_register(vi_pipe, 0x0030, 0x44);
xc9080_write_register(vi_pipe, 0x0031, 0x88);
xc9080_write_register(vi_pipe, 0x0032, 0x34);
xc9080_write_register(vi_pipe, 0x0033, 0x70);
            
xc9080_write_register(vi_pipe, 0x0020, 0x02);
xc9080_write_register(vi_pipe, 0x0021, 0x0d);
xc9080_write_register(vi_pipe, 0x0022, 0x01);
xc9080_write_register(vi_pipe, 0x0023, 0x85);
xc9080_write_register(vi_pipe, 0x0024, 0x06);
xc9080_write_register(vi_pipe, 0x0025, 0x00);
xc9080_write_register(vi_pipe, 0x0026, 0x01);
xc9080_write_register(vi_pipe, 0x0027, 0x06);
xc9080_write_register(vi_pipe, 0x0028, 0x01);
xc9080_write_register(vi_pipe, 0x0029, 0x00);
xc9080_write_register(vi_pipe, 0x002a, 0x01);
xc9080_write_register(vi_pipe, 0x002b, 0x06);
xc9080_write_register(vi_pipe, 0x002e, 0x05);


xc9080_write_register(vi_pipe, 0xfffe, 0x50);
xc9080_write_register(vi_pipe, 0x0050, 0x0f);
xc9080_write_register(vi_pipe, 0x0054, 0x0f);
xc9080_write_register(vi_pipe, 0x0058, 0x00);
xc9080_write_register(vi_pipe, 0x0058, 0x0f);
xc9080_write_register(vi_pipe, 0x00bc, 0x19);
xc9080_write_register(vi_pipe, 0x0090, 0x38);	//0x38
xc9080_write_register(vi_pipe, 0x00a8, 0x09);	//0x09

xc9080_write_register(vi_pipe, 0x0200, 0x0f);
xc9080_write_register(vi_pipe, 0x0201, 0x00);
xc9080_write_register(vi_pipe, 0x0202, 0x80);
xc9080_write_register(vi_pipe, 0x0203, 0x00);
xc9080_write_register(vi_pipe, 0x0214, 0x0f);
xc9080_write_register(vi_pipe, 0x0215, 0x00);
xc9080_write_register(vi_pipe, 0x0216, 0x80);
xc9080_write_register(vi_pipe, 0x0217, 0x00);

xc9080_write_register(vi_pipe, 0xfffe, 0x26);
xc9080_write_register(vi_pipe, 0x8001, 0x80);
xc9080_write_register(vi_pipe, 0x8002, 0x02);
xc9080_write_register(vi_pipe, 0x8003, 0xe0);
xc9080_write_register(vi_pipe, 0x8004, 0x01);
xc9080_write_register(vi_pipe, 0x8005, 0x40);
xc9080_write_register(vi_pipe, 0x8006, 0x40);
xc9080_write_register(vi_pipe, 0x8007, 0x10);
xc9080_write_register(vi_pipe, 0x8008, 0xf0);
xc9080_write_register(vi_pipe, 0x800b, 0xff);
xc9080_write_register(vi_pipe, 0x8000, 0x1d);
xc9080_write_register(vi_pipe, 0x8041, 0x80);
xc9080_write_register(vi_pipe, 0x8042, 0x02);
xc9080_write_register(vi_pipe, 0x8043, 0xe0);
xc9080_write_register(vi_pipe, 0x8044, 0x01);
xc9080_write_register(vi_pipe, 0x8045, 0x40);
xc9080_write_register(vi_pipe, 0x8046, 0x40);
xc9080_write_register(vi_pipe, 0x8047, 0x10);
xc9080_write_register(vi_pipe, 0x8048, 0xf0);
xc9080_write_register(vi_pipe, 0x804b, 0xff);
xc9080_write_register(vi_pipe, 0x8040, 0x1d);

xc9080_write_register(vi_pipe, 0x8010, 0x01);
xc9080_write_register(vi_pipe, 0x8012, 0x80);
xc9080_write_register(vi_pipe, 0x8013, 0x02);
xc9080_write_register(vi_pipe, 0x8014, 0xe0);
xc9080_write_register(vi_pipe, 0x8015, 0x01);
xc9080_write_register(vi_pipe, 0x8016, 0x00);
xc9080_write_register(vi_pipe, 0x8017, 0x00);
xc9080_write_register(vi_pipe, 0x8018, 0x00);
xc9080_write_register(vi_pipe, 0x8019, 0x00);
xc9080_write_register(vi_pipe, 0x8050, 0x01);
xc9080_write_register(vi_pipe, 0x8052, 0x80);
xc9080_write_register(vi_pipe, 0x8053, 0x02);
xc9080_write_register(vi_pipe, 0x8054, 0xe0);
xc9080_write_register(vi_pipe, 0x8055, 0x01);
xc9080_write_register(vi_pipe, 0x8056, 0x00);
xc9080_write_register(vi_pipe, 0x8057, 0x00);
xc9080_write_register(vi_pipe, 0x8058, 0x00);
xc9080_write_register(vi_pipe, 0x8059, 0x00);

xc9080_write_register(vi_pipe, 0xfffe, 0x2e);
xc9080_write_register(vi_pipe, 0x0026, 0xc0);
xc9080_write_register(vi_pipe, 0x0100, 0x00);
xc9080_write_register(vi_pipe, 0x0101, 0x00);
xc9080_write_register(vi_pipe, 0x0102, 0x00);
xc9080_write_register(vi_pipe, 0x0103, 0x00);
xc9080_write_register(vi_pipe, 0x0104, 0x02);
xc9080_write_register(vi_pipe, 0x0105, 0x80);
xc9080_write_register(vi_pipe, 0x0106, 0x01);
xc9080_write_register(vi_pipe, 0x0107, 0xe0);
xc9080_write_register(vi_pipe, 0x0108, 0x01);
xc9080_write_register(vi_pipe, 0x0200, 0x00);
xc9080_write_register(vi_pipe, 0x0201, 0x00);
xc9080_write_register(vi_pipe, 0x0202, 0x00);
xc9080_write_register(vi_pipe, 0x0203, 0x00);
xc9080_write_register(vi_pipe, 0x0204, 0x02);
xc9080_write_register(vi_pipe, 0x0205, 0x80);
xc9080_write_register(vi_pipe, 0x0206, 0x01);
xc9080_write_register(vi_pipe, 0x0207, 0xe0);
xc9080_write_register(vi_pipe, 0x0208, 0x01);

xc9080_write_register(vi_pipe, 0xfffe, 0x30);
xc9080_write_register(vi_pipe, 0x0019, 0x08);
xc9080_write_register(vi_pipe, 0x0050, 0x20);
xc9080_write_register(vi_pipe, 0x005e, 0x7f);
xc9080_write_register(vi_pipe, 0x005f, 0x02);
xc9080_write_register(vi_pipe, 0x0060, 0xdf);
xc9080_write_register(vi_pipe, 0x0061, 0x01);
xc9080_write_register(vi_pipe, 0x0064, 0x80);
xc9080_write_register(vi_pipe, 0x0065, 0x02);
xc9080_write_register(vi_pipe, 0x0066, 0xe0);
xc9080_write_register(vi_pipe, 0x0067, 0x01);
xc9080_write_register(vi_pipe, 0x0006, 0x02);
xc9080_write_register(vi_pipe, 0x0007, 0x80);
xc9080_write_register(vi_pipe, 0x0008, 0x01);
xc9080_write_register(vi_pipe, 0x0009, 0xe0);
xc9080_write_register(vi_pipe, 0x000a, 0x02);
xc9080_write_register(vi_pipe, 0x000b, 0x80);
xc9080_write_register(vi_pipe, 0x000c, 0x01);
xc9080_write_register(vi_pipe, 0x000d, 0xe0);
xc9080_write_register(vi_pipe, 0xfffe, 0x31);
xc9080_write_register(vi_pipe, 0x0019, 0x08);
xc9080_write_register(vi_pipe, 0x0050, 0x20);
xc9080_write_register(vi_pipe, 0x005e, 0x7f);
xc9080_write_register(vi_pipe, 0x005f, 0x02);
xc9080_write_register(vi_pipe, 0x0060, 0xdf);
xc9080_write_register(vi_pipe, 0x0061, 0x01);
xc9080_write_register(vi_pipe, 0x0064, 0x80);
xc9080_write_register(vi_pipe, 0x0065, 0x02);
xc9080_write_register(vi_pipe, 0x0066, 0xe0);
xc9080_write_register(vi_pipe, 0x0067, 0x01);
xc9080_write_register(vi_pipe, 0x0006, 0x02);
xc9080_write_register(vi_pipe, 0x0007, 0x80);
xc9080_write_register(vi_pipe, 0x0008, 0x01);
xc9080_write_register(vi_pipe, 0x0009, 0xe0);
xc9080_write_register(vi_pipe, 0x000a, 0x02);
xc9080_write_register(vi_pipe, 0x000b, 0x80);
xc9080_write_register(vi_pipe, 0x000c, 0x01);
xc9080_write_register(vi_pipe, 0x000d, 0xe0);
xc9080_write_register(vi_pipe, 0xfffe, 0x26);
xc9080_write_register(vi_pipe, 0x0000, 0x00);
xc9080_write_register(vi_pipe, 0x0009, 0xc4);
xc9080_write_register(vi_pipe, 0x1000, 0x00);
xc9080_write_register(vi_pipe, 0x1009, 0xc4);
xc9080_write_register(vi_pipe, 0x2019, 0x05);
xc9080_write_register(vi_pipe, 0x201a, 0x00);
xc9080_write_register(vi_pipe, 0x201b, 0x01);
xc9080_write_register(vi_pipe, 0x201c, 0xe0);
xc9080_write_register(vi_pipe, 0x201d, 0x05);
xc9080_write_register(vi_pipe, 0x201e, 0x00);
xc9080_write_register(vi_pipe, 0x201f, 0x01);
xc9080_write_register(vi_pipe, 0x2020, 0xe0);
xc9080_write_register(vi_pipe, 0x2015, 0x80);
xc9080_write_register(vi_pipe, 0x2017, 0x1e);
xc9080_write_register(vi_pipe, 0x2018, 0x1e);
xc9080_write_register(vi_pipe, 0x2023, 0x03);
xc9080_write_register(vi_pipe, 0xfffe, 0x2c);
xc9080_write_register(vi_pipe, 0x0000, 0x00);
xc9080_write_register(vi_pipe, 0x0001, 0x05);
xc9080_write_register(vi_pipe, 0x0002, 0x00);
xc9080_write_register(vi_pipe, 0x0004, 0x02);
xc9080_write_register(vi_pipe, 0x0005, 0x80);
xc9080_write_register(vi_pipe, 0x0008, 0x10);
xc9080_write_register(vi_pipe, 0x0044, 0x08);
xc9080_write_register(vi_pipe, 0x0045, 0x04);
xc9080_write_register(vi_pipe, 0x0048, 0x09);
xc9080_write_register(vi_pipe, 0x0049, 0xf0);
xc9080_write_register(vi_pipe, 0x0084, 0x08);
xc9080_write_register(vi_pipe, 0x0085, 0x04);
xc9080_write_register(vi_pipe, 0x0088, 0x09);
xc9080_write_register(vi_pipe, 0x0089, 0xf0);
xc9080_write_register(vi_pipe, 0xfffe, 0x2e);
xc9080_write_register(vi_pipe, 0x0000, 0x42);
xc9080_write_register(vi_pipe, 0x0001, 0xee);
xc9080_write_register(vi_pipe, 0x0003, 0x01);
xc9080_write_register(vi_pipe, 0x0004, 0xa0);
xc9080_write_register(vi_pipe, 0x0006, 0x01);
xc9080_write_register(vi_pipe, 0x0007, 0xa0);
xc9080_write_register(vi_pipe, 0x000a, 0x13);
xc9080_write_register(vi_pipe, 0x000b, 0x04);
xc9080_write_register(vi_pipe, 0x000c, 0x80);
xc9080_write_register(vi_pipe, 0x000d, 0x02);
xc9080_write_register(vi_pipe, 0x1000, 0x0a);
xc9080_write_register(vi_pipe, 0x1001, 0x00);
xc9080_write_register(vi_pipe, 0x1002, 0x05);
xc9080_write_register(vi_pipe, 0x1003, 0x80);
xc9080_write_register(vi_pipe, 0x1004, 0x02);
xc9080_write_register(vi_pipe, 0x1005, 0x00);
xc9080_write_register(vi_pipe, 0x1006, 0x05);
xc9080_write_register(vi_pipe, 0x1007, 0x80);
xc9080_write_register(vi_pipe, 0x1008, 0x02);
xc9080_write_register(vi_pipe, 0x1009, 0x00);
xc9080_write_register(vi_pipe, 0x100a, 0x05);
xc9080_write_register(vi_pipe, 0x100b, 0x00);
xc9080_write_register(vi_pipe, 0x100e, 0x00);
xc9080_write_register(vi_pipe, 0x100f, 0x01);
xc9080_write_register(vi_pipe, 0xfffe, 0x26);
xc9080_write_register(vi_pipe, 0x200b, 0x25);
xc9080_write_register(vi_pipe, 0x200c, 0x04);

xc9080_write_register(vi_pipe, 0xfffe, 0x30);
xc9080_write_register(vi_pipe, 0x0004, 0x10);
xc9080_write_register(vi_pipe, 0xfffe, 0x31);
xc9080_write_register(vi_pipe, 0x0004, 0x10);

//isp0 ae
xc9080_write_register(vi_pipe, 0xfffe, 0x30);
xc9080_write_register(vi_pipe, 0x1f00, 0x00);
xc9080_write_register(vi_pipe, 0x1f01, 0x00);
xc9080_write_register(vi_pipe, 0x1f02, 0x00);
xc9080_write_register(vi_pipe, 0x1f03, 0x00);
xc9080_write_register(vi_pipe, 0x1f04, 0x02);
xc9080_write_register(vi_pipe, 0x1f05, 0x80);
xc9080_write_register(vi_pipe, 0x1f06, 0x01);
xc9080_write_register(vi_pipe, 0x1f07, 0xe0);
xc9080_write_register(vi_pipe, 0x1f08, 0x03);
xc9080_write_register(vi_pipe, 0x0051, 0x03);

xc9080_write_register(vi_pipe, 0xfffe, 0x14); 


xc9080_write_register(vi_pipe, 0x0020, 0x03);  //isp1 copy from isp0

xc9080_write_register(vi_pipe, 0xfffe, 0x14);
xc9080_write_register(vi_pipe, 0x000e, 0x00);
xc9080_write_register(vi_pipe, 0x010e, 0xc0);
xc9080_write_register(vi_pipe, 0x010f, 0x01);
xc9080_write_register(vi_pipe, 0x0110, 0x00);
xc9080_write_register(vi_pipe, 0x0111, 0x00);
xc9080_write_register(vi_pipe, 0x0114, 0x00);
xc9080_write_register(vi_pipe, 0x0115, 0x00);
xc9080_write_register(vi_pipe, 0x0116, 0x35);
xc9080_write_register(vi_pipe, 0x0117, 0x01);
xc9080_write_register(vi_pipe, 0x0118, 0x35);
xc9080_write_register(vi_pipe, 0x0119, 0x02);
xc9080_write_register(vi_pipe, 0x011c, 0x00);
xc9080_write_register(vi_pipe, 0x011d, 0x00);
xc9080_write_register(vi_pipe, 0x011e, 0x00);
xc9080_write_register(vi_pipe, 0x011f, 0xff);
xc9080_write_register(vi_pipe, 0x0120, 0x00);
xc9080_write_register(vi_pipe, 0x0121, 0xff);
xc9080_write_register(vi_pipe, 0x0134, 0x00);
xc9080_write_register(vi_pipe, 0x0135, 0x00);
xc9080_write_register(vi_pipe, 0x0136, 0x35);
xc9080_write_register(vi_pipe, 0x0137, 0x0b);
xc9080_write_register(vi_pipe, 0x013c, 0x00);
xc9080_write_register(vi_pipe, 0x013d, 0x00);
xc9080_write_register(vi_pipe, 0x013e, 0x00);
xc9080_write_register(vi_pipe, 0x013f, 0xff);
xc9080_write_register(vi_pipe, 0xfffe, 0x14);
xc9080_write_register(vi_pipe, 0x004c, 0x00);
xc9080_write_register(vi_pipe, 0x002b, 0x01);
xc9080_write_register(vi_pipe, 0x004d, 0x01);
xc9080_write_register(vi_pipe, 0x00fa, 0x00);
xc9080_write_register(vi_pipe, 0x00fb, 0x60);
xc9080_write_register(vi_pipe, 0x00fc, 0x00);
xc9080_write_register(vi_pipe, 0x00fd, 0x20);
xc9080_write_register(vi_pipe, 0x00e2, 0x24);
xc9080_write_register(vi_pipe, 0x00e3, 0x00);
xc9080_write_register(vi_pipe, 0x00de, 0x00);
xc9080_write_register(vi_pipe, 0x00df, 0x10);
xc9080_write_register(vi_pipe, 0x00a0, 0x00);
xc9080_write_register(vi_pipe, 0x00a1, 0x90);
xc9080_write_register(vi_pipe, 0x0104, 0x00);
xc9080_write_register(vi_pipe, 0x0105, 0x01);
xc9080_write_register(vi_pipe, 0x0108, 0x15);
xc9080_write_register(vi_pipe, 0x0109, 0xa0);
xc9080_write_register(vi_pipe, 0x0055, 0x04);
xc9080_write_register(vi_pipe, 0x0056, 0x04);
xc9080_write_register(vi_pipe, 0x0057, 0x04);
xc9080_write_register(vi_pipe, 0x0058, 0x04);
xc9080_write_register(vi_pipe, 0x0059, 0x04);
xc9080_write_register(vi_pipe, 0x005a, 0x04);
xc9080_write_register(vi_pipe, 0x005b, 0x04);
xc9080_write_register(vi_pipe, 0x005c, 0x04);
xc9080_write_register(vi_pipe, 0x005d, 0x04);
xc9080_write_register(vi_pipe, 0x005e, 0x04);
xc9080_write_register(vi_pipe, 0x005f, 0x04);
xc9080_write_register(vi_pipe, 0x0060, 0x04);
xc9080_write_register(vi_pipe, 0x0061, 0x04);
xc9080_write_register(vi_pipe, 0x0062, 0x04);
xc9080_write_register(vi_pipe, 0x0063, 0x04);
xc9080_write_register(vi_pipe, 0x0064, 0x04);
xc9080_write_register(vi_pipe, 0x0065, 0x04);
xc9080_write_register(vi_pipe, 0x0066, 0x04);
xc9080_write_register(vi_pipe, 0x0067, 0x04);
xc9080_write_register(vi_pipe, 0x0068, 0x04);
xc9080_write_register(vi_pipe, 0x0069, 0x04);
xc9080_write_register(vi_pipe, 0x006a, 0x04);
xc9080_write_register(vi_pipe, 0x006b, 0x04);
xc9080_write_register(vi_pipe, 0x006c, 0x04);
xc9080_write_register(vi_pipe, 0x006d, 0x04);
xc9080_write_register(vi_pipe, 0x0088, 0x00);
xc9080_write_register(vi_pipe, 0x0089, 0x00);
xc9080_write_register(vi_pipe, 0x008a, 0x00);
xc9080_write_register(vi_pipe, 0x008b, 0x00);
xc9080_write_register(vi_pipe, 0x0050, 0x01);
xc9080_write_register(vi_pipe, 0x00ca, 0x00);
xc9080_write_register(vi_pipe, 0x00cb, 0x80);
xc9080_write_register(vi_pipe, 0x01bc, 0x00);
xc9080_write_register(vi_pipe, 0x01bd, 0xa0);
xc9080_write_register(vi_pipe, 0x01be, 0x00);
xc9080_write_register(vi_pipe, 0x01bf, 0x60);
xc9080_write_register(vi_pipe, 0x00cc, 0x00);
xc9080_write_register(vi_pipe, 0x00cd, 0x50);
xc9080_write_register(vi_pipe, 0x00c7, 0x20);
xc9080_write_register(vi_pipe, 0x00d8, 0x80);
xc9080_write_register(vi_pipe, 0x00c8, 0x01);
xc9080_write_register(vi_pipe, 0x0208, 0x02);
xc9080_write_register(vi_pipe, 0x00da, 0x00);
xc9080_write_register(vi_pipe, 0x00db, 0xa0);
xc9080_write_register(vi_pipe, 0x00dc, 0x03);
xc9080_write_register(vi_pipe, 0x00dd, 0x00);
xc9080_write_register(vi_pipe, 0x0092, 0x00);
xc9080_write_register(vi_pipe, 0x0093, 0x07);
xc9080_write_register(vi_pipe, 0x0094, 0x00);
xc9080_write_register(vi_pipe, 0x00ad, 0x02);
xc9080_write_register(vi_pipe, 0x0022, 0x1e);
xc9080_write_register(vi_pipe, 0x01e4, 0x00);
xc9080_write_register(vi_pipe, 0x01e5, 0x00);
xc9080_write_register(vi_pipe, 0x01e6, 0x04);
xc9080_write_register(vi_pipe, 0x01e7, 0x00);
xc9080_write_register(vi_pipe, 0x01e8, 0x00);
xc9080_write_register(vi_pipe, 0x01e9, 0x00);
xc9080_write_register(vi_pipe, 0x01ea, 0x0c);
xc9080_write_register(vi_pipe, 0x01eb, 0x00);
xc9080_write_register(vi_pipe, 0x01ec, 0x00);
xc9080_write_register(vi_pipe, 0x01ed, 0x00);
xc9080_write_register(vi_pipe, 0x01ee, 0x24);
xc9080_write_register(vi_pipe, 0x01ef, 0x00);
xc9080_write_register(vi_pipe, 0x01f0, 0x00);
xc9080_write_register(vi_pipe, 0x01f1, 0x00);
xc9080_write_register(vi_pipe, 0x01f2, 0x6c);
xc9080_write_register(vi_pipe, 0x01f3, 0x00);
xc9080_write_register(vi_pipe, 0x01f4, 0x00);
xc9080_write_register(vi_pipe, 0x01f5, 0x01);
xc9080_write_register(vi_pipe, 0x01f6, 0x44);
xc9080_write_register(vi_pipe, 0x01f7, 0x00);
xc9080_write_register(vi_pipe, 0x01f8, 0x00);
xc9080_write_register(vi_pipe, 0x01f9, 0x04);
xc9080_write_register(vi_pipe, 0x01fa, 0x00);
xc9080_write_register(vi_pipe, 0x01fb, 0x00);
xc9080_write_register(vi_pipe, 0x00b2, 0x02);
xc9080_write_register(vi_pipe, 0x00b3, 0xd0);
xc9080_write_register(vi_pipe, 0x00b4, 0x02);
xc9080_write_register(vi_pipe, 0x00b5, 0xb0);
xc9080_write_register(vi_pipe, 0x00b6, 0x02);
xc9080_write_register(vi_pipe, 0x00b7, 0x90);
xc9080_write_register(vi_pipe, 0x00b8, 0x02);
xc9080_write_register(vi_pipe, 0x00b9, 0x00);
xc9080_write_register(vi_pipe, 0x00ba, 0x01);
xc9080_write_register(vi_pipe, 0x00bb, 0xb0);
xc9080_write_register(vi_pipe, 0x00bc, 0x00);
xc9080_write_register(vi_pipe, 0x00bd, 0xf0);
xc9080_write_register(vi_pipe, 0x01cd, 0x28);
xc9080_write_register(vi_pipe, 0x01cb, 0x00);
xc9080_write_register(vi_pipe, 0x01cc, 0x40);
xc9080_write_register(vi_pipe, 0x01d6, 0x00);
xc9080_write_register(vi_pipe, 0x01d7, 0x04);
xc9080_write_register(vi_pipe, 0x01d8, 0x14);
xc9080_write_register(vi_pipe, 0x01d9, 0x50);
xc9080_write_register(vi_pipe, 0x01da, 0x70);
xc9080_write_register(vi_pipe, 0x01db, 0x90);
xc9080_write_register(vi_pipe, 0x01c0, 0x08);
xc9080_write_register(vi_pipe, 0x01c7, 0x06);
xc9080_write_register(vi_pipe, 0x01c9, 0x02);
xc9080_write_register(vi_pipe, 0x01ca, 0x30);
xc9080_write_register(vi_pipe, 0x01d1, 0x40);
xc9080_write_register(vi_pipe, 0x01b1, 0x30);
xc9080_write_register(vi_pipe, 0x01b2, 0x01);
xc9080_write_register(vi_pipe, 0x01b3, 0x00);
xc9080_write_register(vi_pipe, 0x01b4, 0x06);
xc9080_write_register(vi_pipe, 0x01b5, 0x00);
xc9080_write_register(vi_pipe, 0x016e, 0x02);
xc9080_write_register(vi_pipe, 0x016f, 0x80);
xc9080_write_register(vi_pipe, 0x01d3, 0x00);
xc9080_write_register(vi_pipe, 0x01d4, 0x30);
xc9080_write_register(vi_pipe, 0x016c, 0x00);
xc9080_write_register(vi_pipe, 0x016d, 0x00);
xc9080_write_register(vi_pipe, 0x01ba, 0x08);
xc9080_write_register(vi_pipe, 0x0212, 0x00); 
xc9080_write_register(vi_pipe, 0x0219, 0x40);
//isp0 ae

//isp1 ae
xc9080_write_register(vi_pipe, 0xfffe, 0x31);
xc9080_write_register(vi_pipe, 0x1f00, 0x00);
xc9080_write_register(vi_pipe, 0x1f01, 0x00);
xc9080_write_register(vi_pipe, 0x1f02, 0x00);
xc9080_write_register(vi_pipe, 0x1f03, 0x00);
xc9080_write_register(vi_pipe, 0x1f04, 0x02);
xc9080_write_register(vi_pipe, 0x1f05, 0x80);
xc9080_write_register(vi_pipe, 0x1f06, 0x01);
xc9080_write_register(vi_pipe, 0x1f07, 0xe0);
xc9080_write_register(vi_pipe, 0x1f08, 0x03);
xc9080_write_register(vi_pipe, 0x0051, 0x03);
xc9080_write_register(vi_pipe, 0xfffe, 0x14);
xc9080_write_register(vi_pipe, 0x000f, 0x01);
xc9080_write_register(vi_pipe, 0x0ac2, 0xc0);
xc9080_write_register(vi_pipe, 0x0ac3, 0x01);
xc9080_write_register(vi_pipe, 0x0ac4, 0x00);
xc9080_write_register(vi_pipe, 0x0ac5, 0x00);
xc9080_write_register(vi_pipe, 0x0ac8, 0x00);
xc9080_write_register(vi_pipe, 0x0ac9, 0x00);
xc9080_write_register(vi_pipe, 0x0aca, 0x35);
xc9080_write_register(vi_pipe, 0x0acb, 0x01);
xc9080_write_register(vi_pipe, 0x0acc, 0x35);
xc9080_write_register(vi_pipe, 0x0acd, 0x02);
xc9080_write_register(vi_pipe, 0x0ad0, 0x00);
xc9080_write_register(vi_pipe, 0x0ad1, 0x00);
xc9080_write_register(vi_pipe, 0x0ad2, 0x00);
xc9080_write_register(vi_pipe, 0x0ad3, 0xff);
xc9080_write_register(vi_pipe, 0x0ad4, 0x00);
xc9080_write_register(vi_pipe, 0x0ad5, 0xff);
xc9080_write_register(vi_pipe, 0x0ae8, 0x00);
xc9080_write_register(vi_pipe, 0x0ae9, 0x00);
xc9080_write_register(vi_pipe, 0x0aea, 0x35);
xc9080_write_register(vi_pipe, 0x0aeb, 0x0b);
xc9080_write_register(vi_pipe, 0x0af0, 0x00);
xc9080_write_register(vi_pipe, 0x0af1, 0x00);
xc9080_write_register(vi_pipe, 0x0af2, 0x00);
xc9080_write_register(vi_pipe, 0x0af3, 0xff);
xc9080_write_register(vi_pipe, 0xfffe, 0x14);
xc9080_write_register(vi_pipe, 0x0a00, 0x00);
xc9080_write_register(vi_pipe, 0x003c, 0x00);
xc9080_write_register(vi_pipe, 0x0a01, 0x01);
xc9080_write_register(vi_pipe, 0x0aae, 0x00);
xc9080_write_register(vi_pipe, 0x0aaf, 0x60);
xc9080_write_register(vi_pipe, 0x0ab0, 0x00);
xc9080_write_register(vi_pipe, 0x0ab1, 0x20);
xc9080_write_register(vi_pipe, 0x0a96, 0x24);
xc9080_write_register(vi_pipe, 0x0a97, 0x00);
xc9080_write_register(vi_pipe, 0x0a92, 0x00);
xc9080_write_register(vi_pipe, 0x0a93, 0x10);
xc9080_write_register(vi_pipe, 0x0a54, 0x00);
xc9080_write_register(vi_pipe, 0x0a55, 0x90);
xc9080_write_register(vi_pipe, 0x0ab8, 0x00);
xc9080_write_register(vi_pipe, 0x0ab9, 0x01);
xc9080_write_register(vi_pipe, 0x0abc, 0x15);
xc9080_write_register(vi_pipe, 0x0abd, 0xa0);
xc9080_write_register(vi_pipe, 0x0a09, 0x04);
xc9080_write_register(vi_pipe, 0x0a0a, 0x04);
xc9080_write_register(vi_pipe, 0x0a0b, 0x04);
xc9080_write_register(vi_pipe, 0x0a0c, 0x04);
xc9080_write_register(vi_pipe, 0x0a0d, 0x04);
xc9080_write_register(vi_pipe, 0x0a0e, 0x04);
xc9080_write_register(vi_pipe, 0x0a0f, 0x04);
xc9080_write_register(vi_pipe, 0x0a10, 0x04);
xc9080_write_register(vi_pipe, 0x0a11, 0x04);
xc9080_write_register(vi_pipe, 0x0a12, 0x04);
xc9080_write_register(vi_pipe, 0x0a13, 0x04);
xc9080_write_register(vi_pipe, 0x0a14, 0x04);
xc9080_write_register(vi_pipe, 0x0a15, 0x04);
xc9080_write_register(vi_pipe, 0x0a16, 0x04);
xc9080_write_register(vi_pipe, 0x0a17, 0x04);
xc9080_write_register(vi_pipe, 0x0a18, 0x04);
xc9080_write_register(vi_pipe, 0x0a19, 0x04);
xc9080_write_register(vi_pipe, 0x0a1a, 0x04);
xc9080_write_register(vi_pipe, 0x0a1b, 0x04);
xc9080_write_register(vi_pipe, 0x0a1c, 0x04);
xc9080_write_register(vi_pipe, 0x0a1d, 0x04);
xc9080_write_register(vi_pipe, 0x0a1e, 0x04);
xc9080_write_register(vi_pipe, 0x0a1f, 0x04);
xc9080_write_register(vi_pipe, 0x0a20, 0x04);
xc9080_write_register(vi_pipe, 0x0a21, 0x04);
xc9080_write_register(vi_pipe, 0x0a3c, 0x00);
xc9080_write_register(vi_pipe, 0x0a3d, 0x00);
xc9080_write_register(vi_pipe, 0x0a3e, 0x00);
xc9080_write_register(vi_pipe, 0x0a3f, 0x00);
xc9080_write_register(vi_pipe, 0x0a04, 0x01);
xc9080_write_register(vi_pipe, 0x0a7e, 0x00);
xc9080_write_register(vi_pipe, 0x0a7f, 0x80);
xc9080_write_register(vi_pipe, 0x0b70, 0x00);
xc9080_write_register(vi_pipe, 0x0b71, 0xa0);
xc9080_write_register(vi_pipe, 0x0b72, 0x00);
xc9080_write_register(vi_pipe, 0x0b73, 0x60);
xc9080_write_register(vi_pipe, 0x0a80, 0x00);
xc9080_write_register(vi_pipe, 0x0a81, 0x50);
xc9080_write_register(vi_pipe, 0x0a7b, 0x20);
xc9080_write_register(vi_pipe, 0x0a8c, 0x80);
xc9080_write_register(vi_pipe, 0x0a7c, 0x01);
xc9080_write_register(vi_pipe, 0x0bbc, 0x02);
xc9080_write_register(vi_pipe, 0x0a8e, 0x00);
xc9080_write_register(vi_pipe, 0x0a8f, 0xa0);
xc9080_write_register(vi_pipe, 0x0a90, 0x03);
xc9080_write_register(vi_pipe, 0x0a91, 0x00);
xc9080_write_register(vi_pipe, 0x0a46, 0x00);
xc9080_write_register(vi_pipe, 0x0a47, 0x07);
xc9080_write_register(vi_pipe, 0x0a48, 0x00);
xc9080_write_register(vi_pipe, 0x0a61, 0x02);
xc9080_write_register(vi_pipe, 0x0022, 0x1e);
xc9080_write_register(vi_pipe, 0x0b98, 0x00);
xc9080_write_register(vi_pipe, 0x0b99, 0x00);
xc9080_write_register(vi_pipe, 0x0b9a, 0x04);
xc9080_write_register(vi_pipe, 0x0b9b, 0x00);
xc9080_write_register(vi_pipe, 0x0b9c, 0x00);
xc9080_write_register(vi_pipe, 0x0b9d, 0x00);
xc9080_write_register(vi_pipe, 0x0b9e, 0x0c);
xc9080_write_register(vi_pipe, 0x0b9f, 0x00);
xc9080_write_register(vi_pipe, 0x0ba0, 0x00);
xc9080_write_register(vi_pipe, 0x0ba1, 0x00);
xc9080_write_register(vi_pipe, 0x0ba2, 0x24);
xc9080_write_register(vi_pipe, 0x0ba3, 0x00);
xc9080_write_register(vi_pipe, 0x0ba4, 0x00);
xc9080_write_register(vi_pipe, 0x0ba5, 0x00);
xc9080_write_register(vi_pipe, 0x0ba6, 0x6c);
xc9080_write_register(vi_pipe, 0x0ba7, 0x00);
xc9080_write_register(vi_pipe, 0x0ba8, 0x00);
xc9080_write_register(vi_pipe, 0x0ba9, 0x01);
xc9080_write_register(vi_pipe, 0x0baa, 0x44);
xc9080_write_register(vi_pipe, 0x0bab, 0x00);
xc9080_write_register(vi_pipe, 0x0bac, 0x00);
xc9080_write_register(vi_pipe, 0x0bad, 0x04);
xc9080_write_register(vi_pipe, 0x0bae, 0x00);
xc9080_write_register(vi_pipe, 0x0baf, 0x00);
xc9080_write_register(vi_pipe, 0x0a66, 0x02);
xc9080_write_register(vi_pipe, 0x0a67, 0xd0);
xc9080_write_register(vi_pipe, 0x0a68, 0x02);
xc9080_write_register(vi_pipe, 0x0a69, 0xb0);
xc9080_write_register(vi_pipe, 0x0a6a, 0x02);
xc9080_write_register(vi_pipe, 0x0a6b, 0x90);
xc9080_write_register(vi_pipe, 0x0a6c, 0x02);
xc9080_write_register(vi_pipe, 0x0a6d, 0x00);
xc9080_write_register(vi_pipe, 0x0a6e, 0x01);
xc9080_write_register(vi_pipe, 0x0a6f, 0xb0);
xc9080_write_register(vi_pipe, 0x0a70, 0x00);
xc9080_write_register(vi_pipe, 0x0a71, 0xf0);
xc9080_write_register(vi_pipe, 0x0b81, 0x28);
xc9080_write_register(vi_pipe, 0x0b7f, 0x00);
xc9080_write_register(vi_pipe, 0x0b80, 0x40);
xc9080_write_register(vi_pipe, 0x0b8a, 0x00);
xc9080_write_register(vi_pipe, 0x0b8b, 0x04);
xc9080_write_register(vi_pipe, 0x0b8c, 0x14);
xc9080_write_register(vi_pipe, 0x0b8d, 0x50);
xc9080_write_register(vi_pipe, 0x0b8e, 0x70);
xc9080_write_register(vi_pipe, 0x0b8f, 0x90);
xc9080_write_register(vi_pipe, 0x0b74, 0x08);
xc9080_write_register(vi_pipe, 0x0b7b, 0x06);
xc9080_write_register(vi_pipe, 0x0b7d, 0x02);
xc9080_write_register(vi_pipe, 0x0b7e, 0x30);
xc9080_write_register(vi_pipe, 0x0b85, 0x40);
xc9080_write_register(vi_pipe, 0x0b65, 0x30);
xc9080_write_register(vi_pipe, 0x0b66, 0x01);
xc9080_write_register(vi_pipe, 0x0b67, 0x00);
xc9080_write_register(vi_pipe, 0x0b68, 0x06);
xc9080_write_register(vi_pipe, 0x0b69, 0x00);
xc9080_write_register(vi_pipe, 0x0b22, 0x02);
xc9080_write_register(vi_pipe, 0x0b23, 0x80);
xc9080_write_register(vi_pipe, 0x0b87, 0x00);
xc9080_write_register(vi_pipe, 0x0b88, 0x30);
xc9080_write_register(vi_pipe, 0x0b20, 0x00);
xc9080_write_register(vi_pipe, 0x0b21, 0x00);
xc9080_write_register(vi_pipe, 0x0b6e, 0x08);
xc9080_write_register(vi_pipe, 0x0bc6, 0x00);
//isp1 ae

xc9080_write_register(vi_pipe, 0xfffe, 0x14);
xc9080_write_register(vi_pipe, 0x002b, 0x01);
xc9080_write_register(vi_pipe, 0x002c, 0x00);
xc9080_write_register(vi_pipe, 0x0030, 0x01);
xc9080_write_register(vi_pipe, 0x0620, 0x01);
xc9080_write_register(vi_pipe, 0x0621, 0x01);
xc9080_write_register(vi_pipe, 0xfffe, 0x30);
xc9080_write_register(vi_pipe, 0x0000, 0x47);
xc9080_write_register(vi_pipe, 0x0001, 0x00);
xc9080_write_register(vi_pipe, 0x0002, 0x90);
xc9080_write_register(vi_pipe, 0x0003, 0x00);
xc9080_write_register(vi_pipe, 0x0004, 0x10);
xc9080_write_register(vi_pipe, 0x2300, 0x09);
xc9080_write_register(vi_pipe, 0x0019, 0x0b);
xc9080_write_register(vi_pipe, 0x0051, 0x01);
xc9080_write_register(vi_pipe, 0xfffe, 0x14);
xc9080_write_register(vi_pipe, 0x003c, 0x00);
xc9080_write_register(vi_pipe, 0x003d, 0x00);
xc9080_write_register(vi_pipe, 0x0041, 0x01);
xc9080_write_register(vi_pipe, 0x0fd4, 0x01);
xc9080_write_register(vi_pipe, 0x0fd5, 0x01);
xc9080_write_register(vi_pipe, 0xfffe, 0x31);
xc9080_write_register(vi_pipe, 0x0000, 0x47);
xc9080_write_register(vi_pipe, 0x0001, 0x00);
xc9080_write_register(vi_pipe, 0x0002, 0x10);
xc9080_write_register(vi_pipe, 0x0003, 0x00);
xc9080_write_register(vi_pipe, 0x0004, 0x10);
xc9080_write_register(vi_pipe, 0x2300, 0x09);
xc9080_write_register(vi_pipe, 0x0019, 0x0b);
xc9080_write_register(vi_pipe, 0x0051, 0x01);

xc9080_write_register(vi_pipe, 0xfffe, 0x30);                                                     
xc9080_write_register(vi_pipe, 0x0013, 0x40);//blc                                                
xc9080_write_register(vi_pipe, 0x071b, 0xff);  

xc9080_write_register(vi_pipe, 0xfffe, 0x30);	
xc9080_write_register(vi_pipe, 0x03ca, 0x13);	
xc9080_write_register(vi_pipe, 0x03cb, 0x33);	
xc9080_write_register(vi_pipe, 0x03cc, 0x19);	
xc9080_write_register(vi_pipe, 0x03cd, 0x99);	
xc9080_write_register(vi_pipe, 0x03ce, 0x13);	
xc9080_write_register(vi_pipe, 0x03cf, 0x33);	
xc9080_write_register(vi_pipe, 0x03d0, 0xC);	
xc9080_write_register(vi_pipe, 0x03d1, 0xCC);	
xc9080_write_register(vi_pipe, 0x0012, 0x1a);	

// xc7160 lenc setting 
xc9080_write_register(vi_pipe, 0x0300, 0xd );
xc9080_write_register(vi_pipe, 0x0301, 0xb );
xc9080_write_register(vi_pipe, 0x0302, 0x8 );
xc9080_write_register(vi_pipe, 0x0303, 0x7 );
xc9080_write_register(vi_pipe, 0x0304, 0x8 );
xc9080_write_register(vi_pipe, 0x0305, 0x9 );
xc9080_write_register(vi_pipe, 0x0306, 0xb );
xc9080_write_register(vi_pipe, 0x0307, 0x11);
xc9080_write_register(vi_pipe, 0x0308, 0x8 );
xc9080_write_register(vi_pipe, 0x0309, 0x6 );
xc9080_write_register(vi_pipe, 0x030a, 0x4 );
xc9080_write_register(vi_pipe, 0x030b, 0x4 );
xc9080_write_register(vi_pipe, 0x030c, 0x4 );
xc9080_write_register(vi_pipe, 0x030d, 0x5 );
xc9080_write_register(vi_pipe, 0x030e, 0x7 );
xc9080_write_register(vi_pipe, 0x030f, 0xa );
xc9080_write_register(vi_pipe, 0x0310, 0x5 );
xc9080_write_register(vi_pipe, 0x0311, 0x3 );
xc9080_write_register(vi_pipe, 0x0312, 0x2 );
xc9080_write_register(vi_pipe, 0x0313, 0x1 );
xc9080_write_register(vi_pipe, 0x0314, 0x1 );
xc9080_write_register(vi_pipe, 0x0315, 0x2 );
xc9080_write_register(vi_pipe, 0x0316, 0x4 );
xc9080_write_register(vi_pipe, 0x0317, 0x7 );
xc9080_write_register(vi_pipe, 0x0318, 0x4 );
xc9080_write_register(vi_pipe, 0x0319, 0x2 );
xc9080_write_register(vi_pipe, 0x031a, 0x1 );
xc9080_write_register(vi_pipe, 0x031b, 0x0 );
xc9080_write_register(vi_pipe, 0x031c, 0x0 );
xc9080_write_register(vi_pipe, 0x031d, 0x1 );
xc9080_write_register(vi_pipe, 0x031e, 0x3 );
xc9080_write_register(vi_pipe, 0x031f, 0x6 );
xc9080_write_register(vi_pipe, 0x0320, 0x5 );
xc9080_write_register(vi_pipe, 0x0321, 0x3 );
xc9080_write_register(vi_pipe, 0x0322, 0x1 );
xc9080_write_register(vi_pipe, 0x0323, 0x0 );
xc9080_write_register(vi_pipe, 0x0324, 0x0 );
xc9080_write_register(vi_pipe, 0x0325, 0x1 );
xc9080_write_register(vi_pipe, 0x0326, 0x3 );
xc9080_write_register(vi_pipe, 0x0327, 0x6 );
xc9080_write_register(vi_pipe, 0x0328, 0x7 );
xc9080_write_register(vi_pipe, 0x0329, 0x5 );
xc9080_write_register(vi_pipe, 0x032a, 0x3 );
xc9080_write_register(vi_pipe, 0x032b, 0x2 );
xc9080_write_register(vi_pipe, 0x032c, 0x2 );
xc9080_write_register(vi_pipe, 0x032d, 0x3 );
xc9080_write_register(vi_pipe, 0x032e, 0x5 );
xc9080_write_register(vi_pipe, 0x032f, 0x9 );
xc9080_write_register(vi_pipe, 0x0330, 0xc );
xc9080_write_register(vi_pipe, 0x0331, 0x8 );
xc9080_write_register(vi_pipe, 0x0332, 0x6 );
xc9080_write_register(vi_pipe, 0x0333, 0x6 );
xc9080_write_register(vi_pipe, 0x0334, 0x6 );
xc9080_write_register(vi_pipe, 0x0335, 0x7 );
xc9080_write_register(vi_pipe, 0x0336, 0xa );
xc9080_write_register(vi_pipe, 0x0337, 0xe );
xc9080_write_register(vi_pipe, 0x0338, 0x14);
xc9080_write_register(vi_pipe, 0x0339, 0xf );
xc9080_write_register(vi_pipe, 0x033a, 0xd );
xc9080_write_register(vi_pipe, 0x033b, 0xb );
xc9080_write_register(vi_pipe, 0x033c, 0xc );
xc9080_write_register(vi_pipe, 0x033d, 0xe );
xc9080_write_register(vi_pipe, 0x033e, 0x11);
xc9080_write_register(vi_pipe, 0x033f, 0x15);
xc9080_write_register(vi_pipe, 0x0340, 0x21);
xc9080_write_register(vi_pipe, 0x0341, 0x20);
xc9080_write_register(vi_pipe, 0x0342, 0x20);
xc9080_write_register(vi_pipe, 0x0343, 0x21);
xc9080_write_register(vi_pipe, 0x0344, 0x20);
xc9080_write_register(vi_pipe, 0x0345, 0x1f);
xc9080_write_register(vi_pipe, 0x0346, 0x23);
xc9080_write_register(vi_pipe, 0x0347, 0x18);
xc9080_write_register(vi_pipe, 0x0348, 0x20);
xc9080_write_register(vi_pipe, 0x0349, 0x20);
xc9080_write_register(vi_pipe, 0x034a, 0x20);
xc9080_write_register(vi_pipe, 0x034b, 0x20);
xc9080_write_register(vi_pipe, 0x034c, 0x20);
xc9080_write_register(vi_pipe, 0x034d, 0x20);
xc9080_write_register(vi_pipe, 0x034e, 0x20);
xc9080_write_register(vi_pipe, 0x034f, 0x21);
xc9080_write_register(vi_pipe, 0x0350, 0x20);
xc9080_write_register(vi_pipe, 0x0351, 0x20);
xc9080_write_register(vi_pipe, 0x0352, 0x20);
xc9080_write_register(vi_pipe, 0x0353, 0x20);
xc9080_write_register(vi_pipe, 0x0354, 0x20);
xc9080_write_register(vi_pipe, 0x0355, 0x20);
xc9080_write_register(vi_pipe, 0x0356, 0x20);
xc9080_write_register(vi_pipe, 0x0357, 0x20);
xc9080_write_register(vi_pipe, 0x0358, 0x20);
xc9080_write_register(vi_pipe, 0x0359, 0x20);
xc9080_write_register(vi_pipe, 0x035a, 0x20);
xc9080_write_register(vi_pipe, 0x035b, 0x20);
xc9080_write_register(vi_pipe, 0x035c, 0x20);
xc9080_write_register(vi_pipe, 0x035d, 0x20);
xc9080_write_register(vi_pipe, 0x035e, 0x20);
xc9080_write_register(vi_pipe, 0x035f, 0x1f);
xc9080_write_register(vi_pipe, 0x0360, 0x21);
xc9080_write_register(vi_pipe, 0x0361, 0x20);
xc9080_write_register(vi_pipe, 0x0362, 0x20);
xc9080_write_register(vi_pipe, 0x0363, 0x20);
xc9080_write_register(vi_pipe, 0x0364, 0x20);
xc9080_write_register(vi_pipe, 0x0365, 0x20);
xc9080_write_register(vi_pipe, 0x0366, 0x20);
xc9080_write_register(vi_pipe, 0x0367, 0x20);
xc9080_write_register(vi_pipe, 0x0368, 0x20);
xc9080_write_register(vi_pipe, 0x0369, 0x20);
xc9080_write_register(vi_pipe, 0x036a, 0x20);
xc9080_write_register(vi_pipe, 0x036b, 0x20);
xc9080_write_register(vi_pipe, 0x036c, 0x20);
xc9080_write_register(vi_pipe, 0x036d, 0x20);
xc9080_write_register(vi_pipe, 0x036e, 0x20);
xc9080_write_register(vi_pipe, 0x036f, 0x1f);
xc9080_write_register(vi_pipe, 0x0370, 0x1f);
xc9080_write_register(vi_pipe, 0x0371, 0x20);
xc9080_write_register(vi_pipe, 0x0372, 0x20);
xc9080_write_register(vi_pipe, 0x0373, 0x20);
xc9080_write_register(vi_pipe, 0x0374, 0x20);
xc9080_write_register(vi_pipe, 0x0375, 0x20);
xc9080_write_register(vi_pipe, 0x0376, 0x20);
xc9080_write_register(vi_pipe, 0x0377, 0x21);
xc9080_write_register(vi_pipe, 0x0378, 0x21);
xc9080_write_register(vi_pipe, 0x0379, 0x20);
xc9080_write_register(vi_pipe, 0x037a, 0x1e);
xc9080_write_register(vi_pipe, 0x037b, 0x20);
xc9080_write_register(vi_pipe, 0x037c, 0x1f);
xc9080_write_register(vi_pipe, 0x037d, 0x20);
xc9080_write_register(vi_pipe, 0x037e, 0x1e);
xc9080_write_register(vi_pipe, 0x037f, 0x1e);
xc9080_write_register(vi_pipe, 0x0380, 0x24);
xc9080_write_register(vi_pipe, 0x0381, 0x1f);
xc9080_write_register(vi_pipe, 0x0382, 0x20);
xc9080_write_register(vi_pipe, 0x0383, 0x21);
xc9080_write_register(vi_pipe, 0x0384, 0x20);
xc9080_write_register(vi_pipe, 0x0385, 0x21);
xc9080_write_register(vi_pipe, 0x0386, 0x20);
xc9080_write_register(vi_pipe, 0x0387, 0x20);
xc9080_write_register(vi_pipe, 0x0388, 0x1f);
xc9080_write_register(vi_pipe, 0x0389, 0x20);
xc9080_write_register(vi_pipe, 0x038a, 0x20);
xc9080_write_register(vi_pipe, 0x038b, 0x20);
xc9080_write_register(vi_pipe, 0x038c, 0x20);
xc9080_write_register(vi_pipe, 0x038d, 0x20);
xc9080_write_register(vi_pipe, 0x038e, 0x21);
xc9080_write_register(vi_pipe, 0x038f, 0x21);
xc9080_write_register(vi_pipe, 0x0390, 0x20);
xc9080_write_register(vi_pipe, 0x0391, 0x20);
xc9080_write_register(vi_pipe, 0x0392, 0x20);
xc9080_write_register(vi_pipe, 0x0393, 0x20);
xc9080_write_register(vi_pipe, 0x0394, 0x20);
xc9080_write_register(vi_pipe, 0x0395, 0x20);
xc9080_write_register(vi_pipe, 0x0396, 0x20);
xc9080_write_register(vi_pipe, 0x0397, 0x20);
xc9080_write_register(vi_pipe, 0x0398, 0x21);
xc9080_write_register(vi_pipe, 0x0399, 0x20);
xc9080_write_register(vi_pipe, 0x039a, 0x20);
xc9080_write_register(vi_pipe, 0x039b, 0x20);
xc9080_write_register(vi_pipe, 0x039c, 0x20);
xc9080_write_register(vi_pipe, 0x039d, 0x21);
xc9080_write_register(vi_pipe, 0x039e, 0x21);
xc9080_write_register(vi_pipe, 0x039f, 0x20);
xc9080_write_register(vi_pipe, 0x03a0, 0x20);
xc9080_write_register(vi_pipe, 0x03a1, 0x20);
xc9080_write_register(vi_pipe, 0x03a2, 0x20);
xc9080_write_register(vi_pipe, 0x03a3, 0x20);
xc9080_write_register(vi_pipe, 0x03a4, 0x20);
xc9080_write_register(vi_pipe, 0x03a5, 0x21);
xc9080_write_register(vi_pipe, 0x03a6, 0x20);
xc9080_write_register(vi_pipe, 0x03a7, 0x21);
xc9080_write_register(vi_pipe, 0x03a8, 0x21);
xc9080_write_register(vi_pipe, 0x03a9, 0x20);
xc9080_write_register(vi_pipe, 0x03aa, 0x20);
xc9080_write_register(vi_pipe, 0x03ab, 0x21);
xc9080_write_register(vi_pipe, 0x03ac, 0x20);
xc9080_write_register(vi_pipe, 0x03ad, 0x21);
xc9080_write_register(vi_pipe, 0x03ae, 0x20);
xc9080_write_register(vi_pipe, 0x03af, 0x20);
xc9080_write_register(vi_pipe, 0x03b0, 0x1f);
xc9080_write_register(vi_pipe, 0x03b1, 0x20);
xc9080_write_register(vi_pipe, 0x03b2, 0x21);
xc9080_write_register(vi_pipe, 0x03b3, 0x20);
xc9080_write_register(vi_pipe, 0x03b4, 0x21);
xc9080_write_register(vi_pipe, 0x03b5, 0x20);
xc9080_write_register(vi_pipe, 0x03b6, 0x21);
xc9080_write_register(vi_pipe, 0x03b7, 0x21);
xc9080_write_register(vi_pipe, 0x03b8, 0x23);
xc9080_write_register(vi_pipe, 0x03b9, 0x21);
xc9080_write_register(vi_pipe, 0x03ba, 0x20);
xc9080_write_register(vi_pipe, 0x03bb, 0x22);
xc9080_write_register(vi_pipe, 0x03bc, 0x20);
xc9080_write_register(vi_pipe, 0x03bd, 0x23);
xc9080_write_register(vi_pipe, 0x03be, 0x1f);
xc9080_write_register(vi_pipe, 0x03bf, 0x21);        

//gamma
xc9080_write_register(vi_pipe, 0xfffe, 0x30);
xc9080_write_register(vi_pipe, 0x1400, 0x00);
xc9080_write_register(vi_pipe, 0x1401, 0x07);
xc9080_write_register(vi_pipe, 0x1402, 0x0e);
xc9080_write_register(vi_pipe, 0x1403, 0x15);
xc9080_write_register(vi_pipe, 0x1404, 0x1c);
xc9080_write_register(vi_pipe, 0x1405, 0x23);
xc9080_write_register(vi_pipe, 0x1406, 0x2a);
xc9080_write_register(vi_pipe, 0x1407, 0x31);
xc9080_write_register(vi_pipe, 0x1408, 0x37);
xc9080_write_register(vi_pipe, 0x1409, 0x3d);
xc9080_write_register(vi_pipe, 0x140a, 0x43);
xc9080_write_register(vi_pipe, 0x140b, 0x48);
xc9080_write_register(vi_pipe, 0x140c, 0x4d);
xc9080_write_register(vi_pipe, 0x140d, 0x51);
xc9080_write_register(vi_pipe, 0x140e, 0x55);
xc9080_write_register(vi_pipe, 0x140f, 0x59);
xc9080_write_register(vi_pipe, 0x1410, 0x5d);
xc9080_write_register(vi_pipe, 0x1411, 0x61);
xc9080_write_register(vi_pipe, 0x1412, 0x64);
xc9080_write_register(vi_pipe, 0x1413, 0x67);
xc9080_write_register(vi_pipe, 0x1414, 0x6a);
xc9080_write_register(vi_pipe, 0x1415, 0x6d);
xc9080_write_register(vi_pipe, 0x1416, 0x70);
xc9080_write_register(vi_pipe, 0x1417, 0x73);
xc9080_write_register(vi_pipe, 0x1418, 0x76);
xc9080_write_register(vi_pipe, 0x1419, 0x79);
xc9080_write_register(vi_pipe, 0x141a, 0x7c);
xc9080_write_register(vi_pipe, 0x141b, 0x7f);
xc9080_write_register(vi_pipe, 0x141c, 0x81);
xc9080_write_register(vi_pipe, 0x141d, 0x83);
xc9080_write_register(vi_pipe, 0x141e, 0x85);
xc9080_write_register(vi_pipe, 0x141f, 0x87);
xc9080_write_register(vi_pipe, 0x1420, 0x89);
xc9080_write_register(vi_pipe, 0x1421, 0x8c);
xc9080_write_register(vi_pipe, 0x1422, 0x8f);
xc9080_write_register(vi_pipe, 0x1423, 0x92);
xc9080_write_register(vi_pipe, 0x1424, 0x95);
xc9080_write_register(vi_pipe, 0x1425, 0x97);
xc9080_write_register(vi_pipe, 0x1426, 0x99);
xc9080_write_register(vi_pipe, 0x1427, 0x9b);
xc9080_write_register(vi_pipe, 0x1428, 0x9d);
xc9080_write_register(vi_pipe, 0x1429, 0x9f);
xc9080_write_register(vi_pipe, 0x142a, 0xa1);
xc9080_write_register(vi_pipe, 0x142b, 0xa3);
xc9080_write_register(vi_pipe, 0x142c, 0xa5);
xc9080_write_register(vi_pipe, 0x142d, 0xa6);
xc9080_write_register(vi_pipe, 0x142e, 0xa7);
xc9080_write_register(vi_pipe, 0x142f, 0xa8);
xc9080_write_register(vi_pipe, 0x1430, 0xa9);
xc9080_write_register(vi_pipe, 0x1431, 0xab);
xc9080_write_register(vi_pipe, 0x1432, 0xae);
xc9080_write_register(vi_pipe, 0x1433, 0xb1);
xc9080_write_register(vi_pipe, 0x1434, 0xb4);
xc9080_write_register(vi_pipe, 0x1435, 0xb7);
xc9080_write_register(vi_pipe, 0x1436, 0xbb);
xc9080_write_register(vi_pipe, 0x1437, 0xbf);
xc9080_write_register(vi_pipe, 0x1438, 0xc4);
xc9080_write_register(vi_pipe, 0x1439, 0xc9);
xc9080_write_register(vi_pipe, 0x143a, 0xcf);
xc9080_write_register(vi_pipe, 0x143b, 0xd6);
xc9080_write_register(vi_pipe, 0x143c, 0xde);
xc9080_write_register(vi_pipe, 0x143d, 0xe7);
xc9080_write_register(vi_pipe, 0x143e, 0xf0);
xc9080_write_register(vi_pipe, 0x143f, 0xf9);
xc9080_write_register(vi_pipe, 0x1440, 0xff);

//advance_raw_dns     20170623                                                                                   
xc9080_write_register(vi_pipe, 0xfffe, 0x30);                                                                                            
                                                                                                                                                                    
xc9080_write_register(vi_pipe, 0x2000, 0x14);  //s0_sigma_0                                                                              
xc9080_write_register(vi_pipe, 0x2001, 0x18);                                                                                            
xc9080_write_register(vi_pipe, 0x2002, 0x1d);                                                                                            
xc9080_write_register(vi_pipe, 0x2003, 0x20);                                                                                            
xc9080_write_register(vi_pipe, 0x2004, 0x28);                                                                                            
xc9080_write_register(vi_pipe, 0x2005, 0x30);  //s0_sigma_5                                                                              
                                                                                                         
xc9080_write_register(vi_pipe, 0x2006, 0x18);  //s0_Gsl_0                                                                           
xc9080_write_register(vi_pipe, 0x2007, 0x14);                                                                                       
xc9080_write_register(vi_pipe, 0x2008, 0x10);                                                                                       
xc9080_write_register(vi_pipe, 0x2009, 0x0a);                                                                                       
xc9080_write_register(vi_pipe, 0x200a, 0x04);                                                                                       
xc9080_write_register(vi_pipe, 0x200b, 0x01);  //s0_Gsl_5                                                                           
                                                                                                         
xc9080_write_register(vi_pipe, 0x200c, 0x1a);  //s0_RBsl_0                                                                               
xc9080_write_register(vi_pipe, 0x200d, 0x18);                                                                                            
xc9080_write_register(vi_pipe, 0x200e, 0x16);                                                                                            
xc9080_write_register(vi_pipe, 0x200f, 0x10);                                                                                            
xc9080_write_register(vi_pipe, 0x2010, 0x08);                                                                                            
xc9080_write_register(vi_pipe, 0x2011, 0x04);   //s0_RBsl_5                                                                              
                                                                                                         
xc9080_write_register(vi_pipe, 0x2012, 0x24);   //s0_ps00    //sigma_scale 大                                                            
xc9080_write_register(vi_pipe, 0x2013, 0x24);                                                                                            
xc9080_write_register(vi_pipe, 0x2014, 0x28);                                                                                            
xc9080_write_register(vi_pipe, 0x2015, 0x30);                                                                                            
xc9080_write_register(vi_pipe, 0x2016, 0x38);                                                                                            
xc9080_write_register(vi_pipe, 0x2017, 0x40);   //s0_ps05                                                                                
                                                                                                         
xc9080_write_register(vi_pipe, 0x2018, 0x20);   //s0_ps10                                                                                
xc9080_write_register(vi_pipe, 0x2019, 0x20);                                                                                            
xc9080_write_register(vi_pipe, 0x201a, 0x24);                                                                                            
xc9080_write_register(vi_pipe, 0x201b, 0x28);                                                                                            
xc9080_write_register(vi_pipe, 0x201c, 0x30);                                                                                            
xc9080_write_register(vi_pipe, 0x201d, 0x38);  //s0_ps15                                                                                 
                                                                                                         
xc9080_write_register(vi_pipe, 0x201e, 0x18);  //s0_ps20                                                                                 
xc9080_write_register(vi_pipe, 0x201f, 0x1d);                                                                                            
xc9080_write_register(vi_pipe, 0x2020, 0x20);                                                                                            
xc9080_write_register(vi_pipe, 0x2021, 0x24);                                                                                            
xc9080_write_register(vi_pipe, 0x2022, 0x28);                                                                                            
xc9080_write_register(vi_pipe, 0x2023, 0x30);   //s0_ps25                                                                                
                                                                                                         
xc9080_write_register(vi_pipe, 0x2024, 0x10);   //s0_ps30                                                                                
xc9080_write_register(vi_pipe, 0x2025, 0x12);                                                                                            
xc9080_write_register(vi_pipe, 0x2026, 0x18);                                                                                            
xc9080_write_register(vi_pipe, 0x2027, 0x1d);                                                                                            
xc9080_write_register(vi_pipe, 0x2028, 0x20);                                                                                            
xc9080_write_register(vi_pipe, 0x2029, 0x28);   //s0_ps35                                                                                
                                                                                                         
xc9080_write_register(vi_pipe, 0x202a, 0x28);    //s0_pl00     //h2_scale 小                                                             
xc9080_write_register(vi_pipe, 0x202b, 0x20);                                                                                            
xc9080_write_register(vi_pipe, 0x202c, 0x16);                                                                                            
xc9080_write_register(vi_pipe, 0x202d, 0x10);                                                                                            
xc9080_write_register(vi_pipe, 0x202e, 0x0c);                                                                                            
xc9080_write_register(vi_pipe, 0x202f, 0x08);   //s0_pl05                                                                                
                                                                                                         
xc9080_write_register(vi_pipe, 0x2030, 0x30);   //s0_pl10                                                                                
xc9080_write_register(vi_pipe, 0x2031, 0x28);                                                                                            
xc9080_write_register(vi_pipe, 0x2032, 0x24);                                                                                            
xc9080_write_register(vi_pipe, 0x2033, 0x20);                                                                                            
xc9080_write_register(vi_pipe, 0x2034, 0x1a);                                                                                            
xc9080_write_register(vi_pipe, 0x2035, 0x16);   //s0_pl15                                                                                
                                                                                                         
xc9080_write_register(vi_pipe, 0x2036, 0x38);  //s0_pl20                                                                                 
xc9080_write_register(vi_pipe, 0x2037, 0x30);                                                                                            
xc9080_write_register(vi_pipe, 0x2038, 0x28);                                                                                            
xc9080_write_register(vi_pipe, 0x2039, 0x24);                                                                                            
xc9080_write_register(vi_pipe, 0x203a, 0x20);                                                                                            
xc9080_write_register(vi_pipe, 0x203b, 0x1a);   //s0_pl25                                                                                
                                                                                                         
xc9080_write_register(vi_pipe, 0x203c, 0x3a);  //s0_pl30                                                                                 
xc9080_write_register(vi_pipe, 0x203d, 0x32);                                                                                            
xc9080_write_register(vi_pipe, 0x203e, 0x2d);                                                                                            
xc9080_write_register(vi_pipe, 0x203f, 0x28);                                                                                            
xc9080_write_register(vi_pipe, 0x2040, 0x24);                                                                                            
xc9080_write_register(vi_pipe, 0x2041, 0x20);   //s0_pl35                                                                                
                                                                                                        
xc9080_write_register(vi_pipe, 0x2044, 0x10);   //bit[4:0]thre_y                                                                         
                                                                                                        
//UV DNS                                                                                                
xc9080_write_register(vi_pipe, 0xfffe, 0x30);                                                                                                                                                                
xc9080_write_register(vi_pipe, 0x2100, 0x04);  //l_noise_list0                                                                          
xc9080_write_register(vi_pipe, 0x2101, 0x0a);                                                                                           
xc9080_write_register(vi_pipe, 0x2102, 0x10);                                                                                           
xc9080_write_register(vi_pipe, 0x2103, 0x18);                                                                                           
xc9080_write_register(vi_pipe, 0x2104, 0x28);                                                                                           
xc9080_write_register(vi_pipe, 0x2105, 0x48);  //l_noise_list5                                                                          
xc9080_write_register(vi_pipe, 0x2106, 0x5f);  //bit[7]l_noise_man_en; bit[6]l_sdw_ext_en; bit[4:0]l_sdw_ext_ns                         
xc9080_write_register(vi_pipe, 0x2107, 0x08);  //l_noise_man                                                                            
                                                                                                        
//CIP                                                                                                   
xc9080_write_register(vi_pipe, 0xfffe, 0x30);                                                                                                                                                                    
xc9080_write_register(vi_pipe, 0x0f00, 0x8f);   //bit[7:4] noise_y_slp  bit[3:0] Lsharp                                                  
xc9080_write_register(vi_pipe, 0x0f02, 0x00);  //noise_list_0                                                                            
xc9080_write_register(vi_pipe, 0x0f03, 0x00);                                                                                            
xc9080_write_register(vi_pipe, 0x0f04, 0x00);                                                                                            
xc9080_write_register(vi_pipe, 0x0f05, 0x00);                                                                                            
xc9080_write_register(vi_pipe, 0x0f06, 0x00);                                                                                            
xc9080_write_register(vi_pipe, 0x0f07, 0x00);                                                                                            
xc9080_write_register(vi_pipe, 0x0f08, 0x00);                                                                                            
xc9080_write_register(vi_pipe, 0x0f09, 0x00);  //noise_list_7                                                                            
xc9080_write_register(vi_pipe, 0x0f0a, 0x00);   //min_shp       //30                                                                       
xc9080_write_register(vi_pipe, 0x0f0b, 0x08);   //max_shp       //38                                                                       
xc9080_write_register(vi_pipe, 0x0f0c, 0x01);   //min_detail    //0b                                                                       
xc9080_write_register(vi_pipe, 0x0f0d, 0x03);   //max_detail    //0d                                                                       
xc9080_write_register(vi_pipe, 0x0f0e, 0x0f);   //min_shp_gain  //10                                                                       
xc9080_write_register(vi_pipe, 0x0f0f, 0x3f);   //max_shp_gain  //40                                                                           
                                                                                                        




////////////////////////////////////////////
//isp1
xc9080_write_register(vi_pipe, 0xfffe, 0x31);                                                     
xc9080_write_register(vi_pipe, 0x0013, 0x40);//blc                                                
xc9080_write_register(vi_pipe, 0x071b, 0xff);  

//gamma
xc9080_write_register(vi_pipe, 0xfffe, 0x31);
xc9080_write_register(vi_pipe, 0x1400, 0x00);
xc9080_write_register(vi_pipe, 0x1401, 0x07);
xc9080_write_register(vi_pipe, 0x1402, 0x0e);
xc9080_write_register(vi_pipe, 0x1403, 0x15);
xc9080_write_register(vi_pipe, 0x1404, 0x1c);
xc9080_write_register(vi_pipe, 0x1405, 0x23);
xc9080_write_register(vi_pipe, 0x1406, 0x2a);
xc9080_write_register(vi_pipe, 0x1407, 0x31);
xc9080_write_register(vi_pipe, 0x1408, 0x37);
xc9080_write_register(vi_pipe, 0x1409, 0x3d);
xc9080_write_register(vi_pipe, 0x140a, 0x43);
xc9080_write_register(vi_pipe, 0x140b, 0x48);
xc9080_write_register(vi_pipe, 0x140c, 0x4d);
xc9080_write_register(vi_pipe, 0x140d, 0x51);
xc9080_write_register(vi_pipe, 0x140e, 0x55);
xc9080_write_register(vi_pipe, 0x140f, 0x59);
xc9080_write_register(vi_pipe, 0x1410, 0x5d);
xc9080_write_register(vi_pipe, 0x1411, 0x61);
xc9080_write_register(vi_pipe, 0x1412, 0x64);
xc9080_write_register(vi_pipe, 0x1413, 0x67);
xc9080_write_register(vi_pipe, 0x1414, 0x6a);
xc9080_write_register(vi_pipe, 0x1415, 0x6d);
xc9080_write_register(vi_pipe, 0x1416, 0x70);
xc9080_write_register(vi_pipe, 0x1417, 0x73);
xc9080_write_register(vi_pipe, 0x1418, 0x76);
xc9080_write_register(vi_pipe, 0x1419, 0x79);
xc9080_write_register(vi_pipe, 0x141a, 0x7c);
xc9080_write_register(vi_pipe, 0x141b, 0x7f);
xc9080_write_register(vi_pipe, 0x141c, 0x81);
xc9080_write_register(vi_pipe, 0x141d, 0x83);
xc9080_write_register(vi_pipe, 0x141e, 0x85);
xc9080_write_register(vi_pipe, 0x141f, 0x87);
xc9080_write_register(vi_pipe, 0x1420, 0x89);
xc9080_write_register(vi_pipe, 0x1421, 0x8c);
xc9080_write_register(vi_pipe, 0x1422, 0x8f);
xc9080_write_register(vi_pipe, 0x1423, 0x92);
xc9080_write_register(vi_pipe, 0x1424, 0x95);
xc9080_write_register(vi_pipe, 0x1425, 0x97);
xc9080_write_register(vi_pipe, 0x1426, 0x99);
xc9080_write_register(vi_pipe, 0x1427, 0x9b);
xc9080_write_register(vi_pipe, 0x1428, 0x9d);
xc9080_write_register(vi_pipe, 0x1429, 0x9f);
xc9080_write_register(vi_pipe, 0x142a, 0xa1);
xc9080_write_register(vi_pipe, 0x142b, 0xa3);
xc9080_write_register(vi_pipe, 0x142c, 0xa5);
xc9080_write_register(vi_pipe, 0x142d, 0xa6);
xc9080_write_register(vi_pipe, 0x142e, 0xa7);
xc9080_write_register(vi_pipe, 0x142f, 0xa8);
xc9080_write_register(vi_pipe, 0x1430, 0xa9);
xc9080_write_register(vi_pipe, 0x1431, 0xab);
xc9080_write_register(vi_pipe, 0x1432, 0xae);
xc9080_write_register(vi_pipe, 0x1433, 0xb1);
xc9080_write_register(vi_pipe, 0x1434, 0xb4);
xc9080_write_register(vi_pipe, 0x1435, 0xb7);
xc9080_write_register(vi_pipe, 0x1436, 0xbb);
xc9080_write_register(vi_pipe, 0x1437, 0xbf);
xc9080_write_register(vi_pipe, 0x1438, 0xc4);
xc9080_write_register(vi_pipe, 0x1439, 0xc9);
xc9080_write_register(vi_pipe, 0x143a, 0xcf);
xc9080_write_register(vi_pipe, 0x143b, 0xd6);
xc9080_write_register(vi_pipe, 0x143c, 0xde);
xc9080_write_register(vi_pipe, 0x143d, 0xe7);
xc9080_write_register(vi_pipe, 0x143e, 0xf0);
xc9080_write_register(vi_pipe, 0x143f, 0xf9);
xc9080_write_register(vi_pipe, 0x1440, 0xff); 


//advance_raw_dns     20170623                                                                                   
xc9080_write_register(vi_pipe, 0xfffe, 0x31);                                                                                            
                                                                                                                                                                     
xc9080_write_register(vi_pipe, 0x2000, 0x14);  //s0_sigma_0                                                                              
xc9080_write_register(vi_pipe, 0x2001, 0x18);                                                                                            
xc9080_write_register(vi_pipe, 0x2002, 0x1d);                                                                                            
xc9080_write_register(vi_pipe, 0x2003, 0x20);                                                                                            
xc9080_write_register(vi_pipe, 0x2004, 0x28);                                                                                            
xc9080_write_register(vi_pipe, 0x2005, 0x30);  //s0_sigma_5                                                                              
                                                                                                         
xc9080_write_register(vi_pipe, 0x2006, 0x18);  //s0_Gsl_0                                                                           
xc9080_write_register(vi_pipe, 0x2007, 0x14);                                                                                       
xc9080_write_register(vi_pipe, 0x2008, 0x10);                                                                                       
xc9080_write_register(vi_pipe, 0x2009, 0x0a);                                                                                       
xc9080_write_register(vi_pipe, 0x200a, 0x04);                                                                                       
xc9080_write_register(vi_pipe, 0x200b, 0x01);  //s0_Gsl_5                                                                           
                                                                                                         
xc9080_write_register(vi_pipe, 0x200c, 0x1a);  //s0_RBsl_0                                                                               
xc9080_write_register(vi_pipe, 0x200d, 0x18);                                                                                            
xc9080_write_register(vi_pipe, 0x200e, 0x16);                                                                                            
xc9080_write_register(vi_pipe, 0x200f, 0x10);                                                                                            
xc9080_write_register(vi_pipe, 0x2010, 0x08);                                                                                            
xc9080_write_register(vi_pipe, 0x2011, 0x04);   //s0_RBsl_5                                                                              
                                                                                                         
xc9080_write_register(vi_pipe, 0x2012, 0x24);   //s0_ps00    //sigma_scale 大                                                            
xc9080_write_register(vi_pipe, 0x2013, 0x24);                                                                                            
xc9080_write_register(vi_pipe, 0x2014, 0x28);                                                                                            
xc9080_write_register(vi_pipe, 0x2015, 0x30);                                                                                            
xc9080_write_register(vi_pipe, 0x2016, 0x38);                                                                                            
xc9080_write_register(vi_pipe, 0x2017, 0x40);   //s0_ps05                                                                                
                                                                                                         
xc9080_write_register(vi_pipe, 0x2018, 0x20);   //s0_ps10                                                                                
xc9080_write_register(vi_pipe, 0x2019, 0x20);                                                                                            
xc9080_write_register(vi_pipe, 0x201a, 0x24);                                                                                            
xc9080_write_register(vi_pipe, 0x201b, 0x28);                                                                                            
xc9080_write_register(vi_pipe, 0x201c, 0x30);                                                                                            
xc9080_write_register(vi_pipe, 0x201d, 0x38);  //s0_ps15                                                                                 
                                                                                                         
xc9080_write_register(vi_pipe, 0x201e, 0x18);  //s0_ps20                                                                                 
xc9080_write_register(vi_pipe, 0x201f, 0x1d);                                                                                            
xc9080_write_register(vi_pipe, 0x2020, 0x20);                                                                                            
xc9080_write_register(vi_pipe, 0x2021, 0x24);                                                                                            
xc9080_write_register(vi_pipe, 0x2022, 0x28);                                                                                            
xc9080_write_register(vi_pipe, 0x2023, 0x30);   //s0_ps25                                                                                
                                                                                                         
xc9080_write_register(vi_pipe, 0x2024, 0x10);   //s0_ps30                                                                                
xc9080_write_register(vi_pipe, 0x2025, 0x12);                                                                                            
xc9080_write_register(vi_pipe, 0x2026, 0x18);                                                                                            
xc9080_write_register(vi_pipe, 0x2027, 0x1d);                                                                                            
xc9080_write_register(vi_pipe, 0x2028, 0x20);                                                                                            
xc9080_write_register(vi_pipe, 0x2029, 0x28);   //s0_ps35                                                                                
                                                                                                         
xc9080_write_register(vi_pipe, 0x202a, 0x28);    //s0_pl00     //h2_scale 小                                                             
xc9080_write_register(vi_pipe, 0x202b, 0x20);                                                                                            
xc9080_write_register(vi_pipe, 0x202c, 0x16);                                                                                            
xc9080_write_register(vi_pipe, 0x202d, 0x10);                                                                                            
xc9080_write_register(vi_pipe, 0x202e, 0x0c);                                                                                            
xc9080_write_register(vi_pipe, 0x202f, 0x08);   //s0_pl05                                                                                
                                                                                                         
xc9080_write_register(vi_pipe, 0x2030, 0x30);   //s0_pl10                                                                                
xc9080_write_register(vi_pipe, 0x2031, 0x28);                                                                                            
xc9080_write_register(vi_pipe, 0x2032, 0x24);                                                                                            
xc9080_write_register(vi_pipe, 0x2033, 0x20);                                                                                            
xc9080_write_register(vi_pipe, 0x2034, 0x1a);                                                                                            
xc9080_write_register(vi_pipe, 0x2035, 0x16);   //s0_pl15                                                                                
                                                                                                         
xc9080_write_register(vi_pipe, 0x2036, 0x38);  //s0_pl20                                                                                 
xc9080_write_register(vi_pipe, 0x2037, 0x30);                                                                                            
xc9080_write_register(vi_pipe, 0x2038, 0x28);                                                                                            
xc9080_write_register(vi_pipe, 0x2039, 0x24);                                                                                            
xc9080_write_register(vi_pipe, 0x203a, 0x20);                                                                                            
xc9080_write_register(vi_pipe, 0x203b, 0x1a);   //s0_pl25                                                                                
                                                                                                        
xc9080_write_register(vi_pipe, 0x203c, 0x3a);  //s0_pl30                                                                                 
xc9080_write_register(vi_pipe, 0x203d, 0x32);                                                                                            
xc9080_write_register(vi_pipe, 0x203e, 0x2d);                                                                                            
xc9080_write_register(vi_pipe, 0x203f, 0x28);                                                                                            
xc9080_write_register(vi_pipe, 0x2040, 0x24);                                                                                            
xc9080_write_register(vi_pipe, 0x2041, 0x20);   //s0_pl35                                                                                
                                                                                                         
xc9080_write_register(vi_pipe, 0x2044, 0x10);   //bit[4:0]thre_y                                                                         
                                                                                                        
//UV DNS                                                                                                
xc9080_write_register(vi_pipe, 0xfffe, 0x31);                                                                                                                                                                
xc9080_write_register(vi_pipe, 0x2100, 0x04);  //l_noise_list0                                                                          
xc9080_write_register(vi_pipe, 0x2101, 0x0a);                                                                                           
xc9080_write_register(vi_pipe, 0x2102, 0x10);                                                                                           
xc9080_write_register(vi_pipe, 0x2103, 0x18);                                                                                           
xc9080_write_register(vi_pipe, 0x2104, 0x28);                                                                                           
xc9080_write_register(vi_pipe, 0x2105, 0x48);  //l_noise_list5                                                                          
xc9080_write_register(vi_pipe, 0x2106, 0x5f);  //bit[7]l_noise_man_en; bit[6]l_sdw_ext_en; bit[4:0]l_sdw_ext_ns                         
xc9080_write_register(vi_pipe, 0x2107, 0x08);  //l_noise_man                                                                            
                                                                                                         
//CIP                                                                                                    
xc9080_write_register(vi_pipe, 0xfffe, 0x31);                                                                                                                                                                    
xc9080_write_register(vi_pipe, 0x0f00, 0x8f);   //bit[7:4] noise_y_slp  bit[3:0] Lsharp                                                  
xc9080_write_register(vi_pipe, 0x0f02, 0x00);  //noise_list_0                                                                            
xc9080_write_register(vi_pipe, 0x0f03, 0x00);                                                                                            
xc9080_write_register(vi_pipe, 0x0f04, 0x00);                                                                                            
xc9080_write_register(vi_pipe, 0x0f05, 0x00);                                                                                            
xc9080_write_register(vi_pipe, 0x0f06, 0x00);                                                                                            
xc9080_write_register(vi_pipe, 0x0f07, 0x00);                                                                                            
xc9080_write_register(vi_pipe, 0x0f08, 0x00);                                                                                            
xc9080_write_register(vi_pipe, 0x0f09, 0x00);  //noise_list_7                                                                            
xc9080_write_register(vi_pipe, 0x0f0a, 0x00);   //min_shp       //30                                                                       
xc9080_write_register(vi_pipe, 0x0f0b, 0x08);   //max_shp       //38                                                                       
xc9080_write_register(vi_pipe, 0x0f0c, 0x01);   //min_detail    //0b                                                                       
xc9080_write_register(vi_pipe, 0x0f0d, 0x03);   //max_detail    //0d                                                                       
xc9080_write_register(vi_pipe, 0x0f0e, 0x0f);   //min_shp_gain  //10                                                                       
xc9080_write_register(vi_pipe, 0x0f0f, 0x3f);   //max_shp_gain  //40  
xc9080_write_register(vi_pipe, 0xfffe, 0x25);
xc9080_write_register(vi_pipe, 0x0002, 0x44);
xc9080_write_register(vi_pipe, 0x1002, 0x44);

//ISP0  TOP            
xc9080_write_register(vi_pipe, 0xfffe, 0x30);   //isp0   
xc9080_write_register(vi_pipe, 0x0000, 0x47);   //57         
xc9080_write_register(vi_pipe, 0x0001, 0x80);   //92          
xc9080_write_register(vi_pipe, 0x0002, 0x10);   //96---90
xc9080_write_register(vi_pipe, 0x0003, 0x31);    //35----31      
xc9080_write_register(vi_pipe, 0x0004, 0x10);  
  

xc9080_write_register(vi_pipe, 0x0019, 0x8b);
xc9080_write_register(vi_pipe, 0x071c, 0x0a);
        
xc9080_write_register(vi_pipe, 0x1700, 0x81);
xc9080_write_register(vi_pipe, 0x1701, 0x40);
xc9080_write_register(vi_pipe, 0x1702, 0x40);
xc9080_write_register(vi_pipe, 0x1704, 0x1d);

//ISP0  TOP            
xc9080_write_register(vi_pipe, 0xfffe, 0x31);   //isp0   
xc9080_write_register(vi_pipe, 0x0000, 0x47);   //57         
xc9080_write_register(vi_pipe, 0x0001, 0x80);   //92          
xc9080_write_register(vi_pipe, 0x0002, 0x10);   //96---90
xc9080_write_register(vi_pipe, 0x0003, 0x31);    //35----31      
xc9080_write_register(vi_pipe, 0x0004, 0x10);  
  

xc9080_write_register(vi_pipe, 0x0019, 0x8b);
xc9080_write_register(vi_pipe, 0x071c, 0x0a);
        
xc9080_write_register(vi_pipe, 0x1700, 0x81);
xc9080_write_register(vi_pipe, 0x1701, 0x40);
xc9080_write_register(vi_pipe, 0x1702, 0x40);
xc9080_write_register(vi_pipe, 0x1704, 0x1d);

xc9080_write_register(vi_pipe, 0xfffe, 0x30);
xc9080_write_register(vi_pipe, 0x006c, 0xa0);
xc9080_write_register(vi_pipe, 0xfffe, 0x31);
xc9080_write_register(vi_pipe, 0x006c, 0xa0);
#endif

	printf("===xc9080 Init OK!===\n");
	
	ov7251_register_init(vi_pipe);	

    return TD_SUCCESS;
}


