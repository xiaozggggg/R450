#pragma once
// MESSAGE WK_MODULE_VERSION PACKING

#define MAVLINK_MSG_ID_WK_MODULE_VERSION 8010


typedef struct __mavlink_wk_module_version_t {
 uint32_t dev_id; /*<  device id*/
 uint32_t sw_ver; /*<  software version format:1.3.01 ---> 1301*/
 uint32_t hw_ver; /*<  hardware version*/
 uint16_t dev_type; /*<  device type*/
 uint8_t serial_number[32]; /*<  serial number */
} mavlink_wk_module_version_t;

#define MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN 46
#define MAVLINK_MSG_ID_WK_MODULE_VERSION_MIN_LEN 46
#define MAVLINK_MSG_ID_8010_LEN 46
#define MAVLINK_MSG_ID_8010_MIN_LEN 46

#define MAVLINK_MSG_ID_WK_MODULE_VERSION_CRC 166
#define MAVLINK_MSG_ID_8010_CRC 166

#define MAVLINK_MSG_WK_MODULE_VERSION_FIELD_SERIAL_NUMBER_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_MODULE_VERSION { \
    8010, \
    "WK_MODULE_VERSION", \
    5, \
    {  { "dev_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_wk_module_version_t, dev_type) }, \
         { "dev_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_module_version_t, dev_id) }, \
         { "sw_ver", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_module_version_t, sw_ver) }, \
         { "hw_ver", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_module_version_t, hw_ver) }, \
         { "serial_number", NULL, MAVLINK_TYPE_UINT8_T, 32, 14, offsetof(mavlink_wk_module_version_t, serial_number) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_MODULE_VERSION { \
    "WK_MODULE_VERSION", \
    5, \
    {  { "dev_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_wk_module_version_t, dev_type) }, \
         { "dev_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_module_version_t, dev_id) }, \
         { "sw_ver", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_module_version_t, sw_ver) }, \
         { "hw_ver", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_module_version_t, hw_ver) }, \
         { "serial_number", NULL, MAVLINK_TYPE_UINT8_T, 32, 14, offsetof(mavlink_wk_module_version_t, serial_number) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_module_version message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param dev_type  device type
 * @param dev_id  device id
 * @param sw_ver  software version format:1.3.01 ---> 1301
 * @param hw_ver  hardware version
 * @param serial_number  serial number 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_module_version_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t dev_type, uint32_t dev_id, uint32_t sw_ver, uint32_t hw_ver, const uint8_t *serial_number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN];
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint32_t(buf, 4, sw_ver);
    _mav_put_uint32_t(buf, 8, hw_ver);
    _mav_put_uint16_t(buf, 12, dev_type);
    _mav_put_uint8_t_array(buf, 14, serial_number, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN);
#else
    mavlink_wk_module_version_t packet;
    packet.dev_id = dev_id;
    packet.sw_ver = sw_ver;
    packet.hw_ver = hw_ver;
    packet.dev_type = dev_type;
    mav_array_memcpy(packet.serial_number, serial_number, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_MODULE_VERSION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_MODULE_VERSION_MIN_LEN, MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN, MAVLINK_MSG_ID_WK_MODULE_VERSION_CRC);
}

/**
 * @brief Pack a wk_module_version message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dev_type  device type
 * @param dev_id  device id
 * @param sw_ver  software version format:1.3.01 ---> 1301
 * @param hw_ver  hardware version
 * @param serial_number  serial number 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_module_version_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t dev_type,uint32_t dev_id,uint32_t sw_ver,uint32_t hw_ver,const uint8_t *serial_number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN];
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint32_t(buf, 4, sw_ver);
    _mav_put_uint32_t(buf, 8, hw_ver);
    _mav_put_uint16_t(buf, 12, dev_type);
    _mav_put_uint8_t_array(buf, 14, serial_number, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN);
#else
    mavlink_wk_module_version_t packet;
    packet.dev_id = dev_id;
    packet.sw_ver = sw_ver;
    packet.hw_ver = hw_ver;
    packet.dev_type = dev_type;
    mav_array_memcpy(packet.serial_number, serial_number, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_MODULE_VERSION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_MODULE_VERSION_MIN_LEN, MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN, MAVLINK_MSG_ID_WK_MODULE_VERSION_CRC);
}

/**
 * @brief Encode a wk_module_version struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_module_version C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_module_version_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_module_version_t* wk_module_version)
{
    return mavlink_msg_wk_module_version_pack(system_id, component_id, msg, wk_module_version->dev_type, wk_module_version->dev_id, wk_module_version->sw_ver, wk_module_version->hw_ver, wk_module_version->serial_number);
}

/**
 * @brief Encode a wk_module_version struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_module_version C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_module_version_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_module_version_t* wk_module_version)
{
    return mavlink_msg_wk_module_version_pack_chan(system_id, component_id, chan, msg, wk_module_version->dev_type, wk_module_version->dev_id, wk_module_version->sw_ver, wk_module_version->hw_ver, wk_module_version->serial_number);
}

/**
 * @brief Send a wk_module_version message
 * @param chan MAVLink channel to send the message
 *
 * @param dev_type  device type
 * @param dev_id  device id
 * @param sw_ver  software version format:1.3.01 ---> 1301
 * @param hw_ver  hardware version
 * @param serial_number  serial number 
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_module_version_send(mavlink_channel_t chan, uint16_t dev_type, uint32_t dev_id, uint32_t sw_ver, uint32_t hw_ver, const uint8_t *serial_number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN];
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint32_t(buf, 4, sw_ver);
    _mav_put_uint32_t(buf, 8, hw_ver);
    _mav_put_uint16_t(buf, 12, dev_type);
    _mav_put_uint8_t_array(buf, 14, serial_number, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MODULE_VERSION, buf, MAVLINK_MSG_ID_WK_MODULE_VERSION_MIN_LEN, MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN, MAVLINK_MSG_ID_WK_MODULE_VERSION_CRC);
#else
    mavlink_wk_module_version_t packet;
    packet.dev_id = dev_id;
    packet.sw_ver = sw_ver;
    packet.hw_ver = hw_ver;
    packet.dev_type = dev_type;
    mav_array_memcpy(packet.serial_number, serial_number, sizeof(uint8_t)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MODULE_VERSION, (const char *)&packet, MAVLINK_MSG_ID_WK_MODULE_VERSION_MIN_LEN, MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN, MAVLINK_MSG_ID_WK_MODULE_VERSION_CRC);
#endif
}

/**
 * @brief Send a wk_module_version message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_module_version_send_struct(mavlink_channel_t chan, const mavlink_wk_module_version_t* wk_module_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_module_version_send(chan, wk_module_version->dev_type, wk_module_version->dev_id, wk_module_version->sw_ver, wk_module_version->hw_ver, wk_module_version->serial_number);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MODULE_VERSION, (const char *)wk_module_version, MAVLINK_MSG_ID_WK_MODULE_VERSION_MIN_LEN, MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN, MAVLINK_MSG_ID_WK_MODULE_VERSION_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_module_version_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t dev_type, uint32_t dev_id, uint32_t sw_ver, uint32_t hw_ver, const uint8_t *serial_number)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint32_t(buf, 4, sw_ver);
    _mav_put_uint32_t(buf, 8, hw_ver);
    _mav_put_uint16_t(buf, 12, dev_type);
    _mav_put_uint8_t_array(buf, 14, serial_number, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MODULE_VERSION, buf, MAVLINK_MSG_ID_WK_MODULE_VERSION_MIN_LEN, MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN, MAVLINK_MSG_ID_WK_MODULE_VERSION_CRC);
#else
    mavlink_wk_module_version_t *packet = (mavlink_wk_module_version_t *)msgbuf;
    packet->dev_id = dev_id;
    packet->sw_ver = sw_ver;
    packet->hw_ver = hw_ver;
    packet->dev_type = dev_type;
    mav_array_memcpy(packet->serial_number, serial_number, sizeof(uint8_t)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MODULE_VERSION, (const char *)packet, MAVLINK_MSG_ID_WK_MODULE_VERSION_MIN_LEN, MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN, MAVLINK_MSG_ID_WK_MODULE_VERSION_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_MODULE_VERSION UNPACKING


/**
 * @brief Get field dev_type from wk_module_version message
 *
 * @return  device type
 */
static inline uint16_t mavlink_msg_wk_module_version_get_dev_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field dev_id from wk_module_version message
 *
 * @return  device id
 */
static inline uint32_t mavlink_msg_wk_module_version_get_dev_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field sw_ver from wk_module_version message
 *
 * @return  software version format:1.3.01 ---> 1301
 */
static inline uint32_t mavlink_msg_wk_module_version_get_sw_ver(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field hw_ver from wk_module_version message
 *
 * @return  hardware version
 */
static inline uint32_t mavlink_msg_wk_module_version_get_hw_ver(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field serial_number from wk_module_version message
 *
 * @return  serial number 
 */
static inline uint16_t mavlink_msg_wk_module_version_get_serial_number(const mavlink_message_t* msg, uint8_t *serial_number)
{
    return _MAV_RETURN_uint8_t_array(msg, serial_number, 32,  14);
}

/**
 * @brief Decode a wk_module_version message into a struct
 *
 * @param msg The message to decode
 * @param wk_module_version C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_module_version_decode(const mavlink_message_t* msg, mavlink_wk_module_version_t* wk_module_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_module_version->dev_id = mavlink_msg_wk_module_version_get_dev_id(msg);
    wk_module_version->sw_ver = mavlink_msg_wk_module_version_get_sw_ver(msg);
    wk_module_version->hw_ver = mavlink_msg_wk_module_version_get_hw_ver(msg);
    wk_module_version->dev_type = mavlink_msg_wk_module_version_get_dev_type(msg);
    mavlink_msg_wk_module_version_get_serial_number(msg, wk_module_version->serial_number);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN? msg->len : MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN;
        memset(wk_module_version, 0, MAVLINK_MSG_ID_WK_MODULE_VERSION_LEN);
    memcpy(wk_module_version, _MAV_PAYLOAD(msg), len);
#endif
}
