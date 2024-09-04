
#ifndef __WK_IMU__
#define __WK_IMU__

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys_utils.h>
#include "ot_type.h"
#include "ss_mpi_sys.h"

#include "wk_log.h"
#include "wk_imu_middle.h"
#include "wk_imu_socket_mng.h"

#ifdef __cplusplus
extern "C" {
#endif

/* imu数据获取功能开启 */
td_s32 wk_imu_rev_start();

/* imu数据获取功能停止 */
td_s32 wk_imu_rev_stop();

#ifdef __cplusplus
}
#endif

#endif /* __WK_IMU__ */

