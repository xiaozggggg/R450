#pragma once
#ifndef MYSLAM_VISUAL_ODOMETRY_H
#define MYSLAM_VISUAL_ODOMETRY_H

#include "myslam/backend.h"
#include "myslam/common_include.h"
#include "myslam/frontend.h"
#include "wk_st_lk_middle.h"

namespace myslam
{

/**
 * VO 对外接口
 */
class VisualOdometry
{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    typedef std::shared_ptr<VisualOdometry> Ptr;

    /// constructor with config file
    VisualOdometry(void);
    ~VisualOdometry(void);
    /**
     * do initialization things before run
     * @return true if success
     */
    bool Init(const std::string& config_file_path);

    /**
     * Make a step forward in dataset
     */
    void Step(wk_corner_video_frame_s::wk_ptr img_data);

    /// 获取前端状态
    FrontendStatus GetFrontendStatus() const { return frontend_->GetStatus(); }

private:
    bool inited_ = false;
    std::string config_file_path_;

    Frontend::Ptr frontend_ = nullptr;
    Backend::Ptr backend_ = nullptr;
    Map::Ptr map_ = nullptr;
};
}  // namespace myslam

#endif  // MYSLAM_VISUAL_ODOMETRY_H
