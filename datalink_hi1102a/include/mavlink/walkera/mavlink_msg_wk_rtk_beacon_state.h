#pragma once
// MESSAGE WK_RTK_BEACON_STATE PACKING

#define MAVLINK_MSG_ID_WK_RTK_BEACON_STATE 8023


typedef struct __mavlink_wk_rtk_beacon_state_t {
 uint32_t distance; /*<  distance between beacon and copter,unit cm*/
 uint32_t distance_x; /*<  distance_x,unit cm*/
 uint32_t distance_y; /*<  distance_y,unit cm*/
 uint8_t fix_type; /*<  fix_type*/
 uint8_t sv_nums; /*<  satelite numbers*/
 uint8_t beacon_rate; /*<  beacon_rate*/
} mavlink_wk_rtk_beacon_state_t;

#define MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN 15
#define MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_MIN_LEN 15
#define MAVLINK_MSG_ID_8023_LEN 15
#define MAVLINK_MSG_ID_8023_MIN_LEN 15

#define MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_CRC 185
#define MAVLINK_MSG_ID_8023_CRC 185



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_RTK_BEACON_STATE { \
    8023, \
    "WK_RTK_BEACON_STATE", \
    6, \
    {  { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_wk_rtk_beacon_state_t, fix_type) }, \
         { "sv_nums", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_wk_rtk_beacon_state_t, sv_nums) }, \
         { "beacon_rate", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_wk_rtk_beacon_state_t, beacon_rate) }, \
         { "distance", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_rtk_beacon_state_t, distance) }, \
         { "distance_x", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_rtk_beacon_state_t, distance_x) }, \
         { "distance_y", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_rtk_beacon_state_t, distance_y) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_RTK_BEACON_STATE { \
    "WK_RTK_BEACON_STATE", \
    6, \
    {  { "fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_wk_rtk_beacon_state_t, fix_type) }, \
         { "sv_nums", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_wk_rtk_beacon_state_t, sv_nums) }, \
         { "beacon_rate", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_wk_rtk_beacon_state_t, beacon_rate) }, \
         { "distance", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_rtk_beacon_state_t, distance) }, \
         { "distance_x", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_rtk_beacon_state_t, distance_x) }, \
         { "distance_y", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_rtk_beacon_state_t, distance_y) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_rtk_beacon_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param fix_type  fix_type
 * @param sv_nums  satelite numbers
 * @param beacon_rate  beacon_rate
 * @param distance  distance between beacon and copter,unit cm
 * @param distance_x  distance_x,unit cm
 * @param distance_y  distance_y,unit cm
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_rtk_beacon_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t fix_type, uint8_t sv_nums, uint8_t beacon_rate, uint32_t distance, uint32_t distance_x, uint32_t distance_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN];
    _mav_put_uint32_t(buf, 0, distance);
    _mav_put_uint32_t(buf, 4, distance_x);
    _mav_put_uint32_t(buf, 8, distance_y);
    _mav_put_uint8_t(buf, 12, fix_type);
    _mav_put_uint8_t(buf, 13, sv_nums);
    _mav_put_uint8_t(buf, 14, beacon_rate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN);
#else
    mavlink_wk_rtk_beacon_state_t packet;
    packet.distance = distance;
    packet.distance_x = distance_x;
    packet.distance_y = distance_y;
    packet.fix_type = fix_type;
    packet.sv_nums = sv_nums;
    packet.beacon_rate = beacon_rate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_RTK_BEACON_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_CRC);
}

/**
 * @brief Pack a wk_rtk_beacon_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param fix_type  fix_type
 * @param sv_nums  satelite numbers
 * @param beacon_rate  beacon_rate
 * @param distance  distance between beacon and copter,unit cm
 * @param distance_x  distance_x,unit cm
 * @param distance_y  distance_y,unit cm
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_rtk_beacon_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t fix_type,uint8_t sv_nums,uint8_t beacon_rate,uint32_t distance,uint32_t distance_x,uint32_t distance_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN];
    _mav_put_uint32_t(buf, 0, distance);
    _mav_put_uint32_t(buf, 4, distance_x);
    _mav_put_uint32_t(buf, 8, distance_y);
    _mav_put_uint8_t(buf, 12, fix_type);
    _mav_put_uint8_t(buf, 13, sv_nums);
    _mav_put_uint8_t(buf, 14, beacon_rate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN);
#else
    mavlink_wk_rtk_beacon_state_t packet;
    packet.distance = distance;
    packet.distance_x = distance_x;
    packet.distance_y = distance_y;
    packet.fix_type = fix_type;
    packet.sv_nums = sv_nums;
    packet.beacon_rate = beacon_rate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_RTK_BEACON_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_CRC);
}

/**
 * @brief Encode a wk_rtk_beacon_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_rtk_beacon_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_rtk_beacon_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_rtk_beacon_state_t* wk_rtk_beacon_state)
{
    return mavlink_msg_wk_rtk_beacon_state_pack(system_id, component_id, msg, wk_rtk_beacon_state->fix_type, wk_rtk_beacon_state->sv_nums, wk_rtk_beacon_state->beacon_rate, wk_rtk_beacon_state->distance, wk_rtk_beacon_state->distance_x, wk_rtk_beacon_state->distance_y);
}

/**
 * @brief Encode a wk_rtk_beacon_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_rtk_beacon_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_rtk_beacon_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_rtk_beacon_state_t* wk_rtk_beacon_state)
{
    return mavlink_msg_wk_rtk_beacon_state_pack_chan(system_id, component_id, chan, msg, wk_rtk_beacon_state->fix_type, wk_rtk_beacon_state->sv_nums, wk_rtk_beacon_state->beacon_rate, wk_rtk_beacon_state->distance, wk_rtk_beacon_state->distance_x, wk_rtk_beacon_state->distance_y);
}

/**
 * @brief Send a wk_rtk_beacon_state message
 * @param chan MAVLink channel to send the message
 *
 * @param fix_type  fix_type
 * @param sv_nums  satelite numbers
 * @param beacon_rate  beacon_rate
 * @param distance  distance between beacon and copter,unit cm
 * @param distance_x  distance_x,unit cm
 * @param distance_y  distance_y,unit cm
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_rtk_beacon_state_send(mavlink_channel_t chan, uint8_t fix_type, uint8_t sv_nums, uint8_t beacon_rate, uint32_t distance, uint32_t distance_x, uint32_t distance_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN];
    _mav_put_uint32_t(buf, 0, distance);
    _mav_put_uint32_t(buf, 4, distance_x);
    _mav_put_uint32_t(buf, 8, distance_y);
    _mav_put_uint8_t(buf, 12, fix_type);
    _mav_put_uint8_t(buf, 13, sv_nums);
    _mav_put_uint8_t(buf, 14, beacon_rate);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE, buf, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_CRC);
#else
    mavlink_wk_rtk_beacon_state_t packet;
    packet.distance = distance;
    packet.distance_x = distance_x;
    packet.distance_y = distance_y;
    packet.fix_type = fix_type;
    packet.sv_nums = sv_nums;
    packet.beacon_rate = beacon_rate;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE, (const char *)&packet, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_CRC);
#endif
}

/**
 * @brief Send a wk_rtk_beacon_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_rtk_beacon_state_send_struct(mavlink_channel_t chan, const mavlink_wk_rtk_beacon_state_t* wk_rtk_beacon_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_rtk_beacon_state_send(chan, wk_rtk_beacon_state->fix_type, wk_rtk_beacon_state->sv_nums, wk_rtk_beacon_state->beacon_rate, wk_rtk_beacon_state->distance, wk_rtk_beacon_state->distance_x, wk_rtk_beacon_state->distance_y);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE, (const char *)wk_rtk_beacon_state, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_rtk_beacon_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t fix_type, uint8_t sv_nums, uint8_t beacon_rate, uint32_t distance, uint32_t distance_x, uint32_t distance_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, distance);
    _mav_put_uint32_t(buf, 4, distance_x);
    _mav_put_uint32_t(buf, 8, distance_y);
    _mav_put_uint8_t(buf, 12, fix_type);
    _mav_put_uint8_t(buf, 13, sv_nums);
    _mav_put_uint8_t(buf, 14, beacon_rate);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE, buf, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_CRC);
#else
    mavlink_wk_rtk_beacon_state_t *packet = (mavlink_wk_rtk_beacon_state_t *)msgbuf;
    packet->distance = distance;
    packet->distance_x = distance_x;
    packet->distance_y = distance_y;
    packet->fix_type = fix_type;
    packet->sv_nums = sv_nums;
    packet->beacon_rate = beacon_rate;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE, (const char *)packet, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_RTK_BEACON_STATE UNPACKING


/**
 * @brief Get field fix_type from wk_rtk_beacon_state message
 *
 * @return  fix_type
 */
static inline uint8_t mavlink_msg_wk_rtk_beacon_state_get_fix_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field sv_nums from wk_rtk_beacon_state message
 *
 * @return  satelite numbers
 */
static inline uint8_t mavlink_msg_wk_rtk_beacon_state_get_sv_nums(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field beacon_rate from wk_rtk_beacon_state message
 *
 * @return  beacon_rate
 */
static inline uint8_t mavlink_msg_wk_rtk_beacon_state_get_beacon_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field distance from wk_rtk_beacon_state message
 *
 * @return  distance between beacon and copter,unit cm
 */
static inline uint32_t mavlink_msg_wk_rtk_beacon_state_get_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field distance_x from wk_rtk_beacon_state message
 *
 * @return  distance_x,unit cm
 */
static inline uint32_t mavlink_msg_wk_rtk_beacon_state_get_distance_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field distance_y from wk_rtk_beacon_state message
 *
 * @return  distance_y,unit cm
 */
static inline uint32_t mavlink_msg_wk_rtk_beacon_state_get_distance_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Decode a wk_rtk_beacon_state message into a struct
 *
 * @param msg The message to decode
 * @param wk_rtk_beacon_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_rtk_beacon_state_decode(const mavlink_message_t* msg, mavlink_wk_rtk_beacon_state_t* wk_rtk_beacon_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_rtk_beacon_state->distance = mavlink_msg_wk_rtk_beacon_state_get_distance(msg);
    wk_rtk_beacon_state->distance_x = mavlink_msg_wk_rtk_beacon_state_get_distance_x(msg);
    wk_rtk_beacon_state->distance_y = mavlink_msg_wk_rtk_beacon_state_get_distance_y(msg);
    wk_rtk_beacon_state->fix_type = mavlink_msg_wk_rtk_beacon_state_get_fix_type(msg);
    wk_rtk_beacon_state->sv_nums = mavlink_msg_wk_rtk_beacon_state_get_sv_nums(msg);
    wk_rtk_beacon_state->beacon_rate = mavlink_msg_wk_rtk_beacon_state_get_beacon_rate(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN? msg->len : MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN;
        memset(wk_rtk_beacon_state, 0, MAVLINK_MSG_ID_WK_RTK_BEACON_STATE_LEN);
    memcpy(wk_rtk_beacon_state, _MAV_PAYLOAD(msg), len);
#endif
}
