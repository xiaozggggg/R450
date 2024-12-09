#ifndef __WK_IMU_MIDDLE_H__
#define __WK_IMU_MIDDLE_H__

#include <iostream>
#include <list>
#include <queue>
#include <mutex>
#include <memory>
#include <list>
#include <functional>
#include <sample_comm.h>

#include "wk_log.h"
#include "wk_imu.h"

using namespace std; 


 struct wk_imu_data_s{
	using wk_ptr = std::shared_ptr<wk_imu_data_s>;
 
	td_float gyro_x;
	td_float gyro_y;
	td_float gyro_z;

	td_float accel_x;
	td_float accel_y;
	td_float accel_z;
	
	td_u64 u64pts;       	// 单位：us
};

typedef std::function<void(wk_imu_data_s::wk_ptr)> pfun_wk_get_imu_cb;


class wk_imu_middle 
{
public:
	using wk_ptr = std::shared_ptr<wk_imu_middle>;
	static wk_imu_middle* wk_imu_get_instance();
	static td_s32 wk_imu_destroy_instance();
	~wk_imu_middle();

	
	/**
	 * @brief 注册获取imu数据回调(算法层使用)
	 * 
	 * @param _cb	回调
	 */
	td_bool wk_register_get_imu_cb(pfun_wk_get_imu_cb _cb);

	/**
	 * @brief 上报imu数据（mpp层使用）
	 * 
	 * @param _data  imu数据
	 */
	td_bool wk_imu_data_reported(wk_imu_data_s& _data);

	#ifdef DEBUG_SAVE_IMU_FRAME
	td_s32 wk_imu_save_file_enable(td_bool _enable);
	#endif

private:
	wk_imu_middle();
	wk_imu_middle(const wk_imu_middle&)=delete;
	wk_imu_middle& operator=(const wk_imu_middle&)=delete;
	
	static wk_imu_middle* instance;
	pfun_wk_get_imu_cb imu_cb = nullptr;
};


#endif /* __WK_IMU_MIDDLE_H__ */
