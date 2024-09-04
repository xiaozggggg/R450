#pragma once
// MESSAGE WK_MISSION_STATE PACKING

#define MAVLINK_MSG_ID_WK_MISSION_STATE 8005


typedef struct __mavlink_wk_mission_state_t {
 uint32_t next_cmd_seq; /*<  next command seq*/
 float total_distance; /*<  total distance,unit meters*/
 float complete_distance; /*<  complete distance,unit meters*/
 uint32_t complete_percent; /*<  complete percent*/
 uint32_t photo_counts; /*<  take photo counts*/
 uint8_t status; /*<  mission status*/
} mavlink_wk_mission_state_t;

#define MAVLINK_MSG_ID_WK_MISSION_STATE_LEN 21
#define MAVLINK_MSG_ID_WK_MISSION_STATE_MIN_LEN 21
#define MAVLINK_MSG_ID_8005_LEN 21
#define MAVLINK_MSG_ID_8005_MIN_LEN 21

#define MAVLINK_MSG_ID_WK_MISSION_STATE_CRC 166
#define MAVLINK_MSG_ID_8005_CRC 166



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_MISSION_STATE { \
    8005, \
    "WK_MISSION_STATE", \
    6, \
    {  { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_wk_mission_state_t, status) }, \
         { "next_cmd_seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_mission_state_t, next_cmd_seq) }, \
         { "total_distance", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_mission_state_t, total_distance) }, \
         { "complete_distance", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_mission_state_t, complete_distance) }, \
         { "complete_percent", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_wk_mission_state_t, complete_percent) }, \
         { "photo_counts", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_wk_mission_state_t, photo_counts) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_MISSION_STATE { \
    "WK_MISSION_STATE", \
    6, \
    {  { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_wk_mission_state_t, status) }, \
         { "next_cmd_seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_mission_state_t, next_cmd_seq) }, \
         { "total_distance", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_mission_state_t, total_distance) }, \
         { "complete_distance", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_mission_state_t, complete_distance) }, \
         { "complete_percent", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_wk_mission_state_t, complete_percent) }, \
         { "photo_counts", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_wk_mission_state_t, photo_counts) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_mission_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param status  mission status
 * @param next_cmd_seq  next command seq
 * @param total_distance  total distance,unit meters
 * @param complete_distance  complete distance,unit meters
 * @param complete_percent  complete percent
 * @param photo_counts  take photo counts
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_mission_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t status, uint32_t next_cmd_seq, float total_distance, float complete_distance, uint32_t complete_percent, uint32_t photo_counts)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MISSION_STATE_LEN];
    _mav_put_uint32_t(buf, 0, next_cmd_seq);
    _mav_put_float(buf, 4, total_distance);
    _mav_put_float(buf, 8, complete_distance);
    _mav_put_uint32_t(buf, 12, complete_percent);
    _mav_put_uint32_t(buf, 16, photo_counts);
    _mav_put_uint8_t(buf, 20, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_MISSION_STATE_LEN);
#else
    mavlink_wk_mission_state_t packet;
    packet.next_cmd_seq = next_cmd_seq;
    packet.total_distance = total_distance;
    packet.complete_distance = complete_distance;
    packet.complete_percent = complete_percent;
    packet.photo_counts = photo_counts;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_MISSION_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_MISSION_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_MISSION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_MISSION_STATE_LEN, MAVLINK_MSG_ID_WK_MISSION_STATE_CRC);
}

/**
 * @brief Pack a wk_mission_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param status  mission status
 * @param next_cmd_seq  next command seq
 * @param total_distance  total distance,unit meters
 * @param complete_distance  complete distance,unit meters
 * @param complete_percent  complete percent
 * @param photo_counts  take photo counts
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_mission_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t status,uint32_t next_cmd_seq,float total_distance,float complete_distance,uint32_t complete_percent,uint32_t photo_counts)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MISSION_STATE_LEN];
    _mav_put_uint32_t(buf, 0, next_cmd_seq);
    _mav_put_float(buf, 4, total_distance);
    _mav_put_float(buf, 8, complete_distance);
    _mav_put_uint32_t(buf, 12, complete_percent);
    _mav_put_uint32_t(buf, 16, photo_counts);
    _mav_put_uint8_t(buf, 20, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_MISSION_STATE_LEN);
#else
    mavlink_wk_mission_state_t packet;
    packet.next_cmd_seq = next_cmd_seq;
    packet.total_distance = total_distance;
    packet.complete_distance = complete_distance;
    packet.complete_percent = complete_percent;
    packet.photo_counts = photo_counts;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_MISSION_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_MISSION_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_MISSION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_MISSION_STATE_LEN, MAVLINK_MSG_ID_WK_MISSION_STATE_CRC);
}

/**
 * @brief Encode a wk_mission_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_mission_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_mission_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_mission_state_t* wk_mission_state)
{
    return mavlink_msg_wk_mission_state_pack(system_id, component_id, msg, wk_mission_state->status, wk_mission_state->next_cmd_seq, wk_mission_state->total_distance, wk_mission_state->complete_distance, wk_mission_state->complete_percent, wk_mission_state->photo_counts);
}

/**
 * @brief Encode a wk_mission_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_mission_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_mission_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_mission_state_t* wk_mission_state)
{
    return mavlink_msg_wk_mission_state_pack_chan(system_id, component_id, chan, msg, wk_mission_state->status, wk_mission_state->next_cmd_seq, wk_mission_state->total_distance, wk_mission_state->complete_distance, wk_mission_state->complete_percent, wk_mission_state->photo_counts);
}

/**
 * @brief Send a wk_mission_state message
 * @param chan MAVLink channel to send the message
 *
 * @param status  mission status
 * @param next_cmd_seq  next command seq
 * @param total_distance  total distance,unit meters
 * @param complete_distance  complete distance,unit meters
 * @param complete_percent  complete percent
 * @param photo_counts  take photo counts
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_mission_state_send(mavlink_channel_t chan, uint8_t status, uint32_t next_cmd_seq, float total_distance, float complete_distance, uint32_t complete_percent, uint32_t photo_counts)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MISSION_STATE_LEN];
    _mav_put_uint32_t(buf, 0, next_cmd_seq);
    _mav_put_float(buf, 4, total_distance);
    _mav_put_float(buf, 8, complete_distance);
    _mav_put_uint32_t(buf, 12, complete_percent);
    _mav_put_uint32_t(buf, 16, photo_counts);
    _mav_put_uint8_t(buf, 20, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MISSION_STATE, buf, MAVLINK_MSG_ID_WK_MISSION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_MISSION_STATE_LEN, MAVLINK_MSG_ID_WK_MISSION_STATE_CRC);
#else
    mavlink_wk_mission_state_t packet;
    packet.next_cmd_seq = next_cmd_seq;
    packet.total_distance = total_distance;
    packet.complete_distance = complete_distance;
    packet.complete_percent = complete_percent;
    packet.photo_counts = photo_counts;
    packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MISSION_STATE, (const char *)&packet, MAVLINK_MSG_ID_WK_MISSION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_MISSION_STATE_LEN, MAVLINK_MSG_ID_WK_MISSION_STATE_CRC);
#endif
}

/**
 * @brief Send a wk_mission_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_mission_state_send_struct(mavlink_channel_t chan, const mavlink_wk_mission_state_t* wk_mission_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_mission_state_send(chan, wk_mission_state->status, wk_mission_state->next_cmd_seq, wk_mission_state->total_distance, wk_mission_state->complete_distance, wk_mission_state->complete_percent, wk_mission_state->photo_counts);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MISSION_STATE, (const char *)wk_mission_state, MAVLINK_MSG_ID_WK_MISSION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_MISSION_STATE_LEN, MAVLINK_MSG_ID_WK_MISSION_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_MISSION_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_mission_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t status, uint32_t next_cmd_seq, float total_distance, float complete_distance, uint32_t complete_percent, uint32_t photo_counts)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, next_cmd_seq);
    _mav_put_float(buf, 4, total_distance);
    _mav_put_float(buf, 8, complete_distance);
    _mav_put_uint32_t(buf, 12, complete_percent);
    _mav_put_uint32_t(buf, 16, photo_counts);
    _mav_put_uint8_t(buf, 20, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MISSION_STATE, buf, MAVLINK_MSG_ID_WK_MISSION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_MISSION_STATE_LEN, MAVLINK_MSG_ID_WK_MISSION_STATE_CRC);
#else
    mavlink_wk_mission_state_t *packet = (mavlink_wk_mission_state_t *)msgbuf;
    packet->next_cmd_seq = next_cmd_seq;
    packet->total_distance = total_distance;
    packet->complete_distance = complete_distance;
    packet->complete_percent = complete_percent;
    packet->photo_counts = photo_counts;
    packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MISSION_STATE, (const char *)packet, MAVLINK_MSG_ID_WK_MISSION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_MISSION_STATE_LEN, MAVLINK_MSG_ID_WK_MISSION_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_MISSION_STATE UNPACKING


/**
 * @brief Get field status from wk_mission_state message
 *
 * @return  mission status
 */
static inline uint8_t mavlink_msg_wk_mission_state_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field next_cmd_seq from wk_mission_state message
 *
 * @return  next command seq
 */
static inline uint32_t mavlink_msg_wk_mission_state_get_next_cmd_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field total_distance from wk_mission_state message
 *
 * @return  total distance,unit meters
 */
static inline float mavlink_msg_wk_mission_state_get_total_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field complete_distance from wk_mission_state message
 *
 * @return  complete distance,unit meters
 */
static inline float mavlink_msg_wk_mission_state_get_complete_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field complete_percent from wk_mission_state message
 *
 * @return  complete percent
 */
static inline uint32_t mavlink_msg_wk_mission_state_get_complete_percent(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field photo_counts from wk_mission_state message
 *
 * @return  take photo counts
 */
static inline uint32_t mavlink_msg_wk_mission_state_get_photo_counts(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Decode a wk_mission_state message into a struct
 *
 * @param msg The message to decode
 * @param wk_mission_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_mission_state_decode(const mavlink_message_t* msg, mavlink_wk_mission_state_t* wk_mission_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_mission_state->next_cmd_seq = mavlink_msg_wk_mission_state_get_next_cmd_seq(msg);
    wk_mission_state->total_distance = mavlink_msg_wk_mission_state_get_total_distance(msg);
    wk_mission_state->complete_distance = mavlink_msg_wk_mission_state_get_complete_distance(msg);
    wk_mission_state->complete_percent = mavlink_msg_wk_mission_state_get_complete_percent(msg);
    wk_mission_state->photo_counts = mavlink_msg_wk_mission_state_get_photo_counts(msg);
    wk_mission_state->status = mavlink_msg_wk_mission_state_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_MISSION_STATE_LEN? msg->len : MAVLINK_MSG_ID_WK_MISSION_STATE_LEN;
        memset(wk_mission_state, 0, MAVLINK_MSG_ID_WK_MISSION_STATE_LEN);
    memcpy(wk_mission_state, _MAV_PAYLOAD(msg), len);
#endif
}
