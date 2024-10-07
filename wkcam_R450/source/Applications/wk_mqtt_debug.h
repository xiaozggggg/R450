#ifndef __WK_MQTT_DEBUG_H__
#define __WK_MQTT_DEBUG_H__

#include <iostream>
#include <list>
#include <queue>
#include <mutex>
#include <memory>
#include <list>
#include <functional>

#include "wk_log.h"
#include "wk_imu.h"
#include "mosquitto.h"
#include "mqtt_protocol.h"
#include "cJSON.h"

using namespace std; 


#define HOST_ADDR 	"192.168.1.78"
#define HOST_POAT 	1883

#define PUBLISH_SUBJECT		"mqtt_vio_push_sub"    // 发送的主题
#define SUBSCRIBE_SUBJECT	"mqtt_vio_rev_sub"   // 订阅的主题



/* 结果输出数据结构 */
struct wk_mqtt_debug_data_s{
	using wk_ptr = std::shared_ptr<wk_mqtt_debug_data_s>;

	td_float x;
	td_float y;
	td_float z;
	td_float q[4];

	std::string str;
};


typedef void (*connect_ptr)(struct mosquitto *mosq, void *obj, int reason_code);
typedef void (*publish_ptr)(struct mosquitto *mosq, void *obj, int mid);
typedef void (*subscribe_ptr)(struct mosquitto *mosq, void *obj, int mid, int qos_count, const int *granted_qos);
typedef void (*message_ptr)(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg);



class wk_mqtt_debug 
{
public:
	using wk_ptr = std::shared_ptr<wk_mqtt_debug>;
	static wk_mqtt_debug* wk_mqtt_get_instance();
	static td_s32 wk_mqtt_destroy_instance();
	~wk_mqtt_debug();

	td_s32 wk_mqtt_debug_data_push(wk_mqtt_debug_data_s::wk_ptr _data);

private:
	wk_mqtt_debug();
	wk_mqtt_debug(const wk_mqtt_debug&)=delete;
	wk_mqtt_debug& operator=(const wk_mqtt_debug&)=delete;

	/* 开启/关闭mqtt客户端 */
	td_s32 wk_mqtt_debug_start();
	td_s32 wk_mqtt_debug_stop();
	td_s32 wk_mqtt_create_client();

	/* mqtt push函数 */
	td_s32 wk_mqtt_debug_send(td_char* _data, td_u32 lengh);
	
	static void on_connect(struct mosquitto *mosq, void *obj, int reason_code);
	static void on_publish(struct mosquitto *mosq, void *obj, int mid);
	static void on_subscribe(struct mosquitto *mosq, void *obj, int mid, int qos_count, const int *granted_qos);
	static void on_message(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg);

	static wk_mqtt_debug* instance;
	
	pthread_mutex_t mutex;
	struct mosquitto *mosq;   
	td_u32 msg_id = 0;
};



#endif /* __WK_MQTT_DEBUG_H__ */
