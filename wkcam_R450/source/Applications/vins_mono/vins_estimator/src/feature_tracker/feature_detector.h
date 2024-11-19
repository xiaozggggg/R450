#ifndef FEATURE_DETECTOR_H_
#define FEATURE_DETECTOR_H_

#include <opencv2/opencv.hpp>
#include "utility.hpp"
#include<mutex>

class IdGenerator {
 public:
  IdGenerator() : id_(0) {}
  int get() {
    std::lock_guard<std::mutex> lock(id_mutex_);
    ++id_;
    // wrap around
    if (id_ <= 0) id_ = 1;  // 0 indicates an invalid id!
    return id_;
  }
  void reset(int id) { id_ = id; }
 private:
  std::mutex id_mutex_;
  int id_;
};

#define DETECT_LEVEL 1
#define BIG_GRID_ROW 5
#define BIG_GRID_COL 5
#define BIG_SMALL_RATE_ROW 3
#define BIG_SMALL_RATE_COL 4
#define DROP_BORDER 4

struct SmallCell
{
    int x;
    int y;
    int w;
    int h;
};

struct BigCell
{
    int x;
    int y;
    int w;
    int h;
    std::vector<SmallCell> small_cells_;
};

class FeatureDetector
{
private:
    int big_grid_rows_;
    int big_grid_cols_;
    int small_grid_rows_;
    int small_grid_cols_;

    int big_g_r_size_;
    int big_g_c_size_;
    int small_g_r_size_;
    int small_g_c_size_;

    std::vector<uchar> big_grid_occ_;
    std::vector<cv::KeyPoint> small_grid_occ_; // have border

    int* small_neib;


    IdGenerator id_generator_;

public:
    void DetectNewPts(const cv::Mat &img, const cv::Mat &div_1, const std::vector<cv::KeyPoint> &old_pts, std::vector<cv::KeyPoint> &new_pts, int num);
    void DetectNewPts(const std::vector<cv::Mat> &pyr, const std::vector<cv::KeyPoint> &old_pts, std::vector<cv::KeyPoint> &new_pts, int num);

    FeatureDetector(cv::Size img_s);
    ~FeatureDetector();
    //old_pts在原图像上的，grid是缩放之后的了
    void PutOldPtsInGrid(const std::vector<cv::KeyPoint>& old_pts, std::vector<uchar>& status);
    void PutOldPtsInGrid(const std::vector<cv::KeyPoint> &old_pts);
    int getBigGridRows(){return big_grid_rows_;}
    int getBigGridCols(){return big_grid_cols_;}
    int getBigGridRowSize(){return big_g_r_size_;}
    int getBigGridColSize(){return big_g_c_size_;}
    int getSmallGridRows(){return small_grid_rows_;}
    int getSmallGridCols(){return small_grid_cols_;}
    int getSmallGridRowSize(){return small_g_r_size_;}
    int getSmallGridColSize(){return small_g_c_size_;}




private:
void putSmallToBigGrid(const std::vector<std::pair<int, std::vector<int>>> &detect_big_small_sub);
void SmallGridMaxFillter(const std::vector<int>& detect_s_g_r, std::vector<cv::KeyPoint>& big33Pts);
void ClearGrid(std::vector<cv::KeyPoint>& grid_occ_);
void ClearGrid(std::vector<uchar> &grid_occ_);
// void refine_kp_in_larger_img(const cv::Mat &img, std::vector<cv::KeyPoint> &t_key_pnts_ptr);
void refine_kp_in_larger_img(const cv::Mat &img, const std::vector<cv::KeyPoint> &smallPs, std::vector<cv::KeyPoint> &bigPs);

};


#endif