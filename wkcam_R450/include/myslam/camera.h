#pragma once

#ifndef MYSLAM_CAMERA_H
#define MYSLAM_CAMERA_H

#include "myslam/common_include.h"

namespace myslam {

// Pinhole stereo camera model
class Camera {
   public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<Camera> Ptr;

    //Camera intrinsics
    float fx_ = 0;
    float fy_ = 0;
    float cx_ = 0;
    float cy_ = 0;

    Camera();

    Camera(float fx, float fy, float cx, float cy) : fx_(fx), fy_(fy), cx_(cx), cy_(cy)
    {
    }

    // return intrinsic matrix
    cv::Mat K() const
    {
        cv::Mat k = (cv::Mat_<float>(3, 3) << fx_, 0, cx_, 0, fy_, cy_, 0, 0, 1);

        return k;
    }

    // coordinate transform: world, camera, pixel
    cv::Mat world2camera(const cv::Mat &p_w, const cv::Mat &R_c_w, const cv::Mat &t_c_w);

    cv::Mat camera2world(const cv::Mat &p_c, const cv::Mat &R_c_w, const cv::Mat &t_c_w);

    cv::Mat camera2pixel(const cv::Mat &p_c);

    cv::Mat pixel2camera(const cv::Mat &p_p, float depth = 1);

    cv::Point2f pixel2cam(const cv::Point2d &p)
    {
      return cv::Point2f( (p.x - K().at<float>(0, 2)) / K().at<float>(0, 0),
                          (p.y - K().at<float>(1, 2)) / K().at<float>(1, 1));
    }

    cv::Mat pixel2world(const cv::Mat &p_p, const cv::Mat &R_c_w, const cv::Mat &t_c_w, float depth = 1);

    cv::Mat world2pixel(const cv::Mat &p_w, const cv::Mat &R_c_w, const cv::Mat &t_c_w);
};

}  // namespace myslam
#endif  // MYSLAM_CAMERA_H
