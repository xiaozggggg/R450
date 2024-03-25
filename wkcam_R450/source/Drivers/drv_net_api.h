//////////////////////////////////////////////////
//drv_net_api.h
//////////////////////////////////////////////////

#ifndef __DRV_NET_API_H__
#define __DRV_NET_API_H__

#include <sys/un.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <netinet/ip_icmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <net/if.h>

int net_close_socket(int *pSock);
int net_create_sock(void);
int net_bind_sock(int sockfd, int nPort);
int net_select(int *fd_array, int fd_num, int fd_type, int time_out);
int net_udp_recv(int sockfd, unsigned char *rcvBuf, int bufSize, int rcvSize, struct sockaddr *from, int *fromlen);
int net_udp_send(int hSock,unsigned char *pbuf,int size, struct sockaddr * distAddr);

#endif




