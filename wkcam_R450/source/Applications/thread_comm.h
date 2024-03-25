
#ifndef __THREAD_COMM_H__
#define __THREAD_COMM_H__

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <drv_usart.h>
#include <drv_net_api.h>
#include <mavlink_common.h>

#define MAX_CMDLENGTH  (512)
#define MIN_VT_BUFFER_SIZE 1024*1024/4

#define APP_SED_PORT  8079
#define UDP_SRC_PORT  8802
#define UDP_DST_PORT  8809
#define APP_UDP_PORT  8810
#define CAM_DST_PORT  8820
#define CAM_SRC_PORT  8821
#define SVP_SRC_PORT  8822
#define SVP_DST_PORT  8823
#define UDP_GRD_ADDR  "192.168.1.21"
#define SOCKET_SERVER "/tmp/sock_server" 
#define SOCKET_CLIENT "/tmp/sock_client" 

#define YOLOV3_DETECT 0
#define OPENCV_ARUCO  0

#define FRAME_FCS 	  0xdddd
#define FRAME_GRD 	  0xdddf
#define FRAME_MAV1 	  0xfe
#define FRAME_MAV2 	  0xfd

#define APP_TIMEOUT   60
#define MAX_RB_SIZE   10*1024

typedef struct {
    float mX;
    float mY;
    float mW;
    float mH; 
}YOLO_RECT_S;

bool thread_comm_init(void);

void PrintBuf(unsigned char DataBuf[] ,unsigned int DataLen);
void PutIntoRxQueue(char *dstbuf, int len);
void UdpSendHandle(char *buf,int size);
void CamSendHandle(char *buf,int size);
void setArucoDetectEnable(int enable_status);

void *MavlinkCmdAnalysisThread(void *arg);
void *UdpRecvThread(void *arg);
void comm_send_data(uint8_t *data, uint16_t length);

void *ArcuoDetectThread(void *pArgs);
void *YoloRecvThread(void *pArgs);
void *YoloDrawRectThread(void *pArgs);
int YoloSendHandle(char *buf,int size);
void yolo_send_data(char *messagebuf);

#endif /*  */

