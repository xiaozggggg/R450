#pragma once
// MESSAGE WK_PRODUCT_ID PACKING

#define MAVLINK_MSG_ID_WK_PRODUCT_ID 8061


typedef struct __mavlink_wk_product_id_t {
 uint8_t product_id[30]; /*<  product id*/
 uint8_t len; /*<  len*/
} mavlink_wk_product_id_t;

#define MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN 31
#define MAVLINK_MSG_ID_WK_PRODUCT_ID_MIN_LEN 31
#define MAVLINK_MSG_ID_8061_LEN 31
#define MAVLINK_MSG_ID_8061_MIN_LEN 31

#define MAVLINK_MSG_ID_WK_PRODUCT_ID_CRC 184
#define MAVLINK_MSG_ID_8061_CRC 184

#define MAVLINK_MSG_WK_PRODUCT_ID_FIELD_PRODUCT_ID_LEN 30

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_PRODUCT_ID { \
    8061, \
    "WK_PRODUCT_ID", \
    2, \
    {  { "product_id", NULL, MAVLINK_TYPE_UINT8_T, 30, 0, offsetof(mavlink_wk_product_id_t, product_id) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_wk_product_id_t, len) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_PRODUCT_ID { \
    "WK_PRODUCT_ID", \
    2, \
    {  { "product_id", NULL, MAVLINK_TYPE_UINT8_T, 30, 0, offsetof(mavlink_wk_product_id_t, product_id) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_wk_product_id_t, len) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_product_id message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param product_id  product id
 * @param len  len
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_product_id_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint8_t *product_id, uint8_t len)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN];
    _mav_put_uint8_t(buf, 30, len);
    _mav_put_uint8_t_array(buf, 0, product_id, 30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN);
#else
    mavlink_wk_product_id_t packet;
    packet.len = len;
    mav_array_memcpy(packet.product_id, product_id, sizeof(uint8_t)*30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_PRODUCT_ID;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_PRODUCT_ID_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ID_CRC);
}

/**
 * @brief Pack a wk_product_id message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param product_id  product id
 * @param len  len
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_product_id_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint8_t *product_id,uint8_t len)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN];
    _mav_put_uint8_t(buf, 30, len);
    _mav_put_uint8_t_array(buf, 0, product_id, 30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN);
#else
    mavlink_wk_product_id_t packet;
    packet.len = len;
    mav_array_memcpy(packet.product_id, product_id, sizeof(uint8_t)*30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_PRODUCT_ID;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_PRODUCT_ID_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ID_CRC);
}

/**
 * @brief Encode a wk_product_id struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_product_id C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_product_id_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_product_id_t* wk_product_id)
{
    return mavlink_msg_wk_product_id_pack(system_id, component_id, msg, wk_product_id->product_id, wk_product_id->len);
}

/**
 * @brief Encode a wk_product_id struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_product_id C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_product_id_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_product_id_t* wk_product_id)
{
    return mavlink_msg_wk_product_id_pack_chan(system_id, component_id, chan, msg, wk_product_id->product_id, wk_product_id->len);
}

/**
 * @brief Send a wk_product_id message
 * @param chan MAVLink channel to send the message
 *
 * @param product_id  product id
 * @param len  len
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_product_id_send(mavlink_channel_t chan, const uint8_t *product_id, uint8_t len)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN];
    _mav_put_uint8_t(buf, 30, len);
    _mav_put_uint8_t_array(buf, 0, product_id, 30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_ID, buf, MAVLINK_MSG_ID_WK_PRODUCT_ID_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ID_CRC);
#else
    mavlink_wk_product_id_t packet;
    packet.len = len;
    mav_array_memcpy(packet.product_id, product_id, sizeof(uint8_t)*30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_ID, (const char *)&packet, MAVLINK_MSG_ID_WK_PRODUCT_ID_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ID_CRC);
#endif
}

/**
 * @brief Send a wk_product_id message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_product_id_send_struct(mavlink_channel_t chan, const mavlink_wk_product_id_t* wk_product_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_product_id_send(chan, wk_product_id->product_id, wk_product_id->len);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_ID, (const char *)wk_product_id, MAVLINK_MSG_ID_WK_PRODUCT_ID_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ID_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_product_id_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint8_t *product_id, uint8_t len)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 30, len);
    _mav_put_uint8_t_array(buf, 0, product_id, 30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_ID, buf, MAVLINK_MSG_ID_WK_PRODUCT_ID_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ID_CRC);
#else
    mavlink_wk_product_id_t *packet = (mavlink_wk_product_id_t *)msgbuf;
    packet->len = len;
    mav_array_memcpy(packet->product_id, product_id, sizeof(uint8_t)*30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_ID, (const char *)packet, MAVLINK_MSG_ID_WK_PRODUCT_ID_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ID_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_PRODUCT_ID UNPACKING


/**
 * @brief Get field product_id from wk_product_id message
 *
 * @return  product id
 */
static inline uint16_t mavlink_msg_wk_product_id_get_product_id(const mavlink_message_t* msg, uint8_t *product_id)
{
    return _MAV_RETURN_uint8_t_array(msg, product_id, 30,  0);
}

/**
 * @brief Get field len from wk_product_id message
 *
 * @return  len
 */
static inline uint8_t mavlink_msg_wk_product_id_get_len(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  30);
}

/**
 * @brief Decode a wk_product_id message into a struct
 *
 * @param msg The message to decode
 * @param wk_product_id C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_product_id_decode(const mavlink_message_t* msg, mavlink_wk_product_id_t* wk_product_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_product_id_get_product_id(msg, wk_product_id->product_id);
    wk_product_id->len = mavlink_msg_wk_product_id_get_len(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN? msg->len : MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN;
        memset(wk_product_id, 0, MAVLINK_MSG_ID_WK_PRODUCT_ID_LEN);
    memcpy(wk_product_id, _MAV_PAYLOAD(msg), len);
#endif
}
