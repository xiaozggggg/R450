#ifndef _UART_H_
#define	_UART_H_

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

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

/*
enum SeriaComStat {
	WAIT_DATA_READY = 1,   
	WAIT_DATA_EXCEPT = -1,	
	WAIT_DATA_ERROR = -2,
	WAIT_DATA_TIMEOUT = -3,
			
};
*/

// Hi3516A 使用串口1 需要设置对应寄存器复用
#define AFREG_BASEADDR      (unsigned int)(0x200F0000)
#define UART1RXDREG_ADDR    (unsigned int)(AFREG_BASEADDR+0x7C)
#define UART1TXDREG_ADDR    (unsigned int)(AFREG_BASEADDR+0x84)

#define UART1_RXD_MUXCTRL_REG_ADDR	0x120400A8
#define UART1_TXD_MUXCTRL_REG_ADDR	0x120400B0

int UartOpen(const char *path);
int UartWrite(int fd, unsigned char *pdatabuf, int ndatalen);
int UartRead(int fd, unsigned char *pDdatabuf, int nDatalen, int wait_time);
int UartConfig(int fd,  int baudrate, int bitnum, int stopbits, int parity);
int UartClose(int fd);

// 新增加
void Hi3516A_SetRegValue(unsigned int setRegAddr ,unsigned int setValue);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif


