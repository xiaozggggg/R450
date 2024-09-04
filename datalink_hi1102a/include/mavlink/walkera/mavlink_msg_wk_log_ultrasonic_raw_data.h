#pragma once
// MESSAGE WK_LOG_ULTRASONIC_RAW_DATA PACKING

#define MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA 8518


typedef struct __mavlink_wk_log_ultrasonic_raw_data_t {
 uint64_t timestamp; /*<  timestamp*/
 uint16_t data[100]; /*<  raw data*/
} mavlink_wk_log_ultrasonic_raw_data_t;

#define MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN 208
#define MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_MIN_LEN 208
#define MAVLINK_MSG_ID_8518_LEN 208
#define MAVLINK_MSG_ID_8518_MIN_LEN 208

#define MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_CRC 20
#define MAVLINK_MSG_ID_8518_CRC 20

#define MAVLINK_MSG_WK_LOG_ULTRASONIC_RAW_DATA_FIELD_DATA_LEN 100

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_LOG_ULTRASONIC_RAW_DATA { \
    8518, \
    "WK_LOG_ULTRASONIC_RAW_DATA", \
    2, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_ultrasonic_raw_data_t, timestamp) }, \
         { "data", NULL, MAVLINK_TYPE_UINT16_T, 100, 8, offsetof(mavlink_wk_log_ultrasonic_raw_data_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_LOG_ULTRASONIC_RAW_DATA { \
    "WK_LOG_ULTRASONIC_RAW_DATA", \
    2, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_ultrasonic_raw_data_t, timestamp) }, \
         { "data", NULL, MAVLINK_TYPE_UINT16_T, 100, 8, offsetof(mavlink_wk_log_ultrasonic_raw_data_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_log_ultrasonic_raw_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  timestamp
 * @param data  raw data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_ultrasonic_raw_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, const uint16_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint16_t_array(buf, 8, data, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN);
#else
    mavlink_wk_log_ultrasonic_raw_data_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.data, data, sizeof(uint16_t)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_CRC);
}

/**
 * @brief Pack a wk_log_ultrasonic_raw_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  timestamp
 * @param data  raw data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_ultrasonic_raw_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,const uint16_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint16_t_array(buf, 8, data, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN);
#else
    mavlink_wk_log_ultrasonic_raw_data_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.data, data, sizeof(uint16_t)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_CRC);
}

/**
 * @brief Encode a wk_log_ultrasonic_raw_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_ultrasonic_raw_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_ultrasonic_raw_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_log_ultrasonic_raw_data_t* wk_log_ultrasonic_raw_data)
{
    return mavlink_msg_wk_log_ultrasonic_raw_data_pack(system_id, component_id, msg, wk_log_ultrasonic_raw_data->timestamp, wk_log_ultrasonic_raw_data->data);
}

/**
 * @brief Encode a wk_log_ultrasonic_raw_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_ultrasonic_raw_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_ultrasonic_raw_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_log_ultrasonic_raw_data_t* wk_log_ultrasonic_raw_data)
{
    return mavlink_msg_wk_log_ultrasonic_raw_data_pack_chan(system_id, component_id, chan, msg, wk_log_ultrasonic_raw_data->timestamp, wk_log_ultrasonic_raw_data->data);
}

/**
 * @brief Send a wk_log_ultrasonic_raw_data message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 * @param data  raw data
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_log_ultrasonic_raw_data_send(mavlink_channel_t chan, uint64_t timestamp, const uint16_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint16_t_array(buf, 8, data, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA, buf, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_CRC);
#else
    mavlink_wk_log_ultrasonic_raw_data_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.data, data, sizeof(uint16_t)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA, (const char *)&packet, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_CRC);
#endif
}

/**
 * @brief Send a wk_log_ultrasonic_raw_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_log_ultrasonic_raw_data_send_struct(mavlink_channel_t chan, const mavlink_wk_log_ultrasonic_raw_data_t* wk_log_ultrasonic_raw_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_log_ultrasonic_raw_data_send(chan, wk_log_ultrasonic_raw_data->timestamp, wk_log_ultrasonic_raw_data->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA, (const char *)wk_log_ultrasonic_raw_data, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_log_ultrasonic_raw_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, const uint16_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint16_t_array(buf, 8, data, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA, buf, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_CRC);
#else
    mavlink_wk_log_ultrasonic_raw_data_t *packet = (mavlink_wk_log_ultrasonic_raw_data_t *)msgbuf;
    packet->timestamp = timestamp;
    mav_array_memcpy(packet->data, data, sizeof(uint16_t)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA, (const char *)packet, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_LOG_ULTRASONIC_RAW_DATA UNPACKING


/**
 * @brief Get field timestamp from wk_log_ultrasonic_raw_data message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_wk_log_ultrasonic_raw_data_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field data from wk_log_ultrasonic_raw_data message
 *
 * @return  raw data
 */
static inline uint16_t mavlink_msg_wk_log_ultrasonic_raw_data_get_data(const mavlink_message_t* msg, uint16_t *data)
{
    return _MAV_RETURN_uint16_t_array(msg, data, 100,  8);
}

/**
 * @brief Decode a wk_log_ultrasonic_raw_data message into a struct
 *
 * @param msg The message to decode
 * @param wk_log_ultrasonic_raw_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_log_ultrasonic_raw_data_decode(const mavlink_message_t* msg, mavlink_wk_log_ultrasonic_raw_data_t* wk_log_ultrasonic_raw_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_log_ultrasonic_raw_data->timestamp = mavlink_msg_wk_log_ultrasonic_raw_data_get_timestamp(msg);
    mavlink_msg_wk_log_ultrasonic_raw_data_get_data(msg, wk_log_ultrasonic_raw_data->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN? msg->len : MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN;
        memset(wk_log_ultrasonic_raw_data, 0, MAVLINK_MSG_ID_WK_LOG_ULTRASONIC_RAW_DATA_LEN);
    memcpy(wk_log_ultrasonic_raw_data, _MAV_PAYLOAD(msg), len);
#endif
}
