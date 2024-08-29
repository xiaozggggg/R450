//
// Created by gaoxiang on 19-5-2.
//

#include <opencv2/opencv.hpp>
#include "myslam/algorithm.h"
#include "myslam/backend.h"
#include "myslam/config.h"
#include "myslam/feature.h"
#include "myslam/frontend.h"
//#include "myslam/g2o_types.h"
#include "myslam/map.h"
#include "wk_st_lk_middle.h"

namespace myslam
{

Frontend::Frontend() : mpInitializer(nullptr)
{
    gftt_ = cv::GFTTDetector::create(Config::Get<int>("num_features"), 0.01, 20);
    num_features_init_ = Config::Get<int>("num_features_init");
    num_features_ = Config::Get<int>("num_features");
}

bool Frontend::AddFrame(myslam::Frame::Ptr frame)
{
    current_frame_ = frame;

    if(status_ == FrontendStatus::NO_IMAGES_YET)
        status_ = FrontendStatus::INITING;

    switch (status_)
    {
        case FrontendStatus::INITING:
            MonocularInitialization();
            break;
        case FrontendStatus::TRACKING_GOOD:
        case FrontendStatus::TRACKING_BAD:
            Track();
            break;
        case FrontendStatus::LOST:
            Reset();
            break;
    }

    last_frame_ = current_frame_;

    return status_ != FrontendStatus::LOST && status_ != FrontendStatus::INITING;
}

bool Frontend::Track()
{
    if (last_frame_)
        current_frame_->SetPose(relative_motion_ * last_frame_->Pose());

    int num_track_last = TrackLastFrame();

    tracking_inliers_ = EstimateCurrentPose();

    if (tracking_inliers_ > num_features_tracking_)
    {
        // tracking good
        status_ = FrontendStatus::TRACKING_GOOD;

        std::cout << "tracking good!" << std::endl;
    }
    else if (tracking_inliers_ > num_features_tracking_bad_)
    {
        // tracking bad
        status_ = FrontendStatus::TRACKING_BAD;
    }
    else
    {
        // lost
        status_ = FrontendStatus::LOST;

        std::cout << "tracking lost!" << std::endl;
    }

    InsertKeyframe();

    relative_motion_ = current_frame_->Pose() * last_frame_->Pose().inv();

    return status_ != FrontendStatus::LOST;
}

bool Frontend::InsertKeyframe()
{
    if (tracking_inliers_ >= num_features_tracking_bad_)
    {
        std::cout << "still have enough features, don't insert keyframe:" << tracking_inliers_ << std::endl << num_features_tracking_bad_ << std::endl;
        return false;
    }

    // current frame is a new keyframe
    current_frame_->SetKeyFrame();
    map_->InsertKeyFrame(current_frame_);

    std::cout << "Set frame " << current_frame_->id_ << " as keyframe " << current_frame_->keyframe_id_ << std::endl;

    SetObservationsForKeyFrame();
    DetectFeatures(last_frame_);  // detect new features

    // track in right image
    FindFeaturesInLast();
    // triangulate map points
    //TriangulateNewPoints();
    // update backend because we have a new keyframe
    backend_->UpdateMap();

    return true;
}

void Frontend::SetObservationsForKeyFrame() {
    for (auto &feat : current_frame_->features_left_) {
        auto mp = feat->map_point_.lock();
        if (mp) mp->AddObservation(feat);
    }
}

cv::Point2f cam2pixel(const cv::Point3d &p_c, const cv::Mat &K)
{
    cv::Point2f pi = (cv::Point2f(K.at<double>(0, 0) * p_c.x / p_c.z + K.at<double>(0, 2),
                                            K.at<double>(1, 1) * p_c.y / p_c.z + K.at<double>(1, 2)));
    return pi;
}

int Frontend::TriangulateNewPoints(const std::vector<cv::Point2f> &keypoint_1,
                                   const std::vector<cv::Point2f> &keypoint_2,
                                   const Mat &R, const Mat &t, std::vector<cv::Point3f> &points)
{
    cv::Mat T1 = (cv::Mat_<float>(3, 4) <<
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0);
    cv::Mat T2 = (cv::Mat_<float>(3, 4) <<
      R.at<double>(0, 0), R.at<double>(0, 1), R.at<double>(0, 2), t.at<double>(0, 0),
      R.at<double>(1, 0), R.at<double>(1, 1), R.at<double>(1, 2), t.at<double>(1, 0),
      R.at<double>(2, 0), R.at<double>(2, 1), R.at<double>(2, 2), t.at<double>(2, 0)
    );

    std::vector<cv::Point2f> pts_1, pts_2;

    for(int i=0; i< int(keypoint_1.size()); ++i)
    {
      // 将像素坐标转换至相机坐标
      pts_1.push_back(camera_left_->pixel2cam(keypoint_1[i]));
      pts_2.push_back(camera_left_->pixel2cam(keypoint_2[i]));
    }

    Mat pts_4d;
    cv::triangulatePoints(T1, T2, pts_1, pts_2, pts_4d);

    // 转换成非齐次坐标
    for (int i = 0; i < pts_4d.cols; i++)
    {
      Mat x = pts_4d.col(i);
      x /= x.at<float>(3, 0); // 归一化
      cv::Point3d p(
        x.at<float>(0, 0),
        x.at<float>(1, 0),
        x.at<float>(2, 0)
      );
      points.push_back(p);
    }

    //std::cout << "new landmarks: " << points.size();

    return points.size();
}

int Frontend::EstimateCurrentPose()
{
    // setup g2o
    // 解映射关系
    cv::Mat rotationVector;
    cv::Mat translationVector;

    std::vector<cv::Point3f> vecWorldPts;
    std::vector<cv::Point2f> vecImagePts;

    for (auto &kp : current_frame_->features_left_)
    {
        if (kp->map_point_.lock())
        {
            auto mp = kp->map_point_.lock();

            vecWorldPts.push_back(cv::Point3f(mp->Pos().x(), mp->Pos().y(), mp->Pos().z()));
            vecImagePts.push_back(cv::Point2f(kp->position_.pt));
        }
    }

    if(vecWorldPts.size() < 8)
    {
        std::cout << "vecWorldPts.size() < 8!" << std::endl;
        return 0;
    }
    if(!cv::solvePnP(vecWorldPts, vecImagePts, camera_left_->K(), cv::Mat::zeros(5, 1, CV_64FC1), rotationVector, translationVector))
        std::cout << "solvePnP false!" << std::endl;

    // 旋转矩阵
    cv::Mat matRotation;
    cv::Mat Tcw = cv::Mat::eye(4,4,CV_32F);

    cv::Rodrigues(rotationVector, matRotation);

    matRotation.copyTo(Tcw.rowRange(0,3).colRange(0,3));
    translationVector.copyTo(Tcw.rowRange(0,3).col(3));

    current_frame_->SetPose(Tcw);

    std::cout << "EstimateCurrentPose" << std::endl << vecWorldPts.size() << std::endl << matRotation << std::endl << translationVector << std::endl;

    return vecWorldPts.size();
}

int Frontend::TrackLastFrame()
{
    int num_good_pts = 0;
    // use LK flow to estimate points in the right image
    if(false && "use wk")
    {
        std::vector<cv::Point2f> kps_last, kps_current;

        for (auto &kp : last_frame_->features_left_)
        {
            if (kp->map_point_.lock() && false)
            {
                // use project point
                auto mp = kp->map_point_.lock();
                cv::Mat pc = (cv::Mat_<float>(3, 1) << mp->pos_.x(), mp->pos_.y(), mp->pos_.z());
                cv::Mat Rcw;
                cv::Mat tcw;
                current_frame_->Pose().rowRange(0,3).colRange(0,3).copyTo(Rcw);
                current_frame_->Pose().rowRange(0,3).col(3).copyTo(tcw);
                auto px = camera_left_->world2pixel(pc, Rcw, tcw);
                //std::cout << "ppppppppppppppppppp1:" << kp->position_.pt.x << " " << kp->position_.pt.y << std::endl;
                //std::cout << "ppppppppppppppppppp2:" << px.at<float>(0) << " " << px.at<float>(1) << std::endl;
                kps_last.push_back(kp->position_.pt);
                kps_current.push_back(cv::Point2f(px.at<float>(0), px.at<float>(1)));
            }
            else
            {
                kps_last.push_back(kp->position_.pt);
                kps_current.push_back(kp->position_.pt);
            }
        }

        std::vector<uchar> status;
        Mat error;
        cv::calcOpticalFlowPyrLK(
            last_frame_->left_img_, current_frame_->left_img_, kps_last,
            kps_current, status, error, cv::Size(11, 11), 3,
            cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30,
                            0.01),
            cv::OPTFLOW_USE_INITIAL_FLOW);

        for (size_t i = 0; i < status.size(); ++i)
        {
            if (status[i])
            {
                cv::KeyPoint kp(kps_current[i], 7);
                Feature::Ptr feature(new Feature(current_frame_, kp));
                feature->map_point_ = last_frame_->features_left_[i]->map_point_;
                current_frame_->features_left_.push_back(feature);
                num_good_pts++;
            }
        }
    }
    else
    {
        wk_lk_points_input_s::wk_ptr _info = std::make_shared<wk_lk_points_input_s>();
        wk_lk_points_output_s::wk_ptr _points = std::make_shared<wk_lk_points_output_s>();

        _info->points_cnt = 0;
        _info->prev_frame = &last_frame_->img_data->frame;
        _info->curr_frame = &current_frame_->img_data->frame;

        for (auto &kp : last_frame_->features_left_)
        {
            _info->prev_points[_info->points_cnt].x = kp->position_.pt.x;
            _info->prev_points[_info->points_cnt].y = kp->position_.pt.y;
            _info->points_cnt++;
        }

        wk_st_lk_middle::wk_st_lk_get_instance()->wk_corner_track(_info, _points);

        for(int i=0; i<_info->points_cnt; ++i)
        {
            if(_points->status[i] == 1)
            {
                cv::KeyPoint kp(cv::Point2f(_points->curr_points[i].x, _points->curr_points[i].y), 7);
                Feature::Ptr feat(new Feature(current_frame_, kp));
                feat->map_point_ = last_frame_->features_left_[i]->map_point_;
                current_frame_->features_left_.push_back(feat);
                num_good_pts++;
            }
        }
    }

    std::cout << "TrackLastFrame Find " << num_good_pts << " in the last image." << std::endl;

    return num_good_pts;
}

void Frontend::MonocularInitialization()
{
    int num_features_left = DetectFeatures(current_frame_);

    if(!mpInitializer)
    {
        // Set Reference Frame
        if(int(current_frame_->features_left_.size()) > num_features_init_)
        {
            mInitialFrame = current_frame_;
            last_frame_ = current_frame_;
            mvbPrevMatched.resize(current_frame_->features_left_.size());

            for(size_t i=0; i<current_frame_->features_left_.size(); i++)
                mvbPrevMatched[i] = current_frame_->features_left_[i]->position_.pt;

            if(mpInitializer)
                mpInitializer = nullptr;

            cv::Mat k = (cv::Mat_<float>(3, 3) <<
                        camera_left_->fx_, 0, camera_left_->cx_,
                        0, camera_left_->fy_, camera_left_->cy_,
                        0, 0, 1);

            mpInitializer = std::make_unique<Initializer>(*current_frame_, k, 1.0, 200);

            std::fill(mvIniMatches.begin(), mvIniMatches.end(), -1);

            std::cout << "Init step 1 succ!" << std::endl;

            return;
        }
        else
        {
            std::cout << "Init step 1 fail feature points less than " << num_features_init_ << std::endl;
        }
    }
    else
    {
        // Try to initialize
        if(int(current_frame_->features_left_.size()) <= num_features_init_)
        {
            mpInitializer = nullptr;

            std::fill(mvIniMatches.begin(),mvIniMatches.end(),-1);

            std::cout << "Init step 2 feature points less than 100!" << std::endl;

            return;
        }
        else
        {
            std::cout << "Init step 2 succ!" << std::endl;
        }

        int nmatches = FindFeaturesInRight();

        // Check if there are enough correspondences
        if(nmatches < num_features_init_)
        {
            mpInitializer = nullptr;

            std::cout << "Init step 3 feature points match less than 100!" << std::endl;

            return;
        }
        else
        {
            std::cout << "Init step 3 succ!" << std::endl;
        }

        cv::Mat Rcw; // Current Camera Rotation
        cv::Mat tcw; // Current Camera Translation
        std::vector<bool> vbTriangulated; // Triangulated Correspondences (mvIniMatches)

        if(true)
        {
            //-- 计算本质矩阵
            cv::Point2d principal_point(camera_left_->cx_, camera_left_->cy_);  //相机光心, TUM dataset标定值
            double focal_length = camera_left_->fx_;      //相机焦距, TUM dataset标定值
            cv::Mat essential_matrix;
            std::vector<cv::Point2f> points1;
            std::vector<cv::Point2f> points2;

            for(int i=0; i<last_frame_->features_left_.size();++i)
            {
                if(mvIniMatches[i]>=0)
                {
                    points1.push_back(last_frame_->features_left_[i]->position_.pt);
                    points2.push_back(current_frame_->features_left_[mvIniMatches[i]]->position_.pt);
                }
            }
            essential_matrix = cv::findEssentialMat(points1, points2, focal_length, principal_point);
            cv::recoverPose(essential_matrix, points1, points2, Rcw, tcw, focal_length, principal_point);
            std::cout << "essential_matrix is " << std::endl << essential_matrix << std::endl;
            std::cout << "R is " << std::endl << Rcw << std::endl;
            std::cout << "t is " << std::endl << tcw << std::endl;

            std::vector<cv::Point3f> IniP3D;
            TriangulateNewPoints(points1, points2, Rcw, tcw, IniP3D);

            int matchIndex = 0;

            for(int i=0; i<mvIniMatches.size(); ++i)
            {
                mvIniP3D.push_back(IniP3D[matchIndex]);

                if(mvIniMatches[i]>=0)
                    matchIndex++;
            }

            std::cout << "Init step 3333 succ!" << std::endl;

            // Set Frame Poses
            mInitialFrame->SetPose(cv::Mat::eye(4,4,CV_32F));
            cv::Mat Tcw = cv::Mat::eye(4,4,CV_32F);

            Rcw.copyTo(Tcw.rowRange(0,3).colRange(0,3));
            tcw.copyTo(Tcw.rowRange(0,3).col(3));

            current_frame_->SetPose(Tcw);


            if(CreateInitialMapMonocular())
            {
                status_ = FrontendStatus::TRACKING_GOOD;
            }
        }
        else if(mpInitializer->Initialize(*current_frame_, mvIniMatches, Rcw, tcw, mvIniP3D, vbTriangulated))
        {
            for(size_t i=0, iend=mvIniMatches.size(); i<iend;i++)
            {
                if(mvIniMatches[i]>=0 && !vbTriangulated[i])
                {
                    mvIniMatches[i]=-1;
                    nmatches--;
                }
            }

            std::cout << "Init step 3333 succ!" << std::endl;

            // Set Frame Poses
            mInitialFrame->SetPose(cv::Mat::eye(4,4,CV_32F));
            cv::Mat Tcw = cv::Mat::eye(4,4,CV_32F);

            Rcw.copyTo(Tcw.rowRange(0,3).colRange(0,3));
            tcw.copyTo(Tcw.rowRange(0,3).col(3));

            current_frame_->SetPose(Tcw);


            if(CreateInitialMapMonocular())
            {
                status_ = FrontendStatus::TRACKING_GOOD;
            }
        }
        else
        {
            std::cout << "Init step 4 Initialize fail!" << std::endl;
        }
    }
    return;
}

int Frontend::DetectFeatures(Frame::Ptr frame)
{
    std::vector<cv::KeyPoint> keypoints;

    if(false && "use wk")
    {
        cv::Mat mask(frame->left_img_.size(), CV_8UC1, 255);

        for (auto &feat : frame->features_left_)
        {
            cv::rectangle(mask, feat->position_.pt - cv::Point2f(10, 10),
                          feat->position_.pt + cv::Point2f(10, 10), 0, CV_FILLED);
        }

        gftt_->detect(frame->left_img_, keypoints, mask);
    }
    else
    {
        wk_st_points_s::wk_ptr _points = std::make_shared<wk_st_points_s>();
        wk_st_lk_middle::wk_st_lk_get_instance()->wk_corner_recognize(frame->img_data, _points);

        for(int i=0; i<_points->points_cnt; ++i)
        {
            cv::KeyPoint kp;
            kp.pt.x = _points->points[i].x;
            kp.pt.y = _points->points[i].y;

            keypoints.push_back(kp);

            std::cout << "DetectFeatures num: " << _points->points[i].x << " " << _points->points[i].y << std::endl;
        }

        std::cout << "DetectFeatures num: " << keypoints.size() << std::endl;
    }


    int cnt_detected = 0;
    for (auto &kp : keypoints)
    {
        frame->features_left_.push_back(Feature::Ptr(new Feature(frame, kp)));
        cnt_detected++;
    }

    std::cout << "Detect " << cnt_detected << " new features!" << std::endl;
    return cnt_detected;
}

int Frontend::FindFeaturesInRight()
{
    int num_good_pts = 0;

    current_frame_->features_left_.clear();

    mvIniMatches = std::vector<int>(last_frame_->features_left_.size(),-1);

    if(false && "use wk")
    {
        // use LK flow to estimate points in the right image
        std::vector<cv::Point2f> kps_last_frame, kps_current_frame;
        for (auto &kp : last_frame_->features_left_)
        {
            kps_last_frame.push_back(kp->position_.pt);
            auto mp = kp->map_point_.lock();
            if (mp && false)
            {
                // use projected points as initial guess
                cv::Mat pc = (cv::Mat_<float>(3, 1) << mp->pos_.x(), mp->pos_.y(), mp->pos_.z());
                cv::Mat Rcw;
                cv::Mat tcw;
                current_frame_->Pose().rowRange(0,3).colRange(0,3).copyTo(Rcw);
                current_frame_->Pose().rowRange(0,3).col(3).copyTo(tcw);

                auto px = camera_left_->world2pixel(pc, Rcw, tcw);
                kps_current_frame.push_back(cv::Point2f(px.at<float>(0), px.at<float>(1)));
            }
            else
            {
                // use same pixel in left iamge
                kps_current_frame.push_back(kp->position_.pt);
            }
        }

        std::vector<uchar> status;
        Mat error;
        cv::calcOpticalFlowPyrLK(last_frame_->left_img_,
                                current_frame_->left_img_,
                                kps_last_frame,
                                kps_current_frame,
                                status, error, cv::Size(11, 11), 3,
                                cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, 0.01),
                                cv::OPTFLOW_USE_INITIAL_FLOW);

        for (size_t i = 0; i < status.size(); ++i)
        {
            if (status[i])
            {
                cv::KeyPoint kp(kps_current_frame[i], 7);
                Feature::Ptr feat(new Feature(current_frame_, kp));
                current_frame_->features_left_.push_back(feat);
                mvIniMatches[i] = current_frame_->features_left_.size()-1;
                num_good_pts++;
            }
        }
    }
    else
    {
        wk_lk_points_input_s::wk_ptr _info = std::make_shared<wk_lk_points_input_s>();
        wk_lk_points_output_s::wk_ptr _points = std::make_shared<wk_lk_points_output_s>();

        _info->points_cnt = 0;
        _info->prev_frame = &last_frame_->img_data->frame;
        _info->curr_frame = &current_frame_->img_data->frame;

        for (auto &kp : last_frame_->features_left_)
        {
            _info->prev_points[_info->points_cnt].x = kp->position_.pt.x;
            _info->prev_points[_info->points_cnt].y = kp->position_.pt.y;
            _info->points_cnt++;
        }

        wk_st_lk_middle::wk_st_lk_get_instance()->wk_corner_track(_info, _points);

        for(int i=0; i<_info->points_cnt; ++i)
        {
            if(_points->status[i] == 1)
            {
                cv::KeyPoint kp(cv::Point2f(_points->curr_points[i].x, _points->curr_points[i].y), 7);
                Feature::Ptr feat(new Feature(current_frame_, kp));
                current_frame_->features_left_.push_back(feat);
                mvIniMatches[i] = current_frame_->features_left_.size()-1;
                num_good_pts++;
            }
        }
    }
    std::cout << "Find " << num_good_pts << " in the right image." << std::endl;
    return num_good_pts;
}

int Frontend::FindFeaturesInLast()
{
    std::cout << "current_frame_ " << current_frame_->features_left_.size() << " features." << std::endl;

    current_frame_->features_left_.clear();

    // use LK flow to estimate points in the right image

    int num_good_pts = 0;
    int num_triangulate_pts = 0;

    if(false && "use wk")
    {
        std::vector<cv::Point2f> kps_last_frame, kps_current_frame;

        for (auto &kp : last_frame_->features_left_)
        {
            kps_last_frame.push_back(kp->position_.pt);

            auto mp = kp->map_point_.lock();

            if (mp && false)
            {
                // use projected points as initial guess
                cv::Mat pc = (cv::Mat_<float>(3, 1) << mp->pos_.x(), mp->pos_.y(), mp->pos_.z());
                cv::Mat Rcw;
                cv::Mat tcw;
                current_frame_->Pose().rowRange(0,3).colRange(0,3).copyTo(Rcw);
                current_frame_->Pose().rowRange(0,3).col(3).copyTo(tcw);

                auto px = camera_left_->world2pixel(pc, Rcw, tcw);
                kps_current_frame.push_back(cv::Point2f(px.at<float>(0), px.at<float>(1)));
            }
            else
            {
                // use same pixel in left iamge
                kps_current_frame.push_back(kp->position_.pt);
            }
        }

        std::vector<uchar> status;
        cv::Mat error;
        cv::calcOpticalFlowPyrLK(last_frame_->left_img_,
                                current_frame_->left_img_,
                                kps_last_frame,
                                kps_current_frame,
                                status, error, cv::Size(11, 11), 3,
                                cv::TermCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 30, 0.01),
                                cv::OPTFLOW_USE_INITIAL_FLOW);

        for (size_t i = 0; i < status.size(); ++i)
        {
            if (status[i])
            {
                cv::KeyPoint kp(kps_current_frame[i], 7);
                Feature::Ptr feat(new Feature(current_frame_, kp));

                if(last_frame_->features_left_[i]->map_point_.lock())
                {
                    feat->map_point_ = last_frame_->features_left_[i]->map_point_;
                    current_frame_->features_left_.push_back(feat);
                    num_good_pts++;
                }
                else
                {
                    std::vector<cv::Point2f> keypoint_1{last_frame_->features_left_[i]->position_.pt};
                    std::vector<cv::Point2f> keypoint_2{kps_current_frame[i]};

                    cv::Mat R;
                    cv::Mat t;
                    std::vector<cv::Point3f> points;
                    cv::Mat Tcl = current_frame_->Pose() * last_frame_->Pose().inv();
                    Tcl.rowRange(0,3).colRange(0,3).copyTo(R);
                    Tcl.rowRange(0,3).col(3).copyTo(t);

                    TriangulateNewPoints(keypoint_1, keypoint_2, R, t, points);

                    if(points[i].z < 0)
                    {
                        std::cout << "points[" << i << "].z < 0 !" << std::endl;
                        continue;
                    }

                    cv::Mat p_c = (cv::Mat_<float>(3, 1) << points[0].x, points[0].y, points[0].z);
                    cv::Mat p_w = camera_left_->camera2world(p_c, last_frame_->Pose().rowRange(0,3).colRange(0,3), last_frame_->Pose().rowRange(0,3).col(3));
                    Vec3 pworld(p_w.at<float>(0,0), p_w.at<float>(1,0), p_w.at<float>(2,0));

                    auto new_map_point = MapPoint::CreateNewMappoint();
                    new_map_point->SetPos(pworld);
                    new_map_point->AddObservation(last_frame_->features_left_[i]);
                    new_map_point->AddObservation(feat);
                    last_frame_->features_left_[i]->map_point_ = new_map_point;
                    feat->map_point_ = new_map_point;
                    map_->InsertMapPoint(new_map_point);
                    num_triangulate_pts++;

                    current_frame_->features_left_.push_back(feat);
                    num_good_pts++;
                }
            }

        }
    }
    else
    {
        wk_lk_points_input_s::wk_ptr _info = std::make_shared<wk_lk_points_input_s>();
        wk_lk_points_output_s::wk_ptr _points = std::make_shared<wk_lk_points_output_s>();

        _info->points_cnt = 0;
        _info->prev_frame = &last_frame_->img_data->frame;
        _info->curr_frame = &current_frame_->img_data->frame;

        for (auto &kp : last_frame_->features_left_)
        {
            _info->prev_points[_info->points_cnt].x = kp->position_.pt.x;
            _info->prev_points[_info->points_cnt].y = kp->position_.pt.y;
            _info->points_cnt++;
        }

        wk_st_lk_middle::wk_st_lk_get_instance()->wk_corner_track(_info, _points);

        for(int i=0; i<_info->points_cnt; ++i)
        {
            if(_points->status[i] == 1)
            {
                cv::KeyPoint kp(cv::Point2f(_points->curr_points[i].x, _points->curr_points[i].y), 7);
                Feature::Ptr feat(new Feature(current_frame_, kp));
                
                if(last_frame_->features_left_[i]->map_point_.lock())
                {
                    feat->map_point_ = last_frame_->features_left_[i]->map_point_;
                    current_frame_->features_left_.push_back(feat);
                    num_good_pts++;
                }
                else
                {
                    std::vector<cv::Point2f> keypoint_1{last_frame_->features_left_[i]->position_.pt};
                    std::vector<cv::Point2f> keypoint_2{cv::Point2f(_points->curr_points[i].x, _points->curr_points[i].y)};

                    cv::Mat R;
                    cv::Mat t;
                    std::vector<cv::Point3f> points;
                    cv::Mat Tcl = current_frame_->Pose() * last_frame_->Pose().inv();
                    Tcl.rowRange(0,3).colRange(0,3).copyTo(R);
                    Tcl.rowRange(0,3).col(3).copyTo(t);

                    TriangulateNewPoints(keypoint_1, keypoint_2, R, t, points);

                    if(points[i].z < 0)
                    {
                        std::cout << "points[" << i << "].z < 0 !" << std::endl;
                        continue;
                    }

                    cv::Mat p_c = (cv::Mat_<float>(3, 1) << points[0].x, points[0].y, points[0].z);
                    cv::Mat p_w = camera_left_->camera2world(p_c, last_frame_->Pose().rowRange(0,3).colRange(0,3), last_frame_->Pose().rowRange(0,3).col(3));
                    Vec3 pworld(p_w.at<float>(0,0), p_w.at<float>(1,0), p_w.at<float>(2,0));

                    auto new_map_point = MapPoint::CreateNewMappoint();
                    new_map_point->SetPos(pworld);
                    new_map_point->AddObservation(last_frame_->features_left_[i]);
                    new_map_point->AddObservation(feat);
                    last_frame_->features_left_[i]->map_point_ = new_map_point;
                    feat->map_point_ = new_map_point;
                    map_->InsertMapPoint(new_map_point);
                    num_triangulate_pts++;

                    current_frame_->features_left_.push_back(feat);
                    num_good_pts++;
                }
            }
        }
    }

    if(num_good_pts < 50)
    {
        //std::cout << "KKKKKKKKKKKKKKKKKKKKKKK" << std::endl;
        //cv::imshow("last_frame_->left_img_", last_frame_->left_img_);
        //cv::imshow("current_frame_->left_img_", current_frame_->left_img_);
        //cv::waitKey(0);
    }
    else
    {
        //std::cout << "KKKKKKKKKKKKKKKKKKKKKKK2" << std::endl;
        //cv::imshow("last_frame_->left_img_", last_frame_->left_img_);
        //cv::imshow("current_frame_->left_img_", current_frame_->left_img_);
        //cv::waitKey(0);
    }
    std::cout << "Find " << num_good_pts << " in the last image." << std::endl << num_triangulate_pts << std::endl;

    return num_good_pts;
}

bool Frontend::CreateInitialMapMonocular()
{
    map_->Reset();
    
    size_t cnt_init_landmarks = 0;

    for(size_t i=0; i<mvIniMatches.size();i++)
    {
        if(mvIniMatches[i]<0)
            continue;

        if(mvIniP3D[i].z < 0)
        {
            std::cout << "mvIniP3D[" << i << "].z < 0 !" << std::endl;
            continue;
        }

        Vec3 pworld(mvIniP3D[i].x, mvIniP3D[i].y, mvIniP3D[i].z);

        auto new_map_point = MapPoint::CreateNewMappoint();
        new_map_point->SetPos(pworld);
        new_map_point->AddObservation(mInitialFrame->features_left_[i]);
        new_map_point->AddObservation(current_frame_->features_left_[mvIniMatches[i]]);
        mInitialFrame->features_left_[i]->map_point_ = new_map_point;
        current_frame_->features_left_[mvIniMatches[i]]->map_point_ = new_map_point;
        cnt_init_landmarks++;
        map_->InsertMapPoint(new_map_point);

    }

    mInitialFrame->SetKeyFrame();
    current_frame_->SetKeyFrame();
    map_->InsertKeyFrame(mInitialFrame);
    map_->InsertKeyFrame(current_frame_);
    backend_->UpdateMap();

    std::cout << "Initial map created with " << cnt_init_landmarks << " map points." << std::endl;

    return true;
}

bool Frontend::Reset()
{
    if(mpInitializer)
        mpInitializer = nullptr;

    status_ = FrontendStatus::INITING;

    std::cout << "Reset is implemented. ";

    return true;
}

}  // namespace myslam
