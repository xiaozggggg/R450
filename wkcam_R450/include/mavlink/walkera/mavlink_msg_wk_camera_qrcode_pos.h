#pragma once
// MESSAGE WK_CAMERA_QRCODE_POS PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS 8059


typedef struct __mavlink_wk_camera_qrcode_pos_t {
 float xPos; /*<  */
 float yPos; /*<  */
 uint8_t reserved[8]; /*<  */
} mavlink_wk_camera_qrcode_pos_t;

#define MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN 16
#define MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_MIN_LEN 16
#define MAVLINK_MSG_ID_8059_LEN 16
#define MAVLINK_MSG_ID_8059_MIN_LEN 16

#define MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_CRC 206
#define MAVLINK_MSG_ID_8059_CRC 206

#define MAVLINK_MSG_WK_CAMERA_QRCODE_POS_FIELD_RESERVED_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_QRCODE_POS { \
    8059, \
    "WK_CAMERA_QRCODE_POS", \
    3, \
    {  { "xPos", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_camera_qrcode_pos_t, xPos) }, \
         { "yPos", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_camera_qrcode_pos_t, yPos) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 8, 8, offsetof(mavlink_wk_camera_qrcode_pos_t, reserved) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_QRCODE_POS { \
    "WK_CAMERA_QRCODE_POS", \
    3, \
    {  { "xPos", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_camera_qrcode_pos_t, xPos) }, \
         { "yPos", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_camera_qrcode_pos_t, yPos) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 8, 8, offsetof(mavlink_wk_camera_qrcode_pos_t, reserved) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_qrcode_pos message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param xPos  
 * @param yPos  
 * @param reserved  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_qrcode_pos_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float xPos, float yPos, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN];
    _mav_put_float(buf, 0, xPos);
    _mav_put_float(buf, 4, yPos);
    _mav_put_uint8_t_array(buf, 8, reserved, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN);
#else
    mavlink_wk_camera_qrcode_pos_t packet;
    packet.xPos = xPos;
    packet.yPos = yPos;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_CRC);
}

/**
 * @brief Pack a wk_camera_qrcode_pos message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param xPos  
 * @param yPos  
 * @param reserved  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_qrcode_pos_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float xPos,float yPos,const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN];
    _mav_put_float(buf, 0, xPos);
    _mav_put_float(buf, 4, yPos);
    _mav_put_uint8_t_array(buf, 8, reserved, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN);
#else
    mavlink_wk_camera_qrcode_pos_t packet;
    packet.xPos = xPos;
    packet.yPos = yPos;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_CRC);
}

/**
 * @brief Encode a wk_camera_qrcode_pos struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_qrcode_pos C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_qrcode_pos_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_qrcode_pos_t* wk_camera_qrcode_pos)
{
    return mavlink_msg_wk_camera_qrcode_pos_pack(system_id, component_id, msg, wk_camera_qrcode_pos->xPos, wk_camera_qrcode_pos->yPos, wk_camera_qrcode_pos->reserved);
}

/**
 * @brief Encode a wk_camera_qrcode_pos struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_qrcode_pos C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_qrcode_pos_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_qrcode_pos_t* wk_camera_qrcode_pos)
{
    return mavlink_msg_wk_camera_qrcode_pos_pack_chan(system_id, component_id, chan, msg, wk_camera_qrcode_pos->xPos, wk_camera_qrcode_pos->yPos, wk_camera_qrcode_pos->reserved);
}

/**
 * @brief Send a wk_camera_qrcode_pos message
 * @param chan MAVLink channel to send the message
 *
 * @param xPos  
 * @param yPos  
 * @param reserved  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_qrcode_pos_send(mavlink_channel_t chan, float xPos, float yPos, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN];
    _mav_put_float(buf, 0, xPos);
    _mav_put_float(buf, 4, yPos);
    _mav_put_uint8_t_array(buf, 8, reserved, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS, buf, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_CRC);
#else
    mavlink_wk_camera_qrcode_pos_t packet;
    packet.xPos = xPos;
    packet.yPos = yPos;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_CRC);
#endif
}

/**
 * @brief Send a wk_camera_qrcode_pos message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_qrcode_pos_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_qrcode_pos_t* wk_camera_qrcode_pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_qrcode_pos_send(chan, wk_camera_qrcode_pos->xPos, wk_camera_qrcode_pos->yPos, wk_camera_qrcode_pos->reserved);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS, (const char *)wk_camera_qrcode_pos, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_qrcode_pos_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float xPos, float yPos, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, xPos);
    _mav_put_float(buf, 4, yPos);
    _mav_put_uint8_t_array(buf, 8, reserved, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS, buf, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_CRC);
#else
    mavlink_wk_camera_qrcode_pos_t *packet = (mavlink_wk_camera_qrcode_pos_t *)msgbuf;
    packet->xPos = xPos;
    packet->yPos = yPos;
    mav_array_memcpy(packet->reserved, reserved, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_QRCODE_POS UNPACKING


/**
 * @brief Get field xPos from wk_camera_qrcode_pos message
 *
 * @return  
 */
static inline float mavlink_msg_wk_camera_qrcode_pos_get_xPos(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field yPos from wk_camera_qrcode_pos message
 *
 * @return  
 */
static inline float mavlink_msg_wk_camera_qrcode_pos_get_yPos(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field reserved from wk_camera_qrcode_pos message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_camera_qrcode_pos_get_reserved(const mavlink_message_t* msg, uint8_t *reserved)
{
    return _MAV_RETURN_uint8_t_array(msg, reserved, 8,  8);
}

/**
 * @brief Decode a wk_camera_qrcode_pos message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_qrcode_pos C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_qrcode_pos_decode(const mavlink_message_t* msg, mavlink_wk_camera_qrcode_pos_t* wk_camera_qrcode_pos)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_qrcode_pos->xPos = mavlink_msg_wk_camera_qrcode_pos_get_xPos(msg);
    wk_camera_qrcode_pos->yPos = mavlink_msg_wk_camera_qrcode_pos_get_yPos(msg);
    mavlink_msg_wk_camera_qrcode_pos_get_reserved(msg, wk_camera_qrcode_pos->reserved);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN;
        memset(wk_camera_qrcode_pos, 0, MAVLINK_MSG_ID_WK_CAMERA_QRCODE_POS_LEN);
    memcpy(wk_camera_qrcode_pos, _MAV_PAYLOAD(msg), len);
#endif
}
