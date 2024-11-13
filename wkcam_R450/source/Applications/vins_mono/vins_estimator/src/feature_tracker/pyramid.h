#ifndef PYTAMID_H_
#define PYTAMID_H_

#include <opencv2/opencv.hpp>

#define MaxPyraLevel 3

class Pyramid
{
private:
  const int level_ = 3;
  cv::Size img_size_;

  std::shared_ptr<uchar> prev_img_pyramids_buffer_; // buffer for storing previous pyramids
  std::shared_ptr<uchar> curr_img_pyramids_buffer_; // buffer for storing current pyramids
  std::vector<cv::Mat> prev_img_pyramids_;
  std::vector<cv::Mat> curr_img_pyramids_;

  // For optical flow dan feature detection
  std::shared_ptr<int16_t> prev_div_pyramids_buffer_; // buffer for storing previous pyramids
  std::shared_ptr<int16_t> curr_div_pyramids_buffer_; // buffer for storing current pyramids
  std::vector<cv::Mat> prev_div_pyramids_;
  std::vector<cv::Mat> curr_div_pyramids_;

public:
  Pyramid(cv::Size img_size, int track_lvl = 1, int detect_lvl = 1);
  ~Pyramid();

  void setImgSize(const cv::Size img_size);

  void build_pyramids(const cv::Mat *left_img, const cv::Mat *right_img = NULL);
  void update_img_pyramids();

  std::vector<cv::Mat> getPreImgPyr() { return prev_img_pyramids_; }
  cv::Mat getPrePyrImg(int level = 0) { return prev_img_pyramids_[level]; }
  std::vector<cv::Mat> getCurrImgPyr() { return curr_img_pyramids_; }
  cv::Mat getCurrPyrImg(int level = 0) { return curr_img_pyramids_[level]; }

  std::vector<cv::Mat> getPreDivPyr() { return prev_div_pyramids_; }
  cv::Mat getPreDivPyrImg(int level = 1) { return prev_div_pyramids_[level]; }
  std::vector<cv::Mat> getCurrDivPyr() { return curr_div_pyramids_; }
  cv::Mat getCurrDivPyrImg(int level = 1) { return curr_div_pyramids_[level]; }

private:
  void build_pyr(const cv::Mat *img, std::vector<cv::Mat> &img_pyr, std::vector<cv::Mat> &div_pyr);
  void fast_pyra_down_internal(const cv::Mat &img_in_smooth, cv::Mat *_img_in_small);
  void calcSharrDeriv(const cv::Mat &src, cv::Mat *dst);
};

#endif