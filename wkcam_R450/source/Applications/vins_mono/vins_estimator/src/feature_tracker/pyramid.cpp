#include "pyramid.h"
#include "utility.hpp"

Pyramid::Pyramid(cv::Size img_size, int track_lvl, int detect_lvl)
{
  img_size_ = img_size;
  detect_level_ = detect_lvl;
  track_level_ = track_lvl;
  assert(track_lvl == 0 || track_lvl == 1);

  // Allocated buffer for pyramids
  const int size = img_size.width * img_size.height;
  int img_pyr_size = int(size * 1.4 + 3) & ~3;
  prev_img_pyramids_buffer_ = std::shared_ptr<uchar>(
      new uchar[img_pyr_size]); // 1+1/4+1/16+1/64约等于1.4 后面部分是向上取整成4的倍数，对齐内存
  curr_img_pyramids_buffer_ = std::shared_ptr<uchar>(
      new uchar[img_pyr_size]);

  // gradient x y ,int16
  int div_pyr_size = int(size * 0.4 * 2 * 2 + 3) & ~3;
  if (track_level_ == 0)
    div_pyr_size = int(size * 1.4 * 2 * 2 + 3) & ~3;
  prev_div_pyramids_buffer_ = std::shared_ptr<int16_t>(
      new int16_t[div_pyr_size]); // 金字塔0层不需要计算,双通道，int16_t俩字节
  curr_div_pyramids_buffer_ = std::shared_ptr<int16_t>(
      new int16_t[div_pyr_size]);

  if (prev_img_pyramids_buffer_ == nullptr ||
      curr_img_pyramids_buffer_ == nullptr ||
      prev_div_pyramids_buffer_ == nullptr ||
      curr_div_pyramids_buffer_ == nullptr)
  {
    std::cout << "Allocat buffer for pyramids failed.";
    assert(0);
  }

  // init image
  prev_img_pyramids_.resize(MaxPyraLevel + 1);
  curr_img_pyramids_.resize(MaxPyraLevel + 1);
  prev_div_pyramids_.resize(MaxPyraLevel + 1); // level 0 would be null
  curr_div_pyramids_.resize(MaxPyraLevel + 1);

  // pyr buffer offset
  int img_off_set = 0;
  int div_off_set = 0;

  for (size_t i = 0; i <= MaxPyraLevel; i++)
  {

    // img
    if (i == 0)
    {
      prev_img_pyramids_[i] = cv::Mat(img_size, CV_8UC1, prev_img_pyramids_buffer_.get());
      curr_img_pyramids_[i] = cv::Mat(img_size, CV_8UC1, curr_img_pyramids_buffer_.get());

      if (track_level_ == 0)
      {
        prev_div_pyramids_[i] = cv::Mat(img_size, CV_16SC2, prev_div_pyramids_buffer_.get());
        curr_div_pyramids_[i] = cv::Mat(img_size, CV_16SC2, curr_div_pyramids_buffer_.get());
      }
    }
    else
    {
      img_off_set += size >> (i - 1) * 2;
      prev_img_pyramids_[i] = cv::Mat(img_size.height >> i, img_size.width >> i, CV_8UC1, prev_img_pyramids_buffer_.get() + img_off_set);
      curr_img_pyramids_[i] = cv::Mat(img_size.height >> i, img_size.width >> i, CV_8UC1, curr_img_pyramids_buffer_.get() + img_off_set);
      std::cout << "img_off_set i " << i << " " << img_off_set << std::endl;
      std::cout << "curr_img_pyramids_[i] size " << curr_img_pyramids_[i].size().height << " " << curr_img_pyramids_[i].size().width << std::endl;
      // div
      if (i == 1 && track_level_ != 0)
        div_off_set = 0;
      else
        div_off_set += 2 * 2 * (size >> ((i - 1) * 2));

      std::cout << "div_off_set i " << i << " " << div_off_set << std::endl;
      
      prev_div_pyramids_[i] = cv::Mat(img_size.height >> i, img_size.width >> i, CV_16SC2, prev_div_pyramids_buffer_.get() + div_off_set);
      curr_div_pyramids_[i] = cv::Mat(img_size.height >> i, img_size.width >> i, CV_16SC2, curr_div_pyramids_buffer_.get() + div_off_set);
    }
  }
}

Pyramid::~Pyramid()
{
}

void Pyramid::update_img_pyramids()
{
  curr_img_pyramids_.swap(prev_img_pyramids_);
  curr_div_pyramids_.swap(prev_div_pyramids_);
  curr_img_pyramids_buffer_.swap(prev_img_pyramids_buffer_);
  curr_div_pyramids_buffer_.swap(prev_div_pyramids_buffer_);

}
// 因为后面的参数想用默认参数，所以使用指针不用引用
void Pyramid::build_pyramids(const cv::Mat *left_img, const cv::Mat *right_img)
{

  build_pyr(left_img, curr_img_pyramids_, curr_div_pyramids_);

  // todo(CY): build right img pyr; maybe all the pyr valueable should be array
  //  if(right_img)
  //  build_pyr(right_img, right_curr_img_pyramids_, right_curr_div_pyramids_);
}

void Pyramid::build_pyr(const cv::Mat *img, std::vector<cv::Mat> &img_pyr, std::vector<cv::Mat> &div_pyr)
{
  for (size_t i = 0; i <= MaxPyraLevel; i++)
  {
    if (i == 0)
    {
      // copy
      img_pyr[i] = img->clone(); // TODO(cy): 图像数据产生的时候已经拷贝到储存中一次了，这里又要拷贝到指定的地址上面；因该直接数据i产生的时候就直接把数据拷贝到金字塔第一层的地址那里，省去一次拷贝
      if(track_level_ == 0)
        calcSharrDeriv(img_pyr[i], div_pyr[i]);
    }
    else
    {
      // cal
      // build left img pyr
      fast_pyra_down_internal(img_pyr[i - 1], img_pyr[i]);
      // TODO(cy): need to set hyper para track and detect level
      // build deriv img; do not cal level 0, so in op flow ont track level 0
      calcSharrDeriv(img_pyr[i], div_pyr[i]);
    }
  }
}

#ifdef CV_SSE2
/******************************************************************************
 * fast_pyra_down_internal       This interface should not used directly
 * @param[in]   img_in_smooth    input image
 * @param[out]  _img_in_small    output image, the memory of _img_in_small must
 *                               be pre-allocated before calling this function
 */
void Pyramid::fast_pyra_down_internal(const cv::Mat &img_in_smooth, cv::Mat &img_in_small)
{
  // CHECK_NOTNULL(_img_in_small);
  // CHECK_NOTNULL(_img_in_small.data);
  // CHECK_EQ(img_in_smooth.type(), CV_8U);
  // CHECK_EQ(img_in_smooth.rows & 1, 0);
  // CHECK_EQ(img_in_smooth.cols & 3, 0);

  // use our own pyra down for faster performance
  const int width_step_in = img_in_smooth.step1();
  int sum0, sum1, sum2, sum3;
  const uchar *data0_ptr = img_in_smooth.data;
  const uchar *data1_ptr = img_in_smooth.data + width_step_in;
  uchar *target_data_ptr = img_in_small.data;

  for (int rows = img_in_small.rows, y = 0; y < rows; ++y)
  {
    int x = 0;
    for (int cols = img_in_small.cols & ~3; x < cols; x += 4, target_data_ptr += 4)
    {
      sum0 = ((static_cast<int>(*data0_ptr) + static_cast<int>(*(data0_ptr + 1))) +
              (static_cast<int>(*data1_ptr) + static_cast<int>(*(data1_ptr + 1)))) /
             4;
      sum1 = ((static_cast<int>(*(data0_ptr + 2)) + static_cast<int>(*(data0_ptr + 3))) +
              (static_cast<int>(*(data1_ptr + 2)) + static_cast<int>(*(data1_ptr + 3)))) /
             4;
      sum2 = ((static_cast<int>(*(data0_ptr + 4)) + static_cast<int>(*(data0_ptr + 5))) +
              (static_cast<int>(*(data1_ptr + 4)) + static_cast<int>(*(data1_ptr + 5)))) /
             4;
      sum3 = ((static_cast<int>(*(data0_ptr + 6)) + static_cast<int>(*(data0_ptr + 7))) +
              (static_cast<int>(*(data1_ptr + 6)) + static_cast<int>(*(data1_ptr + 7)))) /
             4;

      *(target_data_ptr) = static_cast<uchar>(sum0);
      *(target_data_ptr + 1) = static_cast<uchar>(sum1);
      *(target_data_ptr + 2) = static_cast<uchar>(sum2);
      *(target_data_ptr + 3) = static_cast<uchar>(sum3);
      data0_ptr += 8;
      data1_ptr += 8;
    }
    for (; x < img_in_small.cols; ++x)
    {
      int sum = ((static_cast<int>(*data0_ptr) + static_cast<int>(*(data0_ptr + 1))) +
                 (static_cast<int>(*data1_ptr) + static_cast<int>(*(data1_ptr + 1)))) /
                4;
      *target_data_ptr++ = static_cast<uchar>(sum);
      data0_ptr += 2;
      data1_ptr += 2;
    }
    data0_ptr += width_step_in;
    data1_ptr += width_step_in;
  }
}
#else
inline void fast_pyra_down_internal(const cv::Mat &img_in_smooth, cv::Mat& img_in_small)
{
  CHECK_NOTNULL(_img_in_small);
  CHECK_NOTNULL(_img_in_small->data);
  CHECK_EQ(img_in_smooth.type(), CV_8U);
  CHECK_EQ(img_in_smooth.rows & 1, 0);


  // use our own pyra down for faster performance
  const int width_step_in = img_in_smooth.step1();
  const int width_step_small = img_in_small.step1();
  uchar *target_data_ptr = img_in_small.data;
  uchar *data0_ptr = img_in_smooth.data;
  uchar *data1_ptr = img_in_smooth.data + width_step_in;

  // provide hits to gcc for optimization
  const int cols = img_in_small.cols - 8;
  for (int rows = img_in_small.rows, y = 0; y < rows; ++y)
  {
    int x = 0;
    for (; x <= cols; x += 8, target_data_ptr += 8)
    {
      // loading 32 pixels per row from source image
      uint8x8x2_t row0 = vld2_u8(data0_ptr);
      uint8x8x2_t row1 = vld2_u8(data1_ptr);
      // compute 16 target pixels per loop
      uint16x8_t sum = vaddq_u16(vaddl_u8(row0.val[0], row0.val[1]),
                                 vaddl_u8(row1.val[0], row1.val[1]));
      vst1_u8(target_data_ptr, vmovn_u16(vshrq_n_u16(sum, 2)));
      data0_ptr += 16;
      data1_ptr += 16;
    }
    for (; x < img_in_small.cols; ++x)
    {
      int sum = ((static_cast<int>(*data0_ptr) + static_cast<int>(*(data0_ptr + 1))) +
                 (static_cast<int>(*data1_ptr) + static_cast<int>(*(data1_ptr + 1)))) /
                4;
      *target_data_ptr++ = static_cast<uchar>(sum);
      data0_ptr += 2;
      data1_ptr += 2;
    }
    data0_ptr += width_step_in;
    data1_ptr += width_step_in;
  }
}
#endif

void Pyramid::calcSharrDeriv(const cv::Mat &src, cv::Mat &dst)
{
  int rows = src.rows, cols = src.cols, cn = src.channels(), colsn = cols * cn;
#ifdef _WK_OPTICAL_FLOW_DEBUG_MODE_
  int depth = src.depth();
  CHECK_EQ(depth, CV_8U);
  CHECK_NOTNULL(dst.data);
  CHECK_EQ(dst.channels(), 2); // x and y gradient
  CHECK_EQ(dst.depth(), DataType<int16_t>::depth);
#endif

  int x, y, delta = static_cast<int>(cv::alignSize((cols + 2) * cn, 16));
  cv::AutoBuffer<int16_t> _tempBuf(delta * 2 + 64);
  int16_t *trow0 = cv::alignPtr(_tempBuf + cn, 16), *trow1 = cv::alignPtr(trow0 + delta, 16);

#if CV_SSE2
  __m128i z = _mm_setzero_si128(), c3 = _mm_set1_epi16(3), c10 = _mm_set1_epi16(10);
#else
  const uint16x8_t q8 = vdupq_n_u16(3);
  const uint8x8_t d18 = vdup_n_u8(10);

  const int16x8_t q8i = vdupq_n_s16(3);
  const int16x8_t q9 = vdupq_n_s16(10);
#endif

  for (y = 0; y < rows; ++y)
  {
    const uchar *srow0 = src.ptr<uchar>(y > 0 ? y - 1 : rows > 1 ? 1
                                                                 : 0); //! 镜像的方法扩充边界,所以图像可以不预留边界，当初留边界是计算fast用的; 但是计算响应的时候也是需要考虑边界的！！
    const uchar *srow1 = src.ptr<uchar>(y);
    const uchar *srow2 = src.ptr<uchar>(y < rows - 1 ? y + 1 : rows > 1 ? rows - 2
                                                                        : 0);
    int16_t *drow = dst.ptr<int16_t>(y);

    // do vertical convolution
    x = 0;
#if CV_SSE2
    for (; x <= colsn - 8; x += 8)
    {
      __m128i s0 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(srow0 + x)), z);
      __m128i s1 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(srow1 + x)), z);
      __m128i s2 = _mm_unpacklo_epi8(_mm_loadl_epi64((const __m128i *)(srow2 + x)), z);
      __m128i t0 = _mm_add_epi16(_mm_mullo_epi16(_mm_add_epi16(s0, s2), c3),
                                 _mm_mullo_epi16(s1, c10));
      __m128i t1 = _mm_sub_epi16(s2, s0);
      _mm_store_si128(reinterpret_cast<__m128i *>(trow0 + x), t0);
      _mm_store_si128(reinterpret_cast<__m128i *>(trow1 + x), t1);
    }
#else
    for (; x <= colsn - 8; x += 8)
    {
      uint8x8_t d0 = vld1_u8(static_cast<const uint8_t *>(&srow0[x]));
      uint8x8_t d1 = vld1_u8(static_cast<const uint8_t *>(&srow1[x]));
      uint8x8_t d2 = vld1_u8(static_cast<const uint8_t *>(&srow2[x]));
      uint16x8_t q4 = vaddl_u8(d0, d2);
      uint16x8_t q11 = vsubl_u8(d2, d0);
      uint16x8_t q5 = vmulq_u16(q4, q8);
      uint16x8_t q6 = vmull_u8(d1, d18);
      uint16x8_t q10 = vaddq_u16(q6, q5);
      vst1q_u16(reinterpret_cast<uint16_t *>(&trow0[x]), q10);
      vst1q_u16(reinterpret_cast<uint16_t *>(&trow1[x]), q11);
    }
#endif

    for (; x < colsn; x++)
    {
      int t0 = (srow0[x] + srow2[x]) * 3 + srow1[x] * 10;
      int t1 = srow2[x] - srow0[x];
      trow0[x] = (int16_t)t0;
      trow1[x] = (int16_t)t1;
    }

    // make border
    int x0 = (cols > 1 ? 1 : 0) * cn, x1 = (cols > 1 ? cols - 2 : 0) * cn;
    for (int k = 0; k < cn; k++)
    {
      trow0[-cn + k] = trow0[x0 + k];
      trow0[colsn + k] = trow0[x1 + k];
      trow1[-cn + k] = trow1[x0 + k];
      trow1[colsn + k] = trow1[x1 + k];
    }

    // do horizontal convolution, interleave the results and store them to dst
    x = 0;

#if CV_SSE2
    for (; x <= colsn - 8; x += 8)
    {
      __m128i s0 = _mm_loadu_si128(reinterpret_cast<const __m128i *>(trow0 + x - cn));
      __m128i s1 = _mm_loadu_si128(reinterpret_cast<const __m128i *>(trow0 + x + cn));
      __m128i s2 = _mm_loadu_si128(reinterpret_cast<const __m128i *>(trow1 + x - cn));
      __m128i s3 = _mm_load_si128(reinterpret_cast<const __m128i *>(trow1 + x));
      __m128i s4 = _mm_loadu_si128(reinterpret_cast<const __m128i *>(trow1 + x + cn));
      __m128i t0 = _mm_sub_epi16(s1, s0);
      __m128i t1 = _mm_add_epi16(_mm_mullo_epi16(_mm_add_epi16(s2, s4), c3),
                                 _mm_mullo_epi16(s3, c10));
      __m128i t2 = _mm_unpacklo_epi16(t0, t1);
      t0 = _mm_unpackhi_epi16(t0, t1);
      // this can probably be replaced with aligned stores if we aligned dst properly.
      _mm_storeu_si128(reinterpret_cast<__m128i *>(drow + x * 2), t2);
      _mm_storeu_si128(reinterpret_cast<__m128i *>(drow + x * 2 + 8), t0);
    }
#else
    for (; x <= colsn - 8; x += 8)
    {
      int16x8_t q0 = vld1q_s16(static_cast<const int16_t *>(&trow0[x + cn]));
      int16x8_t q1 = vld1q_s16(static_cast<const int16_t *>(&trow0[x - cn]));
      int16x8_t q2 = vld1q_s16(static_cast<const int16_t *>(&trow1[x + cn]));
      int16x8_t q3 = vld1q_s16(static_cast<const int16_t *>(&trow1[x - cn]));
      int16x8_t q5 = vsubq_s16(q0, q1);
      int16x8_t q6 = vaddq_s16(q2, q3);
      int16x8_t q4 = vld1q_s16(static_cast<const int16_t *>(&trow1[x]));

      int16x8_t q11 = vaddq_s16(vmulq_s16(q6, q8i), vmulq_s16(q4, q9));

      int16x4x2_t q5x2 = {
          vget_low_s16(q5),
          vget_low_s16(q11)};
      int16x4x2_t q11x2 = {
          vget_high_s16(q5),
          vget_high_s16(q11)};
      vst2_s16(static_cast<int16_t *>(&drow[x * 2]), q5x2);
      vst2_s16(static_cast<int16_t *>(&drow[(x * 2) + 8]), q11x2);
    }
#endif
    for (; x < colsn; x++)
    {
      int16_t t0 = (int16_t)(trow0[x + cn] - trow0[x - cn]);
      int16_t t1 = (int16_t)((trow1[x + cn] + trow1[x - cn]) * 3 + trow1[x] * 10);
      drow[x * 2] = t0;
      drow[x * 2 + 1] = t1;
    }
  }
}