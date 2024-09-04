#pragma once
// MESSAGE WK_CAMERA_CMD_FOCUS2 PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2 8067


typedef struct __mavlink_wk_camera_cmd_focus2_t {
 uint8_t direction; /*<  0:APP -> camera  ; 1: camera -> APP*/
 uint8_t type; /*<  0:zoom level    1:focus type*/
 uint8_t zoom_level; /*<  zoom level*/
 uint8_t focus_type; /*<  see enum WKCAM_FOCUS_SET*/
} mavlink_wk_camera_cmd_focus2_t;

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN 4
#define MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_MIN_LEN 4
#define MAVLINK_MSG_ID_8067_LEN 4
#define MAVLINK_MSG_ID_8067_MIN_LEN 4

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_CRC 79
#define MAVLINK_MSG_ID_8067_CRC 79



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_FOCUS2 { \
    8067, \
    "WK_CAMERA_CMD_FOCUS2", \
    4, \
    {  { "direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_camera_cmd_focus2_t, direction) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_camera_cmd_focus2_t, type) }, \
         { "zoom_level", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_camera_cmd_focus2_t, zoom_level) }, \
         { "focus_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_camera_cmd_focus2_t, focus_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_FOCUS2 { \
    "WK_CAMERA_CMD_FOCUS2", \
    4, \
    {  { "direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_camera_cmd_focus2_t, direction) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_camera_cmd_focus2_t, type) }, \
         { "zoom_level", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_camera_cmd_focus2_t, zoom_level) }, \
         { "focus_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_camera_cmd_focus2_t, focus_type) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_cmd_focus2 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param direction  0:APP -> camera  ; 1: camera -> APP
 * @param type  0:zoom level    1:focus type
 * @param zoom_level  zoom level
 * @param focus_type  see enum WKCAM_FOCUS_SET
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_focus2_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t direction, uint8_t type, uint8_t zoom_level, uint8_t focus_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN];
    _mav_put_uint8_t(buf, 0, direction);
    _mav_put_uint8_t(buf, 1, type);
    _mav_put_uint8_t(buf, 2, zoom_level);
    _mav_put_uint8_t(buf, 3, focus_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN);
#else
    mavlink_wk_camera_cmd_focus2_t packet;
    packet.direction = direction;
    packet.type = type;
    packet.zoom_level = zoom_level;
    packet.focus_type = focus_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_CRC);
}

/**
 * @brief Pack a wk_camera_cmd_focus2 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param direction  0:APP -> camera  ; 1: camera -> APP
 * @param type  0:zoom level    1:focus type
 * @param zoom_level  zoom level
 * @param focus_type  see enum WKCAM_FOCUS_SET
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_focus2_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t direction,uint8_t type,uint8_t zoom_level,uint8_t focus_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN];
    _mav_put_uint8_t(buf, 0, direction);
    _mav_put_uint8_t(buf, 1, type);
    _mav_put_uint8_t(buf, 2, zoom_level);
    _mav_put_uint8_t(buf, 3, focus_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN);
#else
    mavlink_wk_camera_cmd_focus2_t packet;
    packet.direction = direction;
    packet.type = type;
    packet.zoom_level = zoom_level;
    packet.focus_type = focus_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_CRC);
}

/**
 * @brief Encode a wk_camera_cmd_focus2 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_focus2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_focus2_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_cmd_focus2_t* wk_camera_cmd_focus2)
{
    return mavlink_msg_wk_camera_cmd_focus2_pack(system_id, component_id, msg, wk_camera_cmd_focus2->direction, wk_camera_cmd_focus2->type, wk_camera_cmd_focus2->zoom_level, wk_camera_cmd_focus2->focus_type);
}

/**
 * @brief Encode a wk_camera_cmd_focus2 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_focus2 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_focus2_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_cmd_focus2_t* wk_camera_cmd_focus2)
{
    return mavlink_msg_wk_camera_cmd_focus2_pack_chan(system_id, component_id, chan, msg, wk_camera_cmd_focus2->direction, wk_camera_cmd_focus2->type, wk_camera_cmd_focus2->zoom_level, wk_camera_cmd_focus2->focus_type);
}

/**
 * @brief Send a wk_camera_cmd_focus2 message
 * @param chan MAVLink channel to send the message
 *
 * @param direction  0:APP -> camera  ; 1: camera -> APP
 * @param type  0:zoom level    1:focus type
 * @param zoom_level  zoom level
 * @param focus_type  see enum WKCAM_FOCUS_SET
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_cmd_focus2_send(mavlink_channel_t chan, uint8_t direction, uint8_t type, uint8_t zoom_level, uint8_t focus_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN];
    _mav_put_uint8_t(buf, 0, direction);
    _mav_put_uint8_t(buf, 1, type);
    _mav_put_uint8_t(buf, 2, zoom_level);
    _mav_put_uint8_t(buf, 3, focus_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_CRC);
#else
    mavlink_wk_camera_cmd_focus2_t packet;
    packet.direction = direction;
    packet.type = type;
    packet.zoom_level = zoom_level;
    packet.focus_type = focus_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_CRC);
#endif
}

/**
 * @brief Send a wk_camera_cmd_focus2 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_cmd_focus2_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_cmd_focus2_t* wk_camera_cmd_focus2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_focus2_send(chan, wk_camera_cmd_focus2->direction, wk_camera_cmd_focus2->type, wk_camera_cmd_focus2->zoom_level, wk_camera_cmd_focus2->focus_type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2, (const char *)wk_camera_cmd_focus2, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_cmd_focus2_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t direction, uint8_t type, uint8_t zoom_level, uint8_t focus_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, direction);
    _mav_put_uint8_t(buf, 1, type);
    _mav_put_uint8_t(buf, 2, zoom_level);
    _mav_put_uint8_t(buf, 3, focus_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_CRC);
#else
    mavlink_wk_camera_cmd_focus2_t *packet = (mavlink_wk_camera_cmd_focus2_t *)msgbuf;
    packet->direction = direction;
    packet->type = type;
    packet->zoom_level = zoom_level;
    packet->focus_type = focus_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_CMD_FOCUS2 UNPACKING


/**
 * @brief Get field direction from wk_camera_cmd_focus2 message
 *
 * @return  0:APP -> camera  ; 1: camera -> APP
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_focus2_get_direction(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field type from wk_camera_cmd_focus2 message
 *
 * @return  0:zoom level    1:focus type
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_focus2_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field zoom_level from wk_camera_cmd_focus2 message
 *
 * @return  zoom level
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_focus2_get_zoom_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field focus_type from wk_camera_cmd_focus2 message
 *
 * @return  see enum WKCAM_FOCUS_SET
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_focus2_get_focus_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Decode a wk_camera_cmd_focus2 message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_cmd_focus2 C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_cmd_focus2_decode(const mavlink_message_t* msg, mavlink_wk_camera_cmd_focus2_t* wk_camera_cmd_focus2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_cmd_focus2->direction = mavlink_msg_wk_camera_cmd_focus2_get_direction(msg);
    wk_camera_cmd_focus2->type = mavlink_msg_wk_camera_cmd_focus2_get_type(msg);
    wk_camera_cmd_focus2->zoom_level = mavlink_msg_wk_camera_cmd_focus2_get_zoom_level(msg);
    wk_camera_cmd_focus2->focus_type = mavlink_msg_wk_camera_cmd_focus2_get_focus_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN;
        memset(wk_camera_cmd_focus2, 0, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS2_LEN);
    memcpy(wk_camera_cmd_focus2, _MAV_PAYLOAD(msg), len);
#endif
}
