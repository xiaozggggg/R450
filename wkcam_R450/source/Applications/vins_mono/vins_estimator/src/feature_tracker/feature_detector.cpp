#include "feature_detector.h"


FeatureDetector::FeatureDetector(cv::Size img_s)
{
  img_s.width /= (1<<DETECT_LEVEL);
  img_s.height /= (1<<DETECT_LEVEL);

  big_grid_rows_ = BIG_GRID_ROW;
  big_grid_cols_ = BIG_GRID_COL;
  small_grid_rows_ = big_grid_rows_ * BIG_SMALL_RATE_ROW + 2; // add border
  small_grid_cols_ = big_grid_cols_ * BIG_SMALL_RATE_COL + 2;

  big_g_r_size_ = img_s.height / big_grid_rows_;
  big_g_c_size_ = img_s.width / big_grid_cols_;
  small_g_r_size_ = big_g_r_size_ / BIG_SMALL_RATE_ROW;
  small_g_c_size_ = big_g_c_size_ / BIG_SMALL_RATE_COL;

  big_grid_occ_.resize(big_grid_rows_ * big_grid_cols_);
  small_grid_occ_.resize(small_grid_rows_ * small_grid_cols_);

  small_neib = new int[8]{-small_grid_cols_ - 1, -small_grid_cols_, -small_grid_cols_ + 1,
                          -1, 1,
                          small_grid_cols_ - 1, small_grid_cols_, small_grid_cols_ + 1};
}

FeatureDetector::~FeatureDetector()
{
}

void FeatureDetector::ClearGrid(std::vector<cv::KeyPoint> &grid_occ_)
{
  for (size_t i = 0; i < grid_occ_.size(); i++)
  {
    grid_occ_[i].class_id = -1; // new point
    grid_occ_[i].response = 0;  // empty
    grid_occ_[i].angle = -1;  // 
  }
}

void FeatureDetector::PutOldPtsInGrid(const std::vector<cv::KeyPoint> &old_pts, std::vector<uchar> &status)
{
  ClearGrid(big_grid_occ_);
  ClearGrid(small_grid_occ_);

  for (size_t i = 0; i < old_pts.size(); i++)
  {
    if (!status[i])
      continue;

    int big_r = old_pts[i].pt.y / (big_g_r_size_ * (1 << DETECT_LEVEL));
    int big_c = old_pts[i].pt.x / (big_g_c_size_ * (1 << DETECT_LEVEL));
    int sub = big_r * big_grid_cols_ + big_c;
    if (old_pts[i].response > big_grid_occ_[sub].response)
    {

      if (big_grid_occ_[sub].angle != -1)
      {
        status[big_grid_occ_[sub].angle] = 0;
      }
      big_grid_occ_[sub] = old_pts[i];
      big_grid_occ_[sub].angle = i; // 暂时用来存储下标

      // small
      size_t srow = big_r * BIG_SMALL_RATE_ROW + 1; // small grid have border
      size_t scol = big_c * BIG_SMALL_RATE_COL + 1;
      int small_sub = srow * small_grid_cols_ + scol;
      for (int r = 0; r < BIG_SMALL_RATE_ROW; r++, srow++)
      {
        if (srow >= small_grid_rows_)
          break;

        scol = big_c * BIG_SMALL_RATE_COL + 1; // reset col
        for (int c = 0; c < BIG_SMALL_RATE_COL; c++, scol++)
        {
          if (scol >= small_grid_cols_)
            break;
          small_grid_occ_[small_sub] = old_pts[i];
          small_sub++;
        }
        small_sub += small_grid_cols_ - BIG_SMALL_RATE_COL;
      }
    }
    else
      status[i] = 0;
  }
}

void calCov(const cv::Mat &div, cv::Mat &cov, int block_size)
{
  cv::Size size = div.size();
  int i, j;

  for (i = 0; i < size.height; i++)
  {
    float *cov_data = cov.ptr<float>(i);
    const float *divdata = div.ptr<float>(i);
    j = 0;

    // #if CV_SIMD128
    //             {
    //               for (; j <= size.width - v_float32x4::nlanes; j += v_float32x4::nlanes)
    //               {
    //                 v_float32x4 v_dx = v_load(dxdata + j);
    //                 v_float32x4 v_dy = v_load(dydata + j);

    //                 v_float32x4 v_dst0, v_dst1, v_dst2;
    //                 v_dst0 = v_dx * v_dx;
    //                 v_dst1 = v_dx * v_dy;
    //                 v_dst2 = v_dy * v_dy;

    //                 v_store_interleave(cov_data + j * 3, v_dst0, v_dst1, v_dst2);
    //               }
    //             }
    // #endif // CV_SIMD128

    for (; j < size.width; j++)
    {
      float dx = divdata[j * 2];
      float dy = divdata[j * 2 + 1];

      cov_data[j * 3] = dx * dx;
      cov_data[j * 3 + 1] = dx * dy;
      cov_data[j * 3 + 2] = dy * dy;
    }
  }

  boxFilter(cov, cov, cov.depth(), cv::Size(block_size, block_size),
            cv::Point(-1, -1), false);
}
void calCov(const cv::Mat &div, int x, int y, int width, int height, cv::Mat &cov, int block_size = 3)
{
  assert(cov.cols == width);
  assert(cov.rows == height);

  int div_y = y;

  int end_y = y + height;
  int end_x = x + width;

  for (int i = 0; div_y < end_y; div_y++, i++)
  {
    float *cov_data = cov.ptr<float>(i);
    const int16_t *divdata = div.ptr<int16_t>(div_y);

    int cov_x = 0;
    int div_x = x;

    // #if CV_SIMD128
    //             {
    //               for (; j <= size.width - v_float32x4::nlanes; j += v_float32x4::nlanes)
    //               {
    //                 v_float32x4 v_dx = v_load(dxdata + j);
    //                 v_float32x4 v_dy = v_load(dydata + j);

    //                 v_float32x4 v_dst0, v_dst1, v_dst2;
    //                 v_dst0 = v_dx * v_dx;
    //                 v_dst1 = v_dx * v_dy;
    //                 v_dst2 = v_dy * v_dy;

    //                 v_store_interleave(cov_data + j * 3, v_dst0, v_dst1, v_dst2);
    //               }
    //             }
    // #endif // CV_SIMD128

    for (; div_x < end_x; cov_x++, div_x++)
    {
      float dx = divdata[div_x * 2];
      float dy = divdata[div_x * 2 + 1];

      cov_data[cov_x * 3] = dx * dx;
      cov_data[cov_x * 3 + 1] = dx * dy;
      cov_data[cov_x * 3 + 2] = dy * dy;
    }
  }

  boxFilter(cov, cov, cov.depth(), cv::Size(block_size, block_size),
            cv::Point(-1, -1), false);
}

void calcMinEigenVal(const cv::Mat &_cov, cv::Mat &_dst)
{
  int i, j;
  cv::Size size = _cov.size();

  if (_cov.isContinuous() && _dst.isContinuous())
  {
    size.width *= size.height;
    size.height = 1;
  }

  for (i = 0; i < size.height; i++)
  {
    const float *cov = _cov.ptr<float>(i);
    float *dst = _dst.ptr<float>(i);
    j = 0;

    // #if CV_SIMD128
    //     {
    //       v_float32x4 half = v_setall_f32(0.5f);
    //       for (; j <= size.width - v_float32x4::nlanes; j += v_float32x4::nlanes)
    //       {
    //         v_float32x4 v_a, v_b, v_c, v_t;
    //         v_load_deinterleave(cov + j * 3, v_a, v_b, v_c);
    //         v_a *= half;
    //         v_c *= half;
    //         v_t = v_a - v_c;
    //         v_t = v_muladd(v_b, v_b, (v_t * v_t));
    //         v_store(dst + j, (v_a + v_c) - v_sqrt(v_t));
    //       }
    //     }
    // #endif // CV_SIMD128

    for (; j < size.width; j++)
    {
      float a = cov[j * 3] * 0.5f;
      float b = cov[j * 3 + 1];
      float c = cov[j * 3 + 2] * 0.5f;
      dst[j] = (float)((a + c) - std::sqrt((a - c) * (a - c) + b * b));
    }
  }
}

void minEigenVal(const cv::Mat &img,
                 std::vector<cv::KeyPoint> *pts,
                 int blockSize = 7)
{

  CV_Assert(img.type() == CV_8UC1 && blockSize * blockSize <= 81);

  size_t ptidx, ptsize = pts->size();

  const uchar *ptr00 = img.ptr<uchar>();
  int step = static_cast<int>(img.step / img.elemSize1());
  int r = blockSize / 2;
  int block_element = blockSize * blockSize;

  cv::AutoBuffer<int> ofsbuf(block_element);
  int *ofs = ofsbuf;
  for (int i = 0; i < blockSize; i++)
    for (int j = 0; j < blockSize; j++)
      ofs[i * blockSize + j] = static_cast<int>(i * step + j);

  for (ptidx = 0; ptidx < ptsize; ptidx++)
  {
    int x0 = cvRound((*pts)[ptidx].pt.x - r);
    int y0 = cvRound((*pts)[ptidx].pt.y - r);

    const uchar *ptr0 = ptr00 + y0 * step + x0;
    int a = 0, b = 0, c = 0;

    for (int k = 0; k < block_element; k++)
    {
      const uchar *ptr = ptr0 + ofs[k];
      int Ix = (ptr[1] - ptr[-1]) * 10 + (ptr[-step + 1] - ptr[-step - 1]) * 3 + (ptr[step + 1] - ptr[step - 1]) * 3;
      int Iy = (ptr[step] - ptr[-step]) * 10 + (ptr[step - 1] - ptr[-step - 1]) * 3 + (ptr[step + 1] - ptr[-step + 1]) * 3;
      a += Ix * Ix;
      b += Ix * Iy;
      c += Iy * Iy;
    }

    a /= (block_element >> 1);
    c /= (block_element >> 1);
    b /= block_element;

    (*pts)[ptidx].response = (float)((a + c) - std::sqrt((a - c) * (a - c) + b * b));
  }
}

void FeatureDetector::refine_kp_in_larger_img(const cv::Mat &img, std::vector<cv::KeyPoint> &t_key_pnts_ptr)
{
  int refineNewPointNum = 0;
  std::vector<cv::KeyPoint> local_kps;
  constexpr int harris_block_size = 7; // 5 does not give correct results
  constexpr int compress_ratio = 2;

  for (int kp_small_idx = 0; kp_small_idx < big_grid_occ_.size(); ++kp_small_idx)
  {
    const cv::KeyPoint &key_pnt_small = big_grid_occ_[kp_small_idx];
    if (key_pnt_small.class_id != -1 || key_pnt_small.response == 0) // old track point in raw img; or empty
      continue;
    local_kps.clear();
    local_kps.reserve(compress_ratio * 2 * compress_ratio * 2);
    for (int y = key_pnt_small.pt.y * compress_ratio - compress_ratio + 1;
         y < key_pnt_small.pt.y * compress_ratio + compress_ratio; y++)
    {
      for (int x = key_pnt_small.pt.x * compress_ratio - compress_ratio + 1;
           x < key_pnt_small.pt.x * compress_ratio + compress_ratio; x++)
      {
        cv::KeyPoint local_kp = key_pnt_small;
        local_kp.pt.x = x;
        local_kp.pt.y = y;
        local_kps.push_back(local_kp);
      }
    }

    assert(local_kps.size() > 0);

    // 有可能小图上是特征点大图上旧不就不是了
    minEigenVal(img, &local_kps, harris_block_size);//TODO:(cy) 会越界
    float score_total = 0;
    float x_weighted_sum = 0;
    float y_weighted_sum = 0;
    float highest_score = -std::numeric_limits<float>::max();
    int best_local_kp_id = -1;
    for (size_t i = 0; i < local_kps.size(); i++)
    {
      if (local_kps[i].response > 0)
      {
        // ignore points whose harris response is less than 0
        score_total += local_kps[i].response;
        x_weighted_sum += local_kps[i].pt.x * local_kps[i].response;
        y_weighted_sum += local_kps[i].pt.y * local_kps[i].response;
        if (local_kps[i].response > highest_score)
        {
          highest_score = local_kps[i].response;
          best_local_kp_id = i;
        }
      }
#ifndef __FEATURE_UTILS_NO_DEBUG__
      // VLOG(3) << "local_kp.response " << local_kps[i].response
      //         << " local_kp.pt " << local_kps[i].pt
      //         << " score_total " << score_total;
#endif
    }
    if (best_local_kp_id < 0)
    {
      // no good point,remove
      big_grid_occ_[kp_small_idx].response = 0;
      continue;
    }
    //?使用响应的质心是为了获得亚像素，可是真的该这么去使用么？还是说因为只是3*3所以可以这么玩？
    cv::KeyPoint best_local_kp = local_kps[best_local_kp_id]; // copy scale score etc.
    // use weighted average
    if (highest_score > 1e-9)
    {
      best_local_kp.pt.x = round(x_weighted_sum / score_total);
      best_local_kp.pt.y = round(y_weighted_sum / score_total);
      best_local_kp.class_id = id_generator_.get();
#ifndef __FEATURE_UTILS_NO_DEBUG__
      // VLOG(3) << "refine best_local_kp for kp_small[" << kp_small_idx
      //         << "]: pt = " << best_local_kp.pt;
#endif
      big_grid_occ_[kp_small_idx] = best_local_kp;
      t_key_pnts_ptr.push_back(best_local_kp);
      refineNewPointNum++;
    }
    else
    {
      assert(0);
#ifndef __FEATURE_UTILS_NO_DEBUG__
      // VLOG(3) << "refine best_local_kp for kp_small[" << kp_small_idx
      //         << "] fails: weak harris response = " << highest_score;
#endif
    }
  }
  // std::cout<<"refineNewPointNum "<<refineNewPointNum<<std::endl;
}
void FeatureDetector::DetectNewPts(const cv::Mat &img, const cv::Mat &div_1, const std::vector<cv::KeyPoint> &old_pts, std::vector<cv::KeyPoint> &new_pts)
{
  IMGUtility::drawGrid(big_grid_occ_,big_grid_rows_,big_grid_cols_, "big_grid_occ_",1);

  // select grid to detect
  int sub = 0;
  std::vector<std::pair<int, std::vector<int>>> detect_big_small_sub;
  detect_big_small_sub.reserve(big_grid_occ_.size());
  for (size_t r = 0; r < big_grid_rows_; r++)
  {
    for (size_t c = 0; c < big_grid_cols_; c++)
    {
      if (big_grid_occ_[sub].response == 0)
      {
        int x = c * big_g_c_size_;
        int y = r * big_g_r_size_;

        cv::Mat cov = cv::Mat(big_g_r_size_, big_g_c_size_, CV_32FC3); // 这部分必须是要开辟出来数组的
        calCov(div_1, x, y, big_g_c_size_, big_g_r_size_, cov);
        cv::Mat min_eigen_mat;
        min_eigen_mat.create(cov.size(), CV_32FC1);
        calcMinEigenVal(cov, min_eigen_mat); // TODO(cy):可以直接在这里得到最小值,这样能省略下面这一大堆的计算

        double min, max;
        cv::Point2i min_p, max_p;
        std::vector<int> detect_small_sub;
        detect_small_sub.reserve(BIG_SMALL_RATE_ROW * BIG_SMALL_RATE_COL);
        for (size_t row = 0; row < BIG_SMALL_RATE_ROW; row++)
        {
          int grid_start_y = row * small_g_r_size_;
          for (size_t col = 0; col < BIG_SMALL_RATE_COL; col++)
          {
            int grid_start_x = col * small_g_c_size_;
            cv::Mat s_grid = min_eigen_mat(cv::Rect(grid_start_x, grid_start_y, small_g_c_size_, small_g_r_size_));
            cv::minMaxLoc(s_grid, &min, &max, &min_p, &max_p);

            int small_grid_sub = (r * BIG_SMALL_RATE_ROW + row + 1) * small_grid_cols_ + c * BIG_SMALL_RATE_COL + col + 1; // TODO(cy): 直接计算好关系，直接拿来用就可以了

            cv::Point2f p(max_p.x + x + grid_start_x, max_p.y + y + grid_start_y);
            if (p.x <= 8 || p.x >= img.cols - 8 || p.y <= 8 || p.y >= img.rows - 8)
              continue;

            small_grid_occ_[small_grid_sub].pt = p;
            small_grid_occ_[small_grid_sub].response = max;
            detect_small_sub.push_back(small_grid_sub);

          }
        }
        detect_big_small_sub.push_back(std::make_pair(sub, detect_small_sub));
      }
      sub++;
    }
  }

  IMGUtility::drawGrid(small_grid_occ_,small_grid_rows_,small_grid_cols_, "small_grid_occ_",1);

  putSmallToBigGrid(detect_big_small_sub);

  refine_kp_in_larger_img(img, new_pts); // only append new point in key_pnts
}

void FeatureDetector::putSmallToBigGrid(const std::vector<std::pair<int, std::vector<int>>> &detect_big_small_sub)
{

  // 直接将小点放进大grid中
  int put_in_big_num = 0;
  bool big33;
  for (size_t i = 0; i < detect_big_small_sub.size(); i++)
  {
    int big_sub = detect_big_small_sub[i].first;
    const std::vector<int> &small_subs = detect_big_small_sub[i].second;
    int small_sub = 0;
    for (size_t j = 0; j < small_subs.size(); j++)
    {
      big33 = true;
      small_sub = small_subs[j];
      float response = small_grid_occ_[small_sub].response;
      for (size_t k = 0; k < 8; k++) // 小grid中8邻域最大值
      {  const cv::KeyPoint& s_nerb = small_grid_occ_[small_sub + small_neib[k]];
        if (response <= s_nerb.response || s_nerb.class_id != -1) // small grid添加了1的边界，所以不需要判断越界的问题
        {
          big33 = false;
          break;
        }
      }
      if (big33 && response > big_grid_occ_[big_sub].response) // 最值，且比大grid中原本的还大
      {
        big_grid_occ_[big_sub] = small_grid_occ_[small_sub];
        put_in_big_num++;

      }
    }
  }
  // std::cout<<"put_in_big_num "<<put_in_big_num<<std::endl;
}