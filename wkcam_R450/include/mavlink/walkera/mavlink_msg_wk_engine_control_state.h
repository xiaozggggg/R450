#pragma once
// MESSAGE WK_ENGINE_CONTROL_STATE PACKING

#define MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE 8073


typedef struct __mavlink_wk_engine_control_state_t {
 float state; /*<  */
 float speed; /*<  */
 float acce; /*<  */
 float reserved1; /*<  */
 float reserved2; /*<  */
} mavlink_wk_engine_control_state_t;

#define MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN 20
#define MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_MIN_LEN 20
#define MAVLINK_MSG_ID_8073_LEN 20
#define MAVLINK_MSG_ID_8073_MIN_LEN 20

#define MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_CRC 82
#define MAVLINK_MSG_ID_8073_CRC 82



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_ENGINE_CONTROL_STATE { \
    8073, \
    "WK_ENGINE_CONTROL_STATE", \
    5, \
    {  { "state", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_engine_control_state_t, state) }, \
         { "speed", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_engine_control_state_t, speed) }, \
         { "acce", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_engine_control_state_t, acce) }, \
         { "reserved1", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_engine_control_state_t, reserved1) }, \
         { "reserved2", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_engine_control_state_t, reserved2) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_ENGINE_CONTROL_STATE { \
    "WK_ENGINE_CONTROL_STATE", \
    5, \
    {  { "state", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_engine_control_state_t, state) }, \
         { "speed", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_engine_control_state_t, speed) }, \
         { "acce", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_engine_control_state_t, acce) }, \
         { "reserved1", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_engine_control_state_t, reserved1) }, \
         { "reserved2", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_engine_control_state_t, reserved2) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_engine_control_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param state  
 * @param speed  
 * @param acce  
 * @param reserved1  
 * @param reserved2  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_engine_control_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float state, float speed, float acce, float reserved1, float reserved2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN];
    _mav_put_float(buf, 0, state);
    _mav_put_float(buf, 4, speed);
    _mav_put_float(buf, 8, acce);
    _mav_put_float(buf, 12, reserved1);
    _mav_put_float(buf, 16, reserved2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN);
#else
    mavlink_wk_engine_control_state_t packet;
    packet.state = state;
    packet.speed = speed;
    packet.acce = acce;
    packet.reserved1 = reserved1;
    packet.reserved2 = reserved2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_CRC);
}

/**
 * @brief Pack a wk_engine_control_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param state  
 * @param speed  
 * @param acce  
 * @param reserved1  
 * @param reserved2  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_engine_control_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float state,float speed,float acce,float reserved1,float reserved2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN];
    _mav_put_float(buf, 0, state);
    _mav_put_float(buf, 4, speed);
    _mav_put_float(buf, 8, acce);
    _mav_put_float(buf, 12, reserved1);
    _mav_put_float(buf, 16, reserved2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN);
#else
    mavlink_wk_engine_control_state_t packet;
    packet.state = state;
    packet.speed = speed;
    packet.acce = acce;
    packet.reserved1 = reserved1;
    packet.reserved2 = reserved2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_CRC);
}

/**
 * @brief Encode a wk_engine_control_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_engine_control_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_engine_control_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_engine_control_state_t* wk_engine_control_state)
{
    return mavlink_msg_wk_engine_control_state_pack(system_id, component_id, msg, wk_engine_control_state->state, wk_engine_control_state->speed, wk_engine_control_state->acce, wk_engine_control_state->reserved1, wk_engine_control_state->reserved2);
}

/**
 * @brief Encode a wk_engine_control_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_engine_control_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_engine_control_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_engine_control_state_t* wk_engine_control_state)
{
    return mavlink_msg_wk_engine_control_state_pack_chan(system_id, component_id, chan, msg, wk_engine_control_state->state, wk_engine_control_state->speed, wk_engine_control_state->acce, wk_engine_control_state->reserved1, wk_engine_control_state->reserved2);
}

/**
 * @brief Send a wk_engine_control_state message
 * @param chan MAVLink channel to send the message
 *
 * @param state  
 * @param speed  
 * @param acce  
 * @param reserved1  
 * @param reserved2  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_engine_control_state_send(mavlink_channel_t chan, float state, float speed, float acce, float reserved1, float reserved2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN];
    _mav_put_float(buf, 0, state);
    _mav_put_float(buf, 4, speed);
    _mav_put_float(buf, 8, acce);
    _mav_put_float(buf, 12, reserved1);
    _mav_put_float(buf, 16, reserved2);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE, buf, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_CRC);
#else
    mavlink_wk_engine_control_state_t packet;
    packet.state = state;
    packet.speed = speed;
    packet.acce = acce;
    packet.reserved1 = reserved1;
    packet.reserved2 = reserved2;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE, (const char *)&packet, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_CRC);
#endif
}

/**
 * @brief Send a wk_engine_control_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_engine_control_state_send_struct(mavlink_channel_t chan, const mavlink_wk_engine_control_state_t* wk_engine_control_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_engine_control_state_send(chan, wk_engine_control_state->state, wk_engine_control_state->speed, wk_engine_control_state->acce, wk_engine_control_state->reserved1, wk_engine_control_state->reserved2);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE, (const char *)wk_engine_control_state, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_engine_control_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float state, float speed, float acce, float reserved1, float reserved2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, state);
    _mav_put_float(buf, 4, speed);
    _mav_put_float(buf, 8, acce);
    _mav_put_float(buf, 12, reserved1);
    _mav_put_float(buf, 16, reserved2);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE, buf, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_CRC);
#else
    mavlink_wk_engine_control_state_t *packet = (mavlink_wk_engine_control_state_t *)msgbuf;
    packet->state = state;
    packet->speed = speed;
    packet->acce = acce;
    packet->reserved1 = reserved1;
    packet->reserved2 = reserved2;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE, (const char *)packet, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_ENGINE_CONTROL_STATE UNPACKING


/**
 * @brief Get field state from wk_engine_control_state message
 *
 * @return  
 */
static inline float mavlink_msg_wk_engine_control_state_get_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field speed from wk_engine_control_state message
 *
 * @return  
 */
static inline float mavlink_msg_wk_engine_control_state_get_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field acce from wk_engine_control_state message
 *
 * @return  
 */
static inline float mavlink_msg_wk_engine_control_state_get_acce(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field reserved1 from wk_engine_control_state message
 *
 * @return  
 */
static inline float mavlink_msg_wk_engine_control_state_get_reserved1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field reserved2 from wk_engine_control_state message
 *
 * @return  
 */
static inline float mavlink_msg_wk_engine_control_state_get_reserved2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Decode a wk_engine_control_state message into a struct
 *
 * @param msg The message to decode
 * @param wk_engine_control_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_engine_control_state_decode(const mavlink_message_t* msg, mavlink_wk_engine_control_state_t* wk_engine_control_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_engine_control_state->state = mavlink_msg_wk_engine_control_state_get_state(msg);
    wk_engine_control_state->speed = mavlink_msg_wk_engine_control_state_get_speed(msg);
    wk_engine_control_state->acce = mavlink_msg_wk_engine_control_state_get_acce(msg);
    wk_engine_control_state->reserved1 = mavlink_msg_wk_engine_control_state_get_reserved1(msg);
    wk_engine_control_state->reserved2 = mavlink_msg_wk_engine_control_state_get_reserved2(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN? msg->len : MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN;
        memset(wk_engine_control_state, 0, MAVLINK_MSG_ID_WK_ENGINE_CONTROL_STATE_LEN);
    memcpy(wk_engine_control_state, _MAV_PAYLOAD(msg), len);
#endif
}
