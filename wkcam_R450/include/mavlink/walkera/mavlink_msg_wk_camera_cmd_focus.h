#pragma once
// MESSAGE WK_CAMERA_CMD_FOCUS PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS 8046


typedef struct __mavlink_wk_camera_cmd_focus_t {
 uint8_t type; /*<  see enum WKCAM_FOCUS_SET*/
} mavlink_wk_camera_cmd_focus_t;

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN 1
#define MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_MIN_LEN 1
#define MAVLINK_MSG_ID_8046_LEN 1
#define MAVLINK_MSG_ID_8046_MIN_LEN 1

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_CRC 57
#define MAVLINK_MSG_ID_8046_CRC 57



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_FOCUS { \
    8046, \
    "WK_CAMERA_CMD_FOCUS", \
    1, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_camera_cmd_focus_t, type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_FOCUS { \
    "WK_CAMERA_CMD_FOCUS", \
    1, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_camera_cmd_focus_t, type) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_cmd_focus message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type  see enum WKCAM_FOCUS_SET
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_focus_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN];
    _mav_put_uint8_t(buf, 0, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN);
#else
    mavlink_wk_camera_cmd_focus_t packet;
    packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_CRC);
}

/**
 * @brief Pack a wk_camera_cmd_focus message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type  see enum WKCAM_FOCUS_SET
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_focus_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN];
    _mav_put_uint8_t(buf, 0, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN);
#else
    mavlink_wk_camera_cmd_focus_t packet;
    packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_CRC);
}

/**
 * @brief Encode a wk_camera_cmd_focus struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_focus C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_focus_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_cmd_focus_t* wk_camera_cmd_focus)
{
    return mavlink_msg_wk_camera_cmd_focus_pack(system_id, component_id, msg, wk_camera_cmd_focus->type);
}

/**
 * @brief Encode a wk_camera_cmd_focus struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_focus C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_focus_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_cmd_focus_t* wk_camera_cmd_focus)
{
    return mavlink_msg_wk_camera_cmd_focus_pack_chan(system_id, component_id, chan, msg, wk_camera_cmd_focus->type);
}

/**
 * @brief Send a wk_camera_cmd_focus message
 * @param chan MAVLink channel to send the message
 *
 * @param type  see enum WKCAM_FOCUS_SET
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_cmd_focus_send(mavlink_channel_t chan, uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN];
    _mav_put_uint8_t(buf, 0, type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_CRC);
#else
    mavlink_wk_camera_cmd_focus_t packet;
    packet.type = type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_CRC);
#endif
}

/**
 * @brief Send a wk_camera_cmd_focus message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_cmd_focus_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_cmd_focus_t* wk_camera_cmd_focus)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_focus_send(chan, wk_camera_cmd_focus->type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS, (const char *)wk_camera_cmd_focus, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_cmd_focus_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_CRC);
#else
    mavlink_wk_camera_cmd_focus_t *packet = (mavlink_wk_camera_cmd_focus_t *)msgbuf;
    packet->type = type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_CMD_FOCUS UNPACKING


/**
 * @brief Get field type from wk_camera_cmd_focus message
 *
 * @return  see enum WKCAM_FOCUS_SET
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_focus_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a wk_camera_cmd_focus message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_cmd_focus C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_cmd_focus_decode(const mavlink_message_t* msg, mavlink_wk_camera_cmd_focus_t* wk_camera_cmd_focus)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_cmd_focus->type = mavlink_msg_wk_camera_cmd_focus_get_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN;
        memset(wk_camera_cmd_focus, 0, MAVLINK_MSG_ID_WK_CAMERA_CMD_FOCUS_LEN);
    memcpy(wk_camera_cmd_focus, _MAV_PAYLOAD(msg), len);
#endif
}
