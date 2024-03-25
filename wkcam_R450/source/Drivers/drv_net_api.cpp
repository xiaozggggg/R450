

#include "drv_net_api.h"

#define INVALID_SOCKET  (int)(~0)
#define MAX_BLOCK_SEND_TIME 3
#define MAX_BLOCK_RECV_TIME 3

int net_set_sock_attr(int fd, int bReuseAddr, int nSndTimeO, int nRcvTimeO, int nSndBuf, int nRcvBuf)
{
    int err_ret = 0;
    int val = 1;	    
    struct timeval sndTo, rcvTo;

	if (fd <= 0)
		return -1;

    if(setsockopt(fd, SOL_SOCKET, SO_BROADCAST, &val, sizeof(val)) < 0){
        err_ret = -1;
    }
	
    sndTo.tv_sec  = nSndTimeO / 1000;
    sndTo.tv_usec = (nSndTimeO % 1000) * 1000;
	
    rcvTo.tv_sec  = nRcvTimeO / 1000;
    rcvTo.tv_usec = (nRcvTimeO % 1000) * 1000;
	
    if (bReuseAddr != 0 && setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,(void *)&bReuseAddr,sizeof(int)) < 0)
        err_ret = -1;
	
    if (nSndTimeO != 0 && setsockopt(fd,SOL_SOCKET,SO_SNDTIMEO,(void  *)&sndTo,sizeof(sndTo)) < 0)
		err_ret = -1;
    if (nSndTimeO != 0 && setsockopt(fd,SOL_SOCKET,SO_RCVTIMEO,(void  *)&rcvTo,sizeof(rcvTo)) < 0)
		err_ret = -1;
	
    if (nSndBuf != 0 && setsockopt(fd,SOL_SOCKET,SO_SNDBUF,(void  *)&nSndBuf,sizeof(nSndBuf)) < 0)
		err_ret = -1;
    if (nRcvBuf != 0 && setsockopt(fd,SOL_SOCKET,SO_RCVBUF,(void  *)&nRcvBuf,sizeof(nSndBuf)) < 0)
        err_ret = -1;
    return err_ret;
}

//***********************�׽������************************************//
int net_close_socket(int *pSock)
{
	if (pSock != NULL && *pSock > 0)
	{

		close(*pSock);
		*pSock = -1;
		return 0;
	}
	return -1;	
}

int net_create_sock(void)
{
    int fd = socket(AF_INET,SOCK_DGRAM, IPPROTO_UDP);
    if (fd == INVALID_SOCKET){
        return -1;
    }
	return fd;
}

int net_bind_sock(int sockfd, int nPort)
{
	struct sockaddr_in addr_local;
	memset(&addr_local, 0, sizeof(struct sockaddr_in));

	addr_local.sin_family      = AF_INET;
	addr_local.sin_port        = htons(nPort);
    addr_local.sin_addr.s_addr = INADDR_ANY;	
	
	net_set_sock_attr(sockfd, 1, 0, 0, 0, 0);  //set the sock reuser_addr attribute
	if (bind(sockfd,(struct sockaddr*)&addr_local, sizeof(struct sockaddr_in)) < 0){
        close(sockfd);
        return -1;
    }

	return 0;
}
	
int net_select(int *fd_array, int fd_num, int fd_type, int time_out)
{
	int maxfd = 0;
	int index = 0;
	int ret   = 0;
	
	fd_set read_fd, *p_read_fd;
	fd_set write_fd, *p_write_fd;
	fd_set except_fd, *p_except_fd;
	struct timeval timeO, *p_time_out;

	if (fd_array == NULL || fd_num < 0)
		return -1;
	p_time_out = NULL;
	if (time_out > 0)
	{
    		timeO.tv_sec = time_out / 1000;
    		timeO.tv_usec= (time_out % 1000)*1000;	
		p_time_out = &timeO;
	}

	p_read_fd = p_write_fd = p_except_fd = NULL;
	
	if (fd_type & 0x1)
	{
		p_read_fd = &read_fd;
		FD_ZERO(p_read_fd);
	}
	
	if (fd_type & 0x2)
	{
		p_write_fd = &write_fd;
		FD_ZERO(p_write_fd);
	}
	
	if (fd_type & 0x4)
	{
		p_except_fd = &except_fd;
		FD_ZERO(p_except_fd);
	}
	
	for (index = 0; index < fd_num; ++index)
	{
		if(fd_array[index] <= 0)
			continue;
		maxfd = maxfd > fd_array[index] ? maxfd : fd_array[index];

		if (p_read_fd)
			FD_SET(fd_array[index], p_read_fd);
		if (p_write_fd)
			FD_SET(fd_array[index], p_write_fd);
		if (p_except_fd)
			FD_SET(fd_array[index], p_except_fd);
	}
	if (maxfd <= 0)
		return -1;
	
	maxfd += 1;

	while (1)
	{
		ret = select(maxfd, p_read_fd, p_write_fd, p_except_fd, p_time_out);
		if (ret < 0 && errno == EINTR)
		{
		    continue;
		}    
		else if (ret < 0)
			return -1;
		else if (ret == 0)
			return 0;
		else
		{
			for (index = 0; index < fd_num; ++index)
			{
				if (fd_array[index] <= 0)  //socket error
					continue;
				
				if (p_read_fd)
				{
					if (FD_ISSET(fd_array[index], p_read_fd))
						return fd_array[index] | 0x10000;
				}
				else if (p_write_fd)
				{
					if (FD_ISSET(fd_array[index], p_write_fd))
						return fd_array[index] | 0x20000;
				}
				else if (p_except_fd)
				{
					if (FD_ISSET(fd_array[index], p_except_fd))
						return fd_array[index] | 0x40000;
				}			
			}
			return 0;
		}
	}	
	return -1;	
}


int net_udp_recv(int sockfd, unsigned char *rcvBuf, int bufSize, int rcvSize, struct sockaddr *from, int *fromlen)
{
    int		ret;
    unsigned long	dwRecved = 0;
    unsigned long	nTryTime = 0;
    int             nSize    = rcvSize;

    if (rcvSize <= 0 || rcvBuf == NULL || bufSize <= 0)
        nSize = bufSize;	           

    while(dwRecved < nSize)
    {
		ret = recvfrom(sockfd, rcvBuf + dwRecved, nSize - dwRecved, 
						MSG_DONTWAIT, from, (socklen_t *)fromlen);
		if(0 == ret)
			return -1;
		else if(ret < 1)
		{
			if(ECONNRESET == errno)
				return -1;
			else if(EWOULDBLOCK == errno  || errno == EINTR || errno == EAGAIN)
			{
				if(nTryTime++ < MAX_BLOCK_RECV_TIME)
				{				
					usleep(10000);
					continue;
				}
				else
					break;
			}
			
			return -1;
		}
		nTryTime = 0;
		dwRecved += ret;

		if (rcvSize <= 0)
            break;
    }
    return dwRecved;
}
	 
int net_udp_send(int hSock,unsigned char *pbuf,int size, struct sockaddr * distAddr)
{
    int  block  = 0;	
    int  alllen = size;
    int  sended = 0;

	if (hSock <= 0 || pbuf == NULL || size <= 0 || distAddr == NULL)
	{
//		HI_SYSLOG(HI_LOG_ERR,"HI_Udp_Send %d %d\n", hSock, size);
		return 0;
	}
	
    while(alllen > 0)
    {	
		sended = sendto(hSock,pbuf,alllen,0, distAddr, sizeof(struct sockaddr));
		if(0 == sended)
		{
         	   return -1;
		}
		else if(sended < 1)
		{
			if(block > MAX_BLOCK_SEND_TIME)
			{
				return -1;
			}
			if(errno == EWOULDBLOCK || errno == EINTR || errno == EAGAIN)
			{			
				if(block++ < MAX_BLOCK_SEND_TIME)
				{
					usleep(1000);
                    continue;
				}
				else
				{
					break;
				}
			}
			return -1;
		}
		else
		{		
			pbuf += sended;
			alllen -= sended;
		}
    }
    
    if(alllen > 0)
		return -1;
    return size;
}



