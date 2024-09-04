#pragma once
// MESSAGE WK_CAMERA_CMD_CSC PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC 8057


typedef struct __mavlink_wk_camera_cmd_csc_t {
 uint8_t csc_luma; /*<  */
 uint8_t csc_contrast; /*<  */
 uint8_t csc_hue; /*<  */
 uint8_t csc_aturation; /*<  */
} mavlink_wk_camera_cmd_csc_t;

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN 4
#define MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_MIN_LEN 4
#define MAVLINK_MSG_ID_8057_LEN 4
#define MAVLINK_MSG_ID_8057_MIN_LEN 4

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_CRC 175
#define MAVLINK_MSG_ID_8057_CRC 175



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_CSC { \
    8057, \
    "WK_CAMERA_CMD_CSC", \
    4, \
    {  { "csc_luma", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_camera_cmd_csc_t, csc_luma) }, \
         { "csc_contrast", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_camera_cmd_csc_t, csc_contrast) }, \
         { "csc_hue", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_camera_cmd_csc_t, csc_hue) }, \
         { "csc_aturation", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_camera_cmd_csc_t, csc_aturation) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_CSC { \
    "WK_CAMERA_CMD_CSC", \
    4, \
    {  { "csc_luma", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_camera_cmd_csc_t, csc_luma) }, \
         { "csc_contrast", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_camera_cmd_csc_t, csc_contrast) }, \
         { "csc_hue", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_camera_cmd_csc_t, csc_hue) }, \
         { "csc_aturation", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_camera_cmd_csc_t, csc_aturation) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_cmd_csc message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param csc_luma  
 * @param csc_contrast  
 * @param csc_hue  
 * @param csc_aturation  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_csc_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t csc_luma, uint8_t csc_contrast, uint8_t csc_hue, uint8_t csc_aturation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN];
    _mav_put_uint8_t(buf, 0, csc_luma);
    _mav_put_uint8_t(buf, 1, csc_contrast);
    _mav_put_uint8_t(buf, 2, csc_hue);
    _mav_put_uint8_t(buf, 3, csc_aturation);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN);
#else
    mavlink_wk_camera_cmd_csc_t packet;
    packet.csc_luma = csc_luma;
    packet.csc_contrast = csc_contrast;
    packet.csc_hue = csc_hue;
    packet.csc_aturation = csc_aturation;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_CRC);
}

/**
 * @brief Pack a wk_camera_cmd_csc message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param csc_luma  
 * @param csc_contrast  
 * @param csc_hue  
 * @param csc_aturation  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_csc_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t csc_luma,uint8_t csc_contrast,uint8_t csc_hue,uint8_t csc_aturation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN];
    _mav_put_uint8_t(buf, 0, csc_luma);
    _mav_put_uint8_t(buf, 1, csc_contrast);
    _mav_put_uint8_t(buf, 2, csc_hue);
    _mav_put_uint8_t(buf, 3, csc_aturation);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN);
#else
    mavlink_wk_camera_cmd_csc_t packet;
    packet.csc_luma = csc_luma;
    packet.csc_contrast = csc_contrast;
    packet.csc_hue = csc_hue;
    packet.csc_aturation = csc_aturation;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_CRC);
}

/**
 * @brief Encode a wk_camera_cmd_csc struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_csc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_csc_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_cmd_csc_t* wk_camera_cmd_csc)
{
    return mavlink_msg_wk_camera_cmd_csc_pack(system_id, component_id, msg, wk_camera_cmd_csc->csc_luma, wk_camera_cmd_csc->csc_contrast, wk_camera_cmd_csc->csc_hue, wk_camera_cmd_csc->csc_aturation);
}

/**
 * @brief Encode a wk_camera_cmd_csc struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_csc C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_csc_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_cmd_csc_t* wk_camera_cmd_csc)
{
    return mavlink_msg_wk_camera_cmd_csc_pack_chan(system_id, component_id, chan, msg, wk_camera_cmd_csc->csc_luma, wk_camera_cmd_csc->csc_contrast, wk_camera_cmd_csc->csc_hue, wk_camera_cmd_csc->csc_aturation);
}

/**
 * @brief Send a wk_camera_cmd_csc message
 * @param chan MAVLink channel to send the message
 *
 * @param csc_luma  
 * @param csc_contrast  
 * @param csc_hue  
 * @param csc_aturation  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_cmd_csc_send(mavlink_channel_t chan, uint8_t csc_luma, uint8_t csc_contrast, uint8_t csc_hue, uint8_t csc_aturation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN];
    _mav_put_uint8_t(buf, 0, csc_luma);
    _mav_put_uint8_t(buf, 1, csc_contrast);
    _mav_put_uint8_t(buf, 2, csc_hue);
    _mav_put_uint8_t(buf, 3, csc_aturation);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_CRC);
#else
    mavlink_wk_camera_cmd_csc_t packet;
    packet.csc_luma = csc_luma;
    packet.csc_contrast = csc_contrast;
    packet.csc_hue = csc_hue;
    packet.csc_aturation = csc_aturation;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_CRC);
#endif
}

/**
 * @brief Send a wk_camera_cmd_csc message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_cmd_csc_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_cmd_csc_t* wk_camera_cmd_csc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_csc_send(chan, wk_camera_cmd_csc->csc_luma, wk_camera_cmd_csc->csc_contrast, wk_camera_cmd_csc->csc_hue, wk_camera_cmd_csc->csc_aturation);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC, (const char *)wk_camera_cmd_csc, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_cmd_csc_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t csc_luma, uint8_t csc_contrast, uint8_t csc_hue, uint8_t csc_aturation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, csc_luma);
    _mav_put_uint8_t(buf, 1, csc_contrast);
    _mav_put_uint8_t(buf, 2, csc_hue);
    _mav_put_uint8_t(buf, 3, csc_aturation);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_CRC);
#else
    mavlink_wk_camera_cmd_csc_t *packet = (mavlink_wk_camera_cmd_csc_t *)msgbuf;
    packet->csc_luma = csc_luma;
    packet->csc_contrast = csc_contrast;
    packet->csc_hue = csc_hue;
    packet->csc_aturation = csc_aturation;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_CMD_CSC UNPACKING


/**
 * @brief Get field csc_luma from wk_camera_cmd_csc message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_csc_get_csc_luma(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field csc_contrast from wk_camera_cmd_csc message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_csc_get_csc_contrast(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field csc_hue from wk_camera_cmd_csc message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_csc_get_csc_hue(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field csc_aturation from wk_camera_cmd_csc message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_csc_get_csc_aturation(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Decode a wk_camera_cmd_csc message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_cmd_csc C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_cmd_csc_decode(const mavlink_message_t* msg, mavlink_wk_camera_cmd_csc_t* wk_camera_cmd_csc)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_cmd_csc->csc_luma = mavlink_msg_wk_camera_cmd_csc_get_csc_luma(msg);
    wk_camera_cmd_csc->csc_contrast = mavlink_msg_wk_camera_cmd_csc_get_csc_contrast(msg);
    wk_camera_cmd_csc->csc_hue = mavlink_msg_wk_camera_cmd_csc_get_csc_hue(msg);
    wk_camera_cmd_csc->csc_aturation = mavlink_msg_wk_camera_cmd_csc_get_csc_aturation(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN;
        memset(wk_camera_cmd_csc, 0, MAVLINK_MSG_ID_WK_CAMERA_CMD_CSC_LEN);
    memcpy(wk_camera_cmd_csc, _MAV_PAYLOAD(msg), len);
#endif
}
