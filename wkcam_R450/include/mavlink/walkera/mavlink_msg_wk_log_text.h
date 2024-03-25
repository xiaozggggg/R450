#pragma once
// MESSAGE WK_LOG_TEXT PACKING

#define MAVLINK_MSG_ID_WK_LOG_TEXT 8512


typedef struct __mavlink_wk_log_text_t {
 uint64_t timestamp; /*<  timestamp*/
 uint8_t text[230]; /*<  text string*/
} mavlink_wk_log_text_t;

#define MAVLINK_MSG_ID_WK_LOG_TEXT_LEN 238
#define MAVLINK_MSG_ID_WK_LOG_TEXT_MIN_LEN 238
#define MAVLINK_MSG_ID_8512_LEN 238
#define MAVLINK_MSG_ID_8512_MIN_LEN 238

#define MAVLINK_MSG_ID_WK_LOG_TEXT_CRC 48
#define MAVLINK_MSG_ID_8512_CRC 48

#define MAVLINK_MSG_WK_LOG_TEXT_FIELD_TEXT_LEN 230

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_LOG_TEXT { \
    8512, \
    "WK_LOG_TEXT", \
    2, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_text_t, timestamp) }, \
         { "text", NULL, MAVLINK_TYPE_UINT8_T, 230, 8, offsetof(mavlink_wk_log_text_t, text) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_LOG_TEXT { \
    "WK_LOG_TEXT", \
    2, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_text_t, timestamp) }, \
         { "text", NULL, MAVLINK_TYPE_UINT8_T, 230, 8, offsetof(mavlink_wk_log_text_t, text) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_log_text message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  timestamp
 * @param text  text string
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_text_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, const uint8_t *text)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_TEXT_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t_array(buf, 8, text, 230);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_TEXT_LEN);
#else
    mavlink_wk_log_text_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.text, text, sizeof(uint8_t)*230);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_TEXT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_TEXT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_LOG_TEXT_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_TEXT_LEN, MAVLINK_MSG_ID_WK_LOG_TEXT_CRC);
}

/**
 * @brief Pack a wk_log_text message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  timestamp
 * @param text  text string
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_text_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,const uint8_t *text)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_TEXT_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t_array(buf, 8, text, 230);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_TEXT_LEN);
#else
    mavlink_wk_log_text_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.text, text, sizeof(uint8_t)*230);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_TEXT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_TEXT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_LOG_TEXT_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_TEXT_LEN, MAVLINK_MSG_ID_WK_LOG_TEXT_CRC);
}

/**
 * @brief Encode a wk_log_text struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_text C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_text_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_log_text_t* wk_log_text)
{
    return mavlink_msg_wk_log_text_pack(system_id, component_id, msg, wk_log_text->timestamp, wk_log_text->text);
}

/**
 * @brief Encode a wk_log_text struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_text C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_text_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_log_text_t* wk_log_text)
{
    return mavlink_msg_wk_log_text_pack_chan(system_id, component_id, chan, msg, wk_log_text->timestamp, wk_log_text->text);
}

/**
 * @brief Send a wk_log_text message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 * @param text  text string
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_log_text_send(mavlink_channel_t chan, uint64_t timestamp, const uint8_t *text)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_TEXT_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t_array(buf, 8, text, 230);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_TEXT, buf, MAVLINK_MSG_ID_WK_LOG_TEXT_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_TEXT_LEN, MAVLINK_MSG_ID_WK_LOG_TEXT_CRC);
#else
    mavlink_wk_log_text_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.text, text, sizeof(uint8_t)*230);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_TEXT, (const char *)&packet, MAVLINK_MSG_ID_WK_LOG_TEXT_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_TEXT_LEN, MAVLINK_MSG_ID_WK_LOG_TEXT_CRC);
#endif
}

/**
 * @brief Send a wk_log_text message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_log_text_send_struct(mavlink_channel_t chan, const mavlink_wk_log_text_t* wk_log_text)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_log_text_send(chan, wk_log_text->timestamp, wk_log_text->text);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_TEXT, (const char *)wk_log_text, MAVLINK_MSG_ID_WK_LOG_TEXT_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_TEXT_LEN, MAVLINK_MSG_ID_WK_LOG_TEXT_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_LOG_TEXT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_log_text_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, const uint8_t *text)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint8_t_array(buf, 8, text, 230);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_TEXT, buf, MAVLINK_MSG_ID_WK_LOG_TEXT_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_TEXT_LEN, MAVLINK_MSG_ID_WK_LOG_TEXT_CRC);
#else
    mavlink_wk_log_text_t *packet = (mavlink_wk_log_text_t *)msgbuf;
    packet->timestamp = timestamp;
    mav_array_memcpy(packet->text, text, sizeof(uint8_t)*230);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_TEXT, (const char *)packet, MAVLINK_MSG_ID_WK_LOG_TEXT_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_TEXT_LEN, MAVLINK_MSG_ID_WK_LOG_TEXT_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_LOG_TEXT UNPACKING


/**
 * @brief Get field timestamp from wk_log_text message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_wk_log_text_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field text from wk_log_text message
 *
 * @return  text string
 */
static inline uint16_t mavlink_msg_wk_log_text_get_text(const mavlink_message_t* msg, uint8_t *text)
{
    return _MAV_RETURN_uint8_t_array(msg, text, 230,  8);
}

/**
 * @brief Decode a wk_log_text message into a struct
 *
 * @param msg The message to decode
 * @param wk_log_text C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_log_text_decode(const mavlink_message_t* msg, mavlink_wk_log_text_t* wk_log_text)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_log_text->timestamp = mavlink_msg_wk_log_text_get_timestamp(msg);
    mavlink_msg_wk_log_text_get_text(msg, wk_log_text->text);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_LOG_TEXT_LEN? msg->len : MAVLINK_MSG_ID_WK_LOG_TEXT_LEN;
        memset(wk_log_text, 0, MAVLINK_MSG_ID_WK_LOG_TEXT_LEN);
    memcpy(wk_log_text, _MAV_PAYLOAD(msg), len);
#endif
}
