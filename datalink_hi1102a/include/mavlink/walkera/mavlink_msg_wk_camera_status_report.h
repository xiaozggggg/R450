#pragma once
// MESSAGE WK_CAMERA_STATUS_REPORT PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT 8045


typedef struct __mavlink_wk_camera_status_report_t {
 uint32_t sdcard_capacity_total_bytes; /*<  total capacity bytes (MB)*/
 uint32_t sdcard_capacity_free_bytes; /*<  free capacity bytes (MB)*/
 uint32_t video_record_time; /*<  video record time*/
 uint32_t capability_flags; /*<  see enum WKCAM_CAPABILITY_FLAGS*/
 uint8_t sdcard_status; /*<  see enum WKCAM_SDCARD_STATUS*/
 uint8_t sdcard_filesystem; /*<  see enum WKCAM_SDCARD_FILESYSTEM*/
 uint8_t reserved[16]; /*<  reserved*/
} mavlink_wk_camera_status_report_t;

#define MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN 34
#define MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_MIN_LEN 34
#define MAVLINK_MSG_ID_8045_LEN 34
#define MAVLINK_MSG_ID_8045_MIN_LEN 34

#define MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_CRC 178
#define MAVLINK_MSG_ID_8045_CRC 178

#define MAVLINK_MSG_WK_CAMERA_STATUS_REPORT_FIELD_RESERVED_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_STATUS_REPORT { \
    8045, \
    "WK_CAMERA_STATUS_REPORT", \
    7, \
    {  { "sdcard_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_wk_camera_status_report_t, sdcard_status) }, \
         { "sdcard_filesystem", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_wk_camera_status_report_t, sdcard_filesystem) }, \
         { "sdcard_capacity_total_bytes", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_status_report_t, sdcard_capacity_total_bytes) }, \
         { "sdcard_capacity_free_bytes", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_camera_status_report_t, sdcard_capacity_free_bytes) }, \
         { "video_record_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_camera_status_report_t, video_record_time) }, \
         { "capability_flags", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_wk_camera_status_report_t, capability_flags) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 16, 18, offsetof(mavlink_wk_camera_status_report_t, reserved) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_STATUS_REPORT { \
    "WK_CAMERA_STATUS_REPORT", \
    7, \
    {  { "sdcard_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_wk_camera_status_report_t, sdcard_status) }, \
         { "sdcard_filesystem", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_wk_camera_status_report_t, sdcard_filesystem) }, \
         { "sdcard_capacity_total_bytes", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_status_report_t, sdcard_capacity_total_bytes) }, \
         { "sdcard_capacity_free_bytes", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_camera_status_report_t, sdcard_capacity_free_bytes) }, \
         { "video_record_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_camera_status_report_t, video_record_time) }, \
         { "capability_flags", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_wk_camera_status_report_t, capability_flags) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 16, 18, offsetof(mavlink_wk_camera_status_report_t, reserved) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_status_report message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param sdcard_status  see enum WKCAM_SDCARD_STATUS
 * @param sdcard_filesystem  see enum WKCAM_SDCARD_FILESYSTEM
 * @param sdcard_capacity_total_bytes  total capacity bytes (MB)
 * @param sdcard_capacity_free_bytes  free capacity bytes (MB)
 * @param video_record_time  video record time
 * @param capability_flags  see enum WKCAM_CAPABILITY_FLAGS
 * @param reserved  reserved
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_status_report_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t sdcard_status, uint8_t sdcard_filesystem, uint32_t sdcard_capacity_total_bytes, uint32_t sdcard_capacity_free_bytes, uint32_t video_record_time, uint32_t capability_flags, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN];
    _mav_put_uint32_t(buf, 0, sdcard_capacity_total_bytes);
    _mav_put_uint32_t(buf, 4, sdcard_capacity_free_bytes);
    _mav_put_uint32_t(buf, 8, video_record_time);
    _mav_put_uint32_t(buf, 12, capability_flags);
    _mav_put_uint8_t(buf, 16, sdcard_status);
    _mav_put_uint8_t(buf, 17, sdcard_filesystem);
    _mav_put_uint8_t_array(buf, 18, reserved, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN);
#else
    mavlink_wk_camera_status_report_t packet;
    packet.sdcard_capacity_total_bytes = sdcard_capacity_total_bytes;
    packet.sdcard_capacity_free_bytes = sdcard_capacity_free_bytes;
    packet.video_record_time = video_record_time;
    packet.capability_flags = capability_flags;
    packet.sdcard_status = sdcard_status;
    packet.sdcard_filesystem = sdcard_filesystem;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_CRC);
}

/**
 * @brief Pack a wk_camera_status_report message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sdcard_status  see enum WKCAM_SDCARD_STATUS
 * @param sdcard_filesystem  see enum WKCAM_SDCARD_FILESYSTEM
 * @param sdcard_capacity_total_bytes  total capacity bytes (MB)
 * @param sdcard_capacity_free_bytes  free capacity bytes (MB)
 * @param video_record_time  video record time
 * @param capability_flags  see enum WKCAM_CAPABILITY_FLAGS
 * @param reserved  reserved
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_status_report_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t sdcard_status,uint8_t sdcard_filesystem,uint32_t sdcard_capacity_total_bytes,uint32_t sdcard_capacity_free_bytes,uint32_t video_record_time,uint32_t capability_flags,const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN];
    _mav_put_uint32_t(buf, 0, sdcard_capacity_total_bytes);
    _mav_put_uint32_t(buf, 4, sdcard_capacity_free_bytes);
    _mav_put_uint32_t(buf, 8, video_record_time);
    _mav_put_uint32_t(buf, 12, capability_flags);
    _mav_put_uint8_t(buf, 16, sdcard_status);
    _mav_put_uint8_t(buf, 17, sdcard_filesystem);
    _mav_put_uint8_t_array(buf, 18, reserved, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN);
#else
    mavlink_wk_camera_status_report_t packet;
    packet.sdcard_capacity_total_bytes = sdcard_capacity_total_bytes;
    packet.sdcard_capacity_free_bytes = sdcard_capacity_free_bytes;
    packet.video_record_time = video_record_time;
    packet.capability_flags = capability_flags;
    packet.sdcard_status = sdcard_status;
    packet.sdcard_filesystem = sdcard_filesystem;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_CRC);
}

/**
 * @brief Encode a wk_camera_status_report struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_status_report C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_status_report_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_status_report_t* wk_camera_status_report)
{
    return mavlink_msg_wk_camera_status_report_pack(system_id, component_id, msg, wk_camera_status_report->sdcard_status, wk_camera_status_report->sdcard_filesystem, wk_camera_status_report->sdcard_capacity_total_bytes, wk_camera_status_report->sdcard_capacity_free_bytes, wk_camera_status_report->video_record_time, wk_camera_status_report->capability_flags, wk_camera_status_report->reserved);
}

/**
 * @brief Encode a wk_camera_status_report struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_status_report C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_status_report_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_status_report_t* wk_camera_status_report)
{
    return mavlink_msg_wk_camera_status_report_pack_chan(system_id, component_id, chan, msg, wk_camera_status_report->sdcard_status, wk_camera_status_report->sdcard_filesystem, wk_camera_status_report->sdcard_capacity_total_bytes, wk_camera_status_report->sdcard_capacity_free_bytes, wk_camera_status_report->video_record_time, wk_camera_status_report->capability_flags, wk_camera_status_report->reserved);
}

/**
 * @brief Send a wk_camera_status_report message
 * @param chan MAVLink channel to send the message
 *
 * @param sdcard_status  see enum WKCAM_SDCARD_STATUS
 * @param sdcard_filesystem  see enum WKCAM_SDCARD_FILESYSTEM
 * @param sdcard_capacity_total_bytes  total capacity bytes (MB)
 * @param sdcard_capacity_free_bytes  free capacity bytes (MB)
 * @param video_record_time  video record time
 * @param capability_flags  see enum WKCAM_CAPABILITY_FLAGS
 * @param reserved  reserved
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_status_report_send(mavlink_channel_t chan, uint8_t sdcard_status, uint8_t sdcard_filesystem, uint32_t sdcard_capacity_total_bytes, uint32_t sdcard_capacity_free_bytes, uint32_t video_record_time, uint32_t capability_flags, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN];
    _mav_put_uint32_t(buf, 0, sdcard_capacity_total_bytes);
    _mav_put_uint32_t(buf, 4, sdcard_capacity_free_bytes);
    _mav_put_uint32_t(buf, 8, video_record_time);
    _mav_put_uint32_t(buf, 12, capability_flags);
    _mav_put_uint8_t(buf, 16, sdcard_status);
    _mav_put_uint8_t(buf, 17, sdcard_filesystem);
    _mav_put_uint8_t_array(buf, 18, reserved, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT, buf, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_CRC);
#else
    mavlink_wk_camera_status_report_t packet;
    packet.sdcard_capacity_total_bytes = sdcard_capacity_total_bytes;
    packet.sdcard_capacity_free_bytes = sdcard_capacity_free_bytes;
    packet.video_record_time = video_record_time;
    packet.capability_flags = capability_flags;
    packet.sdcard_status = sdcard_status;
    packet.sdcard_filesystem = sdcard_filesystem;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_CRC);
#endif
}

/**
 * @brief Send a wk_camera_status_report message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_status_report_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_status_report_t* wk_camera_status_report)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_status_report_send(chan, wk_camera_status_report->sdcard_status, wk_camera_status_report->sdcard_filesystem, wk_camera_status_report->sdcard_capacity_total_bytes, wk_camera_status_report->sdcard_capacity_free_bytes, wk_camera_status_report->video_record_time, wk_camera_status_report->capability_flags, wk_camera_status_report->reserved);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT, (const char *)wk_camera_status_report, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_status_report_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t sdcard_status, uint8_t sdcard_filesystem, uint32_t sdcard_capacity_total_bytes, uint32_t sdcard_capacity_free_bytes, uint32_t video_record_time, uint32_t capability_flags, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, sdcard_capacity_total_bytes);
    _mav_put_uint32_t(buf, 4, sdcard_capacity_free_bytes);
    _mav_put_uint32_t(buf, 8, video_record_time);
    _mav_put_uint32_t(buf, 12, capability_flags);
    _mav_put_uint8_t(buf, 16, sdcard_status);
    _mav_put_uint8_t(buf, 17, sdcard_filesystem);
    _mav_put_uint8_t_array(buf, 18, reserved, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT, buf, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_CRC);
#else
    mavlink_wk_camera_status_report_t *packet = (mavlink_wk_camera_status_report_t *)msgbuf;
    packet->sdcard_capacity_total_bytes = sdcard_capacity_total_bytes;
    packet->sdcard_capacity_free_bytes = sdcard_capacity_free_bytes;
    packet->video_record_time = video_record_time;
    packet->capability_flags = capability_flags;
    packet->sdcard_status = sdcard_status;
    packet->sdcard_filesystem = sdcard_filesystem;
    mav_array_memcpy(packet->reserved, reserved, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_STATUS_REPORT UNPACKING


/**
 * @brief Get field sdcard_status from wk_camera_status_report message
 *
 * @return  see enum WKCAM_SDCARD_STATUS
 */
static inline uint8_t mavlink_msg_wk_camera_status_report_get_sdcard_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field sdcard_filesystem from wk_camera_status_report message
 *
 * @return  see enum WKCAM_SDCARD_FILESYSTEM
 */
static inline uint8_t mavlink_msg_wk_camera_status_report_get_sdcard_filesystem(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field sdcard_capacity_total_bytes from wk_camera_status_report message
 *
 * @return  total capacity bytes (MB)
 */
static inline uint32_t mavlink_msg_wk_camera_status_report_get_sdcard_capacity_total_bytes(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field sdcard_capacity_free_bytes from wk_camera_status_report message
 *
 * @return  free capacity bytes (MB)
 */
static inline uint32_t mavlink_msg_wk_camera_status_report_get_sdcard_capacity_free_bytes(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field video_record_time from wk_camera_status_report message
 *
 * @return  video record time
 */
static inline uint32_t mavlink_msg_wk_camera_status_report_get_video_record_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field capability_flags from wk_camera_status_report message
 *
 * @return  see enum WKCAM_CAPABILITY_FLAGS
 */
static inline uint32_t mavlink_msg_wk_camera_status_report_get_capability_flags(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field reserved from wk_camera_status_report message
 *
 * @return  reserved
 */
static inline uint16_t mavlink_msg_wk_camera_status_report_get_reserved(const mavlink_message_t* msg, uint8_t *reserved)
{
    return _MAV_RETURN_uint8_t_array(msg, reserved, 16,  18);
}

/**
 * @brief Decode a wk_camera_status_report message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_status_report C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_status_report_decode(const mavlink_message_t* msg, mavlink_wk_camera_status_report_t* wk_camera_status_report)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_status_report->sdcard_capacity_total_bytes = mavlink_msg_wk_camera_status_report_get_sdcard_capacity_total_bytes(msg);
    wk_camera_status_report->sdcard_capacity_free_bytes = mavlink_msg_wk_camera_status_report_get_sdcard_capacity_free_bytes(msg);
    wk_camera_status_report->video_record_time = mavlink_msg_wk_camera_status_report_get_video_record_time(msg);
    wk_camera_status_report->capability_flags = mavlink_msg_wk_camera_status_report_get_capability_flags(msg);
    wk_camera_status_report->sdcard_status = mavlink_msg_wk_camera_status_report_get_sdcard_status(msg);
    wk_camera_status_report->sdcard_filesystem = mavlink_msg_wk_camera_status_report_get_sdcard_filesystem(msg);
    mavlink_msg_wk_camera_status_report_get_reserved(msg, wk_camera_status_report->reserved);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN;
        memset(wk_camera_status_report, 0, MAVLINK_MSG_ID_WK_CAMERA_STATUS_REPORT_LEN);
    memcpy(wk_camera_status_report, _MAV_PAYLOAD(msg), len);
#endif
}
