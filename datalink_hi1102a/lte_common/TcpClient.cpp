#include "TcpClient.h"

TcpClient::TcpClient()
{
    mSockFd = -1;
    mConnectStatus = TCP_DISCONNECT;
    memset(&mServerAddr ,0 ,sizeof(NetAddress_t));
}

TcpClient::~TcpClient()
{
    Close();
}

bool TcpClient::CreateSocket()
{
    int sizeSize = 1*1024*1024;
    int resUseFlag = 1;

    mSockFd = socket(AF_INET ,SOCK_STREAM ,0);
    if(mSockFd < 0){
        return false;
    }

    // /* Set nonblocking */
    // int old_option = fcntl(mSockFd, F_GETFL);
    // int new_option = old_option | O_NONBLOCK;
    // fcntl(mSockFd, F_SETFL, new_option);

    // 设置相关属性
    if(-1 == setsockopt(mSockFd , SOL_SOCKET, SO_REUSEADDR,(char *)&resUseFlag, sizeof(int)) ){
        goto CLOSE_SOCK;
    }

    if(0 != setsockopt(mSockFd,SOL_SOCKET,SO_RCVBUF,(const char*)&sizeSize,sizeof(int)) ){
        goto CLOSE_SOCK;
    }

    pthread_mutex_init(&mConnectStatusMutex ,NULL);

    return true;

CLOSE_SOCK:
    Close();
    return false;
}

bool TcpClient::Close()
{
    if(mSockFd > 0){
        shutdown(mSockFd, SHUT_RDWR);
        close(mSockFd);
        mSockFd = -1;
        mConnectStatus = TCP_DISCONNECT;
        pthread_mutex_destroy(&mConnectStatusMutex);
    }

    return true;
}

bool TcpClient::Connect(const char *ptrServerIp ,int ServerPort)
{
    struct sockaddr_in ServerAddr;
    memset(&ServerAddr ,0 ,sizeof(ServerAddr));
    ServerAddr.sin_family = AF_INET;

    if(ServerPort <= 0){
        mServerAddr._port = DEFAULT_SERVERPORT;
    }else{
        mServerAddr._port = ServerPort;
    }

    ServerAddr.sin_port   = htons(mServerAddr._port);
    //ServerAddr.sin_addr.s_addr = inet_addr(DEFAULT_SERVERIP);
    if(NULL == ptrServerIp){
        memcpy(mServerAddr._ip ,DEFAULT_SERVERIP ,strlen(DEFAULT_SERVERIP));
    }else{
        memcpy(mServerAddr._ip ,ptrServerIp ,strlen(ptrServerIp));
    }

    inet_aton(mServerAddr._ip ,(struct in_addr *)&ServerAddr.sin_addr.s_addr);

    int TimeOutCnt = 5;
	for ( ;TimeOutCnt>0 ;TimeOutCnt--)
	{
		if (0 == connect(mSockFd ,(struct sockaddr*)&ServerAddr ,sizeof(ServerAddr))){
			mConnectStatus = TCP_CONNECT;
            break;
		}

        usleep(500*1000);   // 500ms
	}

    if(TimeOutCnt <= 0){
        mConnectStatus = TCP_DISCONNECT;
        printf("============ tcp connect failed \n");
        return false;
    }

    printf("============ tcp connect success [%d]\n", mConnectStatus);
    return true;
}


int TcpClient::ReadData(const char *rDataBuf ,int rDatalen)
{
    // param check
    if( (rDataBuf==NULL) || (rDatalen<=0) ){
        return -1;
    }

    //pthread_mutex_lock(&mConnectStatusMutex);
    if(TCP_DISCONNECT == mConnectStatus){
        //pthread_mutex_unlock(&mConnectStatusMutex);
        return -1;
    }
    //pthread_mutex_unlock(&mConnectStatusMutex);

    return read(mSockFd ,(char *)rDataBuf ,(size_t)rDatalen);
}

int TcpClient::WriteData(char *wDataBuf ,int wDatalen)
{
    // param check
    if( (wDataBuf==NULL) || (wDatalen<=0) ){
        return -1;
    }

    //pthread_mutex_lock(&mConnectStatusMutex);
    if(TCP_DISCONNECT == mConnectStatus){
        //pthread_mutex_unlock(&mConnectStatusMutex);
        return -1;
    }
    //pthread_mutex_unlock(&mConnectStatusMutex);

    // write data
    return write(mSockFd ,(unsigned char *)wDataBuf ,(size_t)wDatalen);
}

int TcpClient::ReadSelect()
{
    fd_set s_fds;
    int max_fd;
    struct timeval tv;

    FD_ZERO(&s_fds);
    FD_SET(mSockFd ,&s_fds);
    max_fd = mSockFd;

    tv.tv_sec  = 2;
    tv.tv_usec = 0;

    printf("=========== select socket [%d]\n", mSockFd);
    int ret = select(max_fd+1 ,&s_fds ,NULL ,NULL ,&tv);
    if(ret < 0){
        return SELECT_ERROR;
    }else if(ret == 0){
        return SELECT_TIMEOUT;          //time out
    }else{
        if(FD_ISSET(mSockFd ,&s_fds)){  // server message
            return SELECT_WAITREAD;
        }else{
            return SELECT_OTHER;        // other fd
        }
    }
}


////////////////////////////////
int TcpClient::getSockFd()
{
    return mSockFd;
}

int TcpClient::getConnectStatus()
{
    pthread_mutex_lock(&mConnectStatusMutex);
    int status = mConnectStatus;
    pthread_mutex_unlock(&mConnectStatusMutex);

    return status;
}

void TcpClient::setConnectStatus(int ConnectStatus)
{
    pthread_mutex_lock(&mConnectStatusMutex);
    mConnectStatus = ConnectStatus;
    pthread_mutex_unlock(&mConnectStatusMutex);
}

void TcpClient::setServerAddr(const char *ServerIp ,int ServerPort)
{
    if( (ServerIp==NULL) || (ServerPort<=0) ){
        mServerAddr._port = DEFAULT_SERVERPORT;
        memcpy(mServerAddr._ip ,DEFAULT_SERVERIP ,strlen(DEFAULT_SERVERIP));
    }else{
        mServerAddr._port = ServerPort;
        memcpy(mServerAddr._ip ,ServerIp ,strlen(ServerIp));
    }
}


