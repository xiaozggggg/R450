#pragma once
// MESSAGE WK_LOG_MOTORS PACKING

#define MAVLINK_MSG_ID_WK_LOG_MOTORS 8506


typedef struct __mavlink_wk_log_motors_t {
 uint64_t timestamp; /*<  timestamp*/
 uint16_t MOT01; /*<  MOT01*/
 uint16_t MOT02; /*<  MOT02*/
 uint16_t MOT03; /*<  MOT03*/
 uint16_t MOT04; /*<  MOT04*/
 uint16_t MOT05; /*<  MOT05*/
 uint16_t MOT06; /*<  MOT06*/
 uint16_t MOT07; /*<  MOT07*/
 uint16_t MOT08; /*<  MOT08*/
 uint16_t MOT09; /*<  MOT09*/
 uint16_t MOT10; /*<  MOT10*/
 uint16_t MOT11; /*<  MOT11*/
 uint16_t MOT12; /*<  MOT12*/
} mavlink_wk_log_motors_t;

#define MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN 32
#define MAVLINK_MSG_ID_WK_LOG_MOTORS_MIN_LEN 32
#define MAVLINK_MSG_ID_8506_LEN 32
#define MAVLINK_MSG_ID_8506_MIN_LEN 32

#define MAVLINK_MSG_ID_WK_LOG_MOTORS_CRC 149
#define MAVLINK_MSG_ID_8506_CRC 149



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_LOG_MOTORS { \
    8506, \
    "WK_LOG_MOTORS", \
    13, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_motors_t, timestamp) }, \
         { "MOT01", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_wk_log_motors_t, MOT01) }, \
         { "MOT02", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_wk_log_motors_t, MOT02) }, \
         { "MOT03", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_wk_log_motors_t, MOT03) }, \
         { "MOT04", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_wk_log_motors_t, MOT04) }, \
         { "MOT05", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_wk_log_motors_t, MOT05) }, \
         { "MOT06", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_wk_log_motors_t, MOT06) }, \
         { "MOT07", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_wk_log_motors_t, MOT07) }, \
         { "MOT08", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_wk_log_motors_t, MOT08) }, \
         { "MOT09", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_wk_log_motors_t, MOT09) }, \
         { "MOT10", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_wk_log_motors_t, MOT10) }, \
         { "MOT11", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_wk_log_motors_t, MOT11) }, \
         { "MOT12", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_wk_log_motors_t, MOT12) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_LOG_MOTORS { \
    "WK_LOG_MOTORS", \
    13, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_motors_t, timestamp) }, \
         { "MOT01", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_wk_log_motors_t, MOT01) }, \
         { "MOT02", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_wk_log_motors_t, MOT02) }, \
         { "MOT03", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_wk_log_motors_t, MOT03) }, \
         { "MOT04", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_wk_log_motors_t, MOT04) }, \
         { "MOT05", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_wk_log_motors_t, MOT05) }, \
         { "MOT06", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_wk_log_motors_t, MOT06) }, \
         { "MOT07", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_wk_log_motors_t, MOT07) }, \
         { "MOT08", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_wk_log_motors_t, MOT08) }, \
         { "MOT09", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_wk_log_motors_t, MOT09) }, \
         { "MOT10", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_wk_log_motors_t, MOT10) }, \
         { "MOT11", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_wk_log_motors_t, MOT11) }, \
         { "MOT12", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_wk_log_motors_t, MOT12) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_log_motors message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  timestamp
 * @param MOT01  MOT01
 * @param MOT02  MOT02
 * @param MOT03  MOT03
 * @param MOT04  MOT04
 * @param MOT05  MOT05
 * @param MOT06  MOT06
 * @param MOT07  MOT07
 * @param MOT08  MOT08
 * @param MOT09  MOT09
 * @param MOT10  MOT10
 * @param MOT11  MOT11
 * @param MOT12  MOT12
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_motors_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint16_t MOT01, uint16_t MOT02, uint16_t MOT03, uint16_t MOT04, uint16_t MOT05, uint16_t MOT06, uint16_t MOT07, uint16_t MOT08, uint16_t MOT09, uint16_t MOT10, uint16_t MOT11, uint16_t MOT12)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint16_t(buf, 8, MOT01);
    _mav_put_uint16_t(buf, 10, MOT02);
    _mav_put_uint16_t(buf, 12, MOT03);
    _mav_put_uint16_t(buf, 14, MOT04);
    _mav_put_uint16_t(buf, 16, MOT05);
    _mav_put_uint16_t(buf, 18, MOT06);
    _mav_put_uint16_t(buf, 20, MOT07);
    _mav_put_uint16_t(buf, 22, MOT08);
    _mav_put_uint16_t(buf, 24, MOT09);
    _mav_put_uint16_t(buf, 26, MOT10);
    _mav_put_uint16_t(buf, 28, MOT11);
    _mav_put_uint16_t(buf, 30, MOT12);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN);
#else
    mavlink_wk_log_motors_t packet;
    packet.timestamp = timestamp;
    packet.MOT01 = MOT01;
    packet.MOT02 = MOT02;
    packet.MOT03 = MOT03;
    packet.MOT04 = MOT04;
    packet.MOT05 = MOT05;
    packet.MOT06 = MOT06;
    packet.MOT07 = MOT07;
    packet.MOT08 = MOT08;
    packet.MOT09 = MOT09;
    packet.MOT10 = MOT10;
    packet.MOT11 = MOT11;
    packet.MOT12 = MOT12;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_MOTORS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_LOG_MOTORS_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN, MAVLINK_MSG_ID_WK_LOG_MOTORS_CRC);
}

/**
 * @brief Pack a wk_log_motors message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  timestamp
 * @param MOT01  MOT01
 * @param MOT02  MOT02
 * @param MOT03  MOT03
 * @param MOT04  MOT04
 * @param MOT05  MOT05
 * @param MOT06  MOT06
 * @param MOT07  MOT07
 * @param MOT08  MOT08
 * @param MOT09  MOT09
 * @param MOT10  MOT10
 * @param MOT11  MOT11
 * @param MOT12  MOT12
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_motors_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,uint16_t MOT01,uint16_t MOT02,uint16_t MOT03,uint16_t MOT04,uint16_t MOT05,uint16_t MOT06,uint16_t MOT07,uint16_t MOT08,uint16_t MOT09,uint16_t MOT10,uint16_t MOT11,uint16_t MOT12)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint16_t(buf, 8, MOT01);
    _mav_put_uint16_t(buf, 10, MOT02);
    _mav_put_uint16_t(buf, 12, MOT03);
    _mav_put_uint16_t(buf, 14, MOT04);
    _mav_put_uint16_t(buf, 16, MOT05);
    _mav_put_uint16_t(buf, 18, MOT06);
    _mav_put_uint16_t(buf, 20, MOT07);
    _mav_put_uint16_t(buf, 22, MOT08);
    _mav_put_uint16_t(buf, 24, MOT09);
    _mav_put_uint16_t(buf, 26, MOT10);
    _mav_put_uint16_t(buf, 28, MOT11);
    _mav_put_uint16_t(buf, 30, MOT12);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN);
#else
    mavlink_wk_log_motors_t packet;
    packet.timestamp = timestamp;
    packet.MOT01 = MOT01;
    packet.MOT02 = MOT02;
    packet.MOT03 = MOT03;
    packet.MOT04 = MOT04;
    packet.MOT05 = MOT05;
    packet.MOT06 = MOT06;
    packet.MOT07 = MOT07;
    packet.MOT08 = MOT08;
    packet.MOT09 = MOT09;
    packet.MOT10 = MOT10;
    packet.MOT11 = MOT11;
    packet.MOT12 = MOT12;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_MOTORS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_LOG_MOTORS_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN, MAVLINK_MSG_ID_WK_LOG_MOTORS_CRC);
}

/**
 * @brief Encode a wk_log_motors struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_motors C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_motors_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_log_motors_t* wk_log_motors)
{
    return mavlink_msg_wk_log_motors_pack(system_id, component_id, msg, wk_log_motors->timestamp, wk_log_motors->MOT01, wk_log_motors->MOT02, wk_log_motors->MOT03, wk_log_motors->MOT04, wk_log_motors->MOT05, wk_log_motors->MOT06, wk_log_motors->MOT07, wk_log_motors->MOT08, wk_log_motors->MOT09, wk_log_motors->MOT10, wk_log_motors->MOT11, wk_log_motors->MOT12);
}

/**
 * @brief Encode a wk_log_motors struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_motors C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_motors_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_log_motors_t* wk_log_motors)
{
    return mavlink_msg_wk_log_motors_pack_chan(system_id, component_id, chan, msg, wk_log_motors->timestamp, wk_log_motors->MOT01, wk_log_motors->MOT02, wk_log_motors->MOT03, wk_log_motors->MOT04, wk_log_motors->MOT05, wk_log_motors->MOT06, wk_log_motors->MOT07, wk_log_motors->MOT08, wk_log_motors->MOT09, wk_log_motors->MOT10, wk_log_motors->MOT11, wk_log_motors->MOT12);
}

/**
 * @brief Send a wk_log_motors message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 * @param MOT01  MOT01
 * @param MOT02  MOT02
 * @param MOT03  MOT03
 * @param MOT04  MOT04
 * @param MOT05  MOT05
 * @param MOT06  MOT06
 * @param MOT07  MOT07
 * @param MOT08  MOT08
 * @param MOT09  MOT09
 * @param MOT10  MOT10
 * @param MOT11  MOT11
 * @param MOT12  MOT12
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_log_motors_send(mavlink_channel_t chan, uint64_t timestamp, uint16_t MOT01, uint16_t MOT02, uint16_t MOT03, uint16_t MOT04, uint16_t MOT05, uint16_t MOT06, uint16_t MOT07, uint16_t MOT08, uint16_t MOT09, uint16_t MOT10, uint16_t MOT11, uint16_t MOT12)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint16_t(buf, 8, MOT01);
    _mav_put_uint16_t(buf, 10, MOT02);
    _mav_put_uint16_t(buf, 12, MOT03);
    _mav_put_uint16_t(buf, 14, MOT04);
    _mav_put_uint16_t(buf, 16, MOT05);
    _mav_put_uint16_t(buf, 18, MOT06);
    _mav_put_uint16_t(buf, 20, MOT07);
    _mav_put_uint16_t(buf, 22, MOT08);
    _mav_put_uint16_t(buf, 24, MOT09);
    _mav_put_uint16_t(buf, 26, MOT10);
    _mav_put_uint16_t(buf, 28, MOT11);
    _mav_put_uint16_t(buf, 30, MOT12);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_MOTORS, buf, MAVLINK_MSG_ID_WK_LOG_MOTORS_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN, MAVLINK_MSG_ID_WK_LOG_MOTORS_CRC);
#else
    mavlink_wk_log_motors_t packet;
    packet.timestamp = timestamp;
    packet.MOT01 = MOT01;
    packet.MOT02 = MOT02;
    packet.MOT03 = MOT03;
    packet.MOT04 = MOT04;
    packet.MOT05 = MOT05;
    packet.MOT06 = MOT06;
    packet.MOT07 = MOT07;
    packet.MOT08 = MOT08;
    packet.MOT09 = MOT09;
    packet.MOT10 = MOT10;
    packet.MOT11 = MOT11;
    packet.MOT12 = MOT12;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_MOTORS, (const char *)&packet, MAVLINK_MSG_ID_WK_LOG_MOTORS_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN, MAVLINK_MSG_ID_WK_LOG_MOTORS_CRC);
#endif
}

/**
 * @brief Send a wk_log_motors message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_log_motors_send_struct(mavlink_channel_t chan, const mavlink_wk_log_motors_t* wk_log_motors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_log_motors_send(chan, wk_log_motors->timestamp, wk_log_motors->MOT01, wk_log_motors->MOT02, wk_log_motors->MOT03, wk_log_motors->MOT04, wk_log_motors->MOT05, wk_log_motors->MOT06, wk_log_motors->MOT07, wk_log_motors->MOT08, wk_log_motors->MOT09, wk_log_motors->MOT10, wk_log_motors->MOT11, wk_log_motors->MOT12);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_MOTORS, (const char *)wk_log_motors, MAVLINK_MSG_ID_WK_LOG_MOTORS_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN, MAVLINK_MSG_ID_WK_LOG_MOTORS_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_log_motors_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, uint16_t MOT01, uint16_t MOT02, uint16_t MOT03, uint16_t MOT04, uint16_t MOT05, uint16_t MOT06, uint16_t MOT07, uint16_t MOT08, uint16_t MOT09, uint16_t MOT10, uint16_t MOT11, uint16_t MOT12)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint16_t(buf, 8, MOT01);
    _mav_put_uint16_t(buf, 10, MOT02);
    _mav_put_uint16_t(buf, 12, MOT03);
    _mav_put_uint16_t(buf, 14, MOT04);
    _mav_put_uint16_t(buf, 16, MOT05);
    _mav_put_uint16_t(buf, 18, MOT06);
    _mav_put_uint16_t(buf, 20, MOT07);
    _mav_put_uint16_t(buf, 22, MOT08);
    _mav_put_uint16_t(buf, 24, MOT09);
    _mav_put_uint16_t(buf, 26, MOT10);
    _mav_put_uint16_t(buf, 28, MOT11);
    _mav_put_uint16_t(buf, 30, MOT12);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_MOTORS, buf, MAVLINK_MSG_ID_WK_LOG_MOTORS_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN, MAVLINK_MSG_ID_WK_LOG_MOTORS_CRC);
#else
    mavlink_wk_log_motors_t *packet = (mavlink_wk_log_motors_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->MOT01 = MOT01;
    packet->MOT02 = MOT02;
    packet->MOT03 = MOT03;
    packet->MOT04 = MOT04;
    packet->MOT05 = MOT05;
    packet->MOT06 = MOT06;
    packet->MOT07 = MOT07;
    packet->MOT08 = MOT08;
    packet->MOT09 = MOT09;
    packet->MOT10 = MOT10;
    packet->MOT11 = MOT11;
    packet->MOT12 = MOT12;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_MOTORS, (const char *)packet, MAVLINK_MSG_ID_WK_LOG_MOTORS_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN, MAVLINK_MSG_ID_WK_LOG_MOTORS_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_LOG_MOTORS UNPACKING


/**
 * @brief Get field timestamp from wk_log_motors message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_wk_log_motors_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field MOT01 from wk_log_motors message
 *
 * @return  MOT01
 */
static inline uint16_t mavlink_msg_wk_log_motors_get_MOT01(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field MOT02 from wk_log_motors message
 *
 * @return  MOT02
 */
static inline uint16_t mavlink_msg_wk_log_motors_get_MOT02(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Get field MOT03 from wk_log_motors message
 *
 * @return  MOT03
 */
static inline uint16_t mavlink_msg_wk_log_motors_get_MOT03(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field MOT04 from wk_log_motors message
 *
 * @return  MOT04
 */
static inline uint16_t mavlink_msg_wk_log_motors_get_MOT04(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field MOT05 from wk_log_motors message
 *
 * @return  MOT05
 */
static inline uint16_t mavlink_msg_wk_log_motors_get_MOT05(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field MOT06 from wk_log_motors message
 *
 * @return  MOT06
 */
static inline uint16_t mavlink_msg_wk_log_motors_get_MOT06(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field MOT07 from wk_log_motors message
 *
 * @return  MOT07
 */
static inline uint16_t mavlink_msg_wk_log_motors_get_MOT07(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field MOT08 from wk_log_motors message
 *
 * @return  MOT08
 */
static inline uint16_t mavlink_msg_wk_log_motors_get_MOT08(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Get field MOT09 from wk_log_motors message
 *
 * @return  MOT09
 */
static inline uint16_t mavlink_msg_wk_log_motors_get_MOT09(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field MOT10 from wk_log_motors message
 *
 * @return  MOT10
 */
static inline uint16_t mavlink_msg_wk_log_motors_get_MOT10(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field MOT11 from wk_log_motors message
 *
 * @return  MOT11
 */
static inline uint16_t mavlink_msg_wk_log_motors_get_MOT11(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field MOT12 from wk_log_motors message
 *
 * @return  MOT12
 */
static inline uint16_t mavlink_msg_wk_log_motors_get_MOT12(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  30);
}

/**
 * @brief Decode a wk_log_motors message into a struct
 *
 * @param msg The message to decode
 * @param wk_log_motors C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_log_motors_decode(const mavlink_message_t* msg, mavlink_wk_log_motors_t* wk_log_motors)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_log_motors->timestamp = mavlink_msg_wk_log_motors_get_timestamp(msg);
    wk_log_motors->MOT01 = mavlink_msg_wk_log_motors_get_MOT01(msg);
    wk_log_motors->MOT02 = mavlink_msg_wk_log_motors_get_MOT02(msg);
    wk_log_motors->MOT03 = mavlink_msg_wk_log_motors_get_MOT03(msg);
    wk_log_motors->MOT04 = mavlink_msg_wk_log_motors_get_MOT04(msg);
    wk_log_motors->MOT05 = mavlink_msg_wk_log_motors_get_MOT05(msg);
    wk_log_motors->MOT06 = mavlink_msg_wk_log_motors_get_MOT06(msg);
    wk_log_motors->MOT07 = mavlink_msg_wk_log_motors_get_MOT07(msg);
    wk_log_motors->MOT08 = mavlink_msg_wk_log_motors_get_MOT08(msg);
    wk_log_motors->MOT09 = mavlink_msg_wk_log_motors_get_MOT09(msg);
    wk_log_motors->MOT10 = mavlink_msg_wk_log_motors_get_MOT10(msg);
    wk_log_motors->MOT11 = mavlink_msg_wk_log_motors_get_MOT11(msg);
    wk_log_motors->MOT12 = mavlink_msg_wk_log_motors_get_MOT12(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN? msg->len : MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN;
        memset(wk_log_motors, 0, MAVLINK_MSG_ID_WK_LOG_MOTORS_LEN);
    memcpy(wk_log_motors, _MAV_PAYLOAD(msg), len);
#endif
}
