#pragma once
// MESSAGE WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA 8100


typedef struct __mavlink_wk_camera_visual_intertial_odometry_data_t {
 uint64_t timestamp; /*<  timestamp*/
 uint32_t ave_lun; /*<  ave_lun*/
 float x; /*<  x*/
 float y; /*<  y*/
 float z; /*<  z*/
 float quaternion[4]; /*<  quaternion*/
 float reserve[4]; /*<  reserve*/
 uint16_t corner; /*<  corner*/
 uint16_t width; /*<  width*/
 uint16_t height; /*<  height*/
} mavlink_wk_camera_visual_intertial_odometry_data_t;

#define MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN 62
#define MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_MIN_LEN 62
#define MAVLINK_MSG_ID_8100_LEN 62
#define MAVLINK_MSG_ID_8100_MIN_LEN 62

#define MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_CRC 179
#define MAVLINK_MSG_ID_8100_CRC 179

#define MAVLINK_MSG_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_FIELD_QUATERNION_LEN 4
#define MAVLINK_MSG_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_FIELD_RESERVE_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA { \
    8100, \
    "WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA", \
    10, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, timestamp) }, \
         { "ave_lun", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, ave_lun) }, \
         { "corner", NULL, MAVLINK_TYPE_UINT16_T, 0, 56, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, corner) }, \
         { "width", NULL, MAVLINK_TYPE_UINT16_T, 0, 58, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, width) }, \
         { "height", NULL, MAVLINK_TYPE_UINT16_T, 0, 60, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, height) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, z) }, \
         { "quaternion", NULL, MAVLINK_TYPE_FLOAT, 4, 24, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, quaternion) }, \
         { "reserve", NULL, MAVLINK_TYPE_FLOAT, 4, 40, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, reserve) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA { \
    "WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA", \
    10, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, timestamp) }, \
         { "ave_lun", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, ave_lun) }, \
         { "corner", NULL, MAVLINK_TYPE_UINT16_T, 0, 56, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, corner) }, \
         { "width", NULL, MAVLINK_TYPE_UINT16_T, 0, 58, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, width) }, \
         { "height", NULL, MAVLINK_TYPE_UINT16_T, 0, 60, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, height) }, \
         { "x", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, z) }, \
         { "quaternion", NULL, MAVLINK_TYPE_FLOAT, 4, 24, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, quaternion) }, \
         { "reserve", NULL, MAVLINK_TYPE_FLOAT, 4, 40, offsetof(mavlink_wk_camera_visual_intertial_odometry_data_t, reserve) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_visual_intertial_odometry_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  timestamp
 * @param ave_lun  ave_lun
 * @param corner  corner
 * @param width  width
 * @param height  height
 * @param x  x
 * @param y  y
 * @param z  z
 * @param quaternion  quaternion
 * @param reserve  reserve
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_visual_intertial_odometry_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint32_t ave_lun, uint16_t corner, uint16_t width, uint16_t height, float x, float y, float z, const float *quaternion, const float *reserve)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, ave_lun);
    _mav_put_float(buf, 12, x);
    _mav_put_float(buf, 16, y);
    _mav_put_float(buf, 20, z);
    _mav_put_uint16_t(buf, 56, corner);
    _mav_put_uint16_t(buf, 58, width);
    _mav_put_uint16_t(buf, 60, height);
    _mav_put_float_array(buf, 24, quaternion, 4);
    _mav_put_float_array(buf, 40, reserve, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN);
#else
    mavlink_wk_camera_visual_intertial_odometry_data_t packet;
    packet.timestamp = timestamp;
    packet.ave_lun = ave_lun;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.corner = corner;
    packet.width = width;
    packet.height = height;
    mav_array_memcpy(packet.quaternion, quaternion, sizeof(float)*4);
    mav_array_memcpy(packet.reserve, reserve, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_CRC);
}

/**
 * @brief Pack a wk_camera_visual_intertial_odometry_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  timestamp
 * @param ave_lun  ave_lun
 * @param corner  corner
 * @param width  width
 * @param height  height
 * @param x  x
 * @param y  y
 * @param z  z
 * @param quaternion  quaternion
 * @param reserve  reserve
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_visual_intertial_odometry_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,uint32_t ave_lun,uint16_t corner,uint16_t width,uint16_t height,float x,float y,float z,const float *quaternion,const float *reserve)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, ave_lun);
    _mav_put_float(buf, 12, x);
    _mav_put_float(buf, 16, y);
    _mav_put_float(buf, 20, z);
    _mav_put_uint16_t(buf, 56, corner);
    _mav_put_uint16_t(buf, 58, width);
    _mav_put_uint16_t(buf, 60, height);
    _mav_put_float_array(buf, 24, quaternion, 4);
    _mav_put_float_array(buf, 40, reserve, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN);
#else
    mavlink_wk_camera_visual_intertial_odometry_data_t packet;
    packet.timestamp = timestamp;
    packet.ave_lun = ave_lun;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.corner = corner;
    packet.width = width;
    packet.height = height;
    mav_array_memcpy(packet.quaternion, quaternion, sizeof(float)*4);
    mav_array_memcpy(packet.reserve, reserve, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_CRC);
}

/**
 * @brief Encode a wk_camera_visual_intertial_odometry_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_visual_intertial_odometry_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_visual_intertial_odometry_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_visual_intertial_odometry_data_t* wk_camera_visual_intertial_odometry_data)
{
    return mavlink_msg_wk_camera_visual_intertial_odometry_data_pack(system_id, component_id, msg, wk_camera_visual_intertial_odometry_data->timestamp, wk_camera_visual_intertial_odometry_data->ave_lun, wk_camera_visual_intertial_odometry_data->corner, wk_camera_visual_intertial_odometry_data->width, wk_camera_visual_intertial_odometry_data->height, wk_camera_visual_intertial_odometry_data->x, wk_camera_visual_intertial_odometry_data->y, wk_camera_visual_intertial_odometry_data->z, wk_camera_visual_intertial_odometry_data->quaternion, wk_camera_visual_intertial_odometry_data->reserve);
}

/**
 * @brief Encode a wk_camera_visual_intertial_odometry_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_visual_intertial_odometry_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_visual_intertial_odometry_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_visual_intertial_odometry_data_t* wk_camera_visual_intertial_odometry_data)
{
    return mavlink_msg_wk_camera_visual_intertial_odometry_data_pack_chan(system_id, component_id, chan, msg, wk_camera_visual_intertial_odometry_data->timestamp, wk_camera_visual_intertial_odometry_data->ave_lun, wk_camera_visual_intertial_odometry_data->corner, wk_camera_visual_intertial_odometry_data->width, wk_camera_visual_intertial_odometry_data->height, wk_camera_visual_intertial_odometry_data->x, wk_camera_visual_intertial_odometry_data->y, wk_camera_visual_intertial_odometry_data->z, wk_camera_visual_intertial_odometry_data->quaternion, wk_camera_visual_intertial_odometry_data->reserve);
}

/**
 * @brief Send a wk_camera_visual_intertial_odometry_data message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 * @param ave_lun  ave_lun
 * @param corner  corner
 * @param width  width
 * @param height  height
 * @param x  x
 * @param y  y
 * @param z  z
 * @param quaternion  quaternion
 * @param reserve  reserve
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_visual_intertial_odometry_data_send(mavlink_channel_t chan, uint64_t timestamp, uint32_t ave_lun, uint16_t corner, uint16_t width, uint16_t height, float x, float y, float z, const float *quaternion, const float *reserve)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, ave_lun);
    _mav_put_float(buf, 12, x);
    _mav_put_float(buf, 16, y);
    _mav_put_float(buf, 20, z);
    _mav_put_uint16_t(buf, 56, corner);
    _mav_put_uint16_t(buf, 58, width);
    _mav_put_uint16_t(buf, 60, height);
    _mav_put_float_array(buf, 24, quaternion, 4);
    _mav_put_float_array(buf, 40, reserve, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA, buf, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_CRC);
#else
    mavlink_wk_camera_visual_intertial_odometry_data_t packet;
    packet.timestamp = timestamp;
    packet.ave_lun = ave_lun;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.corner = corner;
    packet.width = width;
    packet.height = height;
    mav_array_memcpy(packet.quaternion, quaternion, sizeof(float)*4);
    mav_array_memcpy(packet.reserve, reserve, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_CRC);
#endif
}

/**
 * @brief Send a wk_camera_visual_intertial_odometry_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_visual_intertial_odometry_data_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_visual_intertial_odometry_data_t* wk_camera_visual_intertial_odometry_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_visual_intertial_odometry_data_send(chan, wk_camera_visual_intertial_odometry_data->timestamp, wk_camera_visual_intertial_odometry_data->ave_lun, wk_camera_visual_intertial_odometry_data->corner, wk_camera_visual_intertial_odometry_data->width, wk_camera_visual_intertial_odometry_data->height, wk_camera_visual_intertial_odometry_data->x, wk_camera_visual_intertial_odometry_data->y, wk_camera_visual_intertial_odometry_data->z, wk_camera_visual_intertial_odometry_data->quaternion, wk_camera_visual_intertial_odometry_data->reserve);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA, (const char *)wk_camera_visual_intertial_odometry_data, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_visual_intertial_odometry_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, uint32_t ave_lun, uint16_t corner, uint16_t width, uint16_t height, float x, float y, float z, const float *quaternion, const float *reserve)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_uint32_t(buf, 8, ave_lun);
    _mav_put_float(buf, 12, x);
    _mav_put_float(buf, 16, y);
    _mav_put_float(buf, 20, z);
    _mav_put_uint16_t(buf, 56, corner);
    _mav_put_uint16_t(buf, 58, width);
    _mav_put_uint16_t(buf, 60, height);
    _mav_put_float_array(buf, 24, quaternion, 4);
    _mav_put_float_array(buf, 40, reserve, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA, buf, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_CRC);
#else
    mavlink_wk_camera_visual_intertial_odometry_data_t *packet = (mavlink_wk_camera_visual_intertial_odometry_data_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->ave_lun = ave_lun;
    packet->x = x;
    packet->y = y;
    packet->z = z;
    packet->corner = corner;
    packet->width = width;
    packet->height = height;
    mav_array_memcpy(packet->quaternion, quaternion, sizeof(float)*4);
    mav_array_memcpy(packet->reserve, reserve, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA UNPACKING


/**
 * @brief Get field timestamp from wk_camera_visual_intertial_odometry_data message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_wk_camera_visual_intertial_odometry_data_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field ave_lun from wk_camera_visual_intertial_odometry_data message
 *
 * @return  ave_lun
 */
static inline uint32_t mavlink_msg_wk_camera_visual_intertial_odometry_data_get_ave_lun(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field corner from wk_camera_visual_intertial_odometry_data message
 *
 * @return  corner
 */
static inline uint16_t mavlink_msg_wk_camera_visual_intertial_odometry_data_get_corner(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  56);
}

/**
 * @brief Get field width from wk_camera_visual_intertial_odometry_data message
 *
 * @return  width
 */
static inline uint16_t mavlink_msg_wk_camera_visual_intertial_odometry_data_get_width(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  58);
}

/**
 * @brief Get field height from wk_camera_visual_intertial_odometry_data message
 *
 * @return  height
 */
static inline uint16_t mavlink_msg_wk_camera_visual_intertial_odometry_data_get_height(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  60);
}

/**
 * @brief Get field x from wk_camera_visual_intertial_odometry_data message
 *
 * @return  x
 */
static inline float mavlink_msg_wk_camera_visual_intertial_odometry_data_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field y from wk_camera_visual_intertial_odometry_data message
 *
 * @return  y
 */
static inline float mavlink_msg_wk_camera_visual_intertial_odometry_data_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field z from wk_camera_visual_intertial_odometry_data message
 *
 * @return  z
 */
static inline float mavlink_msg_wk_camera_visual_intertial_odometry_data_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field quaternion from wk_camera_visual_intertial_odometry_data message
 *
 * @return  quaternion
 */
static inline uint16_t mavlink_msg_wk_camera_visual_intertial_odometry_data_get_quaternion(const mavlink_message_t* msg, float *quaternion)
{
    return _MAV_RETURN_float_array(msg, quaternion, 4,  24);
}

/**
 * @brief Get field reserve from wk_camera_visual_intertial_odometry_data message
 *
 * @return  reserve
 */
static inline uint16_t mavlink_msg_wk_camera_visual_intertial_odometry_data_get_reserve(const mavlink_message_t* msg, float *reserve)
{
    return _MAV_RETURN_float_array(msg, reserve, 4,  40);
}

/**
 * @brief Decode a wk_camera_visual_intertial_odometry_data message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_visual_intertial_odometry_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_visual_intertial_odometry_data_decode(const mavlink_message_t* msg, mavlink_wk_camera_visual_intertial_odometry_data_t* wk_camera_visual_intertial_odometry_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_visual_intertial_odometry_data->timestamp = mavlink_msg_wk_camera_visual_intertial_odometry_data_get_timestamp(msg);
    wk_camera_visual_intertial_odometry_data->ave_lun = mavlink_msg_wk_camera_visual_intertial_odometry_data_get_ave_lun(msg);
    wk_camera_visual_intertial_odometry_data->x = mavlink_msg_wk_camera_visual_intertial_odometry_data_get_x(msg);
    wk_camera_visual_intertial_odometry_data->y = mavlink_msg_wk_camera_visual_intertial_odometry_data_get_y(msg);
    wk_camera_visual_intertial_odometry_data->z = mavlink_msg_wk_camera_visual_intertial_odometry_data_get_z(msg);
    mavlink_msg_wk_camera_visual_intertial_odometry_data_get_quaternion(msg, wk_camera_visual_intertial_odometry_data->quaternion);
    mavlink_msg_wk_camera_visual_intertial_odometry_data_get_reserve(msg, wk_camera_visual_intertial_odometry_data->reserve);
    wk_camera_visual_intertial_odometry_data->corner = mavlink_msg_wk_camera_visual_intertial_odometry_data_get_corner(msg);
    wk_camera_visual_intertial_odometry_data->width = mavlink_msg_wk_camera_visual_intertial_odometry_data_get_width(msg);
    wk_camera_visual_intertial_odometry_data->height = mavlink_msg_wk_camera_visual_intertial_odometry_data_get_height(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN;
        memset(wk_camera_visual_intertial_odometry_data, 0, MAVLINK_MSG_ID_WK_CAMERA_VISUAL_INTERTIAL_ODOMETRY_DATA_LEN);
    memcpy(wk_camera_visual_intertial_odometry_data, _MAV_PAYLOAD(msg), len);
#endif
}
