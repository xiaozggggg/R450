#pragma once
// MESSAGE WK_CAMERA_CMD_VIDEO_REC PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC 8043


typedef struct __mavlink_wk_camera_cmd_video_rec_t {
 uint32_t trig_timestamps; /*<  trig timestamps*/
 uint8_t cmd_type; /*<  see enum WACAM_VIDEO_REC_CMD*/
 uint8_t response_code; /*<  see enum WKCAM_VIDEOREC_ACK*/
} mavlink_wk_camera_cmd_video_rec_t;

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN 6
#define MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_MIN_LEN 6
#define MAVLINK_MSG_ID_8043_LEN 6
#define MAVLINK_MSG_ID_8043_MIN_LEN 6

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_CRC 191
#define MAVLINK_MSG_ID_8043_CRC 191



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_VIDEO_REC { \
    8043, \
    "WK_CAMERA_CMD_VIDEO_REC", \
    3, \
    {  { "cmd_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_camera_cmd_video_rec_t, cmd_type) }, \
         { "trig_timestamps", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_cmd_video_rec_t, trig_timestamps) }, \
         { "response_code", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_camera_cmd_video_rec_t, response_code) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_VIDEO_REC { \
    "WK_CAMERA_CMD_VIDEO_REC", \
    3, \
    {  { "cmd_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_camera_cmd_video_rec_t, cmd_type) }, \
         { "trig_timestamps", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_cmd_video_rec_t, trig_timestamps) }, \
         { "response_code", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_camera_cmd_video_rec_t, response_code) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_cmd_video_rec message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param cmd_type  see enum WACAM_VIDEO_REC_CMD
 * @param trig_timestamps  trig timestamps
 * @param response_code  see enum WKCAM_VIDEOREC_ACK
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_video_rec_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t cmd_type, uint32_t trig_timestamps, uint8_t response_code)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN];
    _mav_put_uint32_t(buf, 0, trig_timestamps);
    _mav_put_uint8_t(buf, 4, cmd_type);
    _mav_put_uint8_t(buf, 5, response_code);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN);
#else
    mavlink_wk_camera_cmd_video_rec_t packet;
    packet.trig_timestamps = trig_timestamps;
    packet.cmd_type = cmd_type;
    packet.response_code = response_code;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_CRC);
}

/**
 * @brief Pack a wk_camera_cmd_video_rec message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cmd_type  see enum WACAM_VIDEO_REC_CMD
 * @param trig_timestamps  trig timestamps
 * @param response_code  see enum WKCAM_VIDEOREC_ACK
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_video_rec_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t cmd_type,uint32_t trig_timestamps,uint8_t response_code)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN];
    _mav_put_uint32_t(buf, 0, trig_timestamps);
    _mav_put_uint8_t(buf, 4, cmd_type);
    _mav_put_uint8_t(buf, 5, response_code);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN);
#else
    mavlink_wk_camera_cmd_video_rec_t packet;
    packet.trig_timestamps = trig_timestamps;
    packet.cmd_type = cmd_type;
    packet.response_code = response_code;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_CRC);
}

/**
 * @brief Encode a wk_camera_cmd_video_rec struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_video_rec C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_video_rec_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_cmd_video_rec_t* wk_camera_cmd_video_rec)
{
    return mavlink_msg_wk_camera_cmd_video_rec_pack(system_id, component_id, msg, wk_camera_cmd_video_rec->cmd_type, wk_camera_cmd_video_rec->trig_timestamps, wk_camera_cmd_video_rec->response_code);
}

/**
 * @brief Encode a wk_camera_cmd_video_rec struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_video_rec C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_video_rec_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_cmd_video_rec_t* wk_camera_cmd_video_rec)
{
    return mavlink_msg_wk_camera_cmd_video_rec_pack_chan(system_id, component_id, chan, msg, wk_camera_cmd_video_rec->cmd_type, wk_camera_cmd_video_rec->trig_timestamps, wk_camera_cmd_video_rec->response_code);
}

/**
 * @brief Send a wk_camera_cmd_video_rec message
 * @param chan MAVLink channel to send the message
 *
 * @param cmd_type  see enum WACAM_VIDEO_REC_CMD
 * @param trig_timestamps  trig timestamps
 * @param response_code  see enum WKCAM_VIDEOREC_ACK
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_cmd_video_rec_send(mavlink_channel_t chan, uint8_t cmd_type, uint32_t trig_timestamps, uint8_t response_code)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN];
    _mav_put_uint32_t(buf, 0, trig_timestamps);
    _mav_put_uint8_t(buf, 4, cmd_type);
    _mav_put_uint8_t(buf, 5, response_code);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_CRC);
#else
    mavlink_wk_camera_cmd_video_rec_t packet;
    packet.trig_timestamps = trig_timestamps;
    packet.cmd_type = cmd_type;
    packet.response_code = response_code;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_CRC);
#endif
}

/**
 * @brief Send a wk_camera_cmd_video_rec message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_cmd_video_rec_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_cmd_video_rec_t* wk_camera_cmd_video_rec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_video_rec_send(chan, wk_camera_cmd_video_rec->cmd_type, wk_camera_cmd_video_rec->trig_timestamps, wk_camera_cmd_video_rec->response_code);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC, (const char *)wk_camera_cmd_video_rec, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_cmd_video_rec_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t cmd_type, uint32_t trig_timestamps, uint8_t response_code)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, trig_timestamps);
    _mav_put_uint8_t(buf, 4, cmd_type);
    _mav_put_uint8_t(buf, 5, response_code);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_CRC);
#else
    mavlink_wk_camera_cmd_video_rec_t *packet = (mavlink_wk_camera_cmd_video_rec_t *)msgbuf;
    packet->trig_timestamps = trig_timestamps;
    packet->cmd_type = cmd_type;
    packet->response_code = response_code;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_CMD_VIDEO_REC UNPACKING


/**
 * @brief Get field cmd_type from wk_camera_cmd_video_rec message
 *
 * @return  see enum WACAM_VIDEO_REC_CMD
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_video_rec_get_cmd_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field trig_timestamps from wk_camera_cmd_video_rec message
 *
 * @return  trig timestamps
 */
static inline uint32_t mavlink_msg_wk_camera_cmd_video_rec_get_trig_timestamps(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field response_code from wk_camera_cmd_video_rec message
 *
 * @return  see enum WKCAM_VIDEOREC_ACK
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_video_rec_get_response_code(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Decode a wk_camera_cmd_video_rec message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_cmd_video_rec C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_cmd_video_rec_decode(const mavlink_message_t* msg, mavlink_wk_camera_cmd_video_rec_t* wk_camera_cmd_video_rec)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_cmd_video_rec->trig_timestamps = mavlink_msg_wk_camera_cmd_video_rec_get_trig_timestamps(msg);
    wk_camera_cmd_video_rec->cmd_type = mavlink_msg_wk_camera_cmd_video_rec_get_cmd_type(msg);
    wk_camera_cmd_video_rec->response_code = mavlink_msg_wk_camera_cmd_video_rec_get_response_code(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN;
        memset(wk_camera_cmd_video_rec, 0, MAVLINK_MSG_ID_WK_CAMERA_CMD_VIDEO_REC_LEN);
    memcpy(wk_camera_cmd_video_rec, _MAV_PAYLOAD(msg), len);
#endif
}
