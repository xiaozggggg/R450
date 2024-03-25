#pragma once
// MESSAGE WK_TOF_CALI_STATE PACKING

#define MAVLINK_MSG_ID_WK_TOF_CALI_STATE 8520


typedef struct __mavlink_wk_tof_cali_state_t {
 float phase_temperature; /*<  */
 uint8_t mag_cali_state; /*<  */
 uint8_t xtalk_cali_state; /*<  */
 uint8_t distance_cali_state; /*<  */
 uint8_t temp_cali_state; /*<  */
 uint8_t light_cali_state; /*<  */
 uint8_t crosstalkgainMSB; /*<  */
} mavlink_wk_tof_cali_state_t;

#define MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN 10
#define MAVLINK_MSG_ID_WK_TOF_CALI_STATE_MIN_LEN 10
#define MAVLINK_MSG_ID_8520_LEN 10
#define MAVLINK_MSG_ID_8520_MIN_LEN 10

#define MAVLINK_MSG_ID_WK_TOF_CALI_STATE_CRC 199
#define MAVLINK_MSG_ID_8520_CRC 199



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_TOF_CALI_STATE { \
    8520, \
    "WK_TOF_CALI_STATE", \
    7, \
    {  { "mag_cali_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_tof_cali_state_t, mag_cali_state) }, \
         { "xtalk_cali_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_tof_cali_state_t, xtalk_cali_state) }, \
         { "distance_cali_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_tof_cali_state_t, distance_cali_state) }, \
         { "temp_cali_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_wk_tof_cali_state_t, temp_cali_state) }, \
         { "light_cali_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wk_tof_cali_state_t, light_cali_state) }, \
         { "crosstalkgainMSB", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_wk_tof_cali_state_t, crosstalkgainMSB) }, \
         { "phase_temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_tof_cali_state_t, phase_temperature) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_TOF_CALI_STATE { \
    "WK_TOF_CALI_STATE", \
    7, \
    {  { "mag_cali_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_tof_cali_state_t, mag_cali_state) }, \
         { "xtalk_cali_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_tof_cali_state_t, xtalk_cali_state) }, \
         { "distance_cali_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_tof_cali_state_t, distance_cali_state) }, \
         { "temp_cali_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_wk_tof_cali_state_t, temp_cali_state) }, \
         { "light_cali_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wk_tof_cali_state_t, light_cali_state) }, \
         { "crosstalkgainMSB", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_wk_tof_cali_state_t, crosstalkgainMSB) }, \
         { "phase_temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_tof_cali_state_t, phase_temperature) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_tof_cali_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mag_cali_state  
 * @param xtalk_cali_state  
 * @param distance_cali_state  
 * @param temp_cali_state  
 * @param light_cali_state  
 * @param crosstalkgainMSB  
 * @param phase_temperature  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_tof_cali_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t mag_cali_state, uint8_t xtalk_cali_state, uint8_t distance_cali_state, uint8_t temp_cali_state, uint8_t light_cali_state, uint8_t crosstalkgainMSB, float phase_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN];
    _mav_put_float(buf, 0, phase_temperature);
    _mav_put_uint8_t(buf, 4, mag_cali_state);
    _mav_put_uint8_t(buf, 5, xtalk_cali_state);
    _mav_put_uint8_t(buf, 6, distance_cali_state);
    _mav_put_uint8_t(buf, 7, temp_cali_state);
    _mav_put_uint8_t(buf, 8, light_cali_state);
    _mav_put_uint8_t(buf, 9, crosstalkgainMSB);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN);
#else
    mavlink_wk_tof_cali_state_t packet;
    packet.phase_temperature = phase_temperature;
    packet.mag_cali_state = mag_cali_state;
    packet.xtalk_cali_state = xtalk_cali_state;
    packet.distance_cali_state = distance_cali_state;
    packet.temp_cali_state = temp_cali_state;
    packet.light_cali_state = light_cali_state;
    packet.crosstalkgainMSB = crosstalkgainMSB;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_TOF_CALI_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_CRC);
}

/**
 * @brief Pack a wk_tof_cali_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mag_cali_state  
 * @param xtalk_cali_state  
 * @param distance_cali_state  
 * @param temp_cali_state  
 * @param light_cali_state  
 * @param crosstalkgainMSB  
 * @param phase_temperature  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_tof_cali_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t mag_cali_state,uint8_t xtalk_cali_state,uint8_t distance_cali_state,uint8_t temp_cali_state,uint8_t light_cali_state,uint8_t crosstalkgainMSB,float phase_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN];
    _mav_put_float(buf, 0, phase_temperature);
    _mav_put_uint8_t(buf, 4, mag_cali_state);
    _mav_put_uint8_t(buf, 5, xtalk_cali_state);
    _mav_put_uint8_t(buf, 6, distance_cali_state);
    _mav_put_uint8_t(buf, 7, temp_cali_state);
    _mav_put_uint8_t(buf, 8, light_cali_state);
    _mav_put_uint8_t(buf, 9, crosstalkgainMSB);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN);
#else
    mavlink_wk_tof_cali_state_t packet;
    packet.phase_temperature = phase_temperature;
    packet.mag_cali_state = mag_cali_state;
    packet.xtalk_cali_state = xtalk_cali_state;
    packet.distance_cali_state = distance_cali_state;
    packet.temp_cali_state = temp_cali_state;
    packet.light_cali_state = light_cali_state;
    packet.crosstalkgainMSB = crosstalkgainMSB;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_TOF_CALI_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_CRC);
}

/**
 * @brief Encode a wk_tof_cali_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_tof_cali_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_tof_cali_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_tof_cali_state_t* wk_tof_cali_state)
{
    return mavlink_msg_wk_tof_cali_state_pack(system_id, component_id, msg, wk_tof_cali_state->mag_cali_state, wk_tof_cali_state->xtalk_cali_state, wk_tof_cali_state->distance_cali_state, wk_tof_cali_state->temp_cali_state, wk_tof_cali_state->light_cali_state, wk_tof_cali_state->crosstalkgainMSB, wk_tof_cali_state->phase_temperature);
}

/**
 * @brief Encode a wk_tof_cali_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_tof_cali_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_tof_cali_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_tof_cali_state_t* wk_tof_cali_state)
{
    return mavlink_msg_wk_tof_cali_state_pack_chan(system_id, component_id, chan, msg, wk_tof_cali_state->mag_cali_state, wk_tof_cali_state->xtalk_cali_state, wk_tof_cali_state->distance_cali_state, wk_tof_cali_state->temp_cali_state, wk_tof_cali_state->light_cali_state, wk_tof_cali_state->crosstalkgainMSB, wk_tof_cali_state->phase_temperature);
}

/**
 * @brief Send a wk_tof_cali_state message
 * @param chan MAVLink channel to send the message
 *
 * @param mag_cali_state  
 * @param xtalk_cali_state  
 * @param distance_cali_state  
 * @param temp_cali_state  
 * @param light_cali_state  
 * @param crosstalkgainMSB  
 * @param phase_temperature  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_tof_cali_state_send(mavlink_channel_t chan, uint8_t mag_cali_state, uint8_t xtalk_cali_state, uint8_t distance_cali_state, uint8_t temp_cali_state, uint8_t light_cali_state, uint8_t crosstalkgainMSB, float phase_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN];
    _mav_put_float(buf, 0, phase_temperature);
    _mav_put_uint8_t(buf, 4, mag_cali_state);
    _mav_put_uint8_t(buf, 5, xtalk_cali_state);
    _mav_put_uint8_t(buf, 6, distance_cali_state);
    _mav_put_uint8_t(buf, 7, temp_cali_state);
    _mav_put_uint8_t(buf, 8, light_cali_state);
    _mav_put_uint8_t(buf, 9, crosstalkgainMSB);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CALI_STATE, buf, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_CRC);
#else
    mavlink_wk_tof_cali_state_t packet;
    packet.phase_temperature = phase_temperature;
    packet.mag_cali_state = mag_cali_state;
    packet.xtalk_cali_state = xtalk_cali_state;
    packet.distance_cali_state = distance_cali_state;
    packet.temp_cali_state = temp_cali_state;
    packet.light_cali_state = light_cali_state;
    packet.crosstalkgainMSB = crosstalkgainMSB;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CALI_STATE, (const char *)&packet, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_CRC);
#endif
}

/**
 * @brief Send a wk_tof_cali_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_tof_cali_state_send_struct(mavlink_channel_t chan, const mavlink_wk_tof_cali_state_t* wk_tof_cali_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_tof_cali_state_send(chan, wk_tof_cali_state->mag_cali_state, wk_tof_cali_state->xtalk_cali_state, wk_tof_cali_state->distance_cali_state, wk_tof_cali_state->temp_cali_state, wk_tof_cali_state->light_cali_state, wk_tof_cali_state->crosstalkgainMSB, wk_tof_cali_state->phase_temperature);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CALI_STATE, (const char *)wk_tof_cali_state, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_tof_cali_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t mag_cali_state, uint8_t xtalk_cali_state, uint8_t distance_cali_state, uint8_t temp_cali_state, uint8_t light_cali_state, uint8_t crosstalkgainMSB, float phase_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, phase_temperature);
    _mav_put_uint8_t(buf, 4, mag_cali_state);
    _mav_put_uint8_t(buf, 5, xtalk_cali_state);
    _mav_put_uint8_t(buf, 6, distance_cali_state);
    _mav_put_uint8_t(buf, 7, temp_cali_state);
    _mav_put_uint8_t(buf, 8, light_cali_state);
    _mav_put_uint8_t(buf, 9, crosstalkgainMSB);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CALI_STATE, buf, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_CRC);
#else
    mavlink_wk_tof_cali_state_t *packet = (mavlink_wk_tof_cali_state_t *)msgbuf;
    packet->phase_temperature = phase_temperature;
    packet->mag_cali_state = mag_cali_state;
    packet->xtalk_cali_state = xtalk_cali_state;
    packet->distance_cali_state = distance_cali_state;
    packet->temp_cali_state = temp_cali_state;
    packet->light_cali_state = light_cali_state;
    packet->crosstalkgainMSB = crosstalkgainMSB;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CALI_STATE, (const char *)packet, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_TOF_CALI_STATE UNPACKING


/**
 * @brief Get field mag_cali_state from wk_tof_cali_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_cali_state_get_mag_cali_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field xtalk_cali_state from wk_tof_cali_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_cali_state_get_xtalk_cali_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field distance_cali_state from wk_tof_cali_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_cali_state_get_distance_cali_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field temp_cali_state from wk_tof_cali_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_cali_state_get_temp_cali_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field light_cali_state from wk_tof_cali_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_cali_state_get_light_cali_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field crosstalkgainMSB from wk_tof_cali_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_cali_state_get_crosstalkgainMSB(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field phase_temperature from wk_tof_cali_state message
 *
 * @return  
 */
static inline float mavlink_msg_wk_tof_cali_state_get_phase_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a wk_tof_cali_state message into a struct
 *
 * @param msg The message to decode
 * @param wk_tof_cali_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_tof_cali_state_decode(const mavlink_message_t* msg, mavlink_wk_tof_cali_state_t* wk_tof_cali_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_tof_cali_state->phase_temperature = mavlink_msg_wk_tof_cali_state_get_phase_temperature(msg);
    wk_tof_cali_state->mag_cali_state = mavlink_msg_wk_tof_cali_state_get_mag_cali_state(msg);
    wk_tof_cali_state->xtalk_cali_state = mavlink_msg_wk_tof_cali_state_get_xtalk_cali_state(msg);
    wk_tof_cali_state->distance_cali_state = mavlink_msg_wk_tof_cali_state_get_distance_cali_state(msg);
    wk_tof_cali_state->temp_cali_state = mavlink_msg_wk_tof_cali_state_get_temp_cali_state(msg);
    wk_tof_cali_state->light_cali_state = mavlink_msg_wk_tof_cali_state_get_light_cali_state(msg);
    wk_tof_cali_state->crosstalkgainMSB = mavlink_msg_wk_tof_cali_state_get_crosstalkgainMSB(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN? msg->len : MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN;
        memset(wk_tof_cali_state, 0, MAVLINK_MSG_ID_WK_TOF_CALI_STATE_LEN);
    memcpy(wk_tof_cali_state, _MAV_PAYLOAD(msg), len);
#endif
}
