#pragma once
// MESSAGE WK_SCOUT_STATE PACKING

#define MAVLINK_MSG_ID_WK_SCOUT_STATE 8071


typedef struct __mavlink_wk_scout_state_t {
 int32_t longitude; /*<  */
 int32_t latitude; /*<  */
 int32_t altitude; /*<  */
 uint8_t scout_state; /*<  scout state*/
} mavlink_wk_scout_state_t;

#define MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN 13
#define MAVLINK_MSG_ID_WK_SCOUT_STATE_MIN_LEN 13
#define MAVLINK_MSG_ID_8071_LEN 13
#define MAVLINK_MSG_ID_8071_MIN_LEN 13

#define MAVLINK_MSG_ID_WK_SCOUT_STATE_CRC 103
#define MAVLINK_MSG_ID_8071_CRC 103



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_SCOUT_STATE { \
    8071, \
    "WK_SCOUT_STATE", \
    4, \
    {  { "scout_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_wk_scout_state_t, scout_state) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_wk_scout_state_t, longitude) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_wk_scout_state_t, latitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_scout_state_t, altitude) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_SCOUT_STATE { \
    "WK_SCOUT_STATE", \
    4, \
    {  { "scout_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_wk_scout_state_t, scout_state) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_wk_scout_state_t, longitude) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_wk_scout_state_t, latitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_scout_state_t, altitude) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_scout_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param scout_state  scout state
 * @param longitude  
 * @param latitude  
 * @param altitude  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_scout_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t scout_state, int32_t longitude, int32_t latitude, int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN];
    _mav_put_int32_t(buf, 0, longitude);
    _mav_put_int32_t(buf, 4, latitude);
    _mav_put_int32_t(buf, 8, altitude);
    _mav_put_uint8_t(buf, 12, scout_state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN);
#else
    mavlink_wk_scout_state_t packet;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.altitude = altitude;
    packet.scout_state = scout_state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_SCOUT_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_SCOUT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN, MAVLINK_MSG_ID_WK_SCOUT_STATE_CRC);
}

/**
 * @brief Pack a wk_scout_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param scout_state  scout state
 * @param longitude  
 * @param latitude  
 * @param altitude  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_scout_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t scout_state,int32_t longitude,int32_t latitude,int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN];
    _mav_put_int32_t(buf, 0, longitude);
    _mav_put_int32_t(buf, 4, latitude);
    _mav_put_int32_t(buf, 8, altitude);
    _mav_put_uint8_t(buf, 12, scout_state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN);
#else
    mavlink_wk_scout_state_t packet;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.altitude = altitude;
    packet.scout_state = scout_state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_SCOUT_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_SCOUT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN, MAVLINK_MSG_ID_WK_SCOUT_STATE_CRC);
}

/**
 * @brief Encode a wk_scout_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_scout_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_scout_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_scout_state_t* wk_scout_state)
{
    return mavlink_msg_wk_scout_state_pack(system_id, component_id, msg, wk_scout_state->scout_state, wk_scout_state->longitude, wk_scout_state->latitude, wk_scout_state->altitude);
}

/**
 * @brief Encode a wk_scout_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_scout_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_scout_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_scout_state_t* wk_scout_state)
{
    return mavlink_msg_wk_scout_state_pack_chan(system_id, component_id, chan, msg, wk_scout_state->scout_state, wk_scout_state->longitude, wk_scout_state->latitude, wk_scout_state->altitude);
}

/**
 * @brief Send a wk_scout_state message
 * @param chan MAVLink channel to send the message
 *
 * @param scout_state  scout state
 * @param longitude  
 * @param latitude  
 * @param altitude  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_scout_state_send(mavlink_channel_t chan, uint8_t scout_state, int32_t longitude, int32_t latitude, int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN];
    _mav_put_int32_t(buf, 0, longitude);
    _mav_put_int32_t(buf, 4, latitude);
    _mav_put_int32_t(buf, 8, altitude);
    _mav_put_uint8_t(buf, 12, scout_state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SCOUT_STATE, buf, MAVLINK_MSG_ID_WK_SCOUT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN, MAVLINK_MSG_ID_WK_SCOUT_STATE_CRC);
#else
    mavlink_wk_scout_state_t packet;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.altitude = altitude;
    packet.scout_state = scout_state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SCOUT_STATE, (const char *)&packet, MAVLINK_MSG_ID_WK_SCOUT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN, MAVLINK_MSG_ID_WK_SCOUT_STATE_CRC);
#endif
}

/**
 * @brief Send a wk_scout_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_scout_state_send_struct(mavlink_channel_t chan, const mavlink_wk_scout_state_t* wk_scout_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_scout_state_send(chan, wk_scout_state->scout_state, wk_scout_state->longitude, wk_scout_state->latitude, wk_scout_state->altitude);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SCOUT_STATE, (const char *)wk_scout_state, MAVLINK_MSG_ID_WK_SCOUT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN, MAVLINK_MSG_ID_WK_SCOUT_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_scout_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t scout_state, int32_t longitude, int32_t latitude, int32_t altitude)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, longitude);
    _mav_put_int32_t(buf, 4, latitude);
    _mav_put_int32_t(buf, 8, altitude);
    _mav_put_uint8_t(buf, 12, scout_state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SCOUT_STATE, buf, MAVLINK_MSG_ID_WK_SCOUT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN, MAVLINK_MSG_ID_WK_SCOUT_STATE_CRC);
#else
    mavlink_wk_scout_state_t *packet = (mavlink_wk_scout_state_t *)msgbuf;
    packet->longitude = longitude;
    packet->latitude = latitude;
    packet->altitude = altitude;
    packet->scout_state = scout_state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SCOUT_STATE, (const char *)packet, MAVLINK_MSG_ID_WK_SCOUT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN, MAVLINK_MSG_ID_WK_SCOUT_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_SCOUT_STATE UNPACKING


/**
 * @brief Get field scout_state from wk_scout_state message
 *
 * @return  scout state
 */
static inline uint8_t mavlink_msg_wk_scout_state_get_scout_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field longitude from wk_scout_state message
 *
 * @return  
 */
static inline int32_t mavlink_msg_wk_scout_state_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field latitude from wk_scout_state message
 *
 * @return  
 */
static inline int32_t mavlink_msg_wk_scout_state_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field altitude from wk_scout_state message
 *
 * @return  
 */
static inline int32_t mavlink_msg_wk_scout_state_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Decode a wk_scout_state message into a struct
 *
 * @param msg The message to decode
 * @param wk_scout_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_scout_state_decode(const mavlink_message_t* msg, mavlink_wk_scout_state_t* wk_scout_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_scout_state->longitude = mavlink_msg_wk_scout_state_get_longitude(msg);
    wk_scout_state->latitude = mavlink_msg_wk_scout_state_get_latitude(msg);
    wk_scout_state->altitude = mavlink_msg_wk_scout_state_get_altitude(msg);
    wk_scout_state->scout_state = mavlink_msg_wk_scout_state_get_scout_state(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN? msg->len : MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN;
        memset(wk_scout_state, 0, MAVLINK_MSG_ID_WK_SCOUT_STATE_LEN);
    memcpy(wk_scout_state, _MAV_PAYLOAD(msg), len);
#endif
}
