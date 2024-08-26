

#include <thread_comm.h>
#include <cJSON.h>
#include <sample_comm.h>
#include "wkringbuffer.h"
#include "wk_log.h"

struct rt_ringbuffer rb_queue;   //recv from uart1
unsigned char rb_buffer[MAX_RB_SIZE];

struct sockaddr_in addr_dst;     //grd address
int Sock_send = 0;

struct sockaddr_in addr_app;     //app address
int  Sock_app = 0;
char app_ipaddr[20];
int  app_port;
int  app_connect = 0;

struct sockaddr_in addr_wkyolo;  //yolo address
int Sock_wkyolo= 0;

struct sockaddr_un addr_remote;  //datalink address
int Sock_wkdata = 0;

void PrintBuftest(unsigned char DataBuf[] ,unsigned int DataLen)
{
    unsigned int i;
    for(i=0;i<DataLen;i++){
        printf("%x ", DataBuf[i]);
    }
    printf("\n");
	
	return;
}

void *MavlinkCmdAnalysisThread(void *arg) 
{
    int i;
    int rb_lenght;
    unsigned char buffer[MAX_CMDLENGTH];

    while(1)
    {
        rb_lenght = rt_ringbuffer_get(&rb_queue, buffer, MAX_CMDLENGTH);
        if(rb_lenght > 0){
            for(i = 0;i<rb_lenght;i++){
                mavlink_decode(buffer[i]);
            }
        }
        else{
            usleep(10*1000);
        }

        // call mavlink prodic tasks
        mavlink_prodic_tasks();
    }
}

/*
 * received data from process (datalink)
 */
void *SocketRecvThread(void *arg)
{
	int nRet = 0;
	int clen;
    int flag;
	unsigned char buf[1024];

	int nAddrLen = -1;
	char ipaddr[32];
    struct sockaddr_un addr_local;     //local address

    while(1)
    {
        Sock_wkdata = socket(AF_UNIX, SOCK_DGRAM, 0);
        if(Sock_wkdata < 0){
            WK_LOGE("socket create failed\n");
            sleep(1);
            continue;
        }
    
        addr_local.sun_family = AF_UNIX;
        sprintf(addr_local.sun_path, SOCKET_CLIENT);
        remove(SOCKET_CLIENT);//绑定之前要删除原来的文件
        if(bind(Sock_wkdata, (struct sockaddr*)&addr_local, sizeof(addr_local)) < 0){
            close(Sock_wkdata);
            WK_LOGE("bind address failed \n");
            sleep(1);
            continue;
        }
        WK_LOGD("Bind wkcam addr success Sock_wkdata[%d]!\n",Sock_wkdata);

        addr_remote.sun_family = AF_UNIX;
        sprintf(addr_remote.sun_path, SOCKET_SERVER);

        while(1)
        {
            clen = recvfrom(Sock_wkdata, buf, sizeof(buf), 0, NULL, NULL);
            if(clen > 0){
                // PrintBuftest(buf, clen);
                if(buf[0] == 0xaa && buf[1] == 0xaa && buf[clen-1] == 0xff){
                    app_connect = buf[2];
                    app_port = buf[3] << 8 | buf[4];
                    memcpy(app_ipaddr, buf+5, clen-6);

                    // printf("=============== app connect heartbeat =========== \n");
                    // printf("=============== app connect status[%d] ip addr is[%s] port[%d]\n", app_connect, app_ipaddr, app_port);
                }
                else{
                    rt_ringbuffer_put(&rb_queue, buf, clen);
                }
            }

            usleep(5*1000);
        }
    }
}

/*
 * send data to datalink process
 */
void CamSendHandle(char *buf,int size)
{
    int nRet;

    nRet = sendto(Sock_wkdata, buf, size, 0, (struct sockaddr*)&addr_remote, sizeof(addr_remote));

	return;
}

/*
 * send data to grd
 */
void UdpSendHandle(char *buf,int size)
{
    int nRet;

    while(Sock_send <= 0)
    {
        addr_dst.sin_family      = AF_INET;
        addr_dst.sin_port        = htons(UDP_DST_PORT);
        addr_dst.sin_addr.s_addr = (unsigned long)inet_addr(UDP_GRD_ADDR);

        if ((Sock_send = net_create_sock()) < 0){
            WK_LOGE("Create socket fail\n");
            sleep(1);
            continue ;
        }

        if (net_bind_sock(Sock_send,UDP_SRC_PORT)  < 0){
            WK_LOGE("Bind addr error %d %s\n",errno,strerror(errno));
            net_close_socket(&Sock_send);
            sleep(1);
            continue;
        }
        WK_LOGD("Bind wkcam addr success Sock_send[%d]! \n",Sock_send);
        break;
    }

    nRet = net_udp_send(Sock_send,(unsigned char*)buf,size,(struct sockaddr *)&addr_dst);
    if(nRet<0){
        WK_LOGE("cam udp[%d] send%d,%s\n",Sock_send,errno,strerror(errno));
        usleep(50*1000);
        net_close_socket(&Sock_send);
    }

	return;
}

void comm_send_data(uint8_t *data,uint16_t length)
{
    UdpSendHandle((char*)data,length);
	return;
}

bool thread_comm_init(void)
{
    pthread_t MavlinkCmdThreadId;
    pthread_t SocketRecvThreadId;
    pthread_t ArcuoDetectThreadId;
    pthread_t YoloRecvThreadId;
    pthread_t YoloDrawRectThreadId;

    mavlink_init();
    rt_ringbuffer_init(&rb_queue, rb_buffer, MAX_RB_SIZE);

    if(pthread_create(&MavlinkCmdThreadId,NULL,MavlinkCmdAnalysisThread,NULL) != 0 ){
        return false;
    }

    if(pthread_create(&SocketRecvThreadId,NULL,SocketRecvThread,NULL) != 0 ){
        return false;
    }

    return true;
}

