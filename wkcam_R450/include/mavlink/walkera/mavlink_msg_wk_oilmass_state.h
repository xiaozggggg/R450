#pragma once
// MESSAGE WK_OILMASS_STATE PACKING

#define MAVLINK_MSG_ID_WK_OILMASS_STATE 8022


typedef struct __mavlink_wk_oilmass_state_t {
 uint32_t current_oil_mass; /*<  current oil mass remian(ml)*/
 uint32_t total_oil_mass; /*<  total oil mass set(ml)*/
 uint32_t percent; /*<  current oil mass remain(percent)*/
 uint32_t remainder_range; /*<  remainder distance range(m)*/
} mavlink_wk_oilmass_state_t;

#define MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN 16
#define MAVLINK_MSG_ID_WK_OILMASS_STATE_MIN_LEN 16
#define MAVLINK_MSG_ID_8022_LEN 16
#define MAVLINK_MSG_ID_8022_MIN_LEN 16

#define MAVLINK_MSG_ID_WK_OILMASS_STATE_CRC 142
#define MAVLINK_MSG_ID_8022_CRC 142



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_OILMASS_STATE { \
    8022, \
    "WK_OILMASS_STATE", \
    4, \
    {  { "current_oil_mass", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_oilmass_state_t, current_oil_mass) }, \
         { "total_oil_mass", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_oilmass_state_t, total_oil_mass) }, \
         { "percent", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_oilmass_state_t, percent) }, \
         { "remainder_range", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_wk_oilmass_state_t, remainder_range) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_OILMASS_STATE { \
    "WK_OILMASS_STATE", \
    4, \
    {  { "current_oil_mass", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_oilmass_state_t, current_oil_mass) }, \
         { "total_oil_mass", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_oilmass_state_t, total_oil_mass) }, \
         { "percent", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_oilmass_state_t, percent) }, \
         { "remainder_range", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_wk_oilmass_state_t, remainder_range) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_oilmass_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param current_oil_mass  current oil mass remian(ml)
 * @param total_oil_mass  total oil mass set(ml)
 * @param percent  current oil mass remain(percent)
 * @param remainder_range  remainder distance range(m)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_oilmass_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t current_oil_mass, uint32_t total_oil_mass, uint32_t percent, uint32_t remainder_range)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN];
    _mav_put_uint32_t(buf, 0, current_oil_mass);
    _mav_put_uint32_t(buf, 4, total_oil_mass);
    _mav_put_uint32_t(buf, 8, percent);
    _mav_put_uint32_t(buf, 12, remainder_range);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN);
#else
    mavlink_wk_oilmass_state_t packet;
    packet.current_oil_mass = current_oil_mass;
    packet.total_oil_mass = total_oil_mass;
    packet.percent = percent;
    packet.remainder_range = remainder_range;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_OILMASS_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_OILMASS_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN, MAVLINK_MSG_ID_WK_OILMASS_STATE_CRC);
}

/**
 * @brief Pack a wk_oilmass_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param current_oil_mass  current oil mass remian(ml)
 * @param total_oil_mass  total oil mass set(ml)
 * @param percent  current oil mass remain(percent)
 * @param remainder_range  remainder distance range(m)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_oilmass_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t current_oil_mass,uint32_t total_oil_mass,uint32_t percent,uint32_t remainder_range)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN];
    _mav_put_uint32_t(buf, 0, current_oil_mass);
    _mav_put_uint32_t(buf, 4, total_oil_mass);
    _mav_put_uint32_t(buf, 8, percent);
    _mav_put_uint32_t(buf, 12, remainder_range);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN);
#else
    mavlink_wk_oilmass_state_t packet;
    packet.current_oil_mass = current_oil_mass;
    packet.total_oil_mass = total_oil_mass;
    packet.percent = percent;
    packet.remainder_range = remainder_range;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_OILMASS_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_OILMASS_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN, MAVLINK_MSG_ID_WK_OILMASS_STATE_CRC);
}

/**
 * @brief Encode a wk_oilmass_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_oilmass_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_oilmass_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_oilmass_state_t* wk_oilmass_state)
{
    return mavlink_msg_wk_oilmass_state_pack(system_id, component_id, msg, wk_oilmass_state->current_oil_mass, wk_oilmass_state->total_oil_mass, wk_oilmass_state->percent, wk_oilmass_state->remainder_range);
}

/**
 * @brief Encode a wk_oilmass_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_oilmass_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_oilmass_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_oilmass_state_t* wk_oilmass_state)
{
    return mavlink_msg_wk_oilmass_state_pack_chan(system_id, component_id, chan, msg, wk_oilmass_state->current_oil_mass, wk_oilmass_state->total_oil_mass, wk_oilmass_state->percent, wk_oilmass_state->remainder_range);
}

/**
 * @brief Send a wk_oilmass_state message
 * @param chan MAVLink channel to send the message
 *
 * @param current_oil_mass  current oil mass remian(ml)
 * @param total_oil_mass  total oil mass set(ml)
 * @param percent  current oil mass remain(percent)
 * @param remainder_range  remainder distance range(m)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_oilmass_state_send(mavlink_channel_t chan, uint32_t current_oil_mass, uint32_t total_oil_mass, uint32_t percent, uint32_t remainder_range)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN];
    _mav_put_uint32_t(buf, 0, current_oil_mass);
    _mav_put_uint32_t(buf, 4, total_oil_mass);
    _mav_put_uint32_t(buf, 8, percent);
    _mav_put_uint32_t(buf, 12, remainder_range);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_OILMASS_STATE, buf, MAVLINK_MSG_ID_WK_OILMASS_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN, MAVLINK_MSG_ID_WK_OILMASS_STATE_CRC);
#else
    mavlink_wk_oilmass_state_t packet;
    packet.current_oil_mass = current_oil_mass;
    packet.total_oil_mass = total_oil_mass;
    packet.percent = percent;
    packet.remainder_range = remainder_range;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_OILMASS_STATE, (const char *)&packet, MAVLINK_MSG_ID_WK_OILMASS_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN, MAVLINK_MSG_ID_WK_OILMASS_STATE_CRC);
#endif
}

/**
 * @brief Send a wk_oilmass_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_oilmass_state_send_struct(mavlink_channel_t chan, const mavlink_wk_oilmass_state_t* wk_oilmass_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_oilmass_state_send(chan, wk_oilmass_state->current_oil_mass, wk_oilmass_state->total_oil_mass, wk_oilmass_state->percent, wk_oilmass_state->remainder_range);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_OILMASS_STATE, (const char *)wk_oilmass_state, MAVLINK_MSG_ID_WK_OILMASS_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN, MAVLINK_MSG_ID_WK_OILMASS_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_oilmass_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t current_oil_mass, uint32_t total_oil_mass, uint32_t percent, uint32_t remainder_range)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, current_oil_mass);
    _mav_put_uint32_t(buf, 4, total_oil_mass);
    _mav_put_uint32_t(buf, 8, percent);
    _mav_put_uint32_t(buf, 12, remainder_range);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_OILMASS_STATE, buf, MAVLINK_MSG_ID_WK_OILMASS_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN, MAVLINK_MSG_ID_WK_OILMASS_STATE_CRC);
#else
    mavlink_wk_oilmass_state_t *packet = (mavlink_wk_oilmass_state_t *)msgbuf;
    packet->current_oil_mass = current_oil_mass;
    packet->total_oil_mass = total_oil_mass;
    packet->percent = percent;
    packet->remainder_range = remainder_range;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_OILMASS_STATE, (const char *)packet, MAVLINK_MSG_ID_WK_OILMASS_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN, MAVLINK_MSG_ID_WK_OILMASS_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_OILMASS_STATE UNPACKING


/**
 * @brief Get field current_oil_mass from wk_oilmass_state message
 *
 * @return  current oil mass remian(ml)
 */
static inline uint32_t mavlink_msg_wk_oilmass_state_get_current_oil_mass(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field total_oil_mass from wk_oilmass_state message
 *
 * @return  total oil mass set(ml)
 */
static inline uint32_t mavlink_msg_wk_oilmass_state_get_total_oil_mass(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field percent from wk_oilmass_state message
 *
 * @return  current oil mass remain(percent)
 */
static inline uint32_t mavlink_msg_wk_oilmass_state_get_percent(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field remainder_range from wk_oilmass_state message
 *
 * @return  remainder distance range(m)
 */
static inline uint32_t mavlink_msg_wk_oilmass_state_get_remainder_range(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Decode a wk_oilmass_state message into a struct
 *
 * @param msg The message to decode
 * @param wk_oilmass_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_oilmass_state_decode(const mavlink_message_t* msg, mavlink_wk_oilmass_state_t* wk_oilmass_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_oilmass_state->current_oil_mass = mavlink_msg_wk_oilmass_state_get_current_oil_mass(msg);
    wk_oilmass_state->total_oil_mass = mavlink_msg_wk_oilmass_state_get_total_oil_mass(msg);
    wk_oilmass_state->percent = mavlink_msg_wk_oilmass_state_get_percent(msg);
    wk_oilmass_state->remainder_range = mavlink_msg_wk_oilmass_state_get_remainder_range(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN? msg->len : MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN;
        memset(wk_oilmass_state, 0, MAVLINK_MSG_ID_WK_OILMASS_STATE_LEN);
    memcpy(wk_oilmass_state, _MAV_PAYLOAD(msg), len);
#endif
}
