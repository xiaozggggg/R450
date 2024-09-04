#pragma once
// MESSAGE WK_CAMERA_CMD_SHUTTER PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER 8053


typedef struct __mavlink_wk_camera_cmd_shutter_t {
 uint32_t shutter; /*<  see enum WKCAM_SHUTTER*/
} mavlink_wk_camera_cmd_shutter_t;

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN 4
#define MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_MIN_LEN 4
#define MAVLINK_MSG_ID_8053_LEN 4
#define MAVLINK_MSG_ID_8053_MIN_LEN 4

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_CRC 175
#define MAVLINK_MSG_ID_8053_CRC 175



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_SHUTTER { \
    8053, \
    "WK_CAMERA_CMD_SHUTTER", \
    1, \
    {  { "shutter", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_cmd_shutter_t, shutter) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_SHUTTER { \
    "WK_CAMERA_CMD_SHUTTER", \
    1, \
    {  { "shutter", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_cmd_shutter_t, shutter) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_cmd_shutter message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param shutter  see enum WKCAM_SHUTTER
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_shutter_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t shutter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN];
    _mav_put_uint32_t(buf, 0, shutter);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN);
#else
    mavlink_wk_camera_cmd_shutter_t packet;
    packet.shutter = shutter;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_CRC);
}

/**
 * @brief Pack a wk_camera_cmd_shutter message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param shutter  see enum WKCAM_SHUTTER
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_shutter_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t shutter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN];
    _mav_put_uint32_t(buf, 0, shutter);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN);
#else
    mavlink_wk_camera_cmd_shutter_t packet;
    packet.shutter = shutter;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_CRC);
}

/**
 * @brief Encode a wk_camera_cmd_shutter struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_shutter C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_shutter_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_cmd_shutter_t* wk_camera_cmd_shutter)
{
    return mavlink_msg_wk_camera_cmd_shutter_pack(system_id, component_id, msg, wk_camera_cmd_shutter->shutter);
}

/**
 * @brief Encode a wk_camera_cmd_shutter struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_shutter C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_shutter_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_cmd_shutter_t* wk_camera_cmd_shutter)
{
    return mavlink_msg_wk_camera_cmd_shutter_pack_chan(system_id, component_id, chan, msg, wk_camera_cmd_shutter->shutter);
}

/**
 * @brief Send a wk_camera_cmd_shutter message
 * @param chan MAVLink channel to send the message
 *
 * @param shutter  see enum WKCAM_SHUTTER
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_cmd_shutter_send(mavlink_channel_t chan, uint32_t shutter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN];
    _mav_put_uint32_t(buf, 0, shutter);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_CRC);
#else
    mavlink_wk_camera_cmd_shutter_t packet;
    packet.shutter = shutter;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_CRC);
#endif
}

/**
 * @brief Send a wk_camera_cmd_shutter message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_cmd_shutter_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_cmd_shutter_t* wk_camera_cmd_shutter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_shutter_send(chan, wk_camera_cmd_shutter->shutter);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER, (const char *)wk_camera_cmd_shutter, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_cmd_shutter_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t shutter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, shutter);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_CRC);
#else
    mavlink_wk_camera_cmd_shutter_t *packet = (mavlink_wk_camera_cmd_shutter_t *)msgbuf;
    packet->shutter = shutter;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_CMD_SHUTTER UNPACKING


/**
 * @brief Get field shutter from wk_camera_cmd_shutter message
 *
 * @return  see enum WKCAM_SHUTTER
 */
static inline uint32_t mavlink_msg_wk_camera_cmd_shutter_get_shutter(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a wk_camera_cmd_shutter message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_cmd_shutter C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_cmd_shutter_decode(const mavlink_message_t* msg, mavlink_wk_camera_cmd_shutter_t* wk_camera_cmd_shutter)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_cmd_shutter->shutter = mavlink_msg_wk_camera_cmd_shutter_get_shutter(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN;
        memset(wk_camera_cmd_shutter, 0, MAVLINK_MSG_ID_WK_CAMERA_CMD_SHUTTER_LEN);
    memcpy(wk_camera_cmd_shutter, _MAV_PAYLOAD(msg), len);
#endif
}
