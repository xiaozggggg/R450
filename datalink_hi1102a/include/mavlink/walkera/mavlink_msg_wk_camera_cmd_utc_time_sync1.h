#pragma once
// MESSAGE WK_CAMERA_CMD_UTC_TIME_SYNC1 PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1 8074


typedef struct __mavlink_wk_camera_cmd_utc_time_sync1_t {
 uint16_t year; /*<  year*/
 uint8_t month; /*<  month*/
 uint8_t day; /*<  day*/
 uint8_t hour; /*<  hour*/
 uint8_t min; /*<  minutes*/
 uint8_t sec; /*<  second*/
 char time_zone; /*<  time zone*/
} mavlink_wk_camera_cmd_utc_time_sync1_t;

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN 8
#define MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_MIN_LEN 8
#define MAVLINK_MSG_ID_8074_LEN 8
#define MAVLINK_MSG_ID_8074_MIN_LEN 8

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_CRC 124
#define MAVLINK_MSG_ID_8074_CRC 124



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_UTC_TIME_SYNC1 { \
    8074, \
    "WK_CAMERA_CMD_UTC_TIME_SYNC1", \
    7, \
    {  { "year", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wk_camera_cmd_utc_time_sync1_t, year) }, \
         { "month", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_camera_cmd_utc_time_sync1_t, month) }, \
         { "day", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_camera_cmd_utc_time_sync1_t, day) }, \
         { "hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_camera_cmd_utc_time_sync1_t, hour) }, \
         { "min", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_camera_cmd_utc_time_sync1_t, min) }, \
         { "sec", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_camera_cmd_utc_time_sync1_t, sec) }, \
         { "time_zone", NULL, MAVLINK_TYPE_CHAR, 0, 7, offsetof(mavlink_wk_camera_cmd_utc_time_sync1_t, time_zone) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_UTC_TIME_SYNC1 { \
    "WK_CAMERA_CMD_UTC_TIME_SYNC1", \
    7, \
    {  { "year", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wk_camera_cmd_utc_time_sync1_t, year) }, \
         { "month", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_camera_cmd_utc_time_sync1_t, month) }, \
         { "day", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_camera_cmd_utc_time_sync1_t, day) }, \
         { "hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_camera_cmd_utc_time_sync1_t, hour) }, \
         { "min", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_camera_cmd_utc_time_sync1_t, min) }, \
         { "sec", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_camera_cmd_utc_time_sync1_t, sec) }, \
         { "time_zone", NULL, MAVLINK_TYPE_CHAR, 0, 7, offsetof(mavlink_wk_camera_cmd_utc_time_sync1_t, time_zone) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_cmd_utc_time_sync1 message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param year  year
 * @param month  month
 * @param day  day
 * @param hour  hour
 * @param min  minutes
 * @param sec  second
 * @param time_zone  time zone
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_utc_time_sync1_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec, char time_zone)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN];
    _mav_put_uint16_t(buf, 0, year);
    _mav_put_uint8_t(buf, 2, month);
    _mav_put_uint8_t(buf, 3, day);
    _mav_put_uint8_t(buf, 4, hour);
    _mav_put_uint8_t(buf, 5, min);
    _mav_put_uint8_t(buf, 6, sec);
    _mav_put_char(buf, 7, time_zone);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN);
#else
    mavlink_wk_camera_cmd_utc_time_sync1_t packet;
    packet.year = year;
    packet.month = month;
    packet.day = day;
    packet.hour = hour;
    packet.min = min;
    packet.sec = sec;
    packet.time_zone = time_zone;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_CRC);
}

/**
 * @brief Pack a wk_camera_cmd_utc_time_sync1 message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param year  year
 * @param month  month
 * @param day  day
 * @param hour  hour
 * @param min  minutes
 * @param sec  second
 * @param time_zone  time zone
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_utc_time_sync1_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t min,uint8_t sec,char time_zone)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN];
    _mav_put_uint16_t(buf, 0, year);
    _mav_put_uint8_t(buf, 2, month);
    _mav_put_uint8_t(buf, 3, day);
    _mav_put_uint8_t(buf, 4, hour);
    _mav_put_uint8_t(buf, 5, min);
    _mav_put_uint8_t(buf, 6, sec);
    _mav_put_char(buf, 7, time_zone);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN);
#else
    mavlink_wk_camera_cmd_utc_time_sync1_t packet;
    packet.year = year;
    packet.month = month;
    packet.day = day;
    packet.hour = hour;
    packet.min = min;
    packet.sec = sec;
    packet.time_zone = time_zone;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_CRC);
}

/**
 * @brief Encode a wk_camera_cmd_utc_time_sync1 struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_utc_time_sync1 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_utc_time_sync1_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_cmd_utc_time_sync1_t* wk_camera_cmd_utc_time_sync1)
{
    return mavlink_msg_wk_camera_cmd_utc_time_sync1_pack(system_id, component_id, msg, wk_camera_cmd_utc_time_sync1->year, wk_camera_cmd_utc_time_sync1->month, wk_camera_cmd_utc_time_sync1->day, wk_camera_cmd_utc_time_sync1->hour, wk_camera_cmd_utc_time_sync1->min, wk_camera_cmd_utc_time_sync1->sec, wk_camera_cmd_utc_time_sync1->time_zone);
}

/**
 * @brief Encode a wk_camera_cmd_utc_time_sync1 struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_utc_time_sync1 C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_utc_time_sync1_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_cmd_utc_time_sync1_t* wk_camera_cmd_utc_time_sync1)
{
    return mavlink_msg_wk_camera_cmd_utc_time_sync1_pack_chan(system_id, component_id, chan, msg, wk_camera_cmd_utc_time_sync1->year, wk_camera_cmd_utc_time_sync1->month, wk_camera_cmd_utc_time_sync1->day, wk_camera_cmd_utc_time_sync1->hour, wk_camera_cmd_utc_time_sync1->min, wk_camera_cmd_utc_time_sync1->sec, wk_camera_cmd_utc_time_sync1->time_zone);
}

/**
 * @brief Send a wk_camera_cmd_utc_time_sync1 message
 * @param chan MAVLink channel to send the message
 *
 * @param year  year
 * @param month  month
 * @param day  day
 * @param hour  hour
 * @param min  minutes
 * @param sec  second
 * @param time_zone  time zone
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_cmd_utc_time_sync1_send(mavlink_channel_t chan, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec, char time_zone)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN];
    _mav_put_uint16_t(buf, 0, year);
    _mav_put_uint8_t(buf, 2, month);
    _mav_put_uint8_t(buf, 3, day);
    _mav_put_uint8_t(buf, 4, hour);
    _mav_put_uint8_t(buf, 5, min);
    _mav_put_uint8_t(buf, 6, sec);
    _mav_put_char(buf, 7, time_zone);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_CRC);
#else
    mavlink_wk_camera_cmd_utc_time_sync1_t packet;
    packet.year = year;
    packet.month = month;
    packet.day = day;
    packet.hour = hour;
    packet.min = min;
    packet.sec = sec;
    packet.time_zone = time_zone;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_CRC);
#endif
}

/**
 * @brief Send a wk_camera_cmd_utc_time_sync1 message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_cmd_utc_time_sync1_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_cmd_utc_time_sync1_t* wk_camera_cmd_utc_time_sync1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_utc_time_sync1_send(chan, wk_camera_cmd_utc_time_sync1->year, wk_camera_cmd_utc_time_sync1->month, wk_camera_cmd_utc_time_sync1->day, wk_camera_cmd_utc_time_sync1->hour, wk_camera_cmd_utc_time_sync1->min, wk_camera_cmd_utc_time_sync1->sec, wk_camera_cmd_utc_time_sync1->time_zone);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1, (const char *)wk_camera_cmd_utc_time_sync1, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_cmd_utc_time_sync1_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec, char time_zone)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, year);
    _mav_put_uint8_t(buf, 2, month);
    _mav_put_uint8_t(buf, 3, day);
    _mav_put_uint8_t(buf, 4, hour);
    _mav_put_uint8_t(buf, 5, min);
    _mav_put_uint8_t(buf, 6, sec);
    _mav_put_char(buf, 7, time_zone);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_CRC);
#else
    mavlink_wk_camera_cmd_utc_time_sync1_t *packet = (mavlink_wk_camera_cmd_utc_time_sync1_t *)msgbuf;
    packet->year = year;
    packet->month = month;
    packet->day = day;
    packet->hour = hour;
    packet->min = min;
    packet->sec = sec;
    packet->time_zone = time_zone;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_CMD_UTC_TIME_SYNC1 UNPACKING


/**
 * @brief Get field year from wk_camera_cmd_utc_time_sync1 message
 *
 * @return  year
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_utc_time_sync1_get_year(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field month from wk_camera_cmd_utc_time_sync1 message
 *
 * @return  month
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_utc_time_sync1_get_month(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field day from wk_camera_cmd_utc_time_sync1 message
 *
 * @return  day
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_utc_time_sync1_get_day(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field hour from wk_camera_cmd_utc_time_sync1 message
 *
 * @return  hour
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_utc_time_sync1_get_hour(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field min from wk_camera_cmd_utc_time_sync1 message
 *
 * @return  minutes
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_utc_time_sync1_get_min(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field sec from wk_camera_cmd_utc_time_sync1 message
 *
 * @return  second
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_utc_time_sync1_get_sec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field time_zone from wk_camera_cmd_utc_time_sync1 message
 *
 * @return  time zone
 */
static inline char mavlink_msg_wk_camera_cmd_utc_time_sync1_get_time_zone(const mavlink_message_t* msg)
{
    return _MAV_RETURN_char(msg,  7);
}

/**
 * @brief Decode a wk_camera_cmd_utc_time_sync1 message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_cmd_utc_time_sync1 C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_cmd_utc_time_sync1_decode(const mavlink_message_t* msg, mavlink_wk_camera_cmd_utc_time_sync1_t* wk_camera_cmd_utc_time_sync1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_cmd_utc_time_sync1->year = mavlink_msg_wk_camera_cmd_utc_time_sync1_get_year(msg);
    wk_camera_cmd_utc_time_sync1->month = mavlink_msg_wk_camera_cmd_utc_time_sync1_get_month(msg);
    wk_camera_cmd_utc_time_sync1->day = mavlink_msg_wk_camera_cmd_utc_time_sync1_get_day(msg);
    wk_camera_cmd_utc_time_sync1->hour = mavlink_msg_wk_camera_cmd_utc_time_sync1_get_hour(msg);
    wk_camera_cmd_utc_time_sync1->min = mavlink_msg_wk_camera_cmd_utc_time_sync1_get_min(msg);
    wk_camera_cmd_utc_time_sync1->sec = mavlink_msg_wk_camera_cmd_utc_time_sync1_get_sec(msg);
    wk_camera_cmd_utc_time_sync1->time_zone = mavlink_msg_wk_camera_cmd_utc_time_sync1_get_time_zone(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN;
        memset(wk_camera_cmd_utc_time_sync1, 0, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC1_LEN);
    memcpy(wk_camera_cmd_utc_time_sync1, _MAV_PAYLOAD(msg), len);
#endif
}
