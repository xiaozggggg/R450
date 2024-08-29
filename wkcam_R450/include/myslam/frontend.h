#pragma once
#ifndef MYSLAM_FRONTEND_H
#define MYSLAM_FRONTEND_H

#include <opencv2/features2d.hpp>

#include "myslam/common_include.h"
#include "myslam/frame.h"
#include "myslam/map.h"
#include "myslam/Initializer.h"

namespace myslam {

class Backend;
class Viewer;

enum class FrontendStatus { NO_IMAGES_YET, INITING, TRACKING_GOOD, TRACKING_BAD, LOST };

/**
 * 前端
 * 估计当前帧Pose，在满足关键帧条件时向地图加入关键帧并触发优化
 */
class Frontend {
   public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<Frontend> Ptr;

    Frontend();

    /// 外部接口，添加一个帧并计算其定位结果
    bool AddFrame(Frame::Ptr frame);

    /// Set函数
    void SetMap(Map::Ptr map) { map_ = map; }

    void SetBackend(std::shared_ptr<Backend> backend) { backend_ = backend; }

    FrontendStatus GetStatus() const { return status_; }

    void SetCameras(Camera::Ptr left, Camera::Ptr right) {
        camera_left_ = left;
        camera_right_ = right;
    }

    int GetTrackingInliersNum()
    {
        return tracking_inliers_;
    }

   private:
    /**
     * Track in normal mode
     * @return true if success
     */
    bool Track();

    /**
     * Reset when lost
     * @return true if success
     */
    bool Reset();

    /**
     * Track with last frame
     * @return num of tracked points
     */
    int TrackLastFrame();

    /**
     * estimate current frame's pose
     * @return num of inliers
     */
    int EstimateCurrentPose();

    /**
     * set current frame as a keyframe and insert it into backend
     * @return true if success
     */
    bool InsertKeyframe();

    /**
     * Try init the frontend with stereo images saved in current_frame_
     * @return true if success
     */
    void MonocularInitialization();

    /**
     * Detect features in left image in current_frame_
     * keypoints will be saved in current_frame_
     * @return
     */
    int DetectFeatures(Frame::Ptr frame);

    /**
     * Find the corresponding features in right image of current_frame_
     * @return num of features found
     */
    int FindFeaturesInInitialFrame();

    int FindFeaturesInLast();

    /**
     * Build the initial map with single image
     * @return true if succeed
     */
    bool CreateInitialMapMonocular();

    /**
     * Triangulate the 2D points in current frame
     * @return num of triangulated points
     */
    int TriangulateNewPoints(const std::vector<cv::Point2f> &keypoint_1,
                             const std::vector<cv::Point2f> &keypoint_2,
                             const Mat &R, const Mat &t, std::vector<cv::Point3f> &points);

    /**
     * Set the features in keyframe as new observation of the map points
     */
    void SetObservationsForKeyFrame();

    // data
    std::unique_ptr<Initializer> mpInitializer;
    FrontendStatus status_ = FrontendStatus::NO_IMAGES_YET;

    // Initialization Variables (Monocular)
    std::vector<int> mvIniLastMatches;
    std::vector<int> mvIniMatches;
    std::vector<cv::Point3f> mvIniP3D;
    Frame::Ptr mInitialFrame;

    Frame::Ptr current_frame_ = nullptr;  // 当前帧
    Frame::Ptr last_frame_ = nullptr;     // 上一帧
    Camera::Ptr camera_left_ = nullptr;   // 左侧相机
    Camera::Ptr camera_right_ = nullptr;  // 右侧相机

    Map::Ptr map_ = nullptr;
    std::shared_ptr<Backend> backend_ = nullptr;

    cv::Mat relative_motion_ = cv::Mat::eye(4,4,CV_32F);  // 当前帧与上一帧的相对运动，用于估计当前帧pose初值

    int tracking_inliers_ = 0;  // inliers, used for testing new keyframes

    // params
    int num_features_ = 200;
    int num_features_init_ = 100;
    int num_features_tracking_ = 50;
    int num_features_tracking_bad_ = 20;
    int num_features_needed_for_keyframe_ = 80;

    // utilities
    cv::Ptr<cv::GFTTDetector> gftt_;  // feature detector in opencv
};

}  // namespace myslam

#endif  // MYSLAM_FRONTEND_H
