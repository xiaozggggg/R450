#pragma once
// MESSAGE WK_UPGRADE_END_REPORT PACKING

#define MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT 8015


typedef struct __mavlink_wk_upgrade_end_report_t {
 uint32_t dev_id; /*<  device id*/
 uint16_t dev_type; /*<  device type*/
 uint8_t result; /*<  0:successfully,1:failure*/
} mavlink_wk_upgrade_end_report_t;

#define MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN 7
#define MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_MIN_LEN 7
#define MAVLINK_MSG_ID_8015_LEN 7
#define MAVLINK_MSG_ID_8015_MIN_LEN 7

#define MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_CRC 126
#define MAVLINK_MSG_ID_8015_CRC 126



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_UPGRADE_END_REPORT { \
    8015, \
    "WK_UPGRADE_END_REPORT", \
    3, \
    {  { "dev_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_wk_upgrade_end_report_t, dev_type) }, \
         { "dev_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_upgrade_end_report_t, dev_id) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_upgrade_end_report_t, result) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_UPGRADE_END_REPORT { \
    "WK_UPGRADE_END_REPORT", \
    3, \
    {  { "dev_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_wk_upgrade_end_report_t, dev_type) }, \
         { "dev_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_upgrade_end_report_t, dev_id) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_upgrade_end_report_t, result) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_upgrade_end_report message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param dev_type  device type
 * @param dev_id  device id
 * @param result  0:successfully,1:failure
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_upgrade_end_report_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t dev_type, uint32_t dev_id, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN];
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint16_t(buf, 4, dev_type);
    _mav_put_uint8_t(buf, 6, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN);
#else
    mavlink_wk_upgrade_end_report_t packet;
    packet.dev_id = dev_id;
    packet.dev_type = dev_type;
    packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_CRC);
}

/**
 * @brief Pack a wk_upgrade_end_report message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dev_type  device type
 * @param dev_id  device id
 * @param result  0:successfully,1:failure
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_upgrade_end_report_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t dev_type,uint32_t dev_id,uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN];
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint16_t(buf, 4, dev_type);
    _mav_put_uint8_t(buf, 6, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN);
#else
    mavlink_wk_upgrade_end_report_t packet;
    packet.dev_id = dev_id;
    packet.dev_type = dev_type;
    packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_CRC);
}

/**
 * @brief Encode a wk_upgrade_end_report struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_upgrade_end_report C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_upgrade_end_report_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_upgrade_end_report_t* wk_upgrade_end_report)
{
    return mavlink_msg_wk_upgrade_end_report_pack(system_id, component_id, msg, wk_upgrade_end_report->dev_type, wk_upgrade_end_report->dev_id, wk_upgrade_end_report->result);
}

/**
 * @brief Encode a wk_upgrade_end_report struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_upgrade_end_report C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_upgrade_end_report_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_upgrade_end_report_t* wk_upgrade_end_report)
{
    return mavlink_msg_wk_upgrade_end_report_pack_chan(system_id, component_id, chan, msg, wk_upgrade_end_report->dev_type, wk_upgrade_end_report->dev_id, wk_upgrade_end_report->result);
}

/**
 * @brief Send a wk_upgrade_end_report message
 * @param chan MAVLink channel to send the message
 *
 * @param dev_type  device type
 * @param dev_id  device id
 * @param result  0:successfully,1:failure
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_upgrade_end_report_send(mavlink_channel_t chan, uint16_t dev_type, uint32_t dev_id, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN];
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint16_t(buf, 4, dev_type);
    _mav_put_uint8_t(buf, 6, result);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT, buf, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_CRC);
#else
    mavlink_wk_upgrade_end_report_t packet;
    packet.dev_id = dev_id;
    packet.dev_type = dev_type;
    packet.result = result;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT, (const char *)&packet, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_CRC);
#endif
}

/**
 * @brief Send a wk_upgrade_end_report message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_upgrade_end_report_send_struct(mavlink_channel_t chan, const mavlink_wk_upgrade_end_report_t* wk_upgrade_end_report)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_upgrade_end_report_send(chan, wk_upgrade_end_report->dev_type, wk_upgrade_end_report->dev_id, wk_upgrade_end_report->result);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT, (const char *)wk_upgrade_end_report, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_upgrade_end_report_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t dev_type, uint32_t dev_id, uint8_t result)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint16_t(buf, 4, dev_type);
    _mav_put_uint8_t(buf, 6, result);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT, buf, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_CRC);
#else
    mavlink_wk_upgrade_end_report_t *packet = (mavlink_wk_upgrade_end_report_t *)msgbuf;
    packet->dev_id = dev_id;
    packet->dev_type = dev_type;
    packet->result = result;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT, (const char *)packet, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_UPGRADE_END_REPORT UNPACKING


/**
 * @brief Get field dev_type from wk_upgrade_end_report message
 *
 * @return  device type
 */
static inline uint16_t mavlink_msg_wk_upgrade_end_report_get_dev_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field dev_id from wk_upgrade_end_report message
 *
 * @return  device id
 */
static inline uint32_t mavlink_msg_wk_upgrade_end_report_get_dev_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field result from wk_upgrade_end_report message
 *
 * @return  0:successfully,1:failure
 */
static inline uint8_t mavlink_msg_wk_upgrade_end_report_get_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Decode a wk_upgrade_end_report message into a struct
 *
 * @param msg The message to decode
 * @param wk_upgrade_end_report C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_upgrade_end_report_decode(const mavlink_message_t* msg, mavlink_wk_upgrade_end_report_t* wk_upgrade_end_report)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_upgrade_end_report->dev_id = mavlink_msg_wk_upgrade_end_report_get_dev_id(msg);
    wk_upgrade_end_report->dev_type = mavlink_msg_wk_upgrade_end_report_get_dev_type(msg);
    wk_upgrade_end_report->result = mavlink_msg_wk_upgrade_end_report_get_result(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN? msg->len : MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN;
        memset(wk_upgrade_end_report, 0, MAVLINK_MSG_ID_WK_UPGRADE_END_REPORT_LEN);
    memcpy(wk_upgrade_end_report, _MAV_PAYLOAD(msg), len);
#endif
}
