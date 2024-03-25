#ifndef _DRV_UART_H_
#define	_DRV_UART_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


/*
enum SeriaComStat {
	WAIT_DATA_READY = 1,   
	WAIT_DATA_EXCEPT = -1,	
	WAIT_DATA_ERROR = -2,
	WAIT_DATA_TIMEOUT = -3,
			
};
*/

#define UART1_PATH "/dev/ttyAMA1"      //调试串口，一般用不上
#define UART3_PATH "/dev/ttyS3"        //通信串口

int UartOpen(const char *path);
int UartWrite(int fd, unsigned char *pdatabuf, int ndatalen);
int UartRead(int fd, unsigned char *pDdatabuf, int nDatalen, int wait_time);
int UartConfig(int fd,  int baudrate, int bitnum, int stopbits, int parity);
int UartClose(int fd);


#endif


