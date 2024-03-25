#pragma once
// MESSAGE WK_5GINFO_STATUS PACKING

#define MAVLINK_MSG_ID_WK_5GINFO_STATUS 8060


typedef struct __mavlink_wk_5ginfo_status_t {
 uint8_t sim_card_status; /*<  see enum SIM_CARD_STATUS*/
 uint8_t network_status; /*<  see enum NETWORK_STATUS*/
 uint8_t signal_value; /*<  */
 uint8_t camera_status; /*<  see enum CAMERA_STATUS*/
 uint8_t uart_status; /*<  see enum UART_STATUS*/
 uint8_t reserved[16]; /*<  */
} mavlink_wk_5ginfo_status_t;

#define MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN 21
#define MAVLINK_MSG_ID_WK_5GINFO_STATUS_MIN_LEN 21
#define MAVLINK_MSG_ID_8060_LEN 21
#define MAVLINK_MSG_ID_8060_MIN_LEN 21

#define MAVLINK_MSG_ID_WK_5GINFO_STATUS_CRC 104
#define MAVLINK_MSG_ID_8060_CRC 104

#define MAVLINK_MSG_WK_5GINFO_STATUS_FIELD_RESERVED_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_5GINFO_STATUS { \
    8060, \
    "WK_5GINFO_STATUS", \
    6, \
    {  { "sim_card_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_5ginfo_status_t, sim_card_status) }, \
         { "network_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_5ginfo_status_t, network_status) }, \
         { "signal_value", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_5ginfo_status_t, signal_value) }, \
         { "camera_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_5ginfo_status_t, camera_status) }, \
         { "uart_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_5ginfo_status_t, uart_status) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 16, 5, offsetof(mavlink_wk_5ginfo_status_t, reserved) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_5GINFO_STATUS { \
    "WK_5GINFO_STATUS", \
    6, \
    {  { "sim_card_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_5ginfo_status_t, sim_card_status) }, \
         { "network_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_5ginfo_status_t, network_status) }, \
         { "signal_value", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_5ginfo_status_t, signal_value) }, \
         { "camera_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_5ginfo_status_t, camera_status) }, \
         { "uart_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_5ginfo_status_t, uart_status) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 16, 5, offsetof(mavlink_wk_5ginfo_status_t, reserved) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_5ginfo_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param sim_card_status  see enum SIM_CARD_STATUS
 * @param network_status  see enum NETWORK_STATUS
 * @param signal_value  
 * @param camera_status  see enum CAMERA_STATUS
 * @param uart_status  see enum UART_STATUS
 * @param reserved  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_5ginfo_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t sim_card_status, uint8_t network_status, uint8_t signal_value, uint8_t camera_status, uint8_t uart_status, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, sim_card_status);
    _mav_put_uint8_t(buf, 1, network_status);
    _mav_put_uint8_t(buf, 2, signal_value);
    _mav_put_uint8_t(buf, 3, camera_status);
    _mav_put_uint8_t(buf, 4, uart_status);
    _mav_put_uint8_t_array(buf, 5, reserved, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN);
#else
    mavlink_wk_5ginfo_status_t packet;
    packet.sim_card_status = sim_card_status;
    packet.network_status = network_status;
    packet.signal_value = signal_value;
    packet.camera_status = camera_status;
    packet.uart_status = uart_status;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_5GINFO_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_5GINFO_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN, MAVLINK_MSG_ID_WK_5GINFO_STATUS_CRC);
}

/**
 * @brief Pack a wk_5ginfo_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sim_card_status  see enum SIM_CARD_STATUS
 * @param network_status  see enum NETWORK_STATUS
 * @param signal_value  
 * @param camera_status  see enum CAMERA_STATUS
 * @param uart_status  see enum UART_STATUS
 * @param reserved  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_5ginfo_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t sim_card_status,uint8_t network_status,uint8_t signal_value,uint8_t camera_status,uint8_t uart_status,const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, sim_card_status);
    _mav_put_uint8_t(buf, 1, network_status);
    _mav_put_uint8_t(buf, 2, signal_value);
    _mav_put_uint8_t(buf, 3, camera_status);
    _mav_put_uint8_t(buf, 4, uart_status);
    _mav_put_uint8_t_array(buf, 5, reserved, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN);
#else
    mavlink_wk_5ginfo_status_t packet;
    packet.sim_card_status = sim_card_status;
    packet.network_status = network_status;
    packet.signal_value = signal_value;
    packet.camera_status = camera_status;
    packet.uart_status = uart_status;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_5GINFO_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_5GINFO_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN, MAVLINK_MSG_ID_WK_5GINFO_STATUS_CRC);
}

/**
 * @brief Encode a wk_5ginfo_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_5ginfo_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_5ginfo_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_5ginfo_status_t* wk_5ginfo_status)
{
    return mavlink_msg_wk_5ginfo_status_pack(system_id, component_id, msg, wk_5ginfo_status->sim_card_status, wk_5ginfo_status->network_status, wk_5ginfo_status->signal_value, wk_5ginfo_status->camera_status, wk_5ginfo_status->uart_status, wk_5ginfo_status->reserved);
}

/**
 * @brief Encode a wk_5ginfo_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_5ginfo_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_5ginfo_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_5ginfo_status_t* wk_5ginfo_status)
{
    return mavlink_msg_wk_5ginfo_status_pack_chan(system_id, component_id, chan, msg, wk_5ginfo_status->sim_card_status, wk_5ginfo_status->network_status, wk_5ginfo_status->signal_value, wk_5ginfo_status->camera_status, wk_5ginfo_status->uart_status, wk_5ginfo_status->reserved);
}

/**
 * @brief Send a wk_5ginfo_status message
 * @param chan MAVLink channel to send the message
 *
 * @param sim_card_status  see enum SIM_CARD_STATUS
 * @param network_status  see enum NETWORK_STATUS
 * @param signal_value  
 * @param camera_status  see enum CAMERA_STATUS
 * @param uart_status  see enum UART_STATUS
 * @param reserved  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_5ginfo_status_send(mavlink_channel_t chan, uint8_t sim_card_status, uint8_t network_status, uint8_t signal_value, uint8_t camera_status, uint8_t uart_status, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, sim_card_status);
    _mav_put_uint8_t(buf, 1, network_status);
    _mav_put_uint8_t(buf, 2, signal_value);
    _mav_put_uint8_t(buf, 3, camera_status);
    _mav_put_uint8_t(buf, 4, uart_status);
    _mav_put_uint8_t_array(buf, 5, reserved, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_5GINFO_STATUS, buf, MAVLINK_MSG_ID_WK_5GINFO_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN, MAVLINK_MSG_ID_WK_5GINFO_STATUS_CRC);
#else
    mavlink_wk_5ginfo_status_t packet;
    packet.sim_card_status = sim_card_status;
    packet.network_status = network_status;
    packet.signal_value = signal_value;
    packet.camera_status = camera_status;
    packet.uart_status = uart_status;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_5GINFO_STATUS, (const char *)&packet, MAVLINK_MSG_ID_WK_5GINFO_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN, MAVLINK_MSG_ID_WK_5GINFO_STATUS_CRC);
#endif
}

/**
 * @brief Send a wk_5ginfo_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_5ginfo_status_send_struct(mavlink_channel_t chan, const mavlink_wk_5ginfo_status_t* wk_5ginfo_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_5ginfo_status_send(chan, wk_5ginfo_status->sim_card_status, wk_5ginfo_status->network_status, wk_5ginfo_status->signal_value, wk_5ginfo_status->camera_status, wk_5ginfo_status->uart_status, wk_5ginfo_status->reserved);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_5GINFO_STATUS, (const char *)wk_5ginfo_status, MAVLINK_MSG_ID_WK_5GINFO_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN, MAVLINK_MSG_ID_WK_5GINFO_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_5ginfo_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t sim_card_status, uint8_t network_status, uint8_t signal_value, uint8_t camera_status, uint8_t uart_status, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, sim_card_status);
    _mav_put_uint8_t(buf, 1, network_status);
    _mav_put_uint8_t(buf, 2, signal_value);
    _mav_put_uint8_t(buf, 3, camera_status);
    _mav_put_uint8_t(buf, 4, uart_status);
    _mav_put_uint8_t_array(buf, 5, reserved, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_5GINFO_STATUS, buf, MAVLINK_MSG_ID_WK_5GINFO_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN, MAVLINK_MSG_ID_WK_5GINFO_STATUS_CRC);
#else
    mavlink_wk_5ginfo_status_t *packet = (mavlink_wk_5ginfo_status_t *)msgbuf;
    packet->sim_card_status = sim_card_status;
    packet->network_status = network_status;
    packet->signal_value = signal_value;
    packet->camera_status = camera_status;
    packet->uart_status = uart_status;
    mav_array_memcpy(packet->reserved, reserved, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_5GINFO_STATUS, (const char *)packet, MAVLINK_MSG_ID_WK_5GINFO_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN, MAVLINK_MSG_ID_WK_5GINFO_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_5GINFO_STATUS UNPACKING


/**
 * @brief Get field sim_card_status from wk_5ginfo_status message
 *
 * @return  see enum SIM_CARD_STATUS
 */
static inline uint8_t mavlink_msg_wk_5ginfo_status_get_sim_card_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field network_status from wk_5ginfo_status message
 *
 * @return  see enum NETWORK_STATUS
 */
static inline uint8_t mavlink_msg_wk_5ginfo_status_get_network_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field signal_value from wk_5ginfo_status message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_5ginfo_status_get_signal_value(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field camera_status from wk_5ginfo_status message
 *
 * @return  see enum CAMERA_STATUS
 */
static inline uint8_t mavlink_msg_wk_5ginfo_status_get_camera_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field uart_status from wk_5ginfo_status message
 *
 * @return  see enum UART_STATUS
 */
static inline uint8_t mavlink_msg_wk_5ginfo_status_get_uart_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field reserved from wk_5ginfo_status message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_5ginfo_status_get_reserved(const mavlink_message_t* msg, uint8_t *reserved)
{
    return _MAV_RETURN_uint8_t_array(msg, reserved, 16,  5);
}

/**
 * @brief Decode a wk_5ginfo_status message into a struct
 *
 * @param msg The message to decode
 * @param wk_5ginfo_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_5ginfo_status_decode(const mavlink_message_t* msg, mavlink_wk_5ginfo_status_t* wk_5ginfo_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_5ginfo_status->sim_card_status = mavlink_msg_wk_5ginfo_status_get_sim_card_status(msg);
    wk_5ginfo_status->network_status = mavlink_msg_wk_5ginfo_status_get_network_status(msg);
    wk_5ginfo_status->signal_value = mavlink_msg_wk_5ginfo_status_get_signal_value(msg);
    wk_5ginfo_status->camera_status = mavlink_msg_wk_5ginfo_status_get_camera_status(msg);
    wk_5ginfo_status->uart_status = mavlink_msg_wk_5ginfo_status_get_uart_status(msg);
    mavlink_msg_wk_5ginfo_status_get_reserved(msg, wk_5ginfo_status->reserved);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN? msg->len : MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN;
        memset(wk_5ginfo_status, 0, MAVLINK_MSG_ID_WK_5GINFO_STATUS_LEN);
    memcpy(wk_5ginfo_status, _MAV_PAYLOAD(msg), len);
#endif
}
