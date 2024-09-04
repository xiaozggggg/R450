#pragma once
// MESSAGE WK_RTK_BEACON_INAV_DATA PACKING

#define MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA 8028


typedef struct __mavlink_wk_rtk_beacon_inav_data_t {
 uint32_t seq; /*<  packet sequence number*/
 int32_t latitude; /*<  latitude * 1E7*/
 int32_t longitude; /*<  longitude * 1E7*/
 int32_t gnss_height; /*<  gnss heignt,unit cm*/
 int16_t velocity_ef_x; /*<  velocity ef x * 10,unit cm/s*/
 int16_t velocity_ef_y; /*<  velocity ef y * 10,unit cm/s*/
 int16_t velocity_ef_z; /*<  velocity ef z * 10,unit cm/s*/
 int16_t yaw; /*<  yaw*/
 uint8_t gps_fix_type; /*<  gnss fix type*/
 uint8_t sv_nums; /*<  satellite number in used*/
 uint8_t battery_capacity; /*<  */
} mavlink_wk_rtk_beacon_inav_data_t;

#define MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN 27
#define MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_MIN_LEN 27
#define MAVLINK_MSG_ID_8028_LEN 27
#define MAVLINK_MSG_ID_8028_MIN_LEN 27

#define MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_CRC 139
#define MAVLINK_MSG_ID_8028_CRC 139



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_RTK_BEACON_INAV_DATA { \
    8028, \
    "WK_RTK_BEACON_INAV_DATA", \
    11, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_rtk_beacon_inav_data_t, seq) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_wk_rtk_beacon_inav_data_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_rtk_beacon_inav_data_t, longitude) }, \
         { "gnss_height", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_rtk_beacon_inav_data_t, gnss_height) }, \
         { "gps_fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_wk_rtk_beacon_inav_data_t, gps_fix_type) }, \
         { "sv_nums", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_wk_rtk_beacon_inav_data_t, sv_nums) }, \
         { "velocity_ef_x", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_wk_rtk_beacon_inav_data_t, velocity_ef_x) }, \
         { "velocity_ef_y", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_wk_rtk_beacon_inav_data_t, velocity_ef_y) }, \
         { "velocity_ef_z", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_wk_rtk_beacon_inav_data_t, velocity_ef_z) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_wk_rtk_beacon_inav_data_t, yaw) }, \
         { "battery_capacity", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_wk_rtk_beacon_inav_data_t, battery_capacity) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_RTK_BEACON_INAV_DATA { \
    "WK_RTK_BEACON_INAV_DATA", \
    11, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_rtk_beacon_inav_data_t, seq) }, \
         { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_wk_rtk_beacon_inav_data_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_wk_rtk_beacon_inav_data_t, longitude) }, \
         { "gnss_height", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_wk_rtk_beacon_inav_data_t, gnss_height) }, \
         { "gps_fix_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_wk_rtk_beacon_inav_data_t, gps_fix_type) }, \
         { "sv_nums", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_wk_rtk_beacon_inav_data_t, sv_nums) }, \
         { "velocity_ef_x", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_wk_rtk_beacon_inav_data_t, velocity_ef_x) }, \
         { "velocity_ef_y", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_wk_rtk_beacon_inav_data_t, velocity_ef_y) }, \
         { "velocity_ef_z", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_wk_rtk_beacon_inav_data_t, velocity_ef_z) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_wk_rtk_beacon_inav_data_t, yaw) }, \
         { "battery_capacity", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_wk_rtk_beacon_inav_data_t, battery_capacity) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_rtk_beacon_inav_data message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param seq  packet sequence number
 * @param latitude  latitude * 1E7
 * @param longitude  longitude * 1E7
 * @param gnss_height  gnss heignt,unit cm
 * @param gps_fix_type  gnss fix type
 * @param sv_nums  satellite number in used
 * @param velocity_ef_x  velocity ef x * 10,unit cm/s
 * @param velocity_ef_y  velocity ef y * 10,unit cm/s
 * @param velocity_ef_z  velocity ef z * 10,unit cm/s
 * @param yaw  yaw
 * @param battery_capacity  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_rtk_beacon_inav_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t seq, int32_t latitude, int32_t longitude, int32_t gnss_height, uint8_t gps_fix_type, uint8_t sv_nums, int16_t velocity_ef_x, int16_t velocity_ef_y, int16_t velocity_ef_z, int16_t yaw, uint8_t battery_capacity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN];
    _mav_put_uint32_t(buf, 0, seq);
    _mav_put_int32_t(buf, 4, latitude);
    _mav_put_int32_t(buf, 8, longitude);
    _mav_put_int32_t(buf, 12, gnss_height);
    _mav_put_int16_t(buf, 16, velocity_ef_x);
    _mav_put_int16_t(buf, 18, velocity_ef_y);
    _mav_put_int16_t(buf, 20, velocity_ef_z);
    _mav_put_int16_t(buf, 22, yaw);
    _mav_put_uint8_t(buf, 24, gps_fix_type);
    _mav_put_uint8_t(buf, 25, sv_nums);
    _mav_put_uint8_t(buf, 26, battery_capacity);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN);
#else
    mavlink_wk_rtk_beacon_inav_data_t packet;
    packet.seq = seq;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.gnss_height = gnss_height;
    packet.velocity_ef_x = velocity_ef_x;
    packet.velocity_ef_y = velocity_ef_y;
    packet.velocity_ef_z = velocity_ef_z;
    packet.yaw = yaw;
    packet.gps_fix_type = gps_fix_type;
    packet.sv_nums = sv_nums;
    packet.battery_capacity = battery_capacity;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_CRC);
}

/**
 * @brief Pack a wk_rtk_beacon_inav_data message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param seq  packet sequence number
 * @param latitude  latitude * 1E7
 * @param longitude  longitude * 1E7
 * @param gnss_height  gnss heignt,unit cm
 * @param gps_fix_type  gnss fix type
 * @param sv_nums  satellite number in used
 * @param velocity_ef_x  velocity ef x * 10,unit cm/s
 * @param velocity_ef_y  velocity ef y * 10,unit cm/s
 * @param velocity_ef_z  velocity ef z * 10,unit cm/s
 * @param yaw  yaw
 * @param battery_capacity  
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_rtk_beacon_inav_data_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t seq,int32_t latitude,int32_t longitude,int32_t gnss_height,uint8_t gps_fix_type,uint8_t sv_nums,int16_t velocity_ef_x,int16_t velocity_ef_y,int16_t velocity_ef_z,int16_t yaw,uint8_t battery_capacity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN];
    _mav_put_uint32_t(buf, 0, seq);
    _mav_put_int32_t(buf, 4, latitude);
    _mav_put_int32_t(buf, 8, longitude);
    _mav_put_int32_t(buf, 12, gnss_height);
    _mav_put_int16_t(buf, 16, velocity_ef_x);
    _mav_put_int16_t(buf, 18, velocity_ef_y);
    _mav_put_int16_t(buf, 20, velocity_ef_z);
    _mav_put_int16_t(buf, 22, yaw);
    _mav_put_uint8_t(buf, 24, gps_fix_type);
    _mav_put_uint8_t(buf, 25, sv_nums);
    _mav_put_uint8_t(buf, 26, battery_capacity);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN);
#else
    mavlink_wk_rtk_beacon_inav_data_t packet;
    packet.seq = seq;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.gnss_height = gnss_height;
    packet.velocity_ef_x = velocity_ef_x;
    packet.velocity_ef_y = velocity_ef_y;
    packet.velocity_ef_z = velocity_ef_z;
    packet.yaw = yaw;
    packet.gps_fix_type = gps_fix_type;
    packet.sv_nums = sv_nums;
    packet.battery_capacity = battery_capacity;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_CRC);
}

/**
 * @brief Encode a wk_rtk_beacon_inav_data struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_rtk_beacon_inav_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_rtk_beacon_inav_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_rtk_beacon_inav_data_t* wk_rtk_beacon_inav_data)
{
    return mavlink_msg_wk_rtk_beacon_inav_data_pack(system_id, component_id, msg, wk_rtk_beacon_inav_data->seq, wk_rtk_beacon_inav_data->latitude, wk_rtk_beacon_inav_data->longitude, wk_rtk_beacon_inav_data->gnss_height, wk_rtk_beacon_inav_data->gps_fix_type, wk_rtk_beacon_inav_data->sv_nums, wk_rtk_beacon_inav_data->velocity_ef_x, wk_rtk_beacon_inav_data->velocity_ef_y, wk_rtk_beacon_inav_data->velocity_ef_z, wk_rtk_beacon_inav_data->yaw, wk_rtk_beacon_inav_data->battery_capacity);
}

/**
 * @brief Encode a wk_rtk_beacon_inav_data struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_rtk_beacon_inav_data C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_rtk_beacon_inav_data_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_rtk_beacon_inav_data_t* wk_rtk_beacon_inav_data)
{
    return mavlink_msg_wk_rtk_beacon_inav_data_pack_chan(system_id, component_id, chan, msg, wk_rtk_beacon_inav_data->seq, wk_rtk_beacon_inav_data->latitude, wk_rtk_beacon_inav_data->longitude, wk_rtk_beacon_inav_data->gnss_height, wk_rtk_beacon_inav_data->gps_fix_type, wk_rtk_beacon_inav_data->sv_nums, wk_rtk_beacon_inav_data->velocity_ef_x, wk_rtk_beacon_inav_data->velocity_ef_y, wk_rtk_beacon_inav_data->velocity_ef_z, wk_rtk_beacon_inav_data->yaw, wk_rtk_beacon_inav_data->battery_capacity);
}

/**
 * @brief Send a wk_rtk_beacon_inav_data message
 * @param chan MAVLink channel to send the message
 *
 * @param seq  packet sequence number
 * @param latitude  latitude * 1E7
 * @param longitude  longitude * 1E7
 * @param gnss_height  gnss heignt,unit cm
 * @param gps_fix_type  gnss fix type
 * @param sv_nums  satellite number in used
 * @param velocity_ef_x  velocity ef x * 10,unit cm/s
 * @param velocity_ef_y  velocity ef y * 10,unit cm/s
 * @param velocity_ef_z  velocity ef z * 10,unit cm/s
 * @param yaw  yaw
 * @param battery_capacity  
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_rtk_beacon_inav_data_send(mavlink_channel_t chan, uint32_t seq, int32_t latitude, int32_t longitude, int32_t gnss_height, uint8_t gps_fix_type, uint8_t sv_nums, int16_t velocity_ef_x, int16_t velocity_ef_y, int16_t velocity_ef_z, int16_t yaw, uint8_t battery_capacity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN];
    _mav_put_uint32_t(buf, 0, seq);
    _mav_put_int32_t(buf, 4, latitude);
    _mav_put_int32_t(buf, 8, longitude);
    _mav_put_int32_t(buf, 12, gnss_height);
    _mav_put_int16_t(buf, 16, velocity_ef_x);
    _mav_put_int16_t(buf, 18, velocity_ef_y);
    _mav_put_int16_t(buf, 20, velocity_ef_z);
    _mav_put_int16_t(buf, 22, yaw);
    _mav_put_uint8_t(buf, 24, gps_fix_type);
    _mav_put_uint8_t(buf, 25, sv_nums);
    _mav_put_uint8_t(buf, 26, battery_capacity);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA, buf, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_CRC);
#else
    mavlink_wk_rtk_beacon_inav_data_t packet;
    packet.seq = seq;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.gnss_height = gnss_height;
    packet.velocity_ef_x = velocity_ef_x;
    packet.velocity_ef_y = velocity_ef_y;
    packet.velocity_ef_z = velocity_ef_z;
    packet.yaw = yaw;
    packet.gps_fix_type = gps_fix_type;
    packet.sv_nums = sv_nums;
    packet.battery_capacity = battery_capacity;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA, (const char *)&packet, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_CRC);
#endif
}

/**
 * @brief Send a wk_rtk_beacon_inav_data message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_rtk_beacon_inav_data_send_struct(mavlink_channel_t chan, const mavlink_wk_rtk_beacon_inav_data_t* wk_rtk_beacon_inav_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_rtk_beacon_inav_data_send(chan, wk_rtk_beacon_inav_data->seq, wk_rtk_beacon_inav_data->latitude, wk_rtk_beacon_inav_data->longitude, wk_rtk_beacon_inav_data->gnss_height, wk_rtk_beacon_inav_data->gps_fix_type, wk_rtk_beacon_inav_data->sv_nums, wk_rtk_beacon_inav_data->velocity_ef_x, wk_rtk_beacon_inav_data->velocity_ef_y, wk_rtk_beacon_inav_data->velocity_ef_z, wk_rtk_beacon_inav_data->yaw, wk_rtk_beacon_inav_data->battery_capacity);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA, (const char *)wk_rtk_beacon_inav_data, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_rtk_beacon_inav_data_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t seq, int32_t latitude, int32_t longitude, int32_t gnss_height, uint8_t gps_fix_type, uint8_t sv_nums, int16_t velocity_ef_x, int16_t velocity_ef_y, int16_t velocity_ef_z, int16_t yaw, uint8_t battery_capacity)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, seq);
    _mav_put_int32_t(buf, 4, latitude);
    _mav_put_int32_t(buf, 8, longitude);
    _mav_put_int32_t(buf, 12, gnss_height);
    _mav_put_int16_t(buf, 16, velocity_ef_x);
    _mav_put_int16_t(buf, 18, velocity_ef_y);
    _mav_put_int16_t(buf, 20, velocity_ef_z);
    _mav_put_int16_t(buf, 22, yaw);
    _mav_put_uint8_t(buf, 24, gps_fix_type);
    _mav_put_uint8_t(buf, 25, sv_nums);
    _mav_put_uint8_t(buf, 26, battery_capacity);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA, buf, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_CRC);
#else
    mavlink_wk_rtk_beacon_inav_data_t *packet = (mavlink_wk_rtk_beacon_inav_data_t *)msgbuf;
    packet->seq = seq;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->gnss_height = gnss_height;
    packet->velocity_ef_x = velocity_ef_x;
    packet->velocity_ef_y = velocity_ef_y;
    packet->velocity_ef_z = velocity_ef_z;
    packet->yaw = yaw;
    packet->gps_fix_type = gps_fix_type;
    packet->sv_nums = sv_nums;
    packet->battery_capacity = battery_capacity;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA, (const char *)packet, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_MIN_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_RTK_BEACON_INAV_DATA UNPACKING


/**
 * @brief Get field seq from wk_rtk_beacon_inav_data message
 *
 * @return  packet sequence number
 */
static inline uint32_t mavlink_msg_wk_rtk_beacon_inav_data_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field latitude from wk_rtk_beacon_inav_data message
 *
 * @return  latitude * 1E7
 */
static inline int32_t mavlink_msg_wk_rtk_beacon_inav_data_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field longitude from wk_rtk_beacon_inav_data message
 *
 * @return  longitude * 1E7
 */
static inline int32_t mavlink_msg_wk_rtk_beacon_inav_data_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field gnss_height from wk_rtk_beacon_inav_data message
 *
 * @return  gnss heignt,unit cm
 */
static inline int32_t mavlink_msg_wk_rtk_beacon_inav_data_get_gnss_height(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field gps_fix_type from wk_rtk_beacon_inav_data message
 *
 * @return  gnss fix type
 */
static inline uint8_t mavlink_msg_wk_rtk_beacon_inav_data_get_gps_fix_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field sv_nums from wk_rtk_beacon_inav_data message
 *
 * @return  satellite number in used
 */
static inline uint8_t mavlink_msg_wk_rtk_beacon_inav_data_get_sv_nums(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  25);
}

/**
 * @brief Get field velocity_ef_x from wk_rtk_beacon_inav_data message
 *
 * @return  velocity ef x * 10,unit cm/s
 */
static inline int16_t mavlink_msg_wk_rtk_beacon_inav_data_get_velocity_ef_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field velocity_ef_y from wk_rtk_beacon_inav_data message
 *
 * @return  velocity ef y * 10,unit cm/s
 */
static inline int16_t mavlink_msg_wk_rtk_beacon_inav_data_get_velocity_ef_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field velocity_ef_z from wk_rtk_beacon_inav_data message
 *
 * @return  velocity ef z * 10,unit cm/s
 */
static inline int16_t mavlink_msg_wk_rtk_beacon_inav_data_get_velocity_ef_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field yaw from wk_rtk_beacon_inav_data message
 *
 * @return  yaw
 */
static inline int16_t mavlink_msg_wk_rtk_beacon_inav_data_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field battery_capacity from wk_rtk_beacon_inav_data message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_wk_rtk_beacon_inav_data_get_battery_capacity(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  26);
}

/**
 * @brief Decode a wk_rtk_beacon_inav_data message into a struct
 *
 * @param msg The message to decode
 * @param wk_rtk_beacon_inav_data C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_rtk_beacon_inav_data_decode(const mavlink_message_t* msg, mavlink_wk_rtk_beacon_inav_data_t* wk_rtk_beacon_inav_data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_rtk_beacon_inav_data->seq = mavlink_msg_wk_rtk_beacon_inav_data_get_seq(msg);
    wk_rtk_beacon_inav_data->latitude = mavlink_msg_wk_rtk_beacon_inav_data_get_latitude(msg);
    wk_rtk_beacon_inav_data->longitude = mavlink_msg_wk_rtk_beacon_inav_data_get_longitude(msg);
    wk_rtk_beacon_inav_data->gnss_height = mavlink_msg_wk_rtk_beacon_inav_data_get_gnss_height(msg);
    wk_rtk_beacon_inav_data->velocity_ef_x = mavlink_msg_wk_rtk_beacon_inav_data_get_velocity_ef_x(msg);
    wk_rtk_beacon_inav_data->velocity_ef_y = mavlink_msg_wk_rtk_beacon_inav_data_get_velocity_ef_y(msg);
    wk_rtk_beacon_inav_data->velocity_ef_z = mavlink_msg_wk_rtk_beacon_inav_data_get_velocity_ef_z(msg);
    wk_rtk_beacon_inav_data->yaw = mavlink_msg_wk_rtk_beacon_inav_data_get_yaw(msg);
    wk_rtk_beacon_inav_data->gps_fix_type = mavlink_msg_wk_rtk_beacon_inav_data_get_gps_fix_type(msg);
    wk_rtk_beacon_inav_data->sv_nums = mavlink_msg_wk_rtk_beacon_inav_data_get_sv_nums(msg);
    wk_rtk_beacon_inav_data->battery_capacity = mavlink_msg_wk_rtk_beacon_inav_data_get_battery_capacity(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN? msg->len : MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN;
        memset(wk_rtk_beacon_inav_data, 0, MAVLINK_MSG_ID_WK_RTK_BEACON_INAV_DATA_LEN);
    memcpy(wk_rtk_beacon_inav_data, _MAV_PAYLOAD(msg), len);
#endif
}
