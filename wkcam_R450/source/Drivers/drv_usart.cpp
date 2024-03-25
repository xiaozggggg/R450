

#include "drv_usart.h"

/*
 * 功  能：设置串口波特率
 * 参  数：
 *      fd      ---》串口对应的文件描述符
 *      speed   ---》设置的波特率
 * 返回值：
 *      0       ---》成功
 *      -1      ---》失败
 */
static int set_speed(int fd , int speed)
{
    int birdrate_arr[] = {	B115200, B38400, B19200, B9600, B4800,
    						B2400, B1200, B300, B38400, B19200, 
    						B9600,B4800, B2400, B1200, B300
    					};
    int name_arr[] = {		115200, 38400, 19200, 9600, 4800, 
    						2400 ,1200, 300, 38400, 19200,
    						9600, 4800, 2400, 1200, 300
    					};

    struct termios oldtio;
    if(tcgetattr( fd,&oldtio) !=  0) 
    {
      perror("SetupSerial 1");
      return -1;
    }
    int i = -1 ;
    for(i = 0 ; i < (int)(sizeof(name_arr)/sizeof(name_arr[0])) ; i++)
    {
        if(speed == name_arr[i])
            break ;
    }

    tcflush(fd,TCIFLUSH);
    cfsetispeed(&oldtio, birdrate_arr[i]);
    cfsetospeed(&oldtio, birdrate_arr[i]);
    if((tcsetattr(fd,TCSANOW,&oldtio))!=0)
    {
        perror("com set error");
        return -1;
    }
    tcflush(fd,TCIFLUSH);

    return 0 ;

}

/*
 * 功  能：设置串口 数据位 停止位 校验位
 * 参  数：
 *      fd          ---》串口对应的文件描述符
 *      databits    ---》设置的数据位
 *      stopbits    ---》设置的停止位
 *      parity      ---》设置的校验位
 * 返回值：
 *      0       ---》成功
 *      -1      ---》失败
 */
static int set_Parity(int fd, int databits, int stopbits, int parity)
{
    struct termios oldtio;
    if  (tcgetattr( fd,&oldtio)  !=  0)
    {
      perror("SetupSerial 1");
      return -1;
    }

    oldtio.c_cflag |= (CLOCAL | CREAD) ;
    switch(databits) 
    {
        case 7:
            oldtio.c_cflag &= ~CSIZE ;
            oldtio.c_cflag |= CS7 ;
            break ;
        case 8:
            oldtio.c_cflag &= ~CSIZE ;
            oldtio.c_cflag |= CS8 ;
            break ;
        default:
            perror("Unsupported data size.");
            return -1 ;
    }

   switch(parity)
    {
        case 'n':
        case 'N':
            oldtio.c_cflag &= ~PARENB ;
            oldtio.c_iflag &= ~INPCK ;
            break ;
        case 'o':
        case 'O':
            oldtio.c_cflag |= PARENB ;
            oldtio.c_cflag |= PARODD ;
            oldtio.c_iflag |= INPCK ;
            break ;
        case 's':
        case 'S':
            oldtio.c_cflag &= ~PARENB ;
            oldtio.c_cflag &= ~CSTOPB ;
            oldtio.c_iflag |= INPCK ;
            break ;
        case 'e':
        case 'E':
            oldtio.c_cflag |= PARENB;
            oldtio.c_cflag &= ~ PARODD ;
            oldtio.c_iflag |= INPCK ;
            break ;
        default :
            perror("Unsupported parity.");
            return -1 ;
    }


    switch(stopbits)
    {
        case 1:
            oldtio.c_cflag &= ~CSTOPB ;
            break ;
        case 2:
            oldtio.c_cflag |= CSTOPB ;
            break ;
        default :
            perror("Unsupported stopbits.");
            return -1 ;
    }

    oldtio.c_cflag |= (CLOCAL|CREAD) ;
    oldtio.c_iflag &= ~(ICANON|ECHO|ECHOE|ISIG) ;

    oldtio.c_oflag &= ~OPOST ;
    oldtio.c_oflag &= ~(ONLCR|OCRNL) ;

    oldtio.c_iflag &= (ICRNL | INLCR) ;
    oldtio.c_iflag &= ~(IXON|IXOFF|IXANY) ;


    tcflush(fd,TCIFLUSH);
    oldtio.c_cc[VTIME] = 0 ;
    oldtio.c_cc[VTIME] = 0 ;

    /*raw model*/
    oldtio.c_lflag  &= ~(ICANON | ECHO | ECHOE | ISIG);
    oldtio.c_oflag  &= ~OPOST;

    oldtio.c_iflag &= ~(INLCR|IGNCR|ICRNL);
    oldtio.c_iflag &= ~(ONLCR|OCRNL);

    oldtio.c_oflag &= ~(INLCR|IGNCR|ICRNL);
    oldtio.c_oflag &= ~(ONLCR|OCRNL);
    if((tcsetattr(fd,TCSANOW,&oldtio))!=0)
    {
        perror("com set error");
        return -1;
    }
    return 0 ;
}


/*******************************************************************************/

/*
 * 功  能：打开串口
 * 参  数：
 *      pathname     ---》串口的路径名
 * 返回值：
 *      成功          ---》串口文件描述符
 *      失败          ---》-1
 */
int UartOpen(const char *pathname)  //"/dev/ttyAMA1"
{
    // Param Check
    if(!pathname){
        printf("[%s][%d] Input Param Error!\n" ,__FUNCTION__ ,__LINE__);
        return -1;
    }

	int fd = open(pathname, O_RDWR|O_NOCTTY|O_NDELAY);
    if (-1 == fd)
    {
        perror("Can't Open Serial Port");
        return(-1);
    }

    fcntl(fd, F_SETFL, 0);    //串口阻塞

    return fd;
}

/*
 * 功  能：串口写数据
 * 参  数：
 *      fd      ---》串口对应的文件描述符
 *      pdatabuf    ---》写入数据所在缓冲区首地址
 *      ndatalen    ---》写入的数据长度
 * 返回值：
 *      成功          ---》成功写入的字节数
 *      失败          ---》-1
 */
int UartWrite(int fd, unsigned char *pdatabuf, int ndatalen)
{
    // Param Check
    if((fd<0) || (!pdatabuf) || (ndatalen<=0)){
        printf("[%s][%d] Input Param Error!\n" ,__FUNCTION__ ,__LINE__);
        return -1;
    }

	int w_ret = write(fd ,pdatabuf ,ndatalen);
	if ( w_ret < 0)
	{
		printf("write uart data failed!\n");
		return -1;
	}

	return w_ret;
}

/*
 * 功  能：串口读数据
 * 参  数：
 *      fd      ---》串口对应的文件描述符
 *      pdatabuf    ---》保存读取数据的缓冲区首地址
 *      ndatalen    ---》读取的数据长度
 *      wait_time   ---》等待的超时时间 ,例如：(wait_time/1000)s + (wait_time%1000*1000)us
 * 返回值：
 *      成功          ---》成功读取的字节数
 *      失败          ---》-1
 */
int UartRead(int fd, unsigned char *pDdatabuf, int nDatalen, int wait_time)
{
    // Param Check
    if((fd<0) || (!pDdatabuf) || (nDatalen<=0) || (wait_time<0)){
        printf("[%s][%d] Input Param Error!\n" ,__FUNCTION__ ,__LINE__);
        return -1;
    }

	int len, fs_sel;
    fd_set fs_read;
    struct timeval time;

    time.tv_sec = wait_time / 1000;              //set the rcv wait time
    time.tv_usec = wait_time % 1000 * 1000;    //100000us = 0.1s

    FD_ZERO(&fs_read);        //每次循环都要清空集合，否则不能检测描述符变化
    FD_SET(fd, &fs_read);    //添加描述符

    // 超时等待读变化，>0：就绪描述字的正数目， -1：出错， 0 ：超时
    fs_sel = select(fd + 1, &fs_read, NULL, NULL, &time);
    if(fs_sel)
    {
        len = read(fd, pDdatabuf, nDatalen);
        return len;
    }else{
        return -1;
    }
}

/*
 * 功  能：关闭串口
 * 参  数：
 *      fd      ---》串口对应的文件描述符
 * 返回值：
 *      成功          ---》0
 *      失败          ---》-1
 */
int UartClose(int fd)
{
    if ( fd < 0){
		return -1;
    }

	int c_ret = close(fd);
	if (c_ret < 0)
	{
		printf("close failed!\n");
		return -1;
	}

	return 0;
}


/*
 * 功  能：配置串口 （波特率 数据位 停止位 校验位）
 * 参  数：
 *      fd          ---》串口对应的文件描述符
 *      bitnum    ---》设置的数据位
 *      stopbits    ---》设置的停止位
 *      parity      ---》设置的校验位
 * 返回值：
 *      0       ---》成功
 *      -1      ---》失败
 */
int UartConfig(int fd,  int baudrate, int bitnum, int stopbits, int parity)
{
    // Param Check
    if((fd<0) || (baudrate<=0) || (bitnum<=0) || (stopbits<0)){
        printf("[%s][%d] Input Param Error!\n" ,__FUNCTION__ ,__LINE__);
        return -1;
    }

    if( !(((parity>'a')&&(parity<'z')) || ((parity>'A')&&(parity<'Z'))) ){
        printf("[%s][%d] Input Param Error!\n" ,__FUNCTION__ ,__LINE__);
        return -1;
    }

	if(  0 != set_speed(fd ,baudrate) )
	{
		printf("set_speed failed!\n");
		return -1;
	}

	if( 0 != set_Parity(fd ,bitnum ,stopbits ,parity) )
	{
		printf("set_Parity failed!\n");
		return -1;
	}

    printf("BaudRate:%d DataBits:%d StopBits:%d ParityBit:%c\n" ,baudrate, bitnum, stopbits, parity);

	return 0;
}

/*
 * 功  能： 设置寄存器的值
 * 参  数：
 *      setRegAddr      ---》设置的寄存器地址
 *      setValue        ---》设置的寄存器的值
 * 返回值： 无
 */
void Hi3516A_SetRegValue(unsigned int setRegAddr, unsigned int setValue)
{
    char setRegCmd[64] = {0};

    sprintf(setRegCmd ,"himm 0x%x 0x%x" ,setRegAddr ,setValue);
    system(setRegCmd);
    usleep(100);    // delay 100us
}






















