/*************************************************************************************
*	brief: 该代码用于为算法层提供中间层接口
*	主要实现：
**************************************************************************************/

#include "wk_quaternion_middle.h"


wk_quaternion_middle* wk_quaternion_middle::instance = nullptr;


wk_quaternion_middle::wk_quaternion_middle()
{
	
}

wk_quaternion_middle::~wk_quaternion_middle()
{
	
}

wk_quaternion_middle* wk_quaternion_middle::wk_quaternion_get_instance()
{
	td_s32 u32ret;
	
	if(instance == nullptr) {
		u32ret = wk_quaternion_start();
		if(u32ret != TD_SUCCESS) {
			WK_LOGE("err: wk_quaternion_start error!\n");
			return nullptr;
		}

		instance = new wk_quaternion_middle();
	}

	return instance;
}

td_s32 wk_quaternion_middle::wk_quaternion_destroy_instance()
{
	td_s32 u32ret;

	if(instance) { 
		delete instance; 
		instance = nullptr;

		u32ret = wk_quaternion_stop();
		if(u32ret != TD_SUCCESS) {
			WK_LOGE("err: wk_quaternion_stop error!\n");
		}		
	} 
	
	return TD_SUCCESS;
}


td_bool wk_quaternion_middle::wk_register_get_quaternion_cb(pfun_wk_get_quaternion_cb _cb)
{
	this->quaternion_cb = _cb;
	return TD_TRUE;
}

td_bool wk_quaternion_middle::wk_quaternion_data_reported(wk_quaternion_data_s& _data)
{
	wk_quaternion_data_s::wk_ptr quaternion_ptr(new wk_quaternion_data_s);
	
	if(this->quaternion_cb != nullptr) {
		*quaternion_ptr = _data;
		this->quaternion_cb(quaternion_ptr);
	}
	return TD_TRUE;
}


