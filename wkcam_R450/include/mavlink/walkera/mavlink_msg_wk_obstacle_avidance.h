#pragma once
// MESSAGE WK_OBSTACLE_AVIDANCE PACKING

#define MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE 8003


typedef struct __mavlink_wk_obstacle_avidance_t {
 uint32_t avoid_dist_cm; /*<  avoidance distance,unit cm*/
 uint32_t front_radar_cm; /*<  distance of front radar*/
 uint32_t below_radar_cm; /*<  distance of below radar*/
 uint32_t behind_radar_cm; /*<  distance of behind radar*/
 uint32_t left_radar_cm; /*<  distance of left radar*/
 uint32_t right_radar_cm; /*<  distance of right radar*/
 uint16_t warning_position_bitmask; /*<  see enum WK_AVOID_WARNING_POSITION_TYPE*/
 uint16_t angle; /*<  (0~360)used only with 360-degrees obstacle-avoidance radar*/
 uint8_t enable; /*<  0:disable avoid function,1:enable aoidance function*/
 uint8_t radar_type; /*<  0:only front directory avoid support,1:360 degrees*/
 uint8_t warning_flag[8]; /*<  see enum WK_AVOID_WARNING_TYPE*/
} mavlink_wk_obstacle_avidance_t;

#define MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN 38
#define MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_MIN_LEN 38
#define MAVLINK_MSG_ID_8003_LEN 38
#define MAVLINK_MSG_ID_8003_MIN_LEN 38

#define MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_CRC 13
#define MAVLINK_MSG_ID_8003_CRC 13

#define MAVLINK_MSG_WK_OBSTACLE_AVIDANCE_FIELD_WARNING_FLAG_LEN 8

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_OBSTACLE_AVIDANCE { \
    8003, \
    "WK_OBSTACLE_AVIDANCE", \
    11, \
    {  { "enable", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_wk_obstacle_avidance_t, enable) }, \
         { "radar_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_wk_obstacle_avidance_t, radar_type) }, \
         { "warning_flag", NULL, MAVLINK_TYPE_UINT8_T, 8, 30, offsetof(mavlink_wk_obstacle_avidance_t, warning_flag) }, \
         { "warning_position_bitmask", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_wk_obstacle_avidance_t, warning_position_bitmask) }, \
         { "angle", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_wk_obstacle_avidance_t, angle) }, \
         { "avoid_dist_cm", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_obstacle_avidance_t, avoid_dist_cm) }, \
         { "front_radar_cm", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_obstacle_avidance_t, front_radar_cm) }, \
         { "below_radar_cm", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_obstacle_avidance_t, below_radar_cm) }, \
         { "behind_radar_cm", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_wk_obstacle_avidance_t, behind_radar_cm) }, \
         { "left_radar_cm", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_wk_obstacle_avidance_t, left_radar_cm) }, \
         { "right_radar_cm", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_wk_obstacle_avidance_t, right_radar_cm) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_OBSTACLE_AVIDANCE { \
    "WK_OBSTACLE_AVIDANCE", \
    11, \
    {  { "enable", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_wk_obstacle_avidance_t, enable) }, \
         { "radar_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_wk_obstacle_avidance_t, radar_type) }, \
         { "warning_flag", NULL, MAVLINK_TYPE_UINT8_T, 8, 30, offsetof(mavlink_wk_obstacle_avidance_t, warning_flag) }, \
         { "warning_position_bitmask", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_wk_obstacle_avidance_t, warning_position_bitmask) }, \
         { "angle", NULL, MAVLINK_TYPE_UINT16_T, 0, 26, offsetof(mavlink_wk_obstacle_avidance_t, angle) }, \
         { "avoid_dist_cm", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_obstacle_avidance_t, avoid_dist_cm) }, \
         { "front_radar_cm", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_obstacle_avidance_t, front_radar_cm) }, \
         { "below_radar_cm", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_obstacle_avidance_t, below_radar_cm) }, \
         { "behind_radar_cm", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_wk_obstacle_avidance_t, behind_radar_cm) }, \
         { "left_radar_cm", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_wk_obstacle_avidance_t, left_radar_cm) }, \
         { "right_radar_cm", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_wk_obstacle_avidance_t, right_radar_cm) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_obstacle_avidance message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param enable  0:disable avoid function,1:enable aoidance function
 * @param radar_type  0:only front directory avoid support,1:360 degrees
 * @param warning_flag  see enum WK_AVOID_WARNING_TYPE
 * @param warning_position_bitmask  see enum WK_AVOID_WARNING_POSITION_TYPE
 * @param angle  (0~360)used only with 360-degrees obstacle-avoidance radar
 * @param avoid_dist_cm  avoidance distance,unit cm
 * @param front_radar_cm  distance of front radar
 * @param below_radar_cm  distance of below radar
 * @param behind_radar_cm  distance of behind radar
 * @param left_radar_cm  distance of left radar
 * @param right_radar_cm  distance of right radar
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_obstacle_avidance_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t enable, uint8_t radar_type, const uint8_t *warning_flag, uint16_t warning_position_bitmask, uint16_t angle, uint32_t avoid_dist_cm, uint32_t front_radar_cm, uint32_t below_radar_cm, uint32_t behind_radar_cm, uint32_t left_radar_cm, uint32_t right_radar_cm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN];
    _mav_put_uint32_t(buf, 0, avoid_dist_cm);
    _mav_put_uint32_t(buf, 4, front_radar_cm);
    _mav_put_uint32_t(buf, 8, below_radar_cm);
    _mav_put_uint32_t(buf, 12, behind_radar_cm);
    _mav_put_uint32_t(buf, 16, left_radar_cm);
    _mav_put_uint32_t(buf, 20, right_radar_cm);
    _mav_put_uint16_t(buf, 24, warning_position_bitmask);
    _mav_put_uint16_t(buf, 26, angle);
    _mav_put_uint8_t(buf, 28, enable);
    _mav_put_uint8_t(buf, 29, radar_type);
    _mav_put_uint8_t_array(buf, 30, warning_flag, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN);
#else
    mavlink_wk_obstacle_avidance_t packet;
    packet.avoid_dist_cm = avoid_dist_cm;
    packet.front_radar_cm = front_radar_cm;
    packet.below_radar_cm = below_radar_cm;
    packet.behind_radar_cm = behind_radar_cm;
    packet.left_radar_cm = left_radar_cm;
    packet.right_radar_cm = right_radar_cm;
    packet.warning_position_bitmask = warning_position_bitmask;
    packet.angle = angle;
    packet.enable = enable;
    packet.radar_type = radar_type;
    mav_array_memcpy(packet.warning_flag, warning_flag, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_MIN_LEN, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_CRC);
}

/**
 * @brief Pack a wk_obstacle_avidance message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param enable  0:disable avoid function,1:enable aoidance function
 * @param radar_type  0:only front directory avoid support,1:360 degrees
 * @param warning_flag  see enum WK_AVOID_WARNING_TYPE
 * @param warning_position_bitmask  see enum WK_AVOID_WARNING_POSITION_TYPE
 * @param angle  (0~360)used only with 360-degrees obstacle-avoidance radar
 * @param avoid_dist_cm  avoidance distance,unit cm
 * @param front_radar_cm  distance of front radar
 * @param below_radar_cm  distance of below radar
 * @param behind_radar_cm  distance of behind radar
 * @param left_radar_cm  distance of left radar
 * @param right_radar_cm  distance of right radar
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_obstacle_avidance_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t enable,uint8_t radar_type,const uint8_t *warning_flag,uint16_t warning_position_bitmask,uint16_t angle,uint32_t avoid_dist_cm,uint32_t front_radar_cm,uint32_t below_radar_cm,uint32_t behind_radar_cm,uint32_t left_radar_cm,uint32_t right_radar_cm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN];
    _mav_put_uint32_t(buf, 0, avoid_dist_cm);
    _mav_put_uint32_t(buf, 4, front_radar_cm);
    _mav_put_uint32_t(buf, 8, below_radar_cm);
    _mav_put_uint32_t(buf, 12, behind_radar_cm);
    _mav_put_uint32_t(buf, 16, left_radar_cm);
    _mav_put_uint32_t(buf, 20, right_radar_cm);
    _mav_put_uint16_t(buf, 24, warning_position_bitmask);
    _mav_put_uint16_t(buf, 26, angle);
    _mav_put_uint8_t(buf, 28, enable);
    _mav_put_uint8_t(buf, 29, radar_type);
    _mav_put_uint8_t_array(buf, 30, warning_flag, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN);
#else
    mavlink_wk_obstacle_avidance_t packet;
    packet.avoid_dist_cm = avoid_dist_cm;
    packet.front_radar_cm = front_radar_cm;
    packet.below_radar_cm = below_radar_cm;
    packet.behind_radar_cm = behind_radar_cm;
    packet.left_radar_cm = left_radar_cm;
    packet.right_radar_cm = right_radar_cm;
    packet.warning_position_bitmask = warning_position_bitmask;
    packet.angle = angle;
    packet.enable = enable;
    packet.radar_type = radar_type;
    mav_array_memcpy(packet.warning_flag, warning_flag, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_MIN_LEN, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_CRC);
}

/**
 * @brief Encode a wk_obstacle_avidance struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_obstacle_avidance C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_obstacle_avidance_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_obstacle_avidance_t* wk_obstacle_avidance)
{
    return mavlink_msg_wk_obstacle_avidance_pack(system_id, component_id, msg, wk_obstacle_avidance->enable, wk_obstacle_avidance->radar_type, wk_obstacle_avidance->warning_flag, wk_obstacle_avidance->warning_position_bitmask, wk_obstacle_avidance->angle, wk_obstacle_avidance->avoid_dist_cm, wk_obstacle_avidance->front_radar_cm, wk_obstacle_avidance->below_radar_cm, wk_obstacle_avidance->behind_radar_cm, wk_obstacle_avidance->left_radar_cm, wk_obstacle_avidance->right_radar_cm);
}

/**
 * @brief Encode a wk_obstacle_avidance struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_obstacle_avidance C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_obstacle_avidance_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_obstacle_avidance_t* wk_obstacle_avidance)
{
    return mavlink_msg_wk_obstacle_avidance_pack_chan(system_id, component_id, chan, msg, wk_obstacle_avidance->enable, wk_obstacle_avidance->radar_type, wk_obstacle_avidance->warning_flag, wk_obstacle_avidance->warning_position_bitmask, wk_obstacle_avidance->angle, wk_obstacle_avidance->avoid_dist_cm, wk_obstacle_avidance->front_radar_cm, wk_obstacle_avidance->below_radar_cm, wk_obstacle_avidance->behind_radar_cm, wk_obstacle_avidance->left_radar_cm, wk_obstacle_avidance->right_radar_cm);
}

/**
 * @brief Send a wk_obstacle_avidance message
 * @param chan MAVLink channel to send the message
 *
 * @param enable  0:disable avoid function,1:enable aoidance function
 * @param radar_type  0:only front directory avoid support,1:360 degrees
 * @param warning_flag  see enum WK_AVOID_WARNING_TYPE
 * @param warning_position_bitmask  see enum WK_AVOID_WARNING_POSITION_TYPE
 * @param angle  (0~360)used only with 360-degrees obstacle-avoidance radar
 * @param avoid_dist_cm  avoidance distance,unit cm
 * @param front_radar_cm  distance of front radar
 * @param below_radar_cm  distance of below radar
 * @param behind_radar_cm  distance of behind radar
 * @param left_radar_cm  distance of left radar
 * @param right_radar_cm  distance of right radar
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_obstacle_avidance_send(mavlink_channel_t chan, uint8_t enable, uint8_t radar_type, const uint8_t *warning_flag, uint16_t warning_position_bitmask, uint16_t angle, uint32_t avoid_dist_cm, uint32_t front_radar_cm, uint32_t below_radar_cm, uint32_t behind_radar_cm, uint32_t left_radar_cm, uint32_t right_radar_cm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN];
    _mav_put_uint32_t(buf, 0, avoid_dist_cm);
    _mav_put_uint32_t(buf, 4, front_radar_cm);
    _mav_put_uint32_t(buf, 8, below_radar_cm);
    _mav_put_uint32_t(buf, 12, behind_radar_cm);
    _mav_put_uint32_t(buf, 16, left_radar_cm);
    _mav_put_uint32_t(buf, 20, right_radar_cm);
    _mav_put_uint16_t(buf, 24, warning_position_bitmask);
    _mav_put_uint16_t(buf, 26, angle);
    _mav_put_uint8_t(buf, 28, enable);
    _mav_put_uint8_t(buf, 29, radar_type);
    _mav_put_uint8_t_array(buf, 30, warning_flag, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE, buf, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_MIN_LEN, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_CRC);
#else
    mavlink_wk_obstacle_avidance_t packet;
    packet.avoid_dist_cm = avoid_dist_cm;
    packet.front_radar_cm = front_radar_cm;
    packet.below_radar_cm = below_radar_cm;
    packet.behind_radar_cm = behind_radar_cm;
    packet.left_radar_cm = left_radar_cm;
    packet.right_radar_cm = right_radar_cm;
    packet.warning_position_bitmask = warning_position_bitmask;
    packet.angle = angle;
    packet.enable = enable;
    packet.radar_type = radar_type;
    mav_array_memcpy(packet.warning_flag, warning_flag, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE, (const char *)&packet, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_MIN_LEN, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_CRC);
#endif
}

/**
 * @brief Send a wk_obstacle_avidance message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_obstacle_avidance_send_struct(mavlink_channel_t chan, const mavlink_wk_obstacle_avidance_t* wk_obstacle_avidance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_obstacle_avidance_send(chan, wk_obstacle_avidance->enable, wk_obstacle_avidance->radar_type, wk_obstacle_avidance->warning_flag, wk_obstacle_avidance->warning_position_bitmask, wk_obstacle_avidance->angle, wk_obstacle_avidance->avoid_dist_cm, wk_obstacle_avidance->front_radar_cm, wk_obstacle_avidance->below_radar_cm, wk_obstacle_avidance->behind_radar_cm, wk_obstacle_avidance->left_radar_cm, wk_obstacle_avidance->right_radar_cm);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE, (const char *)wk_obstacle_avidance, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_MIN_LEN, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_obstacle_avidance_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t enable, uint8_t radar_type, const uint8_t *warning_flag, uint16_t warning_position_bitmask, uint16_t angle, uint32_t avoid_dist_cm, uint32_t front_radar_cm, uint32_t below_radar_cm, uint32_t behind_radar_cm, uint32_t left_radar_cm, uint32_t right_radar_cm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, avoid_dist_cm);
    _mav_put_uint32_t(buf, 4, front_radar_cm);
    _mav_put_uint32_t(buf, 8, below_radar_cm);
    _mav_put_uint32_t(buf, 12, behind_radar_cm);
    _mav_put_uint32_t(buf, 16, left_radar_cm);
    _mav_put_uint32_t(buf, 20, right_radar_cm);
    _mav_put_uint16_t(buf, 24, warning_position_bitmask);
    _mav_put_uint16_t(buf, 26, angle);
    _mav_put_uint8_t(buf, 28, enable);
    _mav_put_uint8_t(buf, 29, radar_type);
    _mav_put_uint8_t_array(buf, 30, warning_flag, 8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE, buf, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_MIN_LEN, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_CRC);
#else
    mavlink_wk_obstacle_avidance_t *packet = (mavlink_wk_obstacle_avidance_t *)msgbuf;
    packet->avoid_dist_cm = avoid_dist_cm;
    packet->front_radar_cm = front_radar_cm;
    packet->below_radar_cm = below_radar_cm;
    packet->behind_radar_cm = behind_radar_cm;
    packet->left_radar_cm = left_radar_cm;
    packet->right_radar_cm = right_radar_cm;
    packet->warning_position_bitmask = warning_position_bitmask;
    packet->angle = angle;
    packet->enable = enable;
    packet->radar_type = radar_type;
    mav_array_memcpy(packet->warning_flag, warning_flag, sizeof(uint8_t)*8);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE, (const char *)packet, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_MIN_LEN, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_OBSTACLE_AVIDANCE UNPACKING


/**
 * @brief Get field enable from wk_obstacle_avidance message
 *
 * @return  0:disable avoid function,1:enable aoidance function
 */
static inline uint8_t mavlink_msg_wk_obstacle_avidance_get_enable(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field radar_type from wk_obstacle_avidance message
 *
 * @return  0:only front directory avoid support,1:360 degrees
 */
static inline uint8_t mavlink_msg_wk_obstacle_avidance_get_radar_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  29);
}

/**
 * @brief Get field warning_flag from wk_obstacle_avidance message
 *
 * @return  see enum WK_AVOID_WARNING_TYPE
 */
static inline uint16_t mavlink_msg_wk_obstacle_avidance_get_warning_flag(const mavlink_message_t* msg, uint8_t *warning_flag)
{
    return _MAV_RETURN_uint8_t_array(msg, warning_flag, 8,  30);
}

/**
 * @brief Get field warning_position_bitmask from wk_obstacle_avidance message
 *
 * @return  see enum WK_AVOID_WARNING_POSITION_TYPE
 */
static inline uint16_t mavlink_msg_wk_obstacle_avidance_get_warning_position_bitmask(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field angle from wk_obstacle_avidance message
 *
 * @return  (0~360)used only with 360-degrees obstacle-avoidance radar
 */
static inline uint16_t mavlink_msg_wk_obstacle_avidance_get_angle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field avoid_dist_cm from wk_obstacle_avidance message
 *
 * @return  avoidance distance,unit cm
 */
static inline uint32_t mavlink_msg_wk_obstacle_avidance_get_avoid_dist_cm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field front_radar_cm from wk_obstacle_avidance message
 *
 * @return  distance of front radar
 */
static inline uint32_t mavlink_msg_wk_obstacle_avidance_get_front_radar_cm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field below_radar_cm from wk_obstacle_avidance message
 *
 * @return  distance of below radar
 */
static inline uint32_t mavlink_msg_wk_obstacle_avidance_get_below_radar_cm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field behind_radar_cm from wk_obstacle_avidance message
 *
 * @return  distance of behind radar
 */
static inline uint32_t mavlink_msg_wk_obstacle_avidance_get_behind_radar_cm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field left_radar_cm from wk_obstacle_avidance message
 *
 * @return  distance of left radar
 */
static inline uint32_t mavlink_msg_wk_obstacle_avidance_get_left_radar_cm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field right_radar_cm from wk_obstacle_avidance message
 *
 * @return  distance of right radar
 */
static inline uint32_t mavlink_msg_wk_obstacle_avidance_get_right_radar_cm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Decode a wk_obstacle_avidance message into a struct
 *
 * @param msg The message to decode
 * @param wk_obstacle_avidance C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_obstacle_avidance_decode(const mavlink_message_t* msg, mavlink_wk_obstacle_avidance_t* wk_obstacle_avidance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_obstacle_avidance->avoid_dist_cm = mavlink_msg_wk_obstacle_avidance_get_avoid_dist_cm(msg);
    wk_obstacle_avidance->front_radar_cm = mavlink_msg_wk_obstacle_avidance_get_front_radar_cm(msg);
    wk_obstacle_avidance->below_radar_cm = mavlink_msg_wk_obstacle_avidance_get_below_radar_cm(msg);
    wk_obstacle_avidance->behind_radar_cm = mavlink_msg_wk_obstacle_avidance_get_behind_radar_cm(msg);
    wk_obstacle_avidance->left_radar_cm = mavlink_msg_wk_obstacle_avidance_get_left_radar_cm(msg);
    wk_obstacle_avidance->right_radar_cm = mavlink_msg_wk_obstacle_avidance_get_right_radar_cm(msg);
    wk_obstacle_avidance->warning_position_bitmask = mavlink_msg_wk_obstacle_avidance_get_warning_position_bitmask(msg);
    wk_obstacle_avidance->angle = mavlink_msg_wk_obstacle_avidance_get_angle(msg);
    wk_obstacle_avidance->enable = mavlink_msg_wk_obstacle_avidance_get_enable(msg);
    wk_obstacle_avidance->radar_type = mavlink_msg_wk_obstacle_avidance_get_radar_type(msg);
    mavlink_msg_wk_obstacle_avidance_get_warning_flag(msg, wk_obstacle_avidance->warning_flag);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN? msg->len : MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN;
        memset(wk_obstacle_avidance, 0, MAVLINK_MSG_ID_WK_OBSTACLE_AVIDANCE_LEN);
    memcpy(wk_obstacle_avidance, _MAV_PAYLOAD(msg), len);
#endif
}
