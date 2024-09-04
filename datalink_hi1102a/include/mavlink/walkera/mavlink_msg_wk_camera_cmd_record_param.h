#pragma once
// MESSAGE WK_CAMERA_CMD_RECORD_PARAM PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM 8051


typedef struct __mavlink_wk_camera_cmd_record_param_t {
 uint8_t record_resolution; /*<  see enum WKCAM_RECORD_RESOLUTION*/
 uint8_t record_bitrate; /*<  see enum WKCAM_RECORD_BITRATE*/
} mavlink_wk_camera_cmd_record_param_t;

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN 2
#define MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_MIN_LEN 2
#define MAVLINK_MSG_ID_8051_LEN 2
#define MAVLINK_MSG_ID_8051_MIN_LEN 2

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_CRC 41
#define MAVLINK_MSG_ID_8051_CRC 41



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_RECORD_PARAM { \
    8051, \
    "WK_CAMERA_CMD_RECORD_PARAM", \
    2, \
    {  { "record_resolution", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_camera_cmd_record_param_t, record_resolution) }, \
         { "record_bitrate", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_camera_cmd_record_param_t, record_bitrate) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_RECORD_PARAM { \
    "WK_CAMERA_CMD_RECORD_PARAM", \
    2, \
    {  { "record_resolution", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_camera_cmd_record_param_t, record_resolution) }, \
         { "record_bitrate", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_camera_cmd_record_param_t, record_bitrate) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_cmd_record_param message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param record_resolution  see enum WKCAM_RECORD_RESOLUTION
 * @param record_bitrate  see enum WKCAM_RECORD_BITRATE
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_record_param_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t record_resolution, uint8_t record_bitrate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN];
    _mav_put_uint8_t(buf, 0, record_resolution);
    _mav_put_uint8_t(buf, 1, record_bitrate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN);
#else
    mavlink_wk_camera_cmd_record_param_t packet;
    packet.record_resolution = record_resolution;
    packet.record_bitrate = record_bitrate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_CRC);
}

/**
 * @brief Pack a wk_camera_cmd_record_param message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param record_resolution  see enum WKCAM_RECORD_RESOLUTION
 * @param record_bitrate  see enum WKCAM_RECORD_BITRATE
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_record_param_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t record_resolution,uint8_t record_bitrate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN];
    _mav_put_uint8_t(buf, 0, record_resolution);
    _mav_put_uint8_t(buf, 1, record_bitrate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN);
#else
    mavlink_wk_camera_cmd_record_param_t packet;
    packet.record_resolution = record_resolution;
    packet.record_bitrate = record_bitrate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_CRC);
}

/**
 * @brief Encode a wk_camera_cmd_record_param struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_record_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_record_param_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_cmd_record_param_t* wk_camera_cmd_record_param)
{
    return mavlink_msg_wk_camera_cmd_record_param_pack(system_id, component_id, msg, wk_camera_cmd_record_param->record_resolution, wk_camera_cmd_record_param->record_bitrate);
}

/**
 * @brief Encode a wk_camera_cmd_record_param struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_record_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_record_param_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_cmd_record_param_t* wk_camera_cmd_record_param)
{
    return mavlink_msg_wk_camera_cmd_record_param_pack_chan(system_id, component_id, chan, msg, wk_camera_cmd_record_param->record_resolution, wk_camera_cmd_record_param->record_bitrate);
}

/**
 * @brief Send a wk_camera_cmd_record_param message
 * @param chan MAVLink channel to send the message
 *
 * @param record_resolution  see enum WKCAM_RECORD_RESOLUTION
 * @param record_bitrate  see enum WKCAM_RECORD_BITRATE
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_cmd_record_param_send(mavlink_channel_t chan, uint8_t record_resolution, uint8_t record_bitrate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN];
    _mav_put_uint8_t(buf, 0, record_resolution);
    _mav_put_uint8_t(buf, 1, record_bitrate);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_CRC);
#else
    mavlink_wk_camera_cmd_record_param_t packet;
    packet.record_resolution = record_resolution;
    packet.record_bitrate = record_bitrate;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_CRC);
#endif
}

/**
 * @brief Send a wk_camera_cmd_record_param message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_cmd_record_param_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_cmd_record_param_t* wk_camera_cmd_record_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_record_param_send(chan, wk_camera_cmd_record_param->record_resolution, wk_camera_cmd_record_param->record_bitrate);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM, (const char *)wk_camera_cmd_record_param, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_cmd_record_param_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t record_resolution, uint8_t record_bitrate)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, record_resolution);
    _mav_put_uint8_t(buf, 1, record_bitrate);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_CRC);
#else
    mavlink_wk_camera_cmd_record_param_t *packet = (mavlink_wk_camera_cmd_record_param_t *)msgbuf;
    packet->record_resolution = record_resolution;
    packet->record_bitrate = record_bitrate;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_CMD_RECORD_PARAM UNPACKING


/**
 * @brief Get field record_resolution from wk_camera_cmd_record_param message
 *
 * @return  see enum WKCAM_RECORD_RESOLUTION
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_record_param_get_record_resolution(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field record_bitrate from wk_camera_cmd_record_param message
 *
 * @return  see enum WKCAM_RECORD_BITRATE
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_record_param_get_record_bitrate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a wk_camera_cmd_record_param message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_cmd_record_param C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_cmd_record_param_decode(const mavlink_message_t* msg, mavlink_wk_camera_cmd_record_param_t* wk_camera_cmd_record_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_cmd_record_param->record_resolution = mavlink_msg_wk_camera_cmd_record_param_get_record_resolution(msg);
    wk_camera_cmd_record_param->record_bitrate = mavlink_msg_wk_camera_cmd_record_param_get_record_bitrate(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN;
        memset(wk_camera_cmd_record_param, 0, MAVLINK_MSG_ID_WK_CAMERA_CMD_RECORD_PARAM_LEN);
    memcpy(wk_camera_cmd_record_param, _MAV_PAYLOAD(msg), len);
#endif
}
