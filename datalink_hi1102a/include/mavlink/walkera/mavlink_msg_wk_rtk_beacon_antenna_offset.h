#pragma once
// MESSAGE WK_RTK_BEACON_ANTENNA_OFFSET PACKING

#define MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET 8029


typedef struct __mavlink_wk_rtk_beacon_antenna_offset_t {
 int32_t ant_offset_x; /*<  unit cm*/
 int32_t ant_offset_y; /*<  unit cm*/
 int32_t ant_offset_z; /*<  unit cm*/
 int32_t land_offset; /*<  unit cm*/
} mavlink_wk_rtk_beacon_antenna_offset_t;

#define MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN 16
#define MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_MIN_LEN 16
#define MAVLINK_MSG_ID_8029_LEN 16
#define MAVLINK_MSG_ID_8029_MIN_LEN 16

#define MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_CRC 79
#define MAVLINK_MSG_ID_8029_CRC 79



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_RTK_BEACON_ANTENNA_OFFSET { \
    8029, \
    "WK_RTK_BEACON_ANTENNA_OFFSET", \
    4, \
    {  { "ant_offset_x", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_wk_rtk_beacon_antenna_offset_t, ant_offset_x) }, \
         { "ant_offset_y", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_wk_rtk_beacon_antenna_offset_t, ant_offset_y) }, \
         { "ant_offset_z", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_rtk_beacon_antenna_offset_t, ant_offset_z) }, \
         { "land_offset", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_rtk_beacon_antenna_offset_t, land_offset) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_RTK_BEACON_ANTENNA_OFFSET { \
    "WK_RTK_BEACON_ANTENNA_OFFSET", \
    4, \
    {  { "ant_offset_x", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_wk_rtk_beacon_antenna_offset_t, ant_offset_x) }, \
         { "ant_offset_y", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_wk_rtk_beacon_antenna_offset_t, ant_offset_y) }, \
         { "ant_offset_z", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_rtk_beacon_antenna_offset_t, ant_offset_z) }, \
         { "land_offset", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_rtk_beacon_antenna_offset_t, land_offset) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_rtk_beacon_antenna_offset message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ant_offset_x  unit cm
 * @param ant_offset_y  unit cm
 * @param ant_offset_z  unit cm
 * @param land_offset  unit cm
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_rtk_beacon_antenna_offset_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int32_t ant_offset_x, int32_t ant_offset_y, int32_t ant_offset_z, int32_t land_offset)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN];
    _mav_put_int32_t(buf, 0, ant_offset_x);
    _mav_put_int32_t(buf, 4, ant_offset_y);
    _mav_put_int32_t(buf, 8, ant_offset_z);
    _mav_put_int32_t(buf, 12, land_offset);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN);
#else
    mavlink_wk_rtk_beacon_antenna_offset_t packet;
    packet.ant_offset_x = ant_offset_x;
    packet.ant_offset_y = ant_offset_y;
    packet.ant_offset_z = ant_offset_z;
    packet.land_offset = land_offset;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_CRC);
}

/**
 * @brief Pack a wk_rtk_beacon_antenna_offset message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ant_offset_x  unit cm
 * @param ant_offset_y  unit cm
 * @param ant_offset_z  unit cm
 * @param land_offset  unit cm
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_rtk_beacon_antenna_offset_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int32_t ant_offset_x,int32_t ant_offset_y,int32_t ant_offset_z,int32_t land_offset)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN];
    _mav_put_int32_t(buf, 0, ant_offset_x);
    _mav_put_int32_t(buf, 4, ant_offset_y);
    _mav_put_int32_t(buf, 8, ant_offset_z);
    _mav_put_int32_t(buf, 12, land_offset);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN);
#else
    mavlink_wk_rtk_beacon_antenna_offset_t packet;
    packet.ant_offset_x = ant_offset_x;
    packet.ant_offset_y = ant_offset_y;
    packet.ant_offset_z = ant_offset_z;
    packet.land_offset = land_offset;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_CRC);
}

/**
 * @brief Encode a wk_rtk_beacon_antenna_offset struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_rtk_beacon_antenna_offset C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_rtk_beacon_antenna_offset_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_rtk_beacon_antenna_offset_t* wk_rtk_beacon_antenna_offset)
{
    return mavlink_msg_wk_rtk_beacon_antenna_offset_pack(system_id, component_id, msg, wk_rtk_beacon_antenna_offset->ant_offset_x, wk_rtk_beacon_antenna_offset->ant_offset_y, wk_rtk_beacon_antenna_offset->ant_offset_z, wk_rtk_beacon_antenna_offset->land_offset);
}

/**
 * @brief Encode a wk_rtk_beacon_antenna_offset struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_rtk_beacon_antenna_offset C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_rtk_beacon_antenna_offset_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_rtk_beacon_antenna_offset_t* wk_rtk_beacon_antenna_offset)
{
    return mavlink_msg_wk_rtk_beacon_antenna_offset_pack_chan(system_id, component_id, chan, msg, wk_rtk_beacon_antenna_offset->ant_offset_x, wk_rtk_beacon_antenna_offset->ant_offset_y, wk_rtk_beacon_antenna_offset->ant_offset_z, wk_rtk_beacon_antenna_offset->land_offset);
}

/**
 * @brief Send a wk_rtk_beacon_antenna_offset message
 * @param chan MAVLink channel to send the message
 *
 * @param ant_offset_x  unit cm
 * @param ant_offset_y  unit cm
 * @param ant_offset_z  unit cm
 * @param land_offset  unit cm
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_rtk_beacon_antenna_offset_send(mavlink_channel_t chan, int32_t ant_offset_x, int32_t ant_offset_y, int32_t ant_offset_z, int32_t land_offset)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN];
    _mav_put_int32_t(buf, 0, ant_offset_x);
    _mav_put_int32_t(buf, 4, ant_offset_y);
    _mav_put_int32_t(buf, 8, ant_offset_z);
    _mav_put_int32_t(buf, 12, land_offset);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET, buf, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_CRC);
#else
    mavlink_wk_rtk_beacon_antenna_offset_t packet;
    packet.ant_offset_x = ant_offset_x;
    packet.ant_offset_y = ant_offset_y;
    packet.ant_offset_z = ant_offset_z;
    packet.land_offset = land_offset;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET, (const char *)&packet, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_CRC);
#endif
}

/**
 * @brief Send a wk_rtk_beacon_antenna_offset message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_rtk_beacon_antenna_offset_send_struct(mavlink_channel_t chan, const mavlink_wk_rtk_beacon_antenna_offset_t* wk_rtk_beacon_antenna_offset)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_rtk_beacon_antenna_offset_send(chan, wk_rtk_beacon_antenna_offset->ant_offset_x, wk_rtk_beacon_antenna_offset->ant_offset_y, wk_rtk_beacon_antenna_offset->ant_offset_z, wk_rtk_beacon_antenna_offset->land_offset);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET, (const char *)wk_rtk_beacon_antenna_offset, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_rtk_beacon_antenna_offset_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t ant_offset_x, int32_t ant_offset_y, int32_t ant_offset_z, int32_t land_offset)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, ant_offset_x);
    _mav_put_int32_t(buf, 4, ant_offset_y);
    _mav_put_int32_t(buf, 8, ant_offset_z);
    _mav_put_int32_t(buf, 12, land_offset);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET, buf, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_CRC);
#else
    mavlink_wk_rtk_beacon_antenna_offset_t *packet = (mavlink_wk_rtk_beacon_antenna_offset_t *)msgbuf;
    packet->ant_offset_x = ant_offset_x;
    packet->ant_offset_y = ant_offset_y;
    packet->ant_offset_z = ant_offset_z;
    packet->land_offset = land_offset;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET, (const char *)packet, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_RTK_BEACON_ANTENNA_OFFSET UNPACKING


/**
 * @brief Get field ant_offset_x from wk_rtk_beacon_antenna_offset message
 *
 * @return  unit cm
 */
static inline int32_t mavlink_msg_wk_rtk_beacon_antenna_offset_get_ant_offset_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field ant_offset_y from wk_rtk_beacon_antenna_offset message
 *
 * @return  unit cm
 */
static inline int32_t mavlink_msg_wk_rtk_beacon_antenna_offset_get_ant_offset_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field ant_offset_z from wk_rtk_beacon_antenna_offset message
 *
 * @return  unit cm
 */
static inline int32_t mavlink_msg_wk_rtk_beacon_antenna_offset_get_ant_offset_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field land_offset from wk_rtk_beacon_antenna_offset message
 *
 * @return  unit cm
 */
static inline int32_t mavlink_msg_wk_rtk_beacon_antenna_offset_get_land_offset(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Decode a wk_rtk_beacon_antenna_offset message into a struct
 *
 * @param msg The message to decode
 * @param wk_rtk_beacon_antenna_offset C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_rtk_beacon_antenna_offset_decode(const mavlink_message_t* msg, mavlink_wk_rtk_beacon_antenna_offset_t* wk_rtk_beacon_antenna_offset)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_rtk_beacon_antenna_offset->ant_offset_x = mavlink_msg_wk_rtk_beacon_antenna_offset_get_ant_offset_x(msg);
    wk_rtk_beacon_antenna_offset->ant_offset_y = mavlink_msg_wk_rtk_beacon_antenna_offset_get_ant_offset_y(msg);
    wk_rtk_beacon_antenna_offset->ant_offset_z = mavlink_msg_wk_rtk_beacon_antenna_offset_get_ant_offset_z(msg);
    wk_rtk_beacon_antenna_offset->land_offset = mavlink_msg_wk_rtk_beacon_antenna_offset_get_land_offset(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN? msg->len : MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN;
        memset(wk_rtk_beacon_antenna_offset, 0, MAVLINK_MSG_ID_WK_RTK_BEACON_ANTENNA_OFFSET_LEN);
    memcpy(wk_rtk_beacon_antenna_offset, _MAV_PAYLOAD(msg), len);
#endif
}
