#ifndef _ULOG_DATA_H_
#define _ULOG_DATA_H_

#include "ulog.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* __cplusplus */

#define ULOG_DATA_RAW_SENSOR_NUM 20
#define ULOG_DATA_FLIGHT_NUM     24
#define ULOG_DATA_GPS_NUM        14
#define ULOG_DATA_MISSION_NUM    5
#define ULOG_DATA_MOTORS_NUM     (12 + 1)
#define ULOG_DATA_RCIN_NUM       18
#define ULOG_DATA_MODE_NUM       3
#define ULOG_DATA_POS_CTRL_NUM   13
#define ULOG_DATA_IMAGE_GEO_NUM  8
#define ULOG_DATA_GNSS_NUM       20
#define ULOG_DATA_RTK_RAW_NUM    21
#define ULOG_DATA_BEACON_NUM     11

#define ULOG_DATA_FLIGHT_ID      0
#define ULOG_DATA_GPS_ID         1
#define ULOG_DATA_MOTORS_ID      2
#define ULOG_DATA_RCIN_ID        3
#define ULOG_DATA_MISSION_ID     4
#define ULOG_DATA_RAW_SENSOR_ID  5
#define ULOG_DATA_MODE_ID        6
#define ULOG_DATA_POS_CTRL_ID    7
#define ULOG_DATA_IMAGE_GEO_ID   8
#define ULOG_DATA_GNSS_ID        9
#define ULOG_DATA_RTK_RAW_ID     10
#define ULOG_DATA_BEACON_ID      11

typedef struct
{
    uint64_t timestamp;
	
	uint8_t flag_arm;
	uint8_t flight_mode;
	uint8_t failsafe;
	uint8_t inav_gps_health;
    uint16_t time_cnt;
    float  roll_rate;
    float  pitch_rate;
    float  yaw_rate;
    float  roll_rate_sp;
    float  pitch_rate_sp;
    float  yaw_rate_sp;
    float  roll;
    float  pitch;
    float  yaw;
    float  roll_sp;
    float  pitch_sp;
    float  yaw_sp;
    float  accel[3];
    float  velocity[3];
    float  velocity_sp[3];
    float  position[3];
    float  position_sp[3];		
    float  position_obver[3];	
} __attribute__((packed)) ULOG_DATA_FLIGHT_t;

typedef struct
{
    uint64_t timestamp;
    float  raw_mag[3];
    float  raw_mag_ext[3];
    float  raw_acc[3];
    float  raw_gyro[3];	
    float  raw_baro_temperature;
    float  raw_baro_pressure_alt;
    float  raw_baro_alt;
    float  raw_tof_below_alt;
    float  raw_tof_front_alt;
    float  raw_battery_voltage;
    
    float  fly_time_s_by_current;
    float  smart_bat_voltage;
    float  smart_bat_current;
    float  smart_bat_temperature;
    float  smart_bat_cell_voltage[12];
    float  smart_bat_capacity_full_charge;
    float  smart_bat_capacity_remainng;
    float  smart_bat_capacity_percen;     
    float  main_mcu_temprature;
} __attribute__((packed)) ULOG_DATA_RAW_SENSOR_t;

typedef struct
{
    uint64_t timestamp;
    int32_t  latitude;	  //纬度
    int32_t	 longitude;   //经度
    int32_t	 altitude;	  //高度
    int32_t	 velN;		  //北向速度
    int32_t	 velE;		  //东向速度
    int32_t	 velD;		  //天向速度
    int16_t  heading;     //航向
    int16_t	 hAcc;		  //水平定位精度
    int16_t  vAcc;        //垂直定位精度
    int16_t  sAcc;        //速度精度
    int16_t  cAcc;        //航向精度
    uint8_t fixStatus;    //定位状态
    uint8_t numSV;		  //卫星数量
} __attribute__((packed)) ULOG_DATA_GPS_t;

typedef struct{
    uint64_t timestamp;
    uint32_t seq;
    int32_t latitude;
    int32_t longitude;
    int32_t altitude;
} __attribute__((packed)) ULOG_DATA_MISSION_t;

typedef struct{
    uint64_t timestamp;
    uint16_t motors[13];
} __attribute__((packed)) ULOG_DATA_MOTORS_t;

typedef struct{
    uint64_t timestamp;
    uint32_t update_ms;
    uint16_t chan_val[16];
} __attribute__((packed))  ULOG_DATA_RCIN_t;

typedef struct{
    uint64_t timestamp;
    uint8_t mode;
    uint8_t reason;
} __attribute__((packed)) ULOG_DATA_MODE_t ;

typedef struct{
    uint64_t timestamp;
    float target_vel_yaw;
    float target_yaw_rate;
    float target_vel_ef_x;
    float target_vel_ef_y;
    float target_vel_ef_z;
    float target_vel_bf_x;
    float target_vel_bf_y;
    float target_bf_acc_x;
    float target_bf_acc_y;
    float target_pos_x;
    float target_pos_y;
    float target_pos_z;
} __attribute__((packed)) ULOG_DATA_POSCTRL_t;


typedef struct{
    uint64_t timestamp;
    uint32_t index;
    int32_t latitude;
    int32_t longitude;
    int32_t altitude;
    int32_t roll;
    int32_t pitch;
    int32_t yaw;
} __attribute__((packed)) ULOG_DATA_IMAGE_GEO_t;


typedef struct{
    uint64_t timestamp;
    uint8_t gnss_detected;
    uint8_t numsv;				
    uint8_t fixtype;					
    float height;  
    int32_t latitude;
    int32_t longitude;
    uint8_t updata_flag;
    float timegap; 
    float horizontal_acc;
    float vertical_acc;
    float velocity_acc;
    float gps_pos_dop;
    float ground_speed;
    float alt_vel;
    float vel_e;
    float vel_n;
    float vel_d;
    float rtk_yaw;
    float rtk_yaw_health;
} __attribute__((packed)) ULOG_DATA_GNSS_t;

typedef struct{
    uint64_t timestamp;
    uint8_t numsv;
    uint8_t fixtype;
    int32_t latitude;
    int32_t longitude;
    int32_t alt;
    float velx;
    float vely;
    float velz;
    float yaw;
    float distance;
} __attribute__((packed)) ULOG_DATA_BEACON_t;

typedef struct{
    uint64_t timestamp;
    // all the following fields must all be filled by the backend driver
    uint8_t status;                  ///< driver fix status
    uint8_t num_sats;                ///< Number of visible satellites 	 
    uint16_t time_week;              ///< GPS week number
    uint32_t time_week_ms;           ///< GPS time (milliseconds from start of GPS week)
    double lat;                      ///< param 3 - Latitude
    double lng;                      ///< param 4 - Longitude
    float alt;                       ///< param 2 - Altitude in centimeters (meters)
    float ground_speed;              ///< ground speed in m/sec
    float ground_course;             ///< ground course in degrees
    uint16_t hdop;                   ///< horizontal dilution of precision in cm
    uint16_t vdop;                   ///< vertical dilution of precision in cm
    float speed_accuracy;
    float horizontal_accuracy;
    float vertical_accuracy;
    uint32_t diff_age;
    float heading;
    float hdg_sd;
    float velocity_x;                ///< 3D velocitiy in m/s, in NED format
    float velocity_y;
    float velocity_z;
}__attribute__((packed)) ULOG_DATA_RTK_RAW_t;;

extern ULOG_FORMAT_t ulog_data_mission[ULOG_DATA_MISSION_NUM];
extern ULOG_FORMAT_t ulog_data_flight[ULOG_DATA_FLIGHT_NUM];
extern ULOG_FORMAT_t ulog_data_gps[ULOG_DATA_GPS_NUM];
extern ULOG_FORMAT_t ulog_data_motors[ULOG_DATA_MOTORS_NUM];
extern ULOG_FORMAT_t ulog_data_rcin[ULOG_DATA_RCIN_NUM];
extern ULOG_FORMAT_t ulog_data_raw_sensor[ULOG_DATA_RAW_SENSOR_NUM];
extern ULOG_FORMAT_t ulog_data_mode[ULOG_DATA_MODE_NUM];
extern ULOG_FORMAT_t ulog_data_pos_ctrl[ULOG_DATA_POS_CTRL_NUM];
extern ULOG_FORMAT_t ulog_data_image_geo[ULOG_DATA_IMAGE_GEO_NUM];
extern ULOG_FORMAT_t ulog_data_rtk_raw[ULOG_DATA_RTK_RAW_NUM];
extern ULOG_FORMAT_t ulog_data_gnss[ULOG_DATA_GNSS_NUM];
extern ULOG_FORMAT_t ulog_data_beacon[ULOG_DATA_BEACON_NUM];

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif


