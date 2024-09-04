

#ifndef __TRANSMIT_H__
#define __TRANSMIT_H__

typedef struct {
    int32_t l_nlkfd;                          /* netlink descriptor */
    unsigned char *uc_buf;                    /* recv sdt data buf */
    struct nlmsghdr *pst_nlh;                /* netlink message header */
} drone_info_str;

void transmitter_setGPSdata(int32_t lat, int32_t lon, int32_t height, uint8_t numSV);
void transmitter_setSYSdata(char *droneid);
int transmitter_handle(void);

#endif /* __TRANSMIT_H__ */
