#pragma once
// MESSAGE WK_TOF_CALI_VALUE PACKING

#define MAVLINK_MSG_ID_WK_TOF_CALI_VALUE 8522


typedef struct __mavlink_wk_tof_cali_value_t {
 uint8_t type; /*<  */
 uint8_t temp_reg_31; /*<  */
 uint8_t temp_reg_34; /*<  */
 uint8_t temp_reg_33; /*<  */
 uint8_t temp_reg_39; /*<  */
 uint8_t light_reg_36; /*<  */
 uint8_t light_reg_33; /*<  */
 uint8_t light_reg_3B; /*<  */
} mavlink_wk_tof_cali_value_t;

#define MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN 8
#define MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_MIN_LEN 8
#define MAVLINK_MSG_ID_8522_LEN 8
#define MAVLINK_MSG_ID_8522_MIN_LEN 8

#define MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_CRC 251
#define MAVLINK_MSG_ID_8522_CRC 251



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_TOF_CALI_VALUE { \
    8522, \
    "WK_TOF_CALI_VALUE", \
    8, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_tof_cali_value_t, type) }, \
         { "temp_reg_31", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_tof_cali_value_t, temp_reg_31) }, \
         { "temp_reg_34", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_tof_cali_value_t, temp_reg_34) }, \
         { "temp_reg_33", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_tof_cali_value_t, temp_reg_33) }, \
         { "temp_reg_39", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_tof_cali_value_t, temp_reg_39) }, \
         { "light_reg_36", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_tof_cali_value_t, light_reg_36) }, \
         { "light_reg_33", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_tof_cali_value_t, light_reg_33) }, \
         { "light_reg_3B", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_wk_tof_cali_value_t, light_reg_3B) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_TOF_CALI_VALUE { \
    "WK_TOF_CALI_VALUE", \
    8, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wk_tof_cali_value_t, type) }, \
         { "temp_reg_31", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_wk_tof_cali_value_t, temp_reg_31) }, \
         { "temp_reg_34", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_wk_tof_cali_value_t, temp_reg_34) }, \
         { "temp_reg_33", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_wk_tof_cali_value_t, temp_reg_33) }, \
         { "temp_reg_39", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_wk_tof_cali_value_t, temp_reg_39) }, \
         { "light_reg_36", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_wk_tof_cali_value_t, light_reg_36) }, \
         { "light_reg_33", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_wk_tof_cali_value_t, light_reg_33) }, \
         { "light_reg_3B", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_wk_tof_cali_value_t, light_reg_3B) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_tof_cali_value message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type  
 * @param temp_reg_31  
 * @param temp_reg_34  
 * @param temp_reg_33  
 * @param temp_reg_39  
 * @param light_reg_36  
 * @param light_reg_33  
 * @param light_reg_3B  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_tof_cali_value_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t type, uint8_t temp_reg_31, uint8_t temp_reg_34, uint8_t temp_reg_33, uint8_t temp_reg_39, uint8_t light_reg_36, uint8_t light_reg_33, uint8_t light_reg_3B)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, temp_reg_31);
    _mav_put_uint8_t(buf, 2, temp_reg_34);
    _mav_put_uint8_t(buf, 3, temp_reg_33);
    _mav_put_uint8_t(buf, 4, temp_reg_39);
    _mav_put_uint8_t(buf, 5, light_reg_36);
    _mav_put_uint8_t(buf, 6, light_reg_33);
    _mav_put_uint8_t(buf, 7, light_reg_3B);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN);
#else
    mavlink_wk_tof_cali_value_t packet;
    packet.type = type;
    packet.temp_reg_31 = temp_reg_31;
    packet.temp_reg_34 = temp_reg_34;
    packet.temp_reg_33 = temp_reg_33;
    packet.temp_reg_39 = temp_reg_39;
    packet.light_reg_36 = light_reg_36;
    packet.light_reg_33 = light_reg_33;
    packet.light_reg_3B = light_reg_3B;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_TOF_CALI_VALUE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_CRC);
}

/**
 * @brief Pack a wk_tof_cali_value message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type  
 * @param temp_reg_31  
 * @param temp_reg_34  
 * @param temp_reg_33  
 * @param temp_reg_39  
 * @param light_reg_36  
 * @param light_reg_33  
 * @param light_reg_3B  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_tof_cali_value_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t type,uint8_t temp_reg_31,uint8_t temp_reg_34,uint8_t temp_reg_33,uint8_t temp_reg_39,uint8_t light_reg_36,uint8_t light_reg_33,uint8_t light_reg_3B)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, temp_reg_31);
    _mav_put_uint8_t(buf, 2, temp_reg_34);
    _mav_put_uint8_t(buf, 3, temp_reg_33);
    _mav_put_uint8_t(buf, 4, temp_reg_39);
    _mav_put_uint8_t(buf, 5, light_reg_36);
    _mav_put_uint8_t(buf, 6, light_reg_33);
    _mav_put_uint8_t(buf, 7, light_reg_3B);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN);
#else
    mavlink_wk_tof_cali_value_t packet;
    packet.type = type;
    packet.temp_reg_31 = temp_reg_31;
    packet.temp_reg_34 = temp_reg_34;
    packet.temp_reg_33 = temp_reg_33;
    packet.temp_reg_39 = temp_reg_39;
    packet.light_reg_36 = light_reg_36;
    packet.light_reg_33 = light_reg_33;
    packet.light_reg_3B = light_reg_3B;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_TOF_CALI_VALUE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_CRC);
}

/**
 * @brief Encode a wk_tof_cali_value struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_tof_cali_value C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_tof_cali_value_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_tof_cali_value_t* wk_tof_cali_value)
{
    return mavlink_msg_wk_tof_cali_value_pack(system_id, component_id, msg, wk_tof_cali_value->type, wk_tof_cali_value->temp_reg_31, wk_tof_cali_value->temp_reg_34, wk_tof_cali_value->temp_reg_33, wk_tof_cali_value->temp_reg_39, wk_tof_cali_value->light_reg_36, wk_tof_cali_value->light_reg_33, wk_tof_cali_value->light_reg_3B);
}

/**
 * @brief Encode a wk_tof_cali_value struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_tof_cali_value C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_tof_cali_value_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_tof_cali_value_t* wk_tof_cali_value)
{
    return mavlink_msg_wk_tof_cali_value_pack_chan(system_id, component_id, chan, msg, wk_tof_cali_value->type, wk_tof_cali_value->temp_reg_31, wk_tof_cali_value->temp_reg_34, wk_tof_cali_value->temp_reg_33, wk_tof_cali_value->temp_reg_39, wk_tof_cali_value->light_reg_36, wk_tof_cali_value->light_reg_33, wk_tof_cali_value->light_reg_3B);
}

/**
 * @brief Send a wk_tof_cali_value message
 * @param chan MAVLink channel to send the message
 *
 * @param type  
 * @param temp_reg_31  
 * @param temp_reg_34  
 * @param temp_reg_33  
 * @param temp_reg_39  
 * @param light_reg_36  
 * @param light_reg_33  
 * @param light_reg_3B  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_tof_cali_value_send(mavlink_channel_t chan, uint8_t type, uint8_t temp_reg_31, uint8_t temp_reg_34, uint8_t temp_reg_33, uint8_t temp_reg_39, uint8_t light_reg_36, uint8_t light_reg_33, uint8_t light_reg_3B)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN];
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, temp_reg_31);
    _mav_put_uint8_t(buf, 2, temp_reg_34);
    _mav_put_uint8_t(buf, 3, temp_reg_33);
    _mav_put_uint8_t(buf, 4, temp_reg_39);
    _mav_put_uint8_t(buf, 5, light_reg_36);
    _mav_put_uint8_t(buf, 6, light_reg_33);
    _mav_put_uint8_t(buf, 7, light_reg_3B);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE, buf, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_CRC);
#else
    mavlink_wk_tof_cali_value_t packet;
    packet.type = type;
    packet.temp_reg_31 = temp_reg_31;
    packet.temp_reg_34 = temp_reg_34;
    packet.temp_reg_33 = temp_reg_33;
    packet.temp_reg_39 = temp_reg_39;
    packet.light_reg_36 = light_reg_36;
    packet.light_reg_33 = light_reg_33;
    packet.light_reg_3B = light_reg_3B;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE, (const char *)&packet, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_CRC);
#endif
}

/**
 * @brief Send a wk_tof_cali_value message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_tof_cali_value_send_struct(mavlink_channel_t chan, const mavlink_wk_tof_cali_value_t* wk_tof_cali_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_tof_cali_value_send(chan, wk_tof_cali_value->type, wk_tof_cali_value->temp_reg_31, wk_tof_cali_value->temp_reg_34, wk_tof_cali_value->temp_reg_33, wk_tof_cali_value->temp_reg_39, wk_tof_cali_value->light_reg_36, wk_tof_cali_value->light_reg_33, wk_tof_cali_value->light_reg_3B);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE, (const char *)wk_tof_cali_value, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_tof_cali_value_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t type, uint8_t temp_reg_31, uint8_t temp_reg_34, uint8_t temp_reg_33, uint8_t temp_reg_39, uint8_t light_reg_36, uint8_t light_reg_33, uint8_t light_reg_3B)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, type);
    _mav_put_uint8_t(buf, 1, temp_reg_31);
    _mav_put_uint8_t(buf, 2, temp_reg_34);
    _mav_put_uint8_t(buf, 3, temp_reg_33);
    _mav_put_uint8_t(buf, 4, temp_reg_39);
    _mav_put_uint8_t(buf, 5, light_reg_36);
    _mav_put_uint8_t(buf, 6, light_reg_33);
    _mav_put_uint8_t(buf, 7, light_reg_3B);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE, buf, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_CRC);
#else
    mavlink_wk_tof_cali_value_t *packet = (mavlink_wk_tof_cali_value_t *)msgbuf;
    packet->type = type;
    packet->temp_reg_31 = temp_reg_31;
    packet->temp_reg_34 = temp_reg_34;
    packet->temp_reg_33 = temp_reg_33;
    packet->temp_reg_39 = temp_reg_39;
    packet->light_reg_36 = light_reg_36;
    packet->light_reg_33 = light_reg_33;
    packet->light_reg_3B = light_reg_3B;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE, (const char *)packet, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_MIN_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_TOF_CALI_VALUE UNPACKING


/**
 * @brief Get field type from wk_tof_cali_value message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_cali_value_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field temp_reg_31 from wk_tof_cali_value message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_cali_value_get_temp_reg_31(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field temp_reg_34 from wk_tof_cali_value message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_cali_value_get_temp_reg_34(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field temp_reg_33 from wk_tof_cali_value message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_cali_value_get_temp_reg_33(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field temp_reg_39 from wk_tof_cali_value message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_cali_value_get_temp_reg_39(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field light_reg_36 from wk_tof_cali_value message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_cali_value_get_light_reg_36(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field light_reg_33 from wk_tof_cali_value message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_cali_value_get_light_reg_33(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field light_reg_3B from wk_tof_cali_value message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_tof_cali_value_get_light_reg_3B(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Decode a wk_tof_cali_value message into a struct
 *
 * @param msg The message to decode
 * @param wk_tof_cali_value C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_tof_cali_value_decode(const mavlink_message_t* msg, mavlink_wk_tof_cali_value_t* wk_tof_cali_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_tof_cali_value->type = mavlink_msg_wk_tof_cali_value_get_type(msg);
    wk_tof_cali_value->temp_reg_31 = mavlink_msg_wk_tof_cali_value_get_temp_reg_31(msg);
    wk_tof_cali_value->temp_reg_34 = mavlink_msg_wk_tof_cali_value_get_temp_reg_34(msg);
    wk_tof_cali_value->temp_reg_33 = mavlink_msg_wk_tof_cali_value_get_temp_reg_33(msg);
    wk_tof_cali_value->temp_reg_39 = mavlink_msg_wk_tof_cali_value_get_temp_reg_39(msg);
    wk_tof_cali_value->light_reg_36 = mavlink_msg_wk_tof_cali_value_get_light_reg_36(msg);
    wk_tof_cali_value->light_reg_33 = mavlink_msg_wk_tof_cali_value_get_light_reg_33(msg);
    wk_tof_cali_value->light_reg_3B = mavlink_msg_wk_tof_cali_value_get_light_reg_3B(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN? msg->len : MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN;
        memset(wk_tof_cali_value, 0, MAVLINK_MSG_ID_WK_TOF_CALI_VALUE_LEN);
    memcpy(wk_tof_cali_value, _MAV_PAYLOAD(msg), len);
#endif
}
