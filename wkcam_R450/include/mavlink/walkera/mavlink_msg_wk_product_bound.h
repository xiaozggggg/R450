#pragma once
// MESSAGE WK_PRODUCT_BOUND PACKING

#define MAVLINK_MSG_ID_WK_PRODUCT_BOUND 8078


typedef struct __mavlink_wk_product_bound_t {
 uint8_t user_name[32]; /*<  user name*/
 uint8_t bound; /*<  bound*/
} mavlink_wk_product_bound_t;

#define MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN 33
#define MAVLINK_MSG_ID_WK_PRODUCT_BOUND_MIN_LEN 33
#define MAVLINK_MSG_ID_8078_LEN 33
#define MAVLINK_MSG_ID_8078_MIN_LEN 33

#define MAVLINK_MSG_ID_WK_PRODUCT_BOUND_CRC 151
#define MAVLINK_MSG_ID_8078_CRC 151

#define MAVLINK_MSG_WK_PRODUCT_BOUND_FIELD_USER_NAME_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_PRODUCT_BOUND { \
    8078, \
    "WK_PRODUCT_BOUND", \
    2, \
    {  { "user_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 0, offsetof(mavlink_wk_product_bound_t, user_name) }, \
         { "bound", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_wk_product_bound_t, bound) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_PRODUCT_BOUND { \
    "WK_PRODUCT_BOUND", \
    2, \
    {  { "user_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 0, offsetof(mavlink_wk_product_bound_t, user_name) }, \
         { "bound", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_wk_product_bound_t, bound) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_product_bound message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param user_name  user name
 * @param bound  bound
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_product_bound_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint8_t *user_name, uint8_t bound)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN];
    _mav_put_uint8_t(buf, 32, bound);
    _mav_put_uint8_t_array(buf, 0, user_name, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN);
#else
    mavlink_wk_product_bound_t packet;
    packet.bound = bound;
    mav_array_memcpy(packet.user_name, user_name, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_PRODUCT_BOUND;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_CRC);
}

/**
 * @brief Pack a wk_product_bound message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param user_name  user name
 * @param bound  bound
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_product_bound_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint8_t *user_name,uint8_t bound)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN];
    _mav_put_uint8_t(buf, 32, bound);
    _mav_put_uint8_t_array(buf, 0, user_name, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN);
#else
    mavlink_wk_product_bound_t packet;
    packet.bound = bound;
    mav_array_memcpy(packet.user_name, user_name, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_PRODUCT_BOUND;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_CRC);
}

/**
 * @brief Encode a wk_product_bound struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_product_bound C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_product_bound_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_product_bound_t* wk_product_bound)
{
    return mavlink_msg_wk_product_bound_pack(system_id, component_id, msg, wk_product_bound->user_name, wk_product_bound->bound);
}

/**
 * @brief Encode a wk_product_bound struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_product_bound C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_product_bound_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_product_bound_t* wk_product_bound)
{
    return mavlink_msg_wk_product_bound_pack_chan(system_id, component_id, chan, msg, wk_product_bound->user_name, wk_product_bound->bound);
}

/**
 * @brief Send a wk_product_bound message
 * @param chan MAVLink channel to send the message
 *
 * @param user_name  user name
 * @param bound  bound
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_product_bound_send(mavlink_channel_t chan, const uint8_t *user_name, uint8_t bound)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN];
    _mav_put_uint8_t(buf, 32, bound);
    _mav_put_uint8_t_array(buf, 0, user_name, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_BOUND, buf, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_CRC);
#else
    mavlink_wk_product_bound_t packet;
    packet.bound = bound;
    mav_array_memcpy(packet.user_name, user_name, sizeof(uint8_t)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_BOUND, (const char *)&packet, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_CRC);
#endif
}

/**
 * @brief Send a wk_product_bound message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_product_bound_send_struct(mavlink_channel_t chan, const mavlink_wk_product_bound_t* wk_product_bound)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_product_bound_send(chan, wk_product_bound->user_name, wk_product_bound->bound);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_BOUND, (const char *)wk_product_bound, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_product_bound_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint8_t *user_name, uint8_t bound)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 32, bound);
    _mav_put_uint8_t_array(buf, 0, user_name, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_BOUND, buf, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_CRC);
#else
    mavlink_wk_product_bound_t *packet = (mavlink_wk_product_bound_t *)msgbuf;
    packet->bound = bound;
    mav_array_memcpy(packet->user_name, user_name, sizeof(uint8_t)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_BOUND, (const char *)packet, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_PRODUCT_BOUND UNPACKING


/**
 * @brief Get field user_name from wk_product_bound message
 *
 * @return  user name
 */
static inline uint16_t mavlink_msg_wk_product_bound_get_user_name(const mavlink_message_t* msg, uint8_t *user_name)
{
    return _MAV_RETURN_uint8_t_array(msg, user_name, 32,  0);
}

/**
 * @brief Get field bound from wk_product_bound message
 *
 * @return  bound
 */
static inline uint8_t mavlink_msg_wk_product_bound_get_bound(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Decode a wk_product_bound message into a struct
 *
 * @param msg The message to decode
 * @param wk_product_bound C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_product_bound_decode(const mavlink_message_t* msg, mavlink_wk_product_bound_t* wk_product_bound)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_product_bound_get_user_name(msg, wk_product_bound->user_name);
    wk_product_bound->bound = mavlink_msg_wk_product_bound_get_bound(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN? msg->len : MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN;
        memset(wk_product_bound, 0, MAVLINK_MSG_ID_WK_PRODUCT_BOUND_LEN);
    memcpy(wk_product_bound, _MAV_PAYLOAD(msg), len);
#endif
}
