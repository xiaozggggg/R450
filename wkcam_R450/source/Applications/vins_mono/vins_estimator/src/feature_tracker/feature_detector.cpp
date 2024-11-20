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

  big_grid_occ_.resize(big_grid_rows_ * big_grid_cols_, 0);
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

void FeatureDetector::ClearGrid(std::vector<uchar> &grid_occ_)
{
  for (size_t i = 0; i < grid_occ_.size(); i++)
  {
    grid_occ_[i] = 0;
  }
}

void FeatureDetector::PutOldPtsInGrid(const std::vector<cv::KeyPoint> &old_pts, std::vector<uchar>& status)
{
  ClearGrid(big_grid_occ_);
  ClearGrid(small_grid_occ_);
  status.resize(old_pts.size(), 1);
  for (size_t i = 0; i < old_pts.size(); i++)
  {

    int br = old_pts[i].pt.y / (big_g_r_size_ * (1 << DETECT_LEVEL));
    int bc = old_pts[i].pt.x / (big_g_c_size_ * (1 << DETECT_LEVEL));
    int bsub = br * big_grid_cols_ + bc;

    big_grid_occ_[bsub] = 1;

    int sr = old_pts[i].pt.y / (small_g_r_size_ * (1 << DETECT_LEVEL)) + 1; // border
    int sc = old_pts[i].pt.x / (small_g_c_size_ * (1 << DETECT_LEVEL)) + 1;
    int ssub = sr * small_grid_cols_ + sc;

    if(old_pts[i].response > small_grid_occ_[ssub].response)
    {
      //old point
      if(small_grid_occ_[ssub].response != 0)
        status[small_grid_occ_[ssub].angle] = 0;

      small_grid_occ_[ssub] = old_pts[i];
      small_grid_occ_[ssub].angle = i;//所有点记录下标
    }
    else
      status[i] = 0;
  }
}

void calCov(const cv::Mat &div, cv::Mat &cov, int block_size = 3)
{
  cv::Size size = div.size();
  int i, j;

  for (i = 0; i < size.height; i++)
  {
    float *cov_data = cov.ptr<float>(i);
    const int16_t *divdata = div.ptr<int16_t>(i);
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
//验证过数值与上面的相同
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

#ifndef CV_SSE2
  // this function only handles block size 7 & 8
    static inline void accumulate_matrix_coeff(const uint8x16_t* top_row,
                                 const uint8x16_t* mid_row,
                                 const uint8x16_t* bot_row,
                                 const int block_size,
                                 int32x4_t* a,
                                 int32x4_t* b,
                                 int32x4_t* c) {
      union {
        int16x8_t ix;
        int16_t ixc[8];
      } __attribute__((aligned(16)));
      union {
        int16x8_t iy;
        int16_t iyc[8];
      } __attribute__((aligned(16)));
      int16x8_t diff0 = vreinterpretq_s16_u16(vsubl_u8(vget_low_u8(*bot_row),
                                                       vget_low_u8(*top_row)));
      int16x8_t diff1 = vreinterpretq_s16_u16(
                      vsubl_u8(vget_low_u8(vextq_u8(*bot_row, vdupq_n_u8(0), 1)),
                      vget_low_u8(vextq_u8(*top_row, vdupq_n_u8(0), 1))));
      int16x8_t diff2 = vreinterpretq_s16_u16(
                      vsubl_u8(vget_low_u8(vextq_u8(*bot_row, vdupq_n_u8(0), 2)),
                      vget_low_u8(vextq_u8(*top_row, vdupq_n_u8(0), 2))));

      iy = vaddq_s16(vaddq_s16(diff0, diff2), vmulq_n_s16(diff1, 2));

      diff0 = vreinterpretq_s16_u16(vsubl_u8(vget_low_u8(vextq_u8(*top_row, vdupq_n_u8(0), 2)),
                               vget_low_u8(*top_row)));
      diff1 = vreinterpretq_s16_u16(vsubl_u8(vget_low_u8(vextq_u8(*mid_row, vdupq_n_u8(0), 2)),
                               vget_low_u8(*mid_row)));
      diff2 = vreinterpretq_s16_u16(vsubl_u8(vget_low_u8(vextq_u8(*bot_row, vdupq_n_u8(0), 2)),
                               vget_low_u8(*bot_row)));

      ix = vaddq_s16(vmulq_n_s16(diff1, 2), vaddq_s16(diff0, diff2));
      // set the last lane to zero
      if (__builtin_expect(block_size == 7, 1)) {
        ixc[7] = 0;
        iyc[7] = 0;
      }
      *a = vaddq_s32(vaddq_s32(vmull_s16(vget_low_s16(ix), vget_low_s16(ix)),
                               vmull_s16(vget_high_s16(ix), vget_high_s16(ix))), *a);
      *b = vaddq_s32(vaddq_s32(vmull_s16(vget_low_s16(iy), vget_low_s16(iy)),
                               vmull_s16(vget_high_s16(iy), vget_high_s16(iy))), *b);
      *c = vaddq_s32(vaddq_s32(vmull_s16(vget_low_s16(ix), vget_low_s16(iy)),
                               vmull_s16(vget_high_s16(ix), vget_high_s16(iy))), *c);
    }


    // [NOTE] This function does NOT check boundary condition when computing harris response!
    // [NOTE] This function only handles block size 7, 8 and 9.
    static void HarrisResponses_neon(const cv::Mat& img,
                                     int blockSize,
                                     float harris_k,
                                     vector<KeyPoint>* pts) {
      CV_Assert(img.type() == CV_8UC1 && blockSize * blockSize <= 2048);
      CV_Assert(blockSize == 7 || blockSize == 8 || blockSize == 9);
      uint8x16_t raw_buffer[3] __attribute__((aligned(16)));
      size_t ptidx, ptsize = pts->size();

      const uchar* ptr00 = img.ptr<uchar>();
      int step = static_cast<int>(img.step / img.elemSize1());
      int r = blockSize / 2;

      float scale = (1 << 2) * blockSize * 255.0f;
      scale = 1.0f / scale;
      float scale_sq_sq = scale * scale * scale * scale;

      uint8x16_t* row_top = &raw_buffer[0];
      uint8x16_t* row_mid = &raw_buffer[1];
      uint8x16_t* row_bot = &raw_buffer[2];
      uint8x16_t* tmp_ptr = NULL;

      for (ptidx = 0; ptidx < ptsize; ptidx++) {
        int a = 0, b = 0, c = 0;
        int x0 = cvRound((*pts)[ptidx].pt.x - r);
        int y0 = cvRound((*pts)[ptidx].pt.y - r);
        const uchar* ptr0 = ptr00 + y0 * step + x0;
        *row_mid = vld1q_u8(ptr0 - step - 1);  // top row
        *row_bot = vld1q_u8(ptr0 - 1);  // middle row

        int32x4_t va __attribute__((aligned(16))) = vmovq_n_s32(0);
        int32x4_t vb __attribute__((aligned(16))) = vmovq_n_s32(0);
        int32x4_t vc __attribute__((aligned(16))) = vmovq_n_s32(0);
        for (int k = 0; k < blockSize; k++, ptr0 += step) {
          // shifting
          tmp_ptr = row_top;
          row_top = row_mid;
          row_mid = row_bot;
          row_bot = tmp_ptr;
          *row_bot = vld1q_u8(ptr0 + step - 1);  // bottom row
          accumulate_matrix_coeff(row_top, row_mid, row_bot, blockSize,
                                  &va, &vb, &vc);
          if (blockSize == 9) {
            const uchar* rtop_ptr = reinterpret_cast<const uchar*>(row_top);
            const uchar* rmid_ptr = reinterpret_cast<const uchar*>(row_mid);
            const uchar* rbot_ptr = reinterpret_cast<const uchar*>(row_bot);
            int ix = (rmid_ptr[10] - rmid_ptr[8]) * 2 +
                     (rtop_ptr[10] - rtop_ptr[8]) +
                     (rbot_ptr[10] - rbot_ptr[8]);
            int iy = (rbot_ptr[9] - rtop_ptr[9]) * 2 +
                     (rbot_ptr[8] - rtop_ptr[8]) +
                     (rbot_ptr[10] - rtop_ptr[10]);
            a += ix * ix;
            b += iy * iy;
            c += ix * iy;
          }
        }
        a += (vgetq_lane_s32(va, 0) + vgetq_lane_s32(va, 1) +
              vgetq_lane_s32(va, 2) + vgetq_lane_s32(va, 3));
        b += (vgetq_lane_s32(vb, 0) + vgetq_lane_s32(vb, 1) +
              vgetq_lane_s32(vb, 2) + vgetq_lane_s32(vb, 3));
        c += (vgetq_lane_s32(vc, 0) + vgetq_lane_s32(vc, 1) +
              vgetq_lane_s32(vc, 2) + vgetq_lane_s32(vc, 3));
        (*pts)[ptidx].response = (static_cast<float>(a) * b - static_cast<float>(c) * c -
          harris_k * (static_cast<float>(a) + b) * (static_cast<float>(a) + b)) * scale_sq_sq;
      }
    }
#endif

void HarrisResponses(const cv::Mat &img,
                     int blockSize,
                     float harris_k,
                     std::vector<cv::KeyPoint> *pts)
{
#ifndef CV_SSE2
  return HarrisResponses_neon(img, blockSize, harris_k, pts);
#endif
  CV_Assert(img.type() == CV_8UC1 && blockSize * blockSize <= 2048);

  size_t ptidx, ptsize = pts->size();

  const uchar* ptr00 = img.ptr<uchar>();
  int step = static_cast<int>(img.step / img.elemSize1());
  int r = blockSize / 2;

  float scale = (1 << 2) * blockSize * 255.0f;
  scale = 1.0f / scale;
  float scale_sq_sq = scale * scale * scale * scale;

  cv::AutoBuffer<int> ofsbuf(blockSize*blockSize);
  int* ofs = ofsbuf;
  for (int i = 0; i < blockSize; i++ )
    for (int j = 0; j < blockSize; j++ )
      ofs[i * blockSize + j] = static_cast<int>(i * step + j);

  for (ptidx = 0; ptidx < ptsize; ptidx++) {
    int x0 = cvRound((*pts)[ptidx].pt.x - r);
    int y0 = cvRound((*pts)[ptidx].pt.y - r);

    const uchar* ptr0 = ptr00 + y0 * step + x0;
    int a = 0, b = 0, c = 0;

    for (int k = 0; k < blockSize * blockSize; k++) {
      const uchar* ptr = ptr0 + ofs[k];
      int Ix = (ptr[1] - ptr[-1]) * 2 + (ptr[-step + 1] - ptr[-step - 1])
          + (ptr[step + 1] - ptr[step - 1]);
      int Iy = (ptr[step] - ptr[-step]) * 2 + (ptr[step - 1]
          - ptr[-step - 1]) + (ptr[step + 1] - ptr[-step + 1]);
      a += Ix * Ix;
      b += Iy * Iy;
      c += Ix * Iy;
    }
    (*pts)[ptidx].response = (static_cast<float>(a) * b - static_cast<float>(c) * c -
        harris_k * (static_cast<float>(a) + b) * (static_cast<float>(a) + b)) * scale_sq_sq;
  }
}


void FeatureDetector::refine_kp_in_larger_img(const cv::Mat &img, const std::vector<cv::KeyPoint> &smallPs, std::vector<cv::KeyPoint> &bigPs)
{
  int refineNewPointNum = 0;
  std::vector<cv::KeyPoint> local_kps;
  constexpr int harris_block_size = 7; // 5 does not give correct results
  constexpr int compress_ratio = 2;

  for (int kp_small_idx = 0; kp_small_idx < smallPs.size(); ++kp_small_idx)
  {
    const cv::KeyPoint &key_pnt_small = smallPs[kp_small_idx];
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

        HarrisResponses(img, 7, 0.04f, &local_kps);
    // minEigenVal(img, &local_kps, harris_block_size);//TODO:(cy) 会越界，且计算不对感觉
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
    }

    if (best_local_kp_id < 0)
      continue;


    cv::KeyPoint best_local_kp = local_kps[best_local_kp_id]; // copy scale score etc.
    // use weighted average
    if (highest_score > 1e-9)
    {
      best_local_kp.pt.x = round(x_weighted_sum / score_total);
      best_local_kp.pt.y = round(y_weighted_sum / score_total);
      best_local_kp.class_id = id_generator_.get();

      best_local_kp.response = key_pnt_small.response;//细化之后的response没必要记录，因为还要用来和检测时候的response进行比较
      bigPs.push_back(best_local_kp);
      refineNewPointNum++;
    }

  }
  // std::cout<<"refineNewPointNum "<<refineNewPointNum<<std::endl;
}

//比下面的更快，但是结果貌似有点儿不太对
void FeatureDetector::DetectNewPts(const cv::Mat& img, const cv::Mat& div_1, const std::vector<cv::KeyPoint> &old_pts, std::vector<cv::KeyPoint> &new_pts, int num)
{
  
  // select grid to detect
  int sub = 0;
  std::vector<int> detect_s_g_r;
  for (size_t br = 0; br < big_grid_rows_; br++)
  {
    for (size_t bc = 0; bc < big_grid_cols_; bc++)
    {
      if (!big_grid_occ_[sub])
      {
        int x = bc * big_g_c_size_;
        int y = br * big_g_r_size_;

        cv::Mat cov = cv::Mat(big_g_r_size_, big_g_c_size_, CV_32FC3); // 这部分必须是要开辟出来数组的
        calCov(div_1, x, y, big_g_c_size_, big_g_r_size_, cov);

        cv::Mat min_eigen_mat;
        min_eigen_mat.create(cov.size(), CV_32FC1);
        calcMinEigenVal(cov, min_eigen_mat); // TODO(cy):可以直接在这里得到最小值,这样能省略下面这一大堆的计算

        double min, max;
        cv::Point2i min_p, max_p;
        std::vector<int> detect_small_sub;
        detect_small_sub.reserve(BIG_SMALL_RATE_ROW * BIG_SMALL_RATE_COL);
        for (size_t sr = 0; sr < BIG_SMALL_RATE_ROW; sr++)
        {
          int grid_start_y = sr * small_g_r_size_;
          for (size_t sc = 0; sc < BIG_SMALL_RATE_COL; sc++)
          {
            int grid_start_x = sc * small_g_c_size_;
            cv::Mat s_grid = min_eigen_mat(cv::Rect( grid_start_x, grid_start_y, small_g_c_size_, small_g_r_size_));
            cv::minMaxLoc(s_grid, &min, &max, &min_p, &max_p);

            int small_grid_sub = (br * BIG_SMALL_RATE_ROW + sr + 1) * small_grid_cols_ + bc * BIG_SMALL_RATE_COL + sc + 1; // TODO(cy): 直接计算好关系，直接拿来用就可以了

            cv::Point2f p(max_p.x + x + grid_start_x, max_p.y + y + grid_start_y);
            if (p.x <= 8 || p.x >= div_1.cols - 8 || p.y <= 8 || p.y >= div_1.rows - 8)
              continue;

            small_grid_occ_[small_grid_sub].pt = p;
            small_grid_occ_[small_grid_sub].response = max;
            detect_s_g_r.push_back(small_grid_sub);

          }
        }

      }
      sub++;
    }
  }

  // IMGUtility::drawGrid(small_grid_occ_, small_grid_rows_, small_grid_cols_, "small_grid_occ_", 1);

  std::vector<cv::KeyPoint> big33Pts;
  SmallGridMaxFillter(detect_s_g_r, big33Pts);

  std::sort(big33Pts.begin(), big33Pts.end(), [](const cv::KeyPoint &p1, const cv::KeyPoint &p2)
            { return p1.response > p2.response; });

  if(big33Pts.size() > num)
    big33Pts.resize(num);

  refine_kp_in_larger_img(img, big33Pts, new_pts); // only append new point in key_pnts
}

void putOldPtsBack(cv::Mat& eig, const std::vector<cv::KeyPoint> &old_pts)
{
  for (size_t i = 0; i < old_pts.size(); i++)
  {
    int x = old_pts[i].pt.x /2;
    int y = old_pts[i].pt.y /2;
    eig.at<float>(y,x) = __FLT_MAX__;
  }
  
}

void FeatureDetector::DetectNewPts(const std::vector<cv::Mat>& pyr, const std::vector<cv::KeyPoint> &old_pts, std::vector<cv::KeyPoint> &new_pts, int num)
{
  // IMGUtility::drawGrid(big_grid_occ_,big_grid_rows_,big_grid_cols_, "big_grid_occ_",1);

  cv::Mat min_eigen_mat;
  cv::cornerMinEigenVal(pyr[1], min_eigen_mat, 3, 3);
  putOldPtsBack(min_eigen_mat, old_pts);//TODO(cy):记录下标，可以跳过不计算

  // cv::Mat eigNorm;
  // cv::normalize(min_eigen_mat, eigNorm, 0, 255, cv::NORM_MINMAX);
  // cv::Mat eigDisplay;
  // eigNorm.convertTo(eigDisplay, CV_8U);

  
  // select grid to detect
  int sub = 0;
  std::vector<int> detect_s_g_r;
  for (size_t br = 0; br < big_grid_rows_; br++)
  {
    for (size_t bc = 0; bc < big_grid_cols_; bc++)
    {
      if (!big_grid_occ_[sub])
      {
        int x = bc * big_g_c_size_;
        int y = br * big_g_r_size_;

        double min, max;
        cv::Point2i min_p, max_p;
        std::vector<int> detect_small_sub;
        detect_small_sub.reserve(BIG_SMALL_RATE_ROW * BIG_SMALL_RATE_COL);
        for (size_t sr = 0; sr < BIG_SMALL_RATE_ROW; sr++)
        {
          int grid_start_y = sr * small_g_r_size_;
          for (size_t sc = 0; sc < BIG_SMALL_RATE_COL; sc++)
          {
            int grid_start_x = sc * small_g_c_size_;
            cv::Mat s_grid = min_eigen_mat(cv::Rect(x + grid_start_x, y + grid_start_y, small_g_c_size_, small_g_r_size_));
            cv::minMaxLoc(s_grid, &min, &max, &min_p, &max_p);

            int small_grid_sub = (br * BIG_SMALL_RATE_ROW + sr + 1) * small_grid_cols_ + bc * BIG_SMALL_RATE_COL + sc + 1; // TODO(cy): 直接计算好关系，直接拿来用就可以了

            cv::Point2f p(max_p.x + x + grid_start_x, max_p.y + y + grid_start_y);
            if (p.x <= 8 || p.x >= pyr[1].cols - 8 || p.y <= 8 || p.y >= pyr[1].rows - 8)
              continue;

            small_grid_occ_[small_grid_sub].pt = p;
            small_grid_occ_[small_grid_sub].response = max;
            detect_s_g_r.push_back(small_grid_sub);

          }
        }

      }
      sub++;
    }
  }

  // IMGUtility::drawGrid(small_grid_occ_, small_grid_rows_, small_grid_cols_, "small_grid_occ_", 1);

  std::vector<cv::KeyPoint> big33Pts;
  SmallGridMaxFillter(detect_s_g_r, big33Pts);

  std::sort(big33Pts.begin(), big33Pts.end(), [](const cv::KeyPoint &p1, const cv::KeyPoint &p2)
            { return p1.response > p2.response; });

  if(big33Pts.size() > num)
    big33Pts.resize(num);

  // for (size_t i = 0; i < big33Pts.size(); i++)
  //   cv::circle(eigDisplay, big33Pts[i].pt, 5, cv::Scalar(128), 1);
  // IMGUtility::showImg(eigDisplay, "eigDisplay");

  refine_kp_in_larger_img(pyr[0], big33Pts, new_pts); // only append new point in key_pnts
}

// void FeatureDetector::putSmallToBigGrid(const std::vector<std::pair<int, std::vector<int>>> &detect_big_small_sub)
// {

//   // 直接将小点放进大grid中
//   int put_in_big_num = 0;
//   bool big33;
//   for (size_t i = 0; i < detect_big_small_sub.size(); i++)
//   {
//     int big_sub = detect_big_small_sub[i].first;
//     const std::vector<int> &small_subs = detect_big_small_sub[i].second;
//     int small_sub = 0;
//     for (size_t j = 0; j < small_subs.size(); j++)
//     {
//       big33 = true;
//       small_sub = small_subs[j];
//       float response = small_grid_occ_[small_sub].response;
//       for (size_t k = 0; k < 8; k++) // 小grid中8邻域最大值
//       {  const cv::KeyPoint& s_nerb = small_grid_occ_[small_sub + small_neib[k]];
//         if (response <= s_nerb.response || s_nerb.class_id != -1) // small grid添加了1的边界，所以不需要判断越界的问题
//         {
//           big33 = false;
//           break;
//         }
//       }
//       if (big33 && response > big_grid_occ_[big_sub].response) // 最值，且比大grid中原本的还大
//       {
//         big_grid_occ_[big_sub] = small_grid_occ_[small_sub];
//         put_in_big_num++;

//       }
//     }
//   }
//   // std::cout<<"put_in_big_num "<<put_in_big_num<<std::endl;
// }

void FeatureDetector::SmallGridMaxFillter(const std::vector<int>& detect_s_g_r, std::vector<cv::KeyPoint>& big33Pts)
{

  int put_in_big_num = 0;
  bool big33;

  int small_sub = 0;
  for (size_t j = 0; j < detect_s_g_r.size(); j++)
  {
    big33 = true;
    small_sub = detect_s_g_r[j];
    float response = small_grid_occ_[small_sub].response;
    for (size_t k = 0; k < 8; k++) // 小grid中8邻域最大值
    {
      const cv::KeyPoint &s_nerb = small_grid_occ_[small_sub + small_neib[k]];
      if (response <= s_nerb.response || s_nerb.class_id != -1) // small grid添加了1的边界，所以不需要判断越界的问题
      {
        big33 = false;
        break;
      }
    }
    if (big33 && response != __FLT_MAX__) // 最值，且比大grid中原本的还大
    {
      big33Pts.push_back(small_grid_occ_[small_sub]);
    }
  }

  // std::cout<<"put_in_big_num "<<put_in_big_num<<std::endl;
}