#pragma once
// MESSAGE WK_20T_RANGING_PARAM PACKING

#define MAVLINK_MSG_ID_WK_20T_RANGING_PARAM 8515


typedef struct __mavlink_wk_20t_ranging_param_t {
 int32_t alt; /*<  */
 int32_t lat; /*<  */
 int32_t lng; /*<  */
 float yaw_angle; /*<  */
 float gimbal_pitch; /*<  */
 float gimbal_roll; /*<  */
 float gimbal_yaw; /*<  */
 uint8_t direction; /*<  camera ---> uav(0) uav ---> camera(1)*/
} mavlink_wk_20t_ranging_param_t;

#define MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN 29
#define MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_MIN_LEN 29
#define MAVLINK_MSG_ID_8515_LEN 29
#define MAVLINK_MSG_ID_8515_MIN_LEN 29

#define MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_CRC 208
#define MAVLINK_MSG_ID_8515_CRC 208



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_20T_RANGING_PARAM { \
    8515, \
    "WK_20T_RANGING_PARAM", \
    8, \
    {  { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_wk_20t_ranging_param_t, alt) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_wk_20t_ranging_param_t, lat) }, \
         { "lng", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_20t_ranging_param_t, lng) }, \
         { "yaw_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_20t_ranging_param_t, yaw_angle) }, \
         { "gimbal_pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_20t_ranging_param_t, gimbal_pitch) }, \
         { "gimbal_roll", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_20t_ranging_param_t, gimbal_roll) }, \
         { "gimbal_yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wk_20t_ranging_param_t, gimbal_yaw) }, \
         { "direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_wk_20t_ranging_param_t, direction) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_20T_RANGING_PARAM { \
    "WK_20T_RANGING_PARAM", \
    8, \
    {  { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_wk_20t_ranging_param_t, alt) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_wk_20t_ranging_param_t, lat) }, \
         { "lng", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_20t_ranging_param_t, lng) }, \
         { "yaw_angle", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_20t_ranging_param_t, yaw_angle) }, \
         { "gimbal_pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_20t_ranging_param_t, gimbal_pitch) }, \
         { "gimbal_roll", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_20t_ranging_param_t, gimbal_roll) }, \
         { "gimbal_yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wk_20t_ranging_param_t, gimbal_yaw) }, \
         { "direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_wk_20t_ranging_param_t, direction) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_20t_ranging_param message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param alt  
 * @param lat  
 * @param lng  
 * @param yaw_angle  
 * @param gimbal_pitch  
 * @param gimbal_roll  
 * @param gimbal_yaw  
 * @param direction  camera ---> uav(0) uav ---> camera(1)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_20t_ranging_param_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int32_t alt, int32_t lat, int32_t lng, float yaw_angle, float gimbal_pitch, float gimbal_roll, float gimbal_yaw, uint8_t direction)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN];
    _mav_put_int32_t(buf, 0, alt);
    _mav_put_int32_t(buf, 4, lat);
    _mav_put_int32_t(buf, 8, lng);
    _mav_put_float(buf, 12, yaw_angle);
    _mav_put_float(buf, 16, gimbal_pitch);
    _mav_put_float(buf, 20, gimbal_roll);
    _mav_put_float(buf, 24, gimbal_yaw);
    _mav_put_uint8_t(buf, 28, direction);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN);
#else
    mavlink_wk_20t_ranging_param_t packet;
    packet.alt = alt;
    packet.lat = lat;
    packet.lng = lng;
    packet.yaw_angle = yaw_angle;
    packet.gimbal_pitch = gimbal_pitch;
    packet.gimbal_roll = gimbal_roll;
    packet.gimbal_yaw = gimbal_yaw;
    packet.direction = direction;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_20T_RANGING_PARAM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_CRC);
}

/**
 * @brief Pack a wk_20t_ranging_param message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param alt  
 * @param lat  
 * @param lng  
 * @param yaw_angle  
 * @param gimbal_pitch  
 * @param gimbal_roll  
 * @param gimbal_yaw  
 * @param direction  camera ---> uav(0) uav ---> camera(1)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_20t_ranging_param_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int32_t alt,int32_t lat,int32_t lng,float yaw_angle,float gimbal_pitch,float gimbal_roll,float gimbal_yaw,uint8_t direction)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN];
    _mav_put_int32_t(buf, 0, alt);
    _mav_put_int32_t(buf, 4, lat);
    _mav_put_int32_t(buf, 8, lng);
    _mav_put_float(buf, 12, yaw_angle);
    _mav_put_float(buf, 16, gimbal_pitch);
    _mav_put_float(buf, 20, gimbal_roll);
    _mav_put_float(buf, 24, gimbal_yaw);
    _mav_put_uint8_t(buf, 28, direction);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN);
#else
    mavlink_wk_20t_ranging_param_t packet;
    packet.alt = alt;
    packet.lat = lat;
    packet.lng = lng;
    packet.yaw_angle = yaw_angle;
    packet.gimbal_pitch = gimbal_pitch;
    packet.gimbal_roll = gimbal_roll;
    packet.gimbal_yaw = gimbal_yaw;
    packet.direction = direction;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_20T_RANGING_PARAM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_CRC);
}

/**
 * @brief Encode a wk_20t_ranging_param struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_20t_ranging_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_20t_ranging_param_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_20t_ranging_param_t* wk_20t_ranging_param)
{
    return mavlink_msg_wk_20t_ranging_param_pack(system_id, component_id, msg, wk_20t_ranging_param->alt, wk_20t_ranging_param->lat, wk_20t_ranging_param->lng, wk_20t_ranging_param->yaw_angle, wk_20t_ranging_param->gimbal_pitch, wk_20t_ranging_param->gimbal_roll, wk_20t_ranging_param->gimbal_yaw, wk_20t_ranging_param->direction);
}

/**
 * @brief Encode a wk_20t_ranging_param struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_20t_ranging_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_20t_ranging_param_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_20t_ranging_param_t* wk_20t_ranging_param)
{
    return mavlink_msg_wk_20t_ranging_param_pack_chan(system_id, component_id, chan, msg, wk_20t_ranging_param->alt, wk_20t_ranging_param->lat, wk_20t_ranging_param->lng, wk_20t_ranging_param->yaw_angle, wk_20t_ranging_param->gimbal_pitch, wk_20t_ranging_param->gimbal_roll, wk_20t_ranging_param->gimbal_yaw, wk_20t_ranging_param->direction);
}

/**
 * @brief Send a wk_20t_ranging_param message
 * @param chan MAVLink channel to send the message
 *
 * @param alt  
 * @param lat  
 * @param lng  
 * @param yaw_angle  
 * @param gimbal_pitch  
 * @param gimbal_roll  
 * @param gimbal_yaw  
 * @param direction  camera ---> uav(0) uav ---> camera(1)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_20t_ranging_param_send(mavlink_channel_t chan, int32_t alt, int32_t lat, int32_t lng, float yaw_angle, float gimbal_pitch, float gimbal_roll, float gimbal_yaw, uint8_t direction)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN];
    _mav_put_int32_t(buf, 0, alt);
    _mav_put_int32_t(buf, 4, lat);
    _mav_put_int32_t(buf, 8, lng);
    _mav_put_float(buf, 12, yaw_angle);
    _mav_put_float(buf, 16, gimbal_pitch);
    _mav_put_float(buf, 20, gimbal_roll);
    _mav_put_float(buf, 24, gimbal_yaw);
    _mav_put_uint8_t(buf, 28, direction);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM, buf, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_CRC);
#else
    mavlink_wk_20t_ranging_param_t packet;
    packet.alt = alt;
    packet.lat = lat;
    packet.lng = lng;
    packet.yaw_angle = yaw_angle;
    packet.gimbal_pitch = gimbal_pitch;
    packet.gimbal_roll = gimbal_roll;
    packet.gimbal_yaw = gimbal_yaw;
    packet.direction = direction;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM, (const char *)&packet, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_CRC);
#endif
}

/**
 * @brief Send a wk_20t_ranging_param message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_20t_ranging_param_send_struct(mavlink_channel_t chan, const mavlink_wk_20t_ranging_param_t* wk_20t_ranging_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_20t_ranging_param_send(chan, wk_20t_ranging_param->alt, wk_20t_ranging_param->lat, wk_20t_ranging_param->lng, wk_20t_ranging_param->yaw_angle, wk_20t_ranging_param->gimbal_pitch, wk_20t_ranging_param->gimbal_roll, wk_20t_ranging_param->gimbal_yaw, wk_20t_ranging_param->direction);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM, (const char *)wk_20t_ranging_param, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_20t_ranging_param_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t alt, int32_t lat, int32_t lng, float yaw_angle, float gimbal_pitch, float gimbal_roll, float gimbal_yaw, uint8_t direction)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, alt);
    _mav_put_int32_t(buf, 4, lat);
    _mav_put_int32_t(buf, 8, lng);
    _mav_put_float(buf, 12, yaw_angle);
    _mav_put_float(buf, 16, gimbal_pitch);
    _mav_put_float(buf, 20, gimbal_roll);
    _mav_put_float(buf, 24, gimbal_yaw);
    _mav_put_uint8_t(buf, 28, direction);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM, buf, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_CRC);
#else
    mavlink_wk_20t_ranging_param_t *packet = (mavlink_wk_20t_ranging_param_t *)msgbuf;
    packet->alt = alt;
    packet->lat = lat;
    packet->lng = lng;
    packet->yaw_angle = yaw_angle;
    packet->gimbal_pitch = gimbal_pitch;
    packet->gimbal_roll = gimbal_roll;
    packet->gimbal_yaw = gimbal_yaw;
    packet->direction = direction;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM, (const char *)packet, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_20T_RANGING_PARAM UNPACKING


/**
 * @brief Get field alt from wk_20t_ranging_param message
 *
 * @return  
 */
static inline int32_t mavlink_msg_wk_20t_ranging_param_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field lat from wk_20t_ranging_param message
 *
 * @return  
 */
static inline int32_t mavlink_msg_wk_20t_ranging_param_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field lng from wk_20t_ranging_param message
 *
 * @return  
 */
static inline int32_t mavlink_msg_wk_20t_ranging_param_get_lng(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field yaw_angle from wk_20t_ranging_param message
 *
 * @return  
 */
static inline float mavlink_msg_wk_20t_ranging_param_get_yaw_angle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field gimbal_pitch from wk_20t_ranging_param message
 *
 * @return  
 */
static inline float mavlink_msg_wk_20t_ranging_param_get_gimbal_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field gimbal_roll from wk_20t_ranging_param message
 *
 * @return  
 */
static inline float mavlink_msg_wk_20t_ranging_param_get_gimbal_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field gimbal_yaw from wk_20t_ranging_param message
 *
 * @return  
 */
static inline float mavlink_msg_wk_20t_ranging_param_get_gimbal_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field direction from wk_20t_ranging_param message
 *
 * @return  camera ---> uav(0) uav ---> camera(1)
 */
static inline uint8_t mavlink_msg_wk_20t_ranging_param_get_direction(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Decode a wk_20t_ranging_param message into a struct
 *
 * @param msg The message to decode
 * @param wk_20t_ranging_param C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_20t_ranging_param_decode(const mavlink_message_t* msg, mavlink_wk_20t_ranging_param_t* wk_20t_ranging_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_20t_ranging_param->alt = mavlink_msg_wk_20t_ranging_param_get_alt(msg);
    wk_20t_ranging_param->lat = mavlink_msg_wk_20t_ranging_param_get_lat(msg);
    wk_20t_ranging_param->lng = mavlink_msg_wk_20t_ranging_param_get_lng(msg);
    wk_20t_ranging_param->yaw_angle = mavlink_msg_wk_20t_ranging_param_get_yaw_angle(msg);
    wk_20t_ranging_param->gimbal_pitch = mavlink_msg_wk_20t_ranging_param_get_gimbal_pitch(msg);
    wk_20t_ranging_param->gimbal_roll = mavlink_msg_wk_20t_ranging_param_get_gimbal_roll(msg);
    wk_20t_ranging_param->gimbal_yaw = mavlink_msg_wk_20t_ranging_param_get_gimbal_yaw(msg);
    wk_20t_ranging_param->direction = mavlink_msg_wk_20t_ranging_param_get_direction(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN? msg->len : MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN;
        memset(wk_20t_ranging_param, 0, MAVLINK_MSG_ID_WK_20T_RANGING_PARAM_LEN);
    memcpy(wk_20t_ranging_param, _MAV_PAYLOAD(msg), len);
#endif
}
