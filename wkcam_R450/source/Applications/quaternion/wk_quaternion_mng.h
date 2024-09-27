
#ifndef __WK_QUATERNION_MNG__
#define __WK_QUATERNION_MNG__

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys_utils.h>
#include <list>
#include "ot_type.h"
#include "ss_mpi_sys.h"

#include "wk_log.h"
#include "wk_quaternion_middle.h"

#ifdef __cplusplus
extern "C" {
#endif

/* 四元素数据获取功能开启 */
td_s32 wk_quaternion_start();

/* 四元素数据获取功能停止 */
td_s32 wk_quaternion_stop();

/* 添加四元素数据 */
td_s32 wk_quaternion_push_data(td_float q0, td_float q1, td_float q2, td_float q3, td_u64 pts);

#ifdef __cplusplus
}
#endif

#endif /* __WK_QUATERNION_MNG__ */

