/**********************************************************************************************************
                                天穹飞控 —— 致力于打造中国最好的多旋翼开源飞控
                                Github: github.com/loveuav/BlueSkyFlightControl
                                技术讨论：bbs.loveuav.com/forum-68-1.html
 * @文件     ulog.c
 * @说明     ulog日志
 * @版本  	 V1.0
 * @作者     BlueSky
 * @网站     bbs.loveuav.com
 * @日期     2018.08
**********************************************************************************************************/

#include "ulog.h"
#include "ulog_data.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* __cplusplus */

#define DEBUG_SAVE_TMP 0

#if DEBUG_SAVE_TMP
FILE *loggertmpfp = NULL;
#endif

static LOG_CACHE_QUEUE_S mLogCache;
bool bWriteCacheFlag;

FILE *loggerfp = NULL;
static uint32_t LogTotalSize = 0;

/**********************************************************************************************************
*函 数 名: LoggerFileInit
*功能说明: 打开/创建日志文件
*形    参: 无
*返 回 值: 0:成功 -1:失败
**********************************************************************************************************/
uint16_t LoggerFileInit(char *filename)
{	 
    char filepath[50];
    uint16_t ret;
     
    //打开/创建日志文件
    sprintf(filepath, "/mnt/%s", filename);
    printf("create fcs_log file --> [%s]!\n",filepath);

    if(NULL != loggerfp){
        fclose(loggerfp);
        loggerfp = NULL;
    }

    loggerfp = fopen(filepath, "w+");
    if(NULL != loggerfp){
        fseek(loggerfp ,0 ,SEEK_SET);	
        ret = 0;				
    }
    else{
        ret = -1;
    }
    LogTotalSize = 0;

    bWriteCacheFlag = false;

    return ret;
}

/**********************************************************************************************************
*函 数 名: LoggerWrite
*功能说明: 往打开的日志文件里写入数据
*形    参: 数据指针 数据长度
*返 回 值: 无
**********************************************************************************************************/
void LoggerWrite(void *data, uint16_t size)
{	 
    if(NULL != loggerfp){
        LogTotalSize += fwrite(data, 1, size, loggerfp);
        // fflush(loggerfp);
    }
}

void LoggerSync(void)
{
    if(NULL != loggerfp){
        fflush(loggerfp);
    }
}

/**********************************************************************************************************
*函 数 名: LoggerFileClose
*功能说明: 关闭日志文件
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
uint32_t LoggerFileClose(void)
{
    if(NULL != loggerfp){
        fclose(loggerfp);
        loggerfp = NULL;

        printf("close fcs_log file, file size[%d] !\n",LogTotalSize);
        return LogTotalSize;
    }
    else{
        return 0;
    }
}

/**********************************************************************************************************
*函 数 名: UlogWriteHeader
*功能说明: ulog写入日志固定头部信息
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteHeader(void)
{
    ulog_file_header_s  header;
    header.magic[0] = 'U';
    header.magic[1] = 'L';
    header.magic[2] = 'o';
    header.magic[3] = 'g';
    header.magic[4] = 0x01;
    header.magic[5] = 0x12;
    header.magic[6] = 0x35;
    header.magic[7] = 0x01; //版本1
    header.timestamp = 0;//sys_time_us_64
    LoggerWrite(&header, sizeof(header));
}

/**********************************************************************************************************
*函 数 名: UlogWriteFlag
*功能说明: ulog写入Flag
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteFlag(void)
{
    ulog_message_flag_bits_s flag;
    memset(&flag, 0, sizeof(flag));
    flag.msg_size = 40;
    flag.msg_type = FLAG_BITS;
    LoggerWrite(&flag, sizeof(flag));
}

/**********************************************************************************************************
*函 数 名: UlogWriteFormat
*功能说明: ulog写入数据格式定义
*形    参: 格式类型 格式内容指针 格式内容数量
*返 回 值: 无
**********************************************************************************************************/
static ulog_message_format_s format;
void UlogWriteFormat(char* formatType, ULOG_FORMAT_t* ulog_format, int16_t dataNum)
{
    uint16_t dataCnt = 0;

    memset(&format, 0, sizeof(format));

    format.msg_size           = 0;
    format.msg_type           = FORMAT;
    for(uint8_t i=0; *(formatType + i) != '\0' ; i++)
    {
        format.format[dataCnt++] = *(formatType + i);
    }
    format.format[dataCnt++]  = ':';
    for(uint8_t i=0; i<dataNum; i++)
    {
        //写入数据类型
        memcpy(format.format+dataCnt, ulog_format[i].data_type, strlen(ulog_format[i].data_type));
        dataCnt += strlen(ulog_format[i].data_type);
        //数据类型与数据名称之间增加空格
        format.format[dataCnt++]  = ' ';
        //写入数据名称
        memcpy(format.format+dataCnt, ulog_format[i].data_name, strlen(ulog_format[i].data_name));
        dataCnt += strlen(ulog_format[i].data_name);
        //增加分号作为分隔符
        format.format[dataCnt++]  = ';';
    }
    format.msg_size = dataCnt;
    LoggerWrite(&format, dataCnt+3);
}

/**********************************************************************************************************
*函 数 名: UlogWriteParameters
*功能说明: ulog写入参数
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteParameters(char *param_name, float param_value)
{
    ulog_message_parameter_header_s msg;
    size_t value_size = sizeof(float);
    size_t msg_size;

    memset(&msg,0,sizeof(msg));

    msg.msg_size = 0;
    msg.msg_type = PARAMETER;

    // format parameter key (type and name)
    msg.key_len = snprintf(msg.key,sizeof(msg.key),"%s %s","float",param_name);

    msg_size = sizeof(msg) - sizeof(msg.key) + msg.key_len + value_size;

    // copy parameter value directly to buffer
    float value = param_value;
    memcpy(&msg.key[msg.key_len],(float *)&value,value_size);

    msg.msg_size = msg_size - ULOG_MSG_HEADER_LEN;

    LoggerWrite(&msg,msg_size);
}


/**********************************************************************************************************
*函 数 名: UlogWriteData_Missions
*功能说明: ulog写入航线
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteData_Missions(void *data)
{
    ULOG_DATA_MISSION_t *ulog_mission;
    ulog_message_logging_s msg;
    uint16_t length;
    
    ulog_mission = (ULOG_DATA_MISSION_t *)data;
    msg.log_level = '6';//informational log level
    msg.msg_type = LOGGING;
    msg.timestamp = ulog_mission->timestamp;
 
    sprintf(msg.message,"MIS_CMD:%04d-WAYPOINT:Lat=%d,Lng=%d,Alt=%d",
            ulog_mission->seq, ulog_mission->latitude, ulog_mission->longitude, ulog_mission->altitude);
    
    length = strlen(msg.message);

    msg.msg_size = length + 9;// message + log_level(1 byte) + timestamp(8bytes)
    LoggerWrite(&msg, msg.msg_size + 3);//msg_size + msg_type
}

/**********************************************************************************************************
*函 数 名: UlogWriteData_Missions
*功能说明: ulog写入航线
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteData_Log_Text(char *buf,  uint64_t timestamp)
{
    ulog_message_logging_s  msg;
    uint16_t length;

    length = strlen(buf);
    
    msg.log_level = '6';//informational log level
    msg.msg_type = LOGGING;
    msg.timestamp = timestamp;
    memcpy(msg.message, buf, length);
        
    msg.msg_size = length + 9;// message + log_level(1 byte) + timestamp(8bytes)
    LoggerWrite(&msg, msg.msg_size + 3);//msg_size + msg_type
}


/**********************************************************************************************************
*函 数 名: UlogWriteBatteryInfo
*功能说明: UlogWriteBatteryInfo
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteBatteryInfo(void)
{
    // char str[64];
    // static uint8_t battery_write_flat = 0;
    
    // if (smbus_data.got_sw_ver && smbus_data.got_sn_code && battery_write_flat == 0)
    // {
    //     char sw_ver[13]={0};
    //     sprintf(sw_ver,"%01d.%01d.%01d",smbus_data.sw_ver/1000%10,(smbus_data.sw_ver/100)%10,smbus_data.sw_ver%10);
    //     sprintf(str,"BATTERY SN:%s SW_VER:%s CYC_CNT:%d",smbus_data.serial_number,sw_ver,smbus_data.cycle_count);
    //     LogWriteSysLog(str);
        
    //     battery_write_flat = 1;
    // }
}

/**********************************************************************************************************
*函 数 名: UlogWriteAddLogged
*功能说明: ulog写入AddLogged
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteAddLogged(char* logType, uint8_t msg_id)
{
    ulog_message_add_logged_s add_logged;
    uint16_t dataCnt = 0;

    memset(&add_logged, 0, sizeof(add_logged));

    add_logged.msg_size = 0;
    add_logged.msg_type = ADD_LOGGED_MSG;
    add_logged.multi_id = 0;
    add_logged.msg_id   = msg_id;

    for(uint8_t i=0; *(logType + i) != '\0' ; i++)
    {
        add_logged.message_name[dataCnt++] = *(logType + i);
    }
    add_logged.msg_size = 3 + dataCnt;
    LoggerWrite(&add_logged, add_logged.msg_size+3);
}

/**********************************************************************************************************
*函 数 名: UlogWriteData_Flight
*功能说明: ulog写入数据
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteData_Flight(void *data)
{
    ulog_message_data_header_s header;

    header.msg_size = sizeof(ULOG_DATA_FLIGHT_t) + 2; //消息ID长度包括在内
    header.msg_type = DATA;
    header.msg_id   = ULOG_DATA_FLIGHT_ID;

    uint8_t date_to_file[sizeof(header)+sizeof(ULOG_DATA_FLIGHT_t)];  
    memcpy(date_to_file, &header, sizeof(header));
    memcpy(date_to_file+sizeof(header), data, sizeof(ULOG_DATA_FLIGHT_t));       
    LoggerWrite(date_to_file, sizeof(header)+sizeof(ULOG_DATA_FLIGHT_t));
}

/**********************************************************************************************************
*函 数 名: UlogWriteData_GPS
*功能说明: ulog写入数据
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteData_GPS(void *data)
{
    ulog_message_data_header_s header;

    header.msg_size = sizeof(ULOG_DATA_GPS_t) + 2; //消息ID长度包括在内
    header.msg_type = DATA;
    header.msg_id   = ULOG_DATA_GPS_ID;

    uint8_t date_to_file[sizeof(header)+sizeof(ULOG_DATA_GPS_t)];  
    memcpy(date_to_file, &header, sizeof(header));
    memcpy(date_to_file+sizeof(header), data, sizeof(ULOG_DATA_GPS_t));       
    LoggerWrite(date_to_file, sizeof(header)+sizeof(ULOG_DATA_GPS_t));
}


/**********************************************************************************************************
*函 数 名: UlogWriteData_Motors
*功能说明: ulog写入电机输出
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteData_Motors(void *data)
{
    ulog_message_data_header_s header;

    header.msg_size = sizeof(ULOG_DATA_MOTORS_t) + 2; //消息ID长度包括在内
    header.msg_type = DATA;
    header.msg_id   = ULOG_DATA_MOTORS_ID;
    
    uint8_t date_to_file[sizeof(header)+sizeof(ULOG_DATA_MOTORS_t)];  
    memcpy(date_to_file, &header, sizeof(header));
    memcpy(date_to_file+sizeof(header), data, sizeof(ULOG_DATA_MOTORS_t));       
    LoggerWrite(date_to_file, sizeof(header)+sizeof(ULOG_DATA_MOTORS_t));
}


/**********************************************************************************************************
*函 数 名: UlogWriteData_RcInput
*功能说明: ulog写入遥控输入
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteData_RcInput(void *data)
{
    ulog_message_data_header_s header;

    header.msg_size = sizeof(ULOG_DATA_RCIN_t) + 2; //消息ID长度包括在内
    header.msg_type = DATA;
    header.msg_id   = ULOG_DATA_RCIN_ID;

    uint8_t date_to_file[sizeof(header)+sizeof(ULOG_DATA_RCIN_t)];  
    memcpy(date_to_file, &header, sizeof(header));
    memcpy(date_to_file+sizeof(header), data, sizeof(ULOG_DATA_RCIN_t));       
    LoggerWrite(date_to_file, sizeof(header)+sizeof(ULOG_DATA_RCIN_t));
}

/**********************************************************************************************************
*函 数 名: UlogWriteData_Raw_Sensor
*功能说明: ulog写入遥控输入
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteData_Raw_Sensor(void *data)
{
    ulog_message_data_header_s header;

    header.msg_size = sizeof(ULOG_DATA_RAW_SENSOR_t) + 2; //消息ID长度包括在内
    header.msg_type = DATA;
    header.msg_id   = ULOG_DATA_RAW_SENSOR_ID;
  
    uint8_t date_to_file[sizeof(header)+sizeof(ULOG_DATA_RAW_SENSOR_t)];  
    memcpy(date_to_file, &header, sizeof(header));
    memcpy(date_to_file+sizeof(header), data, sizeof(ULOG_DATA_RAW_SENSOR_t));       
    LoggerWrite(date_to_file, sizeof(header)+sizeof(ULOG_DATA_RAW_SENSOR_t));
}


/**********************************************************************************************************
*函 数 名: UlogWriteData_Mode
*功能说明: ulog写入模式数据
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteData_Mode(void *data)
{
    ulog_message_data_header_s header;

    header.msg_size = sizeof(ULOG_DATA_MODE_t) + 2; //消息ID长度包括在内
    header.msg_type = DATA;
    header.msg_id   = ULOG_DATA_MODE_ID;

    uint8_t date_to_file[sizeof(header)+sizeof(ULOG_DATA_MODE_t)];  
    memcpy(date_to_file, &header, sizeof(header));
    memcpy(date_to_file+sizeof(header), data, sizeof(ULOG_DATA_MODE_t));       
    LoggerWrite(date_to_file, sizeof(header)+sizeof(ULOG_DATA_MODE_t));
}


/**********************************************************************************************************
*函 数 名: UlogWriteData_PosController
*功能说明: ulog写入位置控制器内部数据
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteData_PosController(void *data)
{
    ulog_message_data_header_s header;

    header.msg_size = sizeof(ULOG_DATA_POSCTRL_t) + 2; //消息ID长度包括在内
    header.msg_type = DATA;
    header.msg_id   = ULOG_DATA_POS_CTRL_ID;
    
    uint8_t date_to_file[sizeof(header)+sizeof(ULOG_DATA_POSCTRL_t)];  
    memcpy(date_to_file, &header, sizeof(header));
    memcpy(date_to_file+sizeof(header), data, sizeof(ULOG_DATA_POSCTRL_t));       
    LoggerWrite(date_to_file, sizeof(header)+sizeof(ULOG_DATA_POSCTRL_t));
}


/**********************************************************************************************************
*函 数 名: UlogWriteData_ImageGeoData
*功能说明: ulog写入航测照片地理数据
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteData_ImageGeoData(void *data)
{
    ulog_message_data_header_s header;

    header.msg_size = sizeof(ULOG_DATA_IMAGE_GEO_t) + 2; //消息ID长度包括在内
    header.msg_type = DATA;
    header.msg_id   = ULOG_DATA_IMAGE_GEO_ID;
    
    uint8_t date_to_file[sizeof(header)+sizeof(ULOG_DATA_IMAGE_GEO_t)];  
    memcpy(date_to_file, &header, sizeof(header));
    memcpy(date_to_file+sizeof(header), data, sizeof(ULOG_DATA_IMAGE_GEO_t));       
    LoggerWrite(date_to_file, sizeof(header)+sizeof(ULOG_DATA_IMAGE_GEO_t));
}


/**********************************************************************************************************
*函 数 名: UlogWriteData_RTKRawData
*功能说明: ulog写入RTK原始数据
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteData_RTKRawData(void *data)
{
    ulog_message_data_header_s header;

    header.msg_size = sizeof(ULOG_DATA_RTK_RAW_t) + 2; //消息ID长度包括在内
    header.msg_type = DATA;
    header.msg_id   = ULOG_DATA_RTK_RAW_ID;

    uint8_t date_to_file[sizeof(header)+sizeof(ULOG_DATA_RTK_RAW_t)];  
    memcpy(date_to_file, &header, sizeof(header));
    memcpy(date_to_file+sizeof(header), data, sizeof(ULOG_DATA_RTK_RAW_t));       
    LoggerWrite(date_to_file, sizeof(header)+sizeof(ULOG_DATA_RTK_RAW_t));
}


/**********************************************************************************************************
*函 数 名: UlogWriteData_GnssData
*功能说明: ulog写入GNSS观测数据
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteData_GnssData(void *data)
{
    ulog_message_data_header_s header;

    header.msg_size = sizeof(ULOG_DATA_GNSS_t) + 2; //消息ID长度包括在内
    header.msg_type = DATA;
    header.msg_id   = ULOG_DATA_GNSS_ID;
    
    uint8_t date_to_file[sizeof(header)+sizeof(ULOG_DATA_GNSS_t)];  
    memcpy(date_to_file, &header, sizeof(header));
    memcpy(date_to_file+sizeof(header), data, sizeof(ULOG_DATA_GNSS_t));       
    LoggerWrite(date_to_file, sizeof(header)+sizeof(ULOG_DATA_GNSS_t));
}


/**********************************************************************************************************
*函 数 名: UlogWriteData_BeaconData
*功能说明: ulog写入信标数据
*形    参: 无
*返 回 值: 无
**********************************************************************************************************/
void UlogWriteData_BeaconData(void * data)
{
    ulog_message_data_header_s header;
    
    header.msg_size = sizeof(ULOG_DATA_BEACON_t) + 2; //消息ID长度包括在内
    header.msg_type = DATA;
    header.msg_id   = ULOG_DATA_BEACON_ID;
    
    uint8_t date_to_file[sizeof(header)+sizeof(ULOG_DATA_BEACON_t)];  
    memcpy(date_to_file, &header, sizeof(header));
    memcpy(date_to_file+sizeof(header), data, sizeof(ULOG_DATA_BEACON_t));       
    LoggerWrite(date_to_file, sizeof(header)+sizeof(ULOG_DATA_BEACON_t));
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

