#pragma once
// MESSAGE WK_GNSS_SIGNAL_STRENGTH PACKING

#define MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH 8026


typedef struct __mavlink_wk_gnss_signal_strength_t {
 uint8_t index; /*<  gnss index in fc system*/
 uint8_t gnss_type; /*<  0:general gps,1:rtk*/
 uint8_t sv_nums; /*<  satallite numbers*/
 uint8_t sv_id[80]; /*<  satallite id(see WK_GNSS_SVID_ENUM)*/
 uint8_t sig_id[80]; /*<  signal id(frequency id,see WK_GNSS_SIGID_ENUM)*/
 uint8_t cno[80]; /*<  carrier to noise ratio(signal strength)*/
} mavlink_wk_gnss_signal_strength_t;

#define MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN 243
#define MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_MIN_LEN 243
#define MAVLINK_MSG_ID_8026_LEN 243
#define MAVLINK_MSG_ID_8026_MIN_LEN 243

#define MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_CRC 241
#define MAVLINK_MSG_ID_8026_CRC 241

#define MAVLINK_MSG_WK_GNSS_SIGNAL_STRENGTH_FIELD_SV_ID_LEN 80
#define MAVLINK_MSG_WK_GNSS_SIGNAL_STRENGTH_FIELD_SIG_ID_LEN 80
#define MAVLINK_MSG_WK_GNSS_SIGNAL_STRENGTH_FIELD_CNO_LEN 80

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_GNSS_SIGNAL_STRENGTH { \
    8026, \
    "WK_GNSS_SIGNAL_STRENGTH", \
    6, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_gnss_signal_strength_t, index) }, \
         { "gnss_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_gnss_signal_strength_t, gnss_type) }, \
         { "sv_nums", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_gnss_signal_strength_t, sv_nums) }, \
         { "sv_id", NULL, MAVLINK_TYPE_UINT8_T, 80, 3, offsetof(mavlink_wk_gnss_signal_strength_t, sv_id) }, \
         { "sig_id", NULL, MAVLINK_TYPE_UINT8_T, 80, 83, offsetof(mavlink_wk_gnss_signal_strength_t, sig_id) }, \
         { "cno", NULL, MAVLINK_TYPE_UINT8_T, 80, 163, offsetof(mavlink_wk_gnss_signal_strength_t, cno) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_GNSS_SIGNAL_STRENGTH { \
    "WK_GNSS_SIGNAL_STRENGTH", \
    6, \
    {  { "index", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_gnss_signal_strength_t, index) }, \
         { "gnss_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_gnss_signal_strength_t, gnss_type) }, \
         { "sv_nums", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_gnss_signal_strength_t, sv_nums) }, \
         { "sv_id", NULL, MAVLINK_TYPE_UINT8_T, 80, 3, offsetof(mavlink_wk_gnss_signal_strength_t, sv_id) }, \
         { "sig_id", NULL, MAVLINK_TYPE_UINT8_T, 80, 83, offsetof(mavlink_wk_gnss_signal_strength_t, sig_id) }, \
         { "cno", NULL, MAVLINK_TYPE_UINT8_T, 80, 163, offsetof(mavlink_wk_gnss_signal_strength_t, cno) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_gnss_signal_strength message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param index  gnss index in fc system
 * @param gnss_type  0:general gps,1:rtk
 * @param sv_nums  satallite numbers
 * @param sv_id  satallite id(see WK_GNSS_SVID_ENUM)
 * @param sig_id  signal id(frequency id,see WK_GNSS_SIGID_ENUM)
 * @param cno  carrier to noise ratio(signal strength)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_gnss_signal_strength_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t index, uint8_t gnss_type, uint8_t sv_nums, const uint8_t *sv_id, const uint8_t *sig_id, const uint8_t *cno)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN];
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t(buf, 1, gnss_type);
    _mav_put_uint8_t(buf, 2, sv_nums);
    _mav_put_uint8_t_array(buf, 3, sv_id, 80);
    _mav_put_uint8_t_array(buf, 83, sig_id, 80);
    _mav_put_uint8_t_array(buf, 163, cno, 80);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN);
#else
    mavlink_wk_gnss_signal_strength_t packet;
    packet.index = index;
    packet.gnss_type = gnss_type;
    packet.sv_nums = sv_nums;
    mav_array_memcpy(packet.sv_id, sv_id, sizeof(uint8_t)*80);
    mav_array_memcpy(packet.sig_id, sig_id, sizeof(uint8_t)*80);
    mav_array_memcpy(packet.cno, cno, sizeof(uint8_t)*80);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_MIN_LEN, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_CRC);
}

/**
 * @brief Pack a wk_gnss_signal_strength message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param index  gnss index in fc system
 * @param gnss_type  0:general gps,1:rtk
 * @param sv_nums  satallite numbers
 * @param sv_id  satallite id(see WK_GNSS_SVID_ENUM)
 * @param sig_id  signal id(frequency id,see WK_GNSS_SIGID_ENUM)
 * @param cno  carrier to noise ratio(signal strength)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_gnss_signal_strength_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t index,uint8_t gnss_type,uint8_t sv_nums,const uint8_t *sv_id,const uint8_t *sig_id,const uint8_t *cno)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN];
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t(buf, 1, gnss_type);
    _mav_put_uint8_t(buf, 2, sv_nums);
    _mav_put_uint8_t_array(buf, 3, sv_id, 80);
    _mav_put_uint8_t_array(buf, 83, sig_id, 80);
    _mav_put_uint8_t_array(buf, 163, cno, 80);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN);
#else
    mavlink_wk_gnss_signal_strength_t packet;
    packet.index = index;
    packet.gnss_type = gnss_type;
    packet.sv_nums = sv_nums;
    mav_array_memcpy(packet.sv_id, sv_id, sizeof(uint8_t)*80);
    mav_array_memcpy(packet.sig_id, sig_id, sizeof(uint8_t)*80);
    mav_array_memcpy(packet.cno, cno, sizeof(uint8_t)*80);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_MIN_LEN, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_CRC);
}

/**
 * @brief Encode a wk_gnss_signal_strength struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_gnss_signal_strength C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_gnss_signal_strength_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_gnss_signal_strength_t* wk_gnss_signal_strength)
{
    return mavlink_msg_wk_gnss_signal_strength_pack(system_id, component_id, msg, wk_gnss_signal_strength->index, wk_gnss_signal_strength->gnss_type, wk_gnss_signal_strength->sv_nums, wk_gnss_signal_strength->sv_id, wk_gnss_signal_strength->sig_id, wk_gnss_signal_strength->cno);
}

/**
 * @brief Encode a wk_gnss_signal_strength struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_gnss_signal_strength C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_gnss_signal_strength_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_gnss_signal_strength_t* wk_gnss_signal_strength)
{
    return mavlink_msg_wk_gnss_signal_strength_pack_chan(system_id, component_id, chan, msg, wk_gnss_signal_strength->index, wk_gnss_signal_strength->gnss_type, wk_gnss_signal_strength->sv_nums, wk_gnss_signal_strength->sv_id, wk_gnss_signal_strength->sig_id, wk_gnss_signal_strength->cno);
}

/**
 * @brief Send a wk_gnss_signal_strength message
 * @param chan MAVLink channel to send the message
 *
 * @param index  gnss index in fc system
 * @param gnss_type  0:general gps,1:rtk
 * @param sv_nums  satallite numbers
 * @param sv_id  satallite id(see WK_GNSS_SVID_ENUM)
 * @param sig_id  signal id(frequency id,see WK_GNSS_SIGID_ENUM)
 * @param cno  carrier to noise ratio(signal strength)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_gnss_signal_strength_send(mavlink_channel_t chan, uint8_t index, uint8_t gnss_type, uint8_t sv_nums, const uint8_t *sv_id, const uint8_t *sig_id, const uint8_t *cno)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN];
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t(buf, 1, gnss_type);
    _mav_put_uint8_t(buf, 2, sv_nums);
    _mav_put_uint8_t_array(buf, 3, sv_id, 80);
    _mav_put_uint8_t_array(buf, 83, sig_id, 80);
    _mav_put_uint8_t_array(buf, 163, cno, 80);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH, buf, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_MIN_LEN, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_CRC);
#else
    mavlink_wk_gnss_signal_strength_t packet;
    packet.index = index;
    packet.gnss_type = gnss_type;
    packet.sv_nums = sv_nums;
    mav_array_memcpy(packet.sv_id, sv_id, sizeof(uint8_t)*80);
    mav_array_memcpy(packet.sig_id, sig_id, sizeof(uint8_t)*80);
    mav_array_memcpy(packet.cno, cno, sizeof(uint8_t)*80);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH, (const char *)&packet, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_MIN_LEN, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_CRC);
#endif
}

/**
 * @brief Send a wk_gnss_signal_strength message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_gnss_signal_strength_send_struct(mavlink_channel_t chan, const mavlink_wk_gnss_signal_strength_t* wk_gnss_signal_strength)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_gnss_signal_strength_send(chan, wk_gnss_signal_strength->index, wk_gnss_signal_strength->gnss_type, wk_gnss_signal_strength->sv_nums, wk_gnss_signal_strength->sv_id, wk_gnss_signal_strength->sig_id, wk_gnss_signal_strength->cno);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH, (const char *)wk_gnss_signal_strength, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_MIN_LEN, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_gnss_signal_strength_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t index, uint8_t gnss_type, uint8_t sv_nums, const uint8_t *sv_id, const uint8_t *sig_id, const uint8_t *cno)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, index);
    _mav_put_uint8_t(buf, 1, gnss_type);
    _mav_put_uint8_t(buf, 2, sv_nums);
    _mav_put_uint8_t_array(buf, 3, sv_id, 80);
    _mav_put_uint8_t_array(buf, 83, sig_id, 80);
    _mav_put_uint8_t_array(buf, 163, cno, 80);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH, buf, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_MIN_LEN, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_CRC);
#else
    mavlink_wk_gnss_signal_strength_t *packet = (mavlink_wk_gnss_signal_strength_t *)msgbuf;
    packet->index = index;
    packet->gnss_type = gnss_type;
    packet->sv_nums = sv_nums;
    mav_array_memcpy(packet->sv_id, sv_id, sizeof(uint8_t)*80);
    mav_array_memcpy(packet->sig_id, sig_id, sizeof(uint8_t)*80);
    mav_array_memcpy(packet->cno, cno, sizeof(uint8_t)*80);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH, (const char *)packet, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_MIN_LEN, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_GNSS_SIGNAL_STRENGTH UNPACKING


/**
 * @brief Get field index from wk_gnss_signal_strength message
 *
 * @return  gnss index in fc system
 */
static inline uint8_t mavlink_msg_wk_gnss_signal_strength_get_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field gnss_type from wk_gnss_signal_strength message
 *
 * @return  0:general gps,1:rtk
 */
static inline uint8_t mavlink_msg_wk_gnss_signal_strength_get_gnss_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field sv_nums from wk_gnss_signal_strength message
 *
 * @return  satallite numbers
 */
static inline uint8_t mavlink_msg_wk_gnss_signal_strength_get_sv_nums(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field sv_id from wk_gnss_signal_strength message
 *
 * @return  satallite id(see WK_GNSS_SVID_ENUM)
 */
static inline uint16_t mavlink_msg_wk_gnss_signal_strength_get_sv_id(const mavlink_message_t* msg, uint8_t *sv_id)
{
    return _MAV_RETURN_uint8_t_array(msg, sv_id, 80,  3);
}

/**
 * @brief Get field sig_id from wk_gnss_signal_strength message
 *
 * @return  signal id(frequency id,see WK_GNSS_SIGID_ENUM)
 */
static inline uint16_t mavlink_msg_wk_gnss_signal_strength_get_sig_id(const mavlink_message_t* msg, uint8_t *sig_id)
{
    return _MAV_RETURN_uint8_t_array(msg, sig_id, 80,  83);
}

/**
 * @brief Get field cno from wk_gnss_signal_strength message
 *
 * @return  carrier to noise ratio(signal strength)
 */
static inline uint16_t mavlink_msg_wk_gnss_signal_strength_get_cno(const mavlink_message_t* msg, uint8_t *cno)
{
    return _MAV_RETURN_uint8_t_array(msg, cno, 80,  163);
}

/**
 * @brief Decode a wk_gnss_signal_strength message into a struct
 *
 * @param msg The message to decode
 * @param wk_gnss_signal_strength C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_gnss_signal_strength_decode(const mavlink_message_t* msg, mavlink_wk_gnss_signal_strength_t* wk_gnss_signal_strength)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_gnss_signal_strength->index = mavlink_msg_wk_gnss_signal_strength_get_index(msg);
    wk_gnss_signal_strength->gnss_type = mavlink_msg_wk_gnss_signal_strength_get_gnss_type(msg);
    wk_gnss_signal_strength->sv_nums = mavlink_msg_wk_gnss_signal_strength_get_sv_nums(msg);
    mavlink_msg_wk_gnss_signal_strength_get_sv_id(msg, wk_gnss_signal_strength->sv_id);
    mavlink_msg_wk_gnss_signal_strength_get_sig_id(msg, wk_gnss_signal_strength->sig_id);
    mavlink_msg_wk_gnss_signal_strength_get_cno(msg, wk_gnss_signal_strength->cno);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN? msg->len : MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN;
        memset(wk_gnss_signal_strength, 0, MAVLINK_MSG_ID_WK_GNSS_SIGNAL_STRENGTH_LEN);
    memcpy(wk_gnss_signal_strength, _MAV_PAYLOAD(msg), len);
#endif
}
