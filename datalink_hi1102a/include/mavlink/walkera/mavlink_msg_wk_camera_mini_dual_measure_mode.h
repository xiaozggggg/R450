#pragma once
// MESSAGE WK_CAMERA_MINI_DUAL_MEASURE_MODE PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE 8069


typedef struct __mavlink_wk_camera_mini_dual_measure_mode_t {
 uint16_t measure_area_x; /*<  left top x*/
 uint16_t measure_area_y; /*<  left top y*/
 uint16_t measure_area_width; /*<  area width*/
 uint16_t measure_area_height; /*<  area height*/
 uint8_t direction; /*<  0:APP -> camera  ; 1: camera -> APP*/
 uint8_t measure_mode; /*<  see WK_CAMERA_R500_DUAL_MEASURE_MODE*/
} mavlink_wk_camera_mini_dual_measure_mode_t;

#define MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN 10
#define MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_MIN_LEN 10
#define MAVLINK_MSG_ID_8069_LEN 10
#define MAVLINK_MSG_ID_8069_MIN_LEN 10

#define MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_CRC 171
#define MAVLINK_MSG_ID_8069_CRC 171



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_MINI_DUAL_MEASURE_MODE { \
    8069, \
    "WK_CAMERA_MINI_DUAL_MEASURE_MODE", \
    6, \
    {  { "direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wk_camera_mini_dual_measure_mode_t, direction) }, \
         { "measure_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_wk_camera_mini_dual_measure_mode_t, measure_mode) }, \
         { "measure_area_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wk_camera_mini_dual_measure_mode_t, measure_area_x) }, \
         { "measure_area_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_wk_camera_mini_dual_measure_mode_t, measure_area_y) }, \
         { "measure_area_width", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_wk_camera_mini_dual_measure_mode_t, measure_area_width) }, \
         { "measure_area_height", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_wk_camera_mini_dual_measure_mode_t, measure_area_height) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_MINI_DUAL_MEASURE_MODE { \
    "WK_CAMERA_MINI_DUAL_MEASURE_MODE", \
    6, \
    {  { "direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wk_camera_mini_dual_measure_mode_t, direction) }, \
         { "measure_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_wk_camera_mini_dual_measure_mode_t, measure_mode) }, \
         { "measure_area_x", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wk_camera_mini_dual_measure_mode_t, measure_area_x) }, \
         { "measure_area_y", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_wk_camera_mini_dual_measure_mode_t, measure_area_y) }, \
         { "measure_area_width", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_wk_camera_mini_dual_measure_mode_t, measure_area_width) }, \
         { "measure_area_height", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_wk_camera_mini_dual_measure_mode_t, measure_area_height) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_mini_dual_measure_mode message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param direction  0:APP -> camera  ; 1: camera -> APP
 * @param measure_mode  see WK_CAMERA_R500_DUAL_MEASURE_MODE
 * @param measure_area_x  left top x
 * @param measure_area_y  left top y
 * @param measure_area_width  area width
 * @param measure_area_height  area height
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_measure_mode_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t direction, uint8_t measure_mode, uint16_t measure_area_x, uint16_t measure_area_y, uint16_t measure_area_width, uint16_t measure_area_height)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN];
    _mav_put_uint16_t(buf, 0, measure_area_x);
    _mav_put_uint16_t(buf, 2, measure_area_y);
    _mav_put_uint16_t(buf, 4, measure_area_width);
    _mav_put_uint16_t(buf, 6, measure_area_height);
    _mav_put_uint8_t(buf, 8, direction);
    _mav_put_uint8_t(buf, 9, measure_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN);
#else
    mavlink_wk_camera_mini_dual_measure_mode_t packet;
    packet.measure_area_x = measure_area_x;
    packet.measure_area_y = measure_area_y;
    packet.measure_area_width = measure_area_width;
    packet.measure_area_height = measure_area_height;
    packet.direction = direction;
    packet.measure_mode = measure_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_CRC);
}

/**
 * @brief Pack a wk_camera_mini_dual_measure_mode message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param direction  0:APP -> camera  ; 1: camera -> APP
 * @param measure_mode  see WK_CAMERA_R500_DUAL_MEASURE_MODE
 * @param measure_area_x  left top x
 * @param measure_area_y  left top y
 * @param measure_area_width  area width
 * @param measure_area_height  area height
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_measure_mode_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t direction,uint8_t measure_mode,uint16_t measure_area_x,uint16_t measure_area_y,uint16_t measure_area_width,uint16_t measure_area_height)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN];
    _mav_put_uint16_t(buf, 0, measure_area_x);
    _mav_put_uint16_t(buf, 2, measure_area_y);
    _mav_put_uint16_t(buf, 4, measure_area_width);
    _mav_put_uint16_t(buf, 6, measure_area_height);
    _mav_put_uint8_t(buf, 8, direction);
    _mav_put_uint8_t(buf, 9, measure_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN);
#else
    mavlink_wk_camera_mini_dual_measure_mode_t packet;
    packet.measure_area_x = measure_area_x;
    packet.measure_area_y = measure_area_y;
    packet.measure_area_width = measure_area_width;
    packet.measure_area_height = measure_area_height;
    packet.direction = direction;
    packet.measure_mode = measure_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_CRC);
}

/**
 * @brief Encode a wk_camera_mini_dual_measure_mode struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_mini_dual_measure_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_measure_mode_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_mini_dual_measure_mode_t* wk_camera_mini_dual_measure_mode)
{
    return mavlink_msg_wk_camera_mini_dual_measure_mode_pack(system_id, component_id, msg, wk_camera_mini_dual_measure_mode->direction, wk_camera_mini_dual_measure_mode->measure_mode, wk_camera_mini_dual_measure_mode->measure_area_x, wk_camera_mini_dual_measure_mode->measure_area_y, wk_camera_mini_dual_measure_mode->measure_area_width, wk_camera_mini_dual_measure_mode->measure_area_height);
}

/**
 * @brief Encode a wk_camera_mini_dual_measure_mode struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_mini_dual_measure_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_measure_mode_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_mini_dual_measure_mode_t* wk_camera_mini_dual_measure_mode)
{
    return mavlink_msg_wk_camera_mini_dual_measure_mode_pack_chan(system_id, component_id, chan, msg, wk_camera_mini_dual_measure_mode->direction, wk_camera_mini_dual_measure_mode->measure_mode, wk_camera_mini_dual_measure_mode->measure_area_x, wk_camera_mini_dual_measure_mode->measure_area_y, wk_camera_mini_dual_measure_mode->measure_area_width, wk_camera_mini_dual_measure_mode->measure_area_height);
}

/**
 * @brief Send a wk_camera_mini_dual_measure_mode message
 * @param chan MAVLink channel to send the message
 *
 * @param direction  0:APP -> camera  ; 1: camera -> APP
 * @param measure_mode  see WK_CAMERA_R500_DUAL_MEASURE_MODE
 * @param measure_area_x  left top x
 * @param measure_area_y  left top y
 * @param measure_area_width  area width
 * @param measure_area_height  area height
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_mini_dual_measure_mode_send(mavlink_channel_t chan, uint8_t direction, uint8_t measure_mode, uint16_t measure_area_x, uint16_t measure_area_y, uint16_t measure_area_width, uint16_t measure_area_height)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN];
    _mav_put_uint16_t(buf, 0, measure_area_x);
    _mav_put_uint16_t(buf, 2, measure_area_y);
    _mav_put_uint16_t(buf, 4, measure_area_width);
    _mav_put_uint16_t(buf, 6, measure_area_height);
    _mav_put_uint8_t(buf, 8, direction);
    _mav_put_uint8_t(buf, 9, measure_mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE, buf, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_CRC);
#else
    mavlink_wk_camera_mini_dual_measure_mode_t packet;
    packet.measure_area_x = measure_area_x;
    packet.measure_area_y = measure_area_y;
    packet.measure_area_width = measure_area_width;
    packet.measure_area_height = measure_area_height;
    packet.direction = direction;
    packet.measure_mode = measure_mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_CRC);
#endif
}

/**
 * @brief Send a wk_camera_mini_dual_measure_mode message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_mini_dual_measure_mode_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_mini_dual_measure_mode_t* wk_camera_mini_dual_measure_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_mini_dual_measure_mode_send(chan, wk_camera_mini_dual_measure_mode->direction, wk_camera_mini_dual_measure_mode->measure_mode, wk_camera_mini_dual_measure_mode->measure_area_x, wk_camera_mini_dual_measure_mode->measure_area_y, wk_camera_mini_dual_measure_mode->measure_area_width, wk_camera_mini_dual_measure_mode->measure_area_height);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE, (const char *)wk_camera_mini_dual_measure_mode, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_mini_dual_measure_mode_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t direction, uint8_t measure_mode, uint16_t measure_area_x, uint16_t measure_area_y, uint16_t measure_area_width, uint16_t measure_area_height)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, measure_area_x);
    _mav_put_uint16_t(buf, 2, measure_area_y);
    _mav_put_uint16_t(buf, 4, measure_area_width);
    _mav_put_uint16_t(buf, 6, measure_area_height);
    _mav_put_uint8_t(buf, 8, direction);
    _mav_put_uint8_t(buf, 9, measure_mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE, buf, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_CRC);
#else
    mavlink_wk_camera_mini_dual_measure_mode_t *packet = (mavlink_wk_camera_mini_dual_measure_mode_t *)msgbuf;
    packet->measure_area_x = measure_area_x;
    packet->measure_area_y = measure_area_y;
    packet->measure_area_width = measure_area_width;
    packet->measure_area_height = measure_area_height;
    packet->direction = direction;
    packet->measure_mode = measure_mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_MINI_DUAL_MEASURE_MODE UNPACKING


/**
 * @brief Get field direction from wk_camera_mini_dual_measure_mode message
 *
 * @return  0:APP -> camera  ; 1: camera -> APP
 */
static inline uint8_t mavlink_msg_wk_camera_mini_dual_measure_mode_get_direction(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field measure_mode from wk_camera_mini_dual_measure_mode message
 *
 * @return  see WK_CAMERA_R500_DUAL_MEASURE_MODE
 */
static inline uint8_t mavlink_msg_wk_camera_mini_dual_measure_mode_get_measure_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field measure_area_x from wk_camera_mini_dual_measure_mode message
 *
 * @return  left top x
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_measure_mode_get_measure_area_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field measure_area_y from wk_camera_mini_dual_measure_mode message
 *
 * @return  left top y
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_measure_mode_get_measure_area_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field measure_area_width from wk_camera_mini_dual_measure_mode message
 *
 * @return  area width
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_measure_mode_get_measure_area_width(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field measure_area_height from wk_camera_mini_dual_measure_mode message
 *
 * @return  area height
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_measure_mode_get_measure_area_height(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Decode a wk_camera_mini_dual_measure_mode message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_mini_dual_measure_mode C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_mini_dual_measure_mode_decode(const mavlink_message_t* msg, mavlink_wk_camera_mini_dual_measure_mode_t* wk_camera_mini_dual_measure_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_mini_dual_measure_mode->measure_area_x = mavlink_msg_wk_camera_mini_dual_measure_mode_get_measure_area_x(msg);
    wk_camera_mini_dual_measure_mode->measure_area_y = mavlink_msg_wk_camera_mini_dual_measure_mode_get_measure_area_y(msg);
    wk_camera_mini_dual_measure_mode->measure_area_width = mavlink_msg_wk_camera_mini_dual_measure_mode_get_measure_area_width(msg);
    wk_camera_mini_dual_measure_mode->measure_area_height = mavlink_msg_wk_camera_mini_dual_measure_mode_get_measure_area_height(msg);
    wk_camera_mini_dual_measure_mode->direction = mavlink_msg_wk_camera_mini_dual_measure_mode_get_direction(msg);
    wk_camera_mini_dual_measure_mode->measure_mode = mavlink_msg_wk_camera_mini_dual_measure_mode_get_measure_mode(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN;
        memset(wk_camera_mini_dual_measure_mode, 0, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_MEASURE_MODE_LEN);
    memcpy(wk_camera_mini_dual_measure_mode, _MAV_PAYLOAD(msg), len);
#endif
}
