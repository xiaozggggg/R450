#pragma once
// MESSAGE WK_CAMERA_CMD_CAMERA_CONTROL PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL 8064


typedef struct __mavlink_wk_camera_cmd_camera_control_t {
 uint32_t cam_ctrl_value1; /*<  continue: pictrue num; time token: time(S); time lapse: sampling time; record: see enum WACAM_VIDEO_REC_CMD*/
 uint32_t cam_ctrl_value2; /*<   time lapse: frame rate*/
 uint32_t cam_ctrl_value3; /*<   time lapse: total time*/
 int32_t longitude; /*<  lon * 1E7*/
 int32_t latitude; /*<  lat * lE7*/
 int32_t altitude; /*<  alt * 100*/
 float UavRoll; /*<  uav roll angle,unit degree*/
 float UavPitch; /*<  uav pitch angle,unit degree*/
 float UavYaw; /*<  uav yaw angle,unit degree*/
 float GimbalRoll; /*<  gimbal roll angle,unit degree*/
 float GimbalPitch; /*<  gimbal pitch angle,unit degree*/
 float GimbalYaw; /*<  gimbal yaw angle,unit degree*/
 uint32_t cam_ctrl_timestamps; /*<  active_timestamps*/
 uint8_t cam_ctrl_type; /*<  see enum WKCAM_CAMERA_CONTROL_TYPE*/
 uint8_t cam_ctrl_sub_type; /*<  time lapse: see WK_TIME_LAPSE_MODE ; panorama shot: see WK_PANORAMA_MODE*/
} mavlink_wk_camera_cmd_camera_control_t;

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN 54
#define MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_MIN_LEN 54
#define MAVLINK_MSG_ID_8064_LEN 54
#define MAVLINK_MSG_ID_8064_MIN_LEN 54

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_CRC 166
#define MAVLINK_MSG_ID_8064_CRC 166



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_CAMERA_CONTROL { \
    8064, \
    "WK_CAMERA_CMD_CAMERA_CONTROL", \
    15, \
    {  { "cam_ctrl_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_wk_camera_cmd_camera_control_t, cam_ctrl_type) }, \
         { "cam_ctrl_sub_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 53, offsetof(mavlink_wk_camera_cmd_camera_control_t, cam_ctrl_sub_type) }, \
         { "cam_ctrl_value1", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_cmd_camera_control_t, cam_ctrl_value1) }, \
         { "cam_ctrl_value2", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_camera_cmd_camera_control_t, cam_ctrl_value2) }, \
         { "cam_ctrl_value3", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_camera_cmd_camera_control_t, cam_ctrl_value3) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_camera_cmd_camera_control_t, longitude) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_wk_camera_cmd_camera_control_t, latitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_wk_camera_cmd_camera_control_t, altitude) }, \
         { "UavRoll", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wk_camera_cmd_camera_control_t, UavRoll) }, \
         { "UavPitch", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wk_camera_cmd_camera_control_t, UavPitch) }, \
         { "UavYaw", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wk_camera_cmd_camera_control_t, UavYaw) }, \
         { "GimbalRoll", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wk_camera_cmd_camera_control_t, GimbalRoll) }, \
         { "GimbalPitch", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_wk_camera_cmd_camera_control_t, GimbalPitch) }, \
         { "GimbalYaw", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_wk_camera_cmd_camera_control_t, GimbalYaw) }, \
         { "cam_ctrl_timestamps", NULL, MAVLINK_TYPE_UINT32_T, 0, 48, offsetof(mavlink_wk_camera_cmd_camera_control_t, cam_ctrl_timestamps) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_CAMERA_CONTROL { \
    "WK_CAMERA_CMD_CAMERA_CONTROL", \
    15, \
    {  { "cam_ctrl_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_wk_camera_cmd_camera_control_t, cam_ctrl_type) }, \
         { "cam_ctrl_sub_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 53, offsetof(mavlink_wk_camera_cmd_camera_control_t, cam_ctrl_sub_type) }, \
         { "cam_ctrl_value1", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_cmd_camera_control_t, cam_ctrl_value1) }, \
         { "cam_ctrl_value2", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_camera_cmd_camera_control_t, cam_ctrl_value2) }, \
         { "cam_ctrl_value3", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_camera_cmd_camera_control_t, cam_ctrl_value3) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_camera_cmd_camera_control_t, longitude) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_wk_camera_cmd_camera_control_t, latitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_wk_camera_cmd_camera_control_t, altitude) }, \
         { "UavRoll", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wk_camera_cmd_camera_control_t, UavRoll) }, \
         { "UavPitch", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wk_camera_cmd_camera_control_t, UavPitch) }, \
         { "UavYaw", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wk_camera_cmd_camera_control_t, UavYaw) }, \
         { "GimbalRoll", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wk_camera_cmd_camera_control_t, GimbalRoll) }, \
         { "GimbalPitch", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_wk_camera_cmd_camera_control_t, GimbalPitch) }, \
         { "GimbalYaw", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_wk_camera_cmd_camera_control_t, GimbalYaw) }, \
         { "cam_ctrl_timestamps", NULL, MAVLINK_TYPE_UINT32_T, 0, 48, offsetof(mavlink_wk_camera_cmd_camera_control_t, cam_ctrl_timestamps) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_cmd_camera_control message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param cam_ctrl_type  see enum WKCAM_CAMERA_CONTROL_TYPE
 * @param cam_ctrl_sub_type  time lapse: see WK_TIME_LAPSE_MODE ; panorama shot: see WK_PANORAMA_MODE
 * @param cam_ctrl_value1  continue: pictrue num; time token: time(S); time lapse: sampling time; record: see enum WACAM_VIDEO_REC_CMD
 * @param cam_ctrl_value2   time lapse: frame rate
 * @param cam_ctrl_value3   time lapse: total time
 * @param longitude  lon * 1E7
 * @param latitude  lat * lE7
 * @param altitude  alt * 100
 * @param UavRoll  uav roll angle,unit degree
 * @param UavPitch  uav pitch angle,unit degree
 * @param UavYaw  uav yaw angle,unit degree
 * @param GimbalRoll  gimbal roll angle,unit degree
 * @param GimbalPitch  gimbal pitch angle,unit degree
 * @param GimbalYaw  gimbal yaw angle,unit degree
 * @param cam_ctrl_timestamps  active_timestamps
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_camera_control_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t cam_ctrl_type, uint8_t cam_ctrl_sub_type, uint32_t cam_ctrl_value1, uint32_t cam_ctrl_value2, uint32_t cam_ctrl_value3, int32_t longitude, int32_t latitude, int32_t altitude, float UavRoll, float UavPitch, float UavYaw, float GimbalRoll, float GimbalPitch, float GimbalYaw, uint32_t cam_ctrl_timestamps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN];
    _mav_put_uint32_t(buf, 0, cam_ctrl_value1);
    _mav_put_uint32_t(buf, 4, cam_ctrl_value2);
    _mav_put_uint32_t(buf, 8, cam_ctrl_value3);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, latitude);
    _mav_put_int32_t(buf, 20, altitude);
    _mav_put_float(buf, 24, UavRoll);
    _mav_put_float(buf, 28, UavPitch);
    _mav_put_float(buf, 32, UavYaw);
    _mav_put_float(buf, 36, GimbalRoll);
    _mav_put_float(buf, 40, GimbalPitch);
    _mav_put_float(buf, 44, GimbalYaw);
    _mav_put_uint32_t(buf, 48, cam_ctrl_timestamps);
    _mav_put_uint8_t(buf, 52, cam_ctrl_type);
    _mav_put_uint8_t(buf, 53, cam_ctrl_sub_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN);
#else
    mavlink_wk_camera_cmd_camera_control_t packet;
    packet.cam_ctrl_value1 = cam_ctrl_value1;
    packet.cam_ctrl_value2 = cam_ctrl_value2;
    packet.cam_ctrl_value3 = cam_ctrl_value3;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.altitude = altitude;
    packet.UavRoll = UavRoll;
    packet.UavPitch = UavPitch;
    packet.UavYaw = UavYaw;
    packet.GimbalRoll = GimbalRoll;
    packet.GimbalPitch = GimbalPitch;
    packet.GimbalYaw = GimbalYaw;
    packet.cam_ctrl_timestamps = cam_ctrl_timestamps;
    packet.cam_ctrl_type = cam_ctrl_type;
    packet.cam_ctrl_sub_type = cam_ctrl_sub_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_CRC);
}

/**
 * @brief Pack a wk_camera_cmd_camera_control message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cam_ctrl_type  see enum WKCAM_CAMERA_CONTROL_TYPE
 * @param cam_ctrl_sub_type  time lapse: see WK_TIME_LAPSE_MODE ; panorama shot: see WK_PANORAMA_MODE
 * @param cam_ctrl_value1  continue: pictrue num; time token: time(S); time lapse: sampling time; record: see enum WACAM_VIDEO_REC_CMD
 * @param cam_ctrl_value2   time lapse: frame rate
 * @param cam_ctrl_value3   time lapse: total time
 * @param longitude  lon * 1E7
 * @param latitude  lat * lE7
 * @param altitude  alt * 100
 * @param UavRoll  uav roll angle,unit degree
 * @param UavPitch  uav pitch angle,unit degree
 * @param UavYaw  uav yaw angle,unit degree
 * @param GimbalRoll  gimbal roll angle,unit degree
 * @param GimbalPitch  gimbal pitch angle,unit degree
 * @param GimbalYaw  gimbal yaw angle,unit degree
 * @param cam_ctrl_timestamps  active_timestamps
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_camera_control_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t cam_ctrl_type,uint8_t cam_ctrl_sub_type,uint32_t cam_ctrl_value1,uint32_t cam_ctrl_value2,uint32_t cam_ctrl_value3,int32_t longitude,int32_t latitude,int32_t altitude,float UavRoll,float UavPitch,float UavYaw,float GimbalRoll,float GimbalPitch,float GimbalYaw,uint32_t cam_ctrl_timestamps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN];
    _mav_put_uint32_t(buf, 0, cam_ctrl_value1);
    _mav_put_uint32_t(buf, 4, cam_ctrl_value2);
    _mav_put_uint32_t(buf, 8, cam_ctrl_value3);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, latitude);
    _mav_put_int32_t(buf, 20, altitude);
    _mav_put_float(buf, 24, UavRoll);
    _mav_put_float(buf, 28, UavPitch);
    _mav_put_float(buf, 32, UavYaw);
    _mav_put_float(buf, 36, GimbalRoll);
    _mav_put_float(buf, 40, GimbalPitch);
    _mav_put_float(buf, 44, GimbalYaw);
    _mav_put_uint32_t(buf, 48, cam_ctrl_timestamps);
    _mav_put_uint8_t(buf, 52, cam_ctrl_type);
    _mav_put_uint8_t(buf, 53, cam_ctrl_sub_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN);
#else
    mavlink_wk_camera_cmd_camera_control_t packet;
    packet.cam_ctrl_value1 = cam_ctrl_value1;
    packet.cam_ctrl_value2 = cam_ctrl_value2;
    packet.cam_ctrl_value3 = cam_ctrl_value3;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.altitude = altitude;
    packet.UavRoll = UavRoll;
    packet.UavPitch = UavPitch;
    packet.UavYaw = UavYaw;
    packet.GimbalRoll = GimbalRoll;
    packet.GimbalPitch = GimbalPitch;
    packet.GimbalYaw = GimbalYaw;
    packet.cam_ctrl_timestamps = cam_ctrl_timestamps;
    packet.cam_ctrl_type = cam_ctrl_type;
    packet.cam_ctrl_sub_type = cam_ctrl_sub_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_CRC);
}

/**
 * @brief Encode a wk_camera_cmd_camera_control struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_camera_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_camera_control_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_cmd_camera_control_t* wk_camera_cmd_camera_control)
{
    return mavlink_msg_wk_camera_cmd_camera_control_pack(system_id, component_id, msg, wk_camera_cmd_camera_control->cam_ctrl_type, wk_camera_cmd_camera_control->cam_ctrl_sub_type, wk_camera_cmd_camera_control->cam_ctrl_value1, wk_camera_cmd_camera_control->cam_ctrl_value2, wk_camera_cmd_camera_control->cam_ctrl_value3, wk_camera_cmd_camera_control->longitude, wk_camera_cmd_camera_control->latitude, wk_camera_cmd_camera_control->altitude, wk_camera_cmd_camera_control->UavRoll, wk_camera_cmd_camera_control->UavPitch, wk_camera_cmd_camera_control->UavYaw, wk_camera_cmd_camera_control->GimbalRoll, wk_camera_cmd_camera_control->GimbalPitch, wk_camera_cmd_camera_control->GimbalYaw, wk_camera_cmd_camera_control->cam_ctrl_timestamps);
}

/**
 * @brief Encode a wk_camera_cmd_camera_control struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_camera_control C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_camera_control_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_cmd_camera_control_t* wk_camera_cmd_camera_control)
{
    return mavlink_msg_wk_camera_cmd_camera_control_pack_chan(system_id, component_id, chan, msg, wk_camera_cmd_camera_control->cam_ctrl_type, wk_camera_cmd_camera_control->cam_ctrl_sub_type, wk_camera_cmd_camera_control->cam_ctrl_value1, wk_camera_cmd_camera_control->cam_ctrl_value2, wk_camera_cmd_camera_control->cam_ctrl_value3, wk_camera_cmd_camera_control->longitude, wk_camera_cmd_camera_control->latitude, wk_camera_cmd_camera_control->altitude, wk_camera_cmd_camera_control->UavRoll, wk_camera_cmd_camera_control->UavPitch, wk_camera_cmd_camera_control->UavYaw, wk_camera_cmd_camera_control->GimbalRoll, wk_camera_cmd_camera_control->GimbalPitch, wk_camera_cmd_camera_control->GimbalYaw, wk_camera_cmd_camera_control->cam_ctrl_timestamps);
}

/**
 * @brief Send a wk_camera_cmd_camera_control message
 * @param chan MAVLink channel to send the message
 *
 * @param cam_ctrl_type  see enum WKCAM_CAMERA_CONTROL_TYPE
 * @param cam_ctrl_sub_type  time lapse: see WK_TIME_LAPSE_MODE ; panorama shot: see WK_PANORAMA_MODE
 * @param cam_ctrl_value1  continue: pictrue num; time token: time(S); time lapse: sampling time; record: see enum WACAM_VIDEO_REC_CMD
 * @param cam_ctrl_value2   time lapse: frame rate
 * @param cam_ctrl_value3   time lapse: total time
 * @param longitude  lon * 1E7
 * @param latitude  lat * lE7
 * @param altitude  alt * 100
 * @param UavRoll  uav roll angle,unit degree
 * @param UavPitch  uav pitch angle,unit degree
 * @param UavYaw  uav yaw angle,unit degree
 * @param GimbalRoll  gimbal roll angle,unit degree
 * @param GimbalPitch  gimbal pitch angle,unit degree
 * @param GimbalYaw  gimbal yaw angle,unit degree
 * @param cam_ctrl_timestamps  active_timestamps
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_cmd_camera_control_send(mavlink_channel_t chan, uint8_t cam_ctrl_type, uint8_t cam_ctrl_sub_type, uint32_t cam_ctrl_value1, uint32_t cam_ctrl_value2, uint32_t cam_ctrl_value3, int32_t longitude, int32_t latitude, int32_t altitude, float UavRoll, float UavPitch, float UavYaw, float GimbalRoll, float GimbalPitch, float GimbalYaw, uint32_t cam_ctrl_timestamps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN];
    _mav_put_uint32_t(buf, 0, cam_ctrl_value1);
    _mav_put_uint32_t(buf, 4, cam_ctrl_value2);
    _mav_put_uint32_t(buf, 8, cam_ctrl_value3);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, latitude);
    _mav_put_int32_t(buf, 20, altitude);
    _mav_put_float(buf, 24, UavRoll);
    _mav_put_float(buf, 28, UavPitch);
    _mav_put_float(buf, 32, UavYaw);
    _mav_put_float(buf, 36, GimbalRoll);
    _mav_put_float(buf, 40, GimbalPitch);
    _mav_put_float(buf, 44, GimbalYaw);
    _mav_put_uint32_t(buf, 48, cam_ctrl_timestamps);
    _mav_put_uint8_t(buf, 52, cam_ctrl_type);
    _mav_put_uint8_t(buf, 53, cam_ctrl_sub_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_CRC);
#else
    mavlink_wk_camera_cmd_camera_control_t packet;
    packet.cam_ctrl_value1 = cam_ctrl_value1;
    packet.cam_ctrl_value2 = cam_ctrl_value2;
    packet.cam_ctrl_value3 = cam_ctrl_value3;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.altitude = altitude;
    packet.UavRoll = UavRoll;
    packet.UavPitch = UavPitch;
    packet.UavYaw = UavYaw;
    packet.GimbalRoll = GimbalRoll;
    packet.GimbalPitch = GimbalPitch;
    packet.GimbalYaw = GimbalYaw;
    packet.cam_ctrl_timestamps = cam_ctrl_timestamps;
    packet.cam_ctrl_type = cam_ctrl_type;
    packet.cam_ctrl_sub_type = cam_ctrl_sub_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_CRC);
#endif
}

/**
 * @brief Send a wk_camera_cmd_camera_control message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_cmd_camera_control_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_cmd_camera_control_t* wk_camera_cmd_camera_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_camera_control_send(chan, wk_camera_cmd_camera_control->cam_ctrl_type, wk_camera_cmd_camera_control->cam_ctrl_sub_type, wk_camera_cmd_camera_control->cam_ctrl_value1, wk_camera_cmd_camera_control->cam_ctrl_value2, wk_camera_cmd_camera_control->cam_ctrl_value3, wk_camera_cmd_camera_control->longitude, wk_camera_cmd_camera_control->latitude, wk_camera_cmd_camera_control->altitude, wk_camera_cmd_camera_control->UavRoll, wk_camera_cmd_camera_control->UavPitch, wk_camera_cmd_camera_control->UavYaw, wk_camera_cmd_camera_control->GimbalRoll, wk_camera_cmd_camera_control->GimbalPitch, wk_camera_cmd_camera_control->GimbalYaw, wk_camera_cmd_camera_control->cam_ctrl_timestamps);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL, (const char *)wk_camera_cmd_camera_control, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_cmd_camera_control_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t cam_ctrl_type, uint8_t cam_ctrl_sub_type, uint32_t cam_ctrl_value1, uint32_t cam_ctrl_value2, uint32_t cam_ctrl_value3, int32_t longitude, int32_t latitude, int32_t altitude, float UavRoll, float UavPitch, float UavYaw, float GimbalRoll, float GimbalPitch, float GimbalYaw, uint32_t cam_ctrl_timestamps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, cam_ctrl_value1);
    _mav_put_uint32_t(buf, 4, cam_ctrl_value2);
    _mav_put_uint32_t(buf, 8, cam_ctrl_value3);
    _mav_put_int32_t(buf, 12, longitude);
    _mav_put_int32_t(buf, 16, latitude);
    _mav_put_int32_t(buf, 20, altitude);
    _mav_put_float(buf, 24, UavRoll);
    _mav_put_float(buf, 28, UavPitch);
    _mav_put_float(buf, 32, UavYaw);
    _mav_put_float(buf, 36, GimbalRoll);
    _mav_put_float(buf, 40, GimbalPitch);
    _mav_put_float(buf, 44, GimbalYaw);
    _mav_put_uint32_t(buf, 48, cam_ctrl_timestamps);
    _mav_put_uint8_t(buf, 52, cam_ctrl_type);
    _mav_put_uint8_t(buf, 53, cam_ctrl_sub_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_CRC);
#else
    mavlink_wk_camera_cmd_camera_control_t *packet = (mavlink_wk_camera_cmd_camera_control_t *)msgbuf;
    packet->cam_ctrl_value1 = cam_ctrl_value1;
    packet->cam_ctrl_value2 = cam_ctrl_value2;
    packet->cam_ctrl_value3 = cam_ctrl_value3;
    packet->longitude = longitude;
    packet->latitude = latitude;
    packet->altitude = altitude;
    packet->UavRoll = UavRoll;
    packet->UavPitch = UavPitch;
    packet->UavYaw = UavYaw;
    packet->GimbalRoll = GimbalRoll;
    packet->GimbalPitch = GimbalPitch;
    packet->GimbalYaw = GimbalYaw;
    packet->cam_ctrl_timestamps = cam_ctrl_timestamps;
    packet->cam_ctrl_type = cam_ctrl_type;
    packet->cam_ctrl_sub_type = cam_ctrl_sub_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_CMD_CAMERA_CONTROL UNPACKING


/**
 * @brief Get field cam_ctrl_type from wk_camera_cmd_camera_control message
 *
 * @return  see enum WKCAM_CAMERA_CONTROL_TYPE
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_camera_control_get_cam_ctrl_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  52);
}

/**
 * @brief Get field cam_ctrl_sub_type from wk_camera_cmd_camera_control message
 *
 * @return  time lapse: see WK_TIME_LAPSE_MODE ; panorama shot: see WK_PANORAMA_MODE
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_camera_control_get_cam_ctrl_sub_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  53);
}

/**
 * @brief Get field cam_ctrl_value1 from wk_camera_cmd_camera_control message
 *
 * @return  continue: pictrue num; time token: time(S); time lapse: sampling time; record: see enum WACAM_VIDEO_REC_CMD
 */
static inline uint32_t mavlink_msg_wk_camera_cmd_camera_control_get_cam_ctrl_value1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field cam_ctrl_value2 from wk_camera_cmd_camera_control message
 *
 * @return   time lapse: frame rate
 */
static inline uint32_t mavlink_msg_wk_camera_cmd_camera_control_get_cam_ctrl_value2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field cam_ctrl_value3 from wk_camera_cmd_camera_control message
 *
 * @return   time lapse: total time
 */
static inline uint32_t mavlink_msg_wk_camera_cmd_camera_control_get_cam_ctrl_value3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field longitude from wk_camera_cmd_camera_control message
 *
 * @return  lon * 1E7
 */
static inline int32_t mavlink_msg_wk_camera_cmd_camera_control_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field latitude from wk_camera_cmd_camera_control message
 *
 * @return  lat * lE7
 */
static inline int32_t mavlink_msg_wk_camera_cmd_camera_control_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field altitude from wk_camera_cmd_camera_control message
 *
 * @return  alt * 100
 */
static inline int32_t mavlink_msg_wk_camera_cmd_camera_control_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field UavRoll from wk_camera_cmd_camera_control message
 *
 * @return  uav roll angle,unit degree
 */
static inline float mavlink_msg_wk_camera_cmd_camera_control_get_UavRoll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field UavPitch from wk_camera_cmd_camera_control message
 *
 * @return  uav pitch angle,unit degree
 */
static inline float mavlink_msg_wk_camera_cmd_camera_control_get_UavPitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field UavYaw from wk_camera_cmd_camera_control message
 *
 * @return  uav yaw angle,unit degree
 */
static inline float mavlink_msg_wk_camera_cmd_camera_control_get_UavYaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field GimbalRoll from wk_camera_cmd_camera_control message
 *
 * @return  gimbal roll angle,unit degree
 */
static inline float mavlink_msg_wk_camera_cmd_camera_control_get_GimbalRoll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field GimbalPitch from wk_camera_cmd_camera_control message
 *
 * @return  gimbal pitch angle,unit degree
 */
static inline float mavlink_msg_wk_camera_cmd_camera_control_get_GimbalPitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field GimbalYaw from wk_camera_cmd_camera_control message
 *
 * @return  gimbal yaw angle,unit degree
 */
static inline float mavlink_msg_wk_camera_cmd_camera_control_get_GimbalYaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field cam_ctrl_timestamps from wk_camera_cmd_camera_control message
 *
 * @return  active_timestamps
 */
static inline uint32_t mavlink_msg_wk_camera_cmd_camera_control_get_cam_ctrl_timestamps(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  48);
}

/**
 * @brief Decode a wk_camera_cmd_camera_control message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_cmd_camera_control C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_cmd_camera_control_decode(const mavlink_message_t* msg, mavlink_wk_camera_cmd_camera_control_t* wk_camera_cmd_camera_control)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_cmd_camera_control->cam_ctrl_value1 = mavlink_msg_wk_camera_cmd_camera_control_get_cam_ctrl_value1(msg);
    wk_camera_cmd_camera_control->cam_ctrl_value2 = mavlink_msg_wk_camera_cmd_camera_control_get_cam_ctrl_value2(msg);
    wk_camera_cmd_camera_control->cam_ctrl_value3 = mavlink_msg_wk_camera_cmd_camera_control_get_cam_ctrl_value3(msg);
    wk_camera_cmd_camera_control->longitude = mavlink_msg_wk_camera_cmd_camera_control_get_longitude(msg);
    wk_camera_cmd_camera_control->latitude = mavlink_msg_wk_camera_cmd_camera_control_get_latitude(msg);
    wk_camera_cmd_camera_control->altitude = mavlink_msg_wk_camera_cmd_camera_control_get_altitude(msg);
    wk_camera_cmd_camera_control->UavRoll = mavlink_msg_wk_camera_cmd_camera_control_get_UavRoll(msg);
    wk_camera_cmd_camera_control->UavPitch = mavlink_msg_wk_camera_cmd_camera_control_get_UavPitch(msg);
    wk_camera_cmd_camera_control->UavYaw = mavlink_msg_wk_camera_cmd_camera_control_get_UavYaw(msg);
    wk_camera_cmd_camera_control->GimbalRoll = mavlink_msg_wk_camera_cmd_camera_control_get_GimbalRoll(msg);
    wk_camera_cmd_camera_control->GimbalPitch = mavlink_msg_wk_camera_cmd_camera_control_get_GimbalPitch(msg);
    wk_camera_cmd_camera_control->GimbalYaw = mavlink_msg_wk_camera_cmd_camera_control_get_GimbalYaw(msg);
    wk_camera_cmd_camera_control->cam_ctrl_timestamps = mavlink_msg_wk_camera_cmd_camera_control_get_cam_ctrl_timestamps(msg);
    wk_camera_cmd_camera_control->cam_ctrl_type = mavlink_msg_wk_camera_cmd_camera_control_get_cam_ctrl_type(msg);
    wk_camera_cmd_camera_control->cam_ctrl_sub_type = mavlink_msg_wk_camera_cmd_camera_control_get_cam_ctrl_sub_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN;
        memset(wk_camera_cmd_camera_control, 0, MAVLINK_MSG_ID_WK_CAMERA_CMD_CAMERA_CONTROL_LEN);
    memcpy(wk_camera_cmd_camera_control, _MAV_PAYLOAD(msg), len);
#endif
}
