
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// user app header
#include <thread_comm.h>
#include <thread_video_preview.h>
#include <isp_setting.h>
#include "git_info/git_info.h"
#include "wk_log.h"
#include <myslam/visual_odometry.h>
//#include <wkSlam/System.h>
#include <vins_mono/vins_estimator/src/estimator_system.h>
#include "wk_imu_middle.h"
#include "wk_quaternion_middle.h"

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

/* 保存imu、frame的测试函数 */
extern int middle_test(char* argv);
int save_imu_frame_test_start(int argc, char *argv[])
{
	if(argc != 2) {
		WK_LOGE("cmd ./wkcam_r450 1/2/3\n");
		return -1;
	}
	
	middle_test(argv[1]);  // 测试中间接口层使用
	while (1) {
		//wk_mpp_get_Exptime_gain();
		//usleep(10);
        usleep(2000*1000);
		system("sync");         //  定时对写磁盘刷新
	}	

	return 0;
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

	#ifdef DEBUG_SAVE_IMU_FRAME
	if(save_imu_frame_test_start(argc, argv)){
		return -1;
	}
	#endif

	if(argc == 5)
	{
		ifstream fImus;
		fImus.open(argv[4]);

		cv::Mat image;
		int ni;//num image
		
		EstimatorSystem es;

		es.init(argv[1]);

		vector<string> vStrImagesFileNames;
		vector<double> vTimeStamps;
		es.LoadImages(string(argv[2]),string(argv[3]),vStrImagesFileNames,vTimeStamps);

		int imageNum = vStrImagesFileNames.size();
		
		if(imageNum<=0)
		{
			cerr << "ERROR: Failed to load images" << endl;
			return 1;
		}
		
		es.run();

		for(ni=0; ni<imageNum; ni++)
		{
			double  tframe = vTimeStamps[ni];   //timestamp
			uint32_t  sec = tframe;
			uint32_t nsec = (tframe-sec)*1e9;
			nsec = (nsec/1000)*1000+500;
			ros::Time image_timestamp = ros::Time(sec, nsec);
			// read imu data
			es.LoadImus(fImus,image_timestamp);

			//read image from file
			image = cv::imread(vStrImagesFileNames[ni],CV_LOAD_IMAGE_UNCHANGED);

			if(image.empty())
			{
				cerr << endl << "Failed to load image: " << vStrImagesFileNames[ni] <<endl;
				return 1;
			}

			cv::resize(image, image, cv::Size(), 1.0, 1.0, cv::INTER_NEAREST);

			std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
			wk_corner_video_frame_s::wk_ptr img_data = std::make_shared<wk_corner_video_frame_s>();
			es.img_callback(image, image_timestamp, img_data);
			std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
			double timeSpent =std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1).count();

			//wait to load the next frame image
			double T=0;
			if(ni < imageNum-1)
				T = vTimeStamps[ni+1]-tframe;   //interval time between two consecutive frames,unit:second
			else if(ni>0)                       //lastest frame
				T = tframe-vTimeStamps[ni-1];

			if(timeSpent < T)
				usleep((T-timeSpent)*1e6);      //sec->us:1e6
			else
				cerr << endl << "process image speed too slow, larger than interval time between two consecutive frames" << endl;
		}
	}
	else
	{
		EstimatorSystem es;

		es.init(argv[1]);

		es.run();

		cv::FileStorage fsSettings(argv[1], cv::FileStorage::READ);

        if(!fsSettings.isOpened())
            std::cerr << "ERROR: Wrong path to settings " << argv[1] << std::endl;

        double factor =  static_cast<double>(fsSettings["factor"]);

		auto ImgCallBack = [&](wk_corner_video_frame_s::wk_ptr img_data)
		{
			static int tmp1 = 0;

			cv::Mat im;
			double timestamp = img_data->pts;
			timestamp /= 1e6;

			if(tmp1%60==0)
			{
				std::cout << "--------ImgCallBack!--------" << std::endl;
				std::cout << "img_data->pts: " << img_data->pts << "us  timestamp: " << timestamp << "s." << std::endl;
			}

			tmp1++;

			wk_st_lk_middle::wk_st_lk_get_instance()->wk_frame_to_mat(img_data, im);

			if(tmp1%2000==0 || tmp1==1)
				cv::imwrite(std::to_string(tmp1) + std::string(".jpg"), im);

			cv::resize(im, im, cv::Size(), factor, factor, cv::INTER_NEAREST);

			uint32_t  sec = timestamp;
			uint32_t nsec = (timestamp-sec)*1e9;
			nsec = (nsec/1000)*1000+500;
			ros::Time image_timestamp = ros::Time(sec, nsec);

			es.img_callback(im, image_timestamp, img_data);
		};

		auto IMUCallBack = [&](wk_imu_data_s::wk_ptr imu_data)
		{
			static int tmp2 = 0;

			double timestamp = imu_data->u64pts;
			timestamp /= 1e6;

			if(tmp2%200==0)
			{
				std::cout << "--------IMUCallBack!--------" << std::endl;
				std::cout << "imu_data->u64pts: " << imu_data->u64pts << "us  timestamp: " << timestamp << "s." << std::endl;
			}

			tmp2++;

			sensor_msgs::ImuPtr imudata(new sensor_msgs::Imu);
			imudata->angular_velocity.x = imu_data->gyro_x;
			imudata->angular_velocity.y = imu_data->gyro_y;
			imudata->angular_velocity.z = imu_data->gyro_z;
			imudata->linear_acceleration.x = imu_data->accel_x;
			imudata->linear_acceleration.y = imu_data->accel_y;
			imudata->linear_acceleration.z = imu_data->accel_z;
			uint32_t  sec = timestamp;
			uint32_t nsec = (timestamp-sec)*1e9;
			nsec = (nsec/1000)*1000+500;
			imudata->header.stamp = ros::Time(sec,nsec);
			es.imu_callback(imudata);
		};

		auto QCallBack = [&](wk_quaternion_data_s::wk_ptr q_data)
		{
			static int tmp3 = 0;

			if(tmp3%200==0)
			{
				std::cout << "--------QCallBack!--------" << std::endl;
				std::cout << "q_data->u64pts: " << q_data->u64pts << " us" << std::endl;
			}

			tmp3++;

			Eigen::Quaterniond q;
			q.x() = q_data->q[0];
			q.y() = q_data->q[1];
			q.z() = q_data->q[2];
			q.w() = q_data->q[3];
			es.q_callback(q, q_data->u64pts);
		};

		wk_st_lk_middle::wk_st_lk_get_instance()->wk_register_get_frame_cb(ImgCallBack);

		wk_imu_middle::wk_imu_get_instance()->wk_register_get_imu_cb(IMUCallBack);

		wk_quaternion_middle::wk_quaternion_get_instance()->wk_register_get_quaternion_cb(QCallBack);
	}

#if 0
	WK_SLAM::System SLAM("./release/vc.txt", "./EuRoC.yaml", WK_SLAM::System::MONOCULAR, true);

	wk_st_lk_middle::wk_st_lk_get_instance()->wk_register_get_frame_cb(
		std::bind(&WK_SLAM::System::TrackMonocular, &SLAM, std::placeholders::_1)
	);
#elif 0
	myslam::VisualOdometry::Ptr vo( new myslam::VisualOdometry() );

	if(!vo->Init(argv[1]))
	{
		std::cout << "vo->Ini() fail!" << std::endl;
		return -1;
	}

	wk_st_lk_middle::wk_st_lk_get_instance()->wk_register_get_frame_cb(
		std::bind(&myslam::VisualOdometry::Step, vo, std::placeholders::_1)
	);
#endif


	while (1) {
		//wk_mpp_get_Exptime_gain();
		//usleep(10);
        usleep(2000*1000);
		system("sync");         //  定时对写磁盘刷新
	}

	return 0;
}
