#pragma once
// MESSAGE WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS 8058


typedef struct __mavlink_wk_camera_cmd_hsyk_dualcam_params_t {
 uint8_t pip_mode; /*<  */
 uint8_t pcolor; /*<  */
} mavlink_wk_camera_cmd_hsyk_dualcam_params_t;

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN 2
#define MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_MIN_LEN 2
#define MAVLINK_MSG_ID_8058_LEN 2
#define MAVLINK_MSG_ID_8058_MIN_LEN 2

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_CRC 190
#define MAVLINK_MSG_ID_8058_CRC 190



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS { \
    8058, \
    "WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS", \
    2, \
    {  { "pip_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_camera_cmd_hsyk_dualcam_params_t, pip_mode) }, \
         { "pcolor", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_camera_cmd_hsyk_dualcam_params_t, pcolor) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS { \
    "WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS", \
    2, \
    {  { "pip_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_camera_cmd_hsyk_dualcam_params_t, pip_mode) }, \
         { "pcolor", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_camera_cmd_hsyk_dualcam_params_t, pcolor) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_cmd_hsyk_dualcam_params message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param pip_mode  
 * @param pcolor  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t pip_mode, uint8_t pcolor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN];
    _mav_put_uint8_t(buf, 0, pip_mode);
    _mav_put_uint8_t(buf, 1, pcolor);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN);
#else
    mavlink_wk_camera_cmd_hsyk_dualcam_params_t packet;
    packet.pip_mode = pip_mode;
    packet.pcolor = pcolor;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_CRC);
}

/**
 * @brief Pack a wk_camera_cmd_hsyk_dualcam_params message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pip_mode  
 * @param pcolor  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t pip_mode,uint8_t pcolor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN];
    _mav_put_uint8_t(buf, 0, pip_mode);
    _mav_put_uint8_t(buf, 1, pcolor);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN);
#else
    mavlink_wk_camera_cmd_hsyk_dualcam_params_t packet;
    packet.pip_mode = pip_mode;
    packet.pcolor = pcolor;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_CRC);
}

/**
 * @brief Encode a wk_camera_cmd_hsyk_dualcam_params struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_hsyk_dualcam_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_cmd_hsyk_dualcam_params_t* wk_camera_cmd_hsyk_dualcam_params)
{
    return mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_pack(system_id, component_id, msg, wk_camera_cmd_hsyk_dualcam_params->pip_mode, wk_camera_cmd_hsyk_dualcam_params->pcolor);
}

/**
 * @brief Encode a wk_camera_cmd_hsyk_dualcam_params struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_hsyk_dualcam_params C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_cmd_hsyk_dualcam_params_t* wk_camera_cmd_hsyk_dualcam_params)
{
    return mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_pack_chan(system_id, component_id, chan, msg, wk_camera_cmd_hsyk_dualcam_params->pip_mode, wk_camera_cmd_hsyk_dualcam_params->pcolor);
}

/**
 * @brief Send a wk_camera_cmd_hsyk_dualcam_params message
 * @param chan MAVLink channel to send the message
 *
 * @param pip_mode  
 * @param pcolor  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_send(mavlink_channel_t chan, uint8_t pip_mode, uint8_t pcolor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN];
    _mav_put_uint8_t(buf, 0, pip_mode);
    _mav_put_uint8_t(buf, 1, pcolor);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_CRC);
#else
    mavlink_wk_camera_cmd_hsyk_dualcam_params_t packet;
    packet.pip_mode = pip_mode;
    packet.pcolor = pcolor;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_CRC);
#endif
}

/**
 * @brief Send a wk_camera_cmd_hsyk_dualcam_params message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_cmd_hsyk_dualcam_params_t* wk_camera_cmd_hsyk_dualcam_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_send(chan, wk_camera_cmd_hsyk_dualcam_params->pip_mode, wk_camera_cmd_hsyk_dualcam_params->pcolor);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS, (const char *)wk_camera_cmd_hsyk_dualcam_params, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t pip_mode, uint8_t pcolor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, pip_mode);
    _mav_put_uint8_t(buf, 1, pcolor);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_CRC);
#else
    mavlink_wk_camera_cmd_hsyk_dualcam_params_t *packet = (mavlink_wk_camera_cmd_hsyk_dualcam_params_t *)msgbuf;
    packet->pip_mode = pip_mode;
    packet->pcolor = pcolor;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS UNPACKING


/**
 * @brief Get field pip_mode from wk_camera_cmd_hsyk_dualcam_params message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_get_pip_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field pcolor from wk_camera_cmd_hsyk_dualcam_params message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_get_pcolor(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a wk_camera_cmd_hsyk_dualcam_params message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_cmd_hsyk_dualcam_params C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_decode(const mavlink_message_t* msg, mavlink_wk_camera_cmd_hsyk_dualcam_params_t* wk_camera_cmd_hsyk_dualcam_params)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_cmd_hsyk_dualcam_params->pip_mode = mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_get_pip_mode(msg);
    wk_camera_cmd_hsyk_dualcam_params->pcolor = mavlink_msg_wk_camera_cmd_hsyk_dualcam_params_get_pcolor(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN;
        memset(wk_camera_cmd_hsyk_dualcam_params, 0, MAVLINK_MSG_ID_WK_CAMERA_CMD_HSYK_DUALCAM_PARAMS_LEN);
    memcpy(wk_camera_cmd_hsyk_dualcam_params, _MAV_PAYLOAD(msg), len);
#endif
}
