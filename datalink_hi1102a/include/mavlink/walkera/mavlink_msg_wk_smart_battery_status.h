#pragma once
// MESSAGE WK_SMART_BATTERY_STATUS PACKING

#define MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS 8007


typedef struct __mavlink_wk_smart_battery_status_t {
 uint32_t fault_bitmasks; /*<  fault error bitmasks*/
 uint32_t capacity_design; /*<  capacity_design*/
 uint32_t capacity_full_charge; /*<  capacity full charge*/
 uint32_t capacity_remaining; /*<  capacity remaining*/
 float voltage; /*<  voltage*/
 float current; /*<  current*/
 float temperature; /*<  temperature*/
 float cell_volt[16]; /*<  cell voltages*/
 uint16_t version; /*<  version*/
 uint16_t cycle_count; /*<  cycle count*/
 uint8_t serial_number[12]; /*<  serial number*/
 uint8_t production_date[12]; /*<  productino date*/
 uint8_t cell_count; /*<  count of cells*/
} mavlink_wk_smart_battery_status_t;

#define MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN 121
#define MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_MIN_LEN 121
#define MAVLINK_MSG_ID_8007_LEN 121
#define MAVLINK_MSG_ID_8007_MIN_LEN 121

#define MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_CRC 205
#define MAVLINK_MSG_ID_8007_CRC 205

#define MAVLINK_MSG_WK_SMART_BATTERY_STATUS_FIELD_CELL_VOLT_LEN 16
#define MAVLINK_MSG_WK_SMART_BATTERY_STATUS_FIELD_SERIAL_NUMBER_LEN 12
#define MAVLINK_MSG_WK_SMART_BATTERY_STATUS_FIELD_PRODUCTION_DATE_LEN 12

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WK_SMART_BATTERY_STATUS { \
    8007, \
    "WK_SMART_BATTERY_STATUS", \
    13, \
    {  { "serial_number", NULL, MAVLINK_TYPE_UINT8_T, 12, 96, offsetof(mavlink_wk_smart_battery_status_t, serial_number) }, \
         { "production_date", NULL, MAVLINK_TYPE_UINT8_T, 12, 108, offsetof(mavlink_wk_smart_battery_status_t, production_date) }, \
         { "cell_count", NULL, MAVLINK_TYPE_UINT8_T, 0, 120, offsetof(mavlink_wk_smart_battery_status_t, cell_count) }, \
         { "fault_bitmasks", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_smart_battery_status_t, fault_bitmasks) }, \
         { "version", NULL, MAVLINK_TYPE_UINT16_T, 0, 92, offsetof(mavlink_wk_smart_battery_status_t, version) }, \
         { "capacity_design", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_smart_battery_status_t, capacity_design) }, \
         { "capacity_full_charge", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_smart_battery_status_t, capacity_full_charge) }, \
         { "capacity_remaining", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_wk_smart_battery_status_t, capacity_remaining) }, \
         { "cycle_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 94, offsetof(mavlink_wk_smart_battery_status_t, cycle_count) }, \
         { "voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_smart_battery_status_t, voltage) }, \
         { "current", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_smart_battery_status_t, current) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wk_smart_battery_status_t, temperature) }, \
         { "cell_volt", NULL, MAVLINK_TYPE_FLOAT, 16, 28, offsetof(mavlink_wk_smart_battery_status_t, cell_volt) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WK_SMART_BATTERY_STATUS { \
    "WK_SMART_BATTERY_STATUS", \
    13, \
    {  { "serial_number", NULL, MAVLINK_TYPE_UINT8_T, 12, 96, offsetof(mavlink_wk_smart_battery_status_t, serial_number) }, \
         { "production_date", NULL, MAVLINK_TYPE_UINT8_T, 12, 108, offsetof(mavlink_wk_smart_battery_status_t, production_date) }, \
         { "cell_count", NULL, MAVLINK_TYPE_UINT8_T, 0, 120, offsetof(mavlink_wk_smart_battery_status_t, cell_count) }, \
         { "fault_bitmasks", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_wk_smart_battery_status_t, fault_bitmasks) }, \
         { "version", NULL, MAVLINK_TYPE_UINT16_T, 0, 92, offsetof(mavlink_wk_smart_battery_status_t, version) }, \
         { "capacity_design", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_wk_smart_battery_status_t, capacity_design) }, \
         { "capacity_full_charge", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_wk_smart_battery_status_t, capacity_full_charge) }, \
         { "capacity_remaining", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_wk_smart_battery_status_t, capacity_remaining) }, \
         { "cycle_count", NULL, MAVLINK_TYPE_UINT16_T, 0, 94, offsetof(mavlink_wk_smart_battery_status_t, cycle_count) }, \
         { "voltage", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_wk_smart_battery_status_t, voltage) }, \
         { "current", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_wk_smart_battery_status_t, current) }, \
         { "temperature", NULL, MAVLINK_TYPE_FLOAT, 0, 24, offsetof(mavlink_wk_smart_battery_status_t, temperature) }, \
         { "cell_volt", NULL, MAVLINK_TYPE_FLOAT, 16, 28, offsetof(mavlink_wk_smart_battery_status_t, cell_volt) }, \
         } \
}
#endif

/**
 * @brief Pack a wk_smart_battery_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param serial_number  serial number
 * @param production_date  productino date
 * @param cell_count  count of cells
 * @param fault_bitmasks  fault error bitmasks
 * @param version  version
 * @param capacity_design  capacity_design
 * @param capacity_full_charge  capacity full charge
 * @param capacity_remaining  capacity remaining
 * @param cycle_count  cycle count
 * @param voltage  voltage
 * @param current  current
 * @param temperature  temperature
 * @param cell_volt  cell voltages
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_smart_battery_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint8_t *serial_number, const uint8_t *production_date, uint8_t cell_count, uint32_t fault_bitmasks, uint16_t version, uint32_t capacity_design, uint32_t capacity_full_charge, uint32_t capacity_remaining, uint16_t cycle_count, float voltage, float current, float temperature, const float *cell_volt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, fault_bitmasks);
    _mav_put_uint32_t(buf, 4, capacity_design);
    _mav_put_uint32_t(buf, 8, capacity_full_charge);
    _mav_put_uint32_t(buf, 12, capacity_remaining);
    _mav_put_float(buf, 16, voltage);
    _mav_put_float(buf, 20, current);
    _mav_put_float(buf, 24, temperature);
    _mav_put_uint16_t(buf, 92, version);
    _mav_put_uint16_t(buf, 94, cycle_count);
    _mav_put_uint8_t(buf, 120, cell_count);
    _mav_put_float_array(buf, 28, cell_volt, 16);
    _mav_put_uint8_t_array(buf, 96, serial_number, 12);
    _mav_put_uint8_t_array(buf, 108, production_date, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN);
#else
    mavlink_wk_smart_battery_status_t packet;
    packet.fault_bitmasks = fault_bitmasks;
    packet.capacity_design = capacity_design;
    packet.capacity_full_charge = capacity_full_charge;
    packet.capacity_remaining = capacity_remaining;
    packet.voltage = voltage;
    packet.current = current;
    packet.temperature = temperature;
    packet.version = version;
    packet.cycle_count = cycle_count;
    packet.cell_count = cell_count;
    mav_array_memcpy(packet.cell_volt, cell_volt, sizeof(float)*16);
    mav_array_memcpy(packet.serial_number, serial_number, sizeof(uint8_t)*12);
    mav_array_memcpy(packet.production_date, production_date, sizeof(uint8_t)*12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_CRC);
}

/**
 * @brief Pack a wk_smart_battery_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param serial_number  serial number
 * @param production_date  productino date
 * @param cell_count  count of cells
 * @param fault_bitmasks  fault error bitmasks
 * @param version  version
 * @param capacity_design  capacity_design
 * @param capacity_full_charge  capacity full charge
 * @param capacity_remaining  capacity remaining
 * @param cycle_count  cycle count
 * @param voltage  voltage
 * @param current  current
 * @param temperature  temperature
 * @param cell_volt  cell voltages
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wk_smart_battery_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint8_t *serial_number,const uint8_t *production_date,uint8_t cell_count,uint32_t fault_bitmasks,uint16_t version,uint32_t capacity_design,uint32_t capacity_full_charge,uint32_t capacity_remaining,uint16_t cycle_count,float voltage,float current,float temperature,const float *cell_volt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, fault_bitmasks);
    _mav_put_uint32_t(buf, 4, capacity_design);
    _mav_put_uint32_t(buf, 8, capacity_full_charge);
    _mav_put_uint32_t(buf, 12, capacity_remaining);
    _mav_put_float(buf, 16, voltage);
    _mav_put_float(buf, 20, current);
    _mav_put_float(buf, 24, temperature);
    _mav_put_uint16_t(buf, 92, version);
    _mav_put_uint16_t(buf, 94, cycle_count);
    _mav_put_uint8_t(buf, 120, cell_count);
    _mav_put_float_array(buf, 28, cell_volt, 16);
    _mav_put_uint8_t_array(buf, 96, serial_number, 12);
    _mav_put_uint8_t_array(buf, 108, production_date, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN);
#else
    mavlink_wk_smart_battery_status_t packet;
    packet.fault_bitmasks = fault_bitmasks;
    packet.capacity_design = capacity_design;
    packet.capacity_full_charge = capacity_full_charge;
    packet.capacity_remaining = capacity_remaining;
    packet.voltage = voltage;
    packet.current = current;
    packet.temperature = temperature;
    packet.version = version;
    packet.cycle_count = cycle_count;
    packet.cell_count = cell_count;
    mav_array_memcpy(packet.cell_volt, cell_volt, sizeof(float)*16);
    mav_array_memcpy(packet.serial_number, serial_number, sizeof(uint8_t)*12);
    mav_array_memcpy(packet.production_date, production_date, sizeof(uint8_t)*12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_CRC);
}

/**
 * @brief Encode a wk_smart_battery_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wk_smart_battery_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_smart_battery_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wk_smart_battery_status_t* wk_smart_battery_status)
{
    return mavlink_msg_wk_smart_battery_status_pack(system_id, component_id, msg, wk_smart_battery_status->serial_number, wk_smart_battery_status->production_date, wk_smart_battery_status->cell_count, wk_smart_battery_status->fault_bitmasks, wk_smart_battery_status->version, wk_smart_battery_status->capacity_design, wk_smart_battery_status->capacity_full_charge, wk_smart_battery_status->capacity_remaining, wk_smart_battery_status->cycle_count, wk_smart_battery_status->voltage, wk_smart_battery_status->current, wk_smart_battery_status->temperature, wk_smart_battery_status->cell_volt);
}

/**
 * @brief Encode a wk_smart_battery_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wk_smart_battery_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wk_smart_battery_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wk_smart_battery_status_t* wk_smart_battery_status)
{
    return mavlink_msg_wk_smart_battery_status_pack_chan(system_id, component_id, chan, msg, wk_smart_battery_status->serial_number, wk_smart_battery_status->production_date, wk_smart_battery_status->cell_count, wk_smart_battery_status->fault_bitmasks, wk_smart_battery_status->version, wk_smart_battery_status->capacity_design, wk_smart_battery_status->capacity_full_charge, wk_smart_battery_status->capacity_remaining, wk_smart_battery_status->cycle_count, wk_smart_battery_status->voltage, wk_smart_battery_status->current, wk_smart_battery_status->temperature, wk_smart_battery_status->cell_volt);
}

/**
 * @brief Send a wk_smart_battery_status message
 * @param chan MAVLink channel to send the message
 *
 * @param serial_number  serial number
 * @param production_date  productino date
 * @param cell_count  count of cells
 * @param fault_bitmasks  fault error bitmasks
 * @param version  version
 * @param capacity_design  capacity_design
 * @param capacity_full_charge  capacity full charge
 * @param capacity_remaining  capacity remaining
 * @param cycle_count  cycle count
 * @param voltage  voltage
 * @param current  current
 * @param temperature  temperature
 * @param cell_volt  cell voltages
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wk_smart_battery_status_send(mavlink_channel_t chan, const uint8_t *serial_number, const uint8_t *production_date, uint8_t cell_count, uint32_t fault_bitmasks, uint16_t version, uint32_t capacity_design, uint32_t capacity_full_charge, uint32_t capacity_remaining, uint16_t cycle_count, float voltage, float current, float temperature, const float *cell_volt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, fault_bitmasks);
    _mav_put_uint32_t(buf, 4, capacity_design);
    _mav_put_uint32_t(buf, 8, capacity_full_charge);
    _mav_put_uint32_t(buf, 12, capacity_remaining);
    _mav_put_float(buf, 16, voltage);
    _mav_put_float(buf, 20, current);
    _mav_put_float(buf, 24, temperature);
    _mav_put_uint16_t(buf, 92, version);
    _mav_put_uint16_t(buf, 94, cycle_count);
    _mav_put_uint8_t(buf, 120, cell_count);
    _mav_put_float_array(buf, 28, cell_volt, 16);
    _mav_put_uint8_t_array(buf, 96, serial_number, 12);
    _mav_put_uint8_t_array(buf, 108, production_date, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS, buf, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_CRC);
#else
    mavlink_wk_smart_battery_status_t packet;
    packet.fault_bitmasks = fault_bitmasks;
    packet.capacity_design = capacity_design;
    packet.capacity_full_charge = capacity_full_charge;
    packet.capacity_remaining = capacity_remaining;
    packet.voltage = voltage;
    packet.current = current;
    packet.temperature = temperature;
    packet.version = version;
    packet.cycle_count = cycle_count;
    packet.cell_count = cell_count;
    mav_array_memcpy(packet.cell_volt, cell_volt, sizeof(float)*16);
    mav_array_memcpy(packet.serial_number, serial_number, sizeof(uint8_t)*12);
    mav_array_memcpy(packet.production_date, production_date, sizeof(uint8_t)*12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS, (const char *)&packet, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_CRC);
#endif
}

/**
 * @brief Send a wk_smart_battery_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wk_smart_battery_status_send_struct(mavlink_channel_t chan, const mavlink_wk_smart_battery_status_t* wk_smart_battery_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wk_smart_battery_status_send(chan, wk_smart_battery_status->serial_number, wk_smart_battery_status->production_date, wk_smart_battery_status->cell_count, wk_smart_battery_status->fault_bitmasks, wk_smart_battery_status->version, wk_smart_battery_status->capacity_design, wk_smart_battery_status->capacity_full_charge, wk_smart_battery_status->capacity_remaining, wk_smart_battery_status->cycle_count, wk_smart_battery_status->voltage, wk_smart_battery_status->current, wk_smart_battery_status->temperature, wk_smart_battery_status->cell_volt);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS, (const char *)wk_smart_battery_status, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wk_smart_battery_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint8_t *serial_number, const uint8_t *production_date, uint8_t cell_count, uint32_t fault_bitmasks, uint16_t version, uint32_t capacity_design, uint32_t capacity_full_charge, uint32_t capacity_remaining, uint16_t cycle_count, float voltage, float current, float temperature, const float *cell_volt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, fault_bitmasks);
    _mav_put_uint32_t(buf, 4, capacity_design);
    _mav_put_uint32_t(buf, 8, capacity_full_charge);
    _mav_put_uint32_t(buf, 12, capacity_remaining);
    _mav_put_float(buf, 16, voltage);
    _mav_put_float(buf, 20, current);
    _mav_put_float(buf, 24, temperature);
    _mav_put_uint16_t(buf, 92, version);
    _mav_put_uint16_t(buf, 94, cycle_count);
    _mav_put_uint8_t(buf, 120, cell_count);
    _mav_put_float_array(buf, 28, cell_volt, 16);
    _mav_put_uint8_t_array(buf, 96, serial_number, 12);
    _mav_put_uint8_t_array(buf, 108, production_date, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS, buf, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_CRC);
#else
    mavlink_wk_smart_battery_status_t *packet = (mavlink_wk_smart_battery_status_t *)msgbuf;
    packet->fault_bitmasks = fault_bitmasks;
    packet->capacity_design = capacity_design;
    packet->capacity_full_charge = capacity_full_charge;
    packet->capacity_remaining = capacity_remaining;
    packet->voltage = voltage;
    packet->current = current;
    packet->temperature = temperature;
    packet->version = version;
    packet->cycle_count = cycle_count;
    packet->cell_count = cell_count;
    mav_array_memcpy(packet->cell_volt, cell_volt, sizeof(float)*16);
    mav_array_memcpy(packet->serial_number, serial_number, sizeof(uint8_t)*12);
    mav_array_memcpy(packet->production_date, production_date, sizeof(uint8_t)*12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS, (const char *)packet, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_MIN_LEN, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE WK_SMART_BATTERY_STATUS UNPACKING


/**
 * @brief Get field serial_number from wk_smart_battery_status message
 *
 * @return  serial number
 */
static inline uint16_t mavlink_msg_wk_smart_battery_status_get_serial_number(const mavlink_message_t* msg, uint8_t *serial_number)
{
    return _MAV_RETURN_uint8_t_array(msg, serial_number, 12,  96);
}

/**
 * @brief Get field production_date from wk_smart_battery_status message
 *
 * @return  productino date
 */
static inline uint16_t mavlink_msg_wk_smart_battery_status_get_production_date(const mavlink_message_t* msg, uint8_t *production_date)
{
    return _MAV_RETURN_uint8_t_array(msg, production_date, 12,  108);
}

/**
 * @brief Get field cell_count from wk_smart_battery_status message
 *
 * @return  count of cells
 */
static inline uint8_t mavlink_msg_wk_smart_battery_status_get_cell_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  120);
}

/**
 * @brief Get field fault_bitmasks from wk_smart_battery_status message
 *
 * @return  fault error bitmasks
 */
static inline uint32_t mavlink_msg_wk_smart_battery_status_get_fault_bitmasks(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field version from wk_smart_battery_status message
 *
 * @return  version
 */
static inline uint16_t mavlink_msg_wk_smart_battery_status_get_version(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  92);
}

/**
 * @brief Get field capacity_design from wk_smart_battery_status message
 *
 * @return  capacity_design
 */
static inline uint32_t mavlink_msg_wk_smart_battery_status_get_capacity_design(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field capacity_full_charge from wk_smart_battery_status message
 *
 * @return  capacity full charge
 */
static inline uint32_t mavlink_msg_wk_smart_battery_status_get_capacity_full_charge(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field capacity_remaining from wk_smart_battery_status message
 *
 * @return  capacity remaining
 */
static inline uint32_t mavlink_msg_wk_smart_battery_status_get_capacity_remaining(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field cycle_count from wk_smart_battery_status message
 *
 * @return  cycle count
 */
static inline uint16_t mavlink_msg_wk_smart_battery_status_get_cycle_count(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  94);
}

/**
 * @brief Get field voltage from wk_smart_battery_status message
 *
 * @return  voltage
 */
static inline float mavlink_msg_wk_smart_battery_status_get_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field current from wk_smart_battery_status message
 *
 * @return  current
 */
static inline float mavlink_msg_wk_smart_battery_status_get_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field temperature from wk_smart_battery_status message
 *
 * @return  temperature
 */
static inline float mavlink_msg_wk_smart_battery_status_get_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field cell_volt from wk_smart_battery_status message
 *
 * @return  cell voltages
 */
static inline uint16_t mavlink_msg_wk_smart_battery_status_get_cell_volt(const mavlink_message_t* msg, float *cell_volt)
{
    return _MAV_RETURN_float_array(msg, cell_volt, 16,  28);
}

/**
 * @brief Decode a wk_smart_battery_status message into a struct
 *
 * @param msg The message to decode
 * @param wk_smart_battery_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_wk_smart_battery_status_decode(const mavlink_message_t* msg, mavlink_wk_smart_battery_status_t* wk_smart_battery_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wk_smart_battery_status->fault_bitmasks = mavlink_msg_wk_smart_battery_status_get_fault_bitmasks(msg);
    wk_smart_battery_status->capacity_design = mavlink_msg_wk_smart_battery_status_get_capacity_design(msg);
    wk_smart_battery_status->capacity_full_charge = mavlink_msg_wk_smart_battery_status_get_capacity_full_charge(msg);
    wk_smart_battery_status->capacity_remaining = mavlink_msg_wk_smart_battery_status_get_capacity_remaining(msg);
    wk_smart_battery_status->voltage = mavlink_msg_wk_smart_battery_status_get_voltage(msg);
    wk_smart_battery_status->current = mavlink_msg_wk_smart_battery_status_get_current(msg);
    wk_smart_battery_status->temperature = mavlink_msg_wk_smart_battery_status_get_temperature(msg);
    mavlink_msg_wk_smart_battery_status_get_cell_volt(msg, wk_smart_battery_status->cell_volt);
    wk_smart_battery_status->version = mavlink_msg_wk_smart_battery_status_get_version(msg);
    wk_smart_battery_status->cycle_count = mavlink_msg_wk_smart_battery_status_get_cycle_count(msg);
    mavlink_msg_wk_smart_battery_status_get_serial_number(msg, wk_smart_battery_status->serial_number);
    mavlink_msg_wk_smart_battery_status_get_production_date(msg, wk_smart_battery_status->production_date);
    wk_smart_battery_status->cell_count = mavlink_msg_wk_smart_battery_status_get_cell_count(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN? msg->len : MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN;
        memset(wk_smart_battery_status, 0, MAVLINK_MSG_ID_WK_SMART_BATTERY_STATUS_LEN);
    memcpy(wk_smart_battery_status, _MAV_PAYLOAD(msg), len);
#endif
}
