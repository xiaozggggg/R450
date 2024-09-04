#pragma once
// MESSAGE WK_MISSION_BREAK_POINT PACKING

#define MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT 8004


typedef struct __mavlink_wk_mission_break_point_t {
 uint32_t trig_timestamp; /*<  trig_timestamp*/
 uint32_t break_cmd_seq; /*<  break cmd seq*/
 int32_t latitude; /*<  latitude * 1E7*/
 int32_t longitude; /*<  longitude * 1E7*/
 int32_t altitude_relative; /*<  altitude relative HOME,unit cm*/
 int32_t altitude_abs; /*<  altitude above sea level,unit cm*/
} mavlink_wk_mission_break_point_t;

#define MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN 24
#define MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_MIN_LEN 24
#define MAVLINK_MSG_ID_8004_LEN 24
#define MAVLINK_MSG_ID_8004_MIN_LEN 24

#define MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_CRC 9
#define MAVLINK_MSG_ID_8004_CRC 9



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_MISSION_BREAK_POINT { \
    8004, \
    "WK_MISSION_BREAK_POINT", \
    6, \
    {  { "trig_timestamp", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_mission_break_point_t, trig_timestamp) }, \
         { "break_cmd_seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_mission_break_point_t, break_cmd_seq) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_mission_break_point_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_mission_break_point_t, longitude) }, \
         { "altitude_relative", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_wk_mission_break_point_t, altitude_relative) }, \
         { "altitude_abs", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_wk_mission_break_point_t, altitude_abs) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_MISSION_BREAK_POINT { \
    "WK_MISSION_BREAK_POINT", \
    6, \
    {  { "trig_timestamp", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_mission_break_point_t, trig_timestamp) }, \
         { "break_cmd_seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_mission_break_point_t, break_cmd_seq) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_mission_break_point_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_mission_break_point_t, longitude) }, \
         { "altitude_relative", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_wk_mission_break_point_t, altitude_relative) }, \
         { "altitude_abs", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_wk_mission_break_point_t, altitude_abs) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_mission_break_point message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param trig_timestamp  trig_timestamp
 * @param break_cmd_seq  break cmd seq
 * @param latitude  latitude * 1E7
 * @param longitude  longitude * 1E7
 * @param altitude_relative  altitude relative HOME,unit cm
 * @param altitude_abs  altitude above sea level,unit cm
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_mission_break_point_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t trig_timestamp, uint32_t break_cmd_seq, int32_t latitude, int32_t longitude, int32_t altitude_relative, int32_t altitude_abs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN];
    _mav_put_uint32_t(buf, 0, trig_timestamp);
    _mav_put_uint32_t(buf, 4, break_cmd_seq);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, altitude_relative);
    _mav_put_int32_t(buf, 20, altitude_abs);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN);
#else
    mavlink_wk_mission_break_point_t packet;
    packet.trig_timestamp = trig_timestamp;
    packet.break_cmd_seq = break_cmd_seq;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude_relative = altitude_relative;
    packet.altitude_abs = altitude_abs;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_MIN_LEN, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_CRC);
}

/**
 * @brief Pack a wk_mission_break_point message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param trig_timestamp  trig_timestamp
 * @param break_cmd_seq  break cmd seq
 * @param latitude  latitude * 1E7
 * @param longitude  longitude * 1E7
 * @param altitude_relative  altitude relative HOME,unit cm
 * @param altitude_abs  altitude above sea level,unit cm
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_mission_break_point_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t trig_timestamp,uint32_t break_cmd_seq,int32_t latitude,int32_t longitude,int32_t altitude_relative,int32_t altitude_abs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN];
    _mav_put_uint32_t(buf, 0, trig_timestamp);
    _mav_put_uint32_t(buf, 4, break_cmd_seq);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, altitude_relative);
    _mav_put_int32_t(buf, 20, altitude_abs);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN);
#else
    mavlink_wk_mission_break_point_t packet;
    packet.trig_timestamp = trig_timestamp;
    packet.break_cmd_seq = break_cmd_seq;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude_relative = altitude_relative;
    packet.altitude_abs = altitude_abs;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_MIN_LEN, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_CRC);
}

/**
 * @brief Encode a wk_mission_break_point struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_mission_break_point C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_mission_break_point_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_mission_break_point_t* wk_mission_break_point)
{
    return mavlink_msg_wk_mission_break_point_pack(system_id, component_id, msg, wk_mission_break_point->trig_timestamp, wk_mission_break_point->break_cmd_seq, wk_mission_break_point->latitude, wk_mission_break_point->longitude, wk_mission_break_point->altitude_relative, wk_mission_break_point->altitude_abs);
}

/**
 * @brief Encode a wk_mission_break_point struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_mission_break_point C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_mission_break_point_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_mission_break_point_t* wk_mission_break_point)
{
    return mavlink_msg_wk_mission_break_point_pack_chan(system_id, component_id, chan, msg, wk_mission_break_point->trig_timestamp, wk_mission_break_point->break_cmd_seq, wk_mission_break_point->latitude, wk_mission_break_point->longitude, wk_mission_break_point->altitude_relative, wk_mission_break_point->altitude_abs);
}

/**
 * @brief Send a wk_mission_break_point message
 * @param chan MAVLink channel to send the message
 *
 * @param trig_timestamp  trig_timestamp
 * @param break_cmd_seq  break cmd seq
 * @param latitude  latitude * 1E7
 * @param longitude  longitude * 1E7
 * @param altitude_relative  altitude relative HOME,unit cm
 * @param altitude_abs  altitude above sea level,unit cm
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_mission_break_point_send(mavlink_channel_t chan, uint32_t trig_timestamp, uint32_t break_cmd_seq, int32_t latitude, int32_t longitude, int32_t altitude_relative, int32_t altitude_abs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN];
    _mav_put_uint32_t(buf, 0, trig_timestamp);
    _mav_put_uint32_t(buf, 4, break_cmd_seq);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, altitude_relative);
    _mav_put_int32_t(buf, 20, altitude_abs);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT, buf, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_MIN_LEN, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_CRC);
#else
    mavlink_wk_mission_break_point_t packet;
    packet.trig_timestamp = trig_timestamp;
    packet.break_cmd_seq = break_cmd_seq;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude_relative = altitude_relative;
    packet.altitude_abs = altitude_abs;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT, (const char *)&packet, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_MIN_LEN, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_CRC);
#endif
}

/**
 * @brief Send a wk_mission_break_point message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_mission_break_point_send_struct(mavlink_channel_t chan, const mavlink_wk_mission_break_point_t* wk_mission_break_point)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_mission_break_point_send(chan, wk_mission_break_point->trig_timestamp, wk_mission_break_point->break_cmd_seq, wk_mission_break_point->latitude, wk_mission_break_point->longitude, wk_mission_break_point->altitude_relative, wk_mission_break_point->altitude_abs);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT, (const char *)wk_mission_break_point, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_MIN_LEN, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_mission_break_point_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t trig_timestamp, uint32_t break_cmd_seq, int32_t latitude, int32_t longitude, int32_t altitude_relative, int32_t altitude_abs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, trig_timestamp);
    _mav_put_uint32_t(buf, 4, break_cmd_seq);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, altitude_relative);
    _mav_put_int32_t(buf, 20, altitude_abs);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT, buf, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_MIN_LEN, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_CRC);
#else
    mavlink_wk_mission_break_point_t *packet = (mavlink_wk_mission_break_point_t *)msgbuf;
    packet->trig_timestamp = trig_timestamp;
    packet->break_cmd_seq = break_cmd_seq;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->altitude_relative = altitude_relative;
    packet->altitude_abs = altitude_abs;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT, (const char *)packet, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_MIN_LEN, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_MISSION_BREAK_POINT UNPACKING


/**
 * @brief Get field trig_timestamp from wk_mission_break_point message
 *
 * @return  trig_timestamp
 */
static inline uint32_t mavlink_msg_wk_mission_break_point_get_trig_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field break_cmd_seq from wk_mission_break_point message
 *
 * @return  break cmd seq
 */
static inline uint32_t mavlink_msg_wk_mission_break_point_get_break_cmd_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field latitude from wk_mission_break_point message
 *
 * @return  latitude * 1E7
 */
static inline int32_t mavlink_msg_wk_mission_break_point_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field longitude from wk_mission_break_point message
 *
 * @return  longitude * 1E7
 */
static inline int32_t mavlink_msg_wk_mission_break_point_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field altitude_relative from wk_mission_break_point message
 *
 * @return  altitude relative HOME,unit cm
 */
static inline int32_t mavlink_msg_wk_mission_break_point_get_altitude_relative(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field altitude_abs from wk_mission_break_point message
 *
 * @return  altitude above sea level,unit cm
 */
static inline int32_t mavlink_msg_wk_mission_break_point_get_altitude_abs(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Decode a wk_mission_break_point message into a struct
 *
 * @param msg The message to decode
 * @param wk_mission_break_point C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_mission_break_point_decode(const mavlink_message_t* msg, mavlink_wk_mission_break_point_t* wk_mission_break_point)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_mission_break_point->trig_timestamp = mavlink_msg_wk_mission_break_point_get_trig_timestamp(msg);
    wk_mission_break_point->break_cmd_seq = mavlink_msg_wk_mission_break_point_get_break_cmd_seq(msg);
    wk_mission_break_point->latitude = mavlink_msg_wk_mission_break_point_get_latitude(msg);
    wk_mission_break_point->longitude = mavlink_msg_wk_mission_break_point_get_longitude(msg);
    wk_mission_break_point->altitude_relative = mavlink_msg_wk_mission_break_point_get_altitude_relative(msg);
    wk_mission_break_point->altitude_abs = mavlink_msg_wk_mission_break_point_get_altitude_abs(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN? msg->len : MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN;
        memset(wk_mission_break_point, 0, MAVLINK_MSG_ID_WK_MISSION_BREAK_POINT_LEN);
    memcpy(wk_mission_break_point, _MAV_PAYLOAD(msg), len);
#endif
}
