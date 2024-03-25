#pragma once
// MESSAGE WK_SELFCHK_STATE PACKING

#define MAVLINK_MSG_ID_WK_SELFCHK_STATE 8016


typedef struct __mavlink_wk_selfchk_state_t {
 uint8_t gps_healthy; /*<  gps_healthy*/
 uint8_t inav_healthy; /*<  navigation healthy*/
 uint8_t compass_healthy; /*<  compass healthy*/
 uint8_t battery_healthy; /*<  battery_healthy*/
 uint8_t imu_healthy; /*<  imu_healthy*/
 uint8_t gyro_calib_flag; /*<  gyro calibration flag*/
 uint8_t acc_calib_flag; /*<  accelerometer calibration flag*/
 uint8_t compass_calib_flag; /*<  compass calibration flag*/
 uint8_t reserved[5]; /*<  reserved*/
} mavlink_wk_selfchk_state_t;

#define MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN 13
#define MAVLINK_MSG_ID_WK_SELFCHK_STATE_MIN_LEN 13
#define MAVLINK_MSG_ID_8016_LEN 13
#define MAVLINK_MSG_ID_8016_MIN_LEN 13

#define MAVLINK_MSG_ID_WK_SELFCHK_STATE_CRC 94
#define MAVLINK_MSG_ID_8016_CRC 94

#define MAVLINK_MSG_WK_SELFCHK_STATE_FIELD_RESERVED_LEN 5

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_SELFCHK_STATE { \
    8016, \
    "WK_SELFCHK_STATE", \
    9, \
    {  { "gps_healthy", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_selfchk_state_t, gps_healthy) }, \
         { "inav_healthy", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_selfchk_state_t, inav_healthy) }, \
         { "compass_healthy", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_selfchk_state_t, compass_healthy) }, \
         { "battery_healthy", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_selfchk_state_t, battery_healthy) }, \
         { "imu_healthy", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_selfchk_state_t, imu_healthy) }, \
         { "gyro_calib_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_selfchk_state_t, gyro_calib_flag) }, \
         { "acc_calib_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_selfchk_state_t, acc_calib_flag) }, \
         { "compass_calib_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_wk_selfchk_state_t, compass_calib_flag) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 5, 8, offsetof(mavlink_wk_selfchk_state_t, reserved) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_SELFCHK_STATE { \
    "WK_SELFCHK_STATE", \
    9, \
    {  { "gps_healthy", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_selfchk_state_t, gps_healthy) }, \
         { "inav_healthy", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_selfchk_state_t, inav_healthy) }, \
         { "compass_healthy", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_selfchk_state_t, compass_healthy) }, \
         { "battery_healthy", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_selfchk_state_t, battery_healthy) }, \
         { "imu_healthy", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_selfchk_state_t, imu_healthy) }, \
         { "gyro_calib_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_selfchk_state_t, gyro_calib_flag) }, \
         { "acc_calib_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_selfchk_state_t, acc_calib_flag) }, \
         { "compass_calib_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_wk_selfchk_state_t, compass_calib_flag) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 5, 8, offsetof(mavlink_wk_selfchk_state_t, reserved) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_selfchk_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param gps_healthy  gps_healthy
 * @param inav_healthy  navigation healthy
 * @param compass_healthy  compass healthy
 * @param battery_healthy  battery_healthy
 * @param imu_healthy  imu_healthy
 * @param gyro_calib_flag  gyro calibration flag
 * @param acc_calib_flag  accelerometer calibration flag
 * @param compass_calib_flag  compass calibration flag
 * @param reserved  reserved
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_selfchk_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t gps_healthy, uint8_t inav_healthy, uint8_t compass_healthy, uint8_t battery_healthy, uint8_t imu_healthy, uint8_t gyro_calib_flag, uint8_t acc_calib_flag, uint8_t compass_calib_flag, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN];
    _mav_put_uint8_t(buf, 0, gps_healthy);
    _mav_put_uint8_t(buf, 1, inav_healthy);
    _mav_put_uint8_t(buf, 2, compass_healthy);
    _mav_put_uint8_t(buf, 3, battery_healthy);
    _mav_put_uint8_t(buf, 4, imu_healthy);
    _mav_put_uint8_t(buf, 5, gyro_calib_flag);
    _mav_put_uint8_t(buf, 6, acc_calib_flag);
    _mav_put_uint8_t(buf, 7, compass_calib_flag);
    _mav_put_uint8_t_array(buf, 8, reserved, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN);
#else
    mavlink_wk_selfchk_state_t packet;
    packet.gps_healthy = gps_healthy;
    packet.inav_healthy = inav_healthy;
    packet.compass_healthy = compass_healthy;
    packet.battery_healthy = battery_healthy;
    packet.imu_healthy = imu_healthy;
    packet.gyro_calib_flag = gyro_calib_flag;
    packet.acc_calib_flag = acc_calib_flag;
    packet.compass_calib_flag = compass_calib_flag;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_SELFCHK_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_SELFCHK_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN, MAVLINK_MSG_ID_WK_SELFCHK_STATE_CRC);
}

/**
 * @brief Pack a wk_selfchk_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gps_healthy  gps_healthy
 * @param inav_healthy  navigation healthy
 * @param compass_healthy  compass healthy
 * @param battery_healthy  battery_healthy
 * @param imu_healthy  imu_healthy
 * @param gyro_calib_flag  gyro calibration flag
 * @param acc_calib_flag  accelerometer calibration flag
 * @param compass_calib_flag  compass calibration flag
 * @param reserved  reserved
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_selfchk_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t gps_healthy,uint8_t inav_healthy,uint8_t compass_healthy,uint8_t battery_healthy,uint8_t imu_healthy,uint8_t gyro_calib_flag,uint8_t acc_calib_flag,uint8_t compass_calib_flag,const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN];
    _mav_put_uint8_t(buf, 0, gps_healthy);
    _mav_put_uint8_t(buf, 1, inav_healthy);
    _mav_put_uint8_t(buf, 2, compass_healthy);
    _mav_put_uint8_t(buf, 3, battery_healthy);
    _mav_put_uint8_t(buf, 4, imu_healthy);
    _mav_put_uint8_t(buf, 5, gyro_calib_flag);
    _mav_put_uint8_t(buf, 6, acc_calib_flag);
    _mav_put_uint8_t(buf, 7, compass_calib_flag);
    _mav_put_uint8_t_array(buf, 8, reserved, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN);
#else
    mavlink_wk_selfchk_state_t packet;
    packet.gps_healthy = gps_healthy;
    packet.inav_healthy = inav_healthy;
    packet.compass_healthy = compass_healthy;
    packet.battery_healthy = battery_healthy;
    packet.imu_healthy = imu_healthy;
    packet.gyro_calib_flag = gyro_calib_flag;
    packet.acc_calib_flag = acc_calib_flag;
    packet.compass_calib_flag = compass_calib_flag;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_SELFCHK_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_SELFCHK_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN, MAVLINK_MSG_ID_WK_SELFCHK_STATE_CRC);
}

/**
 * @brief Encode a wk_selfchk_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_selfchk_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_selfchk_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_selfchk_state_t* wk_selfchk_state)
{
    return mavlink_msg_wk_selfchk_state_pack(system_id, component_id, msg, wk_selfchk_state->gps_healthy, wk_selfchk_state->inav_healthy, wk_selfchk_state->compass_healthy, wk_selfchk_state->battery_healthy, wk_selfchk_state->imu_healthy, wk_selfchk_state->gyro_calib_flag, wk_selfchk_state->acc_calib_flag, wk_selfchk_state->compass_calib_flag, wk_selfchk_state->reserved);
}

/**
 * @brief Encode a wk_selfchk_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_selfchk_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_selfchk_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_selfchk_state_t* wk_selfchk_state)
{
    return mavlink_msg_wk_selfchk_state_pack_chan(system_id, component_id, chan, msg, wk_selfchk_state->gps_healthy, wk_selfchk_state->inav_healthy, wk_selfchk_state->compass_healthy, wk_selfchk_state->battery_healthy, wk_selfchk_state->imu_healthy, wk_selfchk_state->gyro_calib_flag, wk_selfchk_state->acc_calib_flag, wk_selfchk_state->compass_calib_flag, wk_selfchk_state->reserved);
}

/**
 * @brief Send a wk_selfchk_state message
 * @param chan MAVLink channel to send the message
 *
 * @param gps_healthy  gps_healthy
 * @param inav_healthy  navigation healthy
 * @param compass_healthy  compass healthy
 * @param battery_healthy  battery_healthy
 * @param imu_healthy  imu_healthy
 * @param gyro_calib_flag  gyro calibration flag
 * @param acc_calib_flag  accelerometer calibration flag
 * @param compass_calib_flag  compass calibration flag
 * @param reserved  reserved
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_selfchk_state_send(mavlink_channel_t chan, uint8_t gps_healthy, uint8_t inav_healthy, uint8_t compass_healthy, uint8_t battery_healthy, uint8_t imu_healthy, uint8_t gyro_calib_flag, uint8_t acc_calib_flag, uint8_t compass_calib_flag, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN];
    _mav_put_uint8_t(buf, 0, gps_healthy);
    _mav_put_uint8_t(buf, 1, inav_healthy);
    _mav_put_uint8_t(buf, 2, compass_healthy);
    _mav_put_uint8_t(buf, 3, battery_healthy);
    _mav_put_uint8_t(buf, 4, imu_healthy);
    _mav_put_uint8_t(buf, 5, gyro_calib_flag);
    _mav_put_uint8_t(buf, 6, acc_calib_flag);
    _mav_put_uint8_t(buf, 7, compass_calib_flag);
    _mav_put_uint8_t_array(buf, 8, reserved, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SELFCHK_STATE, buf, MAVLINK_MSG_ID_WK_SELFCHK_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN, MAVLINK_MSG_ID_WK_SELFCHK_STATE_CRC);
#else
    mavlink_wk_selfchk_state_t packet;
    packet.gps_healthy = gps_healthy;
    packet.inav_healthy = inav_healthy;
    packet.compass_healthy = compass_healthy;
    packet.battery_healthy = battery_healthy;
    packet.imu_healthy = imu_healthy;
    packet.gyro_calib_flag = gyro_calib_flag;
    packet.acc_calib_flag = acc_calib_flag;
    packet.compass_calib_flag = compass_calib_flag;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SELFCHK_STATE, (const char *)&packet, MAVLINK_MSG_ID_WK_SELFCHK_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN, MAVLINK_MSG_ID_WK_SELFCHK_STATE_CRC);
#endif
}

/**
 * @brief Send a wk_selfchk_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_selfchk_state_send_struct(mavlink_channel_t chan, const mavlink_wk_selfchk_state_t* wk_selfchk_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_selfchk_state_send(chan, wk_selfchk_state->gps_healthy, wk_selfchk_state->inav_healthy, wk_selfchk_state->compass_healthy, wk_selfchk_state->battery_healthy, wk_selfchk_state->imu_healthy, wk_selfchk_state->gyro_calib_flag, wk_selfchk_state->acc_calib_flag, wk_selfchk_state->compass_calib_flag, wk_selfchk_state->reserved);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SELFCHK_STATE, (const char *)wk_selfchk_state, MAVLINK_MSG_ID_WK_SELFCHK_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN, MAVLINK_MSG_ID_WK_SELFCHK_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_selfchk_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t gps_healthy, uint8_t inav_healthy, uint8_t compass_healthy, uint8_t battery_healthy, uint8_t imu_healthy, uint8_t gyro_calib_flag, uint8_t acc_calib_flag, uint8_t compass_calib_flag, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, gps_healthy);
    _mav_put_uint8_t(buf, 1, inav_healthy);
    _mav_put_uint8_t(buf, 2, compass_healthy);
    _mav_put_uint8_t(buf, 3, battery_healthy);
    _mav_put_uint8_t(buf, 4, imu_healthy);
    _mav_put_uint8_t(buf, 5, gyro_calib_flag);
    _mav_put_uint8_t(buf, 6, acc_calib_flag);
    _mav_put_uint8_t(buf, 7, compass_calib_flag);
    _mav_put_uint8_t_array(buf, 8, reserved, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SELFCHK_STATE, buf, MAVLINK_MSG_ID_WK_SELFCHK_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN, MAVLINK_MSG_ID_WK_SELFCHK_STATE_CRC);
#else
    mavlink_wk_selfchk_state_t *packet = (mavlink_wk_selfchk_state_t *)msgbuf;
    packet->gps_healthy = gps_healthy;
    packet->inav_healthy = inav_healthy;
    packet->compass_healthy = compass_healthy;
    packet->battery_healthy = battery_healthy;
    packet->imu_healthy = imu_healthy;
    packet->gyro_calib_flag = gyro_calib_flag;
    packet->acc_calib_flag = acc_calib_flag;
    packet->compass_calib_flag = compass_calib_flag;
    mav_array_memcpy(packet->reserved, reserved, sizeof(uint8_t)*5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SELFCHK_STATE, (const char *)packet, MAVLINK_MSG_ID_WK_SELFCHK_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN, MAVLINK_MSG_ID_WK_SELFCHK_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_SELFCHK_STATE UNPACKING


/**
 * @brief Get field gps_healthy from wk_selfchk_state message
 *
 * @return  gps_healthy
 */
static inline uint8_t mavlink_msg_wk_selfchk_state_get_gps_healthy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field inav_healthy from wk_selfchk_state message
 *
 * @return  navigation healthy
 */
static inline uint8_t mavlink_msg_wk_selfchk_state_get_inav_healthy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field compass_healthy from wk_selfchk_state message
 *
 * @return  compass healthy
 */
static inline uint8_t mavlink_msg_wk_selfchk_state_get_compass_healthy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field battery_healthy from wk_selfchk_state message
 *
 * @return  battery_healthy
 */
static inline uint8_t mavlink_msg_wk_selfchk_state_get_battery_healthy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field imu_healthy from wk_selfchk_state message
 *
 * @return  imu_healthy
 */
static inline uint8_t mavlink_msg_wk_selfchk_state_get_imu_healthy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field gyro_calib_flag from wk_selfchk_state message
 *
 * @return  gyro calibration flag
 */
static inline uint8_t mavlink_msg_wk_selfchk_state_get_gyro_calib_flag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field acc_calib_flag from wk_selfchk_state message
 *
 * @return  accelerometer calibration flag
 */
static inline uint8_t mavlink_msg_wk_selfchk_state_get_acc_calib_flag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field compass_calib_flag from wk_selfchk_state message
 *
 * @return  compass calibration flag
 */
static inline uint8_t mavlink_msg_wk_selfchk_state_get_compass_calib_flag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field reserved from wk_selfchk_state message
 *
 * @return  reserved
 */
static inline uint16_t mavlink_msg_wk_selfchk_state_get_reserved(const mavlink_message_t* msg, uint8_t *reserved)
{
    return _MAV_RETURN_uint8_t_array(msg, reserved, 5,  8);
}

/**
 * @brief Decode a wk_selfchk_state message into a struct
 *
 * @param msg The message to decode
 * @param wk_selfchk_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_selfchk_state_decode(const mavlink_message_t* msg, mavlink_wk_selfchk_state_t* wk_selfchk_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_selfchk_state->gps_healthy = mavlink_msg_wk_selfchk_state_get_gps_healthy(msg);
    wk_selfchk_state->inav_healthy = mavlink_msg_wk_selfchk_state_get_inav_healthy(msg);
    wk_selfchk_state->compass_healthy = mavlink_msg_wk_selfchk_state_get_compass_healthy(msg);
    wk_selfchk_state->battery_healthy = mavlink_msg_wk_selfchk_state_get_battery_healthy(msg);
    wk_selfchk_state->imu_healthy = mavlink_msg_wk_selfchk_state_get_imu_healthy(msg);
    wk_selfchk_state->gyro_calib_flag = mavlink_msg_wk_selfchk_state_get_gyro_calib_flag(msg);
    wk_selfchk_state->acc_calib_flag = mavlink_msg_wk_selfchk_state_get_acc_calib_flag(msg);
    wk_selfchk_state->compass_calib_flag = mavlink_msg_wk_selfchk_state_get_compass_calib_flag(msg);
    mavlink_msg_wk_selfchk_state_get_reserved(msg, wk_selfchk_state->reserved);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN? msg->len : MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN;
        memset(wk_selfchk_state, 0, MAVLINK_MSG_ID_WK_SELFCHK_STATE_LEN);
    memcpy(wk_selfchk_state, _MAV_PAYLOAD(msg), len);
#endif
}
