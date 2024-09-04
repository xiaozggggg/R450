#pragma once
// MESSAGE NTRIP_CONFIG PACKING

#define MAVLINK_MSG_ID_NTRIP_CONFIG 8000


typedef struct __mavlink_ntrip_config_t {
 uint16_t port; /*<  ntrip server port*/
 char url[64]; /*<  ntrip server url*/
 char mount_point[32]; /*<  ntrip server mountpoint*/
 char user[32]; /*<  user name*/
 char password[32]; /*<  password*/
} mavlink_ntrip_config_t;

#define MAVLINK_MSG_ID_NTRIP_CONFIG_LEN 162
#define MAVLINK_MSG_ID_NTRIP_CONFIG_MIN_LEN 162
#define MAVLINK_MSG_ID_8000_LEN 162
#define MAVLINK_MSG_ID_8000_MIN_LEN 162

#define MAVLINK_MSG_ID_NTRIP_CONFIG_CRC 248
#define MAVLINK_MSG_ID_8000_CRC 248

#define MAVLINK_MSG_NTRIP_CONFIG_FIELD_URL_LEN 64
#define MAVLINK_MSG_NTRIP_CONFIG_FIELD_MOUNT_POINT_LEN 32
#define MAVLINK_MSG_NTRIP_CONFIG_FIELD_USER_LEN 32
#define MAVLINK_MSG_NTRIP_CONFIG_FIELD_PASSWORD_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_NTRIP_CONFIG { \
    8000, \
    "NTRIP_CONFIG", \
    5, \
    {  { "url", NULL, MAVLINK_TYPE_CHAR, 64, 2, offsetof(mavlink_ntrip_config_t, url) }, \
         { "port", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_ntrip_config_t, port) }, \
         { "mount_point", NULL, MAVLINK_TYPE_CHAR, 32, 66, offsetof(mavlink_ntrip_config_t, mount_point) }, \
         { "user", NULL, MAVLINK_TYPE_CHAR, 32, 98, offsetof(mavlink_ntrip_config_t, user) }, \
         { "password", NULL, MAVLINK_TYPE_CHAR, 32, 130, offsetof(mavlink_ntrip_config_t, password) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_NTRIP_CONFIG { \
    "NTRIP_CONFIG", \
    5, \
    {  { "url", NULL, MAVLINK_TYPE_CHAR, 64, 2, offsetof(mavlink_ntrip_config_t, url) }, \
         { "port", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_ntrip_config_t, port) }, \
         { "mount_point", NULL, MAVLINK_TYPE_CHAR, 32, 66, offsetof(mavlink_ntrip_config_t, mount_point) }, \
         { "user", NULL, MAVLINK_TYPE_CHAR, 32, 98, offsetof(mavlink_ntrip_config_t, user) }, \
         { "password", NULL, MAVLINK_TYPE_CHAR, 32, 130, offsetof(mavlink_ntrip_config_t, password) }, \
         } \
}
#endif

/**
 * @brief Pack a ntrip_config message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param url  ntrip server url
 * @param port  ntrip server port
 * @param mount_point  ntrip server mountpoint
 * @param user  user name
 * @param password  password
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ntrip_config_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *url, uint16_t port, const char *mount_point, const char *user, const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NTRIP_CONFIG_LEN];
    _mav_put_uint16_t(buf, 0, port);
    _mav_put_char_array(buf, 2, url, 64);
    _mav_put_char_array(buf, 66, mount_point, 32);
    _mav_put_char_array(buf, 98, user, 32);
    _mav_put_char_array(buf, 130, password, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NTRIP_CONFIG_LEN);
#else
    mavlink_ntrip_config_t packet;
    packet.port = port;
    mav_array_memcpy(packet.url, url, sizeof(char)*64);
    mav_array_memcpy(packet.mount_point, mount_point, sizeof(char)*32);
    mav_array_memcpy(packet.user, user, sizeof(char)*32);
    mav_array_memcpy(packet.password, password, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NTRIP_CONFIG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_NTRIP_CONFIG;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_NTRIP_CONFIG_MIN_LEN, MAVLINK_MSG_ID_NTRIP_CONFIG_LEN, MAVLINK_MSG_ID_NTRIP_CONFIG_CRC);
}

/**
 * @brief Pack a ntrip_config message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param url  ntrip server url
 * @param port  ntrip server port
 * @param mount_point  ntrip server mountpoint
 * @param user  user name
 * @param password  password
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ntrip_config_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *url,uint16_t port,const char *mount_point,const char *user,const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NTRIP_CONFIG_LEN];
    _mav_put_uint16_t(buf, 0, port);
    _mav_put_char_array(buf, 2, url, 64);
    _mav_put_char_array(buf, 66, mount_point, 32);
    _mav_put_char_array(buf, 98, user, 32);
    _mav_put_char_array(buf, 130, password, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NTRIP_CONFIG_LEN);
#else
    mavlink_ntrip_config_t packet;
    packet.port = port;
    mav_array_memcpy(packet.url, url, sizeof(char)*64);
    mav_array_memcpy(packet.mount_point, mount_point, sizeof(char)*32);
    mav_array_memcpy(packet.user, user, sizeof(char)*32);
    mav_array_memcpy(packet.password, password, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NTRIP_CONFIG_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_NTRIP_CONFIG;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_NTRIP_CONFIG_MIN_LEN, MAVLINK_MSG_ID_NTRIP_CONFIG_LEN, MAVLINK_MSG_ID_NTRIP_CONFIG_CRC);
}

/**
 * @brief Encode a ntrip_config struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ntrip_config C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ntrip_config_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ntrip_config_t* ntrip_config)
{
    return mavlink_msg_ntrip_config_pack(system_id, component_id, msg, ntrip_config->url, ntrip_config->port, ntrip_config->mount_point, ntrip_config->user, ntrip_config->password);
}

/**
 * @brief Encode a ntrip_config struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ntrip_config C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ntrip_config_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ntrip_config_t* ntrip_config)
{
    return mavlink_msg_ntrip_config_pack_chan(system_id, component_id, chan, msg, ntrip_config->url, ntrip_config->port, ntrip_config->mount_point, ntrip_config->user, ntrip_config->password);
}

/**
 * @brief Send a ntrip_config message
 * @param chan MAVLink channel to send the message
 *
 * @param url  ntrip server url
 * @param port  ntrip server port
 * @param mount_point  ntrip server mountpoint
 * @param user  user name
 * @param password  password
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ntrip_config_send(mavlink_channel_t chan, const char *url, uint16_t port, const char *mount_point, const char *user, const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NTRIP_CONFIG_LEN];
    _mav_put_uint16_t(buf, 0, port);
    _mav_put_char_array(buf, 2, url, 64);
    _mav_put_char_array(buf, 66, mount_point, 32);
    _mav_put_char_array(buf, 98, user, 32);
    _mav_put_char_array(buf, 130, password, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NTRIP_CONFIG, buf, MAVLINK_MSG_ID_NTRIP_CONFIG_MIN_LEN, MAVLINK_MSG_ID_NTRIP_CONFIG_LEN, MAVLINK_MSG_ID_NTRIP_CONFIG_CRC);
#else
    mavlink_ntrip_config_t packet;
    packet.port = port;
    mav_array_memcpy(packet.url, url, sizeof(char)*64);
    mav_array_memcpy(packet.mount_point, mount_point, sizeof(char)*32);
    mav_array_memcpy(packet.user, user, sizeof(char)*32);
    mav_array_memcpy(packet.password, password, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NTRIP_CONFIG, (const char *)&packet, MAVLINK_MSG_ID_NTRIP_CONFIG_MIN_LEN, MAVLINK_MSG_ID_NTRIP_CONFIG_LEN, MAVLINK_MSG_ID_NTRIP_CONFIG_CRC);
#endif
}

/**
 * @brief Send a ntrip_config message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ntrip_config_send_struct(mavlink_channel_t chan, const mavlink_ntrip_config_t* ntrip_config)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ntrip_config_send(chan, ntrip_config->url, ntrip_config->port, ntrip_config->mount_point, ntrip_config->user, ntrip_config->password);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NTRIP_CONFIG, (const char *)ntrip_config, MAVLINK_MSG_ID_NTRIP_CONFIG_MIN_LEN, MAVLINK_MSG_ID_NTRIP_CONFIG_LEN, MAVLINK_MSG_ID_NTRIP_CONFIG_CRC);
#endif
}

#if MAVLINK_MSG_ID_NTRIP_CONFIG_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ntrip_config_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *url, uint16_t port, const char *mount_point, const char *user, const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, port);
    _mav_put_char_array(buf, 2, url, 64);
    _mav_put_char_array(buf, 66, mount_point, 32);
    _mav_put_char_array(buf, 98, user, 32);
    _mav_put_char_array(buf, 130, password, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NTRIP_CONFIG, buf, MAVLINK_MSG_ID_NTRIP_CONFIG_MIN_LEN, MAVLINK_MSG_ID_NTRIP_CONFIG_LEN, MAVLINK_MSG_ID_NTRIP_CONFIG_CRC);
#else
    mavlink_ntrip_config_t *packet = (mavlink_ntrip_config_t *)msgbuf;
    packet->port = port;
    mav_array_memcpy(packet->url, url, sizeof(char)*64);
    mav_array_memcpy(packet->mount_point, mount_point, sizeof(char)*32);
    mav_array_memcpy(packet->user, user, sizeof(char)*32);
    mav_array_memcpy(packet->password, password, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NTRIP_CONFIG, (const char *)packet, MAVLINK_MSG_ID_NTRIP_CONFIG_MIN_LEN, MAVLINK_MSG_ID_NTRIP_CONFIG_LEN, MAVLINK_MSG_ID_NTRIP_CONFIG_CRC);
#endif
}
#endif

#endif

// MESSAGE NTRIP_CONFIG UNPACKING


/**
 * @brief Get field url from ntrip_config message
 *
 * @return  ntrip server url
 */
static inline uint16_t mavlink_msg_ntrip_config_get_url(const mavlink_message_t* msg, char *url)
{
    return _MAV_RETURN_char_array(msg, url, 64,  2);
}

/**
 * @brief Get field port from ntrip_config message
 *
 * @return  ntrip server port
 */
static inline uint16_t mavlink_msg_ntrip_config_get_port(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field mount_point from ntrip_config message
 *
 * @return  ntrip server mountpoint
 */
static inline uint16_t mavlink_msg_ntrip_config_get_mount_point(const mavlink_message_t* msg, char *mount_point)
{
    return _MAV_RETURN_char_array(msg, mount_point, 32,  66);
}

/**
 * @brief Get field user from ntrip_config message
 *
 * @return  user name
 */
static inline uint16_t mavlink_msg_ntrip_config_get_user(const mavlink_message_t* msg, char *user)
{
    return _MAV_RETURN_char_array(msg, user, 32,  98);
}

/**
 * @brief Get field password from ntrip_config message
 *
 * @return  password
 */
static inline uint16_t mavlink_msg_ntrip_config_get_password(const mavlink_message_t* msg, char *password)
{
    return _MAV_RETURN_char_array(msg, password, 32,  130);
}

/**
 * @brief Decode a ntrip_config message into a struct
 *
 * @param msg The message to decode
 * @param ntrip_config C-struct to decode the message contents into
 */
static inline void mavlink_msg_ntrip_config_decode(const mavlink_message_t* msg, mavlink_ntrip_config_t* ntrip_config)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ntrip_config->port = mavlink_msg_ntrip_config_get_port(msg);
    mavlink_msg_ntrip_config_get_url(msg, ntrip_config->url);
    mavlink_msg_ntrip_config_get_mount_point(msg, ntrip_config->mount_point);
    mavlink_msg_ntrip_config_get_user(msg, ntrip_config->user);
    mavlink_msg_ntrip_config_get_password(msg, ntrip_config->password);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_NTRIP_CONFIG_LEN? msg->len : MAVLINK_MSG_ID_NTRIP_CONFIG_LEN;
        memset(ntrip_config, 0, MAVLINK_MSG_ID_NTRIP_CONFIG_LEN);
    memcpy(ntrip_config, _MAV_PAYLOAD(msg), len);
#endif
}
