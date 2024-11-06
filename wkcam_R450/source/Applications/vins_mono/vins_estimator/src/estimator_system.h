#include "estimator.h"
#include "parameters.h"
#include "utility/visualization.h"
#include "loop-closure/loop_closure.h"
#include "loop-closure/keyframe.h"
#include "loop-closure/keyframe_database.h"
#include "camodocal/camera_models/CameraFactory.h"
#include "camodocal/camera_models/CataCamera.h"
#include "camodocal/camera_models/PinholeCamera.h"
/****************** load image section ***********************/
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <condition_variable>
/****************** load image section ***********************/

/****************** feature tracker section ***********************/
#include "../../include/PointCloud.h"
#include "../../include/Imu.h"
#include "feature_tracker/feature_tracker.h"
#ifndef RUN_ON_PC
#include "wk_corner_info.h"
#endif

class EstimatorSystem
{
private:
    using imu_img_type = std::vector<std::pair<std::vector<sensor_msgs::ImuConstPtr>, sensor_msgs::PointCloudConstPtr>>;
public:

    EstimatorSystem();
    
    void run(void);

    void init(const std::string& yamlPath);

    void generateCameraFromYamlFile(void);

    void updateLoopPath(nav_msgs::Path _loop_path);

    void predict(const sensor_msgs::ImuConstPtr &imu_msg);

    void update();

    imu_img_type getMeasurements();

    void imu_callback(const sensor_msgs::ImuConstPtr &imu_msg);

    void feature_callback(const sensor_msgs::PointCloudConstPtr &feature_msg);

    void send_imu(const sensor_msgs::ImuConstPtr &imu_msg);

    //thread:loop detection
    void process_loop_detection();

    //thread: pose_graph optimization
    void process_pose_graph();

    // thread: visual-inertial odometry
    void process();
#ifndef RUN_ON_PC
    void img_callback(const cv::Mat &show_img, const ros::Time &timestamp, wk_corner_video_frame_s::wk_ptr img_data);
#else
    void img_callback(const cv::Mat &show_img, const ros::Time &timestamp);
#endif

    /******************* load image begin ***********************/
    void LoadImages(const string &strImagePath, const string &strTimesStampsPath, vector<string> &strImagesFileNames, vector<double> &timeStamps);
    /******************* load image end ***********************/

    /******************* load IMU begin ***********************/

    void LoadImus(ifstream & fImus, const ros::Time &imageTimestamp);
    /******************* load IMU end ***********************/

    void q_callback(Eigen::Quaterniond q, unsigned long long ts);

    bool reset_q();

    #ifndef RUN_ON_PC
    void SendResult(Eigen::Vector3d loop_correct_t, Eigen::Matrix3d loop_correct_r, wk_corner_video_frame_s::wk_ptr img_data, int track_num);
    #else
    void SendResult(Eigen::Vector3d loop_correct_t, Eigen::Matrix3d loop_correct_r, int track_num);
    #endif

private:
    std::mutex m_lck_q;
    std::vector<std::pair<unsigned long long, Eigen::Quaterniond>> m_qs;
    Matrix3d delta_R;
};
