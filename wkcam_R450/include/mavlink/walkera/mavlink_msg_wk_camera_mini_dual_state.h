#pragma once
// MESSAGE WK_CAMERA_MINI_DUAL_STATE PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE 8070


typedef struct __mavlink_wk_camera_mini_dual_state_t {
 uint16_t max_temper_x_pos; /*<  */
 uint16_t max_temper_y_pos; /*<  */
 uint16_t max_temperature; /*<  */
 uint16_t min_temper_x_pos; /*<  */
 uint16_t min_temper_y_pos; /*<  */
 uint16_t min_temperature; /*<  */
 uint16_t cur_x_pos; /*<  */
 uint16_t cur_y_pos; /*<  */
 uint16_t cur_temperature; /*<  */
 uint16_t area_average_temperature; /*<  */
 uint8_t measure_mode; /*<  see WK_CAMERA_R500_DUAL_MEASURE_MODE*/
} mavlink_wk_camera_mini_dual_state_t;

#define MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN 21
#define MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_MIN_LEN 21
#define MAVLINK_MSG_ID_8070_LEN 21
#define MAVLINK_MSG_ID_8070_MIN_LEN 21

#define MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_CRC 5
#define MAVLINK_MSG_ID_8070_CRC 5



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_MINI_DUAL_STATE { \
    8070, \
    "WK_CAMERA_MINI_DUAL_STATE", \
    11, \
    {  { "measure_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_wk_camera_mini_dual_state_t, measure_mode) }, \
         { "max_temper_x_pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wk_camera_mini_dual_state_t, max_temper_x_pos) }, \
         { "max_temper_y_pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_wk_camera_mini_dual_state_t, max_temper_y_pos) }, \
         { "max_temperature", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_wk_camera_mini_dual_state_t, max_temperature) }, \
         { "min_temper_x_pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_wk_camera_mini_dual_state_t, min_temper_x_pos) }, \
         { "min_temper_y_pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_wk_camera_mini_dual_state_t, min_temper_y_pos) }, \
         { "min_temperature", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_wk_camera_mini_dual_state_t, min_temperature) }, \
         { "cur_x_pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_wk_camera_mini_dual_state_t, cur_x_pos) }, \
         { "cur_y_pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_wk_camera_mini_dual_state_t, cur_y_pos) }, \
         { "cur_temperature", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_wk_camera_mini_dual_state_t, cur_temperature) }, \
         { "area_average_temperature", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_wk_camera_mini_dual_state_t, area_average_temperature) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_MINI_DUAL_STATE { \
    "WK_CAMERA_MINI_DUAL_STATE", \
    11, \
    {  { "measure_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_wk_camera_mini_dual_state_t, measure_mode) }, \
         { "max_temper_x_pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wk_camera_mini_dual_state_t, max_temper_x_pos) }, \
         { "max_temper_y_pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_wk_camera_mini_dual_state_t, max_temper_y_pos) }, \
         { "max_temperature", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_wk_camera_mini_dual_state_t, max_temperature) }, \
         { "min_temper_x_pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_wk_camera_mini_dual_state_t, min_temper_x_pos) }, \
         { "min_temper_y_pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_wk_camera_mini_dual_state_t, min_temper_y_pos) }, \
         { "min_temperature", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_wk_camera_mini_dual_state_t, min_temperature) }, \
         { "cur_x_pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_wk_camera_mini_dual_state_t, cur_x_pos) }, \
         { "cur_y_pos", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_wk_camera_mini_dual_state_t, cur_y_pos) }, \
         { "cur_temperature", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_wk_camera_mini_dual_state_t, cur_temperature) }, \
         { "area_average_temperature", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_wk_camera_mini_dual_state_t, area_average_temperature) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_mini_dual_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param measure_mode  see WK_CAMERA_R500_DUAL_MEASURE_MODE
 * @param max_temper_x_pos  
 * @param max_temper_y_pos  
 * @param max_temperature  
 * @param min_temper_x_pos  
 * @param min_temper_y_pos  
 * @param min_temperature  
 * @param cur_x_pos  
 * @param cur_y_pos  
 * @param cur_temperature  
 * @param area_average_temperature  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t measure_mode, uint16_t max_temper_x_pos, uint16_t max_temper_y_pos, uint16_t max_temperature, uint16_t min_temper_x_pos, uint16_t min_temper_y_pos, uint16_t min_temperature, uint16_t cur_x_pos, uint16_t cur_y_pos, uint16_t cur_temperature, uint16_t area_average_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN];
    _mav_put_uint16_t(buf, 0, max_temper_x_pos);
    _mav_put_uint16_t(buf, 2, max_temper_y_pos);
    _mav_put_uint16_t(buf, 4, max_temperature);
    _mav_put_uint16_t(buf, 6, min_temper_x_pos);
    _mav_put_uint16_t(buf, 8, min_temper_y_pos);
    _mav_put_uint16_t(buf, 10, min_temperature);
    _mav_put_uint16_t(buf, 12, cur_x_pos);
    _mav_put_uint16_t(buf, 14, cur_y_pos);
    _mav_put_uint16_t(buf, 16, cur_temperature);
    _mav_put_uint16_t(buf, 18, area_average_temperature);
    _mav_put_uint8_t(buf, 20, measure_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN);
#else
    mavlink_wk_camera_mini_dual_state_t packet;
    packet.max_temper_x_pos = max_temper_x_pos;
    packet.max_temper_y_pos = max_temper_y_pos;
    packet.max_temperature = max_temperature;
    packet.min_temper_x_pos = min_temper_x_pos;
    packet.min_temper_y_pos = min_temper_y_pos;
    packet.min_temperature = min_temperature;
    packet.cur_x_pos = cur_x_pos;
    packet.cur_y_pos = cur_y_pos;
    packet.cur_temperature = cur_temperature;
    packet.area_average_temperature = area_average_temperature;
    packet.measure_mode = measure_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_CRC);
}

/**
 * @brief Pack a wk_camera_mini_dual_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param measure_mode  see WK_CAMERA_R500_DUAL_MEASURE_MODE
 * @param max_temper_x_pos  
 * @param max_temper_y_pos  
 * @param max_temperature  
 * @param min_temper_x_pos  
 * @param min_temper_y_pos  
 * @param min_temperature  
 * @param cur_x_pos  
 * @param cur_y_pos  
 * @param cur_temperature  
 * @param area_average_temperature  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t measure_mode,uint16_t max_temper_x_pos,uint16_t max_temper_y_pos,uint16_t max_temperature,uint16_t min_temper_x_pos,uint16_t min_temper_y_pos,uint16_t min_temperature,uint16_t cur_x_pos,uint16_t cur_y_pos,uint16_t cur_temperature,uint16_t area_average_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN];
    _mav_put_uint16_t(buf, 0, max_temper_x_pos);
    _mav_put_uint16_t(buf, 2, max_temper_y_pos);
    _mav_put_uint16_t(buf, 4, max_temperature);
    _mav_put_uint16_t(buf, 6, min_temper_x_pos);
    _mav_put_uint16_t(buf, 8, min_temper_y_pos);
    _mav_put_uint16_t(buf, 10, min_temperature);
    _mav_put_uint16_t(buf, 12, cur_x_pos);
    _mav_put_uint16_t(buf, 14, cur_y_pos);
    _mav_put_uint16_t(buf, 16, cur_temperature);
    _mav_put_uint16_t(buf, 18, area_average_temperature);
    _mav_put_uint8_t(buf, 20, measure_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN);
#else
    mavlink_wk_camera_mini_dual_state_t packet;
    packet.max_temper_x_pos = max_temper_x_pos;
    packet.max_temper_y_pos = max_temper_y_pos;
    packet.max_temperature = max_temperature;
    packet.min_temper_x_pos = min_temper_x_pos;
    packet.min_temper_y_pos = min_temper_y_pos;
    packet.min_temperature = min_temperature;
    packet.cur_x_pos = cur_x_pos;
    packet.cur_y_pos = cur_y_pos;
    packet.cur_temperature = cur_temperature;
    packet.area_average_temperature = area_average_temperature;
    packet.measure_mode = measure_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_CRC);
}

/**
 * @brief Encode a wk_camera_mini_dual_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_mini_dual_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_mini_dual_state_t* wk_camera_mini_dual_state)
{
    return mavlink_msg_wk_camera_mini_dual_state_pack(system_id, component_id, msg, wk_camera_mini_dual_state->measure_mode, wk_camera_mini_dual_state->max_temper_x_pos, wk_camera_mini_dual_state->max_temper_y_pos, wk_camera_mini_dual_state->max_temperature, wk_camera_mini_dual_state->min_temper_x_pos, wk_camera_mini_dual_state->min_temper_y_pos, wk_camera_mini_dual_state->min_temperature, wk_camera_mini_dual_state->cur_x_pos, wk_camera_mini_dual_state->cur_y_pos, wk_camera_mini_dual_state->cur_temperature, wk_camera_mini_dual_state->area_average_temperature);
}

/**
 * @brief Encode a wk_camera_mini_dual_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_mini_dual_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_mini_dual_state_t* wk_camera_mini_dual_state)
{
    return mavlink_msg_wk_camera_mini_dual_state_pack_chan(system_id, component_id, chan, msg, wk_camera_mini_dual_state->measure_mode, wk_camera_mini_dual_state->max_temper_x_pos, wk_camera_mini_dual_state->max_temper_y_pos, wk_camera_mini_dual_state->max_temperature, wk_camera_mini_dual_state->min_temper_x_pos, wk_camera_mini_dual_state->min_temper_y_pos, wk_camera_mini_dual_state->min_temperature, wk_camera_mini_dual_state->cur_x_pos, wk_camera_mini_dual_state->cur_y_pos, wk_camera_mini_dual_state->cur_temperature, wk_camera_mini_dual_state->area_average_temperature);
}

/**
 * @brief Send a wk_camera_mini_dual_state message
 * @param chan MAVLink channel to send the message
 *
 * @param measure_mode  see WK_CAMERA_R500_DUAL_MEASURE_MODE
 * @param max_temper_x_pos  
 * @param max_temper_y_pos  
 * @param max_temperature  
 * @param min_temper_x_pos  
 * @param min_temper_y_pos  
 * @param min_temperature  
 * @param cur_x_pos  
 * @param cur_y_pos  
 * @param cur_temperature  
 * @param area_average_temperature  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_mini_dual_state_send(mavlink_channel_t chan, uint8_t measure_mode, uint16_t max_temper_x_pos, uint16_t max_temper_y_pos, uint16_t max_temperature, uint16_t min_temper_x_pos, uint16_t min_temper_y_pos, uint16_t min_temperature, uint16_t cur_x_pos, uint16_t cur_y_pos, uint16_t cur_temperature, uint16_t area_average_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN];
    _mav_put_uint16_t(buf, 0, max_temper_x_pos);
    _mav_put_uint16_t(buf, 2, max_temper_y_pos);
    _mav_put_uint16_t(buf, 4, max_temperature);
    _mav_put_uint16_t(buf, 6, min_temper_x_pos);
    _mav_put_uint16_t(buf, 8, min_temper_y_pos);
    _mav_put_uint16_t(buf, 10, min_temperature);
    _mav_put_uint16_t(buf, 12, cur_x_pos);
    _mav_put_uint16_t(buf, 14, cur_y_pos);
    _mav_put_uint16_t(buf, 16, cur_temperature);
    _mav_put_uint16_t(buf, 18, area_average_temperature);
    _mav_put_uint8_t(buf, 20, measure_mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE, buf, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_CRC);
#else
    mavlink_wk_camera_mini_dual_state_t packet;
    packet.max_temper_x_pos = max_temper_x_pos;
    packet.max_temper_y_pos = max_temper_y_pos;
    packet.max_temperature = max_temperature;
    packet.min_temper_x_pos = min_temper_x_pos;
    packet.min_temper_y_pos = min_temper_y_pos;
    packet.min_temperature = min_temperature;
    packet.cur_x_pos = cur_x_pos;
    packet.cur_y_pos = cur_y_pos;
    packet.cur_temperature = cur_temperature;
    packet.area_average_temperature = area_average_temperature;
    packet.measure_mode = measure_mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_CRC);
#endif
}

/**
 * @brief Send a wk_camera_mini_dual_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_mini_dual_state_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_mini_dual_state_t* wk_camera_mini_dual_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_mini_dual_state_send(chan, wk_camera_mini_dual_state->measure_mode, wk_camera_mini_dual_state->max_temper_x_pos, wk_camera_mini_dual_state->max_temper_y_pos, wk_camera_mini_dual_state->max_temperature, wk_camera_mini_dual_state->min_temper_x_pos, wk_camera_mini_dual_state->min_temper_y_pos, wk_camera_mini_dual_state->min_temperature, wk_camera_mini_dual_state->cur_x_pos, wk_camera_mini_dual_state->cur_y_pos, wk_camera_mini_dual_state->cur_temperature, wk_camera_mini_dual_state->area_average_temperature);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE, (const char *)wk_camera_mini_dual_state, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_mini_dual_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t measure_mode, uint16_t max_temper_x_pos, uint16_t max_temper_y_pos, uint16_t max_temperature, uint16_t min_temper_x_pos, uint16_t min_temper_y_pos, uint16_t min_temperature, uint16_t cur_x_pos, uint16_t cur_y_pos, uint16_t cur_temperature, uint16_t area_average_temperature)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, max_temper_x_pos);
    _mav_put_uint16_t(buf, 2, max_temper_y_pos);
    _mav_put_uint16_t(buf, 4, max_temperature);
    _mav_put_uint16_t(buf, 6, min_temper_x_pos);
    _mav_put_uint16_t(buf, 8, min_temper_y_pos);
    _mav_put_uint16_t(buf, 10, min_temperature);
    _mav_put_uint16_t(buf, 12, cur_x_pos);
    _mav_put_uint16_t(buf, 14, cur_y_pos);
    _mav_put_uint16_t(buf, 16, cur_temperature);
    _mav_put_uint16_t(buf, 18, area_average_temperature);
    _mav_put_uint8_t(buf, 20, measure_mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE, buf, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_CRC);
#else
    mavlink_wk_camera_mini_dual_state_t *packet = (mavlink_wk_camera_mini_dual_state_t *)msgbuf;
    packet->max_temper_x_pos = max_temper_x_pos;
    packet->max_temper_y_pos = max_temper_y_pos;
    packet->max_temperature = max_temperature;
    packet->min_temper_x_pos = min_temper_x_pos;
    packet->min_temper_y_pos = min_temper_y_pos;
    packet->min_temperature = min_temperature;
    packet->cur_x_pos = cur_x_pos;
    packet->cur_y_pos = cur_y_pos;
    packet->cur_temperature = cur_temperature;
    packet->area_average_temperature = area_average_temperature;
    packet->measure_mode = measure_mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_MINI_DUAL_STATE UNPACKING


/**
 * @brief Get field measure_mode from wk_camera_mini_dual_state message
 *
 * @return  see WK_CAMERA_R500_DUAL_MEASURE_MODE
 */
static inline uint8_t mavlink_msg_wk_camera_mini_dual_state_get_measure_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field max_temper_x_pos from wk_camera_mini_dual_state message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_state_get_max_temper_x_pos(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field max_temper_y_pos from wk_camera_mini_dual_state message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_state_get_max_temper_y_pos(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field max_temperature from wk_camera_mini_dual_state message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_state_get_max_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field min_temper_x_pos from wk_camera_mini_dual_state message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_state_get_min_temper_x_pos(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field min_temper_y_pos from wk_camera_mini_dual_state message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_state_get_min_temper_y_pos(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field min_temperature from wk_camera_mini_dual_state message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_state_get_min_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Get field cur_x_pos from wk_camera_mini_dual_state message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_state_get_cur_x_pos(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field cur_y_pos from wk_camera_mini_dual_state message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_state_get_cur_y_pos(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field cur_temperature from wk_camera_mini_dual_state message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_state_get_cur_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field area_average_temperature from wk_camera_mini_dual_state message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_camera_mini_dual_state_get_area_average_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Decode a wk_camera_mini_dual_state message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_mini_dual_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_mini_dual_state_decode(const mavlink_message_t* msg, mavlink_wk_camera_mini_dual_state_t* wk_camera_mini_dual_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_mini_dual_state->max_temper_x_pos = mavlink_msg_wk_camera_mini_dual_state_get_max_temper_x_pos(msg);
    wk_camera_mini_dual_state->max_temper_y_pos = mavlink_msg_wk_camera_mini_dual_state_get_max_temper_y_pos(msg);
    wk_camera_mini_dual_state->max_temperature = mavlink_msg_wk_camera_mini_dual_state_get_max_temperature(msg);
    wk_camera_mini_dual_state->min_temper_x_pos = mavlink_msg_wk_camera_mini_dual_state_get_min_temper_x_pos(msg);
    wk_camera_mini_dual_state->min_temper_y_pos = mavlink_msg_wk_camera_mini_dual_state_get_min_temper_y_pos(msg);
    wk_camera_mini_dual_state->min_temperature = mavlink_msg_wk_camera_mini_dual_state_get_min_temperature(msg);
    wk_camera_mini_dual_state->cur_x_pos = mavlink_msg_wk_camera_mini_dual_state_get_cur_x_pos(msg);
    wk_camera_mini_dual_state->cur_y_pos = mavlink_msg_wk_camera_mini_dual_state_get_cur_y_pos(msg);
    wk_camera_mini_dual_state->cur_temperature = mavlink_msg_wk_camera_mini_dual_state_get_cur_temperature(msg);
    wk_camera_mini_dual_state->area_average_temperature = mavlink_msg_wk_camera_mini_dual_state_get_area_average_temperature(msg);
    wk_camera_mini_dual_state->measure_mode = mavlink_msg_wk_camera_mini_dual_state_get_measure_mode(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN;
        memset(wk_camera_mini_dual_state, 0, MAVLINK_MSG_ID_WK_CAMERA_MINI_DUAL_STATE_LEN);
    memcpy(wk_camera_mini_dual_state, _MAV_PAYLOAD(msg), len);
#endif
}
