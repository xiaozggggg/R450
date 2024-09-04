#pragma once
// MESSAGE WK_SET_AI_TRACKING_CMD PACKING

#define MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD 8301


typedef struct __mavlink_wk_set_ai_tracking_cmd_t {
 float x; /*<  */
 float y; /*<  */
 float width; /*<  */
 float height; /*<  */
 uint16_t resolutionWidth; /*<  */
 uint16_t resolutionHeight; /*<  */
 uint8_t isTracking; /*<  */
 uint8_t mode; /*<  see WK_TACKING_MODE_CMD*/
 uint8_t reserved[8]; /*<  */
} mavlink_wk_set_ai_tracking_cmd_t;

#define MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN 30
#define MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_MIN_LEN 30
#define MAVLINK_MSG_ID_8301_LEN 30
#define MAVLINK_MSG_ID_8301_MIN_LEN 30

#define MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_CRC 228
#define MAVLINK_MSG_ID_8301_CRC 228

#define MAVLINK_MSG_WK_SET_AI_TRACKING_CMD_FIELD_RESERVED_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_SET_AI_TRACKING_CMD { \
    8301, \
    "WK_SET_AI_TRACKING_CMD", \
    9, \
    {  { "isTracking", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_wk_set_ai_tracking_cmd_t, isTracking) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_set_ai_tracking_cmd_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_set_ai_tracking_cmd_t, y) }, \
         { "width", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_set_ai_tracking_cmd_t, width) }, \
         { "height", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_set_ai_tracking_cmd_t, height) }, \
         { "resolutionWidth", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_wk_set_ai_tracking_cmd_t, resolutionWidth) }, \
         { "resolutionHeight", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_wk_set_ai_tracking_cmd_t, resolutionHeight) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_wk_set_ai_tracking_cmd_t, mode) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 8, 22, offsetof(mavlink_wk_set_ai_tracking_cmd_t, reserved) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_SET_AI_TRACKING_CMD { \
    "WK_SET_AI_TRACKING_CMD", \
    9, \
    {  { "isTracking", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_wk_set_ai_tracking_cmd_t, isTracking) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_set_ai_tracking_cmd_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_set_ai_tracking_cmd_t, y) }, \
         { "width", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_set_ai_tracking_cmd_t, width) }, \
         { "height", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_set_ai_tracking_cmd_t, height) }, \
         { "resolutionWidth", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_wk_set_ai_tracking_cmd_t, resolutionWidth) }, \
         { "resolutionHeight", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_wk_set_ai_tracking_cmd_t, resolutionHeight) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_wk_set_ai_tracking_cmd_t, mode) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 8, 22, offsetof(mavlink_wk_set_ai_tracking_cmd_t, reserved) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_set_ai_tracking_cmd message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param isTracking  
 * @param x  
 * @param y  
 * @param width  
 * @param height  
 * @param resolutionWidth  
 * @param resolutionHeight  
 * @param mode  see WK_TACKING_MODE_CMD
 * @param reserved  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_set_ai_tracking_cmd_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t isTracking, float x, float y, float width, float height, uint16_t resolutionWidth, uint16_t resolutionHeight, uint8_t mode, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, width);
    _mav_put_float(buf, 12, height);
    _mav_put_uint16_t(buf, 16, resolutionWidth);
    _mav_put_uint16_t(buf, 18, resolutionHeight);
    _mav_put_uint8_t(buf, 20, isTracking);
    _mav_put_uint8_t(buf, 21, mode);
    _mav_put_uint8_t_array(buf, 22, reserved, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN);
#else
    mavlink_wk_set_ai_tracking_cmd_t packet;
    packet.x = x;
    packet.y = y;
    packet.width = width;
    packet.height = height;
    packet.resolutionWidth = resolutionWidth;
    packet.resolutionHeight = resolutionHeight;
    packet.isTracking = isTracking;
    packet.mode = mode;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_MIN_LEN, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_CRC);
}

/**
 * @brief Pack a wk_set_ai_tracking_cmd message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param isTracking  
 * @param x  
 * @param y  
 * @param width  
 * @param height  
 * @param resolutionWidth  
 * @param resolutionHeight  
 * @param mode  see WK_TACKING_MODE_CMD
 * @param reserved  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_set_ai_tracking_cmd_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t isTracking,float x,float y,float width,float height,uint16_t resolutionWidth,uint16_t resolutionHeight,uint8_t mode,const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, width);
    _mav_put_float(buf, 12, height);
    _mav_put_uint16_t(buf, 16, resolutionWidth);
    _mav_put_uint16_t(buf, 18, resolutionHeight);
    _mav_put_uint8_t(buf, 20, isTracking);
    _mav_put_uint8_t(buf, 21, mode);
    _mav_put_uint8_t_array(buf, 22, reserved, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN);
#else
    mavlink_wk_set_ai_tracking_cmd_t packet;
    packet.x = x;
    packet.y = y;
    packet.width = width;
    packet.height = height;
    packet.resolutionWidth = resolutionWidth;
    packet.resolutionHeight = resolutionHeight;
    packet.isTracking = isTracking;
    packet.mode = mode;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_MIN_LEN, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_CRC);
}

/**
 * @brief Encode a wk_set_ai_tracking_cmd struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_set_ai_tracking_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_set_ai_tracking_cmd_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_set_ai_tracking_cmd_t* wk_set_ai_tracking_cmd)
{
    return mavlink_msg_wk_set_ai_tracking_cmd_pack(system_id, component_id, msg, wk_set_ai_tracking_cmd->isTracking, wk_set_ai_tracking_cmd->x, wk_set_ai_tracking_cmd->y, wk_set_ai_tracking_cmd->width, wk_set_ai_tracking_cmd->height, wk_set_ai_tracking_cmd->resolutionWidth, wk_set_ai_tracking_cmd->resolutionHeight, wk_set_ai_tracking_cmd->mode, wk_set_ai_tracking_cmd->reserved);
}

/**
 * @brief Encode a wk_set_ai_tracking_cmd struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_set_ai_tracking_cmd C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_set_ai_tracking_cmd_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_set_ai_tracking_cmd_t* wk_set_ai_tracking_cmd)
{
    return mavlink_msg_wk_set_ai_tracking_cmd_pack_chan(system_id, component_id, chan, msg, wk_set_ai_tracking_cmd->isTracking, wk_set_ai_tracking_cmd->x, wk_set_ai_tracking_cmd->y, wk_set_ai_tracking_cmd->width, wk_set_ai_tracking_cmd->height, wk_set_ai_tracking_cmd->resolutionWidth, wk_set_ai_tracking_cmd->resolutionHeight, wk_set_ai_tracking_cmd->mode, wk_set_ai_tracking_cmd->reserved);
}

/**
 * @brief Send a wk_set_ai_tracking_cmd message
 * @param chan MAVLink channel to send the message
 *
 * @param isTracking  
 * @param x  
 * @param y  
 * @param width  
 * @param height  
 * @param resolutionWidth  
 * @param resolutionHeight  
 * @param mode  see WK_TACKING_MODE_CMD
 * @param reserved  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_set_ai_tracking_cmd_send(mavlink_channel_t chan, uint8_t isTracking, float x, float y, float width, float height, uint16_t resolutionWidth, uint16_t resolutionHeight, uint8_t mode, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN];
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, width);
    _mav_put_float(buf, 12, height);
    _mav_put_uint16_t(buf, 16, resolutionWidth);
    _mav_put_uint16_t(buf, 18, resolutionHeight);
    _mav_put_uint8_t(buf, 20, isTracking);
    _mav_put_uint8_t(buf, 21, mode);
    _mav_put_uint8_t_array(buf, 22, reserved, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD, buf, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_MIN_LEN, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_CRC);
#else
    mavlink_wk_set_ai_tracking_cmd_t packet;
    packet.x = x;
    packet.y = y;
    packet.width = width;
    packet.height = height;
    packet.resolutionWidth = resolutionWidth;
    packet.resolutionHeight = resolutionHeight;
    packet.isTracking = isTracking;
    packet.mode = mode;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD, (const char *)&packet, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_MIN_LEN, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_CRC);
#endif
}

/**
 * @brief Send a wk_set_ai_tracking_cmd message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_set_ai_tracking_cmd_send_struct(mavlink_channel_t chan, const mavlink_wk_set_ai_tracking_cmd_t* wk_set_ai_tracking_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_set_ai_tracking_cmd_send(chan, wk_set_ai_tracking_cmd->isTracking, wk_set_ai_tracking_cmd->x, wk_set_ai_tracking_cmd->y, wk_set_ai_tracking_cmd->width, wk_set_ai_tracking_cmd->height, wk_set_ai_tracking_cmd->resolutionWidth, wk_set_ai_tracking_cmd->resolutionHeight, wk_set_ai_tracking_cmd->mode, wk_set_ai_tracking_cmd->reserved);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD, (const char *)wk_set_ai_tracking_cmd, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_MIN_LEN, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_set_ai_tracking_cmd_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t isTracking, float x, float y, float width, float height, uint16_t resolutionWidth, uint16_t resolutionHeight, uint8_t mode, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, x);
    _mav_put_float(buf, 4, y);
    _mav_put_float(buf, 8, width);
    _mav_put_float(buf, 12, height);
    _mav_put_uint16_t(buf, 16, resolutionWidth);
    _mav_put_uint16_t(buf, 18, resolutionHeight);
    _mav_put_uint8_t(buf, 20, isTracking);
    _mav_put_uint8_t(buf, 21, mode);
    _mav_put_uint8_t_array(buf, 22, reserved, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD, buf, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_MIN_LEN, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_CRC);
#else
    mavlink_wk_set_ai_tracking_cmd_t *packet = (mavlink_wk_set_ai_tracking_cmd_t *)msgbuf;
    packet->x = x;
    packet->y = y;
    packet->width = width;
    packet->height = height;
    packet->resolutionWidth = resolutionWidth;
    packet->resolutionHeight = resolutionHeight;
    packet->isTracking = isTracking;
    packet->mode = mode;
    mav_array_memcpy(packet->reserved, reserved, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD, (const char *)packet, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_MIN_LEN, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_SET_AI_TRACKING_CMD UNPACKING


/**
 * @brief Get field isTracking from wk_set_ai_tracking_cmd message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_set_ai_tracking_cmd_get_isTracking(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field x from wk_set_ai_tracking_cmd message
 *
 * @return  
 */
static inline float mavlink_msg_wk_set_ai_tracking_cmd_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field y from wk_set_ai_tracking_cmd message
 *
 * @return  
 */
static inline float mavlink_msg_wk_set_ai_tracking_cmd_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field width from wk_set_ai_tracking_cmd message
 *
 * @return  
 */
static inline float mavlink_msg_wk_set_ai_tracking_cmd_get_width(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field height from wk_set_ai_tracking_cmd message
 *
 * @return  
 */
static inline float mavlink_msg_wk_set_ai_tracking_cmd_get_height(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field resolutionWidth from wk_set_ai_tracking_cmd message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_set_ai_tracking_cmd_get_resolutionWidth(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field resolutionHeight from wk_set_ai_tracking_cmd message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_set_ai_tracking_cmd_get_resolutionHeight(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field mode from wk_set_ai_tracking_cmd message
 *
 * @return  see WK_TACKING_MODE_CMD
 */
static inline uint8_t mavlink_msg_wk_set_ai_tracking_cmd_get_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  21);
}

/**
 * @brief Get field reserved from wk_set_ai_tracking_cmd message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_set_ai_tracking_cmd_get_reserved(const mavlink_message_t* msg, uint8_t *reserved)
{
    return _MAV_RETURN_uint8_t_array(msg, reserved, 8,  22);
}

/**
 * @brief Decode a wk_set_ai_tracking_cmd message into a struct
 *
 * @param msg The message to decode
 * @param wk_set_ai_tracking_cmd C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_set_ai_tracking_cmd_decode(const mavlink_message_t* msg, mavlink_wk_set_ai_tracking_cmd_t* wk_set_ai_tracking_cmd)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_set_ai_tracking_cmd->x = mavlink_msg_wk_set_ai_tracking_cmd_get_x(msg);
    wk_set_ai_tracking_cmd->y = mavlink_msg_wk_set_ai_tracking_cmd_get_y(msg);
    wk_set_ai_tracking_cmd->width = mavlink_msg_wk_set_ai_tracking_cmd_get_width(msg);
    wk_set_ai_tracking_cmd->height = mavlink_msg_wk_set_ai_tracking_cmd_get_height(msg);
    wk_set_ai_tracking_cmd->resolutionWidth = mavlink_msg_wk_set_ai_tracking_cmd_get_resolutionWidth(msg);
    wk_set_ai_tracking_cmd->resolutionHeight = mavlink_msg_wk_set_ai_tracking_cmd_get_resolutionHeight(msg);
    wk_set_ai_tracking_cmd->isTracking = mavlink_msg_wk_set_ai_tracking_cmd_get_isTracking(msg);
    wk_set_ai_tracking_cmd->mode = mavlink_msg_wk_set_ai_tracking_cmd_get_mode(msg);
    mavlink_msg_wk_set_ai_tracking_cmd_get_reserved(msg, wk_set_ai_tracking_cmd->reserved);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN? msg->len : MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN;
        memset(wk_set_ai_tracking_cmd, 0, MAVLINK_MSG_ID_WK_SET_AI_TRACKING_CMD_LEN);
    memcpy(wk_set_ai_tracking_cmd, _MAV_PAYLOAD(msg), len);
#endif
}
