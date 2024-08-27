
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// user app header
#include <thread_comm.h>
#include <thread_video_preview.h>
#include <isp_setting.h>
#include "git_info/git_info.h"
#include "wk_log.h"
#include<myslam/visual_odometry.h>

#define TAG "wkcam_app"

#include "ss_mpi_ae.h"
void wk_mpp_get_Exptime_gain()
{
    ot_isp_exp_info stExpInfo;
    ss_mpi_isp_query_exposure_info(0, &stExpInfo);
	WK_LOGD("a_gain = %d, exposure = %d, exp_time = %d, fps = %d\n", 
			stExpInfo.a_gain, stExpInfo.exposure, stExpInfo.exp_time, stExpInfo.fps);
	
	return;
}


int main(int argc, char *argv[])
{
	int ret = 0;

    printf("=========== OV7251 ===========\n");
	wk_git_info_print();
	wk_log_init();

#if 1
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

	myslam::VisualOdometry::Ptr vo( new myslam::VisualOdometry() );

	if(!vo->Init(argv[1]))
    {
        std::cout << "vo->Ini() fail!" << std::endl;
        return -1;
    }

	wk_st_lk_middle::wk_st_lk_get_instance()->wk_register_get_frame_cb(
		std::bind(&myslam::VisualOdometry::Step, vo, std::placeholders::_1)
	);

	while (1) {
		//wk_mpp_get_Exptime_gain();
		//usleep(10);
        usleep(2000*1000);
		system("sync");         //  定时对写磁盘刷新
	}

	return 0;
}
