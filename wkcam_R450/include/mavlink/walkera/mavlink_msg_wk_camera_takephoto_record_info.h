#pragma once
// MESSAGE WK_CAMERA_TAKEPHOTO_RECORD_INFO PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO 8036


typedef struct __mavlink_wk_camera_takephoto_record_info_t {
 uint32_t uav_longitude; /*<  */
 uint32_t uav_lattitude; /*<  */
 uint32_t uav_altitude; /*<  */
 uint32_t uav_roll; /*<  */
 uint32_t uav_pitch; /*<  */
 uint32_t uav_yaw; /*<  */
 uint32_t gimbal_roll; /*<  */
 uint32_t gimbal_pitch; /*<  */
 uint32_t gimbal_yaw; /*<  */
 uint32_t timestamp; /*<  */
 uint8_t filename[128]; /*<  */
 uint8_t reserved[16]; /*<  reserved*/
} mavlink_wk_camera_takephoto_record_info_t;

#define MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN 184
#define MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_MIN_LEN 184
#define MAVLINK_MSG_ID_8036_LEN 184
#define MAVLINK_MSG_ID_8036_MIN_LEN 184

#define MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_CRC 134
#define MAVLINK_MSG_ID_8036_CRC 134

#define MAVLINK_MSG_WK_CAMERA_TAKEPHOTO_RECORD_INFO_FIELD_FILENAME_LEN 128
#define MAVLINK_MSG_WK_CAMERA_TAKEPHOTO_RECORD_INFO_FIELD_RESERVED_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_TAKEPHOTO_RECORD_INFO { \
    8036, \
    "WK_CAMERA_TAKEPHOTO_RECORD_INFO", \
    12, \
    {  { "uav_longitude", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_takephoto_record_info_t, uav_longitude) }, \
         { "uav_lattitude", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_camera_takephoto_record_info_t, uav_lattitude) }, \
         { "uav_altitude", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_camera_takephoto_record_info_t, uav_altitude) }, \
         { "uav_roll", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_wk_camera_takephoto_record_info_t, uav_roll) }, \
         { "uav_pitch", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_wk_camera_takephoto_record_info_t, uav_pitch) }, \
         { "uav_yaw", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_wk_camera_takephoto_record_info_t, uav_yaw) }, \
         { "gimbal_roll", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_wk_camera_takephoto_record_info_t, gimbal_roll) }, \
         { "gimbal_pitch", NULL, MAVLINK_TYPE_UINT32_T, 0, 28, offsetof(mavlink_wk_camera_takephoto_record_info_t, gimbal_pitch) }, \
         { "gimbal_yaw", NULL, MAVLINK_TYPE_UINT32_T, 0, 32, offsetof(mavlink_wk_camera_takephoto_record_info_t, gimbal_yaw) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT32_T, 0, 36, offsetof(mavlink_wk_camera_takephoto_record_info_t, timestamp) }, \
         { "filename", NULL, MAVLINK_TYPE_UINT8_T, 128, 40, offsetof(mavlink_wk_camera_takephoto_record_info_t, filename) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 16, 168, offsetof(mavlink_wk_camera_takephoto_record_info_t, reserved) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_TAKEPHOTO_RECORD_INFO { \
    "WK_CAMERA_TAKEPHOTO_RECORD_INFO", \
    12, \
    {  { "uav_longitude", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_takephoto_record_info_t, uav_longitude) }, \
         { "uav_lattitude", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_camera_takephoto_record_info_t, uav_lattitude) }, \
         { "uav_altitude", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_camera_takephoto_record_info_t, uav_altitude) }, \
         { "uav_roll", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_wk_camera_takephoto_record_info_t, uav_roll) }, \
         { "uav_pitch", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_wk_camera_takephoto_record_info_t, uav_pitch) }, \
         { "uav_yaw", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_wk_camera_takephoto_record_info_t, uav_yaw) }, \
         { "gimbal_roll", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_wk_camera_takephoto_record_info_t, gimbal_roll) }, \
         { "gimbal_pitch", NULL, MAVLINK_TYPE_UINT32_T, 0, 28, offsetof(mavlink_wk_camera_takephoto_record_info_t, gimbal_pitch) }, \
         { "gimbal_yaw", NULL, MAVLINK_TYPE_UINT32_T, 0, 32, offsetof(mavlink_wk_camera_takephoto_record_info_t, gimbal_yaw) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT32_T, 0, 36, offsetof(mavlink_wk_camera_takephoto_record_info_t, timestamp) }, \
         { "filename", NULL, MAVLINK_TYPE_UINT8_T, 128, 40, offsetof(mavlink_wk_camera_takephoto_record_info_t, filename) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 16, 168, offsetof(mavlink_wk_camera_takephoto_record_info_t, reserved) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_takephoto_record_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param uav_longitude  
 * @param uav_lattitude  
 * @param uav_altitude  
 * @param uav_roll  
 * @param uav_pitch  
 * @param uav_yaw  
 * @param gimbal_roll  
 * @param gimbal_pitch  
 * @param gimbal_yaw  
 * @param timestamp  
 * @param filename  
 * @param reserved  reserved
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_takephoto_record_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t uav_longitude, uint32_t uav_lattitude, uint32_t uav_altitude, uint32_t uav_roll, uint32_t uav_pitch, uint32_t uav_yaw, uint32_t gimbal_roll, uint32_t gimbal_pitch, uint32_t gimbal_yaw, uint32_t timestamp, const uint8_t *filename, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN];
    _mav_put_uint32_t(buf, 0, uav_longitude);
    _mav_put_uint32_t(buf, 4, uav_lattitude);
    _mav_put_uint32_t(buf, 8, uav_altitude);
    _mav_put_uint32_t(buf, 12, uav_roll);
    _mav_put_uint32_t(buf, 16, uav_pitch);
    _mav_put_uint32_t(buf, 20, uav_yaw);
    _mav_put_uint32_t(buf, 24, gimbal_roll);
    _mav_put_uint32_t(buf, 28, gimbal_pitch);
    _mav_put_uint32_t(buf, 32, gimbal_yaw);
    _mav_put_uint32_t(buf, 36, timestamp);
    _mav_put_uint8_t_array(buf, 40, filename, 128);
    _mav_put_uint8_t_array(buf, 168, reserved, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN);
#else
    mavlink_wk_camera_takephoto_record_info_t packet;
    packet.uav_longitude = uav_longitude;
    packet.uav_lattitude = uav_lattitude;
    packet.uav_altitude = uav_altitude;
    packet.uav_roll = uav_roll;
    packet.uav_pitch = uav_pitch;
    packet.uav_yaw = uav_yaw;
    packet.gimbal_roll = gimbal_roll;
    packet.gimbal_pitch = gimbal_pitch;
    packet.gimbal_yaw = gimbal_yaw;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.filename, filename, sizeof(uint8_t)*128);
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_CRC);
}

/**
 * @brief Pack a wk_camera_takephoto_record_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param uav_longitude  
 * @param uav_lattitude  
 * @param uav_altitude  
 * @param uav_roll  
 * @param uav_pitch  
 * @param uav_yaw  
 * @param gimbal_roll  
 * @param gimbal_pitch  
 * @param gimbal_yaw  
 * @param timestamp  
 * @param filename  
 * @param reserved  reserved
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_takephoto_record_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t uav_longitude,uint32_t uav_lattitude,uint32_t uav_altitude,uint32_t uav_roll,uint32_t uav_pitch,uint32_t uav_yaw,uint32_t gimbal_roll,uint32_t gimbal_pitch,uint32_t gimbal_yaw,uint32_t timestamp,const uint8_t *filename,const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN];
    _mav_put_uint32_t(buf, 0, uav_longitude);
    _mav_put_uint32_t(buf, 4, uav_lattitude);
    _mav_put_uint32_t(buf, 8, uav_altitude);
    _mav_put_uint32_t(buf, 12, uav_roll);
    _mav_put_uint32_t(buf, 16, uav_pitch);
    _mav_put_uint32_t(buf, 20, uav_yaw);
    _mav_put_uint32_t(buf, 24, gimbal_roll);
    _mav_put_uint32_t(buf, 28, gimbal_pitch);
    _mav_put_uint32_t(buf, 32, gimbal_yaw);
    _mav_put_uint32_t(buf, 36, timestamp);
    _mav_put_uint8_t_array(buf, 40, filename, 128);
    _mav_put_uint8_t_array(buf, 168, reserved, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN);
#else
    mavlink_wk_camera_takephoto_record_info_t packet;
    packet.uav_longitude = uav_longitude;
    packet.uav_lattitude = uav_lattitude;
    packet.uav_altitude = uav_altitude;
    packet.uav_roll = uav_roll;
    packet.uav_pitch = uav_pitch;
    packet.uav_yaw = uav_yaw;
    packet.gimbal_roll = gimbal_roll;
    packet.gimbal_pitch = gimbal_pitch;
    packet.gimbal_yaw = gimbal_yaw;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.filename, filename, sizeof(uint8_t)*128);
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_CRC);
}

/**
 * @brief Encode a wk_camera_takephoto_record_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_takephoto_record_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_takephoto_record_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_takephoto_record_info_t* wk_camera_takephoto_record_info)
{
    return mavlink_msg_wk_camera_takephoto_record_info_pack(system_id, component_id, msg, wk_camera_takephoto_record_info->uav_longitude, wk_camera_takephoto_record_info->uav_lattitude, wk_camera_takephoto_record_info->uav_altitude, wk_camera_takephoto_record_info->uav_roll, wk_camera_takephoto_record_info->uav_pitch, wk_camera_takephoto_record_info->uav_yaw, wk_camera_takephoto_record_info->gimbal_roll, wk_camera_takephoto_record_info->gimbal_pitch, wk_camera_takephoto_record_info->gimbal_yaw, wk_camera_takephoto_record_info->timestamp, wk_camera_takephoto_record_info->filename, wk_camera_takephoto_record_info->reserved);
}

/**
 * @brief Encode a wk_camera_takephoto_record_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_takephoto_record_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_takephoto_record_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_takephoto_record_info_t* wk_camera_takephoto_record_info)
{
    return mavlink_msg_wk_camera_takephoto_record_info_pack_chan(system_id, component_id, chan, msg, wk_camera_takephoto_record_info->uav_longitude, wk_camera_takephoto_record_info->uav_lattitude, wk_camera_takephoto_record_info->uav_altitude, wk_camera_takephoto_record_info->uav_roll, wk_camera_takephoto_record_info->uav_pitch, wk_camera_takephoto_record_info->uav_yaw, wk_camera_takephoto_record_info->gimbal_roll, wk_camera_takephoto_record_info->gimbal_pitch, wk_camera_takephoto_record_info->gimbal_yaw, wk_camera_takephoto_record_info->timestamp, wk_camera_takephoto_record_info->filename, wk_camera_takephoto_record_info->reserved);
}

/**
 * @brief Send a wk_camera_takephoto_record_info message
 * @param chan MAVLink channel to send the message
 *
 * @param uav_longitude  
 * @param uav_lattitude  
 * @param uav_altitude  
 * @param uav_roll  
 * @param uav_pitch  
 * @param uav_yaw  
 * @param gimbal_roll  
 * @param gimbal_pitch  
 * @param gimbal_yaw  
 * @param timestamp  
 * @param filename  
 * @param reserved  reserved
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_takephoto_record_info_send(mavlink_channel_t chan, uint32_t uav_longitude, uint32_t uav_lattitude, uint32_t uav_altitude, uint32_t uav_roll, uint32_t uav_pitch, uint32_t uav_yaw, uint32_t gimbal_roll, uint32_t gimbal_pitch, uint32_t gimbal_yaw, uint32_t timestamp, const uint8_t *filename, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN];
    _mav_put_uint32_t(buf, 0, uav_longitude);
    _mav_put_uint32_t(buf, 4, uav_lattitude);
    _mav_put_uint32_t(buf, 8, uav_altitude);
    _mav_put_uint32_t(buf, 12, uav_roll);
    _mav_put_uint32_t(buf, 16, uav_pitch);
    _mav_put_uint32_t(buf, 20, uav_yaw);
    _mav_put_uint32_t(buf, 24, gimbal_roll);
    _mav_put_uint32_t(buf, 28, gimbal_pitch);
    _mav_put_uint32_t(buf, 32, gimbal_yaw);
    _mav_put_uint32_t(buf, 36, timestamp);
    _mav_put_uint8_t_array(buf, 40, filename, 128);
    _mav_put_uint8_t_array(buf, 168, reserved, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO, buf, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_CRC);
#else
    mavlink_wk_camera_takephoto_record_info_t packet;
    packet.uav_longitude = uav_longitude;
    packet.uav_lattitude = uav_lattitude;
    packet.uav_altitude = uav_altitude;
    packet.uav_roll = uav_roll;
    packet.uav_pitch = uav_pitch;
    packet.uav_yaw = uav_yaw;
    packet.gimbal_roll = gimbal_roll;
    packet.gimbal_pitch = gimbal_pitch;
    packet.gimbal_yaw = gimbal_yaw;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.filename, filename, sizeof(uint8_t)*128);
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_CRC);
#endif
}

/**
 * @brief Send a wk_camera_takephoto_record_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_takephoto_record_info_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_takephoto_record_info_t* wk_camera_takephoto_record_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_takephoto_record_info_send(chan, wk_camera_takephoto_record_info->uav_longitude, wk_camera_takephoto_record_info->uav_lattitude, wk_camera_takephoto_record_info->uav_altitude, wk_camera_takephoto_record_info->uav_roll, wk_camera_takephoto_record_info->uav_pitch, wk_camera_takephoto_record_info->uav_yaw, wk_camera_takephoto_record_info->gimbal_roll, wk_camera_takephoto_record_info->gimbal_pitch, wk_camera_takephoto_record_info->gimbal_yaw, wk_camera_takephoto_record_info->timestamp, wk_camera_takephoto_record_info->filename, wk_camera_takephoto_record_info->reserved);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO, (const char *)wk_camera_takephoto_record_info, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_takephoto_record_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t uav_longitude, uint32_t uav_lattitude, uint32_t uav_altitude, uint32_t uav_roll, uint32_t uav_pitch, uint32_t uav_yaw, uint32_t gimbal_roll, uint32_t gimbal_pitch, uint32_t gimbal_yaw, uint32_t timestamp, const uint8_t *filename, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, uav_longitude);
    _mav_put_uint32_t(buf, 4, uav_lattitude);
    _mav_put_uint32_t(buf, 8, uav_altitude);
    _mav_put_uint32_t(buf, 12, uav_roll);
    _mav_put_uint32_t(buf, 16, uav_pitch);
    _mav_put_uint32_t(buf, 20, uav_yaw);
    _mav_put_uint32_t(buf, 24, gimbal_roll);
    _mav_put_uint32_t(buf, 28, gimbal_pitch);
    _mav_put_uint32_t(buf, 32, gimbal_yaw);
    _mav_put_uint32_t(buf, 36, timestamp);
    _mav_put_uint8_t_array(buf, 40, filename, 128);
    _mav_put_uint8_t_array(buf, 168, reserved, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO, buf, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_CRC);
#else
    mavlink_wk_camera_takephoto_record_info_t *packet = (mavlink_wk_camera_takephoto_record_info_t *)msgbuf;
    packet->uav_longitude = uav_longitude;
    packet->uav_lattitude = uav_lattitude;
    packet->uav_altitude = uav_altitude;
    packet->uav_roll = uav_roll;
    packet->uav_pitch = uav_pitch;
    packet->uav_yaw = uav_yaw;
    packet->gimbal_roll = gimbal_roll;
    packet->gimbal_pitch = gimbal_pitch;
    packet->gimbal_yaw = gimbal_yaw;
    packet->timestamp = timestamp;
    mav_array_memcpy(packet->filename, filename, sizeof(uint8_t)*128);
    mav_array_memcpy(packet->reserved, reserved, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_TAKEPHOTO_RECORD_INFO UNPACKING


/**
 * @brief Get field uav_longitude from wk_camera_takephoto_record_info message
 *
 * @return  
 */
static inline uint32_t mavlink_msg_wk_camera_takephoto_record_info_get_uav_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field uav_lattitude from wk_camera_takephoto_record_info message
 *
 * @return  
 */
static inline uint32_t mavlink_msg_wk_camera_takephoto_record_info_get_uav_lattitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field uav_altitude from wk_camera_takephoto_record_info message
 *
 * @return  
 */
static inline uint32_t mavlink_msg_wk_camera_takephoto_record_info_get_uav_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field uav_roll from wk_camera_takephoto_record_info message
 *
 * @return  
 */
static inline uint32_t mavlink_msg_wk_camera_takephoto_record_info_get_uav_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field uav_pitch from wk_camera_takephoto_record_info message
 *
 * @return  
 */
static inline uint32_t mavlink_msg_wk_camera_takephoto_record_info_get_uav_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field uav_yaw from wk_camera_takephoto_record_info message
 *
 * @return  
 */
static inline uint32_t mavlink_msg_wk_camera_takephoto_record_info_get_uav_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Get field gimbal_roll from wk_camera_takephoto_record_info message
 *
 * @return  
 */
static inline uint32_t mavlink_msg_wk_camera_takephoto_record_info_get_gimbal_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  24);
}

/**
 * @brief Get field gimbal_pitch from wk_camera_takephoto_record_info message
 *
 * @return  
 */
static inline uint32_t mavlink_msg_wk_camera_takephoto_record_info_get_gimbal_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  28);
}

/**
 * @brief Get field gimbal_yaw from wk_camera_takephoto_record_info message
 *
 * @return  
 */
static inline uint32_t mavlink_msg_wk_camera_takephoto_record_info_get_gimbal_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  32);
}

/**
 * @brief Get field timestamp from wk_camera_takephoto_record_info message
 *
 * @return  
 */
static inline uint32_t mavlink_msg_wk_camera_takephoto_record_info_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  36);
}

/**
 * @brief Get field filename from wk_camera_takephoto_record_info message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_camera_takephoto_record_info_get_filename(const mavlink_message_t* msg, uint8_t *filename)
{
    return _MAV_RETURN_uint8_t_array(msg, filename, 128,  40);
}

/**
 * @brief Get field reserved from wk_camera_takephoto_record_info message
 *
 * @return  reserved
 */
static inline uint16_t mavlink_msg_wk_camera_takephoto_record_info_get_reserved(const mavlink_message_t* msg, uint8_t *reserved)
{
    return _MAV_RETURN_uint8_t_array(msg, reserved, 16,  168);
}

/**
 * @brief Decode a wk_camera_takephoto_record_info message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_takephoto_record_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_takephoto_record_info_decode(const mavlink_message_t* msg, mavlink_wk_camera_takephoto_record_info_t* wk_camera_takephoto_record_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_takephoto_record_info->uav_longitude = mavlink_msg_wk_camera_takephoto_record_info_get_uav_longitude(msg);
    wk_camera_takephoto_record_info->uav_lattitude = mavlink_msg_wk_camera_takephoto_record_info_get_uav_lattitude(msg);
    wk_camera_takephoto_record_info->uav_altitude = mavlink_msg_wk_camera_takephoto_record_info_get_uav_altitude(msg);
    wk_camera_takephoto_record_info->uav_roll = mavlink_msg_wk_camera_takephoto_record_info_get_uav_roll(msg);
    wk_camera_takephoto_record_info->uav_pitch = mavlink_msg_wk_camera_takephoto_record_info_get_uav_pitch(msg);
    wk_camera_takephoto_record_info->uav_yaw = mavlink_msg_wk_camera_takephoto_record_info_get_uav_yaw(msg);
    wk_camera_takephoto_record_info->gimbal_roll = mavlink_msg_wk_camera_takephoto_record_info_get_gimbal_roll(msg);
    wk_camera_takephoto_record_info->gimbal_pitch = mavlink_msg_wk_camera_takephoto_record_info_get_gimbal_pitch(msg);
    wk_camera_takephoto_record_info->gimbal_yaw = mavlink_msg_wk_camera_takephoto_record_info_get_gimbal_yaw(msg);
    wk_camera_takephoto_record_info->timestamp = mavlink_msg_wk_camera_takephoto_record_info_get_timestamp(msg);
    mavlink_msg_wk_camera_takephoto_record_info_get_filename(msg, wk_camera_takephoto_record_info->filename);
    mavlink_msg_wk_camera_takephoto_record_info_get_reserved(msg, wk_camera_takephoto_record_info->reserved);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN;
        memset(wk_camera_takephoto_record_info, 0, MAVLINK_MSG_ID_WK_CAMERA_TAKEPHOTO_RECORD_INFO_LEN);
    memcpy(wk_camera_takephoto_record_info, _MAV_PAYLOAD(msg), len);
#endif
}
