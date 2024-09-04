
#ifndef __WK_IMU_SOCKET_MNG__
#define __WK_IMU_SOCKET_MNG__

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <list>
#include <map>
#include <sys_utils.h>
#include <netinet/in.h>
#include <sys/un.h>


#include "ot_type.h"
#include "ss_mpi_sys.h"
#include "wk_log.h"

typedef enum {
	WK_IMU_SOCKET_START_STOP_CMD  = 0x11,  // 开启/停止数据传输
	WK_IMU_SOCKET_SYNC_PTS_CMD    = 0x12,  // 时间同步
	WK_IMU_SOCKET_SENSER_DATA_CMD = 0x21,  // 传输传感器数据上报
	WK_IMU_SOCKET_MCU_DEBUG_CMD	  = 0x22,  // mcu端调试信息（仅用于mcu端调试）
	WK_IMU_SOCKET_CMD_BUTT,
}wk_imu_socket_cmd_e; 

typedef enum {
	WK_IMU_SOCKET_ERR_CODE_SUCCESS 		= 0x00,
	WK_IMU_SOCKET_ERR_CODE_INVALID_CMD 	= 0xF1,
	WK_IMU_SOCKET_ERR_CODE_LENGTH_ERR 	= 0xF2,
	WK_IMU_SOCKET_ERR_CODE_VERIFY_ERR  	= 0xF3,
	WK_IMU_SOCKET_ERR_CODE_IMU_ERR  	= 0xF4,
	WK_IMU_SOCKET_ERR_CODE_TIMEOUT_ERR	= 0xFE,
	WK_IMU_SOCKET_ERR_CODE_FAIL			= 0xFF,
}wk_imu_socket_err_code_e; 

typedef enum {
	WK_IMU_GYRO 	= 0x01,
	WK_IMU_ACCEL = 0x02,
	WK_IMU_ELECT = 0x04,
}wk_imu_type_e;

typedef struct {
	bool bstart_gyro;
	bool bstart_accel;
	bool bstart_elect;
}wk_imu_socket_cmd_start_stop_s;

typedef struct {
	td_u64 u64pts;
}wk_imu_socket_cmd_sync_pts_s;

#pragma pack(1)
typedef struct {
	td_s16 s16gyro_x;
	td_s16 s16gyro_y;
	td_s16 s16gyro_z;
	td_s16 s16gyro_temp;
	
	td_s16 s16accel_x;
	td_s16 s16accel_y;
	td_s16 s16accel_z;
	
	td_s16 s16angle;
	td_u64 u64pts;       // 单位：ms

	td_s8 s8reserved[3];
}wk_imu_socket_cmd_imu_data_s;
#pragma pack()

#pragma pack(1)
typedef struct {
	td_u32 u32irq_cnt;
	td_u32 u322rx_cnt;
	td_u8  u8analyse_flag;
	td_u8  u8status;
	td_u8  u8sync_cnt;
	td_u8  arrpts_debug[16];
}wk_imu_socket_cmd_mcu_debug_s;
#pragma pack()



/* 接收响应数据结构 */
typedef struct {
	wk_imu_socket_cmd_e e_cmd;
	wk_imu_socket_err_code_e e_result;
	union{
		wk_imu_socket_cmd_imu_data_s st_imu_data;
		wk_imu_socket_cmd_mcu_debug_s st_mcu_debug;
	};
}wk_imu_socket_cmd_reply_data_s;


typedef void (*wk_fun_cmd_reply_callback)(wk_imu_socket_cmd_reply_data_s* _reply_data);

typedef void (*wk_imu_callback)();



/* imu数据获取功能初始化 */
td_s32 wk_imu_socket_init(wk_imu_callback _cb);

/* imu数据获取功能去初始化 */
td_s32 wk_imu_socket_deinit();

/* 开始或停止传感器数据传输命令发送 */
td_s32 wk_imu_start_stop_cmd_send(wk_imu_socket_cmd_start_stop_s* _cmd_data, wk_fun_cmd_reply_callback _cb);

/* 发送时间戳同步 */
td_s32 wk_imu_sync_pts_cmd_send(wk_imu_socket_cmd_sync_pts_s* _cmd_data, wk_fun_cmd_reply_callback _cb);

/* 注册senser数据上报回调 */
td_s32 wk_imu_socket_register_imu_data_cb(wk_fun_cmd_reply_callback _cb);


#endif /* __WK_IMU_SOCKET_MNG__ */

