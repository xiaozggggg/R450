#pragma once
// MESSAGE WK_LOG_GNSS PACKING

#define MAVLINK_MSG_ID_WK_LOG_GNSS 8501


typedef struct __mavlink_wk_log_gnss_t {
 uint64_t timestamp; /*<  timestamp*/
 float height; /*<  height*/
 int32_t latitude; /*<  latitude*/
 int32_t longitude; /*<  longitude*/
 float timegap; /*<  timegap*/
 float horizontal_acc; /*<  horizontal_acc*/
 float vertical_acc; /*<  vertical_acc*/
 float velocity_acc; /*<  velocity_acc*/
 float gps_pos_dop; /*<  gps_pos_dop*/
 float ground_speed; /*<  ground_speed*/
 float alt_vel; /*<  alt_vel*/
 float vel_e; /*<  vel_e*/
 float vel_n; /*<  vel_n*/
 float vel_d; /*<  vel_d*/
 float rtk_yaw; /*<  rtk_yaw*/
 float rtk_yaw_health; /*<  rtk_yaw_health*/
 uint8_t gnss_detected; /*<  gnss_detected*/
 uint8_t numsv; /*<  numsv*/
 uint8_t fixtype; /*<  fixtype*/
 uint8_t update_flag; /*<  update_flag*/
} mavlink_wk_log_gnss_t;

#define MAVLINK_MSG_ID_WK_LOG_GNSS_LEN 72
#define MAVLINK_MSG_ID_WK_LOG_GNSS_MIN_LEN 72
#define MAVLINK_MSG_ID_8501_LEN 72
#define MAVLINK_MSG_ID_8501_MIN_LEN 72

#define MAVLINK_MSG_ID_WK_LOG_GNSS_CRC 127
#define MAVLINK_MSG_ID_8501_CRC 127



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_LOG_GNSS { \
    8501, \
    "WK_LOG_GNSS", \
    20, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_gnss_t, timestamp) }, \
         { "gnss_detected", NULL, MAVLINK_TYPE_UINT8_T, 0, 68, offsetof(mavlink_wk_log_gnss_t, gnss_detected) }, \
         { "numsv", NULL, MAVLINK_TYPE_UINT8_T, 0, 69, offsetof(mavlink_wk_log_gnss_t, numsv) }, \
         { "fixtype", NULL, MAVLINK_TYPE_UINT8_T, 0, 70, offsetof(mavlink_wk_log_gnss_t, fixtype) }, \
         { "height", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_log_gnss_t, height) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_log_gnss_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_wk_log_gnss_t, longitude) }, \
         { "update_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 71, offsetof(mavlink_wk_log_gnss_t, update_flag) }, \
         { "timegap", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_log_gnss_t, timegap) }, \
         { "horizontal_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wk_log_gnss_t, horizontal_acc) }, \
         { "vertical_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wk_log_gnss_t, vertical_acc) }, \
         { "velocity_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wk_log_gnss_t, velocity_acc) }, \
         { "gps_pos_dop", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wk_log_gnss_t, gps_pos_dop) }, \
         { "ground_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_wk_log_gnss_t, ground_speed) }, \
         { "alt_vel", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_wk_log_gnss_t, alt_vel) }, \
         { "vel_e", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_wk_log_gnss_t, vel_e) }, \
         { "vel_n", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_wk_log_gnss_t, vel_n) }, \
         { "vel_d", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_wk_log_gnss_t, vel_d) }, \
         { "rtk_yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_wk_log_gnss_t, rtk_yaw) }, \
         { "rtk_yaw_health", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_wk_log_gnss_t, rtk_yaw_health) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_LOG_GNSS { \
    "WK_LOG_GNSS", \
    20, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_gnss_t, timestamp) }, \
         { "gnss_detected", NULL, MAVLINK_TYPE_UINT8_T, 0, 68, offsetof(mavlink_wk_log_gnss_t, gnss_detected) }, \
         { "numsv", NULL, MAVLINK_TYPE_UINT8_T, 0, 69, offsetof(mavlink_wk_log_gnss_t, numsv) }, \
         { "fixtype", NULL, MAVLINK_TYPE_UINT8_T, 0, 70, offsetof(mavlink_wk_log_gnss_t, fixtype) }, \
         { "height", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_log_gnss_t, height) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_log_gnss_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_wk_log_gnss_t, longitude) }, \
         { "update_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 71, offsetof(mavlink_wk_log_gnss_t, update_flag) }, \
         { "timegap", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_log_gnss_t, timegap) }, \
         { "horizontal_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wk_log_gnss_t, horizontal_acc) }, \
         { "vertical_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wk_log_gnss_t, vertical_acc) }, \
         { "velocity_acc", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wk_log_gnss_t, velocity_acc) }, \
         { "gps_pos_dop", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wk_log_gnss_t, gps_pos_dop) }, \
         { "ground_speed", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_wk_log_gnss_t, ground_speed) }, \
         { "alt_vel", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_wk_log_gnss_t, alt_vel) }, \
         { "vel_e", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_wk_log_gnss_t, vel_e) }, \
         { "vel_n", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_wk_log_gnss_t, vel_n) }, \
         { "vel_d", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_wk_log_gnss_t, vel_d) }, \
         { "rtk_yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_wk_log_gnss_t, rtk_yaw) }, \
         { "rtk_yaw_health", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_wk_log_gnss_t, rtk_yaw_health) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_log_gnss message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  timestamp
 * @param gnss_detected  gnss_detected
 * @param numsv  numsv
 * @param fixtype  fixtype
 * @param height  height
 * @param latitude  latitude
 * @param longitude  longitude
 * @param update_flag  update_flag
 * @param timegap  timegap
 * @param horizontal_acc  horizontal_acc
 * @param vertical_acc  vertical_acc
 * @param velocity_acc  velocity_acc
 * @param gps_pos_dop  gps_pos_dop
 * @param ground_speed  ground_speed
 * @param alt_vel  alt_vel
 * @param vel_e  vel_e
 * @param vel_n  vel_n
 * @param vel_d  vel_d
 * @param rtk_yaw  rtk_yaw
 * @param rtk_yaw_health  rtk_yaw_health
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_gnss_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint8_t gnss_detected, uint8_t numsv, uint8_t fixtype, float height, int32_t latitude, int32_t longitude, uint8_t update_flag, float timegap, float horizontal_acc, float vertical_acc, float velocity_acc, float gps_pos_dop, float ground_speed, float alt_vel, float vel_e, float vel_n, float vel_d, float rtk_yaw, float rtk_yaw_health)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_GNSS_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, height);
    _mav_put_int32_t(buf, 12, latitude);
    _mav_put_int32_t(buf, 16, longitude);
    _mav_put_float(buf, 20, timegap);
    _mav_put_float(buf, 24, horizontal_acc);
    _mav_put_float(buf, 28, vertical_acc);
    _mav_put_float(buf, 32, velocity_acc);
    _mav_put_float(buf, 36, gps_pos_dop);
    _mav_put_float(buf, 40, ground_speed);
    _mav_put_float(buf, 44, alt_vel);
    _mav_put_float(buf, 48, vel_e);
    _mav_put_float(buf, 52, vel_n);
    _mav_put_float(buf, 56, vel_d);
    _mav_put_float(buf, 60, rtk_yaw);
    _mav_put_float(buf, 64, rtk_yaw_health);
    _mav_put_uint8_t(buf, 68, gnss_detected);
    _mav_put_uint8_t(buf, 69, numsv);
    _mav_put_uint8_t(buf, 70, fixtype);
    _mav_put_uint8_t(buf, 71, update_flag);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_GNSS_LEN);
#else
    mavlink_wk_log_gnss_t packet;
    packet.timestamp = timestamp;
    packet.height = height;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.timegap = timegap;
    packet.horizontal_acc = horizontal_acc;
    packet.vertical_acc = vertical_acc;
    packet.velocity_acc = velocity_acc;
    packet.gps_pos_dop = gps_pos_dop;
    packet.ground_speed = ground_speed;
    packet.alt_vel = alt_vel;
    packet.vel_e = vel_e;
    packet.vel_n = vel_n;
    packet.vel_d = vel_d;
    packet.rtk_yaw = rtk_yaw;
    packet.rtk_yaw_health = rtk_yaw_health;
    packet.gnss_detected = gnss_detected;
    packet.numsv = numsv;
    packet.fixtype = fixtype;
    packet.update_flag = update_flag;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_GNSS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_GNSS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_LOG_GNSS_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_GNSS_LEN, MAVLINK_MSG_ID_WK_LOG_GNSS_CRC);
}

/**
 * @brief Pack a wk_log_gnss message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  timestamp
 * @param gnss_detected  gnss_detected
 * @param numsv  numsv
 * @param fixtype  fixtype
 * @param height  height
 * @param latitude  latitude
 * @param longitude  longitude
 * @param update_flag  update_flag
 * @param timegap  timegap
 * @param horizontal_acc  horizontal_acc
 * @param vertical_acc  vertical_acc
 * @param velocity_acc  velocity_acc
 * @param gps_pos_dop  gps_pos_dop
 * @param ground_speed  ground_speed
 * @param alt_vel  alt_vel
 * @param vel_e  vel_e
 * @param vel_n  vel_n
 * @param vel_d  vel_d
 * @param rtk_yaw  rtk_yaw
 * @param rtk_yaw_health  rtk_yaw_health
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_gnss_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,uint8_t gnss_detected,uint8_t numsv,uint8_t fixtype,float height,int32_t latitude,int32_t longitude,uint8_t update_flag,float timegap,float horizontal_acc,float vertical_acc,float velocity_acc,float gps_pos_dop,float ground_speed,float alt_vel,float vel_e,float vel_n,float vel_d,float rtk_yaw,float rtk_yaw_health)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_GNSS_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, height);
    _mav_put_int32_t(buf, 12, latitude);
    _mav_put_int32_t(buf, 16, longitude);
    _mav_put_float(buf, 20, timegap);
    _mav_put_float(buf, 24, horizontal_acc);
    _mav_put_float(buf, 28, vertical_acc);
    _mav_put_float(buf, 32, velocity_acc);
    _mav_put_float(buf, 36, gps_pos_dop);
    _mav_put_float(buf, 40, ground_speed);
    _mav_put_float(buf, 44, alt_vel);
    _mav_put_float(buf, 48, vel_e);
    _mav_put_float(buf, 52, vel_n);
    _mav_put_float(buf, 56, vel_d);
    _mav_put_float(buf, 60, rtk_yaw);
    _mav_put_float(buf, 64, rtk_yaw_health);
    _mav_put_uint8_t(buf, 68, gnss_detected);
    _mav_put_uint8_t(buf, 69, numsv);
    _mav_put_uint8_t(buf, 70, fixtype);
    _mav_put_uint8_t(buf, 71, update_flag);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_GNSS_LEN);
#else
    mavlink_wk_log_gnss_t packet;
    packet.timestamp = timestamp;
    packet.height = height;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.timegap = timegap;
    packet.horizontal_acc = horizontal_acc;
    packet.vertical_acc = vertical_acc;
    packet.velocity_acc = velocity_acc;
    packet.gps_pos_dop = gps_pos_dop;
    packet.ground_speed = ground_speed;
    packet.alt_vel = alt_vel;
    packet.vel_e = vel_e;
    packet.vel_n = vel_n;
    packet.vel_d = vel_d;
    packet.rtk_yaw = rtk_yaw;
    packet.rtk_yaw_health = rtk_yaw_health;
    packet.gnss_detected = gnss_detected;
    packet.numsv = numsv;
    packet.fixtype = fixtype;
    packet.update_flag = update_flag;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_GNSS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_GNSS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_LOG_GNSS_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_GNSS_LEN, MAVLINK_MSG_ID_WK_LOG_GNSS_CRC);
}

/**
 * @brief Encode a wk_log_gnss struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_gnss C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_gnss_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_log_gnss_t* wk_log_gnss)
{
    return mavlink_msg_wk_log_gnss_pack(system_id, component_id, msg, wk_log_gnss->timestamp, wk_log_gnss->gnss_detected, wk_log_gnss->numsv, wk_log_gnss->fixtype, wk_log_gnss->height, wk_log_gnss->latitude, wk_log_gnss->longitude, wk_log_gnss->update_flag, wk_log_gnss->timegap, wk_log_gnss->horizontal_acc, wk_log_gnss->vertical_acc, wk_log_gnss->velocity_acc, wk_log_gnss->gps_pos_dop, wk_log_gnss->ground_speed, wk_log_gnss->alt_vel, wk_log_gnss->vel_e, wk_log_gnss->vel_n, wk_log_gnss->vel_d, wk_log_gnss->rtk_yaw, wk_log_gnss->rtk_yaw_health);
}

/**
 * @brief Encode a wk_log_gnss struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_gnss C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_gnss_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_log_gnss_t* wk_log_gnss)
{
    return mavlink_msg_wk_log_gnss_pack_chan(system_id, component_id, chan, msg, wk_log_gnss->timestamp, wk_log_gnss->gnss_detected, wk_log_gnss->numsv, wk_log_gnss->fixtype, wk_log_gnss->height, wk_log_gnss->latitude, wk_log_gnss->longitude, wk_log_gnss->update_flag, wk_log_gnss->timegap, wk_log_gnss->horizontal_acc, wk_log_gnss->vertical_acc, wk_log_gnss->velocity_acc, wk_log_gnss->gps_pos_dop, wk_log_gnss->ground_speed, wk_log_gnss->alt_vel, wk_log_gnss->vel_e, wk_log_gnss->vel_n, wk_log_gnss->vel_d, wk_log_gnss->rtk_yaw, wk_log_gnss->rtk_yaw_health);
}

/**
 * @brief Send a wk_log_gnss message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 * @param gnss_detected  gnss_detected
 * @param numsv  numsv
 * @param fixtype  fixtype
 * @param height  height
 * @param latitude  latitude
 * @param longitude  longitude
 * @param update_flag  update_flag
 * @param timegap  timegap
 * @param horizontal_acc  horizontal_acc
 * @param vertical_acc  vertical_acc
 * @param velocity_acc  velocity_acc
 * @param gps_pos_dop  gps_pos_dop
 * @param ground_speed  ground_speed
 * @param alt_vel  alt_vel
 * @param vel_e  vel_e
 * @param vel_n  vel_n
 * @param vel_d  vel_d
 * @param rtk_yaw  rtk_yaw
 * @param rtk_yaw_health  rtk_yaw_health
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_log_gnss_send(mavlink_channel_t chan, uint64_t timestamp, uint8_t gnss_detected, uint8_t numsv, uint8_t fixtype, float height, int32_t latitude, int32_t longitude, uint8_t update_flag, float timegap, float horizontal_acc, float vertical_acc, float velocity_acc, float gps_pos_dop, float ground_speed, float alt_vel, float vel_e, float vel_n, float vel_d, float rtk_yaw, float rtk_yaw_health)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_GNSS_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, height);
    _mav_put_int32_t(buf, 12, latitude);
    _mav_put_int32_t(buf, 16, longitude);
    _mav_put_float(buf, 20, timegap);
    _mav_put_float(buf, 24, horizontal_acc);
    _mav_put_float(buf, 28, vertical_acc);
    _mav_put_float(buf, 32, velocity_acc);
    _mav_put_float(buf, 36, gps_pos_dop);
    _mav_put_float(buf, 40, ground_speed);
    _mav_put_float(buf, 44, alt_vel);
    _mav_put_float(buf, 48, vel_e);
    _mav_put_float(buf, 52, vel_n);
    _mav_put_float(buf, 56, vel_d);
    _mav_put_float(buf, 60, rtk_yaw);
    _mav_put_float(buf, 64, rtk_yaw_health);
    _mav_put_uint8_t(buf, 68, gnss_detected);
    _mav_put_uint8_t(buf, 69, numsv);
    _mav_put_uint8_t(buf, 70, fixtype);
    _mav_put_uint8_t(buf, 71, update_flag);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_GNSS, buf, MAVLINK_MSG_ID_WK_LOG_GNSS_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_GNSS_LEN, MAVLINK_MSG_ID_WK_LOG_GNSS_CRC);
#else
    mavlink_wk_log_gnss_t packet;
    packet.timestamp = timestamp;
    packet.height = height;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.timegap = timegap;
    packet.horizontal_acc = horizontal_acc;
    packet.vertical_acc = vertical_acc;
    packet.velocity_acc = velocity_acc;
    packet.gps_pos_dop = gps_pos_dop;
    packet.ground_speed = ground_speed;
    packet.alt_vel = alt_vel;
    packet.vel_e = vel_e;
    packet.vel_n = vel_n;
    packet.vel_d = vel_d;
    packet.rtk_yaw = rtk_yaw;
    packet.rtk_yaw_health = rtk_yaw_health;
    packet.gnss_detected = gnss_detected;
    packet.numsv = numsv;
    packet.fixtype = fixtype;
    packet.update_flag = update_flag;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_GNSS, (const char *)&packet, MAVLINK_MSG_ID_WK_LOG_GNSS_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_GNSS_LEN, MAVLINK_MSG_ID_WK_LOG_GNSS_CRC);
#endif
}

/**
 * @brief Send a wk_log_gnss message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_log_gnss_send_struct(mavlink_channel_t chan, const mavlink_wk_log_gnss_t* wk_log_gnss)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_log_gnss_send(chan, wk_log_gnss->timestamp, wk_log_gnss->gnss_detected, wk_log_gnss->numsv, wk_log_gnss->fixtype, wk_log_gnss->height, wk_log_gnss->latitude, wk_log_gnss->longitude, wk_log_gnss->update_flag, wk_log_gnss->timegap, wk_log_gnss->horizontal_acc, wk_log_gnss->vertical_acc, wk_log_gnss->velocity_acc, wk_log_gnss->gps_pos_dop, wk_log_gnss->ground_speed, wk_log_gnss->alt_vel, wk_log_gnss->vel_e, wk_log_gnss->vel_n, wk_log_gnss->vel_d, wk_log_gnss->rtk_yaw, wk_log_gnss->rtk_yaw_health);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_GNSS, (const char *)wk_log_gnss, MAVLINK_MSG_ID_WK_LOG_GNSS_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_GNSS_LEN, MAVLINK_MSG_ID_WK_LOG_GNSS_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_LOG_GNSS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_log_gnss_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, uint8_t gnss_detected, uint8_t numsv, uint8_t fixtype, float height, int32_t latitude, int32_t longitude, uint8_t update_flag, float timegap, float horizontal_acc, float vertical_acc, float velocity_acc, float gps_pos_dop, float ground_speed, float alt_vel, float vel_e, float vel_n, float vel_d, float rtk_yaw, float rtk_yaw_health)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, height);
    _mav_put_int32_t(buf, 12, latitude);
    _mav_put_int32_t(buf, 16, longitude);
    _mav_put_float(buf, 20, timegap);
    _mav_put_float(buf, 24, horizontal_acc);
    _mav_put_float(buf, 28, vertical_acc);
    _mav_put_float(buf, 32, velocity_acc);
    _mav_put_float(buf, 36, gps_pos_dop);
    _mav_put_float(buf, 40, ground_speed);
    _mav_put_float(buf, 44, alt_vel);
    _mav_put_float(buf, 48, vel_e);
    _mav_put_float(buf, 52, vel_n);
    _mav_put_float(buf, 56, vel_d);
    _mav_put_float(buf, 60, rtk_yaw);
    _mav_put_float(buf, 64, rtk_yaw_health);
    _mav_put_uint8_t(buf, 68, gnss_detected);
    _mav_put_uint8_t(buf, 69, numsv);
    _mav_put_uint8_t(buf, 70, fixtype);
    _mav_put_uint8_t(buf, 71, update_flag);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_GNSS, buf, MAVLINK_MSG_ID_WK_LOG_GNSS_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_GNSS_LEN, MAVLINK_MSG_ID_WK_LOG_GNSS_CRC);
#else
    mavlink_wk_log_gnss_t *packet = (mavlink_wk_log_gnss_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->height = height;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->timegap = timegap;
    packet->horizontal_acc = horizontal_acc;
    packet->vertical_acc = vertical_acc;
    packet->velocity_acc = velocity_acc;
    packet->gps_pos_dop = gps_pos_dop;
    packet->ground_speed = ground_speed;
    packet->alt_vel = alt_vel;
    packet->vel_e = vel_e;
    packet->vel_n = vel_n;
    packet->vel_d = vel_d;
    packet->rtk_yaw = rtk_yaw;
    packet->rtk_yaw_health = rtk_yaw_health;
    packet->gnss_detected = gnss_detected;
    packet->numsv = numsv;
    packet->fixtype = fixtype;
    packet->update_flag = update_flag;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_GNSS, (const char *)packet, MAVLINK_MSG_ID_WK_LOG_GNSS_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_GNSS_LEN, MAVLINK_MSG_ID_WK_LOG_GNSS_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_LOG_GNSS UNPACKING


/**
 * @brief Get field timestamp from wk_log_gnss message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_wk_log_gnss_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field gnss_detected from wk_log_gnss message
 *
 * @return  gnss_detected
 */
static inline uint8_t mavlink_msg_wk_log_gnss_get_gnss_detected(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  68);
}

/**
 * @brief Get field numsv from wk_log_gnss message
 *
 * @return  numsv
 */
static inline uint8_t mavlink_msg_wk_log_gnss_get_numsv(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  69);
}

/**
 * @brief Get field fixtype from wk_log_gnss message
 *
 * @return  fixtype
 */
static inline uint8_t mavlink_msg_wk_log_gnss_get_fixtype(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  70);
}

/**
 * @brief Get field height from wk_log_gnss message
 *
 * @return  height
 */
static inline float mavlink_msg_wk_log_gnss_get_height(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field latitude from wk_log_gnss message
 *
 * @return  latitude
 */
static inline int32_t mavlink_msg_wk_log_gnss_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field longitude from wk_log_gnss message
 *
 * @return  longitude
 */
static inline int32_t mavlink_msg_wk_log_gnss_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field update_flag from wk_log_gnss message
 *
 * @return  update_flag
 */
static inline uint8_t mavlink_msg_wk_log_gnss_get_update_flag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  71);
}

/**
 * @brief Get field timegap from wk_log_gnss message
 *
 * @return  timegap
 */
static inline float mavlink_msg_wk_log_gnss_get_timegap(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field horizontal_acc from wk_log_gnss message
 *
 * @return  horizontal_acc
 */
static inline float mavlink_msg_wk_log_gnss_get_horizontal_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field vertical_acc from wk_log_gnss message
 *
 * @return  vertical_acc
 */
static inline float mavlink_msg_wk_log_gnss_get_vertical_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field velocity_acc from wk_log_gnss message
 *
 * @return  velocity_acc
 */
static inline float mavlink_msg_wk_log_gnss_get_velocity_acc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field gps_pos_dop from wk_log_gnss message
 *
 * @return  gps_pos_dop
 */
static inline float mavlink_msg_wk_log_gnss_get_gps_pos_dop(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field ground_speed from wk_log_gnss message
 *
 * @return  ground_speed
 */
static inline float mavlink_msg_wk_log_gnss_get_ground_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field alt_vel from wk_log_gnss message
 *
 * @return  alt_vel
 */
static inline float mavlink_msg_wk_log_gnss_get_alt_vel(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field vel_e from wk_log_gnss message
 *
 * @return  vel_e
 */
static inline float mavlink_msg_wk_log_gnss_get_vel_e(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field vel_n from wk_log_gnss message
 *
 * @return  vel_n
 */
static inline float mavlink_msg_wk_log_gnss_get_vel_n(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field vel_d from wk_log_gnss message
 *
 * @return  vel_d
 */
static inline float mavlink_msg_wk_log_gnss_get_vel_d(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field rtk_yaw from wk_log_gnss message
 *
 * @return  rtk_yaw
 */
static inline float mavlink_msg_wk_log_gnss_get_rtk_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field rtk_yaw_health from wk_log_gnss message
 *
 * @return  rtk_yaw_health
 */
static inline float mavlink_msg_wk_log_gnss_get_rtk_yaw_health(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Decode a wk_log_gnss message into a struct
 *
 * @param msg The message to decode
 * @param wk_log_gnss C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_log_gnss_decode(const mavlink_message_t* msg, mavlink_wk_log_gnss_t* wk_log_gnss)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_log_gnss->timestamp = mavlink_msg_wk_log_gnss_get_timestamp(msg);
    wk_log_gnss->height = mavlink_msg_wk_log_gnss_get_height(msg);
    wk_log_gnss->latitude = mavlink_msg_wk_log_gnss_get_latitude(msg);
    wk_log_gnss->longitude = mavlink_msg_wk_log_gnss_get_longitude(msg);
    wk_log_gnss->timegap = mavlink_msg_wk_log_gnss_get_timegap(msg);
    wk_log_gnss->horizontal_acc = mavlink_msg_wk_log_gnss_get_horizontal_acc(msg);
    wk_log_gnss->vertical_acc = mavlink_msg_wk_log_gnss_get_vertical_acc(msg);
    wk_log_gnss->velocity_acc = mavlink_msg_wk_log_gnss_get_velocity_acc(msg);
    wk_log_gnss->gps_pos_dop = mavlink_msg_wk_log_gnss_get_gps_pos_dop(msg);
    wk_log_gnss->ground_speed = mavlink_msg_wk_log_gnss_get_ground_speed(msg);
    wk_log_gnss->alt_vel = mavlink_msg_wk_log_gnss_get_alt_vel(msg);
    wk_log_gnss->vel_e = mavlink_msg_wk_log_gnss_get_vel_e(msg);
    wk_log_gnss->vel_n = mavlink_msg_wk_log_gnss_get_vel_n(msg);
    wk_log_gnss->vel_d = mavlink_msg_wk_log_gnss_get_vel_d(msg);
    wk_log_gnss->rtk_yaw = mavlink_msg_wk_log_gnss_get_rtk_yaw(msg);
    wk_log_gnss->rtk_yaw_health = mavlink_msg_wk_log_gnss_get_rtk_yaw_health(msg);
    wk_log_gnss->gnss_detected = mavlink_msg_wk_log_gnss_get_gnss_detected(msg);
    wk_log_gnss->numsv = mavlink_msg_wk_log_gnss_get_numsv(msg);
    wk_log_gnss->fixtype = mavlink_msg_wk_log_gnss_get_fixtype(msg);
    wk_log_gnss->update_flag = mavlink_msg_wk_log_gnss_get_update_flag(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_LOG_GNSS_LEN? msg->len : MAVLINK_MSG_ID_WK_LOG_GNSS_LEN;
        memset(wk_log_gnss, 0, MAVLINK_MSG_ID_WK_LOG_GNSS_LEN);
    memcpy(wk_log_gnss, _MAV_PAYLOAD(msg), len);
#endif
}
