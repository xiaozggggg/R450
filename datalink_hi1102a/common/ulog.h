#ifndef _ULOG_H_
#define _ULOG_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* __cplusplus */

enum ULogMessageType
{
    FORMAT = 'F',
    DATA = 'D',
    INFO = 'I',
    INFO_MULTIPLE = 'M',
    PARAMETER = 'P',
    ADD_LOGGED_MSG = 'A',
    REMOVE_LOGGED_MSG = 'R',
    SYNC = 'S',
    DROPOUT = 'O',
    LOGGING = 'L',
    FLAG_BITS = 'B',
};

enum UlogMMessageLevel
{
    ULOG_MSG_LEVEL_EMERG = '0',
    ULOG_MSG_LEVEL_ALERT = '1',
    ULOG_MSG_LEVEL_CRITICAL = '2',
    ULOG_MSG_LEVEL_ERR = '3',
    ULOG_MSG_LEVEL_WARNING = '4',
    ULOG_MSG_LEVEL_NOTICE = '5',
    ULOG_MSG_LEVEL_INFO = '6',
    ULOG_MSG_LEVEL_DEBUG = '7',
};

#pragma pack (1)

typedef struct
{
    uint8_t  magic[8];
    uint64_t timestamp;
} ulog_file_header_s;

#define ULOG_MSG_HEADER_LEN 3
typedef struct
{
    uint16_t msg_size;
    uint8_t  msg_type;
} ulog_message_header_s;

typedef struct
{
    uint16_t msg_size;
    uint8_t  msg_type;
    char     format[2096];
} ulog_message_format_s;

typedef struct
{
    uint16_t msg_size;
    uint8_t  msg_type;
    uint8_t  multi_id;
    uint16_t msg_id;
    char     message_name[255];
} ulog_message_add_logged_s;

typedef struct {
    uint16_t msg_size;
    uint8_t  msg_type;
    uint16_t msg_id;
} ulog_message_remove_logged_s;

typedef struct
{
    uint16_t msg_size;
    uint8_t  msg_type;
    uint8_t  sync_magic[8];
} ulog_message_sync_s;

typedef struct
{
    uint16_t msg_size;
    uint8_t  msg_type;
    uint16_t duration;
} ulog_message_dropout_s;

typedef struct
{
    uint16_t msg_size;
    uint8_t  msg_type;
    uint16_t msg_id;
} ulog_message_data_header_s;

typedef struct
{
    uint16_t msg_size;
    uint8_t  msg_type;
    uint8_t  key_len;
    char     key[255];
} ulog_message_info_header_s;

typedef struct
{
    uint16_t msg_size;
    uint8_t  msg_type ;
    uint8_t  is_continued;
    uint8_t  key_len;
    char     key[255];
} ulog_message_info_multiple_header_s;

typedef struct
{
    uint16_t msg_size;
    uint8_t  msg_type;
    uint8_t  log_level;
    uint64_t timestamp;
    char     message[128];
} ulog_message_logging_s;

typedef struct
{
    uint16_t msg_size;
    uint8_t  msg_type;
    uint8_t  key_len;
    char     key[255];
} ulog_message_parameter_header_s;


#define ULOG_INCOMPAT_FLAG0_DATA_APPENDED_MASK (1<<0)

typedef struct
{
    uint16_t msg_size;
    uint8_t  msg_type;
    uint8_t  compat_flags[8];
    uint8_t  incompat_flags[8];
    uint64_t appended_offsets[3];
} ulog_message_flag_bits_s;

typedef struct
{
    char* data_type;
    char* data_name;
} ULOG_FORMAT_t;

#pragma pack ()

#define LOG_CACHE_TIME 2

typedef struct {
    int seq;
    int length;
    char node_buf[20*1024];
}LOG_CACHE_NODE_S;

typedef struct{
    int NodeCount;
    int curNode;
    int lastNode;
    LOG_CACHE_NODE_S Node[LOG_CACHE_TIME];
}LOG_CACHE_QUEUE_S;

uint16_t LoggerFileInit(char *filename);
void LoggerWrite(void *data, uint16_t size);
void LoggerSync(void);
uint32_t LoggerFileClose(void);

void UlogWriteHeader(void);
void UlogWriteFlag(void);
void UlogWriteFormat(char* formatType, ULOG_FORMAT_t* ulog_format, int16_t dataNum);
void UlogWriteParameters(char *param_name, float param_value);
void UlogWriteAddLogged(char* logType, uint8_t msg_id);

void UlogWriteData_Flight(void *data);
void UlogWriteData_GPS(void *data);
void UlogWriteData_Missions(void *data);
void UlogWriteData_Log_Text(char *buf,  uint64_t timestamp);
void UlogWriteData_Motors(void *data);
void UlogWriteData_RcInput(void *data);
void UlogWriteData_Raw_Sensor(void *data);
void UlogWriteData_Mode(void *data);
void UlogWriteData_PosController(void *data);
void UlogWriteData_ImageGeoData(void *data);
void UlogWriteData_RTKRawData(void *data);
void UlogWriteData_GnssData(void *data);
void UlogWriteData_BeaconData(void *data);

void UlogWriteBatteryInfo(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif


