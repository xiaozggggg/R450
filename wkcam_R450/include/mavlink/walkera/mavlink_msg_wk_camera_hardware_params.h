#pragma once
// MESSAGE WK_CAMERA_HARDWARE_PARAMS PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS 8035


typedef struct __mavlink_wk_camera_hardware_params_t {
 float sensor_width; /*<  camera sensor width*/
 float sensor_height; /*<  camera sensor height*/
 float pixel_size; /*<  camera pixel size*/
 float aperture_size; /*<  camera aperture size*/
 float focal_length; /*<  camera focal length*/
 uint32_t pictrue_width; /*<  camera pictrue  width*/
 uint32_t pictrue_height; /*<  camera pictrue height*/
} mavlink_wk_camera_hardware_params_t;

#define MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN 28
#define MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_MIN_LEN 28
#define MAVLINK_MSG_ID_8035_LEN 28
#define MAVLINK_MSG_ID_8035_MIN_LEN 28

#define MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_CRC 19
#define MAVLINK_MSG_ID_8035_CRC 19



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_HARDWARE_PARAMS { \
    8035, \
    "WK_CAMERA_HARDWARE_PARAMS", \
    7, \
    {  { "sensor_width", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_camera_hardware_params_t, sensor_width) }, \
         { "sensor_height", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_camera_hardware_params_t, sensor_height) }, \
         { "pixel_size", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_camera_hardware_params_t, pixel_size) }, \
         { "aperture_size", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_camera_hardware_params_t, aperture_size) }, \
         { "focal_length", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_camera_hardware_params_t, focal_length) }, \
         { "pictrue_width", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_wk_camera_hardware_params_t, pictrue_width) }, \
         { "pictrue_height", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_wk_camera_hardware_params_t, pictrue_height) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_HARDWARE_PARAMS { \
    "WK_CAMERA_HARDWARE_PARAMS", \
    7, \
    {  { "sensor_width", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_camera_hardware_params_t, sensor_width) }, \
         { "sensor_height", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_camera_hardware_params_t, sensor_height) }, \
         { "pixel_size", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_camera_hardware_params_t, pixel_size) }, \
         { "aperture_size", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_camera_hardware_params_t, aperture_size) }, \
         { "focal_length", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_camera_hardware_params_t, focal_length) }, \
         { "pictrue_width", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_wk_camera_hardware_params_t, pictrue_width) }, \
         { "pictrue_height", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_wk_camera_hardware_params_t, pictrue_height) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_hardware_params message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param sensor_width  camera sensor width
 * @param sensor_height  camera sensor height
 * @param pixel_size  camera pixel size
 * @param aperture_size  camera aperture size
 * @param focal_length  camera focal length
 * @param pictrue_width  camera pictrue  width
 * @param pictrue_height  camera pictrue height
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_hardware_params_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float sensor_width, float sensor_height, float pixel_size, float aperture_size, float focal_length, uint32_t pictrue_width, uint32_t pictrue_height)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN];
    _mav_put_float(buf, 0, sensor_width);
    _mav_put_float(buf, 4, sensor_height);
    _mav_put_float(buf, 8, pixel_size);
    _mav_put_float(buf, 12, aperture_size);
    _mav_put_float(buf, 16, focal_length);
    _mav_put_uint32_t(buf, 20, pictrue_width);
    _mav_put_uint32_t(buf, 24, pictrue_height);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN);
#else
    mavlink_wk_camera_hardware_params_t packet;
    packet.sensor_width = sensor_width;
    packet.sensor_height = sensor_height;
    packet.pixel_size = pixel_size;
    packet.aperture_size = aperture_size;
    packet.focal_length = focal_length;
    packet.pictrue_width = pictrue_width;
    packet.pictrue_height = pictrue_height;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_CRC);
}

/**
 * @brief Pack a wk_camera_hardware_params message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sensor_width  camera sensor width
 * @param sensor_height  camera sensor height
 * @param pixel_size  camera pixel size
 * @param aperture_size  camera aperture size
 * @param focal_length  camera focal length
 * @param pictrue_width  camera pictrue  width
 * @param pictrue_height  camera pictrue height
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_hardware_params_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float sensor_width,float sensor_height,float pixel_size,float aperture_size,float focal_length,uint32_t pictrue_width,uint32_t pictrue_height)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN];
    _mav_put_float(buf, 0, sensor_width);
    _mav_put_float(buf, 4, sensor_height);
    _mav_put_float(buf, 8, pixel_size);
    _mav_put_float(buf, 12, aperture_size);
    _mav_put_float(buf, 16, focal_length);
    _mav_put_uint32_t(buf, 20, pictrue_width);
    _mav_put_uint32_t(buf, 24, pictrue_height);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN);
#else
    mavlink_wk_camera_hardware_params_t packet;
    packet.sensor_width = sensor_width;
    packet.sensor_height = sensor_height;
    packet.pixel_size = pixel_size;
    packet.aperture_size = aperture_size;
    packet.focal_length = focal_length;
    packet.pictrue_width = pictrue_width;
    packet.pictrue_height = pictrue_height;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_CRC);
}

/**
 * @brief Encode a wk_camera_hardware_params struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_hardware_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_hardware_params_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_hardware_params_t* wk_camera_hardware_params)
{
    return mavlink_msg_wk_camera_hardware_params_pack(system_id, component_id, msg, wk_camera_hardware_params->sensor_width, wk_camera_hardware_params->sensor_height, wk_camera_hardware_params->pixel_size, wk_camera_hardware_params->aperture_size, wk_camera_hardware_params->focal_length, wk_camera_hardware_params->pictrue_width, wk_camera_hardware_params->pictrue_height);
}

/**
 * @brief Encode a wk_camera_hardware_params struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_hardware_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_hardware_params_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_hardware_params_t* wk_camera_hardware_params)
{
    return mavlink_msg_wk_camera_hardware_params_pack_chan(system_id, component_id, chan, msg, wk_camera_hardware_params->sensor_width, wk_camera_hardware_params->sensor_height, wk_camera_hardware_params->pixel_size, wk_camera_hardware_params->aperture_size, wk_camera_hardware_params->focal_length, wk_camera_hardware_params->pictrue_width, wk_camera_hardware_params->pictrue_height);
}

/**
 * @brief Send a wk_camera_hardware_params message
 * @param chan MAVLink channel to send the message
 *
 * @param sensor_width  camera sensor width
 * @param sensor_height  camera sensor height
 * @param pixel_size  camera pixel size
 * @param aperture_size  camera aperture size
 * @param focal_length  camera focal length
 * @param pictrue_width  camera pictrue  width
 * @param pictrue_height  camera pictrue height
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_hardware_params_send(mavlink_channel_t chan, float sensor_width, float sensor_height, float pixel_size, float aperture_size, float focal_length, uint32_t pictrue_width, uint32_t pictrue_height)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN];
    _mav_put_float(buf, 0, sensor_width);
    _mav_put_float(buf, 4, sensor_height);
    _mav_put_float(buf, 8, pixel_size);
    _mav_put_float(buf, 12, aperture_size);
    _mav_put_float(buf, 16, focal_length);
    _mav_put_uint32_t(buf, 20, pictrue_width);
    _mav_put_uint32_t(buf, 24, pictrue_height);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS, buf, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_CRC);
#else
    mavlink_wk_camera_hardware_params_t packet;
    packet.sensor_width = sensor_width;
    packet.sensor_height = sensor_height;
    packet.pixel_size = pixel_size;
    packet.aperture_size = aperture_size;
    packet.focal_length = focal_length;
    packet.pictrue_width = pictrue_width;
    packet.pictrue_height = pictrue_height;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_CRC);
#endif
}

/**
 * @brief Send a wk_camera_hardware_params message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_hardware_params_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_hardware_params_t* wk_camera_hardware_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_hardware_params_send(chan, wk_camera_hardware_params->sensor_width, wk_camera_hardware_params->sensor_height, wk_camera_hardware_params->pixel_size, wk_camera_hardware_params->aperture_size, wk_camera_hardware_params->focal_length, wk_camera_hardware_params->pictrue_width, wk_camera_hardware_params->pictrue_height);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS, (const char *)wk_camera_hardware_params, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_hardware_params_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float sensor_width, float sensor_height, float pixel_size, float aperture_size, float focal_length, uint32_t pictrue_width, uint32_t pictrue_height)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, sensor_width);
    _mav_put_float(buf, 4, sensor_height);
    _mav_put_float(buf, 8, pixel_size);
    _mav_put_float(buf, 12, aperture_size);
    _mav_put_float(buf, 16, focal_length);
    _mav_put_uint32_t(buf, 20, pictrue_width);
    _mav_put_uint32_t(buf, 24, pictrue_height);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS, buf, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_CRC);
#else
    mavlink_wk_camera_hardware_params_t *packet = (mavlink_wk_camera_hardware_params_t *)msgbuf;
    packet->sensor_width = sensor_width;
    packet->sensor_height = sensor_height;
    packet->pixel_size = pixel_size;
    packet->aperture_size = aperture_size;
    packet->focal_length = focal_length;
    packet->pictrue_width = pictrue_width;
    packet->pictrue_height = pictrue_height;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_HARDWARE_PARAMS UNPACKING


/**
 * @brief Get field sensor_width from wk_camera_hardware_params message
 *
 * @return  camera sensor width
 */
static inline float mavlink_msg_wk_camera_hardware_params_get_sensor_width(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field sensor_height from wk_camera_hardware_params message
 *
 * @return  camera sensor height
 */
static inline float mavlink_msg_wk_camera_hardware_params_get_sensor_height(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field pixel_size from wk_camera_hardware_params message
 *
 * @return  camera pixel size
 */
static inline float mavlink_msg_wk_camera_hardware_params_get_pixel_size(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field aperture_size from wk_camera_hardware_params message
 *
 * @return  camera aperture size
 */
static inline float mavlink_msg_wk_camera_hardware_params_get_aperture_size(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field focal_length from wk_camera_hardware_params message
 *
 * @return  camera focal length
 */
static inline float mavlink_msg_wk_camera_hardware_params_get_focal_length(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field pictrue_width from wk_camera_hardware_params message
 *
 * @return  camera pictrue  width
 */
static inline uint32_t mavlink_msg_wk_camera_hardware_params_get_pictrue_width(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Get field pictrue_height from wk_camera_hardware_params message
 *
 * @return  camera pictrue height
 */
static inline uint32_t mavlink_msg_wk_camera_hardware_params_get_pictrue_height(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  24);
}

/**
 * @brief Decode a wk_camera_hardware_params message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_hardware_params C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_hardware_params_decode(const mavlink_message_t* msg, mavlink_wk_camera_hardware_params_t* wk_camera_hardware_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_hardware_params->sensor_width = mavlink_msg_wk_camera_hardware_params_get_sensor_width(msg);
    wk_camera_hardware_params->sensor_height = mavlink_msg_wk_camera_hardware_params_get_sensor_height(msg);
    wk_camera_hardware_params->pixel_size = mavlink_msg_wk_camera_hardware_params_get_pixel_size(msg);
    wk_camera_hardware_params->aperture_size = mavlink_msg_wk_camera_hardware_params_get_aperture_size(msg);
    wk_camera_hardware_params->focal_length = mavlink_msg_wk_camera_hardware_params_get_focal_length(msg);
    wk_camera_hardware_params->pictrue_width = mavlink_msg_wk_camera_hardware_params_get_pictrue_width(msg);
    wk_camera_hardware_params->pictrue_height = mavlink_msg_wk_camera_hardware_params_get_pictrue_height(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN;
        memset(wk_camera_hardware_params, 0, MAVLINK_MSG_ID_WK_CAMERA_HARDWARE_PARAMS_LEN);
    memcpy(wk_camera_hardware_params, _MAV_PAYLOAD(msg), len);
#endif
}
