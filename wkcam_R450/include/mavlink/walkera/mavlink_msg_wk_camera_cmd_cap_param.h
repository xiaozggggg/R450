#pragma once
// MESSAGE WK_CAMERA_CMD_CAP_PARAM PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM 8049


typedef struct __mavlink_wk_camera_cmd_cap_param_t {
 uint8_t cap_mode; /*<  see enum WKCAM_CAP_MODE*/
 uint8_t cap_continues; /*<  */
 uint8_t cap_save_format; /*<  see enum WKCAM_CAP_SAVE_FORMAT*/
 uint8_t cap_resolution; /*<  see enum WKCAM_CAP_RESOLUTION*/
 uint8_t cap_rotation; /*<  see enum WKCAM_CAP_ROTATION*/
} mavlink_wk_camera_cmd_cap_param_t;

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN 5
#define MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_MIN_LEN 5
#define MAVLINK_MSG_ID_8049_LEN 5
#define MAVLINK_MSG_ID_8049_MIN_LEN 5

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_CRC 233
#define MAVLINK_MSG_ID_8049_CRC 233



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_CAP_PARAM { \
    8049, \
    "WK_CAMERA_CMD_CAP_PARAM", \
    5, \
    {  { "cap_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_camera_cmd_cap_param_t, cap_mode) }, \
         { "cap_continues", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_camera_cmd_cap_param_t, cap_continues) }, \
         { "cap_save_format", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_camera_cmd_cap_param_t, cap_save_format) }, \
         { "cap_resolution", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_camera_cmd_cap_param_t, cap_resolution) }, \
         { "cap_rotation", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_camera_cmd_cap_param_t, cap_rotation) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_CAP_PARAM { \
    "WK_CAMERA_CMD_CAP_PARAM", \
    5, \
    {  { "cap_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_camera_cmd_cap_param_t, cap_mode) }, \
         { "cap_continues", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_camera_cmd_cap_param_t, cap_continues) }, \
         { "cap_save_format", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_camera_cmd_cap_param_t, cap_save_format) }, \
         { "cap_resolution", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_camera_cmd_cap_param_t, cap_resolution) }, \
         { "cap_rotation", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_camera_cmd_cap_param_t, cap_rotation) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_cmd_cap_param message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param cap_mode  see enum WKCAM_CAP_MODE
 * @param cap_continues  
 * @param cap_save_format  see enum WKCAM_CAP_SAVE_FORMAT
 * @param cap_resolution  see enum WKCAM_CAP_RESOLUTION
 * @param cap_rotation  see enum WKCAM_CAP_ROTATION
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_cap_param_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t cap_mode, uint8_t cap_continues, uint8_t cap_save_format, uint8_t cap_resolution, uint8_t cap_rotation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN];
    _mav_put_uint8_t(buf, 0, cap_mode);
    _mav_put_uint8_t(buf, 1, cap_continues);
    _mav_put_uint8_t(buf, 2, cap_save_format);
    _mav_put_uint8_t(buf, 3, cap_resolution);
    _mav_put_uint8_t(buf, 4, cap_rotation);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN);
#else
    mavlink_wk_camera_cmd_cap_param_t packet;
    packet.cap_mode = cap_mode;
    packet.cap_continues = cap_continues;
    packet.cap_save_format = cap_save_format;
    packet.cap_resolution = cap_resolution;
    packet.cap_rotation = cap_rotation;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_CRC);
}

/**
 * @brief Pack a wk_camera_cmd_cap_param message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cap_mode  see enum WKCAM_CAP_MODE
 * @param cap_continues  
 * @param cap_save_format  see enum WKCAM_CAP_SAVE_FORMAT
 * @param cap_resolution  see enum WKCAM_CAP_RESOLUTION
 * @param cap_rotation  see enum WKCAM_CAP_ROTATION
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_cap_param_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t cap_mode,uint8_t cap_continues,uint8_t cap_save_format,uint8_t cap_resolution,uint8_t cap_rotation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN];
    _mav_put_uint8_t(buf, 0, cap_mode);
    _mav_put_uint8_t(buf, 1, cap_continues);
    _mav_put_uint8_t(buf, 2, cap_save_format);
    _mav_put_uint8_t(buf, 3, cap_resolution);
    _mav_put_uint8_t(buf, 4, cap_rotation);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN);
#else
    mavlink_wk_camera_cmd_cap_param_t packet;
    packet.cap_mode = cap_mode;
    packet.cap_continues = cap_continues;
    packet.cap_save_format = cap_save_format;
    packet.cap_resolution = cap_resolution;
    packet.cap_rotation = cap_rotation;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_CRC);
}

/**
 * @brief Encode a wk_camera_cmd_cap_param struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_cap_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_cap_param_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_cmd_cap_param_t* wk_camera_cmd_cap_param)
{
    return mavlink_msg_wk_camera_cmd_cap_param_pack(system_id, component_id, msg, wk_camera_cmd_cap_param->cap_mode, wk_camera_cmd_cap_param->cap_continues, wk_camera_cmd_cap_param->cap_save_format, wk_camera_cmd_cap_param->cap_resolution, wk_camera_cmd_cap_param->cap_rotation);
}

/**
 * @brief Encode a wk_camera_cmd_cap_param struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_cap_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_cap_param_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_cmd_cap_param_t* wk_camera_cmd_cap_param)
{
    return mavlink_msg_wk_camera_cmd_cap_param_pack_chan(system_id, component_id, chan, msg, wk_camera_cmd_cap_param->cap_mode, wk_camera_cmd_cap_param->cap_continues, wk_camera_cmd_cap_param->cap_save_format, wk_camera_cmd_cap_param->cap_resolution, wk_camera_cmd_cap_param->cap_rotation);
}

/**
 * @brief Send a wk_camera_cmd_cap_param message
 * @param chan MAVLink channel to send the message
 *
 * @param cap_mode  see enum WKCAM_CAP_MODE
 * @param cap_continues  
 * @param cap_save_format  see enum WKCAM_CAP_SAVE_FORMAT
 * @param cap_resolution  see enum WKCAM_CAP_RESOLUTION
 * @param cap_rotation  see enum WKCAM_CAP_ROTATION
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_cmd_cap_param_send(mavlink_channel_t chan, uint8_t cap_mode, uint8_t cap_continues, uint8_t cap_save_format, uint8_t cap_resolution, uint8_t cap_rotation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN];
    _mav_put_uint8_t(buf, 0, cap_mode);
    _mav_put_uint8_t(buf, 1, cap_continues);
    _mav_put_uint8_t(buf, 2, cap_save_format);
    _mav_put_uint8_t(buf, 3, cap_resolution);
    _mav_put_uint8_t(buf, 4, cap_rotation);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_CRC);
#else
    mavlink_wk_camera_cmd_cap_param_t packet;
    packet.cap_mode = cap_mode;
    packet.cap_continues = cap_continues;
    packet.cap_save_format = cap_save_format;
    packet.cap_resolution = cap_resolution;
    packet.cap_rotation = cap_rotation;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_CRC);
#endif
}

/**
 * @brief Send a wk_camera_cmd_cap_param message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_cmd_cap_param_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_cmd_cap_param_t* wk_camera_cmd_cap_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_cap_param_send(chan, wk_camera_cmd_cap_param->cap_mode, wk_camera_cmd_cap_param->cap_continues, wk_camera_cmd_cap_param->cap_save_format, wk_camera_cmd_cap_param->cap_resolution, wk_camera_cmd_cap_param->cap_rotation);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM, (const char *)wk_camera_cmd_cap_param, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_cmd_cap_param_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t cap_mode, uint8_t cap_continues, uint8_t cap_save_format, uint8_t cap_resolution, uint8_t cap_rotation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, cap_mode);
    _mav_put_uint8_t(buf, 1, cap_continues);
    _mav_put_uint8_t(buf, 2, cap_save_format);
    _mav_put_uint8_t(buf, 3, cap_resolution);
    _mav_put_uint8_t(buf, 4, cap_rotation);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_CRC);
#else
    mavlink_wk_camera_cmd_cap_param_t *packet = (mavlink_wk_camera_cmd_cap_param_t *)msgbuf;
    packet->cap_mode = cap_mode;
    packet->cap_continues = cap_continues;
    packet->cap_save_format = cap_save_format;
    packet->cap_resolution = cap_resolution;
    packet->cap_rotation = cap_rotation;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_CMD_CAP_PARAM UNPACKING


/**
 * @brief Get field cap_mode from wk_camera_cmd_cap_param message
 *
 * @return  see enum WKCAM_CAP_MODE
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_cap_param_get_cap_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field cap_continues from wk_camera_cmd_cap_param message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_cap_param_get_cap_continues(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field cap_save_format from wk_camera_cmd_cap_param message
 *
 * @return  see enum WKCAM_CAP_SAVE_FORMAT
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_cap_param_get_cap_save_format(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field cap_resolution from wk_camera_cmd_cap_param message
 *
 * @return  see enum WKCAM_CAP_RESOLUTION
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_cap_param_get_cap_resolution(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field cap_rotation from wk_camera_cmd_cap_param message
 *
 * @return  see enum WKCAM_CAP_ROTATION
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_cap_param_get_cap_rotation(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Decode a wk_camera_cmd_cap_param message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_cmd_cap_param C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_cmd_cap_param_decode(const mavlink_message_t* msg, mavlink_wk_camera_cmd_cap_param_t* wk_camera_cmd_cap_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_cmd_cap_param->cap_mode = mavlink_msg_wk_camera_cmd_cap_param_get_cap_mode(msg);
    wk_camera_cmd_cap_param->cap_continues = mavlink_msg_wk_camera_cmd_cap_param_get_cap_continues(msg);
    wk_camera_cmd_cap_param->cap_save_format = mavlink_msg_wk_camera_cmd_cap_param_get_cap_save_format(msg);
    wk_camera_cmd_cap_param->cap_resolution = mavlink_msg_wk_camera_cmd_cap_param_get_cap_resolution(msg);
    wk_camera_cmd_cap_param->cap_rotation = mavlink_msg_wk_camera_cmd_cap_param_get_cap_rotation(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN;
        memset(wk_camera_cmd_cap_param, 0, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAP_PARAM_LEN);
    memcpy(wk_camera_cmd_cap_param, _MAV_PAYLOAD(msg), len);
#endif
}
