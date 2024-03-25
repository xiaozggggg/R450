#pragma once
// MESSAGE WK_AI_STATUS_REQUEST PACKING

#define MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST 8524


typedef struct __mavlink_wk_ai_status_request_t {
 uint8_t percent; /*<  */
 uint8_t assaint_mode; /*<  */
 uint8_t assaint_status; /*<  see enum WK_ASSAINT_MODE_STATUS*/
} mavlink_wk_ai_status_request_t;

#define MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN 3
#define MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_MIN_LEN 3
#define MAVLINK_MSG_ID_8524_LEN 3
#define MAVLINK_MSG_ID_8524_MIN_LEN 3

#define MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_CRC 52
#define MAVLINK_MSG_ID_8524_CRC 52



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_AI_STATUS_REQUEST { \
    8524, \
    "WK_AI_STATUS_REQUEST", \
    3, \
    {  { "percent", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_ai_status_request_t, percent) }, \
         { "assaint_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_ai_status_request_t, assaint_mode) }, \
         { "assaint_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_ai_status_request_t, assaint_status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_AI_STATUS_REQUEST { \
    "WK_AI_STATUS_REQUEST", \
    3, \
    {  { "percent", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_ai_status_request_t, percent) }, \
         { "assaint_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_ai_status_request_t, assaint_mode) }, \
         { "assaint_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_ai_status_request_t, assaint_status) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_ai_status_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param percent  
 * @param assaint_mode  
 * @param assaint_status  see enum WK_ASSAINT_MODE_STATUS
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_ai_status_request_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t percent, uint8_t assaint_mode, uint8_t assaint_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN];
    _mav_put_uint8_t(buf, 0, percent);
    _mav_put_uint8_t(buf, 1, assaint_mode);
    _mav_put_uint8_t(buf, 2, assaint_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN);
#else
    mavlink_wk_ai_status_request_t packet;
    packet.percent = percent;
    packet.assaint_mode = assaint_mode;
    packet.assaint_status = assaint_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_CRC);
}

/**
 * @brief Pack a wk_ai_status_request message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param percent  
 * @param assaint_mode  
 * @param assaint_status  see enum WK_ASSAINT_MODE_STATUS
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_ai_status_request_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t percent,uint8_t assaint_mode,uint8_t assaint_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN];
    _mav_put_uint8_t(buf, 0, percent);
    _mav_put_uint8_t(buf, 1, assaint_mode);
    _mav_put_uint8_t(buf, 2, assaint_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN);
#else
    mavlink_wk_ai_status_request_t packet;
    packet.percent = percent;
    packet.assaint_mode = assaint_mode;
    packet.assaint_status = assaint_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_CRC);
}

/**
 * @brief Encode a wk_ai_status_request struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_ai_status_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_ai_status_request_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_ai_status_request_t* wk_ai_status_request)
{
    return mavlink_msg_wk_ai_status_request_pack(system_id, component_id, msg, wk_ai_status_request->percent, wk_ai_status_request->assaint_mode, wk_ai_status_request->assaint_status);
}

/**
 * @brief Encode a wk_ai_status_request struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_ai_status_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_ai_status_request_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_ai_status_request_t* wk_ai_status_request)
{
    return mavlink_msg_wk_ai_status_request_pack_chan(system_id, component_id, chan, msg, wk_ai_status_request->percent, wk_ai_status_request->assaint_mode, wk_ai_status_request->assaint_status);
}

/**
 * @brief Send a wk_ai_status_request message
 * @param chan MAVLink channel to send the message
 *
 * @param percent  
 * @param assaint_mode  
 * @param assaint_status  see enum WK_ASSAINT_MODE_STATUS
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_ai_status_request_send(mavlink_channel_t chan, uint8_t percent, uint8_t assaint_mode, uint8_t assaint_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN];
    _mav_put_uint8_t(buf, 0, percent);
    _mav_put_uint8_t(buf, 1, assaint_mode);
    _mav_put_uint8_t(buf, 2, assaint_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST, buf, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_CRC);
#else
    mavlink_wk_ai_status_request_t packet;
    packet.percent = percent;
    packet.assaint_mode = assaint_mode;
    packet.assaint_status = assaint_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST, (const char *)&packet, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_CRC);
#endif
}

/**
 * @brief Send a wk_ai_status_request message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_ai_status_request_send_struct(mavlink_channel_t chan, const mavlink_wk_ai_status_request_t* wk_ai_status_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_ai_status_request_send(chan, wk_ai_status_request->percent, wk_ai_status_request->assaint_mode, wk_ai_status_request->assaint_status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST, (const char *)wk_ai_status_request, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_ai_status_request_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t percent, uint8_t assaint_mode, uint8_t assaint_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, percent);
    _mav_put_uint8_t(buf, 1, assaint_mode);
    _mav_put_uint8_t(buf, 2, assaint_status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST, buf, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_CRC);
#else
    mavlink_wk_ai_status_request_t *packet = (mavlink_wk_ai_status_request_t *)msgbuf;
    packet->percent = percent;
    packet->assaint_mode = assaint_mode;
    packet->assaint_status = assaint_status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST, (const char *)packet, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_MIN_LEN, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_AI_STATUS_REQUEST UNPACKING


/**
 * @brief Get field percent from wk_ai_status_request message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_ai_status_request_get_percent(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field assaint_mode from wk_ai_status_request message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_ai_status_request_get_assaint_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field assaint_status from wk_ai_status_request message
 *
 * @return  see enum WK_ASSAINT_MODE_STATUS
 */
static inline uint8_t mavlink_msg_wk_ai_status_request_get_assaint_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a wk_ai_status_request message into a struct
 *
 * @param msg The message to decode
 * @param wk_ai_status_request C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_ai_status_request_decode(const mavlink_message_t* msg, mavlink_wk_ai_status_request_t* wk_ai_status_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_ai_status_request->percent = mavlink_msg_wk_ai_status_request_get_percent(msg);
    wk_ai_status_request->assaint_mode = mavlink_msg_wk_ai_status_request_get_assaint_mode(msg);
    wk_ai_status_request->assaint_status = mavlink_msg_wk_ai_status_request_get_assaint_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN? msg->len : MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN;
        memset(wk_ai_status_request, 0, MAVLINK_MSG_ID_WK_AI_STATUS_REQUEST_LEN);
    memcpy(wk_ai_status_request, _MAV_PAYLOAD(msg), len);
#endif
}
