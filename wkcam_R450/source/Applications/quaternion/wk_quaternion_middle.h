#ifndef __WK_QUATERNION_MIDDLE_H__
#define __WK_QUATERNION_MIDDLE_H__

#include <iostream>
#include <list>
#include <queue>
#include <mutex>
#include <memory>
#include <list>
#include <functional>
#include <sample_comm.h>

#include "wk_log.h"
#include "wk_quaternion_mng.h"

using namespace std; 


 struct wk_quaternion_data_s{
	using wk_ptr = std::shared_ptr<wk_quaternion_data_s>;
 
	td_float q[4];			// 四元数
	td_u64 u64pts;       	// 单位：us
};

typedef std::function<void(wk_quaternion_data_s::wk_ptr)> pfun_wk_get_quaternion_cb;


class wk_quaternion_middle 
{
public:
	using wk_ptr = std::shared_ptr<wk_quaternion_middle>;
	static wk_quaternion_middle* wk_quaternion_get_instance();
	static td_s32 wk_quaternion_destroy_instance();
	~wk_quaternion_middle();

	
	/**
	 * @brief 注册获取四元素数据回调(算法层使用)
	 * 
	 * @param _cb	回调
	 */
	td_bool wk_register_get_quaternion_cb(pfun_wk_get_quaternion_cb _cb);

	/**
	 * @brief 上报4元数数据
	 * 
	 * @param _data  4元数数据
	 */
	td_bool wk_quaternion_data_reported(wk_quaternion_data_s& _data);


private:
	wk_quaternion_middle();
	wk_quaternion_middle(const wk_quaternion_middle&)=delete;
	wk_quaternion_middle& operator=(const wk_quaternion_middle&)=delete;
	
	static wk_quaternion_middle* instance;
	pfun_wk_get_quaternion_cb quaternion_cb = nullptr;
};


#endif /* __WK_QUATERNION_MIDDLE_H__ */
