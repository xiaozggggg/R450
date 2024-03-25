#pragma once
// MESSAGE WK_FLIGHT_STATE PACKING

#define MAVLINK_MSG_ID_WK_FLIGHT_STATE 8006


typedef struct __mavlink_wk_flight_state_t {
 uint8_t flight_state; /*<  see WK_FLIGHT_STATE*/
} mavlink_wk_flight_state_t;

#define MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN 1
#define MAVLINK_MSG_ID_WK_FLIGHT_STATE_MIN_LEN 1
#define MAVLINK_MSG_ID_8006_LEN 1
#define MAVLINK_MSG_ID_8006_MIN_LEN 1

#define MAVLINK_MSG_ID_WK_FLIGHT_STATE_CRC 66
#define MAVLINK_MSG_ID_8006_CRC 66



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_FLIGHT_STATE { \
    8006, \
    "WK_FLIGHT_STATE", \
    1, \
    {  { "flight_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_flight_state_t, flight_state) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_FLIGHT_STATE { \
    "WK_FLIGHT_STATE", \
    1, \
    {  { "flight_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_flight_state_t, flight_state) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_flight_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param flight_state  see WK_FLIGHT_STATE
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_flight_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t flight_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN];
    _mav_put_uint8_t(buf, 0, flight_state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN);
#else
    mavlink_wk_flight_state_t packet;
    packet.flight_state = flight_state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_FLIGHT_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_FLIGHT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN, MAVLINK_MSG_ID_WK_FLIGHT_STATE_CRC);
}

/**
 * @brief Pack a wk_flight_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param flight_state  see WK_FLIGHT_STATE
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_flight_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t flight_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN];
    _mav_put_uint8_t(buf, 0, flight_state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN);
#else
    mavlink_wk_flight_state_t packet;
    packet.flight_state = flight_state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_FLIGHT_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_FLIGHT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN, MAVLINK_MSG_ID_WK_FLIGHT_STATE_CRC);
}

/**
 * @brief Encode a wk_flight_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_flight_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_flight_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_flight_state_t* wk_flight_state)
{
    return mavlink_msg_wk_flight_state_pack(system_id, component_id, msg, wk_flight_state->flight_state);
}

/**
 * @brief Encode a wk_flight_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_flight_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_flight_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_flight_state_t* wk_flight_state)
{
    return mavlink_msg_wk_flight_state_pack_chan(system_id, component_id, chan, msg, wk_flight_state->flight_state);
}

/**
 * @brief Send a wk_flight_state message
 * @param chan MAVLink channel to send the message
 *
 * @param flight_state  see WK_FLIGHT_STATE
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_flight_state_send(mavlink_channel_t chan, uint8_t flight_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN];
    _mav_put_uint8_t(buf, 0, flight_state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_FLIGHT_STATE, buf, MAVLINK_MSG_ID_WK_FLIGHT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN, MAVLINK_MSG_ID_WK_FLIGHT_STATE_CRC);
#else
    mavlink_wk_flight_state_t packet;
    packet.flight_state = flight_state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_FLIGHT_STATE, (const char *)&packet, MAVLINK_MSG_ID_WK_FLIGHT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN, MAVLINK_MSG_ID_WK_FLIGHT_STATE_CRC);
#endif
}

/**
 * @brief Send a wk_flight_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_flight_state_send_struct(mavlink_channel_t chan, const mavlink_wk_flight_state_t* wk_flight_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_flight_state_send(chan, wk_flight_state->flight_state);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_FLIGHT_STATE, (const char *)wk_flight_state, MAVLINK_MSG_ID_WK_FLIGHT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN, MAVLINK_MSG_ID_WK_FLIGHT_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_flight_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t flight_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, flight_state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_FLIGHT_STATE, buf, MAVLINK_MSG_ID_WK_FLIGHT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN, MAVLINK_MSG_ID_WK_FLIGHT_STATE_CRC);
#else
    mavlink_wk_flight_state_t *packet = (mavlink_wk_flight_state_t *)msgbuf;
    packet->flight_state = flight_state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_FLIGHT_STATE, (const char *)packet, MAVLINK_MSG_ID_WK_FLIGHT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN, MAVLINK_MSG_ID_WK_FLIGHT_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_FLIGHT_STATE UNPACKING


/**
 * @brief Get field flight_state from wk_flight_state message
 *
 * @return  see WK_FLIGHT_STATE
 */
static inline uint8_t mavlink_msg_wk_flight_state_get_flight_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a wk_flight_state message into a struct
 *
 * @param msg The message to decode
 * @param wk_flight_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_flight_state_decode(const mavlink_message_t* msg, mavlink_wk_flight_state_t* wk_flight_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_flight_state->flight_state = mavlink_msg_wk_flight_state_get_flight_state(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN? msg->len : MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN;
        memset(wk_flight_state, 0, MAVLINK_MSG_ID_WK_FLIGHT_STATE_LEN);
    memcpy(wk_flight_state, _MAV_PAYLOAD(msg), len);
#endif
}
