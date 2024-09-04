

#ifndef __SYS_UTILS_H__
#define __SYS_UTILS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>       
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statfs.h>
#include <sys/time.h>

#include <stdbool.h>
#include <opendroneid.h>

struct config_data {
    bool use_beacon;

    bool use_btl; // Bluetooth Legacy Advertising
    bool use_bt4; // Bluetooth Legacy Advertising using Extended Advertising APIs
    bool use_bt5; // Bluetooth Long Range with Extended Advertising

    bool use_gps;
    
    uint8_t handle_bt4;
    uint8_t handle_bt5;

    bool use_packs; // Message packs

    uint8_t msg_counters[ODID_MSG_COUNTER_AMOUNT];
};

void uchar_to_ascii(char *out, uint8_t in);

uint32_t system_time_ms_get(void);

uint32_t system_timestamp_get(void);

uint32_t get_delta_time(uint32_t now,uint32_t last_time);

#endif /* __SYS_UTILS_H__ */
