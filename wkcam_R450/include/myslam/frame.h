#pragma once

#ifndef MYSLAM_FRAME_H
#define MYSLAM_FRAME_H

#include "myslam/camera.h"
#include "myslam/common_include.h"
#include "wk_corner_info.h"

namespace myslam
{

// forward declare
struct MapPoint;
struct Feature;

/**
 * 帧
 * 每一帧分配独立id，关键帧分配关键帧ID
 */
struct Frame
{
   public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<Frame> Ptr;

    unsigned long id_ = 0;           // id of this frame
    unsigned long keyframe_id_ = 0;  // id of key frame
    bool is_keyframe_ = false;       // 是否为关键帧
    double time_stamp_;              // 时间戳，暂不使用
    cv::Mat pose_;                       // Tcw 形式Pose
    std::mutex pose_mutex_;          // Pose数据锁
    cv::Mat left_img_, right_img_;   // stereo images

    wk_corner_video_frame_s::wk_ptr img_data;


    // extracted features in left image
    std::vector<std::shared_ptr<Feature>> features_left_;
    // corresponding features in right image, set to nullptr if no corresponding
    std::vector<std::shared_ptr<Feature>> features_right_;

   public:  // data members
    Frame() {}

    Frame(long id, double time_stamp, const cv::Mat &pose, const Mat &left,
          const Mat &right);

    // set and get pose, thread safe
    cv::Mat Pose()
    {
        std::unique_lock<std::mutex> lck(pose_mutex_);
        return pose_;
    }

    void SetPose(const cv::Mat &pose)
    {
        std::unique_lock<std::mutex> lck(pose_mutex_);
        pose_ = pose;
    }

    /// 设置关键帧并分配并键帧id
    void SetKeyFrame();

    /// 工厂构建模式，分配id 
    static std::shared_ptr<Frame> CreateFrame();
};

}  // namespace myslam

#endif  // MYSLAM_FRAME_H
