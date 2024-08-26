//
// Created by gaoxiang on 19-5-4.
//
#include "myslam/visual_odometry.h"
#include <chrono>
#include "myslam/config.h"
#include "myslam/camera.h"
#include <Eigen/Core>
#include <Eigen/Geometry>

namespace myslam
{

VisualOdometry::VisualOdometry(void)
{
}

VisualOdometry::~VisualOdometry(void)
{
    if(nullptr != backend_)
        backend_->Stop();
}

bool VisualOdometry::Init(const std::string& config_file_path)
{
    if (Config::SetParameterFile(config_file_path) == false)
        return false;

    // create components and links
    frontend_ = Frontend::Ptr(new Frontend);
    backend_ = Backend::Ptr(new Backend);
    map_ = Map::Ptr(new Map);

    frontend_->SetBackend(backend_);
    frontend_->SetMap(map_);

    float fx = Config::Get<float>("camera.fx");
    float fy = Config::Get<float>("camera.fy");
    float cx = Config::Get<float>("camera.cx");
    float cy = Config::Get<float>("camera.cy");

    Camera::Ptr new_camera(new Camera(fx, fy, cx, cy));

    frontend_->SetCameras(new_camera, new_camera);

    backend_->SetMap(map_);
    backend_->SetCameras(new_camera, new_camera);

    return true;
}

int VisualOdometry::Step(const cv::Mat& img, unsigned long int timeStamp)
{
    auto new_frame = Frame::CreateFrame();
    new_frame->left_img_ = img;
    new_frame->time_stamp_ = timeStamp;

    auto t1 = std::chrono::steady_clock::now();

    bool success = frontend_->AddFrame(new_frame);

    if(success)
    {
        cv::Mat Tcw = new_frame->Pose();
        cv::Mat R = Tcw.rowRange(0,3).colRange(0,3);
        cv::Mat t = Tcw.rowRange(0,3).col(3);

        Eigen::Matrix3f r = Eigen::Matrix3f::Identity();

        Eigen::Map<Eigen::Matrix<float, 3, 3, Eigen::RowMajor>> eigen_map(R.ptr<float>(), 3, 3);

        r = eigen_map;

        Eigen::Quaternionf q(r);
    }

    auto t2 = std::chrono::steady_clock::now();

    auto time_used = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << "VO cost time: " << time_used.count() << " seconds." << std::endl;

    return success;
}

}  // namespace myslam
