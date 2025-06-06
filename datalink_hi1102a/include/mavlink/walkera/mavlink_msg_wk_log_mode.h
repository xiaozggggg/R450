#pragma once
// MESSAGE WK_LOG_MODE PACKING

#define MAVLINK_MSG_ID_WK_LOG_MODE 8509


typedef struct __mavlink_wk_log_mode_t {
 uint64_t timestamp; /*<  timestamp*/
 uint8_t mode; /*<  mode*/
 uint8_t reason; /*<  reason*/
} mavlink_wk_log_mode_t;

#define MAVLINK_MSG_ID_WK_LOG_MODE_LEN 10
#define MAVLINK_MSG_ID_WK_LOG_MODE_MIN_LEN 10
#define MAVLINK_MSG_ID_8509_LEN 10
#define MAVLINK_MSG_ID_8509_MIN_LEN 10

#define MAVLINK_MSG_ID_WK_LOG_MODE_CRC 179
#define MAVLINK_MSG_ID_8509_CRC 179



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_LOG_MODE { \
    8509, \
    "WK_LOG_MODE", \
    3, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_mode_t, timestamp) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wk_log_mode_t, mode) }, \
         { "reason", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_wk_log_mode_t, reason) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_LOG_MODE { \
    "WK_LOG_MODE", \
    3, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_mode_t, timestamp) }, \
         { "mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wk_log_mode_t, mode) }, \
         { "reason", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_wk_log_mode_t, reason) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_log_mode message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  timestamp
 * @param mode  mode
 * @param reason  reason
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_mode_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint8_t mode, uint8_t reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_MODE_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 8, mode);
    _mav_put_uint8_t(buf, 9, reason);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_MODE_LEN);
#else
    mavlink_wk_log_mode_t packet;
    packet.timestamp = timestamp;
    packet.mode = mode;
    packet.reason = reason;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_MODE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_LOG_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MODE_LEN, MAVLINK_MSG_ID_WK_LOG_MODE_CRC);
}

/**
 * @brief Pack a wk_log_mode message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  timestamp
 * @param mode  mode
 * @param reason  reason
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_mode_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,uint8_t mode,uint8_t reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_MODE_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 8, mode);
    _mav_put_uint8_t(buf, 9, reason);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_MODE_LEN);
#else
    mavlink_wk_log_mode_t packet;
    packet.timestamp = timestamp;
    packet.mode = mode;
    packet.reason = reason;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_MODE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_LOG_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MODE_LEN, MAVLINK_MSG_ID_WK_LOG_MODE_CRC);
}

/**
 * @brief Encode a wk_log_mode struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_mode_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_log_mode_t* wk_log_mode)
{
    return mavlink_msg_wk_log_mode_pack(system_id, component_id, msg, wk_log_mode->timestamp, wk_log_mode->mode, wk_log_mode->reason);
}

/**
 * @brief Encode a wk_log_mode struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_mode_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_log_mode_t* wk_log_mode)
{
    return mavlink_msg_wk_log_mode_pack_chan(system_id, component_id, chan, msg, wk_log_mode->timestamp, wk_log_mode->mode, wk_log_mode->reason);
}

/**
 * @brief Send a wk_log_mode message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 * @param mode  mode
 * @param reason  reason
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_log_mode_send(mavlink_channel_t chan, uint64_t timestamp, uint8_t mode, uint8_t reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_MODE_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 8, mode);
    _mav_put_uint8_t(buf, 9, reason);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_MODE, buf, MAVLINK_MSG_ID_WK_LOG_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MODE_LEN, MAVLINK_MSG_ID_WK_LOG_MODE_CRC);
#else
    mavlink_wk_log_mode_t packet;
    packet.timestamp = timestamp;
    packet.mode = mode;
    packet.reason = reason;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_MODE, (const char *)&packet, MAVLINK_MSG_ID_WK_LOG_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MODE_LEN, MAVLINK_MSG_ID_WK_LOG_MODE_CRC);
#endif
}

/**
 * @brief Send a wk_log_mode message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_log_mode_send_struct(mavlink_channel_t chan, const mavlink_wk_log_mode_t* wk_log_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_log_mode_send(chan, wk_log_mode->timestamp, wk_log_mode->mode, wk_log_mode->reason);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_MODE, (const char *)wk_log_mode, MAVLINK_MSG_ID_WK_LOG_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MODE_LEN, MAVLINK_MSG_ID_WK_LOG_MODE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_LOG_MODE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_log_mode_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, uint8_t mode, uint8_t reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t(buf, 8, mode);
    _mav_put_uint8_t(buf, 9, reason);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_MODE, buf, MAVLINK_MSG_ID_WK_LOG_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MODE_LEN, MAVLINK_MSG_ID_WK_LOG_MODE_CRC);
#else
    mavlink_wk_log_mode_t *packet = (mavlink_wk_log_mode_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->mode = mode;
    packet->reason = reason;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_MODE, (const char *)packet, MAVLINK_MSG_ID_WK_LOG_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MODE_LEN, MAVLINK_MSG_ID_WK_LOG_MODE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_LOG_MODE UNPACKING


/**
 * @brief Get field timestamp from wk_log_mode message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_wk_log_mode_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field mode from wk_log_mode message
 *
 * @return  mode
 */
static inline uint8_t mavlink_msg_wk_log_mode_get_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field reason from wk_log_mode message
 *
 * @return  reason
 */
static inline uint8_t mavlink_msg_wk_log_mode_get_reason(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Decode a wk_log_mode message into a struct
 *
 * @param msg The message to decode
 * @param wk_log_mode C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_log_mode_decode(const mavlink_message_t* msg, mavlink_wk_log_mode_t* wk_log_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_log_mode->timestamp = mavlink_msg_wk_log_mode_get_timestamp(msg);
    wk_log_mode->mode = mavlink_msg_wk_log_mode_get_mode(msg);
    wk_log_mode->reason = mavlink_msg_wk_log_mode_get_reason(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_LOG_MODE_LEN? msg->len : MAVLINK_MSG_ID_WK_LOG_MODE_LEN;
        memset(wk_log_mode, 0, MAVLINK_MSG_ID_WK_LOG_MODE_LEN);
    memcpy(wk_log_mode, _MAV_PAYLOAD(msg), len);
#endif
}
