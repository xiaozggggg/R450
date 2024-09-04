#pragma once
// MESSAGE WK_LOG_POS_CTRL PACKING

#define MAVLINK_MSG_ID_WK_LOG_POS_CTRL 8510


typedef struct __mavlink_wk_log_pos_ctrl_t {
 uint64_t timestamp; /*<  timestamp*/
 float target_vel_yaw; /*<  target_vel_yaw*/
 float target_yaw_rate; /*<  target_yaw_rate*/
 float target_vel_ef_x; /*<  target_vel_ef_x*/
 float target_vel_ef_y; /*<  target_vel_ef_y*/
 float target_vel_ef_z; /*<  target_vel_ef_z*/
 float target_vel_bf_x; /*<  target_vel_bf_x*/
 float target_vel_bf_y; /*<  target_vel_bf_y*/
 float target_bf_acc_x; /*<  target_bf_acc_x*/
 float target_bf_acc_y; /*<  target_bf_acc_y*/
 float target_pos_x; /*<  target_pos_x*/
 float target_pos_y; /*<  target_pos_y*/
 float target_pos_z; /*<  target_pos_z*/
} mavlink_wk_log_pos_ctrl_t;

#define MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN 56
#define MAVLINK_MSG_ID_WK_LOG_POS_CTRL_MIN_LEN 56
#define MAVLINK_MSG_ID_8510_LEN 56
#define MAVLINK_MSG_ID_8510_MIN_LEN 56

#define MAVLINK_MSG_ID_WK_LOG_POS_CTRL_CRC 231
#define MAVLINK_MSG_ID_8510_CRC 231



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_LOG_POS_CTRL { \
    8510, \
    "WK_LOG_POS_CTRL", \
    13, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_pos_ctrl_t, timestamp) }, \
         { "target_vel_yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_log_pos_ctrl_t, target_vel_yaw) }, \
         { "target_yaw_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_log_pos_ctrl_t, target_yaw_rate) }, \
         { "target_vel_ef_x", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_log_pos_ctrl_t, target_vel_ef_x) }, \
         { "target_vel_ef_y", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_log_pos_ctrl_t, target_vel_ef_y) }, \
         { "target_vel_ef_z", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wk_log_pos_ctrl_t, target_vel_ef_z) }, \
         { "target_vel_bf_x", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wk_log_pos_ctrl_t, target_vel_bf_x) }, \
         { "target_vel_bf_y", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wk_log_pos_ctrl_t, target_vel_bf_y) }, \
         { "target_bf_acc_x", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wk_log_pos_ctrl_t, target_bf_acc_x) }, \
         { "target_bf_acc_y", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_wk_log_pos_ctrl_t, target_bf_acc_y) }, \
         { "target_pos_x", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_wk_log_pos_ctrl_t, target_pos_x) }, \
         { "target_pos_y", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_wk_log_pos_ctrl_t, target_pos_y) }, \
         { "target_pos_z", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_wk_log_pos_ctrl_t, target_pos_z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_LOG_POS_CTRL { \
    "WK_LOG_POS_CTRL", \
    13, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_pos_ctrl_t, timestamp) }, \
         { "target_vel_yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_log_pos_ctrl_t, target_vel_yaw) }, \
         { "target_yaw_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_log_pos_ctrl_t, target_yaw_rate) }, \
         { "target_vel_ef_x", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_log_pos_ctrl_t, target_vel_ef_x) }, \
         { "target_vel_ef_y", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_log_pos_ctrl_t, target_vel_ef_y) }, \
         { "target_vel_ef_z", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wk_log_pos_ctrl_t, target_vel_ef_z) }, \
         { "target_vel_bf_x", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wk_log_pos_ctrl_t, target_vel_bf_x) }, \
         { "target_vel_bf_y", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wk_log_pos_ctrl_t, target_vel_bf_y) }, \
         { "target_bf_acc_x", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wk_log_pos_ctrl_t, target_bf_acc_x) }, \
         { "target_bf_acc_y", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_wk_log_pos_ctrl_t, target_bf_acc_y) }, \
         { "target_pos_x", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_wk_log_pos_ctrl_t, target_pos_x) }, \
         { "target_pos_y", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_wk_log_pos_ctrl_t, target_pos_y) }, \
         { "target_pos_z", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_wk_log_pos_ctrl_t, target_pos_z) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_log_pos_ctrl message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  timestamp
 * @param target_vel_yaw  target_vel_yaw
 * @param target_yaw_rate  target_yaw_rate
 * @param target_vel_ef_x  target_vel_ef_x
 * @param target_vel_ef_y  target_vel_ef_y
 * @param target_vel_ef_z  target_vel_ef_z
 * @param target_vel_bf_x  target_vel_bf_x
 * @param target_vel_bf_y  target_vel_bf_y
 * @param target_bf_acc_x  target_bf_acc_x
 * @param target_bf_acc_y  target_bf_acc_y
 * @param target_pos_x  target_pos_x
 * @param target_pos_y  target_pos_y
 * @param target_pos_z  target_pos_z
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_pos_ctrl_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, float target_vel_yaw, float target_yaw_rate, float target_vel_ef_x, float target_vel_ef_y, float target_vel_ef_z, float target_vel_bf_x, float target_vel_bf_y, float target_bf_acc_x, float target_bf_acc_y, float target_pos_x, float target_pos_y, float target_pos_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, target_vel_yaw);
    _mav_put_float(buf, 12, target_yaw_rate);
    _mav_put_float(buf, 16, target_vel_ef_x);
    _mav_put_float(buf, 20, target_vel_ef_y);
    _mav_put_float(buf, 24, target_vel_ef_z);
    _mav_put_float(buf, 28, target_vel_bf_x);
    _mav_put_float(buf, 32, target_vel_bf_y);
    _mav_put_float(buf, 36, target_bf_acc_x);
    _mav_put_float(buf, 40, target_bf_acc_y);
    _mav_put_float(buf, 44, target_pos_x);
    _mav_put_float(buf, 48, target_pos_y);
    _mav_put_float(buf, 52, target_pos_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN);
#else
    mavlink_wk_log_pos_ctrl_t packet;
    packet.timestamp = timestamp;
    packet.target_vel_yaw = target_vel_yaw;
    packet.target_yaw_rate = target_yaw_rate;
    packet.target_vel_ef_x = target_vel_ef_x;
    packet.target_vel_ef_y = target_vel_ef_y;
    packet.target_vel_ef_z = target_vel_ef_z;
    packet.target_vel_bf_x = target_vel_bf_x;
    packet.target_vel_bf_y = target_vel_bf_y;
    packet.target_bf_acc_x = target_bf_acc_x;
    packet.target_bf_acc_y = target_bf_acc_y;
    packet.target_pos_x = target_pos_x;
    packet.target_pos_y = target_pos_y;
    packet.target_pos_z = target_pos_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_POS_CTRL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_CRC);
}

/**
 * @brief Pack a wk_log_pos_ctrl message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  timestamp
 * @param target_vel_yaw  target_vel_yaw
 * @param target_yaw_rate  target_yaw_rate
 * @param target_vel_ef_x  target_vel_ef_x
 * @param target_vel_ef_y  target_vel_ef_y
 * @param target_vel_ef_z  target_vel_ef_z
 * @param target_vel_bf_x  target_vel_bf_x
 * @param target_vel_bf_y  target_vel_bf_y
 * @param target_bf_acc_x  target_bf_acc_x
 * @param target_bf_acc_y  target_bf_acc_y
 * @param target_pos_x  target_pos_x
 * @param target_pos_y  target_pos_y
 * @param target_pos_z  target_pos_z
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_pos_ctrl_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,float target_vel_yaw,float target_yaw_rate,float target_vel_ef_x,float target_vel_ef_y,float target_vel_ef_z,float target_vel_bf_x,float target_vel_bf_y,float target_bf_acc_x,float target_bf_acc_y,float target_pos_x,float target_pos_y,float target_pos_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, target_vel_yaw);
    _mav_put_float(buf, 12, target_yaw_rate);
    _mav_put_float(buf, 16, target_vel_ef_x);
    _mav_put_float(buf, 20, target_vel_ef_y);
    _mav_put_float(buf, 24, target_vel_ef_z);
    _mav_put_float(buf, 28, target_vel_bf_x);
    _mav_put_float(buf, 32, target_vel_bf_y);
    _mav_put_float(buf, 36, target_bf_acc_x);
    _mav_put_float(buf, 40, target_bf_acc_y);
    _mav_put_float(buf, 44, target_pos_x);
    _mav_put_float(buf, 48, target_pos_y);
    _mav_put_float(buf, 52, target_pos_z);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN);
#else
    mavlink_wk_log_pos_ctrl_t packet;
    packet.timestamp = timestamp;
    packet.target_vel_yaw = target_vel_yaw;
    packet.target_yaw_rate = target_yaw_rate;
    packet.target_vel_ef_x = target_vel_ef_x;
    packet.target_vel_ef_y = target_vel_ef_y;
    packet.target_vel_ef_z = target_vel_ef_z;
    packet.target_vel_bf_x = target_vel_bf_x;
    packet.target_vel_bf_y = target_vel_bf_y;
    packet.target_bf_acc_x = target_bf_acc_x;
    packet.target_bf_acc_y = target_bf_acc_y;
    packet.target_pos_x = target_pos_x;
    packet.target_pos_y = target_pos_y;
    packet.target_pos_z = target_pos_z;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_POS_CTRL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_CRC);
}

/**
 * @brief Encode a wk_log_pos_ctrl struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_pos_ctrl C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_pos_ctrl_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_log_pos_ctrl_t* wk_log_pos_ctrl)
{
    return mavlink_msg_wk_log_pos_ctrl_pack(system_id, component_id, msg, wk_log_pos_ctrl->timestamp, wk_log_pos_ctrl->target_vel_yaw, wk_log_pos_ctrl->target_yaw_rate, wk_log_pos_ctrl->target_vel_ef_x, wk_log_pos_ctrl->target_vel_ef_y, wk_log_pos_ctrl->target_vel_ef_z, wk_log_pos_ctrl->target_vel_bf_x, wk_log_pos_ctrl->target_vel_bf_y, wk_log_pos_ctrl->target_bf_acc_x, wk_log_pos_ctrl->target_bf_acc_y, wk_log_pos_ctrl->target_pos_x, wk_log_pos_ctrl->target_pos_y, wk_log_pos_ctrl->target_pos_z);
}

/**
 * @brief Encode a wk_log_pos_ctrl struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_pos_ctrl C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_pos_ctrl_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_log_pos_ctrl_t* wk_log_pos_ctrl)
{
    return mavlink_msg_wk_log_pos_ctrl_pack_chan(system_id, component_id, chan, msg, wk_log_pos_ctrl->timestamp, wk_log_pos_ctrl->target_vel_yaw, wk_log_pos_ctrl->target_yaw_rate, wk_log_pos_ctrl->target_vel_ef_x, wk_log_pos_ctrl->target_vel_ef_y, wk_log_pos_ctrl->target_vel_ef_z, wk_log_pos_ctrl->target_vel_bf_x, wk_log_pos_ctrl->target_vel_bf_y, wk_log_pos_ctrl->target_bf_acc_x, wk_log_pos_ctrl->target_bf_acc_y, wk_log_pos_ctrl->target_pos_x, wk_log_pos_ctrl->target_pos_y, wk_log_pos_ctrl->target_pos_z);
}

/**
 * @brief Send a wk_log_pos_ctrl message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 * @param target_vel_yaw  target_vel_yaw
 * @param target_yaw_rate  target_yaw_rate
 * @param target_vel_ef_x  target_vel_ef_x
 * @param target_vel_ef_y  target_vel_ef_y
 * @param target_vel_ef_z  target_vel_ef_z
 * @param target_vel_bf_x  target_vel_bf_x
 * @param target_vel_bf_y  target_vel_bf_y
 * @param target_bf_acc_x  target_bf_acc_x
 * @param target_bf_acc_y  target_bf_acc_y
 * @param target_pos_x  target_pos_x
 * @param target_pos_y  target_pos_y
 * @param target_pos_z  target_pos_z
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_log_pos_ctrl_send(mavlink_channel_t chan, uint64_t timestamp, float target_vel_yaw, float target_yaw_rate, float target_vel_ef_x, float target_vel_ef_y, float target_vel_ef_z, float target_vel_bf_x, float target_vel_bf_y, float target_bf_acc_x, float target_bf_acc_y, float target_pos_x, float target_pos_y, float target_pos_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, target_vel_yaw);
    _mav_put_float(buf, 12, target_yaw_rate);
    _mav_put_float(buf, 16, target_vel_ef_x);
    _mav_put_float(buf, 20, target_vel_ef_y);
    _mav_put_float(buf, 24, target_vel_ef_z);
    _mav_put_float(buf, 28, target_vel_bf_x);
    _mav_put_float(buf, 32, target_vel_bf_y);
    _mav_put_float(buf, 36, target_bf_acc_x);
    _mav_put_float(buf, 40, target_bf_acc_y);
    _mav_put_float(buf, 44, target_pos_x);
    _mav_put_float(buf, 48, target_pos_y);
    _mav_put_float(buf, 52, target_pos_z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_POS_CTRL, buf, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_CRC);
#else
    mavlink_wk_log_pos_ctrl_t packet;
    packet.timestamp = timestamp;
    packet.target_vel_yaw = target_vel_yaw;
    packet.target_yaw_rate = target_yaw_rate;
    packet.target_vel_ef_x = target_vel_ef_x;
    packet.target_vel_ef_y = target_vel_ef_y;
    packet.target_vel_ef_z = target_vel_ef_z;
    packet.target_vel_bf_x = target_vel_bf_x;
    packet.target_vel_bf_y = target_vel_bf_y;
    packet.target_bf_acc_x = target_bf_acc_x;
    packet.target_bf_acc_y = target_bf_acc_y;
    packet.target_pos_x = target_pos_x;
    packet.target_pos_y = target_pos_y;
    packet.target_pos_z = target_pos_z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_POS_CTRL, (const char *)&packet, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_CRC);
#endif
}

/**
 * @brief Send a wk_log_pos_ctrl message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_log_pos_ctrl_send_struct(mavlink_channel_t chan, const mavlink_wk_log_pos_ctrl_t* wk_log_pos_ctrl)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_log_pos_ctrl_send(chan, wk_log_pos_ctrl->timestamp, wk_log_pos_ctrl->target_vel_yaw, wk_log_pos_ctrl->target_yaw_rate, wk_log_pos_ctrl->target_vel_ef_x, wk_log_pos_ctrl->target_vel_ef_y, wk_log_pos_ctrl->target_vel_ef_z, wk_log_pos_ctrl->target_vel_bf_x, wk_log_pos_ctrl->target_vel_bf_y, wk_log_pos_ctrl->target_bf_acc_x, wk_log_pos_ctrl->target_bf_acc_y, wk_log_pos_ctrl->target_pos_x, wk_log_pos_ctrl->target_pos_y, wk_log_pos_ctrl->target_pos_z);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_POS_CTRL, (const char *)wk_log_pos_ctrl, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_log_pos_ctrl_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, float target_vel_yaw, float target_yaw_rate, float target_vel_ef_x, float target_vel_ef_y, float target_vel_ef_z, float target_vel_bf_x, float target_vel_bf_y, float target_bf_acc_x, float target_bf_acc_y, float target_pos_x, float target_pos_y, float target_pos_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, target_vel_yaw);
    _mav_put_float(buf, 12, target_yaw_rate);
    _mav_put_float(buf, 16, target_vel_ef_x);
    _mav_put_float(buf, 20, target_vel_ef_y);
    _mav_put_float(buf, 24, target_vel_ef_z);
    _mav_put_float(buf, 28, target_vel_bf_x);
    _mav_put_float(buf, 32, target_vel_bf_y);
    _mav_put_float(buf, 36, target_bf_acc_x);
    _mav_put_float(buf, 40, target_bf_acc_y);
    _mav_put_float(buf, 44, target_pos_x);
    _mav_put_float(buf, 48, target_pos_y);
    _mav_put_float(buf, 52, target_pos_z);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_POS_CTRL, buf, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_CRC);
#else
    mavlink_wk_log_pos_ctrl_t *packet = (mavlink_wk_log_pos_ctrl_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->target_vel_yaw = target_vel_yaw;
    packet->target_yaw_rate = target_yaw_rate;
    packet->target_vel_ef_x = target_vel_ef_x;
    packet->target_vel_ef_y = target_vel_ef_y;
    packet->target_vel_ef_z = target_vel_ef_z;
    packet->target_vel_bf_x = target_vel_bf_x;
    packet->target_vel_bf_y = target_vel_bf_y;
    packet->target_bf_acc_x = target_bf_acc_x;
    packet->target_bf_acc_y = target_bf_acc_y;
    packet->target_pos_x = target_pos_x;
    packet->target_pos_y = target_pos_y;
    packet->target_pos_z = target_pos_z;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_POS_CTRL, (const char *)packet, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_LOG_POS_CTRL UNPACKING


/**
 * @brief Get field timestamp from wk_log_pos_ctrl message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_wk_log_pos_ctrl_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field target_vel_yaw from wk_log_pos_ctrl message
 *
 * @return  target_vel_yaw
 */
static inline float mavlink_msg_wk_log_pos_ctrl_get_target_vel_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field target_yaw_rate from wk_log_pos_ctrl message
 *
 * @return  target_yaw_rate
 */
static inline float mavlink_msg_wk_log_pos_ctrl_get_target_yaw_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field target_vel_ef_x from wk_log_pos_ctrl message
 *
 * @return  target_vel_ef_x
 */
static inline float mavlink_msg_wk_log_pos_ctrl_get_target_vel_ef_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field target_vel_ef_y from wk_log_pos_ctrl message
 *
 * @return  target_vel_ef_y
 */
static inline float mavlink_msg_wk_log_pos_ctrl_get_target_vel_ef_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field target_vel_ef_z from wk_log_pos_ctrl message
 *
 * @return  target_vel_ef_z
 */
static inline float mavlink_msg_wk_log_pos_ctrl_get_target_vel_ef_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field target_vel_bf_x from wk_log_pos_ctrl message
 *
 * @return  target_vel_bf_x
 */
static inline float mavlink_msg_wk_log_pos_ctrl_get_target_vel_bf_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field target_vel_bf_y from wk_log_pos_ctrl message
 *
 * @return  target_vel_bf_y
 */
static inline float mavlink_msg_wk_log_pos_ctrl_get_target_vel_bf_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field target_bf_acc_x from wk_log_pos_ctrl message
 *
 * @return  target_bf_acc_x
 */
static inline float mavlink_msg_wk_log_pos_ctrl_get_target_bf_acc_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field target_bf_acc_y from wk_log_pos_ctrl message
 *
 * @return  target_bf_acc_y
 */
static inline float mavlink_msg_wk_log_pos_ctrl_get_target_bf_acc_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field target_pos_x from wk_log_pos_ctrl message
 *
 * @return  target_pos_x
 */
static inline float mavlink_msg_wk_log_pos_ctrl_get_target_pos_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field target_pos_y from wk_log_pos_ctrl message
 *
 * @return  target_pos_y
 */
static inline float mavlink_msg_wk_log_pos_ctrl_get_target_pos_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field target_pos_z from wk_log_pos_ctrl message
 *
 * @return  target_pos_z
 */
static inline float mavlink_msg_wk_log_pos_ctrl_get_target_pos_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Decode a wk_log_pos_ctrl message into a struct
 *
 * @param msg The message to decode
 * @param wk_log_pos_ctrl C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_log_pos_ctrl_decode(const mavlink_message_t* msg, mavlink_wk_log_pos_ctrl_t* wk_log_pos_ctrl)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_log_pos_ctrl->timestamp = mavlink_msg_wk_log_pos_ctrl_get_timestamp(msg);
    wk_log_pos_ctrl->target_vel_yaw = mavlink_msg_wk_log_pos_ctrl_get_target_vel_yaw(msg);
    wk_log_pos_ctrl->target_yaw_rate = mavlink_msg_wk_log_pos_ctrl_get_target_yaw_rate(msg);
    wk_log_pos_ctrl->target_vel_ef_x = mavlink_msg_wk_log_pos_ctrl_get_target_vel_ef_x(msg);
    wk_log_pos_ctrl->target_vel_ef_y = mavlink_msg_wk_log_pos_ctrl_get_target_vel_ef_y(msg);
    wk_log_pos_ctrl->target_vel_ef_z = mavlink_msg_wk_log_pos_ctrl_get_target_vel_ef_z(msg);
    wk_log_pos_ctrl->target_vel_bf_x = mavlink_msg_wk_log_pos_ctrl_get_target_vel_bf_x(msg);
    wk_log_pos_ctrl->target_vel_bf_y = mavlink_msg_wk_log_pos_ctrl_get_target_vel_bf_y(msg);
    wk_log_pos_ctrl->target_bf_acc_x = mavlink_msg_wk_log_pos_ctrl_get_target_bf_acc_x(msg);
    wk_log_pos_ctrl->target_bf_acc_y = mavlink_msg_wk_log_pos_ctrl_get_target_bf_acc_y(msg);
    wk_log_pos_ctrl->target_pos_x = mavlink_msg_wk_log_pos_ctrl_get_target_pos_x(msg);
    wk_log_pos_ctrl->target_pos_y = mavlink_msg_wk_log_pos_ctrl_get_target_pos_y(msg);
    wk_log_pos_ctrl->target_pos_z = mavlink_msg_wk_log_pos_ctrl_get_target_pos_z(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN? msg->len : MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN;
        memset(wk_log_pos_ctrl, 0, MAVLINK_MSG_ID_WK_LOG_POS_CTRL_LEN);
    memcpy(wk_log_pos_ctrl, _MAV_PAYLOAD(msg), len);
#endif
}
