#pragma once
// MESSAGE WK_LOG_MISSION PACKING

#define MAVLINK_MSG_ID_WK_LOG_MISSION 8505


typedef struct __mavlink_wk_log_mission_t {
 uint64_t timestamp; /*<  timestamp*/
 uint32_t seq; /*<  seq*/
 int32_t latitude; /*<  latitude*/
 int32_t longitude; /*<  longitude*/
 int32_t altitude; /*<  altitude*/
} mavlink_wk_log_mission_t;

#define MAVLINK_MSG_ID_WK_LOG_MISSION_LEN 24
#define MAVLINK_MSG_ID_WK_LOG_MISSION_MIN_LEN 24
#define MAVLINK_MSG_ID_8505_LEN 24
#define MAVLINK_MSG_ID_8505_MIN_LEN 24

#define MAVLINK_MSG_ID_WK_LOG_MISSION_CRC 230
#define MAVLINK_MSG_ID_8505_CRC 230



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_LOG_MISSION { \
    8505, \
    "WK_LOG_MISSION", \
    5, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_mission_t, timestamp) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_log_mission_t, seq) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_log_mission_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_wk_log_mission_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_wk_log_mission_t, altitude) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_LOG_MISSION { \
    "WK_LOG_MISSION", \
    5, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_mission_t, timestamp) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_log_mission_t, seq) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_log_mission_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_wk_log_mission_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_wk_log_mission_t, altitude) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_log_mission message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  timestamp
 * @param seq  seq
 * @param latitude  latitude
 * @param longitude  longitude
 * @param altitude  altitude
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_mission_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint32_t seq, int32_t latitude, int32_t longitude, int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_MISSION_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, seq);
    _mav_put_int32_t(buf, 12, latitude);
    _mav_put_int32_t(buf, 16, longitude);
    _mav_put_int32_t(buf, 20, altitude);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_MISSION_LEN);
#else
    mavlink_wk_log_mission_t packet;
    packet.timestamp = timestamp;
    packet.seq = seq;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_MISSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_MISSION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_LOG_MISSION_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MISSION_LEN, MAVLINK_MSG_ID_WK_LOG_MISSION_CRC);
}

/**
 * @brief Pack a wk_log_mission message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  timestamp
 * @param seq  seq
 * @param latitude  latitude
 * @param longitude  longitude
 * @param altitude  altitude
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_mission_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,uint32_t seq,int32_t latitude,int32_t longitude,int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_MISSION_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, seq);
    _mav_put_int32_t(buf, 12, latitude);
    _mav_put_int32_t(buf, 16, longitude);
    _mav_put_int32_t(buf, 20, altitude);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_MISSION_LEN);
#else
    mavlink_wk_log_mission_t packet;
    packet.timestamp = timestamp;
    packet.seq = seq;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_MISSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_MISSION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_LOG_MISSION_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MISSION_LEN, MAVLINK_MSG_ID_WK_LOG_MISSION_CRC);
}

/**
 * @brief Encode a wk_log_mission struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_mission C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_mission_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_log_mission_t* wk_log_mission)
{
    return mavlink_msg_wk_log_mission_pack(system_id, component_id, msg, wk_log_mission->timestamp, wk_log_mission->seq, wk_log_mission->latitude, wk_log_mission->longitude, wk_log_mission->altitude);
}

/**
 * @brief Encode a wk_log_mission struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_mission C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_mission_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_log_mission_t* wk_log_mission)
{
    return mavlink_msg_wk_log_mission_pack_chan(system_id, component_id, chan, msg, wk_log_mission->timestamp, wk_log_mission->seq, wk_log_mission->latitude, wk_log_mission->longitude, wk_log_mission->altitude);
}

/**
 * @brief Send a wk_log_mission message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 * @param seq  seq
 * @param latitude  latitude
 * @param longitude  longitude
 * @param altitude  altitude
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_log_mission_send(mavlink_channel_t chan, uint64_t timestamp, uint32_t seq, int32_t latitude, int32_t longitude, int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_MISSION_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, seq);
    _mav_put_int32_t(buf, 12, latitude);
    _mav_put_int32_t(buf, 16, longitude);
    _mav_put_int32_t(buf, 20, altitude);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_MISSION, buf, MAVLINK_MSG_ID_WK_LOG_MISSION_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MISSION_LEN, MAVLINK_MSG_ID_WK_LOG_MISSION_CRC);
#else
    mavlink_wk_log_mission_t packet;
    packet.timestamp = timestamp;
    packet.seq = seq;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_MISSION, (const char *)&packet, MAVLINK_MSG_ID_WK_LOG_MISSION_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MISSION_LEN, MAVLINK_MSG_ID_WK_LOG_MISSION_CRC);
#endif
}

/**
 * @brief Send a wk_log_mission message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_log_mission_send_struct(mavlink_channel_t chan, const mavlink_wk_log_mission_t* wk_log_mission)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_log_mission_send(chan, wk_log_mission->timestamp, wk_log_mission->seq, wk_log_mission->latitude, wk_log_mission->longitude, wk_log_mission->altitude);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_MISSION, (const char *)wk_log_mission, MAVLINK_MSG_ID_WK_LOG_MISSION_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MISSION_LEN, MAVLINK_MSG_ID_WK_LOG_MISSION_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_LOG_MISSION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_log_mission_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, uint32_t seq, int32_t latitude, int32_t longitude, int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, seq);
    _mav_put_int32_t(buf, 12, latitude);
    _mav_put_int32_t(buf, 16, longitude);
    _mav_put_int32_t(buf, 20, altitude);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_MISSION, buf, MAVLINK_MSG_ID_WK_LOG_MISSION_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MISSION_LEN, MAVLINK_MSG_ID_WK_LOG_MISSION_CRC);
#else
    mavlink_wk_log_mission_t *packet = (mavlink_wk_log_mission_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->seq = seq;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->altitude = altitude;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_MISSION, (const char *)packet, MAVLINK_MSG_ID_WK_LOG_MISSION_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_MISSION_LEN, MAVLINK_MSG_ID_WK_LOG_MISSION_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_LOG_MISSION UNPACKING


/**
 * @brief Get field timestamp from wk_log_mission message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_wk_log_mission_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field seq from wk_log_mission message
 *
 * @return  seq
 */
static inline uint32_t mavlink_msg_wk_log_mission_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field latitude from wk_log_mission message
 *
 * @return  latitude
 */
static inline int32_t mavlink_msg_wk_log_mission_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field longitude from wk_log_mission message
 *
 * @return  longitude
 */
static inline int32_t mavlink_msg_wk_log_mission_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field altitude from wk_log_mission message
 *
 * @return  altitude
 */
static inline int32_t mavlink_msg_wk_log_mission_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Decode a wk_log_mission message into a struct
 *
 * @param msg The message to decode
 * @param wk_log_mission C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_log_mission_decode(const mavlink_message_t* msg, mavlink_wk_log_mission_t* wk_log_mission)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_log_mission->timestamp = mavlink_msg_wk_log_mission_get_timestamp(msg);
    wk_log_mission->seq = mavlink_msg_wk_log_mission_get_seq(msg);
    wk_log_mission->latitude = mavlink_msg_wk_log_mission_get_latitude(msg);
    wk_log_mission->longitude = mavlink_msg_wk_log_mission_get_longitude(msg);
    wk_log_mission->altitude = mavlink_msg_wk_log_mission_get_altitude(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_LOG_MISSION_LEN? msg->len : MAVLINK_MSG_ID_WK_LOG_MISSION_LEN;
        memset(wk_log_mission, 0, MAVLINK_MSG_ID_WK_LOG_MISSION_LEN);
    memcpy(wk_log_mission, _MAV_PAYLOAD(msg), len);
#endif
}
