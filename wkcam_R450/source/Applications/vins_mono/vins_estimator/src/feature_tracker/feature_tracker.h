#pragma once

#include <cstdio>
#include <iostream>
#include <queue>
// #include <execinfo.h>
#include <csignal>

#include <opencv2/opencv.hpp>
#include <Eigen/Dense>

#include "camodocal/camera_models/CameraFactory.h"
#include "camodocal/camera_models/CataCamera.h"
#include "camodocal/camera_models/PinholeCamera.h"

#include "../parameters.h"
#include "../utility/tic_toc.h"

#include "pyramid.h"
#include "feature_detector.h"

using namespace std;
using namespace camodocal;
using namespace Eigen;

bool inBorder(const cv::Point2f &pt);

void reduceVector(vector<cv::KeyPoint> &v, vector<uchar> status);
void reduceVector(vector<int> &v, vector<uchar> status);

class FeatureTracker
{
public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  FeatureTracker();
  ~FeatureTracker();

  void setPara(cv::Size img_size, int track_level);

  int readImage(const cv::Mat &_img);

  void addPoints(const vector<cv::KeyPoint> &pts);

  bool updateID(unsigned int i);

  void readIntrinsicParameter(const string &calib_file);

  void showUndistortion(const string &name);

  void rejectWithF();

  // 计算极线误差并剔除不满足约束的点
  void rejectWithEpipolarError();
  
  // 计算单个点对的极线误差
  double computeEpipolarError(const cv::Point2f& pt1, const cv::Point2f& pt2, const cv::Mat& F);

  // 设置极线误差阈值
  void setEpipolarThreshold(double threshold);
  
  // 成员变量（在类的private部分添加）：
  double epipolar_threshold_ = 0.5;  // 极线误差阈值（像素）
  cv::Mat fundamental_matrix_;       // 基础矩阵，在rejectWithF中计算
  vector<cv::Point2f> undistortedPoints();

  cv::Mat mask;
  cv::Mat fisheye_mask;
  vector<cv::KeyPoint> n_pts;
  vector<cv::KeyPoint> prev_pts, cur_pts;
  vector<int> ids;
  vector<int> track_cnt;
  camodocal::CameraPtr m_camera;

  static int n_id;

  Pyramid *img_pyr_;
  FeatureDetector *deature_detector_;
  int track_level_ = 0;
};
