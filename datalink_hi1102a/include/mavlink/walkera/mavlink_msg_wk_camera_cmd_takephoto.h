#pragma once
// MESSAGE WK_CAMERA_CMD_TAKEPHOTO PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO 8042


typedef struct __mavlink_wk_camera_cmd_takephoto_t {
 uint32_t trig_timestamps; /*<  trig timestamps*/
 int32_t longitude; /*<  lon * 1E7*/
 int32_t latitude; /*<  lat * lE7*/
 int32_t altitude; /*<  alt * 100*/
 float UavRoll; /*<  uav roll angle,unit degree*/
 float UavPitch; /*<  uav pitch angle,unit degree*/
 float UavYaw; /*<  uav yaw angle,unit degree*/
 float GimbalRoll; /*<  gimbal roll angle,unit degree*/
 float GimbalPitch; /*<  gimbal pitch angle,unit degree*/
 float GimbalYaw; /*<  gimbal yaw angle,unit degree*/
 uint8_t response_code; /*<  see enum WKCAM_TAKEPHOTO_ACK*/
} mavlink_wk_camera_cmd_takephoto_t;

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN 41
#define MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_MIN_LEN 41
#define MAVLINK_MSG_ID_8042_LEN 41
#define MAVLINK_MSG_ID_8042_MIN_LEN 41

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_CRC 30
#define MAVLINK_MSG_ID_8042_CRC 30



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_TAKEPHOTO { \
    8042, \
    "WK_CAMERA_CMD_TAKEPHOTO", \
    11, \
    {  { "trig_timestamps", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_cmd_takephoto_t, trig_timestamps) }, \
         { "response_code", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_wk_camera_cmd_takephoto_t, response_code) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_wk_camera_cmd_takephoto_t, longitude) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_camera_cmd_takephoto_t, latitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_camera_cmd_takephoto_t, altitude) }, \
         { "UavRoll", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_camera_cmd_takephoto_t, UavRoll) }, \
         { "UavPitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_camera_cmd_takephoto_t, UavPitch) }, \
         { "UavYaw", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wk_camera_cmd_takephoto_t, UavYaw) }, \
         { "GimbalRoll", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wk_camera_cmd_takephoto_t, GimbalRoll) }, \
         { "GimbalPitch", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wk_camera_cmd_takephoto_t, GimbalPitch) }, \
         { "GimbalYaw", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wk_camera_cmd_takephoto_t, GimbalYaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_TAKEPHOTO { \
    "WK_CAMERA_CMD_TAKEPHOTO", \
    11, \
    {  { "trig_timestamps", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_cmd_takephoto_t, trig_timestamps) }, \
         { "response_code", NULL, MAVLINK_TYPE_UINT8_T, 0, 40, offsetof(mavlink_wk_camera_cmd_takephoto_t, response_code) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_wk_camera_cmd_takephoto_t, longitude) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_camera_cmd_takephoto_t, latitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_camera_cmd_takephoto_t, altitude) }, \
         { "UavRoll", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_camera_cmd_takephoto_t, UavRoll) }, \
         { "UavPitch", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_camera_cmd_takephoto_t, UavPitch) }, \
         { "UavYaw", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wk_camera_cmd_takephoto_t, UavYaw) }, \
         { "GimbalRoll", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wk_camera_cmd_takephoto_t, GimbalRoll) }, \
         { "GimbalPitch", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wk_camera_cmd_takephoto_t, GimbalPitch) }, \
         { "GimbalYaw", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wk_camera_cmd_takephoto_t, GimbalYaw) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_cmd_takephoto message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param trig_timestamps  trig timestamps
 * @param response_code  see enum WKCAM_TAKEPHOTO_ACK
 * @param longitude  lon * 1E7
 * @param latitude  lat * lE7
 * @param altitude  alt * 100
 * @param UavRoll  uav roll angle,unit degree
 * @param UavPitch  uav pitch angle,unit degree
 * @param UavYaw  uav yaw angle,unit degree
 * @param GimbalRoll  gimbal roll angle,unit degree
 * @param GimbalPitch  gimbal pitch angle,unit degree
 * @param GimbalYaw  gimbal yaw angle,unit degree
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_takephoto_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t trig_timestamps, uint8_t response_code, int32_t longitude, int32_t latitude, int32_t altitude, float UavRoll, float UavPitch, float UavYaw, float GimbalRoll, float GimbalPitch, float GimbalYaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN];
    _mav_put_uint32_t(buf, 0, trig_timestamps);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, altitude);
    _mav_put_float(buf, 16, UavRoll);
    _mav_put_float(buf, 20, UavPitch);
    _mav_put_float(buf, 24, UavYaw);
    _mav_put_float(buf, 28, GimbalRoll);
    _mav_put_float(buf, 32, GimbalPitch);
    _mav_put_float(buf, 36, GimbalYaw);
    _mav_put_uint8_t(buf, 40, response_code);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN);
#else
    mavlink_wk_camera_cmd_takephoto_t packet;
    packet.trig_timestamps = trig_timestamps;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.altitude = altitude;
    packet.UavRoll = UavRoll;
    packet.UavPitch = UavPitch;
    packet.UavYaw = UavYaw;
    packet.GimbalRoll = GimbalRoll;
    packet.GimbalPitch = GimbalPitch;
    packet.GimbalYaw = GimbalYaw;
    packet.response_code = response_code;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_CRC);
}

/**
 * @brief Pack a wk_camera_cmd_takephoto message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param trig_timestamps  trig timestamps
 * @param response_code  see enum WKCAM_TAKEPHOTO_ACK
 * @param longitude  lon * 1E7
 * @param latitude  lat * lE7
 * @param altitude  alt * 100
 * @param UavRoll  uav roll angle,unit degree
 * @param UavPitch  uav pitch angle,unit degree
 * @param UavYaw  uav yaw angle,unit degree
 * @param GimbalRoll  gimbal roll angle,unit degree
 * @param GimbalPitch  gimbal pitch angle,unit degree
 * @param GimbalYaw  gimbal yaw angle,unit degree
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_takephoto_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t trig_timestamps,uint8_t response_code,int32_t longitude,int32_t latitude,int32_t altitude,float UavRoll,float UavPitch,float UavYaw,float GimbalRoll,float GimbalPitch,float GimbalYaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN];
    _mav_put_uint32_t(buf, 0, trig_timestamps);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, altitude);
    _mav_put_float(buf, 16, UavRoll);
    _mav_put_float(buf, 20, UavPitch);
    _mav_put_float(buf, 24, UavYaw);
    _mav_put_float(buf, 28, GimbalRoll);
    _mav_put_float(buf, 32, GimbalPitch);
    _mav_put_float(buf, 36, GimbalYaw);
    _mav_put_uint8_t(buf, 40, response_code);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN);
#else
    mavlink_wk_camera_cmd_takephoto_t packet;
    packet.trig_timestamps = trig_timestamps;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.altitude = altitude;
    packet.UavRoll = UavRoll;
    packet.UavPitch = UavPitch;
    packet.UavYaw = UavYaw;
    packet.GimbalRoll = GimbalRoll;
    packet.GimbalPitch = GimbalPitch;
    packet.GimbalYaw = GimbalYaw;
    packet.response_code = response_code;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_CRC);
}

/**
 * @brief Encode a wk_camera_cmd_takephoto struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_takephoto C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_takephoto_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_cmd_takephoto_t* wk_camera_cmd_takephoto)
{
    return mavlink_msg_wk_camera_cmd_takephoto_pack(system_id, component_id, msg, wk_camera_cmd_takephoto->trig_timestamps, wk_camera_cmd_takephoto->response_code, wk_camera_cmd_takephoto->longitude, wk_camera_cmd_takephoto->latitude, wk_camera_cmd_takephoto->altitude, wk_camera_cmd_takephoto->UavRoll, wk_camera_cmd_takephoto->UavPitch, wk_camera_cmd_takephoto->UavYaw, wk_camera_cmd_takephoto->GimbalRoll, wk_camera_cmd_takephoto->GimbalPitch, wk_camera_cmd_takephoto->GimbalYaw);
}

/**
 * @brief Encode a wk_camera_cmd_takephoto struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_takephoto C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_takephoto_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_cmd_takephoto_t* wk_camera_cmd_takephoto)
{
    return mavlink_msg_wk_camera_cmd_takephoto_pack_chan(system_id, component_id, chan, msg, wk_camera_cmd_takephoto->trig_timestamps, wk_camera_cmd_takephoto->response_code, wk_camera_cmd_takephoto->longitude, wk_camera_cmd_takephoto->latitude, wk_camera_cmd_takephoto->altitude, wk_camera_cmd_takephoto->UavRoll, wk_camera_cmd_takephoto->UavPitch, wk_camera_cmd_takephoto->UavYaw, wk_camera_cmd_takephoto->GimbalRoll, wk_camera_cmd_takephoto->GimbalPitch, wk_camera_cmd_takephoto->GimbalYaw);
}

/**
 * @brief Send a wk_camera_cmd_takephoto message
 * @param chan MAVLink channel to send the message
 *
 * @param trig_timestamps  trig timestamps
 * @param response_code  see enum WKCAM_TAKEPHOTO_ACK
 * @param longitude  lon * 1E7
 * @param latitude  lat * lE7
 * @param altitude  alt * 100
 * @param UavRoll  uav roll angle,unit degree
 * @param UavPitch  uav pitch angle,unit degree
 * @param UavYaw  uav yaw angle,unit degree
 * @param GimbalRoll  gimbal roll angle,unit degree
 * @param GimbalPitch  gimbal pitch angle,unit degree
 * @param GimbalYaw  gimbal yaw angle,unit degree
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_cmd_takephoto_send(mavlink_channel_t chan, uint32_t trig_timestamps, uint8_t response_code, int32_t longitude, int32_t latitude, int32_t altitude, float UavRoll, float UavPitch, float UavYaw, float GimbalRoll, float GimbalPitch, float GimbalYaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN];
    _mav_put_uint32_t(buf, 0, trig_timestamps);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, altitude);
    _mav_put_float(buf, 16, UavRoll);
    _mav_put_float(buf, 20, UavPitch);
    _mav_put_float(buf, 24, UavYaw);
    _mav_put_float(buf, 28, GimbalRoll);
    _mav_put_float(buf, 32, GimbalPitch);
    _mav_put_float(buf, 36, GimbalYaw);
    _mav_put_uint8_t(buf, 40, response_code);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_CRC);
#else
    mavlink_wk_camera_cmd_takephoto_t packet;
    packet.trig_timestamps = trig_timestamps;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.altitude = altitude;
    packet.UavRoll = UavRoll;
    packet.UavPitch = UavPitch;
    packet.UavYaw = UavYaw;
    packet.GimbalRoll = GimbalRoll;
    packet.GimbalPitch = GimbalPitch;
    packet.GimbalYaw = GimbalYaw;
    packet.response_code = response_code;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_CRC);
#endif
}

/**
 * @brief Send a wk_camera_cmd_takephoto message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_cmd_takephoto_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_cmd_takephoto_t* wk_camera_cmd_takephoto)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_takephoto_send(chan, wk_camera_cmd_takephoto->trig_timestamps, wk_camera_cmd_takephoto->response_code, wk_camera_cmd_takephoto->longitude, wk_camera_cmd_takephoto->latitude, wk_camera_cmd_takephoto->altitude, wk_camera_cmd_takephoto->UavRoll, wk_camera_cmd_takephoto->UavPitch, wk_camera_cmd_takephoto->UavYaw, wk_camera_cmd_takephoto->GimbalRoll, wk_camera_cmd_takephoto->GimbalPitch, wk_camera_cmd_takephoto->GimbalYaw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO, (const char *)wk_camera_cmd_takephoto, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_cmd_takephoto_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t trig_timestamps, uint8_t response_code, int32_t longitude, int32_t latitude, int32_t altitude, float UavRoll, float UavPitch, float UavYaw, float GimbalRoll, float GimbalPitch, float GimbalYaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, trig_timestamps);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_int32_t(buf, 8, latitude);
    _mav_put_int32_t(buf, 12, altitude);
    _mav_put_float(buf, 16, UavRoll);
    _mav_put_float(buf, 20, UavPitch);
    _mav_put_float(buf, 24, UavYaw);
    _mav_put_float(buf, 28, GimbalRoll);
    _mav_put_float(buf, 32, GimbalPitch);
    _mav_put_float(buf, 36, GimbalYaw);
    _mav_put_uint8_t(buf, 40, response_code);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_CRC);
#else
    mavlink_wk_camera_cmd_takephoto_t *packet = (mavlink_wk_camera_cmd_takephoto_t *)msgbuf;
    packet->trig_timestamps = trig_timestamps;
    packet->longitude = longitude;
    packet->latitude = latitude;
    packet->altitude = altitude;
    packet->UavRoll = UavRoll;
    packet->UavPitch = UavPitch;
    packet->UavYaw = UavYaw;
    packet->GimbalRoll = GimbalRoll;
    packet->GimbalPitch = GimbalPitch;
    packet->GimbalYaw = GimbalYaw;
    packet->response_code = response_code;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_CMD_TAKEPHOTO UNPACKING


/**
 * @brief Get field trig_timestamps from wk_camera_cmd_takephoto message
 *
 * @return  trig timestamps
 */
static inline uint32_t mavlink_msg_wk_camera_cmd_takephoto_get_trig_timestamps(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field response_code from wk_camera_cmd_takephoto message
 *
 * @return  see enum WKCAM_TAKEPHOTO_ACK
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_takephoto_get_response_code(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  40);
}

/**
 * @brief Get field longitude from wk_camera_cmd_takephoto message
 *
 * @return  lon * 1E7
 */
static inline int32_t mavlink_msg_wk_camera_cmd_takephoto_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field latitude from wk_camera_cmd_takephoto message
 *
 * @return  lat * lE7
 */
static inline int32_t mavlink_msg_wk_camera_cmd_takephoto_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field altitude from wk_camera_cmd_takephoto message
 *
 * @return  alt * 100
 */
static inline int32_t mavlink_msg_wk_camera_cmd_takephoto_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field UavRoll from wk_camera_cmd_takephoto message
 *
 * @return  uav roll angle,unit degree
 */
static inline float mavlink_msg_wk_camera_cmd_takephoto_get_UavRoll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field UavPitch from wk_camera_cmd_takephoto message
 *
 * @return  uav pitch angle,unit degree
 */
static inline float mavlink_msg_wk_camera_cmd_takephoto_get_UavPitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field UavYaw from wk_camera_cmd_takephoto message
 *
 * @return  uav yaw angle,unit degree
 */
static inline float mavlink_msg_wk_camera_cmd_takephoto_get_UavYaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field GimbalRoll from wk_camera_cmd_takephoto message
 *
 * @return  gimbal roll angle,unit degree
 */
static inline float mavlink_msg_wk_camera_cmd_takephoto_get_GimbalRoll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field GimbalPitch from wk_camera_cmd_takephoto message
 *
 * @return  gimbal pitch angle,unit degree
 */
static inline float mavlink_msg_wk_camera_cmd_takephoto_get_GimbalPitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field GimbalYaw from wk_camera_cmd_takephoto message
 *
 * @return  gimbal yaw angle,unit degree
 */
static inline float mavlink_msg_wk_camera_cmd_takephoto_get_GimbalYaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Decode a wk_camera_cmd_takephoto message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_cmd_takephoto C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_cmd_takephoto_decode(const mavlink_message_t* msg, mavlink_wk_camera_cmd_takephoto_t* wk_camera_cmd_takephoto)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_cmd_takephoto->trig_timestamps = mavlink_msg_wk_camera_cmd_takephoto_get_trig_timestamps(msg);
    wk_camera_cmd_takephoto->longitude = mavlink_msg_wk_camera_cmd_takephoto_get_longitude(msg);
    wk_camera_cmd_takephoto->latitude = mavlink_msg_wk_camera_cmd_takephoto_get_latitude(msg);
    wk_camera_cmd_takephoto->altitude = mavlink_msg_wk_camera_cmd_takephoto_get_altitude(msg);
    wk_camera_cmd_takephoto->UavRoll = mavlink_msg_wk_camera_cmd_takephoto_get_UavRoll(msg);
    wk_camera_cmd_takephoto->UavPitch = mavlink_msg_wk_camera_cmd_takephoto_get_UavPitch(msg);
    wk_camera_cmd_takephoto->UavYaw = mavlink_msg_wk_camera_cmd_takephoto_get_UavYaw(msg);
    wk_camera_cmd_takephoto->GimbalRoll = mavlink_msg_wk_camera_cmd_takephoto_get_GimbalRoll(msg);
    wk_camera_cmd_takephoto->GimbalPitch = mavlink_msg_wk_camera_cmd_takephoto_get_GimbalPitch(msg);
    wk_camera_cmd_takephoto->GimbalYaw = mavlink_msg_wk_camera_cmd_takephoto_get_GimbalYaw(msg);
    wk_camera_cmd_takephoto->response_code = mavlink_msg_wk_camera_cmd_takephoto_get_response_code(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN;
        memset(wk_camera_cmd_takephoto, 0, MAVLINK_MSG_ID_WK_CAMERA_CMD_TAKEPHOTO_LEN);
    memcpy(wk_camera_cmd_takephoto, _MAV_PAYLOAD(msg), len);
#endif
}
