#pragma once
// MESSAGE WK_LOG_GPS_RAW PACKING

#define MAVLINK_MSG_ID_WK_LOG_GPS_RAW 8502


typedef struct __mavlink_wk_log_gps_raw_t {
 uint64_t timestamp; /*<  timestamp*/
 int32_t latitude; /*<  latitude*/
 int32_t longitude; /*<  longitude*/
 int32_t altitude; /*<  altitude*/
 int32_t vel_n; /*<  vel_n*/
 int32_t vel_e; /*<  vel_e*/
 int32_t vel_d; /*<  vel_d*/
 int16_t heading; /*<  heading*/
 int16_t hAcc; /*<  hAcc*/
 int16_t vAcc; /*<  vAcc*/
 int16_t sAcc; /*<  sAcc*/
 int16_t cAcc; /*<  cAcc*/
 uint8_t fix_type; /*<  fix_type*/
 uint8_t numSv; /*<  numSv*/
} mavlink_wk_log_gps_raw_t;

#define MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN 44
#define MAVLINK_MSG_ID_WK_LOG_GPS_RAW_MIN_LEN 44
#define MAVLINK_MSG_ID_8502_LEN 44
#define MAVLINK_MSG_ID_8502_MIN_LEN 44

#define MAVLINK_MSG_ID_WK_LOG_GPS_RAW_CRC 122
#define MAVLINK_MSG_ID_8502_CRC 122



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_LOG_GPS_RAW { \
    8502, \
    "WK_LOG_GPS_RAW", \
    14, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_gps_raw_t, timestamp) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_log_gps_raw_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_log_gps_raw_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_wk_log_gps_raw_t, altitude) }, \
         { "vel_n", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_wk_log_gps_raw_t, vel_n) }, \
         { "vel_e", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_wk_log_gps_raw_t, vel_e) }, \
         { "vel_d", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_wk_log_gps_raw_t, vel_d) }, \
         { "heading", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_wk_log_gps_raw_t, heading) }, \
         { "hAcc", NULL, MAVLINK_TYPE_INT16_T, 0, 34, offsetof(mavlink_wk_log_gps_raw_t, hAcc) }, \
         { "vAcc", NULL, MAVLINK_TYPE_INT16_T, 0, 36, offsetof(mavlink_wk_log_gps_raw_t, vAcc) }, \
         { "sAcc", NULL, MAVLINK_TYPE_INT16_T, 0, 38, offsetof(mavlink_wk_log_gps_raw_t, sAcc) }, \
         { "cAcc", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_wk_log_gps_raw_t, cAcc) }, \
         { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_wk_log_gps_raw_t, fix_type) }, \
         { "numSv", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_wk_log_gps_raw_t, numSv) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_LOG_GPS_RAW { \
    "WK_LOG_GPS_RAW", \
    14, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_gps_raw_t, timestamp) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_log_gps_raw_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_log_gps_raw_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_wk_log_gps_raw_t, altitude) }, \
         { "vel_n", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_wk_log_gps_raw_t, vel_n) }, \
         { "vel_e", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_wk_log_gps_raw_t, vel_e) }, \
         { "vel_d", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_wk_log_gps_raw_t, vel_d) }, \
         { "heading", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_wk_log_gps_raw_t, heading) }, \
         { "hAcc", NULL, MAVLINK_TYPE_INT16_T, 0, 34, offsetof(mavlink_wk_log_gps_raw_t, hAcc) }, \
         { "vAcc", NULL, MAVLINK_TYPE_INT16_T, 0, 36, offsetof(mavlink_wk_log_gps_raw_t, vAcc) }, \
         { "sAcc", NULL, MAVLINK_TYPE_INT16_T, 0, 38, offsetof(mavlink_wk_log_gps_raw_t, sAcc) }, \
         { "cAcc", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_wk_log_gps_raw_t, cAcc) }, \
         { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 42, offsetof(mavlink_wk_log_gps_raw_t, fix_type) }, \
         { "numSv", NULL, MAVLINK_TYPE_UINT8_T, 0, 43, offsetof(mavlink_wk_log_gps_raw_t, numSv) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_log_gps_raw message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  timestamp
 * @param latitude  latitude
 * @param longitude  longitude
 * @param altitude  altitude
 * @param vel_n  vel_n
 * @param vel_e  vel_e
 * @param vel_d  vel_d
 * @param heading  heading
 * @param hAcc  hAcc
 * @param vAcc  vAcc
 * @param sAcc  sAcc
 * @param cAcc  cAcc
 * @param fix_type  fix_type
 * @param numSv  numSv
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_gps_raw_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, int32_t latitude, int32_t longitude, int32_t altitude, int32_t vel_n, int32_t vel_e, int32_t vel_d, int16_t heading, int16_t hAcc, int16_t vAcc, int16_t sAcc, int16_t cAcc, uint8_t fix_type, uint8_t numSv)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, altitude);
    _mav_put_int32_t(buf, 20, vel_n);
    _mav_put_int32_t(buf, 24, vel_e);
    _mav_put_int32_t(buf, 28, vel_d);
    _mav_put_int16_t(buf, 32, heading);
    _mav_put_int16_t(buf, 34, hAcc);
    _mav_put_int16_t(buf, 36, vAcc);
    _mav_put_int16_t(buf, 38, sAcc);
    _mav_put_int16_t(buf, 40, cAcc);
    _mav_put_uint8_t(buf, 42, fix_type);
    _mav_put_uint8_t(buf, 43, numSv);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN);
#else
    mavlink_wk_log_gps_raw_t packet;
    packet.timestamp = timestamp;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.vel_n = vel_n;
    packet.vel_e = vel_e;
    packet.vel_d = vel_d;
    packet.heading = heading;
    packet.hAcc = hAcc;
    packet.vAcc = vAcc;
    packet.sAcc = sAcc;
    packet.cAcc = cAcc;
    packet.fix_type = fix_type;
    packet.numSv = numSv;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_GPS_RAW;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_CRC);
}

/**
 * @brief Pack a wk_log_gps_raw message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  timestamp
 * @param latitude  latitude
 * @param longitude  longitude
 * @param altitude  altitude
 * @param vel_n  vel_n
 * @param vel_e  vel_e
 * @param vel_d  vel_d
 * @param heading  heading
 * @param hAcc  hAcc
 * @param vAcc  vAcc
 * @param sAcc  sAcc
 * @param cAcc  cAcc
 * @param fix_type  fix_type
 * @param numSv  numSv
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_gps_raw_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,int32_t latitude,int32_t longitude,int32_t altitude,int32_t vel_n,int32_t vel_e,int32_t vel_d,int16_t heading,int16_t hAcc,int16_t vAcc,int16_t sAcc,int16_t cAcc,uint8_t fix_type,uint8_t numSv)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, altitude);
    _mav_put_int32_t(buf, 20, vel_n);
    _mav_put_int32_t(buf, 24, vel_e);
    _mav_put_int32_t(buf, 28, vel_d);
    _mav_put_int16_t(buf, 32, heading);
    _mav_put_int16_t(buf, 34, hAcc);
    _mav_put_int16_t(buf, 36, vAcc);
    _mav_put_int16_t(buf, 38, sAcc);
    _mav_put_int16_t(buf, 40, cAcc);
    _mav_put_uint8_t(buf, 42, fix_type);
    _mav_put_uint8_t(buf, 43, numSv);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN);
#else
    mavlink_wk_log_gps_raw_t packet;
    packet.timestamp = timestamp;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.vel_n = vel_n;
    packet.vel_e = vel_e;
    packet.vel_d = vel_d;
    packet.heading = heading;
    packet.hAcc = hAcc;
    packet.vAcc = vAcc;
    packet.sAcc = sAcc;
    packet.cAcc = cAcc;
    packet.fix_type = fix_type;
    packet.numSv = numSv;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_GPS_RAW;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_CRC);
}

/**
 * @brief Encode a wk_log_gps_raw struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_gps_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_gps_raw_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_log_gps_raw_t* wk_log_gps_raw)
{
    return mavlink_msg_wk_log_gps_raw_pack(system_id, component_id, msg, wk_log_gps_raw->timestamp, wk_log_gps_raw->latitude, wk_log_gps_raw->longitude, wk_log_gps_raw->altitude, wk_log_gps_raw->vel_n, wk_log_gps_raw->vel_e, wk_log_gps_raw->vel_d, wk_log_gps_raw->heading, wk_log_gps_raw->hAcc, wk_log_gps_raw->vAcc, wk_log_gps_raw->sAcc, wk_log_gps_raw->cAcc, wk_log_gps_raw->fix_type, wk_log_gps_raw->numSv);
}

/**
 * @brief Encode a wk_log_gps_raw struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_gps_raw C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_gps_raw_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_log_gps_raw_t* wk_log_gps_raw)
{
    return mavlink_msg_wk_log_gps_raw_pack_chan(system_id, component_id, chan, msg, wk_log_gps_raw->timestamp, wk_log_gps_raw->latitude, wk_log_gps_raw->longitude, wk_log_gps_raw->altitude, wk_log_gps_raw->vel_n, wk_log_gps_raw->vel_e, wk_log_gps_raw->vel_d, wk_log_gps_raw->heading, wk_log_gps_raw->hAcc, wk_log_gps_raw->vAcc, wk_log_gps_raw->sAcc, wk_log_gps_raw->cAcc, wk_log_gps_raw->fix_type, wk_log_gps_raw->numSv);
}

/**
 * @brief Send a wk_log_gps_raw message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 * @param latitude  latitude
 * @param longitude  longitude
 * @param altitude  altitude
 * @param vel_n  vel_n
 * @param vel_e  vel_e
 * @param vel_d  vel_d
 * @param heading  heading
 * @param hAcc  hAcc
 * @param vAcc  vAcc
 * @param sAcc  sAcc
 * @param cAcc  cAcc
 * @param fix_type  fix_type
 * @param numSv  numSv
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_log_gps_raw_send(mavlink_channel_t chan, uint64_t timestamp, int32_t latitude, int32_t longitude, int32_t altitude, int32_t vel_n, int32_t vel_e, int32_t vel_d, int16_t heading, int16_t hAcc, int16_t vAcc, int16_t sAcc, int16_t cAcc, uint8_t fix_type, uint8_t numSv)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, altitude);
    _mav_put_int32_t(buf, 20, vel_n);
    _mav_put_int32_t(buf, 24, vel_e);
    _mav_put_int32_t(buf, 28, vel_d);
    _mav_put_int16_t(buf, 32, heading);
    _mav_put_int16_t(buf, 34, hAcc);
    _mav_put_int16_t(buf, 36, vAcc);
    _mav_put_int16_t(buf, 38, sAcc);
    _mav_put_int16_t(buf, 40, cAcc);
    _mav_put_uint8_t(buf, 42, fix_type);
    _mav_put_uint8_t(buf, 43, numSv);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_GPS_RAW, buf, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_CRC);
#else
    mavlink_wk_log_gps_raw_t packet;
    packet.timestamp = timestamp;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.vel_n = vel_n;
    packet.vel_e = vel_e;
    packet.vel_d = vel_d;
    packet.heading = heading;
    packet.hAcc = hAcc;
    packet.vAcc = vAcc;
    packet.sAcc = sAcc;
    packet.cAcc = cAcc;
    packet.fix_type = fix_type;
    packet.numSv = numSv;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_GPS_RAW, (const char *)&packet, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_CRC);
#endif
}

/**
 * @brief Send a wk_log_gps_raw message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_log_gps_raw_send_struct(mavlink_channel_t chan, const mavlink_wk_log_gps_raw_t* wk_log_gps_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_log_gps_raw_send(chan, wk_log_gps_raw->timestamp, wk_log_gps_raw->latitude, wk_log_gps_raw->longitude, wk_log_gps_raw->altitude, wk_log_gps_raw->vel_n, wk_log_gps_raw->vel_e, wk_log_gps_raw->vel_d, wk_log_gps_raw->heading, wk_log_gps_raw->hAcc, wk_log_gps_raw->vAcc, wk_log_gps_raw->sAcc, wk_log_gps_raw->cAcc, wk_log_gps_raw->fix_type, wk_log_gps_raw->numSv);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_GPS_RAW, (const char *)wk_log_gps_raw, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_log_gps_raw_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, int32_t latitude, int32_t longitude, int32_t altitude, int32_t vel_n, int32_t vel_e, int32_t vel_d, int16_t heading, int16_t hAcc, int16_t vAcc, int16_t sAcc, int16_t cAcc, uint8_t fix_type, uint8_t numSv)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, altitude);
    _mav_put_int32_t(buf, 20, vel_n);
    _mav_put_int32_t(buf, 24, vel_e);
    _mav_put_int32_t(buf, 28, vel_d);
    _mav_put_int16_t(buf, 32, heading);
    _mav_put_int16_t(buf, 34, hAcc);
    _mav_put_int16_t(buf, 36, vAcc);
    _mav_put_int16_t(buf, 38, sAcc);
    _mav_put_int16_t(buf, 40, cAcc);
    _mav_put_uint8_t(buf, 42, fix_type);
    _mav_put_uint8_t(buf, 43, numSv);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_GPS_RAW, buf, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_CRC);
#else
    mavlink_wk_log_gps_raw_t *packet = (mavlink_wk_log_gps_raw_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->altitude = altitude;
    packet->vel_n = vel_n;
    packet->vel_e = vel_e;
    packet->vel_d = vel_d;
    packet->heading = heading;
    packet->hAcc = hAcc;
    packet->vAcc = vAcc;
    packet->sAcc = sAcc;
    packet->cAcc = cAcc;
    packet->fix_type = fix_type;
    packet->numSv = numSv;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_GPS_RAW, (const char *)packet, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_LOG_GPS_RAW UNPACKING


/**
 * @brief Get field timestamp from wk_log_gps_raw message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_wk_log_gps_raw_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field latitude from wk_log_gps_raw message
 *
 * @return  latitude
 */
static inline int32_t mavlink_msg_wk_log_gps_raw_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field longitude from wk_log_gps_raw message
 *
 * @return  longitude
 */
static inline int32_t mavlink_msg_wk_log_gps_raw_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field altitude from wk_log_gps_raw message
 *
 * @return  altitude
 */
static inline int32_t mavlink_msg_wk_log_gps_raw_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field vel_n from wk_log_gps_raw message
 *
 * @return  vel_n
 */
static inline int32_t mavlink_msg_wk_log_gps_raw_get_vel_n(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field vel_e from wk_log_gps_raw message
 *
 * @return  vel_e
 */
static inline int32_t mavlink_msg_wk_log_gps_raw_get_vel_e(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field vel_d from wk_log_gps_raw message
 *
 * @return  vel_d
 */
static inline int32_t mavlink_msg_wk_log_gps_raw_get_vel_d(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field heading from wk_log_gps_raw message
 *
 * @return  heading
 */
static inline int16_t mavlink_msg_wk_log_gps_raw_get_heading(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  32);
}

/**
 * @brief Get field hAcc from wk_log_gps_raw message
 *
 * @return  hAcc
 */
static inline int16_t mavlink_msg_wk_log_gps_raw_get_hAcc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  34);
}

/**
 * @brief Get field vAcc from wk_log_gps_raw message
 *
 * @return  vAcc
 */
static inline int16_t mavlink_msg_wk_log_gps_raw_get_vAcc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  36);
}

/**
 * @brief Get field sAcc from wk_log_gps_raw message
 *
 * @return  sAcc
 */
static inline int16_t mavlink_msg_wk_log_gps_raw_get_sAcc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  38);
}

/**
 * @brief Get field cAcc from wk_log_gps_raw message
 *
 * @return  cAcc
 */
static inline int16_t mavlink_msg_wk_log_gps_raw_get_cAcc(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  40);
}

/**
 * @brief Get field fix_type from wk_log_gps_raw message
 *
 * @return  fix_type
 */
static inline uint8_t mavlink_msg_wk_log_gps_raw_get_fix_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  42);
}

/**
 * @brief Get field numSv from wk_log_gps_raw message
 *
 * @return  numSv
 */
static inline uint8_t mavlink_msg_wk_log_gps_raw_get_numSv(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  43);
}

/**
 * @brief Decode a wk_log_gps_raw message into a struct
 *
 * @param msg The message to decode
 * @param wk_log_gps_raw C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_log_gps_raw_decode(const mavlink_message_t* msg, mavlink_wk_log_gps_raw_t* wk_log_gps_raw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_log_gps_raw->timestamp = mavlink_msg_wk_log_gps_raw_get_timestamp(msg);
    wk_log_gps_raw->latitude = mavlink_msg_wk_log_gps_raw_get_latitude(msg);
    wk_log_gps_raw->longitude = mavlink_msg_wk_log_gps_raw_get_longitude(msg);
    wk_log_gps_raw->altitude = mavlink_msg_wk_log_gps_raw_get_altitude(msg);
    wk_log_gps_raw->vel_n = mavlink_msg_wk_log_gps_raw_get_vel_n(msg);
    wk_log_gps_raw->vel_e = mavlink_msg_wk_log_gps_raw_get_vel_e(msg);
    wk_log_gps_raw->vel_d = mavlink_msg_wk_log_gps_raw_get_vel_d(msg);
    wk_log_gps_raw->heading = mavlink_msg_wk_log_gps_raw_get_heading(msg);
    wk_log_gps_raw->hAcc = mavlink_msg_wk_log_gps_raw_get_hAcc(msg);
    wk_log_gps_raw->vAcc = mavlink_msg_wk_log_gps_raw_get_vAcc(msg);
    wk_log_gps_raw->sAcc = mavlink_msg_wk_log_gps_raw_get_sAcc(msg);
    wk_log_gps_raw->cAcc = mavlink_msg_wk_log_gps_raw_get_cAcc(msg);
    wk_log_gps_raw->fix_type = mavlink_msg_wk_log_gps_raw_get_fix_type(msg);
    wk_log_gps_raw->numSv = mavlink_msg_wk_log_gps_raw_get_numSv(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN? msg->len : MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN;
        memset(wk_log_gps_raw, 0, MAVLINK_MSG_ID_WK_LOG_GPS_RAW_LEN);
    memcpy(wk_log_gps_raw, _MAV_PAYLOAD(msg), len);
#endif
}
