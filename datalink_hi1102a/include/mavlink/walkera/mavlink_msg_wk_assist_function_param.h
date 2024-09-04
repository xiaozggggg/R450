#pragma once
// MESSAGE WK_ASSIST_FUNCTION_PARAM PACKING

#define MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM 8516


typedef struct __mavlink_wk_assist_function_param_t {
 uint8_t assaint_mode; /*<  see enum WK_ASSAINT_MODE_CMD*/
 uint8_t circie_dircetion; /*<  see enum WK_ASSAINT_CIRCLE_DIRECTION*/
 uint8_t circie_num; /*<  */
 uint8_t circie_speed; /*<  */
 uint8_t far_away_height; /*<  */
 uint8_t far_away_distance; /*<  */
 uint8_t raise_up_height; /*<  */
} mavlink_wk_assist_function_param_t;

#define MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN 7
#define MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_MIN_LEN 7
#define MAVLINK_MSG_ID_8516_LEN 7
#define MAVLINK_MSG_ID_8516_MIN_LEN 7

#define MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_CRC 60
#define MAVLINK_MSG_ID_8516_CRC 60



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_ASSIST_FUNCTION_PARAM { \
    8516, \
    "WK_ASSIST_FUNCTION_PARAM", \
    7, \
    {  { "assaint_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_assist_function_param_t, assaint_mode) }, \
         { "circie_dircetion", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_assist_function_param_t, circie_dircetion) }, \
         { "circie_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_assist_function_param_t, circie_num) }, \
         { "circie_speed", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_assist_function_param_t, circie_speed) }, \
         { "far_away_height", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_assist_function_param_t, far_away_height) }, \
         { "far_away_distance", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_assist_function_param_t, far_away_distance) }, \
         { "raise_up_height", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_assist_function_param_t, raise_up_height) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_ASSIST_FUNCTION_PARAM { \
    "WK_ASSIST_FUNCTION_PARAM", \
    7, \
    {  { "assaint_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_assist_function_param_t, assaint_mode) }, \
         { "circie_dircetion", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_assist_function_param_t, circie_dircetion) }, \
         { "circie_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_assist_function_param_t, circie_num) }, \
         { "circie_speed", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_assist_function_param_t, circie_speed) }, \
         { "far_away_height", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_assist_function_param_t, far_away_height) }, \
         { "far_away_distance", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_assist_function_param_t, far_away_distance) }, \
         { "raise_up_height", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_assist_function_param_t, raise_up_height) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_assist_function_param message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param assaint_mode  see enum WK_ASSAINT_MODE_CMD
 * @param circie_dircetion  see enum WK_ASSAINT_CIRCLE_DIRECTION
 * @param circie_num  
 * @param circie_speed  
 * @param far_away_height  
 * @param far_away_distance  
 * @param raise_up_height  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_assist_function_param_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t assaint_mode, uint8_t circie_dircetion, uint8_t circie_num, uint8_t circie_speed, uint8_t far_away_height, uint8_t far_away_distance, uint8_t raise_up_height)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN];
    _mav_put_uint8_t(buf, 0, assaint_mode);
    _mav_put_uint8_t(buf, 1, circie_dircetion);
    _mav_put_uint8_t(buf, 2, circie_num);
    _mav_put_uint8_t(buf, 3, circie_speed);
    _mav_put_uint8_t(buf, 4, far_away_height);
    _mav_put_uint8_t(buf, 5, far_away_distance);
    _mav_put_uint8_t(buf, 6, raise_up_height);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN);
#else
    mavlink_wk_assist_function_param_t packet;
    packet.assaint_mode = assaint_mode;
    packet.circie_dircetion = circie_dircetion;
    packet.circie_num = circie_num;
    packet.circie_speed = circie_speed;
    packet.far_away_height = far_away_height;
    packet.far_away_distance = far_away_distance;
    packet.raise_up_height = raise_up_height;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_CRC);
}

/**
 * @brief Pack a wk_assist_function_param message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param assaint_mode  see enum WK_ASSAINT_MODE_CMD
 * @param circie_dircetion  see enum WK_ASSAINT_CIRCLE_DIRECTION
 * @param circie_num  
 * @param circie_speed  
 * @param far_away_height  
 * @param far_away_distance  
 * @param raise_up_height  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_assist_function_param_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t assaint_mode,uint8_t circie_dircetion,uint8_t circie_num,uint8_t circie_speed,uint8_t far_away_height,uint8_t far_away_distance,uint8_t raise_up_height)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN];
    _mav_put_uint8_t(buf, 0, assaint_mode);
    _mav_put_uint8_t(buf, 1, circie_dircetion);
    _mav_put_uint8_t(buf, 2, circie_num);
    _mav_put_uint8_t(buf, 3, circie_speed);
    _mav_put_uint8_t(buf, 4, far_away_height);
    _mav_put_uint8_t(buf, 5, far_away_distance);
    _mav_put_uint8_t(buf, 6, raise_up_height);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN);
#else
    mavlink_wk_assist_function_param_t packet;
    packet.assaint_mode = assaint_mode;
    packet.circie_dircetion = circie_dircetion;
    packet.circie_num = circie_num;
    packet.circie_speed = circie_speed;
    packet.far_away_height = far_away_height;
    packet.far_away_distance = far_away_distance;
    packet.raise_up_height = raise_up_height;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_CRC);
}

/**
 * @brief Encode a wk_assist_function_param struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_assist_function_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_assist_function_param_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_assist_function_param_t* wk_assist_function_param)
{
    return mavlink_msg_wk_assist_function_param_pack(system_id, component_id, msg, wk_assist_function_param->assaint_mode, wk_assist_function_param->circie_dircetion, wk_assist_function_param->circie_num, wk_assist_function_param->circie_speed, wk_assist_function_param->far_away_height, wk_assist_function_param->far_away_distance, wk_assist_function_param->raise_up_height);
}

/**
 * @brief Encode a wk_assist_function_param struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_assist_function_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_assist_function_param_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_assist_function_param_t* wk_assist_function_param)
{
    return mavlink_msg_wk_assist_function_param_pack_chan(system_id, component_id, chan, msg, wk_assist_function_param->assaint_mode, wk_assist_function_param->circie_dircetion, wk_assist_function_param->circie_num, wk_assist_function_param->circie_speed, wk_assist_function_param->far_away_height, wk_assist_function_param->far_away_distance, wk_assist_function_param->raise_up_height);
}

/**
 * @brief Send a wk_assist_function_param message
 * @param chan MAVLink channel to send the message
 *
 * @param assaint_mode  see enum WK_ASSAINT_MODE_CMD
 * @param circie_dircetion  see enum WK_ASSAINT_CIRCLE_DIRECTION
 * @param circie_num  
 * @param circie_speed  
 * @param far_away_height  
 * @param far_away_distance  
 * @param raise_up_height  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_assist_function_param_send(mavlink_channel_t chan, uint8_t assaint_mode, uint8_t circie_dircetion, uint8_t circie_num, uint8_t circie_speed, uint8_t far_away_height, uint8_t far_away_distance, uint8_t raise_up_height)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN];
    _mav_put_uint8_t(buf, 0, assaint_mode);
    _mav_put_uint8_t(buf, 1, circie_dircetion);
    _mav_put_uint8_t(buf, 2, circie_num);
    _mav_put_uint8_t(buf, 3, circie_speed);
    _mav_put_uint8_t(buf, 4, far_away_height);
    _mav_put_uint8_t(buf, 5, far_away_distance);
    _mav_put_uint8_t(buf, 6, raise_up_height);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM, buf, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_CRC);
#else
    mavlink_wk_assist_function_param_t packet;
    packet.assaint_mode = assaint_mode;
    packet.circie_dircetion = circie_dircetion;
    packet.circie_num = circie_num;
    packet.circie_speed = circie_speed;
    packet.far_away_height = far_away_height;
    packet.far_away_distance = far_away_distance;
    packet.raise_up_height = raise_up_height;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM, (const char *)&packet, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_CRC);
#endif
}

/**
 * @brief Send a wk_assist_function_param message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_assist_function_param_send_struct(mavlink_channel_t chan, const mavlink_wk_assist_function_param_t* wk_assist_function_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_assist_function_param_send(chan, wk_assist_function_param->assaint_mode, wk_assist_function_param->circie_dircetion, wk_assist_function_param->circie_num, wk_assist_function_param->circie_speed, wk_assist_function_param->far_away_height, wk_assist_function_param->far_away_distance, wk_assist_function_param->raise_up_height);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM, (const char *)wk_assist_function_param, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_assist_function_param_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t assaint_mode, uint8_t circie_dircetion, uint8_t circie_num, uint8_t circie_speed, uint8_t far_away_height, uint8_t far_away_distance, uint8_t raise_up_height)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, assaint_mode);
    _mav_put_uint8_t(buf, 1, circie_dircetion);
    _mav_put_uint8_t(buf, 2, circie_num);
    _mav_put_uint8_t(buf, 3, circie_speed);
    _mav_put_uint8_t(buf, 4, far_away_height);
    _mav_put_uint8_t(buf, 5, far_away_distance);
    _mav_put_uint8_t(buf, 6, raise_up_height);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM, buf, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_CRC);
#else
    mavlink_wk_assist_function_param_t *packet = (mavlink_wk_assist_function_param_t *)msgbuf;
    packet->assaint_mode = assaint_mode;
    packet->circie_dircetion = circie_dircetion;
    packet->circie_num = circie_num;
    packet->circie_speed = circie_speed;
    packet->far_away_height = far_away_height;
    packet->far_away_distance = far_away_distance;
    packet->raise_up_height = raise_up_height;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM, (const char *)packet, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_ASSIST_FUNCTION_PARAM UNPACKING


/**
 * @brief Get field assaint_mode from wk_assist_function_param message
 *
 * @return  see enum WK_ASSAINT_MODE_CMD
 */
static inline uint8_t mavlink_msg_wk_assist_function_param_get_assaint_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field circie_dircetion from wk_assist_function_param message
 *
 * @return  see enum WK_ASSAINT_CIRCLE_DIRECTION
 */
static inline uint8_t mavlink_msg_wk_assist_function_param_get_circie_dircetion(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field circie_num from wk_assist_function_param message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_param_get_circie_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field circie_speed from wk_assist_function_param message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_param_get_circie_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field far_away_height from wk_assist_function_param message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_param_get_far_away_height(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field far_away_distance from wk_assist_function_param message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_param_get_far_away_distance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field raise_up_height from wk_assist_function_param message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_assist_function_param_get_raise_up_height(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Decode a wk_assist_function_param message into a struct
 *
 * @param msg The message to decode
 * @param wk_assist_function_param C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_assist_function_param_decode(const mavlink_message_t* msg, mavlink_wk_assist_function_param_t* wk_assist_function_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_assist_function_param->assaint_mode = mavlink_msg_wk_assist_function_param_get_assaint_mode(msg);
    wk_assist_function_param->circie_dircetion = mavlink_msg_wk_assist_function_param_get_circie_dircetion(msg);
    wk_assist_function_param->circie_num = mavlink_msg_wk_assist_function_param_get_circie_num(msg);
    wk_assist_function_param->circie_speed = mavlink_msg_wk_assist_function_param_get_circie_speed(msg);
    wk_assist_function_param->far_away_height = mavlink_msg_wk_assist_function_param_get_far_away_height(msg);
    wk_assist_function_param->far_away_distance = mavlink_msg_wk_assist_function_param_get_far_away_distance(msg);
    wk_assist_function_param->raise_up_height = mavlink_msg_wk_assist_function_param_get_raise_up_height(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN? msg->len : MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN;
        memset(wk_assist_function_param, 0, MAVLINK_MSG_ID_WK_ASSIST_FUNCTION_PARAM_LEN);
    memcpy(wk_assist_function_param, _MAV_PAYLOAD(msg), len);
#endif
}
