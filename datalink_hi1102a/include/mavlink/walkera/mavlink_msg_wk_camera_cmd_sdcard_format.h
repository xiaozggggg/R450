#pragma once
// MESSAGE WK_CAMERA_CMD_SDCARD_FORMAT PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT 8044


typedef struct __mavlink_wk_camera_cmd_sdcard_format_t {
 uint8_t format_type; /*<  see num WKCAM_SDCARD_FORMAT_TYPE*/
 uint8_t response_code; /*<  see enum WKCAM_SDCARD_FORMAT_ACK*/
} mavlink_wk_camera_cmd_sdcard_format_t;

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN 2
#define MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_MIN_LEN 2
#define MAVLINK_MSG_ID_8044_LEN 2
#define MAVLINK_MSG_ID_8044_MIN_LEN 2

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_CRC 47
#define MAVLINK_MSG_ID_8044_CRC 47



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_SDCARD_FORMAT { \
    8044, \
    "WK_CAMERA_CMD_SDCARD_FORMAT", \
    2, \
    {  { "format_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_camera_cmd_sdcard_format_t, format_type) }, \
         { "response_code", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_camera_cmd_sdcard_format_t, response_code) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_SDCARD_FORMAT { \
    "WK_CAMERA_CMD_SDCARD_FORMAT", \
    2, \
    {  { "format_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_camera_cmd_sdcard_format_t, format_type) }, \
         { "response_code", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_camera_cmd_sdcard_format_t, response_code) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_cmd_sdcard_format message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param format_type  see num WKCAM_SDCARD_FORMAT_TYPE
 * @param response_code  see enum WKCAM_SDCARD_FORMAT_ACK
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_sdcard_format_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t format_type, uint8_t response_code)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN];
    _mav_put_uint8_t(buf, 0, format_type);
    _mav_put_uint8_t(buf, 1, response_code);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN);
#else
    mavlink_wk_camera_cmd_sdcard_format_t packet;
    packet.format_type = format_type;
    packet.response_code = response_code;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_CRC);
}

/**
 * @brief Pack a wk_camera_cmd_sdcard_format message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param format_type  see num WKCAM_SDCARD_FORMAT_TYPE
 * @param response_code  see enum WKCAM_SDCARD_FORMAT_ACK
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_sdcard_format_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t format_type,uint8_t response_code)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN];
    _mav_put_uint8_t(buf, 0, format_type);
    _mav_put_uint8_t(buf, 1, response_code);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN);
#else
    mavlink_wk_camera_cmd_sdcard_format_t packet;
    packet.format_type = format_type;
    packet.response_code = response_code;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_CRC);
}

/**
 * @brief Encode a wk_camera_cmd_sdcard_format struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_sdcard_format C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_sdcard_format_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_cmd_sdcard_format_t* wk_camera_cmd_sdcard_format)
{
    return mavlink_msg_wk_camera_cmd_sdcard_format_pack(system_id, component_id, msg, wk_camera_cmd_sdcard_format->format_type, wk_camera_cmd_sdcard_format->response_code);
}

/**
 * @brief Encode a wk_camera_cmd_sdcard_format struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_sdcard_format C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_sdcard_format_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_cmd_sdcard_format_t* wk_camera_cmd_sdcard_format)
{
    return mavlink_msg_wk_camera_cmd_sdcard_format_pack_chan(system_id, component_id, chan, msg, wk_camera_cmd_sdcard_format->format_type, wk_camera_cmd_sdcard_format->response_code);
}

/**
 * @brief Send a wk_camera_cmd_sdcard_format message
 * @param chan MAVLink channel to send the message
 *
 * @param format_type  see num WKCAM_SDCARD_FORMAT_TYPE
 * @param response_code  see enum WKCAM_SDCARD_FORMAT_ACK
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_cmd_sdcard_format_send(mavlink_channel_t chan, uint8_t format_type, uint8_t response_code)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN];
    _mav_put_uint8_t(buf, 0, format_type);
    _mav_put_uint8_t(buf, 1, response_code);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_CRC);
#else
    mavlink_wk_camera_cmd_sdcard_format_t packet;
    packet.format_type = format_type;
    packet.response_code = response_code;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_CRC);
#endif
}

/**
 * @brief Send a wk_camera_cmd_sdcard_format message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_cmd_sdcard_format_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_cmd_sdcard_format_t* wk_camera_cmd_sdcard_format)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_sdcard_format_send(chan, wk_camera_cmd_sdcard_format->format_type, wk_camera_cmd_sdcard_format->response_code);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT, (const char *)wk_camera_cmd_sdcard_format, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_cmd_sdcard_format_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t format_type, uint8_t response_code)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, format_type);
    _mav_put_uint8_t(buf, 1, response_code);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_CRC);
#else
    mavlink_wk_camera_cmd_sdcard_format_t *packet = (mavlink_wk_camera_cmd_sdcard_format_t *)msgbuf;
    packet->format_type = format_type;
    packet->response_code = response_code;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_CMD_SDCARD_FORMAT UNPACKING


/**
 * @brief Get field format_type from wk_camera_cmd_sdcard_format message
 *
 * @return  see num WKCAM_SDCARD_FORMAT_TYPE
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_sdcard_format_get_format_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field response_code from wk_camera_cmd_sdcard_format message
 *
 * @return  see enum WKCAM_SDCARD_FORMAT_ACK
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_sdcard_format_get_response_code(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a wk_camera_cmd_sdcard_format message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_cmd_sdcard_format C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_cmd_sdcard_format_decode(const mavlink_message_t* msg, mavlink_wk_camera_cmd_sdcard_format_t* wk_camera_cmd_sdcard_format)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_cmd_sdcard_format->format_type = mavlink_msg_wk_camera_cmd_sdcard_format_get_format_type(msg);
    wk_camera_cmd_sdcard_format->response_code = mavlink_msg_wk_camera_cmd_sdcard_format_get_response_code(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN;
        memset(wk_camera_cmd_sdcard_format, 0, MAVLINK_MSG_ID_WK_CAMERA_CMD_SDCARD_FORMAT_LEN);
    memcpy(wk_camera_cmd_sdcard_format, _MAV_PAYLOAD(msg), len);
#endif
}
