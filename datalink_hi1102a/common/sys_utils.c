
#include "sys_utils.h"

uint32_t system_time_ms_get(void)
{
    uint32_t time_ms;
    struct timeval stTime;

    gettimeofday(&stTime, NULL);

    time_ms = stTime.tv_sec * 1000 + stTime.tv_usec / 1000;

    return time_ms;
}


uint32_t system_timestamp_get(void)
{
    struct timeval stTime;

    gettimeofday(&stTime, NULL);
    
    return stTime.tv_sec;
}

uint32_t get_delta_time(uint32_t now,uint32_t last_time)
{
    if (now >= last_time)
    {
       return now - last_time;
    }else
    {
        return (UINT32_MAX - last_time + now);
    }
}

// Convert a single uint8_t to two chars representing the value in ASCII format
// 0 - 9 => 0x30 - 0x39, A - F => 0x41 - 0x46
void uchar_to_ascii(char *out, uint8_t in) {
    if (!out)
        return;

    unsigned char high = (in & 0xF0) >> 4;
    if (high < 0xA)
        *out++ = (char) (0x30 + high);
    else
        *out++ = (char) (0x41 + high - 0xA);
    unsigned char low = in & 0x0F;
    if (low < 0xA)
        *out = (char) (0x30 + low);
    else
        *out = (char) (0x41 + low - 0xA);
}
