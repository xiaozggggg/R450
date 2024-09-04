#pragma once
// MESSAGE WK_LOG_RCIN PACKING

#define MAVLINK_MSG_ID_WK_LOG_RCIN 8507


typedef struct __mavlink_wk_log_rcin_t {
 uint64_t timestamp; /*<  timestamp*/
 uint32_t update_ms; /*<  update_ms*/
 uint16_t ch01; /*<  ch01*/
 uint16_t ch02; /*<  ch02*/
 uint16_t ch03; /*<  ch03*/
 uint16_t ch04; /*<  ch04*/
 uint16_t ch05; /*<  ch05*/
 uint16_t ch06; /*<  ch06*/
 uint16_t ch07; /*<  ch07*/
 uint16_t ch08; /*<  ch08*/
 uint16_t ch09; /*<  ch09*/
 uint16_t ch10; /*<  ch10*/
 uint16_t ch11; /*<  ch11*/
 uint16_t ch12; /*<  ch12*/
 uint16_t ch13; /*<  ch13*/
 uint16_t ch14; /*<  ch14*/
 uint16_t ch15; /*<  ch15*/
 uint16_t ch16; /*<  ch16*/
} mavlink_wk_log_rcin_t;

#define MAVLINK_MSG_ID_WK_LOG_RCIN_LEN 44
#define MAVLINK_MSG_ID_WK_LOG_RCIN_MIN_LEN 44
#define MAVLINK_MSG_ID_8507_LEN 44
#define MAVLINK_MSG_ID_8507_MIN_LEN 44

#define MAVLINK_MSG_ID_WK_LOG_RCIN_CRC 35
#define MAVLINK_MSG_ID_8507_CRC 35



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_LOG_RCIN { \
    8507, \
    "WK_LOG_RCIN", \
    18, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_rcin_t, timestamp) }, \
         { "update_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_log_rcin_t, update_ms) }, \
         { "ch01", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_wk_log_rcin_t, ch01) }, \
         { "ch02", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_wk_log_rcin_t, ch02) }, \
         { "ch03", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_wk_log_rcin_t, ch03) }, \
         { "ch04", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_wk_log_rcin_t, ch04) }, \
         { "ch05", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_wk_log_rcin_t, ch05) }, \
         { "ch06", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_wk_log_rcin_t, ch06) }, \
         { "ch07", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_wk_log_rcin_t, ch07) }, \
         { "ch08", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_wk_log_rcin_t, ch08) }, \
         { "ch09", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_wk_log_rcin_t, ch09) }, \
         { "ch10", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_wk_log_rcin_t, ch10) }, \
         { "ch11", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_wk_log_rcin_t, ch11) }, \
         { "ch12", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_wk_log_rcin_t, ch12) }, \
         { "ch13", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_wk_log_rcin_t, ch13) }, \
         { "ch14", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_wk_log_rcin_t, ch14) }, \
         { "ch15", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_wk_log_rcin_t, ch15) }, \
         { "ch16", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_wk_log_rcin_t, ch16) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_LOG_RCIN { \
    "WK_LOG_RCIN", \
    18, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_rcin_t, timestamp) }, \
         { "update_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_log_rcin_t, update_ms) }, \
         { "ch01", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_wk_log_rcin_t, ch01) }, \
         { "ch02", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_wk_log_rcin_t, ch02) }, \
         { "ch03", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_wk_log_rcin_t, ch03) }, \
         { "ch04", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_wk_log_rcin_t, ch04) }, \
         { "ch05", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_wk_log_rcin_t, ch05) }, \
         { "ch06", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_wk_log_rcin_t, ch06) }, \
         { "ch07", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_wk_log_rcin_t, ch07) }, \
         { "ch08", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_wk_log_rcin_t, ch08) }, \
         { "ch09", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_wk_log_rcin_t, ch09) }, \
         { "ch10", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_wk_log_rcin_t, ch10) }, \
         { "ch11", NULL, MAVLINK_TYPE_UINT16_T, 0, 32, offsetof(mavlink_wk_log_rcin_t, ch11) }, \
         { "ch12", NULL, MAVLINK_TYPE_UINT16_T, 0, 34, offsetof(mavlink_wk_log_rcin_t, ch12) }, \
         { "ch13", NULL, MAVLINK_TYPE_UINT16_T, 0, 36, offsetof(mavlink_wk_log_rcin_t, ch13) }, \
         { "ch14", NULL, MAVLINK_TYPE_UINT16_T, 0, 38, offsetof(mavlink_wk_log_rcin_t, ch14) }, \
         { "ch15", NULL, MAVLINK_TYPE_UINT16_T, 0, 40, offsetof(mavlink_wk_log_rcin_t, ch15) }, \
         { "ch16", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_wk_log_rcin_t, ch16) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_log_rcin message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  timestamp
 * @param update_ms  update_ms
 * @param ch01  ch01
 * @param ch02  ch02
 * @param ch03  ch03
 * @param ch04  ch04
 * @param ch05  ch05
 * @param ch06  ch06
 * @param ch07  ch07
 * @param ch08  ch08
 * @param ch09  ch09
 * @param ch10  ch10
 * @param ch11  ch11
 * @param ch12  ch12
 * @param ch13  ch13
 * @param ch14  ch14
 * @param ch15  ch15
 * @param ch16  ch16
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_rcin_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint32_t update_ms, uint16_t ch01, uint16_t ch02, uint16_t ch03, uint16_t ch04, uint16_t ch05, uint16_t ch06, uint16_t ch07, uint16_t ch08, uint16_t ch09, uint16_t ch10, uint16_t ch11, uint16_t ch12, uint16_t ch13, uint16_t ch14, uint16_t ch15, uint16_t ch16)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_RCIN_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, update_ms);
    _mav_put_uint16_t(buf, 12, ch01);
    _mav_put_uint16_t(buf, 14, ch02);
    _mav_put_uint16_t(buf, 16, ch03);
    _mav_put_uint16_t(buf, 18, ch04);
    _mav_put_uint16_t(buf, 20, ch05);
    _mav_put_uint16_t(buf, 22, ch06);
    _mav_put_uint16_t(buf, 24, ch07);
    _mav_put_uint16_t(buf, 26, ch08);
    _mav_put_uint16_t(buf, 28, ch09);
    _mav_put_uint16_t(buf, 30, ch10);
    _mav_put_uint16_t(buf, 32, ch11);
    _mav_put_uint16_t(buf, 34, ch12);
    _mav_put_uint16_t(buf, 36, ch13);
    _mav_put_uint16_t(buf, 38, ch14);
    _mav_put_uint16_t(buf, 40, ch15);
    _mav_put_uint16_t(buf, 42, ch16);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_RCIN_LEN);
#else
    mavlink_wk_log_rcin_t packet;
    packet.timestamp = timestamp;
    packet.update_ms = update_ms;
    packet.ch01 = ch01;
    packet.ch02 = ch02;
    packet.ch03 = ch03;
    packet.ch04 = ch04;
    packet.ch05 = ch05;
    packet.ch06 = ch06;
    packet.ch07 = ch07;
    packet.ch08 = ch08;
    packet.ch09 = ch09;
    packet.ch10 = ch10;
    packet.ch11 = ch11;
    packet.ch12 = ch12;
    packet.ch13 = ch13;
    packet.ch14 = ch14;
    packet.ch15 = ch15;
    packet.ch16 = ch16;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_RCIN_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_RCIN;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_LOG_RCIN_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_RCIN_LEN, MAVLINK_MSG_ID_WK_LOG_RCIN_CRC);
}

/**
 * @brief Pack a wk_log_rcin message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  timestamp
 * @param update_ms  update_ms
 * @param ch01  ch01
 * @param ch02  ch02
 * @param ch03  ch03
 * @param ch04  ch04
 * @param ch05  ch05
 * @param ch06  ch06
 * @param ch07  ch07
 * @param ch08  ch08
 * @param ch09  ch09
 * @param ch10  ch10
 * @param ch11  ch11
 * @param ch12  ch12
 * @param ch13  ch13
 * @param ch14  ch14
 * @param ch15  ch15
 * @param ch16  ch16
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_rcin_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,uint32_t update_ms,uint16_t ch01,uint16_t ch02,uint16_t ch03,uint16_t ch04,uint16_t ch05,uint16_t ch06,uint16_t ch07,uint16_t ch08,uint16_t ch09,uint16_t ch10,uint16_t ch11,uint16_t ch12,uint16_t ch13,uint16_t ch14,uint16_t ch15,uint16_t ch16)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_RCIN_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, update_ms);
    _mav_put_uint16_t(buf, 12, ch01);
    _mav_put_uint16_t(buf, 14, ch02);
    _mav_put_uint16_t(buf, 16, ch03);
    _mav_put_uint16_t(buf, 18, ch04);
    _mav_put_uint16_t(buf, 20, ch05);
    _mav_put_uint16_t(buf, 22, ch06);
    _mav_put_uint16_t(buf, 24, ch07);
    _mav_put_uint16_t(buf, 26, ch08);
    _mav_put_uint16_t(buf, 28, ch09);
    _mav_put_uint16_t(buf, 30, ch10);
    _mav_put_uint16_t(buf, 32, ch11);
    _mav_put_uint16_t(buf, 34, ch12);
    _mav_put_uint16_t(buf, 36, ch13);
    _mav_put_uint16_t(buf, 38, ch14);
    _mav_put_uint16_t(buf, 40, ch15);
    _mav_put_uint16_t(buf, 42, ch16);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_RCIN_LEN);
#else
    mavlink_wk_log_rcin_t packet;
    packet.timestamp = timestamp;
    packet.update_ms = update_ms;
    packet.ch01 = ch01;
    packet.ch02 = ch02;
    packet.ch03 = ch03;
    packet.ch04 = ch04;
    packet.ch05 = ch05;
    packet.ch06 = ch06;
    packet.ch07 = ch07;
    packet.ch08 = ch08;
    packet.ch09 = ch09;
    packet.ch10 = ch10;
    packet.ch11 = ch11;
    packet.ch12 = ch12;
    packet.ch13 = ch13;
    packet.ch14 = ch14;
    packet.ch15 = ch15;
    packet.ch16 = ch16;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_RCIN_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_RCIN;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_LOG_RCIN_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_RCIN_LEN, MAVLINK_MSG_ID_WK_LOG_RCIN_CRC);
}

/**
 * @brief Encode a wk_log_rcin struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_rcin C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_rcin_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_log_rcin_t* wk_log_rcin)
{
    return mavlink_msg_wk_log_rcin_pack(system_id, component_id, msg, wk_log_rcin->timestamp, wk_log_rcin->update_ms, wk_log_rcin->ch01, wk_log_rcin->ch02, wk_log_rcin->ch03, wk_log_rcin->ch04, wk_log_rcin->ch05, wk_log_rcin->ch06, wk_log_rcin->ch07, wk_log_rcin->ch08, wk_log_rcin->ch09, wk_log_rcin->ch10, wk_log_rcin->ch11, wk_log_rcin->ch12, wk_log_rcin->ch13, wk_log_rcin->ch14, wk_log_rcin->ch15, wk_log_rcin->ch16);
}

/**
 * @brief Encode a wk_log_rcin struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_rcin C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_rcin_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_log_rcin_t* wk_log_rcin)
{
    return mavlink_msg_wk_log_rcin_pack_chan(system_id, component_id, chan, msg, wk_log_rcin->timestamp, wk_log_rcin->update_ms, wk_log_rcin->ch01, wk_log_rcin->ch02, wk_log_rcin->ch03, wk_log_rcin->ch04, wk_log_rcin->ch05, wk_log_rcin->ch06, wk_log_rcin->ch07, wk_log_rcin->ch08, wk_log_rcin->ch09, wk_log_rcin->ch10, wk_log_rcin->ch11, wk_log_rcin->ch12, wk_log_rcin->ch13, wk_log_rcin->ch14, wk_log_rcin->ch15, wk_log_rcin->ch16);
}

/**
 * @brief Send a wk_log_rcin message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 * @param update_ms  update_ms
 * @param ch01  ch01
 * @param ch02  ch02
 * @param ch03  ch03
 * @param ch04  ch04
 * @param ch05  ch05
 * @param ch06  ch06
 * @param ch07  ch07
 * @param ch08  ch08
 * @param ch09  ch09
 * @param ch10  ch10
 * @param ch11  ch11
 * @param ch12  ch12
 * @param ch13  ch13
 * @param ch14  ch14
 * @param ch15  ch15
 * @param ch16  ch16
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_log_rcin_send(mavlink_channel_t chan, uint64_t timestamp, uint32_t update_ms, uint16_t ch01, uint16_t ch02, uint16_t ch03, uint16_t ch04, uint16_t ch05, uint16_t ch06, uint16_t ch07, uint16_t ch08, uint16_t ch09, uint16_t ch10, uint16_t ch11, uint16_t ch12, uint16_t ch13, uint16_t ch14, uint16_t ch15, uint16_t ch16)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_RCIN_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, update_ms);
    _mav_put_uint16_t(buf, 12, ch01);
    _mav_put_uint16_t(buf, 14, ch02);
    _mav_put_uint16_t(buf, 16, ch03);
    _mav_put_uint16_t(buf, 18, ch04);
    _mav_put_uint16_t(buf, 20, ch05);
    _mav_put_uint16_t(buf, 22, ch06);
    _mav_put_uint16_t(buf, 24, ch07);
    _mav_put_uint16_t(buf, 26, ch08);
    _mav_put_uint16_t(buf, 28, ch09);
    _mav_put_uint16_t(buf, 30, ch10);
    _mav_put_uint16_t(buf, 32, ch11);
    _mav_put_uint16_t(buf, 34, ch12);
    _mav_put_uint16_t(buf, 36, ch13);
    _mav_put_uint16_t(buf, 38, ch14);
    _mav_put_uint16_t(buf, 40, ch15);
    _mav_put_uint16_t(buf, 42, ch16);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_RCIN, buf, MAVLINK_MSG_ID_WK_LOG_RCIN_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_RCIN_LEN, MAVLINK_MSG_ID_WK_LOG_RCIN_CRC);
#else
    mavlink_wk_log_rcin_t packet;
    packet.timestamp = timestamp;
    packet.update_ms = update_ms;
    packet.ch01 = ch01;
    packet.ch02 = ch02;
    packet.ch03 = ch03;
    packet.ch04 = ch04;
    packet.ch05 = ch05;
    packet.ch06 = ch06;
    packet.ch07 = ch07;
    packet.ch08 = ch08;
    packet.ch09 = ch09;
    packet.ch10 = ch10;
    packet.ch11 = ch11;
    packet.ch12 = ch12;
    packet.ch13 = ch13;
    packet.ch14 = ch14;
    packet.ch15 = ch15;
    packet.ch16 = ch16;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_RCIN, (const char *)&packet, MAVLINK_MSG_ID_WK_LOG_RCIN_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_RCIN_LEN, MAVLINK_MSG_ID_WK_LOG_RCIN_CRC);
#endif
}

/**
 * @brief Send a wk_log_rcin message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_log_rcin_send_struct(mavlink_channel_t chan, const mavlink_wk_log_rcin_t* wk_log_rcin)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_log_rcin_send(chan, wk_log_rcin->timestamp, wk_log_rcin->update_ms, wk_log_rcin->ch01, wk_log_rcin->ch02, wk_log_rcin->ch03, wk_log_rcin->ch04, wk_log_rcin->ch05, wk_log_rcin->ch06, wk_log_rcin->ch07, wk_log_rcin->ch08, wk_log_rcin->ch09, wk_log_rcin->ch10, wk_log_rcin->ch11, wk_log_rcin->ch12, wk_log_rcin->ch13, wk_log_rcin->ch14, wk_log_rcin->ch15, wk_log_rcin->ch16);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_RCIN, (const char *)wk_log_rcin, MAVLINK_MSG_ID_WK_LOG_RCIN_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_RCIN_LEN, MAVLINK_MSG_ID_WK_LOG_RCIN_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_LOG_RCIN_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_log_rcin_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, uint32_t update_ms, uint16_t ch01, uint16_t ch02, uint16_t ch03, uint16_t ch04, uint16_t ch05, uint16_t ch06, uint16_t ch07, uint16_t ch08, uint16_t ch09, uint16_t ch10, uint16_t ch11, uint16_t ch12, uint16_t ch13, uint16_t ch14, uint16_t ch15, uint16_t ch16)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, update_ms);
    _mav_put_uint16_t(buf, 12, ch01);
    _mav_put_uint16_t(buf, 14, ch02);
    _mav_put_uint16_t(buf, 16, ch03);
    _mav_put_uint16_t(buf, 18, ch04);
    _mav_put_uint16_t(buf, 20, ch05);
    _mav_put_uint16_t(buf, 22, ch06);
    _mav_put_uint16_t(buf, 24, ch07);
    _mav_put_uint16_t(buf, 26, ch08);
    _mav_put_uint16_t(buf, 28, ch09);
    _mav_put_uint16_t(buf, 30, ch10);
    _mav_put_uint16_t(buf, 32, ch11);
    _mav_put_uint16_t(buf, 34, ch12);
    _mav_put_uint16_t(buf, 36, ch13);
    _mav_put_uint16_t(buf, 38, ch14);
    _mav_put_uint16_t(buf, 40, ch15);
    _mav_put_uint16_t(buf, 42, ch16);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_RCIN, buf, MAVLINK_MSG_ID_WK_LOG_RCIN_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_RCIN_LEN, MAVLINK_MSG_ID_WK_LOG_RCIN_CRC);
#else
    mavlink_wk_log_rcin_t *packet = (mavlink_wk_log_rcin_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->update_ms = update_ms;
    packet->ch01 = ch01;
    packet->ch02 = ch02;
    packet->ch03 = ch03;
    packet->ch04 = ch04;
    packet->ch05 = ch05;
    packet->ch06 = ch06;
    packet->ch07 = ch07;
    packet->ch08 = ch08;
    packet->ch09 = ch09;
    packet->ch10 = ch10;
    packet->ch11 = ch11;
    packet->ch12 = ch12;
    packet->ch13 = ch13;
    packet->ch14 = ch14;
    packet->ch15 = ch15;
    packet->ch16 = ch16;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_RCIN, (const char *)packet, MAVLINK_MSG_ID_WK_LOG_RCIN_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_RCIN_LEN, MAVLINK_MSG_ID_WK_LOG_RCIN_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_LOG_RCIN UNPACKING


/**
 * @brief Get field timestamp from wk_log_rcin message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_wk_log_rcin_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field update_ms from wk_log_rcin message
 *
 * @return  update_ms
 */
static inline uint32_t mavlink_msg_wk_log_rcin_get_update_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field ch01 from wk_log_rcin message
 *
 * @return  ch01
 */
static inline uint16_t mavlink_msg_wk_log_rcin_get_ch01(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field ch02 from wk_log_rcin message
 *
 * @return  ch02
 */
static inline uint16_t mavlink_msg_wk_log_rcin_get_ch02(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field ch03 from wk_log_rcin message
 *
 * @return  ch03
 */
static inline uint16_t mavlink_msg_wk_log_rcin_get_ch03(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field ch04 from wk_log_rcin message
 *
 * @return  ch04
 */
static inline uint16_t mavlink_msg_wk_log_rcin_get_ch04(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field ch05 from wk_log_rcin message
 *
 * @return  ch05
 */
static inline uint16_t mavlink_msg_wk_log_rcin_get_ch05(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field ch06 from wk_log_rcin message
 *
 * @return  ch06
 */
static inline uint16_t mavlink_msg_wk_log_rcin_get_ch06(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Get field ch07 from wk_log_rcin message
 *
 * @return  ch07
 */
static inline uint16_t mavlink_msg_wk_log_rcin_get_ch07(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field ch08 from wk_log_rcin message
 *
 * @return  ch08
 */
static inline uint16_t mavlink_msg_wk_log_rcin_get_ch08(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field ch09 from wk_log_rcin message
 *
 * @return  ch09
 */
static inline uint16_t mavlink_msg_wk_log_rcin_get_ch09(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field ch10 from wk_log_rcin message
 *
 * @return  ch10
 */
static inline uint16_t mavlink_msg_wk_log_rcin_get_ch10(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  30);
}

/**
 * @brief Get field ch11 from wk_log_rcin message
 *
 * @return  ch11
 */
static inline uint16_t mavlink_msg_wk_log_rcin_get_ch11(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field ch12 from wk_log_rcin message
 *
 * @return  ch12
 */
static inline uint16_t mavlink_msg_wk_log_rcin_get_ch12(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  34);
}

/**
 * @brief Get field ch13 from wk_log_rcin message
 *
 * @return  ch13
 */
static inline uint16_t mavlink_msg_wk_log_rcin_get_ch13(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  36);
}

/**
 * @brief Get field ch14 from wk_log_rcin message
 *
 * @return  ch14
 */
static inline uint16_t mavlink_msg_wk_log_rcin_get_ch14(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  38);
}

/**
 * @brief Get field ch15 from wk_log_rcin message
 *
 * @return  ch15
 */
static inline uint16_t mavlink_msg_wk_log_rcin_get_ch15(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  40);
}

/**
 * @brief Get field ch16 from wk_log_rcin message
 *
 * @return  ch16
 */
static inline uint16_t mavlink_msg_wk_log_rcin_get_ch16(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  42);
}

/**
 * @brief Decode a wk_log_rcin message into a struct
 *
 * @param msg The message to decode
 * @param wk_log_rcin C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_log_rcin_decode(const mavlink_message_t* msg, mavlink_wk_log_rcin_t* wk_log_rcin)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_log_rcin->timestamp = mavlink_msg_wk_log_rcin_get_timestamp(msg);
    wk_log_rcin->update_ms = mavlink_msg_wk_log_rcin_get_update_ms(msg);
    wk_log_rcin->ch01 = mavlink_msg_wk_log_rcin_get_ch01(msg);
    wk_log_rcin->ch02 = mavlink_msg_wk_log_rcin_get_ch02(msg);
    wk_log_rcin->ch03 = mavlink_msg_wk_log_rcin_get_ch03(msg);
    wk_log_rcin->ch04 = mavlink_msg_wk_log_rcin_get_ch04(msg);
    wk_log_rcin->ch05 = mavlink_msg_wk_log_rcin_get_ch05(msg);
    wk_log_rcin->ch06 = mavlink_msg_wk_log_rcin_get_ch06(msg);
    wk_log_rcin->ch07 = mavlink_msg_wk_log_rcin_get_ch07(msg);
    wk_log_rcin->ch08 = mavlink_msg_wk_log_rcin_get_ch08(msg);
    wk_log_rcin->ch09 = mavlink_msg_wk_log_rcin_get_ch09(msg);
    wk_log_rcin->ch10 = mavlink_msg_wk_log_rcin_get_ch10(msg);
    wk_log_rcin->ch11 = mavlink_msg_wk_log_rcin_get_ch11(msg);
    wk_log_rcin->ch12 = mavlink_msg_wk_log_rcin_get_ch12(msg);
    wk_log_rcin->ch13 = mavlink_msg_wk_log_rcin_get_ch13(msg);
    wk_log_rcin->ch14 = mavlink_msg_wk_log_rcin_get_ch14(msg);
    wk_log_rcin->ch15 = mavlink_msg_wk_log_rcin_get_ch15(msg);
    wk_log_rcin->ch16 = mavlink_msg_wk_log_rcin_get_ch16(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_LOG_RCIN_LEN? msg->len : MAVLINK_MSG_ID_WK_LOG_RCIN_LEN;
        memset(wk_log_rcin, 0, MAVLINK_MSG_ID_WK_LOG_RCIN_LEN);
    memcpy(wk_log_rcin, _MAV_PAYLOAD(msg), len);
#endif
}
