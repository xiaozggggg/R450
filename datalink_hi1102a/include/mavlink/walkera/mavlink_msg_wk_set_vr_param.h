#pragma once
// MESSAGE WK_SET_VR_PARAM PACKING

#define MAVLINK_MSG_ID_WK_SET_VR_PARAM 8302


typedef struct __mavlink_wk_set_vr_param_t {
 float gyroscopeX; /*<  */
 float gyroscopeY; /*<  */
 float gyroscopeZ; /*<  */
 float accelerationX; /*<  */
 float accelerationY; /*<  */
 float accelerationZ; /*<  */
} mavlink_wk_set_vr_param_t;

#define MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN 24
#define MAVLINK_MSG_ID_WK_SET_VR_PARAM_MIN_LEN 24
#define MAVLINK_MSG_ID_8302_LEN 24
#define MAVLINK_MSG_ID_8302_MIN_LEN 24

#define MAVLINK_MSG_ID_WK_SET_VR_PARAM_CRC 42
#define MAVLINK_MSG_ID_8302_CRC 42



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_SET_VR_PARAM { \
    8302, \
    "WK_SET_VR_PARAM", \
    6, \
    {  { "gyroscopeX", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_set_vr_param_t, gyroscopeX) }, \
         { "gyroscopeY", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_set_vr_param_t, gyroscopeY) }, \
         { "gyroscopeZ", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_set_vr_param_t, gyroscopeZ) }, \
         { "accelerationX", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_set_vr_param_t, accelerationX) }, \
         { "accelerationY", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_set_vr_param_t, accelerationY) }, \
         { "accelerationZ", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_set_vr_param_t, accelerationZ) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_SET_VR_PARAM { \
    "WK_SET_VR_PARAM", \
    6, \
    {  { "gyroscopeX", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_set_vr_param_t, gyroscopeX) }, \
         { "gyroscopeY", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_set_vr_param_t, gyroscopeY) }, \
         { "gyroscopeZ", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_set_vr_param_t, gyroscopeZ) }, \
         { "accelerationX", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_set_vr_param_t, accelerationX) }, \
         { "accelerationY", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_set_vr_param_t, accelerationY) }, \
         { "accelerationZ", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_set_vr_param_t, accelerationZ) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_set_vr_param message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param gyroscopeX  
 * @param gyroscopeY  
 * @param gyroscopeZ  
 * @param accelerationX  
 * @param accelerationY  
 * @param accelerationZ  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_set_vr_param_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float gyroscopeX, float gyroscopeY, float gyroscopeZ, float accelerationX, float accelerationY, float accelerationZ)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN];
    _mav_put_float(buf, 0, gyroscopeX);
    _mav_put_float(buf, 4, gyroscopeY);
    _mav_put_float(buf, 8, gyroscopeZ);
    _mav_put_float(buf, 12, accelerationX);
    _mav_put_float(buf, 16, accelerationY);
    _mav_put_float(buf, 20, accelerationZ);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN);
#else
    mavlink_wk_set_vr_param_t packet;
    packet.gyroscopeX = gyroscopeX;
    packet.gyroscopeY = gyroscopeY;
    packet.gyroscopeZ = gyroscopeZ;
    packet.accelerationX = accelerationX;
    packet.accelerationY = accelerationY;
    packet.accelerationZ = accelerationZ;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_SET_VR_PARAM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_SET_VR_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN, MAVLINK_MSG_ID_WK_SET_VR_PARAM_CRC);
}

/**
 * @brief Pack a wk_set_vr_param message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gyroscopeX  
 * @param gyroscopeY  
 * @param gyroscopeZ  
 * @param accelerationX  
 * @param accelerationY  
 * @param accelerationZ  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_set_vr_param_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float gyroscopeX,float gyroscopeY,float gyroscopeZ,float accelerationX,float accelerationY,float accelerationZ)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN];
    _mav_put_float(buf, 0, gyroscopeX);
    _mav_put_float(buf, 4, gyroscopeY);
    _mav_put_float(buf, 8, gyroscopeZ);
    _mav_put_float(buf, 12, accelerationX);
    _mav_put_float(buf, 16, accelerationY);
    _mav_put_float(buf, 20, accelerationZ);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN);
#else
    mavlink_wk_set_vr_param_t packet;
    packet.gyroscopeX = gyroscopeX;
    packet.gyroscopeY = gyroscopeY;
    packet.gyroscopeZ = gyroscopeZ;
    packet.accelerationX = accelerationX;
    packet.accelerationY = accelerationY;
    packet.accelerationZ = accelerationZ;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_SET_VR_PARAM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_SET_VR_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN, MAVLINK_MSG_ID_WK_SET_VR_PARAM_CRC);
}

/**
 * @brief Encode a wk_set_vr_param struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_set_vr_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_set_vr_param_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_set_vr_param_t* wk_set_vr_param)
{
    return mavlink_msg_wk_set_vr_param_pack(system_id, component_id, msg, wk_set_vr_param->gyroscopeX, wk_set_vr_param->gyroscopeY, wk_set_vr_param->gyroscopeZ, wk_set_vr_param->accelerationX, wk_set_vr_param->accelerationY, wk_set_vr_param->accelerationZ);
}

/**
 * @brief Encode a wk_set_vr_param struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_set_vr_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_set_vr_param_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_set_vr_param_t* wk_set_vr_param)
{
    return mavlink_msg_wk_set_vr_param_pack_chan(system_id, component_id, chan, msg, wk_set_vr_param->gyroscopeX, wk_set_vr_param->gyroscopeY, wk_set_vr_param->gyroscopeZ, wk_set_vr_param->accelerationX, wk_set_vr_param->accelerationY, wk_set_vr_param->accelerationZ);
}

/**
 * @brief Send a wk_set_vr_param message
 * @param chan MAVLink channel to send the message
 *
 * @param gyroscopeX  
 * @param gyroscopeY  
 * @param gyroscopeZ  
 * @param accelerationX  
 * @param accelerationY  
 * @param accelerationZ  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_set_vr_param_send(mavlink_channel_t chan, float gyroscopeX, float gyroscopeY, float gyroscopeZ, float accelerationX, float accelerationY, float accelerationZ)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN];
    _mav_put_float(buf, 0, gyroscopeX);
    _mav_put_float(buf, 4, gyroscopeY);
    _mav_put_float(buf, 8, gyroscopeZ);
    _mav_put_float(buf, 12, accelerationX);
    _mav_put_float(buf, 16, accelerationY);
    _mav_put_float(buf, 20, accelerationZ);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SET_VR_PARAM, buf, MAVLINK_MSG_ID_WK_SET_VR_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN, MAVLINK_MSG_ID_WK_SET_VR_PARAM_CRC);
#else
    mavlink_wk_set_vr_param_t packet;
    packet.gyroscopeX = gyroscopeX;
    packet.gyroscopeY = gyroscopeY;
    packet.gyroscopeZ = gyroscopeZ;
    packet.accelerationX = accelerationX;
    packet.accelerationY = accelerationY;
    packet.accelerationZ = accelerationZ;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SET_VR_PARAM, (const char *)&packet, MAVLINK_MSG_ID_WK_SET_VR_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN, MAVLINK_MSG_ID_WK_SET_VR_PARAM_CRC);
#endif
}

/**
 * @brief Send a wk_set_vr_param message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_set_vr_param_send_struct(mavlink_channel_t chan, const mavlink_wk_set_vr_param_t* wk_set_vr_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_set_vr_param_send(chan, wk_set_vr_param->gyroscopeX, wk_set_vr_param->gyroscopeY, wk_set_vr_param->gyroscopeZ, wk_set_vr_param->accelerationX, wk_set_vr_param->accelerationY, wk_set_vr_param->accelerationZ);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SET_VR_PARAM, (const char *)wk_set_vr_param, MAVLINK_MSG_ID_WK_SET_VR_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN, MAVLINK_MSG_ID_WK_SET_VR_PARAM_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_set_vr_param_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float gyroscopeX, float gyroscopeY, float gyroscopeZ, float accelerationX, float accelerationY, float accelerationZ)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, gyroscopeX);
    _mav_put_float(buf, 4, gyroscopeY);
    _mav_put_float(buf, 8, gyroscopeZ);
    _mav_put_float(buf, 12, accelerationX);
    _mav_put_float(buf, 16, accelerationY);
    _mav_put_float(buf, 20, accelerationZ);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SET_VR_PARAM, buf, MAVLINK_MSG_ID_WK_SET_VR_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN, MAVLINK_MSG_ID_WK_SET_VR_PARAM_CRC);
#else
    mavlink_wk_set_vr_param_t *packet = (mavlink_wk_set_vr_param_t *)msgbuf;
    packet->gyroscopeX = gyroscopeX;
    packet->gyroscopeY = gyroscopeY;
    packet->gyroscopeZ = gyroscopeZ;
    packet->accelerationX = accelerationX;
    packet->accelerationY = accelerationY;
    packet->accelerationZ = accelerationZ;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SET_VR_PARAM, (const char *)packet, MAVLINK_MSG_ID_WK_SET_VR_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN, MAVLINK_MSG_ID_WK_SET_VR_PARAM_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_SET_VR_PARAM UNPACKING


/**
 * @brief Get field gyroscopeX from wk_set_vr_param message
 *
 * @return  
 */
static inline float mavlink_msg_wk_set_vr_param_get_gyroscopeX(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field gyroscopeY from wk_set_vr_param message
 *
 * @return  
 */
static inline float mavlink_msg_wk_set_vr_param_get_gyroscopeY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field gyroscopeZ from wk_set_vr_param message
 *
 * @return  
 */
static inline float mavlink_msg_wk_set_vr_param_get_gyroscopeZ(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field accelerationX from wk_set_vr_param message
 *
 * @return  
 */
static inline float mavlink_msg_wk_set_vr_param_get_accelerationX(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field accelerationY from wk_set_vr_param message
 *
 * @return  
 */
static inline float mavlink_msg_wk_set_vr_param_get_accelerationY(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field accelerationZ from wk_set_vr_param message
 *
 * @return  
 */
static inline float mavlink_msg_wk_set_vr_param_get_accelerationZ(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a wk_set_vr_param message into a struct
 *
 * @param msg The message to decode
 * @param wk_set_vr_param C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_set_vr_param_decode(const mavlink_message_t* msg, mavlink_wk_set_vr_param_t* wk_set_vr_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_set_vr_param->gyroscopeX = mavlink_msg_wk_set_vr_param_get_gyroscopeX(msg);
    wk_set_vr_param->gyroscopeY = mavlink_msg_wk_set_vr_param_get_gyroscopeY(msg);
    wk_set_vr_param->gyroscopeZ = mavlink_msg_wk_set_vr_param_get_gyroscopeZ(msg);
    wk_set_vr_param->accelerationX = mavlink_msg_wk_set_vr_param_get_accelerationX(msg);
    wk_set_vr_param->accelerationY = mavlink_msg_wk_set_vr_param_get_accelerationY(msg);
    wk_set_vr_param->accelerationZ = mavlink_msg_wk_set_vr_param_get_accelerationZ(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN? msg->len : MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN;
        memset(wk_set_vr_param, 0, MAVLINK_MSG_ID_WK_SET_VR_PARAM_LEN);
    memcpy(wk_set_vr_param, _MAV_PAYLOAD(msg), len);
#endif
}
