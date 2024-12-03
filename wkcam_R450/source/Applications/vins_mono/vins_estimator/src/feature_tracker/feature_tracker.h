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
