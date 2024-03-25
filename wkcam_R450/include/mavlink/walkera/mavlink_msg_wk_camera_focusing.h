#pragma once
// MESSAGE WK_CAMERA_FOCUSING PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_FOCUSING 8075


typedef struct __mavlink_wk_camera_focusing_t {
 int32_t timestamp; /*<  timestamp*/
 float focusing_x; /*<  focusing_x  normalization*/
 float focusing_y; /*<  focusing_y  normalization*/
 uint8_t direction; /*<  see WK_CMD_DIRECTION*/
 uint8_t focusing_type; /*<  focusing_type  0: tropism 1:fix point*/
 uint8_t tropism; /*<  tropism  0:forward  1:backward*/
} mavlink_wk_camera_focusing_t;

#define MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN 15
#define MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_MIN_LEN 15
#define MAVLINK_MSG_ID_8075_LEN 15
#define MAVLINK_MSG_ID_8075_MIN_LEN 15

#define MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_CRC 230
#define MAVLINK_MSG_ID_8075_CRC 230



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_FOCUSING { \
    8075, \
    "WK_CAMERA_FOCUSING", \
    6, \
    {  { "direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_wk_camera_focusing_t, direction) }, \
         { "timestamp", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_wk_camera_focusing_t, timestamp) }, \
         { "focusing_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_wk_camera_focusing_t, focusing_type) }, \
         { "tropism", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_wk_camera_focusing_t, tropism) }, \
         { "focusing_x", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_camera_focusing_t, focusing_x) }, \
         { "focusing_y", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_camera_focusing_t, focusing_y) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_FOCUSING { \
    "WK_CAMERA_FOCUSING", \
    6, \
    {  { "direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_wk_camera_focusing_t, direction) }, \
         { "timestamp", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_wk_camera_focusing_t, timestamp) }, \
         { "focusing_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_wk_camera_focusing_t, focusing_type) }, \
         { "tropism", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_wk_camera_focusing_t, tropism) }, \
         { "focusing_x", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_camera_focusing_t, focusing_x) }, \
         { "focusing_y", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_camera_focusing_t, focusing_y) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_focusing message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param direction  see WK_CMD_DIRECTION
 * @param timestamp  timestamp
 * @param focusing_type  focusing_type  0: tropism 1:fix point
 * @param tropism  tropism  0:forward  1:backward
 * @param focusing_x  focusing_x  normalization
 * @param focusing_y  focusing_y  normalization
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_focusing_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t direction, int32_t timestamp, uint8_t focusing_type, uint8_t tropism, float focusing_x, float focusing_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN];
    _mav_put_int32_t(buf, 0, timestamp);
    _mav_put_float(buf, 4, focusing_x);
    _mav_put_float(buf, 8, focusing_y);
    _mav_put_uint8_t(buf, 12, direction);
    _mav_put_uint8_t(buf, 13, focusing_type);
    _mav_put_uint8_t(buf, 14, tropism);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN);
#else
    mavlink_wk_camera_focusing_t packet;
    packet.timestamp = timestamp;
    packet.focusing_x = focusing_x;
    packet.focusing_y = focusing_y;
    packet.direction = direction;
    packet.focusing_type = focusing_type;
    packet.tropism = tropism;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_FOCUSING;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_CRC);
}

/**
 * @brief Pack a wk_camera_focusing message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param direction  see WK_CMD_DIRECTION
 * @param timestamp  timestamp
 * @param focusing_type  focusing_type  0: tropism 1:fix point
 * @param tropism  tropism  0:forward  1:backward
 * @param focusing_x  focusing_x  normalization
 * @param focusing_y  focusing_y  normalization
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_focusing_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t direction,int32_t timestamp,uint8_t focusing_type,uint8_t tropism,float focusing_x,float focusing_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN];
    _mav_put_int32_t(buf, 0, timestamp);
    _mav_put_float(buf, 4, focusing_x);
    _mav_put_float(buf, 8, focusing_y);
    _mav_put_uint8_t(buf, 12, direction);
    _mav_put_uint8_t(buf, 13, focusing_type);
    _mav_put_uint8_t(buf, 14, tropism);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN);
#else
    mavlink_wk_camera_focusing_t packet;
    packet.timestamp = timestamp;
    packet.focusing_x = focusing_x;
    packet.focusing_y = focusing_y;
    packet.direction = direction;
    packet.focusing_type = focusing_type;
    packet.tropism = tropism;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_FOCUSING;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_CRC);
}

/**
 * @brief Encode a wk_camera_focusing struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_focusing C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_focusing_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_focusing_t* wk_camera_focusing)
{
    return mavlink_msg_wk_camera_focusing_pack(system_id, component_id, msg, wk_camera_focusing->direction, wk_camera_focusing->timestamp, wk_camera_focusing->focusing_type, wk_camera_focusing->tropism, wk_camera_focusing->focusing_x, wk_camera_focusing->focusing_y);
}

/**
 * @brief Encode a wk_camera_focusing struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_focusing C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_focusing_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_focusing_t* wk_camera_focusing)
{
    return mavlink_msg_wk_camera_focusing_pack_chan(system_id, component_id, chan, msg, wk_camera_focusing->direction, wk_camera_focusing->timestamp, wk_camera_focusing->focusing_type, wk_camera_focusing->tropism, wk_camera_focusing->focusing_x, wk_camera_focusing->focusing_y);
}

/**
 * @brief Send a wk_camera_focusing message
 * @param chan MAVLink channel to send the message
 *
 * @param direction  see WK_CMD_DIRECTION
 * @param timestamp  timestamp
 * @param focusing_type  focusing_type  0: tropism 1:fix point
 * @param tropism  tropism  0:forward  1:backward
 * @param focusing_x  focusing_x  normalization
 * @param focusing_y  focusing_y  normalization
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_focusing_send(mavlink_channel_t chan, uint8_t direction, int32_t timestamp, uint8_t focusing_type, uint8_t tropism, float focusing_x, float focusing_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN];
    _mav_put_int32_t(buf, 0, timestamp);
    _mav_put_float(buf, 4, focusing_x);
    _mav_put_float(buf, 8, focusing_y);
    _mav_put_uint8_t(buf, 12, direction);
    _mav_put_uint8_t(buf, 13, focusing_type);
    _mav_put_uint8_t(buf, 14, tropism);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING, buf, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_CRC);
#else
    mavlink_wk_camera_focusing_t packet;
    packet.timestamp = timestamp;
    packet.focusing_x = focusing_x;
    packet.focusing_y = focusing_y;
    packet.direction = direction;
    packet.focusing_type = focusing_type;
    packet.tropism = tropism;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_CRC);
#endif
}

/**
 * @brief Send a wk_camera_focusing message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_focusing_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_focusing_t* wk_camera_focusing)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_focusing_send(chan, wk_camera_focusing->direction, wk_camera_focusing->timestamp, wk_camera_focusing->focusing_type, wk_camera_focusing->tropism, wk_camera_focusing->focusing_x, wk_camera_focusing->focusing_y);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING, (const char *)wk_camera_focusing, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_focusing_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t direction, int32_t timestamp, uint8_t focusing_type, uint8_t tropism, float focusing_x, float focusing_y)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, timestamp);
    _mav_put_float(buf, 4, focusing_x);
    _mav_put_float(buf, 8, focusing_y);
    _mav_put_uint8_t(buf, 12, direction);
    _mav_put_uint8_t(buf, 13, focusing_type);
    _mav_put_uint8_t(buf, 14, tropism);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING, buf, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_CRC);
#else
    mavlink_wk_camera_focusing_t *packet = (mavlink_wk_camera_focusing_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->focusing_x = focusing_x;
    packet->focusing_y = focusing_y;
    packet->direction = direction;
    packet->focusing_type = focusing_type;
    packet->tropism = tropism;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_FOCUSING UNPACKING


/**
 * @brief Get field direction from wk_camera_focusing message
 *
 * @return  see WK_CMD_DIRECTION
 */
static inline uint8_t mavlink_msg_wk_camera_focusing_get_direction(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field timestamp from wk_camera_focusing message
 *
 * @return  timestamp
 */
static inline int32_t mavlink_msg_wk_camera_focusing_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field focusing_type from wk_camera_focusing message
 *
 * @return  focusing_type  0: tropism 1:fix point
 */
static inline uint8_t mavlink_msg_wk_camera_focusing_get_focusing_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field tropism from wk_camera_focusing message
 *
 * @return  tropism  0:forward  1:backward
 */
static inline uint8_t mavlink_msg_wk_camera_focusing_get_tropism(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field focusing_x from wk_camera_focusing message
 *
 * @return  focusing_x  normalization
 */
static inline float mavlink_msg_wk_camera_focusing_get_focusing_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field focusing_y from wk_camera_focusing message
 *
 * @return  focusing_y  normalization
 */
static inline float mavlink_msg_wk_camera_focusing_get_focusing_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a wk_camera_focusing message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_focusing C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_focusing_decode(const mavlink_message_t* msg, mavlink_wk_camera_focusing_t* wk_camera_focusing)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_focusing->timestamp = mavlink_msg_wk_camera_focusing_get_timestamp(msg);
    wk_camera_focusing->focusing_x = mavlink_msg_wk_camera_focusing_get_focusing_x(msg);
    wk_camera_focusing->focusing_y = mavlink_msg_wk_camera_focusing_get_focusing_y(msg);
    wk_camera_focusing->direction = mavlink_msg_wk_camera_focusing_get_direction(msg);
    wk_camera_focusing->focusing_type = mavlink_msg_wk_camera_focusing_get_focusing_type(msg);
    wk_camera_focusing->tropism = mavlink_msg_wk_camera_focusing_get_tropism(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN;
        memset(wk_camera_focusing, 0, MAVLINK_MSG_ID_WK_CAMERA_FOCUSING_LEN);
    memcpy(wk_camera_focusing, _MAV_PAYLOAD(msg), len);
#endif
}
