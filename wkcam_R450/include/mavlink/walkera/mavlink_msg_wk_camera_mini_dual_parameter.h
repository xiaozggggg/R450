#pragma once
// MESSAGE WK_CAMERA_MINI_DUAL_PARAMETER PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER 8068


typedef struct __mavlink_wk_camera_mini_dual_parameter_t {
 uint16_t alarm_value; /*<  alarm value*/
 uint8_t direction; /*<  0:APP -> camera  ; 1: camera -> APP*/
 uint8_t colorize_type; /*<  see HSYK_CAM_PCOLOR_MODE*/
 uint8_t pip_mode; /*<  see WK_CAMERA_R500_DUAL_PIP_MODE*/
 uint8_t alarm_onoff; /*<  alarm  onoff*/
 uint8_t alarm_status; /*<  alarm status*/
} mavlink_wk_camera_mini_dual_parameter_t;

#define MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN 7
#define MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_MIN_LEN 7
#define MAVLINK_MSG_ID_8068_LEN 7
#define MAVLINK_MSG_ID_8068_MIN_LEN 7

#define MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_CRC 162
#define MAVLINK_MSG_ID_8068_CRC 162



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_MINI_DUAL_PARAMETER { \
    8068, \
    "WK_CAMERA_MINI_DUAL_PARAMETER", \
    6, \
    {  { "direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_camera_mini_dual_parameter_t, direction) }, \
         { "colorize_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_camera_mini_dual_parameter_t, colorize_type) }, \
         { "pip_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_camera_mini_dual_parameter_t, pip_mode) }, \
         { "alarm_onoff", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_camera_mini_dual_parameter_t, alarm_onoff) }, \
         { "alarm_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_camera_mini_dual_parameter_t, alarm_status) }, \
         { "alarm_value", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wk_camera_mini_dual_parameter_t, alarm_value) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_MINI_DUAL_PARAMETER { \
    "WK_CAMERA_MINI_DUAL_PARAMETER", \
    6, \
    {  { "direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_camera_mini_dual_parameter_t, direction) }, \
         { "colorize_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_camera_mini_dual_parameter_t, colorize_type) }, \
         { "pip_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_camera_mini_dual_parameter_t, pip_mode) }, \
         { "alarm_onoff", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_camera_mini_dual_parameter_t, alarm_onoff) }, \
         { "alarm_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_camera_mini_dual_parameter_t, alarm_status) }, \
         { "alarm_value", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wk_camera_mini_dual_parameter_t, alarm_value) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_mini_dual_parameter message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param direction  0:APP -> camera  ; 1: camera -> APP
 * @param colorize_type  see HSYK_CAM_PCOLOR_MODE
 * @param pip_mode  see WK_CAMERA_R500_DUAL_PIP_MODE
 * @param alarm_onoff  alarm  onoff
 * @param alarm_status  alarm status
 * @param alarm_value  alarm value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_parameter_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t direction, uint8_t colorize_type, uint8_t pip_mode, uint8_t alarm_onoff, uint8_t alarm_status, uint16_t alarm_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN];
    _mav_put_uint16_t(buf, 0, alarm_value);
    _mav_put_uint8_t(buf, 2, direction);
    _mav_put_uint8_t(buf, 3, colorize_type);
    _mav_put_uint8_t(buf, 4, pip_mode);
    _mav_put_uint8_t(buf, 5, alarm_onoff);
    _mav_put_uint8_t(buf, 6, alarm_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN);
#else
    mavlink_wk_camera_mini_dual_parameter_t packet;
    packet.alarm_value = alarm_value;
    packet.direction = direction;
    packet.colorize_type = colorize_type;
    packet.pip_mode = pip_mode;
    packet.alarm_onoff = alarm_onoff;
    packet.alarm_status = alarm_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_CRC);
}

/**
 * @brief Pack a wk_camera_mini_dual_parameter message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param direction  0:APP -> camera  ; 1: camera -> APP
 * @param colorize_type  see HSYK_CAM_PCOLOR_MODE
 * @param pip_mode  see WK_CAMERA_R500_DUAL_PIP_MODE
 * @param alarm_onoff  alarm  onoff
 * @param alarm_status  alarm status
 * @param alarm_value  alarm value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_parameter_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t direction,uint8_t colorize_type,uint8_t pip_mode,uint8_t alarm_onoff,uint8_t alarm_status,uint16_t alarm_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN];
    _mav_put_uint16_t(buf, 0, alarm_value);
    _mav_put_uint8_t(buf, 2, direction);
    _mav_put_uint8_t(buf, 3, colorize_type);
    _mav_put_uint8_t(buf, 4, pip_mode);
    _mav_put_uint8_t(buf, 5, alarm_onoff);
    _mav_put_uint8_t(buf, 6, alarm_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN);
#else
    mavlink_wk_camera_mini_dual_parameter_t packet;
    packet.alarm_value = alarm_value;
    packet.direction = direction;
    packet.colorize_type = colorize_type;
    packet.pip_mode = pip_mode;
    packet.alarm_onoff = alarm_onoff;
    packet.alarm_status = alarm_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_CRC);
}

/**
 * @brief Encode a wk_camera_mini_dual_parameter struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_mini_dual_parameter C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_parameter_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_mini_dual_parameter_t* wk_camera_mini_dual_parameter)
{
    return mavlink_msg_wk_camera_mini_dual_parameter_pack(system_id, component_id, msg, wk_camera_mini_dual_parameter->direction, wk_camera_mini_dual_parameter->colorize_type, wk_camera_mini_dual_parameter->pip_mode, wk_camera_mini_dual_parameter->alarm_onoff, wk_camera_mini_dual_parameter->alarm_status, wk_camera_mini_dual_parameter->alarm_value);
}

/**
 * @brief Encode a wk_camera_mini_dual_parameter struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_mini_dual_parameter C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_parameter_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_mini_dual_parameter_t* wk_camera_mini_dual_parameter)
{
    return mavlink_msg_wk_camera_mini_dual_parameter_pack_chan(system_id, component_id, chan, msg, wk_camera_mini_dual_parameter->direction, wk_camera_mini_dual_parameter->colorize_type, wk_camera_mini_dual_parameter->pip_mode, wk_camera_mini_dual_parameter->alarm_onoff, wk_camera_mini_dual_parameter->alarm_status, wk_camera_mini_dual_parameter->alarm_value);
}

/**
 * @brief Send a wk_camera_mini_dual_parameter message
 * @param chan MAVLink channel to send the message
 *
 * @param direction  0:APP -> camera  ; 1: camera -> APP
 * @param colorize_type  see HSYK_CAM_PCOLOR_MODE
 * @param pip_mode  see WK_CAMERA_R500_DUAL_PIP_MODE
 * @param alarm_onoff  alarm  onoff
 * @param alarm_status  alarm status
 * @param alarm_value  alarm value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_mini_dual_parameter_send(mavlink_channel_t chan, uint8_t direction, uint8_t colorize_type, uint8_t pip_mode, uint8_t alarm_onoff, uint8_t alarm_status, uint16_t alarm_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN];
    _mav_put_uint16_t(buf, 0, alarm_value);
    _mav_put_uint8_t(buf, 2, direction);
    _mav_put_uint8_t(buf, 3, colorize_type);
    _mav_put_uint8_t(buf, 4, pip_mode);
    _mav_put_uint8_t(buf, 5, alarm_onoff);
    _mav_put_uint8_t(buf, 6, alarm_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER, buf, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_CRC);
#else
    mavlink_wk_camera_mini_dual_parameter_t packet;
    packet.alarm_value = alarm_value;
    packet.direction = direction;
    packet.colorize_type = colorize_type;
    packet.pip_mode = pip_mode;
    packet.alarm_onoff = alarm_onoff;
    packet.alarm_status = alarm_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_CRC);
#endif
}

/**
 * @brief Send a wk_camera_mini_dual_parameter message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_mini_dual_parameter_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_mini_dual_parameter_t* wk_camera_mini_dual_parameter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_mini_dual_parameter_send(chan, wk_camera_mini_dual_parameter->direction, wk_camera_mini_dual_parameter->colorize_type, wk_camera_mini_dual_parameter->pip_mode, wk_camera_mini_dual_parameter->alarm_onoff, wk_camera_mini_dual_parameter->alarm_status, wk_camera_mini_dual_parameter->alarm_value);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER, (const char *)wk_camera_mini_dual_parameter, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_mini_dual_parameter_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t direction, uint8_t colorize_type, uint8_t pip_mode, uint8_t alarm_onoff, uint8_t alarm_status, uint16_t alarm_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, alarm_value);
    _mav_put_uint8_t(buf, 2, direction);
    _mav_put_uint8_t(buf, 3, colorize_type);
    _mav_put_uint8_t(buf, 4, pip_mode);
    _mav_put_uint8_t(buf, 5, alarm_onoff);
    _mav_put_uint8_t(buf, 6, alarm_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER, buf, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_CRC);
#else
    mavlink_wk_camera_mini_dual_parameter_t *packet = (mavlink_wk_camera_mini_dual_parameter_t *)msgbuf;
    packet->alarm_value = alarm_value;
    packet->direction = direction;
    packet->colorize_type = colorize_type;
    packet->pip_mode = pip_mode;
    packet->alarm_onoff = alarm_onoff;
    packet->alarm_status = alarm_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_MINI_DUAL_PARAMETER UNPACKING


/**
 * @brief Get field direction from wk_camera_mini_dual_parameter message
 *
 * @return  0:APP -> camera  ; 1: camera -> APP
 */
static inline uint8_t mavlink_msg_wk_camera_mini_dual_parameter_get_direction(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field colorize_type from wk_camera_mini_dual_parameter message
 *
 * @return  see HSYK_CAM_PCOLOR_MODE
 */
static inline uint8_t mavlink_msg_wk_camera_mini_dual_parameter_get_colorize_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field pip_mode from wk_camera_mini_dual_parameter message
 *
 * @return  see WK_CAMERA_R500_DUAL_PIP_MODE
 */
static inline uint8_t mavlink_msg_wk_camera_mini_dual_parameter_get_pip_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field alarm_onoff from wk_camera_mini_dual_parameter message
 *
 * @return  alarm  onoff
 */
static inline uint8_t mavlink_msg_wk_camera_mini_dual_parameter_get_alarm_onoff(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field alarm_status from wk_camera_mini_dual_parameter message
 *
 * @return  alarm status
 */
static inline uint8_t mavlink_msg_wk_camera_mini_dual_parameter_get_alarm_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field alarm_value from wk_camera_mini_dual_parameter message
 *
 * @return  alarm value
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_parameter_get_alarm_value(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a wk_camera_mini_dual_parameter message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_mini_dual_parameter C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_mini_dual_parameter_decode(const mavlink_message_t* msg, mavlink_wk_camera_mini_dual_parameter_t* wk_camera_mini_dual_parameter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_mini_dual_parameter->alarm_value = mavlink_msg_wk_camera_mini_dual_parameter_get_alarm_value(msg);
    wk_camera_mini_dual_parameter->direction = mavlink_msg_wk_camera_mini_dual_parameter_get_direction(msg);
    wk_camera_mini_dual_parameter->colorize_type = mavlink_msg_wk_camera_mini_dual_parameter_get_colorize_type(msg);
    wk_camera_mini_dual_parameter->pip_mode = mavlink_msg_wk_camera_mini_dual_parameter_get_pip_mode(msg);
    wk_camera_mini_dual_parameter->alarm_onoff = mavlink_msg_wk_camera_mini_dual_parameter_get_alarm_onoff(msg);
    wk_camera_mini_dual_parameter->alarm_status = mavlink_msg_wk_camera_mini_dual_parameter_get_alarm_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN;
        memset(wk_camera_mini_dual_parameter, 0, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_PARAMETER_LEN);
    memcpy(wk_camera_mini_dual_parameter, _MAV_PAYLOAD(msg), len);
#endif
}
