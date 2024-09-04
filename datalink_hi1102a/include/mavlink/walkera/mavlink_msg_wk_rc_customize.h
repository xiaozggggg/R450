#pragma once
// MESSAGE WK_RC_CUSTOMIZE PACKING

#define MAVLINK_MSG_ID_WK_RC_CUSTOMIZE 8517


typedef struct __mavlink_wk_rc_customize_t {
 uint8_t single_click; /*<  */
 uint8_t double_click; /*<  see enum WK_RC_CUSTOM_CMD*/
} mavlink_wk_rc_customize_t;

#define MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN 2
#define MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_MIN_LEN 2
#define MAVLINK_MSG_ID_8517_LEN 2
#define MAVLINK_MSG_ID_8517_MIN_LEN 2

#define MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_CRC 25
#define MAVLINK_MSG_ID_8517_CRC 25



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_RC_CUSTOMIZE { \
    8517, \
    "WK_RC_CUSTOMIZE", \
    2, \
    {  { "single_click", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_rc_customize_t, single_click) }, \
         { "double_click", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_rc_customize_t, double_click) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_RC_CUSTOMIZE { \
    "WK_RC_CUSTOMIZE", \
    2, \
    {  { "single_click", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_rc_customize_t, single_click) }, \
         { "double_click", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_rc_customize_t, double_click) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_rc_customize message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param single_click  
 * @param double_click  see enum WK_RC_CUSTOM_CMD
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_rc_customize_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t single_click, uint8_t double_click)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN];
    _mav_put_uint8_t(buf, 0, single_click);
    _mav_put_uint8_t(buf, 1, double_click);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN);
#else
    mavlink_wk_rc_customize_t packet;
    packet.single_click = single_click;
    packet.double_click = double_click;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_RC_CUSTOMIZE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_MIN_LEN, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_CRC);
}

/**
 * @brief Pack a wk_rc_customize message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param single_click  
 * @param double_click  see enum WK_RC_CUSTOM_CMD
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_rc_customize_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t single_click,uint8_t double_click)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN];
    _mav_put_uint8_t(buf, 0, single_click);
    _mav_put_uint8_t(buf, 1, double_click);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN);
#else
    mavlink_wk_rc_customize_t packet;
    packet.single_click = single_click;
    packet.double_click = double_click;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_RC_CUSTOMIZE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_MIN_LEN, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_CRC);
}

/**
 * @brief Encode a wk_rc_customize struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_rc_customize C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_rc_customize_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_rc_customize_t* wk_rc_customize)
{
    return mavlink_msg_wk_rc_customize_pack(system_id, component_id, msg, wk_rc_customize->single_click, wk_rc_customize->double_click);
}

/**
 * @brief Encode a wk_rc_customize struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_rc_customize C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_rc_customize_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_rc_customize_t* wk_rc_customize)
{
    return mavlink_msg_wk_rc_customize_pack_chan(system_id, component_id, chan, msg, wk_rc_customize->single_click, wk_rc_customize->double_click);
}

/**
 * @brief Send a wk_rc_customize message
 * @param chan MAVLink channel to send the message
 *
 * @param single_click  
 * @param double_click  see enum WK_RC_CUSTOM_CMD
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_rc_customize_send(mavlink_channel_t chan, uint8_t single_click, uint8_t double_click)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN];
    _mav_put_uint8_t(buf, 0, single_click);
    _mav_put_uint8_t(buf, 1, double_click);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE, buf, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_MIN_LEN, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_CRC);
#else
    mavlink_wk_rc_customize_t packet;
    packet.single_click = single_click;
    packet.double_click = double_click;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE, (const char *)&packet, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_MIN_LEN, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_CRC);
#endif
}

/**
 * @brief Send a wk_rc_customize message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_rc_customize_send_struct(mavlink_channel_t chan, const mavlink_wk_rc_customize_t* wk_rc_customize)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_rc_customize_send(chan, wk_rc_customize->single_click, wk_rc_customize->double_click);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE, (const char *)wk_rc_customize, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_MIN_LEN, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_rc_customize_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t single_click, uint8_t double_click)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, single_click);
    _mav_put_uint8_t(buf, 1, double_click);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE, buf, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_MIN_LEN, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_CRC);
#else
    mavlink_wk_rc_customize_t *packet = (mavlink_wk_rc_customize_t *)msgbuf;
    packet->single_click = single_click;
    packet->double_click = double_click;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE, (const char *)packet, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_MIN_LEN, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_RC_CUSTOMIZE UNPACKING


/**
 * @brief Get field single_click from wk_rc_customize message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_rc_customize_get_single_click(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field double_click from wk_rc_customize message
 *
 * @return  see enum WK_RC_CUSTOM_CMD
 */
static inline uint8_t mavlink_msg_wk_rc_customize_get_double_click(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a wk_rc_customize message into a struct
 *
 * @param msg The message to decode
 * @param wk_rc_customize C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_rc_customize_decode(const mavlink_message_t* msg, mavlink_wk_rc_customize_t* wk_rc_customize)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_rc_customize->single_click = mavlink_msg_wk_rc_customize_get_single_click(msg);
    wk_rc_customize->double_click = mavlink_msg_wk_rc_customize_get_double_click(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN? msg->len : MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN;
        memset(wk_rc_customize, 0, MAVLINK_MSG_ID_WK_RC_CUSTOMIZE_LEN);
    memcpy(wk_rc_customize, _MAV_PAYLOAD(msg), len);
#endif
}
