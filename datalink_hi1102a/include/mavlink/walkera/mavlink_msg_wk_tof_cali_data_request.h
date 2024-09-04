#pragma once
// MESSAGE WK_TOF_CALI_DATA_REQUEST PACKING

#define MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST 8523


typedef struct __mavlink_wk_tof_cali_data_request_t {
 uint8_t num; /*<  */
} mavlink_wk_tof_cali_data_request_t;

#define MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN 1
#define MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_MIN_LEN 1
#define MAVLINK_MSG_ID_8523_LEN 1
#define MAVLINK_MSG_ID_8523_MIN_LEN 1

#define MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_CRC 68
#define MAVLINK_MSG_ID_8523_CRC 68



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_TOF_CALI_DATA_REQUEST { \
    8523, \
    "WK_TOF_CALI_DATA_REQUEST", \
    1, \
    {  { "num", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_tof_cali_data_request_t, num) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_TOF_CALI_DATA_REQUEST { \
    "WK_TOF_CALI_DATA_REQUEST", \
    1, \
    {  { "num", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_tof_cali_data_request_t, num) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_tof_cali_data_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param num  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_tof_cali_data_request_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN];
    _mav_put_uint8_t(buf, 0, num);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN);
#else
    mavlink_wk_tof_cali_data_request_t packet;
    packet.num = num;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_CRC);
}

/**
 * @brief Pack a wk_tof_cali_data_request message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param num  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_tof_cali_data_request_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN];
    _mav_put_uint8_t(buf, 0, num);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN);
#else
    mavlink_wk_tof_cali_data_request_t packet;
    packet.num = num;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_CRC);
}

/**
 * @brief Encode a wk_tof_cali_data_request struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_tof_cali_data_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_tof_cali_data_request_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_tof_cali_data_request_t* wk_tof_cali_data_request)
{
    return mavlink_msg_wk_tof_cali_data_request_pack(system_id, component_id, msg, wk_tof_cali_data_request->num);
}

/**
 * @brief Encode a wk_tof_cali_data_request struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_tof_cali_data_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_tof_cali_data_request_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_tof_cali_data_request_t* wk_tof_cali_data_request)
{
    return mavlink_msg_wk_tof_cali_data_request_pack_chan(system_id, component_id, chan, msg, wk_tof_cali_data_request->num);
}

/**
 * @brief Send a wk_tof_cali_data_request message
 * @param chan MAVLink channel to send the message
 *
 * @param num  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_tof_cali_data_request_send(mavlink_channel_t chan, uint8_t num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN];
    _mav_put_uint8_t(buf, 0, num);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST, buf, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_CRC);
#else
    mavlink_wk_tof_cali_data_request_t packet;
    packet.num = num;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST, (const char *)&packet, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_CRC);
#endif
}

/**
 * @brief Send a wk_tof_cali_data_request message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_tof_cali_data_request_send_struct(mavlink_channel_t chan, const mavlink_wk_tof_cali_data_request_t* wk_tof_cali_data_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_tof_cali_data_request_send(chan, wk_tof_cali_data_request->num);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST, (const char *)wk_tof_cali_data_request, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_tof_cali_data_request_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t num)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, num);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST, buf, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_CRC);
#else
    mavlink_wk_tof_cali_data_request_t *packet = (mavlink_wk_tof_cali_data_request_t *)msgbuf;
    packet->num = num;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST, (const char *)packet, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_TOF_CALI_DATA_REQUEST UNPACKING


/**
 * @brief Get field num from wk_tof_cali_data_request message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_cali_data_request_get_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a wk_tof_cali_data_request message into a struct
 *
 * @param msg The message to decode
 * @param wk_tof_cali_data_request C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_tof_cali_data_request_decode(const mavlink_message_t* msg, mavlink_wk_tof_cali_data_request_t* wk_tof_cali_data_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_tof_cali_data_request->num = mavlink_msg_wk_tof_cali_data_request_get_num(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN? msg->len : MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN;
        memset(wk_tof_cali_data_request, 0, MAVLINK_MSG_ID_WK_TOF_CALI_DATA_REQUEST_LEN);
    memcpy(wk_tof_cali_data_request, _MAV_PAYLOAD(msg), len);
#endif
}
