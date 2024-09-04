

#include "netlink_info.h"

nb_globals_stru g_st_global = {0};
pthread_t g_wifi_netlink_thd_id = 0;

static int act_rssi;
static int act_connect_status;
static char mMatchId[8];

static void getSysInfo(const char *command,char *buffer)
{
	char result_buf[40];
	int rc = 0;
	FILE *fp;

	fp = popen(command, "r");
	if(NULL == fp){
		perror("===== popen error ======");
		return;
	}
	while(fgets(result_buf, sizeof(result_buf), fp) != NULL)
	{
		if('\n' == result_buf[strlen(result_buf)-1]){
			result_buf[strlen(result_buf)-1] = '\0';
		}
	}
	memcpy(buffer,result_buf,sizeof(result_buf));

	rc = pclose(fp);
	if(-1 == rc){
		perror("close fp error");
	}
}

static void GenerateDynamicID(char *buf)
{
	int len,i;
    char temp;
    char bit_switch = 0;
    unsigned long long byte_select = 0;
    unsigned long long random_lld;

    random_lld = 0;
    srand((unsigned)time(NULL));
    for(i=0;i<10;i++){
        temp = (rand()%10);
        random_lld = random_lld*10 + temp;
    }
    printf("[netlink] --> get random_temp [%lld]\n",random_lld);

	for(i=0;i<8;i++){
        //取值移位
        byte_select = 0xf0000000 >> (4*i);
        bit_switch = 4*(7-i);
        temp = (random_lld & byte_select) >> bit_switch;

        //hex转ascii
        if(temp >= 0 && temp < 0x0A){
            buf[i] = temp + 0x30;
        }
        else if(temp >= 0x0A && temp <= 0x0F){
            buf[i] = temp - 0x0A + 0x41;
        }
        else{
            continue;
        }
	}
}

int nb_netlink_create(void)
{
    struct sockaddr_nl st_src_addr;
    printf(" inter nb_netlink_create\n");

    /* 创建netlink类型的socket通道 */
    g_st_global.l_nlkfd = socket(PF_NETLINK, SOCK_RAW, NB_NETLINK_ID);
    if (g_st_global.l_nlkfd <= 0) {
        printf("create netlink failed!:%s\n", strerror(errno));
        return -1;
    }

    printf(" socket over\n");

    memset(&st_src_addr, 0, sizeof(st_src_addr));
    st_src_addr.nl_family = AF_NETLINK;
    st_src_addr.nl_pid = (uint)getpid(); /* self pid 多播有关 */
    st_src_addr.nl_groups = 0;                /* not in mcast groups 多播有关 */
    /* 绑定 */
    /*lint -e826*/
    if (bind(g_st_global.l_nlkfd, (struct sockaddr *)&st_src_addr, sizeof(st_src_addr)) < 0)  {
        /*lint +e826*/
        printf("bind() < 0");
        close(g_st_global.l_nlkfd);
        return -1;
    }

    printf(" bind over\n");

    g_st_global.pst_nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_PAYLOAD));
    if (g_st_global.pst_nlh == NULL) {
        printf("nlh malloc failed!;errno:%s\n", strerror(errno));
        close(g_st_global.l_nlkfd);
        return -1;
    }

    return g_st_global.l_nlkfd;
}

int nb_netlink_send(unsigned char *data, uint len)
{
    struct iovec st_iov;
    struct msghdr st_msg;
    struct sockaddr_nl st_dest_addr;
    int l_ret;

    if ((data == NULL) || (len > MAX_PAYLOAD)) {
        return -1;
    }

    if (g_st_global.l_nlkfd <= 0) {
        printf(" netlink not opened\n");
        return -1;
    }

    memset(&st_msg, 0, sizeof(st_msg));

    memset(&st_dest_addr, 0, sizeof(st_dest_addr));
    st_dest_addr.nl_family = AF_NETLINK;
    st_dest_addr.nl_pid = 0;    /* For Linux Kernel */
    st_dest_addr.nl_groups = 0; /* unicast */

    /* Fill the netlink message header */
    g_st_global.pst_nlh->nlmsg_len = NLMSG_SPACE(len);
    g_st_global.pst_nlh->nlmsg_pid = (uint)getpid(); /* self pid */
    g_st_global.pst_nlh->nlmsg_flags = 0;

    /* Fill in the netlink message payload */
    /*lint -save -e835*/ /* 屏蔽系统宏NLMSG_DATA宏引入的告警 */
    memcpy(NLMSG_DATA(g_st_global.pst_nlh), data, len);  // 可保证空间足够
    /*lint -restore*/

    st_iov.iov_base = (void *)g_st_global.pst_nlh;
    st_iov.iov_len = g_st_global.pst_nlh->nlmsg_len;
    st_msg.msg_name = (void *)&st_dest_addr;
    st_msg.msg_namelen = sizeof(st_dest_addr);
    st_msg.msg_iov = &st_iov;
    st_msg.msg_iovlen = 1;

    /* 系统函数，发送数据到nbdrv的netlink */
    l_ret = sendmsg(g_st_global.l_nlkfd, &st_msg, 0);
    if (l_ret < 0) {
        printf(" Netlink Sending message fail....\n");
    } else {
        //printf(" Netlink Sending message %d bytes....\n", l_ret);
    }

    return l_ret;
}

void nb_get_netlink_info(int *rssi)
{
    *rssi = act_rssi;
}

void *nb_netlink_recv_pthread(void *p_buf)
{
    struct nlmsghdr *pst_nlh_recv = NULL;
    struct iovec st_iov_recv;
    struct msghdr st_msg_recv;
    struct sockaddr_nl st_dest_addr;
    uint ul_len;
    nb_report_info *report_info = NULL;
    struct nb_msg_hdr_stru *msg_hdr = NULL;
    unsigned char *recv_buf = NULL;

    printf("%s:: entry\n", __func__);

    /* 开辟线程后，初始化以下设置 */
    memset(&st_dest_addr, 0, sizeof(struct sockaddr_nl));
    st_dest_addr.nl_family = AF_NETLINK;
    st_dest_addr.nl_pid = 0;    /* For Linux Kernel */
    st_dest_addr.nl_groups = 0; /* unicast */

    ul_len = NLMSG_SPACE(MAX_PAYLOAD);

    pst_nlh_recv = (struct nlmsghdr *)malloc(ul_len);
    if (pst_nlh_recv == NULL) {
        printf("nlh malloc failed!\n");
        return NULL;
    }

    memset(pst_nlh_recv, 0, ul_len);
    memset((void *)&st_msg_recv, 0, sizeof(struct msghdr));
    /* Fill the netlink message header */
    pst_nlh_recv->nlmsg_len = MAX_PAYLOAD;
    /* self pid */
    pst_nlh_recv->nlmsg_pid = (uint)getpid();
    pst_nlh_recv->nlmsg_flags = 0;

    /* Fill in the netlink message payload */
    st_iov_recv.iov_base = (void *)pst_nlh_recv;
    st_iov_recv.iov_len = pst_nlh_recv->nlmsg_len;
    st_msg_recv.msg_name = (void *)&st_dest_addr;
    st_msg_recv.msg_namelen = sizeof(st_dest_addr);
    st_msg_recv.msg_iov = &st_iov_recv;
    st_msg_recv.msg_iovlen = 1;

    /* Read message from kernel */
    /* 初始化完毕后，进入以下循环 */
    while (1) {
        memset(pst_nlh_recv, 0, NLMSG_SPACE(MAX_PAYLOAD));
		//printf("wait for nlkfd=%d\n", g_st_global.l_nlkfd);
        // 阻塞式等待接收驱动数据，停在这个地方
        if (recvmsg(g_st_global.l_nlkfd, &st_msg_recv, 0) < 0) {
            printf("recv < 0");
            usleep(100*1000);
            continue;
        }

        // 校验接收长度信息
        ul_len = NLMSG_PAYLOAD(pst_nlh_recv, 0); /*lint -e835*/
        if (ul_len == 0 || ul_len >= RECV_BUF_LEN) {
            printf("netlink recv NULL package...;errno:%s,len is %u\n", strerror(errno), ul_len);
            continue;
        }
		recv_buf = NLMSG_DATA(pst_nlh_recv);
		msg_hdr = (struct nb_msg_hdr_stru *)recv_buf;
		if (msg_hdr->cmd == NB_GET_REPORT_INFO) {
			report_info = (nb_report_info *)(recv_buf + sizeof(struct nb_msg_hdr_stru));
			// printf("report info:connected[%u],rate_level[%u],channel[%u],bw[%s],rssi[%d],succ_rate=[%u]\n",
			// 	report_info->is_connected,
			// 	report_info->rate_level,
			// 	report_info->channel,
			// 	(report_info->bw == 129 ? "5MHz" : "10MHz"),
			// 	(report_info->rssi - 256),
			// 	report_info->succ_rate
			// );

            act_connect_status = report_info->is_connected;
            act_rssi = report_info->rssi - 156;
		} else {
			printf("recv error, cmd=%u, len=%u, skb->len=%u\n", msg_hdr->cmd, msg_hdr->len, ul_len);
		}
	}

    free(pst_nlh_recv);
    printf("nb-wifi-recv-pthread is over \n");
    return NULL;
}

int nb_pthread_create(pthread_t *thd_id)
{
    int l_nb_netlink_recv_pthread_ret;

    printf("%s:: entry\n", __func__);

    if (thd_id == NULL) {
        printf("%s:: error\n", __func__);
        return -1;
    }
    /* 创建线程函数 */
    l_nb_netlink_recv_pthread_ret = pthread_create(thd_id, NULL, nb_netlink_recv_pthread, NULL);
    if (l_nb_netlink_recv_pthread_ret != 0) {
        printf("create nb netlink recv pthread error:%d\n", l_nb_netlink_recv_pthread_ret);
        return -1;
    }
    return 0;
}

void nb_wifi_create_thread(void)
{
    printf("%s:: entry\n", __func__);

    /* 创建和driver通讯的netlink */
    g_st_global.l_nlkfd = nb_netlink_create();
    if (g_st_global.l_nlkfd < 0) {
        printf("netlink create failed\n");
    } else {
        /* 只有netlink创建成功后，才会创建线程 */
        nb_pthread_create(&g_wifi_netlink_thd_id);
    }
}

void nb_pthread_kill(pthread_t thd_id)
{
    int ul_pthread_kill_err;

    printf("%s:: entry\n", __func__);

    /* pthread_kill的返回值：成功（0） 线程不存在（ESRCH） 信号不合法（EINVAL） */
    ul_pthread_kill_err = pthread_kill(thd_id, 0);
    if (ul_pthread_kill_err == ESRCH) {
        printf("thread(ID:0x%x) is inexistent\n", (unsigned int)thd_id);
    } else if (ul_pthread_kill_err == EINVAL) {
        printf(" sigal is error;errno:%s \n", strerror(errno));
    } else {
        printf("thread(ID:0x%x) is normal\n", (unsigned int)thd_id);
    }

    return;
}

void nb_pthread_close(pthread_t thd_id)
{
    printf("%s:: entry\n", __func__);

    /* 阻塞式等待当前线程结束 */
    pthread_join(thd_id, NULL);
    nb_pthread_kill(thd_id);
    return;
}

void nb_pthread_exit(void)
{
    if (g_st_global.l_nlkfd > 0) {
        nb_pthread_close(g_wifi_netlink_thd_id);
    }
}

void nb_send_handle(void)
{
    char buf[128];
    struct nb_msg_hdr_stru st_msg_hdr = {0};

    memset(buf, 0, sizeof(buf));

    st_msg_hdr.cmd = NB_GET_REPORT_INFO;
    st_msg_hdr.len = 0;
    memcpy(buf, &st_msg_hdr, sizeof(st_msg_hdr));
    nb_netlink_send((unsigned char *)buf, sizeof(st_msg_hdr));

	return;
}

void nb_enable_match(void)
{
    char sedcmd[100];

    memset(sedcmd, 0x00, sizeof(sedcmd));
    memset(mMatchId, 0x00, sizeof(mMatchId));

    //获取本地MAC地址
    getSysInfo(GET_DEVICE_ID, mMatchId);
    printf("[netlink] --> GET_DEVICE_ID [%s] \n", mMatchId);

    //备份上次的对频信息
    system("cp /etc/hostapd_5G_WPA.conf /etc/hostapd_5G_WPA_last.conf");
    usleep(100*1000);

    //动态修改ID
    sprintf(sedcmd, "sed -i \"s/hi1102a_factory/hi1102a_%s/g\" /etc/hostapd_5G_WPA.conf", mMatchId);
    printf("[netlink] --> sedcmd[%s]\n", sedcmd);
    system(sedcmd);
    usleep(100*1000);
    system("sync");

    //重启图传服务
    system("killall -9 hostapd");
    usleep(500*1000);
}

void nb_send_match_cmd(int type)
{
    char buf[128];
    struct nb_msg_hdr_stru st_msg_hdr = {0};
    unsigned char enter_mode[4] = {'1','\0','\0','\0'};
    unsigned char exit_mode[4] = {'0','\0','\0','\0'};
    unsigned char tmp_msg[64];

    switch (type)
    {
    case 0:
        //=============== 发送对码关闭命令 ===============//
        memset(buf, 0, sizeof(buf));
        st_msg_hdr.cmd = NB_SEND_NOKEY_MODE;
        st_msg_hdr.len = sizeof(exit_mode);
        memcpy(buf, &st_msg_hdr, sizeof(st_msg_hdr));
        memcpy(buf+sizeof(st_msg_hdr), &exit_mode, sizeof(exit_mode));
        printf("st_msg_hdr :%d\n",buf[sizeof(st_msg_hdr)]);
        printf("st_msg_hdr :%d\n",buf[sizeof(st_msg_hdr)+1]);
        printf("len :%d\n",sizeof(st_msg_hdr)+sizeof(exit_mode));
        nb_netlink_send((unsigned char *)buf, sizeof(st_msg_hdr)+sizeof(exit_mode));
        printf("=========== send match disable cmd\n");
        break;

    case 1:
        //=============== 发送对码开启命令 ===============//
        memset(buf, 0, sizeof(buf));
        st_msg_hdr.cmd = NB_SEND_NOKEY_MODE;
        st_msg_hdr.len = sizeof(enter_mode);
        memcpy(buf, &st_msg_hdr, sizeof(st_msg_hdr));
        memcpy(buf+sizeof(st_msg_hdr), &enter_mode, sizeof(enter_mode));
        printf("st_msg_hdr :%d\n",buf[sizeof(st_msg_hdr)]);
        printf("st_msg_hdr :%d\n",buf[sizeof(st_msg_hdr)+1]);
        printf("len :%d\n",sizeof(st_msg_hdr)+sizeof(enter_mode));
        nb_netlink_send((unsigned char *)buf, sizeof(st_msg_hdr)+sizeof(enter_mode));
        printf("=========== send match start cmd\n");
        break;

    case 2:
        memset(tmp_msg, 0x00, sizeof(tmp_msg));
        sprintf(tmp_msg, "hi1102a_%s:%s", mMatchId, "87654321");
        printf("[netlink] --> send message:[%s] message len[%d]\n", tmp_msg, strlen(tmp_msg));

        //=============== 设置密钥消息 ===============//
        memset(buf, 0, sizeof(buf));
        st_msg_hdr.cmd = NB_SEND_KEY_DATA;
        st_msg_hdr.len = strlen(tmp_msg);
        memcpy(buf, &st_msg_hdr, sizeof(st_msg_hdr));
        memcpy(buf+sizeof(st_msg_hdr), tmp_msg, strlen(tmp_msg));
        nb_netlink_send((unsigned char *)buf, sizeof(st_msg_hdr)+strlen(tmp_msg));
        printf("=========== send match ssid and passwd\n");
        break;
    
    default:
        break;
    }
}
