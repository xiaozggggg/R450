#include "wk_mqtt_debug.h"


wk_mqtt_debug* wk_mqtt_debug::instance = nullptr;


wk_mqtt_debug::wk_mqtt_debug()
{
	
}

wk_mqtt_debug::~wk_mqtt_debug()
{
	
}

wk_mqtt_debug* wk_mqtt_debug::wk_mqtt_get_instance()
{
	td_s32 u32ret;
	
	if(instance == nullptr) {
		instance = new wk_mqtt_debug();

		u32ret = instance->wk_mqtt_debug_start();
		if(u32ret != TD_SUCCESS) {
			WK_LOGE("err: wk_mqtt_debug_start error!\n");
			return nullptr;
		}
	}

	return instance;
}

td_s32 wk_mqtt_debug::wk_mqtt_destroy_instance()
{
	td_s32 u32ret;

	if(instance) { 
		delete instance; 
		instance = nullptr;

		u32ret = instance->wk_mqtt_debug_stop();
		if(u32ret != TD_SUCCESS) {
			WK_LOGE("err: wk_mqtt_debug_stop error!\n");
		}		
	} 
	
	return TD_SUCCESS;
}


td_s32 wk_mqtt_debug::wk_mqtt_debug_data_push(wk_mqtt_debug_data_s::wk_ptr _data)
{
    cJSON *root = NULL, *q4 = NULL;
    char *str_print = NULL;
	td_char floatStr[32];

    root = cJSON_CreateObject(); 
	if(root == NULL) {
		WK_LOGE("cJSON_CreateObject root error\n");
		goto exit0;
	}

	q4 = cJSON_CreateArray();
	if(q4 == NULL) {
		WK_LOGE("cJSON_CreateObject q4 error\n");
		goto exit1;
	}

	/* 序列化 */
	cJSON_AddNumberToObject(root, "msg_id", ++msg_id);

	memset(floatStr, 0, sizeof(floatStr));
	snprintf(floatStr, sizeof(floatStr), "%.6f", _data->x); 
	cJSON_AddStringToObject(root, "x", floatStr);
	memset(floatStr, 0, sizeof(floatStr));
	snprintf(floatStr, sizeof(floatStr), "%.6f", _data->y); 
	cJSON_AddStringToObject(root, "y", floatStr);
	memset(floatStr, 0, sizeof(floatStr));
	snprintf(floatStr, sizeof(floatStr), "%.6f", _data->z); 
	cJSON_AddStringToObject(root, "z", floatStr);


	cJSON_AddItemToObject(root, "q4", q4);
	memset(floatStr, 0, sizeof(floatStr));
	snprintf(floatStr, sizeof(floatStr), "%.6f", _data->q[0]); 
	cJSON_AddItemToArray(q4, cJSON_CreateString(floatStr));
	memset(floatStr, 0, sizeof(floatStr));
	snprintf(floatStr, sizeof(floatStr), "%.6f", _data->q[1]); 
	cJSON_AddItemToArray(q4, cJSON_CreateString(floatStr));
	memset(floatStr, 0, sizeof(floatStr));
	snprintf(floatStr, sizeof(floatStr), "%.6f", _data->q[2]); 
	cJSON_AddItemToArray(q4, cJSON_CreateString(floatStr));
	memset(floatStr, 0, sizeof(floatStr));
	snprintf(floatStr, sizeof(floatStr), "%.6f", _data->q[3]); 
	cJSON_AddItemToArray(q4, cJSON_CreateString(floatStr));


    cJSON_AddStringToObject(root, "str", _data->str.c_str());

    str_print = cJSON_Print(root);
	if(str_print == NULL) {
		WK_LOGE("cJSON_Print error\n");
		goto exit1;
	}
	
    //WK_LOGD("%s\n", str_print);
	wk_mqtt_debug_send(str_print, strlen(str_print));

	cJSON_free(str_print);
    cJSON_Delete(root);
	root = NULL;
	str_print = NULL;
	return TD_SUCCESS;

exit1:
	cJSON_Delete(root);
	root = NULL;
exit0:
	return TD_FAILURE;
}


/**
 * mqtt push函数
 */
td_s32 wk_mqtt_debug::wk_mqtt_debug_send(td_char* _data, td_u32 lengh)
{
	td_s32 rc;
	
	pthread_mutex_lock(&mutex);
	rc = mosquitto_publish(mosq, NULL, PUBLISH_SUBJECT, lengh, _data, 2, false);
	if(rc != MOSQ_ERR_SUCCESS){
		WK_LOGE("Error publishing: %s\n", mosquitto_strerror(rc));
		pthread_mutex_unlock(&mutex);
		return TD_FAILURE;
	}	
	pthread_mutex_unlock(&mutex);

	return TD_SUCCESS;
}

/* 连接时回调 */
void wk_mqtt_debug::on_connect(struct mosquitto *mosq, void *obj, int reason_code)
{
	td_s32 rc;
	WK_LOGI("on_connect: %s\n", mosquitto_connack_string(reason_code));
	if(reason_code != 0){
		mosquitto_disconnect(mosq);
	}
	else{
		/* 进行订阅，订阅subscribe_sub主题 */
		rc = mosquitto_subscribe(mosq, NULL, SUBSCRIBE_SUBJECT, 1);
		if(rc != MOSQ_ERR_SUCCESS) {
			WK_LOGE("Error subscribing: %s\n", mosquitto_strerror(rc));
			mosquitto_disconnect(mosq);
		}
	}

	return;
}

/* 发送响应回调 */
void wk_mqtt_debug::on_publish(struct mosquitto *mosq, void *obj, int mid)
{
	WK_LOGD("Message with mid %d has been published.\n", mid);
	return;
}



/* 服务器响应客户端订阅回调 */
void wk_mqtt_debug::on_subscribe(struct mosquitto *mosq, void *obj, int mid, int qos_count, const int *granted_qos)
{
	td_s32 i;
	bool have_subscription = false;

	/* 检查订阅的QoS是否合法 */
	for(i=0; i<qos_count; i++){
		WK_LOGD("on_subscribe: %d:granted qos = %d\n", i, granted_qos[i]);
		if(granted_qos[i] <= 2){
			have_subscription = true;
		}
	}
	
	if(have_subscription == false){
		WK_LOGE("Error: All subscriptions rejected.\n");
		mosquitto_disconnect(mosq);
	}
	
	return;
}

/* 收到订阅消息后的回调 */
void wk_mqtt_debug::on_message(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg)
{
	WK_LOGI("%s %d %s\n", msg->topic, msg->qos, (char *)msg->payload);
	return;
}

td_s32 wk_mqtt_debug::wk_mqtt_create_client()
{
	td_s32 rc;

	/* 创建一个mosquitto */
	mosq = mosquitto_new("pub", true, NULL);  
	if(mosq == NULL){
		WK_LOGE("Error: Out of memory.\n");
		return TD_FAILURE;
	}

	/* 绑定回调 */
	mosquitto_connect_callback_set(mosq, wk_mqtt_debug::on_connect);
	mosquitto_publish_callback_set(mosq, wk_mqtt_debug::on_publish);
	mosquitto_subscribe_callback_set(mosq, wk_mqtt_debug::on_subscribe);
	mosquitto_message_callback_set(mosq, wk_mqtt_debug::on_message);	

	/* 进行和代理的链接 */
	rc = mosquitto_connect(mosq, HOST_ADDR, HOST_POAT, 60);
	if(rc != MOSQ_ERR_SUCCESS){
		mosquitto_destroy(mosq);
		WK_LOGE("Error: %s\n", mosquitto_strerror(rc));
		return TD_FAILURE;
	}	
	
	/* 启动网络循环管理 */
	rc = mosquitto_loop_start(mosq);
	if(rc != MOSQ_ERR_SUCCESS){
		mosquitto_destroy(mosq);
		WK_LOGE( "Error: %s\n", mosquitto_strerror(rc));
		return TD_FAILURE;
	}
	return TD_SUCCESS;
}

/* 开启mqtt客户端 */
td_s32 wk_mqtt_debug::wk_mqtt_debug_start()
{
	pthread_mutex_init(&mutex, NULL);
	int ret = mosquitto_lib_init(); 
	return wk_mqtt_create_client();
}


/* 关闭mqtt客户端 */
td_s32 wk_mqtt_debug::wk_mqtt_debug_stop()
{
	if(mosq){
		mosquitto_destroy(mosq);
		mosq=NULL;
	}
	
	pthread_mutex_destroy(&mutex);
	mosquitto_lib_cleanup();
	return TD_SUCCESS;
}





