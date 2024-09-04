#pragma once
// MESSAGE WK_MINI_4G_AUTHENTICATION PACKING

#define MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION 8304


typedef struct __mavlink_wk_mini_4g_authentication_t {
 uint8_t type; /*<  */
 uint8_t id_length; /*<  */
 uint8_t sn_id[32]; /*<  */
 uint8_t password[8]; /*<  */
 uint8_t user_id[32]; /*<  */
 uint8_t md5_chk[32]; /*<  */
 uint8_t url_length; /*<  */
 uint8_t video_url[100]; /*<  */
} mavlink_wk_mini_4g_authentication_t;

#define MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN 207
#define MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_MIN_LEN 207
#define MAVLINK_MSG_ID_8304_LEN 207
#define MAVLINK_MSG_ID_8304_MIN_LEN 207

#define MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_CRC 17
#define MAVLINK_MSG_ID_8304_CRC 17

#define MAVLINK_MSG_WK_MINI_4G_AUTHENTICATION_FIELD_SN_ID_LEN 32
#define MAVLINK_MSG_WK_MINI_4G_AUTHENTICATION_FIELD_PASSWORD_LEN 8
#define MAVLINK_MSG_WK_MINI_4G_AUTHENTICATION_FIELD_USER_ID_LEN 32
#define MAVLINK_MSG_WK_MINI_4G_AUTHENTICATION_FIELD_MD5_CHK_LEN 32
#define MAVLINK_MSG_WK_MINI_4G_AUTHENTICATION_FIELD_VIDEO_URL_LEN 100

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_MINI_4G_AUTHENTICATION { \
    8304, \
    "WK_MINI_4G_AUTHENTICATION", \
    8, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_mini_4g_authentication_t, type) }, \
         { "id_length", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_mini_4g_authentication_t, id_length) }, \
         { "sn_id", NULL, MAVLINK_TYPE_UINT8_T, 32, 2, offsetof(mavlink_wk_mini_4g_authentication_t, sn_id) }, \
         { "password", NULL, MAVLINK_TYPE_UINT8_T, 8, 34, offsetof(mavlink_wk_mini_4g_authentication_t, password) }, \
         { "user_id", NULL, MAVLINK_TYPE_UINT8_T, 32, 42, offsetof(mavlink_wk_mini_4g_authentication_t, user_id) }, \
         { "md5_chk", NULL, MAVLINK_TYPE_UINT8_T, 32, 74, offsetof(mavlink_wk_mini_4g_authentication_t, md5_chk) }, \
         { "url_length", NULL, MAVLINK_TYPE_UINT8_T, 0, 106, offsetof(mavlink_wk_mini_4g_authentication_t, url_length) }, \
         { "video_url", NULL, MAVLINK_TYPE_UINT8_T, 100, 107, offsetof(mavlink_wk_mini_4g_authentication_t, video_url) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_MINI_4G_AUTHENTICATION { \
    "WK_MINI_4G_AUTHENTICATION", \
    8, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_mini_4g_authentication_t, type) }, \
         { "id_length", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_mini_4g_authentication_t, id_length) }, \
         { "sn_id", NULL, MAVLINK_TYPE_UINT8_T, 32, 2, offsetof(mavlink_wk_mini_4g_authentication_t, sn_id) }, \
         { "password", NULL, MAVLINK_TYPE_UINT8_T, 8, 34, offsetof(mavlink_wk_mini_4g_authentication_t, password) }, \
         { "user_id", NULL, MAVLINK_TYPE_UINT8_T, 32, 42, offsetof(mavlink_wk_mini_4g_authentication_t, user_id) }, \
         { "md5_chk", NULL, MAVLINK_TYPE_UINT8_T, 32, 74, offsetof(mavlink_wk_mini_4g_authentication_t, md5_chk) }, \
         { "url_length", NULL, MAVLINK_TYPE_UINT8_T, 0, 106, offsetof(mavlink_wk_mini_4g_authentication_t, url_length) }, \
         { "video_url", NULL, MAVLINK_TYPE_UINT8_T, 100, 107, offsetof(mavlink_wk_mini_4g_authentication_t, video_url) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_mini_4g_authentication message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type  
 * @param id_length  
 * @param sn_id  
 * @param password  
 * @param user_id  
 * @param md5_chk  
 * @param url_length  
 * @param video_url  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_mini_4g_authentication_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t type, uint8_t id_length, const uint8_t *sn_id, const uint8_t *password, const uint8_t *user_id, const uint8_t *md5_chk, uint8_t url_length, const uint8_t *video_url)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, id_length);
    _mav_put_uint8_t(buf, 106, url_length);
    _mav_put_uint8_t_array(buf, 2, sn_id, 32);
    _mav_put_uint8_t_array(buf, 34, password, 8);
    _mav_put_uint8_t_array(buf, 42, user_id, 32);
    _mav_put_uint8_t_array(buf, 74, md5_chk, 32);
    _mav_put_uint8_t_array(buf, 107, video_url, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN);
#else
    mavlink_wk_mini_4g_authentication_t packet;
    packet.type = type;
    packet.id_length = id_length;
    packet.url_length = url_length;
    mav_array_memcpy(packet.sn_id, sn_id, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.password, password, sizeof(uint8_t)*8);
    mav_array_memcpy(packet.user_id, user_id, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.md5_chk, md5_chk, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.video_url, video_url, sizeof(uint8_t)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_MIN_LEN, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_CRC);
}

/**
 * @brief Pack a wk_mini_4g_authentication message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type  
 * @param id_length  
 * @param sn_id  
 * @param password  
 * @param user_id  
 * @param md5_chk  
 * @param url_length  
 * @param video_url  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_mini_4g_authentication_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t type,uint8_t id_length,const uint8_t *sn_id,const uint8_t *password,const uint8_t *user_id,const uint8_t *md5_chk,uint8_t url_length,const uint8_t *video_url)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, id_length);
    _mav_put_uint8_t(buf, 106, url_length);
    _mav_put_uint8_t_array(buf, 2, sn_id, 32);
    _mav_put_uint8_t_array(buf, 34, password, 8);
    _mav_put_uint8_t_array(buf, 42, user_id, 32);
    _mav_put_uint8_t_array(buf, 74, md5_chk, 32);
    _mav_put_uint8_t_array(buf, 107, video_url, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN);
#else
    mavlink_wk_mini_4g_authentication_t packet;
    packet.type = type;
    packet.id_length = id_length;
    packet.url_length = url_length;
    mav_array_memcpy(packet.sn_id, sn_id, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.password, password, sizeof(uint8_t)*8);
    mav_array_memcpy(packet.user_id, user_id, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.md5_chk, md5_chk, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.video_url, video_url, sizeof(uint8_t)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_MIN_LEN, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_CRC);
}

/**
 * @brief Encode a wk_mini_4g_authentication struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_mini_4g_authentication C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_mini_4g_authentication_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_mini_4g_authentication_t* wk_mini_4g_authentication)
{
    return mavlink_msg_wk_mini_4g_authentication_pack(system_id, component_id, msg, wk_mini_4g_authentication->type, wk_mini_4g_authentication->id_length, wk_mini_4g_authentication->sn_id, wk_mini_4g_authentication->password, wk_mini_4g_authentication->user_id, wk_mini_4g_authentication->md5_chk, wk_mini_4g_authentication->url_length, wk_mini_4g_authentication->video_url);
}

/**
 * @brief Encode a wk_mini_4g_authentication struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_mini_4g_authentication C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_mini_4g_authentication_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_mini_4g_authentication_t* wk_mini_4g_authentication)
{
    return mavlink_msg_wk_mini_4g_authentication_pack_chan(system_id, component_id, chan, msg, wk_mini_4g_authentication->type, wk_mini_4g_authentication->id_length, wk_mini_4g_authentication->sn_id, wk_mini_4g_authentication->password, wk_mini_4g_authentication->user_id, wk_mini_4g_authentication->md5_chk, wk_mini_4g_authentication->url_length, wk_mini_4g_authentication->video_url);
}

/**
 * @brief Send a wk_mini_4g_authentication message
 * @param chan MAVLink channel to send the message
 *
 * @param type  
 * @param id_length  
 * @param sn_id  
 * @param password  
 * @param user_id  
 * @param md5_chk  
 * @param url_length  
 * @param video_url  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_mini_4g_authentication_send(mavlink_channel_t chan, uint8_t type, uint8_t id_length, const uint8_t *sn_id, const uint8_t *password, const uint8_t *user_id, const uint8_t *md5_chk, uint8_t url_length, const uint8_t *video_url)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, id_length);
    _mav_put_uint8_t(buf, 106, url_length);
    _mav_put_uint8_t_array(buf, 2, sn_id, 32);
    _mav_put_uint8_t_array(buf, 34, password, 8);
    _mav_put_uint8_t_array(buf, 42, user_id, 32);
    _mav_put_uint8_t_array(buf, 74, md5_chk, 32);
    _mav_put_uint8_t_array(buf, 107, video_url, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION, buf, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_MIN_LEN, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_CRC);
#else
    mavlink_wk_mini_4g_authentication_t packet;
    packet.type = type;
    packet.id_length = id_length;
    packet.url_length = url_length;
    mav_array_memcpy(packet.sn_id, sn_id, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.password, password, sizeof(uint8_t)*8);
    mav_array_memcpy(packet.user_id, user_id, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.md5_chk, md5_chk, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.video_url, video_url, sizeof(uint8_t)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION, (const char *)&packet, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_MIN_LEN, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_CRC);
#endif
}

/**
 * @brief Send a wk_mini_4g_authentication message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_mini_4g_authentication_send_struct(mavlink_channel_t chan, const mavlink_wk_mini_4g_authentication_t* wk_mini_4g_authentication)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_mini_4g_authentication_send(chan, wk_mini_4g_authentication->type, wk_mini_4g_authentication->id_length, wk_mini_4g_authentication->sn_id, wk_mini_4g_authentication->password, wk_mini_4g_authentication->user_id, wk_mini_4g_authentication->md5_chk, wk_mini_4g_authentication->url_length, wk_mini_4g_authentication->video_url);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION, (const char *)wk_mini_4g_authentication, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_MIN_LEN, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_mini_4g_authentication_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t type, uint8_t id_length, const uint8_t *sn_id, const uint8_t *password, const uint8_t *user_id, const uint8_t *md5_chk, uint8_t url_length, const uint8_t *video_url)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, id_length);
    _mav_put_uint8_t(buf, 106, url_length);
    _mav_put_uint8_t_array(buf, 2, sn_id, 32);
    _mav_put_uint8_t_array(buf, 34, password, 8);
    _mav_put_uint8_t_array(buf, 42, user_id, 32);
    _mav_put_uint8_t_array(buf, 74, md5_chk, 32);
    _mav_put_uint8_t_array(buf, 107, video_url, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION, buf, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_MIN_LEN, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_CRC);
#else
    mavlink_wk_mini_4g_authentication_t *packet = (mavlink_wk_mini_4g_authentication_t *)msgbuf;
    packet->type = type;
    packet->id_length = id_length;
    packet->url_length = url_length;
    mav_array_memcpy(packet->sn_id, sn_id, sizeof(uint8_t)*32);
    mav_array_memcpy(packet->password, password, sizeof(uint8_t)*8);
    mav_array_memcpy(packet->user_id, user_id, sizeof(uint8_t)*32);
    mav_array_memcpy(packet->md5_chk, md5_chk, sizeof(uint8_t)*32);
    mav_array_memcpy(packet->video_url, video_url, sizeof(uint8_t)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION, (const char *)packet, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_MIN_LEN, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_MINI_4G_AUTHENTICATION UNPACKING


/**
 * @brief Get field type from wk_mini_4g_authentication message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_mini_4g_authentication_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field id_length from wk_mini_4g_authentication message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_mini_4g_authentication_get_id_length(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field sn_id from wk_mini_4g_authentication message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_mini_4g_authentication_get_sn_id(const mavlink_message_t* msg, uint8_t *sn_id)
{
    return _MAV_RETURN_uint8_t_array(msg, sn_id, 32,  2);
}

/**
 * @brief Get field password from wk_mini_4g_authentication message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_mini_4g_authentication_get_password(const mavlink_message_t* msg, uint8_t *password)
{
    return _MAV_RETURN_uint8_t_array(msg, password, 8,  34);
}

/**
 * @brief Get field user_id from wk_mini_4g_authentication message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_mini_4g_authentication_get_user_id(const mavlink_message_t* msg, uint8_t *user_id)
{
    return _MAV_RETURN_uint8_t_array(msg, user_id, 32,  42);
}

/**
 * @brief Get field md5_chk from wk_mini_4g_authentication message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_mini_4g_authentication_get_md5_chk(const mavlink_message_t* msg, uint8_t *md5_chk)
{
    return _MAV_RETURN_uint8_t_array(msg, md5_chk, 32,  74);
}

/**
 * @brief Get field url_length from wk_mini_4g_authentication message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_mini_4g_authentication_get_url_length(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  106);
}

/**
 * @brief Get field video_url from wk_mini_4g_authentication message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_mini_4g_authentication_get_video_url(const mavlink_message_t* msg, uint8_t *video_url)
{
    return _MAV_RETURN_uint8_t_array(msg, video_url, 100,  107);
}

/**
 * @brief Decode a wk_mini_4g_authentication message into a struct
 *
 * @param msg The message to decode
 * @param wk_mini_4g_authentication C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_mini_4g_authentication_decode(const mavlink_message_t* msg, mavlink_wk_mini_4g_authentication_t* wk_mini_4g_authentication)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_mini_4g_authentication->type = mavlink_msg_wk_mini_4g_authentication_get_type(msg);
    wk_mini_4g_authentication->id_length = mavlink_msg_wk_mini_4g_authentication_get_id_length(msg);
    mavlink_msg_wk_mini_4g_authentication_get_sn_id(msg, wk_mini_4g_authentication->sn_id);
    mavlink_msg_wk_mini_4g_authentication_get_password(msg, wk_mini_4g_authentication->password);
    mavlink_msg_wk_mini_4g_authentication_get_user_id(msg, wk_mini_4g_authentication->user_id);
    mavlink_msg_wk_mini_4g_authentication_get_md5_chk(msg, wk_mini_4g_authentication->md5_chk);
    wk_mini_4g_authentication->url_length = mavlink_msg_wk_mini_4g_authentication_get_url_length(msg);
    mavlink_msg_wk_mini_4g_authentication_get_video_url(msg, wk_mini_4g_authentication->video_url);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN? msg->len : MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN;
        memset(wk_mini_4g_authentication, 0, MAVLINK_MSG_ID_WK_MINI_4G_AUTHENTICATION_LEN);
    memcpy(wk_mini_4g_authentication, _MAV_PAYLOAD(msg), len);
#endif
}
