#pragma once
// MESSAGE WK_LOG_FLIGHT_STATE PACKING

#define MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE 8500


typedef struct __mavlink_wk_log_flight_state_t {
 uint64_t timestamp; /*<  timestamp*/
 float roll_rate; /*<  roll rate*/
 float pitch_rate; /*<  pitch rate*/
 float yaw_rate; /*<  yaw rate*/
 float roll_rate_sp; /*<  roll_rate_sp*/
 float pitch_rate_sp; /*<  pitch_rate_sp*/
 float yaw_rate_sp; /*<  yaw_rate_sp*/
 float roll; /*<  roll*/
 float pitch; /*<  pitch*/
 float yaw; /*<  yaw*/
 float roll_sp; /*<  roll_sp*/
 float pitch_sp; /*<  pitch_sp*/
 float yaw_sp; /*<  yaw_sp*/
 float accel_ef[3]; /*<  accel_ef*/
 float velocity[3]; /*<  velocity*/
 float velocity_sp[3]; /*<  velocity_sp*/
 float position[3]; /*<  position*/
 float position_sp[3]; /*<  position_sp*/
 float position_obver[3]; /*<  position_obver*/
 uint16_t time_cnt; /*<  runtime counter*/
 uint8_t flag_arm; /*<  arm/disarm flag*/
 uint8_t flight_mode; /*<  flight mode*/
 uint8_t failsafe; /*<  radio failsafe flag*/
 uint8_t inav_health; /*<  inav health flag*/
} mavlink_wk_log_flight_state_t;

#define MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN 134
#define MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_MIN_LEN 134
#define MAVLINK_MSG_ID_8500_LEN 134
#define MAVLINK_MSG_ID_8500_MIN_LEN 134

#define MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_CRC 145
#define MAVLINK_MSG_ID_8500_CRC 145

#define MAVLINK_MSG_WK_LOG_FLIGHT_STATE_FIELD_ACCEL_EF_LEN 3
#define MAVLINK_MSG_WK_LOG_FLIGHT_STATE_FIELD_VELOCITY_LEN 3
#define MAVLINK_MSG_WK_LOG_FLIGHT_STATE_FIELD_VELOCITY_SP_LEN 3
#define MAVLINK_MSG_WK_LOG_FLIGHT_STATE_FIELD_POSITION_LEN 3
#define MAVLINK_MSG_WK_LOG_FLIGHT_STATE_FIELD_POSITION_SP_LEN 3
#define MAVLINK_MSG_WK_LOG_FLIGHT_STATE_FIELD_POSITION_OBVER_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_LOG_FLIGHT_STATE { \
    8500, \
    "WK_LOG_FLIGHT_STATE", \
    24, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_flight_state_t, timestamp) }, \
         { "time_cnt", NULL, MAVLINK_TYPE_UINT16_T, 0, 128, offsetof(mavlink_wk_log_flight_state_t, time_cnt) }, \
         { "flag_arm", NULL, MAVLINK_TYPE_UINT8_T, 0, 130, offsetof(mavlink_wk_log_flight_state_t, flag_arm) }, \
         { "flight_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 131, offsetof(mavlink_wk_log_flight_state_t, flight_mode) }, \
         { "failsafe", NULL, MAVLINK_TYPE_UINT8_T, 0, 132, offsetof(mavlink_wk_log_flight_state_t, failsafe) }, \
         { "inav_health", NULL, MAVLINK_TYPE_UINT8_T, 0, 133, offsetof(mavlink_wk_log_flight_state_t, inav_health) }, \
         { "roll_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_log_flight_state_t, roll_rate) }, \
         { "pitch_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_log_flight_state_t, pitch_rate) }, \
         { "yaw_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_log_flight_state_t, yaw_rate) }, \
         { "roll_rate_sp", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_log_flight_state_t, roll_rate_sp) }, \
         { "pitch_rate_sp", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wk_log_flight_state_t, pitch_rate_sp) }, \
         { "yaw_rate_sp", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wk_log_flight_state_t, yaw_rate_sp) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wk_log_flight_state_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wk_log_flight_state_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_wk_log_flight_state_t, yaw) }, \
         { "roll_sp", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_wk_log_flight_state_t, roll_sp) }, \
         { "pitch_sp", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_wk_log_flight_state_t, pitch_sp) }, \
         { "yaw_sp", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_wk_log_flight_state_t, yaw_sp) }, \
         { "accel_ef", NULL, MAVLINK_TYPE_FLOAT, 3, 56, offsetof(mavlink_wk_log_flight_state_t, accel_ef) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 3, 68, offsetof(mavlink_wk_log_flight_state_t, velocity) }, \
         { "velocity_sp", NULL, MAVLINK_TYPE_FLOAT, 3, 80, offsetof(mavlink_wk_log_flight_state_t, velocity_sp) }, \
         { "position", NULL, MAVLINK_TYPE_FLOAT, 3, 92, offsetof(mavlink_wk_log_flight_state_t, position) }, \
         { "position_sp", NULL, MAVLINK_TYPE_FLOAT, 3, 104, offsetof(mavlink_wk_log_flight_state_t, position_sp) }, \
         { "position_obver", NULL, MAVLINK_TYPE_FLOAT, 3, 116, offsetof(mavlink_wk_log_flight_state_t, position_obver) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_LOG_FLIGHT_STATE { \
    "WK_LOG_FLIGHT_STATE", \
    24, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_wk_log_flight_state_t, timestamp) }, \
         { "time_cnt", NULL, MAVLINK_TYPE_UINT16_T, 0, 128, offsetof(mavlink_wk_log_flight_state_t, time_cnt) }, \
         { "flag_arm", NULL, MAVLINK_TYPE_UINT8_T, 0, 130, offsetof(mavlink_wk_log_flight_state_t, flag_arm) }, \
         { "flight_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 131, offsetof(mavlink_wk_log_flight_state_t, flight_mode) }, \
         { "failsafe", NULL, MAVLINK_TYPE_UINT8_T, 0, 132, offsetof(mavlink_wk_log_flight_state_t, failsafe) }, \
         { "inav_health", NULL, MAVLINK_TYPE_UINT8_T, 0, 133, offsetof(mavlink_wk_log_flight_state_t, inav_health) }, \
         { "roll_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_wk_log_flight_state_t, roll_rate) }, \
         { "pitch_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 12, offsetof(mavlink_wk_log_flight_state_t, pitch_rate) }, \
         { "yaw_rate", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_log_flight_state_t, yaw_rate) }, \
         { "roll_rate_sp", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_log_flight_state_t, roll_rate_sp) }, \
         { "pitch_rate_sp", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wk_log_flight_state_t, pitch_rate_sp) }, \
         { "yaw_rate_sp", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_wk_log_flight_state_t, yaw_rate_sp) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_wk_log_flight_state_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_wk_log_flight_state_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_wk_log_flight_state_t, yaw) }, \
         { "roll_sp", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_wk_log_flight_state_t, roll_sp) }, \
         { "pitch_sp", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_wk_log_flight_state_t, pitch_sp) }, \
         { "yaw_sp", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_wk_log_flight_state_t, yaw_sp) }, \
         { "accel_ef", NULL, MAVLINK_TYPE_FLOAT, 3, 56, offsetof(mavlink_wk_log_flight_state_t, accel_ef) }, \
         { "velocity", NULL, MAVLINK_TYPE_FLOAT, 3, 68, offsetof(mavlink_wk_log_flight_state_t, velocity) }, \
         { "velocity_sp", NULL, MAVLINK_TYPE_FLOAT, 3, 80, offsetof(mavlink_wk_log_flight_state_t, velocity_sp) }, \
         { "position", NULL, MAVLINK_TYPE_FLOAT, 3, 92, offsetof(mavlink_wk_log_flight_state_t, position) }, \
         { "position_sp", NULL, MAVLINK_TYPE_FLOAT, 3, 104, offsetof(mavlink_wk_log_flight_state_t, position_sp) }, \
         { "position_obver", NULL, MAVLINK_TYPE_FLOAT, 3, 116, offsetof(mavlink_wk_log_flight_state_t, position_obver) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_log_flight_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp  timestamp
 * @param time_cnt  runtime counter
 * @param flag_arm  arm/disarm flag
 * @param flight_mode  flight mode
 * @param failsafe  radio failsafe flag
 * @param inav_health  inav health flag
 * @param roll_rate  roll rate
 * @param pitch_rate  pitch rate
 * @param yaw_rate  yaw rate
 * @param roll_rate_sp  roll_rate_sp
 * @param pitch_rate_sp  pitch_rate_sp
 * @param yaw_rate_sp  yaw_rate_sp
 * @param roll  roll
 * @param pitch  pitch
 * @param yaw  yaw
 * @param roll_sp  roll_sp
 * @param pitch_sp  pitch_sp
 * @param yaw_sp  yaw_sp
 * @param accel_ef  accel_ef
 * @param velocity  velocity
 * @param velocity_sp  velocity_sp
 * @param position  position
 * @param position_sp  position_sp
 * @param position_obver  position_obver
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_flight_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, uint16_t time_cnt, uint8_t flag_arm, uint8_t flight_mode, uint8_t failsafe, uint8_t inav_health, float roll_rate, float pitch_rate, float yaw_rate, float roll_rate_sp, float pitch_rate_sp, float yaw_rate_sp, float roll, float pitch, float yaw, float roll_sp, float pitch_sp, float yaw_sp, const float *accel_ef, const float *velocity, const float *velocity_sp, const float *position, const float *position_sp, const float *position_obver)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, roll_rate);
    _mav_put_float(buf, 12, pitch_rate);
    _mav_put_float(buf, 16, yaw_rate);
    _mav_put_float(buf, 20, roll_rate_sp);
    _mav_put_float(buf, 24, pitch_rate_sp);
    _mav_put_float(buf, 28, yaw_rate_sp);
    _mav_put_float(buf, 32, roll);
    _mav_put_float(buf, 36, pitch);
    _mav_put_float(buf, 40, yaw);
    _mav_put_float(buf, 44, roll_sp);
    _mav_put_float(buf, 48, pitch_sp);
    _mav_put_float(buf, 52, yaw_sp);
    _mav_put_uint16_t(buf, 128, time_cnt);
    _mav_put_uint8_t(buf, 130, flag_arm);
    _mav_put_uint8_t(buf, 131, flight_mode);
    _mav_put_uint8_t(buf, 132, failsafe);
    _mav_put_uint8_t(buf, 133, inav_health);
    _mav_put_float_array(buf, 56, accel_ef, 3);
    _mav_put_float_array(buf, 68, velocity, 3);
    _mav_put_float_array(buf, 80, velocity_sp, 3);
    _mav_put_float_array(buf, 92, position, 3);
    _mav_put_float_array(buf, 104, position_sp, 3);
    _mav_put_float_array(buf, 116, position_obver, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN);
#else
    mavlink_wk_log_flight_state_t packet;
    packet.timestamp = timestamp;
    packet.roll_rate = roll_rate;
    packet.pitch_rate = pitch_rate;
    packet.yaw_rate = yaw_rate;
    packet.roll_rate_sp = roll_rate_sp;
    packet.pitch_rate_sp = pitch_rate_sp;
    packet.yaw_rate_sp = yaw_rate_sp;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.roll_sp = roll_sp;
    packet.pitch_sp = pitch_sp;
    packet.yaw_sp = yaw_sp;
    packet.time_cnt = time_cnt;
    packet.flag_arm = flag_arm;
    packet.flight_mode = flight_mode;
    packet.failsafe = failsafe;
    packet.inav_health = inav_health;
    mav_array_memcpy(packet.accel_ef, accel_ef, sizeof(float)*3);
    mav_array_memcpy(packet.velocity, velocity, sizeof(float)*3);
    mav_array_memcpy(packet.velocity_sp, velocity_sp, sizeof(float)*3);
    mav_array_memcpy(packet.position, position, sizeof(float)*3);
    mav_array_memcpy(packet.position_sp, position_sp, sizeof(float)*3);
    mav_array_memcpy(packet.position_obver, position_obver, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_CRC);
}

/**
 * @brief Pack a wk_log_flight_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp  timestamp
 * @param time_cnt  runtime counter
 * @param flag_arm  arm/disarm flag
 * @param flight_mode  flight mode
 * @param failsafe  radio failsafe flag
 * @param inav_health  inav health flag
 * @param roll_rate  roll rate
 * @param pitch_rate  pitch rate
 * @param yaw_rate  yaw rate
 * @param roll_rate_sp  roll_rate_sp
 * @param pitch_rate_sp  pitch_rate_sp
 * @param yaw_rate_sp  yaw_rate_sp
 * @param roll  roll
 * @param pitch  pitch
 * @param yaw  yaw
 * @param roll_sp  roll_sp
 * @param pitch_sp  pitch_sp
 * @param yaw_sp  yaw_sp
 * @param accel_ef  accel_ef
 * @param velocity  velocity
 * @param velocity_sp  velocity_sp
 * @param position  position
 * @param position_sp  position_sp
 * @param position_obver  position_obver
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_log_flight_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,uint16_t time_cnt,uint8_t flag_arm,uint8_t flight_mode,uint8_t failsafe,uint8_t inav_health,float roll_rate,float pitch_rate,float yaw_rate,float roll_rate_sp,float pitch_rate_sp,float yaw_rate_sp,float roll,float pitch,float yaw,float roll_sp,float pitch_sp,float yaw_sp,const float *accel_ef,const float *velocity,const float *velocity_sp,const float *position,const float *position_sp,const float *position_obver)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, roll_rate);
    _mav_put_float(buf, 12, pitch_rate);
    _mav_put_float(buf, 16, yaw_rate);
    _mav_put_float(buf, 20, roll_rate_sp);
    _mav_put_float(buf, 24, pitch_rate_sp);
    _mav_put_float(buf, 28, yaw_rate_sp);
    _mav_put_float(buf, 32, roll);
    _mav_put_float(buf, 36, pitch);
    _mav_put_float(buf, 40, yaw);
    _mav_put_float(buf, 44, roll_sp);
    _mav_put_float(buf, 48, pitch_sp);
    _mav_put_float(buf, 52, yaw_sp);
    _mav_put_uint16_t(buf, 128, time_cnt);
    _mav_put_uint8_t(buf, 130, flag_arm);
    _mav_put_uint8_t(buf, 131, flight_mode);
    _mav_put_uint8_t(buf, 132, failsafe);
    _mav_put_uint8_t(buf, 133, inav_health);
    _mav_put_float_array(buf, 56, accel_ef, 3);
    _mav_put_float_array(buf, 68, velocity, 3);
    _mav_put_float_array(buf, 80, velocity_sp, 3);
    _mav_put_float_array(buf, 92, position, 3);
    _mav_put_float_array(buf, 104, position_sp, 3);
    _mav_put_float_array(buf, 116, position_obver, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN);
#else
    mavlink_wk_log_flight_state_t packet;
    packet.timestamp = timestamp;
    packet.roll_rate = roll_rate;
    packet.pitch_rate = pitch_rate;
    packet.yaw_rate = yaw_rate;
    packet.roll_rate_sp = roll_rate_sp;
    packet.pitch_rate_sp = pitch_rate_sp;
    packet.yaw_rate_sp = yaw_rate_sp;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.roll_sp = roll_sp;
    packet.pitch_sp = pitch_sp;
    packet.yaw_sp = yaw_sp;
    packet.time_cnt = time_cnt;
    packet.flag_arm = flag_arm;
    packet.flight_mode = flight_mode;
    packet.failsafe = failsafe;
    packet.inav_health = inav_health;
    mav_array_memcpy(packet.accel_ef, accel_ef, sizeof(float)*3);
    mav_array_memcpy(packet.velocity, velocity, sizeof(float)*3);
    mav_array_memcpy(packet.velocity_sp, velocity_sp, sizeof(float)*3);
    mav_array_memcpy(packet.position, position, sizeof(float)*3);
    mav_array_memcpy(packet.position_sp, position_sp, sizeof(float)*3);
    mav_array_memcpy(packet.position_obver, position_obver, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_CRC);
}

/**
 * @brief Encode a wk_log_flight_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_flight_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_flight_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_log_flight_state_t* wk_log_flight_state)
{
    return mavlink_msg_wk_log_flight_state_pack(system_id, component_id, msg, wk_log_flight_state->timestamp, wk_log_flight_state->time_cnt, wk_log_flight_state->flag_arm, wk_log_flight_state->flight_mode, wk_log_flight_state->failsafe, wk_log_flight_state->inav_health, wk_log_flight_state->roll_rate, wk_log_flight_state->pitch_rate, wk_log_flight_state->yaw_rate, wk_log_flight_state->roll_rate_sp, wk_log_flight_state->pitch_rate_sp, wk_log_flight_state->yaw_rate_sp, wk_log_flight_state->roll, wk_log_flight_state->pitch, wk_log_flight_state->yaw, wk_log_flight_state->roll_sp, wk_log_flight_state->pitch_sp, wk_log_flight_state->yaw_sp, wk_log_flight_state->accel_ef, wk_log_flight_state->velocity, wk_log_flight_state->velocity_sp, wk_log_flight_state->position, wk_log_flight_state->position_sp, wk_log_flight_state->position_obver);
}

/**
 * @brief Encode a wk_log_flight_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_log_flight_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_log_flight_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_log_flight_state_t* wk_log_flight_state)
{
    return mavlink_msg_wk_log_flight_state_pack_chan(system_id, component_id, chan, msg, wk_log_flight_state->timestamp, wk_log_flight_state->time_cnt, wk_log_flight_state->flag_arm, wk_log_flight_state->flight_mode, wk_log_flight_state->failsafe, wk_log_flight_state->inav_health, wk_log_flight_state->roll_rate, wk_log_flight_state->pitch_rate, wk_log_flight_state->yaw_rate, wk_log_flight_state->roll_rate_sp, wk_log_flight_state->pitch_rate_sp, wk_log_flight_state->yaw_rate_sp, wk_log_flight_state->roll, wk_log_flight_state->pitch, wk_log_flight_state->yaw, wk_log_flight_state->roll_sp, wk_log_flight_state->pitch_sp, wk_log_flight_state->yaw_sp, wk_log_flight_state->accel_ef, wk_log_flight_state->velocity, wk_log_flight_state->velocity_sp, wk_log_flight_state->position, wk_log_flight_state->position_sp, wk_log_flight_state->position_obver);
}

/**
 * @brief Send a wk_log_flight_state message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp  timestamp
 * @param time_cnt  runtime counter
 * @param flag_arm  arm/disarm flag
 * @param flight_mode  flight mode
 * @param failsafe  radio failsafe flag
 * @param inav_health  inav health flag
 * @param roll_rate  roll rate
 * @param pitch_rate  pitch rate
 * @param yaw_rate  yaw rate
 * @param roll_rate_sp  roll_rate_sp
 * @param pitch_rate_sp  pitch_rate_sp
 * @param yaw_rate_sp  yaw_rate_sp
 * @param roll  roll
 * @param pitch  pitch
 * @param yaw  yaw
 * @param roll_sp  roll_sp
 * @param pitch_sp  pitch_sp
 * @param yaw_sp  yaw_sp
 * @param accel_ef  accel_ef
 * @param velocity  velocity
 * @param velocity_sp  velocity_sp
 * @param position  position
 * @param position_sp  position_sp
 * @param position_obver  position_obver
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_log_flight_state_send(mavlink_channel_t chan, uint64_t timestamp, uint16_t time_cnt, uint8_t flag_arm, uint8_t flight_mode, uint8_t failsafe, uint8_t inav_health, float roll_rate, float pitch_rate, float yaw_rate, float roll_rate_sp, float pitch_rate_sp, float yaw_rate_sp, float roll, float pitch, float yaw, float roll_sp, float pitch_sp, float yaw_sp, const float *accel_ef, const float *velocity, const float *velocity_sp, const float *position, const float *position_sp, const float *position_obver)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, roll_rate);
    _mav_put_float(buf, 12, pitch_rate);
    _mav_put_float(buf, 16, yaw_rate);
    _mav_put_float(buf, 20, roll_rate_sp);
    _mav_put_float(buf, 24, pitch_rate_sp);
    _mav_put_float(buf, 28, yaw_rate_sp);
    _mav_put_float(buf, 32, roll);
    _mav_put_float(buf, 36, pitch);
    _mav_put_float(buf, 40, yaw);
    _mav_put_float(buf, 44, roll_sp);
    _mav_put_float(buf, 48, pitch_sp);
    _mav_put_float(buf, 52, yaw_sp);
    _mav_put_uint16_t(buf, 128, time_cnt);
    _mav_put_uint8_t(buf, 130, flag_arm);
    _mav_put_uint8_t(buf, 131, flight_mode);
    _mav_put_uint8_t(buf, 132, failsafe);
    _mav_put_uint8_t(buf, 133, inav_health);
    _mav_put_float_array(buf, 56, accel_ef, 3);
    _mav_put_float_array(buf, 68, velocity, 3);
    _mav_put_float_array(buf, 80, velocity_sp, 3);
    _mav_put_float_array(buf, 92, position, 3);
    _mav_put_float_array(buf, 104, position_sp, 3);
    _mav_put_float_array(buf, 116, position_obver, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE, buf, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_CRC);
#else
    mavlink_wk_log_flight_state_t packet;
    packet.timestamp = timestamp;
    packet.roll_rate = roll_rate;
    packet.pitch_rate = pitch_rate;
    packet.yaw_rate = yaw_rate;
    packet.roll_rate_sp = roll_rate_sp;
    packet.pitch_rate_sp = pitch_rate_sp;
    packet.yaw_rate_sp = yaw_rate_sp;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.roll_sp = roll_sp;
    packet.pitch_sp = pitch_sp;
    packet.yaw_sp = yaw_sp;
    packet.time_cnt = time_cnt;
    packet.flag_arm = flag_arm;
    packet.flight_mode = flight_mode;
    packet.failsafe = failsafe;
    packet.inav_health = inav_health;
    mav_array_memcpy(packet.accel_ef, accel_ef, sizeof(float)*3);
    mav_array_memcpy(packet.velocity, velocity, sizeof(float)*3);
    mav_array_memcpy(packet.velocity_sp, velocity_sp, sizeof(float)*3);
    mav_array_memcpy(packet.position, position, sizeof(float)*3);
    mav_array_memcpy(packet.position_sp, position_sp, sizeof(float)*3);
    mav_array_memcpy(packet.position_obver, position_obver, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE, (const char *)&packet, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_CRC);
#endif
}

/**
 * @brief Send a wk_log_flight_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_log_flight_state_send_struct(mavlink_channel_t chan, const mavlink_wk_log_flight_state_t* wk_log_flight_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_log_flight_state_send(chan, wk_log_flight_state->timestamp, wk_log_flight_state->time_cnt, wk_log_flight_state->flag_arm, wk_log_flight_state->flight_mode, wk_log_flight_state->failsafe, wk_log_flight_state->inav_health, wk_log_flight_state->roll_rate, wk_log_flight_state->pitch_rate, wk_log_flight_state->yaw_rate, wk_log_flight_state->roll_rate_sp, wk_log_flight_state->pitch_rate_sp, wk_log_flight_state->yaw_rate_sp, wk_log_flight_state->roll, wk_log_flight_state->pitch, wk_log_flight_state->yaw, wk_log_flight_state->roll_sp, wk_log_flight_state->pitch_sp, wk_log_flight_state->yaw_sp, wk_log_flight_state->accel_ef, wk_log_flight_state->velocity, wk_log_flight_state->velocity_sp, wk_log_flight_state->position, wk_log_flight_state->position_sp, wk_log_flight_state->position_obver);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE, (const char *)wk_log_flight_state, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_log_flight_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, uint16_t time_cnt, uint8_t flag_arm, uint8_t flight_mode, uint8_t failsafe, uint8_t inav_health, float roll_rate, float pitch_rate, float yaw_rate, float roll_rate_sp, float pitch_rate_sp, float yaw_rate_sp, float roll, float pitch, float yaw, float roll_sp, float pitch_sp, float yaw_sp, const float *accel_ef, const float *velocity, const float *velocity_sp, const float *position, const float *position_sp, const float *position_obver)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float(buf, 8, roll_rate);
    _mav_put_float(buf, 12, pitch_rate);
    _mav_put_float(buf, 16, yaw_rate);
    _mav_put_float(buf, 20, roll_rate_sp);
    _mav_put_float(buf, 24, pitch_rate_sp);
    _mav_put_float(buf, 28, yaw_rate_sp);
    _mav_put_float(buf, 32, roll);
    _mav_put_float(buf, 36, pitch);
    _mav_put_float(buf, 40, yaw);
    _mav_put_float(buf, 44, roll_sp);
    _mav_put_float(buf, 48, pitch_sp);
    _mav_put_float(buf, 52, yaw_sp);
    _mav_put_uint16_t(buf, 128, time_cnt);
    _mav_put_uint8_t(buf, 130, flag_arm);
    _mav_put_uint8_t(buf, 131, flight_mode);
    _mav_put_uint8_t(buf, 132, failsafe);
    _mav_put_uint8_t(buf, 133, inav_health);
    _mav_put_float_array(buf, 56, accel_ef, 3);
    _mav_put_float_array(buf, 68, velocity, 3);
    _mav_put_float_array(buf, 80, velocity_sp, 3);
    _mav_put_float_array(buf, 92, position, 3);
    _mav_put_float_array(buf, 104, position_sp, 3);
    _mav_put_float_array(buf, 116, position_obver, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE, buf, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_CRC);
#else
    mavlink_wk_log_flight_state_t *packet = (mavlink_wk_log_flight_state_t *)msgbuf;
    packet->timestamp = timestamp;
    packet->roll_rate = roll_rate;
    packet->pitch_rate = pitch_rate;
    packet->yaw_rate = yaw_rate;
    packet->roll_rate_sp = roll_rate_sp;
    packet->pitch_rate_sp = pitch_rate_sp;
    packet->yaw_rate_sp = yaw_rate_sp;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->yaw = yaw;
    packet->roll_sp = roll_sp;
    packet->pitch_sp = pitch_sp;
    packet->yaw_sp = yaw_sp;
    packet->time_cnt = time_cnt;
    packet->flag_arm = flag_arm;
    packet->flight_mode = flight_mode;
    packet->failsafe = failsafe;
    packet->inav_health = inav_health;
    mav_array_memcpy(packet->accel_ef, accel_ef, sizeof(float)*3);
    mav_array_memcpy(packet->velocity, velocity, sizeof(float)*3);
    mav_array_memcpy(packet->velocity_sp, velocity_sp, sizeof(float)*3);
    mav_array_memcpy(packet->position, position, sizeof(float)*3);
    mav_array_memcpy(packet->position_sp, position_sp, sizeof(float)*3);
    mav_array_memcpy(packet->position_obver, position_obver, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE, (const char *)packet, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_MIN_LEN, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_LOG_FLIGHT_STATE UNPACKING


/**
 * @brief Get field timestamp from wk_log_flight_state message
 *
 * @return  timestamp
 */
static inline uint64_t mavlink_msg_wk_log_flight_state_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field time_cnt from wk_log_flight_state message
 *
 * @return  runtime counter
 */
static inline uint16_t mavlink_msg_wk_log_flight_state_get_time_cnt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  128);
}

/**
 * @brief Get field flag_arm from wk_log_flight_state message
 *
 * @return  arm/disarm flag
 */
static inline uint8_t mavlink_msg_wk_log_flight_state_get_flag_arm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  130);
}

/**
 * @brief Get field flight_mode from wk_log_flight_state message
 *
 * @return  flight mode
 */
static inline uint8_t mavlink_msg_wk_log_flight_state_get_flight_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  131);
}

/**
 * @brief Get field failsafe from wk_log_flight_state message
 *
 * @return  radio failsafe flag
 */
static inline uint8_t mavlink_msg_wk_log_flight_state_get_failsafe(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  132);
}

/**
 * @brief Get field inav_health from wk_log_flight_state message
 *
 * @return  inav health flag
 */
static inline uint8_t mavlink_msg_wk_log_flight_state_get_inav_health(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  133);
}

/**
 * @brief Get field roll_rate from wk_log_flight_state message
 *
 * @return  roll rate
 */
static inline float mavlink_msg_wk_log_flight_state_get_roll_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field pitch_rate from wk_log_flight_state message
 *
 * @return  pitch rate
 */
static inline float mavlink_msg_wk_log_flight_state_get_pitch_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field yaw_rate from wk_log_flight_state message
 *
 * @return  yaw rate
 */
static inline float mavlink_msg_wk_log_flight_state_get_yaw_rate(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field roll_rate_sp from wk_log_flight_state message
 *
 * @return  roll_rate_sp
 */
static inline float mavlink_msg_wk_log_flight_state_get_roll_rate_sp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field pitch_rate_sp from wk_log_flight_state message
 *
 * @return  pitch_rate_sp
 */
static inline float mavlink_msg_wk_log_flight_state_get_pitch_rate_sp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field yaw_rate_sp from wk_log_flight_state message
 *
 * @return  yaw_rate_sp
 */
static inline float mavlink_msg_wk_log_flight_state_get_yaw_rate_sp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field roll from wk_log_flight_state message
 *
 * @return  roll
 */
static inline float mavlink_msg_wk_log_flight_state_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field pitch from wk_log_flight_state message
 *
 * @return  pitch
 */
static inline float mavlink_msg_wk_log_flight_state_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field yaw from wk_log_flight_state message
 *
 * @return  yaw
 */
static inline float mavlink_msg_wk_log_flight_state_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field roll_sp from wk_log_flight_state message
 *
 * @return  roll_sp
 */
static inline float mavlink_msg_wk_log_flight_state_get_roll_sp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field pitch_sp from wk_log_flight_state message
 *
 * @return  pitch_sp
 */
static inline float mavlink_msg_wk_log_flight_state_get_pitch_sp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field yaw_sp from wk_log_flight_state message
 *
 * @return  yaw_sp
 */
static inline float mavlink_msg_wk_log_flight_state_get_yaw_sp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field accel_ef from wk_log_flight_state message
 *
 * @return  accel_ef
 */
static inline uint16_t mavlink_msg_wk_log_flight_state_get_accel_ef(const mavlink_message_t* msg, float *accel_ef)
{
    return _MAV_RETURN_float_array(msg, accel_ef, 3,  56);
}

/**
 * @brief Get field velocity from wk_log_flight_state message
 *
 * @return  velocity
 */
static inline uint16_t mavlink_msg_wk_log_flight_state_get_velocity(const mavlink_message_t* msg, float *velocity)
{
    return _MAV_RETURN_float_array(msg, velocity, 3,  68);
}

/**
 * @brief Get field velocity_sp from wk_log_flight_state message
 *
 * @return  velocity_sp
 */
static inline uint16_t mavlink_msg_wk_log_flight_state_get_velocity_sp(const mavlink_message_t* msg, float *velocity_sp)
{
    return _MAV_RETURN_float_array(msg, velocity_sp, 3,  80);
}

/**
 * @brief Get field position from wk_log_flight_state message
 *
 * @return  position
 */
static inline uint16_t mavlink_msg_wk_log_flight_state_get_position(const mavlink_message_t* msg, float *position)
{
    return _MAV_RETURN_float_array(msg, position, 3,  92);
}

/**
 * @brief Get field position_sp from wk_log_flight_state message
 *
 * @return  position_sp
 */
static inline uint16_t mavlink_msg_wk_log_flight_state_get_position_sp(const mavlink_message_t* msg, float *position_sp)
{
    return _MAV_RETURN_float_array(msg, position_sp, 3,  104);
}

/**
 * @brief Get field position_obver from wk_log_flight_state message
 *
 * @return  position_obver
 */
static inline uint16_t mavlink_msg_wk_log_flight_state_get_position_obver(const mavlink_message_t* msg, float *position_obver)
{
    return _MAV_RETURN_float_array(msg, position_obver, 3,  116);
}

/**
 * @brief Decode a wk_log_flight_state message into a struct
 *
 * @param msg The message to decode
 * @param wk_log_flight_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_log_flight_state_decode(const mavlink_message_t* msg, mavlink_wk_log_flight_state_t* wk_log_flight_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_log_flight_state->timestamp = mavlink_msg_wk_log_flight_state_get_timestamp(msg);
    wk_log_flight_state->roll_rate = mavlink_msg_wk_log_flight_state_get_roll_rate(msg);
    wk_log_flight_state->pitch_rate = mavlink_msg_wk_log_flight_state_get_pitch_rate(msg);
    wk_log_flight_state->yaw_rate = mavlink_msg_wk_log_flight_state_get_yaw_rate(msg);
    wk_log_flight_state->roll_rate_sp = mavlink_msg_wk_log_flight_state_get_roll_rate_sp(msg);
    wk_log_flight_state->pitch_rate_sp = mavlink_msg_wk_log_flight_state_get_pitch_rate_sp(msg);
    wk_log_flight_state->yaw_rate_sp = mavlink_msg_wk_log_flight_state_get_yaw_rate_sp(msg);
    wk_log_flight_state->roll = mavlink_msg_wk_log_flight_state_get_roll(msg);
    wk_log_flight_state->pitch = mavlink_msg_wk_log_flight_state_get_pitch(msg);
    wk_log_flight_state->yaw = mavlink_msg_wk_log_flight_state_get_yaw(msg);
    wk_log_flight_state->roll_sp = mavlink_msg_wk_log_flight_state_get_roll_sp(msg);
    wk_log_flight_state->pitch_sp = mavlink_msg_wk_log_flight_state_get_pitch_sp(msg);
    wk_log_flight_state->yaw_sp = mavlink_msg_wk_log_flight_state_get_yaw_sp(msg);
    mavlink_msg_wk_log_flight_state_get_accel_ef(msg, wk_log_flight_state->accel_ef);
    mavlink_msg_wk_log_flight_state_get_velocity(msg, wk_log_flight_state->velocity);
    mavlink_msg_wk_log_flight_state_get_velocity_sp(msg, wk_log_flight_state->velocity_sp);
    mavlink_msg_wk_log_flight_state_get_position(msg, wk_log_flight_state->position);
    mavlink_msg_wk_log_flight_state_get_position_sp(msg, wk_log_flight_state->position_sp);
    mavlink_msg_wk_log_flight_state_get_position_obver(msg, wk_log_flight_state->position_obver);
    wk_log_flight_state->time_cnt = mavlink_msg_wk_log_flight_state_get_time_cnt(msg);
    wk_log_flight_state->flag_arm = mavlink_msg_wk_log_flight_state_get_flag_arm(msg);
    wk_log_flight_state->flight_mode = mavlink_msg_wk_log_flight_state_get_flight_mode(msg);
    wk_log_flight_state->failsafe = mavlink_msg_wk_log_flight_state_get_failsafe(msg);
    wk_log_flight_state->inav_health = mavlink_msg_wk_log_flight_state_get_inav_health(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN? msg->len : MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN;
        memset(wk_log_flight_state, 0, MAVLINK_MSG_ID_WK_LOG_FLIGHT_STATE_LEN);
    memcpy(wk_log_flight_state, _MAV_PAYLOAD(msg), len);
#endif
}
