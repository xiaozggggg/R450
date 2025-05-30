#ifndef OPTICAL_FLOW_H_
#define OPTICAL_FLOW_H_
#include <opencv2/core.hpp>
#include <opencv2/video/tracking.hpp>
#include <boost/pool/object_pool.hpp>
#include <vector>
#include <memory>
#include <iostream> // Added for logging

// #define _WK_OPTICAL_FLOW_DEBUG_MODE_

// Define a maximum window size for buffer allocation in WKKeyPointRepo
// This should be large enough for the desired maximum window size, e.g., 15x15, 21x21, etc.
#define MAX_OPTICAL_FLOW_WINDOW_SIZE 21 

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

// WKKeyPointRepo stores data for a keypoint at a specific pyramid level.
// The patch and xy_gradient buffers are sized for MAX_OPTICAL_FLOW_WINDOW_SIZE.
// The actual winSize used in calculations will determine the portion of these buffers used.
typedef struct _WKKeyPointRepo
{
  // Image patch storage: channels (usually 1 for grayscale) * MAX_OPTICAL_FLOW_WINDOW_SIZE * MAX_OPTICAL_FLOW_WINDOW_SIZE
  int16_t patch[MAX_OPTICAL_FLOW_WINDOW_SIZE * MAX_OPTICAL_FLOW_WINDOW_SIZE];
  float covariance_maxtrix[6]; // covariance matrix
  // XY gradient storage: 2 (for dx, dy) * MAX_OPTICAL_FLOW_WINDOW_SIZE * MAX_OPTICAL_FLOW_WINDOW_SIZE
  int16_t xy_gradient[MAX_OPTICAL_FLOW_WINDOW_SIZE * MAX_OPTICAL_FLOW_WINDOW_SIZE * 2];
} WKKeyPointRepo;

typedef struct _WKKeyPointPyramidRepo
{
  WKKeyPointRepo pyramids[4]; // Assuming max 4 pyramid levels as before
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
    this->keypoint_repo = nullptr; // Initialize shared_ptr
  }
  WKKeyPoint(float _x, float _y)
  {
    this->pt.x = _x;
    this->pt.y = _y;
    this->response = 0.f;
    this->angle = 0.f;
    this->need_to_update_repo = true;
    this->keypoint_repo = nullptr; // Initialize shared_ptr
  }
  explicit WKKeyPoint(const cv::Point2f &pt)
  {
    this->pt = pt;
    this->response = 0.f;
    this->angle = 0.f;
    this->need_to_update_repo = true;
    this->keypoint_repo = nullptr; // Initialize shared_ptr
  }

  explicit WKKeyPoint(const cv::KeyPoint &kp)
  {
    this->pt = kp.pt;
    this->response = kp.response;
    this->angle = kp.angle;
    this->class_id = kp.class_id;
    this->need_to_update_repo = true;
    this->keypoint_repo = nullptr; // Initialize shared_ptr
  }

  static void convert(const std::vector<cv::KeyPoint> &keypoints, std::vector<WKKeyPoint> &WKkpts)
  {
    WKkpts.resize(keypoints.size());
    for (size_t i = 0; i < keypoints.size(); i++)
    {
      // WKkpts[i] = WKKeyPoint(keypoints[i]); // This might try to re-allocate if not careful
      // Safer to copy members and manage shared_ptr explicitly if needed
      WKkpts[i].pt = keypoints[i].pt;
      WKkpts[i].response = keypoints[i].response;
      WKkpts[i].angle = keypoints[i].angle;
      WKkpts[i].class_id = keypoints[i].class_id;
      WKkpts[i].need_to_update_repo = true; // Default for new conversion
      // keypoint_repo should be allocated when needed by calling allocate()
      WKkpts[i].keypoint_repo = nullptr;
    }
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

  WKKeyPoint &operator=(const WKKeyPoint &other)
  {
    if (this != &other)
    {
      this->pt = other.pt;
      this->response = other.response;
      this->angle = other.angle;
      this->class_id = other.class_id; // Make sure class_id is copied
      this->keypoint_repo = other.keypoint_repo;
      this->need_to_update_repo = other.need_to_update_repo;
    }
    return *this;
  }

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
    if (!keypoint_repo) {
        std::cerr << "Error: Failed to allocate WKKeyPointPyramidRepo from pool." << std::endl;
        // Consider throwing an exception or handling error appropriately
    }
  }
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
 * @param[in]  _win_size       window size (e.g., cv::Size(7,7) or cv::Size(15,15))
 * @param[in]  _max_level      the maximum pyramid level, only surpport 4 levels
 * pyramid level = [0, max_level], max_level <= 3
 * @param[in]  _start_level    you can do optical flow start from this level
 * @param[in]  _criteria       termination condition for iteration
 * @param[in]  _flags          flags, e.g., cv::OPTFLOW_USE_INITIAL_FLOW, cv::OPTFLOW_LK_GET_MIN_EIGENVALS
 * @param[in]  _minEigThreshold minimum eigenvalue threshold
 */
void WKcalcOpticalFlowPyrLK(const std::vector<cv::Mat> &_prevPyramids,
                            const std::vector<cv::Mat> &_nextPyramids,
                            const std::vector<cv::Mat> &_prevDivPyramids,
                            std::vector<WKKeyPoint> *_prevPts,
                            std::vector<cv::Point2f> *_nextPts,
                            std::vector<uchar> *_status,
                            std::vector<float> *_err,
                            const cv::Size _win_size = cv::Size(15, 15), // Default, but will be overridden
                            int _max_level = 3, // Adjusted default to match common use (0,1,2,3 means 4 levels)
                            int _start_level = 0, // Default start level
                            cv::TermCriteria _criteria =
                                cv::TermCriteria(cv::TermCriteria::COUNT +
                                                 cv::TermCriteria::EPS,
                                             30, 0.01), // Adjusted criteria
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

  static inline bool is_keypoint_not_in_valid_range(
      const cv::Point2i &pt,
      const cv::Rect &region,
      const cv::Size& winSize, // Added winSize for more accurate boundary checks
      const cv::Size& imageSize // Added imageSize for complete check
      )
  {
    // Check considers top-left corner of the window for the point 'pt'
    // and if the window would go out of bounds of 'region'.
    // 'region' itself should be pre-calculated to be valid within imageSize.
    // For example, region might be image.size() inset by winSize/2 if pt is centered.
    // Or more simply, check if the whole window around pt fits in imageSize.
    int halfW = winSize.width / 2;
    int halfH = winSize.height / 2;

    // Check if the point itself (top-left of patch) is within the image boundary
    // allowing for the full window size.
    if (pt.x < 0 || pt.y < 0 || 
        pt.x + winSize.width >= imageSize.width || 
        pt.y + winSize.height >= imageSize.height) {
        return true; // Point is such that window would be out of image bounds
    }
    // The original check against 'region' might be for a pre-padded region.
    // If 'region' is just the image boundary minus padding:
    // return (pt.x < region.x || pt.x + winSize.width > region.width + region.x ||
    //         pt.y < region.y || pt.y + winSize.height > region.height + region.y);
    // For simplicity, let's assume region is already the valid area for top-left of patch
     return (pt.x < region.x || pt.x >= region.x + region.width ||   // Check if top-left of patch is within region
            pt.y < region.y || pt.y >= region.y + region.height);
    // A more robust check would be:
    // return (pt.x - halfW < 0 || pt.x + halfW + (winSize.width % 2) >= imageSize.width ||
    //         pt.y - halfH < 0 || pt.y + halfH + (winSize.height % 2) >= imageSize.height);
    // But the original code uses region, so we stick to that concept.
    // The key is that the caller must define 'region' correctly based on winSize.
  }


  void operator()(const cv::Range &range) const;

  void compute_covariance_matrix_and_update_patch(
      const cv::Point2i &iprevPt,
      const InterpolationParam &inter_param,
      cv::Mat *IWinBuf,       // This Mat will wrap WKKeyPointRepo::patch
      cv::Mat *derivIWinBuf,  // This Mat will wrap WKKeyPointRepo::xy_gradient
      float *const A_ptr,      // Points to WKKeyPointRepo::covariance_maxtrix
      const cv::Size& currentWinSize // Pass current winSize
      ) const;


  const cv::Mat *prevImg;
  const cv::Mat *nextImg;
  const cv::Mat *prevDeriv;
  std::vector<WKKeyPoint> *m_prevPts;
  std::vector<cv::Point2f> *m_nextPts;
  std::vector<uchar> *m_status;
  std::vector<float> *m_err;

  cv::Size winSize; // This will be the actual, variable window size
  cv::TermCriteria criteria;
  int level;
  int maxLevel;
  int start_level;
  int flags;
  float minEigThreshold;
} WKTrackerInvoker;

#endif // OPTICAL_FLOW_H_