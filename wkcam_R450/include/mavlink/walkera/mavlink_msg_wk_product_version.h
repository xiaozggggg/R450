#pragma once
// MESSAGE WK_PRODUCT_VERSION PACKING

#define MAVLINK_MSG_ID_WK_PRODUCT_VERSION 8002


typedef struct __mavlink_wk_product_version_t {
 uint32_t active_timestamps; /*<  active timestamps*/
 float version; /*<  product version*/
 float build_date; /*<  build date*/
 uint16_t product_type; /*<  product type*/
 uint16_t product_subtype; /*<  product subtype*/
 uint8_t product_id[16]; /*<  product id*/
 uint8_t activated; /*<  0:unactivated,1:activated*/
} mavlink_wk_product_version_t;

#define MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN 33
#define MAVLINK_MSG_ID_WK_PRODUCT_VERSION_MIN_LEN 33
#define MAVLINK_MSG_ID_8002_LEN 33
#define MAVLINK_MSG_ID_8002_MIN_LEN 33

#define MAVLINK_MSG_ID_WK_PRODUCT_VERSION_CRC 223
#define MAVLINK_MSG_ID_8002_CRC 223

#define MAVLINK_MSG_WK_PRODUCT_VERSION_FIELD_PRODUCT_ID_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_PRODUCT_VERSION { \
    8002, \
    "WK_PRODUCT_VERSION", \
    7, \
    {  { "active_timestamps", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_product_version_t, active_timestamps) }, \
         { "product_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_wk_product_version_t, product_type) }, \
         { "product_subtype", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_wk_product_version_t, product_subtype) }, \
         { "version", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_product_version_t, version) }, \
         { "build_date", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_product_version_t, build_date) }, \
         { "product_id", NULL, MAVLINK_TYPE_UINT8_T, 16, 16, offsetof(mavlink_wk_product_version_t, product_id) }, \
         { "activated", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_wk_product_version_t, activated) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_PRODUCT_VERSION { \
    "WK_PRODUCT_VERSION", \
    7, \
    {  { "active_timestamps", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_product_version_t, active_timestamps) }, \
         { "product_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_wk_product_version_t, product_type) }, \
         { "product_subtype", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_wk_product_version_t, product_subtype) }, \
         { "version", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_product_version_t, version) }, \
         { "build_date", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_product_version_t, build_date) }, \
         { "product_id", NULL, MAVLINK_TYPE_UINT8_T, 16, 16, offsetof(mavlink_wk_product_version_t, product_id) }, \
         { "activated", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_wk_product_version_t, activated) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_product_version message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param active_timestamps  active timestamps
 * @param product_type  product type
 * @param product_subtype  product subtype
 * @param version  product version
 * @param build_date  build date
 * @param product_id  product id
 * @param activated  0:unactivated,1:activated
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_product_version_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t active_timestamps, uint16_t product_type, uint16_t product_subtype, float version, float build_date, const uint8_t *product_id, uint8_t activated)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN];
    _mav_put_uint32_t(buf, 0, active_timestamps);
    _mav_put_float(buf, 4, version);
    _mav_put_float(buf, 8, build_date);
    _mav_put_uint16_t(buf, 12, product_type);
    _mav_put_uint16_t(buf, 14, product_subtype);
    _mav_put_uint8_t(buf, 32, activated);
    _mav_put_uint8_t_array(buf, 16, product_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN);
#else
    mavlink_wk_product_version_t packet;
    packet.active_timestamps = active_timestamps;
    packet.version = version;
    packet.build_date = build_date;
    packet.product_type = product_type;
    packet.product_subtype = product_subtype;
    packet.activated = activated;
    mav_array_memcpy(packet.product_id, product_id, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_PRODUCT_VERSION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_CRC);
}

/**
 * @brief Pack a wk_product_version message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param active_timestamps  active timestamps
 * @param product_type  product type
 * @param product_subtype  product subtype
 * @param version  product version
 * @param build_date  build date
 * @param product_id  product id
 * @param activated  0:unactivated,1:activated
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_product_version_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t active_timestamps,uint16_t product_type,uint16_t product_subtype,float version,float build_date,const uint8_t *product_id,uint8_t activated)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN];
    _mav_put_uint32_t(buf, 0, active_timestamps);
    _mav_put_float(buf, 4, version);
    _mav_put_float(buf, 8, build_date);
    _mav_put_uint16_t(buf, 12, product_type);
    _mav_put_uint16_t(buf, 14, product_subtype);
    _mav_put_uint8_t(buf, 32, activated);
    _mav_put_uint8_t_array(buf, 16, product_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN);
#else
    mavlink_wk_product_version_t packet;
    packet.active_timestamps = active_timestamps;
    packet.version = version;
    packet.build_date = build_date;
    packet.product_type = product_type;
    packet.product_subtype = product_subtype;
    packet.activated = activated;
    mav_array_memcpy(packet.product_id, product_id, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_PRODUCT_VERSION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_CRC);
}

/**
 * @brief Encode a wk_product_version struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_product_version C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_product_version_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_product_version_t* wk_product_version)
{
    return mavlink_msg_wk_product_version_pack(system_id, component_id, msg, wk_product_version->active_timestamps, wk_product_version->product_type, wk_product_version->product_subtype, wk_product_version->version, wk_product_version->build_date, wk_product_version->product_id, wk_product_version->activated);
}

/**
 * @brief Encode a wk_product_version struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_product_version C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_product_version_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_product_version_t* wk_product_version)
{
    return mavlink_msg_wk_product_version_pack_chan(system_id, component_id, chan, msg, wk_product_version->active_timestamps, wk_product_version->product_type, wk_product_version->product_subtype, wk_product_version->version, wk_product_version->build_date, wk_product_version->product_id, wk_product_version->activated);
}

/**
 * @brief Send a wk_product_version message
 * @param chan MAVLink channel to send the message
 *
 * @param active_timestamps  active timestamps
 * @param product_type  product type
 * @param product_subtype  product subtype
 * @param version  product version
 * @param build_date  build date
 * @param product_id  product id
 * @param activated  0:unactivated,1:activated
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_product_version_send(mavlink_channel_t chan, uint32_t active_timestamps, uint16_t product_type, uint16_t product_subtype, float version, float build_date, const uint8_t *product_id, uint8_t activated)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN];
    _mav_put_uint32_t(buf, 0, active_timestamps);
    _mav_put_float(buf, 4, version);
    _mav_put_float(buf, 8, build_date);
    _mav_put_uint16_t(buf, 12, product_type);
    _mav_put_uint16_t(buf, 14, product_subtype);
    _mav_put_uint8_t(buf, 32, activated);
    _mav_put_uint8_t_array(buf, 16, product_id, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_VERSION, buf, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_CRC);
#else
    mavlink_wk_product_version_t packet;
    packet.active_timestamps = active_timestamps;
    packet.version = version;
    packet.build_date = build_date;
    packet.product_type = product_type;
    packet.product_subtype = product_subtype;
    packet.activated = activated;
    mav_array_memcpy(packet.product_id, product_id, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_VERSION, (const char *)&packet, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_CRC);
#endif
}

/**
 * @brief Send a wk_product_version message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_product_version_send_struct(mavlink_channel_t chan, const mavlink_wk_product_version_t* wk_product_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_product_version_send(chan, wk_product_version->active_timestamps, wk_product_version->product_type, wk_product_version->product_subtype, wk_product_version->version, wk_product_version->build_date, wk_product_version->product_id, wk_product_version->activated);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_VERSION, (const char *)wk_product_version, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_product_version_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t active_timestamps, uint16_t product_type, uint16_t product_subtype, float version, float build_date, const uint8_t *product_id, uint8_t activated)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, active_timestamps);
    _mav_put_float(buf, 4, version);
    _mav_put_float(buf, 8, build_date);
    _mav_put_uint16_t(buf, 12, product_type);
    _mav_put_uint16_t(buf, 14, product_subtype);
    _mav_put_uint8_t(buf, 32, activated);
    _mav_put_uint8_t_array(buf, 16, product_id, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_VERSION, buf, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_CRC);
#else
    mavlink_wk_product_version_t *packet = (mavlink_wk_product_version_t *)msgbuf;
    packet->active_timestamps = active_timestamps;
    packet->version = version;
    packet->build_date = build_date;
    packet->product_type = product_type;
    packet->product_subtype = product_subtype;
    packet->activated = activated;
    mav_array_memcpy(packet->product_id, product_id, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PRODUCT_VERSION, (const char *)packet, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_MIN_LEN, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_PRODUCT_VERSION UNPACKING


/**
 * @brief Get field active_timestamps from wk_product_version message
 *
 * @return  active timestamps
 */
static inline uint32_t mavlink_msg_wk_product_version_get_active_timestamps(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field product_type from wk_product_version message
 *
 * @return  product type
 */
static inline uint16_t mavlink_msg_wk_product_version_get_product_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field product_subtype from wk_product_version message
 *
 * @return  product subtype
 */
static inline uint16_t mavlink_msg_wk_product_version_get_product_subtype(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field version from wk_product_version message
 *
 * @return  product version
 */
static inline float mavlink_msg_wk_product_version_get_version(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field build_date from wk_product_version message
 *
 * @return  build date
 */
static inline float mavlink_msg_wk_product_version_get_build_date(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field product_id from wk_product_version message
 *
 * @return  product id
 */
static inline uint16_t mavlink_msg_wk_product_version_get_product_id(const mavlink_message_t* msg, uint8_t *product_id)
{
    return _MAV_RETURN_uint8_t_array(msg, product_id, 16,  16);
}

/**
 * @brief Get field activated from wk_product_version message
 *
 * @return  0:unactivated,1:activated
 */
static inline uint8_t mavlink_msg_wk_product_version_get_activated(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Decode a wk_product_version message into a struct
 *
 * @param msg The message to decode
 * @param wk_product_version C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_product_version_decode(const mavlink_message_t* msg, mavlink_wk_product_version_t* wk_product_version)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_product_version->active_timestamps = mavlink_msg_wk_product_version_get_active_timestamps(msg);
    wk_product_version->version = mavlink_msg_wk_product_version_get_version(msg);
    wk_product_version->build_date = mavlink_msg_wk_product_version_get_build_date(msg);
    wk_product_version->product_type = mavlink_msg_wk_product_version_get_product_type(msg);
    wk_product_version->product_subtype = mavlink_msg_wk_product_version_get_product_subtype(msg);
    mavlink_msg_wk_product_version_get_product_id(msg, wk_product_version->product_id);
    wk_product_version->activated = mavlink_msg_wk_product_version_get_activated(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN? msg->len : MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN;
        memset(wk_product_version, 0, MAVLINK_MSG_ID_WK_PRODUCT_VERSION_LEN);
    memcpy(wk_product_version, _MAV_PAYLOAD(msg), len);
#endif
}
