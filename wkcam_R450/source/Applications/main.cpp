
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// user app header
#include <thread_comm.h>
#include <thread_video_preview.h>
#include <isp_setting.h>

#define TAG "wkcam_app"

int main(int argc, char *argv[])
{
	int ret = 0;

	printf("=========== R450 start  version: v1.0.1 20240301 ========== \n");
    printf("=========== OV7251 ===========\n");

#if 0
	//initial serial communications thread
	if (thread_comm_init() == false)
	{
		return -1;
	}	
#endif

	//initial imp system
	ret = imp_system_init();

    // initial video preview thread
	if (thread_video_preview_init() == false)
	{
		return -1;
	}

	while (1) {
        usleep(2000*1000);
		system("sync");         //  定时对写磁盘刷新
	}

	return 0;
}
