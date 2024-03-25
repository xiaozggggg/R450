#pragma once
// MESSAGE WK_UPGRADE_REQUEST_ACK PACKING

#define MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK 8018


typedef struct __mavlink_wk_upgrade_request_ack_t {
 uint32_t dev_id; /*<  device id*/
 uint16_t dev_type; /*<  device type*/
} mavlink_wk_upgrade_request_ack_t;

#define MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN 6
#define MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_MIN_LEN 6
#define MAVLINK_MSG_ID_8018_LEN 6
#define MAVLINK_MSG_ID_8018_MIN_LEN 6

#define MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_CRC 52
#define MAVLINK_MSG_ID_8018_CRC 52



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_UPGRADE_REQUEST_ACK { \
    8018, \
    "WK_UPGRADE_REQUEST_ACK", \
    2, \
    {  { "dev_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_wk_upgrade_request_ack_t, dev_type) }, \
         { "dev_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_upgrade_request_ack_t, dev_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_UPGRADE_REQUEST_ACK { \
    "WK_UPGRADE_REQUEST_ACK", \
    2, \
    {  { "dev_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_wk_upgrade_request_ack_t, dev_type) }, \
         { "dev_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_upgrade_request_ack_t, dev_id) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_upgrade_request_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param dev_type  device type
 * @param dev_id  device id
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_upgrade_request_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t dev_type, uint32_t dev_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN];
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint16_t(buf, 4, dev_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN);
#else
    mavlink_wk_upgrade_request_ack_t packet;
    packet.dev_id = dev_id;
    packet.dev_type = dev_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_CRC);
}

/**
 * @brief Pack a wk_upgrade_request_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dev_type  device type
 * @param dev_id  device id
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_upgrade_request_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t dev_type,uint32_t dev_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN];
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint16_t(buf, 4, dev_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN);
#else
    mavlink_wk_upgrade_request_ack_t packet;
    packet.dev_id = dev_id;
    packet.dev_type = dev_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_CRC);
}

/**
 * @brief Encode a wk_upgrade_request_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_upgrade_request_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_upgrade_request_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_upgrade_request_ack_t* wk_upgrade_request_ack)
{
    return mavlink_msg_wk_upgrade_request_ack_pack(system_id, component_id, msg, wk_upgrade_request_ack->dev_type, wk_upgrade_request_ack->dev_id);
}

/**
 * @brief Encode a wk_upgrade_request_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_upgrade_request_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_upgrade_request_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_upgrade_request_ack_t* wk_upgrade_request_ack)
{
    return mavlink_msg_wk_upgrade_request_ack_pack_chan(system_id, component_id, chan, msg, wk_upgrade_request_ack->dev_type, wk_upgrade_request_ack->dev_id);
}

/**
 * @brief Send a wk_upgrade_request_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param dev_type  device type
 * @param dev_id  device id
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_upgrade_request_ack_send(mavlink_channel_t chan, uint16_t dev_type, uint32_t dev_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN];
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint16_t(buf, 4, dev_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK, buf, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_CRC);
#else
    mavlink_wk_upgrade_request_ack_t packet;
    packet.dev_id = dev_id;
    packet.dev_type = dev_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK, (const char *)&packet, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_CRC);
#endif
}

/**
 * @brief Send a wk_upgrade_request_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_upgrade_request_ack_send_struct(mavlink_channel_t chan, const mavlink_wk_upgrade_request_ack_t* wk_upgrade_request_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_upgrade_request_ack_send(chan, wk_upgrade_request_ack->dev_type, wk_upgrade_request_ack->dev_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK, (const char *)wk_upgrade_request_ack, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_upgrade_request_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t dev_type, uint32_t dev_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint16_t(buf, 4, dev_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK, buf, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_CRC);
#else
    mavlink_wk_upgrade_request_ack_t *packet = (mavlink_wk_upgrade_request_ack_t *)msgbuf;
    packet->dev_id = dev_id;
    packet->dev_type = dev_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK, (const char *)packet, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_UPGRADE_REQUEST_ACK UNPACKING


/**
 * @brief Get field dev_type from wk_upgrade_request_ack message
 *
 * @return  device type
 */
static inline uint16_t mavlink_msg_wk_upgrade_request_ack_get_dev_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field dev_id from wk_upgrade_request_ack message
 *
 * @return  device id
 */
static inline uint32_t mavlink_msg_wk_upgrade_request_ack_get_dev_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a wk_upgrade_request_ack message into a struct
 *
 * @param msg The message to decode
 * @param wk_upgrade_request_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_upgrade_request_ack_decode(const mavlink_message_t* msg, mavlink_wk_upgrade_request_ack_t* wk_upgrade_request_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_upgrade_request_ack->dev_id = mavlink_msg_wk_upgrade_request_ack_get_dev_id(msg);
    wk_upgrade_request_ack->dev_type = mavlink_msg_wk_upgrade_request_ack_get_dev_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN? msg->len : MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN;
        memset(wk_upgrade_request_ack, 0, MAVLINK_MSG_ID_WK_UPGRADE_REQUEST_ACK_LEN);
    memcpy(wk_upgrade_request_ack, _MAV_PAYLOAD(msg), len);
#endif
}
