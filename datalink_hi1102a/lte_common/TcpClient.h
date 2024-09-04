#ifndef _TCPCLIENT_H_
#define _TCPCLIENT_H_

#include <iostream>
#include <pthread.h>

using namespace std;

extern "C"{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <sys/types.h>
    #include <sys/un.h>
    #include <arpa/inet.h>
    #include <errno.h>
    #include <unistd.h>
    #include <signal.h>
    #include <sys/prctl.h>
    #include <unistd.h>
    #include <fcntl.h>
}

#define DEFAULT_SERVERIP        "192.168.1.100"
#define DEFAULT_SERVERPORT      (8125)
#define MAX_BUFSIZE             (1024)


typedef enum{
    PING_FAILED = -1,
    PING_SUCCESS = 0,
}PING_STATUS_E;

typedef enum{
    TCP_CONNECT = 0,
    TCP_DISCONNECT,
}TCP_CONNECTSTATUS_E;

typedef enum{
    SELECT_NONE = -1,
    SELECT_ERROR = 0,
    SELECT_TIMEOUT ,
    SELECT_WAITREAD ,
    SELECT_OTHER ,
} TCP_SELECTSTATUS_E;

typedef struct{
    char _ip[16];
    int  _port;
} __attribute__((packed)) NetAddress_t ,*ptrNetAddress_t;


class TcpClient
{
public:
    TcpClient();
    ~TcpClient();

    bool CreateSocket();
    bool Close();
    bool Connect(const char *ptrServerIp , int ServerPort);
    int  ReadData(const char *rDataBuf ,int rDatalen);
    int  WriteData(char *wDataBuf ,int wDatalen);
    int  ReadSelect();
    ////////////////////////////////
    int getSockFd();
    int getConnectStatus();
    void setConnectStatus(int ConnectStatus);
    void setServerAddr(const char *ServerIp ,int ServerPort);
 
    NetAddress_t mServerAddr;
    char mDataBuf[MAX_BUFSIZE];
    int  mDataLen;

private:
    int mSockFd;
    int mConnectStatus;
    pthread_mutex_t mConnectStatusMutex;
};






#endif