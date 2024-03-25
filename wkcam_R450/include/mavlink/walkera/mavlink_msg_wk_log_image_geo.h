#pragma once
// MESSAGE WK_LOG_IMAGE_GEO PACKING

#define MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO 8511


typedef struct __mavlink_wk_log_image_geo_t {
 uint64_t timestamp; /*<  timestamp*/
 int32_t index; /*<  index*/
 int32_t latitude; /*<  latitude*/
 int32_t longitude; /*<  longitude*/
 int32_t altitude; /*<  altitude*/
 int32_t roll; /*<  roll*/
 int32_t pitch; /*<  pitch*/
 int32_t yaw; /*<  yaw*/
} mavlink_wk_log_image_geo_t;

#define MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN 36
#define MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_MIN_LEN 36
#define MAVLINK_MSG_ID_8511_LEN 36
#define MAVLINK_MSG_ID_8511_MIN_LEN 36

#define MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_CRC 48
#define MAVLINK_MSG_ID_8511_CRC 48



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_LOG_IMAGE_GEO { \
    8511, \
    "WK_LOG_IMAGE_GEO", \
    8, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_image_geo_t, timestamp) }, \
         { "index", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_log_image_geo_t, index) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_log_image_geo_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_wk_log_image_geo_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_wk_log_image_geo_t, altitude) }, \
         { "roll", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_wk_log_image_geo_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_wk_log_image_geo_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT32_T, 0, 32, offsetof(mavlink_wk_log_image_geo_t, yaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_LOG_IMAGE_GEO { \
    "WK_LOG_IMAGE_GEO", \
    8, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_image_geo_t, timestamp) }, \
         { "index", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_log_image_geo_t, index) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_log_image_geo_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_wk_log_image_geo_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_wk_log_image_geo_t, altitude) }, \
         { "roll", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_wk_log_image_geo_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_wk_log_image_geo_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT32_T, 0, 32, offsetof(mavlink_wk_log_image_geo_t, yaw) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_log_image_geo message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  timestamp
 * @param index  index
 * @param latitude  latitude
 * @param longitude  longitude
 * @param altitude  altitude
 * @param roll  roll
 * @param pitch  pitch
 * @param yaw  yaw
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_image_geo_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, int32_t index, int32_t latitude, int32_t longitude, int32_t altitude, int32_t roll, int32_t pitch, int32_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_int32_t(buf, 8, index);
    _mav_put_int32_t(buf, 12, latitude);
    _mav_put_int32_t(buf, 16, longitude);
    _mav_put_int32_t(buf, 20, altitude);
    _mav_put_int32_t(buf, 24, roll);
    _mav_put_int32_t(buf, 28, pitch);
    _mav_put_int32_t(buf, 32, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN);
#else
    mavlink_wk_log_image_geo_t packet;
    packet.timestamp = timestamp;
    packet.index = index;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_CRC);
}

/**
 * @brief Pack a wk_log_image_geo message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  timestamp
 * @param index  index
 * @param latitude  latitude
 * @param longitude  longitude
 * @param altitude  altitude
 * @param roll  roll
 * @param pitch  pitch
 * @param yaw  yaw
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_image_geo_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,int32_t index,int32_t latitude,int32_t longitude,int32_t altitude,int32_t roll,int32_t pitch,int32_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_int32_t(buf, 8, index);
    _mav_put_int32_t(buf, 12, latitude);
    _mav_put_int32_t(buf, 16, longitude);
    _mav_put_int32_t(buf, 20, altitude);
    _mav_put_int32_t(buf, 24, roll);
    _mav_put_int32_t(buf, 28, pitch);
    _mav_put_int32_t(buf, 32, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN);
#else
    mavlink_wk_log_image_geo_t packet;
    packet.timestamp = timestamp;
    packet.index = index;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_CRC);
}

/**
 * @brief Encode a wk_log_image_geo struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_image_geo C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_image_geo_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_log_image_geo_t* wk_log_image_geo)
{
    return mavlink_msg_wk_log_image_geo_pack(system_id, component_id, msg, wk_log_image_geo->timestamp, wk_log_image_geo->index, wk_log_image_geo->latitude, wk_log_image_geo->longitude, wk_log_image_geo->altitude, wk_log_image_geo->roll, wk_log_image_geo->pitch, wk_log_image_geo->yaw);
}

/**
 * @brief Encode a wk_log_image_geo struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_image_geo C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_image_geo_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_log_image_geo_t* wk_log_image_geo)
{
    return mavlink_msg_wk_log_image_geo_pack_chan(system_id, component_id, chan, msg, wk_log_image_geo->timestamp, wk_log_image_geo->index, wk_log_image_geo->latitude, wk_log_image_geo->longitude, wk_log_image_geo->altitude, wk_log_image_geo->roll, wk_log_image_geo->pitch, wk_log_image_geo->yaw);
}

/**
 * @brief Send a wk_log_image_geo message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 * @param index  index
 * @param latitude  latitude
 * @param longitude  longitude
 * @param altitude  altitude
 * @param roll  roll
 * @param pitch  pitch
 * @param yaw  yaw
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_log_image_geo_send(mavlink_channel_t chan, uint64_t timestamp, int32_t index, int32_t latitude, int32_t longitude, int32_t altitude, int32_t roll, int32_t pitch, int32_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_int32_t(buf, 8, index);
    _mav_put_int32_t(buf, 12, latitude);
    _mav_put_int32_t(buf, 16, longitude);
    _mav_put_int32_t(buf, 20, altitude);
    _mav_put_int32_t(buf, 24, roll);
    _mav_put_int32_t(buf, 28, pitch);
    _mav_put_int32_t(buf, 32, yaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO, buf, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_CRC);
#else
    mavlink_wk_log_image_geo_t packet;
    packet.timestamp = timestamp;
    packet.index = index;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO, (const char *)&packet, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_CRC);
#endif
}

/**
 * @brief Send a wk_log_image_geo message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_log_image_geo_send_struct(mavlink_channel_t chan, const mavlink_wk_log_image_geo_t* wk_log_image_geo)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_log_image_geo_send(chan, wk_log_image_geo->timestamp, wk_log_image_geo->index, wk_log_image_geo->latitude, wk_log_image_geo->longitude, wk_log_image_geo->altitude, wk_log_image_geo->roll, wk_log_image_geo->pitch, wk_log_image_geo->yaw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO, (const char *)wk_log_image_geo, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_log_image_geo_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, int32_t index, int32_t latitude, int32_t longitude, int32_t altitude, int32_t roll, int32_t pitch, int32_t yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_int32_t(buf, 8, index);
    _mav_put_int32_t(buf, 12, latitude);
    _mav_put_int32_t(buf, 16, longitude);
    _mav_put_int32_t(buf, 20, altitude);
    _mav_put_int32_t(buf, 24, roll);
    _mav_put_int32_t(buf, 28, pitch);
    _mav_put_int32_t(buf, 32, yaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO, buf, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_CRC);
#else
    mavlink_wk_log_image_geo_t *packet = (mavlink_wk_log_image_geo_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->index = index;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->altitude = altitude;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->yaw = yaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO, (const char *)packet, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_LOG_IMAGE_GEO UNPACKING


/**
 * @brief Get field timestamp from wk_log_image_geo message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_wk_log_image_geo_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field index from wk_log_image_geo message
 *
 * @return  index
 */
static inline int32_t mavlink_msg_wk_log_image_geo_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field latitude from wk_log_image_geo message
 *
 * @return  latitude
 */
static inline int32_t mavlink_msg_wk_log_image_geo_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field longitude from wk_log_image_geo message
 *
 * @return  longitude
 */
static inline int32_t mavlink_msg_wk_log_image_geo_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field altitude from wk_log_image_geo message
 *
 * @return  altitude
 */
static inline int32_t mavlink_msg_wk_log_image_geo_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field roll from wk_log_image_geo message
 *
 * @return  roll
 */
static inline int32_t mavlink_msg_wk_log_image_geo_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field pitch from wk_log_image_geo message
 *
 * @return  pitch
 */
static inline int32_t mavlink_msg_wk_log_image_geo_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field yaw from wk_log_image_geo message
 *
 * @return  yaw
 */
static inline int32_t mavlink_msg_wk_log_image_geo_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  32);
}

/**
 * @brief Decode a wk_log_image_geo message into a struct
 *
 * @param msg The message to decode
 * @param wk_log_image_geo C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_log_image_geo_decode(const mavlink_message_t* msg, mavlink_wk_log_image_geo_t* wk_log_image_geo)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_log_image_geo->timestamp = mavlink_msg_wk_log_image_geo_get_timestamp(msg);
    wk_log_image_geo->index = mavlink_msg_wk_log_image_geo_get_index(msg);
    wk_log_image_geo->latitude = mavlink_msg_wk_log_image_geo_get_latitude(msg);
    wk_log_image_geo->longitude = mavlink_msg_wk_log_image_geo_get_longitude(msg);
    wk_log_image_geo->altitude = mavlink_msg_wk_log_image_geo_get_altitude(msg);
    wk_log_image_geo->roll = mavlink_msg_wk_log_image_geo_get_roll(msg);
    wk_log_image_geo->pitch = mavlink_msg_wk_log_image_geo_get_pitch(msg);
    wk_log_image_geo->yaw = mavlink_msg_wk_log_image_geo_get_yaw(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN? msg->len : MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN;
        memset(wk_log_image_geo, 0, MAVLINK_MSG_ID_WK_LOG_IMAGE_GEO_LEN);
    memcpy(wk_log_image_geo, _MAV_PAYLOAD(msg), len);
#endif
}
