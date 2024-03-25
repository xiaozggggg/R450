#pragma once
// MESSAGE WK_LOG_BEACON PACKING

#define MAVLINK_MSG_ID_WK_LOG_BEACON 8504


typedef struct __mavlink_wk_log_beacon_t {
 uint64_t timestamp; /*<  timestamp*/
 int32_t latitude; /*<  latitude*/
 int32_t longitude; /*<  longitude*/
 int32_t alt; /*<  alt*/
 float velx; /*<  velx*/
 float vely; /*<  vely*/
 float velz; /*<  velz*/
 float yaw; /*<  yaw*/
 float distance; /*<  distance*/
 uint8_t numsv; /*<  numsv*/
 uint8_t fixtype; /*<  fixtype*/
} mavlink_wk_log_beacon_t;

#define MAVLINK_MSG_ID_WK_LOG_BEACON_LEN 42
#define MAVLINK_MSG_ID_WK_LOG_BEACON_MIN_LEN 42
#define MAVLINK_MSG_ID_8504_LEN 42
#define MAVLINK_MSG_ID_8504_MIN_LEN 42

#define MAVLINK_MSG_ID_WK_LOG_BEACON_CRC 114
#define MAVLINK_MSG_ID_8504_CRC 114



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_LOG_BEACON { \
    8504, \
    "WK_LOG_BEACON", \
    11, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_beacon_t, timestamp) }, \
         { "numsv", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_wk_log_beacon_t, numsv) }, \
         { "fixtype", NULL, MAVLINK_TYPE_UINT8_T, 0, 41, offsetof(mavlink_wk_log_beacon_t, fixtype) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_log_beacon_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_log_beacon_t, longitude) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_wk_log_beacon_t, alt) }, \
         { "velx", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_log_beacon_t, velx) }, \
         { "vely", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wk_log_beacon_t, vely) }, \
         { "velz", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wk_log_beacon_t, velz) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wk_log_beacon_t, yaw) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wk_log_beacon_t, distance) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_LOG_BEACON { \
    "WK_LOG_BEACON", \
    11, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_beacon_t, timestamp) }, \
         { "numsv", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_wk_log_beacon_t, numsv) }, \
         { "fixtype", NULL, MAVLINK_TYPE_UINT8_T, 0, 41, offsetof(mavlink_wk_log_beacon_t, fixtype) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_log_beacon_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_log_beacon_t, longitude) }, \
         { "alt", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_wk_log_beacon_t, alt) }, \
         { "velx", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_log_beacon_t, velx) }, \
         { "vely", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wk_log_beacon_t, vely) }, \
         { "velz", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wk_log_beacon_t, velz) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wk_log_beacon_t, yaw) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wk_log_beacon_t, distance) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_log_beacon message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  timestamp
 * @param numsv  numsv
 * @param fixtype  fixtype
 * @param latitude  latitude
 * @param longitude  longitude
 * @param alt  alt
 * @param velx  velx
 * @param vely  vely
 * @param velz  velz
 * @param yaw  yaw
 * @param distance  distance
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_beacon_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint8_t numsv, uint8_t fixtype, int32_t latitude, int32_t longitude, int32_t alt, float velx, float vely, float velz, float yaw, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_BEACON_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, alt);
    _mav_put_float(buf, 20, velx);
    _mav_put_float(buf, 24, vely);
    _mav_put_float(buf, 28, velz);
    _mav_put_float(buf, 32, yaw);
    _mav_put_float(buf, 36, distance);
    _mav_put_uint8_t(buf, 40, numsv);
    _mav_put_uint8_t(buf, 41, fixtype);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_BEACON_LEN);
#else
    mavlink_wk_log_beacon_t packet;
    packet.timestamp = timestamp;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.alt = alt;
    packet.velx = velx;
    packet.vely = vely;
    packet.velz = velz;
    packet.yaw = yaw;
    packet.distance = distance;
    packet.numsv = numsv;
    packet.fixtype = fixtype;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_BEACON_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_BEACON;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_LOG_BEACON_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_BEACON_LEN, MAVLINK_MSG_ID_WK_LOG_BEACON_CRC);
}

/**
 * @brief Pack a wk_log_beacon message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  timestamp
 * @param numsv  numsv
 * @param fixtype  fixtype
 * @param latitude  latitude
 * @param longitude  longitude
 * @param alt  alt
 * @param velx  velx
 * @param vely  vely
 * @param velz  velz
 * @param yaw  yaw
 * @param distance  distance
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_beacon_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,uint8_t numsv,uint8_t fixtype,int32_t latitude,int32_t longitude,int32_t alt,float velx,float vely,float velz,float yaw,float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_BEACON_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, alt);
    _mav_put_float(buf, 20, velx);
    _mav_put_float(buf, 24, vely);
    _mav_put_float(buf, 28, velz);
    _mav_put_float(buf, 32, yaw);
    _mav_put_float(buf, 36, distance);
    _mav_put_uint8_t(buf, 40, numsv);
    _mav_put_uint8_t(buf, 41, fixtype);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_BEACON_LEN);
#else
    mavlink_wk_log_beacon_t packet;
    packet.timestamp = timestamp;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.alt = alt;
    packet.velx = velx;
    packet.vely = vely;
    packet.velz = velz;
    packet.yaw = yaw;
    packet.distance = distance;
    packet.numsv = numsv;
    packet.fixtype = fixtype;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_BEACON_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_BEACON;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_LOG_BEACON_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_BEACON_LEN, MAVLINK_MSG_ID_WK_LOG_BEACON_CRC);
}

/**
 * @brief Encode a wk_log_beacon struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_beacon C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_beacon_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_log_beacon_t* wk_log_beacon)
{
    return mavlink_msg_wk_log_beacon_pack(system_id, component_id, msg, wk_log_beacon->timestamp, wk_log_beacon->numsv, wk_log_beacon->fixtype, wk_log_beacon->latitude, wk_log_beacon->longitude, wk_log_beacon->alt, wk_log_beacon->velx, wk_log_beacon->vely, wk_log_beacon->velz, wk_log_beacon->yaw, wk_log_beacon->distance);
}

/**
 * @brief Encode a wk_log_beacon struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_beacon C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_beacon_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_log_beacon_t* wk_log_beacon)
{
    return mavlink_msg_wk_log_beacon_pack_chan(system_id, component_id, chan, msg, wk_log_beacon->timestamp, wk_log_beacon->numsv, wk_log_beacon->fixtype, wk_log_beacon->latitude, wk_log_beacon->longitude, wk_log_beacon->alt, wk_log_beacon->velx, wk_log_beacon->vely, wk_log_beacon->velz, wk_log_beacon->yaw, wk_log_beacon->distance);
}

/**
 * @brief Send a wk_log_beacon message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 * @param numsv  numsv
 * @param fixtype  fixtype
 * @param latitude  latitude
 * @param longitude  longitude
 * @param alt  alt
 * @param velx  velx
 * @param vely  vely
 * @param velz  velz
 * @param yaw  yaw
 * @param distance  distance
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_log_beacon_send(mavlink_channel_t chan, uint64_t timestamp, uint8_t numsv, uint8_t fixtype, int32_t latitude, int32_t longitude, int32_t alt, float velx, float vely, float velz, float yaw, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_BEACON_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, alt);
    _mav_put_float(buf, 20, velx);
    _mav_put_float(buf, 24, vely);
    _mav_put_float(buf, 28, velz);
    _mav_put_float(buf, 32, yaw);
    _mav_put_float(buf, 36, distance);
    _mav_put_uint8_t(buf, 40, numsv);
    _mav_put_uint8_t(buf, 41, fixtype);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_BEACON, buf, MAVLINK_MSG_ID_WK_LOG_BEACON_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_BEACON_LEN, MAVLINK_MSG_ID_WK_LOG_BEACON_CRC);
#else
    mavlink_wk_log_beacon_t packet;
    packet.timestamp = timestamp;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.alt = alt;
    packet.velx = velx;
    packet.vely = vely;
    packet.velz = velz;
    packet.yaw = yaw;
    packet.distance = distance;
    packet.numsv = numsv;
    packet.fixtype = fixtype;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_BEACON, (const char *)&packet, MAVLINK_MSG_ID_WK_LOG_BEACON_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_BEACON_LEN, MAVLINK_MSG_ID_WK_LOG_BEACON_CRC);
#endif
}

/**
 * @brief Send a wk_log_beacon message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_log_beacon_send_struct(mavlink_channel_t chan, const mavlink_wk_log_beacon_t* wk_log_beacon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_log_beacon_send(chan, wk_log_beacon->timestamp, wk_log_beacon->numsv, wk_log_beacon->fixtype, wk_log_beacon->latitude, wk_log_beacon->longitude, wk_log_beacon->alt, wk_log_beacon->velx, wk_log_beacon->vely, wk_log_beacon->velz, wk_log_beacon->yaw, wk_log_beacon->distance);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_BEACON, (const char *)wk_log_beacon, MAVLINK_MSG_ID_WK_LOG_BEACON_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_BEACON_LEN, MAVLINK_MSG_ID_WK_LOG_BEACON_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_LOG_BEACON_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_log_beacon_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, uint8_t numsv, uint8_t fixtype, int32_t latitude, int32_t longitude, int32_t alt, float velx, float vely, float velz, float yaw, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, alt);
    _mav_put_float(buf, 20, velx);
    _mav_put_float(buf, 24, vely);
    _mav_put_float(buf, 28, velz);
    _mav_put_float(buf, 32, yaw);
    _mav_put_float(buf, 36, distance);
    _mav_put_uint8_t(buf, 40, numsv);
    _mav_put_uint8_t(buf, 41, fixtype);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_BEACON, buf, MAVLINK_MSG_ID_WK_LOG_BEACON_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_BEACON_LEN, MAVLINK_MSG_ID_WK_LOG_BEACON_CRC);
#else
    mavlink_wk_log_beacon_t *packet = (mavlink_wk_log_beacon_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->alt = alt;
    packet->velx = velx;
    packet->vely = vely;
    packet->velz = velz;
    packet->yaw = yaw;
    packet->distance = distance;
    packet->numsv = numsv;
    packet->fixtype = fixtype;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_BEACON, (const char *)packet, MAVLINK_MSG_ID_WK_LOG_BEACON_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_BEACON_LEN, MAVLINK_MSG_ID_WK_LOG_BEACON_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_LOG_BEACON UNPACKING


/**
 * @brief Get field timestamp from wk_log_beacon message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_wk_log_beacon_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field numsv from wk_log_beacon message
 *
 * @return  numsv
 */
static inline uint8_t mavlink_msg_wk_log_beacon_get_numsv(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  40);
}

/**
 * @brief Get field fixtype from wk_log_beacon message
 *
 * @return  fixtype
 */
static inline uint8_t mavlink_msg_wk_log_beacon_get_fixtype(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  41);
}

/**
 * @brief Get field latitude from wk_log_beacon message
 *
 * @return  latitude
 */
static inline int32_t mavlink_msg_wk_log_beacon_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field longitude from wk_log_beacon message
 *
 * @return  longitude
 */
static inline int32_t mavlink_msg_wk_log_beacon_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field alt from wk_log_beacon message
 *
 * @return  alt
 */
static inline int32_t mavlink_msg_wk_log_beacon_get_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field velx from wk_log_beacon message
 *
 * @return  velx
 */
static inline float mavlink_msg_wk_log_beacon_get_velx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field vely from wk_log_beacon message
 *
 * @return  vely
 */
static inline float mavlink_msg_wk_log_beacon_get_vely(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field velz from wk_log_beacon message
 *
 * @return  velz
 */
static inline float mavlink_msg_wk_log_beacon_get_velz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field yaw from wk_log_beacon message
 *
 * @return  yaw
 */
static inline float mavlink_msg_wk_log_beacon_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field distance from wk_log_beacon message
 *
 * @return  distance
 */
static inline float mavlink_msg_wk_log_beacon_get_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Decode a wk_log_beacon message into a struct
 *
 * @param msg The message to decode
 * @param wk_log_beacon C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_log_beacon_decode(const mavlink_message_t* msg, mavlink_wk_log_beacon_t* wk_log_beacon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_log_beacon->timestamp = mavlink_msg_wk_log_beacon_get_timestamp(msg);
    wk_log_beacon->latitude = mavlink_msg_wk_log_beacon_get_latitude(msg);
    wk_log_beacon->longitude = mavlink_msg_wk_log_beacon_get_longitude(msg);
    wk_log_beacon->alt = mavlink_msg_wk_log_beacon_get_alt(msg);
    wk_log_beacon->velx = mavlink_msg_wk_log_beacon_get_velx(msg);
    wk_log_beacon->vely = mavlink_msg_wk_log_beacon_get_vely(msg);
    wk_log_beacon->velz = mavlink_msg_wk_log_beacon_get_velz(msg);
    wk_log_beacon->yaw = mavlink_msg_wk_log_beacon_get_yaw(msg);
    wk_log_beacon->distance = mavlink_msg_wk_log_beacon_get_distance(msg);
    wk_log_beacon->numsv = mavlink_msg_wk_log_beacon_get_numsv(msg);
    wk_log_beacon->fixtype = mavlink_msg_wk_log_beacon_get_fixtype(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_LOG_BEACON_LEN? msg->len : MAVLINK_MSG_ID_WK_LOG_BEACON_LEN;
        memset(wk_log_beacon, 0, MAVLINK_MSG_ID_WK_LOG_BEACON_LEN);
    memcpy(wk_log_beacon, _MAV_PAYLOAD(msg), len);
#endif
}
