
#ifndef __DATA_CENTER_H__
#define __DATA_CENTER_H__

#include <thread>
#include "TcpClient.h"
#include "mobilecc.h"
#include "Protocol.h"
#include "WKMD5.h"

extern "C"{
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdint.h>
    #include <string.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <linux/ioctl.h>
    #include <linux/types.h>
    #include <time.h> 
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <errno.h>
    #include <math.h>
    #include <netinet/in.h>
    #include <sys/un.h>
};

#define UDP_SRC_PORT 	8808
#define UDP_DST_PORT 	8809
#define APP_UDP_PORT 	8810
#define CAM_SRC_PORT    8820
#define CAM_DST_PORT    8821
#define UDP_GRD_ADDR 	"192.168.1.21"

#define SOCKET_SERVER   "/tmp/sock_server" 
#define SOCKET_CLIENT   "/tmp/sock_client" 

#define SOCKET_IMU_SERVER   "/tmp/imu_sock_server" 
#define SOCKET_IMU_CLIENT   "/tmp/imu_sock_client" 


#define FRAME_FCS 	    0xdddd
#define FRAME_GRD 	    0xdddf
#define FRAME_BEA       0xaaaa
#define FRAME_MAV1 	    0xfe
#define FRAME_MAV2 	    0xfd

#define APP_TIMEOUT     20

#define MAX_RB_SIZE           20*1024
#define MAX_CMDLENGTH         2*1024
#define ITEM_COUNT	          30
#define MAVLINK_TARGET_GND    1
#define MAVLINK_TARGET_CAM    2

#define MAX_MATCH_TIMEOUT     60
#define MATCH_TIMEOUT_ACK     3

#define GET_CAMERA_PID  "ps | grep \"wkcam_f210\" | grep -v grep | awk '{printf $1}'"
#define GET_DEVICE_ID   "ifconfig | grep \"wlan0\" | awk '{print $5}' | awk -F: '{print $4 $5 $6}'"
#define GET_CSW_STATUS  "cat /proc/net/csw2201/wlan0/rx_info_msg | grep RF_PATH_0 | awk -F: '{printf $2}'"
#define GET_SUPPLICANT_PID  "ps | grep \"hostapd\" | grep -v grep | awk '{printf $1}'"

typedef enum{
    CSW_DISCONNECT = 0,
    CSW_CONNECT,
    CSW_MATCH_START,
    CSW_MATCH_ING
}CSW_STATUS_E;

typedef enum{
    WK_CHARGE_ENABLE = 0,
    WK_CHARGE_DISABLE
}WK_CHARGE_E;

typedef enum{
    FILE_OPENED = 0,
    FILE_READY_CLOSE,
    FILE_READY_START
}FILE_TASK_E;

typedef enum{
    DRONE_ARMED = 0,
    DRONE_DISARMED
}DRONE_ARMED_MODE_E;

typedef enum{
    WIFI_SET_TO_STA = 0,
    WIFI_SET_TO_AP,
    WIFI_IN_AP
}WK_WIFI_CONFIG_E;

typedef struct{
    unsigned char mavlink_cmd[300]; //对频命令消息
    unsigned char match_enable;     //对频开始标志
    int  match_timeout;             //对频超时时间
    int  cmd_length;                //对频命令长度
    unsigned long long timestamp;   //指令时间戳
}CSW_MATCH_S;

typedef struct{
    int nDataLength;
	bool msg_received;
    int msg_type;
	int msg_id;
	char parse_state;
	int msg_step;
	char chk_sum;
    unsigned char msgbuf[MAX_CMDLENGTH];
}MSG_INFO_S;

typedef struct {
    unsigned int  year;
    unsigned int  month;
    unsigned int  date;
    unsigned int  hour;
    unsigned int  minute;
    unsigned int  second;
    unsigned int  weekday;
}CAM_TIME_T;

typedef struct {
    int32_t alt;                                  
    int32_t lat; 
    int32_t lng;
    int sat_mode;
}Location;

typedef struct
{
    int set_wifi_config;
    int set_wifi_busy;
}WIFI_CONF_S;


//=====================================================//
class DataCenter
{
public:
    int drone_mode;
    char file_task;

    //===== Data and Time Zone ====//
    Location home_local;
    char sync_fcs_systime;
    char sync_app_systime;

    //===== CSW match function ======//
    CSW_MATCH_S mMatchInfo;
    WIFI_CONF_S mWifiConf;

    //===== debug variue =====//
    char received_count;
    char received_count_dd;
    char received_count_df;
    int  send_count;

    //===== udp socket =====//
    struct sockaddr_in addr_dst;
    int Sock_send = 0;

    struct sockaddr_in addr_app;
    int Sock_APP = -1;
    bool app_connect; //是否收到app的数据
    int app_count;

    //===== local socket =====//
    struct sockaddr_un addr_un_remote;
    int Sock_cam = -1;

    //===== process watchdog =====//
    int wkcam_process_enable;

    //===== local imu socket and rw_buf =====//
    struct sockaddr_un imu_addr_un_remote;
    int Imu_Sock_cam = -1;
	uint8_t rw_buffer[MAX_CMDLENGTH*2];
	uint16_t u32rw_buf_index;
	uint64_t u64sync_pts_last_ms;

private:
    //====== 4G server communicate =====//
    unsigned char OnlineServerIp[20];
    bool server_auth;

    mobilecc *mSimModule;
    TcpClient mCmdClient;

    //======  thread id ==========//
    std::thread udpRecvThreadid;
    std::thread camRecvThreadid;
    std::thread uartRecvThreadid;
    std::thread vtMatchThreadid;
    std::thread loggerThreadid;
    std::thread appRecvThreadid;
    std::thread connectThreadid;
    std::thread heartbeatThreadid;
    
public:
    DataCenter();
    ~DataCenter();
    
    void Start(void);

    //================ protocol analysis ================//
    int  checkMavlinkMsgId(int msg_id);
    void UartParseChar(unsigned char temp,MSG_INFO_S *recv_message);
    void mavlink_decode_FCS(unsigned char byte);
    void mavlink_decode_GRD(unsigned char byte);
    void mavlink_decode_SER(unsigned char byte);

    //================ 2.4G module communicate ================//
    void UdpRecvFcsThread(void);
    int  UdpSendHandle(unsigned char *buf,int size);

    //================ process communicate ================//
    void CamRecvThread(void);
    int  CamSendHandle(unsigned char *buf,int size);
    void sendRTSPcmd(uint8_t status);

    //================ process imu communicate ================//
    int CamImuUnixSocketCreate(void);
    int  CamImuSendHandle(uint8_t *buf, uint32_t size);
	uint8_t CamImuDatasum(uint8_t* data, uint8_t length);
	int CamImuHandle(uint8_t *src_buf, uint16_t src_size, uint8_t other[], uint16_t* out_size);
	int CamImuInit();
	int CamImuDeInit();

    //================ fcs communicate ================//
    void UartRevThread(void);
    void LoggerAnalysisThread(void);

    //================ 2.4G module setting ================//
    CSW_STATUS_E getVTStatus(int vt_rssi, int timeout);
    void sendMatchStatus(int csw_rssi);
    void VTMatchThread(void);
    void send_wifi_ack(WIFI_CONF_S wifi_conf);

    //================ app direct communicate =================//
    void AppRevThread(void);
    int  AppSendHandle(unsigned char *buf,int size);
    void AppSocketReset(void);

    //================ 4g communicate ==============//
    void CmdClientHeartBeatThread(void);
    void CmdClientSelectThread(void);
    void CmdClientConnectThread(void);
    int  tcpSendHandle(unsigned char *buf, int size);

    int  comm_send_handle(unsigned char *buf,int size);
};

#endif

