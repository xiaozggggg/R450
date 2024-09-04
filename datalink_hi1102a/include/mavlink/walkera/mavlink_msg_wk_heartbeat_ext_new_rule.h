#pragma once
// MESSAGE WK_HEARTBEAT_EXT_NEW_RULE PACKING

#define MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE 8027


typedef struct __mavlink_wk_heartbeat_ext_new_rule_t {
 uint32_t custom_mode; /*<  A bitfield for use for autopilot-specific flags*/
 uint32_t active_timestamps; /*<  active timestamps*/
 float version; /*<  product version*/
 float build_date; /*<  build date*/
 uint16_t product_type; /*<  product type*/
 uint16_t product_subtype; /*<  product subtype*/
 uint8_t type; /*<  Vehicle or component type. For a flight controller component the vehicle type (quadrotor, helicopter, etc.). For other components the component type (e.g. camera, gimbal, etc.). This should be used in preference to component id for identifying the component type.*/
 uint8_t autopilot; /*<  Autopilot type / class. Use MAV_AUTOPILOT_INVALID for components that are not flight controllers.*/
 uint8_t base_mode; /*<  System mode bitmap.*/
 uint8_t system_status; /*<  System status flag.*/
 uint8_t mavlink_version; /*<  MAVLink version, not writable by user, gets added by protocol because of magic data type: uint8_t_mavlink_version*/
 uint8_t user_name[32]; /*<  user name*/
 uint8_t product_id_len; /*<  product id len*/
 uint8_t product_id[30]; /*<  product id*/
 uint8_t activated; /*<  0:unactivated,1:activated*/
 uint8_t bound; /*<  0:not bound,1:bound*/
 uint8_t locked; /*<  0:not locked,1:locked*/
} mavlink_wk_heartbeat_ext_new_rule_t;

#define MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN 91
#define MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_MIN_LEN 91
#define MAVLINK_MSG_ID_8027_LEN 91
#define MAVLINK_MSG_ID_8027_MIN_LEN 91

#define MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_CRC 103
#define MAVLINK_MSG_ID_8027_CRC 103

#define MAVLINK_MSG_WK_HEARTBEAT_EXT_NEW_RULE_FIELD_USER_NAME_LEN 32
#define MAVLINK_MSG_WK_HEARTBEAT_EXT_NEW_RULE_FIELD_PRODUCT_ID_LEN 30

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_HEARTBEAT_EXT_NEW_RULE { \
    8027, \
    "WK_HEARTBEAT_EXT_NEW_RULE", \
    17, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, type) }, \
         { "autopilot", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, autopilot) }, \
         { "base_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, base_mode) }, \
         { "custom_mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, custom_mode) }, \
         { "system_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 23, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, system_status) }, \
         { "mavlink_version", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, mavlink_version) }, \
         { "active_timestamps", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, active_timestamps) }, \
         { "product_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, product_type) }, \
         { "product_subtype", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, product_subtype) }, \
         { "version", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, version) }, \
         { "build_date", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, build_date) }, \
         { "user_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 25, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, user_name) }, \
         { "product_id_len", NULL, MAVLINK_TYPE_UINT8_T, 0, 57, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, product_id_len) }, \
         { "product_id", NULL, MAVLINK_TYPE_UINT8_T, 30, 58, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, product_id) }, \
         { "activated", NULL, MAVLINK_TYPE_UINT8_T, 0, 88, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, activated) }, \
         { "bound", NULL, MAVLINK_TYPE_UINT8_T, 0, 89, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, bound) }, \
         { "locked", NULL, MAVLINK_TYPE_UINT8_T, 0, 90, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, locked) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_HEARTBEAT_EXT_NEW_RULE { \
    "WK_HEARTBEAT_EXT_NEW_RULE", \
    17, \
    {  { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, type) }, \
         { "autopilot", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, autopilot) }, \
         { "base_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, base_mode) }, \
         { "custom_mode", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, custom_mode) }, \
         { "system_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 23, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, system_status) }, \
         { "mavlink_version", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, mavlink_version) }, \
         { "active_timestamps", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, active_timestamps) }, \
         { "product_type", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, product_type) }, \
         { "product_subtype", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, product_subtype) }, \
         { "version", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, version) }, \
         { "build_date", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, build_date) }, \
         { "user_name", NULL, MAVLINK_TYPE_UINT8_T, 32, 25, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, user_name) }, \
         { "product_id_len", NULL, MAVLINK_TYPE_UINT8_T, 0, 57, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, product_id_len) }, \
         { "product_id", NULL, MAVLINK_TYPE_UINT8_T, 30, 58, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, product_id) }, \
         { "activated", NULL, MAVLINK_TYPE_UINT8_T, 0, 88, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, activated) }, \
         { "bound", NULL, MAVLINK_TYPE_UINT8_T, 0, 89, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, bound) }, \
         { "locked", NULL, MAVLINK_TYPE_UINT8_T, 0, 90, offsetof(mavlink_wk_heartbeat_ext_new_rule_t, locked) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_heartbeat_ext_new_rule message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param type  Vehicle or component type. For a flight controller component the vehicle type (quadrotor, helicopter, etc.). For other components the component type (e.g. camera, gimbal, etc.). This should be used in preference to component id for identifying the component type.
 * @param autopilot  Autopilot type / class. Use MAV_AUTOPILOT_INVALID for components that are not flight controllers.
 * @param base_mode  System mode bitmap.
 * @param custom_mode  A bitfield for use for autopilot-specific flags
 * @param system_status  System status flag.
 * @param mavlink_version  MAVLink version, not writable by user, gets added by protocol because of magic data type: uint8_t_mavlink_version
 * @param active_timestamps  active timestamps
 * @param product_type  product type
 * @param product_subtype  product subtype
 * @param version  product version
 * @param build_date  build date
 * @param user_name  user name
 * @param product_id_len  product id len
 * @param product_id  product id
 * @param activated  0:unactivated,1:activated
 * @param bound  0:not bound,1:bound
 * @param locked  0:not locked,1:locked
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_heartbeat_ext_new_rule_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t type, uint8_t autopilot, uint8_t base_mode, uint32_t custom_mode, uint8_t system_status, uint8_t mavlink_version, uint32_t active_timestamps, uint16_t product_type, uint16_t product_subtype, float version, float build_date, const uint8_t *user_name, uint8_t product_id_len, const uint8_t *product_id, uint8_t activated, uint8_t bound, uint8_t locked)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN];
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint32_t(buf, 4, active_timestamps);
    _mav_put_float(buf, 8, version);
    _mav_put_float(buf, 12, build_date);
    _mav_put_uint16_t(buf, 16, product_type);
    _mav_put_uint16_t(buf, 18, product_subtype);
    _mav_put_uint8_t(buf, 20, type);
    _mav_put_uint8_t(buf, 21, autopilot);
    _mav_put_uint8_t(buf, 22, base_mode);
    _mav_put_uint8_t(buf, 23, system_status);
    _mav_put_uint8_t(buf, 24, mavlink_version);
    _mav_put_uint8_t(buf, 57, product_id_len);
    _mav_put_uint8_t(buf, 88, activated);
    _mav_put_uint8_t(buf, 89, bound);
    _mav_put_uint8_t(buf, 90, locked);
    _mav_put_uint8_t_array(buf, 25, user_name, 32);
    _mav_put_uint8_t_array(buf, 58, product_id, 30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN);
#else
    mavlink_wk_heartbeat_ext_new_rule_t packet;
    packet.custom_mode = custom_mode;
    packet.active_timestamps = active_timestamps;
    packet.version = version;
    packet.build_date = build_date;
    packet.product_type = product_type;
    packet.product_subtype = product_subtype;
    packet.type = type;
    packet.autopilot = autopilot;
    packet.base_mode = base_mode;
    packet.system_status = system_status;
    packet.mavlink_version = mavlink_version;
    packet.product_id_len = product_id_len;
    packet.activated = activated;
    packet.bound = bound;
    packet.locked = locked;
    mav_array_memcpy(packet.user_name, user_name, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.product_id, product_id, sizeof(uint8_t)*30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_MIN_LEN, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_CRC);
}

/**
 * @brief Pack a wk_heartbeat_ext_new_rule message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param type  Vehicle or component type. For a flight controller component the vehicle type (quadrotor, helicopter, etc.). For other components the component type (e.g. camera, gimbal, etc.). This should be used in preference to component id for identifying the component type.
 * @param autopilot  Autopilot type / class. Use MAV_AUTOPILOT_INVALID for components that are not flight controllers.
 * @param base_mode  System mode bitmap.
 * @param custom_mode  A bitfield for use for autopilot-specific flags
 * @param system_status  System status flag.
 * @param mavlink_version  MAVLink version, not writable by user, gets added by protocol because of magic data type: uint8_t_mavlink_version
 * @param active_timestamps  active timestamps
 * @param product_type  product type
 * @param product_subtype  product subtype
 * @param version  product version
 * @param build_date  build date
 * @param user_name  user name
 * @param product_id_len  product id len
 * @param product_id  product id
 * @param activated  0:unactivated,1:activated
 * @param bound  0:not bound,1:bound
 * @param locked  0:not locked,1:locked
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_heartbeat_ext_new_rule_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t type,uint8_t autopilot,uint8_t base_mode,uint32_t custom_mode,uint8_t system_status,uint8_t mavlink_version,uint32_t active_timestamps,uint16_t product_type,uint16_t product_subtype,float version,float build_date,const uint8_t *user_name,uint8_t product_id_len,const uint8_t *product_id,uint8_t activated,uint8_t bound,uint8_t locked)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN];
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint32_t(buf, 4, active_timestamps);
    _mav_put_float(buf, 8, version);
    _mav_put_float(buf, 12, build_date);
    _mav_put_uint16_t(buf, 16, product_type);
    _mav_put_uint16_t(buf, 18, product_subtype);
    _mav_put_uint8_t(buf, 20, type);
    _mav_put_uint8_t(buf, 21, autopilot);
    _mav_put_uint8_t(buf, 22, base_mode);
    _mav_put_uint8_t(buf, 23, system_status);
    _mav_put_uint8_t(buf, 24, mavlink_version);
    _mav_put_uint8_t(buf, 57, product_id_len);
    _mav_put_uint8_t(buf, 88, activated);
    _mav_put_uint8_t(buf, 89, bound);
    _mav_put_uint8_t(buf, 90, locked);
    _mav_put_uint8_t_array(buf, 25, user_name, 32);
    _mav_put_uint8_t_array(buf, 58, product_id, 30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN);
#else
    mavlink_wk_heartbeat_ext_new_rule_t packet;
    packet.custom_mode = custom_mode;
    packet.active_timestamps = active_timestamps;
    packet.version = version;
    packet.build_date = build_date;
    packet.product_type = product_type;
    packet.product_subtype = product_subtype;
    packet.type = type;
    packet.autopilot = autopilot;
    packet.base_mode = base_mode;
    packet.system_status = system_status;
    packet.mavlink_version = mavlink_version;
    packet.product_id_len = product_id_len;
    packet.activated = activated;
    packet.bound = bound;
    packet.locked = locked;
    mav_array_memcpy(packet.user_name, user_name, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.product_id, product_id, sizeof(uint8_t)*30);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_MIN_LEN, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_CRC);
}

/**
 * @brief Encode a wk_heartbeat_ext_new_rule struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_heartbeat_ext_new_rule C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_heartbeat_ext_new_rule_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_heartbeat_ext_new_rule_t* wk_heartbeat_ext_new_rule)
{
    return mavlink_msg_wk_heartbeat_ext_new_rule_pack(system_id, component_id, msg, wk_heartbeat_ext_new_rule->type, wk_heartbeat_ext_new_rule->autopilot, wk_heartbeat_ext_new_rule->base_mode, wk_heartbeat_ext_new_rule->custom_mode, wk_heartbeat_ext_new_rule->system_status, wk_heartbeat_ext_new_rule->mavlink_version, wk_heartbeat_ext_new_rule->active_timestamps, wk_heartbeat_ext_new_rule->product_type, wk_heartbeat_ext_new_rule->product_subtype, wk_heartbeat_ext_new_rule->version, wk_heartbeat_ext_new_rule->build_date, wk_heartbeat_ext_new_rule->user_name, wk_heartbeat_ext_new_rule->product_id_len, wk_heartbeat_ext_new_rule->product_id, wk_heartbeat_ext_new_rule->activated, wk_heartbeat_ext_new_rule->bound, wk_heartbeat_ext_new_rule->locked);
}

/**
 * @brief Encode a wk_heartbeat_ext_new_rule struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_heartbeat_ext_new_rule C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_heartbeat_ext_new_rule_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_heartbeat_ext_new_rule_t* wk_heartbeat_ext_new_rule)
{
    return mavlink_msg_wk_heartbeat_ext_new_rule_pack_chan(system_id, component_id, chan, msg, wk_heartbeat_ext_new_rule->type, wk_heartbeat_ext_new_rule->autopilot, wk_heartbeat_ext_new_rule->base_mode, wk_heartbeat_ext_new_rule->custom_mode, wk_heartbeat_ext_new_rule->system_status, wk_heartbeat_ext_new_rule->mavlink_version, wk_heartbeat_ext_new_rule->active_timestamps, wk_heartbeat_ext_new_rule->product_type, wk_heartbeat_ext_new_rule->product_subtype, wk_heartbeat_ext_new_rule->version, wk_heartbeat_ext_new_rule->build_date, wk_heartbeat_ext_new_rule->user_name, wk_heartbeat_ext_new_rule->product_id_len, wk_heartbeat_ext_new_rule->product_id, wk_heartbeat_ext_new_rule->activated, wk_heartbeat_ext_new_rule->bound, wk_heartbeat_ext_new_rule->locked);
}

/**
 * @brief Send a wk_heartbeat_ext_new_rule message
 * @param chan MAVLink channel to send the message
 *
 * @param type  Vehicle or component type. For a flight controller component the vehicle type (quadrotor, helicopter, etc.). For other components the component type (e.g. camera, gimbal, etc.). This should be used in preference to component id for identifying the component type.
 * @param autopilot  Autopilot type / class. Use MAV_AUTOPILOT_INVALID for components that are not flight controllers.
 * @param base_mode  System mode bitmap.
 * @param custom_mode  A bitfield for use for autopilot-specific flags
 * @param system_status  System status flag.
 * @param mavlink_version  MAVLink version, not writable by user, gets added by protocol because of magic data type: uint8_t_mavlink_version
 * @param active_timestamps  active timestamps
 * @param product_type  product type
 * @param product_subtype  product subtype
 * @param version  product version
 * @param build_date  build date
 * @param user_name  user name
 * @param product_id_len  product id len
 * @param product_id  product id
 * @param activated  0:unactivated,1:activated
 * @param bound  0:not bound,1:bound
 * @param locked  0:not locked,1:locked
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_heartbeat_ext_new_rule_send(mavlink_channel_t chan, uint8_t type, uint8_t autopilot, uint8_t base_mode, uint32_t custom_mode, uint8_t system_status, uint8_t mavlink_version, uint32_t active_timestamps, uint16_t product_type, uint16_t product_subtype, float version, float build_date, const uint8_t *user_name, uint8_t product_id_len, const uint8_t *product_id, uint8_t activated, uint8_t bound, uint8_t locked)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN];
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint32_t(buf, 4, active_timestamps);
    _mav_put_float(buf, 8, version);
    _mav_put_float(buf, 12, build_date);
    _mav_put_uint16_t(buf, 16, product_type);
    _mav_put_uint16_t(buf, 18, product_subtype);
    _mav_put_uint8_t(buf, 20, type);
    _mav_put_uint8_t(buf, 21, autopilot);
    _mav_put_uint8_t(buf, 22, base_mode);
    _mav_put_uint8_t(buf, 23, system_status);
    _mav_put_uint8_t(buf, 24, mavlink_version);
    _mav_put_uint8_t(buf, 57, product_id_len);
    _mav_put_uint8_t(buf, 88, activated);
    _mav_put_uint8_t(buf, 89, bound);
    _mav_put_uint8_t(buf, 90, locked);
    _mav_put_uint8_t_array(buf, 25, user_name, 32);
    _mav_put_uint8_t_array(buf, 58, product_id, 30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE, buf, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_MIN_LEN, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_CRC);
#else
    mavlink_wk_heartbeat_ext_new_rule_t packet;
    packet.custom_mode = custom_mode;
    packet.active_timestamps = active_timestamps;
    packet.version = version;
    packet.build_date = build_date;
    packet.product_type = product_type;
    packet.product_subtype = product_subtype;
    packet.type = type;
    packet.autopilot = autopilot;
    packet.base_mode = base_mode;
    packet.system_status = system_status;
    packet.mavlink_version = mavlink_version;
    packet.product_id_len = product_id_len;
    packet.activated = activated;
    packet.bound = bound;
    packet.locked = locked;
    mav_array_memcpy(packet.user_name, user_name, sizeof(uint8_t)*32);
    mav_array_memcpy(packet.product_id, product_id, sizeof(uint8_t)*30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE, (const char *)&packet, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_MIN_LEN, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_CRC);
#endif
}

/**
 * @brief Send a wk_heartbeat_ext_new_rule message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_heartbeat_ext_new_rule_send_struct(mavlink_channel_t chan, const mavlink_wk_heartbeat_ext_new_rule_t* wk_heartbeat_ext_new_rule)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_heartbeat_ext_new_rule_send(chan, wk_heartbeat_ext_new_rule->type, wk_heartbeat_ext_new_rule->autopilot, wk_heartbeat_ext_new_rule->base_mode, wk_heartbeat_ext_new_rule->custom_mode, wk_heartbeat_ext_new_rule->system_status, wk_heartbeat_ext_new_rule->mavlink_version, wk_heartbeat_ext_new_rule->active_timestamps, wk_heartbeat_ext_new_rule->product_type, wk_heartbeat_ext_new_rule->product_subtype, wk_heartbeat_ext_new_rule->version, wk_heartbeat_ext_new_rule->build_date, wk_heartbeat_ext_new_rule->user_name, wk_heartbeat_ext_new_rule->product_id_len, wk_heartbeat_ext_new_rule->product_id, wk_heartbeat_ext_new_rule->activated, wk_heartbeat_ext_new_rule->bound, wk_heartbeat_ext_new_rule->locked);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE, (const char *)wk_heartbeat_ext_new_rule, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_MIN_LEN, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_heartbeat_ext_new_rule_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t type, uint8_t autopilot, uint8_t base_mode, uint32_t custom_mode, uint8_t system_status, uint8_t mavlink_version, uint32_t active_timestamps, uint16_t product_type, uint16_t product_subtype, float version, float build_date, const uint8_t *user_name, uint8_t product_id_len, const uint8_t *product_id, uint8_t activated, uint8_t bound, uint8_t locked)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, custom_mode);
    _mav_put_uint32_t(buf, 4, active_timestamps);
    _mav_put_float(buf, 8, version);
    _mav_put_float(buf, 12, build_date);
    _mav_put_uint16_t(buf, 16, product_type);
    _mav_put_uint16_t(buf, 18, product_subtype);
    _mav_put_uint8_t(buf, 20, type);
    _mav_put_uint8_t(buf, 21, autopilot);
    _mav_put_uint8_t(buf, 22, base_mode);
    _mav_put_uint8_t(buf, 23, system_status);
    _mav_put_uint8_t(buf, 24, mavlink_version);
    _mav_put_uint8_t(buf, 57, product_id_len);
    _mav_put_uint8_t(buf, 88, activated);
    _mav_put_uint8_t(buf, 89, bound);
    _mav_put_uint8_t(buf, 90, locked);
    _mav_put_uint8_t_array(buf, 25, user_name, 32);
    _mav_put_uint8_t_array(buf, 58, product_id, 30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE, buf, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_MIN_LEN, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_CRC);
#else
    mavlink_wk_heartbeat_ext_new_rule_t *packet = (mavlink_wk_heartbeat_ext_new_rule_t *)msgbuf;
    packet->custom_mode = custom_mode;
    packet->active_timestamps = active_timestamps;
    packet->version = version;
    packet->build_date = build_date;
    packet->product_type = product_type;
    packet->product_subtype = product_subtype;
    packet->type = type;
    packet->autopilot = autopilot;
    packet->base_mode = base_mode;
    packet->system_status = system_status;
    packet->mavlink_version = mavlink_version;
    packet->product_id_len = product_id_len;
    packet->activated = activated;
    packet->bound = bound;
    packet->locked = locked;
    mav_array_memcpy(packet->user_name, user_name, sizeof(uint8_t)*32);
    mav_array_memcpy(packet->product_id, product_id, sizeof(uint8_t)*30);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE, (const char *)packet, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_MIN_LEN, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_HEARTBEAT_EXT_NEW_RULE UNPACKING


/**
 * @brief Get field type from wk_heartbeat_ext_new_rule message
 *
 * @return  Vehicle or component type. For a flight controller component the vehicle type (quadrotor, helicopter, etc.). For other components the component type (e.g. camera, gimbal, etc.). This should be used in preference to component id for identifying the component type.
 */
static inline uint8_t mavlink_msg_wk_heartbeat_ext_new_rule_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field autopilot from wk_heartbeat_ext_new_rule message
 *
 * @return  Autopilot type / class. Use MAV_AUTOPILOT_INVALID for components that are not flight controllers.
 */
static inline uint8_t mavlink_msg_wk_heartbeat_ext_new_rule_get_autopilot(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  21);
}

/**
 * @brief Get field base_mode from wk_heartbeat_ext_new_rule message
 *
 * @return  System mode bitmap.
 */
static inline uint8_t mavlink_msg_wk_heartbeat_ext_new_rule_get_base_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  22);
}

/**
 * @brief Get field custom_mode from wk_heartbeat_ext_new_rule message
 *
 * @return  A bitfield for use for autopilot-specific flags
 */
static inline uint32_t mavlink_msg_wk_heartbeat_ext_new_rule_get_custom_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field system_status from wk_heartbeat_ext_new_rule message
 *
 * @return  System status flag.
 */
static inline uint8_t mavlink_msg_wk_heartbeat_ext_new_rule_get_system_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  23);
}

/**
 * @brief Get field mavlink_version from wk_heartbeat_ext_new_rule message
 *
 * @return  MAVLink version, not writable by user, gets added by protocol because of magic data type: uint8_t_mavlink_version
 */
static inline uint8_t mavlink_msg_wk_heartbeat_ext_new_rule_get_mavlink_version(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field active_timestamps from wk_heartbeat_ext_new_rule message
 *
 * @return  active timestamps
 */
static inline uint32_t mavlink_msg_wk_heartbeat_ext_new_rule_get_active_timestamps(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field product_type from wk_heartbeat_ext_new_rule message
 *
 * @return  product type
 */
static inline uint16_t mavlink_msg_wk_heartbeat_ext_new_rule_get_product_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field product_subtype from wk_heartbeat_ext_new_rule message
 *
 * @return  product subtype
 */
static inline uint16_t mavlink_msg_wk_heartbeat_ext_new_rule_get_product_subtype(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field version from wk_heartbeat_ext_new_rule message
 *
 * @return  product version
 */
static inline float mavlink_msg_wk_heartbeat_ext_new_rule_get_version(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field build_date from wk_heartbeat_ext_new_rule message
 *
 * @return  build date
 */
static inline float mavlink_msg_wk_heartbeat_ext_new_rule_get_build_date(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field user_name from wk_heartbeat_ext_new_rule message
 *
 * @return  user name
 */
static inline uint16_t mavlink_msg_wk_heartbeat_ext_new_rule_get_user_name(const mavlink_message_t* msg, uint8_t *user_name)
{
    return _MAV_RETURN_uint8_t_array(msg, user_name, 32,  25);
}

/**
 * @brief Get field product_id_len from wk_heartbeat_ext_new_rule message
 *
 * @return  product id len
 */
static inline uint8_t mavlink_msg_wk_heartbeat_ext_new_rule_get_product_id_len(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  57);
}

/**
 * @brief Get field product_id from wk_heartbeat_ext_new_rule message
 *
 * @return  product id
 */
static inline uint16_t mavlink_msg_wk_heartbeat_ext_new_rule_get_product_id(const mavlink_message_t* msg, uint8_t *product_id)
{
    return _MAV_RETURN_uint8_t_array(msg, product_id, 30,  58);
}

/**
 * @brief Get field activated from wk_heartbeat_ext_new_rule message
 *
 * @return  0:unactivated,1:activated
 */
static inline uint8_t mavlink_msg_wk_heartbeat_ext_new_rule_get_activated(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  88);
}

/**
 * @brief Get field bound from wk_heartbeat_ext_new_rule message
 *
 * @return  0:not bound,1:bound
 */
static inline uint8_t mavlink_msg_wk_heartbeat_ext_new_rule_get_bound(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  89);
}

/**
 * @brief Get field locked from wk_heartbeat_ext_new_rule message
 *
 * @return  0:not locked,1:locked
 */
static inline uint8_t mavlink_msg_wk_heartbeat_ext_new_rule_get_locked(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  90);
}

/**
 * @brief Decode a wk_heartbeat_ext_new_rule message into a struct
 *
 * @param msg The message to decode
 * @param wk_heartbeat_ext_new_rule C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_heartbeat_ext_new_rule_decode(const mavlink_message_t* msg, mavlink_wk_heartbeat_ext_new_rule_t* wk_heartbeat_ext_new_rule)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_heartbeat_ext_new_rule->custom_mode = mavlink_msg_wk_heartbeat_ext_new_rule_get_custom_mode(msg);
    wk_heartbeat_ext_new_rule->active_timestamps = mavlink_msg_wk_heartbeat_ext_new_rule_get_active_timestamps(msg);
    wk_heartbeat_ext_new_rule->version = mavlink_msg_wk_heartbeat_ext_new_rule_get_version(msg);
    wk_heartbeat_ext_new_rule->build_date = mavlink_msg_wk_heartbeat_ext_new_rule_get_build_date(msg);
    wk_heartbeat_ext_new_rule->product_type = mavlink_msg_wk_heartbeat_ext_new_rule_get_product_type(msg);
    wk_heartbeat_ext_new_rule->product_subtype = mavlink_msg_wk_heartbeat_ext_new_rule_get_product_subtype(msg);
    wk_heartbeat_ext_new_rule->type = mavlink_msg_wk_heartbeat_ext_new_rule_get_type(msg);
    wk_heartbeat_ext_new_rule->autopilot = mavlink_msg_wk_heartbeat_ext_new_rule_get_autopilot(msg);
    wk_heartbeat_ext_new_rule->base_mode = mavlink_msg_wk_heartbeat_ext_new_rule_get_base_mode(msg);
    wk_heartbeat_ext_new_rule->system_status = mavlink_msg_wk_heartbeat_ext_new_rule_get_system_status(msg);
    wk_heartbeat_ext_new_rule->mavlink_version = mavlink_msg_wk_heartbeat_ext_new_rule_get_mavlink_version(msg);
    mavlink_msg_wk_heartbeat_ext_new_rule_get_user_name(msg, wk_heartbeat_ext_new_rule->user_name);
    wk_heartbeat_ext_new_rule->product_id_len = mavlink_msg_wk_heartbeat_ext_new_rule_get_product_id_len(msg);
    mavlink_msg_wk_heartbeat_ext_new_rule_get_product_id(msg, wk_heartbeat_ext_new_rule->product_id);
    wk_heartbeat_ext_new_rule->activated = mavlink_msg_wk_heartbeat_ext_new_rule_get_activated(msg);
    wk_heartbeat_ext_new_rule->bound = mavlink_msg_wk_heartbeat_ext_new_rule_get_bound(msg);
    wk_heartbeat_ext_new_rule->locked = mavlink_msg_wk_heartbeat_ext_new_rule_get_locked(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN? msg->len : MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN;
        memset(wk_heartbeat_ext_new_rule, 0, MAVLINK_MSG_ID_WK_HEARTBEAT_EXT_NEW_RULE_LEN);
    memcpy(wk_heartbeat_ext_new_rule, _MAV_PAYLOAD(msg), len);
#endif
}
