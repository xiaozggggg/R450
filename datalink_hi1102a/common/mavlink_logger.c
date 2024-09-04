

#include "mavlink_logger.h"
#include "ulog.h"
#include "ulog_data.h"
#include "cJSON.h"
#include "uart.h"

static LOG_FILELIST_E mLogFileList;
static int mCmdUartFd;

int mParamStatus;
int mParamSeqRequest;
int recv_total_size;

int mUartSendState; //串口是否发送标志

bool UartInit(void)
{
    //============== init uart ==============//
    mUartSendState = 0;

	mCmdUartFd = UartOpen(UART3_PATH);
    if(mCmdUartFd == -1){
        printf("UartOpen Failed!\n");
        return false;
    }else{
        if(UartConfig(mCmdUartFd, UART1_BAUD, 8, 1, 'N') != 0){
            printf("UartConfig Failed!\n");
            return false;
        }
    }

    return true;
}

int UartSendHandle(unsigned char *buf, int size)
{
    //正在充电不发送数据给飞控
    if(mCmdUartFd < 0 || mUartSendState == 0){
        return -1;
    }

    return UartWrite(mCmdUartFd, buf, size);
}

int UartReadHandle(unsigned char *buf, int size)
{
    int len;

    if(mCmdUartFd > 0){
        len = read(mCmdUartFd, buf, size);
    }
    else{
        len = 0;
    }

    return len;
}

void setUartSendStatus(int state)
{
    mUartSendState = state;
}

/**
 * @brief 飞控日志文件列表，初始化数据库
 * 
 */
void log_file_list_init(void)
{
    struct stat sbuf;
    char temp_path[60];

    logger_sql_init();
    logger_sql_get_item(0, 0, &mLogFileList);
    printf("[logger init] --> latest fcs index[%d]\n",mLogFileList.fcs_index);

    //更新最新的日志文件大小
    if(mLogFileList.file_size <= 0){
        sprintf(temp_path, "/mnt/%s/%s", LOG_FILE_PATH, mLogFileList.filename);
        if(stat(temp_path, &sbuf) < 0) {
            printf("Get file size failed.\n");
        } else {
            mLogFileList.file_size = (int)sbuf.st_size;
            logger_sql_update_item(LOG_COL_SIZE, &mLogFileList);
        }
        usleep(500*1000);
    }

    //初始化时，生成新的列表Json文件
    mavlink_log_Json_Generate();

    mLogFileList.fix_type = 0;
    memset(mLogFileList.flight_time, 0x00, sizeof(mLogFileList.flight_time));
}

/**
 * @brief 飞行时间更新（单位：秒）
 * 
 */
void mavlink_log_flight_duration_update(void)
{
    mLogFileList.flight_duration += 1;
    if(mLogFileList.flight_duration%3 == 0){
        logger_sql_update_item(LOG_COL_DURATION, &mLogFileList);
    }
}

/**
 * @brief 设置飞机定位状态
 * 
 */
void mavlink_log_fix_type(int type)
{
    mLogFileList.fix_type = type;
}

/**
 * @brief 若日志文件数量超过最大值，则删除一条最旧的记录
 * 
 */
void mavlink_log_delete_file(void)
{
    LOG_FILELIST_E ploglist;
    char del_cmd[60];
    int filecount;

    while(1)
    {
        //获取当前数据库中记录条数
        filecount = logger_sql_get_file_count();
        if(filecount > LOG_LIST_MAX_COUNT){
            printf("[logger delete] --> file count[%d] > LOG_LIST_MAX_COUNT\n",filecount);
            //找到最旧的文件信息
            logger_sql_get_item(1, 0, &ploglist);

            //删除文件
            printf("[logger delete] --> delete file[%s] index[%d]\n", ploglist.filename, ploglist.fcs_index);
            sprintf(del_cmd, "rm /mnt/fcs_log/%s", ploglist.filename);
            system(del_cmd);

            //删除数据库中的记录
            logger_sql_delete_item(ploglist.fcs_index);
        }
        else{
            printf("[logger delete] --> file count < LOG_LIST_MAX_COUNT\n");
            break;
        }
    }
}

/**
 * @brief 清空所有飞控日志文件
 * 
 */
void mavlink_log_file_reset(int index)
{
    if(index == 9527){
        LoggerFileClose();
        printf("[logger reset]:clear all fcs log files\n");

    #if LOG_TO_LOCAL
        system("rm /mnt/fcs_log/*");
    #else
        system("rm /mnt/sdcard/*");
    #endif

        log_file_list_init();
    }
}

/**
 * @brief 相机给飞控的请求 --> 请求飞控参数列表
 * 
 */
void mavlink_send_log_params_request(int paramStartSeq)
{
    mavlink_message_t mavlink_message;
    mavlink_wk_log_params_request_t wk_mavlink_log_params_request;
    
	uint16_t length;
    uint8_t msgbuff[MAVLINK_MAX_PACKET_LEN];

    wk_mavlink_log_params_request.seq = paramStartSeq;
    // printf("[logger param seq request] ack[%d]\n",wk_mavlink_log_params_request.seq);

    mavlink_msg_wk_log_params_request_encode(MAVLINK_SYS_ID, WK_MODULE_TYPE_CAMERA, &mavlink_message, &wk_mavlink_log_params_request);
    length = mavlink_msg_to_send_buffer(msgbuff, &mavlink_message);

    UartSendHandle(msgbuff, length);
}

/**
 * @brief 飞控给相机的请求 --> 开始记录飞控日志处理函数
 * 
 * @param log_index 飞控日志文件的序号
 */
void mavlink_log_enable_request_handle(int index)
{
    char filepath[60];
    int ret;
    int filecount;
    time_t tim;
    struct tm *timenow;
    int tm_year, tm_mon, tm_mday, tm_hour, tm_min, tm_sec;

    //获取时间
    time(&tim);
    timenow = gmtime(&tim);

    tm_year = timenow->tm_year + 1900;
    tm_mon = timenow->tm_mon + 1;
    tm_mday = timenow->tm_mday;
    tm_hour = timenow->tm_hour;
    tm_min = timenow->tm_min;
    tm_sec = timenow->tm_sec;

    //文件信息初始化
    mLogFileList.file_size = 0;
    mLogFileList.flight_duration = 0;
    mLogFileList.fcs_index += 1;
    if(mLogFileList.fix_type >= 3){
        sprintf(mLogFileList.flight_time, "%04d-%02d-%02d-%02d-%02d-%02d", tm_year, tm_mon, tm_mday, tm_hour, tm_min, tm_sec);
    }
    else{
        memset(mLogFileList.flight_time, 0x00, sizeof(mLogFileList.flight_time));
    }

    //根据序号生成文件名
    memset(mLogFileList.filename, 0x00, sizeof(mLogFileList.filename));
    memset(filepath, 0x00, sizeof(filepath));
    sprintf(mLogFileList.filename, "flylog_%08d.ulg", mLogFileList.fcs_index);
    sprintf(filepath, "%s/%s", LOG_FILE_PATH, mLogFileList.filename);
    printf("[logger insert] --> ID[%d] filename[%s] flight_time[%s]\n", mLogFileList.fcs_index, mLogFileList.filename, mLogFileList.flight_time);

    //检查日志文件数量，并删除最旧的文件
    mavlink_log_delete_file();

    //创建文件
    ret = LoggerFileInit(filepath);
    if(ret == 0){
        //文件初始信息写入数据库
        logger_sql_insert_item(&mLogFileList);

        //写入文件头信息
        mavlink_logger_header_init();

        //开始请求飞控参数
        mParamStatus = LOG_PARAMS_READY;
        mavlink_send_log_params_request(0);
    }
}

/**
 * @brief 日志文件关闭并保存相关信息
 * 
 */
void mavlink_log_file_close(void)
{
    struct stat sbuf;
    char sys_cmd[120];
    char temp_path[60];

    //关闭当前日志文件
    LoggerFileClose();

    //获取文件大小
    sprintf(temp_path, "/mnt/%s/%s", LOG_FILE_PATH, mLogFileList.filename);
    if(stat(temp_path, &sbuf) < 0) {
        printf("Get file size failed.\n");
        return;
    } else {
        mLogFileList.file_size = (int)sbuf.st_size;

        //更新文件信息(文件大小/飞行时长/日志时间)，并写入数据库
        logger_sql_update_item(LOG_COL_DURATION, &mLogFileList);
        logger_sql_update_item(LOG_COL_SIZE, &mLogFileList);
    }

    //关闭文件时，生成新的列表Json文件
    mavlink_log_Json_Generate();
}

/**
 * @brief 把数据库中的记录导出到JSON文件
 * 
 */
void mavlink_log_Json_Generate(void)
{
    LOG_FILELIST_E ploglist;
    int i,filecount;
    char *liststr;
    char file_url[80];

    cJSON* cjson_item = NULL;
    cJSON* cjson_summary = NULL;
    cJSON* cjson_list = NULL;
    cJSON* cjson_fileinfo[LOG_LIST_MAX_COUNT] = {NULL};

    cjson_item = cJSON_CreateObject();
    cjson_list = cJSON_CreateArray();

    //获取当前数据库中记录条数
    filecount = logger_sql_get_file_count();
    if(filecount > LOG_LIST_MAX_COUNT){
        filecount = LOG_LIST_MAX_COUNT;
    }
    
    for(i = 0;i < filecount;i++)
    {
        cjson_fileinfo[i] = cJSON_CreateObject();
        memset(&ploglist, 0x00, sizeof(LOG_FILELIST_E));
        logger_sql_get_item(2, mLogFileList.fcs_index-i, &ploglist);

        memset(file_url, 0x00, sizeof(file_url));
        sprintf(file_url, "fcs_log/%s", ploglist.filename);
        // printf("[logger generate] --> get file index[%d] to JSON[%d]\n", mLogFileList.fcs_index-i, i);
        // printf("[logger generate] --> get file name[%s] size[%d]\n", ploglist.filename, ploglist.file_size);

        //配置fileinfo
        cJSON_AddStringToObject(cjson_fileinfo[i], "filename", ploglist.filename);
        cJSON_AddNumberToObject(cjson_fileinfo[i], "filesize", ploglist.file_size);
        cJSON_AddStringToObject(cjson_fileinfo[i], "url",      file_url);
        cJSON_AddStringToObject(cjson_fileinfo[i], "flightTime", ploglist.flight_time);
        cJSON_AddNumberToObject(cjson_fileinfo[i], "flightDuration", ploglist.flight_duration);

        cJSON_AddItemToArray(cjson_list,cjson_fileinfo[i]);
    } 

    //配置summary和list
    cjson_summary = cJSON_CreateObject();
    cJSON_AddNumberToObject(cjson_summary, "file_count", filecount);
    cJSON_AddItemToObject(cjson_item, "summary", cjson_summary);
    cJSON_AddItemToObject(cjson_item, "list", cjson_list);
    liststr = cJSON_Print(cjson_item);
    // printf("%s\n",liststr);

    //保存到文件中
    if(liststr != NULL){
        FILE *f = fopen(LOG_LIST_JSON_FILE,"w+");
        fseek(f,0,SEEK_SET);
        fprintf(f, "%s", liststr);
        fflush(f);
        fdatasync(fileno(f));
        fclose(f);
        free(liststr);
    }

    cJSON_Delete(cjson_item);
}

/**
 * @brief 飞控日志定时任务
 * 
 */
void mavlink_log_prodic_tasks(void)
{
    time_t tim;
    struct tm *timenow;
    int tm_year, tm_mon, tm_mday, tm_hour, tm_min, tm_sec;

    switch(mParamStatus){
    case LOG_PARAMS_READY:
        mavlink_send_log_params_request(0);
        break;

    case LOG_PARAMS_START:
        mavlink_send_log_params_request(mParamSeqRequest);
        break;

    case LOG_SYNC_TIME:
        // printf("[logger sync time] --> [%d] cur flight time --> [%s]\n", mLogFileList.fix_type, mLogFileList.flight_time);
        if(mLogFileList.fix_type >= 3 && strlen(mLogFileList.flight_time) == 0){
            //获取时间
            time(&tim);
            timenow = gmtime(&tim);

            tm_year = timenow->tm_year + 1900;
            tm_mon = timenow->tm_mon + 1;
            tm_mday = timenow->tm_mday;
            tm_hour = timenow->tm_hour;
            tm_min = timenow->tm_min;
            tm_sec = timenow->tm_sec;

            sprintf(mLogFileList.flight_time, "%04d-%02d-%02d-%02d-%02d-%02d", tm_year, tm_mon, tm_mday, tm_hour, tm_min, tm_sec);
            printf("[logger sync time] --> update flight time --> [%s]\n", mLogFileList.flight_time);
            logger_sql_update_item(LOG_COL_FLIGHT_TIME, &mLogFileList);

            mParamStatus = LOG_PARAMS_END;
        }
        break;

    case LOG_PARAMS_END:
        break;

    default:
        break;
    }
}

/**
 * @brief 飞控日志参数列表保存
 * 
 * @param logger_params 
 */
void mavlink_log_params_data_handle(mavlink_wk_log_params_data_t logger_params)
{
    char param_name[16];
    int  i,param_count;
    float param_value;

    param_count = logger_params.param_counts;
    for(i = 0;i < param_count;i++){
        memcpy(param_name,logger_params.param_name+i*16, 16);
        param_value = logger_params.param_value[i];
        UlogWriteParameters(param_name, param_value);
    }

    mParamSeqRequest = logger_params.start_seq + logger_params.param_counts;
    printf("[logger param] --> mParamSeqRequest[%d]\n",mParamSeqRequest);
    if(mParamSeqRequest >= logger_params.total_cnt){
        //接收参数完成后，发送停止指令
        mavlink_send_log_params_request(0xffff);
        if(mLogFileList.fix_type < 3){
            //创建日志时，没有定位，需要等待同步时间
            mParamStatus = LOG_SYNC_TIME;
        }
        else{
            //若已定位，则不需要同步时间
            mParamStatus = LOG_PARAMS_END;
        }
    }
    else{
        //请求下一部分飞控参数
        mParamStatus = LOG_PARAMS_START;
        mavlink_send_log_params_request(mParamSeqRequest);
    }

    // printf("------------------- mavlink_log_params_data_handle!!!\n");
}

void mavlink_log_mode_handle(mavlink_wk_log_mode_t logger_mode)
{
    ULOG_DATA_MODE_t ulog_mode;

    ulog_mode.timestamp = logger_mode.timestamp;
    ulog_mode.mode      = logger_mode.mode;
    ulog_mode.reason    = logger_mode.reason;
    UlogWriteData_Mode(&ulog_mode);

    // printf("------------------- mavlink_log_mode_handle!!!\n");
}

void mavlink_log_flight_state_handle(mavlink_wk_log_flight_state_t logger_flight_state)
{
    ULOG_DATA_FLIGHT_t ulog_flight;

    ulog_flight.timestamp       = logger_flight_state.timestamp;
    ulog_flight.flag_arm        = logger_flight_state.flag_arm;
    ulog_flight.flight_mode     = logger_flight_state.flight_mode;
    ulog_flight.failsafe        = logger_flight_state.failsafe;
    ulog_flight.inav_gps_health = logger_flight_state.inav_health;
    ulog_flight.roll_rate       = logger_flight_state.roll_rate;
    ulog_flight.pitch_rate      = logger_flight_state.pitch_rate;
    ulog_flight.yaw_rate        = logger_flight_state.yaw_rate;
    ulog_flight.roll_rate_sp    = logger_flight_state.roll_rate_sp;
    ulog_flight.pitch_rate_sp   = logger_flight_state.pitch_rate_sp;
    ulog_flight.yaw_rate_sp     = logger_flight_state.yaw_rate_sp;
    ulog_flight.roll            = logger_flight_state.roll;
    ulog_flight.pitch           = logger_flight_state.pitch;
    ulog_flight.yaw             = logger_flight_state.yaw;
    ulog_flight.roll_sp         = logger_flight_state.roll_sp;
    ulog_flight.pitch_sp        = logger_flight_state.pitch_sp;
    ulog_flight.yaw_sp          = logger_flight_state.yaw_sp;
    ulog_flight.time_cnt        = logger_flight_state.time_cnt;
    
    for(int i = 0;i < 3;i++){
        ulog_flight.accel[i]          = logger_flight_state.accel_ef[i]; 
        ulog_flight.velocity[i]       = logger_flight_state.velocity[i];
        ulog_flight.velocity_sp[i]    = logger_flight_state.velocity_sp[i];
        ulog_flight.position[i]       = logger_flight_state.position[i];
        ulog_flight.position_sp[i]    = logger_flight_state.position_sp[i];
        ulog_flight.position_obver[i] = logger_flight_state.position_obver[i];
    }
    UlogWriteData_Flight(&ulog_flight);

    // printf("------------------- mavlink_log_flight_state_handle!!!\n");
}

void mavlink_log_gnss_handle(mavlink_wk_log_gnss_t logger_gnss)
{
    ULOG_DATA_GNSS_t ulog_gnss;

    ulog_gnss.timestamp      = logger_gnss.timestamp;
    ulog_gnss.gnss_detected  = logger_gnss.gnss_detected;
    ulog_gnss.numsv          = logger_gnss.numsv;
    ulog_gnss.fixtype        = logger_gnss.fixtype;
    ulog_gnss.height         = logger_gnss.height;
    ulog_gnss.latitude       = logger_gnss.latitude;
    ulog_gnss.longitude      = logger_gnss.longitude;
    ulog_gnss.updata_flag    = logger_gnss.update_flag;
    ulog_gnss.timegap        = logger_gnss.timegap;
    ulog_gnss.horizontal_acc = logger_gnss.horizontal_acc;
    ulog_gnss.vertical_acc   = logger_gnss.vertical_acc;
    ulog_gnss.velocity_acc   = logger_gnss.velocity_acc;
    ulog_gnss.gps_pos_dop    = logger_gnss.gps_pos_dop;
    ulog_gnss.ground_speed   = logger_gnss.ground_speed;
    ulog_gnss.alt_vel        = logger_gnss.alt_vel;
    ulog_gnss.vel_n          = logger_gnss.vel_n;
    ulog_gnss.vel_e          = logger_gnss.vel_e;
    ulog_gnss.vel_d          = logger_gnss.vel_d;
    ulog_gnss.rtk_yaw        = logger_gnss.rtk_yaw;
    ulog_gnss.rtk_yaw_health = logger_gnss.rtk_yaw_health;
    UlogWriteData_GnssData(&ulog_gnss);

    // printf("------------------- mavlink_log_gnss_handle!!!\n");
}

void mavlink_log_gps_raw_handle(mavlink_wk_log_gps_raw_t logger_gps_raw)
{
    ULOG_DATA_GPS_t ulog_gps;

    ulog_gps.timestamp = logger_gps_raw.timestamp;
    ulog_gps.latitude  = logger_gps_raw.latitude;
    ulog_gps.longitude = logger_gps_raw.longitude;
    ulog_gps.altitude  = logger_gps_raw.altitude;
    ulog_gps.velN      = logger_gps_raw.vel_n;
    ulog_gps.velE      = logger_gps_raw.vel_e;
    ulog_gps.velD      = logger_gps_raw.vel_d;
    ulog_gps.heading   = logger_gps_raw.heading;
    ulog_gps.hAcc      = logger_gps_raw.hAcc;
    ulog_gps.vAcc      = logger_gps_raw.vAcc;
    ulog_gps.sAcc      = logger_gps_raw.sAcc;
    ulog_gps.cAcc      = logger_gps_raw.cAcc;
    ulog_gps.fixStatus = logger_gps_raw.fix_type;
    ulog_gps.numSV     = logger_gps_raw.numSv;
    UlogWriteData_GPS(&ulog_gps);

    // printf("------------------- mavlink_log_gps_raw_handle!!!\n");
}

void mavlink_log_rtk_raw_handle(mavlink_wk_log_rtk_raw_t logger_rtk_raw)
{
    ULOG_DATA_RTK_RAW_t ulog_rtk_raw;

    ulog_rtk_raw.timestamp           = logger_rtk_raw.timestamp;
    ulog_rtk_raw.status              = logger_rtk_raw.status;
    ulog_rtk_raw.num_sats            = logger_rtk_raw.num_sats;
    ulog_rtk_raw.time_week           = logger_rtk_raw.time_week;
    ulog_rtk_raw.time_week_ms        = logger_rtk_raw.time_week_ms;
    ulog_rtk_raw.lat                 = logger_rtk_raw.lat;
    ulog_rtk_raw.lng                 = logger_rtk_raw.lng;
    ulog_rtk_raw.alt                 = logger_rtk_raw.alt;
    ulog_rtk_raw.ground_speed        = logger_rtk_raw.ground_speed;
    ulog_rtk_raw.ground_course       = logger_rtk_raw.ground_course;
    ulog_rtk_raw.hdop                = logger_rtk_raw.hdop;
    ulog_rtk_raw.vdop                = logger_rtk_raw.vdop;
    ulog_rtk_raw.speed_accuracy      = logger_rtk_raw.speed_accuracy;
    ulog_rtk_raw.horizontal_accuracy = logger_rtk_raw.horizontal_accuracy;
    ulog_rtk_raw.vertical_accuracy   = logger_rtk_raw.vertical_accuracy;
    ulog_rtk_raw.diff_age            = logger_rtk_raw.diff_age;
    ulog_rtk_raw.heading             = logger_rtk_raw.heading;
    ulog_rtk_raw.hdg_sd              = logger_rtk_raw.hdg_sd ;
    ulog_rtk_raw.velocity_x          = logger_rtk_raw.velocity_x;
    ulog_rtk_raw.velocity_y          = logger_rtk_raw.velocity_y;
    ulog_rtk_raw.velocity_z          = logger_rtk_raw.velocity_z;
    UlogWriteData_RTKRawData(&ulog_rtk_raw);

    // printf("------------------- mavlink_log_rtk_raw_handle!!!\n");
}

void mavlink_log_beacon_handle(mavlink_wk_log_beacon_t logger_beacon)
{
    ULOG_DATA_BEACON_t ulog_beacon;

    ulog_beacon.timestamp = logger_beacon.timestamp;
    ulog_beacon.numsv     = logger_beacon.numsv;
    ulog_beacon.fixtype   = logger_beacon.fixtype;
    ulog_beacon.latitude  = logger_beacon.latitude;
    ulog_beacon.longitude = logger_beacon.longitude;
    ulog_beacon.alt       = logger_beacon.alt;
    ulog_beacon.velx      = logger_beacon.velx;
    ulog_beacon.vely      = logger_beacon.vely;
    ulog_beacon.velz      = logger_beacon.velz;
    ulog_beacon.yaw       = logger_beacon.yaw;
    ulog_beacon.distance  = logger_beacon.distance;
    UlogWriteData_BeaconData(&ulog_beacon);

    // printf("------------------- mavlink_log_beacon_handle!!!\n");
}

void mavlink_log_motors_handle(mavlink_wk_log_motors_t logger_motors)
{
    ULOG_DATA_MOTORS_t ulog_motors;

    ulog_motors.timestamp   = logger_motors.timestamp;
    ulog_motors.motors[0]   = logger_motors.MOT01;
    ulog_motors.motors[1]   = logger_motors.MOT02;
    ulog_motors.motors[2]   = logger_motors.MOT03;
    ulog_motors.motors[3]   = logger_motors.MOT04;
    ulog_motors.motors[4]   = logger_motors.MOT05;
    ulog_motors.motors[5]   = logger_motors.MOT06;
    ulog_motors.motors[6]   = logger_motors.MOT07;
    ulog_motors.motors[7]   = logger_motors.MOT08;
    ulog_motors.motors[8]   = logger_motors.MOT09;
    ulog_motors.motors[9]   = logger_motors.MOT10;
    ulog_motors.motors[10]  = logger_motors.MOT11;
    ulog_motors.motors[11]  = logger_motors.MOT12;
    UlogWriteData_Motors(&ulog_motors);

    // printf("------------------- mavlink_log_motors_handle!!!\n");
}

void mavlink_log_rc_input_handle(mavlink_wk_log_rcin_t logger_rc_input)
{
    ULOG_DATA_RCIN_t ulog_rc_input;

    ulog_rc_input.timestamp    = logger_rc_input.timestamp;
    ulog_rc_input.update_ms    = logger_rc_input.update_ms;
    ulog_rc_input.chan_val[0]  = logger_rc_input.ch01;
    ulog_rc_input.chan_val[1]  = logger_rc_input.ch02;
    ulog_rc_input.chan_val[2]  = logger_rc_input.ch03;
    ulog_rc_input.chan_val[3]  = logger_rc_input.ch04;
    ulog_rc_input.chan_val[4]  = logger_rc_input.ch05;
    ulog_rc_input.chan_val[5]  = logger_rc_input.ch06;
    ulog_rc_input.chan_val[6]  = logger_rc_input.ch07;
    ulog_rc_input.chan_val[7]  = logger_rc_input.ch08;
    ulog_rc_input.chan_val[8]  = logger_rc_input.ch09;
    ulog_rc_input.chan_val[9]  = logger_rc_input.ch10;
    ulog_rc_input.chan_val[10] = logger_rc_input.ch11;
    ulog_rc_input.chan_val[11] = logger_rc_input.ch12;
    ulog_rc_input.chan_val[12] = logger_rc_input.ch13;
    ulog_rc_input.chan_val[13] = logger_rc_input.ch14;
    ulog_rc_input.chan_val[14] = logger_rc_input.ch15;
    ulog_rc_input.chan_val[15] = logger_rc_input.ch16;
    UlogWriteData_RcInput(&ulog_rc_input);

    // printf("------------------- mavlink_log_rc_input_handle!!!\n");
}

void mavlink_log_sensor_raw_handle(mavlink_wk_log_sensor_raw_t logger_sensor_raw)
{
    int i;
    ULOG_DATA_RAW_SENSOR_t ulog_raw_sensor;

    ulog_raw_sensor.timestamp   = logger_sensor_raw.timestamp;

    for(i=0;i<3;i++){
        ulog_raw_sensor.raw_mag[i] = logger_sensor_raw.imu_raw_mag[i];
        ulog_raw_sensor.raw_mag_ext[i] = logger_sensor_raw.imu_raw_mag_ext[i];
        ulog_raw_sensor.raw_acc[i] = logger_sensor_raw.imu_raw_acc[i];
        ulog_raw_sensor.raw_gyro[i] = logger_sensor_raw.imu_raw_gyro[i];
    }

    ulog_raw_sensor.raw_baro_temperature   = logger_sensor_raw.raw_baro_temperature;
    ulog_raw_sensor.raw_baro_pressure_alt  = logger_sensor_raw.raw_baro_pressure_alt;
    ulog_raw_sensor.raw_baro_alt		   = logger_sensor_raw.raw_baro_alt;
    ulog_raw_sensor.raw_tof_below_alt	   = logger_sensor_raw.raw_tof_below_alt;
    ulog_raw_sensor.raw_tof_front_alt      = logger_sensor_raw.raw_tof_front_alt;
    ulog_raw_sensor.raw_battery_voltage    = logger_sensor_raw.raw_battery_voltage;

    ulog_raw_sensor.fly_time_s_by_current  = logger_sensor_raw.fly_time_s_by_current;
    ulog_raw_sensor.smart_bat_voltage      = logger_sensor_raw.smart_bat_voltage;
    ulog_raw_sensor.smart_bat_current      = logger_sensor_raw.smart_bat_current;
    ulog_raw_sensor.smart_bat_temperature  = logger_sensor_raw.smart_bat_temperature;
    ulog_raw_sensor.smart_bat_capacity_full_charge  = logger_sensor_raw.smart_bat_capacity_full_charge;
    ulog_raw_sensor.smart_bat_capacity_remainng     = logger_sensor_raw.smart_bat_capacity_remainng;
    ulog_raw_sensor.smart_bat_capacity_percen       = logger_sensor_raw.smart_bat_capacity_percen;

    for(i=0;i<12;i++){
        ulog_raw_sensor.smart_bat_cell_voltage[i]   = logger_sensor_raw.smart_bat_cell_voltage[i];
    }

    ulog_raw_sensor.main_mcu_temprature    = logger_sensor_raw.main_mcu_temprature;
    UlogWriteData_Raw_Sensor(&ulog_raw_sensor);

    // printf("------------------- mavlink_log_sensor_raw_handle!!!\n");
}

void mavlink_log_pos_ctrl_handle(mavlink_wk_log_pos_ctrl_t logger_pos_ctrl)
{
    ULOG_DATA_POSCTRL_t ulog_pos_ctrl;

    ulog_pos_ctrl.timestamp       = logger_pos_ctrl.timestamp;
    ulog_pos_ctrl.target_vel_yaw  = logger_pos_ctrl.target_vel_yaw;
    ulog_pos_ctrl.target_yaw_rate = logger_pos_ctrl.target_yaw_rate;
    ulog_pos_ctrl.target_vel_ef_x = logger_pos_ctrl.target_vel_ef_x;
    ulog_pos_ctrl.target_vel_ef_y = logger_pos_ctrl.target_vel_ef_y;
    ulog_pos_ctrl.target_vel_ef_z = logger_pos_ctrl.target_vel_ef_z;
    ulog_pos_ctrl.target_vel_bf_x = logger_pos_ctrl.target_vel_bf_x;
    ulog_pos_ctrl.target_vel_bf_y = logger_pos_ctrl.target_vel_bf_y;
    ulog_pos_ctrl.target_bf_acc_x = logger_pos_ctrl.target_bf_acc_x;
    ulog_pos_ctrl.target_bf_acc_y = logger_pos_ctrl.target_bf_acc_y;
    ulog_pos_ctrl.target_pos_x    = logger_pos_ctrl.target_pos_x;
    ulog_pos_ctrl.target_pos_y    = logger_pos_ctrl.target_pos_y;
    ulog_pos_ctrl.target_pos_z    = logger_pos_ctrl.target_pos_z;
    UlogWriteData_PosController(&ulog_pos_ctrl);

    // printf("------------------- mavlink_log_pos_ctrl_handle!!!\n");
}

void mavlink_log_image_geo_handle(mavlink_wk_log_image_geo_t logger_image_geo)
{
    ULOG_DATA_IMAGE_GEO_t ulog_image_geo;

    ulog_image_geo.timestamp = logger_image_geo.timestamp;
    ulog_image_geo.index     = logger_image_geo.index;
    ulog_image_geo.latitude  = logger_image_geo.latitude;
    ulog_image_geo.longitude = logger_image_geo.longitude;
    ulog_image_geo.altitude  = logger_image_geo.altitude;
    ulog_image_geo.roll      = logger_image_geo.roll;
    ulog_image_geo.pitch     = logger_image_geo.pitch;
    ulog_image_geo.yaw       = logger_image_geo.yaw;
    UlogWriteData_ImageGeoData(&ulog_image_geo);

    // printf("------------------- mavlink_log_image_geo_handle!!!\n");
}

void mavlink_log_mission_handle(mavlink_wk_log_mission_t wk_logger_mission)
{
    ULOG_DATA_MISSION_t ulog_mission_data;
    
    ulog_mission_data.timestamp = wk_logger_mission.timestamp;
    ulog_mission_data.seq = wk_logger_mission.seq;
    ulog_mission_data.latitude = wk_logger_mission.latitude;
    ulog_mission_data.longitude = wk_logger_mission.longitude;
    ulog_mission_data.altitude = wk_logger_mission.altitude;
    UlogWriteData_Missions(&ulog_mission_data);

    // printf("------------------- mavlink_log_mission_handle!!!\n");
}

void mavlink_log_text_handle(mavlink_wk_log_text_t wk_logger_text)
{
    UlogWriteData_Log_Text(wk_logger_text.text, wk_logger_text.timestamp);

    // printf("------------------- mavlink_log_text_handle!!!\n");
}

/*
 * deal with one fcs logger command
 */
bool MavlinkCmdOnDealLogger(mavlink_message_t msg)
{
	if(msg.msgid < 0){
		return false;
	}

	switch(msg.msgid) 
	{
        case MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA:{
            mavlink_wk_log_params_data_t wk_log_params_data;
            mavlink_msg_wk_log_params_data_decode(&msg,&wk_log_params_data);
            mavlink_log_params_data_handle(wk_log_params_data);
            break;}

        case MAVLINK_MSG_ID_WK_LOG_MODE:{
            mavlink_wk_log_mode_t wk_logger_mode;
            mavlink_msg_wk_log_mode_decode(&msg,&wk_logger_mode);
            mavlink_log_mode_handle(wk_logger_mode);
            break;}

        case MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE:{
            mavlink_wk_log_flight_state_t wk_logger_flight_state;
            mavlink_msg_wk_log_flight_state_decode(&msg,&wk_logger_flight_state);
            mavlink_log_flight_state_handle(wk_logger_flight_state);
            break;}

        case MAVLINK_MSG_ID_WK_LOG_GNSS:{
            mavlink_wk_log_gnss_t wk_logger_gnss;
            mavlink_msg_wk_log_gnss_decode(&msg,&wk_logger_gnss);
            mavlink_log_gnss_handle(wk_logger_gnss);
            break;}

        case MAVLINK_MSG_ID_WK_LOG_GPS_RAW:{
            mavlink_wk_log_gps_raw_t wk_logger_gps_raw;
            mavlink_msg_wk_log_gps_raw_decode(&msg,&wk_logger_gps_raw);
            mavlink_log_gps_raw_handle(wk_logger_gps_raw);
            break;}

        case MAVLINK_MSG_ID_WK_LOG_RTK_RAW:{
            mavlink_wk_log_rtk_raw_t wk_logger_rtk_raw;
            mavlink_msg_wk_log_rtk_raw_decode(&msg,&wk_logger_rtk_raw);
            mavlink_log_rtk_raw_handle(wk_logger_rtk_raw);
            break;}

        case MAVLINK_MSG_ID_WK_LOG_BEACON:{
            mavlink_wk_log_beacon_t wk_logger_beacon;
            mavlink_msg_wk_log_beacon_decode(&msg,&wk_logger_beacon);
            mavlink_log_beacon_handle(wk_logger_beacon);
            break;}

        case MAVLINK_MSG_ID_WK_LOG_MISSION:{
            mavlink_wk_log_mission_t wk_logger_mission;
            mavlink_msg_wk_log_mission_decode(&msg,&wk_logger_mission);
            mavlink_log_mission_handle(wk_logger_mission);
            break;}

        case MAVLINK_MSG_ID_WK_LOG_TEXT:{
            mavlink_wk_log_text_t wk_logger_text;
            mavlink_msg_wk_log_text_decode(&msg,&wk_logger_text);
            mavlink_log_text_handle(wk_logger_text);
            break;}

        case MAVLINK_MSG_ID_WK_LOG_MOTORS:{
            mavlink_wk_log_motors_t wk_logger_motors;
            mavlink_msg_wk_log_motors_decode(&msg,&wk_logger_motors);
            mavlink_log_motors_handle(wk_logger_motors);
            break;}

        case MAVLINK_MSG_ID_WK_LOG_RCIN:{
            mavlink_wk_log_rcin_t wk_logger_rc_input;
            mavlink_msg_wk_log_rcin_decode(&msg,&wk_logger_rc_input);
            mavlink_log_rc_input_handle(wk_logger_rc_input);
            break;}

        case MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW:{
            mavlink_wk_log_sensor_raw_t wk_logger_sensor_raw;
            mavlink_msg_wk_log_sensor_raw_decode(&msg,&wk_logger_sensor_raw);
            mavlink_log_sensor_raw_handle(wk_logger_sensor_raw);
            break;}

        case MAVLINK_MSG_ID_WK_LOG_POS_CTRL:{
            mavlink_wk_log_pos_ctrl_t wk_logger_pos_ctrl;
            mavlink_msg_wk_log_pos_ctrl_decode(&msg,&wk_logger_pos_ctrl);
            mavlink_log_pos_ctrl_handle(wk_logger_pos_ctrl);
            break;}

        case MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO:{
            mavlink_wk_log_image_geo_t wk_logger_image_geo;
            mavlink_msg_wk_log_image_geo_decode(&msg,&wk_logger_image_geo);
            mavlink_log_image_geo_handle(wk_logger_image_geo);
            break;}

		default:{
			return false;
			break;}
	}

	return true;
}

/**
 * @brief ulog文件格式头
 * 
 */
void mavlink_logger_header_init(void)
{
    /*写入log头部信息*/
    UlogWriteHeader();

    //数据格式定义
    UlogWriteFormat((char *)"flight", ulog_data_flight, ULOG_DATA_FLIGHT_NUM);
    UlogWriteFormat((char *)"gps_raw", ulog_data_gps, ULOG_DATA_GPS_NUM);
    UlogWriteFormat((char *)"rcin", ulog_data_rcin, ULOG_DATA_RCIN_NUM);
    UlogWriteFormat((char *)"motors", ulog_data_motors, ULOG_DATA_MOTORS_NUM);
    UlogWriteFormat((char *)"mission",ulog_data_mission,ULOG_DATA_MISSION_NUM);
    UlogWriteFormat((char *)"raw_sensor",ulog_data_raw_sensor,ULOG_DATA_RAW_SENSOR_NUM);
    UlogWriteFormat((char *)"mode",ulog_data_mode,ULOG_DATA_MODE_NUM);
    UlogWriteFormat((char *)"pos_ctrl",ulog_data_pos_ctrl,ULOG_DATA_POS_CTRL_NUM);
    UlogWriteFormat((char *)"image_geo",ulog_data_image_geo,ULOG_DATA_IMAGE_GEO_NUM);
    UlogWriteFormat((char *)"rtk_raw", ulog_data_rtk_raw, ULOG_DATA_RTK_RAW_NUM);
    UlogWriteFormat((char *)"gnss_inav", ulog_data_gnss, ULOG_DATA_GNSS_NUM);
    UlogWriteFormat((char *)"beacon",ulog_data_beacon,ULOG_DATA_BEACON_NUM);
    
    //订阅数据
    UlogWriteAddLogged((char *)"flight", ULOG_DATA_FLIGHT_ID);
    UlogWriteAddLogged((char *)"gps_raw", ULOG_DATA_GPS_ID);
    UlogWriteAddLogged((char *)"motors", ULOG_DATA_MOTORS_ID);
    UlogWriteAddLogged((char *)"rcin", ULOG_DATA_RCIN_ID);
    UlogWriteAddLogged((char *)"mission", ULOG_DATA_MISSION_ID);
    UlogWriteAddLogged((char *)"raw_sensor",ULOG_DATA_RAW_SENSOR_ID);
    UlogWriteAddLogged((char *)"mode",ULOG_DATA_MODE_ID);
    UlogWriteAddLogged((char *)"pos_ctrl",ULOG_DATA_POS_CTRL_ID);
    UlogWriteAddLogged((char *)"image_geo",ULOG_DATA_IMAGE_GEO_ID);
    UlogWriteAddLogged((char *)"rtk_raw",ULOG_DATA_RTK_RAW_ID);
    UlogWriteAddLogged((char *)"gnss_inav",ULOG_DATA_GNSS_ID);
    UlogWriteAddLogged((char *)"beacon",ULOG_DATA_BEACON_ID);
}

/**
 * @brief Mavlink飞控日志保存初始化
 * 
 */
void mavlink_logger_init(void)
{
    int ret;

    log_file_list_init();
    mParamStatus = LOG_PARAMS_END;
}

