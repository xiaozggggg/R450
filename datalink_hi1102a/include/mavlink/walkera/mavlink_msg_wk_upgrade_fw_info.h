#pragma once
// MESSAGE WK_UPGRADE_FW_INFO PACKING

#define MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO 8012


typedef struct __mavlink_wk_upgrade_fw_info_t {
 uint32_t dev_id; /*<  device id*/
 uint32_t sw_ver; /*<  software version*/
 uint32_t hw_ver; /*<  hardware version*/
 uint32_t length; /*<  firmware length*/
 uint32_t crc32; /*<  crc32 value*/
 uint32_t total_fragments; /*<  total fragment numbers*/
 uint16_t dev_type; /*<  device_type*/
} mavlink_wk_upgrade_fw_info_t;

#define MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN 26
#define MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_MIN_LEN 26
#define MAVLINK_MSG_ID_8012_LEN 26
#define MAVLINK_MSG_ID_8012_MIN_LEN 26

#define MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_CRC 220
#define MAVLINK_MSG_ID_8012_CRC 220



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_UPGRADE_FW_INFO { \
    8012, \
    "WK_UPGRADE_FW_INFO", \
    7, \
    {  { "dev_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_wk_upgrade_fw_info_t, dev_type) }, \
         { "dev_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_upgrade_fw_info_t, dev_id) }, \
         { "sw_ver", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_upgrade_fw_info_t, sw_ver) }, \
         { "hw_ver", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_upgrade_fw_info_t, hw_ver) }, \
         { "length", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_wk_upgrade_fw_info_t, length) }, \
         { "crc32", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_wk_upgrade_fw_info_t, crc32) }, \
         { "total_fragments", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_wk_upgrade_fw_info_t, total_fragments) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_UPGRADE_FW_INFO { \
    "WK_UPGRADE_FW_INFO", \
    7, \
    {  { "dev_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_wk_upgrade_fw_info_t, dev_type) }, \
         { "dev_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_upgrade_fw_info_t, dev_id) }, \
         { "sw_ver", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_upgrade_fw_info_t, sw_ver) }, \
         { "hw_ver", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_upgrade_fw_info_t, hw_ver) }, \
         { "length", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_wk_upgrade_fw_info_t, length) }, \
         { "crc32", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_wk_upgrade_fw_info_t, crc32) }, \
         { "total_fragments", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_wk_upgrade_fw_info_t, total_fragments) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_upgrade_fw_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param dev_type  device_type
 * @param dev_id  device id
 * @param sw_ver  software version
 * @param hw_ver  hardware version
 * @param length  firmware length
 * @param crc32  crc32 value
 * @param total_fragments  total fragment numbers
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_upgrade_fw_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t dev_type, uint32_t dev_id, uint32_t sw_ver, uint32_t hw_ver, uint32_t length, uint32_t crc32, uint32_t total_fragments)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN];
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint32_t(buf, 4, sw_ver);
    _mav_put_uint32_t(buf, 8, hw_ver);
    _mav_put_uint32_t(buf, 12, length);
    _mav_put_uint32_t(buf, 16, crc32);
    _mav_put_uint32_t(buf, 20, total_fragments);
    _mav_put_uint16_t(buf, 24, dev_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN);
#else
    mavlink_wk_upgrade_fw_info_t packet;
    packet.dev_id = dev_id;
    packet.sw_ver = sw_ver;
    packet.hw_ver = hw_ver;
    packet.length = length;
    packet.crc32 = crc32;
    packet.total_fragments = total_fragments;
    packet.dev_type = dev_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_CRC);
}

/**
 * @brief Pack a wk_upgrade_fw_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dev_type  device_type
 * @param dev_id  device id
 * @param sw_ver  software version
 * @param hw_ver  hardware version
 * @param length  firmware length
 * @param crc32  crc32 value
 * @param total_fragments  total fragment numbers
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_upgrade_fw_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t dev_type,uint32_t dev_id,uint32_t sw_ver,uint32_t hw_ver,uint32_t length,uint32_t crc32,uint32_t total_fragments)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN];
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint32_t(buf, 4, sw_ver);
    _mav_put_uint32_t(buf, 8, hw_ver);
    _mav_put_uint32_t(buf, 12, length);
    _mav_put_uint32_t(buf, 16, crc32);
    _mav_put_uint32_t(buf, 20, total_fragments);
    _mav_put_uint16_t(buf, 24, dev_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN);
#else
    mavlink_wk_upgrade_fw_info_t packet;
    packet.dev_id = dev_id;
    packet.sw_ver = sw_ver;
    packet.hw_ver = hw_ver;
    packet.length = length;
    packet.crc32 = crc32;
    packet.total_fragments = total_fragments;
    packet.dev_type = dev_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_CRC);
}

/**
 * @brief Encode a wk_upgrade_fw_info struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_upgrade_fw_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_upgrade_fw_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_upgrade_fw_info_t* wk_upgrade_fw_info)
{
    return mavlink_msg_wk_upgrade_fw_info_pack(system_id, component_id, msg, wk_upgrade_fw_info->dev_type, wk_upgrade_fw_info->dev_id, wk_upgrade_fw_info->sw_ver, wk_upgrade_fw_info->hw_ver, wk_upgrade_fw_info->length, wk_upgrade_fw_info->crc32, wk_upgrade_fw_info->total_fragments);
}

/**
 * @brief Encode a wk_upgrade_fw_info struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_upgrade_fw_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_upgrade_fw_info_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_upgrade_fw_info_t* wk_upgrade_fw_info)
{
    return mavlink_msg_wk_upgrade_fw_info_pack_chan(system_id, component_id, chan, msg, wk_upgrade_fw_info->dev_type, wk_upgrade_fw_info->dev_id, wk_upgrade_fw_info->sw_ver, wk_upgrade_fw_info->hw_ver, wk_upgrade_fw_info->length, wk_upgrade_fw_info->crc32, wk_upgrade_fw_info->total_fragments);
}

/**
 * @brief Send a wk_upgrade_fw_info message
 * @param chan MAVLink channel to send the message
 *
 * @param dev_type  device_type
 * @param dev_id  device id
 * @param sw_ver  software version
 * @param hw_ver  hardware version
 * @param length  firmware length
 * @param crc32  crc32 value
 * @param total_fragments  total fragment numbers
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_upgrade_fw_info_send(mavlink_channel_t chan, uint16_t dev_type, uint32_t dev_id, uint32_t sw_ver, uint32_t hw_ver, uint32_t length, uint32_t crc32, uint32_t total_fragments)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN];
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint32_t(buf, 4, sw_ver);
    _mav_put_uint32_t(buf, 8, hw_ver);
    _mav_put_uint32_t(buf, 12, length);
    _mav_put_uint32_t(buf, 16, crc32);
    _mav_put_uint32_t(buf, 20, total_fragments);
    _mav_put_uint16_t(buf, 24, dev_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO, buf, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_CRC);
#else
    mavlink_wk_upgrade_fw_info_t packet;
    packet.dev_id = dev_id;
    packet.sw_ver = sw_ver;
    packet.hw_ver = hw_ver;
    packet.length = length;
    packet.crc32 = crc32;
    packet.total_fragments = total_fragments;
    packet.dev_type = dev_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO, (const char *)&packet, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_CRC);
#endif
}

/**
 * @brief Send a wk_upgrade_fw_info message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_upgrade_fw_info_send_struct(mavlink_channel_t chan, const mavlink_wk_upgrade_fw_info_t* wk_upgrade_fw_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_upgrade_fw_info_send(chan, wk_upgrade_fw_info->dev_type, wk_upgrade_fw_info->dev_id, wk_upgrade_fw_info->sw_ver, wk_upgrade_fw_info->hw_ver, wk_upgrade_fw_info->length, wk_upgrade_fw_info->crc32, wk_upgrade_fw_info->total_fragments);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO, (const char *)wk_upgrade_fw_info, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_upgrade_fw_info_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t dev_type, uint32_t dev_id, uint32_t sw_ver, uint32_t hw_ver, uint32_t length, uint32_t crc32, uint32_t total_fragments)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, dev_id);
    _mav_put_uint32_t(buf, 4, sw_ver);
    _mav_put_uint32_t(buf, 8, hw_ver);
    _mav_put_uint32_t(buf, 12, length);
    _mav_put_uint32_t(buf, 16, crc32);
    _mav_put_uint32_t(buf, 20, total_fragments);
    _mav_put_uint16_t(buf, 24, dev_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO, buf, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_CRC);
#else
    mavlink_wk_upgrade_fw_info_t *packet = (mavlink_wk_upgrade_fw_info_t *)msgbuf;
    packet->dev_id = dev_id;
    packet->sw_ver = sw_ver;
    packet->hw_ver = hw_ver;
    packet->length = length;
    packet->crc32 = crc32;
    packet->total_fragments = total_fragments;
    packet->dev_type = dev_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO, (const char *)packet, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_MIN_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_UPGRADE_FW_INFO UNPACKING


/**
 * @brief Get field dev_type from wk_upgrade_fw_info message
 *
 * @return  device_type
 */
static inline uint16_t mavlink_msg_wk_upgrade_fw_info_get_dev_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field dev_id from wk_upgrade_fw_info message
 *
 * @return  device id
 */
static inline uint32_t mavlink_msg_wk_upgrade_fw_info_get_dev_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field sw_ver from wk_upgrade_fw_info message
 *
 * @return  software version
 */
static inline uint32_t mavlink_msg_wk_upgrade_fw_info_get_sw_ver(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field hw_ver from wk_upgrade_fw_info message
 *
 * @return  hardware version
 */
static inline uint32_t mavlink_msg_wk_upgrade_fw_info_get_hw_ver(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field length from wk_upgrade_fw_info message
 *
 * @return  firmware length
 */
static inline uint32_t mavlink_msg_wk_upgrade_fw_info_get_length(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field crc32 from wk_upgrade_fw_info message
 *
 * @return  crc32 value
 */
static inline uint32_t mavlink_msg_wk_upgrade_fw_info_get_crc32(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field total_fragments from wk_upgrade_fw_info message
 *
 * @return  total fragment numbers
 */
static inline uint32_t mavlink_msg_wk_upgrade_fw_info_get_total_fragments(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Decode a wk_upgrade_fw_info message into a struct
 *
 * @param msg The message to decode
 * @param wk_upgrade_fw_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_upgrade_fw_info_decode(const mavlink_message_t* msg, mavlink_wk_upgrade_fw_info_t* wk_upgrade_fw_info)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_upgrade_fw_info->dev_id = mavlink_msg_wk_upgrade_fw_info_get_dev_id(msg);
    wk_upgrade_fw_info->sw_ver = mavlink_msg_wk_upgrade_fw_info_get_sw_ver(msg);
    wk_upgrade_fw_info->hw_ver = mavlink_msg_wk_upgrade_fw_info_get_hw_ver(msg);
    wk_upgrade_fw_info->length = mavlink_msg_wk_upgrade_fw_info_get_length(msg);
    wk_upgrade_fw_info->crc32 = mavlink_msg_wk_upgrade_fw_info_get_crc32(msg);
    wk_upgrade_fw_info->total_fragments = mavlink_msg_wk_upgrade_fw_info_get_total_fragments(msg);
    wk_upgrade_fw_info->dev_type = mavlink_msg_wk_upgrade_fw_info_get_dev_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN? msg->len : MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN;
        memset(wk_upgrade_fw_info, 0, MAVLINK_MSG_ID_WK_UPGRADE_FW_INFO_LEN);
    memcpy(wk_upgrade_fw_info, _MAV_PAYLOAD(msg), len);
#endif
}
