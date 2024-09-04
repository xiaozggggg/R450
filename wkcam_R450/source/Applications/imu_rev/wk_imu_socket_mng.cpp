
#include "wk_imu_socket_mng.h"


#define MAX_SOCKET_BUF_SIZE   		(10*1024)
#define SOCKET_READ_TIMEOUT			(1000)	

#define SOCKET_HEADER_FIRST 		(0xAA)
#define SOCKET_HEADER_SEC  			(0x55)

#define SOCKET_TIMEOUT_CHEAK_TIME 	(500)       // 检查命令超时周期
#define SOCKET_NORMAL_TIMEOUT		(3000)  	// 设置或获取类命令超时时间3s
#define SOCKET_REPORT_TIMEOUT		(0xFFFFFFFF)// 上报类命令超时时间

#define SOCKET_IMU_SERVER   		"/tmp/imu_sock_server" 
#define SOCKET_IMU_CLIENT   		"/tmp/imu_sock_client" 


/* 协议接收层数据结构 */
typedef struct {
	int imu_socket;
	struct sockaddr_un imu_addr_remote;  
	
	td_u8 rw_buffer[MAX_SOCKET_BUF_SIZE];
	td_u32 u32rw_buf_index;
	
	std::list<wk_imu_socket_cmd_reply_data_s> rw_data_list;
}wk_imu_socket_rw_s;

/* 协议命令接收解析映射 */
typedef struct {
    wk_imu_socket_cmd_e e_cmd;
    td_s32 (*cmd_rw_handler)(td_u8* _data, td_u8 _length);
}wk_imu_socket_rw_cmd_handler_s;



/* 等待列表元素数据结构 */
typedef struct {	
	wk_imu_socket_cmd_e e_cmd;
	td_u32 u32timeout; 
	td_u32 u32time;
	
	/* 命令回调处理,上层应用提供 */ 
	wk_fun_cmd_reply_callback callback; 
}wait_info_s;

/* 协议命令管理层数据结构 */
typedef struct {
	/* 等待列表和锁 */
	pthread_mutex_t mutex;
	std::multimap<wk_imu_socket_cmd_e, wait_info_s> wait_map;

	/* 线程id */
	bool b_proc_running;
    pthread_t proc_id;

	/* imu使用层注册回调 */
	wk_imu_callback imu_callback;
}wk_imu_socket_mng_s;


static td_s32 _wk_imu_socket_rw_list_push_normal(td_u8* _data, td_u8 _length);
static td_s32 _wk_imu_socket_rw_list_push_imu_data(td_u8* _data, td_u8 _length);
static td_s32 _wk_imu_socket_rw_mcu_debug_print(td_u8* _data, td_u8 _length);


static td_s32 wk_imu_unix_socket_create(void);
static td_s32 wk_imu_unix_socket_destroy(void);
static td_s32 wk_imu_unix_socket_send(td_u8 *buf, td_u8 size);


static wk_imu_socket_rw_s g_socket_rw;
static wk_imu_socket_mng_s g_socket_mng;

static wk_imu_socket_rw_cmd_handler_s g_rw_cmd_handller_list[] = {
    { WK_IMU_SOCKET_START_STOP_CMD,		_wk_imu_socket_rw_list_push_normal },
    { WK_IMU_SOCKET_SYNC_PTS_CMD,		_wk_imu_socket_rw_list_push_normal },
    { WK_IMU_SOCKET_SENSER_DATA_CMD,	_wk_imu_socket_rw_list_push_imu_data },
    { WK_IMU_SOCKET_MCU_DEBUG_CMD,		_wk_imu_socket_rw_mcu_debug_print },
};


/* 判断命令是否为上报命令，返回合适的回调超时时间 */
static td_u32 _wk_imu_socket_mng_get_cb_timeout(wk_imu_socket_cmd_e _cmd)
{
	switch (_cmd)
	{
		case WK_IMU_SOCKET_SENSER_DATA_CMD:
			return SOCKET_REPORT_TIMEOUT;
		default:	
			return SOCKET_NORMAL_TIMEOUT;
	}
}

/* 注册响应回调 */
static td_s32 _wk_imu_socket_mng_register_reply_cb(wk_imu_socket_cmd_e _cmd, wk_fun_cmd_reply_callback _cb)
{
	wait_info_s infor;
	wk_imu_socket_mng_s* pmng = &g_socket_mng;

	pthread_mutex_lock(&pmng->mutex);
	
	memset(&infor, 0, sizeof(wait_info_s));
	infor.e_cmd = _cmd;
	infor.u32timeout = _wk_imu_socket_mng_get_cb_timeout(_cmd);
	infor.u32time = system_time_ms_get();
	infor.callback = _cb;
	pmng->wait_map.insert({_cmd, infor});
	
	pthread_mutex_unlock(&pmng->mutex);

	if(_cmd != WK_IMU_SOCKET_SYNC_PTS_CMD){
		WK_LOGI("register cmd(0x%02x) reply callback\n", _cmd);
	}

	return 0;
}

/* 注册senser数据上报回调 */
td_s32 wk_imu_socket_register_imu_data_cb(wk_fun_cmd_reply_callback _cb)
{
	return _wk_imu_socket_mng_register_reply_cb(WK_IMU_SOCKET_SENSER_DATA_CMD, _cb);
}


/* 数据发送接口 */
static td_s32 _wk_imu_socket_rw_send(td_u8* _data, td_u8 _length)
{
	td_s32 ret = -1;
	wk_imu_socket_rw_s* prw = &g_socket_rw;

	if(prw->imu_socket <= 0) {
		WK_LOGE("usart is no open\n");
		return ret;
	}

	if(_data == NULL || _length <= 0) {
		WK_LOGE("_data is null");
		return ret;
	}

	ret = wk_imu_unix_socket_send(_data, _length);
	if(ret < 0 || ret != _length) {
		WK_LOGE("write socket data failed! ret = %d\n", ret);
		return -1;
	}
	
	return ret;
}

/* 求数据帧校验和 */
static td_u8 _wk_imu_socket_rw_checksum(td_u8* _data, td_u8 _length)
{
	td_u8 u8sum = 0;
	if(_data == NULL || _length <= 0) {
		WK_LOGE("_data is null");
		return 0;
	}

	for(td_u8 ifor=0; ifor<_length; ifor++) {
		u8sum += _data[ifor];
	}
	
	return u8sum;
}

/* 开始或停止传感器数据传输命令发送 */
td_s32 wk_imu_start_stop_cmd_send(wk_imu_socket_cmd_start_stop_s* _cmd_data, wk_fun_cmd_reply_callback _cb)
{
	td_s32 ret = -1;
	td_u8 u8tmp[32] = {0};
	td_u8* pdata = u8tmp;

	if(_cmd_data == NULL || _cb == NULL){
		WK_LOGE("Invalid param\n");
		return ret;
	}

	*pdata++ = SOCKET_HEADER_FIRST;
	*pdata++ = SOCKET_HEADER_SEC;
	*pdata++ = 0x02;
	*pdata++ = WK_IMU_SOCKET_START_STOP_CMD;
	*pdata |= _cmd_data->bstart_gyro  ?  WK_IMU_GYRO  : 0;
	*pdata |= _cmd_data->bstart_accel ?  WK_IMU_ACCEL : 0;
	*pdata |= _cmd_data->bstart_elect ?  WK_IMU_ELECT : 0;
	pdata++;
	*pdata = _wk_imu_socket_rw_checksum(&u8tmp[2], 3);

	ret = _wk_imu_socket_rw_send(u8tmp, 6);
	if(ret < 0) {
		return ret;
	}
	
	/* 注册响应回调 */
	if(_cb) {
		_wk_imu_socket_mng_register_reply_cb(WK_IMU_SOCKET_START_STOP_CMD, _cb);
	}
	
	return 0;
}

/* 发送时间戳同步 */
td_s32 wk_imu_sync_pts_cmd_send(wk_imu_socket_cmd_sync_pts_s* _cmd_data, wk_fun_cmd_reply_callback _cb)
{
	td_s32 ret = -1;
	td_u8 u8tmp[32] = {0};
	td_u8* pdata = u8tmp;
	static td_u8 tmp_cnt = 0;
	
	if(_cmd_data == NULL){
		WK_LOGE("Invalid param\n");
		return ret;
	}

	*pdata++ = SOCKET_HEADER_FIRST;
	*pdata++ = SOCKET_HEADER_SEC;
	*pdata++ = 0x09;
	*pdata++ = WK_IMU_SOCKET_SYNC_PTS_CMD;
	memcpy(pdata, &_cmd_data->u64pts, sizeof(td_u64));
	pdata += 8;
	*pdata = _wk_imu_socket_rw_checksum(&u8tmp[2], sizeof(td_u64)+2);

	ret = _wk_imu_socket_rw_send(u8tmp, sizeof(td_u64) + 5);
	if(ret < 0) {
		return ret;
	}
	
	/* 注册响应回调 */
	if(_cb) {
		_wk_imu_socket_mng_register_reply_cb(WK_IMU_SOCKET_SYNC_PTS_CMD, _cb);
	}
	
	return 0;
}


/* 普通命令回应送入list */
static td_s32 _wk_imu_socket_rw_list_push_normal(td_u8* _data, td_u8 _length)
{
	if(_data == NULL || _length <= 0) {
		WK_LOGE("Invalid param\n");
		return -1;
	}	

	td_s32 ret = -1;
	td_u8 u8data_len = _data[2];
	wk_imu_socket_rw_s* prw = &g_socket_rw;

    wk_imu_socket_cmd_reply_data_s pack;
    memset(&pack, 0, sizeof(wk_imu_socket_cmd_reply_data_s));
	pack.e_cmd =  (wk_imu_socket_cmd_e)_data[3];
	pack.e_result = (wk_imu_socket_err_code_e)_data[4];
    prw->rw_data_list.push_back(pack);	

	return 0;
}

/* imu数据上报送入list */
static td_s32 _wk_imu_socket_rw_list_push_imu_data(td_u8* _data, td_u8 _length)
{
	const td_u8 data_len = sizeof(wk_imu_socket_cmd_imu_data_s)+1;
		
	if(_data == NULL || _length <= 0) {
		WK_LOGE("Invalid param\n");
		return -1;
	}	

	/* 判断数据长度 */
	if((_data[2] != data_len) || ((_data[2]+4) != _length)) {
		WK_LOGE("Length error\n");
		return -1;		
	}

	td_s32 ret = -1;
	td_u8 u8data_len = _data[2];
	wk_imu_socket_rw_s* prw = &g_socket_rw;
	
    wk_imu_socket_cmd_reply_data_s pack;
    memset(&pack, 0, sizeof(wk_imu_socket_cmd_reply_data_s));
	pack.e_cmd =  (wk_imu_socket_cmd_e)_data[3];
	pack.e_result = WK_IMU_SOCKET_ERR_CODE_SUCCESS;
	memcpy(&pack.st_imu_data, &_data[4], u8data_len-1);
	pack.st_imu_data.u64pts =  (td_u32)(pack.st_imu_data.u64pts & 0x00000000FFFFFFFF); 
    prw->rw_data_list.push_back(pack);	

	//WK_LOGD("dif:%d\n", pack.st_imu_data.s8reserved[1]);  // 打印同步时间差
	return 0;
}

/* mcu端调试信息打印 */
static td_s32 _wk_imu_socket_rw_mcu_debug_print(td_u8* _data, td_u8 _length)
{
	const td_u8 data_len = sizeof(wk_imu_socket_cmd_mcu_debug_s)+1;
		
	if(_data == NULL || _length <= 0) {
		WK_LOGE("Invalid param\n");
		return -1;
	}	

	/* 判断数据长度 */
	if((_data[2] != data_len) || ((_data[2]+4) != _length)) {
		WK_LOGE("Length error\n");
		return -1;		
	}

	td_s32 ret = -1;
	td_u8 u8data_len = _data[2];
	wk_imu_socket_rw_s* prw = &g_socket_rw;
	
    wk_imu_socket_cmd_reply_data_s pack;
    memset(&pack, 0, sizeof(wk_imu_socket_cmd_reply_data_s));
	pack.e_cmd =  (wk_imu_socket_cmd_e)_data[3];
	pack.e_result = WK_IMU_SOCKET_ERR_CODE_SUCCESS;
	memcpy(&pack.st_mcu_debug, &_data[4], u8data_len-1);
	
//	WK_LOGD("#### u32irq_cnt = %x, u322rx_cnt = %x, u8analyse_flag = %x, u8status = %x u8sync_cnt = %x arr || ",
//			pack.st_mcu_debug.u32irq_cnt,
//			pack.st_mcu_debug.u322rx_cnt,
//			pack.st_mcu_debug.u8analyse_flag,
//			pack.st_mcu_debug.u8status,
//			pack.st_mcu_debug.u8sync_cnt);
//	for(int ifor=0; ifor<sizeof(pack.st_mcu_debug.arrpts_debug); ifor++){
//		printf("%02x ", pack.st_mcu_debug.arrpts_debug[ifor]);
//	}
//	printf("\n");

	return 0;
}



/* 协议拆包 */
static td_s32 _wk_imu_socket_rw_split_packet(td_u8* _buffer, td_u32 _length)
{
	td_u8* data = _buffer;
	td_u32 u32ignore_cnt = 0; 
	td_u8 u8data_len = 0;
	td_u8 u8pack_len = 0;

	if(_buffer == NULL || _length <= 0) {
		WK_LOGE("Invalid param\n");
		return -1;
	}

	/* 协议包拆分 */
	while(data < (_buffer+_length)) {
		if(data[0] != SOCKET_HEADER_FIRST || data[1] != SOCKET_HEADER_SEC) {
			u32ignore_cnt++;
			data++;
			continue;
		}

		u8data_len = data[2];
		u8pack_len = u8data_len+4;
		
		/* 判断是否接收完 */
		if(u8pack_len > (_length-u32ignore_cnt)){
			break;
		}

		if(WK_IMU_SOCKET_CMD_BUTT <= data[3]){
			u32ignore_cnt++;
			data++;
			continue;
		}

		if(_wk_imu_socket_rw_checksum(&data[2], u8data_len+1) != data[u8pack_len-1]) {
			u32ignore_cnt++;
			data++;
			WK_LOGE("checksum error - %d\n", data[u8pack_len-1]);
			continue;
		}

		/* 存入list */
		for(td_u8 ifor=0; ifor<sizeof(g_rw_cmd_handller_list)/sizeof(g_rw_cmd_handller_list[0]); ifor++) {
			if(g_rw_cmd_handller_list[ifor].e_cmd == data[3]) {	 
				if(g_rw_cmd_handller_list[ifor].cmd_rw_handler)
					g_rw_cmd_handller_list[ifor].cmd_rw_handler(data, u8pack_len);		
				break;
			}				
		}

		data += u8pack_len;
		u32ignore_cnt += u8pack_len;
	}

	return u32ignore_cnt;
}

/* 检查等待列表中有无除上报以外的命令 */
static bool _wk_imu_socket_mng_check_waitmap_cmd()
{
	bool bflag = false;
	wk_imu_socket_mng_s* pmng = &g_socket_mng;

	for(auto pair : pmng->wait_map) {
		wait_info_s &info = pair.second;

		if(_wk_imu_socket_mng_get_cb_timeout(info.e_cmd) != SOCKET_REPORT_TIMEOUT){
			return false;
		}
	}
		
	return true;
}

/* 接收数据处理 */
static td_s32 _wk_imu_socket_receive_mng()
{
	td_s32 ret = -1;
	static td_u32 u32last_time = 0;
	wk_imu_socket_rw_s* prw = &g_socket_rw;
	wk_imu_socket_mng_s* pmng = &g_socket_mng;

	pthread_mutex_lock(&pmng->mutex);

	/* 按命令回调结果 */
	while(!prw->rw_data_list.empty()) {
		wk_imu_socket_cmd_reply_data_s &tmp = prw->rw_data_list.front();

		/* 查看有无注册回调 */
		auto p_pair = pmng->wait_map.find(tmp.e_cmd);
	    if (p_pair == pmng->wait_map.end()) {
			WK_LOGE("the cmd:%d none wait callback\n");
			prw->rw_data_list.pop_front();
			continue;
	    }
		
		wait_info_s &info = p_pair->second;
		if(info.callback) {
			info.callback(&tmp);
		}

		// 上报类型的回调不能删除
		if(info.u32timeout != SOCKET_REPORT_TIMEOUT) {
			pmng->wait_map.erase(p_pair);
		}
		prw->rw_data_list.pop_front();
	}

	/* 命令超时回调*/
	td_u32 currtime = system_time_ms_get();
	if(!pmng->wait_map.empty() && 
		get_delta_time(currtime, u32last_time) >= SOCKET_TIMEOUT_CHEAK_TIME && 
		_wk_imu_socket_mng_check_waitmap_cmd() == false)
	{
		u32last_time = currtime;
		for(auto it = pmng->wait_map.begin(); it != pmng->wait_map.end(); ) {
			wait_info_s &info = it->second;
			
			// 忽略上报类超时检测
			if(info.u32timeout == SOCKET_REPORT_TIMEOUT) {
				++it;
				continue;
			}
			else {
				currtime = system_time_ms_get();
				td_u32 times = get_delta_time(currtime, info.u32time);
				if(times >= _wk_imu_socket_mng_get_cb_timeout(info.e_cmd)) {
					wk_imu_socket_cmd_reply_data_s tmp;

					memset(&tmp, 0, sizeof(wk_imu_socket_cmd_reply_data_s));
					tmp.e_cmd = info.e_cmd;
					tmp.e_result = WK_IMU_SOCKET_ERR_CODE_TIMEOUT_ERR;
					if(info.callback) {
						info.callback(&tmp);
						if(info.e_cmd != WK_IMU_SOCKET_SYNC_PTS_CMD) {
							WK_LOGE("imu socket cmd(0x%02x) timeout\n", info.e_cmd);
						}
					}
					
					it = pmng->wait_map.erase(it);
				}
				else {
					++it;
				}
			}
		}
	}
	pthread_mutex_unlock(&pmng->mutex);

	return 0;
}

/* 线程函数 */
static void * _wk_imu_socket_mng_proc(void* _pArgs) 
{
	wk_imu_socket_rw_s* prw = &g_socket_rw;
	wk_imu_socket_mng_s* pmng = &g_socket_mng;
	td_u8 u8temp[2*1024] = {0};
	td_s32 u32len = 0;
	
	while(pmng->b_proc_running == true) {
		/* 调用imu 使用层注册的回调 */
		if(pmng->imu_callback != NULL){
			pmng->imu_callback();
		}
		
		/* 数据接收 */
		memset(u8temp, 0, sizeof(u8temp));
		u32len = 0;	
		u32len = recvfrom(prw->imu_socket, u8temp, sizeof(u8temp), 0, NULL, NULL);

		/* 数据拆分 */
		if(u32len > 0) {
			memcpy(&prw->rw_buffer[prw->u32rw_buf_index], u8temp, u32len);
			prw->u32rw_buf_index += u32len;
			u32len = _wk_imu_socket_rw_split_packet(prw->rw_buffer, prw->u32rw_buf_index);
			if(u32len > 0) {
				prw->u32rw_buf_index -= u32len;
				memset(prw->rw_buffer, 0, u32len);
	       	 	memmove(prw->rw_buffer, &prw->rw_buffer[u32len], prw->u32rw_buf_index);	
			}
		}
		
		/* 接收数据处理 */
		_wk_imu_socket_receive_mng();
	}

	return NULL;
}


/* imu接收功能数据初始化 */
td_s32 wk_imu_socket_init(wk_imu_callback _cb)
{
	td_s32 ret = -1;
	wk_imu_socket_rw_s* prw = &g_socket_rw;
	wk_imu_socket_mng_s* pmng = &g_socket_mng;

	if(prw->imu_socket > 0 || pmng->b_proc_running == true) {
		WK_LOGI("imu socket is ready started\n");
		return 0;
	}

	ret = wk_imu_unix_socket_create();
	if(ret < 0) {
		WK_LOGE("socket create error\n");
		return ret;
	}

	ret = pthread_mutex_init(&pmng->mutex, NULL);
	if(ret != 0) {
		WK_LOGE("ret is %d\n", ret);
		goto socket_config_err;
	}

	pmng->b_proc_running = true;
	ret = pthread_create(&pmng->proc_id, NULL, _wk_imu_socket_mng_proc, NULL);
    if (ret != 0) {
        WK_LOGE("initial _wk_imu_socket_mng thread error\r\n");
        goto create_thread_err;
    }	

	pmng->imu_callback = _cb;

	WK_LOGI("wk_imu_socket_init ok!\n");

	return 0;
	
create_thread_err:
	pthread_mutex_destroy(&pmng->mutex);
socket_config_err:
	wk_imu_unix_socket_destroy();
	return ret;
}

/* imu接收功能去初始化 */
td_s32 wk_imu_socket_deinit()
{
	td_s32 ret = -1;
	wk_imu_socket_rw_s* prw = &g_socket_rw;
	wk_imu_socket_mng_s* pmng = &g_socket_mng;

	if(pmng->b_proc_running == false){
		return 0;
	}

	pmng->imu_callback = NULL;

	pmng->b_proc_running = false;
	if(pmng->proc_id != 0){
		ret = pthread_join(pmng->proc_id, NULL);
	    if (ret != 0) {
	        WK_LOGE("join _wk_imu_socket_mng_proc thread error\r\n");
	        return -1;
	    }			
		pmng->proc_id = 0;
	}

	wk_imu_unix_socket_destroy();
	
	memset(prw->rw_buffer, 0, MAX_SOCKET_BUF_SIZE);
	prw->u32rw_buf_index = 0;
		
	pthread_mutex_destroy(&pmng->mutex);

	std::list<wk_imu_socket_cmd_reply_data_s>().swap(prw->rw_data_list);
	std::multimap<wk_imu_socket_cmd_e, wait_info_s>().swap(pmng->wait_map);

	WK_LOGI("wk_imu_socket_deinit ok!\n");
	return 0;
}


/* 创建接收datalink的imu数据的socket */
static td_s32 wk_imu_unix_socket_create(void)
{
	wk_imu_socket_rw_s* prw = &g_socket_rw;
    struct sockaddr_un addr_local;     //local address

    prw->imu_socket = socket(AF_UNIX, SOCK_DGRAM, 0);
    if( prw->imu_socket < 0){
        WK_LOGE("socket create failed\n");
		return -1;
    }

    addr_local.sun_family = AF_UNIX;
    sprintf(addr_local.sun_path, SOCKET_IMU_CLIENT);
    remove(SOCKET_IMU_CLIENT);//绑定之前要删除原来的文件
    
    if(bind(prw->imu_socket, (struct sockaddr*)&addr_local, sizeof(addr_local)) < 0){
        close(prw->imu_socket);
        WK_LOGE("bind address failed \n");
		return -1;
    }
    WK_LOGD("Bind wkcam addr success imu_socket[%d]!\n", prw->imu_socket);

    prw->imu_addr_remote.sun_family = AF_UNIX;
    sprintf(prw->imu_addr_remote.sun_path, SOCKET_IMU_SERVER);

	return 0;
}

/* 销毁和datalink的socket连接 */
static td_s32 wk_imu_unix_socket_destroy(void)
{
	wk_imu_socket_rw_s* prw = &g_socket_rw;

	if(prw->imu_socket < 0) {
		return -1;	
	}
	
	close(prw->imu_socket);
	prw->imu_socket = 0;
	
	remove(SOCKET_IMU_CLIENT);
	
	return 0;
}

/* datalink的imu相关内容发送函数 */
static td_s32 wk_imu_unix_socket_send(td_u8 *buf, td_u8 size)
{
    int nRet;
	wk_imu_socket_rw_s* prw = &g_socket_rw;
	
    nRet = sendto(prw->imu_socket, buf, size, 0, (struct sockaddr*)&prw->imu_addr_remote, sizeof(prw->imu_addr_remote));
	return nRet;
}



