#pragma once
// MESSAGE WK_PARAM_VALUE PACKING

#define MAVLINK_MSG_ID_WK_PARAM_VALUE 8030


typedef struct __mavlink_wk_param_value_t {
 float param_value; /*<  Onboard parameter value*/
 float param_maximum; /*<  Onboard parameter maximum value*/
 float param_minimum; /*<  Onboard parameter minimum value*/
 uint16_t param_count; /*<  Total number of onboard parameters*/
 uint16_t param_index; /*<  Index of this onboard parameter*/
 char param_id[16]; /*<  Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string*/
 uint8_t attribute; /*<  Onboard parameter attribute(1:PARAM_RDWR,2:PARAM_RDONLY,4:PARAM_NOT_COVERED)*/
 uint8_t param_type; /*<  Onboard parameter type.*/
} mavlink_wk_param_value_t;

#define MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN 34
#define MAVLINK_MSG_ID_WK_PARAM_VALUE_MIN_LEN 34
#define MAVLINK_MSG_ID_8030_LEN 34
#define MAVLINK_MSG_ID_8030_MIN_LEN 34

#define MAVLINK_MSG_ID_WK_PARAM_VALUE_CRC 119
#define MAVLINK_MSG_ID_8030_CRC 119

#define MAVLINK_MSG_WK_PARAM_VALUE_FIELD_PARAM_ID_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_PARAM_VALUE { \
    8030, \
    "WK_PARAM_VALUE", \
    8, \
    {  { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 16, offsetof(mavlink_wk_param_value_t, param_id) }, \
         { "param_value", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_param_value_t, param_value) }, \
         { "param_maximum", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_param_value_t, param_maximum) }, \
         { "param_minimum", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_param_value_t, param_minimum) }, \
         { "attribute", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_wk_param_value_t, attribute) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_wk_param_value_t, param_type) }, \
         { "param_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_wk_param_value_t, param_count) }, \
         { "param_index", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_wk_param_value_t, param_index) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_PARAM_VALUE { \
    "WK_PARAM_VALUE", \
    8, \
    {  { "param_id", NULL, MAVLINK_TYPE_CHAR, 16, 16, offsetof(mavlink_wk_param_value_t, param_id) }, \
         { "param_value", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_wk_param_value_t, param_value) }, \
         { "param_maximum", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_wk_param_value_t, param_maximum) }, \
         { "param_minimum", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_param_value_t, param_minimum) }, \
         { "attribute", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_wk_param_value_t, attribute) }, \
         { "param_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_wk_param_value_t, param_type) }, \
         { "param_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_wk_param_value_t, param_count) }, \
         { "param_index", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_wk_param_value_t, param_index) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_param_value message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param param_id  Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_value  Onboard parameter value
 * @param param_maximum  Onboard parameter maximum value
 * @param param_minimum  Onboard parameter minimum value
 * @param attribute  Onboard parameter attribute(1:PARAM_RDWR,2:PARAM_RDONLY,4:PARAM_NOT_COVERED)
 * @param param_type  Onboard parameter type.
 * @param param_count  Total number of onboard parameters
 * @param param_index  Index of this onboard parameter
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_param_value_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *param_id, float param_value, float param_maximum, float param_minimum, uint8_t attribute, uint8_t param_type, uint16_t param_count, uint16_t param_index)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN];
    _mav_put_float(buf, 0, param_value);
    _mav_put_float(buf, 4, param_maximum);
    _mav_put_float(buf, 8, param_minimum);
    _mav_put_uint16_t(buf, 12, param_count);
    _mav_put_uint16_t(buf, 14, param_index);
    _mav_put_uint8_t(buf, 32, attribute);
    _mav_put_uint8_t(buf, 33, param_type);
    _mav_put_char_array(buf, 16, param_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN);
#else
    mavlink_wk_param_value_t packet;
    packet.param_value = param_value;
    packet.param_maximum = param_maximum;
    packet.param_minimum = param_minimum;
    packet.param_count = param_count;
    packet.param_index = param_index;
    packet.attribute = attribute;
    packet.param_type = param_type;
    mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_PARAM_VALUE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_PARAM_VALUE_MIN_LEN, MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN, MAVLINK_MSG_ID_WK_PARAM_VALUE_CRC);
}

/**
 * @brief Pack a wk_param_value message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param param_id  Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_value  Onboard parameter value
 * @param param_maximum  Onboard parameter maximum value
 * @param param_minimum  Onboard parameter minimum value
 * @param attribute  Onboard parameter attribute(1:PARAM_RDWR,2:PARAM_RDONLY,4:PARAM_NOT_COVERED)
 * @param param_type  Onboard parameter type.
 * @param param_count  Total number of onboard parameters
 * @param param_index  Index of this onboard parameter
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_param_value_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *param_id,float param_value,float param_maximum,float param_minimum,uint8_t attribute,uint8_t param_type,uint16_t param_count,uint16_t param_index)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN];
    _mav_put_float(buf, 0, param_value);
    _mav_put_float(buf, 4, param_maximum);
    _mav_put_float(buf, 8, param_minimum);
    _mav_put_uint16_t(buf, 12, param_count);
    _mav_put_uint16_t(buf, 14, param_index);
    _mav_put_uint8_t(buf, 32, attribute);
    _mav_put_uint8_t(buf, 33, param_type);
    _mav_put_char_array(buf, 16, param_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN);
#else
    mavlink_wk_param_value_t packet;
    packet.param_value = param_value;
    packet.param_maximum = param_maximum;
    packet.param_minimum = param_minimum;
    packet.param_count = param_count;
    packet.param_index = param_index;
    packet.attribute = attribute;
    packet.param_type = param_type;
    mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_PARAM_VALUE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_PARAM_VALUE_MIN_LEN, MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN, MAVLINK_MSG_ID_WK_PARAM_VALUE_CRC);
}

/**
 * @brief Encode a wk_param_value struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_param_value C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_param_value_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_param_value_t* wk_param_value)
{
    return mavlink_msg_wk_param_value_pack(system_id, component_id, msg, wk_param_value->param_id, wk_param_value->param_value, wk_param_value->param_maximum, wk_param_value->param_minimum, wk_param_value->attribute, wk_param_value->param_type, wk_param_value->param_count, wk_param_value->param_index);
}

/**
 * @brief Encode a wk_param_value struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_param_value C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_param_value_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_param_value_t* wk_param_value)
{
    return mavlink_msg_wk_param_value_pack_chan(system_id, component_id, chan, msg, wk_param_value->param_id, wk_param_value->param_value, wk_param_value->param_maximum, wk_param_value->param_minimum, wk_param_value->attribute, wk_param_value->param_type, wk_param_value->param_count, wk_param_value->param_index);
}

/**
 * @brief Send a wk_param_value message
 * @param chan MAVLink channel to send the message
 *
 * @param param_id  Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 * @param param_value  Onboard parameter value
 * @param param_maximum  Onboard parameter maximum value
 * @param param_minimum  Onboard parameter minimum value
 * @param attribute  Onboard parameter attribute(1:PARAM_RDWR,2:PARAM_RDONLY,4:PARAM_NOT_COVERED)
 * @param param_type  Onboard parameter type.
 * @param param_count  Total number of onboard parameters
 * @param param_index  Index of this onboard parameter
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_param_value_send(mavlink_channel_t chan, const char *param_id, float param_value, float param_maximum, float param_minimum, uint8_t attribute, uint8_t param_type, uint16_t param_count, uint16_t param_index)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN];
    _mav_put_float(buf, 0, param_value);
    _mav_put_float(buf, 4, param_maximum);
    _mav_put_float(buf, 8, param_minimum);
    _mav_put_uint16_t(buf, 12, param_count);
    _mav_put_uint16_t(buf, 14, param_index);
    _mav_put_uint8_t(buf, 32, attribute);
    _mav_put_uint8_t(buf, 33, param_type);
    _mav_put_char_array(buf, 16, param_id, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PARAM_VALUE, buf, MAVLINK_MSG_ID_WK_PARAM_VALUE_MIN_LEN, MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN, MAVLINK_MSG_ID_WK_PARAM_VALUE_CRC);
#else
    mavlink_wk_param_value_t packet;
    packet.param_value = param_value;
    packet.param_maximum = param_maximum;
    packet.param_minimum = param_minimum;
    packet.param_count = param_count;
    packet.param_index = param_index;
    packet.attribute = attribute;
    packet.param_type = param_type;
    mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PARAM_VALUE, (const char *)&packet, MAVLINK_MSG_ID_WK_PARAM_VALUE_MIN_LEN, MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN, MAVLINK_MSG_ID_WK_PARAM_VALUE_CRC);
#endif
}

/**
 * @brief Send a wk_param_value message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_param_value_send_struct(mavlink_channel_t chan, const mavlink_wk_param_value_t* wk_param_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_param_value_send(chan, wk_param_value->param_id, wk_param_value->param_value, wk_param_value->param_maximum, wk_param_value->param_minimum, wk_param_value->attribute, wk_param_value->param_type, wk_param_value->param_count, wk_param_value->param_index);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PARAM_VALUE, (const char *)wk_param_value, MAVLINK_MSG_ID_WK_PARAM_VALUE_MIN_LEN, MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN, MAVLINK_MSG_ID_WK_PARAM_VALUE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_param_value_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *param_id, float param_value, float param_maximum, float param_minimum, uint8_t attribute, uint8_t param_type, uint16_t param_count, uint16_t param_index)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, param_value);
    _mav_put_float(buf, 4, param_maximum);
    _mav_put_float(buf, 8, param_minimum);
    _mav_put_uint16_t(buf, 12, param_count);
    _mav_put_uint16_t(buf, 14, param_index);
    _mav_put_uint8_t(buf, 32, attribute);
    _mav_put_uint8_t(buf, 33, param_type);
    _mav_put_char_array(buf, 16, param_id, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PARAM_VALUE, buf, MAVLINK_MSG_ID_WK_PARAM_VALUE_MIN_LEN, MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN, MAVLINK_MSG_ID_WK_PARAM_VALUE_CRC);
#else
    mavlink_wk_param_value_t *packet = (mavlink_wk_param_value_t *)msgbuf;
    packet->param_value = param_value;
    packet->param_maximum = param_maximum;
    packet->param_minimum = param_minimum;
    packet->param_count = param_count;
    packet->param_index = param_index;
    packet->attribute = attribute;
    packet->param_type = param_type;
    mav_array_memcpy(packet->param_id, param_id, sizeof(char)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_PARAM_VALUE, (const char *)packet, MAVLINK_MSG_ID_WK_PARAM_VALUE_MIN_LEN, MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN, MAVLINK_MSG_ID_WK_PARAM_VALUE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_PARAM_VALUE UNPACKING


/**
 * @brief Get field param_id from wk_param_value message
 *
 * @return  Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
 */
static inline uint16_t mavlink_msg_wk_param_value_get_param_id(const mavlink_message_t* msg, char *param_id)
{
    return _MAV_RETURN_char_array(msg, param_id, 16,  16);
}

/**
 * @brief Get field param_value from wk_param_value message
 *
 * @return  Onboard parameter value
 */
static inline float mavlink_msg_wk_param_value_get_param_value(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param_maximum from wk_param_value message
 *
 * @return  Onboard parameter maximum value
 */
static inline float mavlink_msg_wk_param_value_get_param_maximum(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param_minimum from wk_param_value message
 *
 * @return  Onboard parameter minimum value
 */
static inline float mavlink_msg_wk_param_value_get_param_minimum(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field attribute from wk_param_value message
 *
 * @return  Onboard parameter attribute(1:PARAM_RDWR,2:PARAM_RDONLY,4:PARAM_NOT_COVERED)
 */
static inline uint8_t mavlink_msg_wk_param_value_get_attribute(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field param_type from wk_param_value message
 *
 * @return  Onboard parameter type.
 */
static inline uint8_t mavlink_msg_wk_param_value_get_param_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  33);
}

/**
 * @brief Get field param_count from wk_param_value message
 *
 * @return  Total number of onboard parameters
 */
static inline uint16_t mavlink_msg_wk_param_value_get_param_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field param_index from wk_param_value message
 *
 * @return  Index of this onboard parameter
 */
static inline uint16_t mavlink_msg_wk_param_value_get_param_index(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Decode a wk_param_value message into a struct
 *
 * @param msg The message to decode
 * @param wk_param_value C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_param_value_decode(const mavlink_message_t* msg, mavlink_wk_param_value_t* wk_param_value)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_param_value->param_value = mavlink_msg_wk_param_value_get_param_value(msg);
    wk_param_value->param_maximum = mavlink_msg_wk_param_value_get_param_maximum(msg);
    wk_param_value->param_minimum = mavlink_msg_wk_param_value_get_param_minimum(msg);
    wk_param_value->param_count = mavlink_msg_wk_param_value_get_param_count(msg);
    wk_param_value->param_index = mavlink_msg_wk_param_value_get_param_index(msg);
    mavlink_msg_wk_param_value_get_param_id(msg, wk_param_value->param_id);
    wk_param_value->attribute = mavlink_msg_wk_param_value_get_attribute(msg);
    wk_param_value->param_type = mavlink_msg_wk_param_value_get_param_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN? msg->len : MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN;
        memset(wk_param_value, 0, MAVLINK_MSG_ID_WK_PARAM_VALUE_LEN);
    memcpy(wk_param_value, _MAV_PAYLOAD(msg), len);
#endif
}
