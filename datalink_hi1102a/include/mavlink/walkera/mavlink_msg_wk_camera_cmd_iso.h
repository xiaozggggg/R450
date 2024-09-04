#pragma once
// MESSAGE WK_CAMERA_CMD_ISO PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO 8052


typedef struct __mavlink_wk_camera_cmd_iso_t {
 uint32_t iso; /*<  see enum WKCAM_ISO_TYPE*/
} mavlink_wk_camera_cmd_iso_t;

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN 4
#define MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_MIN_LEN 4
#define MAVLINK_MSG_ID_8052_LEN 4
#define MAVLINK_MSG_ID_8052_MIN_LEN 4

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_CRC 154
#define MAVLINK_MSG_ID_8052_CRC 154



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_ISO { \
    8052, \
    "WK_CAMERA_CMD_ISO", \
    1, \
    {  { "iso", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_cmd_iso_t, iso) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_ISO { \
    "WK_CAMERA_CMD_ISO", \
    1, \
    {  { "iso", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_cmd_iso_t, iso) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_cmd_iso message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param iso  see enum WKCAM_ISO_TYPE
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_iso_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t iso)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN];
    _mav_put_uint32_t(buf, 0, iso);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN);
#else
    mavlink_wk_camera_cmd_iso_t packet;
    packet.iso = iso;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_CRC);
}

/**
 * @brief Pack a wk_camera_cmd_iso message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param iso  see enum WKCAM_ISO_TYPE
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_iso_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t iso)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN];
    _mav_put_uint32_t(buf, 0, iso);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN);
#else
    mavlink_wk_camera_cmd_iso_t packet;
    packet.iso = iso;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_CRC);
}

/**
 * @brief Encode a wk_camera_cmd_iso struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_iso C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_iso_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_cmd_iso_t* wk_camera_cmd_iso)
{
    return mavlink_msg_wk_camera_cmd_iso_pack(system_id, component_id, msg, wk_camera_cmd_iso->iso);
}

/**
 * @brief Encode a wk_camera_cmd_iso struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_iso C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_iso_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_cmd_iso_t* wk_camera_cmd_iso)
{
    return mavlink_msg_wk_camera_cmd_iso_pack_chan(system_id, component_id, chan, msg, wk_camera_cmd_iso->iso);
}

/**
 * @brief Send a wk_camera_cmd_iso message
 * @param chan MAVLink channel to send the message
 *
 * @param iso  see enum WKCAM_ISO_TYPE
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_cmd_iso_send(mavlink_channel_t chan, uint32_t iso)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN];
    _mav_put_uint32_t(buf, 0, iso);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_CRC);
#else
    mavlink_wk_camera_cmd_iso_t packet;
    packet.iso = iso;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_CRC);
#endif
}

/**
 * @brief Send a wk_camera_cmd_iso message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_cmd_iso_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_cmd_iso_t* wk_camera_cmd_iso)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_iso_send(chan, wk_camera_cmd_iso->iso);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO, (const char *)wk_camera_cmd_iso, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_cmd_iso_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t iso)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, iso);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_CRC);
#else
    mavlink_wk_camera_cmd_iso_t *packet = (mavlink_wk_camera_cmd_iso_t *)msgbuf;
    packet->iso = iso;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_CMD_ISO UNPACKING


/**
 * @brief Get field iso from wk_camera_cmd_iso message
 *
 * @return  see enum WKCAM_ISO_TYPE
 */
static inline uint32_t mavlink_msg_wk_camera_cmd_iso_get_iso(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a wk_camera_cmd_iso message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_cmd_iso C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_cmd_iso_decode(const mavlink_message_t* msg, mavlink_wk_camera_cmd_iso_t* wk_camera_cmd_iso)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_cmd_iso->iso = mavlink_msg_wk_camera_cmd_iso_get_iso(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN;
        memset(wk_camera_cmd_iso, 0, MAVLINK_MSG_ID_WK_CAMERA_CMD_ISO_LEN);
    memcpy(wk_camera_cmd_iso, _MAV_PAYLOAD(msg), len);
#endif
}
