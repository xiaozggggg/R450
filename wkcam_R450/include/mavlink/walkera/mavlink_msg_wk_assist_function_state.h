#pragma once
// MESSAGE WK_ASSIST_FUNCTION_STATE PACKING

#define MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE 8516


typedef struct __mavlink_wk_assist_function_state_t {
 uint8_t assaint_mode; /*<  see enum WK_ASSAINT_MODE_CMD*/
 uint8_t circie_dircetion; /*<  see enum WK_ASSAINT_CIRCLE_DIRECTION*/
 uint8_t circie_num; /*<  */
 uint8_t circie_speed; /*<  */
 uint8_t far_away_heigh; /*<  */
 uint8_t far_away_distance; /*<  */
 uint8_t raise_up_hight; /*<  */
} mavlink_wk_assist_function_state_t;

#define MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN 7
#define MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_MIN_LEN 7
#define MAVLINK_MSG_ID_8516_LEN 7
#define MAVLINK_MSG_ID_8516_MIN_LEN 7

#define MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_CRC 58
#define MAVLINK_MSG_ID_8516_CRC 58



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_ASSIST_FUNCTION_STATE { \
    8516, \
    "WK_ASSIST_FUNCTION_STATE", \
    7, \
    {  { "assaint_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_assist_function_state_t, assaint_mode) }, \
         { "circie_dircetion", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_assist_function_state_t, circie_dircetion) }, \
         { "circie_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_assist_function_state_t, circie_num) }, \
         { "circie_speed", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_assist_function_state_t, circie_speed) }, \
         { "far_away_heigh", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_assist_function_state_t, far_away_heigh) }, \
         { "far_away_distance", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_assist_function_state_t, far_away_distance) }, \
         { "raise_up_hight", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_assist_function_state_t, raise_up_hight) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_ASSIST_FUNCTION_STATE { \
    "WK_ASSIST_FUNCTION_STATE", \
    7, \
    {  { "assaint_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_assist_function_state_t, assaint_mode) }, \
         { "circie_dircetion", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_assist_function_state_t, circie_dircetion) }, \
         { "circie_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_assist_function_state_t, circie_num) }, \
         { "circie_speed", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_assist_function_state_t, circie_speed) }, \
         { "far_away_heigh", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_assist_function_state_t, far_away_heigh) }, \
         { "far_away_distance", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_assist_function_state_t, far_away_distance) }, \
         { "raise_up_hight", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_assist_function_state_t, raise_up_hight) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_assist_function_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param assaint_mode  see enum WK_ASSAINT_MODE_CMD
 * @param circie_dircetion  see enum WK_ASSAINT_CIRCLE_DIRECTION
 * @param circie_num  
 * @param circie_speed  
 * @param far_away_heigh  
 * @param far_away_distance  
 * @param raise_up_hight  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_assist_function_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t assaint_mode, uint8_t circie_dircetion, uint8_t circie_num, uint8_t circie_speed, uint8_t far_away_heigh, uint8_t far_away_distance, uint8_t raise_up_hight)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN];
    _mav_put_uint8_t(buf, 0, assaint_mode);
    _mav_put_uint8_t(buf, 1, circie_dircetion);
    _mav_put_uint8_t(buf, 2, circie_num);
    _mav_put_uint8_t(buf, 3, circie_speed);
    _mav_put_uint8_t(buf, 4, far_away_heigh);
    _mav_put_uint8_t(buf, 5, far_away_distance);
    _mav_put_uint8_t(buf, 6, raise_up_hight);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN);
#else
    mavlink_wk_assist_function_state_t packet;
    packet.assaint_mode = assaint_mode;
    packet.circie_dircetion = circie_dircetion;
    packet.circie_num = circie_num;
    packet.circie_speed = circie_speed;
    packet.far_away_heigh = far_away_heigh;
    packet.far_away_distance = far_away_distance;
    packet.raise_up_hight = raise_up_hight;

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
 * @param assaint_mode  see enum WK_ASSAINT_MODE_CMD
 * @param circie_dircetion  see enum WK_ASSAINT_CIRCLE_DIRECTION
 * @param circie_num  
 * @param circie_speed  
 * @param far_away_heigh  
 * @param far_away_distance  
 * @param raise_up_hight  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_assist_function_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t assaint_mode,uint8_t circie_dircetion,uint8_t circie_num,uint8_t circie_speed,uint8_t far_away_heigh,uint8_t far_away_distance,uint8_t raise_up_hight)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN];
    _mav_put_uint8_t(buf, 0, assaint_mode);
    _mav_put_uint8_t(buf, 1, circie_dircetion);
    _mav_put_uint8_t(buf, 2, circie_num);
    _mav_put_uint8_t(buf, 3, circie_speed);
    _mav_put_uint8_t(buf, 4, far_away_heigh);
    _mav_put_uint8_t(buf, 5, far_away_distance);
    _mav_put_uint8_t(buf, 6, raise_up_hight);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN);
#else
    mavlink_wk_assist_function_state_t packet;
    packet.assaint_mode = assaint_mode;
    packet.circie_dircetion = circie_dircetion;
    packet.circie_num = circie_num;
    packet.circie_speed = circie_speed;
    packet.far_away_heigh = far_away_heigh;
    packet.far_away_distance = far_away_distance;
    packet.raise_up_hight = raise_up_hight;

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
    return mavlink_msg_wk_assist_function_state_pack(system_id, component_id, msg, wk_assist_function_state->assaint_mode, wk_assist_function_state->circie_dircetion, wk_assist_function_state->circie_num, wk_assist_function_state->circie_speed, wk_assist_function_state->far_away_heigh, wk_assist_function_state->far_away_distance, wk_assist_function_state->raise_up_hight);
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
    return mavlink_msg_wk_assist_function_state_pack_chan(system_id, component_id, chan, msg, wk_assist_function_state->assaint_mode, wk_assist_function_state->circie_dircetion, wk_assist_function_state->circie_num, wk_assist_function_state->circie_speed, wk_assist_function_state->far_away_heigh, wk_assist_function_state->far_away_distance, wk_assist_function_state->raise_up_hight);
}

/**
 * @brief Send a wk_assist_function_state message
 * @param chan MAVLink channel to send the message
 *
 * @param assaint_mode  see enum WK_ASSAINT_MODE_CMD
 * @param circie_dircetion  see enum WK_ASSAINT_CIRCLE_DIRECTION
 * @param circie_num  
 * @param circie_speed  
 * @param far_away_heigh  
 * @param far_away_distance  
 * @param raise_up_hight  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_assist_function_state_send(mavlink_channel_t chan, uint8_t assaint_mode, uint8_t circie_dircetion, uint8_t circie_num, uint8_t circie_speed, uint8_t far_away_heigh, uint8_t far_away_distance, uint8_t raise_up_hight)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN];
    _mav_put_uint8_t(buf, 0, assaint_mode);
    _mav_put_uint8_t(buf, 1, circie_dircetion);
    _mav_put_uint8_t(buf, 2, circie_num);
    _mav_put_uint8_t(buf, 3, circie_speed);
    _mav_put_uint8_t(buf, 4, far_away_heigh);
    _mav_put_uint8_t(buf, 5, far_away_distance);
    _mav_put_uint8_t(buf, 6, raise_up_hight);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE, buf, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_CRC);
#else
    mavlink_wk_assist_function_state_t packet;
    packet.assaint_mode = assaint_mode;
    packet.circie_dircetion = circie_dircetion;
    packet.circie_num = circie_num;
    packet.circie_speed = circie_speed;
    packet.far_away_heigh = far_away_heigh;
    packet.far_away_distance = far_away_distance;
    packet.raise_up_hight = raise_up_hight;

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
    mavlink_msg_wk_assist_function_state_send(chan, wk_assist_function_state->assaint_mode, wk_assist_function_state->circie_dircetion, wk_assist_function_state->circie_num, wk_assist_function_state->circie_speed, wk_assist_function_state->far_away_heigh, wk_assist_function_state->far_away_distance, wk_assist_function_state->raise_up_hight);
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
static inline void mavlink_msg_wk_assist_function_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t assaint_mode, uint8_t circie_dircetion, uint8_t circie_num, uint8_t circie_speed, uint8_t far_away_heigh, uint8_t far_away_distance, uint8_t raise_up_hight)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, assaint_mode);
    _mav_put_uint8_t(buf, 1, circie_dircetion);
    _mav_put_uint8_t(buf, 2, circie_num);
    _mav_put_uint8_t(buf, 3, circie_speed);
    _mav_put_uint8_t(buf, 4, far_away_heigh);
    _mav_put_uint8_t(buf, 5, far_away_distance);
    _mav_put_uint8_t(buf, 6, raise_up_hight);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE, buf, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_CRC);
#else
    mavlink_wk_assist_function_state_t *packet = (mavlink_wk_assist_function_state_t *)msgbuf;
    packet->assaint_mode = assaint_mode;
    packet->circie_dircetion = circie_dircetion;
    packet->circie_num = circie_num;
    packet->circie_speed = circie_speed;
    packet->far_away_heigh = far_away_heigh;
    packet->far_away_distance = far_away_distance;
    packet->raise_up_hight = raise_up_hight;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE, (const char *)packet, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_ASSIST_FUNCTION_STATE UNPACKING


/**
 * @brief Get field assaint_mode from wk_assist_function_state message
 *
 * @return  see enum WK_ASSAINT_MODE_CMD
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_assaint_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field circie_dircetion from wk_assist_function_state message
 *
 * @return  see enum WK_ASSAINT_CIRCLE_DIRECTION
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_circie_dircetion(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field circie_num from wk_assist_function_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_circie_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field circie_speed from wk_assist_function_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_circie_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field far_away_heigh from wk_assist_function_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_far_away_heigh(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field far_away_distance from wk_assist_function_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_far_away_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field raise_up_hight from wk_assist_function_state message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_state_get_raise_up_hight(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
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
    wk_assist_function_state->assaint_mode = mavlink_msg_wk_assist_function_state_get_assaint_mode(msg);
    wk_assist_function_state->circie_dircetion = mavlink_msg_wk_assist_function_state_get_circie_dircetion(msg);
    wk_assist_function_state->circie_num = mavlink_msg_wk_assist_function_state_get_circie_num(msg);
    wk_assist_function_state->circie_speed = mavlink_msg_wk_assist_function_state_get_circie_speed(msg);
    wk_assist_function_state->far_away_heigh = mavlink_msg_wk_assist_function_state_get_far_away_heigh(msg);
    wk_assist_function_state->far_away_distance = mavlink_msg_wk_assist_function_state_get_far_away_distance(msg);
    wk_assist_function_state->raise_up_hight = mavlink_msg_wk_assist_function_state_get_raise_up_hight(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN? msg->len : MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN;
        memset(wk_assist_function_state, 0, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_STATE_LEN);
    memcpy(wk_assist_function_state, _MAV_PAYLOAD(msg), len);
#endif
}
