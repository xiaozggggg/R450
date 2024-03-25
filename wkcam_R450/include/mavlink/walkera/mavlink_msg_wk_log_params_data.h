#pragma once
// MESSAGE WK_LOG_PARAMS_DATA PACKING

#define MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA 8514


typedef struct __mavlink_wk_log_params_data_t {
 float param_value[10]; /*<  param_value*/
 uint16_t start_seq; /*<  sequence*/
 uint16_t total_cnt; /*<  total count*/
 uint8_t param_counts; /*<  param counts in this packet*/
 uint8_t param_name[160]; /*<  param name*/
} mavlink_wk_log_params_data_t;

#define MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN 205
#define MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_MIN_LEN 205
#define MAVLINK_MSG_ID_8514_LEN 205
#define MAVLINK_MSG_ID_8514_MIN_LEN 205

#define MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_CRC 87
#define MAVLINK_MSG_ID_8514_CRC 87

#define MAVLINK_MSG_WK_LOG_PARAMS_DATA_FIELD_PARAM_VALUE_LEN 10
#define MAVLINK_MSG_WK_LOG_PARAMS_DATA_FIELD_PARAM_NAME_LEN 160

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_LOG_PARAMS_DATA { \
    8514, \
    "WK_LOG_PARAMS_DATA", \
    5, \
    {  { "start_seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_wk_log_params_data_t, start_seq) }, \
         { "total_cnt", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_wk_log_params_data_t, total_cnt) }, \
         { "param_counts", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_wk_log_params_data_t, param_counts) }, \
         { "param_name", NULL, MAVLINK_TYPE_UINT8_T, 160, 45, offsetof(mavlink_wk_log_params_data_t, param_name) }, \
         { "param_value", NULL, MAVLINK_TYPE_FLOAT, 10, 0, offsetof(mavlink_wk_log_params_data_t, param_value) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_LOG_PARAMS_DATA { \
    "WK_LOG_PARAMS_DATA", \
    5, \
    {  { "start_seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_wk_log_params_data_t, start_seq) }, \
         { "total_cnt", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_wk_log_params_data_t, total_cnt) }, \
         { "param_counts", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_wk_log_params_data_t, param_counts) }, \
         { "param_name", NULL, MAVLINK_TYPE_UINT8_T, 160, 45, offsetof(mavlink_wk_log_params_data_t, param_name) }, \
         { "param_value", NULL, MAVLINK_TYPE_FLOAT, 10, 0, offsetof(mavlink_wk_log_params_data_t, param_value) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_log_params_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param start_seq  sequence
 * @param total_cnt  total count
 * @param param_counts  param counts in this packet
 * @param param_name  param name
 * @param param_value  param_value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_params_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t start_seq, uint16_t total_cnt, uint8_t param_counts, const uint8_t *param_name, const float *param_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN];
    _mav_put_uint16_t(buf, 40, start_seq);
    _mav_put_uint16_t(buf, 42, total_cnt);
    _mav_put_uint8_t(buf, 44, param_counts);
    _mav_put_float_array(buf, 0, param_value, 10);
    _mav_put_uint8_t_array(buf, 45, param_name, 160);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN);
#else
    mavlink_wk_log_params_data_t packet;
    packet.start_seq = start_seq;
    packet.total_cnt = total_cnt;
    packet.param_counts = param_counts;
    mav_array_memcpy(packet.param_value, param_value, sizeof(float)*10);
    mav_array_memcpy(packet.param_name, param_name, sizeof(uint8_t)*160);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_CRC);
}

/**
 * @brief Pack a wk_log_params_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param start_seq  sequence
 * @param total_cnt  total count
 * @param param_counts  param counts in this packet
 * @param param_name  param name
 * @param param_value  param_value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_params_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t start_seq,uint16_t total_cnt,uint8_t param_counts,const uint8_t *param_name,const float *param_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN];
    _mav_put_uint16_t(buf, 40, start_seq);
    _mav_put_uint16_t(buf, 42, total_cnt);
    _mav_put_uint8_t(buf, 44, param_counts);
    _mav_put_float_array(buf, 0, param_value, 10);
    _mav_put_uint8_t_array(buf, 45, param_name, 160);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN);
#else
    mavlink_wk_log_params_data_t packet;
    packet.start_seq = start_seq;
    packet.total_cnt = total_cnt;
    packet.param_counts = param_counts;
    mav_array_memcpy(packet.param_value, param_value, sizeof(float)*10);
    mav_array_memcpy(packet.param_name, param_name, sizeof(uint8_t)*160);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_CRC);
}

/**
 * @brief Encode a wk_log_params_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_params_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_params_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_log_params_data_t* wk_log_params_data)
{
    return mavlink_msg_wk_log_params_data_pack(system_id, component_id, msg, wk_log_params_data->start_seq, wk_log_params_data->total_cnt, wk_log_params_data->param_counts, wk_log_params_data->param_name, wk_log_params_data->param_value);
}

/**
 * @brief Encode a wk_log_params_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_params_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_params_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_log_params_data_t* wk_log_params_data)
{
    return mavlink_msg_wk_log_params_data_pack_chan(system_id, component_id, chan, msg, wk_log_params_data->start_seq, wk_log_params_data->total_cnt, wk_log_params_data->param_counts, wk_log_params_data->param_name, wk_log_params_data->param_value);
}

/**
 * @brief Send a wk_log_params_data message
 * @param chan MAVLink channel to send the message
 *
 * @param start_seq  sequence
 * @param total_cnt  total count
 * @param param_counts  param counts in this packet
 * @param param_name  param name
 * @param param_value  param_value
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_log_params_data_send(mavlink_channel_t chan, uint16_t start_seq, uint16_t total_cnt, uint8_t param_counts, const uint8_t *param_name, const float *param_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN];
    _mav_put_uint16_t(buf, 40, start_seq);
    _mav_put_uint16_t(buf, 42, total_cnt);
    _mav_put_uint8_t(buf, 44, param_counts);
    _mav_put_float_array(buf, 0, param_value, 10);
    _mav_put_uint8_t_array(buf, 45, param_name, 160);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA, buf, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_CRC);
#else
    mavlink_wk_log_params_data_t packet;
    packet.start_seq = start_seq;
    packet.total_cnt = total_cnt;
    packet.param_counts = param_counts;
    mav_array_memcpy(packet.param_value, param_value, sizeof(float)*10);
    mav_array_memcpy(packet.param_name, param_name, sizeof(uint8_t)*160);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA, (const char *)&packet, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_CRC);
#endif
}

/**
 * @brief Send a wk_log_params_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_log_params_data_send_struct(mavlink_channel_t chan, const mavlink_wk_log_params_data_t* wk_log_params_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_log_params_data_send(chan, wk_log_params_data->start_seq, wk_log_params_data->total_cnt, wk_log_params_data->param_counts, wk_log_params_data->param_name, wk_log_params_data->param_value);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA, (const char *)wk_log_params_data, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_log_params_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t start_seq, uint16_t total_cnt, uint8_t param_counts, const uint8_t *param_name, const float *param_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 40, start_seq);
    _mav_put_uint16_t(buf, 42, total_cnt);
    _mav_put_uint8_t(buf, 44, param_counts);
    _mav_put_float_array(buf, 0, param_value, 10);
    _mav_put_uint8_t_array(buf, 45, param_name, 160);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA, buf, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_CRC);
#else
    mavlink_wk_log_params_data_t *packet = (mavlink_wk_log_params_data_t *)msgbuf;
    packet->start_seq = start_seq;
    packet->total_cnt = total_cnt;
    packet->param_counts = param_counts;
    mav_array_memcpy(packet->param_value, param_value, sizeof(float)*10);
    mav_array_memcpy(packet->param_name, param_name, sizeof(uint8_t)*160);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA, (const char *)packet, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_LOG_PARAMS_DATA UNPACKING


/**
 * @brief Get field start_seq from wk_log_params_data message
 *
 * @return  sequence
 */
static inline uint16_t mavlink_msg_wk_log_params_data_get_start_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  40);
}

/**
 * @brief Get field total_cnt from wk_log_params_data message
 *
 * @return  total count
 */
static inline uint16_t mavlink_msg_wk_log_params_data_get_total_cnt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  42);
}

/**
 * @brief Get field param_counts from wk_log_params_data message
 *
 * @return  param counts in this packet
 */
static inline uint8_t mavlink_msg_wk_log_params_data_get_param_counts(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  44);
}

/**
 * @brief Get field param_name from wk_log_params_data message
 *
 * @return  param name
 */
static inline uint16_t mavlink_msg_wk_log_params_data_get_param_name(const mavlink_message_t* msg, uint8_t *param_name)
{
    return _MAV_RETURN_uint8_t_array(msg, param_name, 160,  45);
}

/**
 * @brief Get field param_value from wk_log_params_data message
 *
 * @return  param_value
 */
static inline uint16_t mavlink_msg_wk_log_params_data_get_param_value(const mavlink_message_t* msg, float *param_value)
{
    return _MAV_RETURN_float_array(msg, param_value, 10,  0);
}

/**
 * @brief Decode a wk_log_params_data message into a struct
 *
 * @param msg The message to decode
 * @param wk_log_params_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_log_params_data_decode(const mavlink_message_t* msg, mavlink_wk_log_params_data_t* wk_log_params_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_log_params_data_get_param_value(msg, wk_log_params_data->param_value);
    wk_log_params_data->start_seq = mavlink_msg_wk_log_params_data_get_start_seq(msg);
    wk_log_params_data->total_cnt = mavlink_msg_wk_log_params_data_get_total_cnt(msg);
    wk_log_params_data->param_counts = mavlink_msg_wk_log_params_data_get_param_counts(msg);
    mavlink_msg_wk_log_params_data_get_param_name(msg, wk_log_params_data->param_name);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN? msg->len : MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN;
        memset(wk_log_params_data, 0, MAVLINK_MSG_ID_WK_LOG_PARAMS_DATA_LEN);
    memcpy(wk_log_params_data, _MAV_PAYLOAD(msg), len);
#endif
}
