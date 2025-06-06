#pragma once
// MESSAGE WK_MOUNT_STATUS PACKING

#define MAVLINK_MSG_ID_WK_MOUNT_STATUS 8008


typedef struct __mavlink_wk_mount_status_t {
 uint32_t mount_bitmasks; /*<  mount device bitmasks��see WK_MOUNT_STATUS and WK_MOUNT_CTRL_CMD)*/
} mavlink_wk_mount_status_t;

#define MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN 4
#define MAVLINK_MSG_ID_WK_MOUNT_STATUS_MIN_LEN 4
#define MAVLINK_MSG_ID_8008_LEN 4
#define MAVLINK_MSG_ID_8008_MIN_LEN 4

#define MAVLINK_MSG_ID_WK_MOUNT_STATUS_CRC 235
#define MAVLINK_MSG_ID_8008_CRC 235



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_MOUNT_STATUS { \
    8008, \
    "WK_MOUNT_STATUS", \
    1, \
    {  { "mount_bitmasks", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_mount_status_t, mount_bitmasks) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_MOUNT_STATUS { \
    "WK_MOUNT_STATUS", \
    1, \
    {  { "mount_bitmasks", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_mount_status_t, mount_bitmasks) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_mount_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mount_bitmasks  mount device bitmasks��see WK_MOUNT_STATUS and WK_MOUNT_CTRL_CMD)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_mount_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t mount_bitmasks)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, mount_bitmasks);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN);
#else
    mavlink_wk_mount_status_t packet;
    packet.mount_bitmasks = mount_bitmasks;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_MOUNT_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_MOUNT_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN, MAVLINK_MSG_ID_WK_MOUNT_STATUS_CRC);
}

/**
 * @brief Pack a wk_mount_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mount_bitmasks  mount device bitmasks��see WK_MOUNT_STATUS and WK_MOUNT_CTRL_CMD)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_mount_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t mount_bitmasks)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, mount_bitmasks);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN);
#else
    mavlink_wk_mount_status_t packet;
    packet.mount_bitmasks = mount_bitmasks;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_MOUNT_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_MOUNT_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN, MAVLINK_MSG_ID_WK_MOUNT_STATUS_CRC);
}

/**
 * @brief Encode a wk_mount_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_mount_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_mount_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_mount_status_t* wk_mount_status)
{
    return mavlink_msg_wk_mount_status_pack(system_id, component_id, msg, wk_mount_status->mount_bitmasks);
}

/**
 * @brief Encode a wk_mount_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_mount_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_mount_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_mount_status_t* wk_mount_status)
{
    return mavlink_msg_wk_mount_status_pack_chan(system_id, component_id, chan, msg, wk_mount_status->mount_bitmasks);
}

/**
 * @brief Send a wk_mount_status message
 * @param chan MAVLink channel to send the message
 *
 * @param mount_bitmasks  mount device bitmasks��see WK_MOUNT_STATUS and WK_MOUNT_CTRL_CMD)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_mount_status_send(mavlink_channel_t chan, uint32_t mount_bitmasks)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, mount_bitmasks);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MOUNT_STATUS, buf, MAVLINK_MSG_ID_WK_MOUNT_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN, MAVLINK_MSG_ID_WK_MOUNT_STATUS_CRC);
#else
    mavlink_wk_mount_status_t packet;
    packet.mount_bitmasks = mount_bitmasks;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MOUNT_STATUS, (const char *)&packet, MAVLINK_MSG_ID_WK_MOUNT_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN, MAVLINK_MSG_ID_WK_MOUNT_STATUS_CRC);
#endif
}

/**
 * @brief Send a wk_mount_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_mount_status_send_struct(mavlink_channel_t chan, const mavlink_wk_mount_status_t* wk_mount_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_mount_status_send(chan, wk_mount_status->mount_bitmasks);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MOUNT_STATUS, (const char *)wk_mount_status, MAVLINK_MSG_ID_WK_MOUNT_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN, MAVLINK_MSG_ID_WK_MOUNT_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_mount_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t mount_bitmasks)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, mount_bitmasks);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MOUNT_STATUS, buf, MAVLINK_MSG_ID_WK_MOUNT_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN, MAVLINK_MSG_ID_WK_MOUNT_STATUS_CRC);
#else
    mavlink_wk_mount_status_t *packet = (mavlink_wk_mount_status_t *)msgbuf;
    packet->mount_bitmasks = mount_bitmasks;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MOUNT_STATUS, (const char *)packet, MAVLINK_MSG_ID_WK_MOUNT_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN, MAVLINK_MSG_ID_WK_MOUNT_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_MOUNT_STATUS UNPACKING


/**
 * @brief Get field mount_bitmasks from wk_mount_status message
 *
 * @return  mount device bitmasks��see WK_MOUNT_STATUS and WK_MOUNT_CTRL_CMD)
 */
static inline uint32_t mavlink_msg_wk_mount_status_get_mount_bitmasks(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a wk_mount_status message into a struct
 *
 * @param msg The message to decode
 * @param wk_mount_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_mount_status_decode(const mavlink_message_t* msg, mavlink_wk_mount_status_t* wk_mount_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_mount_status->mount_bitmasks = mavlink_msg_wk_mount_status_get_mount_bitmasks(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN? msg->len : MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN;
        memset(wk_mount_status, 0, MAVLINK_MSG_ID_WK_MOUNT_STATUS_LEN);
    memcpy(wk_mount_status, _MAV_PAYLOAD(msg), len);
#endif
}
