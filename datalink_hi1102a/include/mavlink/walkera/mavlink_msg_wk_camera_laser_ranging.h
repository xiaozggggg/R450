#pragma once
// MESSAGE WK_CAMERA_LASER_RANGING PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING 8076


typedef struct __mavlink_wk_camera_laser_ranging_t {
 float x; /*<  x*/
 float y; /*<  y*/
 uint8_t direction; /*<  see WK_CMD_DIRECTION*/
 uint8_t reserved[8]; /*<  */
} mavlink_wk_camera_laser_ranging_t;

#define MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN 17
#define MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_MIN_LEN 17
#define MAVLINK_MSG_ID_8076_LEN 17
#define MAVLINK_MSG_ID_8076_MIN_LEN 17

#define MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_CRC 128
#define MAVLINK_MSG_ID_8076_CRC 128

#define MAVLINK_MSG_WK_CAMERA_LASER_RANGING_FIELD_RESERVED_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_LASER_RANGING { \
    8076, \
    "WK_CAMERA_LASER_RANGING", \
    4, \
    {  { "direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wk_camera_laser_ranging_t, direction) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_camera_laser_ranging_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_camera_laser_ranging_t, y) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 8, 9, offsetof(mavlink_wk_camera_laser_ranging_t, reserved) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_LASER_RANGING { \
    "WK_CAMERA_LASER_RANGING", \
    4, \
    {  { "direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wk_camera_laser_ranging_t, direction) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_camera_laser_ranging_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_camera_laser_ranging_t, y) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 8, 9, offsetof(mavlink_wk_camera_laser_ranging_t, reserved) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_laser_ranging message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param direction  see WK_CMD_DIRECTION
 * @param x  x
 * @param y  y
 * @param reserved  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_laser_ranging_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t direction, float x, float y, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_uint8_t(buf, 8, direction);
    _mav_put_uint8_t_array(buf, 9, reserved, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN);
#else
    mavlink_wk_camera_laser_ranging_t packet;
    packet.x = x;
    packet.y = y;
    packet.direction = direction;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_CRC);
}

/**
 * @brief Pack a wk_camera_laser_ranging message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param direction  see WK_CMD_DIRECTION
 * @param x  x
 * @param y  y
 * @param reserved  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_laser_ranging_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t direction,float x,float y,const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_uint8_t(buf, 8, direction);
    _mav_put_uint8_t_array(buf, 9, reserved, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN);
#else
    mavlink_wk_camera_laser_ranging_t packet;
    packet.x = x;
    packet.y = y;
    packet.direction = direction;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_CRC);
}

/**
 * @brief Encode a wk_camera_laser_ranging struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_laser_ranging C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_laser_ranging_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_laser_ranging_t* wk_camera_laser_ranging)
{
    return mavlink_msg_wk_camera_laser_ranging_pack(system_id, component_id, msg, wk_camera_laser_ranging->direction, wk_camera_laser_ranging->x, wk_camera_laser_ranging->y, wk_camera_laser_ranging->reserved);
}

/**
 * @brief Encode a wk_camera_laser_ranging struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_laser_ranging C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_laser_ranging_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_laser_ranging_t* wk_camera_laser_ranging)
{
    return mavlink_msg_wk_camera_laser_ranging_pack_chan(system_id, component_id, chan, msg, wk_camera_laser_ranging->direction, wk_camera_laser_ranging->x, wk_camera_laser_ranging->y, wk_camera_laser_ranging->reserved);
}

/**
 * @brief Send a wk_camera_laser_ranging message
 * @param chan MAVLink channel to send the message
 *
 * @param direction  see WK_CMD_DIRECTION
 * @param x  x
 * @param y  y
 * @param reserved  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_laser_ranging_send(mavlink_channel_t chan, uint8_t direction, float x, float y, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_uint8_t(buf, 8, direction);
    _mav_put_uint8_t_array(buf, 9, reserved, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING, buf, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_CRC);
#else
    mavlink_wk_camera_laser_ranging_t packet;
    packet.x = x;
    packet.y = y;
    packet.direction = direction;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_CRC);
#endif
}

/**
 * @brief Send a wk_camera_laser_ranging message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_laser_ranging_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_laser_ranging_t* wk_camera_laser_ranging)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_laser_ranging_send(chan, wk_camera_laser_ranging->direction, wk_camera_laser_ranging->x, wk_camera_laser_ranging->y, wk_camera_laser_ranging->reserved);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING, (const char *)wk_camera_laser_ranging, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_laser_ranging_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t direction, float x, float y, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_uint8_t(buf, 8, direction);
    _mav_put_uint8_t_array(buf, 9, reserved, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING, buf, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_CRC);
#else
    mavlink_wk_camera_laser_ranging_t *packet = (mavlink_wk_camera_laser_ranging_t *)msgbuf;
    packet->x = x;
    packet->y = y;
    packet->direction = direction;
    mav_array_memcpy(packet->reserved, reserved, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_LASER_RANGING UNPACKING


/**
 * @brief Get field direction from wk_camera_laser_ranging message
 *
 * @return  see WK_CMD_DIRECTION
 */
static inline uint8_t mavlink_msg_wk_camera_laser_ranging_get_direction(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field x from wk_camera_laser_ranging message
 *
 * @return  x
 */
static inline float mavlink_msg_wk_camera_laser_ranging_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field y from wk_camera_laser_ranging message
 *
 * @return  y
 */
static inline float mavlink_msg_wk_camera_laser_ranging_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field reserved from wk_camera_laser_ranging message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_camera_laser_ranging_get_reserved(const mavlink_message_t* msg, uint8_t *reserved)
{
    return _MAV_RETURN_uint8_t_array(msg, reserved, 8,  9);
}

/**
 * @brief Decode a wk_camera_laser_ranging message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_laser_ranging C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_laser_ranging_decode(const mavlink_message_t* msg, mavlink_wk_camera_laser_ranging_t* wk_camera_laser_ranging)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_laser_ranging->x = mavlink_msg_wk_camera_laser_ranging_get_x(msg);
    wk_camera_laser_ranging->y = mavlink_msg_wk_camera_laser_ranging_get_y(msg);
    wk_camera_laser_ranging->direction = mavlink_msg_wk_camera_laser_ranging_get_direction(msg);
    mavlink_msg_wk_camera_laser_ranging_get_reserved(msg, wk_camera_laser_ranging->reserved);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN;
        memset(wk_camera_laser_ranging, 0, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_LEN);
    memcpy(wk_camera_laser_ranging, _MAV_PAYLOAD(msg), len);
#endif
}
