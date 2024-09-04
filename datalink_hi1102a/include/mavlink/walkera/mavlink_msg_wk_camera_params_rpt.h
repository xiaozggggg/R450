#pragma once
// MESSAGE WK_CAMERA_PARAMS_RPT PACKING

#define MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT 8040


typedef struct __mavlink_wk_camera_params_rpt_t {
 uint32_t serial_number; /*<  serial number*/
 float focal_length; /*<  focal length*/
 float focal_length_35mm; /*<  focal length 35mm*/
 uint32_t iso; /*<  see enum WKCAM_ISO_TYPE*/
 uint32_t shutter; /*<  see enum WKCAM_SHUTTER*/
 uint8_t cap_mode; /*<  see enum WKCAM_CAP_MODE*/
 uint8_t cap_continues; /*<  */
 uint8_t cap_save_format; /*<  see enum WKCAM_CAP_SAVE_FORMAT*/
 uint8_t cap_resolution; /*<  see enum WKCAM_CAP_RESOLUTION*/
 uint8_t cap_rotation; /*<  see enum WKCAM_CAP_ROTATION*/
 uint8_t major_ver; /*<  major software version*/
 uint8_t minor_ver; /*<  minor software version*/
 uint8_t stream_enc_type; /*<  see enum WKCAM_ENC_TYPE*/
 uint8_t preview_resolution; /*<  see enum WKCAM_PREVIEW_RESOLUTION*/
 uint8_t preview_bitrate; /*<  see enum WKCAM_PREVIEW_BITRATE*/
 uint8_t record_resolution; /*<  see enum WKCAM_RECORD_RESOLUTION*/
 uint8_t record_bitrate; /*<  see enum WKCAM_RECORD_BITRATE*/
 uint8_t csc_luma; /*<  csc luma*/
 uint8_t csc_contrast; /*<  csc contrast*/
 uint8_t csc_hue; /*<  csc hue*/
 uint8_t csc_aturation; /*<  csc saturation*/
 uint8_t awb_mode; /*<  see enum WKCAM_AWB_MODE*/
 uint8_t ev_mode; /*<  see enum WKCAM_EV_MODE*/
 uint8_t ev_value; /*<  */
 uint8_t reserved[16]; /*<  reserved*/
} mavlink_wk_camera_params_rpt_t;

#define MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN 55
#define MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_MIN_LEN 55
#define MAVLINK_MSG_ID_8040_LEN 55
#define MAVLINK_MSG_ID_8040_MIN_LEN 55

#define MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_CRC 175
#define MAVLINK_MSG_ID_8040_CRC 175

#define MAVLINK_MSG_WK_CAMERA_PARAMS_RPT_FIELD_RESERVED_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_PARAMS_RPT { \
    8040, \
    "WK_CAMERA_PARAMS_RPT", \
    25, \
    {  { "cap_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_wk_camera_params_rpt_t, cap_mode) }, \
         { "cap_continues", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_wk_camera_params_rpt_t, cap_continues) }, \
         { "cap_save_format", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_wk_camera_params_rpt_t, cap_save_format) }, \
         { "cap_resolution", NULL, MAVLINK_TYPE_UINT8_T, 0, 23, offsetof(mavlink_wk_camera_params_rpt_t, cap_resolution) }, \
         { "cap_rotation", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_wk_camera_params_rpt_t, cap_rotation) }, \
         { "major_ver", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_wk_camera_params_rpt_t, major_ver) }, \
         { "minor_ver", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_wk_camera_params_rpt_t, minor_ver) }, \
         { "serial_number", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_params_rpt_t, serial_number) }, \
         { "focal_length", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_camera_params_rpt_t, focal_length) }, \
         { "focal_length_35mm", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_camera_params_rpt_t, focal_length_35mm) }, \
         { "stream_enc_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 27, offsetof(mavlink_wk_camera_params_rpt_t, stream_enc_type) }, \
         { "preview_resolution", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_wk_camera_params_rpt_t, preview_resolution) }, \
         { "preview_bitrate", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_wk_camera_params_rpt_t, preview_bitrate) }, \
         { "record_resolution", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_wk_camera_params_rpt_t, record_resolution) }, \
         { "record_bitrate", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_wk_camera_params_rpt_t, record_bitrate) }, \
         { "csc_luma", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_wk_camera_params_rpt_t, csc_luma) }, \
         { "csc_contrast", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_wk_camera_params_rpt_t, csc_contrast) }, \
         { "csc_hue", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_wk_camera_params_rpt_t, csc_hue) }, \
         { "csc_aturation", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_wk_camera_params_rpt_t, csc_aturation) }, \
         { "awb_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_wk_camera_params_rpt_t, awb_mode) }, \
         { "ev_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_wk_camera_params_rpt_t, ev_mode) }, \
         { "ev_value", NULL, MAVLINK_TYPE_UINT8_T, 0, 38, offsetof(mavlink_wk_camera_params_rpt_t, ev_value) }, \
         { "iso", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_wk_camera_params_rpt_t, iso) }, \
         { "shutter", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_wk_camera_params_rpt_t, shutter) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 16, 39, offsetof(mavlink_wk_camera_params_rpt_t, reserved) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_CAMERA_PARAMS_RPT { \
    "WK_CAMERA_PARAMS_RPT", \
    25, \
    {  { "cap_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_wk_camera_params_rpt_t, cap_mode) }, \
         { "cap_continues", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_wk_camera_params_rpt_t, cap_continues) }, \
         { "cap_save_format", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_wk_camera_params_rpt_t, cap_save_format) }, \
         { "cap_resolution", NULL, MAVLINK_TYPE_UINT8_T, 0, 23, offsetof(mavlink_wk_camera_params_rpt_t, cap_resolution) }, \
         { "cap_rotation", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_wk_camera_params_rpt_t, cap_rotation) }, \
         { "major_ver", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_wk_camera_params_rpt_t, major_ver) }, \
         { "minor_ver", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_wk_camera_params_rpt_t, minor_ver) }, \
         { "serial_number", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_camera_params_rpt_t, serial_number) }, \
         { "focal_length", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_camera_params_rpt_t, focal_length) }, \
         { "focal_length_35mm", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_camera_params_rpt_t, focal_length_35mm) }, \
         { "stream_enc_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 27, offsetof(mavlink_wk_camera_params_rpt_t, stream_enc_type) }, \
         { "preview_resolution", NULL, MAVLINK_TYPE_UINT8_T, 0, 28, offsetof(mavlink_wk_camera_params_rpt_t, preview_resolution) }, \
         { "preview_bitrate", NULL, MAVLINK_TYPE_UINT8_T, 0, 29, offsetof(mavlink_wk_camera_params_rpt_t, preview_bitrate) }, \
         { "record_resolution", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_wk_camera_params_rpt_t, record_resolution) }, \
         { "record_bitrate", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_wk_camera_params_rpt_t, record_bitrate) }, \
         { "csc_luma", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_wk_camera_params_rpt_t, csc_luma) }, \
         { "csc_contrast", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_wk_camera_params_rpt_t, csc_contrast) }, \
         { "csc_hue", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_wk_camera_params_rpt_t, csc_hue) }, \
         { "csc_aturation", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_wk_camera_params_rpt_t, csc_aturation) }, \
         { "awb_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_wk_camera_params_rpt_t, awb_mode) }, \
         { "ev_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 37, offsetof(mavlink_wk_camera_params_rpt_t, ev_mode) }, \
         { "ev_value", NULL, MAVLINK_TYPE_UINT8_T, 0, 38, offsetof(mavlink_wk_camera_params_rpt_t, ev_value) }, \
         { "iso", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_wk_camera_params_rpt_t, iso) }, \
         { "shutter", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_wk_camera_params_rpt_t, shutter) }, \
         { "reserved", NULL, MAVLINK_TYPE_UINT8_T, 16, 39, offsetof(mavlink_wk_camera_params_rpt_t, reserved) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_camera_params_rpt message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param cap_mode  see enum WKCAM_CAP_MODE
 * @param cap_continues  
 * @param cap_save_format  see enum WKCAM_CAP_SAVE_FORMAT
 * @param cap_resolution  see enum WKCAM_CAP_RESOLUTION
 * @param cap_rotation  see enum WKCAM_CAP_ROTATION
 * @param major_ver  major software version
 * @param minor_ver  minor software version
 * @param serial_number  serial number
 * @param focal_length  focal length
 * @param focal_length_35mm  focal length 35mm
 * @param stream_enc_type  see enum WKCAM_ENC_TYPE
 * @param preview_resolution  see enum WKCAM_PREVIEW_RESOLUTION
 * @param preview_bitrate  see enum WKCAM_PREVIEW_BITRATE
 * @param record_resolution  see enum WKCAM_RECORD_RESOLUTION
 * @param record_bitrate  see enum WKCAM_RECORD_BITRATE
 * @param csc_luma  csc luma
 * @param csc_contrast  csc contrast
 * @param csc_hue  csc hue
 * @param csc_aturation  csc saturation
 * @param awb_mode  see enum WKCAM_AWB_MODE
 * @param ev_mode  see enum WKCAM_EV_MODE
 * @param ev_value  
 * @param iso  see enum WKCAM_ISO_TYPE
 * @param shutter  see enum WKCAM_SHUTTER
 * @param reserved  reserved
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_params_rpt_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t cap_mode, uint8_t cap_continues, uint8_t cap_save_format, uint8_t cap_resolution, uint8_t cap_rotation, uint8_t major_ver, uint8_t minor_ver, uint32_t serial_number, float focal_length, float focal_length_35mm, uint8_t stream_enc_type, uint8_t preview_resolution, uint8_t preview_bitrate, uint8_t record_resolution, uint8_t record_bitrate, uint8_t csc_luma, uint8_t csc_contrast, uint8_t csc_hue, uint8_t csc_aturation, uint8_t awb_mode, uint8_t ev_mode, uint8_t ev_value, uint32_t iso, uint32_t shutter, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN];
    _mav_put_uint32_t(buf, 0, serial_number);
    _mav_put_float(buf, 4, focal_length);
    _mav_put_float(buf, 8, focal_length_35mm);
    _mav_put_uint32_t(buf, 12, iso);
    _mav_put_uint32_t(buf, 16, shutter);
    _mav_put_uint8_t(buf, 20, cap_mode);
    _mav_put_uint8_t(buf, 21, cap_continues);
    _mav_put_uint8_t(buf, 22, cap_save_format);
    _mav_put_uint8_t(buf, 23, cap_resolution);
    _mav_put_uint8_t(buf, 24, cap_rotation);
    _mav_put_uint8_t(buf, 25, major_ver);
    _mav_put_uint8_t(buf, 26, minor_ver);
    _mav_put_uint8_t(buf, 27, stream_enc_type);
    _mav_put_uint8_t(buf, 28, preview_resolution);
    _mav_put_uint8_t(buf, 29, preview_bitrate);
    _mav_put_uint8_t(buf, 30, record_resolution);
    _mav_put_uint8_t(buf, 31, record_bitrate);
    _mav_put_uint8_t(buf, 32, csc_luma);
    _mav_put_uint8_t(buf, 33, csc_contrast);
    _mav_put_uint8_t(buf, 34, csc_hue);
    _mav_put_uint8_t(buf, 35, csc_aturation);
    _mav_put_uint8_t(buf, 36, awb_mode);
    _mav_put_uint8_t(buf, 37, ev_mode);
    _mav_put_uint8_t(buf, 38, ev_value);
    _mav_put_uint8_t_array(buf, 39, reserved, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN);
#else
    mavlink_wk_camera_params_rpt_t packet;
    packet.serial_number = serial_number;
    packet.focal_length = focal_length;
    packet.focal_length_35mm = focal_length_35mm;
    packet.iso = iso;
    packet.shutter = shutter;
    packet.cap_mode = cap_mode;
    packet.cap_continues = cap_continues;
    packet.cap_save_format = cap_save_format;
    packet.cap_resolution = cap_resolution;
    packet.cap_rotation = cap_rotation;
    packet.major_ver = major_ver;
    packet.minor_ver = minor_ver;
    packet.stream_enc_type = stream_enc_type;
    packet.preview_resolution = preview_resolution;
    packet.preview_bitrate = preview_bitrate;
    packet.record_resolution = record_resolution;
    packet.record_bitrate = record_bitrate;
    packet.csc_luma = csc_luma;
    packet.csc_contrast = csc_contrast;
    packet.csc_hue = csc_hue;
    packet.csc_aturation = csc_aturation;
    packet.awb_mode = awb_mode;
    packet.ev_mode = ev_mode;
    packet.ev_value = ev_value;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_CRC);
}

/**
 * @brief Pack a wk_camera_params_rpt message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cap_mode  see enum WKCAM_CAP_MODE
 * @param cap_continues  
 * @param cap_save_format  see enum WKCAM_CAP_SAVE_FORMAT
 * @param cap_resolution  see enum WKCAM_CAP_RESOLUTION
 * @param cap_rotation  see enum WKCAM_CAP_ROTATION
 * @param major_ver  major software version
 * @param minor_ver  minor software version
 * @param serial_number  serial number
 * @param focal_length  focal length
 * @param focal_length_35mm  focal length 35mm
 * @param stream_enc_type  see enum WKCAM_ENC_TYPE
 * @param preview_resolution  see enum WKCAM_PREVIEW_RESOLUTION
 * @param preview_bitrate  see enum WKCAM_PREVIEW_BITRATE
 * @param record_resolution  see enum WKCAM_RECORD_RESOLUTION
 * @param record_bitrate  see enum WKCAM_RECORD_BITRATE
 * @param csc_luma  csc luma
 * @param csc_contrast  csc contrast
 * @param csc_hue  csc hue
 * @param csc_aturation  csc saturation
 * @param awb_mode  see enum WKCAM_AWB_MODE
 * @param ev_mode  see enum WKCAM_EV_MODE
 * @param ev_value  
 * @param iso  see enum WKCAM_ISO_TYPE
 * @param shutter  see enum WKCAM_SHUTTER
 * @param reserved  reserved
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_camera_params_rpt_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t cap_mode,uint8_t cap_continues,uint8_t cap_save_format,uint8_t cap_resolution,uint8_t cap_rotation,uint8_t major_ver,uint8_t minor_ver,uint32_t serial_number,float focal_length,float focal_length_35mm,uint8_t stream_enc_type,uint8_t preview_resolution,uint8_t preview_bitrate,uint8_t record_resolution,uint8_t record_bitrate,uint8_t csc_luma,uint8_t csc_contrast,uint8_t csc_hue,uint8_t csc_aturation,uint8_t awb_mode,uint8_t ev_mode,uint8_t ev_value,uint32_t iso,uint32_t shutter,const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN];
    _mav_put_uint32_t(buf, 0, serial_number);
    _mav_put_float(buf, 4, focal_length);
    _mav_put_float(buf, 8, focal_length_35mm);
    _mav_put_uint32_t(buf, 12, iso);
    _mav_put_uint32_t(buf, 16, shutter);
    _mav_put_uint8_t(buf, 20, cap_mode);
    _mav_put_uint8_t(buf, 21, cap_continues);
    _mav_put_uint8_t(buf, 22, cap_save_format);
    _mav_put_uint8_t(buf, 23, cap_resolution);
    _mav_put_uint8_t(buf, 24, cap_rotation);
    _mav_put_uint8_t(buf, 25, major_ver);
    _mav_put_uint8_t(buf, 26, minor_ver);
    _mav_put_uint8_t(buf, 27, stream_enc_type);
    _mav_put_uint8_t(buf, 28, preview_resolution);
    _mav_put_uint8_t(buf, 29, preview_bitrate);
    _mav_put_uint8_t(buf, 30, record_resolution);
    _mav_put_uint8_t(buf, 31, record_bitrate);
    _mav_put_uint8_t(buf, 32, csc_luma);
    _mav_put_uint8_t(buf, 33, csc_contrast);
    _mav_put_uint8_t(buf, 34, csc_hue);
    _mav_put_uint8_t(buf, 35, csc_aturation);
    _mav_put_uint8_t(buf, 36, awb_mode);
    _mav_put_uint8_t(buf, 37, ev_mode);
    _mav_put_uint8_t(buf, 38, ev_value);
    _mav_put_uint8_t_array(buf, 39, reserved, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN);
#else
    mavlink_wk_camera_params_rpt_t packet;
    packet.serial_number = serial_number;
    packet.focal_length = focal_length;
    packet.focal_length_35mm = focal_length_35mm;
    packet.iso = iso;
    packet.shutter = shutter;
    packet.cap_mode = cap_mode;
    packet.cap_continues = cap_continues;
    packet.cap_save_format = cap_save_format;
    packet.cap_resolution = cap_resolution;
    packet.cap_rotation = cap_rotation;
    packet.major_ver = major_ver;
    packet.minor_ver = minor_ver;
    packet.stream_enc_type = stream_enc_type;
    packet.preview_resolution = preview_resolution;
    packet.preview_bitrate = preview_bitrate;
    packet.record_resolution = record_resolution;
    packet.record_bitrate = record_bitrate;
    packet.csc_luma = csc_luma;
    packet.csc_contrast = csc_contrast;
    packet.csc_hue = csc_hue;
    packet.csc_aturation = csc_aturation;
    packet.awb_mode = awb_mode;
    packet.ev_mode = ev_mode;
    packet.ev_value = ev_value;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_CRC);
}

/**
 * @brief Encode a wk_camera_params_rpt struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_params_rpt C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_params_rpt_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_camera_params_rpt_t* wk_camera_params_rpt)
{
    return mavlink_msg_wk_camera_params_rpt_pack(system_id, component_id, msg, wk_camera_params_rpt->cap_mode, wk_camera_params_rpt->cap_continues, wk_camera_params_rpt->cap_save_format, wk_camera_params_rpt->cap_resolution, wk_camera_params_rpt->cap_rotation, wk_camera_params_rpt->major_ver, wk_camera_params_rpt->minor_ver, wk_camera_params_rpt->serial_number, wk_camera_params_rpt->focal_length, wk_camera_params_rpt->focal_length_35mm, wk_camera_params_rpt->stream_enc_type, wk_camera_params_rpt->preview_resolution, wk_camera_params_rpt->preview_bitrate, wk_camera_params_rpt->record_resolution, wk_camera_params_rpt->record_bitrate, wk_camera_params_rpt->csc_luma, wk_camera_params_rpt->csc_contrast, wk_camera_params_rpt->csc_hue, wk_camera_params_rpt->csc_aturation, wk_camera_params_rpt->awb_mode, wk_camera_params_rpt->ev_mode, wk_camera_params_rpt->ev_value, wk_camera_params_rpt->iso, wk_camera_params_rpt->shutter, wk_camera_params_rpt->reserved);
}

/**
 * @brief Encode a wk_camera_params_rpt struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_camera_params_rpt C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_camera_params_rpt_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_camera_params_rpt_t* wk_camera_params_rpt)
{
    return mavlink_msg_wk_camera_params_rpt_pack_chan(system_id, component_id, chan, msg, wk_camera_params_rpt->cap_mode, wk_camera_params_rpt->cap_continues, wk_camera_params_rpt->cap_save_format, wk_camera_params_rpt->cap_resolution, wk_camera_params_rpt->cap_rotation, wk_camera_params_rpt->major_ver, wk_camera_params_rpt->minor_ver, wk_camera_params_rpt->serial_number, wk_camera_params_rpt->focal_length, wk_camera_params_rpt->focal_length_35mm, wk_camera_params_rpt->stream_enc_type, wk_camera_params_rpt->preview_resolution, wk_camera_params_rpt->preview_bitrate, wk_camera_params_rpt->record_resolution, wk_camera_params_rpt->record_bitrate, wk_camera_params_rpt->csc_luma, wk_camera_params_rpt->csc_contrast, wk_camera_params_rpt->csc_hue, wk_camera_params_rpt->csc_aturation, wk_camera_params_rpt->awb_mode, wk_camera_params_rpt->ev_mode, wk_camera_params_rpt->ev_value, wk_camera_params_rpt->iso, wk_camera_params_rpt->shutter, wk_camera_params_rpt->reserved);
}

/**
 * @brief Send a wk_camera_params_rpt message
 * @param chan MAVLink channel to send the message
 *
 * @param cap_mode  see enum WKCAM_CAP_MODE
 * @param cap_continues  
 * @param cap_save_format  see enum WKCAM_CAP_SAVE_FORMAT
 * @param cap_resolution  see enum WKCAM_CAP_RESOLUTION
 * @param cap_rotation  see enum WKCAM_CAP_ROTATION
 * @param major_ver  major software version
 * @param minor_ver  minor software version
 * @param serial_number  serial number
 * @param focal_length  focal length
 * @param focal_length_35mm  focal length 35mm
 * @param stream_enc_type  see enum WKCAM_ENC_TYPE
 * @param preview_resolution  see enum WKCAM_PREVIEW_RESOLUTION
 * @param preview_bitrate  see enum WKCAM_PREVIEW_BITRATE
 * @param record_resolution  see enum WKCAM_RECORD_RESOLUTION
 * @param record_bitrate  see enum WKCAM_RECORD_BITRATE
 * @param csc_luma  csc luma
 * @param csc_contrast  csc contrast
 * @param csc_hue  csc hue
 * @param csc_aturation  csc saturation
 * @param awb_mode  see enum WKCAM_AWB_MODE
 * @param ev_mode  see enum WKCAM_EV_MODE
 * @param ev_value  
 * @param iso  see enum WKCAM_ISO_TYPE
 * @param shutter  see enum WKCAM_SHUTTER
 * @param reserved  reserved
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_camera_params_rpt_send(mavlink_channel_t chan, uint8_t cap_mode, uint8_t cap_continues, uint8_t cap_save_format, uint8_t cap_resolution, uint8_t cap_rotation, uint8_t major_ver, uint8_t minor_ver, uint32_t serial_number, float focal_length, float focal_length_35mm, uint8_t stream_enc_type, uint8_t preview_resolution, uint8_t preview_bitrate, uint8_t record_resolution, uint8_t record_bitrate, uint8_t csc_luma, uint8_t csc_contrast, uint8_t csc_hue, uint8_t csc_aturation, uint8_t awb_mode, uint8_t ev_mode, uint8_t ev_value, uint32_t iso, uint32_t shutter, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN];
    _mav_put_uint32_t(buf, 0, serial_number);
    _mav_put_float(buf, 4, focal_length);
    _mav_put_float(buf, 8, focal_length_35mm);
    _mav_put_uint32_t(buf, 12, iso);
    _mav_put_uint32_t(buf, 16, shutter);
    _mav_put_uint8_t(buf, 20, cap_mode);
    _mav_put_uint8_t(buf, 21, cap_continues);
    _mav_put_uint8_t(buf, 22, cap_save_format);
    _mav_put_uint8_t(buf, 23, cap_resolution);
    _mav_put_uint8_t(buf, 24, cap_rotation);
    _mav_put_uint8_t(buf, 25, major_ver);
    _mav_put_uint8_t(buf, 26, minor_ver);
    _mav_put_uint8_t(buf, 27, stream_enc_type);
    _mav_put_uint8_t(buf, 28, preview_resolution);
    _mav_put_uint8_t(buf, 29, preview_bitrate);
    _mav_put_uint8_t(buf, 30, record_resolution);
    _mav_put_uint8_t(buf, 31, record_bitrate);
    _mav_put_uint8_t(buf, 32, csc_luma);
    _mav_put_uint8_t(buf, 33, csc_contrast);
    _mav_put_uint8_t(buf, 34, csc_hue);
    _mav_put_uint8_t(buf, 35, csc_aturation);
    _mav_put_uint8_t(buf, 36, awb_mode);
    _mav_put_uint8_t(buf, 37, ev_mode);
    _mav_put_uint8_t(buf, 38, ev_value);
    _mav_put_uint8_t_array(buf, 39, reserved, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT, buf, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_CRC);
#else
    mavlink_wk_camera_params_rpt_t packet;
    packet.serial_number = serial_number;
    packet.focal_length = focal_length;
    packet.focal_length_35mm = focal_length_35mm;
    packet.iso = iso;
    packet.shutter = shutter;
    packet.cap_mode = cap_mode;
    packet.cap_continues = cap_continues;
    packet.cap_save_format = cap_save_format;
    packet.cap_resolution = cap_resolution;
    packet.cap_rotation = cap_rotation;
    packet.major_ver = major_ver;
    packet.minor_ver = minor_ver;
    packet.stream_enc_type = stream_enc_type;
    packet.preview_resolution = preview_resolution;
    packet.preview_bitrate = preview_bitrate;
    packet.record_resolution = record_resolution;
    packet.record_bitrate = record_bitrate;
    packet.csc_luma = csc_luma;
    packet.csc_contrast = csc_contrast;
    packet.csc_hue = csc_hue;
    packet.csc_aturation = csc_aturation;
    packet.awb_mode = awb_mode;
    packet.ev_mode = ev_mode;
    packet.ev_value = ev_value;
    mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT, (const char *)&packet, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_CRC);
#endif
}

/**
 * @brief Send a wk_camera_params_rpt message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_camera_params_rpt_send_struct(mavlink_channel_t chan, const mavlink_wk_camera_params_rpt_t* wk_camera_params_rpt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_camera_params_rpt_send(chan, wk_camera_params_rpt->cap_mode, wk_camera_params_rpt->cap_continues, wk_camera_params_rpt->cap_save_format, wk_camera_params_rpt->cap_resolution, wk_camera_params_rpt->cap_rotation, wk_camera_params_rpt->major_ver, wk_camera_params_rpt->minor_ver, wk_camera_params_rpt->serial_number, wk_camera_params_rpt->focal_length, wk_camera_params_rpt->focal_length_35mm, wk_camera_params_rpt->stream_enc_type, wk_camera_params_rpt->preview_resolution, wk_camera_params_rpt->preview_bitrate, wk_camera_params_rpt->record_resolution, wk_camera_params_rpt->record_bitrate, wk_camera_params_rpt->csc_luma, wk_camera_params_rpt->csc_contrast, wk_camera_params_rpt->csc_hue, wk_camera_params_rpt->csc_aturation, wk_camera_params_rpt->awb_mode, wk_camera_params_rpt->ev_mode, wk_camera_params_rpt->ev_value, wk_camera_params_rpt->iso, wk_camera_params_rpt->shutter, wk_camera_params_rpt->reserved);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT, (const char *)wk_camera_params_rpt, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_camera_params_rpt_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t cap_mode, uint8_t cap_continues, uint8_t cap_save_format, uint8_t cap_resolution, uint8_t cap_rotation, uint8_t major_ver, uint8_t minor_ver, uint32_t serial_number, float focal_length, float focal_length_35mm, uint8_t stream_enc_type, uint8_t preview_resolution, uint8_t preview_bitrate, uint8_t record_resolution, uint8_t record_bitrate, uint8_t csc_luma, uint8_t csc_contrast, uint8_t csc_hue, uint8_t csc_aturation, uint8_t awb_mode, uint8_t ev_mode, uint8_t ev_value, uint32_t iso, uint32_t shutter, const uint8_t *reserved)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, serial_number);
    _mav_put_float(buf, 4, focal_length);
    _mav_put_float(buf, 8, focal_length_35mm);
    _mav_put_uint32_t(buf, 12, iso);
    _mav_put_uint32_t(buf, 16, shutter);
    _mav_put_uint8_t(buf, 20, cap_mode);
    _mav_put_uint8_t(buf, 21, cap_continues);
    _mav_put_uint8_t(buf, 22, cap_save_format);
    _mav_put_uint8_t(buf, 23, cap_resolution);
    _mav_put_uint8_t(buf, 24, cap_rotation);
    _mav_put_uint8_t(buf, 25, major_ver);
    _mav_put_uint8_t(buf, 26, minor_ver);
    _mav_put_uint8_t(buf, 27, stream_enc_type);
    _mav_put_uint8_t(buf, 28, preview_resolution);
    _mav_put_uint8_t(buf, 29, preview_bitrate);
    _mav_put_uint8_t(buf, 30, record_resolution);
    _mav_put_uint8_t(buf, 31, record_bitrate);
    _mav_put_uint8_t(buf, 32, csc_luma);
    _mav_put_uint8_t(buf, 33, csc_contrast);
    _mav_put_uint8_t(buf, 34, csc_hue);
    _mav_put_uint8_t(buf, 35, csc_aturation);
    _mav_put_uint8_t(buf, 36, awb_mode);
    _mav_put_uint8_t(buf, 37, ev_mode);
    _mav_put_uint8_t(buf, 38, ev_value);
    _mav_put_uint8_t_array(buf, 39, reserved, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT, buf, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_CRC);
#else
    mavlink_wk_camera_params_rpt_t *packet = (mavlink_wk_camera_params_rpt_t *)msgbuf;
    packet->serial_number = serial_number;
    packet->focal_length = focal_length;
    packet->focal_length_35mm = focal_length_35mm;
    packet->iso = iso;
    packet->shutter = shutter;
    packet->cap_mode = cap_mode;
    packet->cap_continues = cap_continues;
    packet->cap_save_format = cap_save_format;
    packet->cap_resolution = cap_resolution;
    packet->cap_rotation = cap_rotation;
    packet->major_ver = major_ver;
    packet->minor_ver = minor_ver;
    packet->stream_enc_type = stream_enc_type;
    packet->preview_resolution = preview_resolution;
    packet->preview_bitrate = preview_bitrate;
    packet->record_resolution = record_resolution;
    packet->record_bitrate = record_bitrate;
    packet->csc_luma = csc_luma;
    packet->csc_contrast = csc_contrast;
    packet->csc_hue = csc_hue;
    packet->csc_aturation = csc_aturation;
    packet->awb_mode = awb_mode;
    packet->ev_mode = ev_mode;
    packet->ev_value = ev_value;
    mav_array_memcpy(packet->reserved, reserved, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT, (const char *)packet, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_MIN_LEN, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_CAMERA_PARAMS_RPT UNPACKING


/**
 * @brief Get field cap_mode from wk_camera_params_rpt message
 *
 * @return  see enum WKCAM_CAP_MODE
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_cap_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field cap_continues from wk_camera_params_rpt message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_cap_continues(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  21);
}

/**
 * @brief Get field cap_save_format from wk_camera_params_rpt message
 *
 * @return  see enum WKCAM_CAP_SAVE_FORMAT
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_cap_save_format(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  22);
}

/**
 * @brief Get field cap_resolution from wk_camera_params_rpt message
 *
 * @return  see enum WKCAM_CAP_RESOLUTION
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_cap_resolution(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  23);
}

/**
 * @brief Get field cap_rotation from wk_camera_params_rpt message
 *
 * @return  see enum WKCAM_CAP_ROTATION
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_cap_rotation(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field major_ver from wk_camera_params_rpt message
 *
 * @return  major software version
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_major_ver(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  25);
}

/**
 * @brief Get field minor_ver from wk_camera_params_rpt message
 *
 * @return  minor software version
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_minor_ver(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  26);
}

/**
 * @brief Get field serial_number from wk_camera_params_rpt message
 *
 * @return  serial number
 */
static inline uint32_t mavlink_msg_wk_camera_params_rpt_get_serial_number(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field focal_length from wk_camera_params_rpt message
 *
 * @return  focal length
 */
static inline float mavlink_msg_wk_camera_params_rpt_get_focal_length(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field focal_length_35mm from wk_camera_params_rpt message
 *
 * @return  focal length 35mm
 */
static inline float mavlink_msg_wk_camera_params_rpt_get_focal_length_35mm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field stream_enc_type from wk_camera_params_rpt message
 *
 * @return  see enum WKCAM_ENC_TYPE
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_stream_enc_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  27);
}

/**
 * @brief Get field preview_resolution from wk_camera_params_rpt message
 *
 * @return  see enum WKCAM_PREVIEW_RESOLUTION
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_preview_resolution(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field preview_bitrate from wk_camera_params_rpt message
 *
 * @return  see enum WKCAM_PREVIEW_BITRATE
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_preview_bitrate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  29);
}

/**
 * @brief Get field record_resolution from wk_camera_params_rpt message
 *
 * @return  see enum WKCAM_RECORD_RESOLUTION
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_record_resolution(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  30);
}

/**
 * @brief Get field record_bitrate from wk_camera_params_rpt message
 *
 * @return  see enum WKCAM_RECORD_BITRATE
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_record_bitrate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  31);
}

/**
 * @brief Get field csc_luma from wk_camera_params_rpt message
 *
 * @return  csc luma
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_csc_luma(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field csc_contrast from wk_camera_params_rpt message
 *
 * @return  csc contrast
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_csc_contrast(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  33);
}

/**
 * @brief Get field csc_hue from wk_camera_params_rpt message
 *
 * @return  csc hue
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_csc_hue(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  34);
}

/**
 * @brief Get field csc_aturation from wk_camera_params_rpt message
 *
 * @return  csc saturation
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_csc_aturation(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  35);
}

/**
 * @brief Get field awb_mode from wk_camera_params_rpt message
 *
 * @return  see enum WKCAM_AWB_MODE
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_awb_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Get field ev_mode from wk_camera_params_rpt message
 *
 * @return  see enum WKCAM_EV_MODE
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_ev_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  37);
}

/**
 * @brief Get field ev_value from wk_camera_params_rpt message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_camera_params_rpt_get_ev_value(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  38);
}

/**
 * @brief Get field iso from wk_camera_params_rpt message
 *
 * @return  see enum WKCAM_ISO_TYPE
 */
static inline uint32_t mavlink_msg_wk_camera_params_rpt_get_iso(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field shutter from wk_camera_params_rpt message
 *
 * @return  see enum WKCAM_SHUTTER
 */
static inline uint32_t mavlink_msg_wk_camera_params_rpt_get_shutter(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field reserved from wk_camera_params_rpt message
 *
 * @return  reserved
 */
static inline uint16_t mavlink_msg_wk_camera_params_rpt_get_reserved(const mavlink_message_t* msg, uint8_t *reserved)
{
    return _MAV_RETURN_uint8_t_array(msg, reserved, 16,  39);
}

/**
 * @brief Decode a wk_camera_params_rpt message into a struct
 *
 * @param msg The message to decode
 * @param wk_camera_params_rpt C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_camera_params_rpt_decode(const mavlink_message_t* msg, mavlink_wk_camera_params_rpt_t* wk_camera_params_rpt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_camera_params_rpt->serial_number = mavlink_msg_wk_camera_params_rpt_get_serial_number(msg);
    wk_camera_params_rpt->focal_length = mavlink_msg_wk_camera_params_rpt_get_focal_length(msg);
    wk_camera_params_rpt->focal_length_35mm = mavlink_msg_wk_camera_params_rpt_get_focal_length_35mm(msg);
    wk_camera_params_rpt->iso = mavlink_msg_wk_camera_params_rpt_get_iso(msg);
    wk_camera_params_rpt->shutter = mavlink_msg_wk_camera_params_rpt_get_shutter(msg);
    wk_camera_params_rpt->cap_mode = mavlink_msg_wk_camera_params_rpt_get_cap_mode(msg);
    wk_camera_params_rpt->cap_continues = mavlink_msg_wk_camera_params_rpt_get_cap_continues(msg);
    wk_camera_params_rpt->cap_save_format = mavlink_msg_wk_camera_params_rpt_get_cap_save_format(msg);
    wk_camera_params_rpt->cap_resolution = mavlink_msg_wk_camera_params_rpt_get_cap_resolution(msg);
    wk_camera_params_rpt->cap_rotation = mavlink_msg_wk_camera_params_rpt_get_cap_rotation(msg);
    wk_camera_params_rpt->major_ver = mavlink_msg_wk_camera_params_rpt_get_major_ver(msg);
    wk_camera_params_rpt->minor_ver = mavlink_msg_wk_camera_params_rpt_get_minor_ver(msg);
    wk_camera_params_rpt->stream_enc_type = mavlink_msg_wk_camera_params_rpt_get_stream_enc_type(msg);
    wk_camera_params_rpt->preview_resolution = mavlink_msg_wk_camera_params_rpt_get_preview_resolution(msg);
    wk_camera_params_rpt->preview_bitrate = mavlink_msg_wk_camera_params_rpt_get_preview_bitrate(msg);
    wk_camera_params_rpt->record_resolution = mavlink_msg_wk_camera_params_rpt_get_record_resolution(msg);
    wk_camera_params_rpt->record_bitrate = mavlink_msg_wk_camera_params_rpt_get_record_bitrate(msg);
    wk_camera_params_rpt->csc_luma = mavlink_msg_wk_camera_params_rpt_get_csc_luma(msg);
    wk_camera_params_rpt->csc_contrast = mavlink_msg_wk_camera_params_rpt_get_csc_contrast(msg);
    wk_camera_params_rpt->csc_hue = mavlink_msg_wk_camera_params_rpt_get_csc_hue(msg);
    wk_camera_params_rpt->csc_aturation = mavlink_msg_wk_camera_params_rpt_get_csc_aturation(msg);
    wk_camera_params_rpt->awb_mode = mavlink_msg_wk_camera_params_rpt_get_awb_mode(msg);
    wk_camera_params_rpt->ev_mode = mavlink_msg_wk_camera_params_rpt_get_ev_mode(msg);
    wk_camera_params_rpt->ev_value = mavlink_msg_wk_camera_params_rpt_get_ev_value(msg);
    mavlink_msg_wk_camera_params_rpt_get_reserved(msg, wk_camera_params_rpt->reserved);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN? msg->len : MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN;
        memset(wk_camera_params_rpt, 0, MAVLINK_MSG_ID_WK_CAMERA_PARAMS_RPT_LEN);
    memcpy(wk_camera_params_rpt, _MAV_PAYLOAD(msg), len);
#endif
}
