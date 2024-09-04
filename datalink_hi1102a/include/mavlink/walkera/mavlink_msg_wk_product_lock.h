#pragma once
// MESSAGE WK_PRODUCT_LOCK PACKING

#define MAVLINK_MSG_ID_WK_PRODUCT_LOCK 8079


typedef struct __mavlink_wk_product_lock_t {
 uint8_t user_name[32]; /*<  user name*/
 uint8_t locked; /*<  lock/unlock*/
} mavlink_wk_product_lock_t;

#define MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN 33
#define MAVLINK_MSG_ID_WK_PRODUCT_LOCK_MIN_LEN 33
#define MAVLINK_MSG_ID_8079_LEN 33
#define MAVLINK_MSG_ID_8079_MIN_LEN 33

#define MAVLINK_MSG_ID_WK_PRODUCT_LOCK_CRC 213
#define MAVLINK_MSG_ID_8079_CRC 213

#define MAVLINK_MSG_WK_PRODUCT_LOCK_FIELD_USER_NAME_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_PRODUCT_LOCK { \
    8079, \
    "WK_PRODUCT_LOCK", \
    2, \
    {  { "user_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 0, offsetof(mavlink_wk_product_lock_t, user_name) }, \
         { "locked", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_wk_product_lock_t, locked) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_PRODUCT_LOCK { \
    "WK_PRODUCT_LOCK", \
    2, \
    {  { "user_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 0, offsetof(mavlink_wk_product_lock_t, user_name) }, \
         { "locked", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_wk_product_lock_t, locked) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_product_lock message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param user_name  user name
 * @param locked  lock/unlock
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_product_lock_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint8_t *user_name, uint8_t locked)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN];
    _mav_put_uint8_t(buf, 32, locked);
    _mav_put_uint8_t_array(buf, 0, user_name, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN);
#else
    mavlink_wk_product_lock_t packet;
    packet.locked = locked;
    mav_array_memcpy(packet.user_name, user_name, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_PRODUCT_LOCK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_CRC);
}

/**
 * @brief Pack a wk_product_lock message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param user_name  user name
 * @param locked  lock/unlock
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_product_lock_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint8_t *user_name,uint8_t locked)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN];
    _mav_put_uint8_t(buf, 32, locked);
    _mav_put_uint8_t_array(buf, 0, user_name, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN);
#else
    mavlink_wk_product_lock_t packet;
    packet.locked = locked;
    mav_array_memcpy(packet.user_name, user_name, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_PRODUCT_LOCK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_CRC);
}

/**
 * @brief Encode a wk_product_lock struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_product_lock C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_product_lock_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_product_lock_t* wk_product_lock)
{
    return mavlink_msg_wk_product_lock_pack(system_id, component_id, msg, wk_product_lock->user_name, wk_product_lock->locked);
}

/**
 * @brief Encode a wk_product_lock struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_product_lock C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_product_lock_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_product_lock_t* wk_product_lock)
{
    return mavlink_msg_wk_product_lock_pack_chan(system_id, component_id, chan, msg, wk_product_lock->user_name, wk_product_lock->locked);
}

/**
 * @brief Send a wk_product_lock message
 * @param chan MAVLink channel to send the message
 *
 * @param user_name  user name
 * @param locked  lock/unlock
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_product_lock_send(mavlink_channel_t chan, const uint8_t *user_name, uint8_t locked)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN];
    _mav_put_uint8_t(buf, 32, locked);
    _mav_put_uint8_t_array(buf, 0, user_name, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_LOCK, buf, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_CRC);
#else
    mavlink_wk_product_lock_t packet;
    packet.locked = locked;
    mav_array_memcpy(packet.user_name, user_name, sizeof(uint8_t)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_LOCK, (const char *)&packet, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_CRC);
#endif
}

/**
 * @brief Send a wk_product_lock message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_product_lock_send_struct(mavlink_channel_t chan, const mavlink_wk_product_lock_t* wk_product_lock)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_product_lock_send(chan, wk_product_lock->user_name, wk_product_lock->locked);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_LOCK, (const char *)wk_product_lock, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_product_lock_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint8_t *user_name, uint8_t locked)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 32, locked);
    _mav_put_uint8_t_array(buf, 0, user_name, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_LOCK, buf, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_CRC);
#else
    mavlink_wk_product_lock_t *packet = (mavlink_wk_product_lock_t *)msgbuf;
    packet->locked = locked;
    mav_array_memcpy(packet->user_name, user_name, sizeof(uint8_t)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_LOCK, (const char *)packet, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_PRODUCT_LOCK UNPACKING


/**
 * @brief Get field user_name from wk_product_lock message
 *
 * @return  user name
 */
static inline uint16_t mavlink_msg_wk_product_lock_get_user_name(const mavlink_message_t* msg, uint8_t *user_name)
{
    return _MAV_RETURN_uint8_t_array(msg, user_name, 32,  0);
}

/**
 * @brief Get field locked from wk_product_lock message
 *
 * @return  lock/unlock
 */
static inline uint8_t mavlink_msg_wk_product_lock_get_locked(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Decode a wk_product_lock message into a struct
 *
 * @param msg The message to decode
 * @param wk_product_lock C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_product_lock_decode(const mavlink_message_t* msg, mavlink_wk_product_lock_t* wk_product_lock)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_product_lock_get_user_name(msg, wk_product_lock->user_name);
    wk_product_lock->locked = mavlink_msg_wk_product_lock_get_locked(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN? msg->len : MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN;
        memset(wk_product_lock, 0, MAVLINK_MSG_ID_WK_PRODUCT_LOCK_LEN);
    memcpy(wk_product_lock, _MAV_PAYLOAD(msg), len);
#endif
}
