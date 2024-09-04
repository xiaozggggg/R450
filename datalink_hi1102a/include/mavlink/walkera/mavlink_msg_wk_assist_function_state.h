#pragma once
// MESSAGE WK_ASSIST_FUNCTION_STATE PACKING

#define MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE 8516


typedef struct __mavlink_wk_assist_function_state_t {
 uint8_t cruise_en; /*<  */
 uint8_t target_lock_en; /*<  */
 uint8_t auto_circle_en; /*<  */
 uint8_t auto_rise_en; /*<  */
 uint8_t auto_far_away_en; /*<  */
 uint8_t auto_drift_en; /*<  */
 uint8_t reserve_function1; /*<  */
 uint8_t reserve_function2; /*<  */
 uint8_t reserve_function3; /*<  */
 uint8_t reserve_function4; /*<  */
 uint8_t reserve_function5; /*<  */
} mavlink_wk_assist_function_state_t;

#define MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN 11
#define MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_MIN_LEN 11
#define MAVLINK_MSG_ID_8516_LEN 11
#define MAVLINK_MSG_ID_8516_MIN_LEN 11

#define MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_CRC 80
#define MAVLINK_MSG_ID_8516_CRC 80



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_ASSIST_FUNCTION_STATE { \
    8516, \
    "WK_ASSIST_FUNCTION_STATE", \
    11, \
    {  { "cruise_en", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_assist_function_state_t, cruise_en) }, \
         { "target_lock_en", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_assist_function_state_t, target_lock_en) }, \
         { "auto_circle_en", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_assist_function_state_t, auto_circle_en) }, \
         { "auto_rise_en", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_assist_function_state_t, auto_rise_en) }, \
         { "auto_far_away_en", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_assist_function_state_t, auto_far_away_en) }, \
         { "auto_drift_en", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_assist_function_state_t, auto_drift_en) }, \
         { "reserve_function1", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_assist_function_state_t, reserve_function1) }, \
         { "reserve_function2", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_wk_assist_function_state_t, reserve_function2) }, \
         { "reserve_function3", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wk_assist_function_state_t, reserve_function3) }, \
         { "reserve_function4", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_wk_assist_function_state_t, reserve_function4) }, \
         { "reserve_function5", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_wk_assist_function_state_t, reserve_function5) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_ASSIST_FUNCTION_STATE { \
    "WK_ASSIST_FUNCTION_STATE", \
    11, \
    {  { "cruise_en", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_assist_function_state_t, cruise_en) }, \
         { "target_lock_en", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_assist_function_state_t, target_lock_en) }, \
         { "auto_circle_en", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_assist_function_state_t, auto_circle_en) }, \
         { "auto_rise_en", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_assist_function_state_t, auto_rise_en) }, \
         { "auto_far_away_en", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_assist_function_state_t, auto_far_away_en) }, \
         { "auto_drift_en", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_assist_function_state_t, auto_drift_en) }, \
         { "reserve_function1", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_assist_function_state_t, reserve_function1) }, \
         { "reserve_function2", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_wk_assist_function_state_t, reserve_function2) }, \
         { "reserve_function3", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wk_assist_function_state_t, reserve_function3) }, \
         { "reserve_function4", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_wk_assist_function_state_t, reserve_function4) }, \
         { "reserve_function5", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_wk_assist_function_state_t, reserve_function5) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_assist_function_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param cruise_en  
 * @param target_lock_en  
 * @param auto_circle_en  
 * @param auto_rise_en  
 * @param auto_far_away_en  
 * @param auto_drift_en  
 * @param reserve_function1  
 * @param reserve_function2  
 * @param reserve_function3  
 * @param reserve_function4  
 * @param reserve_function5  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_assist_function_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t cruise_en, uint8_t target_lock_en, uint8_t auto_circle_en, uint8_t auto_rise_en, uint8_t auto_far_away_en, uint8_t auto_drift_en, uint8_t reserve_function1, uint8_t reserve_function2, uint8_t reserve_function3, uint8_t reserve_function4, uint8_t reserve_function5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN];
    _mav_put_uint8_t(buf, 0, cruise_en);
    _mav_put_uint8_t(buf, 1, target_lock_en);
    _mav_put_uint8_t(buf, 2, auto_circle_en);
    _mav_put_uint8_t(buf, 3, auto_rise_en);
    _mav_put_uint8_t(buf, 4, auto_far_away_en);
    _mav_put_uint8_t(buf, 5, auto_drift_en);
    _mav_put_uint8_t(buf, 6, reserve_function1);
    _mav_put_uint8_t(buf, 7, reserve_function2);
    _mav_put_uint8_t(buf, 8, reserve_function3);
    _mav_put_uint8_t(buf, 9, reserve_function4);
    _mav_put_uint8_t(buf, 10, reserve_function5);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN);
#else
    mavlink_wk_assist_function_state_t packet;
    packet.cruise_en = cruise_en;
    packet.target_lock_en = target_lock_en;
    packet.auto_circle_en = auto_circle_en;
    packet.auto_rise_en = auto_rise_en;
    packet.auto_far_away_en = auto_far_away_en;
    packet.auto_drift_en = auto_drift_en;
    packet.reserve_function1 = reserve_function1;
    packet.reserve_function2 = reserve_function2;
    packet.reserve_function3 = reserve_function3;
    packet.reserve_function4 = reserve_function4;
    packet.reserve_function5 = reserve_function5;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_CRC);
}

/**
 * @brief Pack a wk_assist_function_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cruise_en  
 * @param target_lock_en  
 * @param auto_circle_en  
 * @param auto_rise_en  
 * @param auto_far_away_en  
 * @param auto_drift_en  
 * @param reserve_function1  
 * @param reserve_function2  
 * @param reserve_function3  
 * @param reserve_function4  
 * @param reserve_function5  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_assist_function_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t cruise_en,uint8_t target_lock_en,uint8_t auto_circle_en,uint8_t auto_rise_en,uint8_t auto_far_away_en,uint8_t auto_drift_en,uint8_t reserve_function1,uint8_t reserve_function2,uint8_t reserve_function3,uint8_t reserve_function4,uint8_t reserve_function5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN];
    _mav_put_uint8_t(buf, 0, cruise_en);
    _mav_put_uint8_t(buf, 1, target_lock_en);
    _mav_put_uint8_t(buf, 2, auto_circle_en);
    _mav_put_uint8_t(buf, 3, auto_rise_en);
    _mav_put_uint8_t(buf, 4, auto_far_away_en);
    _mav_put_uint8_t(buf, 5, auto_drift_en);
    _mav_put_uint8_t(buf, 6, reserve_function1);
    _mav_put_uint8_t(buf, 7, reserve_function2);
    _mav_put_uint8_t(buf, 8, reserve_function3);
    _mav_put_uint8_t(buf, 9, reserve_function4);
    _mav_put_uint8_t(buf, 10, reserve_function5);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN);
#else
    mavlink_wk_assist_function_state_t packet;
    packet.cruise_en = cruise_en;
    packet.target_lock_en = target_lock_en;
    packet.auto_circle_en = auto_circle_en;
    packet.auto_rise_en = auto_rise_en;
    packet.auto_far_away_en = auto_far_away_en;
    packet.auto_drift_en = auto_drift_en;
    packet.reserve_function1 = reserve_function1;
    packet.reserve_function2 = reserve_function2;
    packet.reserve_function3 = reserve_function3;
    packet.reserve_function4 = reserve_function4;
    packet.reserve_function5 = reserve_function5;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_CRC);
}

/**
 * @brief Encode a wk_assist_function_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_assist_function_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_assist_function_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_assist_function_state_t* wk_assist_function_state)
{
    return mavlink_msg_wk_assist_function_state_pack(system_id, component_id, msg, wk_assist_function_state->cruise_en, wk_assist_function_state->target_lock_en, wk_assist_function_state->auto_circle_en, wk_assist_function_state->auto_rise_en, wk_assist_function_state->auto_far_away_en, wk_assist_function_state->auto_drift_en, wk_assist_function_state->reserve_function1, wk_assist_function_state->reserve_function2, wk_assist_function_state->reserve_function3, wk_assist_function_state->reserve_function4, wk_assist_function_state->reserve_function5);
}

/**
 * @brief Encode a wk_assist_function_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_assist_function_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_assist_function_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_assist_function_state_t* wk_assist_function_state)
{
    return mavlink_msg_wk_assist_function_state_pack_chan(system_id, component_id, chan, msg, wk_assist_function_state->cruise_en, wk_assist_function_state->target_lock_en, wk_assist_function_state->auto_circle_en, wk_assist_function_state->auto_rise_en, wk_assist_function_state->auto_far_away_en, wk_assist_function_state->auto_drift_en, wk_assist_function_state->reserve_function1, wk_assist_function_state->reserve_function2, wk_assist_function_state->reserve_function3, wk_assist_function_state->reserve_function4, wk_assist_function_state->reserve_function5);
}

/**
 * @brief Send a wk_assist_function_state message
 * @param chan MAVLink channel to send the message
 *
 * @param cruise_en  
 * @param target_lock_en  
 * @param auto_circle_en  
 * @param auto_rise_en  
 * @param auto_far_away_en  
 * @param auto_drift_en  
 * @param reserve_function1  
 * @param reserve_function2  
 * @param reserve_function3  
 * @param reserve_function4  
 * @param reserve_function5  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_assist_function_state_send(mavlink_channel_t chan, uint8_t cruise_en, uint8_t target_lock_en, uint8_t auto_circle_en, uint8_t auto_rise_en, uint8_t auto_far_away_en, uint8_t auto_drift_en, uint8_t reserve_function1, uint8_t reserve_function2, uint8_t reserve_function3, uint8_t reserve_function4, uint8_t reserve_function5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN];
    _mav_put_uint8_t(buf, 0, cruise_en);
    _mav_put_uint8_t(buf, 1, target_lock_en);
    _mav_put_uint8_t(buf, 2, auto_circle_en);
    _mav_put_uint8_t(buf, 3, auto_rise_en);
    _mav_put_uint8_t(buf, 4, auto_far_away_en);
    _mav_put_uint8_t(buf, 5, auto_drift_en);
    _mav_put_uint8_t(buf, 6, reserve_function1);
    _mav_put_uint8_t(buf, 7, reserve_function2);
    _mav_put_uint8_t(buf, 8, reserve_function3);
    _mav_put_uint8_t(buf, 9, reserve_function4);
    _mav_put_uint8_t(buf, 10, reserve_function5);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE, buf, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_CRC);
#else
    mavlink_wk_assist_function_state_t packet;
    packet.cruise_en = cruise_en;
    packet.target_lock_en = target_lock_en;
    packet.auto_circle_en = auto_circle_en;
    packet.auto_rise_en = auto_rise_en;
    packet.auto_far_away_en = auto_far_away_en;
    packet.auto_drift_en = auto_drift_en;
    packet.reserve_function1 = reserve_function1;
    packet.reserve_function2 = reserve_function2;
    packet.reserve_function3 = reserve_function3;
    packet.reserve_function4 = reserve_function4;
    packet.reserve_function5 = reserve_function5;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE, (const char *)&packet, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_CRC);
#endif
}

/**
 * @brief Send a wk_assist_function_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_assist_function_state_send_struct(mavlink_channel_t chan, const mavlink_wk_assist_function_state_t* wk_assist_function_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_assist_function_state_send(chan, wk_assist_function_state->cruise_en, wk_assist_function_state->target_lock_en, wk_assist_function_state->auto_circle_en, wk_assist_function_state->auto_rise_en, wk_assist_function_state->auto_far_away_en, wk_assist_function_state->auto_drift_en, wk_assist_function_state->reserve_function1, wk_assist_function_state->reserve_function2, wk_assist_function_state->reserve_function3, wk_assist_function_state->reserve_function4, wk_assist_function_state->reserve_function5);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE, (const char *)wk_assist_function_state, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_assist_function_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t cruise_en, uint8_t target_lock_en, uint8_t auto_circle_en, uint8_t auto_rise_en, uint8_t auto_far_away_en, uint8_t auto_drift_en, uint8_t reserve_function1, uint8_t reserve_function2, uint8_t reserve_function3, uint8_t reserve_function4, uint8_t reserve_function5)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, cruise_en);
    _mav_put_uint8_t(buf, 1, target_lock_en);
    _mav_put_uint8_t(buf, 2, auto_circle_en);
    _mav_put_uint8_t(buf, 3, auto_rise_en);
    _mav_put_uint8_t(buf, 4, auto_far_away_en);
    _mav_put_uint8_t(buf, 5, auto_drift_en);
    _mav_put_uint8_t(buf, 6, reserve_function1);
    _mav_put_uint8_t(buf, 7, reserve_function2);
    _mav_put_uint8_t(buf, 8, reserve_function3);
    _mav_put_uint8_t(buf, 9, reserve_function4);
    _mav_put_uint8_t(buf, 10, reserve_function5);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE, buf, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_CRC);
#else
    mavlink_wk_assist_function_state_t *packet = (mavlink_wk_assist_function_state_t *)msgbuf;
    packet->cruise_en = cruise_en;
    packet->target_lock_en = target_lock_en;
    packet->auto_circle_en = auto_circle_en;
    packet->auto_rise_en = auto_rise_en;
    packet->auto_far_away_en = auto_far_away_en;
    packet->auto_drift_en = auto_drift_en;
    packet->reserve_function1 = reserve_function1;
    packet->reserve_function2 = reserve_function2;
    packet->reserve_function3 = reserve_function3;
    packet->reserve_function4 = reserve_function4;
    packet->reserve_function5 = reserve_function5;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE, (const char *)packet, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_ASSIST_FUNCTION_STATE UNPACKING


/**
 * @brief Get field cruise_en from wk_assist_function_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_cruise_en(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_lock_en from wk_assist_function_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_target_lock_en(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field auto_circle_en from wk_assist_function_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_auto_circle_en(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field auto_rise_en from wk_assist_function_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_auto_rise_en(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field auto_far_away_en from wk_assist_function_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_auto_far_away_en(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field auto_drift_en from wk_assist_function_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_auto_drift_en(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field reserve_function1 from wk_assist_function_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_reserve_function1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field reserve_function2 from wk_assist_function_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_reserve_function2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field reserve_function3 from wk_assist_function_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_reserve_function3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field reserve_function4 from wk_assist_function_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_reserve_function4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field reserve_function5 from wk_assist_function_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_reserve_function5(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Decode a wk_assist_function_state message into a struct
 *
 * @param msg The message to decode
 * @param wk_assist_function_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_assist_function_state_decode(const mavlink_message_t* msg, mavlink_wk_assist_function_state_t* wk_assist_function_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_assist_function_state->cruise_en = mavlink_msg_wk_assist_function_state_get_cruise_en(msg);
    wk_assist_function_state->target_lock_en = mavlink_msg_wk_assist_function_state_get_target_lock_en(msg);
    wk_assist_function_state->auto_circle_en = mavlink_msg_wk_assist_function_state_get_auto_circle_en(msg);
    wk_assist_function_state->auto_rise_en = mavlink_msg_wk_assist_function_state_get_auto_rise_en(msg);
    wk_assist_function_state->auto_far_away_en = mavlink_msg_wk_assist_function_state_get_auto_far_away_en(msg);
    wk_assist_function_state->auto_drift_en = mavlink_msg_wk_assist_function_state_get_auto_drift_en(msg);
    wk_assist_function_state->reserve_function1 = mavlink_msg_wk_assist_function_state_get_reserve_function1(msg);
    wk_assist_function_state->reserve_function2 = mavlink_msg_wk_assist_function_state_get_reserve_function2(msg);
    wk_assist_function_state->reserve_function3 = mavlink_msg_wk_assist_function_state_get_reserve_function3(msg);
    wk_assist_function_state->reserve_function4 = mavlink_msg_wk_assist_function_state_get_reserve_function4(msg);
    wk_assist_function_state->reserve_function5 = mavlink_msg_wk_assist_function_state_get_reserve_function5(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN? msg->len : MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN;
        memset(wk_assist_function_state, 0, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN);
    memcpy(wk_assist_function_state, _MAV_PAYLOAD(msg), len);
#endif
}
