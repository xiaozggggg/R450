#pragma once
// MESSAGE WK_TIME_LAPSE_DIRE_PARAM PACKING

#define MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM 8065


typedef struct __mavlink_wk_time_lapse_dire_param_t {
 float Uavspeed; /*<  uav speed*/
 float UavYaw; /*<  uav yaw angle,unit degree*/
} mavlink_wk_time_lapse_dire_param_t;

#define MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN 8
#define MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_MIN_LEN 8
#define MAVLINK_MSG_ID_8065_LEN 8
#define MAVLINK_MSG_ID_8065_MIN_LEN 8

#define MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_CRC 200
#define MAVLINK_MSG_ID_8065_CRC 200



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_TIME_LAPSE_DIRE_PARAM { \
    8065, \
    "WK_TIME_LAPSE_DIRE_PARAM", \
    2, \
    {  { "Uavspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_time_lapse_dire_param_t, Uavspeed) }, \
         { "UavYaw", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_time_lapse_dire_param_t, UavYaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_TIME_LAPSE_DIRE_PARAM { \
    "WK_TIME_LAPSE_DIRE_PARAM", \
    2, \
    {  { "Uavspeed", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_time_lapse_dire_param_t, Uavspeed) }, \
         { "UavYaw", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_time_lapse_dire_param_t, UavYaw) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_time_lapse_dire_param message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param Uavspeed  uav speed
 * @param UavYaw  uav yaw angle,unit degree
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_time_lapse_dire_param_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float Uavspeed, float UavYaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN];
    _mav_put_float(buf, 0, Uavspeed);
    _mav_put_float(buf, 4, UavYaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN);
#else
    mavlink_wk_time_lapse_dire_param_t packet;
    packet.Uavspeed = Uavspeed;
    packet.UavYaw = UavYaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_CRC);
}

/**
 * @brief Pack a wk_time_lapse_dire_param message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param Uavspeed  uav speed
 * @param UavYaw  uav yaw angle,unit degree
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_time_lapse_dire_param_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float Uavspeed,float UavYaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN];
    _mav_put_float(buf, 0, Uavspeed);
    _mav_put_float(buf, 4, UavYaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN);
#else
    mavlink_wk_time_lapse_dire_param_t packet;
    packet.Uavspeed = Uavspeed;
    packet.UavYaw = UavYaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_CRC);
}

/**
 * @brief Encode a wk_time_lapse_dire_param struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_time_lapse_dire_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_time_lapse_dire_param_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_time_lapse_dire_param_t* wk_time_lapse_dire_param)
{
    return mavlink_msg_wk_time_lapse_dire_param_pack(system_id, component_id, msg, wk_time_lapse_dire_param->Uavspeed, wk_time_lapse_dire_param->UavYaw);
}

/**
 * @brief Encode a wk_time_lapse_dire_param struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_time_lapse_dire_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_time_lapse_dire_param_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_time_lapse_dire_param_t* wk_time_lapse_dire_param)
{
    return mavlink_msg_wk_time_lapse_dire_param_pack_chan(system_id, component_id, chan, msg, wk_time_lapse_dire_param->Uavspeed, wk_time_lapse_dire_param->UavYaw);
}

/**
 * @brief Send a wk_time_lapse_dire_param message
 * @param chan MAVLink channel to send the message
 *
 * @param Uavspeed  uav speed
 * @param UavYaw  uav yaw angle,unit degree
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_time_lapse_dire_param_send(mavlink_channel_t chan, float Uavspeed, float UavYaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN];
    _mav_put_float(buf, 0, Uavspeed);
    _mav_put_float(buf, 4, UavYaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM, buf, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_CRC);
#else
    mavlink_wk_time_lapse_dire_param_t packet;
    packet.Uavspeed = Uavspeed;
    packet.UavYaw = UavYaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM, (const char *)&packet, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_CRC);
#endif
}

/**
 * @brief Send a wk_time_lapse_dire_param message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_time_lapse_dire_param_send_struct(mavlink_channel_t chan, const mavlink_wk_time_lapse_dire_param_t* wk_time_lapse_dire_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_time_lapse_dire_param_send(chan, wk_time_lapse_dire_param->Uavspeed, wk_time_lapse_dire_param->UavYaw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM, (const char *)wk_time_lapse_dire_param, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_time_lapse_dire_param_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float Uavspeed, float UavYaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, Uavspeed);
    _mav_put_float(buf, 4, UavYaw);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM, buf, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_CRC);
#else
    mavlink_wk_time_lapse_dire_param_t *packet = (mavlink_wk_time_lapse_dire_param_t *)msgbuf;
    packet->Uavspeed = Uavspeed;
    packet->UavYaw = UavYaw;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM, (const char *)packet, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_TIME_LAPSE_DIRE_PARAM UNPACKING


/**
 * @brief Get field Uavspeed from wk_time_lapse_dire_param message
 *
 * @return  uav speed
 */
static inline float mavlink_msg_wk_time_lapse_dire_param_get_Uavspeed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field UavYaw from wk_time_lapse_dire_param message
 *
 * @return  uav yaw angle,unit degree
 */
static inline float mavlink_msg_wk_time_lapse_dire_param_get_UavYaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Decode a wk_time_lapse_dire_param message into a struct
 *
 * @param msg The message to decode
 * @param wk_time_lapse_dire_param C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_time_lapse_dire_param_decode(const mavlink_message_t* msg, mavlink_wk_time_lapse_dire_param_t* wk_time_lapse_dire_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_time_lapse_dire_param->Uavspeed = mavlink_msg_wk_time_lapse_dire_param_get_Uavspeed(msg);
    wk_time_lapse_dire_param->UavYaw = mavlink_msg_wk_time_lapse_dire_param_get_UavYaw(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN? msg->len : MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN;
        memset(wk_time_lapse_dire_param, 0, MAVLINK_MSG_ID_WK_TIME_LAPSE_DIRE_PARAM_LEN);
    memcpy(wk_time_lapse_dire_param, _MAV_PAYLOAD(msg), len);
#endif
}
