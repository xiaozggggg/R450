#pragma once
// MESSAGE WK_TEST PACKING

#define MAVLINK_MSG_ID_WK_TEST 8063


typedef struct __mavlink_wk_test_t {
 uint8_t test_flag; /*<  test flag for test engineer*/
 uint8_t user_name[32]; /*<  user name*/
} mavlink_wk_test_t;

#define MAVLINK_MSG_ID_WK_TEST_LEN 33
#define MAVLINK_MSG_ID_WK_TEST_MIN_LEN 33
#define MAVLINK_MSG_ID_8063_LEN 33
#define MAVLINK_MSG_ID_8063_MIN_LEN 33

#define MAVLINK_MSG_ID_WK_TEST_CRC 18
#define MAVLINK_MSG_ID_8063_CRC 18

#define MAVLINK_MSG_WK_TEST_FIELD_USER_NAME_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_TEST { \
    8063, \
    "WK_TEST", \
    2, \
    {  { "test_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_test_t, test_flag) }, \
         { "user_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 1, offsetof(mavlink_wk_test_t, user_name) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_TEST { \
    "WK_TEST", \
    2, \
    {  { "test_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_test_t, test_flag) }, \
         { "user_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 1, offsetof(mavlink_wk_test_t, user_name) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_test message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param test_flag  test flag for test engineer
 * @param user_name  user name
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_test_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t test_flag, const uint8_t *user_name)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TEST_LEN];
    _mav_put_uint8_t(buf, 0, test_flag);
    _mav_put_uint8_t_array(buf, 1, user_name, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_TEST_LEN);
#else
    mavlink_wk_test_t packet;
    packet.test_flag = test_flag;
    mav_array_memcpy(packet.user_name, user_name, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_TEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_TEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_TEST_MIN_LEN, MAVLINK_MSG_ID_WK_TEST_LEN, MAVLINK_MSG_ID_WK_TEST_CRC);
}

/**
 * @brief Pack a wk_test message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param test_flag  test flag for test engineer
 * @param user_name  user name
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_test_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t test_flag,const uint8_t *user_name)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TEST_LEN];
    _mav_put_uint8_t(buf, 0, test_flag);
    _mav_put_uint8_t_array(buf, 1, user_name, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_TEST_LEN);
#else
    mavlink_wk_test_t packet;
    packet.test_flag = test_flag;
    mav_array_memcpy(packet.user_name, user_name, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_TEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_TEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_TEST_MIN_LEN, MAVLINK_MSG_ID_WK_TEST_LEN, MAVLINK_MSG_ID_WK_TEST_CRC);
}

/**
 * @brief Encode a wk_test struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_test C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_test_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_test_t* wk_test)
{
    return mavlink_msg_wk_test_pack(system_id, component_id, msg, wk_test->test_flag, wk_test->user_name);
}

/**
 * @brief Encode a wk_test struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_test C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_test_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_test_t* wk_test)
{
    return mavlink_msg_wk_test_pack_chan(system_id, component_id, chan, msg, wk_test->test_flag, wk_test->user_name);
}

/**
 * @brief Send a wk_test message
 * @param chan MAVLink channel to send the message
 *
 * @param test_flag  test flag for test engineer
 * @param user_name  user name
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_test_send(mavlink_channel_t chan, uint8_t test_flag, const uint8_t *user_name)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TEST_LEN];
    _mav_put_uint8_t(buf, 0, test_flag);
    _mav_put_uint8_t_array(buf, 1, user_name, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TEST, buf, MAVLINK_MSG_ID_WK_TEST_MIN_LEN, MAVLINK_MSG_ID_WK_TEST_LEN, MAVLINK_MSG_ID_WK_TEST_CRC);
#else
    mavlink_wk_test_t packet;
    packet.test_flag = test_flag;
    mav_array_memcpy(packet.user_name, user_name, sizeof(uint8_t)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TEST, (const char *)&packet, MAVLINK_MSG_ID_WK_TEST_MIN_LEN, MAVLINK_MSG_ID_WK_TEST_LEN, MAVLINK_MSG_ID_WK_TEST_CRC);
#endif
}

/**
 * @brief Send a wk_test message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_test_send_struct(mavlink_channel_t chan, const mavlink_wk_test_t* wk_test)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_test_send(chan, wk_test->test_flag, wk_test->user_name);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TEST, (const char *)wk_test, MAVLINK_MSG_ID_WK_TEST_MIN_LEN, MAVLINK_MSG_ID_WK_TEST_LEN, MAVLINK_MSG_ID_WK_TEST_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_TEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_test_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t test_flag, const uint8_t *user_name)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, test_flag);
    _mav_put_uint8_t_array(buf, 1, user_name, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TEST, buf, MAVLINK_MSG_ID_WK_TEST_MIN_LEN, MAVLINK_MSG_ID_WK_TEST_LEN, MAVLINK_MSG_ID_WK_TEST_CRC);
#else
    mavlink_wk_test_t *packet = (mavlink_wk_test_t *)msgbuf;
    packet->test_flag = test_flag;
    mav_array_memcpy(packet->user_name, user_name, sizeof(uint8_t)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TEST, (const char *)packet, MAVLINK_MSG_ID_WK_TEST_MIN_LEN, MAVLINK_MSG_ID_WK_TEST_LEN, MAVLINK_MSG_ID_WK_TEST_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_TEST UNPACKING


/**
 * @brief Get field test_flag from wk_test message
 *
 * @return  test flag for test engineer
 */
static inline uint8_t mavlink_msg_wk_test_get_test_flag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field user_name from wk_test message
 *
 * @return  user name
 */
static inline uint16_t mavlink_msg_wk_test_get_user_name(const mavlink_message_t* msg, uint8_t *user_name)
{
    return _MAV_RETURN_uint8_t_array(msg, user_name, 32,  1);
}

/**
 * @brief Decode a wk_test message into a struct
 *
 * @param msg The message to decode
 * @param wk_test C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_test_decode(const mavlink_message_t* msg, mavlink_wk_test_t* wk_test)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_test->test_flag = mavlink_msg_wk_test_get_test_flag(msg);
    mavlink_msg_wk_test_get_user_name(msg, wk_test->user_name);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_TEST_LEN? msg->len : MAVLINK_MSG_ID_WK_TEST_LEN;
        memset(wk_test, 0, MAVLINK_MSG_ID_WK_TEST_LEN);
    memcpy(wk_test, _MAV_PAYLOAD(msg), len);
#endif
}
