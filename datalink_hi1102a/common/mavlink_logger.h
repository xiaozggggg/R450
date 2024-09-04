
#ifndef __MAVLINK_LOGGER_H__
#define __MAVLINK_LOGGER_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <math.h>

#include "mavlink/walkera/mavlink.h"
#include "mavlink/ardupilotmega/ardupilotmega.h"
#include "logger_sql.h"

#define LOG_TO_LOCAL 1

#if LOG_TO_LOCAL
#define LOG_LIST_FILE_GET_CMD "ls /mnt/fcs_log | grep fly"
#define LOG_LIST_JSON_FILE    "/mnt/fcs_log/flight_log_list.json"
#define LOG_FILE_PATH         "fcs_log"
#define LOG_LIST_MAX_COUNT    10
#else
#define LOG_LIST_FILE_GET_CMD "ls /mnt/sdcard | grep fly"
#define LOG_LIST_JSON_FILE    "/mnt/sdcard/flight_log_list.json"
#define LOG_FILE_PATH         "sdcard"
#define LOG_LIST_MAX_COUNT    10
#endif

#define MAVLINK_SYS_ID        100
#define WK_MODULE_TYPE_CAMERA 210

//===== uart config ====//
#define UART3_PATH 		"/dev/ttyAMA3"
#define UART1_BAUD      1000000 //500000 //500000  //230400 //115200

typedef enum{
    LOG_PARAMS_READY = 0,
    LOG_PARAMS_START,
    LOG_PARAMS_END,
    LOG_SYNC_TIME
}LOG_PARAMS_E;

bool UartInit(void);
int UartSendHandle(unsigned char *buf, int size);
int UartReadHandle(unsigned char *buf, int size);
void setUartSendStatus(int state);

void mavlink_logger_init(void);
void mavlink_logger_header_init(void);
bool MavlinkCmdOnDealLogger(mavlink_message_t msg);
void mavlink_log_prodic_tasks(void);
void mavlink_log_enable_request_handle(int index);
void mavlink_send_log_params_request(int paramStartSeq);
void mavlink_log_file_reset(int index);

void mavlink_log_Json_Generate(void);
void mavlink_log_flight_duration_update(void);
void mavlink_log_fix_type(int type);
void mavlink_log_file_close(void);

#endif

