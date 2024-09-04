#pragma once
// MESSAGE WK_CAMERA_CMD_EV_MODE PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE 8054


typedef struct __mavlink_wk_camera_cmd_ev_mode_t {
 uint8_t ev_mode; /*<  see enum WKCAM_EV_MODE*/
} mavlink_wk_camera_cmd_ev_mode_t;

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN 1
#define MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_MIN_LEN 1
#define MAVLINK_MSG_ID_8054_LEN 1
#define MAVLINK_MSG_ID_8054_MIN_LEN 1

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_CRC 218
#define MAVLINK_MSG_ID_8054_CRC 218



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_EV_MODE { \
    8054, \
    "WK_CAMERA_CMD_EV_MODE", \
    1, \
    {  { "ev_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_camera_cmd_ev_mode_t, ev_mode) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_EV_MODE { \
    "WK_CAMERA_CMD_EV_MODE", \
    1, \
    {  { "ev_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_camera_cmd_ev_mode_t, ev_mode) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_cmd_ev_mode message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ev_mode  see enum WKCAM_EV_MODE
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_ev_mode_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t ev_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN];
    _mav_put_uint8_t(buf, 0, ev_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN);
#else
    mavlink_wk_camera_cmd_ev_mode_t packet;
    packet.ev_mode = ev_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_CRC);
}

/**
 * @brief Pack a wk_camera_cmd_ev_mode message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ev_mode  see enum WKCAM_EV_MODE
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_ev_mode_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t ev_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN];
    _mav_put_uint8_t(buf, 0, ev_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN);
#else
    mavlink_wk_camera_cmd_ev_mode_t packet;
    packet.ev_mode = ev_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_CRC);
}

/**
 * @brief Encode a wk_camera_cmd_ev_mode struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_ev_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_ev_mode_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_cmd_ev_mode_t* wk_camera_cmd_ev_mode)
{
    return mavlink_msg_wk_camera_cmd_ev_mode_pack(system_id, component_id, msg, wk_camera_cmd_ev_mode->ev_mode);
}

/**
 * @brief Encode a wk_camera_cmd_ev_mode struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_ev_mode C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_ev_mode_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_cmd_ev_mode_t* wk_camera_cmd_ev_mode)
{
    return mavlink_msg_wk_camera_cmd_ev_mode_pack_chan(system_id, component_id, chan, msg, wk_camera_cmd_ev_mode->ev_mode);
}

/**
 * @brief Send a wk_camera_cmd_ev_mode message
 * @param chan MAVLink channel to send the message
 *
 * @param ev_mode  see enum WKCAM_EV_MODE
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_cmd_ev_mode_send(mavlink_channel_t chan, uint8_t ev_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN];
    _mav_put_uint8_t(buf, 0, ev_mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_CRC);
#else
    mavlink_wk_camera_cmd_ev_mode_t packet;
    packet.ev_mode = ev_mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_CRC);
#endif
}

/**
 * @brief Send a wk_camera_cmd_ev_mode message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_cmd_ev_mode_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_cmd_ev_mode_t* wk_camera_cmd_ev_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_ev_mode_send(chan, wk_camera_cmd_ev_mode->ev_mode);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE, (const char *)wk_camera_cmd_ev_mode, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_cmd_ev_mode_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t ev_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, ev_mode);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_CRC);
#else
    mavlink_wk_camera_cmd_ev_mode_t *packet = (mavlink_wk_camera_cmd_ev_mode_t *)msgbuf;
    packet->ev_mode = ev_mode;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_CMD_EV_MODE UNPACKING


/**
 * @brief Get field ev_mode from wk_camera_cmd_ev_mode message
 *
 * @return  see enum WKCAM_EV_MODE
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_ev_mode_get_ev_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a wk_camera_cmd_ev_mode message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_cmd_ev_mode C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_cmd_ev_mode_decode(const mavlink_message_t* msg, mavlink_wk_camera_cmd_ev_mode_t* wk_camera_cmd_ev_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_cmd_ev_mode->ev_mode = mavlink_msg_wk_camera_cmd_ev_mode_get_ev_mode(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN;
        memset(wk_camera_cmd_ev_mode, 0, MAVLINK_MSG_ID_WK_CAMERA_CMD_EV_MODE_LEN);
    memcpy(wk_camera_cmd_ev_mode, _MAV_PAYLOAD(msg), len);
#endif
}
