#pragma once
// MESSAGE WK_TOF_CSV_DATA PACKING

#define MAVLINK_MSG_ID_WK_TOF_CSV_DATA 8521


typedef struct __mavlink_wk_tof_csv_data_t {
 float magnitude; /*<  */
 uint8_t type; /*<  see enum WK_TOF_CALI_CSV_TYPE*/
 uint8_t index; /*<  */
 uint8_t type_value; /*<  */
 uint8_t D8; /*<  */
 uint8_t D9; /*<  */
 uint8_t total_num; /*<  */
} mavlink_wk_tof_csv_data_t;

#define MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN 10
#define MAVLINK_MSG_ID_WK_TOF_CSV_DATA_MIN_LEN 10
#define MAVLINK_MSG_ID_8521_LEN 10
#define MAVLINK_MSG_ID_8521_MIN_LEN 10

#define MAVLINK_MSG_ID_WK_TOF_CSV_DATA_CRC 30
#define MAVLINK_MSG_ID_8521_CRC 30



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_TOF_CSV_DATA { \
    8521, \
    "WK_TOF_CSV_DATA", \
    7, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_tof_csv_data_t, type) }, \
         { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_tof_csv_data_t, index) }, \
         { "type_value", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_tof_csv_data_t, type_value) }, \
         { "D8", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_wk_tof_csv_data_t, D8) }, \
         { "D9", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wk_tof_csv_data_t, D9) }, \
         { "total_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_wk_tof_csv_data_t, total_num) }, \
         { "magnitude", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_tof_csv_data_t, magnitude) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_TOF_CSV_DATA { \
    "WK_TOF_CSV_DATA", \
    7, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_tof_csv_data_t, type) }, \
         { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_tof_csv_data_t, index) }, \
         { "type_value", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_tof_csv_data_t, type_value) }, \
         { "D8", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_wk_tof_csv_data_t, D8) }, \
         { "D9", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wk_tof_csv_data_t, D9) }, \
         { "total_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_wk_tof_csv_data_t, total_num) }, \
         { "magnitude", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_tof_csv_data_t, magnitude) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_tof_csv_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type  see enum WK_TOF_CALI_CSV_TYPE
 * @param index  
 * @param type_value  
 * @param D8  
 * @param D9  
 * @param total_num  
 * @param magnitude  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_tof_csv_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t type, uint8_t index, uint8_t type_value, uint8_t D8, uint8_t D9, uint8_t total_num, float magnitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN];
    _mav_put_float(buf, 0, magnitude);
    _mav_put_uint8_t(buf, 4, type);
    _mav_put_uint8_t(buf, 5, index);
    _mav_put_uint8_t(buf, 6, type_value);
    _mav_put_uint8_t(buf, 7, D8);
    _mav_put_uint8_t(buf, 8, D9);
    _mav_put_uint8_t(buf, 9, total_num);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN);
#else
    mavlink_wk_tof_csv_data_t packet;
    packet.magnitude = magnitude;
    packet.type = type;
    packet.index = index;
    packet.type_value = type_value;
    packet.D8 = D8;
    packet.D9 = D9;
    packet.total_num = total_num;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_TOF_CSV_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_CRC);
}

/**
 * @brief Pack a wk_tof_csv_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type  see enum WK_TOF_CALI_CSV_TYPE
 * @param index  
 * @param type_value  
 * @param D8  
 * @param D9  
 * @param total_num  
 * @param magnitude  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_tof_csv_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t type,uint8_t index,uint8_t type_value,uint8_t D8,uint8_t D9,uint8_t total_num,float magnitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN];
    _mav_put_float(buf, 0, magnitude);
    _mav_put_uint8_t(buf, 4, type);
    _mav_put_uint8_t(buf, 5, index);
    _mav_put_uint8_t(buf, 6, type_value);
    _mav_put_uint8_t(buf, 7, D8);
    _mav_put_uint8_t(buf, 8, D9);
    _mav_put_uint8_t(buf, 9, total_num);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN);
#else
    mavlink_wk_tof_csv_data_t packet;
    packet.magnitude = magnitude;
    packet.type = type;
    packet.index = index;
    packet.type_value = type_value;
    packet.D8 = D8;
    packet.D9 = D9;
    packet.total_num = total_num;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_TOF_CSV_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_CRC);
}

/**
 * @brief Encode a wk_tof_csv_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_tof_csv_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_tof_csv_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_tof_csv_data_t* wk_tof_csv_data)
{
    return mavlink_msg_wk_tof_csv_data_pack(system_id, component_id, msg, wk_tof_csv_data->type, wk_tof_csv_data->index, wk_tof_csv_data->type_value, wk_tof_csv_data->D8, wk_tof_csv_data->D9, wk_tof_csv_data->total_num, wk_tof_csv_data->magnitude);
}

/**
 * @brief Encode a wk_tof_csv_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_tof_csv_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_tof_csv_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_tof_csv_data_t* wk_tof_csv_data)
{
    return mavlink_msg_wk_tof_csv_data_pack_chan(system_id, component_id, chan, msg, wk_tof_csv_data->type, wk_tof_csv_data->index, wk_tof_csv_data->type_value, wk_tof_csv_data->D8, wk_tof_csv_data->D9, wk_tof_csv_data->total_num, wk_tof_csv_data->magnitude);
}

/**
 * @brief Send a wk_tof_csv_data message
 * @param chan MAVLink channel to send the message
 *
 * @param type  see enum WK_TOF_CALI_CSV_TYPE
 * @param index  
 * @param type_value  
 * @param D8  
 * @param D9  
 * @param total_num  
 * @param magnitude  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_tof_csv_data_send(mavlink_channel_t chan, uint8_t type, uint8_t index, uint8_t type_value, uint8_t D8, uint8_t D9, uint8_t total_num, float magnitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN];
    _mav_put_float(buf, 0, magnitude);
    _mav_put_uint8_t(buf, 4, type);
    _mav_put_uint8_t(buf, 5, index);
    _mav_put_uint8_t(buf, 6, type_value);
    _mav_put_uint8_t(buf, 7, D8);
    _mav_put_uint8_t(buf, 8, D9);
    _mav_put_uint8_t(buf, 9, total_num);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CSV_DATA, buf, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_CRC);
#else
    mavlink_wk_tof_csv_data_t packet;
    packet.magnitude = magnitude;
    packet.type = type;
    packet.index = index;
    packet.type_value = type_value;
    packet.D8 = D8;
    packet.D9 = D9;
    packet.total_num = total_num;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CSV_DATA, (const char *)&packet, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_CRC);
#endif
}

/**
 * @brief Send a wk_tof_csv_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_tof_csv_data_send_struct(mavlink_channel_t chan, const mavlink_wk_tof_csv_data_t* wk_tof_csv_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_tof_csv_data_send(chan, wk_tof_csv_data->type, wk_tof_csv_data->index, wk_tof_csv_data->type_value, wk_tof_csv_data->D8, wk_tof_csv_data->D9, wk_tof_csv_data->total_num, wk_tof_csv_data->magnitude);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CSV_DATA, (const char *)wk_tof_csv_data, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_tof_csv_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t type, uint8_t index, uint8_t type_value, uint8_t D8, uint8_t D9, uint8_t total_num, float magnitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, magnitude);
    _mav_put_uint8_t(buf, 4, type);
    _mav_put_uint8_t(buf, 5, index);
    _mav_put_uint8_t(buf, 6, type_value);
    _mav_put_uint8_t(buf, 7, D8);
    _mav_put_uint8_t(buf, 8, D9);
    _mav_put_uint8_t(buf, 9, total_num);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CSV_DATA, buf, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_CRC);
#else
    mavlink_wk_tof_csv_data_t *packet = (mavlink_wk_tof_csv_data_t *)msgbuf;
    packet->magnitude = magnitude;
    packet->type = type;
    packet->index = index;
    packet->type_value = type_value;
    packet->D8 = D8;
    packet->D9 = D9;
    packet->total_num = total_num;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CSV_DATA, (const char *)packet, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_TOF_CSV_DATA UNPACKING


/**
 * @brief Get field type from wk_tof_csv_data message
 *
 * @return  see enum WK_TOF_CALI_CSV_TYPE
 */
static inline uint8_t mavlink_msg_wk_tof_csv_data_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field index from wk_tof_csv_data message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_csv_data_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field type_value from wk_tof_csv_data message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_csv_data_get_type_value(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field D8 from wk_tof_csv_data message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_csv_data_get_D8(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field D9 from wk_tof_csv_data message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_csv_data_get_D9(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field total_num from wk_tof_csv_data message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_csv_data_get_total_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field magnitude from wk_tof_csv_data message
 *
 * @return  
 */
static inline float mavlink_msg_wk_tof_csv_data_get_magnitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a wk_tof_csv_data message into a struct
 *
 * @param msg The message to decode
 * @param wk_tof_csv_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_tof_csv_data_decode(const mavlink_message_t* msg, mavlink_wk_tof_csv_data_t* wk_tof_csv_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_tof_csv_data->magnitude = mavlink_msg_wk_tof_csv_data_get_magnitude(msg);
    wk_tof_csv_data->type = mavlink_msg_wk_tof_csv_data_get_type(msg);
    wk_tof_csv_data->index = mavlink_msg_wk_tof_csv_data_get_index(msg);
    wk_tof_csv_data->type_value = mavlink_msg_wk_tof_csv_data_get_type_value(msg);
    wk_tof_csv_data->D8 = mavlink_msg_wk_tof_csv_data_get_D8(msg);
    wk_tof_csv_data->D9 = mavlink_msg_wk_tof_csv_data_get_D9(msg);
    wk_tof_csv_data->total_num = mavlink_msg_wk_tof_csv_data_get_total_num(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN? msg->len : MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN;
        memset(wk_tof_csv_data, 0, MAVLINK_MSG_ID_WK_TOF_CSV_DATA_LEN);
    memcpy(wk_tof_csv_data, _MAV_PAYLOAD(msg), len);
#endif
}
