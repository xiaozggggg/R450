#pragma once
// MESSAGE WK_CAMERA_STATE PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_STATE 8032


typedef struct __mavlink_wk_camera_state_t {
 uint32_t takephoto_resp_timestamp; /*<  timestamp of takephoto cmd response*/
 uint32_t video_resp_timestamp; /*<  timestamp of video cmd response*/
 uint8_t takephoto_ack_flag; /*<  see enum WKCAM_TAKEPHOTO_ACK*/
 uint8_t vidio_ack_flag; /*<  see enum WKCAM_VIDEOREC_ACK*/
} mavlink_wk_camera_state_t;

#define MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN 10
#define MAVLINK_MSG_ID_WK_CAMERA_STATE_MIN_LEN 10
#define MAVLINK_MSG_ID_8032_LEN 10
#define MAVLINK_MSG_ID_8032_MIN_LEN 10

#define MAVLINK_MSG_ID_WK_CAMERA_STATE_CRC 116
#define MAVLINK_MSG_ID_8032_CRC 116



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_STATE { \
    8032, \
    "WK_CAMERA_STATE", \
    4, \
    {  { "takephoto_ack_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wk_camera_state_t, takephoto_ack_flag) }, \
         { "takephoto_resp_timestamp", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_state_t, takephoto_resp_timestamp) }, \
         { "vidio_ack_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_wk_camera_state_t, vidio_ack_flag) }, \
         { "video_resp_timestamp", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_camera_state_t, video_resp_timestamp) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_STATE { \
    "WK_CAMERA_STATE", \
    4, \
    {  { "takephoto_ack_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wk_camera_state_t, takephoto_ack_flag) }, \
         { "takephoto_resp_timestamp", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_state_t, takephoto_resp_timestamp) }, \
         { "vidio_ack_flag", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_wk_camera_state_t, vidio_ack_flag) }, \
         { "video_resp_timestamp", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_camera_state_t, video_resp_timestamp) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param takephoto_ack_flag  see enum WKCAM_TAKEPHOTO_ACK
 * @param takephoto_resp_timestamp  timestamp of takephoto cmd response
 * @param vidio_ack_flag  see enum WKCAM_VIDEOREC_ACK
 * @param video_resp_timestamp  timestamp of video cmd response
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t takephoto_ack_flag, uint32_t takephoto_resp_timestamp, uint8_t vidio_ack_flag, uint32_t video_resp_timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN];
    _mav_put_uint32_t(buf, 0, takephoto_resp_timestamp);
    _mav_put_uint32_t(buf, 4, video_resp_timestamp);
    _mav_put_uint8_t(buf, 8, takephoto_ack_flag);
    _mav_put_uint8_t(buf, 9, vidio_ack_flag);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN);
#else
    mavlink_wk_camera_state_t packet;
    packet.takephoto_resp_timestamp = takephoto_resp_timestamp;
    packet.video_resp_timestamp = video_resp_timestamp;
    packet.takephoto_ack_flag = takephoto_ack_flag;
    packet.vidio_ack_flag = vidio_ack_flag;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATE_CRC);
}

/**
 * @brief Pack a wk_camera_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param takephoto_ack_flag  see enum WKCAM_TAKEPHOTO_ACK
 * @param takephoto_resp_timestamp  timestamp of takephoto cmd response
 * @param vidio_ack_flag  see enum WKCAM_VIDEOREC_ACK
 * @param video_resp_timestamp  timestamp of video cmd response
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t takephoto_ack_flag,uint32_t takephoto_resp_timestamp,uint8_t vidio_ack_flag,uint32_t video_resp_timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN];
    _mav_put_uint32_t(buf, 0, takephoto_resp_timestamp);
    _mav_put_uint32_t(buf, 4, video_resp_timestamp);
    _mav_put_uint8_t(buf, 8, takephoto_ack_flag);
    _mav_put_uint8_t(buf, 9, vidio_ack_flag);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN);
#else
    mavlink_wk_camera_state_t packet;
    packet.takephoto_resp_timestamp = takephoto_resp_timestamp;
    packet.video_resp_timestamp = video_resp_timestamp;
    packet.takephoto_ack_flag = takephoto_ack_flag;
    packet.vidio_ack_flag = vidio_ack_flag;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATE_CRC);
}

/**
 * @brief Encode a wk_camera_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_state_t* wk_camera_state)
{
    return mavlink_msg_wk_camera_state_pack(system_id, component_id, msg, wk_camera_state->takephoto_ack_flag, wk_camera_state->takephoto_resp_timestamp, wk_camera_state->vidio_ack_flag, wk_camera_state->video_resp_timestamp);
}

/**
 * @brief Encode a wk_camera_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_state_t* wk_camera_state)
{
    return mavlink_msg_wk_camera_state_pack_chan(system_id, component_id, chan, msg, wk_camera_state->takephoto_ack_flag, wk_camera_state->takephoto_resp_timestamp, wk_camera_state->vidio_ack_flag, wk_camera_state->video_resp_timestamp);
}

/**
 * @brief Send a wk_camera_state message
 * @param chan MAVLink channel to send the message
 *
 * @param takephoto_ack_flag  see enum WKCAM_TAKEPHOTO_ACK
 * @param takephoto_resp_timestamp  timestamp of takephoto cmd response
 * @param vidio_ack_flag  see enum WKCAM_VIDEOREC_ACK
 * @param video_resp_timestamp  timestamp of video cmd response
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_state_send(mavlink_channel_t chan, uint8_t takephoto_ack_flag, uint32_t takephoto_resp_timestamp, uint8_t vidio_ack_flag, uint32_t video_resp_timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN];
    _mav_put_uint32_t(buf, 0, takephoto_resp_timestamp);
    _mav_put_uint32_t(buf, 4, video_resp_timestamp);
    _mav_put_uint8_t(buf, 8, takephoto_ack_flag);
    _mav_put_uint8_t(buf, 9, vidio_ack_flag);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_STATE, buf, MAVLINK_MSG_ID_WK_CAMERA_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATE_CRC);
#else
    mavlink_wk_camera_state_t packet;
    packet.takephoto_resp_timestamp = takephoto_resp_timestamp;
    packet.video_resp_timestamp = video_resp_timestamp;
    packet.takephoto_ack_flag = takephoto_ack_flag;
    packet.vidio_ack_flag = vidio_ack_flag;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_STATE, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATE_CRC);
#endif
}

/**
 * @brief Send a wk_camera_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_state_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_state_t* wk_camera_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_state_send(chan, wk_camera_state->takephoto_ack_flag, wk_camera_state->takephoto_resp_timestamp, wk_camera_state->vidio_ack_flag, wk_camera_state->video_resp_timestamp);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_STATE, (const char *)wk_camera_state, MAVLINK_MSG_ID_WK_CAMERA_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t takephoto_ack_flag, uint32_t takephoto_resp_timestamp, uint8_t vidio_ack_flag, uint32_t video_resp_timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, takephoto_resp_timestamp);
    _mav_put_uint32_t(buf, 4, video_resp_timestamp);
    _mav_put_uint8_t(buf, 8, takephoto_ack_flag);
    _mav_put_uint8_t(buf, 9, vidio_ack_flag);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_STATE, buf, MAVLINK_MSG_ID_WK_CAMERA_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATE_CRC);
#else
    mavlink_wk_camera_state_t *packet = (mavlink_wk_camera_state_t *)msgbuf;
    packet->takephoto_resp_timestamp = takephoto_resp_timestamp;
    packet->video_resp_timestamp = video_resp_timestamp;
    packet->takephoto_ack_flag = takephoto_ack_flag;
    packet->vidio_ack_flag = vidio_ack_flag;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_STATE, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_STATE UNPACKING


/**
 * @brief Get field takephoto_ack_flag from wk_camera_state message
 *
 * @return  see enum WKCAM_TAKEPHOTO_ACK
 */
static inline uint8_t mavlink_msg_wk_camera_state_get_takephoto_ack_flag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field takephoto_resp_timestamp from wk_camera_state message
 *
 * @return  timestamp of takephoto cmd response
 */
static inline uint32_t mavlink_msg_wk_camera_state_get_takephoto_resp_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field vidio_ack_flag from wk_camera_state message
 *
 * @return  see enum WKCAM_VIDEOREC_ACK
 */
static inline uint8_t mavlink_msg_wk_camera_state_get_vidio_ack_flag(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field video_resp_timestamp from wk_camera_state message
 *
 * @return  timestamp of video cmd response
 */
static inline uint32_t mavlink_msg_wk_camera_state_get_video_resp_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Decode a wk_camera_state message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_state_decode(const mavlink_message_t* msg, mavlink_wk_camera_state_t* wk_camera_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_state->takephoto_resp_timestamp = mavlink_msg_wk_camera_state_get_takephoto_resp_timestamp(msg);
    wk_camera_state->video_resp_timestamp = mavlink_msg_wk_camera_state_get_video_resp_timestamp(msg);
    wk_camera_state->takephoto_ack_flag = mavlink_msg_wk_camera_state_get_takephoto_ack_flag(msg);
    wk_camera_state->vidio_ack_flag = mavlink_msg_wk_camera_state_get_vidio_ack_flag(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN;
        memset(wk_camera_state, 0, MAVLINK_MSG_ID_WK_CAMERA_STATE_LEN);
    memcpy(wk_camera_state, _MAV_PAYLOAD(msg), len);
#endif
}
