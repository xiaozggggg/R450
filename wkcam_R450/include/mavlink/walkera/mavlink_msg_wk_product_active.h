#pragma once
// MESSAGE WK_PRODUCT_ACTIVE PACKING

#define MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE 8062


typedef struct __mavlink_wk_product_active_t {
 uint32_t active_timestamps; /*<  active_timestamps*/
 uint8_t user_name[32]; /*<  user name*/
 uint8_t product_id[16]; /*<  product id*/
} mavlink_wk_product_active_t;

#define MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN 52
#define MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_MIN_LEN 52
#define MAVLINK_MSG_ID_8062_LEN 52
#define MAVLINK_MSG_ID_8062_MIN_LEN 52

#define MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_CRC 156
#define MAVLINK_MSG_ID_8062_CRC 156

#define MAVLINK_MSG_WK_PRODUCT_ACTIVE_FIELD_USER_NAME_LEN 32
#define MAVLINK_MSG_WK_PRODUCT_ACTIVE_FIELD_PRODUCT_ID_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_PRODUCT_ACTIVE { \
    8062, \
    "WK_PRODUCT_ACTIVE", \
    3, \
    {  { "active_timestamps", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_product_active_t, active_timestamps) }, \
         { "user_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 4, offsetof(mavlink_wk_product_active_t, user_name) }, \
         { "product_id", NULL, MAVLINK_TYPE_UINT8_T, 16, 36, offsetof(mavlink_wk_product_active_t, product_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_PRODUCT_ACTIVE { \
    "WK_PRODUCT_ACTIVE", \
    3, \
    {  { "active_timestamps", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_product_active_t, active_timestamps) }, \
         { "user_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 4, offsetof(mavlink_wk_product_active_t, user_name) }, \
         { "product_id", NULL, MAVLINK_TYPE_UINT8_T, 16, 36, offsetof(mavlink_wk_product_active_t, product_id) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_product_active message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param active_timestamps  active_timestamps
 * @param user_name  user name
 * @param product_id  product id
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_product_active_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t active_timestamps, const uint8_t *user_name, const uint8_t *product_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN];
    _mav_put_uint32_t(buf, 0, active_timestamps);
    _mav_put_uint8_t_array(buf, 4, user_name, 32);
    _mav_put_uint8_t_array(buf, 36, product_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN);
#else
    mavlink_wk_product_active_t packet;
    packet.active_timestamps = active_timestamps;
    mav_array_memcpy(packet.user_name, user_name, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.product_id, product_id, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_CRC);
}

/**
 * @brief Pack a wk_product_active message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param active_timestamps  active_timestamps
 * @param user_name  user name
 * @param product_id  product id
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_product_active_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t active_timestamps,const uint8_t *user_name,const uint8_t *product_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN];
    _mav_put_uint32_t(buf, 0, active_timestamps);
    _mav_put_uint8_t_array(buf, 4, user_name, 32);
    _mav_put_uint8_t_array(buf, 36, product_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN);
#else
    mavlink_wk_product_active_t packet;
    packet.active_timestamps = active_timestamps;
    mav_array_memcpy(packet.user_name, user_name, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.product_id, product_id, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_CRC);
}

/**
 * @brief Encode a wk_product_active struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_product_active C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_product_active_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_product_active_t* wk_product_active)
{
    return mavlink_msg_wk_product_active_pack(system_id, component_id, msg, wk_product_active->active_timestamps, wk_product_active->user_name, wk_product_active->product_id);
}

/**
 * @brief Encode a wk_product_active struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_product_active C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_product_active_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_product_active_t* wk_product_active)
{
    return mavlink_msg_wk_product_active_pack_chan(system_id, component_id, chan, msg, wk_product_active->active_timestamps, wk_product_active->user_name, wk_product_active->product_id);
}

/**
 * @brief Send a wk_product_active message
 * @param chan MAVLink channel to send the message
 *
 * @param active_timestamps  active_timestamps
 * @param user_name  user name
 * @param product_id  product id
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_product_active_send(mavlink_channel_t chan, uint32_t active_timestamps, const uint8_t *user_name, const uint8_t *product_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN];
    _mav_put_uint32_t(buf, 0, active_timestamps);
    _mav_put_uint8_t_array(buf, 4, user_name, 32);
    _mav_put_uint8_t_array(buf, 36, product_id, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE, buf, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_CRC);
#else
    mavlink_wk_product_active_t packet;
    packet.active_timestamps = active_timestamps;
    mav_array_memcpy(packet.user_name, user_name, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.product_id, product_id, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE, (const char *)&packet, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_CRC);
#endif
}

/**
 * @brief Send a wk_product_active message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_product_active_send_struct(mavlink_channel_t chan, const mavlink_wk_product_active_t* wk_product_active)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_product_active_send(chan, wk_product_active->active_timestamps, wk_product_active->user_name, wk_product_active->product_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE, (const char *)wk_product_active, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_product_active_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t active_timestamps, const uint8_t *user_name, const uint8_t *product_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, active_timestamps);
    _mav_put_uint8_t_array(buf, 4, user_name, 32);
    _mav_put_uint8_t_array(buf, 36, product_id, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE, buf, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_CRC);
#else
    mavlink_wk_product_active_t *packet = (mavlink_wk_product_active_t *)msgbuf;
    packet->active_timestamps = active_timestamps;
    mav_array_memcpy(packet->user_name, user_name, sizeof(uint8_t)*32);
    mav_array_memcpy(packet->product_id, product_id, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE, (const char *)packet, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_PRODUCT_ACTIVE UNPACKING


/**
 * @brief Get field active_timestamps from wk_product_active message
 *
 * @return  active_timestamps
 */
static inline uint32_t mavlink_msg_wk_product_active_get_active_timestamps(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field user_name from wk_product_active message
 *
 * @return  user name
 */
static inline uint16_t mavlink_msg_wk_product_active_get_user_name(const mavlink_message_t* msg, uint8_t *user_name)
{
    return _MAV_RETURN_uint8_t_array(msg, user_name, 32,  4);
}

/**
 * @brief Get field product_id from wk_product_active message
 *
 * @return  product id
 */
static inline uint16_t mavlink_msg_wk_product_active_get_product_id(const mavlink_message_t* msg, uint8_t *product_id)
{
    return _MAV_RETURN_uint8_t_array(msg, product_id, 16,  36);
}

/**
 * @brief Decode a wk_product_active message into a struct
 *
 * @param msg The message to decode
 * @param wk_product_active C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_product_active_decode(const mavlink_message_t* msg, mavlink_wk_product_active_t* wk_product_active)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_product_active->active_timestamps = mavlink_msg_wk_product_active_get_active_timestamps(msg);
    mavlink_msg_wk_product_active_get_user_name(msg, wk_product_active->user_name);
    mavlink_msg_wk_product_active_get_product_id(msg, wk_product_active->product_id);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN? msg->len : MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN;
        memset(wk_product_active, 0, MAVLINK_MSG_ID_WK_PRODUCT_ACTIVE_LEN);
    memcpy(wk_product_active, _MAV_PAYLOAD(msg), len);
#endif
}
