
#include "DataCenter.h"

extern "C"{
    #include "ringbuffer.h"
    #include "sys_utils.h"
    #include "mavlink_logger.h"
    #include "net_api.h"
    #include "netlink_info.h"
    #include "transmit.h"
};

//===== data struct =====//
MSG_INFO_S fcs_recv_message;
MSG_INFO_S app_recv_message;

mavlink_message_t wkmsg;
mavlink_status_t  wkstatus;

mavlink_message_t grd_msg;
mavlink_status_t  grd_status;

mavlink_message_t server_msg;
mavlink_status_t  server_status;

struct rt_ringbuffer rb_queue;
unsigned char rb_buffer[MAX_RB_SIZE];

void PrintBuf(unsigned char DataBuf[] ,unsigned int DataLen)
{
    unsigned int i;
    for(i=0;i<DataLen;i++){
        printf("%x ", DataBuf[i]);
    }
    printf("\n");
}

void getSysInfo(const char *command,char *buffer)
{
	char result_buf[100];
	int rc = 0;
	FILE *fp;

	fp = popen(command, "r");
	if(NULL == fp){
		perror("==== popen error ====");
		return;
	}
	while(fgets(result_buf, sizeof(result_buf), fp) != NULL)
	{
		if('\n' == result_buf[strlen(result_buf)-1]){
			result_buf[strlen(result_buf)-1] = '\0';
		}
	}
	memcpy(buffer,result_buf,sizeof(result_buf));
	// printf("===== result_buf[%s]\n",result_buf);

    rc = pclose(fp);
	if(-1 == rc){
		perror("close fp error");
	}
}

int strToInt(char *buf)
{
	int len,i;
	float result = 0;

	len = strlen(buf);
	for(i=0;i<len;i++){
		if(*(buf+i) >= 0x30 && *(buf+i) <= 0x39){
			result = result*10 + (*(buf+i)-0x30);
		}
	}

	return result;
}

int strToRSSI(char *buf)
{
	int i;
	int result = 0;

	for(i=1;i<4;i++){
		if(*(buf+i) >= 0x30 && *(buf+i) <= 0x39){
			result = result*10 + (*(buf+i)-0x30);
		}
	}

	result = 100 - result;	

	return result;
}

DataCenter::DataCenter()
{
    sync_fcs_systime = 0;
    sync_app_systime = 0;

    file_task = FILE_READY_START;
}

DataCenter::~DataCenter()
{
    mCmdClient.Close();
    mSimModule->stop();
}

void DataCenter::Start()
{    
    UartInit();

    memcpy(OnlineServerIp, ONLINE_IP ,strlen((char *)ONLINE_IP));

    udpRecvThreadid = std::thread(&DataCenter::UdpRecvFcsThread, this);
    udpRecvThreadid.detach();

    camRecvThreadid = std::thread(&DataCenter::CamRecvThread, this);
    camRecvThreadid.detach();

    uartRecvThreadid = std::thread(&DataCenter::UartRevThread, this);
    uartRecvThreadid.detach();

    vtMatchThreadid = std::thread(&DataCenter::VTMatchThread, this);
    vtMatchThreadid.detach();

    loggerThreadid = std::thread(&DataCenter::LoggerAnalysisThread, this);
    loggerThreadid.detach();
}

/**
 * @brief 串口数据解析
 * 
 * @param temp          接收到的单个字节
 * @param recv_message  接收消息结构体
 */
void DataCenter::UartParseChar(unsigned char temp, MSG_INFO_S *recv_message)
{
    int ret;

	switch(recv_message->parse_state)
	{
    case 0: //header1
        recv_message->chk_sum = 0;
        recv_message->nDataLength = 0;
        recv_message->msg_step = 0;
        recv_message->msg_id = 0;
        recv_message->msg_type = 0;
        recv_message->msg_received = false;

        if(temp == 0xaa || temp == 0xdd || temp == 0xfd || temp == 0xfe){ //0xdd && mavlink1.0/2.0
            memset((char *)recv_message->msgbuf,0x00,MAX_CMDLENGTH);
            recv_message->msgbuf[0] = temp;
            recv_message->msg_type = temp;
            recv_message->chk_sum = temp;
            recv_message->parse_state = 1;
        }
        break;

    case 1: //header2
        if(temp == 0xdf || temp == 0xdd){ //0xdf
            recv_message->msgbuf[1] = temp;
            recv_message->chk_sum += temp;
            recv_message->parse_state = 2;
            recv_message->msg_type = (recv_message->msg_type<<8)|temp;
        }
        else if(temp == 0xaa){ //0xaaaa
            recv_message->msg_type = FRAME_BEA;
            recv_message->msgbuf[1] = temp;
            recv_message->parse_state = 2;
        }
        else if(FRAME_MAV1 == recv_message->msgbuf[0]){ //mavlink1.0
            recv_message->msgbuf[1] = temp;
			recv_message->nDataLength = temp+8;
            recv_message->parse_state = 2;
            recv_message->msg_type = FRAME_MAV1;
        }
        else if(FRAME_MAV2 == recv_message->msgbuf[0]){ //mavlink2.0
            recv_message->msgbuf[1] = temp;
			recv_message->nDataLength = temp+12;
            recv_message->parse_state = 2;
            recv_message->msg_type = FRAME_MAV2;
        }
        else{
            recv_message->chk_sum = 0;
            recv_message->parse_state = 0;
        }
        break;

    case 2: //key word
        if((FRAME_GRD == recv_message->msg_type) || FRAME_FCS == recv_message->msg_type){
            recv_message->msgbuf[2] = temp;
            recv_message->chk_sum += temp;
            recv_message->parse_state = 3;
        }
        else if(FRAME_BEA == recv_message->msg_type && temp == 0xf1){ //0xaaaa
            recv_message->msgbuf[2] = temp;
            recv_message->parse_state = 3;
        }
        else if(FRAME_MAV1 == recv_message->msg_type ||
                FRAME_MAV2 == recv_message->msg_type){
            recv_message->msgbuf[recv_message->msg_step+2] = temp;
            recv_message->msg_step++;

            if(recv_message->msg_step+2 == recv_message->nDataLength){
                recv_message->parse_state = 0;
                recv_message->msg_received = true;

                // app_lost_count = APP_TIMEOUT;

                if(recv_message->msg_id == MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD){
                    recv_message->msg_received = false;
                    recv_message->chk_sum = 0;
                    recv_message->parse_state = 0;
                    printf("recv_message->msg_id[%d]\n", recv_message->msg_id);
                }
            }
        }
        else{
            recv_message->chk_sum = 0;
            recv_message->parse_state = 0;
        }
        break;

    case 3: //payload length
        recv_message->msgbuf[3] = temp;
        if(FRAME_BEA == recv_message->msg_type){
			recv_message->nDataLength = temp+4;
		}
		else{
			recv_message->nDataLength = temp;
			recv_message->chk_sum += temp;
		}

        recv_message->parse_state = 4;
        recv_message->msg_step = 0;
        break;

    case 4: //payload
        if(recv_message->msg_step < recv_message->nDataLength){
            recv_message->msgbuf[recv_message->msg_step+4] = temp;
            recv_message->chk_sum += temp;
            recv_message->msg_step++;
        }

        if(recv_message->msg_step == recv_message->nDataLength){
            if(FRAME_BEA == recv_message->msg_type){
				recv_message->msg_received = true;
				recv_message->parse_state = 0;
			}
			else{
				recv_message->parse_state = 5;
			}
        }
        break;

    case 5: //check sum
        recv_message->msgbuf[recv_message->msg_step+4] = temp;
        if(recv_message->chk_sum == temp){
            recv_message->msg_received = true;
            if(FRAME_GRD == recv_message->msg_type){
                received_count = 3;
            }
        }
        recv_message->parse_state = 0;
        break;

    default:
        break;
	}
}

/**
 * @brief 获取图传当前状态
 * 
 * @param vt_rssi       信号值
 * @param timeout       对频超时计时
 * @return CSW_STATUS_E 图传状态
 */
CSW_STATUS_E DataCenter::getVTStatus(int vt_rssi, int timeout)
{
    CSW_STATUS_E vt_status;

    //对频是否超时
    // printf("========= vt_rssi[%d] timeout[%d]\n",vt_rssi,timeout);
    if(timeout > 0){
        vt_status = CSW_MATCH_ING;

        if(vt_rssi > 0 && vt_rssi < 90 && timeout < (MAX_MATCH_TIMEOUT - 10)){
            vt_status = CSW_CONNECT;
        }
    }
    else {
        if(vt_rssi > 0 && vt_rssi < 90){
            vt_status = CSW_CONNECT;
        }
        else{
            vt_status = CSW_DISCONNECT;
        }
    }

    return vt_status;
}

/**
 * @brief 发送对频状态给飞控
 * 
 * @param csw_rssi 信号值，用于调试
 */
void DataCenter::sendMatchStatus(int csw_rssi)
{
    mavlink_message_t mavlink_message;
    mavlink_command_ack_t wk_mavlink_command_ack;
    
	uint16_t length;
    uint8_t msgbuff[MAVLINK_MAX_PACKET_LEN];

    wk_mavlink_command_ack.command = MAV_CMD_IMAGE_TRANSMITTER_PAIR;
    wk_mavlink_command_ack.result = mMatchInfo.match_enable;
    printf("====== matching match_status[%d] value[%d]\n",wk_mavlink_command_ack.result, csw_rssi);

    mavlink_msg_command_ack_encode(MAVLINK_SYS_ID, WK_MODULE_TYPE_CAMERA, &mavlink_message, &wk_mavlink_command_ack);
    length = mavlink_msg_to_send_buffer(msgbuff, &mavlink_message);
    
    UartSendHandle(msgbuff,length);
}

/**
 * @brief 图传对频线程
 * 
 */
void DataCenter::VTMatchThread(void)
{
	int VT_RSSI,i,wkpid;
    char res_buf[100];
    unsigned char Ack_Count;
    CSW_STATUS_E Vt_Status;

    Ack_Count = 0;

    /* 创建wifi日志接收线程 */
    nb_wifi_create_thread();

	while(1)
	{
        //是否接收到遥控器的数据
        nb_get_netlink_info(&VT_RSSI);
        if(received_count > 0){
            received_count--;
        }
        else{
            VT_RSSI = 0;
            // printf("===== can't received remoter data, disconnect --> rssi[%d] \n", VT_RSSI);
        }
        Vt_Status = getVTStatus(VT_RSSI, mMatchInfo.match_timeout);
        // printf("===== connect stauts[%d] --> mMatchInfo.match_timeout[%d] \n", Vt_Status, mMatchInfo.match_timeout);

        nb_send_handle();

        getSysInfo(GET_SUPPLICANT_PID, res_buf);
        wkpid = strToInt(res_buf);

        switch(Vt_Status){
        case CSW_CONNECT:
            if(CSW_MATCH_ING == mMatchInfo.match_enable){
                mMatchInfo.match_enable = CSW_CONNECT;
                nb_send_match_cmd(0);
                system("rm /etc/hostapd_5G_WPA_last.conf");
                printf("========= match SUCCESS and use NEW match id ===========\n");

                Ack_Count = MATCH_TIMEOUT_ACK;
                mMatchInfo.match_timeout = 0;
            }
            break;
        
        case CSW_DISCONNECT:
            if(CSW_MATCH_ING == mMatchInfo.match_enable){
                mMatchInfo.match_enable = CSW_DISCONNECT;
                nb_send_match_cmd(0);
                system("mv /etc/hostapd_5G_WPA_last.conf /etc/hostapd_5G_WPA.conf");
                printf("========= match TIMEOUT and use LAST match id ===========\n");

                Ack_Count = MATCH_TIMEOUT_ACK;
                mMatchInfo.match_timeout = 0;
            }
            break;

        case CSW_MATCH_ING:
            if(mMatchInfo.match_timeout == MAX_MATCH_TIMEOUT){
                printf("========= start match CMD and backup LAST match id ===========\n");

                //开始对频
                nb_enable_match();
                nb_send_match_cmd(2);
            }

            if(wkpid <= 0){
                system("hostapd /etc/hostapd_5G_WPA.conf &");
                nb_send_match_cmd(1);
            }
            Ack_Count = 0;
            break;

        default:
            break;
        }

        //收到对频指令后，回复对频状态
        if(mMatchInfo.match_timeout > 0){
            mMatchInfo.match_timeout--;

            sendMatchStatus(VT_RSSI);
        }

        //对频超时后，再回复几秒 
        if(Ack_Count > 0){
            Ack_Count--;

            sendMatchStatus(Ack_Count);
        }

        transmitter_handle();

        usleep(1000*1000);
    }
}

/**
 * @brief Mavlink协议解析
 * 
 * @param byte 接收的单个字节
 */
void DataCenter::mavlink_decode_FCS(unsigned char byte)
{
    char string[64] = {0};
    CAM_TIME_T tm = {0};

    uint16_t length;
    uint8_t msgbuff[300];
    unsigned long long recv_timestamp;
    int msg_param;

    if (mavlink_parse_char(0, byte, &wkmsg, &wkstatus)) {
        // printf("============ mavlink msgid[%d]\n",wkmsg.msgid);

        switch (wkmsg.msgid)
        {
        case MAVLINK_MSG_ID_COMMAND_LONG:
            mavlink_command_long_t wk_command_long;
            mavlink_msg_command_long_decode(&wkmsg, &wk_command_long);
            // printf("wk_command_long.param1[%f] \n",wk_command_long.param1);

            if(MAV_CMD_IMAGE_TRANSMITTER_PAIR == wk_command_long.command){
                recv_timestamp = (unsigned long long)wk_command_long.param2;
                
                printf("wk_command_long.command[%d] wk_command_long.param1[%f] timestamp[%lld]\n",
                        wk_command_long.command, wk_command_long.param1, recv_timestamp);
                
                //使用时间戳，判断是否为同一条对频消息
                if(wk_command_long.param1 == 1.0f && recv_timestamp != mMatchInfo.timestamp){
                    mMatchInfo.match_enable = CSW_MATCH_ING;
                    mMatchInfo.match_timeout = MAX_MATCH_TIMEOUT;
                    mMatchInfo.timestamp = recv_timestamp;

                    sendMatchStatus(0);
                }
            }
            else if(MAV_CMD_FACTORY_RESET == wk_command_long.command){
                msg_param = (int)wk_command_long.param1;
                mavlink_log_file_reset(msg_param);
            }
            else if(MAV_CMD_BATT_POWERUP_MODE == wk_command_long.command){
                msg_param = (int)wk_command_long.param1;
                // system("rm /tmp/charging.txt");
                // printf("wk_command_long.command[%d] wk_command_long.param1[%f] \n",wk_command_long.command, wk_command_long.param1);

                //充电时，停止图像进程
                if(wkcam_process_enable != msg_param){
                    printf("MAV_CMD_BATT_POWERUP_MODE --> wkcam_process_enable[%d]\n",msg_param);
                    if(msg_param == WK_CHARGE_ENABLE){
                        system("touch /tmp/charging.txt");
                        system("killall -9 wkcam_f210");
                    }
                    else{
                        system("rm /tmp/charging.txt");
                    }
                    wkcam_process_enable = msg_param;
                    setUartSendStatus(wkcam_process_enable);
                }
            }
            else{
                length = mavlink_msg_to_send_buffer(msgbuff,&wkmsg);
                comm_send_handle(msgbuff,length);
            }
            break;

        case MAVLINK_MSG_ID_GPS_RAW_INT:
            mavlink_gps_raw_int_t drone_gps_raw;
            mavlink_msg_gps_raw_int_decode(&wkmsg, &drone_gps_raw);
            home_local.sat_mode = drone_gps_raw.fix_type;
            transmitter_setGPSdata(drone_gps_raw.lat, drone_gps_raw.lon, drone_gps_raw.alt, drone_gps_raw.satellites_visible);

            length = mavlink_msg_to_send_buffer(msgbuff,&wkmsg);
            comm_send_handle(msgbuff,length);
            break;

        case MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE:
            mavlink_wk_heartbeat_ext_new_rule_t drone_new_rule;
            mavlink_msg_wk_heartbeat_ext_new_rule_decode(&wkmsg, &drone_new_rule);
            // printf("== recv MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE\n");
            transmitter_setSYSdata((char*)drone_new_rule.product_id);
            
            length = mavlink_msg_to_send_buffer(msgbuff,&wkmsg);
            comm_send_handle(msgbuff,length);
            break;

        case MAVLINK_MSG_ID_WK_HEARTBEAT_EXT:
            mavlink_wk_heartbeat_ext_t drone_ext_heartbeat;
            mavlink_msg_wk_heartbeat_ext_decode(&wkmsg, &drone_ext_heartbeat);
            // printf("== recv MAVLINK_MSG_ID_WK_HEARTBEAT_EXT\n");
            transmitter_setSYSdata((char*)drone_ext_heartbeat.product_id);

            length = mavlink_msg_to_send_buffer(msgbuff,&wkmsg);
            comm_send_handle(msgbuff,length);
            break;

        case MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC:
            mavlink_wk_camera_cmd_utc_time_sync_t wk_camera_cmd_utc_time_sync;
            mavlink_msg_wk_camera_cmd_utc_time_sync_decode(&wkmsg, &wk_camera_cmd_utc_time_sync);
            if(wkmsg.compid == MAV_COMP_ID_MISSIONPLANNER) {
                //同步APP的时间后，不再同步飞控的时间
                if(sync_app_systime > 3){
                    break;
                }
                sync_app_systime += 1;
                // printf("======== sync APP time\n");
            }
            else if(wkmsg.compid == MAV_COMP_ID_AUTOPILOT1 && home_local.sat_mode < 3){
                // printf("======== GPS no fix[%d], do not sync FCS time\n",home_local.sat_mode);
                break;
            }
            else if(wkmsg.compid == MAV_COMP_ID_AUTOPILOT1 && home_local.sat_mode >= 3){
                //只同步定位后的飞控时间
                //同步APP的时间后，不再同步飞控的时间
                if(sync_fcs_systime || sync_app_systime){
                    break;
                }
                sync_fcs_systime = 1;
                // printf("======== sync FCS time\n");
            }

            tm.year   = wk_camera_cmd_utc_time_sync.year;
            tm.month  = wk_camera_cmd_utc_time_sync.month;
            tm.date   = wk_camera_cmd_utc_time_sync.day;
            tm.hour   = wk_camera_cmd_utc_time_sync.hour;
            tm.minute = wk_camera_cmd_utc_time_sync.min;
            tm.second = wk_camera_cmd_utc_time_sync.sec;

            //上电后，GPS定位后，同步一次时间
            sprintf(string,"date -s %c%d-%d-%d %d:%d:%d%c", '"', tm.year,tm.month,tm.date,tm.hour,tm.minute,tm.second, '"');
            system(string);

            if(sync_fcs_systime > 0 && sync_app_systime == 0){
                mavlink_log_fix_type(0);
            }
            else if(sync_app_systime){
                mavlink_log_fix_type(3);
            }
            break;
        
        case MAVLINK_MSG_ID_HEARTBEAT:
            mavlink_heartbeat_t wk_heartbeat;
            mavlink_msg_heartbeat_decode(&wkmsg,&wk_heartbeat);
            //获取飞机解锁状态
            if(wk_heartbeat.base_mode & MAV_MODE_FLAG_SAFETY_ARMED){
                // 闭锁后再解锁，立刻关闭上次的日志文件
                if(FILE_READY_CLOSE == file_task){
                    // printf("======= close file within 10s\n");
                    mavlink_log_file_close();
                    file_task = FILE_READY_START;
                }
                else{
                    //解锁状态下，更新飞行时间
                    mavlink_log_flight_duration_update();
                }

                drone_mode = DRONE_DISARMED;
            }
            else{
                // 解锁后再闭锁，若正在记录日志，等待10秒关闭日志文件
                if( FILE_OPENED == file_task && DRONE_DISARMED == drone_mode ){
                    file_task = FILE_READY_CLOSE;

                    drone_mode = DRONE_ARMED;
                }
            }

            length = mavlink_msg_to_send_buffer(msgbuff,&wkmsg);
            comm_send_handle(msgbuff,length);
            break;
        
        case MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD:
            mavlink_wk_set_ai_tracking_cmd_t wk_camera_cmd_ai_tracking;
            mavlink_msg_wk_set_ai_tracking_cmd_decode(&wkmsg, &wk_camera_cmd_ai_tracking);
            length = mavlink_msg_to_send_buffer(msgbuff,&wkmsg);

            // printf("========== recevied from fcs ======= \n");
            if(wk_camera_cmd_ai_tracking.reserved[7] == 0){ // 发送给相机切换模式
                CamSendHandle(msgbuff,length);
            }
            else{ // 发送给app显示识别结果
                comm_send_handle(msgbuff,length);
            }
            break;

        case MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL:
        case MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO:
        case MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC:
        case MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT:
        case MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER:
        case MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS:
        case MAVLINK_MSG_ID_WK_CAMERA_CMD_PREVIEW_PARAM:
        case MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM:
        case MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER:
        case MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO:
        case MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE:
        case MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_VALUE:
        case MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC:
        case MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM:
        case MAVLINK_MSG_ID_WK_CAMERA_CMD_AWB_MODE:
        case MAVLINK_MSG_ID_WK_UPGRADE_REQUEST:
        case MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO:
        case MAVLINK_MSG_ID_WK_UPGRADE_FRAG_DATA:
        case MAVLINK_MSG_ID_WK_UPGRADE_END_ACK:
		case MAVLINK_MSG_ID_ODOMETRY:	
		case MAVLINK_MSG_ID_HIGHRES_IMU:
            // printf("==== datalink recv msg id [%d]\n", wkmsg.msgid);
            length = mavlink_msg_to_send_buffer(msgbuff,&wkmsg);
            CamSendHandle(msgbuff,length);
            break;

        case MAVLINK_MSG_ID_WK_LOG_MODE:
        case MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE:
        case MAVLINK_MSG_ID_WK_LOG_GNSS:
        case MAVLINK_MSG_ID_WK_LOG_GPS_RAW:
        case MAVLINK_MSG_ID_WK_LOG_RTK_RAW:
        case MAVLINK_MSG_ID_WK_LOG_BEACON:
        case MAVLINK_MSG_ID_WK_LOG_MISSION:
        case MAVLINK_MSG_ID_WK_LOG_MOTORS:
        case MAVLINK_MSG_ID_WK_LOG_RCIN:
        case MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW:
        case MAVLINK_MSG_ID_WK_LOG_POS_CTRL:
        case MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO:
        case MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA:
        case MAVLINK_MSG_ID_WK_LOG_TEXT:
            MavlinkCmdOnDealLogger(wkmsg);
            break;
        
        default:
            length = mavlink_msg_to_send_buffer(msgbuff,&wkmsg);
            comm_send_handle(msgbuff,length);
            break;
        }
    }    
}


void DataCenter::mavlink_decode_GRD(unsigned char byte)
{
    char wifi_Cmd[120];

    uint16_t length;
    uint8_t msgbuff[300];

    if(mavlink_parse_char(1, byte, &grd_msg, &grd_status)) {
        // printf("============ mavlink grd msgid[%d]\n",wkmsg.msgid);

        switch(grd_msg.msgid){
        case MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD:
                length = mavlink_msg_to_send_buffer(msgbuff, &grd_msg);
                //printf("========== recevied from app ======= \n");
                CamSendHandle(msgbuff,length);
                break;

        case MAVLINK_MSG_ID_WIFI_CONFIG_AP:
            mavlink_wifi_config_ap_t wk_camera_ap_config;
            mavlink_msg_wifi_config_ap_decode(&grd_msg, &wk_camera_ap_config);

            if(mWifiConf.set_wifi_busy > 0){
                break;
            }
            else{
                printf("recv app setting ssid[%s] passwd[%s]\n", wk_camera_ap_config.ssid, wk_camera_ap_config.password);
                mWifiConf.set_wifi_busy = 5;
            }

            if(strcmp(wk_camera_ap_config.ssid, "DISABLE_AP") == 0){
                mWifiConf.set_wifi_config = WIFI_SET_TO_STA;
                send_wifi_ack(mWifiConf);
                printf("========== exit ap mode [%d]\n", mWifiConf.set_wifi_config);
                usleep(500*1000);

                system("killall -9 hostapd");
                system("killall -9 udhcpd");
                usleep(500*1000);

                system("./setWifiMode.sh sta");
            }
            else{
                mWifiConf.set_wifi_config = WIFI_SET_TO_AP;
                send_wifi_ack(mWifiConf);
                usleep(500*1000);

                //修改WIFI账号
                memset(wifi_Cmd, 0x00, sizeof(wifi_Cmd));
                sprintf(wifi_Cmd, "sed -i '5c ssid=%s' /etc/hostapd-wlan.conf", wk_camera_ap_config.ssid);
                system(wifi_Cmd);

                //修改WIFI密码
                memset(wifi_Cmd, 0x00, sizeof(wifi_Cmd));
                sprintf(wifi_Cmd, "sed -i '8c wpa_passphrase=%s' /etc/hostapd-wlan.conf", wk_camera_ap_config.password);
                system(wifi_Cmd);

                system("sync");
                usleep(500*1000);

                //切换模式
                system("./setWifiMode.sh ap");
            }
            break;

        default:
            break;
        }
    }
}

void DataCenter::send_wifi_ack(WIFI_CONF_S wifi_conf)
{
    mavlink_message_t mavlink_message;
    mavlink_wifi_config_ap_t wk_camera_ap_config;
    
	uint16_t length;
    uint8_t msgbuff[MAVLINK_MAX_PACKET_LEN];

    //printf("========== set ap mode [%d]\n", wifi_conf.set_wifi_config);
    memset(&wk_camera_ap_config, 0x00, sizeof(mavlink_wifi_config_ap_t));
    switch (wifi_conf.set_wifi_config)
    {
    case WIFI_SET_TO_STA:
        sprintf(wk_camera_ap_config.ssid, "DRONE_SET_TO_STA");
        break;

    case WIFI_SET_TO_AP:
        sprintf(wk_camera_ap_config.ssid, "DRONE_SET_TO_AP");
        break;

    case WIFI_IN_AP:
        sprintf(wk_camera_ap_config.ssid, "DRONE_ALREADY_IN_FT");
        break;
    
    default:
        break;
    }

    mavlink_msg_wifi_config_ap_encode(MAVLINK_SYS_ID, WK_MODULE_TYPE_CAMERA, &mavlink_message, &wk_camera_ap_config);
    length = mavlink_msg_to_send_buffer(msgbuff, &mavlink_message);
    comm_send_handle(msgbuff, length);
}

/**
 * @brief 串口接收线程，接收飞控发出的指令
 * 
 * @param arg 
 * @return void* 
 */
 #if 0
void DataCenter::UartRevThread(void)
{
    uint8_t uart_buf[MAX_CMDLENGTH]; 
    uint16_t uart_length;
    int i;

    rt_ringbuffer_init(&rb_queue, rb_buffer, MAX_RB_SIZE);

    while(1)
    {
        // read serial data
        memset(uart_buf ,0 ,sizeof (uart_buf));

        uart_length = UartReadHandle(uart_buf, sizeof (uart_buf));
        if(uart_length > 0){
            rt_ringbuffer_put(&rb_queue, uart_buf, uart_length);
            usleep(10*1000);
        }
		else{
            usleep(1000*1000);
        }
    }
}
#else  // 使用如下代码，则开始imu传输功能

void DataCenter::UartRevThread(void)
{
    uint8_t  uart_buf[MAX_CMDLENGTH]; 
    uint16_t uart_length;
	uint8_t  mavlink_buf[MAX_CMDLENGTH]; 
    uint16_t mavlink_length;
    int i;

    rt_ringbuffer_init(&rb_queue, rb_buffer, MAX_RB_SIZE);
	
	CamImuInit();
	
    while(1)
    {
        memset(uart_buf, 0, sizeof(uart_buf));
		uart_length = UartReadHandle(uart_buf, sizeof(uart_buf));
		//printf("uart_length = %d\n", uart_length);
		
		if(uart_length > 0) {
			memset(mavlink_buf, 0, sizeof(mavlink_buf));
			mavlink_length = 0;
			
			CamImuHandle(uart_buf, uart_length, mavlink_buf, &mavlink_length);
			if(mavlink_length > 0){
				rt_ringbuffer_put(&rb_queue, mavlink_buf, mavlink_length);
			}	
		}
		usleep(5*1000);	
    }
}
#endif

#define ARMED_TIME_DURATION 11
void DataCenter::LoggerAnalysisThread(void) 
{
    int i,rb_lenght;
    uint32_t _lastTime, _nowTime;
    int armed_time, init_time, wifi_ack;
    unsigned char buffer[MAX_CMDLENGTH];

    wkcam_process_enable = -1;
    drone_mode = 0;
    armed_time = 0;
    init_time = 0;
    wifi_ack = 0;

    _lastTime = system_timestamp_get();
    mavlink_logger_init();

    while(1)
    {
        rb_lenght = rt_ringbuffer_get(&rb_queue, buffer, MAX_CMDLENGTH);
        for(i = 0;i<rb_lenght;i++){
            mavlink_decode_FCS(buffer[i]);
        }

        _nowTime = system_timestamp_get();
        if(get_delta_time(_nowTime, _lastTime) >= 1)
        {
            //启动一段时间后，再开始记录日志文件
            if(init_time < 6){
                init_time++;
            }

            //判断是否需要发送WiFi配置应答
            if(mWifiConf.set_wifi_config > 0){
                wifi_ack++;
            }

            //判断WiFi模块是否正在设置
            if(mWifiConf.set_wifi_busy > 0){
                mWifiConf.set_wifi_busy--;
            }

            _lastTime = _nowTime;
            mavlink_log_prodic_tasks();
        
            if(FILE_READY_START == file_task && init_time >= 5){
                //倒计时清零
                armed_time = 0;

                //重新创建新的日志文件
                mavlink_log_enable_request_handle(1);
                file_task = FILE_OPENED;
            }
            else if(FILE_READY_CLOSE == file_task){
                if(++armed_time >= ARMED_TIME_DURATION){
                    //倒计时清零
                    armed_time = 0;

                    //闭锁后，倒计时11秒，关闭日志文件，等待重新创建日志文件
                    mavlink_log_file_close();
                    file_task = FILE_READY_START;
                }
            }

            if(wifi_ack > 5){
                wifi_ack = 0;
                mWifiConf.set_wifi_config = WIFI_IN_AP;
                send_wifi_ack(mWifiConf);
            }
        }  

        usleep(11*1000);
    }
}

/**
 * @brief 与地面端通讯 数据接收线程 (UDP接收并串口转发)
 * 
 */
void DataCenter::UdpRecvFcsThread(void)
{
	int nRet = 0;
	int i, j, clen;
	unsigned char buf[1024];

	struct sockaddr_in addr_src;     //local address
    int Sock_recv = 0;
	int nAddrLen = -1;
	char ipaddr[32];

    mavlink_set_proto_version(0,2);
    mavlink_set_proto_version(1,2);
    mavlink_set_proto_version(2,2);

	//============== init udp ==============//
	printf("send addr:192.168.1.21 port:%d\n",UDP_DST_PORT);
    addr_src.sin_family      = AF_INET;
	addr_src.sin_port        = htons(UDP_SRC_PORT);

	while(1)
	{
		if ((Sock_recv = net_create_sock()) < 0){
			printf("Create socket fail\n");
			sleep(1);
			continue;
		}

		if (net_bind_sock(Sock_recv,UDP_SRC_PORT)  < 0 ){
			printf("Bind addr error %d %s\n",errno,strerror(errno));
			net_close_socket(&Sock_recv);
			sleep(1);
			continue;
		}
		printf("Bind datalink addr success Sock_recv[%d]!\n",Sock_recv);

		while(1)
		{
			memset(buf, 0, sizeof(buf));
		    nAddrLen = sizeof(struct sockaddr_in);

			//udp received data
            clen = net_udp_recv(Sock_recv, buf, sizeof(buf), 0, (struct sockaddr *)&addr_src, &nAddrLen);
            if(clen > 0){
                for(i=0;i<clen;i++){
                    UartParseChar(buf[i], &fcs_recv_message);

                    mavlink_decode_GRD(buf[i]);

                    if(FRAME_GRD == fcs_recv_message.msg_type && fcs_recv_message.msg_received){
                        nRet = UartSendHandle(fcs_recv_message.msgbuf, fcs_recv_message.nDataLength+5);
                        if(nRet <= 0){
                            usleep(50*1000);
                        }
                    }
                    else if(FRAME_BEA == fcs_recv_message.msg_type && fcs_recv_message.msg_received){
                        nRet = UartSendHandle(fcs_recv_message.msgbuf, fcs_recv_message.nDataLength+4);
                        if(nRet <= 0){
                            usleep(50*1000);
                        }
                    }
                    else if(FRAME_MAV2 == fcs_recv_message.msg_type && fcs_recv_message.msg_received){
                        nRet = UartSendHandle(fcs_recv_message.msgbuf, fcs_recv_message.nDataLength);
                        if(nRet <= 0){
                            usleep(50*1000);
                        }
                    }
                }
            }
           
            usleep(5*1000);
		}

		net_close_socket(&Sock_recv);
	}
}

/**
 * @brief  与地面端通讯 发送处理函数
 * 
 * @param buf  发送数据
 * @param size 数据长度
 * @return int 返回发送状态
 */
int DataCenter::UdpSendHandle(unsigned char *buf,int size)
{
	int nRet;

    while(Sock_send <= 0)
    {
		addr_dst.sin_family      = AF_INET;
		addr_dst.sin_port        = htons(UDP_DST_PORT);
		addr_dst.sin_addr.s_addr = (unsigned long)inet_addr(UDP_GRD_ADDR);

        if ((Sock_send = net_create_sock()) < 0){
			printf("Create socket fail\n");
			sleep(1);
			continue ;
		}

		if (net_bind_sock(Sock_send,UDP_DST_PORT)  < 0){
			printf("Bind addr error %d %s\n",errno,strerror(errno));
			net_close_socket(&Sock_send);
			sleep(1);
			continue;
		}
        printf("bind datalink addr success Sock_send[%d]! \n",Sock_send);
        break;
    }

    //不充电时，才发送数据
    if(wkcam_process_enable == WK_CHARGE_DISABLE){
       nRet = net_udp_send(Sock_send,buf,size,(struct sockaddr *)&addr_dst);
        if(nRet<0){
            printf("cam udp[%d] send%d,%s\n",Sock_send,errno,strerror(errno));
            usleep(50*1000);
            net_close_socket(&Sock_send);
        }     
    }

	return nRet;
}

/**
 * @brief 进程间通讯 Socket接收线程 (UDP接收并串口转发)
 * 
 */
void DataCenter::CamRecvThread(void)
{
    int nRet;
    int clen;
    int flag;
	unsigned char buf[1024];
    struct sockaddr_un addr_un_local;

    while(1)
    {
        Sock_cam = socket(AF_LOCAL, SOCK_DGRAM, 0);
        if(Sock_cam < 0){
            printf("socket create failed\n");
            sleep(1);
            continue;
        }
    
        addr_un_local.sun_family = AF_LOCAL;
        sprintf(addr_un_local.sun_path, SOCKET_SERVER);
        unlink(SOCKET_SERVER);

        flag = 1;
        nRet = setsockopt(Sock_cam, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
        if(bind(Sock_cam, (struct sockaddr*)&addr_un_local, sizeof(addr_un_local)) < 0){
            close(Sock_cam);
            printf("bind address failed \n");
            sleep(1);
            continue;
        }
        printf("bind datalink addr success Sock_cam[%d]! \n",Sock_cam);
    
        addr_un_remote.sun_family = AF_LOCAL;
        sprintf(addr_un_remote.sun_path, SOCKET_CLIENT);

        //接收数据
        while(1)
        {
            clen = recvfrom(Sock_cam, buf, sizeof(buf), 0, NULL, NULL);
            if(clen > 0) {
				#if 0
				int now_ms = system_time_ms_get();
				static int last_ms = 0;
				static int u32cnt = 0;
				u32cnt++;
				if(get_delta_time(now_ms, last_ms) >= 1000){
					printf("=============== u32cnt = %d, time = %d\n", u32cnt, now_ms-last_ms);
					u32cnt = 0;
					last_ms = now_ms;
				}
				#endif
				
                //printf("recv from camera -->");
                //PrintBuf(buf, clen);
                nRet = UartSendHandle(buf,clen);
                if(nRet <= 0){
                    usleep(5*1000);
                }
            }
            //usleep(5*1000);
        }
    }
}

/**
 * @brief 进程间通讯 Socket发送处理函数
 * 
 * @param buf   发送的数据
 * @param size  数据长度
 * @return int  返回发送状态
 */
int DataCenter::CamSendHandle(unsigned char *buf, int size)
{
    int nRet;

    nRet = sendto(Sock_cam, buf, size, 0, (struct sockaddr*)&addr_un_remote, sizeof(struct sockaddr_un));
}

/**
 * @brief 回传数据处理函数
 * 
 * @param buf 
 * @param size 
 * @return int 
 */
int DataCenter::comm_send_handle(unsigned char *buf, int size)
{
    //发送到遥控器
    UdpSendHandle(buf, size);
}


/**
 * @brief 进程间通讯 Socket创建，传输IMU数据
 * 
 */
int DataCenter::CamImuUnixSocketCreate(void)
{
    int nRet = 0;
    int flag = 0;
    struct sockaddr_un addr_un_local;

    Imu_Sock_cam = socket(AF_LOCAL, SOCK_DGRAM, 0);
    if(Imu_Sock_cam < 0){
        printf("socket create failed\n");
		return -1;
    }

    addr_un_local.sun_family = AF_LOCAL;
    sprintf(addr_un_local.sun_path, SOCKET_IMU_SERVER);
    unlink(SOCKET_IMU_SERVER);

    flag = 1;
    nRet = setsockopt(Imu_Sock_cam, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
    if(bind(Imu_Sock_cam, (struct sockaddr*)&addr_un_local, sizeof(addr_un_local)) < 0){
        close(Imu_Sock_cam);
		Imu_Sock_cam = -1;
        printf("bind address failed \n");
		return -1;
    }
    printf("bind datalink addr success imu_Sock_cam[%d]! \n", Imu_Sock_cam);

    imu_addr_un_remote.sun_family = AF_LOCAL;
    sprintf(imu_addr_un_remote.sun_path, SOCKET_IMU_CLIENT);

	return 0;
}

/**
 * @brief 进程间通讯 Socket发送处理函数,用于发送IMU数据
 * 
 * @param buf   发送的数据
 * @param size  数据长度
 * @return int  返回发送状态
 */
int DataCenter::CamImuSendHandle(uint8_t *buf, uint32_t size)
{
    int nRet;

    nRet = sendto(Imu_Sock_cam, buf, size, 0, (struct sockaddr*)&imu_addr_un_remote, sizeof(struct sockaddr_un));

	return nRet;
}


/**
 * @brief 计算数据校验和
 * 
 * @param data   	数据源
 * @param length 	数据源长度
 * @return     		生成的校验和
 */
uint8_t DataCenter::CamImuDatasum(uint8_t* data, uint8_t length)
{
	unsigned char u8sum = 0;
	if(data == NULL || length <= 0) {
		printf("err: _data is null");
		return 0;
	}

	for(unsigned char ifor=0; ifor<length; ifor++) {
		u8sum += data[ifor];
	}
	
	return u8sum;
}


/**
 * @brief imu相关处理函数：提取分离IMU数据、发送imu数据
 * 
 * @param src_buf   数据源
 * @param src_size  数据源长度
 * @param buf   	imu数据以外的内容
 * @param size  	数据长度 
 * @return int  	0:成功  -1:失败
 */
int DataCenter::CamImuHandle(uint8_t *src_buf, uint16_t src_size, uint8_t other[], uint16_t* out_size)
{
	const uint8_t header_first = 0xAA;
	const uint8_t header_sec = 0x55;
	const uint8_t start_stop_cmd = 0x11;
	const uint8_t sysc_pts_cmd = 0x12;
	const uint8_t imu_data_cmd = 0x21;
	const uint8_t mcu_debug_cmd = 0x22;

	uint8_t* data = NULL;
	uint16_t u32ignore_cnt = 0; 
	uint8_t u8data_len = 0;
	uint8_t u8pack_len = 0;
	uint8_t u8imu_buffer[MAX_CMDLENGTH] = {0};
	uint16_t u32imu_buf_size = 0 ;
	uint16_t other_size = 0;

	if(src_buf == NULL || src_size <= 0) {
		printf("err: Invalid param\n");
		return -1;
	}

	if(other == NULL || out_size == NULL) {
		printf("err: Invalid param\n");
		return -1;
	}

	/* 数据写入读取缓冲区 */
	memcpy(&rw_buffer[u32rw_buf_index], src_buf, src_size);
	u32rw_buf_index += src_size;
	data = &rw_buffer[0];
	
	/* 数据分离 */
	while(data < &rw_buffer[u32rw_buf_index]) 
	{
		/* 判断是否imu协议数据 */
		if(data[0] != header_first || data[1] != header_sec) {
			other[other_size] = *data;
			other_size++;
			u32ignore_cnt++;
			data++;
			continue;
		}

		/* 判断是否接收完 */
		u8data_len = data[2];
		u8pack_len = u8data_len+4;
		if(u8pack_len > (u32rw_buf_index-u32ignore_cnt)) {
			break;
		}

		/* 命令种类是否符合 */
		if(start_stop_cmd != data[3] && sysc_pts_cmd != data[3] && imu_data_cmd != data[3] && mcu_debug_cmd != data[3]) {
			other[other_size] = *data;
			other_size++;
			u32ignore_cnt++;
			data++;
			continue;
		}

		/* 判断校验和 */
		if(CamImuDatasum(&data[2], u8data_len+1) != data[u8pack_len-1]) {
			other[other_size] = *data;
			other_size++;
			u32ignore_cnt++;
			data++;
			printf("imu data cheak sum err\n");
			continue;
		}

		/* 数据存储有效的imu数据 */
		memcpy(&u8imu_buffer[u32imu_buf_size], data, u8pack_len);
		u32imu_buf_size += u8pack_len;
		data += u8pack_len;
		u32ignore_cnt += u8pack_len;
	}

	/* 赋值解析出来非imu数据的大小 */
	*out_size = other_size;

	/* 依据解析结果，去除已解析内容 */
	if(u32ignore_cnt > 0) {
		u32rw_buf_index -= u32ignore_cnt;
		memset(rw_buffer, 0, u32ignore_cnt);
   	 	memmove(rw_buffer, &rw_buffer[u32ignore_cnt], u32rw_buf_index);			
	}

//	 printf("--- other_size = %d, u32imu_buf_size = %d \n", other_size, u32imu_buf_size);
//		if(other_size > 0){
//			for(int ifor=0; ifor<other_size; ifor++){
//				printf("%02x ", other[ifor]);
//			}
//			printf("\n");
//		}
	
//		if(u32imu_buf_size > 0){
//			for(int ifor=0; ifor<u32imu_buf_size; ifor++){
//				printf("%02x ", u8imu_buffer[ifor]);
//			}
//			printf("\n");
//		}


	/* 发送imu数据到相机 */
	CamImuSendHandle(u8imu_buffer, u32imu_buf_size);
	
	return 0;
}

/**
 * @brief datalink中imu相关初始化
 * 
 */
int DataCenter::CamImuInit()
{
	if(Imu_Sock_cam >= 0) {
		printf("info: imu socket is ready started\n");
		return 0;		
	}

	CamImuUnixSocketCreate();

	memset(rw_buffer, 0, sizeof(rw_buffer));
	u32rw_buf_index = 0;

	return 0;
}

int DataCenter::CamImuDeInit()
{
	if(Imu_Sock_cam < 0) {
		return -1;		
	}

	close(Imu_Sock_cam);
	Imu_Sock_cam = -1;
	unlink(SOCKET_IMU_SERVER);

	memset(rw_buffer, 0, sizeof(rw_buffer));
	u32rw_buf_index = 0;

	return 0;
}