#pragma once
// MESSAGE WK_RC_PARAMETER PACKING

#define MAVLINK_MSG_ID_WK_RC_PARAMETER 8072


typedef struct __mavlink_wk_rc_parameter_t {
 uint8_t rc_control_mode; /*<  rc control mode see WK_RC_CONTROL_MODE*/
 uint8_t reserved[16]; /*<  reserved*/
} mavlink_wk_rc_parameter_t;

#define MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN 17
#define MAVLINK_MSG_ID_WK_RC_PARAMETER_MIN_LEN 17
#define MAVLINK_MSG_ID_8072_LEN 17
#define MAVLINK_MSG_ID_8072_MIN_LEN 17

#define MAVLINK_MSG_ID_WK_RC_PARAMETER_CRC 57
#define MAVLINK_MSG_ID_8072_CRC 57

#define MAVLINK_MSG_WK_RC_PARAMETER_FIELD_RESERVED_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_RC_PARAMETER { \
    8072, \
    "WK_RC_PARAMETER", \
    2, \
    {  { "rc_control_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_rc_parameter_t, rc_control_mode) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 16, 1, offsetof(mavlink_wk_rc_parameter_t, reserved) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_RC_PARAMETER { \
    "WK_RC_PARAMETER", \
    2, \
    {  { "rc_control_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_rc_parameter_t, rc_control_mode) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 16, 1, offsetof(mavlink_wk_rc_parameter_t, reserved) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_rc_parameter message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param rc_control_mode  rc control mode see WK_RC_CONTROL_MODE
 * @param reserved  reserved
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_rc_parameter_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t rc_control_mode, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN];
    _mav_put_uint8_t(buf, 0, rc_control_mode);
    _mav_put_uint8_t_array(buf, 1, reserved, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN);
#else
    mavlink_wk_rc_parameter_t packet;
    packet.rc_control_mode = rc_control_mode;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_RC_PARAMETER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_RC_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN, MAVLINK_MSG_ID_WK_RC_PARAMETER_CRC);
}

/**
 * @brief Pack a wk_rc_parameter message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rc_control_mode  rc control mode see WK_RC_CONTROL_MODE
 * @param reserved  reserved
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_rc_parameter_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t rc_control_mode,const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN];
    _mav_put_uint8_t(buf, 0, rc_control_mode);
    _mav_put_uint8_t_array(buf, 1, reserved, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN);
#else
    mavlink_wk_rc_parameter_t packet;
    packet.rc_control_mode = rc_control_mode;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_RC_PARAMETER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_RC_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN, MAVLINK_MSG_ID_WK_RC_PARAMETER_CRC);
}

/**
 * @brief Encode a wk_rc_parameter struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_rc_parameter C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_rc_parameter_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_rc_parameter_t* wk_rc_parameter)
{
    return mavlink_msg_wk_rc_parameter_pack(system_id, component_id, msg, wk_rc_parameter->rc_control_mode, wk_rc_parameter->reserved);
}

/**
 * @brief Encode a wk_rc_parameter struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_rc_parameter C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_rc_parameter_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_rc_parameter_t* wk_rc_parameter)
{
    return mavlink_msg_wk_rc_parameter_pack_chan(system_id, component_id, chan, msg, wk_rc_parameter->rc_control_mode, wk_rc_parameter->reserved);
}

/**
 * @brief Send a wk_rc_parameter message
 * @param chan MAVLink channel to send the message
 *
 * @param rc_control_mode  rc control mode see WK_RC_CONTROL_MODE
 * @param reserved  reserved
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_rc_parameter_send(mavlink_channel_t chan, uint8_t rc_control_mode, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN];
    _mav_put_uint8_t(buf, 0, rc_control_mode);
    _mav_put_uint8_t_array(buf, 1, reserved, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RC_PARAMETER, buf, MAVLINK_MSG_ID_WK_RC_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN, MAVLINK_MSG_ID_WK_RC_PARAMETER_CRC);
#else
    mavlink_wk_rc_parameter_t packet;
    packet.rc_control_mode = rc_control_mode;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RC_PARAMETER, (const char *)&packet, MAVLINK_MSG_ID_WK_RC_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN, MAVLINK_MSG_ID_WK_RC_PARAMETER_CRC);
#endif
}

/**
 * @brief Send a wk_rc_parameter message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_rc_parameter_send_struct(mavlink_channel_t chan, const mavlink_wk_rc_parameter_t* wk_rc_parameter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_rc_parameter_send(chan, wk_rc_parameter->rc_control_mode, wk_rc_parameter->reserved);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RC_PARAMETER, (const char *)wk_rc_parameter, MAVLINK_MSG_ID_WK_RC_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN, MAVLINK_MSG_ID_WK_RC_PARAMETER_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_rc_parameter_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t rc_control_mode, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, rc_control_mode);
    _mav_put_uint8_t_array(buf, 1, reserved, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RC_PARAMETER, buf, MAVLINK_MSG_ID_WK_RC_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN, MAVLINK_MSG_ID_WK_RC_PARAMETER_CRC);
#else
    mavlink_wk_rc_parameter_t *packet = (mavlink_wk_rc_parameter_t *)msgbuf;
    packet->rc_control_mode = rc_control_mode;
    mav_array_memcpy(packet->reserved, reserved, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RC_PARAMETER, (const char *)packet, MAVLINK_MSG_ID_WK_RC_PARAMETER_MIN_LEN, MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN, MAVLINK_MSG_ID_WK_RC_PARAMETER_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_RC_PARAMETER UNPACKING


/**
 * @brief Get field rc_control_mode from wk_rc_parameter message
 *
 * @return  rc control mode see WK_RC_CONTROL_MODE
 */
static inline uint8_t mavlink_msg_wk_rc_parameter_get_rc_control_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field reserved from wk_rc_parameter message
 *
 * @return  reserved
 */
static inline uint16_t mavlink_msg_wk_rc_parameter_get_reserved(const mavlink_message_t* msg, uint8_t *reserved)
{
    return _MAV_RETURN_uint8_t_array(msg, reserved, 16,  1);
}

/**
 * @brief Decode a wk_rc_parameter message into a struct
 *
 * @param msg The message to decode
 * @param wk_rc_parameter C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_rc_parameter_decode(const mavlink_message_t* msg, mavlink_wk_rc_parameter_t* wk_rc_parameter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_rc_parameter->rc_control_mode = mavlink_msg_wk_rc_parameter_get_rc_control_mode(msg);
    mavlink_msg_wk_rc_parameter_get_reserved(msg, wk_rc_parameter->reserved);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN? msg->len : MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN;
        memset(wk_rc_parameter, 0, MAVLINK_MSG_ID_WK_RC_PARAMETER_LEN);
    memcpy(wk_rc_parameter, _MAV_PAYLOAD(msg), len);
#endif
}
