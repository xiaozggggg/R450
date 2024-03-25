#pragma once
// MESSAGE WK_SET_CONNECT_PARAM PACKING

#define MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM 8300


typedef struct __mavlink_wk_set_connect_param_t {
 uint16_t cmd_port; /*<  */
 uint16_t video1_port; /*<  */
 uint16_t video2_port; /*<  */
 uint16_t video3_port; /*<  */
 uint8_t direction; /*<  see CONNECT_PARAM_DIRECTION_E*/
 uint8_t param_type; /*<  parameters type ,see CONNECT_PARAM_TYPE_E*/
 uint8_t cmd_url[40]; /*<  url*/
 uint8_t video1_url[40]; /*<  */
 uint8_t video2_url[40]; /*<  */
 uint8_t video3_url[40]; /*<  */
 uint8_t id[32]; /*<  */
 uint8_t user[16]; /*<  */
 uint8_t password[16]; /*<  */
} mavlink_wk_set_connect_param_t;

#define MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN 234
#define MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_MIN_LEN 234
#define MAVLINK_MSG_ID_8300_LEN 234
#define MAVLINK_MSG_ID_8300_MIN_LEN 234

#define MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_CRC 166
#define MAVLINK_MSG_ID_8300_CRC 166

#define MAVLINK_MSG_WK_SET_CONNECT_PARAM_FIELD_CMD_URL_LEN 40
#define MAVLINK_MSG_WK_SET_CONNECT_PARAM_FIELD_VIDEO1_URL_LEN 40
#define MAVLINK_MSG_WK_SET_CONNECT_PARAM_FIELD_VIDEO2_URL_LEN 40
#define MAVLINK_MSG_WK_SET_CONNECT_PARAM_FIELD_VIDEO3_URL_LEN 40
#define MAVLINK_MSG_WK_SET_CONNECT_PARAM_FIELD_ID_LEN 32
#define MAVLINK_MSG_WK_SET_CONNECT_PARAM_FIELD_USER_LEN 16
#define MAVLINK_MSG_WK_SET_CONNECT_PARAM_FIELD_PASSWORD_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_SET_CONNECT_PARAM { \
    8300, \
    "WK_SET_CONNECT_PARAM", \
    13, \
    {  { "direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wk_set_connect_param_t, direction) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_wk_set_connect_param_t, param_type) }, \
         { "cmd_url", NULL, MAVLINK_TYPE_UINT8_T, 40, 10, offsetof(mavlink_wk_set_connect_param_t, cmd_url) }, \
         { "cmd_port", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wk_set_connect_param_t, cmd_port) }, \
         { "video1_url", NULL, MAVLINK_TYPE_UINT8_T, 40, 50, offsetof(mavlink_wk_set_connect_param_t, video1_url) }, \
         { "video1_port", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_wk_set_connect_param_t, video1_port) }, \
         { "video2_url", NULL, MAVLINK_TYPE_UINT8_T, 40, 90, offsetof(mavlink_wk_set_connect_param_t, video2_url) }, \
         { "video2_port", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_wk_set_connect_param_t, video2_port) }, \
         { "video3_url", NULL, MAVLINK_TYPE_UINT8_T, 40, 130, offsetof(mavlink_wk_set_connect_param_t, video3_url) }, \
         { "video3_port", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_wk_set_connect_param_t, video3_port) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 32, 170, offsetof(mavlink_wk_set_connect_param_t, id) }, \
         { "user", NULL, MAVLINK_TYPE_UINT8_T, 16, 202, offsetof(mavlink_wk_set_connect_param_t, user) }, \
         { "password", NULL, MAVLINK_TYPE_UINT8_T, 16, 218, offsetof(mavlink_wk_set_connect_param_t, password) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_SET_CONNECT_PARAM { \
    "WK_SET_CONNECT_PARAM", \
    13, \
    {  { "direction", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_wk_set_connect_param_t, direction) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_wk_set_connect_param_t, param_type) }, \
         { "cmd_url", NULL, MAVLINK_TYPE_UINT8_T, 40, 10, offsetof(mavlink_wk_set_connect_param_t, cmd_url) }, \
         { "cmd_port", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_wk_set_connect_param_t, cmd_port) }, \
         { "video1_url", NULL, MAVLINK_TYPE_UINT8_T, 40, 50, offsetof(mavlink_wk_set_connect_param_t, video1_url) }, \
         { "video1_port", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_wk_set_connect_param_t, video1_port) }, \
         { "video2_url", NULL, MAVLINK_TYPE_UINT8_T, 40, 90, offsetof(mavlink_wk_set_connect_param_t, video2_url) }, \
         { "video2_port", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_wk_set_connect_param_t, video2_port) }, \
         { "video3_url", NULL, MAVLINK_TYPE_UINT8_T, 40, 130, offsetof(mavlink_wk_set_connect_param_t, video3_url) }, \
         { "video3_port", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_wk_set_connect_param_t, video3_port) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 32, 170, offsetof(mavlink_wk_set_connect_param_t, id) }, \
         { "user", NULL, MAVLINK_TYPE_UINT8_T, 16, 202, offsetof(mavlink_wk_set_connect_param_t, user) }, \
         { "password", NULL, MAVLINK_TYPE_UINT8_T, 16, 218, offsetof(mavlink_wk_set_connect_param_t, password) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_set_connect_param message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param direction  see CONNECT_PARAM_DIRECTION_E
 * @param param_type  parameters type ,see CONNECT_PARAM_TYPE_E
 * @param cmd_url  url
 * @param cmd_port  
 * @param video1_url  
 * @param video1_port  
 * @param video2_url  
 * @param video2_port  
 * @param video3_url  
 * @param video3_port  
 * @param id  
 * @param user  
 * @param password  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_set_connect_param_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t direction, uint8_t param_type, const uint8_t *cmd_url, uint16_t cmd_port, const uint8_t *video1_url, uint16_t video1_port, const uint8_t *video2_url, uint16_t video2_port, const uint8_t *video3_url, uint16_t video3_port, const uint8_t *id, const uint8_t *user, const uint8_t *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN];
    _mav_put_uint16_t(buf, 0, cmd_port);
    _mav_put_uint16_t(buf, 2, video1_port);
    _mav_put_uint16_t(buf, 4, video2_port);
    _mav_put_uint16_t(buf, 6, video3_port);
    _mav_put_uint8_t(buf, 8, direction);
    _mav_put_uint8_t(buf, 9, param_type);
    _mav_put_uint8_t_array(buf, 10, cmd_url, 40);
    _mav_put_uint8_t_array(buf, 50, video1_url, 40);
    _mav_put_uint8_t_array(buf, 90, video2_url, 40);
    _mav_put_uint8_t_array(buf, 130, video3_url, 40);
    _mav_put_uint8_t_array(buf, 170, id, 32);
    _mav_put_uint8_t_array(buf, 202, user, 16);
    _mav_put_uint8_t_array(buf, 218, password, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN);
#else
    mavlink_wk_set_connect_param_t packet;
    packet.cmd_port = cmd_port;
    packet.video1_port = video1_port;
    packet.video2_port = video2_port;
    packet.video3_port = video3_port;
    packet.direction = direction;
    packet.param_type = param_type;
    mav_array_memcpy(packet.cmd_url, cmd_url, sizeof(uint8_t)*40);
    mav_array_memcpy(packet.video1_url, video1_url, sizeof(uint8_t)*40);
    mav_array_memcpy(packet.video2_url, video2_url, sizeof(uint8_t)*40);
    mav_array_memcpy(packet.video3_url, video3_url, sizeof(uint8_t)*40);
    mav_array_memcpy(packet.id, id, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.user, user, sizeof(uint8_t)*16);
    mav_array_memcpy(packet.password, password, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_CRC);
}

/**
 * @brief Pack a wk_set_connect_param message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param direction  see CONNECT_PARAM_DIRECTION_E
 * @param param_type  parameters type ,see CONNECT_PARAM_TYPE_E
 * @param cmd_url  url
 * @param cmd_port  
 * @param video1_url  
 * @param video1_port  
 * @param video2_url  
 * @param video2_port  
 * @param video3_url  
 * @param video3_port  
 * @param id  
 * @param user  
 * @param password  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_set_connect_param_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t direction,uint8_t param_type,const uint8_t *cmd_url,uint16_t cmd_port,const uint8_t *video1_url,uint16_t video1_port,const uint8_t *video2_url,uint16_t video2_port,const uint8_t *video3_url,uint16_t video3_port,const uint8_t *id,const uint8_t *user,const uint8_t *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN];
    _mav_put_uint16_t(buf, 0, cmd_port);
    _mav_put_uint16_t(buf, 2, video1_port);
    _mav_put_uint16_t(buf, 4, video2_port);
    _mav_put_uint16_t(buf, 6, video3_port);
    _mav_put_uint8_t(buf, 8, direction);
    _mav_put_uint8_t(buf, 9, param_type);
    _mav_put_uint8_t_array(buf, 10, cmd_url, 40);
    _mav_put_uint8_t_array(buf, 50, video1_url, 40);
    _mav_put_uint8_t_array(buf, 90, video2_url, 40);
    _mav_put_uint8_t_array(buf, 130, video3_url, 40);
    _mav_put_uint8_t_array(buf, 170, id, 32);
    _mav_put_uint8_t_array(buf, 202, user, 16);
    _mav_put_uint8_t_array(buf, 218, password, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN);
#else
    mavlink_wk_set_connect_param_t packet;
    packet.cmd_port = cmd_port;
    packet.video1_port = video1_port;
    packet.video2_port = video2_port;
    packet.video3_port = video3_port;
    packet.direction = direction;
    packet.param_type = param_type;
    mav_array_memcpy(packet.cmd_url, cmd_url, sizeof(uint8_t)*40);
    mav_array_memcpy(packet.video1_url, video1_url, sizeof(uint8_t)*40);
    mav_array_memcpy(packet.video2_url, video2_url, sizeof(uint8_t)*40);
    mav_array_memcpy(packet.video3_url, video3_url, sizeof(uint8_t)*40);
    mav_array_memcpy(packet.id, id, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.user, user, sizeof(uint8_t)*16);
    mav_array_memcpy(packet.password, password, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_CRC);
}

/**
 * @brief Encode a wk_set_connect_param struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_set_connect_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_set_connect_param_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_set_connect_param_t* wk_set_connect_param)
{
    return mavlink_msg_wk_set_connect_param_pack(system_id, component_id, msg, wk_set_connect_param->direction, wk_set_connect_param->param_type, wk_set_connect_param->cmd_url, wk_set_connect_param->cmd_port, wk_set_connect_param->video1_url, wk_set_connect_param->video1_port, wk_set_connect_param->video2_url, wk_set_connect_param->video2_port, wk_set_connect_param->video3_url, wk_set_connect_param->video3_port, wk_set_connect_param->id, wk_set_connect_param->user, wk_set_connect_param->password);
}

/**
 * @brief Encode a wk_set_connect_param struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_set_connect_param C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_set_connect_param_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_set_connect_param_t* wk_set_connect_param)
{
    return mavlink_msg_wk_set_connect_param_pack_chan(system_id, component_id, chan, msg, wk_set_connect_param->direction, wk_set_connect_param->param_type, wk_set_connect_param->cmd_url, wk_set_connect_param->cmd_port, wk_set_connect_param->video1_url, wk_set_connect_param->video1_port, wk_set_connect_param->video2_url, wk_set_connect_param->video2_port, wk_set_connect_param->video3_url, wk_set_connect_param->video3_port, wk_set_connect_param->id, wk_set_connect_param->user, wk_set_connect_param->password);
}

/**
 * @brief Send a wk_set_connect_param message
 * @param chan MAVLink channel to send the message
 *
 * @param direction  see CONNECT_PARAM_DIRECTION_E
 * @param param_type  parameters type ,see CONNECT_PARAM_TYPE_E
 * @param cmd_url  url
 * @param cmd_port  
 * @param video1_url  
 * @param video1_port  
 * @param video2_url  
 * @param video2_port  
 * @param video3_url  
 * @param video3_port  
 * @param id  
 * @param user  
 * @param password  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_set_connect_param_send(mavlink_channel_t chan, uint8_t direction, uint8_t param_type, const uint8_t *cmd_url, uint16_t cmd_port, const uint8_t *video1_url, uint16_t video1_port, const uint8_t *video2_url, uint16_t video2_port, const uint8_t *video3_url, uint16_t video3_port, const uint8_t *id, const uint8_t *user, const uint8_t *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN];
    _mav_put_uint16_t(buf, 0, cmd_port);
    _mav_put_uint16_t(buf, 2, video1_port);
    _mav_put_uint16_t(buf, 4, video2_port);
    _mav_put_uint16_t(buf, 6, video3_port);
    _mav_put_uint8_t(buf, 8, direction);
    _mav_put_uint8_t(buf, 9, param_type);
    _mav_put_uint8_t_array(buf, 10, cmd_url, 40);
    _mav_put_uint8_t_array(buf, 50, video1_url, 40);
    _mav_put_uint8_t_array(buf, 90, video2_url, 40);
    _mav_put_uint8_t_array(buf, 130, video3_url, 40);
    _mav_put_uint8_t_array(buf, 170, id, 32);
    _mav_put_uint8_t_array(buf, 202, user, 16);
    _mav_put_uint8_t_array(buf, 218, password, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM, buf, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_CRC);
#else
    mavlink_wk_set_connect_param_t packet;
    packet.cmd_port = cmd_port;
    packet.video1_port = video1_port;
    packet.video2_port = video2_port;
    packet.video3_port = video3_port;
    packet.direction = direction;
    packet.param_type = param_type;
    mav_array_memcpy(packet.cmd_url, cmd_url, sizeof(uint8_t)*40);
    mav_array_memcpy(packet.video1_url, video1_url, sizeof(uint8_t)*40);
    mav_array_memcpy(packet.video2_url, video2_url, sizeof(uint8_t)*40);
    mav_array_memcpy(packet.video3_url, video3_url, sizeof(uint8_t)*40);
    mav_array_memcpy(packet.id, id, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.user, user, sizeof(uint8_t)*16);
    mav_array_memcpy(packet.password, password, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM, (const char *)&packet, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_CRC);
#endif
}

/**
 * @brief Send a wk_set_connect_param message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_set_connect_param_send_struct(mavlink_channel_t chan, const mavlink_wk_set_connect_param_t* wk_set_connect_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_set_connect_param_send(chan, wk_set_connect_param->direction, wk_set_connect_param->param_type, wk_set_connect_param->cmd_url, wk_set_connect_param->cmd_port, wk_set_connect_param->video1_url, wk_set_connect_param->video1_port, wk_set_connect_param->video2_url, wk_set_connect_param->video2_port, wk_set_connect_param->video3_url, wk_set_connect_param->video3_port, wk_set_connect_param->id, wk_set_connect_param->user, wk_set_connect_param->password);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM, (const char *)wk_set_connect_param, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_set_connect_param_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t direction, uint8_t param_type, const uint8_t *cmd_url, uint16_t cmd_port, const uint8_t *video1_url, uint16_t video1_port, const uint8_t *video2_url, uint16_t video2_port, const uint8_t *video3_url, uint16_t video3_port, const uint8_t *id, const uint8_t *user, const uint8_t *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, cmd_port);
    _mav_put_uint16_t(buf, 2, video1_port);
    _mav_put_uint16_t(buf, 4, video2_port);
    _mav_put_uint16_t(buf, 6, video3_port);
    _mav_put_uint8_t(buf, 8, direction);
    _mav_put_uint8_t(buf, 9, param_type);
    _mav_put_uint8_t_array(buf, 10, cmd_url, 40);
    _mav_put_uint8_t_array(buf, 50, video1_url, 40);
    _mav_put_uint8_t_array(buf, 90, video2_url, 40);
    _mav_put_uint8_t_array(buf, 130, video3_url, 40);
    _mav_put_uint8_t_array(buf, 170, id, 32);
    _mav_put_uint8_t_array(buf, 202, user, 16);
    _mav_put_uint8_t_array(buf, 218, password, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM, buf, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_CRC);
#else
    mavlink_wk_set_connect_param_t *packet = (mavlink_wk_set_connect_param_t *)msgbuf;
    packet->cmd_port = cmd_port;
    packet->video1_port = video1_port;
    packet->video2_port = video2_port;
    packet->video3_port = video3_port;
    packet->direction = direction;
    packet->param_type = param_type;
    mav_array_memcpy(packet->cmd_url, cmd_url, sizeof(uint8_t)*40);
    mav_array_memcpy(packet->video1_url, video1_url, sizeof(uint8_t)*40);
    mav_array_memcpy(packet->video2_url, video2_url, sizeof(uint8_t)*40);
    mav_array_memcpy(packet->video3_url, video3_url, sizeof(uint8_t)*40);
    mav_array_memcpy(packet->id, id, sizeof(uint8_t)*32);
    mav_array_memcpy(packet->user, user, sizeof(uint8_t)*16);
    mav_array_memcpy(packet->password, password, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM, (const char *)packet, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_MIN_LEN, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_SET_CONNECT_PARAM UNPACKING


/**
 * @brief Get field direction from wk_set_connect_param message
 *
 * @return  see CONNECT_PARAM_DIRECTION_E
 */
static inline uint8_t mavlink_msg_wk_set_connect_param_get_direction(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field param_type from wk_set_connect_param message
 *
 * @return  parameters type ,see CONNECT_PARAM_TYPE_E
 */
static inline uint8_t mavlink_msg_wk_set_connect_param_get_param_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field cmd_url from wk_set_connect_param message
 *
 * @return  url
 */
static inline uint16_t mavlink_msg_wk_set_connect_param_get_cmd_url(const mavlink_message_t* msg, uint8_t *cmd_url)
{
    return _MAV_RETURN_uint8_t_array(msg, cmd_url, 40,  10);
}

/**
 * @brief Get field cmd_port from wk_set_connect_param message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_set_connect_param_get_cmd_port(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field video1_url from wk_set_connect_param message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_set_connect_param_get_video1_url(const mavlink_message_t* msg, uint8_t *video1_url)
{
    return _MAV_RETURN_uint8_t_array(msg, video1_url, 40,  50);
}

/**
 * @brief Get field video1_port from wk_set_connect_param message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_set_connect_param_get_video1_port(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field video2_url from wk_set_connect_param message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_set_connect_param_get_video2_url(const mavlink_message_t* msg, uint8_t *video2_url)
{
    return _MAV_RETURN_uint8_t_array(msg, video2_url, 40,  90);
}

/**
 * @brief Get field video2_port from wk_set_connect_param message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_set_connect_param_get_video2_port(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field video3_url from wk_set_connect_param message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_set_connect_param_get_video3_url(const mavlink_message_t* msg, uint8_t *video3_url)
{
    return _MAV_RETURN_uint8_t_array(msg, video3_url, 40,  130);
}

/**
 * @brief Get field video3_port from wk_set_connect_param message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_set_connect_param_get_video3_port(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field id from wk_set_connect_param message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_set_connect_param_get_id(const mavlink_message_t* msg, uint8_t *id)
{
    return _MAV_RETURN_uint8_t_array(msg, id, 32,  170);
}

/**
 * @brief Get field user from wk_set_connect_param message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_set_connect_param_get_user(const mavlink_message_t* msg, uint8_t *user)
{
    return _MAV_RETURN_uint8_t_array(msg, user, 16,  202);
}

/**
 * @brief Get field password from wk_set_connect_param message
 *
 * @return  
 */
static inline uint16_t mavlink_msg_wk_set_connect_param_get_password(const mavlink_message_t* msg, uint8_t *password)
{
    return _MAV_RETURN_uint8_t_array(msg, password, 16,  218);
}

/**
 * @brief Decode a wk_set_connect_param message into a struct
 *
 * @param msg The message to decode
 * @param wk_set_connect_param C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_set_connect_param_decode(const mavlink_message_t* msg, mavlink_wk_set_connect_param_t* wk_set_connect_param)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_set_connect_param->cmd_port = mavlink_msg_wk_set_connect_param_get_cmd_port(msg);
    wk_set_connect_param->video1_port = mavlink_msg_wk_set_connect_param_get_video1_port(msg);
    wk_set_connect_param->video2_port = mavlink_msg_wk_set_connect_param_get_video2_port(msg);
    wk_set_connect_param->video3_port = mavlink_msg_wk_set_connect_param_get_video3_port(msg);
    wk_set_connect_param->direction = mavlink_msg_wk_set_connect_param_get_direction(msg);
    wk_set_connect_param->param_type = mavlink_msg_wk_set_connect_param_get_param_type(msg);
    mavlink_msg_wk_set_connect_param_get_cmd_url(msg, wk_set_connect_param->cmd_url);
    mavlink_msg_wk_set_connect_param_get_video1_url(msg, wk_set_connect_param->video1_url);
    mavlink_msg_wk_set_connect_param_get_video2_url(msg, wk_set_connect_param->video2_url);
    mavlink_msg_wk_set_connect_param_get_video3_url(msg, wk_set_connect_param->video3_url);
    mavlink_msg_wk_set_connect_param_get_id(msg, wk_set_connect_param->id);
    mavlink_msg_wk_set_connect_param_get_user(msg, wk_set_connect_param->user);
    mavlink_msg_wk_set_connect_param_get_password(msg, wk_set_connect_param->password);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN? msg->len : MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN;
        memset(wk_set_connect_param, 0, MAVLINK_MSG_ID_WK_SET_CONNECT_PARAM_LEN);
    memcpy(wk_set_connect_param, _MAV_PAYLOAD(msg), len);
#endif
}
