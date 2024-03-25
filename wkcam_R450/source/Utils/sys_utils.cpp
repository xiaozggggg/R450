
#include <sys_utils.h>


uint32_t system_time_ms_get(void)
{
    uint32_t time_ms;
    struct timeval stTime;

    gettimeofday(&stTime, NULL);

    time_ms = stTime.tv_sec * 1000 + stTime.tv_usec / 1000;

    return time_ms;
}


uint32_t system_timestamp_get(void)
{
    struct timeval stTime;

    gettimeofday(&stTime, NULL);
    
    return stTime.tv_sec;
}

uint32_t get_delta_time(uint32_t now,uint32_t last_time)
{
    if (now >= last_time)
    {
       return now - last_time;
    }else
    {
        return (UINT32_MAX - last_time + now);
    }
}


int get_next_file_index(char *path, char *name_prefix)
{
	DIR *dir = NULL;
	struct dirent *ptr = NULL;

	dir = opendir(path);
	if(!dir){
		return -1;
	}

	int max_index = 0, tmp_index;
	char prefix[32] = {0}, index[12] = {0};
	char *p = NULL;

	while((ptr = readdir(dir)) != NULL){

		if(!strcmp(ptr->d_name, ".") || !strcmp(ptr->d_name, "..")){
			continue;
		}else if(ptr->d_type == 8){
			p = strstr(ptr->d_name, name_prefix);
            //printf("p:%s\n" ,p);
			if(p && (strstr(p, ".jpg") || strstr(p, ".mp4"))){
				bzero(prefix, sizeof(prefix));
				bzero(index, sizeof(index));
				sscanf(p, "%[a-zA-Z]_%[0-9]", prefix, index);
				tmp_index = atoi(index);
                //printf("tmp_index:%d\n"  ,tmp_index);
				if(tmp_index > max_index){
					max_index = tmp_index;
				}
			}
		}else{
			//do nothing
		}
	}

	if(dir){
		closedir(dir);
		dir = NULL;
	}
	
	return max_index;
}

bool is_dir_exist(const char * path)
{
    DIR *dir = NULL;

	if (path == NULL) 
		return false;

    dir = opendir(path);	
	if (dir == NULL){
        return false;
    }
    else{
        closedir(dir);
    }

	return true;
}

bool get_sdcard_available_capacity(long long * capacity)
{
	int ret;
	long long freeBytes;

	struct statfs disk_info;

	// check sdcard status
	ret = statfs("/system/sdcard",&disk_info);
	if (ret == 0)
	{
		freeBytes = disk_info.f_bavail * disk_info.f_bsize;
		*capacity = freeBytes;
		
		return true;
	}
	else
	{
		return false;
	}
}

/*
 *	功能：获取本机IP地址
 *	参数：
 * 		EhxName			---> 输入参数，网卡名，如 eth0 ,ens33
 * 		IpAddressBuf	---> 输出参数，保存获取的 IP 地址缓冲区
 * 	返回值：
 * 		成功			---> true
 * 		失败			---> false
 */		

bool getLocalIpAddress(const char *EhxName ,char *IpAddressBuf)
{
	if( (NULL==IpAddressBuf) || (NULL==EhxName) ){
		return false;
	}

	int sock_fd = socket(PF_INET, SOCK_DGRAM, 0);
	if(sock_fd < 0){
		printf("[%s][%d] socket failed!\n" ,__FUNCTION__ ,__LINE__);
		return false;
	}
	
	struct ifconf conf;
	char buff[BUFSIZ] = {0};
	conf.ifc_len = BUFSIZ;
	conf.ifc_buf = buff;
	ioctl(sock_fd, SIOCGIFCONF, &conf);
	int num = conf.ifc_len / sizeof(struct ifreq);
	struct ifreq *ifr = conf.ifc_req;
	if(NULL == ifr){
		close(sock_fd);
		return false;
	}
	
	int i;
	for(i=0;i < num;i++)
	{
		struct sockaddr_in *sin = (struct sockaddr_in *)(&ifr->ifr_addr);
		if(0 == ioctl(sock_fd, SIOCGIFFLAGS, ifr) ){
			if(((ifr->ifr_flags & IFF_LOOPBACK) == 0) && (ifr->ifr_flags & IFF_UP)){
				printf("[i:%d]%s (%s)\n" ,i ,ifr->ifr_name ,inet_ntoa(sin->sin_addr));

				if( 0 == strncmp((char *)ifr->ifr_name ,(char *)EhxName ,(size_t)strlen((char *)EhxName)) ){
					memcpy(IpAddressBuf ,inet_ntoa(sin->sin_addr) ,(size_t)strlen(inet_ntoa(sin->sin_addr)));
					printf("[i:%d](%s)\n" ,i ,IpAddressBuf);
					break;
				}
			}
			ifr++;
		}
	}

	close(sock_fd);

	if(i >= num){
		return false;
	}

	return true;	
}

