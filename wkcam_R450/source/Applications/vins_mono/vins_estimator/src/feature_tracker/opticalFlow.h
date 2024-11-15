#ifndef OPTICAL_FLOW_H_
#define OPTICAL_FLOW_H_
#include <opencv2/core.hpp>
#include <opencv2/video/tracking.hpp>
#include <boost/pool/object_pool.hpp>
#include <vector>
#include <memory>

// #define _WK_OPTICAL_FLOW_DEBUG_MODE_

typedef int16_t deriv_type;

typedef struct _interpolation_param
{
  _interpolation_param(int _iw00, int _iw01, int _iw10, int _iw11, int _w_bits = 14) : iw00(_iw00), iw01(_iw01), iw10(_iw10), iw11(_iw11), w_bits(_w_bits) {}
  int iw00;
  int iw01;
  int iw10;
  int iw11;
  int w_bits;
} InterpolationParam;

// only works for win_size(7, 7)
typedef struct _WKKeyPointRepo
{
  int16_t patch[52];           // image patch storage
  float covariance_maxtrix[6]; // covariance matrix
  int16_t xy_gradient[128];    // xy gradient
} WKKeyPointRepo;

typedef struct _WKKeyPointPyramidRepo
{
  WKKeyPointRepo pyramids[4];
} WKKeyPointPyramidRepo;

static boost::object_pool<WKKeyPointPyramidRepo> g_xp_of_tracker_pool;
struct WKKeyPoint : public cv::KeyPoint
{
  WKKeyPoint()
  {
    this->pt.x = 0.f;
    this->pt.y = 0.f;
    this->angle = 0.f;
    this->response = 0.f;
    this->need_to_update_repo = true;
  }
  WKKeyPoint(float _x, float _y)
  {
    this->pt.x = _x;
    this->pt.y = _y;
    this->response = 0.f;
    this->angle = 0.f;
    this->need_to_update_repo = true;
  }
  explicit WKKeyPoint(const cv::Point2f &pt)
  {
    this->pt = pt;
    this->response = 0.f;
    this->angle = 0.f;
    this->need_to_update_repo = true;
  }

  explicit WKKeyPoint(const cv::KeyPoint &kp)
  {
    this->pt = kp.pt;
    this->response = kp.response;
    this->angle = kp.angle;
    this->class_id = kp.class_id;
    this->need_to_update_repo = true;
  }

  static void convert(const std::vector<cv::KeyPoint> &keypoints, std::vector<WKKeyPoint> &WKkpts)
  {
    WKkpts.resize(keypoints.size());
    for (size_t i = 0; i < keypoints.size(); i++)
      WKkpts[i] = WKKeyPoint(keypoints[i]);
  }

  static void convert(const std::vector<WKKeyPoint> WKkpts, std::vector<cv::KeyPoint> &keypoints)
  {
    keypoints.resize(WKkpts.size());
    for (size_t i = 0; i < WKkpts.size(); i++)
    {
      cv::KeyPoint &kp = keypoints[i];
      kp.pt = WKkpts[i].pt;
      kp.response = WKkpts[i].response;
      kp.angle = WKkpts[i].angle;
      kp.class_id = WKkpts[i].class_id;
    }
  }

  // guarantee the patch memory is released
  // when doing WKKeyPoint assignment
  WKKeyPoint &operator=(const WKKeyPoint &other)
  {
    if (this != &other)
    {
      this->pt = other.pt;
      this->response = other.response;
      this->angle = other.angle;
      this->keypoint_repo = other.keypoint_repo;
      this->need_to_update_repo = other.need_to_update_repo;
    }
    return *this;
  }
  // call this function to allocate memory for the patch of this keypoint,
  // if the patch of keypoint has already allocated, this function will not
  // reallocate memory.
  void allocate()
  {
    if (keypoint_repo)
    {
      return;
    }
    keypoint_repo = std::shared_ptr<WKKeyPointPyramidRepo>(
        g_xp_of_tracker_pool.malloc(),
        [](WKKeyPointPyramidRepo *ptr)
        { g_xp_of_tracker_pool.free(ptr); });
  }
  // repository of keypoint, the memory here is automaticcally handled
  std::shared_ptr<WKKeyPointPyramidRepo> keypoint_repo;
  bool need_to_update_repo;
};
/*****************************************************************************
 * @param[in]  _prevPyramids   the pyramids of previous image
 * @param[out] _nextPyramids   the pyramids of current image
 * @param[out] _prevDivPyramids   the pyramids of pre scharr image
 * @param[in]  _prevPts        input keypoints
 * @param[out] _nextPts        output keypoints
 * @param[out] _status         the vector of track status
 * @param[out] _err            the vector of errors
 * @param[in]  win_size        window size, only support 7 x 7 for now
 * @param[in]  max_level       the maximum pyramid level, only surpport 4 levels
 *                             pyramid level = [0, max_level], max_level <= 3
 * @param[in]  start_level     you can do optical flow start from this level
 * @param[in]  criteria        termination condition for iteration
 * @param[in]  flags           not used yet
 * @param[in]  minEigThreshold
 */
void WKcalcOpticalFlowPyrLK(const std::vector<cv::Mat> &_prevPyramids,
                            const std::vector<cv::Mat> &_nextPyramids,
                            const std::vector<cv::Mat> &_prevDivPyramids,
                            std::vector<WKKeyPoint> *_prevPts,
                            std::vector<cv::Point2f> *_nextPts,
                            std::vector<uchar> *_status,
                            std::vector<float> *_err,
                            const cv::Size _win_size = cv::Size(7, 7),
                            int _max_level = 3,
                            int _start_level = 1,
                            cv::TermCriteria _criteria =
                                cv::TermCriteria(cv::TermCriteria::COUNT +
                                                 cv::TermCriteria::EPS,
                                             30, 0.01),
                            int _flags = 0, double _minEigThreshold = 1e-4);

typedef struct WKTrackerInvoker
{
  WKTrackerInvoker(const cv::Mat &_prevImg,
                   const cv::Mat &_prevDeriv,
                   const cv::Mat &_nextImg,
                   std::vector<WKKeyPoint> *_prevPts,
                   std::vector<cv::Point2f> *_nextPts,
                   std::vector<uchar> *_status,
                   std::vector<float> *_err,
                   cv::Size _winSize,
                   cv::TermCriteria _criteria,
                   int _level,
                   int _maxLevel,
                   int _start_level,
                   int _flags, float _minEigThreshold);

  /*************************************************************
   * To decide whether a image point is in a given region
   * @param[in]    pt        a given image point
   * @param[out]   region    a region descriped by cv::Rect
   * @return       bool      true if not in range
   */
  static inline bool is_keypoint_not_in_valid_range(
      const cv::Point2i &pt,
      const cv::Rect &region)
  {
    return (pt.x < region.x || pt.x > region.width + region.x ||
            pt.y < region.y || pt.y > region.height + region.y);
  }

  // Invoke optical flow by operator()
  void operator()(const cv::Range &range) const;
  /*********************************************************************
   * compute covariance matrix and update patch to corresponding keypoint
   * @param[in]  iprevPt      keypoint position
   * @param[in]  inter_param  bilinear interpolation parameter
   * @param[out] IWinBuf      patch after interpolation
   * @param[out] derivIWinBuf gradient patch after interpolation
   * @param[in]  A_ptr        start address of covariance matrix in patch
   */
  void compute_covariance_matrix_and_update_patch(
      const cv::Point2i &iprevPt,
      const InterpolationParam &inter_param,
      cv::Mat *IWinBuf,
      cv::Mat *derivIWinBuf,
      float *const A_ptr) const;

  const cv::Mat *prevImg;
  const cv::Mat *nextImg;
  const cv::Mat *prevDeriv;
  std::vector<WKKeyPoint> *m_prevPts;
  std::vector<cv::Point2f> *m_nextPts;
  std::vector<uchar> *m_status;
  std::vector<float> *m_err;

  cv::Size winSize;
  cv::TermCriteria criteria;
  int level;
  int maxLevel;
  int start_level;
  int flags;
  float minEigThreshold;
} WKTrackerInvoker;

#endif // OPTICAL_FLOW_H_
