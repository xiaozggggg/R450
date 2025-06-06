#pragma once
// MESSAGE MISSION_ITEM_INT_EXT PACKING

#define MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT 8031


typedef struct __mavlink_mission_item_int_ext_t {
 float param1; /*<  PARAM1, see MAV_CMD enum*/
 float param2; /*<  PARAM2, see MAV_CMD enum*/
 float param3; /*<  PARAM3, see MAV_CMD enum*/
 float param4; /*<  PARAM4, see MAV_CMD enum*/
 int32_t x; /*<  PARAM5 / local: x position in meters * 1e4, global: latitude in degrees * 10^7*/
 int32_t y; /*<  PARAM6 / y position: local: x position in meters * 1e4, global: longitude in degrees *10^7*/
 float z; /*<  PARAM7 / z position: global: altitude in meters (relative or absolute, depending on frame.*/
 uint16_t seq; /*<  Waypoint ID (sequence number). Starts at zero. Increases monotonically for each waypoint, no gaps in the sequence (0,1,2,3,4).*/
 uint16_t command; /*<  The scheduled action for the waypoint.*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
 uint8_t frame; /*<  The coordinate system of the waypoint.*/
 uint8_t current; /*<  false:0, true:1*/
 uint8_t autocontinue; /*<  Autocontinue to next waypoint*/
 uint8_t name[128]; /*<  target name*/
 uint8_t mission_type; /*<  Mission type.*/
} mavlink_mission_item_int_ext_t;

#define MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN 166
#define MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_MIN_LEN 165
#define MAVLINK_MSG_ID_8031_LEN 166
#define MAVLINK_MSG_ID_8031_MIN_LEN 165

#define MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_CRC 217
#define MAVLINK_MSG_ID_8031_CRC 217

#define MAVLINK_MSG_MISSION_ITEM_INT_EXT_FIELD_NAME_LEN 128

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MISSION_ITEM_INT_EXT { \
    8031, \
    "MISSION_ITEM_INT_EXT", \
    16, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_mission_item_int_ext_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_mission_item_int_ext_t, target_component) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_mission_item_int_ext_t, seq) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_mission_item_int_ext_t, frame) }, \
         { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_mission_item_int_ext_t, command) }, \
         { "current", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_mission_item_int_ext_t, current) }, \
         { "autocontinue", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_mission_item_int_ext_t, autocontinue) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_mission_item_int_ext_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_mission_item_int_ext_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_mission_item_int_ext_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_mission_item_int_ext_t, param4) }, \
         { "x", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_mission_item_int_ext_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_mission_item_int_ext_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_mission_item_int_ext_t, z) }, \
         { "name", NULL, MAVLINK_TYPE_UINT8_T, 128, 37, offsetof(mavlink_mission_item_int_ext_t, name) }, \
         { "mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 165, offsetof(mavlink_mission_item_int_ext_t, mission_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MISSION_ITEM_INT_EXT { \
    "MISSION_ITEM_INT_EXT", \
    16, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_mission_item_int_ext_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_mission_item_int_ext_t, target_component) }, \
         { "seq", NULL, MAVLINK_TYPE_UINT16_T, 0, 28, offsetof(mavlink_mission_item_int_ext_t, seq) }, \
         { "frame", NULL, MAVLINK_TYPE_UINT8_T, 0, 34, offsetof(mavlink_mission_item_int_ext_t, frame) }, \
         { "command", NULL, MAVLINK_TYPE_UINT16_T, 0, 30, offsetof(mavlink_mission_item_int_ext_t, command) }, \
         { "current", NULL, MAVLINK_TYPE_UINT8_T, 0, 35, offsetof(mavlink_mission_item_int_ext_t, current) }, \
         { "autocontinue", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_mission_item_int_ext_t, autocontinue) }, \
         { "param1", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_mission_item_int_ext_t, param1) }, \
         { "param2", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_mission_item_int_ext_t, param2) }, \
         { "param3", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_mission_item_int_ext_t, param3) }, \
         { "param4", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_mission_item_int_ext_t, param4) }, \
         { "x", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_mission_item_int_ext_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_mission_item_int_ext_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_mission_item_int_ext_t, z) }, \
         { "name", NULL, MAVLINK_TYPE_UINT8_T, 128, 37, offsetof(mavlink_mission_item_int_ext_t, name) }, \
         { "mission_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 165, offsetof(mavlink_mission_item_int_ext_t, mission_type) }, \
         } \
}
#endif

/**
 * @brief Pack a mission_item_int_ext message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param seq  Waypoint ID (sequence number). Starts at zero. Increases monotonically for each waypoint, no gaps in the sequence (0,1,2,3,4).
 * @param frame  The coordinate system of the waypoint.
 * @param command  The scheduled action for the waypoint.
 * @param current  false:0, true:1
 * @param autocontinue  Autocontinue to next waypoint
 * @param param1  PARAM1, see MAV_CMD enum
 * @param param2  PARAM2, see MAV_CMD enum
 * @param param3  PARAM3, see MAV_CMD enum
 * @param param4  PARAM4, see MAV_CMD enum
 * @param x  PARAM5 / local: x position in meters * 1e4, global: latitude in degrees * 10^7
 * @param y  PARAM6 / y position: local: x position in meters * 1e4, global: longitude in degrees *10^7
 * @param z  PARAM7 / z position: global: altitude in meters (relative or absolute, depending on frame.
 * @param name  target name
 * @param mission_type  Mission type.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_item_int_ext_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t frame, uint16_t command, uint8_t current, uint8_t autocontinue, float param1, float param2, float param3, float param4, int32_t x, int32_t y, float z, const uint8_t *name, uint8_t mission_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_int32_t(buf, 16, x);
    _mav_put_int32_t(buf, 20, y);
    _mav_put_float(buf, 24, z);
    _mav_put_uint16_t(buf, 28, seq);
    _mav_put_uint16_t(buf, 30, command);
    _mav_put_uint8_t(buf, 32, target_system);
    _mav_put_uint8_t(buf, 33, target_component);
    _mav_put_uint8_t(buf, 34, frame);
    _mav_put_uint8_t(buf, 35, current);
    _mav_put_uint8_t(buf, 36, autocontinue);
    _mav_put_uint8_t(buf, 165, mission_type);
    _mav_put_uint8_t_array(buf, 37, name, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN);
#else
    mavlink_mission_item_int_ext_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.seq = seq;
    packet.command = command;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.frame = frame;
    packet.current = current;
    packet.autocontinue = autocontinue;
    packet.mission_type = mission_type;
    mav_array_memcpy(packet.name, name, sizeof(uint8_t)*128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_MIN_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_CRC);
}

/**
 * @brief Pack a mission_item_int_ext message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param seq  Waypoint ID (sequence number). Starts at zero. Increases monotonically for each waypoint, no gaps in the sequence (0,1,2,3,4).
 * @param frame  The coordinate system of the waypoint.
 * @param command  The scheduled action for the waypoint.
 * @param current  false:0, true:1
 * @param autocontinue  Autocontinue to next waypoint
 * @param param1  PARAM1, see MAV_CMD enum
 * @param param2  PARAM2, see MAV_CMD enum
 * @param param3  PARAM3, see MAV_CMD enum
 * @param param4  PARAM4, see MAV_CMD enum
 * @param x  PARAM5 / local: x position in meters * 1e4, global: latitude in degrees * 10^7
 * @param y  PARAM6 / y position: local: x position in meters * 1e4, global: longitude in degrees *10^7
 * @param z  PARAM7 / z position: global: altitude in meters (relative or absolute, depending on frame.
 * @param name  target name
 * @param mission_type  Mission type.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mission_item_int_ext_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint16_t seq,uint8_t frame,uint16_t command,uint8_t current,uint8_t autocontinue,float param1,float param2,float param3,float param4,int32_t x,int32_t y,float z,const uint8_t *name,uint8_t mission_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_int32_t(buf, 16, x);
    _mav_put_int32_t(buf, 20, y);
    _mav_put_float(buf, 24, z);
    _mav_put_uint16_t(buf, 28, seq);
    _mav_put_uint16_t(buf, 30, command);
    _mav_put_uint8_t(buf, 32, target_system);
    _mav_put_uint8_t(buf, 33, target_component);
    _mav_put_uint8_t(buf, 34, frame);
    _mav_put_uint8_t(buf, 35, current);
    _mav_put_uint8_t(buf, 36, autocontinue);
    _mav_put_uint8_t(buf, 165, mission_type);
    _mav_put_uint8_t_array(buf, 37, name, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN);
#else
    mavlink_mission_item_int_ext_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.seq = seq;
    packet.command = command;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.frame = frame;
    packet.current = current;
    packet.autocontinue = autocontinue;
    packet.mission_type = mission_type;
    mav_array_memcpy(packet.name, name, sizeof(uint8_t)*128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_MIN_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_CRC);
}

/**
 * @brief Encode a mission_item_int_ext struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mission_item_int_ext C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_item_int_ext_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mission_item_int_ext_t* mission_item_int_ext)
{
    return mavlink_msg_mission_item_int_ext_pack(system_id, component_id, msg, mission_item_int_ext->target_system, mission_item_int_ext->target_component, mission_item_int_ext->seq, mission_item_int_ext->frame, mission_item_int_ext->command, mission_item_int_ext->current, mission_item_int_ext->autocontinue, mission_item_int_ext->param1, mission_item_int_ext->param2, mission_item_int_ext->param3, mission_item_int_ext->param4, mission_item_int_ext->x, mission_item_int_ext->y, mission_item_int_ext->z, mission_item_int_ext->name, mission_item_int_ext->mission_type);
}

/**
 * @brief Encode a mission_item_int_ext struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mission_item_int_ext C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mission_item_int_ext_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mission_item_int_ext_t* mission_item_int_ext)
{
    return mavlink_msg_mission_item_int_ext_pack_chan(system_id, component_id, chan, msg, mission_item_int_ext->target_system, mission_item_int_ext->target_component, mission_item_int_ext->seq, mission_item_int_ext->frame, mission_item_int_ext->command, mission_item_int_ext->current, mission_item_int_ext->autocontinue, mission_item_int_ext->param1, mission_item_int_ext->param2, mission_item_int_ext->param3, mission_item_int_ext->param4, mission_item_int_ext->x, mission_item_int_ext->y, mission_item_int_ext->z, mission_item_int_ext->name, mission_item_int_ext->mission_type);
}

/**
 * @brief Send a mission_item_int_ext message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param seq  Waypoint ID (sequence number). Starts at zero. Increases monotonically for each waypoint, no gaps in the sequence (0,1,2,3,4).
 * @param frame  The coordinate system of the waypoint.
 * @param command  The scheduled action for the waypoint.
 * @param current  false:0, true:1
 * @param autocontinue  Autocontinue to next waypoint
 * @param param1  PARAM1, see MAV_CMD enum
 * @param param2  PARAM2, see MAV_CMD enum
 * @param param3  PARAM3, see MAV_CMD enum
 * @param param4  PARAM4, see MAV_CMD enum
 * @param x  PARAM5 / local: x position in meters * 1e4, global: latitude in degrees * 10^7
 * @param y  PARAM6 / y position: local: x position in meters * 1e4, global: longitude in degrees *10^7
 * @param z  PARAM7 / z position: global: altitude in meters (relative or absolute, depending on frame.
 * @param name  target name
 * @param mission_type  Mission type.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mission_item_int_ext_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t frame, uint16_t command, uint8_t current, uint8_t autocontinue, float param1, float param2, float param3, float param4, int32_t x, int32_t y, float z, const uint8_t *name, uint8_t mission_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN];
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_int32_t(buf, 16, x);
    _mav_put_int32_t(buf, 20, y);
    _mav_put_float(buf, 24, z);
    _mav_put_uint16_t(buf, 28, seq);
    _mav_put_uint16_t(buf, 30, command);
    _mav_put_uint8_t(buf, 32, target_system);
    _mav_put_uint8_t(buf, 33, target_component);
    _mav_put_uint8_t(buf, 34, frame);
    _mav_put_uint8_t(buf, 35, current);
    _mav_put_uint8_t(buf, 36, autocontinue);
    _mav_put_uint8_t(buf, 165, mission_type);
    _mav_put_uint8_t_array(buf, 37, name, 128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT, buf, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_MIN_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_CRC);
#else
    mavlink_mission_item_int_ext_t packet;
    packet.param1 = param1;
    packet.param2 = param2;
    packet.param3 = param3;
    packet.param4 = param4;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.seq = seq;
    packet.command = command;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.frame = frame;
    packet.current = current;
    packet.autocontinue = autocontinue;
    packet.mission_type = mission_type;
    mav_array_memcpy(packet.name, name, sizeof(uint8_t)*128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT, (const char *)&packet, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_MIN_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_CRC);
#endif
}

/**
 * @brief Send a mission_item_int_ext message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mission_item_int_ext_send_struct(mavlink_channel_t chan, const mavlink_mission_item_int_ext_t* mission_item_int_ext)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mission_item_int_ext_send(chan, mission_item_int_ext->target_system, mission_item_int_ext->target_component, mission_item_int_ext->seq, mission_item_int_ext->frame, mission_item_int_ext->command, mission_item_int_ext->current, mission_item_int_ext->autocontinue, mission_item_int_ext->param1, mission_item_int_ext->param2, mission_item_int_ext->param3, mission_item_int_ext->param4, mission_item_int_ext->x, mission_item_int_ext->y, mission_item_int_ext->z, mission_item_int_ext->name, mission_item_int_ext->mission_type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT, (const char *)mission_item_int_ext, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_MIN_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_CRC);
#endif
}

#if MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mission_item_int_ext_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t frame, uint16_t command, uint8_t current, uint8_t autocontinue, float param1, float param2, float param3, float param4, int32_t x, int32_t y, float z, const uint8_t *name, uint8_t mission_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, param1);
    _mav_put_float(buf, 4, param2);
    _mav_put_float(buf, 8, param3);
    _mav_put_float(buf, 12, param4);
    _mav_put_int32_t(buf, 16, x);
    _mav_put_int32_t(buf, 20, y);
    _mav_put_float(buf, 24, z);
    _mav_put_uint16_t(buf, 28, seq);
    _mav_put_uint16_t(buf, 30, command);
    _mav_put_uint8_t(buf, 32, target_system);
    _mav_put_uint8_t(buf, 33, target_component);
    _mav_put_uint8_t(buf, 34, frame);
    _mav_put_uint8_t(buf, 35, current);
    _mav_put_uint8_t(buf, 36, autocontinue);
    _mav_put_uint8_t(buf, 165, mission_type);
    _mav_put_uint8_t_array(buf, 37, name, 128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT, buf, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_MIN_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_CRC);
#else
    mavlink_mission_item_int_ext_t *packet = (mavlink_mission_item_int_ext_t *)msgbuf;
    packet->param1 = param1;
    packet->param2 = param2;
    packet->param3 = param3;
    packet->param4 = param4;
    packet->x = x;
    packet->y = y;
    packet->z = z;
    packet->seq = seq;
    packet->command = command;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->frame = frame;
    packet->current = current;
    packet->autocontinue = autocontinue;
    packet->mission_type = mission_type;
    mav_array_memcpy(packet->name, name, sizeof(uint8_t)*128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT, (const char *)packet, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_MIN_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_CRC);
#endif
}
#endif

#endif

// MESSAGE MISSION_ITEM_INT_EXT UNPACKING


/**
 * @brief Get field target_system from mission_item_int_ext message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_mission_item_int_ext_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field target_component from mission_item_int_ext message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_mission_item_int_ext_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  33);
}

/**
 * @brief Get field seq from mission_item_int_ext message
 *
 * @return  Waypoint ID (sequence number). Starts at zero. Increases monotonically for each waypoint, no gaps in the sequence (0,1,2,3,4).
 */
static inline uint16_t mavlink_msg_mission_item_int_ext_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field frame from mission_item_int_ext message
 *
 * @return  The coordinate system of the waypoint.
 */
static inline uint8_t mavlink_msg_mission_item_int_ext_get_frame(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  34);
}

/**
 * @brief Get field command from mission_item_int_ext message
 *
 * @return  The scheduled action for the waypoint.
 */
static inline uint16_t mavlink_msg_mission_item_int_ext_get_command(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  30);
}

/**
 * @brief Get field current from mission_item_int_ext message
 *
 * @return  false:0, true:1
 */
static inline uint8_t mavlink_msg_mission_item_int_ext_get_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  35);
}

/**
 * @brief Get field autocontinue from mission_item_int_ext message
 *
 * @return  Autocontinue to next waypoint
 */
static inline uint8_t mavlink_msg_mission_item_int_ext_get_autocontinue(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Get field param1 from mission_item_int_ext message
 *
 * @return  PARAM1, see MAV_CMD enum
 */
static inline float mavlink_msg_mission_item_int_ext_get_param1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param2 from mission_item_int_ext message
 *
 * @return  PARAM2, see MAV_CMD enum
 */
static inline float mavlink_msg_mission_item_int_ext_get_param2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field param3 from mission_item_int_ext message
 *
 * @return  PARAM3, see MAV_CMD enum
 */
static inline float mavlink_msg_mission_item_int_ext_get_param3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field param4 from mission_item_int_ext message
 *
 * @return  PARAM4, see MAV_CMD enum
 */
static inline float mavlink_msg_mission_item_int_ext_get_param4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field x from mission_item_int_ext message
 *
 * @return  PARAM5 / local: x position in meters * 1e4, global: latitude in degrees * 10^7
 */
static inline int32_t mavlink_msg_mission_item_int_ext_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field y from mission_item_int_ext message
 *
 * @return  PARAM6 / y position: local: x position in meters * 1e4, global: longitude in degrees *10^7
 */
static inline int32_t mavlink_msg_mission_item_int_ext_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field z from mission_item_int_ext message
 *
 * @return  PARAM7 / z position: global: altitude in meters (relative or absolute, depending on frame.
 */
static inline float mavlink_msg_mission_item_int_ext_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field name from mission_item_int_ext message
 *
 * @return  target name
 */
static inline uint16_t mavlink_msg_mission_item_int_ext_get_name(const mavlink_message_t* msg, uint8_t *name)
{
    return _MAV_RETURN_uint8_t_array(msg, name, 128,  37);
}

/**
 * @brief Get field mission_type from mission_item_int_ext message
 *
 * @return  Mission type.
 */
static inline uint8_t mavlink_msg_mission_item_int_ext_get_mission_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  165);
}

/**
 * @brief Decode a mission_item_int_ext message into a struct
 *
 * @param msg The message to decode
 * @param mission_item_int_ext C-struct to decode the message contents into
 */
static inline void mavlink_msg_mission_item_int_ext_decode(const mavlink_message_t* msg, mavlink_mission_item_int_ext_t* mission_item_int_ext)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mission_item_int_ext->param1 = mavlink_msg_mission_item_int_ext_get_param1(msg);
    mission_item_int_ext->param2 = mavlink_msg_mission_item_int_ext_get_param2(msg);
    mission_item_int_ext->param3 = mavlink_msg_mission_item_int_ext_get_param3(msg);
    mission_item_int_ext->param4 = mavlink_msg_mission_item_int_ext_get_param4(msg);
    mission_item_int_ext->x = mavlink_msg_mission_item_int_ext_get_x(msg);
    mission_item_int_ext->y = mavlink_msg_mission_item_int_ext_get_y(msg);
    mission_item_int_ext->z = mavlink_msg_mission_item_int_ext_get_z(msg);
    mission_item_int_ext->seq = mavlink_msg_mission_item_int_ext_get_seq(msg);
    mission_item_int_ext->command = mavlink_msg_mission_item_int_ext_get_command(msg);
    mission_item_int_ext->target_system = mavlink_msg_mission_item_int_ext_get_target_system(msg);
    mission_item_int_ext->target_component = mavlink_msg_mission_item_int_ext_get_target_component(msg);
    mission_item_int_ext->frame = mavlink_msg_mission_item_int_ext_get_frame(msg);
    mission_item_int_ext->current = mavlink_msg_mission_item_int_ext_get_current(msg);
    mission_item_int_ext->autocontinue = mavlink_msg_mission_item_int_ext_get_autocontinue(msg);
    mavlink_msg_mission_item_int_ext_get_name(msg, mission_item_int_ext->name);
    mission_item_int_ext->mission_type = mavlink_msg_mission_item_int_ext_get_mission_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN? msg->len : MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN;
        memset(mission_item_int_ext, 0, MAVLINK_MSG_ID_MISSION_ITEM_INT_EXT_LEN);
    memcpy(mission_item_int_ext, _MAV_PAYLOAD(msg), len);
#endif
}
