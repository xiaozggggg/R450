#pragma once
// MESSAGE WK_TARGET_POSVEL PACKING

#define MAVLINK_MSG_ID_WK_TARGET_POSVEL 8020


typedef struct __mavlink_wk_target_posvel_t {
 int32_t latitude; /*<  target's latitude(WGS84 latitude * 10E7)*/
 int32_t longitude; /*<  target's longitude(WGS84 latitude * 10E7)*/
 int16_t velx; /*<  target's velocity(north),unit: cm * 10*/
 int16_t vely; /*<  target's velocity(west),unit: cm * 10*/
 int16_t velz; /*<  target's velocity(up) unit : cm * 10*/
 int16_t heading; /*<  target's heading :unit : degrees * 100*/
 uint8_t valid; /*<  0:invalid,1:valid*/
} mavlink_wk_target_posvel_t;

#define MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN 17
#define MAVLINK_MSG_ID_WK_TARGET_POSVEL_MIN_LEN 17
#define MAVLINK_MSG_ID_8020_LEN 17
#define MAVLINK_MSG_ID_8020_MIN_LEN 17

#define MAVLINK_MSG_ID_WK_TARGET_POSVEL_CRC 111
#define MAVLINK_MSG_ID_8020_CRC 111



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_TARGET_POSVEL { \
    8020, \
    "WK_TARGET_POSVEL", \
    7, \
    {  { "valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_wk_target_posvel_t, valid) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_wk_target_posvel_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_wk_target_posvel_t, longitude) }, \
         { "velx", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_wk_target_posvel_t, velx) }, \
         { "vely", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_wk_target_posvel_t, vely) }, \
         { "velz", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_wk_target_posvel_t, velz) }, \
         { "heading", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_wk_target_posvel_t, heading) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_TARGET_POSVEL { \
    "WK_TARGET_POSVEL", \
    7, \
    {  { "valid", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_wk_target_posvel_t, valid) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_wk_target_posvel_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_wk_target_posvel_t, longitude) }, \
         { "velx", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_wk_target_posvel_t, velx) }, \
         { "vely", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_wk_target_posvel_t, vely) }, \
         { "velz", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_wk_target_posvel_t, velz) }, \
         { "heading", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_wk_target_posvel_t, heading) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_target_posvel message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param valid  0:invalid,1:valid
 * @param latitude  target's latitude(WGS84 latitude * 10E7)
 * @param longitude  target's longitude(WGS84 latitude * 10E7)
 * @param velx  target's velocity(north),unit: cm * 10
 * @param vely  target's velocity(west),unit: cm * 10
 * @param velz  target's velocity(up) unit : cm * 10
 * @param heading  target's heading :unit : degrees * 100
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_target_posvel_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t valid, int32_t latitude, int32_t longitude, int16_t velx, int16_t vely, int16_t velz, int16_t heading)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN];
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_int16_t(buf, 8, velx);
    _mav_put_int16_t(buf, 10, vely);
    _mav_put_int16_t(buf, 12, velz);
    _mav_put_int16_t(buf, 14, heading);
    _mav_put_uint8_t(buf, 16, valid);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN);
#else
    mavlink_wk_target_posvel_t packet;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.velx = velx;
    packet.vely = vely;
    packet.velz = velz;
    packet.heading = heading;
    packet.valid = valid;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_TARGET_POSVEL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_TARGET_POSVEL_MIN_LEN, MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN, MAVLINK_MSG_ID_WK_TARGET_POSVEL_CRC);
}

/**
 * @brief Pack a wk_target_posvel message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param valid  0:invalid,1:valid
 * @param latitude  target's latitude(WGS84 latitude * 10E7)
 * @param longitude  target's longitude(WGS84 latitude * 10E7)
 * @param velx  target's velocity(north),unit: cm * 10
 * @param vely  target's velocity(west),unit: cm * 10
 * @param velz  target's velocity(up) unit : cm * 10
 * @param heading  target's heading :unit : degrees * 100
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_target_posvel_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t valid,int32_t latitude,int32_t longitude,int16_t velx,int16_t vely,int16_t velz,int16_t heading)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN];
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_int16_t(buf, 8, velx);
    _mav_put_int16_t(buf, 10, vely);
    _mav_put_int16_t(buf, 12, velz);
    _mav_put_int16_t(buf, 14, heading);
    _mav_put_uint8_t(buf, 16, valid);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN);
#else
    mavlink_wk_target_posvel_t packet;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.velx = velx;
    packet.vely = vely;
    packet.velz = velz;
    packet.heading = heading;
    packet.valid = valid;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_TARGET_POSVEL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_TARGET_POSVEL_MIN_LEN, MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN, MAVLINK_MSG_ID_WK_TARGET_POSVEL_CRC);
}

/**
 * @brief Encode a wk_target_posvel struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_target_posvel C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_target_posvel_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_target_posvel_t* wk_target_posvel)
{
    return mavlink_msg_wk_target_posvel_pack(system_id, component_id, msg, wk_target_posvel->valid, wk_target_posvel->latitude, wk_target_posvel->longitude, wk_target_posvel->velx, wk_target_posvel->vely, wk_target_posvel->velz, wk_target_posvel->heading);
}

/**
 * @brief Encode a wk_target_posvel struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_target_posvel C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_target_posvel_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_target_posvel_t* wk_target_posvel)
{
    return mavlink_msg_wk_target_posvel_pack_chan(system_id, component_id, chan, msg, wk_target_posvel->valid, wk_target_posvel->latitude, wk_target_posvel->longitude, wk_target_posvel->velx, wk_target_posvel->vely, wk_target_posvel->velz, wk_target_posvel->heading);
}

/**
 * @brief Send a wk_target_posvel message
 * @param chan MAVLink channel to send the message
 *
 * @param valid  0:invalid,1:valid
 * @param latitude  target's latitude(WGS84 latitude * 10E7)
 * @param longitude  target's longitude(WGS84 latitude * 10E7)
 * @param velx  target's velocity(north),unit: cm * 10
 * @param vely  target's velocity(west),unit: cm * 10
 * @param velz  target's velocity(up) unit : cm * 10
 * @param heading  target's heading :unit : degrees * 100
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_target_posvel_send(mavlink_channel_t chan, uint8_t valid, int32_t latitude, int32_t longitude, int16_t velx, int16_t vely, int16_t velz, int16_t heading)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN];
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_int16_t(buf, 8, velx);
    _mav_put_int16_t(buf, 10, vely);
    _mav_put_int16_t(buf, 12, velz);
    _mav_put_int16_t(buf, 14, heading);
    _mav_put_uint8_t(buf, 16, valid);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TARGET_POSVEL, buf, MAVLINK_MSG_ID_WK_TARGET_POSVEL_MIN_LEN, MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN, MAVLINK_MSG_ID_WK_TARGET_POSVEL_CRC);
#else
    mavlink_wk_target_posvel_t packet;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.velx = velx;
    packet.vely = vely;
    packet.velz = velz;
    packet.heading = heading;
    packet.valid = valid;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TARGET_POSVEL, (const char *)&packet, MAVLINK_MSG_ID_WK_TARGET_POSVEL_MIN_LEN, MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN, MAVLINK_MSG_ID_WK_TARGET_POSVEL_CRC);
#endif
}

/**
 * @brief Send a wk_target_posvel message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_target_posvel_send_struct(mavlink_channel_t chan, const mavlink_wk_target_posvel_t* wk_target_posvel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_target_posvel_send(chan, wk_target_posvel->valid, wk_target_posvel->latitude, wk_target_posvel->longitude, wk_target_posvel->velx, wk_target_posvel->vely, wk_target_posvel->velz, wk_target_posvel->heading);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TARGET_POSVEL, (const char *)wk_target_posvel, MAVLINK_MSG_ID_WK_TARGET_POSVEL_MIN_LEN, MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN, MAVLINK_MSG_ID_WK_TARGET_POSVEL_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_target_posvel_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t valid, int32_t latitude, int32_t longitude, int16_t velx, int16_t vely, int16_t velz, int16_t heading)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_int16_t(buf, 8, velx);
    _mav_put_int16_t(buf, 10, vely);
    _mav_put_int16_t(buf, 12, velz);
    _mav_put_int16_t(buf, 14, heading);
    _mav_put_uint8_t(buf, 16, valid);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TARGET_POSVEL, buf, MAVLINK_MSG_ID_WK_TARGET_POSVEL_MIN_LEN, MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN, MAVLINK_MSG_ID_WK_TARGET_POSVEL_CRC);
#else
    mavlink_wk_target_posvel_t *packet = (mavlink_wk_target_posvel_t *)msgbuf;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->velx = velx;
    packet->vely = vely;
    packet->velz = velz;
    packet->heading = heading;
    packet->valid = valid;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TARGET_POSVEL, (const char *)packet, MAVLINK_MSG_ID_WK_TARGET_POSVEL_MIN_LEN, MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN, MAVLINK_MSG_ID_WK_TARGET_POSVEL_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_TARGET_POSVEL UNPACKING


/**
 * @brief Get field valid from wk_target_posvel message
 *
 * @return  0:invalid,1:valid
 */
static inline uint8_t mavlink_msg_wk_target_posvel_get_valid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field latitude from wk_target_posvel message
 *
 * @return  target's latitude(WGS84 latitude * 10E7)
 */
static inline int32_t mavlink_msg_wk_target_posvel_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field longitude from wk_target_posvel message
 *
 * @return  target's longitude(WGS84 latitude * 10E7)
 */
static inline int32_t mavlink_msg_wk_target_posvel_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field velx from wk_target_posvel message
 *
 * @return  target's velocity(north),unit: cm * 10
 */
static inline int16_t mavlink_msg_wk_target_posvel_get_velx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field vely from wk_target_posvel message
 *
 * @return  target's velocity(west),unit: cm * 10
 */
static inline int16_t mavlink_msg_wk_target_posvel_get_vely(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field velz from wk_target_posvel message
 *
 * @return  target's velocity(up) unit : cm * 10
 */
static inline int16_t mavlink_msg_wk_target_posvel_get_velz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field heading from wk_target_posvel message
 *
 * @return  target's heading :unit : degrees * 100
 */
static inline int16_t mavlink_msg_wk_target_posvel_get_heading(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Decode a wk_target_posvel message into a struct
 *
 * @param msg The message to decode
 * @param wk_target_posvel C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_target_posvel_decode(const mavlink_message_t* msg, mavlink_wk_target_posvel_t* wk_target_posvel)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_target_posvel->latitude = mavlink_msg_wk_target_posvel_get_latitude(msg);
    wk_target_posvel->longitude = mavlink_msg_wk_target_posvel_get_longitude(msg);
    wk_target_posvel->velx = mavlink_msg_wk_target_posvel_get_velx(msg);
    wk_target_posvel->vely = mavlink_msg_wk_target_posvel_get_vely(msg);
    wk_target_posvel->velz = mavlink_msg_wk_target_posvel_get_velz(msg);
    wk_target_posvel->heading = mavlink_msg_wk_target_posvel_get_heading(msg);
    wk_target_posvel->valid = mavlink_msg_wk_target_posvel_get_valid(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN? msg->len : MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN;
        memset(wk_target_posvel, 0, MAVLINK_MSG_ID_WK_TARGET_POSVEL_LEN);
    memcpy(wk_target_posvel, _MAV_PAYLOAD(msg), len);
#endif
}
