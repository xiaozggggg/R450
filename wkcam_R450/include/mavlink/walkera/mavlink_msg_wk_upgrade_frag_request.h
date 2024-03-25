#pragma once
// MESSAGE WK_UPGRADE_FRAG_REQUEST PACKING

#define MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST 8013


typedef struct __mavlink_wk_upgrade_frag_request_t {
 uint32_t dev_id; /*<  device id*/
 uint32_t seq; /*<  fragment sequence*/
 uint16_t dev_type; /*<  device type*/
} mavlink_wk_upgrade_frag_request_t;

#define MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN 10
#define MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_MIN_LEN 10
#define MAVLINK_MSG_ID_8013_LEN 10
#define MAVLINK_MSG_ID_8013_MIN_LEN 10

#define MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_CRC 212
#define MAVLINK_MSG_ID_8013_CRC 212



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_UPGRADE_FRAG_REQUEST { \
    8013, \
    "WK_UPGRADE_FRAG_REQUEST", \
    3, \
    {  { "dev_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_wk_upgrade_frag_request_t, dev_type) }, \
         { "dev_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_upgrade_frag_request_t, dev_id) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_upgrade_frag_request_t, seq) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_UPGRADE_FRAG_REQUEST { \
    "WK_UPGRADE_FRAG_REQUEST", \
    3, \
    {  { "dev_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_wk_upgrade_frag_request_t, dev_type) }, \
         { "dev_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_upgrade_frag_request_t, dev_id) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_upgrade_frag_request_t, seq) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_upgrade_frag_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param dev_type  device type
 * @param dev_id  device id
 * @param seq  fragment sequence
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_upgrade_frag_request_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t dev_type, uint32_t dev_id, uint32_t seq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN];
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint32_t(buf, 4, seq);
    _mav_put_uint16_t(buf, 8, dev_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN);
#else
    mavlink_wk_upgrade_frag_request_t packet;
    packet.dev_id = dev_id;
    packet.seq = seq;
    packet.dev_type = dev_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_CRC);
}

/**
 * @brief Pack a wk_upgrade_frag_request message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dev_type  device type
 * @param dev_id  device id
 * @param seq  fragment sequence
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_upgrade_frag_request_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t dev_type,uint32_t dev_id,uint32_t seq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN];
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint32_t(buf, 4, seq);
    _mav_put_uint16_t(buf, 8, dev_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN);
#else
    mavlink_wk_upgrade_frag_request_t packet;
    packet.dev_id = dev_id;
    packet.seq = seq;
    packet.dev_type = dev_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_CRC);
}

/**
 * @brief Encode a wk_upgrade_frag_request struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_upgrade_frag_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_upgrade_frag_request_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_upgrade_frag_request_t* wk_upgrade_frag_request)
{
    return mavlink_msg_wk_upgrade_frag_request_pack(system_id, component_id, msg, wk_upgrade_frag_request->dev_type, wk_upgrade_frag_request->dev_id, wk_upgrade_frag_request->seq);
}

/**
 * @brief Encode a wk_upgrade_frag_request struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_upgrade_frag_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_upgrade_frag_request_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_upgrade_frag_request_t* wk_upgrade_frag_request)
{
    return mavlink_msg_wk_upgrade_frag_request_pack_chan(system_id, component_id, chan, msg, wk_upgrade_frag_request->dev_type, wk_upgrade_frag_request->dev_id, wk_upgrade_frag_request->seq);
}

/**
 * @brief Send a wk_upgrade_frag_request message
 * @param chan MAVLink channel to send the message
 *
 * @param dev_type  device type
 * @param dev_id  device id
 * @param seq  fragment sequence
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_upgrade_frag_request_send(mavlink_channel_t chan, uint16_t dev_type, uint32_t dev_id, uint32_t seq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN];
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint32_t(buf, 4, seq);
    _mav_put_uint16_t(buf, 8, dev_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST, buf, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_CRC);
#else
    mavlink_wk_upgrade_frag_request_t packet;
    packet.dev_id = dev_id;
    packet.seq = seq;
    packet.dev_type = dev_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST, (const char *)&packet, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_CRC);
#endif
}

/**
 * @brief Send a wk_upgrade_frag_request message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_upgrade_frag_request_send_struct(mavlink_channel_t chan, const mavlink_wk_upgrade_frag_request_t* wk_upgrade_frag_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_upgrade_frag_request_send(chan, wk_upgrade_frag_request->dev_type, wk_upgrade_frag_request->dev_id, wk_upgrade_frag_request->seq);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST, (const char *)wk_upgrade_frag_request, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_upgrade_frag_request_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t dev_type, uint32_t dev_id, uint32_t seq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint32_t(buf, 4, seq);
    _mav_put_uint16_t(buf, 8, dev_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST, buf, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_CRC);
#else
    mavlink_wk_upgrade_frag_request_t *packet = (mavlink_wk_upgrade_frag_request_t *)msgbuf;
    packet->dev_id = dev_id;
    packet->seq = seq;
    packet->dev_type = dev_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST, (const char *)packet, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_UPGRADE_FRAG_REQUEST UNPACKING


/**
 * @brief Get field dev_type from wk_upgrade_frag_request message
 *
 * @return  device type
 */
static inline uint16_t mavlink_msg_wk_upgrade_frag_request_get_dev_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field dev_id from wk_upgrade_frag_request message
 *
 * @return  device id
 */
static inline uint32_t mavlink_msg_wk_upgrade_frag_request_get_dev_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field seq from wk_upgrade_frag_request message
 *
 * @return  fragment sequence
 */
static inline uint32_t mavlink_msg_wk_upgrade_frag_request_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Decode a wk_upgrade_frag_request message into a struct
 *
 * @param msg The message to decode
 * @param wk_upgrade_frag_request C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_upgrade_frag_request_decode(const mavlink_message_t* msg, mavlink_wk_upgrade_frag_request_t* wk_upgrade_frag_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_upgrade_frag_request->dev_id = mavlink_msg_wk_upgrade_frag_request_get_dev_id(msg);
    wk_upgrade_frag_request->seq = mavlink_msg_wk_upgrade_frag_request_get_seq(msg);
    wk_upgrade_frag_request->dev_type = mavlink_msg_wk_upgrade_frag_request_get_dev_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN? msg->len : MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN;
        memset(wk_upgrade_frag_request, 0, MAVLINK_MSG_ID_WK_UPGRADE_FRAG_REQUEST_LEN);
    memcpy(wk_upgrade_frag_request, _MAV_PAYLOAD(msg), len);
#endif
}
