#pragma once
// MESSAGE WK_LOG_RTK_RAW PACKING

#define MAVLINK_MSG_ID_WK_LOG_RTK_RAW 8503


typedef struct __mavlink_wk_log_rtk_raw_t {
 uint64_t timestamp; /*<  timestamp*/
 double lat; /*<  lat*/
 double lng; /*<  lng*/
 uint32_t time_week_ms; /*<  time_week_ms*/
 float alt; /*<  alt*/
 float ground_speed; /*<  ground_speed*/
 float ground_course; /*<  ground_course*/
 float speed_accuracy; /*<  speed_accuracy*/
 float horizontal_accuracy; /*<  horizontal_accuracy*/
 float vertical_accuracy; /*<  vertical_accuracy*/
 uint32_t diff_age; /*<  diff_age*/
 float heading; /*<  heading*/
 float hdg_sd; /*<  hdg_sd*/
 float velocity_x; /*<  velocity_x*/
 float velocity_y; /*<  velocity_y*/
 float velocity_z; /*<  velocity_z*/
 uint16_t time_week; /*<  time_week*/
 uint16_t hdop; /*<  hdop*/
 uint16_t vdop; /*<  vdop*/
 uint8_t status; /*<  status*/
 uint8_t num_sats; /*<  num_sats*/
} mavlink_wk_log_rtk_raw_t;

#define MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN 84
#define MAVLINK_MSG_ID_WK_LOG_RTK_RAW_MIN_LEN 84
#define MAVLINK_MSG_ID_8503_LEN 84
#define MAVLINK_MSG_ID_8503_MIN_LEN 84

#define MAVLINK_MSG_ID_WK_LOG_RTK_RAW_CRC 131
#define MAVLINK_MSG_ID_8503_CRC 131



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_LOG_RTK_RAW { \
    8503, \
    "WK_LOG_RTK_RAW", \
    21, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_rtk_raw_t, timestamp) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 82, offsetof(mavlink_wk_log_rtk_raw_t, status) }, \
         { "num_sats", NULL, MAVLINK_TYPE_UINT8_T, 0, 83, offsetof(mavlink_wk_log_rtk_raw_t, num_sats) }, \
         { "time_week", NULL, MAVLINK_TYPE_UINT16_T, 0, 76, offsetof(mavlink_wk_log_rtk_raw_t, time_week) }, \
         { "time_week_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_wk_log_rtk_raw_t, time_week_ms) }, \
         { "lat", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_wk_log_rtk_raw_t, lat) }, \
         { "lng", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_wk_log_rtk_raw_t, lng) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wk_log_rtk_raw_t, alt) }, \
         { "ground_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wk_log_rtk_raw_t, ground_speed) }, \
         { "ground_course", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wk_log_rtk_raw_t, ground_course) }, \
         { "hdop", NULL, MAVLINK_TYPE_UINT16_T, 0, 78, offsetof(mavlink_wk_log_rtk_raw_t, hdop) }, \
         { "vdop", NULL, MAVLINK_TYPE_UINT16_T, 0, 80, offsetof(mavlink_wk_log_rtk_raw_t, vdop) }, \
         { "speed_accuracy", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_wk_log_rtk_raw_t, speed_accuracy) }, \
         { "horizontal_accuracy", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_wk_log_rtk_raw_t, horizontal_accuracy) }, \
         { "vertical_accuracy", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_wk_log_rtk_raw_t, vertical_accuracy) }, \
         { "diff_age", NULL, MAVLINK_TYPE_UINT32_T, 0, 52, offsetof(mavlink_wk_log_rtk_raw_t, diff_age) }, \
         { "heading", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_wk_log_rtk_raw_t, heading) }, \
         { "hdg_sd", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_wk_log_rtk_raw_t, hdg_sd) }, \
         { "velocity_x", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_wk_log_rtk_raw_t, velocity_x) }, \
         { "velocity_y", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_wk_log_rtk_raw_t, velocity_y) }, \
         { "velocity_z", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_wk_log_rtk_raw_t, velocity_z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_LOG_RTK_RAW { \
    "WK_LOG_RTK_RAW", \
    21, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_rtk_raw_t, timestamp) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 82, offsetof(mavlink_wk_log_rtk_raw_t, status) }, \
         { "num_sats", NULL, MAVLINK_TYPE_UINT8_T, 0, 83, offsetof(mavlink_wk_log_rtk_raw_t, num_sats) }, \
         { "time_week", NULL, MAVLINK_TYPE_UINT16_T, 0, 76, offsetof(mavlink_wk_log_rtk_raw_t, time_week) }, \
         { "time_week_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_wk_log_rtk_raw_t, time_week_ms) }, \
         { "lat", NULL, MAVLINK_TYPE_DOUBLE, 0, 8, offsetof(mavlink_wk_log_rtk_raw_t, lat) }, \
         { "lng", NULL, MAVLINK_TYPE_DOUBLE, 0, 16, offsetof(mavlink_wk_log_rtk_raw_t, lng) }, \
         { "alt", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wk_log_rtk_raw_t, alt) }, \
         { "ground_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wk_log_rtk_raw_t, ground_speed) }, \
         { "ground_course", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wk_log_rtk_raw_t, ground_course) }, \
         { "hdop", NULL, MAVLINK_TYPE_UINT16_T, 0, 78, offsetof(mavlink_wk_log_rtk_raw_t, hdop) }, \
         { "vdop", NULL, MAVLINK_TYPE_UINT16_T, 0, 80, offsetof(mavlink_wk_log_rtk_raw_t, vdop) }, \
         { "speed_accuracy", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_wk_log_rtk_raw_t, speed_accuracy) }, \
         { "horizontal_accuracy", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_wk_log_rtk_raw_t, horizontal_accuracy) }, \
         { "vertical_accuracy", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_wk_log_rtk_raw_t, vertical_accuracy) }, \
         { "diff_age", NULL, MAVLINK_TYPE_UINT32_T, 0, 52, offsetof(mavlink_wk_log_rtk_raw_t, diff_age) }, \
         { "heading", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_wk_log_rtk_raw_t, heading) }, \
         { "hdg_sd", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_wk_log_rtk_raw_t, hdg_sd) }, \
         { "velocity_x", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_wk_log_rtk_raw_t, velocity_x) }, \
         { "velocity_y", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_wk_log_rtk_raw_t, velocity_y) }, \
         { "velocity_z", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_wk_log_rtk_raw_t, velocity_z) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_log_rtk_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  timestamp
 * @param status  status
 * @param num_sats  num_sats
 * @param time_week  time_week
 * @param time_week_ms  time_week_ms
 * @param lat  lat
 * @param lng  lng
 * @param alt  alt
 * @param ground_speed  ground_speed
 * @param ground_course  ground_course
 * @param hdop  hdop
 * @param vdop  vdop
 * @param speed_accuracy  speed_accuracy
 * @param horizontal_accuracy  horizontal_accuracy
 * @param vertical_accuracy  vertical_accuracy
 * @param diff_age  diff_age
 * @param heading  heading
 * @param hdg_sd  hdg_sd
 * @param velocity_x  velocity_x
 * @param velocity_y  velocity_y
 * @param velocity_z  velocity_z
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_rtk_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint8_t status, uint8_t num_sats, uint16_t time_week, uint32_t time_week_ms, double lat, double lng, float alt, float ground_speed, float ground_course, uint16_t hdop, uint16_t vdop, float speed_accuracy, float horizontal_accuracy, float vertical_accuracy, uint32_t diff_age, float heading, float hdg_sd, float velocity_x, float velocity_y, float velocity_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_double(buf, 8, lat);
    _mav_put_double(buf, 16, lng);
    _mav_put_uint32_t(buf, 24, time_week_ms);
    _mav_put_float(buf, 28, alt);
    _mav_put_float(buf, 32, ground_speed);
    _mav_put_float(buf, 36, ground_course);
    _mav_put_float(buf, 40, speed_accuracy);
    _mav_put_float(buf, 44, horizontal_accuracy);
    _mav_put_float(buf, 48, vertical_accuracy);
    _mav_put_uint32_t(buf, 52, diff_age);
    _mav_put_float(buf, 56, heading);
    _mav_put_float(buf, 60, hdg_sd);
    _mav_put_float(buf, 64, velocity_x);
    _mav_put_float(buf, 68, velocity_y);
    _mav_put_float(buf, 72, velocity_z);
    _mav_put_uint16_t(buf, 76, time_week);
    _mav_put_uint16_t(buf, 78, hdop);
    _mav_put_uint16_t(buf, 80, vdop);
    _mav_put_uint8_t(buf, 82, status);
    _mav_put_uint8_t(buf, 83, num_sats);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN);
#else
    mavlink_wk_log_rtk_raw_t packet;
    packet.timestamp = timestamp;
    packet.lat = lat;
    packet.lng = lng;
    packet.time_week_ms = time_week_ms;
    packet.alt = alt;
    packet.ground_speed = ground_speed;
    packet.ground_course = ground_course;
    packet.speed_accuracy = speed_accuracy;
    packet.horizontal_accuracy = horizontal_accuracy;
    packet.vertical_accuracy = vertical_accuracy;
    packet.diff_age = diff_age;
    packet.heading = heading;
    packet.hdg_sd = hdg_sd;
    packet.velocity_x = velocity_x;
    packet.velocity_y = velocity_y;
    packet.velocity_z = velocity_z;
    packet.time_week = time_week;
    packet.hdop = hdop;
    packet.vdop = vdop;
    packet.status = status;
    packet.num_sats = num_sats;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_RTK_RAW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_CRC);
}

/**
 * @brief Pack a wk_log_rtk_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  timestamp
 * @param status  status
 * @param num_sats  num_sats
 * @param time_week  time_week
 * @param time_week_ms  time_week_ms
 * @param lat  lat
 * @param lng  lng
 * @param alt  alt
 * @param ground_speed  ground_speed
 * @param ground_course  ground_course
 * @param hdop  hdop
 * @param vdop  vdop
 * @param speed_accuracy  speed_accuracy
 * @param horizontal_accuracy  horizontal_accuracy
 * @param vertical_accuracy  vertical_accuracy
 * @param diff_age  diff_age
 * @param heading  heading
 * @param hdg_sd  hdg_sd
 * @param velocity_x  velocity_x
 * @param velocity_y  velocity_y
 * @param velocity_z  velocity_z
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_rtk_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,uint8_t status,uint8_t num_sats,uint16_t time_week,uint32_t time_week_ms,double lat,double lng,float alt,float ground_speed,float ground_course,uint16_t hdop,uint16_t vdop,float speed_accuracy,float horizontal_accuracy,float vertical_accuracy,uint32_t diff_age,float heading,float hdg_sd,float velocity_x,float velocity_y,float velocity_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_double(buf, 8, lat);
    _mav_put_double(buf, 16, lng);
    _mav_put_uint32_t(buf, 24, time_week_ms);
    _mav_put_float(buf, 28, alt);
    _mav_put_float(buf, 32, ground_speed);
    _mav_put_float(buf, 36, ground_course);
    _mav_put_float(buf, 40, speed_accuracy);
    _mav_put_float(buf, 44, horizontal_accuracy);
    _mav_put_float(buf, 48, vertical_accuracy);
    _mav_put_uint32_t(buf, 52, diff_age);
    _mav_put_float(buf, 56, heading);
    _mav_put_float(buf, 60, hdg_sd);
    _mav_put_float(buf, 64, velocity_x);
    _mav_put_float(buf, 68, velocity_y);
    _mav_put_float(buf, 72, velocity_z);
    _mav_put_uint16_t(buf, 76, time_week);
    _mav_put_uint16_t(buf, 78, hdop);
    _mav_put_uint16_t(buf, 80, vdop);
    _mav_put_uint8_t(buf, 82, status);
    _mav_put_uint8_t(buf, 83, num_sats);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN);
#else
    mavlink_wk_log_rtk_raw_t packet;
    packet.timestamp = timestamp;
    packet.lat = lat;
    packet.lng = lng;
    packet.time_week_ms = time_week_ms;
    packet.alt = alt;
    packet.ground_speed = ground_speed;
    packet.ground_course = ground_course;
    packet.speed_accuracy = speed_accuracy;
    packet.horizontal_accuracy = horizontal_accuracy;
    packet.vertical_accuracy = vertical_accuracy;
    packet.diff_age = diff_age;
    packet.heading = heading;
    packet.hdg_sd = hdg_sd;
    packet.velocity_x = velocity_x;
    packet.velocity_y = velocity_y;
    packet.velocity_z = velocity_z;
    packet.time_week = time_week;
    packet.hdop = hdop;
    packet.vdop = vdop;
    packet.status = status;
    packet.num_sats = num_sats;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_RTK_RAW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_CRC);
}

/**
 * @brief Encode a wk_log_rtk_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_rtk_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_rtk_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_log_rtk_raw_t* wk_log_rtk_raw)
{
    return mavlink_msg_wk_log_rtk_raw_pack(system_id, component_id, msg, wk_log_rtk_raw->timestamp, wk_log_rtk_raw->status, wk_log_rtk_raw->num_sats, wk_log_rtk_raw->time_week, wk_log_rtk_raw->time_week_ms, wk_log_rtk_raw->lat, wk_log_rtk_raw->lng, wk_log_rtk_raw->alt, wk_log_rtk_raw->ground_speed, wk_log_rtk_raw->ground_course, wk_log_rtk_raw->hdop, wk_log_rtk_raw->vdop, wk_log_rtk_raw->speed_accuracy, wk_log_rtk_raw->horizontal_accuracy, wk_log_rtk_raw->vertical_accuracy, wk_log_rtk_raw->diff_age, wk_log_rtk_raw->heading, wk_log_rtk_raw->hdg_sd, wk_log_rtk_raw->velocity_x, wk_log_rtk_raw->velocity_y, wk_log_rtk_raw->velocity_z);
}

/**
 * @brief Encode a wk_log_rtk_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_rtk_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_rtk_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_log_rtk_raw_t* wk_log_rtk_raw)
{
    return mavlink_msg_wk_log_rtk_raw_pack_chan(system_id, component_id, chan, msg, wk_log_rtk_raw->timestamp, wk_log_rtk_raw->status, wk_log_rtk_raw->num_sats, wk_log_rtk_raw->time_week, wk_log_rtk_raw->time_week_ms, wk_log_rtk_raw->lat, wk_log_rtk_raw->lng, wk_log_rtk_raw->alt, wk_log_rtk_raw->ground_speed, wk_log_rtk_raw->ground_course, wk_log_rtk_raw->hdop, wk_log_rtk_raw->vdop, wk_log_rtk_raw->speed_accuracy, wk_log_rtk_raw->horizontal_accuracy, wk_log_rtk_raw->vertical_accuracy, wk_log_rtk_raw->diff_age, wk_log_rtk_raw->heading, wk_log_rtk_raw->hdg_sd, wk_log_rtk_raw->velocity_x, wk_log_rtk_raw->velocity_y, wk_log_rtk_raw->velocity_z);
}

/**
 * @brief Send a wk_log_rtk_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 * @param status  status
 * @param num_sats  num_sats
 * @param time_week  time_week
 * @param time_week_ms  time_week_ms
 * @param lat  lat
 * @param lng  lng
 * @param alt  alt
 * @param ground_speed  ground_speed
 * @param ground_course  ground_course
 * @param hdop  hdop
 * @param vdop  vdop
 * @param speed_accuracy  speed_accuracy
 * @param horizontal_accuracy  horizontal_accuracy
 * @param vertical_accuracy  vertical_accuracy
 * @param diff_age  diff_age
 * @param heading  heading
 * @param hdg_sd  hdg_sd
 * @param velocity_x  velocity_x
 * @param velocity_y  velocity_y
 * @param velocity_z  velocity_z
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_log_rtk_raw_send(mavlink_channel_t chan, uint64_t timestamp, uint8_t status, uint8_t num_sats, uint16_t time_week, uint32_t time_week_ms, double lat, double lng, float alt, float ground_speed, float ground_course, uint16_t hdop, uint16_t vdop, float speed_accuracy, float horizontal_accuracy, float vertical_accuracy, uint32_t diff_age, float heading, float hdg_sd, float velocity_x, float velocity_y, float velocity_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_double(buf, 8, lat);
    _mav_put_double(buf, 16, lng);
    _mav_put_uint32_t(buf, 24, time_week_ms);
    _mav_put_float(buf, 28, alt);
    _mav_put_float(buf, 32, ground_speed);
    _mav_put_float(buf, 36, ground_course);
    _mav_put_float(buf, 40, speed_accuracy);
    _mav_put_float(buf, 44, horizontal_accuracy);
    _mav_put_float(buf, 48, vertical_accuracy);
    _mav_put_uint32_t(buf, 52, diff_age);
    _mav_put_float(buf, 56, heading);
    _mav_put_float(buf, 60, hdg_sd);
    _mav_put_float(buf, 64, velocity_x);
    _mav_put_float(buf, 68, velocity_y);
    _mav_put_float(buf, 72, velocity_z);
    _mav_put_uint16_t(buf, 76, time_week);
    _mav_put_uint16_t(buf, 78, hdop);
    _mav_put_uint16_t(buf, 80, vdop);
    _mav_put_uint8_t(buf, 82, status);
    _mav_put_uint8_t(buf, 83, num_sats);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_RTK_RAW, buf, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_CRC);
#else
    mavlink_wk_log_rtk_raw_t packet;
    packet.timestamp = timestamp;
    packet.lat = lat;
    packet.lng = lng;
    packet.time_week_ms = time_week_ms;
    packet.alt = alt;
    packet.ground_speed = ground_speed;
    packet.ground_course = ground_course;
    packet.speed_accuracy = speed_accuracy;
    packet.horizontal_accuracy = horizontal_accuracy;
    packet.vertical_accuracy = vertical_accuracy;
    packet.diff_age = diff_age;
    packet.heading = heading;
    packet.hdg_sd = hdg_sd;
    packet.velocity_x = velocity_x;
    packet.velocity_y = velocity_y;
    packet.velocity_z = velocity_z;
    packet.time_week = time_week;
    packet.hdop = hdop;
    packet.vdop = vdop;
    packet.status = status;
    packet.num_sats = num_sats;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_RTK_RAW, (const char *)&packet, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_CRC);
#endif
}

/**
 * @brief Send a wk_log_rtk_raw message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_log_rtk_raw_send_struct(mavlink_channel_t chan, const mavlink_wk_log_rtk_raw_t* wk_log_rtk_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_log_rtk_raw_send(chan, wk_log_rtk_raw->timestamp, wk_log_rtk_raw->status, wk_log_rtk_raw->num_sats, wk_log_rtk_raw->time_week, wk_log_rtk_raw->time_week_ms, wk_log_rtk_raw->lat, wk_log_rtk_raw->lng, wk_log_rtk_raw->alt, wk_log_rtk_raw->ground_speed, wk_log_rtk_raw->ground_course, wk_log_rtk_raw->hdop, wk_log_rtk_raw->vdop, wk_log_rtk_raw->speed_accuracy, wk_log_rtk_raw->horizontal_accuracy, wk_log_rtk_raw->vertical_accuracy, wk_log_rtk_raw->diff_age, wk_log_rtk_raw->heading, wk_log_rtk_raw->hdg_sd, wk_log_rtk_raw->velocity_x, wk_log_rtk_raw->velocity_y, wk_log_rtk_raw->velocity_z);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_RTK_RAW, (const char *)wk_log_rtk_raw, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_log_rtk_raw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, uint8_t status, uint8_t num_sats, uint16_t time_week, uint32_t time_week_ms, double lat, double lng, float alt, float ground_speed, float ground_course, uint16_t hdop, uint16_t vdop, float speed_accuracy, float horizontal_accuracy, float vertical_accuracy, uint32_t diff_age, float heading, float hdg_sd, float velocity_x, float velocity_y, float velocity_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_double(buf, 8, lat);
    _mav_put_double(buf, 16, lng);
    _mav_put_uint32_t(buf, 24, time_week_ms);
    _mav_put_float(buf, 28, alt);
    _mav_put_float(buf, 32, ground_speed);
    _mav_put_float(buf, 36, ground_course);
    _mav_put_float(buf, 40, speed_accuracy);
    _mav_put_float(buf, 44, horizontal_accuracy);
    _mav_put_float(buf, 48, vertical_accuracy);
    _mav_put_uint32_t(buf, 52, diff_age);
    _mav_put_float(buf, 56, heading);
    _mav_put_float(buf, 60, hdg_sd);
    _mav_put_float(buf, 64, velocity_x);
    _mav_put_float(buf, 68, velocity_y);
    _mav_put_float(buf, 72, velocity_z);
    _mav_put_uint16_t(buf, 76, time_week);
    _mav_put_uint16_t(buf, 78, hdop);
    _mav_put_uint16_t(buf, 80, vdop);
    _mav_put_uint8_t(buf, 82, status);
    _mav_put_uint8_t(buf, 83, num_sats);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_RTK_RAW, buf, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_CRC);
#else
    mavlink_wk_log_rtk_raw_t *packet = (mavlink_wk_log_rtk_raw_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->lat = lat;
    packet->lng = lng;
    packet->time_week_ms = time_week_ms;
    packet->alt = alt;
    packet->ground_speed = ground_speed;
    packet->ground_course = ground_course;
    packet->speed_accuracy = speed_accuracy;
    packet->horizontal_accuracy = horizontal_accuracy;
    packet->vertical_accuracy = vertical_accuracy;
    packet->diff_age = diff_age;
    packet->heading = heading;
    packet->hdg_sd = hdg_sd;
    packet->velocity_x = velocity_x;
    packet->velocity_y = velocity_y;
    packet->velocity_z = velocity_z;
    packet->time_week = time_week;
    packet->hdop = hdop;
    packet->vdop = vdop;
    packet->status = status;
    packet->num_sats = num_sats;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_RTK_RAW, (const char *)packet, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_LOG_RTK_RAW UNPACKING


/**
 * @brief Get field timestamp from wk_log_rtk_raw message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_wk_log_rtk_raw_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field status from wk_log_rtk_raw message
 *
 * @return  status
 */
static inline uint8_t mavlink_msg_wk_log_rtk_raw_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  82);
}

/**
 * @brief Get field num_sats from wk_log_rtk_raw message
 *
 * @return  num_sats
 */
static inline uint8_t mavlink_msg_wk_log_rtk_raw_get_num_sats(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  83);
}

/**
 * @brief Get field time_week from wk_log_rtk_raw message
 *
 * @return  time_week
 */
static inline uint16_t mavlink_msg_wk_log_rtk_raw_get_time_week(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  76);
}

/**
 * @brief Get field time_week_ms from wk_log_rtk_raw message
 *
 * @return  time_week_ms
 */
static inline uint32_t mavlink_msg_wk_log_rtk_raw_get_time_week_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  24);
}

/**
 * @brief Get field lat from wk_log_rtk_raw message
 *
 * @return  lat
 */
static inline double mavlink_msg_wk_log_rtk_raw_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  8);
}

/**
 * @brief Get field lng from wk_log_rtk_raw message
 *
 * @return  lng
 */
static inline double mavlink_msg_wk_log_rtk_raw_get_lng(const mavlink_message_t* msg)
{
    return _MAV_RETURN_double(msg,  16);
}

/**
 * @brief Get field alt from wk_log_rtk_raw message
 *
 * @return  alt
 */
static inline float mavlink_msg_wk_log_rtk_raw_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field ground_speed from wk_log_rtk_raw message
 *
 * @return  ground_speed
 */
static inline float mavlink_msg_wk_log_rtk_raw_get_ground_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field ground_course from wk_log_rtk_raw message
 *
 * @return  ground_course
 */
static inline float mavlink_msg_wk_log_rtk_raw_get_ground_course(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field hdop from wk_log_rtk_raw message
 *
 * @return  hdop
 */
static inline uint16_t mavlink_msg_wk_log_rtk_raw_get_hdop(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  78);
}

/**
 * @brief Get field vdop from wk_log_rtk_raw message
 *
 * @return  vdop
 */
static inline uint16_t mavlink_msg_wk_log_rtk_raw_get_vdop(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  80);
}

/**
 * @brief Get field speed_accuracy from wk_log_rtk_raw message
 *
 * @return  speed_accuracy
 */
static inline float mavlink_msg_wk_log_rtk_raw_get_speed_accuracy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field horizontal_accuracy from wk_log_rtk_raw message
 *
 * @return  horizontal_accuracy
 */
static inline float mavlink_msg_wk_log_rtk_raw_get_horizontal_accuracy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field vertical_accuracy from wk_log_rtk_raw message
 *
 * @return  vertical_accuracy
 */
static inline float mavlink_msg_wk_log_rtk_raw_get_vertical_accuracy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field diff_age from wk_log_rtk_raw message
 *
 * @return  diff_age
 */
static inline uint32_t mavlink_msg_wk_log_rtk_raw_get_diff_age(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  52);
}

/**
 * @brief Get field heading from wk_log_rtk_raw message
 *
 * @return  heading
 */
static inline float mavlink_msg_wk_log_rtk_raw_get_heading(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field hdg_sd from wk_log_rtk_raw message
 *
 * @return  hdg_sd
 */
static inline float mavlink_msg_wk_log_rtk_raw_get_hdg_sd(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field velocity_x from wk_log_rtk_raw message
 *
 * @return  velocity_x
 */
static inline float mavlink_msg_wk_log_rtk_raw_get_velocity_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field velocity_y from wk_log_rtk_raw message
 *
 * @return  velocity_y
 */
static inline float mavlink_msg_wk_log_rtk_raw_get_velocity_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field velocity_z from wk_log_rtk_raw message
 *
 * @return  velocity_z
 */
static inline float mavlink_msg_wk_log_rtk_raw_get_velocity_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  72);
}

/**
 * @brief Decode a wk_log_rtk_raw message into a struct
 *
 * @param msg The message to decode
 * @param wk_log_rtk_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_log_rtk_raw_decode(const mavlink_message_t* msg, mavlink_wk_log_rtk_raw_t* wk_log_rtk_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_log_rtk_raw->timestamp = mavlink_msg_wk_log_rtk_raw_get_timestamp(msg);
    wk_log_rtk_raw->lat = mavlink_msg_wk_log_rtk_raw_get_lat(msg);
    wk_log_rtk_raw->lng = mavlink_msg_wk_log_rtk_raw_get_lng(msg);
    wk_log_rtk_raw->time_week_ms = mavlink_msg_wk_log_rtk_raw_get_time_week_ms(msg);
    wk_log_rtk_raw->alt = mavlink_msg_wk_log_rtk_raw_get_alt(msg);
    wk_log_rtk_raw->ground_speed = mavlink_msg_wk_log_rtk_raw_get_ground_speed(msg);
    wk_log_rtk_raw->ground_course = mavlink_msg_wk_log_rtk_raw_get_ground_course(msg);
    wk_log_rtk_raw->speed_accuracy = mavlink_msg_wk_log_rtk_raw_get_speed_accuracy(msg);
    wk_log_rtk_raw->horizontal_accuracy = mavlink_msg_wk_log_rtk_raw_get_horizontal_accuracy(msg);
    wk_log_rtk_raw->vertical_accuracy = mavlink_msg_wk_log_rtk_raw_get_vertical_accuracy(msg);
    wk_log_rtk_raw->diff_age = mavlink_msg_wk_log_rtk_raw_get_diff_age(msg);
    wk_log_rtk_raw->heading = mavlink_msg_wk_log_rtk_raw_get_heading(msg);
    wk_log_rtk_raw->hdg_sd = mavlink_msg_wk_log_rtk_raw_get_hdg_sd(msg);
    wk_log_rtk_raw->velocity_x = mavlink_msg_wk_log_rtk_raw_get_velocity_x(msg);
    wk_log_rtk_raw->velocity_y = mavlink_msg_wk_log_rtk_raw_get_velocity_y(msg);
    wk_log_rtk_raw->velocity_z = mavlink_msg_wk_log_rtk_raw_get_velocity_z(msg);
    wk_log_rtk_raw->time_week = mavlink_msg_wk_log_rtk_raw_get_time_week(msg);
    wk_log_rtk_raw->hdop = mavlink_msg_wk_log_rtk_raw_get_hdop(msg);
    wk_log_rtk_raw->vdop = mavlink_msg_wk_log_rtk_raw_get_vdop(msg);
    wk_log_rtk_raw->status = mavlink_msg_wk_log_rtk_raw_get_status(msg);
    wk_log_rtk_raw->num_sats = mavlink_msg_wk_log_rtk_raw_get_num_sats(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN? msg->len : MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN;
        memset(wk_log_rtk_raw, 0, MAVLINK_MSG_ID_WK_LOG_RTK_RAW_LEN);
    memcpy(wk_log_rtk_raw, _MAV_PAYLOAD(msg), len);
#endif
}
