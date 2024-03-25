

#ifndef __SYS_UTILS_H__
#define __SYS_UTILS_H__

#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>       
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statfs.h>
#include <sys/time.h>
#include <Socket.h>
#include <dirent.h>

extern uint32_t system_time_ms_get(void);

extern uint32_t system_timestamp_get(void);

extern uint32_t get_delta_time(uint32_t now,uint32_t last_time);

// get next file(.jpeg or .mp4) index
extern int get_next_file_index(char *path, char *name_prefix);

// check dir is exist or not
extern bool is_dir_exist(const char * path);


extern bool get_sdcard_available_capacity(long long * capacity);


// get local ip address
extern bool getLocalIpAddress(const char *EhxName ,char *IpAddressBuf);

#ifdef __cplusplus
}
#endif

#endif /* __SYS_UTILS_H__ */
