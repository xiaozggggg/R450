#pragma once
// MESSAGE WK_BUOY_RECGONIZE_STATE PACKING

#define MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE 8024


typedef struct __mavlink_wk_buoy_recgonize_state_t {
 uint16_t cmd_index; /*<  mission cmd index*/
 uint8_t state; /*<  0:idle,1:start,2:recgonize success,3:start advanced-recgonizing,4:timeout*/
} mavlink_wk_buoy_recgonize_state_t;

#define MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN 3
#define MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_MIN_LEN 3
#define MAVLINK_MSG_ID_8024_LEN 3
#define MAVLINK_MSG_ID_8024_MIN_LEN 3

#define MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_CRC 96
#define MAVLINK_MSG_ID_8024_CRC 96



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_BUOY_RECGONIZE_STATE { \
    8024, \
    "WK_BUOY_RECGONIZE_STATE", \
    2, \
    {  { "cmd_index", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wk_buoy_recgonize_state_t, cmd_index) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_buoy_recgonize_state_t, state) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_BUOY_RECGONIZE_STATE { \
    "WK_BUOY_RECGONIZE_STATE", \
    2, \
    {  { "cmd_index", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wk_buoy_recgonize_state_t, cmd_index) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_buoy_recgonize_state_t, state) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_buoy_recgonize_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param cmd_index  mission cmd index
 * @param state  0:idle,1:start,2:recgonize success,3:start advanced-recgonizing,4:timeout
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_buoy_recgonize_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t cmd_index, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN];
    _mav_put_uint16_t(buf, 0, cmd_index);
    _mav_put_uint8_t(buf, 2, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN);
#else
    mavlink_wk_buoy_recgonize_state_t packet;
    packet.cmd_index = cmd_index;
    packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_CRC);
}

/**
 * @brief Pack a wk_buoy_recgonize_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_index  mission cmd index
 * @param state  0:idle,1:start,2:recgonize success,3:start advanced-recgonizing,4:timeout
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_buoy_recgonize_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t cmd_index,uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN];
    _mav_put_uint16_t(buf, 0, cmd_index);
    _mav_put_uint8_t(buf, 2, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN);
#else
    mavlink_wk_buoy_recgonize_state_t packet;
    packet.cmd_index = cmd_index;
    packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_CRC);
}

/**
 * @brief Encode a wk_buoy_recgonize_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_buoy_recgonize_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_buoy_recgonize_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_buoy_recgonize_state_t* wk_buoy_recgonize_state)
{
    return mavlink_msg_wk_buoy_recgonize_state_pack(system_id, component_id, msg, wk_buoy_recgonize_state->cmd_index, wk_buoy_recgonize_state->state);
}

/**
 * @brief Encode a wk_buoy_recgonize_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_buoy_recgonize_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_buoy_recgonize_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_buoy_recgonize_state_t* wk_buoy_recgonize_state)
{
    return mavlink_msg_wk_buoy_recgonize_state_pack_chan(system_id, component_id, chan, msg, wk_buoy_recgonize_state->cmd_index, wk_buoy_recgonize_state->state);
}

/**
 * @brief Send a wk_buoy_recgonize_state message
 * @param chan MAVLink channel to send the message
 *
 * @param cmd_index  mission cmd index
 * @param state  0:idle,1:start,2:recgonize success,3:start advanced-recgonizing,4:timeout
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_buoy_recgonize_state_send(mavlink_channel_t chan, uint16_t cmd_index, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN];
    _mav_put_uint16_t(buf, 0, cmd_index);
    _mav_put_uint8_t(buf, 2, state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE, buf, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_CRC);
#else
    mavlink_wk_buoy_recgonize_state_t packet;
    packet.cmd_index = cmd_index;
    packet.state = state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE, (const char *)&packet, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_CRC);
#endif
}

/**
 * @brief Send a wk_buoy_recgonize_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_buoy_recgonize_state_send_struct(mavlink_channel_t chan, const mavlink_wk_buoy_recgonize_state_t* wk_buoy_recgonize_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_buoy_recgonize_state_send(chan, wk_buoy_recgonize_state->cmd_index, wk_buoy_recgonize_state->state);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE, (const char *)wk_buoy_recgonize_state, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_buoy_recgonize_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t cmd_index, uint8_t state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, cmd_index);
    _mav_put_uint8_t(buf, 2, state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE, buf, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_CRC);
#else
    mavlink_wk_buoy_recgonize_state_t *packet = (mavlink_wk_buoy_recgonize_state_t *)msgbuf;
    packet->cmd_index = cmd_index;
    packet->state = state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE, (const char *)packet, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_BUOY_RECGONIZE_STATE UNPACKING


/**
 * @brief Get field cmd_index from wk_buoy_recgonize_state message
 *
 * @return  mission cmd index
 */
static inline uint16_t mavlink_msg_wk_buoy_recgonize_state_get_cmd_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field state from wk_buoy_recgonize_state message
 *
 * @return  0:idle,1:start,2:recgonize success,3:start advanced-recgonizing,4:timeout
 */
static inline uint8_t mavlink_msg_wk_buoy_recgonize_state_get_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a wk_buoy_recgonize_state message into a struct
 *
 * @param msg The message to decode
 * @param wk_buoy_recgonize_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_buoy_recgonize_state_decode(const mavlink_message_t* msg, mavlink_wk_buoy_recgonize_state_t* wk_buoy_recgonize_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_buoy_recgonize_state->cmd_index = mavlink_msg_wk_buoy_recgonize_state_get_cmd_index(msg);
    wk_buoy_recgonize_state->state = mavlink_msg_wk_buoy_recgonize_state_get_state(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN? msg->len : MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN;
        memset(wk_buoy_recgonize_state, 0, MAVLINK_MSG_ID_WK_BUOY_RECGONIZE_STATE_LEN);
    memcpy(wk_buoy_recgonize_state, _MAV_PAYLOAD(msg), len);
#endif
}
