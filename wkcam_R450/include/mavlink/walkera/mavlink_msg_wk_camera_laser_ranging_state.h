#pragma once
// MESSAGE WK_CAMERA_LASER_RANGING_STATE PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE 8077


typedef struct __mavlink_wk_camera_laser_ranging_state_t {
 int32_t latitude; /*<  latitude*/
 int32_t longitude; /*<  longitude*/
 float altitude; /*<  altitude*/
 float distance; /*<  distance*/
 uint8_t state; /*<  state*/
} mavlink_wk_camera_laser_ranging_state_t;

#define MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN 17
#define MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_MIN_LEN 17
#define MAVLINK_MSG_ID_8077_LEN 17
#define MAVLINK_MSG_ID_8077_MIN_LEN 17

#define MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_CRC 149
#define MAVLINK_MSG_ID_8077_CRC 149



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_LASER_RANGING_STATE { \
    8077, \
    "WK_CAMERA_LASER_RANGING_STATE", \
    5, \
    {  { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_wk_camera_laser_ranging_state_t, state) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_wk_camera_laser_ranging_state_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_wk_camera_laser_ranging_state_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_camera_laser_ranging_state_t, altitude) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_camera_laser_ranging_state_t, distance) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_LASER_RANGING_STATE { \
    "WK_CAMERA_LASER_RANGING_STATE", \
    5, \
    {  { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_wk_camera_laser_ranging_state_t, state) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_wk_camera_laser_ranging_state_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_wk_camera_laser_ranging_state_t, longitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_camera_laser_ranging_state_t, altitude) }, \
         { "distance", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_camera_laser_ranging_state_t, distance) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_laser_ranging_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param state  state
 * @param latitude  latitude
 * @param longitude  longitude
 * @param altitude  altitude
 * @param distance  distance
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_laser_ranging_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t state, int32_t latitude, int32_t longitude, float altitude, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN];
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_float(buf, 8, altitude);
    _mav_put_float(buf, 12, distance);
    _mav_put_uint8_t(buf, 16, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN);
#else
    mavlink_wk_camera_laser_ranging_state_t packet;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.distance = distance;
    packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_CRC);
}

/**
 * @brief Pack a wk_camera_laser_ranging_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param state  state
 * @param latitude  latitude
 * @param longitude  longitude
 * @param altitude  altitude
 * @param distance  distance
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_laser_ranging_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t state,int32_t latitude,int32_t longitude,float altitude,float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN];
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_float(buf, 8, altitude);
    _mav_put_float(buf, 12, distance);
    _mav_put_uint8_t(buf, 16, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN);
#else
    mavlink_wk_camera_laser_ranging_state_t packet;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.distance = distance;
    packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_CRC);
}

/**
 * @brief Encode a wk_camera_laser_ranging_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_laser_ranging_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_laser_ranging_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_laser_ranging_state_t* wk_camera_laser_ranging_state)
{
    return mavlink_msg_wk_camera_laser_ranging_state_pack(system_id, component_id, msg, wk_camera_laser_ranging_state->state, wk_camera_laser_ranging_state->latitude, wk_camera_laser_ranging_state->longitude, wk_camera_laser_ranging_state->altitude, wk_camera_laser_ranging_state->distance);
}

/**
 * @brief Encode a wk_camera_laser_ranging_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_laser_ranging_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_laser_ranging_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_laser_ranging_state_t* wk_camera_laser_ranging_state)
{
    return mavlink_msg_wk_camera_laser_ranging_state_pack_chan(system_id, component_id, chan, msg, wk_camera_laser_ranging_state->state, wk_camera_laser_ranging_state->latitude, wk_camera_laser_ranging_state->longitude, wk_camera_laser_ranging_state->altitude, wk_camera_laser_ranging_state->distance);
}

/**
 * @brief Send a wk_camera_laser_ranging_state message
 * @param chan MAVLink channel to send the message
 *
 * @param state  state
 * @param latitude  latitude
 * @param longitude  longitude
 * @param altitude  altitude
 * @param distance  distance
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_laser_ranging_state_send(mavlink_channel_t chan, uint8_t state, int32_t latitude, int32_t longitude, float altitude, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN];
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_float(buf, 8, altitude);
    _mav_put_float(buf, 12, distance);
    _mav_put_uint8_t(buf, 16, state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE, buf, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_CRC);
#else
    mavlink_wk_camera_laser_ranging_state_t packet;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.altitude = altitude;
    packet.distance = distance;
    packet.state = state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_CRC);
#endif
}

/**
 * @brief Send a wk_camera_laser_ranging_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_laser_ranging_state_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_laser_ranging_state_t* wk_camera_laser_ranging_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_laser_ranging_state_send(chan, wk_camera_laser_ranging_state->state, wk_camera_laser_ranging_state->latitude, wk_camera_laser_ranging_state->longitude, wk_camera_laser_ranging_state->altitude, wk_camera_laser_ranging_state->distance);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE, (const char *)wk_camera_laser_ranging_state, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_laser_ranging_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t state, int32_t latitude, int32_t longitude, float altitude, float distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_float(buf, 8, altitude);
    _mav_put_float(buf, 12, distance);
    _mav_put_uint8_t(buf, 16, state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE, buf, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_CRC);
#else
    mavlink_wk_camera_laser_ranging_state_t *packet = (mavlink_wk_camera_laser_ranging_state_t *)msgbuf;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->altitude = altitude;
    packet->distance = distance;
    packet->state = state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_LASER_RANGING_STATE UNPACKING


/**
 * @brief Get field state from wk_camera_laser_ranging_state message
 *
 * @return  state
 */
static inline uint8_t mavlink_msg_wk_camera_laser_ranging_state_get_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field latitude from wk_camera_laser_ranging_state message
 *
 * @return  latitude
 */
static inline int32_t mavlink_msg_wk_camera_laser_ranging_state_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field longitude from wk_camera_laser_ranging_state message
 *
 * @return  longitude
 */
static inline int32_t mavlink_msg_wk_camera_laser_ranging_state_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field altitude from wk_camera_laser_ranging_state message
 *
 * @return  altitude
 */
static inline float mavlink_msg_wk_camera_laser_ranging_state_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field distance from wk_camera_laser_ranging_state message
 *
 * @return  distance
 */
static inline float mavlink_msg_wk_camera_laser_ranging_state_get_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Decode a wk_camera_laser_ranging_state message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_laser_ranging_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_laser_ranging_state_decode(const mavlink_message_t* msg, mavlink_wk_camera_laser_ranging_state_t* wk_camera_laser_ranging_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_laser_ranging_state->latitude = mavlink_msg_wk_camera_laser_ranging_state_get_latitude(msg);
    wk_camera_laser_ranging_state->longitude = mavlink_msg_wk_camera_laser_ranging_state_get_longitude(msg);
    wk_camera_laser_ranging_state->altitude = mavlink_msg_wk_camera_laser_ranging_state_get_altitude(msg);
    wk_camera_laser_ranging_state->distance = mavlink_msg_wk_camera_laser_ranging_state_get_distance(msg);
    wk_camera_laser_ranging_state->state = mavlink_msg_wk_camera_laser_ranging_state_get_state(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN;
        memset(wk_camera_laser_ranging_state, 0, MAVLINK_MSG_ID_WK_CAMERA_LASER_RANGING_STATE_LEN);
    memcpy(wk_camera_laser_ranging_state, _MAV_PAYLOAD(msg), len);
#endif
}
