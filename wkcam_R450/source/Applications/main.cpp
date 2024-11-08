
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// user app header
#include <vins_mono/vins_estimator/src/estimator_system.h>
#ifndef RUN_ON_PC
#include <isp_setting.h>
#include <thread_comm.h>
#include <thread_video_preview.h>
#include "git_info/git_info.h"
#include "wk_log.h"
#include "wk_st_lk_middle.h"
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
#endif

int main(int argc, char *argv[])
{

	cv::FileStorage fsSettings(argv[1], cv::FileStorage::READ);

	if (!fsSettings.isOpened())
	{
		std::cerr << "ERROR: Wrong path to settings " << argv[1] << std::endl;
		return -1;
	}

	double factor = static_cast<double>(fsSettings["factor"]);
#ifndef RUN_ON_PC
	int ret = 0;

	printf("=========== OV7251 ===========\n");
	wk_git_info_print();
	wk_log_init();

#if 1
	// initial serial communications thread
	if (thread_comm_init() == false)
	{
		return -1;
	}
#endif

	// initial imp system
	ret = imp_system_init();

	// initial video preview thread
	if (thread_video_preview_init() == false)
	{
		return -1;
	}

	EstimatorSystem es;

	es.init(argv[1]);

	es.run();

	auto ImgCallBack = [&](wk_corner_video_frame_s::wk_ptr img_data)
	{
		static int imageNum = 0;
		static double total_t = 0;

		cv::Mat im;
		double timestamp = img_data->pts;
		timestamp /= 1e6;

		if (imageNum % 60 == 0)
		{
			std::cout << "--------ImgCallBack!--------" << std::endl;
			std::cout << "img_data->pts: " << img_data->pts << "us  timestamp: " << timestamp << "s." << std::endl;
		}

		imageNum++;

		wk_st_lk_middle::wk_st_lk_get_instance()->wk_frame_to_mat(img_data, im);

		// if (imageNum % 2000 == 0 || imageNum == 1)
		// 	cv::imwrite(std::to_string(imageNum) + std::string(".jpg"), im);
		if(factor != 1)
			cv::resize(im, im, cv::Size(), factor, factor, cv::INTER_NEAREST);

		uint32_t sec = timestamp;
		uint32_t nsec = (timestamp - sec) * 1e9;
		nsec = (nsec / 1000) * 1000 + 500;
		ros::Time image_timestamp = ros::Time(sec, nsec);

		std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
		es.img_callback(im, image_timestamp, img_data);
		std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
		total_t += std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();
		std::cout << "########img_callback mean time : " << (total_t * 1000) / imageNum<< std::endl;
	};

	auto IMUCallBack = [&](wk_imu_data_s::wk_ptr imu_data)
	{
		static int tmp2 = 0;

		double timestamp = imu_data->u64pts;
		timestamp /= 1e6;

		if (tmp2 % 200 == 0)
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
		uint32_t sec = timestamp;
		uint32_t nsec = (timestamp - sec) * 1e9;
		nsec = (nsec / 1000) * 1000 + 500;
		imudata->header.stamp = ros::Time(sec, nsec);
		es.imu_callback(imudata);
	};

	auto QCallBack = [&](wk_quaternion_data_s::wk_ptr q_data)
	{
		Eigen::Quaterniond q;
		q.w() = q_data->q[0];
		q.x() = q_data->q[1];
		q.y() = q_data->q[2];
		q.z() = q_data->q[3];
		es.q_callback(q, q_data->u64pts);

		static int tmp3 = 0;
		if (tmp3 % 200 == 0)
		{
			std::cout << "--------QCallBack!--------" << std::endl;
			std::cout << "q_data->u64pts: " << q_data->u64pts << " us" << std::endl;
			Eigen::Vector3d eulerAngle = q.toRotationMatrix().eulerAngles(2, 1, 0);
			eulerAngle *= (180 / M_PI);
			std::cout << " -------------------- eulerAngle " << eulerAngle[0] << " " << eulerAngle[1] << " " << eulerAngle[2] << "correct_q " << q.w() << " " << q.x() << " " << q.y() << " " << q.z() << std::endl;
		}
		tmp3++;
	};

	wk_st_lk_middle::wk_st_lk_get_instance()->wk_register_get_frame_cb(ImgCallBack);

	wk_imu_middle::wk_imu_get_instance()->wk_register_get_imu_cb(IMUCallBack);

	wk_quaternion_middle::wk_quaternion_get_instance()->wk_register_get_quaternion_cb(QCallBack);

	while (1)
	{
		// wk_mpp_get_Exptime_gain();
		// usleep(10);
		usleep(2000 * 1000);
		system("sync"); //  定时对写磁盘刷新
	}

#else

	if (argc != 5)
	{
		std::cout << "para err, argc = " << argc << std::endl;
		return -1;
	}

	ifstream fImus;
	fImus.open(argv[4]);
	if(!fImus.is_open())
	{
		std::cout<<"con not open imu file "<<argv[4]<<std::endl;
		return -1;
	}

	cv::Mat image;
	int ni; // num image

	EstimatorSystem es;

	es.init(argv[1]);

	vector<string> vStrImagesFileNames;
	vector<double> vTimeStamps;
	es.LoadImages(string(argv[2]), string(argv[3]), vStrImagesFileNames, vTimeStamps);

	int imageNum = vStrImagesFileNames.size();

	if (imageNum <= 0)
	{
		cerr << "ERROR: Failed to load images" << endl;
		return 1;
	}

	es.run();

	double total_t = 0;
	for (ni = 0; ni < imageNum; ni++)
	{
		double tframe = vTimeStamps[ni]; // timestamp
		uint32_t sec = tframe;
		uint32_t nsec = (tframe - sec) * 1e9;
		nsec = (nsec / 1000) * 1000 + 500;
		ros::Time image_timestamp = ros::Time(sec, nsec);
		// read imu data
		es.LoadImus(fImus, image_timestamp);

		// read image from file
		image = cv::imread(vStrImagesFileNames[ni], cv::IMREAD_UNCHANGED);

		if (image.empty())
		{
			cerr << endl
				 << "Failed to load image: " << vStrImagesFileNames[ni] << endl;
			return 1;
		}

		if(factor != 1)
			cv::resize(image, image, cv::Size(), factor, factor, cv::INTER_NEAREST);

		std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
		es.img_callback(image, image_timestamp);
		std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
		double timeSpent = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();
		total_t+=timeSpent;

		//得加上这部分，不然后端处理不过来就结束了
		double T = 0;
		if (ni < imageNum - 1)
			T = vTimeStamps[ni + 1] - tframe; // interval time between two consecutive frames,unit:second
		else if (ni > 0)					  // lastest frame
			T = tframe - vTimeStamps[ni - 1];

		if (timeSpent < T)
			usleep((T - timeSpent) * 1e6); // sec->us:1e6
		else
			cerr << endl
				 << "process image speed too slow, larger than interval time between two consecutive frames" << endl;
	}
        std::cout << "########img_callback mean time : " << (total_t * 1000) / imageNum<< std::endl;

#endif

	return 0;
}
