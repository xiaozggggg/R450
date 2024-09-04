#pragma once
// MESSAGE WK_MODULE_SET_SERIAL_NUMBER PACKING

#define MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER 8009


typedef struct __mavlink_wk_module_set_serial_number_t {
 uint16_t dev_type; /*<  see enum WK_MODULE_TYPE*/
 uint8_t serial_number[32]; /*<  serial number*/
} mavlink_wk_module_set_serial_number_t;

#define MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN 34
#define MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_MIN_LEN 34
#define MAVLINK_MSG_ID_8009_LEN 34
#define MAVLINK_MSG_ID_8009_MIN_LEN 34

#define MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_CRC 111
#define MAVLINK_MSG_ID_8009_CRC 111

#define MAVLINK_MSG_WK_MODULE_SET_SERIAL_NUMBER_FIELD_SERIAL_NUMBER_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_MODULE_SET_SERIAL_NUMBER { \
    8009, \
    "WK_MODULE_SET_SERIAL_NUMBER", \
    2, \
    {  { "dev_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wk_module_set_serial_number_t, dev_type) }, \
         { "serial_number", NULL, MAVLINK_TYPE_UINT8_T, 32, 2, offsetof(mavlink_wk_module_set_serial_number_t, serial_number) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_MODULE_SET_SERIAL_NUMBER { \
    "WK_MODULE_SET_SERIAL_NUMBER", \
    2, \
    {  { "dev_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wk_module_set_serial_number_t, dev_type) }, \
         { "serial_number", NULL, MAVLINK_TYPE_UINT8_T, 32, 2, offsetof(mavlink_wk_module_set_serial_number_t, serial_number) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_module_set_serial_number message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param dev_type  see enum WK_MODULE_TYPE
 * @param serial_number  serial number
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_module_set_serial_number_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t dev_type, const uint8_t *serial_number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN];
    _mav_put_uint16_t(buf, 0, dev_type);
    _mav_put_uint8_t_array(buf, 2, serial_number, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN);
#else
    mavlink_wk_module_set_serial_number_t packet;
    packet.dev_type = dev_type;
    mav_array_memcpy(packet.serial_number, serial_number, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_MIN_LEN, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_CRC);
}

/**
 * @brief Pack a wk_module_set_serial_number message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dev_type  see enum WK_MODULE_TYPE
 * @param serial_number  serial number
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_module_set_serial_number_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t dev_type,const uint8_t *serial_number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN];
    _mav_put_uint16_t(buf, 0, dev_type);
    _mav_put_uint8_t_array(buf, 2, serial_number, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN);
#else
    mavlink_wk_module_set_serial_number_t packet;
    packet.dev_type = dev_type;
    mav_array_memcpy(packet.serial_number, serial_number, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_MIN_LEN, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_CRC);
}

/**
 * @brief Encode a wk_module_set_serial_number struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_module_set_serial_number C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_module_set_serial_number_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_module_set_serial_number_t* wk_module_set_serial_number)
{
    return mavlink_msg_wk_module_set_serial_number_pack(system_id, component_id, msg, wk_module_set_serial_number->dev_type, wk_module_set_serial_number->serial_number);
}

/**
 * @brief Encode a wk_module_set_serial_number struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_module_set_serial_number C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_module_set_serial_number_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_module_set_serial_number_t* wk_module_set_serial_number)
{
    return mavlink_msg_wk_module_set_serial_number_pack_chan(system_id, component_id, chan, msg, wk_module_set_serial_number->dev_type, wk_module_set_serial_number->serial_number);
}

/**
 * @brief Send a wk_module_set_serial_number message
 * @param chan MAVLink channel to send the message
 *
 * @param dev_type  see enum WK_MODULE_TYPE
 * @param serial_number  serial number
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_module_set_serial_number_send(mavlink_channel_t chan, uint16_t dev_type, const uint8_t *serial_number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN];
    _mav_put_uint16_t(buf, 0, dev_type);
    _mav_put_uint8_t_array(buf, 2, serial_number, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER, buf, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_MIN_LEN, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_CRC);
#else
    mavlink_wk_module_set_serial_number_t packet;
    packet.dev_type = dev_type;
    mav_array_memcpy(packet.serial_number, serial_number, sizeof(uint8_t)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER, (const char *)&packet, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_MIN_LEN, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_CRC);
#endif
}

/**
 * @brief Send a wk_module_set_serial_number message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_module_set_serial_number_send_struct(mavlink_channel_t chan, const mavlink_wk_module_set_serial_number_t* wk_module_set_serial_number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_module_set_serial_number_send(chan, wk_module_set_serial_number->dev_type, wk_module_set_serial_number->serial_number);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER, (const char *)wk_module_set_serial_number, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_MIN_LEN, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_module_set_serial_number_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t dev_type, const uint8_t *serial_number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, dev_type);
    _mav_put_uint8_t_array(buf, 2, serial_number, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER, buf, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_MIN_LEN, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_CRC);
#else
    mavlink_wk_module_set_serial_number_t *packet = (mavlink_wk_module_set_serial_number_t *)msgbuf;
    packet->dev_type = dev_type;
    mav_array_memcpy(packet->serial_number, serial_number, sizeof(uint8_t)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER, (const char *)packet, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_MIN_LEN, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_MODULE_SET_SERIAL_NUMBER UNPACKING


/**
 * @brief Get field dev_type from wk_module_set_serial_number message
 *
 * @return  see enum WK_MODULE_TYPE
 */
static inline uint16_t mavlink_msg_wk_module_set_serial_number_get_dev_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field serial_number from wk_module_set_serial_number message
 *
 * @return  serial number
 */
static inline uint16_t mavlink_msg_wk_module_set_serial_number_get_serial_number(const mavlink_message_t* msg, uint8_t *serial_number)
{
    return _MAV_RETURN_uint8_t_array(msg, serial_number, 32,  2);
}

/**
 * @brief Decode a wk_module_set_serial_number message into a struct
 *
 * @param msg The message to decode
 * @param wk_module_set_serial_number C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_module_set_serial_number_decode(const mavlink_message_t* msg, mavlink_wk_module_set_serial_number_t* wk_module_set_serial_number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_module_set_serial_number->dev_type = mavlink_msg_wk_module_set_serial_number_get_dev_type(msg);
    mavlink_msg_wk_module_set_serial_number_get_serial_number(msg, wk_module_set_serial_number->serial_number);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN? msg->len : MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN;
        memset(wk_module_set_serial_number, 0, MAVLINK_MSG_ID_WK_MODULE_SET_SERIAL_NUMBER_LEN);
    memcpy(wk_module_set_serial_number, _MAV_PAYLOAD(msg), len);
#endif
}
