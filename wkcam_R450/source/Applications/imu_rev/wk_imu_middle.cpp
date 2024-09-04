/*************************************************************************************
*	brief: 该代码用于为算法层提供中间层接口
*	主要实现：
**************************************************************************************/

#include "wk_imu_middle.h"


wk_imu_middle* wk_imu_middle::instance = nullptr;


wk_imu_middle::wk_imu_middle()
{
	
}

wk_imu_middle::~wk_imu_middle()
{
	
}

wk_imu_middle* wk_imu_middle::wk_imu_get_instance()
{
	td_s32 u32ret;
	
	if(instance == nullptr) {
		u32ret = wk_imu_rev_start();
		if(u32ret != TD_SUCCESS) {
			WK_LOGE("err: wk_imu_rev_start error!\n");
			return nullptr;
		}

		instance = new wk_imu_middle();
	}

	return instance;
}

td_s32 wk_imu_middle::wk_imu_destroy_instance()
{
	td_s32 u32ret;

	if(instance) { 
		delete instance; 
		instance = nullptr;

		u32ret = wk_imu_rev_stop();
		if(u32ret != TD_SUCCESS) {
			WK_LOGE("err: wk_imu_rev_stop error!\n");
		}		
	} 
	
	return TD_SUCCESS;
}


td_bool wk_imu_middle::wk_register_get_imu_cb(pfun_wk_get_imu_cb _cb)
{
	this->imu_cb = _cb;
	return TD_TRUE;
}

td_bool wk_imu_middle::wk_imu_data_reported(wk_imu_data_s& _data)
{
	wk_imu_data_s::wk_ptr imu_ptr(new wk_imu_data_s);
	
	if(this->imu_cb != nullptr) {
		*imu_ptr = _data;
		this->imu_cb(imu_ptr);
	}
	return TD_TRUE;
}


