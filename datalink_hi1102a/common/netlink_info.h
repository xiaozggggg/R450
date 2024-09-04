
#ifndef __NETLINK_INFO_H__
#define __NETLINK_INFO_H__

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <signal.h>
#include <pthread.h>
#include <errno.h>
#include <time.h>
#include <sys/stat.h>
#include <linux/netlink.h>
#include <linux/socket.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

//=========================  hi1102a config =========================//
#define NB_GET_REPORT_INFO 0
#define NB_NETLINK_ID 26
#define MAX_PAYLOAD 2048
#define RECV_BUF_LEN 512

#define NB_GET_REPORT_INFO 0
#define NB_SEND_CTRL_DATA  1
#define NB_SEND_NOKEY_MODE 2
#define NB_SEND_KEY_DATA   3
#define NB_RECV_KEY_DATA   4

#define GET_DEVICE_ID   "ifconfig | grep \"wlan0\" | awk '{print $5}' | awk -F: '{print $4 $5 $6}'"

typedef struct {
    int32_t l_nlkfd;                          /* netlink descriptor */
    unsigned char *uc_buf;                    /* recv sdt data buf */
    struct nlmsghdr *pst_nlh;                /* netlink message header */
} nb_globals_stru;

typedef struct {
	/* 连接状态：1-已连接，0-未连接 */
    unsigned char is_connected;
	/* 速率档位：0~5档，0档最小，5档最大
	 * 档位0： 5MHz带宽， 6Mbps空口速率，实测UDP速率  1.30Mbps
	 * 档位1：10MHz带宽， 6Mbps空口速率，实测UDP速率  2.60Mbps
	 * 档位2：10MHz带宽， 9Mbps空口速率，实测UDP速率  3.72Mbps
	 * 档位3：10MHz带宽，18Mbps空口速率，实测UDP速率  6.67Mbps
	 * 档位4：10MHz带宽，24Mbps空口速率，实测UDP速率  8.22Mbps
	 * 档位5：10MHz带宽，48Mbps空口速率，实测UDP速率 13.10Mbps
	*/
    unsigned char rate_level;
	/* 连接信道号：参考WiFi协议，如2G频段信道1~13，5G信道36，149等 */
    unsigned char channel;
	/* 通信带宽：129表示5MHz, 128表示10MHz */
    unsigned char bw;
	/* 接收信号强度：0~255，实际=rssi-256 dBm */
    char rssi;
	/* 物理层发帧成功率：百分比*100 */
    unsigned char succ_rate;
	/* 结构对齐预留 */
    unsigned char resv[2];
}nb_report_info;

struct nb_msg_hdr_stru {
    uint32_t cmd;
    uint32_t len;
};

int nb_netlink_create(void);
void nb_send_handle(void);
void nb_enable_match(void);
void nb_send_match_cmd(int type);
void nb_send_disable_match_cmd(void);
void nb_get_netlink_info(int *rssi);
int nb_netlink_send(unsigned char *data, uint len);
int nb_pthread_create(pthread_t *thd_id);
void nb_wifi_create_thread(void);
void nb_pthread_close(pthread_t thd_id);
void nb_pthread_kill(pthread_t thd_id);
void nb_pthread_exit(void);

#endif /* NETLINK_INFO */

