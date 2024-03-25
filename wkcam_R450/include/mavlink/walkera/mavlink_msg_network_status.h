#pragma once
// MESSAGE NETWORK_STATUS PACKING

#define MAVLINK_MSG_ID_NETWORK_STATUS 8001


typedef struct __mavlink_network_status_t {
 uint32_t expired_time; /*<  ntrip account expired time*/
 uint8_t state; /*<  network state*/
 uint8_t rssi; /*<  modem rssi*/
 uint8_t wkcloud_state; /*<  walkera cloud state*/
 uint8_t ntrip_state; /*<  ntrip state*/
 uint8_t account_active; /*<  ntrip account active state*/
 char reserved[3]; /*<  used for reserved*/
} mavlink_network_status_t;

#define MAVLINK_MSG_ID_NETWORK_STATUS_LEN 12
#define MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN 12
#define MAVLINK_MSG_ID_8001_LEN 12
#define MAVLINK_MSG_ID_8001_MIN_LEN 12

#define MAVLINK_MSG_ID_NETWORK_STATUS_CRC 222
#define MAVLINK_MSG_ID_8001_CRC 222

#define MAVLINK_MSG_NETWORK_STATUS_FIELD_RESERVED_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_NETWORK_STATUS { \
    8001, \
    "NETWORK_STATUS", \
    7, \
    {  { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_network_status_t, state) }, \
         { "rssi", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_network_status_t, rssi) }, \
         { "wkcloud_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_network_status_t, wkcloud_state) }, \
         { "ntrip_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_network_status_t, ntrip_state) }, \
         { "account_active", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_network_status_t, account_active) }, \
         { "reserved", NULL, MAVLINK_TYPE_CHAR, 3, 9, offsetof(mavlink_network_status_t, reserved) }, \
         { "expired_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_network_status_t, expired_time) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_NETWORK_STATUS { \
    "NETWORK_STATUS", \
    7, \
    {  { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_network_status_t, state) }, \
         { "rssi", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_network_status_t, rssi) }, \
         { "wkcloud_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_network_status_t, wkcloud_state) }, \
         { "ntrip_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_network_status_t, ntrip_state) }, \
         { "account_active", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_network_status_t, account_active) }, \
         { "reserved", NULL, MAVLINK_TYPE_CHAR, 3, 9, offsetof(mavlink_network_status_t, reserved) }, \
         { "expired_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_network_status_t, expired_time) }, \
         } \
}
#endif

/**
 * @brief Pack a network_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param state  network state
 * @param rssi  modem rssi
 * @param wkcloud_state  walkera cloud state
 * @param ntrip_state  ntrip state
 * @param account_active  ntrip account active state
 * @param reserved  used for reserved
 * @param expired_time  ntrip account expired time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_network_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t state, uint8_t rssi, uint8_t wkcloud_state, uint8_t ntrip_state, uint8_t account_active, const char *reserved, uint32_t expired_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NETWORK_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, expired_time);
    _mav_put_uint8_t(buf, 4, state);
    _mav_put_uint8_t(buf, 5, rssi);
    _mav_put_uint8_t(buf, 6, wkcloud_state);
    _mav_put_uint8_t(buf, 7, ntrip_state);
    _mav_put_uint8_t(buf, 8, account_active);
    _mav_put_char_array(buf, 9, reserved, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NETWORK_STATUS_LEN);
#else
    mavlink_network_status_t packet;
    packet.expired_time = expired_time;
    packet.state = state;
    packet.rssi = rssi;
    packet.wkcloud_state = wkcloud_state;
    packet.ntrip_state = ntrip_state;
    packet.account_active = account_active;
    mav_array_memcpy(packet.reserved, reserved, sizeof(char)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NETWORK_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_NETWORK_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_CRC);
}

/**
 * @brief Pack a network_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param state  network state
 * @param rssi  modem rssi
 * @param wkcloud_state  walkera cloud state
 * @param ntrip_state  ntrip state
 * @param account_active  ntrip account active state
 * @param reserved  used for reserved
 * @param expired_time  ntrip account expired time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_network_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t state,uint8_t rssi,uint8_t wkcloud_state,uint8_t ntrip_state,uint8_t account_active,const char *reserved,uint32_t expired_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NETWORK_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, expired_time);
    _mav_put_uint8_t(buf, 4, state);
    _mav_put_uint8_t(buf, 5, rssi);
    _mav_put_uint8_t(buf, 6, wkcloud_state);
    _mav_put_uint8_t(buf, 7, ntrip_state);
    _mav_put_uint8_t(buf, 8, account_active);
    _mav_put_char_array(buf, 9, reserved, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NETWORK_STATUS_LEN);
#else
    mavlink_network_status_t packet;
    packet.expired_time = expired_time;
    packet.state = state;
    packet.rssi = rssi;
    packet.wkcloud_state = wkcloud_state;
    packet.ntrip_state = ntrip_state;
    packet.account_active = account_active;
    mav_array_memcpy(packet.reserved, reserved, sizeof(char)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NETWORK_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_NETWORK_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_CRC);
}

/**
 * @brief Encode a network_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param network_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_network_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_network_status_t* network_status)
{
    return mavlink_msg_network_status_pack(system_id, component_id, msg, network_status->state, network_status->rssi, network_status->wkcloud_state, network_status->ntrip_state, network_status->account_active, network_status->reserved, network_status->expired_time);
}

/**
 * @brief Encode a network_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param network_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_network_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_network_status_t* network_status)
{
    return mavlink_msg_network_status_pack_chan(system_id, component_id, chan, msg, network_status->state, network_status->rssi, network_status->wkcloud_state, network_status->ntrip_state, network_status->account_active, network_status->reserved, network_status->expired_time);
}

/**
 * @brief Send a network_status message
 * @param chan MAVLink channel to send the message
 *
 * @param state  network state
 * @param rssi  modem rssi
 * @param wkcloud_state  walkera cloud state
 * @param ntrip_state  ntrip state
 * @param account_active  ntrip account active state
 * @param reserved  used for reserved
 * @param expired_time  ntrip account expired time
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_network_status_send(mavlink_channel_t chan, uint8_t state, uint8_t rssi, uint8_t wkcloud_state, uint8_t ntrip_state, uint8_t account_active, const char *reserved, uint32_t expired_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NETWORK_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, expired_time);
    _mav_put_uint8_t(buf, 4, state);
    _mav_put_uint8_t(buf, 5, rssi);
    _mav_put_uint8_t(buf, 6, wkcloud_state);
    _mav_put_uint8_t(buf, 7, ntrip_state);
    _mav_put_uint8_t(buf, 8, account_active);
    _mav_put_char_array(buf, 9, reserved, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NETWORK_STATUS, buf, MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_CRC);
#else
    mavlink_network_status_t packet;
    packet.expired_time = expired_time;
    packet.state = state;
    packet.rssi = rssi;
    packet.wkcloud_state = wkcloud_state;
    packet.ntrip_state = ntrip_state;
    packet.account_active = account_active;
    mav_array_memcpy(packet.reserved, reserved, sizeof(char)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NETWORK_STATUS, (const char *)&packet, MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_CRC);
#endif
}

/**
 * @brief Send a network_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_network_status_send_struct(mavlink_channel_t chan, const mavlink_network_status_t* network_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_network_status_send(chan, network_status->state, network_status->rssi, network_status->wkcloud_state, network_status->ntrip_state, network_status->account_active, network_status->reserved, network_status->expired_time);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NETWORK_STATUS, (const char *)network_status, MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_NETWORK_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_network_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t state, uint8_t rssi, uint8_t wkcloud_state, uint8_t ntrip_state, uint8_t account_active, const char *reserved, uint32_t expired_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, expired_time);
    _mav_put_uint8_t(buf, 4, state);
    _mav_put_uint8_t(buf, 5, rssi);
    _mav_put_uint8_t(buf, 6, wkcloud_state);
    _mav_put_uint8_t(buf, 7, ntrip_state);
    _mav_put_uint8_t(buf, 8, account_active);
    _mav_put_char_array(buf, 9, reserved, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NETWORK_STATUS, buf, MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_CRC);
#else
    mavlink_network_status_t *packet = (mavlink_network_status_t *)msgbuf;
    packet->expired_time = expired_time;
    packet->state = state;
    packet->rssi = rssi;
    packet->wkcloud_state = wkcloud_state;
    packet->ntrip_state = ntrip_state;
    packet->account_active = account_active;
    mav_array_memcpy(packet->reserved, reserved, sizeof(char)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NETWORK_STATUS, (const char *)packet, MAVLINK_MSG_ID_NETWORK_STATUS_MIN_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_LEN, MAVLINK_MSG_ID_NETWORK_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE NETWORK_STATUS UNPACKING


/**
 * @brief Get field state from network_status message
 *
 * @return  network state
 */
static inline uint8_t mavlink_msg_network_status_get_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field rssi from network_status message
 *
 * @return  modem rssi
 */
static inline uint8_t mavlink_msg_network_status_get_rssi(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field wkcloud_state from network_status message
 *
 * @return  walkera cloud state
 */
static inline uint8_t mavlink_msg_network_status_get_wkcloud_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field ntrip_state from network_status message
 *
 * @return  ntrip state
 */
static inline uint8_t mavlink_msg_network_status_get_ntrip_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field account_active from network_status message
 *
 * @return  ntrip account active state
 */
static inline uint8_t mavlink_msg_network_status_get_account_active(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field reserved from network_status message
 *
 * @return  used for reserved
 */
static inline uint16_t mavlink_msg_network_status_get_reserved(const mavlink_message_t* msg, char *reserved)
{
    return _MAV_RETURN_char_array(msg, reserved, 3,  9);
}

/**
 * @brief Get field expired_time from network_status message
 *
 * @return  ntrip account expired time
 */
static inline uint32_t mavlink_msg_network_status_get_expired_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a network_status message into a struct
 *
 * @param msg The message to decode
 * @param network_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_network_status_decode(const mavlink_message_t* msg, mavlink_network_status_t* network_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    network_status->expired_time = mavlink_msg_network_status_get_expired_time(msg);
    network_status->state = mavlink_msg_network_status_get_state(msg);
    network_status->rssi = mavlink_msg_network_status_get_rssi(msg);
    network_status->wkcloud_state = mavlink_msg_network_status_get_wkcloud_state(msg);
    network_status->ntrip_state = mavlink_msg_network_status_get_ntrip_state(msg);
    network_status->account_active = mavlink_msg_network_status_get_account_active(msg);
    mavlink_msg_network_status_get_reserved(msg, network_status->reserved);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_NETWORK_STATUS_LEN? msg->len : MAVLINK_MSG_ID_NETWORK_STATUS_LEN;
        memset(network_status, 0, MAVLINK_MSG_ID_NETWORK_STATUS_LEN);
    memcpy(network_status, _MAV_PAYLOAD(msg), len);
#endif
}
