

#ifndef __MAVLINK_COMMON_H__
#define __MAVLINK_COMMON_H__

#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>
#include <sys/vfs.h>
#include <pthread.h>
#include <dirent.h>
#include <string.h>
#include <sys/mount.h>
#include <sys/time.h>
#include <walkera/mavlink.h>
#include <ardupilotmega/ardupilotmega.h>

//capture params supplement
#define WKCAM_CAP_MODE_DELAY 3
#define WKCAM_CAP_MODE_SCHEDULE 4

//record status supplement
#define WKCAM_VIDEOREC_ACK_STOP_SUCCESS 5
#define WKCAM_VIDEOREC_ACK_STOP_FAIL 6
#define WKCAM_VIDEOREC_ING_SDCARD_FULL 7
#define WKCAM_VIDEOREC_ING_MP4_TOO_LARGE 8

#define WKCAM_PREVIEW_RESOLUTION_1080P_1M 2

#define MAVLINK_SYS_ID 100
#define WK_MODULE_TYPE_CAMERA 210
#define MAVLINK_TARGET_GND 1
#define MAVLINK_TARGET_CAM 2

#define LOG_LIST_PATH      "/mnt/fcs_log/flight_log_list.json"
#define HIGH_FRAME_RATE    60

#define WKCAM_RECORD_BITRATE_50M   4
#define WKCAM_RECORD_BITRATE_100M  5

enum{
    UPGRADE_STATE_IDLE = 0,
    UPGRADE_STATE_WAIT_FW_INFO,
    UPGRADE_STATE_DATA,
    UPGRADE_STATE_WAIT_END_ACK,
};

typedef enum{
	FILESYSTEM_TYPE_NULL = -1,
	FILESYSTEM_TYPE_EXT = 0,
	FILESYSTEM_TYPE_NTFS = 1,
	FILESYSTEM_TYPE_FAT = 2,
	FILESYSTEM_TYPE_UNKNOW = 3,
}FILESYSTEM_TYPE_E;

typedef enum{
    RECORD_STATUS_ERR = 0,
    RECORD_STATUS_DONE,
    RECORD_STATUS_START ,
    RECORD_STATUS_ING ,
    RECORD_STATUS_STOP,
} CAMERA_RECORD_STATUS_E;

typedef struct {
    unsigned int  year;
    unsigned int  month;
    unsigned int  date;
    unsigned int  hour;
    unsigned int  minute;
    unsigned int  second;
    unsigned int  weekday;
}CAM_TIME_T;

typedef struct {
    FILESYSTEM_TYPE_E fs_type;    //sd_filesytem
    unsigned char sdcard_status;  //sd_status
    unsigned long long totalsize; //sd_totalsize
	unsigned long long freeDisk;  //sd_freesize
    unsigned char record_status;  //record_status
    unsigned int record_time;     //record_time
}CAM_STATUS_T;

typedef struct {
    unsigned char   CapMode;      //拍照模式 1为单拍2为连拍
    unsigned char   CapContinue;  //连拍张数
    unsigned char   CapSave;      //图片储存格式1为JPG;2为RAW;3为JPG/RAW
    unsigned char   CapResolution;//图像分辩率1为8M;2为12M;3为16M
    unsigned char   CapRation;    //图像比例 1为4:3;2为16:9
}CAM_PHOTO_PARAM_T;

typedef struct{
    bool cmd_recv;
    unsigned char cap_type;
    unsigned char cap_mode;
    unsigned char cap_continute;
    unsigned char cap_sub_type;

    uint32_t trig_timestamps;
    int32_t longitude;
    int32_t latitude;
    int32_t altitude;
    
    float roll;
    float pitch;
    float yaw;

    float gimbal_roll;
    float gimbal_pitch;
    float gimbal_yaw;
}__attribute__((packed)) CMD_PHOTO_T;

typedef struct {
    bool cmd_recv;

    uint32_t trig_timestamps;
    uint8_t cmd;

    uint32_t sampling_time;
    uint32_t frame_rate;
    uint32_t sampling_total_time;
    uint32_t sampling_sub_type;
}__attribute__((packed)) CMD_RECORD_T;

typedef struct{
     uint8_t dev_type; /*<  device_type*/
     uint32_t dev_id; /*<  device id*/
     uint32_t sw_ver; /*<  software version*/
     uint32_t hw_ver; /*<  hardware version*/
     uint32_t length; /*<  firmware length*/
     uint32_t crc32;  /*<  crc32 value*/
     uint32_t total_fragments; /*<  total fragment numbers*/
}__attribute((packed)) firmware_info_t;


void mavlink_init(void);
void mavlink_decode(unsigned char byte);
bool MavlinkCmdOnDealDate(int id ,char *MessageBuf);
void mavlink_prodic_tasks(void);
void mavlink_camera_prodic_task(void);
void mavlink_sdcard_format_prodic_task(void);

void mavlink_set_camera_status_result(CAM_STATUS_T camStatus);
void mavlink_set_sdcard_status(uint8_t status);
void mavlink_set_time_lapse_status(uint32_t time, uint8_t status);
void mavlink_set_takephoto_result(uint8_t result, uint32_t timestamp, uint32_t timing_tm);
void mavlink_set_video_rev_result(uint8_t result,uint32_t timestamp);
void mavlink_set_video_rev_switch_status(uint8_t status);

void mavlink_send_wkcam_params(void);
void mavlink_send_wkcam_status(void);
void mavlink_send_wkcam_version(void);
void mavlink_send_takephoto_result(void);
void mavlink_send_takephoto_result2(void);
void mavlink_send_video_rec_result(void);

#endif /* __MAVLINK_COMMON_H__ */


