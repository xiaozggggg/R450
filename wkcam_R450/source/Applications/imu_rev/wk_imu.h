
#ifndef __WK_IMU__
#define __WK_IMU__

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys_utils.h>
#include <list>
#include "ot_type.h"
#include "ss_mpi_sys.h"

#include "wk_log.h"
#include "wk_imu_middle.h"

#ifdef __cplusplus
extern "C" {
#endif


/* imu数据获取功能开启 */
td_s32 wk_imu_rev_start();

/* imu数据获取功能停止 */
td_s32 wk_imu_rev_stop();

/* 写入imu传感器数据 */
td_s32 wk_imu_push_data(td_float* _imu_data, td_u8 _size,td_u64 _pts);

#ifdef DEBUG_SAVE_IMU_FRAME
td_s32 wk_imu_to_file_enable(td_bool _enalbe);
#endif

#ifdef __cplusplus
}
#endif

#endif /* __WK_IMU__ */

