#pragma once
// MESSAGE WK_CAMERA_CMD_UTC_TIME_SYNC PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC 8047


typedef struct __mavlink_wk_camera_cmd_utc_time_sync_t {
 uint16_t year; /*<  year*/
 uint8_t month; /*<  month*/
 uint8_t day; /*<  day*/
 uint8_t hour; /*<  hour*/
 uint8_t min; /*<  minutes*/
 uint8_t sec; /*<  second*/
} mavlink_wk_camera_cmd_utc_time_sync_t;

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN 7
#define MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_MIN_LEN 7
#define MAVLINK_MSG_ID_8047_LEN 7
#define MAVLINK_MSG_ID_8047_MIN_LEN 7

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_CRC 254
#define MAVLINK_MSG_ID_8047_CRC 254



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_UTC_TIME_SYNC { \
    8047, \
    "WK_CAMERA_CMD_UTC_TIME_SYNC", \
    6, \
    {  { "year", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wk_camera_cmd_utc_time_sync_t, year) }, \
         { "month", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_camera_cmd_utc_time_sync_t, month) }, \
         { "day", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_camera_cmd_utc_time_sync_t, day) }, \
         { "hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_camera_cmd_utc_time_sync_t, hour) }, \
         { "min", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_camera_cmd_utc_time_sync_t, min) }, \
         { "sec", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_camera_cmd_utc_time_sync_t, sec) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_UTC_TIME_SYNC { \
    "WK_CAMERA_CMD_UTC_TIME_SYNC", \
    6, \
    {  { "year", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wk_camera_cmd_utc_time_sync_t, year) }, \
         { "month", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_camera_cmd_utc_time_sync_t, month) }, \
         { "day", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_camera_cmd_utc_time_sync_t, day) }, \
         { "hour", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_camera_cmd_utc_time_sync_t, hour) }, \
         { "min", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_camera_cmd_utc_time_sync_t, min) }, \
         { "sec", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_camera_cmd_utc_time_sync_t, sec) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_cmd_utc_time_sync message
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
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_utc_time_sync_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN];
    _mav_put_uint16_t(buf, 0, year);
    _mav_put_uint8_t(buf, 2, month);
    _mav_put_uint8_t(buf, 3, day);
    _mav_put_uint8_t(buf, 4, hour);
    _mav_put_uint8_t(buf, 5, min);
    _mav_put_uint8_t(buf, 6, sec);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN);
#else
    mavlink_wk_camera_cmd_utc_time_sync_t packet;
    packet.year = year;
    packet.month = month;
    packet.day = day;
    packet.hour = hour;
    packet.min = min;
    packet.sec = sec;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_CRC);
}

/**
 * @brief Pack a wk_camera_cmd_utc_time_sync message on a channel
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
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_utc_time_sync_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t min,uint8_t sec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN];
    _mav_put_uint16_t(buf, 0, year);
    _mav_put_uint8_t(buf, 2, month);
    _mav_put_uint8_t(buf, 3, day);
    _mav_put_uint8_t(buf, 4, hour);
    _mav_put_uint8_t(buf, 5, min);
    _mav_put_uint8_t(buf, 6, sec);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN);
#else
    mavlink_wk_camera_cmd_utc_time_sync_t packet;
    packet.year = year;
    packet.month = month;
    packet.day = day;
    packet.hour = hour;
    packet.min = min;
    packet.sec = sec;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_CRC);
}

/**
 * @brief Encode a wk_camera_cmd_utc_time_sync struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_utc_time_sync C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_utc_time_sync_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_cmd_utc_time_sync_t* wk_camera_cmd_utc_time_sync)
{
    return mavlink_msg_wk_camera_cmd_utc_time_sync_pack(system_id, component_id, msg, wk_camera_cmd_utc_time_sync->year, wk_camera_cmd_utc_time_sync->month, wk_camera_cmd_utc_time_sync->day, wk_camera_cmd_utc_time_sync->hour, wk_camera_cmd_utc_time_sync->min, wk_camera_cmd_utc_time_sync->sec);
}

/**
 * @brief Encode a wk_camera_cmd_utc_time_sync struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_utc_time_sync C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_utc_time_sync_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_cmd_utc_time_sync_t* wk_camera_cmd_utc_time_sync)
{
    return mavlink_msg_wk_camera_cmd_utc_time_sync_pack_chan(system_id, component_id, chan, msg, wk_camera_cmd_utc_time_sync->year, wk_camera_cmd_utc_time_sync->month, wk_camera_cmd_utc_time_sync->day, wk_camera_cmd_utc_time_sync->hour, wk_camera_cmd_utc_time_sync->min, wk_camera_cmd_utc_time_sync->sec);
}

/**
 * @brief Send a wk_camera_cmd_utc_time_sync message
 * @param chan MAVLink channel to send the message
 *
 * @param year  year
 * @param month  month
 * @param day  day
 * @param hour  hour
 * @param min  minutes
 * @param sec  second
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_cmd_utc_time_sync_send(mavlink_channel_t chan, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN];
    _mav_put_uint16_t(buf, 0, year);
    _mav_put_uint8_t(buf, 2, month);
    _mav_put_uint8_t(buf, 3, day);
    _mav_put_uint8_t(buf, 4, hour);
    _mav_put_uint8_t(buf, 5, min);
    _mav_put_uint8_t(buf, 6, sec);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_CRC);
#else
    mavlink_wk_camera_cmd_utc_time_sync_t packet;
    packet.year = year;
    packet.month = month;
    packet.day = day;
    packet.hour = hour;
    packet.min = min;
    packet.sec = sec;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_CRC);
#endif
}

/**
 * @brief Send a wk_camera_cmd_utc_time_sync message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_cmd_utc_time_sync_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_cmd_utc_time_sync_t* wk_camera_cmd_utc_time_sync)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_utc_time_sync_send(chan, wk_camera_cmd_utc_time_sync->year, wk_camera_cmd_utc_time_sync->month, wk_camera_cmd_utc_time_sync->day, wk_camera_cmd_utc_time_sync->hour, wk_camera_cmd_utc_time_sync->min, wk_camera_cmd_utc_time_sync->sec);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC, (const char *)wk_camera_cmd_utc_time_sync, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_cmd_utc_time_sync_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, year);
    _mav_put_uint8_t(buf, 2, month);
    _mav_put_uint8_t(buf, 3, day);
    _mav_put_uint8_t(buf, 4, hour);
    _mav_put_uint8_t(buf, 5, min);
    _mav_put_uint8_t(buf, 6, sec);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_CRC);
#else
    mavlink_wk_camera_cmd_utc_time_sync_t *packet = (mavlink_wk_camera_cmd_utc_time_sync_t *)msgbuf;
    packet->year = year;
    packet->month = month;
    packet->day = day;
    packet->hour = hour;
    packet->min = min;
    packet->sec = sec;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_CMD_UTC_TIME_SYNC UNPACKING


/**
 * @brief Get field year from wk_camera_cmd_utc_time_sync message
 *
 * @return  year
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_utc_time_sync_get_year(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field month from wk_camera_cmd_utc_time_sync message
 *
 * @return  month
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_utc_time_sync_get_month(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field day from wk_camera_cmd_utc_time_sync message
 *
 * @return  day
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_utc_time_sync_get_day(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field hour from wk_camera_cmd_utc_time_sync message
 *
 * @return  hour
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_utc_time_sync_get_hour(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field min from wk_camera_cmd_utc_time_sync message
 *
 * @return  minutes
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_utc_time_sync_get_min(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field sec from wk_camera_cmd_utc_time_sync message
 *
 * @return  second
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_utc_time_sync_get_sec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Decode a wk_camera_cmd_utc_time_sync message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_cmd_utc_time_sync C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_cmd_utc_time_sync_decode(const mavlink_message_t* msg, mavlink_wk_camera_cmd_utc_time_sync_t* wk_camera_cmd_utc_time_sync)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_cmd_utc_time_sync->year = mavlink_msg_wk_camera_cmd_utc_time_sync_get_year(msg);
    wk_camera_cmd_utc_time_sync->month = mavlink_msg_wk_camera_cmd_utc_time_sync_get_month(msg);
    wk_camera_cmd_utc_time_sync->day = mavlink_msg_wk_camera_cmd_utc_time_sync_get_day(msg);
    wk_camera_cmd_utc_time_sync->hour = mavlink_msg_wk_camera_cmd_utc_time_sync_get_hour(msg);
    wk_camera_cmd_utc_time_sync->min = mavlink_msg_wk_camera_cmd_utc_time_sync_get_min(msg);
    wk_camera_cmd_utc_time_sync->sec = mavlink_msg_wk_camera_cmd_utc_time_sync_get_sec(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN;
        memset(wk_camera_cmd_utc_time_sync, 0, MAVLINK_MSG_ID_WK_CAMERA_CMD_UTC_TIME_SYNC_LEN);
    memcpy(wk_camera_cmd_utc_time_sync, _MAV_PAYLOAD(msg), len);
#endif
}
