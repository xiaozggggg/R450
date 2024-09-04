/**********************************************************************************************************
                                天穹飞控 —— 致力于打造中国最好的多旋翼开源飞控
                                Github: github.com/loveuav/BlueSkyFlightControl
                                技术讨论：bbs.loveuav.com/forum-68-1.html
 * @文件     ulog_data.c
 * @说明     ulog数据格式定义
 * @版本  	 V1.0
 * @作者     BlueSky
 * @网站     bbs.loveuav.com
 * @日期     2018.08
**********************************************************************************************************/

#include "ulog_data.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"
{
#endif
#endif /* __cplusplus */

ULOG_FORMAT_t ulog_data_mission[ULOG_DATA_MISSION_NUM] = 
{
    {
        .data_type = "uint64_t",
        .data_name = "timestamp"
    },	
    {
        .data_type = "uint32_t",
        .data_name = "seq"
    },
    {
        .data_type = "int32_t",
        .data_name = "latitude"
    },
    {
        .data_type = "int32_t",
        .data_name = "longitude"
    },
    {
        .data_type = "int32_t",
        .data_name = "altitude"
    },
};


ULOG_FORMAT_t ulog_data_flight[ULOG_DATA_FLIGHT_NUM] =
{
    {
        .data_type = "uint64_t",
        .data_name = "timestamp"
    },	
    {
        .data_type = "uint8_t",
        .data_name = "flag_arm",
    },		
    {
        .data_type = "uint8_t",
        .data_name = "flight_mode",
    },		
    {
        .data_type = "uint8_t",
        .data_name = "failsafe",
    },		
    {
        .data_type = "uint8_t",
        .data_name = "inav_gps_health",
    },	
    {
        .data_type = "uint16_t",
        .data_name = "time_cnt",
    },			
    {
        .data_type = "float",
        .data_name = "roll_rate"
    },
    {
        .data_type = "float",
        .data_name = "pitch_rate"
    },
    {
        .data_type = "float",
        .data_name = "yaw_rate"
    },
    {
        .data_type = "float",
        .data_name = "roll_rate_sp"
    },
    {
        .data_type = "float",
        .data_name = "pitch_rate_sp"
    },
    {
        .data_type = "float",
        .data_name = "yaw_rate_sp"
    },
    {
        .data_type = "float",
        .data_name = "roll"
    },
    {
        .data_type = "float",
        .data_name = "pitch"
    },
    {
        .data_type = "float",
        .data_name = "yaw"
    },
    {
        .data_type = "float",
        .data_name = "roll_sp"
    },
    {
        .data_type = "float",
        .data_name = "pitch_sp"
    },
    {
        .data_type = "float",
        .data_name = "yaw_sp"
    },
    {
        .data_type = "float[3]",
        .data_name = "accel"
    },
    {
        .data_type = "float[3]",
        .data_name = "velocity"
    },
    {
        .data_type = "float[3]",
        .data_name = "velocity_sp"
    },
    {
        .data_type = "float[3]",
        .data_name = "position"
    },
    {
        .data_type = "float[3]",
        .data_name = "position_sp"
    },
    {
        .data_type = "float[3]",
        .data_name = "position_obver"
    },
};


ULOG_FORMAT_t ulog_data_gps[ULOG_DATA_GPS_NUM] =
{
    {
        .data_type = "uint64_t",
        .data_name = "timestamp"
    },
    {
        .data_type = "int32_t",
        .data_name = "latitude"
    },
    {
        .data_type = "int32_t",
        .data_name = "longitude"
    },
    {
        .data_type = "int32_t",
        .data_name = "altitude"
    },
    {
        .data_type = "int32_t",
        .data_name = "velN"
    },
    {
        .data_type = "int32_t",
        .data_name = "velE"
    },
    {
        .data_type = "int32_t",
        .data_name = "velD"
    },
    {
        .data_type = "int16_t",
        .data_name = "heading"
    },
    {
        .data_type = "int16_t",
        .data_name = "hAcc"
    },
    {
        .data_type = "int16_t",
        .data_name = "vAcc"
    },
    {
        .data_type = "int16_t",
        .data_name = "sAcc"
    },
    {
        .data_type = "int16_t",
        .data_name = "cAcc"
    },
    {
        .data_type = "uint8_t",
        .data_name = "fixState"
    },
    {
        .data_type = "uint8_t",
        .data_name = "numSV"
    },
};


ULOG_FORMAT_t ulog_data_motors[ULOG_DATA_MOTORS_NUM] = 
{
    {
        .data_type = "uint64_t",
        .data_name = "timestamp"
    },
    {
        .data_type = "uint16_t",
        .data_name = "MOT01",
    },
    {
        .data_type = "uint16_t",
        .data_name = "MOT02",
    },
    {
        .data_type = "uint16_t",
        .data_name = "MOT03",
    },
    {
        .data_type = "uint16_t",
        .data_name = "MOT04",
    },
    {
        .data_type = "uint16_t",
        .data_name = "MOT05",
    },
    {
        .data_type = "uint16_t",
        .data_name = "MOT06",
    },
    {
        .data_type = "uint16_t",
        .data_name = "MOT07",
    },
    {
        .data_type = "uint16_t",
        .data_name = "MOT08",
    },
    {
        .data_type = "uint16_t",
        .data_name = "MOT09",
    },
    {
        .data_type = "uint16_t",
        .data_name = "MOT10",
    },
    {
        .data_type = "uint16_t",
        .data_name = "MOT11",
    },
    {
        .data_type = "uint16_t",
        .data_name = "MOT12",
    },
};


ULOG_FORMAT_t ulog_data_rcin[ULOG_DATA_RCIN_NUM] = 
{
    {
        .data_type = "uint64_t",
        .data_name = "timestamp"
    },
    {
        .data_type = "uint32_t",
        .data_name = "update_ms",
    },
    {
        .data_type = "uint16_t",
        .data_name = "ch01",
    },
    {
        .data_type = "uint16_t",
        .data_name = "ch02",
    },
    {
        .data_type = "uint16_t",
        .data_name = "ch03",
    },
    {
        .data_type = "uint16_t",
        .data_name = "ch04",
    },
    {
        .data_type = "uint16_t",
        .data_name = "ch05",
    },
    {
        .data_type = "uint16_t",
        .data_name = "ch06",
    },
    {
        .data_type = "uint16_t",
        .data_name = "ch07",
    },
    {
        .data_type = "uint16_t",
        .data_name = "ch08",
    },
    {
        .data_type = "uint16_t",
        .data_name = "ch09",
    },
    {
        .data_type = "uint16_t",
        .data_name = "ch10",
    },
    {
        .data_type = "uint16_t",
        .data_name = "ch11",
    },
    {
        .data_type = "uint16_t",
        .data_name = "ch12",
    },
    {
        .data_type = "uint16_t",
        .data_name = "ch13",
    },
    {
        .data_type = "uint16_t",
        .data_name = "ch14",
    },
    {
        .data_type = "uint16_t",
        .data_name = "ch15",
    },
    {
        .data_type = "uint16_t",
        .data_name = "ch16",
    },
};


ULOG_FORMAT_t ulog_data_raw_sensor[ULOG_DATA_RAW_SENSOR_NUM] =
{
    {
        .data_type = "uint64_t",
        .data_name = "timestamp"
    },	
    {
        .data_type = "float[3]",
        .data_name = "raw_mag"
    },
    {
        .data_type = "float[3]",
        .data_name = "raw_mag_ext"
    },
    {
        .data_type = "float[3]",
        .data_name = "raw_acc"
    },
		
    {
        .data_type = "float[3]",
        .data_name = "raw_gyro"
    },	
    {
        .data_type = "float",
        .data_name = "raw_baro_temperature"
    },	
    {
        .data_type = "float",
        .data_name = "raw_baro_pressure_alt"
    },		
    {
        .data_type = "float",
        .data_name = "raw_baro_alt"
    },
    {
        .data_type = "float",
        .data_name = "raw_tof_below_alt"
    },
    {
        .data_type = "float",
        .data_name = "raw_tof_front_alt"
    },
    {
        .data_type = "float",
        .data_name = "raw_battery_voltage"
    },

    {
        .data_type = "float",
        .data_name = "fly_time_s_by_current"
    },
    {
        .data_type = "float",
        .data_name = "smart_bat_voltage"
    },
    {
        .data_type = "float",
        .data_name = "smart_bat_current"
    },
    {
        .data_type = "float",
        .data_name = "smart_bat_temperature"
    },
    {
        .data_type = "float[12]",
        .data_name = "smart_bat_cell_voltage"
    },
    {
        .data_type = "float",
        .data_name = "smart_bat_capacity_full_charge"
    },
    {
        .data_type = "float",
        .data_name = "smart_bat_capacity_remainng"
    },
    {
        .data_type = "float",
        .data_name = "smart_bat_capacity_percen"
    },   
    {
        .data_type = "float",
        .data_name = "main_mcu_temprature"
    },     
    
};


ULOG_FORMAT_t ulog_data_mode[ULOG_DATA_MODE_NUM] = 
{
    {
        .data_type = "uint64_t",
        .data_name = "timestamp"
    },
    {
        .data_type = "uint8_t",
        .data_name = "mode"
    },
    {
        .data_type = "uint8_t",
        .data_name = "reason"
    },
};


ULOG_FORMAT_t ulog_data_pos_ctrl[ULOG_DATA_POS_CTRL_NUM] = 
{
    {
        .data_type = "uint64_t",
        .data_name = "timestamp"
    },
    {
        .data_type = "float",
        .data_name = "target_vel_yaw"
    },
    {
        .data_type = "float",
        .data_name = "target_yaw_rate"
    },
    {
        .data_type = "float",
        .data_name = "target_vel_ef_x"
    },
    {
        .data_type = "float",
        .data_name = "target_vel_ef_y"
    },
    {
        .data_type = "float",
        .data_name = "target_vel_ef_z"
    },
    {
        .data_type = "float",
        .data_name = "target_vel_bf_x"
    },
    {
        .data_type = "float",
        .data_name = "target_vel_bf_y"
    },
    {
        .data_type = "float",
        .data_name = "target_bf_acc_x"
    },
    {
        .data_type = "float",
        .data_name = "target_bf_acc_y"
    },
    {
        .data_type = "float",
        .data_name = "target_pos_x"
    },
    {
        .data_type = "float",
        .data_name = "target_pos_y"
    },
    {
        .data_type = "float",
        .data_name = "target_pos_z"
    },
};


ULOG_FORMAT_t ulog_data_image_geo[ULOG_DATA_IMAGE_GEO_NUM] = 
{
    {
        .data_type = "uint64_t",
        .data_name = "timestamp"
    },
    {
        .data_type = "int32_t",
        .data_name = "index"
    },
    {
        .data_type = "int32_t",
        .data_name = "latitude"
    },
    {
        .data_type = "int32_t",
        .data_name = "longitude"
    },
    {
        .data_type = "int32_t",
        .data_name = "altitude"
    },
    {
        .data_type = "int32_t",
        .data_name = "roll"
    },
    {
        .data_type = "int32_t",
        .data_name = "pitch"
    },
    {
        .data_type = "int32_t",
        .data_name = "yaw"
    },
};


ULOG_FORMAT_t ulog_data_rtk_raw[ULOG_DATA_RTK_RAW_NUM] = 
{
    {
        .data_type = "uint64_t",
        .data_name = "timestamp"
    },
    {
        .data_type = "uint8_t",
        .data_name = "status"
    },
    {
        .data_type = "uint8_t",
        .data_name = "num_sats"
    },
    {
        .data_type = "uint16_t",
        .data_name = "time_week"
    },
    {
        .data_type = "uint32_t",
        .data_name = "time_week_ms"
    },
    {
        .data_type = "double",
        .data_name = "lat"
    },
    {
        .data_type = "double",
        .data_name = "lng"
    },
    {
        .data_type = "float",
        .data_name = "alt"
    },
    {
        .data_type = "float",
        .data_name = "ground_speed"
    },
    {
        .data_type = "float",
        .data_name = "ground_course"
    },
    {
        .data_type = "uint16_t",
        .data_name = "hdop"
    },
    {
        .data_type = "uint16_t",
        .data_name = "vdop"
    },
    {
        .data_type = "float",
        .data_name = "speed_accuracy"
    },
    {
        .data_type = "float",
        .data_name = "horizontal_accuracy"
    },
    {
        .data_type = "float",
        .data_name = "vertical_accuracy"
    },
    {
        .data_type = "uint32_t",
        .data_name = "diff_age"
    },
    {
        .data_type = "float",
        .data_name = "heading"
    },
    {
        .data_type = "float",
        .data_name = "hdg_sd"
    },
    {
        .data_type = "float",
        .data_name = "velocity_x"
    },
    {
        .data_type = "float",
        .data_name = "velocity_y"
    },
    {
        .data_type = "float",
        .data_name = "velocity_z"
    },
};


ULOG_FORMAT_t ulog_data_gnss[ULOG_DATA_GNSS_NUM] = 
{
    {
        .data_type = "uint64_t",
        .data_name = "timestamp"
    },
    {
        .data_type = "uint8_t",
        .data_name = "gnss_detected"
    },
    {
        .data_type = "uint8_t",
        .data_name = "numsv"
    },
    {
        .data_type = "uint8_t",
        .data_name = "fixtype"
    },
    {
        .data_type = "float",
        .data_name = "height"
    },
    {
        .data_type = "int32_t",
        .data_name = "latitude"
    },
    {
        .data_type = "int32_t",
        .data_name = "longitude"
    },
    {
        .data_type = "uint8_t",
        .data_name = "updata_flag"
    },
    {
        .data_type = "float",
        .data_name = "timegap"
    },
    {
        .data_type = "float",
        .data_name = "horizontal_acc"
    },
    {
        .data_type = "float",
        .data_name = "vertical_acc"
    },
    {
        .data_type = "float",
        .data_name = "velocity_acc"
    },
    {
        .data_type = "float",
        .data_name = "gps_pos_dop"
    },
    {
        .data_type = "float",
        .data_name = "ground_speed"
    },
    {
        .data_type = "float",
        .data_name = "alt_vel"
    },
    {
        .data_type = "float",
        .data_name = "vel_e"
    },
    {
        .data_type = "float",
        .data_name = "vel_n"
    },
    {
        .data_type = "float",
        .data_name = "vel_d"
    },
    {
        .data_type = "float",
        .data_name = "rtk_yaw"
    },
    {
        .data_type = "float",
        .data_name = "rtk_yaw_health"
    },
};


ULOG_FORMAT_t ulog_data_beacon[ULOG_DATA_BEACON_NUM] = 
{
    {
        .data_type = "uint64_t",
        .data_name = "timestamp"
    },
    {
        .data_type = "uint8_t",
        .data_name = "numsv"
    },
    {
        .data_type = "uint8_t",
        .data_name = "fixtype"
    },
    {
        .data_type = "int32_t",
        .data_name = "latitude"
    },
    {
        .data_type = "int32_t",
        .data_name = "longitude"
    },
    {
        .data_type = "int32_t",
        .data_name = "alt"
    },
    {
        .data_type = "float",
        .data_name = "velx"
    },
    {
        .data_type = "float",
        .data_name = "vely"
    },
    {
        .data_type = "float",
        .data_name = "velz"
    },
    {
        .data_type = "float",
        .data_name = "yaw"
    },
    {
        .data_type = "float",
        .data_name = "distance"
    },
};

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
