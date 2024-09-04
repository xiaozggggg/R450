#pragma once
// MESSAGE WK_CAMERA_CMD_CREATE_FOLDER PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER 8048


typedef struct __mavlink_wk_camera_cmd_create_folder_t {
 uint8_t folder_name[64]; /*<  folder name*/
} mavlink_wk_camera_cmd_create_folder_t;

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN 64
#define MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_MIN_LEN 64
#define MAVLINK_MSG_ID_8048_LEN 64
#define MAVLINK_MSG_ID_8048_MIN_LEN 64

#define MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_CRC 237
#define MAVLINK_MSG_ID_8048_CRC 237

#define MAVLINK_MSG_WK_CAMERA_CMD_CREATE_FOLDER_FIELD_FOLDER_NAME_LEN 64

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_CREATE_FOLDER { \
    8048, \
    "WK_CAMERA_CMD_CREATE_FOLDER", \
    1, \
    {  { "folder_name", NULL, MAVLINK_TYPE_UINT8_T, 64, 0, offsetof(mavlink_wk_camera_cmd_create_folder_t, folder_name) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_CMD_CREATE_FOLDER { \
    "WK_CAMERA_CMD_CREATE_FOLDER", \
    1, \
    {  { "folder_name", NULL, MAVLINK_TYPE_UINT8_T, 64, 0, offsetof(mavlink_wk_camera_cmd_create_folder_t, folder_name) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_cmd_create_folder message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param folder_name  folder name
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_create_folder_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint8_t *folder_name)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN];

    _mav_put_uint8_t_array(buf, 0, folder_name, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN);
#else
    mavlink_wk_camera_cmd_create_folder_t packet;

    mav_array_memcpy(packet.folder_name, folder_name, sizeof(uint8_t)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_CRC);
}

/**
 * @brief Pack a wk_camera_cmd_create_folder message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param folder_name  folder name
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_create_folder_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint8_t *folder_name)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN];

    _mav_put_uint8_t_array(buf, 0, folder_name, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN);
#else
    mavlink_wk_camera_cmd_create_folder_t packet;

    mav_array_memcpy(packet.folder_name, folder_name, sizeof(uint8_t)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_CRC);
}

/**
 * @brief Encode a wk_camera_cmd_create_folder struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_create_folder C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_create_folder_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_cmd_create_folder_t* wk_camera_cmd_create_folder)
{
    return mavlink_msg_wk_camera_cmd_create_folder_pack(system_id, component_id, msg, wk_camera_cmd_create_folder->folder_name);
}

/**
 * @brief Encode a wk_camera_cmd_create_folder struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_cmd_create_folder C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_create_folder_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_cmd_create_folder_t* wk_camera_cmd_create_folder)
{
    return mavlink_msg_wk_camera_cmd_create_folder_pack_chan(system_id, component_id, chan, msg, wk_camera_cmd_create_folder->folder_name);
}

/**
 * @brief Send a wk_camera_cmd_create_folder message
 * @param chan MAVLink channel to send the message
 *
 * @param folder_name  folder name
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_cmd_create_folder_send(mavlink_channel_t chan, const uint8_t *folder_name)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN];

    _mav_put_uint8_t_array(buf, 0, folder_name, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_CRC);
#else
    mavlink_wk_camera_cmd_create_folder_t packet;

    mav_array_memcpy(packet.folder_name, folder_name, sizeof(uint8_t)*64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_CRC);
#endif
}

/**
 * @brief Send a wk_camera_cmd_create_folder message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_cmd_create_folder_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_cmd_create_folder_t* wk_camera_cmd_create_folder)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_create_folder_send(chan, wk_camera_cmd_create_folder->folder_name);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER, (const char *)wk_camera_cmd_create_folder, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_cmd_create_folder_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint8_t *folder_name)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_uint8_t_array(buf, 0, folder_name, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER, buf, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_CRC);
#else
    mavlink_wk_camera_cmd_create_folder_t *packet = (mavlink_wk_camera_cmd_create_folder_t *)msgbuf;

    mav_array_memcpy(packet->folder_name, folder_name, sizeof(uint8_t)*64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_CMD_CREATE_FOLDER UNPACKING


/**
 * @brief Get field folder_name from wk_camera_cmd_create_folder message
 *
 * @return  folder name
 */
static inline uint16_t mavlink_msg_wk_camera_cmd_create_folder_get_folder_name(const mavlink_message_t* msg, uint8_t *folder_name)
{
    return _MAV_RETURN_uint8_t_array(msg, folder_name, 64,  0);
}

/**
 * @brief Decode a wk_camera_cmd_create_folder message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_cmd_create_folder C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_cmd_create_folder_decode(const mavlink_message_t* msg, mavlink_wk_camera_cmd_create_folder_t* wk_camera_cmd_create_folder)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_cmd_create_folder_get_folder_name(msg, wk_camera_cmd_create_folder->folder_name);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN;
        memset(wk_camera_cmd_create_folder, 0, MAVLINK_MSG_ID_WK_CAMERA_CMD_CREATE_FOLDER_LEN);
    memcpy(wk_camera_cmd_create_folder, _MAV_PAYLOAD(msg), len);
#endif
}
