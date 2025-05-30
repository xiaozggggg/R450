#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include "opticalFlow.h" // Already includes opencv headers and defines MAX_OPTICAL_FLOW_WINDOW_SIZE

#ifndef CV_SSE2
#include <arm_neon.h>
#endif

// Debug macro, can be replaced with std::cout or other logging
// #define DBG_WK_PYRAMID(msg) \
//   {                         \
//     std::cout << "[WKOF Debug] " << msg << std::endl; \
//   }

// aligned_alloc is needed on some platforms if not using C++17 std::aligned_alloc
// However, the global iteration_patch_buffer will be replaced by a local Mat.
#if defined(__ANDROID__) || defined(__LINUX__) || defined(__gnu_linux__)
// For Linux/Android, posix_memalign is common. aligned_alloc is C11.
#include <malloc.h> // For memalign / posix_memalign
#ifndef aligned_alloc
#define aligned_alloc(alignment, size) memalign(alignment, size)
#endif
#ifndef aligned_free
#define aligned_free free
#endif
#elif defined(__APPLE__)
// macOS provides aligned_alloc in C11 and later, or posix_memalign
#include <cstdlib> // For posix_memalign
inline void* apple_aligned_alloc(size_t align, size_t size) {
    void* result;
    if (posix_memalign(&result, align, size) != 0) {
        return nullptr;
    }
    return result;
}
#ifndef aligned_alloc
#define aligned_alloc(alignment, size) apple_aligned_alloc(alignment, size)
#endif
#ifndef aligned_free
#define aligned_free free
#endif
#elif defined _MSC_VER
// Windows uses _aligned_malloc
#include <malloc.h>
#ifndef aligned_alloc
#define aligned_alloc(alignment, size) _aligned_malloc(size, alignment)
#endif
#ifndef aligned_free
#define aligned_free _aligned_free
#endif
#else // Fallback for other systems, may not be truly aligned
#warning "aligned_alloc not defined for this platform, using standard malloc."
#define aligned_alloc(alignment, size) malloc(size)
#define aligned_free free
#endif


#define CV_DESCALE(x, n) (((x) + (1 << ((n) - 1))) >> (n))

#if !CV_SSE2
// NEON specific bilinear interpolation helper
inline int32x4_t compute_bilinear_interpolation_neon(const int16x8_t &top_row, 
                                                     const int16x8_t &bottom_row,
                                                     const int16x4_t &w00_vec, 
                                                     const int16x4_t &w01_vec, 
                                                     const int16x4_t &w10_vec, 
                                                     const int16x4_t &w11_vec, 
                                                     const int32x4_t &shift_vec)
{
  const int16x4_t px00 = vget_low_s16(top_row);  
  const int16x4_t px01 = vext_s16(px00, vget_high_s16(top_row), 1); 

  const int16x4_t px10 = vget_low_s16(bottom_row); 
  const int16x4_t px11 = vext_s16(px10, vget_high_s16(bottom_row), 1);

  int32x4_t term00 = vmull_s16(px00, w00_vec);
  int32x4_t term01 = vmull_s16(px01, w01_vec);
  int32x4_t term10 = vmull_s16(px10, w10_vec);
  int32x4_t term11 = vmull_s16(px11, w11_vec);

  int32x4_t sum = vaddq_s32(term00, term01);
  sum = vaddq_s32(sum, term10);
  sum = vaddq_s32(sum, term11);

  return vqrshlq_s32(sum, shift_vec); 
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

  // DBG_WK_PYRAMID("WKTrackerInvoker created. Level: " << level << ", WinSize: " << winSize.width << "x" << winSize.height);
}

#ifndef CV_SSE2
typedef int64_t acctype; 
typedef int32_t itemtype; 
#else
typedef float acctype;   
typedef float itemtype;  
#endif

void WKTrackerInvoker::compute_covariance_matrix_and_update_patch(const cv::Point2i &iprevPt,
                                                                  const InterpolationParam &inter_param,
                                                                  cv::Mat *IWinBuf_mat, 
                                                                  cv::Mat *derivIWinBuf_mat, 
                                                                  float *const A_ptr,
                                                                  const cv::Size& currentWinSize) const 
{
  const cv::Mat &I = *prevImg;
  const cv::Mat &derivI = *prevDeriv;

  // DBG_WK_PYRAMID("compute_covariance_matrix_and_update_patch - Level: " << level << " WinSize: " << currentWinSize.width << "x" << currentWinSize.height << " for point at (" << iprevPt.x << "," << iprevPt.y << ")");

#if CV_SSE2
  __m128i qw0 = _mm_set1_epi32(inter_param.iw00 + (inter_param.iw01 << 16));
  __m128i qw1 = _mm_set1_epi32(inter_param.iw10 + (inter_param.iw11 << 16));
  __m128i z = _mm_setzero_si128();
  __m128i qdelta_d = _mm_set1_epi32(1 << (inter_param.w_bits - 1)); 
  __m128i qdelta = _mm_set1_epi32(1 << (inter_param.w_bits - 5 - 1)); 
  __m128 qA11 = _mm_setzero_ps(), qA12 = _mm_setzero_ps(), qA22 = _mm_setzero_ps();
#else
  int32x4_t nA11_vec = vdupq_n_s32(0); 
  int32x4_t nA12_vec = vdupq_n_s32(0);
  int32x4_t nA22_vec = vdupq_n_s32(0);

  const int16x4_t w00_neon = vdup_n_s16(static_cast<int16_t>(inter_param.iw00));
  const int16x4_t w01_neon = vdup_n_s16(static_cast<int16_t>(inter_param.iw01));
  const int16x4_t w10_neon = vdup_n_s16(static_cast<int16_t>(inter_param.iw10));
  const int16x4_t w11_neon = vdup_n_s16(static_cast<int16_t>(inter_param.iw11));

  const int32x4_t shift_img_neon = vdupq_n_s32(-(inter_param.w_bits - 5)); 
  const int32x4_t shift_deriv_neon = vdupq_n_s32(-(inter_param.w_bits));   
#endif

  int x, y;
  int cn = I.channels(); 
  int cn2 = cn * 2;     
  
  itemtype iA11 = 0, iA12 = 0, iA22 = 0; 
  const float FLT_SCALE = 1.f / (1 << 20); 

  for (y = 0; y < currentWinSize.height; y++)
  {
    const uchar *src_row0 = I.ptr<uchar>(y + iprevPt.y) + iprevPt.x * cn;
    const uchar *src_row1 = I.ptr<uchar>(y + iprevPt.y + 1) + iprevPt.x * cn;

    const deriv_type *dsrc_row0 = derivI.ptr<deriv_type>(y + iprevPt.y) + iprevPt.x * cn2;
    const deriv_type *dsrc_row1 = derivI.ptr<deriv_type>(y + iprevPt.y + 1) + iprevPt.x * cn2;

    deriv_type *Iptr = reinterpret_cast<deriv_type*>(IWinBuf_mat->ptr(y)); 
    deriv_type *dIptr = reinterpret_cast<deriv_type*>(derivIWinBuf_mat->ptr(y));

    x = 0;
#if CV_SSE2
    int sse_loop_end = currentWinSize.width * cn;
    if (cn == 1) sse_loop_end = currentWinSize.width - (currentWinSize.width % 4);

    for (; x < sse_loop_end; x += 4, dsrc_row0 += 4*2, dsrc_row1 += 4*2, Iptr +=4, dIptr += 4*2) // Iptr increments by 4 (4 pixels), dIptr by 4*2 (4 dx,dy pairs)
    {
      __m128i v00, v01, v10, v11, t0, t1;
      v00 = _mm_unpacklo_epi8(_mm_cvtsi32_si128(*reinterpret_cast<const int*>(src_row0 + x)), z); 
      v01 = _mm_unpacklo_epi8(_mm_cvtsi32_si128(*reinterpret_cast<const int*>(src_row0 + x + cn)), z); 
      v10 = _mm_unpacklo_epi8(_mm_cvtsi32_si128(*reinterpret_cast<const int*>(src_row1 + x)), z);
      v11 = _mm_unpacklo_epi8(_mm_cvtsi32_si128(*reinterpret_cast<const int*>(src_row1 + x + cn)), z);
      
      t0 = _mm_add_epi32(_mm_madd_epi16(_mm_unpacklo_epi16(v00, v01), qw0),
                         _mm_madd_epi16(_mm_unpacklo_epi16(v10, v11), qw1));
      t0 = _mm_srai_epi32(_mm_add_epi32(t0, qdelta), inter_param.w_bits - 5); 
      _mm_storel_epi64(reinterpret_cast<__m128i*>(Iptr), _mm_packs_epi32(t0, t0)); 

      v00 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(dsrc_row0)); 
      v01 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(dsrc_row0 + cn2)); 
      v10 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(dsrc_row1));
      v11 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(dsrc_row1 + cn2));

      t0 = _mm_add_epi32(_mm_madd_epi16(_mm_unpacklo_epi16(v00, v01), qw0), 
                         _mm_madd_epi16(_mm_unpacklo_epi16(v10, v11), qw1));
      t1 = _mm_add_epi32(_mm_madd_epi16(_mm_unpackhi_epi16(v00, v01), qw0),
                         _mm_madd_epi16(_mm_unpackhi_epi16(v10, v11), qw1));
      
      t0 = _mm_srai_epi32(_mm_add_epi32(t0, qdelta_d), inter_param.w_bits); 
      t1 = _mm_srai_epi32(_mm_add_epi32(t1, qdelta_d), inter_param.w_bits);
      v00 = _mm_packs_epi32(t0, t1); 
      _mm_storeu_si128(reinterpret_cast<__m128i*>(dIptr), v00);
      
      t1 = _mm_srai_epi32(_mm_slli_epi32(v00, 16), 16); 
      t0 = _mm_srai_epi32(v00, 16);                     
      
      __m128 fx = _mm_cvtepi32_ps(t1); 
      __m128 fy = _mm_cvtepi32_ps(t0); 

      qA11 = _mm_add_ps(qA11, _mm_mul_ps(fx, fx)); 
      qA12 = _mm_add_ps(qA12, _mm_mul_ps(fx, fy)); 
      qA22 = _mm_add_ps(qA22, _mm_mul_ps(fy, fy)); 
    }
#elif !CV_SSE2 // NEON Path
    int neon_loop_end = currentWinSize.width * cn;
    if (cn == 1) neon_loop_end = currentWinSize.width - (currentWinSize.width % 4); 

    for (; x < neon_loop_end; x += 4, dsrc_row0 += 4*2, dsrc_row1 += 4*2, Iptr +=4, dIptr += 4*2 ) 
    {
        uint8x8_t s0_u8 = vld1_u8(src_row0 + x); 
        uint8x8_t s1_u8 = vld1_u8(src_row1 + x);
        int16x8_t top_img_s16 = vreinterpretq_s16_u16(vmovl_u8(s0_u8)); 
        int16x8_t bot_img_s16 = vreinterpretq_s16_u16(vmovl_u8(s1_u8));

        int32x4_t img_val_s32 = compute_bilinear_interpolation_neon(top_img_s16, bot_img_s16, w00_neon, w01_neon, w10_neon, w11_neon, shift_img_neon);
        vst1_s16(Iptr, vmovn_s32(img_val_s32)); 

        int16x8_t d_top_s16 = vld1q_s16(dsrc_row0);
        int16x8_t d_bot_s16 = vld1q_s16(dsrc_row1);
        
        // Deinterleave Dx, Dy from d_top_s16 and d_bot_s16
        // Assuming d_top_s16 is [dx0 dy0 dx1 dy1 dx2 dy2 dx3 dy3]
        int16x4_t dx_top_vals = vuzp1_s16(vget_low_s16(d_top_s16), vget_high_s16(d_top_s16)); // dx0, dx1, dx2, dx3
        int16x4_t dy_top_vals = vuzp2_s16(vget_low_s16(d_top_s16), vget_high_s16(d_top_s16)); // dy0, dy1, dy2, dy3
        int16x8_t dx_top_s16_8 = vcombine_s16(dx_top_vals, dx_top_vals); // Placeholder, needs proper loading for 8 Dx values if next 4 are from dsrc_row0+cn2
        int16x8_t dy_top_s16_8 = vcombine_s16(dy_top_vals, dy_top_vals); // Placeholder

        int16x4_t dx_bot_vals = vuzp1_s16(vget_low_s16(d_bot_s16), vget_high_s16(d_bot_s16));
        int16x4_t dy_bot_vals = vuzp2_s16(vget_low_s16(d_bot_s16), vget_high_s16(d_bot_s16));
        int16x8_t dx_bot_s16_8 = vcombine_s16(dx_bot_vals, dx_bot_vals); // Placeholder
        int16x8_t dy_bot_s16_8 = vcombine_s16(dy_bot_vals, dy_bot_vals); // Placeholder


        int32x4_t ix_s32 = compute_bilinear_interpolation_neon(dx_top_s16_8, dx_bot_s16_8, w00_neon, w01_neon, w10_neon, w11_neon, shift_deriv_neon);
        int32x4_t iy_s32 = compute_bilinear_interpolation_neon(dy_top_s16_8, dy_bot_s16_8, w00_neon, w01_neon, w10_neon, w11_neon, shift_deriv_neon);
        
        int16x4_t ix_s16 = vmovn_s32(ix_s32);
        int16x4_t iy_s16 = vmovn_s32(iy_s32);
        
        int16x4x2_t dI_interleaved;
        dI_interleaved.val[0] = ix_s16;
        dI_interleaved.val[1] = iy_s16;
        vst2_s16(dIptr, dI_interleaved); 

        nA11_vec = vmlal_s16(nA11_vec, ix_s16, ix_s16); 
        nA12_vec = vmlal_s16(nA12_vec, ix_s16, iy_s16);
        nA22_vec = vmlal_s16(nA22_vec, iy_s16, iy_s16);
    }
#endif
    for (; x < currentWinSize.width * cn; ++x) 
    {
      int ival = CV_DESCALE(src_row0[x] * inter_param.iw00 + src_row0[x + cn] * inter_param.iw01 +
                                src_row1[x] * inter_param.iw10 + src_row1[x + cn] * inter_param.iw11,
                            inter_param.w_bits - 5);
      Iptr[x] = static_cast<int16_t>(ival);

      int ixval = CV_DESCALE(dsrc_row0[x*2] * inter_param.iw00 + dsrc_row0[x*2 + cn2] * inter_param.iw01 +
                                 dsrc_row1[x*2] * inter_param.iw10 + dsrc_row1[x*2 + cn2] * inter_param.iw11,
                             inter_param.w_bits);
      int iyval = CV_DESCALE(dsrc_row0[x*2+1] * inter_param.iw00 + dsrc_row0[x*2+1 + cn2] * inter_param.iw01 +
                                 dsrc_row1[x*2+1] * inter_param.iw10 + dsrc_row1[x*2+1 + cn2] * inter_param.iw11,
                             inter_param.w_bits);
      dIptr[x*2] = static_cast<int16_t>(ixval);
      dIptr[x*2+1] = static_cast<int16_t>(iyval);

      iA11 += static_cast<itemtype>(ixval * ixval);
      iA12 += static_cast<itemtype>(ixval * iyval);
      iA22 += static_cast<itemtype>(iyval * iyval);
    }
  } 

#if CV_SSE2
  float CV_DECL_ALIGNED(16) A_buf[4*3]; 
  _mm_store_ps(A_buf, qA11);
  _mm_store_ps(A_buf+4, qA12);
  _mm_store_ps(A_buf+8, qA22);
  iA11 += A_buf[0] + A_buf[1] + A_buf[2] + A_buf[3];
  iA12 += A_buf[4] + A_buf[5] + A_buf[6] + A_buf[7];
  iA22 += A_buf[8] + A_buf[9] + A_buf[10] + A_buf[11];
#elif !CV_SSE2 
  iA11 += vgetq_lane_s32(nA11_vec, 0) + vgetq_lane_s32(nA11_vec, 1) + vgetq_lane_s32(nA11_vec, 2) + vgetq_lane_s32(nA11_vec, 3);
  iA12 += vgetq_lane_s32(nA12_vec, 0) + vgetq_lane_s32(nA12_vec, 1) + vgetq_lane_s32(nA12_vec, 2) + vgetq_lane_s32(nA12_vec, 3);
  iA22 += vgetq_lane_s32(nA22_vec, 0) + vgetq_lane_s32(nA22_vec, 1) + vgetq_lane_s32(nA22_vec, 2) + vgetq_lane_s32(nA22_vec, 3);
#endif

  float A11 = static_cast<float>(iA11) * FLT_SCALE;
  float A12 = static_cast<float>(iA12) * FLT_SCALE;
  float A22 = static_cast<float>(iA22) * FLT_SCALE;

  *(A_ptr + 0) = A11;
  *(A_ptr + 1) = A12;
  *(A_ptr + 2) = A22;

  float D_det = A11 * A22 - A12 * A12; 
  if (D_det < FLT_EPSILON) { 
      *(A_ptr + 3) = 0; 
      *(A_ptr + 4) = 0; 
      // DBG_WK_PYRAMID("Covariance matrix non-invertible or determinant too small. Det: " << D_det);
  } else {
      *(A_ptr + 3) = (A22 + A11 - std::sqrt((A11 - A22) * (A11 - A22) + 4.f * A12 * A12)) / (2.f * currentWinSize.width * currentWinSize.height);
      *(A_ptr + 4) = 1.f / D_det;
  }
  // DBG_WK_PYRAMID("Covariance matrix: A11=" << A11 << ", A12=" << A12 << ", A22=" << A22 << ", minEigNorm=" << *(A_ptr+3) << ", InvDet=" << *(A_ptr+4));
}


void WKTrackerInvoker::operator()(const cv::Range &range) const
{
  const cv::Point2f halfWin((this->winSize.width - 1) * 0.5f, (this->winSize.height - 1) * 0.5f);
  
  const int iter_cache_padding = 4; 
  const cv::Size iter_cache_size(this->winSize.width + 2 * iter_cache_padding, 
                                 this->winSize.height + 2 * iter_cache_padding);
  
  cv::Mat J_patch(iter_cache_size, CV_8UC1); 

  const cv::Point2i half_diff(iter_cache_padding, iter_cache_padding);

  const cv::Mat &I = *prevImg; 
  const cv::Mat &J = *nextImg; 
  
  std::vector<WKKeyPoint> &prevPts_vec = *m_prevPts; 
  std::vector<cv::Point2f> &nextPts_vec = *m_nextPts;
  std::vector<uchar> &status_vec = *m_status;
  std::vector<float> &err_vec = *m_err;

  const int W_BITS = 14; 
  const float FLT_SCALE = 1.f / (1 << 20); 

  int cn = I.channels(); 
  int cn2 = cn * 2;      

  const cv::Rect valid_J_region_for_inextPt(
      half_diff.x, half_diff.y,
      J.cols - iter_cache_size.width, J.rows - iter_cache_size.height
  );
  const cv::Rect valid_I_region_for_iprevPt(
      0, 0, 
      I.cols - this->winSize.width, I.rows - this->winSize.height
  );

  const bool get_min_eigenvals = (flags & cv::OPTFLOW_LK_GET_MIN_EIGENVALS) != 0;

  for (int ptidx = range.start; ptidx < range.end; ++ptidx)
  {
    if (!status_vec[ptidx]) continue; 

    cv::Point2f prevPt_level = prevPts_vec[ptidx].pt * static_cast<float>(1. / (1 << level));
    cv::Point2f nextPt_level;

    if (level == maxLevel) {
      if (flags & cv::OPTFLOW_USE_INITIAL_FLOW)
        nextPt_level = nextPts_vec[ptidx] * static_cast<float>(1. / (1 << level));
      else
        nextPt_level = prevPt_level;
    } else {
      nextPt_level = nextPts_vec[ptidx] * 2.f; 
    }
    nextPts_vec[ptidx] = nextPt_level; 

    // DBG_WK_PYRAMID("Processing ptidx: " << ptidx << " ID: " << prevPts_vec[ptidx].class_id 
    //                << " Level: " << level << " PrevPt_lvl: " << prevPt_level 
    //                << " Initial NextPt_lvl: " << nextPt_level);

    cv::Point2i iprevPt_tl; 
    iprevPt_tl.x = cvFloor(prevPt_level.x - halfWin.x);
    iprevPt_tl.y = cvFloor(prevPt_level.y - halfWin.y);

    if (iprevPt_tl.x < valid_I_region_for_iprevPt.x || iprevPt_tl.y < valid_I_region_for_iprevPt.y ||
        iprevPt_tl.x >= valid_I_region_for_iprevPt.x + valid_I_region_for_iprevPt.width ||
        iprevPt_tl.y >= valid_I_region_for_iprevPt.y + valid_I_region_for_iprevPt.height)
    {
      if (level == start_level) { 
        status_vec[ptidx] = 0;
        err_vec[ptidx] = 0.f;
      }
      // DBG_WK_PYRAMID("ptidx " << ptidx << " iprevPt_tl out of I bounds. iprevPt_tl: " << iprevPt_tl);
      continue;
    }
    
    float subpix_a_prev = prevPt_level.x - halfWin.x - iprevPt_tl.x; 
    float subpix_b_prev = prevPt_level.y - halfWin.y - iprevPt_tl.y;
    int iw00_prev = cvRound((1.f - subpix_a_prev) * (1.f - subpix_b_prev) * (1 << W_BITS));
    int iw01_prev = cvRound(subpix_a_prev * (1.f - subpix_b_prev) * (1 << W_BITS));
    int iw10_prev = cvRound((1.f - subpix_a_prev) * subpix_b_prev * (1 << W_BITS));
    int iw11_prev = (1 << W_BITS) - iw00_prev - iw01_prev - iw10_prev;

    WKKeyPointRepo *kp_repo = &(prevPts_vec[ptidx].keypoint_repo->pyramids[level]);
    
    cv::Mat IWinBuf_mat(this->winSize, CV_MAKETYPE(cv::DataType<deriv_type>::depth, cn), kp_repo->patch);
    cv::Mat derivIWinBuf_mat(this->winSize, CV_MAKETYPE(cv::DataType<deriv_type>::depth, cn2), kp_repo->xy_gradient);

    if (prevPts_vec[ptidx].need_to_update_repo) {
      compute_covariance_matrix_and_update_patch(iprevPt_tl,
                                                 InterpolationParam(iw00_prev, iw01_prev, iw10_prev, iw11_prev, W_BITS),
                                                 &IWinBuf_mat, &derivIWinBuf_mat,
                                                 kp_repo->covariance_maxtrix,
                                                 this->winSize); 
       if (level == start_level) prevPts_vec[ptidx].need_to_update_repo = false; 
    }

    float A11 = kp_repo->covariance_maxtrix[0];
    float A12 = kp_repo->covariance_maxtrix[1];
    float A22 = kp_repo->covariance_maxtrix[2];
    float minEigVal = kp_repo->covariance_maxtrix[3]; 
    float G_inv_det = kp_repo->covariance_maxtrix[4]; 

    if (get_min_eigenvals) err_vec[ptidx] = minEigVal;

    if (minEigVal < minEigThreshold || std::abs(G_inv_det) < FLT_EPSILON) { 
      if (level == start_level) status_vec[ptidx] = 0;
      // DBG_WK_PYRAMID("ptidx " << ptidx << " minEig " << minEigVal << " < thresh or G_inv_det too small. G_inv_det: " << G_inv_det);
      continue;
    }

    cv::Point2f nextPt_patch_tl = nextPt_level - halfWin; 
    cv::Point2f prevDelta(0,0); 

    cv::Point2i J_patch_current_tl_in_J; 

    for (int j_iter = 0; j_iter < criteria.maxCount; ++j_iter)
    {
      cv::Point2i inextPt_tl; 
      inextPt_tl.x = cvFloor(nextPt_patch_tl.x);
      inextPt_tl.y = cvFloor(nextPt_patch_tl.y);

      if (inextPt_tl.x < valid_J_region_for_inextPt.x || inextPt_tl.y < valid_J_region_for_inextPt.y ||
          inextPt_tl.x >= valid_J_region_for_inextPt.x + valid_J_region_for_inextPt.width ||
          inextPt_tl.y >= valid_J_region_for_inextPt.y + valid_J_region_for_inextPt.height)
      {
        if (level == start_level) status_vec[ptidx] = 0;
        // DBG_WK_PYRAMID("ptidx " << ptidx << " iter " << j_iter << " inextPt_tl " << inextPt_tl << " out of J valid region for J_patch.");
        break; 
      }

      cv::Point2i required_J_patch_tl_in_J = inextPt_tl - half_diff;
      if (j_iter == 0 || required_J_patch_tl_in_J != J_patch_current_tl_in_J) {
          J_patch_current_tl_in_J = required_J_patch_tl_in_J;
          cv::Mat J_sub_region = J(cv::Rect(J_patch_current_tl_in_J.x, J_patch_current_tl_in_J.y, iter_cache_size.width, iter_cache_size.height));
          J_sub_region.copyTo(J_patch); 
          // DBG_WK_PYRAMID("ptidx " << ptidx << " iter " << j_iter << " Fetched J_patch from J at " << J_patch_current_tl_in_J);
      }
      
      float subpix_a_next = nextPt_patch_tl.x - inextPt_tl.x;
      float subpix_b_next = nextPt_patch_tl.y - inextPt_tl.y;
      int iw00_next = cvRound((1.f - subpix_a_next) * (1.f - subpix_b_next) * (1 << W_BITS));
      int iw01_next = cvRound(subpix_a_next * (1.f - subpix_b_next) * (1 << W_BITS));
      int iw10_next = cvRound((1.f - subpix_a_next) * subpix_b_next * (1 << W_BITS));
      int iw11_next = (1 << W_BITS) - iw00_next - iw01_next - iw10_next;

      acctype misval_sum_ix = 0, misval_sum_iy = 0; 

#if CV_SSE2
      // SSE variables for this loop were removed due to complexity and reliance on scalar path.
      // __m128i qw0_next = _mm_set1_epi32(iw00_next + (iw01_next << 16));
      // __m128i qw1_next = _mm_set1_epi32(iw10_next + (iw11_next << 16));
      // __m128i z_sse = _mm_setzero_si128();
      // __m128i qdelta_img_sse = _mm_set1_epi32(1 << (W_BITS - 5 - 1));
      // __m128 qb0_unused = _mm_setzero_ps(); // Was qb0, renamed as it's unused by current logic path
      // __m128 qb1_unused = _mm_setzero_ps(); // Was qb1, renamed
#else // NEON
      const int16x4_t w00_next_neon = vdup_n_s16(static_cast<int16_t>(iw00_next));
      const int16x4_t w01_next_neon = vdup_n_s16(static_cast<int16_t>(iw01_next));
      const int16x4_t w10_next_neon = vdup_n_s16(static_cast<int16_t>(iw10_next));
      const int16x4_t w11_next_neon = vdup_n_s16(static_cast<int16_t>(iw11_next));
      const int32x4_t shift_img_next_neon = vdupq_n_s32(-(W_BITS - 5));
      
      int32x4_t n_sum_ix_err = vdupq_n_s32(0);
      int32x4_t n_sum_iy_err = vdupq_n_s32(0);
#endif

      for (int yi = 0; yi < this->winSize.height; ++yi)
      {
        const uchar *Jptr0 = J_patch.ptr<uchar>(yi + half_diff.y);
        const uchar *Jptr1 = J_patch.ptr<uchar>(yi + half_diff.y + 1);
        
        const deriv_type *Ival_ptr = IWinBuf_mat.ptr<deriv_type>(yi); 
        const deriv_type *dI_ptr = derivIWinBuf_mat.ptr<deriv_type>(yi); 

        int xi = 0;
#if CV_SSE2
        // The SSE2 implementation for this inner loop was complex and error-prone for variable winSize.
        // Relying on the scalar loop below for correctness for now.
        // To re-enable, ensure `xi` is incremented correctly and all vars are used.
        // int sse_loop_end_inner = this->winSize.width;
        // if (cn == 1) sse_loop_end_inner = this->winSize.width - (this->winSize.width % 8);
        // for (; xi < sse_loop_end_inner; xi += 8) { /* ... SSE Code ... */ }
#elif !CV_SSE2 // NEON
        int neon_loop_end_inner = this->winSize.width;
        if (cn == 1) neon_loop_end_inner = this->winSize.width - (this->winSize.width % 4);

        for (; xi < neon_loop_end_inner; xi += 4) {
            int16x4_t Ipatch_s16 = vld1_s16(Ival_ptr + xi); 

            uint8x8_t J_u8_0 = vld1_u8(Jptr0 + (xi + half_diff.x)*cn); 
            uint8x8_t J_u8_1 = vld1_u8(Jptr1 + (xi + half_diff.x)*cn);
            int16x8_t J_s16_0 = vreinterpretq_s16_u16(vmovl_u8(J_u8_0));
            int16x8_t J_s16_1 = vreinterpretq_s16_u16(vmovl_u8(J_u8_1));
            int32x4_t J_interp_s32 = compute_bilinear_interpolation_neon(J_s16_0, J_s16_1, w00_next_neon, w01_next_neon, w10_next_neon, w11_next_neon, shift_img_next_neon);
            int16x4_t J_interp_s16 = vmovn_s32(J_interp_s32);

            int16x4_t error_s16_neon = vsub_s16(J_interp_s16, Ipatch_s16); 

            int16x4x2_t IxIy_s16 = vld2_s16(dI_ptr + xi*2); 
            
            n_sum_ix_err = vmlal_s16(n_sum_ix_err, error_s16_neon, IxIy_s16.val[0]);
            n_sum_iy_err = vmlal_s16(n_sum_iy_err, error_s16_neon, IxIy_s16.val[1]);
        }
#endif
        for (; xi < this->winSize.width * cn; ++xi) 
        {
          const uchar* current_J0 = Jptr0 + (xi + half_diff.x)*cn; 
          const uchar* current_J1 = Jptr1 + (xi + half_diff.x)*cn; 

          int J_val = CV_DESCALE(current_J0[0] * iw00_next + current_J0[cn] * iw01_next +
                                   current_J1[0] * iw10_next + current_J1[cn] * iw11_next,
                                 W_BITS - 5);
          int error_val = J_val - Ival_ptr[xi];

          misval_sum_ix += static_cast<acctype>(error_val * dI_ptr[xi*2]);     
          misval_sum_iy += static_cast<acctype>(error_val * dI_ptr[xi*2 + 1]); 
        }
      } 

#if !CV_SSE2 // NEON reduction (SSE part was removed as vars were unused)
      misval_sum_ix += vgetq_lane_s32(n_sum_ix_err,0) + vgetq_lane_s32(n_sum_ix_err,1) + vgetq_lane_s32(n_sum_ix_err,2) + vgetq_lane_s32(n_sum_ix_err,3);
      misval_sum_iy += vgetq_lane_s32(n_sum_iy_err,0) + vgetq_lane_s32(n_sum_iy_err,1) + vgetq_lane_s32(n_sum_iy_err,2) + vgetq_lane_s32(n_sum_iy_err,3);
#endif
      
      float b1 = static_cast<float>(misval_sum_ix) * FLT_SCALE;
      float b2 = static_cast<float>(misval_sum_iy) * FLT_SCALE;

      cv::Point2f delta((A12 * b2 - A22 * b1) * G_inv_det,
                        (A12 * b1 - A11 * b2) * G_inv_det);
      
      nextPt_patch_tl += delta; 
      nextPts_vec[ptidx] = nextPt_patch_tl + halfWin; 

      // DBG_WK_PYRAMID("ptidx " << ptidx << " iter " << j_iter << " b1,b2: (" << b1 << "," << b2 << ") Delta: " << delta << " New NextPt_lvl: " << nextPts_vec[ptidx]);

      if (delta.ddot(delta) <= criteria.epsilon) { 
        // DBG_WK_PYRAMID("ptidx " << ptidx << " iter " << j_iter << " Converged by epsilon.");
        break;
      }
      if (j_iter > 0 && std::abs(delta.x + prevDelta.x) < 0.01 && std::abs(delta.y + prevDelta.y) < 0.01 ) {
          nextPts_vec[ptidx] -= delta * 0.5f; 
          // DBG_WK_PYRAMID("ptidx " << ptidx << " iter " << j_iter << " Oscillation detected, corrected and broke.");
          break;
      }
      prevDelta = delta;
    } 

    if (status_vec[ptidx] && level == start_level && !get_min_eigenvals) {
        cv::Point2f finalNextPt_tl = nextPts_vec[ptidx] - halfWin;
        cv::Point2i iFinalNextPt_tl(cvFloor(finalNextPt_tl.x), cvFloor(finalNextPt_tl.y));

        if (iFinalNextPt_tl.x < 0 || iFinalNextPt_tl.y < 0 ||
            iFinalNextPt_tl.x + this->winSize.width >= J.cols ||
            iFinalNextPt_tl.y + this->winSize.height >= J.rows) {
            status_vec[ptidx] = 0; 
            // DBG_WK_PYRAMID("ptidx " << ptidx << " Final point for error calc out of J bounds.");
            continue;
        }

        float subpix_a_final = finalNextPt_tl.x - iFinalNextPt_tl.x;
        float subpix_b_final = finalNextPt_tl.y - iFinalNextPt_tl.y;
        int iw00_final = cvRound((1.f - subpix_a_final) * (1.f - subpix_b_final) * (1 << W_BITS));
        int iw01_final = cvRound(subpix_a_final * (1.f - subpix_b_final) * (1 << W_BITS));
        int iw10_final = cvRound((1.f - subpix_a_final) * subpix_b_final * (1 << W_BITS));
        int iw11_final = (1 << W_BITS) - iw00_final - iw01_final - iw10_final;
        
        float err_sum = 0.f;
        for (int yi = 0; yi < this->winSize.height; ++yi) {
            const uchar *J_err_ptr0 = J.ptr<uchar>(iFinalNextPt_tl.y + yi) + iFinalNextPt_tl.x * cn;
            const uchar *J_err_ptr1 = J.ptr<uchar>(iFinalNextPt_tl.y + yi + 1) + iFinalNextPt_tl.x * cn;
            const deriv_type *I_err_ptr = IWinBuf_mat.ptr<deriv_type>(yi);

            for (int xi = 0; xi < this->winSize.width * cn; ++xi) { 
                int J_val = CV_DESCALE(J_err_ptr0[xi] * iw00_final + J_err_ptr0[xi + cn] * iw01_final +
                                       J_err_ptr1[xi] * iw10_final + J_err_ptr1[xi + cn] * iw11_final,
                                       W_BITS - 5); 
                err_sum += std::abs(static_cast<float>(J_val - I_err_ptr[xi]));
            }
        }
        err_vec[ptidx] = err_sum / (32.f * this->winSize.width * this->winSize.height * cn);
        // DBG_WK_PYRAMID("ptidx " << ptidx << " Final error: " << err_vec[ptidx]);
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
  if (!_prevPts || !_nextPts || !_status || !_err) {
    CV_Error(cv::Error::StsNullPtr, "Null pointer passed for keypoint/status/error vectors.");
    return;
  }
  if (_prevPyramids.empty() || _nextPyramids.empty() || _prevDivPyramids.empty()) {
     CV_Error(cv::Error::StsBadArg, "Input pyramid vectors are empty.");
     return;
  }
   if (static_cast<int>(_prevPyramids.size()) <= _max_level || 
       static_cast<int>(_nextPyramids.size()) <= _max_level ||
       (_max_level > 0 && static_cast<int>(_prevDivPyramids.size()) <= _max_level && _start_level > 0 && static_cast<int>(_prevDivPyramids.size()) <= _start_level) || // Adjusted check for prevDivPyramids
       _max_level < 0) {
       // If _start_level is 0, _prevDivPyramids[0] might be accessed.
       // If _start_level > 0, then _prevDivPyramids[_start_level ... _max_level] are needed.
       bool divPyrSizeOk = true;
       if (_start_level == 0 && _max_level >=0 && _prevDivPyramids.empty()) divPyrSizeOk = false; // need at least one if level 0 is used
       else if (_start_level > 0 && (static_cast<int>(_prevDivPyramids.size()) <= _max_level || static_cast<int>(_prevDivPyramids.size()) <= _start_level) ) {
            // If start_level > 0, derivatives are needed for levels >= start_level
            // This check might be too strict if only higher levels of DivPyr are used.
            // The loop accesses _prevDivPyramids[level_iter]. We need to ensure this is valid.
       }


      CV_Error(cv::Error::StsBadArg, cv::format("Max pyramid level (%d) is out of bounds for provided pyramids (Prev: %zu, Next: %zu, Div: %zu).", 
                                                _max_level, _prevPyramids.size(), _nextPyramids.size(), _prevDivPyramids.size()));
      return;
  }
   if (_start_level > _max_level || _start_level < 0) {
      CV_Error(cv::Error::StsBadArg, "Start pyramid level is invalid or greater than max level.");
      return;
  }
  if (_win_size.width <= 0 || _win_size.height <= 0 ||
      _win_size.width > MAX_OPTICAL_FLOW_WINDOW_SIZE || _win_size.height > MAX_OPTICAL_FLOW_WINDOW_SIZE) {
      CV_Error(cv::Error::StsBadArg, "Window size is invalid or exceeds MAX_OPTICAL_FLOW_WINDOW_SIZE.");
      return;
  }

  // DBG_WK_PYRAMID("WKcalcOpticalFlowPyrLK started. NumPoints: " << _prevPts->size() 
  //                << " WinSize: " << _win_size.width << "x" << _win_size.height
  //                << " MaxLevel: " << _max_level << " StartLevel: " << _start_level);

  const int npoints = static_cast<int>(_prevPts->size());
  if (npoints == 0) {
    // DBG_WK_PYRAMID("No points to track.");
    return; 
  }

  _nextPts->resize(npoints);
  _status->resize(npoints);
  _err->resize(npoints);

  std::vector<WKKeyPoint> &prevPts_ref = *_prevPts; 
  std::vector<uchar> &status_ref = *_status; // Use a reference for convenience

  for (int i = 0; i < npoints; i++)
  {
    if (!prevPts_ref[i].keypoint_repo) { 
        prevPts_ref[i].allocate();
        prevPts_ref[i].need_to_update_repo = true; 
    }
    status_ref[i] = 1; // Corrected: use status_ref or (*_status)
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

  for (int level_iter = _max_level; level_iter >= _start_level; --level_iter)
  {
    // DBG_WK_PYRAMID("Processing Pyramid Level: " << level_iter);
    
    // Check if pyramid levels are valid before accessing
    // Note: _prevDivPyramids[0] might be intentionally empty if not used by LK at level 0.
    // The invoker will use _prevDivPyramids[level_iter].
    bool divPyrNeeded = true; // Assume needed unless specific logic says otherwise for level 0
    if (level_iter == 0) {
        // If your LK for level 0 doesn't use derivatives, set divPyrNeeded = false
        // Or, ensure _prevDivPyramids[0] is valid if it does.
        // For now, we assume if level_iter is 0, and _prevDivPyramids[0] is accessed, it must be valid.
    }

    if(level_iter >= static_cast<int>(_prevPyramids.size()) || _prevPyramids[level_iter].empty() ||
       level_iter >= static_cast<int>(_nextPyramids.size()) || _nextPyramids[level_iter].empty() ||
       (divPyrNeeded && (level_iter >= static_cast<int>(_prevDivPyramids.size()) || _prevDivPyramids[level_iter].empty())) ) {
        CV_Error(cv::Error::StsBadArg, cv::format("Pyramid data for level %d is missing or empty. (Prev: %d, Next: %d, Div: %d, DivNeeded: %d)", 
            level_iter, 
            (level_iter < static_cast<int>(_prevPyramids.size()) ? !_prevPyramids[level_iter].empty() : 0),
            (level_iter < static_cast<int>(_nextPyramids.size()) ? !_nextPyramids[level_iter].empty() : 0),
            (level_iter < static_cast<int>(_prevDivPyramids.size()) ? !_prevDivPyramids[level_iter].empty() : 0),
            divPyrNeeded
            ));
        for(int i=0; i<npoints; ++i) if(status_ref[i]) status_ref[i] = 0;
        return;
    }
    
    // If _start_level = 0 and _prevDivPyramids[0] is typically not computed by Pyramid class:
    // This is a potential issue. The original code expects _prevDivPyramids[level_iter].
    // If Pyramid class doesn't fill _prevDivPyramids[0], then using start_level=0 will fail here
    // unless the invoker handles a potentially empty prevDeriv for level 0.
    // For now, assume prevDeriv is valid if accessed.

    WKTrackerInvoker invoker(_prevPyramids[level_iter], 
                             _prevDivPyramids[level_iter], // This will be problematic if level_iter=0 and it's empty
                             _nextPyramids[level_iter], _prevPts, _nextPts,
                             _status, _err,
                             _win_size, _criteria, level_iter, _max_level, _start_level, 
                             _flags, static_cast<float>(_minEigThreshold));
    
    invoker(cv::Range(0, npoints));
  }

  if (_start_level > 0) {
    float scaleFactor = static_cast<float>(1 << _start_level);
    // DBG_WK_PYRAMID("Scaling final points from level " << _start_level << " to level 0 by factor " << scaleFactor);
    for (int i = 0; i < npoints; ++i) {
      if (status_ref[i]) { 
        (*_nextPts)[i].x *= scaleFactor;
        (*_nextPts)[i].y *= scaleFactor;
      }
    }
  }
  // DBG_WK_PYRAMID("WKcalcOpticalFlowPyrLK finished.");
}