#pragma once
// MESSAGE WK_LOG_SENSOR_RAW PACKING

#define MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW 8508


typedef struct __mavlink_wk_log_sensor_raw_t {
 uint64_t timestamp; /*<  timestamp*/
 float imu_raw_mag[3]; /*<  imu_raw_mag*/
 float imu_raw_mag_ext[3]; /*<  imu_raw_mag_ext*/
 float imu_raw_acc[3]; /*<  imu_raw_acc*/
 float imu_raw_gyro[3]; /*<  imu_raw_gyro*/
 float raw_baro_temperature; /*<  raw_baro_temperature*/
 float raw_baro_pressure_alt; /*<  raw_baro_pressure_alt*/
 float raw_baro_alt; /*<  raw_baro_alt*/
 float raw_tof_below_alt; /*<  raw_tof_below_alt*/
 float raw_tof_front_alt; /*<  raw_tof_front_alt*/
 float raw_battery_voltage; /*<  raw_battery_voltage*/
 float fly_time_s_by_current; /*<  fly_time_s_by_current*/
 float smart_bat_voltage; /*<  smart_bat_voltage*/
 float smart_bat_current; /*<  smart_bat_current*/
 float smart_bat_cell_voltage[12]; /*<  smart_bat_cell_voltage*/
 float smart_bat_capacity_full_charge; /*<  smart_bat_capacity_full_charge*/
 float smart_bat_temperature; /*<  smart_bat_temperature*/
 float smart_bat_capacity_remainng; /*<  smart_bat_capacity_remainng*/
 float smart_bat_capacity_percen; /*<  smart_bat_capacity_percen*/
 float main_mcu_temprature; /*<  main_mcu_temprature*/
} mavlink_wk_log_sensor_raw_t;

#define MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN 160
#define MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_MIN_LEN 160
#define MAVLINK_MSG_ID_8508_LEN 160
#define MAVLINK_MSG_ID_8508_MIN_LEN 160

#define MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_CRC 206
#define MAVLINK_MSG_ID_8508_CRC 206

#define MAVLINK_MSG_WK_LOG_SENSOR_RAW_FIELD_IMU_RAW_MAG_LEN 3
#define MAVLINK_MSG_WK_LOG_SENSOR_RAW_FIELD_IMU_RAW_MAG_EXT_LEN 3
#define MAVLINK_MSG_WK_LOG_SENSOR_RAW_FIELD_IMU_RAW_ACC_LEN 3
#define MAVLINK_MSG_WK_LOG_SENSOR_RAW_FIELD_IMU_RAW_GYRO_LEN 3
#define MAVLINK_MSG_WK_LOG_SENSOR_RAW_FIELD_SMART_BAT_CELL_VOLTAGE_LEN 12

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_LOG_SENSOR_RAW { \
    8508, \
    "WK_LOG_SENSOR_RAW", \
    20, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_sensor_raw_t, timestamp) }, \
         { "imu_raw_mag", NULL, MAVLINK_TYPE_FLOAT, 3, 8, offsetof(mavlink_wk_log_sensor_raw_t, imu_raw_mag) }, \
         { "imu_raw_mag_ext", NULL, MAVLINK_TYPE_FLOAT, 3, 20, offsetof(mavlink_wk_log_sensor_raw_t, imu_raw_mag_ext) }, \
         { "imu_raw_acc", NULL, MAVLINK_TYPE_FLOAT, 3, 32, offsetof(mavlink_wk_log_sensor_raw_t, imu_raw_acc) }, \
         { "imu_raw_gyro", NULL, MAVLINK_TYPE_FLOAT, 3, 44, offsetof(mavlink_wk_log_sensor_raw_t, imu_raw_gyro) }, \
         { "raw_baro_temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_wk_log_sensor_raw_t, raw_baro_temperature) }, \
         { "raw_baro_pressure_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_wk_log_sensor_raw_t, raw_baro_pressure_alt) }, \
         { "raw_baro_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_wk_log_sensor_raw_t, raw_baro_alt) }, \
         { "raw_tof_below_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_wk_log_sensor_raw_t, raw_tof_below_alt) }, \
         { "raw_tof_front_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_wk_log_sensor_raw_t, raw_tof_front_alt) }, \
         { "raw_battery_voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_wk_log_sensor_raw_t, raw_battery_voltage) }, \
         { "fly_time_s_by_current", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_wk_log_sensor_raw_t, fly_time_s_by_current) }, \
         { "smart_bat_voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_wk_log_sensor_raw_t, smart_bat_voltage) }, \
         { "smart_bat_current", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_wk_log_sensor_raw_t, smart_bat_current) }, \
         { "smart_bat_cell_voltage", NULL, MAVLINK_TYPE_FLOAT, 12, 92, offsetof(mavlink_wk_log_sensor_raw_t, smart_bat_cell_voltage) }, \
         { "smart_bat_capacity_full_charge", NULL, MAVLINK_TYPE_FLOAT, 0, 140, offsetof(mavlink_wk_log_sensor_raw_t, smart_bat_capacity_full_charge) }, \
         { "smart_bat_temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 144, offsetof(mavlink_wk_log_sensor_raw_t, smart_bat_temperature) }, \
         { "smart_bat_capacity_remainng", NULL, MAVLINK_TYPE_FLOAT, 0, 148, offsetof(mavlink_wk_log_sensor_raw_t, smart_bat_capacity_remainng) }, \
         { "smart_bat_capacity_percen", NULL, MAVLINK_TYPE_FLOAT, 0, 152, offsetof(mavlink_wk_log_sensor_raw_t, smart_bat_capacity_percen) }, \
         { "main_mcu_temprature", NULL, MAVLINK_TYPE_FLOAT, 0, 156, offsetof(mavlink_wk_log_sensor_raw_t, main_mcu_temprature) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_LOG_SENSOR_RAW { \
    "WK_LOG_SENSOR_RAW", \
    20, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_sensor_raw_t, timestamp) }, \
         { "imu_raw_mag", NULL, MAVLINK_TYPE_FLOAT, 3, 8, offsetof(mavlink_wk_log_sensor_raw_t, imu_raw_mag) }, \
         { "imu_raw_mag_ext", NULL, MAVLINK_TYPE_FLOAT, 3, 20, offsetof(mavlink_wk_log_sensor_raw_t, imu_raw_mag_ext) }, \
         { "imu_raw_acc", NULL, MAVLINK_TYPE_FLOAT, 3, 32, offsetof(mavlink_wk_log_sensor_raw_t, imu_raw_acc) }, \
         { "imu_raw_gyro", NULL, MAVLINK_TYPE_FLOAT, 3, 44, offsetof(mavlink_wk_log_sensor_raw_t, imu_raw_gyro) }, \
         { "raw_baro_temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_wk_log_sensor_raw_t, raw_baro_temperature) }, \
         { "raw_baro_pressure_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_wk_log_sensor_raw_t, raw_baro_pressure_alt) }, \
         { "raw_baro_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_wk_log_sensor_raw_t, raw_baro_alt) }, \
         { "raw_tof_below_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_wk_log_sensor_raw_t, raw_tof_below_alt) }, \
         { "raw_tof_front_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_wk_log_sensor_raw_t, raw_tof_front_alt) }, \
         { "raw_battery_voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_wk_log_sensor_raw_t, raw_battery_voltage) }, \
         { "fly_time_s_by_current", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_wk_log_sensor_raw_t, fly_time_s_by_current) }, \
         { "smart_bat_voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_wk_log_sensor_raw_t, smart_bat_voltage) }, \
         { "smart_bat_current", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_wk_log_sensor_raw_t, smart_bat_current) }, \
         { "smart_bat_cell_voltage", NULL, MAVLINK_TYPE_FLOAT, 12, 92, offsetof(mavlink_wk_log_sensor_raw_t, smart_bat_cell_voltage) }, \
         { "smart_bat_capacity_full_charge", NULL, MAVLINK_TYPE_FLOAT, 0, 140, offsetof(mavlink_wk_log_sensor_raw_t, smart_bat_capacity_full_charge) }, \
         { "smart_bat_temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 144, offsetof(mavlink_wk_log_sensor_raw_t, smart_bat_temperature) }, \
         { "smart_bat_capacity_remainng", NULL, MAVLINK_TYPE_FLOAT, 0, 148, offsetof(mavlink_wk_log_sensor_raw_t, smart_bat_capacity_remainng) }, \
         { "smart_bat_capacity_percen", NULL, MAVLINK_TYPE_FLOAT, 0, 152, offsetof(mavlink_wk_log_sensor_raw_t, smart_bat_capacity_percen) }, \
         { "main_mcu_temprature", NULL, MAVLINK_TYPE_FLOAT, 0, 156, offsetof(mavlink_wk_log_sensor_raw_t, main_mcu_temprature) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_log_sensor_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  timestamp
 * @param imu_raw_mag  imu_raw_mag
 * @param imu_raw_mag_ext  imu_raw_mag_ext
 * @param imu_raw_acc  imu_raw_acc
 * @param imu_raw_gyro  imu_raw_gyro
 * @param raw_baro_temperature  raw_baro_temperature
 * @param raw_baro_pressure_alt  raw_baro_pressure_alt
 * @param raw_baro_alt  raw_baro_alt
 * @param raw_tof_below_alt  raw_tof_below_alt
 * @param raw_tof_front_alt  raw_tof_front_alt
 * @param raw_battery_voltage  raw_battery_voltage
 * @param fly_time_s_by_current  fly_time_s_by_current
 * @param smart_bat_voltage  smart_bat_voltage
 * @param smart_bat_current  smart_bat_current
 * @param smart_bat_cell_voltage  smart_bat_cell_voltage
 * @param smart_bat_capacity_full_charge  smart_bat_capacity_full_charge
 * @param smart_bat_temperature  smart_bat_temperature
 * @param smart_bat_capacity_remainng  smart_bat_capacity_remainng
 * @param smart_bat_capacity_percen  smart_bat_capacity_percen
 * @param main_mcu_temprature  main_mcu_temprature
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_sensor_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, const float *imu_raw_mag, const float *imu_raw_mag_ext, const float *imu_raw_acc, const float *imu_raw_gyro, float raw_baro_temperature, float raw_baro_pressure_alt, float raw_baro_alt, float raw_tof_below_alt, float raw_tof_front_alt, float raw_battery_voltage, float fly_time_s_by_current, float smart_bat_voltage, float smart_bat_current, const float *smart_bat_cell_voltage, float smart_bat_capacity_full_charge, float smart_bat_temperature, float smart_bat_capacity_remainng, float smart_bat_capacity_percen, float main_mcu_temprature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 56, raw_baro_temperature);
    _mav_put_float(buf, 60, raw_baro_pressure_alt);
    _mav_put_float(buf, 64, raw_baro_alt);
    _mav_put_float(buf, 68, raw_tof_below_alt);
    _mav_put_float(buf, 72, raw_tof_front_alt);
    _mav_put_float(buf, 76, raw_battery_voltage);
    _mav_put_float(buf, 80, fly_time_s_by_current);
    _mav_put_float(buf, 84, smart_bat_voltage);
    _mav_put_float(buf, 88, smart_bat_current);
    _mav_put_float(buf, 140, smart_bat_capacity_full_charge);
    _mav_put_float(buf, 144, smart_bat_temperature);
    _mav_put_float(buf, 148, smart_bat_capacity_remainng);
    _mav_put_float(buf, 152, smart_bat_capacity_percen);
    _mav_put_float(buf, 156, main_mcu_temprature);
    _mav_put_float_array(buf, 8, imu_raw_mag, 3);
    _mav_put_float_array(buf, 20, imu_raw_mag_ext, 3);
    _mav_put_float_array(buf, 32, imu_raw_acc, 3);
    _mav_put_float_array(buf, 44, imu_raw_gyro, 3);
    _mav_put_float_array(buf, 92, smart_bat_cell_voltage, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN);
#else
    mavlink_wk_log_sensor_raw_t packet;
    packet.timestamp = timestamp;
    packet.raw_baro_temperature = raw_baro_temperature;
    packet.raw_baro_pressure_alt = raw_baro_pressure_alt;
    packet.raw_baro_alt = raw_baro_alt;
    packet.raw_tof_below_alt = raw_tof_below_alt;
    packet.raw_tof_front_alt = raw_tof_front_alt;
    packet.raw_battery_voltage = raw_battery_voltage;
    packet.fly_time_s_by_current = fly_time_s_by_current;
    packet.smart_bat_voltage = smart_bat_voltage;
    packet.smart_bat_current = smart_bat_current;
    packet.smart_bat_capacity_full_charge = smart_bat_capacity_full_charge;
    packet.smart_bat_temperature = smart_bat_temperature;
    packet.smart_bat_capacity_remainng = smart_bat_capacity_remainng;
    packet.smart_bat_capacity_percen = smart_bat_capacity_percen;
    packet.main_mcu_temprature = main_mcu_temprature;
    mav_array_memcpy(packet.imu_raw_mag, imu_raw_mag, sizeof(float)*3);
    mav_array_memcpy(packet.imu_raw_mag_ext, imu_raw_mag_ext, sizeof(float)*3);
    mav_array_memcpy(packet.imu_raw_acc, imu_raw_acc, sizeof(float)*3);
    mav_array_memcpy(packet.imu_raw_gyro, imu_raw_gyro, sizeof(float)*3);
    mav_array_memcpy(packet.smart_bat_cell_voltage, smart_bat_cell_voltage, sizeof(float)*12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_CRC);
}

/**
 * @brief Pack a wk_log_sensor_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  timestamp
 * @param imu_raw_mag  imu_raw_mag
 * @param imu_raw_mag_ext  imu_raw_mag_ext
 * @param imu_raw_acc  imu_raw_acc
 * @param imu_raw_gyro  imu_raw_gyro
 * @param raw_baro_temperature  raw_baro_temperature
 * @param raw_baro_pressure_alt  raw_baro_pressure_alt
 * @param raw_baro_alt  raw_baro_alt
 * @param raw_tof_below_alt  raw_tof_below_alt
 * @param raw_tof_front_alt  raw_tof_front_alt
 * @param raw_battery_voltage  raw_battery_voltage
 * @param fly_time_s_by_current  fly_time_s_by_current
 * @param smart_bat_voltage  smart_bat_voltage
 * @param smart_bat_current  smart_bat_current
 * @param smart_bat_cell_voltage  smart_bat_cell_voltage
 * @param smart_bat_capacity_full_charge  smart_bat_capacity_full_charge
 * @param smart_bat_temperature  smart_bat_temperature
 * @param smart_bat_capacity_remainng  smart_bat_capacity_remainng
 * @param smart_bat_capacity_percen  smart_bat_capacity_percen
 * @param main_mcu_temprature  main_mcu_temprature
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_sensor_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,const float *imu_raw_mag,const float *imu_raw_mag_ext,const float *imu_raw_acc,const float *imu_raw_gyro,float raw_baro_temperature,float raw_baro_pressure_alt,float raw_baro_alt,float raw_tof_below_alt,float raw_tof_front_alt,float raw_battery_voltage,float fly_time_s_by_current,float smart_bat_voltage,float smart_bat_current,const float *smart_bat_cell_voltage,float smart_bat_capacity_full_charge,float smart_bat_temperature,float smart_bat_capacity_remainng,float smart_bat_capacity_percen,float main_mcu_temprature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 56, raw_baro_temperature);
    _mav_put_float(buf, 60, raw_baro_pressure_alt);
    _mav_put_float(buf, 64, raw_baro_alt);
    _mav_put_float(buf, 68, raw_tof_below_alt);
    _mav_put_float(buf, 72, raw_tof_front_alt);
    _mav_put_float(buf, 76, raw_battery_voltage);
    _mav_put_float(buf, 80, fly_time_s_by_current);
    _mav_put_float(buf, 84, smart_bat_voltage);
    _mav_put_float(buf, 88, smart_bat_current);
    _mav_put_float(buf, 140, smart_bat_capacity_full_charge);
    _mav_put_float(buf, 144, smart_bat_temperature);
    _mav_put_float(buf, 148, smart_bat_capacity_remainng);
    _mav_put_float(buf, 152, smart_bat_capacity_percen);
    _mav_put_float(buf, 156, main_mcu_temprature);
    _mav_put_float_array(buf, 8, imu_raw_mag, 3);
    _mav_put_float_array(buf, 20, imu_raw_mag_ext, 3);
    _mav_put_float_array(buf, 32, imu_raw_acc, 3);
    _mav_put_float_array(buf, 44, imu_raw_gyro, 3);
    _mav_put_float_array(buf, 92, smart_bat_cell_voltage, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN);
#else
    mavlink_wk_log_sensor_raw_t packet;
    packet.timestamp = timestamp;
    packet.raw_baro_temperature = raw_baro_temperature;
    packet.raw_baro_pressure_alt = raw_baro_pressure_alt;
    packet.raw_baro_alt = raw_baro_alt;
    packet.raw_tof_below_alt = raw_tof_below_alt;
    packet.raw_tof_front_alt = raw_tof_front_alt;
    packet.raw_battery_voltage = raw_battery_voltage;
    packet.fly_time_s_by_current = fly_time_s_by_current;
    packet.smart_bat_voltage = smart_bat_voltage;
    packet.smart_bat_current = smart_bat_current;
    packet.smart_bat_capacity_full_charge = smart_bat_capacity_full_charge;
    packet.smart_bat_temperature = smart_bat_temperature;
    packet.smart_bat_capacity_remainng = smart_bat_capacity_remainng;
    packet.smart_bat_capacity_percen = smart_bat_capacity_percen;
    packet.main_mcu_temprature = main_mcu_temprature;
    mav_array_memcpy(packet.imu_raw_mag, imu_raw_mag, sizeof(float)*3);
    mav_array_memcpy(packet.imu_raw_mag_ext, imu_raw_mag_ext, sizeof(float)*3);
    mav_array_memcpy(packet.imu_raw_acc, imu_raw_acc, sizeof(float)*3);
    mav_array_memcpy(packet.imu_raw_gyro, imu_raw_gyro, sizeof(float)*3);
    mav_array_memcpy(packet.smart_bat_cell_voltage, smart_bat_cell_voltage, sizeof(float)*12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_CRC);
}

/**
 * @brief Encode a wk_log_sensor_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_sensor_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_sensor_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_log_sensor_raw_t* wk_log_sensor_raw)
{
    return mavlink_msg_wk_log_sensor_raw_pack(system_id, component_id, msg, wk_log_sensor_raw->timestamp, wk_log_sensor_raw->imu_raw_mag, wk_log_sensor_raw->imu_raw_mag_ext, wk_log_sensor_raw->imu_raw_acc, wk_log_sensor_raw->imu_raw_gyro, wk_log_sensor_raw->raw_baro_temperature, wk_log_sensor_raw->raw_baro_pressure_alt, wk_log_sensor_raw->raw_baro_alt, wk_log_sensor_raw->raw_tof_below_alt, wk_log_sensor_raw->raw_tof_front_alt, wk_log_sensor_raw->raw_battery_voltage, wk_log_sensor_raw->fly_time_s_by_current, wk_log_sensor_raw->smart_bat_voltage, wk_log_sensor_raw->smart_bat_current, wk_log_sensor_raw->smart_bat_cell_voltage, wk_log_sensor_raw->smart_bat_capacity_full_charge, wk_log_sensor_raw->smart_bat_temperature, wk_log_sensor_raw->smart_bat_capacity_remainng, wk_log_sensor_raw->smart_bat_capacity_percen, wk_log_sensor_raw->main_mcu_temprature);
}

/**
 * @brief Encode a wk_log_sensor_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_sensor_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_sensor_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_log_sensor_raw_t* wk_log_sensor_raw)
{
    return mavlink_msg_wk_log_sensor_raw_pack_chan(system_id, component_id, chan, msg, wk_log_sensor_raw->timestamp, wk_log_sensor_raw->imu_raw_mag, wk_log_sensor_raw->imu_raw_mag_ext, wk_log_sensor_raw->imu_raw_acc, wk_log_sensor_raw->imu_raw_gyro, wk_log_sensor_raw->raw_baro_temperature, wk_log_sensor_raw->raw_baro_pressure_alt, wk_log_sensor_raw->raw_baro_alt, wk_log_sensor_raw->raw_tof_below_alt, wk_log_sensor_raw->raw_tof_front_alt, wk_log_sensor_raw->raw_battery_voltage, wk_log_sensor_raw->fly_time_s_by_current, wk_log_sensor_raw->smart_bat_voltage, wk_log_sensor_raw->smart_bat_current, wk_log_sensor_raw->smart_bat_cell_voltage, wk_log_sensor_raw->smart_bat_capacity_full_charge, wk_log_sensor_raw->smart_bat_temperature, wk_log_sensor_raw->smart_bat_capacity_remainng, wk_log_sensor_raw->smart_bat_capacity_percen, wk_log_sensor_raw->main_mcu_temprature);
}

/**
 * @brief Send a wk_log_sensor_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 * @param imu_raw_mag  imu_raw_mag
 * @param imu_raw_mag_ext  imu_raw_mag_ext
 * @param imu_raw_acc  imu_raw_acc
 * @param imu_raw_gyro  imu_raw_gyro
 * @param raw_baro_temperature  raw_baro_temperature
 * @param raw_baro_pressure_alt  raw_baro_pressure_alt
 * @param raw_baro_alt  raw_baro_alt
 * @param raw_tof_below_alt  raw_tof_below_alt
 * @param raw_tof_front_alt  raw_tof_front_alt
 * @param raw_battery_voltage  raw_battery_voltage
 * @param fly_time_s_by_current  fly_time_s_by_current
 * @param smart_bat_voltage  smart_bat_voltage
 * @param smart_bat_current  smart_bat_current
 * @param smart_bat_cell_voltage  smart_bat_cell_voltage
 * @param smart_bat_capacity_full_charge  smart_bat_capacity_full_charge
 * @param smart_bat_temperature  smart_bat_temperature
 * @param smart_bat_capacity_remainng  smart_bat_capacity_remainng
 * @param smart_bat_capacity_percen  smart_bat_capacity_percen
 * @param main_mcu_temprature  main_mcu_temprature
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_log_sensor_raw_send(mavlink_channel_t chan, uint64_t timestamp, const float *imu_raw_mag, const float *imu_raw_mag_ext, const float *imu_raw_acc, const float *imu_raw_gyro, float raw_baro_temperature, float raw_baro_pressure_alt, float raw_baro_alt, float raw_tof_below_alt, float raw_tof_front_alt, float raw_battery_voltage, float fly_time_s_by_current, float smart_bat_voltage, float smart_bat_current, const float *smart_bat_cell_voltage, float smart_bat_capacity_full_charge, float smart_bat_temperature, float smart_bat_capacity_remainng, float smart_bat_capacity_percen, float main_mcu_temprature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 56, raw_baro_temperature);
    _mav_put_float(buf, 60, raw_baro_pressure_alt);
    _mav_put_float(buf, 64, raw_baro_alt);
    _mav_put_float(buf, 68, raw_tof_below_alt);
    _mav_put_float(buf, 72, raw_tof_front_alt);
    _mav_put_float(buf, 76, raw_battery_voltage);
    _mav_put_float(buf, 80, fly_time_s_by_current);
    _mav_put_float(buf, 84, smart_bat_voltage);
    _mav_put_float(buf, 88, smart_bat_current);
    _mav_put_float(buf, 140, smart_bat_capacity_full_charge);
    _mav_put_float(buf, 144, smart_bat_temperature);
    _mav_put_float(buf, 148, smart_bat_capacity_remainng);
    _mav_put_float(buf, 152, smart_bat_capacity_percen);
    _mav_put_float(buf, 156, main_mcu_temprature);
    _mav_put_float_array(buf, 8, imu_raw_mag, 3);
    _mav_put_float_array(buf, 20, imu_raw_mag_ext, 3);
    _mav_put_float_array(buf, 32, imu_raw_acc, 3);
    _mav_put_float_array(buf, 44, imu_raw_gyro, 3);
    _mav_put_float_array(buf, 92, smart_bat_cell_voltage, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW, buf, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_CRC);
#else
    mavlink_wk_log_sensor_raw_t packet;
    packet.timestamp = timestamp;
    packet.raw_baro_temperature = raw_baro_temperature;
    packet.raw_baro_pressure_alt = raw_baro_pressure_alt;
    packet.raw_baro_alt = raw_baro_alt;
    packet.raw_tof_below_alt = raw_tof_below_alt;
    packet.raw_tof_front_alt = raw_tof_front_alt;
    packet.raw_battery_voltage = raw_battery_voltage;
    packet.fly_time_s_by_current = fly_time_s_by_current;
    packet.smart_bat_voltage = smart_bat_voltage;
    packet.smart_bat_current = smart_bat_current;
    packet.smart_bat_capacity_full_charge = smart_bat_capacity_full_charge;
    packet.smart_bat_temperature = smart_bat_temperature;
    packet.smart_bat_capacity_remainng = smart_bat_capacity_remainng;
    packet.smart_bat_capacity_percen = smart_bat_capacity_percen;
    packet.main_mcu_temprature = main_mcu_temprature;
    mav_array_memcpy(packet.imu_raw_mag, imu_raw_mag, sizeof(float)*3);
    mav_array_memcpy(packet.imu_raw_mag_ext, imu_raw_mag_ext, sizeof(float)*3);
    mav_array_memcpy(packet.imu_raw_acc, imu_raw_acc, sizeof(float)*3);
    mav_array_memcpy(packet.imu_raw_gyro, imu_raw_gyro, sizeof(float)*3);
    mav_array_memcpy(packet.smart_bat_cell_voltage, smart_bat_cell_voltage, sizeof(float)*12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW, (const char *)&packet, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_CRC);
#endif
}

/**
 * @brief Send a wk_log_sensor_raw message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_log_sensor_raw_send_struct(mavlink_channel_t chan, const mavlink_wk_log_sensor_raw_t* wk_log_sensor_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_log_sensor_raw_send(chan, wk_log_sensor_raw->timestamp, wk_log_sensor_raw->imu_raw_mag, wk_log_sensor_raw->imu_raw_mag_ext, wk_log_sensor_raw->imu_raw_acc, wk_log_sensor_raw->imu_raw_gyro, wk_log_sensor_raw->raw_baro_temperature, wk_log_sensor_raw->raw_baro_pressure_alt, wk_log_sensor_raw->raw_baro_alt, wk_log_sensor_raw->raw_tof_below_alt, wk_log_sensor_raw->raw_tof_front_alt, wk_log_sensor_raw->raw_battery_voltage, wk_log_sensor_raw->fly_time_s_by_current, wk_log_sensor_raw->smart_bat_voltage, wk_log_sensor_raw->smart_bat_current, wk_log_sensor_raw->smart_bat_cell_voltage, wk_log_sensor_raw->smart_bat_capacity_full_charge, wk_log_sensor_raw->smart_bat_temperature, wk_log_sensor_raw->smart_bat_capacity_remainng, wk_log_sensor_raw->smart_bat_capacity_percen, wk_log_sensor_raw->main_mcu_temprature);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW, (const char *)wk_log_sensor_raw, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_log_sensor_raw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, const float *imu_raw_mag, const float *imu_raw_mag_ext, const float *imu_raw_acc, const float *imu_raw_gyro, float raw_baro_temperature, float raw_baro_pressure_alt, float raw_baro_alt, float raw_tof_below_alt, float raw_tof_front_alt, float raw_battery_voltage, float fly_time_s_by_current, float smart_bat_voltage, float smart_bat_current, const float *smart_bat_cell_voltage, float smart_bat_capacity_full_charge, float smart_bat_temperature, float smart_bat_capacity_remainng, float smart_bat_capacity_percen, float main_mcu_temprature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 56, raw_baro_temperature);
    _mav_put_float(buf, 60, raw_baro_pressure_alt);
    _mav_put_float(buf, 64, raw_baro_alt);
    _mav_put_float(buf, 68, raw_tof_below_alt);
    _mav_put_float(buf, 72, raw_tof_front_alt);
    _mav_put_float(buf, 76, raw_battery_voltage);
    _mav_put_float(buf, 80, fly_time_s_by_current);
    _mav_put_float(buf, 84, smart_bat_voltage);
    _mav_put_float(buf, 88, smart_bat_current);
    _mav_put_float(buf, 140, smart_bat_capacity_full_charge);
    _mav_put_float(buf, 144, smart_bat_temperature);
    _mav_put_float(buf, 148, smart_bat_capacity_remainng);
    _mav_put_float(buf, 152, smart_bat_capacity_percen);
    _mav_put_float(buf, 156, main_mcu_temprature);
    _mav_put_float_array(buf, 8, imu_raw_mag, 3);
    _mav_put_float_array(buf, 20, imu_raw_mag_ext, 3);
    _mav_put_float_array(buf, 32, imu_raw_acc, 3);
    _mav_put_float_array(buf, 44, imu_raw_gyro, 3);
    _mav_put_float_array(buf, 92, smart_bat_cell_voltage, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW, buf, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_CRC);
#else
    mavlink_wk_log_sensor_raw_t *packet = (mavlink_wk_log_sensor_raw_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->raw_baro_temperature = raw_baro_temperature;
    packet->raw_baro_pressure_alt = raw_baro_pressure_alt;
    packet->raw_baro_alt = raw_baro_alt;
    packet->raw_tof_below_alt = raw_tof_below_alt;
    packet->raw_tof_front_alt = raw_tof_front_alt;
    packet->raw_battery_voltage = raw_battery_voltage;
    packet->fly_time_s_by_current = fly_time_s_by_current;
    packet->smart_bat_voltage = smart_bat_voltage;
    packet->smart_bat_current = smart_bat_current;
    packet->smart_bat_capacity_full_charge = smart_bat_capacity_full_charge;
    packet->smart_bat_temperature = smart_bat_temperature;
    packet->smart_bat_capacity_remainng = smart_bat_capacity_remainng;
    packet->smart_bat_capacity_percen = smart_bat_capacity_percen;
    packet->main_mcu_temprature = main_mcu_temprature;
    mav_array_memcpy(packet->imu_raw_mag, imu_raw_mag, sizeof(float)*3);
    mav_array_memcpy(packet->imu_raw_mag_ext, imu_raw_mag_ext, sizeof(float)*3);
    mav_array_memcpy(packet->imu_raw_acc, imu_raw_acc, sizeof(float)*3);
    mav_array_memcpy(packet->imu_raw_gyro, imu_raw_gyro, sizeof(float)*3);
    mav_array_memcpy(packet->smart_bat_cell_voltage, smart_bat_cell_voltage, sizeof(float)*12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW, (const char *)packet, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_LOG_SENSOR_RAW UNPACKING


/**
 * @brief Get field timestamp from wk_log_sensor_raw message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_wk_log_sensor_raw_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field imu_raw_mag from wk_log_sensor_raw message
 *
 * @return  imu_raw_mag
 */
static inline uint16_t mavlink_msg_wk_log_sensor_raw_get_imu_raw_mag(const mavlink_message_t* msg, float *imu_raw_mag)
{
    return _MAV_RETURN_float_array(msg, imu_raw_mag, 3,  8);
}

/**
 * @brief Get field imu_raw_mag_ext from wk_log_sensor_raw message
 *
 * @return  imu_raw_mag_ext
 */
static inline uint16_t mavlink_msg_wk_log_sensor_raw_get_imu_raw_mag_ext(const mavlink_message_t* msg, float *imu_raw_mag_ext)
{
    return _MAV_RETURN_float_array(msg, imu_raw_mag_ext, 3,  20);
}

/**
 * @brief Get field imu_raw_acc from wk_log_sensor_raw message
 *
 * @return  imu_raw_acc
 */
static inline uint16_t mavlink_msg_wk_log_sensor_raw_get_imu_raw_acc(const mavlink_message_t* msg, float *imu_raw_acc)
{
    return _MAV_RETURN_float_array(msg, imu_raw_acc, 3,  32);
}

/**
 * @brief Get field imu_raw_gyro from wk_log_sensor_raw message
 *
 * @return  imu_raw_gyro
 */
static inline uint16_t mavlink_msg_wk_log_sensor_raw_get_imu_raw_gyro(const mavlink_message_t* msg, float *imu_raw_gyro)
{
    return _MAV_RETURN_float_array(msg, imu_raw_gyro, 3,  44);
}

/**
 * @brief Get field raw_baro_temperature from wk_log_sensor_raw message
 *
 * @return  raw_baro_temperature
 */
static inline float mavlink_msg_wk_log_sensor_raw_get_raw_baro_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field raw_baro_pressure_alt from wk_log_sensor_raw message
 *
 * @return  raw_baro_pressure_alt
 */
static inline float mavlink_msg_wk_log_sensor_raw_get_raw_baro_pressure_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field raw_baro_alt from wk_log_sensor_raw message
 *
 * @return  raw_baro_alt
 */
static inline float mavlink_msg_wk_log_sensor_raw_get_raw_baro_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field raw_tof_below_alt from wk_log_sensor_raw message
 *
 * @return  raw_tof_below_alt
 */
static inline float mavlink_msg_wk_log_sensor_raw_get_raw_tof_below_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field raw_tof_front_alt from wk_log_sensor_raw message
 *
 * @return  raw_tof_front_alt
 */
static inline float mavlink_msg_wk_log_sensor_raw_get_raw_tof_front_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  72);
}

/**
 * @brief Get field raw_battery_voltage from wk_log_sensor_raw message
 *
 * @return  raw_battery_voltage
 */
static inline float mavlink_msg_wk_log_sensor_raw_get_raw_battery_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  76);
}

/**
 * @brief Get field fly_time_s_by_current from wk_log_sensor_raw message
 *
 * @return  fly_time_s_by_current
 */
static inline float mavlink_msg_wk_log_sensor_raw_get_fly_time_s_by_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  80);
}

/**
 * @brief Get field smart_bat_voltage from wk_log_sensor_raw message
 *
 * @return  smart_bat_voltage
 */
static inline float mavlink_msg_wk_log_sensor_raw_get_smart_bat_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  84);
}

/**
 * @brief Get field smart_bat_current from wk_log_sensor_raw message
 *
 * @return  smart_bat_current
 */
static inline float mavlink_msg_wk_log_sensor_raw_get_smart_bat_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  88);
}

/**
 * @brief Get field smart_bat_cell_voltage from wk_log_sensor_raw message
 *
 * @return  smart_bat_cell_voltage
 */
static inline uint16_t mavlink_msg_wk_log_sensor_raw_get_smart_bat_cell_voltage(const mavlink_message_t* msg, float *smart_bat_cell_voltage)
{
    return _MAV_RETURN_float_array(msg, smart_bat_cell_voltage, 12,  92);
}

/**
 * @brief Get field smart_bat_capacity_full_charge from wk_log_sensor_raw message
 *
 * @return  smart_bat_capacity_full_charge
 */
static inline float mavlink_msg_wk_log_sensor_raw_get_smart_bat_capacity_full_charge(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  140);
}

/**
 * @brief Get field smart_bat_temperature from wk_log_sensor_raw message
 *
 * @return  smart_bat_temperature
 */
static inline float mavlink_msg_wk_log_sensor_raw_get_smart_bat_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  144);
}

/**
 * @brief Get field smart_bat_capacity_remainng from wk_log_sensor_raw message
 *
 * @return  smart_bat_capacity_remainng
 */
static inline float mavlink_msg_wk_log_sensor_raw_get_smart_bat_capacity_remainng(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  148);
}

/**
 * @brief Get field smart_bat_capacity_percen from wk_log_sensor_raw message
 *
 * @return  smart_bat_capacity_percen
 */
static inline float mavlink_msg_wk_log_sensor_raw_get_smart_bat_capacity_percen(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  152);
}

/**
 * @brief Get field main_mcu_temprature from wk_log_sensor_raw message
 *
 * @return  main_mcu_temprature
 */
static inline float mavlink_msg_wk_log_sensor_raw_get_main_mcu_temprature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  156);
}

/**
 * @brief Decode a wk_log_sensor_raw message into a struct
 *
 * @param msg The message to decode
 * @param wk_log_sensor_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_log_sensor_raw_decode(const mavlink_message_t* msg, mavlink_wk_log_sensor_raw_t* wk_log_sensor_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_log_sensor_raw->timestamp = mavlink_msg_wk_log_sensor_raw_get_timestamp(msg);
    mavlink_msg_wk_log_sensor_raw_get_imu_raw_mag(msg, wk_log_sensor_raw->imu_raw_mag);
    mavlink_msg_wk_log_sensor_raw_get_imu_raw_mag_ext(msg, wk_log_sensor_raw->imu_raw_mag_ext);
    mavlink_msg_wk_log_sensor_raw_get_imu_raw_acc(msg, wk_log_sensor_raw->imu_raw_acc);
    mavlink_msg_wk_log_sensor_raw_get_imu_raw_gyro(msg, wk_log_sensor_raw->imu_raw_gyro);
    wk_log_sensor_raw->raw_baro_temperature = mavlink_msg_wk_log_sensor_raw_get_raw_baro_temperature(msg);
    wk_log_sensor_raw->raw_baro_pressure_alt = mavlink_msg_wk_log_sensor_raw_get_raw_baro_pressure_alt(msg);
    wk_log_sensor_raw->raw_baro_alt = mavlink_msg_wk_log_sensor_raw_get_raw_baro_alt(msg);
    wk_log_sensor_raw->raw_tof_below_alt = mavlink_msg_wk_log_sensor_raw_get_raw_tof_below_alt(msg);
    wk_log_sensor_raw->raw_tof_front_alt = mavlink_msg_wk_log_sensor_raw_get_raw_tof_front_alt(msg);
    wk_log_sensor_raw->raw_battery_voltage = mavlink_msg_wk_log_sensor_raw_get_raw_battery_voltage(msg);
    wk_log_sensor_raw->fly_time_s_by_current = mavlink_msg_wk_log_sensor_raw_get_fly_time_s_by_current(msg);
    wk_log_sensor_raw->smart_bat_voltage = mavlink_msg_wk_log_sensor_raw_get_smart_bat_voltage(msg);
    wk_log_sensor_raw->smart_bat_current = mavlink_msg_wk_log_sensor_raw_get_smart_bat_current(msg);
    mavlink_msg_wk_log_sensor_raw_get_smart_bat_cell_voltage(msg, wk_log_sensor_raw->smart_bat_cell_voltage);
    wk_log_sensor_raw->smart_bat_capacity_full_charge = mavlink_msg_wk_log_sensor_raw_get_smart_bat_capacity_full_charge(msg);
    wk_log_sensor_raw->smart_bat_temperature = mavlink_msg_wk_log_sensor_raw_get_smart_bat_temperature(msg);
    wk_log_sensor_raw->smart_bat_capacity_remainng = mavlink_msg_wk_log_sensor_raw_get_smart_bat_capacity_remainng(msg);
    wk_log_sensor_raw->smart_bat_capacity_percen = mavlink_msg_wk_log_sensor_raw_get_smart_bat_capacity_percen(msg);
    wk_log_sensor_raw->main_mcu_temprature = mavlink_msg_wk_log_sensor_raw_get_main_mcu_temprature(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN? msg->len : MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN;
        memset(wk_log_sensor_raw, 0, MAVLINK_MSG_ID_WK_LOG_SENSOR_RAW_LEN);
    memcpy(wk_log_sensor_raw, _MAV_PAYLOAD(msg), len);
#endif
}
