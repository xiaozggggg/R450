#pragma once
// MESSAGE WK_R500_NEST_LANDING_STATE PACKING

#define MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE 8519


typedef struct __mavlink_wk_r500_nest_landing_state_t {
 float diatance_to_nest; /*<  diatance_to_nest*/
 uint8_t land_time; /*<  land_time*/
 uint8_t resever[8]; /*<  resever*/
} mavlink_wk_r500_nest_landing_state_t;

#define MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN 13
#define MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_MIN_LEN 13
#define MAVLINK_MSG_ID_8519_LEN 13
#define MAVLINK_MSG_ID_8519_MIN_LEN 13

#define MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_CRC 116
#define MAVLINK_MSG_ID_8519_CRC 116

#define MAVLINK_MSG_WK_R500_NEST_LANDING_STATE_FIELD_RESEVER_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_R500_NEST_LANDING_STATE { \
    8519, \
    "WK_R500_NEST_LANDING_STATE", \
    3, \
    {  { "diatance_to_nest", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_r500_nest_landing_state_t, diatance_to_nest) }, \
         { "land_time", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_r500_nest_landing_state_t, land_time) }, \
         { "resever", NULL, MAVLINK_TYPE_UINT8_T, 8, 5, offsetof(mavlink_wk_r500_nest_landing_state_t, resever) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_R500_NEST_LANDING_STATE { \
    "WK_R500_NEST_LANDING_STATE", \
    3, \
    {  { "diatance_to_nest", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_r500_nest_landing_state_t, diatance_to_nest) }, \
         { "land_time", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_r500_nest_landing_state_t, land_time) }, \
         { "resever", NULL, MAVLINK_TYPE_UINT8_T, 8, 5, offsetof(mavlink_wk_r500_nest_landing_state_t, resever) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_r500_nest_landing_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param diatance_to_nest  diatance_to_nest
 * @param land_time  land_time
 * @param resever  resever
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_r500_nest_landing_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float diatance_to_nest, uint8_t land_time, const uint8_t *resever)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN];
    _mav_put_float(buf, 0, diatance_to_nest);
    _mav_put_uint8_t(buf, 4, land_time);
    _mav_put_uint8_t_array(buf, 5, resever, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN);
#else
    mavlink_wk_r500_nest_landing_state_t packet;
    packet.diatance_to_nest = diatance_to_nest;
    packet.land_time = land_time;
    mav_array_memcpy(packet.resever, resever, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_CRC);
}

/**
 * @brief Pack a wk_r500_nest_landing_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param diatance_to_nest  diatance_to_nest
 * @param land_time  land_time
 * @param resever  resever
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_r500_nest_landing_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float diatance_to_nest,uint8_t land_time,const uint8_t *resever)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN];
    _mav_put_float(buf, 0, diatance_to_nest);
    _mav_put_uint8_t(buf, 4, land_time);
    _mav_put_uint8_t_array(buf, 5, resever, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN);
#else
    mavlink_wk_r500_nest_landing_state_t packet;
    packet.diatance_to_nest = diatance_to_nest;
    packet.land_time = land_time;
    mav_array_memcpy(packet.resever, resever, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_CRC);
}

/**
 * @brief Encode a wk_r500_nest_landing_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_r500_nest_landing_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_r500_nest_landing_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_r500_nest_landing_state_t* wk_r500_nest_landing_state)
{
    return mavlink_msg_wk_r500_nest_landing_state_pack(system_id, component_id, msg, wk_r500_nest_landing_state->diatance_to_nest, wk_r500_nest_landing_state->land_time, wk_r500_nest_landing_state->resever);
}

/**
 * @brief Encode a wk_r500_nest_landing_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_r500_nest_landing_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_r500_nest_landing_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_r500_nest_landing_state_t* wk_r500_nest_landing_state)
{
    return mavlink_msg_wk_r500_nest_landing_state_pack_chan(system_id, component_id, chan, msg, wk_r500_nest_landing_state->diatance_to_nest, wk_r500_nest_landing_state->land_time, wk_r500_nest_landing_state->resever);
}

/**
 * @brief Send a wk_r500_nest_landing_state message
 * @param chan MAVLink channel to send the message
 *
 * @param diatance_to_nest  diatance_to_nest
 * @param land_time  land_time
 * @param resever  resever
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_r500_nest_landing_state_send(mavlink_channel_t chan, float diatance_to_nest, uint8_t land_time, const uint8_t *resever)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN];
    _mav_put_float(buf, 0, diatance_to_nest);
    _mav_put_uint8_t(buf, 4, land_time);
    _mav_put_uint8_t_array(buf, 5, resever, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE, buf, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_CRC);
#else
    mavlink_wk_r500_nest_landing_state_t packet;
    packet.diatance_to_nest = diatance_to_nest;
    packet.land_time = land_time;
    mav_array_memcpy(packet.resever, resever, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE, (const char *)&packet, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_CRC);
#endif
}

/**
 * @brief Send a wk_r500_nest_landing_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_r500_nest_landing_state_send_struct(mavlink_channel_t chan, const mavlink_wk_r500_nest_landing_state_t* wk_r500_nest_landing_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_r500_nest_landing_state_send(chan, wk_r500_nest_landing_state->diatance_to_nest, wk_r500_nest_landing_state->land_time, wk_r500_nest_landing_state->resever);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE, (const char *)wk_r500_nest_landing_state, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_r500_nest_landing_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float diatance_to_nest, uint8_t land_time, const uint8_t *resever)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, diatance_to_nest);
    _mav_put_uint8_t(buf, 4, land_time);
    _mav_put_uint8_t_array(buf, 5, resever, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE, buf, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_CRC);
#else
    mavlink_wk_r500_nest_landing_state_t *packet = (mavlink_wk_r500_nest_landing_state_t *)msgbuf;
    packet->diatance_to_nest = diatance_to_nest;
    packet->land_time = land_time;
    mav_array_memcpy(packet->resever, resever, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE, (const char *)packet, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_R500_NEST_LANDING_STATE UNPACKING


/**
 * @brief Get field diatance_to_nest from wk_r500_nest_landing_state message
 *
 * @return  diatance_to_nest
 */
static inline float mavlink_msg_wk_r500_nest_landing_state_get_diatance_to_nest(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field land_time from wk_r500_nest_landing_state message
 *
 * @return  land_time
 */
static inline uint8_t mavlink_msg_wk_r500_nest_landing_state_get_land_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field resever from wk_r500_nest_landing_state message
 *
 * @return  resever
 */
static inline uint16_t mavlink_msg_wk_r500_nest_landing_state_get_resever(const mavlink_message_t* msg, uint8_t *resever)
{
    return _MAV_RETURN_uint8_t_array(msg, resever, 8,  5);
}

/**
 * @brief Decode a wk_r500_nest_landing_state message into a struct
 *
 * @param msg The message to decode
 * @param wk_r500_nest_landing_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_r500_nest_landing_state_decode(const mavlink_message_t* msg, mavlink_wk_r500_nest_landing_state_t* wk_r500_nest_landing_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_r500_nest_landing_state->diatance_to_nest = mavlink_msg_wk_r500_nest_landing_state_get_diatance_to_nest(msg);
    wk_r500_nest_landing_state->land_time = mavlink_msg_wk_r500_nest_landing_state_get_land_time(msg);
    mavlink_msg_wk_r500_nest_landing_state_get_resever(msg, wk_r500_nest_landing_state->resever);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN? msg->len : MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN;
        memset(wk_r500_nest_landing_state, 0, MAVLINK_MSG_ID_WK_R500_NEST_LANDING_STATE_LEN);
    memcpy(wk_r500_nest_landing_state, _MAV_PAYLOAD(msg), len);
#endif
}
