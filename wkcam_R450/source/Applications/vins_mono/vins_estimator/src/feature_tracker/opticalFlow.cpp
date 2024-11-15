#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include "opticalFlow.h"


#define DBG_WK_PYRAMID(msg) \
  {                         \
    VLOG(1) << msg;         \
  }

// temporary buffer used for storing bigger patch in optical flow iterarion loop
// [NOTE] aligned_alloc is NOT supported by GCC on OSX or Windows
#ifdef __APPLE__
inline void *aligned_alloc(size_t align, size_t size)
{
  void *result;
  if (posix_memalign(&result, align, size))
  {
    result = 0;
  }
  return result;
}
#elif defined _MSC_VER
inline void *aligned_alloc(size_t align, size_t size)
{
  void *result;
  result = _aligned_malloc(size, align);
  return result;
}
#endif

static std::shared_ptr<uchar> iteration_patch_buffer(
    reinterpret_cast<uchar *>(aligned_alloc(64, 256)));
// temporary buffer for storing graident data in each pyramid level.
static std::shared_ptr<deriv_type> xy_gradient_buffer_prev(
    reinterpret_cast<deriv_type *>(aligned_alloc(64, 640 * 480 * sizeof(deriv_type) * 2)));

#define CV_DESCALE(x, n) (((x) + (1 << ((n) - 1))) >> (n))
#ifdef __ARM_NEON__
inline int32x4_t compute_bilinear_interpolation(const int16x8_t &top_row,
                                                const int16x8_t &bottom_row,
                                                const int16x4_t &w00,
                                                const int16x4_t &w01,
                                                const int16x4_t &w10,
                                                const int16x4_t &w11,
                                                const int32x4_t &shift)
{
  // Get the left column of upper row
  const int16x4_t px00 = vget_low_s16(top_row);

  // Get the right column of upper row
  const int16x4_t px01 = vext_s16(px00, vget_high_s16(top_row), 1);

  // Get the left column of lower row
  const int16x4_t px10 = vget_low_s16(bottom_row);

  // Get the right column of right row
  const int16x4_t px11 = vext_s16(px10, vget_high_s16(bottom_row), 1);

  // Apply the bilinear filter
  return vqrshlq_s32(vmull_s16(px00, w00) +
                         vmull_s16(px01, w01) +
                         vmull_s16(px10, w10) +
                         vmull_s16(px11, w11),
                     shift);
}
#endif

WKTrackerInvoker::WKTrackerInvoker(
    const cv::Mat &_prevImg, const cv::Mat &_prevDeriv, const cv::Mat &_nextImg,
    std::vector<WKKeyPoint> *_prevPts,
    std::vector<cv::Point2f> *_nextPts,
    std::vector<uchar> *_status, std::vector<float> *_err,
    cv::Size _winSize, cv::TermCriteria _criteria,
    int _level, int _maxLevel, int _start_level,
    int _flags, float _minEigThreshold)
{
  prevImg = &_prevImg;
  prevDeriv = &_prevDeriv;
  nextImg = &_nextImg;
  m_prevPts = _prevPts;
  m_nextPts = _nextPts;
  m_status = _status;
  m_err = _err;
  winSize = _winSize;
  criteria = _criteria;
  level = _level;
  maxLevel = _maxLevel;
  start_level = _start_level;
  flags = _flags;
  minEigThreshold = _minEigThreshold;
}

#if defined __arm__ && !__ARM_NEON__
typedef int64_t acctype;
typedef int32_t itemtype;
#else
typedef float acctype;
typedef float itemtype;
#endif

void WKTrackerInvoker::compute_covariance_matrix_and_update_patch(const cv::Point2i &iprevPt,
                                                                  const InterpolationParam &inter_param,
                                                                  cv::Mat *IWinBuf, cv::Mat *derivIWinBuf,
                                                                  float *const A_ptr) const
{
  const cv::Mat &I = *prevImg;
  const cv::Mat &derivI = *prevDeriv;

#if CV_SSE2
  __m128i qw0 = _mm_set1_epi32(inter_param.iw00 + (inter_param.iw01 << 16));
  __m128i qw1 = _mm_set1_epi32(inter_param.iw10 + (inter_param.iw11 << 16));
  __m128i z = _mm_setzero_si128();
  __m128i qdelta_d = _mm_set1_epi32(1 << (inter_param.w_bits - 1));
  __m128i qdelta = _mm_set1_epi32(1 << (inter_param.w_bits - 5 - 1));
  __m128 qA11 = _mm_setzero_ps(), qA12 = _mm_setzero_ps(), qA22 = _mm_setzero_ps();
#elif __ARM_NEON__
  int32x4_t CV_DECL_ALIGNED(16) nA11 = vdupq_n_s32(0);
  int32x4_t CV_DECL_ALIGNED(16) nA12 = vdupq_n_s32(0);
  int32x4_t CV_DECL_ALIGNED(16) nA22 = vdupq_n_s32(0);
  const int16x4_t d26 = vdup_n_s16(static_cast<int16_t>(inter_param.iw00));
  const int16x4_t d27 = vdup_n_s16(static_cast<int16_t>(inter_param.iw01));
  const int16x4_t d28 = vdup_n_s16(static_cast<int16_t>(inter_param.iw10));
  const int16x4_t d29 = vdup_n_s16(static_cast<int16_t>(inter_param.iw11));
  const int32x4_t q11 = vdupq_n_s32(static_cast<int32_t>(5 - inter_param.w_bits));
  const int32x4_t q12 = vdupq_n_s32(static_cast<int32_t>(-inter_param.w_bits));
#endif

  int x, y;
  int cn = I.channels();
  int cn2 = cn * 2;
  const float FLT_SCALE = 1.f / (1 << 20);
  itemtype iA11 = 0;
  itemtype iA12 = 0;
  itemtype iA22 = 0;

  // extract the patch from the first image, compute covariation matrix of derivatives
  for (y = 0; y < winSize.height; y++)
  {
    const uchar *src_row0 = I.ptr<uchar>(y + iprevPt.y) + iprevPt.x * cn;
    const uchar *src_row1 = I.ptr<uchar>(y + iprevPt.y + 1) + iprevPt.x * cn;

    const deriv_type *dsrc_row0 = derivI.ptr<deriv_type>(y + iprevPt.y) + iprevPt.x * cn2;
    const deriv_type *dsrc_row1 = derivI.ptr<deriv_type>(y + iprevPt.y + 1) + iprevPt.x * cn2;

    deriv_type *Iptr = IWinBuf->ptr<deriv_type>(y);
    deriv_type *dIptr = derivIWinBuf->ptr<deriv_type>(y);

    x = 0;
#if CV_SSE2
    for (; x <= winSize.width * cn - 4; x += 4,
                                        dsrc_row0 += 4 * 2, dsrc_row1 += 4 * 2, dIptr += 4 * 2)
    {
      __m128i v00, v01, v10, v11, t0, t1;

      v00 = _mm_unpacklo_epi8(_mm_cvtsi32_si128(
                                  *reinterpret_cast<const int *>(src_row0 + x)),
                              z);
      v01 = _mm_unpacklo_epi8(_mm_cvtsi32_si128(
                                  *reinterpret_cast<const int *>(src_row0 + x + cn)),
                              z);
      v10 = _mm_unpacklo_epi8(_mm_cvtsi32_si128(
                                  *reinterpret_cast<const int *>(src_row1 + x)),
                              z);
      v11 = _mm_unpacklo_epi8(_mm_cvtsi32_si128(
                                  *reinterpret_cast<const int *>(src_row1 + x + cn)),
                              z);

      t0 = _mm_add_epi32(_mm_madd_epi16(_mm_unpacklo_epi16(v00, v01), qw0),
                         _mm_madd_epi16(_mm_unpacklo_epi16(v10, v11), qw1));
      t0 = _mm_srai_epi32(_mm_add_epi32(t0, qdelta), inter_param.w_bits - 5);
      _mm_storel_epi64(reinterpret_cast<__m128i *>(Iptr + x), _mm_packs_epi32(t0, t0));

      v00 = _mm_loadu_si128(reinterpret_cast<const __m128i *>(dsrc_row0));
      v01 = _mm_loadu_si128(reinterpret_cast<const __m128i *>(dsrc_row0 + cn2));
      v10 = _mm_loadu_si128(reinterpret_cast<const __m128i *>(dsrc_row1));
      v11 = _mm_loadu_si128(reinterpret_cast<const __m128i *>(dsrc_row1 + cn2));

      t0 = _mm_add_epi32(_mm_madd_epi16(_mm_unpacklo_epi16(v00, v01), qw0),
                         _mm_madd_epi16(_mm_unpacklo_epi16(v10, v11), qw1));
      t1 = _mm_add_epi32(_mm_madd_epi16(_mm_unpackhi_epi16(v00, v01), qw0),
                         _mm_madd_epi16(_mm_unpackhi_epi16(v10, v11), qw1));
      t0 = _mm_srai_epi32(_mm_add_epi32(t0, qdelta_d), inter_param.w_bits);
      t1 = _mm_srai_epi32(_mm_add_epi32(t1, qdelta_d), inter_param.w_bits);
      v00 = _mm_packs_epi32(t0, t1); //  Ix0 Iy0 Ix1 Iy1 ...

      _mm_storeu_si128(reinterpret_cast<__m128i *>(dIptr), v00);
      t0 = _mm_srai_epi32(v00, 16);                     //  Iy0 Iy1 Iy2 Iy3
      t1 = _mm_srai_epi32(_mm_slli_epi32(v00, 16), 16); //  Ix0 Ix1 Ix2 Ix3

      __m128 fy = _mm_cvtepi32_ps(t0);
      __m128 fx = _mm_cvtepi32_ps(t1);

      qA22 = _mm_add_ps(qA22, _mm_mul_ps(fy, fy));
      qA12 = _mm_add_ps(qA12, _mm_mul_ps(fx, fy));
      qA11 = _mm_add_ps(qA11, _mm_mul_ps(fx, fx));
    }
#elif __ARM_NEON__
    for (; x <= winSize.width * cn - 4; x += 4,
                                        dsrc_row0 += 4 * 2, dsrc_row1 += 4 * 2, dIptr += 4 * 2)
    {
      int32x4_t q5 = compute_bilinear_interpolation(
          vreinterpretq_s16_u16(vmovl_u8(vld1_u8(&src_row0[x]))),
          vreinterpretq_s16_u16(vmovl_u8(vld1_u8(&src_row1[x]))),
          d26, d27, d28, d29, q11);

      vst1_s16(&Iptr[x], vmovn_s32(q5));

      int16x4x2_t d0d1 = vld2_s16(dsrc_row0);
      int16x4x2_t d2d3 = vld2_s16(&dsrc_row0[cn2]);
      int16x4x2_t d4d5 = vld2_s16(dsrc_row1);
      int16x4x2_t d6d7 = vld2_s16(&dsrc_row1[cn2]);

      int32x4_t q4 = vaddq_s32(vmull_s16(d0d1.val[0], d26), vmull_s16(d2d3.val[0], d27));
      int32x4_t q6 = vaddq_s32(vmull_s16(d0d1.val[1], d26), vmull_s16(d2d3.val[1], d27));

      int32x4_t q7 = vaddq_s32(vmull_s16(d4d5.val[0], d28), vmull_s16(d6d7.val[0], d29));
      int32x4_t q8 = vaddq_s32(vmull_s16(d4d5.val[1], d28), vmull_s16(d6d7.val[1], d29));

      q4 = vqrshlq_s32(vaddq_s32(q4, q7), q12);
      q6 = vqrshlq_s32(vaddq_s32(q6, q8), q12);

      int16x4x2_t d8d12 = {
          vmovn_s32(q4),
          vmovn_s32(q6)};
      vst2_s16(dIptr, d8d12);

      nA11 = vmlaq_s32(nA11, q4, q4);
      nA12 = vmlaq_s32(nA12, q4, q6);
      nA22 = vmlaq_s32(nA22, q6, q6);
    }
#endif
    for (; x < winSize.width; ++x, dsrc_row0 += 2, dsrc_row1 += 2, dIptr += 2)
    {
      int ival = CV_DESCALE(src_row0[x] * inter_param.iw00 + src_row0[x + 1] * inter_param.iw01 +
                                src_row1[x] * inter_param.iw10 + src_row1[x + 1] * inter_param.iw11,
                            inter_param.w_bits - 5);
      int ixval = CV_DESCALE(dsrc_row0[0] * inter_param.iw00 + dsrc_row0[2] * inter_param.iw01 +
                                 dsrc_row1[0] * inter_param.iw10 + dsrc_row1[2] * inter_param.iw11,
                             inter_param.w_bits);
      int iyval = CV_DESCALE(dsrc_row0[1] * inter_param.iw00 + dsrc_row0[3] * inter_param.iw01 +
                                 dsrc_row1[1] * inter_param.iw10 + dsrc_row1[3] * inter_param.iw11,
                             inter_param.w_bits);

      Iptr[x] = static_cast<int16_t>(ival);
      dIptr[0] = static_cast<int16_t>(ixval);
      dIptr[1] = static_cast<int16_t>(iyval);

      iA11 += static_cast<itemtype>(ixval * ixval);
      iA12 += static_cast<itemtype>(ixval * iyval);
      iA22 += static_cast<itemtype>(iyval * iyval);
    }
  }
#if CV_SSE2
  float CV_DECL_ALIGNED(16) A11buf[4], A12buf[4], A22buf[4];
  _mm_store_ps(A11buf, qA11);
  _mm_store_ps(A12buf, qA12);
  _mm_store_ps(A22buf, qA22);
  iA11 += A11buf[0] + A11buf[1] + A11buf[2] + A11buf[3];
  iA12 += A12buf[0] + A12buf[1] + A12buf[2] + A12buf[3];
  iA22 += A22buf[0] + A22buf[1] + A22buf[2] + A22buf[3];
#elif __ARM_NEON__
  iA11 += static_cast<float>(vgetq_lane_s32(nA11, 0) +
                             vgetq_lane_s32(nA11, 1) +
                             vgetq_lane_s32(nA11, 2) +
                             vgetq_lane_s32(nA11, 3));
  iA12 += static_cast<float>(vgetq_lane_s32(nA12, 0) +
                             vgetq_lane_s32(nA12, 1) +
                             vgetq_lane_s32(nA12, 2) +
                             vgetq_lane_s32(nA12, 3));
  iA22 += static_cast<float>(vgetq_lane_s32(nA22, 0) +
                             vgetq_lane_s32(nA22, 1) +
                             vgetq_lane_s32(nA22, 2) +
                             vgetq_lane_s32(nA22, 3));
#endif
  float A11 = iA11 * FLT_SCALE;
  float A12 = iA12 * FLT_SCALE;
  float A22 = iA22 * FLT_SCALE;
  *(A_ptr + 0) = A11;
  *(A_ptr + 1) = A12;
  *(A_ptr + 2) = A22;
  *(A_ptr + 3) = (A22 + A11 - std::sqrt((A11 - A22) * (A11 - A22) + 4.f * A12 * A12)) / (2 * winSize.width * winSize.height);
  *(A_ptr + 4) = 1.f / (A11 * A22 - A12 * A12);
}

void WKTrackerInvoker::operator()(const cv::Range &range) const
{
  const cv::Point2f halfWin((winSize.width - 1) * 0.5f, (winSize.height - 1) * 0.5f);
  const cv::Point2i halfWini(3, 3);
  const cv::Size iter_cache_size(15, 15);
  const cv::Point2i half_diff(iter_cache_size.width / 2 - halfWini.x,
                              iter_cache_size.height / 2 - halfWin.y);
  const cv::Mat &I = *prevImg;
  const cv::Mat &J = *nextImg;
  const cv::Mat &derivI = *prevDeriv;
  const std::vector<WKKeyPoint> &prevPts = *m_prevPts;
  const int W_BITS = 14;
  const float FLT_SCALE = 1.f / (1 << 20);
  std::vector<cv::Point2f> &nextPts = *m_nextPts;
  std::vector<uchar> &status = *m_status;
  std::vector<float> &err = *m_err;

  int j, cn = I.channels(), cn2 = cn * 2;
  int derivDepth = cv::DataType<deriv_type>::depth;
  int Jcols = J.cols, Jrows = J.rows;
#ifdef _WK_OPTICAL_FLOW_DEBUG_MODE_
  CHECK_EQ(derivI.cols, Jcols);
  CHECK_EQ(derivI.rows, Jrows);
#endif

  int wh = winSize.height;

  cv::Rect valid_region(half_diff.x, half_diff.y,
                        Jcols - iter_cache_size.width, Jrows - iter_cache_size.height);
  const bool get_min_eigenvals = (flags & cv::OPTFLOW_LK_GET_MIN_EIGENVALS) != 0;
  cv::Mat J_patch(iter_cache_size, CV_MAKETYPE(cv::DataType<uchar>::depth, 1),
                  iteration_patch_buffer.get());
  __builtin_prefetch(J_patch.data, 1, 3);
  for (int ptidx = range.start; ptidx < range.end; ++ptidx)
  {
    cv::Point2f prevPt = prevPts[ptidx].pt * static_cast<float>(1. / (1 << (level - start_level)));
    cv::Point2f nextPt;
    if (level == maxLevel)
    {
      if (flags & cv::OPTFLOW_USE_INITIAL_FLOW)
        nextPt = nextPts[ptidx] * static_cast<float>(1. / (1 << (level - start_level)));
      else
        nextPt = prevPt;
    }
    else
    {
      nextPt = nextPts[ptidx] * 2.f;
    }
    nextPts[ptidx] = nextPt;

    //DBG_WK_PYRAMID("ft_id: " << prevPts[ptidx].class_id << " cur level = " << level);
    //DBG_WK_PYRAMID("prevPt = " << prevPt << " nextPt = " << nextPt);

    cv::Point2i iprevPt, inextPt;
    prevPt -= halfWin;
    iprevPt.x = cvFloor(prevPt.x);
    iprevPt.y = cvFloor(prevPt.y);

    if (WKTrackerInvoker::is_keypoint_not_in_valid_range(iprevPt, valid_region))
    {
      if (level == start_level)
      {
        status[ptidx] = 0;
        err[ptidx] = 0.f;
      }
      //DBG_WK_PYRAMID(" continue as not in valid range");
      continue;
    }

    int x, y;
    float a = prevPt.x - iprevPt.x;
    float b = prevPt.y - iprevPt.y;
    int iw00 = cvRound((1.f - a) * (1.f - b) * (1 << W_BITS));
    int iw01 = cvRound(a * (1.f - b) * (1 << W_BITS));
    int iw10 = cvRound((1.f - a) * b * (1 << W_BITS));
    int iw11 = (1 << W_BITS) - iw00 - iw01 - iw10;
    int stepJ = static_cast<int>(J.step / J.elemSize1());
#if CV_SSE2
    __m128i qw0 = _mm_set1_epi32(iw00 + (iw01 << 16));
    __m128i qw1 = _mm_set1_epi32(iw10 + (iw11 << 16));
    __m128i z = _mm_setzero_si128();
    __m128i qdelta = _mm_set1_epi32(1 << (W_BITS - 5 - 1));
#elif __ARM_NEON__
    int32x4_t CV_DECL_ALIGNED(16) nA11 = vdupq_n_s32(0);
    int32x4_t CV_DECL_ALIGNED(16) nA12 = vdupq_n_s32(0);
    int32x4_t CV_DECL_ALIGNED(16) nA22 = vdupq_n_s32(0);
    const int shifter1 = -(W_BITS - 5); // negative so it shifts right
    const int shifter2 = -(W_BITS);

    const int16x4_t d26 = vdup_n_s16(static_cast<int16_t>(iw00));
    const int16x4_t d27 = vdup_n_s16(static_cast<int16_t>(iw01));
    const int16x4_t d28 = vdup_n_s16(static_cast<int16_t>(iw10));
    const int16x4_t d29 = vdup_n_s16(static_cast<int16_t>(iw11));
    const int32x4_t q11 = vdupq_n_s32(static_cast<int32_t>(shifter1));
    const int32x4_t q12 = vdupq_n_s32(static_cast<int32_t>(shifter2));

#endif
    WKKeyPointRepo *kp_repo =
        &(prevPts[ptidx].keypoint_repo->pyramids[level]);

    cv::Mat IWinBuf(winSize, CV_MAKETYPE(derivDepth, cn), kp_repo->patch);

    cv::Mat derivIWinBuf(winSize, CV_MAKETYPE(derivDepth, cn2), kp_repo->xy_gradient);
    // to decide whether to recompute convariance matrix
    if (prevPts[ptidx].need_to_update_repo)
    {
      compute_covariance_matrix_and_update_patch(iprevPt,
                                                 InterpolationParam(iw00, iw01, iw10, iw11),
                                                 &IWinBuf, &derivIWinBuf,
                                                 kp_repo->covariance_maxtrix);
    }
    // get the convariance matrix
    float A11 = kp_repo->covariance_maxtrix[0];
    float A12 = kp_repo->covariance_maxtrix[1];
    float A22 = kp_repo->covariance_maxtrix[2];

    float minEig = kp_repo->covariance_maxtrix[3];

    if (get_min_eigenvals)
      err[ptidx] = static_cast<float>(minEig);

    if (minEig < minEigThreshold || (A11 * A22 - A12 * A12) < FLT_EPSILON)
    {
      if (level == start_level)
      {
        status[ptidx] = 0;
      }
      //DBG_WK_PYRAMID("continue at itr = " << j);
      continue;
    }

    float D = kp_repo->covariance_maxtrix[4];

    nextPt -= halfWin;
    cv::Point2f prevDelta;
    cv::Point2i init_pos;

    init_pos.x = cvFloor(nextPt.x);
    init_pos.y = cvFloor(nextPt.y);

    const int max_iterations = criteria.maxCount;
    for (j = 0; j < max_iterations; ++j)
    {
      inextPt.x = cvFloor(nextPt.x);
      inextPt.y = cvFloor(nextPt.y);

      if (WKTrackerInvoker::is_keypoint_not_in_valid_range(inextPt, valid_region))
      {
        if (level == start_level)
        {
          status[ptidx] = 0;
        }
        //DBG_WK_PYRAMID("not in valid range at itr = " << j);
        break;
      }
      // compute the current optical flow in pixels
      // this info will be used to decide whether update the cached buffer.
      cv::Point2i off = inextPt - init_pos;

      if (std::abs(off.x) > half_diff.x ||
          std::abs(off.y) > half_diff.y ||
          j == 0)
      {
#ifndef __ARM_NEON__
        for (int m = 0; m < iter_cache_size.height + 1; ++m)
        {
          uchar *dst = const_cast<uchar *>(J_patch.ptr<uchar>(m));
          uchar *src = const_cast<uchar *>(J.ptr<uchar>(m + inextPt.y - half_diff.y) +
                                           inextPt.x - half_diff.x);
          __builtin_prefetch(src + stepJ, 0, 1);
          _mm_storeu_si128(reinterpret_cast<__m128i *>(dst),
                           _mm_loadu_si128(reinterpret_cast<const __m128i *>(src)));
        }
#else
        for (int m = 0; m < iter_cache_size.height + 1; ++m)
        {
          uchar *dst = const_cast<uchar *>(J_patch.ptr<uchar>(m));
          uchar *src = const_cast<uchar *>(J.ptr<uchar>(m + inextPt.y - half_diff.y) +
                                           inextPt.x - half_diff.x);
          __builtin_prefetch(src + stepJ, 0, 1);
          vst1q_u8(dst, vld1q_u8(src));
        }
#endif
        init_pos = inextPt;
        off.x = 0;
        off.y = 0;
      }

      a = nextPt.x - inextPt.x;
      b = nextPt.y - inextPt.y;
      iw00 = cvRound((1.f - a) * (1.f - b) * (1 << W_BITS));
      iw01 = cvRound(a * (1.f - b) * (1 << W_BITS));
      iw10 = cvRound((1.f - a) * b * (1 << W_BITS));
      iw11 = (1 << W_BITS) - iw00 - iw01 - iw10;
      acctype ib1 = 0, ib2 = 0;
      float b1, b2;
#if CV_SSE2
      qw0 = _mm_set1_epi32(iw00 + (iw01 << 16));
      qw1 = _mm_set1_epi32(iw10 + (iw11 << 16));
      __m128 qb0 = _mm_setzero_ps(), qb1 = _mm_setzero_ps();
#elif __ARM_NEON__
      int32x4_t CV_DECL_ALIGNED(16) nb1 = vdupq_n_s32(0);
      int32x4_t CV_DECL_ALIGNED(16) nb2 = vdupq_n_s32(0);

      const int16x4_t d26_2 = vdup_n_s16(static_cast<int16_t>(iw00));
      const int16x4_t d27_2 = vdup_n_s16(static_cast<int16_t>(iw01));
      const int16x4_t d28_2 = vdup_n_s16(static_cast<int16_t>(iw10));
      const int16x4_t d29_2 = vdup_n_s16(static_cast<int16_t>(iw11));
#endif

      for (y = 0; y < wh; y++)
      {
        const uchar *Jptr0 = J_patch.ptr<uchar>(y + half_diff.y + off.y) +
                             (half_diff.x + off.x);
        const uchar *Jptr1 = J_patch.ptr<uchar>((y + half_diff.y) + (off.y + 1)) +
                             (half_diff.x + off.x);
        const deriv_type *Iptr = IWinBuf.ptr<deriv_type>(y);
        const deriv_type *dIptr = derivIWinBuf.ptr<deriv_type>(y);

        x = 0;
#if CV_SSE2
        for (; x <= winSize.width - 8; x += 8, dIptr += 8 * 2)
        {
          __m128i diff0 = _mm_loadu_si128(reinterpret_cast<const __m128i *>(Iptr + x)), diff1;
          __m128i v00 = _mm_unpacklo_epi8(
              _mm_loadl_epi64(reinterpret_cast<const __m128i *>(Jptr0 + x)), z);
          __m128i v01 = _mm_unpacklo_epi8(
              _mm_loadl_epi64(reinterpret_cast<const __m128i *>(Jptr0 + x + cn)), z);
          __m128i v10 = _mm_unpacklo_epi8(
              _mm_loadl_epi64(reinterpret_cast<const __m128i *>(Jptr1 + x)), z);
          __m128i v11 = _mm_unpacklo_epi8(
              _mm_loadl_epi64(reinterpret_cast<const __m128i *>(Jptr1 + x + cn)), z);

          __m128i t0 = _mm_add_epi32(_mm_madd_epi16(_mm_unpacklo_epi16(v00, v01), qw0),
                                     _mm_madd_epi16(_mm_unpacklo_epi16(v10, v11), qw1));
          __m128i t1 = _mm_add_epi32(_mm_madd_epi16(_mm_unpackhi_epi16(v00, v01), qw0),
                                     _mm_madd_epi16(_mm_unpackhi_epi16(v10, v11), qw1));
          t0 = _mm_srai_epi32(_mm_add_epi32(t0, qdelta), W_BITS - 5);
          t1 = _mm_srai_epi32(_mm_add_epi32(t1, qdelta), W_BITS - 5);
          diff0 = _mm_subs_epi16(_mm_packs_epi32(t0, t1), diff0);
          diff1 = _mm_unpackhi_epi16(diff0, diff0);
          diff0 = _mm_unpacklo_epi16(diff0, diff0); //  It0 It0 It1 It1 ...
          //  Ix0 Iy0 Ix1 Iy1 ...
          v00 = _mm_loadu_si128(reinterpret_cast<const __m128i *>(dIptr));
          v01 = _mm_loadu_si128(reinterpret_cast<const __m128i *>(dIptr + 8));
          v10 = _mm_mullo_epi16(v00, diff0);
          v11 = _mm_mulhi_epi16(v00, diff0);
          v00 = _mm_unpacklo_epi16(v10, v11);
          v10 = _mm_unpackhi_epi16(v10, v11);
          qb0 = _mm_add_ps(qb0, _mm_cvtepi32_ps(v00));
          qb1 = _mm_add_ps(qb1, _mm_cvtepi32_ps(v10));
          v10 = _mm_mullo_epi16(v01, diff1);
          v11 = _mm_mulhi_epi16(v01, diff1);
          v00 = _mm_unpacklo_epi16(v10, v11);
          v10 = _mm_unpackhi_epi16(v10, v11);
          qb0 = _mm_add_ps(qb0, _mm_cvtepi32_ps(v00));
          qb1 = _mm_add_ps(qb1, _mm_cvtepi32_ps(v10));
        }
#elif __ARM_NEON__
        for (; x <= winSize.width - 4; x += 4, dIptr += 8)
        {
          union
          {
            int16x4x2_t q3;
            int16x8_t q0;
          };
          // loading pixel value from current image
          q0 = vreinterpretq_s16_u16(vmovl_u8(vld1_u8(&Jptr0[x])));
          int16x8_t q1 = vreinterpretq_s16_u16(vmovl_u8(vld1_u8(&Jptr1[x])));
          // do interpolation
          int32x4_t q2 = compute_bilinear_interpolation(
              q0, q1, d26_2, d27_2, d28_2, d29_2, q11);
          // image diff between current image and prev image
          q2 = vsubq_s32(q2, vmovl_s16(vld1_s16(&Iptr[x])));
          // loading x and y gradient
          q3 = vld2_s16(dIptr);
          // accumulate
          nb1 = vmlaq_s32(nb1, q2, vmovl_s16(q3.val[0]));
          nb2 = vmlaq_s32(nb2, q2, vmovl_s16(q3.val[1]));
        }
        // process the leftover: 3
        union
        {
          int16x4x2_t q3;
          int16x8_t q0;
        };
        // loading pixel value from current image
        q0 = vreinterpretq_s16_u16(vmovl_u8(vld1_u8(&Jptr0[x])));
        int16x8_t q1 = vreinterpretq_s16_u16(vmovl_u8(vld1_u8(&Jptr1[x])));
        // do interpolation
        int32x4_t q2 = compute_bilinear_interpolation(
            q0, q1, d26_2, d27_2, d28_2, d29_2, q11);
        // image diff between current image and prev image
        q2 = vsubq_s32(q2, vmovl_s16(vld1_s16(&Iptr[x])));
        // loading x and y gradient
        q3 = vld2_s16(dIptr);
        q2 = vsetq_lane_s32(0, q2, 3); // IMPORTANT: set lane3 to 0 for win_size 7
        // accumulate
        nb1 = vmlaq_s32(nb1, q2, vmovl_s16(q3.val[0]));
        nb2 = vmlaq_s32(nb2, q2, vmovl_s16(q3.val[1]));
        x += 3;
#endif
        for (; x < winSize.width; ++x, dIptr += 2)
        {
          int diff = CV_DESCALE(Jptr0[x] * iw00 + Jptr0[x + 1] * iw01 +
                                    Jptr1[x] * iw10 + Jptr1[x + 1] * iw11,
                                W_BITS - 5) -
                     Iptr[x];
          ib1 += diff * dIptr[0];
          ib2 += diff * dIptr[1];
        }
      }
#if CV_SSE2
      float CV_DECL_ALIGNED(16) bbuf[4];
      _mm_store_ps(bbuf, _mm_add_ps(qb0, qb1));
      ib1 += bbuf[0] + bbuf[2];
      ib2 += bbuf[1] + bbuf[3];
#elif __ARM_NEON__
      ib1 += vgetq_lane_s32(nb1, 0) +
             vgetq_lane_s32(nb1, 1) +
             vgetq_lane_s32(nb1, 2) +
             vgetq_lane_s32(nb1, 3);
      ib2 += vgetq_lane_s32(nb2, 0) +
             vgetq_lane_s32(nb2, 1) +
             vgetq_lane_s32(nb2, 2) +
             vgetq_lane_s32(nb2, 3);
#endif

      b1 = ib1 * FLT_SCALE;
      b2 = ib2 * FLT_SCALE;

      cv::Point2f delta((A12 * b2 - A22 * b1) * D,
                    (A12 * b1 - A11 * b2) * D);
      //  delta = -delta;
      nextPt += delta;
      nextPts[ptidx] = nextPt + halfWin;

      if (delta.ddot(delta) <= criteria.epsilon)
      {
        //DBG_WK_PYRAMID("break delta < epsilon at itr = " << j << " nextPt = " << nextPts[ptidx]);
        break;
      }
      if (std::abs(delta.x + prevDelta.x) < 0.01 &&
          std::abs(delta.y + prevDelta.y) < 0.01 && j > 0)
      {
        nextPts[ptidx] -= delta * 0.5f;
        //DBG_WK_PYRAMID("break terminates at itr = " << j << " nextPt = " << nextPts[ptidx]);
        break;
      }

      //DBG_WK_PYRAMID("delta = " << delta << " at itr = " << j << " nextPt = " << nextPts[ptidx]);
      prevDelta = delta;
    }

    if (status[ptidx] && level == start_level &&
        (flags & cv::OPTFLOW_LK_GET_MIN_EIGENVALS) == 0)
    {
      cv::Point2f nextPoint = nextPts[ptidx] - halfWin;
      cv::Point inextPoint;

      inextPoint.x = cvFloor(nextPoint.x);
      inextPoint.y = cvFloor(nextPoint.y);

      if (inextPoint.x < 0 || inextPoint.x >= Jcols - winSize.width ||
          inextPoint.y < 0 || inextPoint.y >= Jrows - winSize.height)
      {
        status[ptidx] = 0;
        continue;
      }
      // TODO(yanghongtian) : supportint patch here, update need_to_update_repo flag.
      // for now, need_to_update_repo is always true.
      float aa = nextPoint.x - inextPoint.x;
      float bb = nextPoint.y - inextPoint.y;
      iw00 = cvRound((1.f - aa) * (1.f - bb) * (1 << W_BITS));
      iw01 = cvRound(aa * (1.f - bb) * (1 << W_BITS));
      iw10 = cvRound((1.f - aa) * bb * (1 << W_BITS));
      iw11 = (1 << W_BITS) - iw00 - iw01 - iw10;
      float errval = 0.f;

      for (y = 0; y < winSize.height; y++)
      {
        const uchar *Jptr = J.ptr() + (y + inextPoint.y) * stepJ + inextPoint.x * cn;
        const deriv_type *Iptr = IWinBuf.ptr<deriv_type>(y);

        for (x = 0; x < winSize.width; x++)
        {
          int diff = CV_DESCALE(Jptr[x] * iw00 + Jptr[x + cn] * iw01 +
                                    Jptr[x + stepJ] * iw10 + Jptr[x + stepJ + cn] * iw11,
                                W_BITS - 5) -
                     Iptr[x];
          errval += std::abs(static_cast<float>(diff));
        }
      }
      err[ptidx] = errval * 1.f / (32 * winSize.width * cn * winSize.height);
    }
  }
}

void WKcalcOpticalFlowPyrLK(const std::vector<cv::Mat> &_prevPyramids,
                            const std::vector<cv::Mat> &_nextPyramids,
                            const std::vector<cv::Mat> &_prevDivPyramids,
                            std::vector<WKKeyPoint> *_prevPts,
                            std::vector<cv::Point2f> *_nextPts,
                            std::vector<uchar> *_status,
                            std::vector<float> *_err,
                            const cv::Size _win_size,
                            int _max_level,
                            int _start_level,
                            cv::TermCriteria _criteria,
                            int _flags, double _minEigThreshold)
{
#ifdef _WK_OPTICAL_FLOW_DEBUG_MODE_
  CHECK_EQ(_win_size.width, 7) << "only support window size 7 for now";
  CHECK_EQ(_win_size.height, 7) << "only support window size 7 for now";
  CHECK_NOTNULL(_prevPts);
  CHECK_NOTNULL(_nextPts);
  CHECK_NOTNULL(_status);
  CHECK_NOTNULL(_err);
  CHECK_LT(_max_level, 4) << "only support 4 level pyramids";
  CHECK_GT(npoints, 0);
#endif
  const int npoints = _prevPts->size();
  _nextPts->resize(npoints);
  _err->resize(npoints);
  _status->resize(npoints);

  int level = 0, i;
  std::vector<uchar> &status = *_status;
  std::vector<WKKeyPoint> &prevPts = *_prevPts;
  // allocate memory for new keypoint,
  for (i = 0; i < npoints; i++)
  {
    if (prevPts[i].need_to_update_repo)
    {
      prevPts[i].allocate(); // will not reallocate memory
    }
    status[i] = 1;
  }

  if ((_criteria.type & cv::TermCriteria::COUNT) == 0)
    _criteria.maxCount = 30;
  else
    _criteria.maxCount = std::min(std::max(_criteria.maxCount, 0), 100);
  if ((_criteria.type & cv::TermCriteria::EPS) == 0)
    _criteria.epsilon = 0.01;
  else
    _criteria.epsilon = std::min(std::max(_criteria.epsilon, 0.), 10.);
  _criteria.epsilon *= _criteria.epsilon;

  for (level = _max_level; level >= _start_level; --level)
  {
    // invoke optical flow, single thread
    //DBG_WK_PYRAMID("WKTrackerInvoker at level " << level);
    WKTrackerInvoker(_prevPyramids[level], _prevDivPyramids[level],
                     _nextPyramids[level], _prevPts, _nextPts,
                     _status, _err,
                     _win_size, _criteria, level, _max_level, _start_level,
                     _flags, static_cast<float>(_minEigThreshold))
        .operator()(cv::Range(0, npoints));
  }
}
/* End of file. */
