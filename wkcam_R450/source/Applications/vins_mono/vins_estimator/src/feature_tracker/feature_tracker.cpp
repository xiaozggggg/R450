#include "opticalFlow.h"
#include "feature_tracker.h"

int FeatureTracker::n_id = 0;

bool inBorder(const cv::Point2f &pt)
{
    const int BORDER_SIZE = 1;
    int img_x = cvRound(pt.x);
    int img_y = cvRound(pt.y);
    return BORDER_SIZE <= img_x && img_x < COL - BORDER_SIZE && BORDER_SIZE <= img_y && img_y < ROW - BORDER_SIZE;
}

void reduceVector(vector<cv::KeyPoint> &v, vector<uchar> status)
{
    int j = 0;
    for (int i = 0; i < int(v.size()); i++)
        if (status[i])
            v[j++] = v[i];
    v.resize(j);
}

void reduceVector(vector<int> &v, vector<uchar> status)
{
    int j = 0;
    for (int i = 0; i < int(v.size()); i++)
        if (status[i])
            v[j++] = v[i];
    v.resize(j);
}

FeatureTracker::FeatureTracker()
{
}
FeatureTracker::~FeatureTracker()
{
    // delete img_pyr_;
    // delete deature_detector_;
}

void FeatureTracker::setPara(cv::Size img_size, int track_level)
{
    track_level_ = track_level;
    img_pyr_ = new Pyramid(img_size, track_level);
    deature_detector_ = new FeatureDetector(img_size);
}

void FeatureTracker::addPoints(const vector<cv::KeyPoint>& pts)
{
    for (auto &p : pts)
    {
        if(inBorder(p.pt))
        {
        cur_pts.push_back(p);
        ids.push_back(-1);
        track_cnt.push_back(1);
        }
    }
}

int FeatureTracker::readImage(const cv::Mat &_img)
{
    cv::Mat img;
    TicToc t_r;

    img_pyr_->build_pyramids(&_img);
    int track_num = 0;

    if (prev_pts.size() > 0)
    {
        TicToc t_o;
        vector<uchar> status;
        vector<float> err;
        std::vector<cv::Point2f> cur_temp;

        std::vector<WKKeyPoint> pre_temp;
        WKKeyPoint::convert(prev_pts, pre_temp);
        WKcalcOpticalFlowPyrLK(img_pyr_->getPreImgPyr(),
                               img_pyr_->getCurrImgPyr(),
                               img_pyr_->getPreDivPyr(),
                               &pre_temp,
                               &cur_temp,
                               &status,
                               &err,
                               cv::Size(21, 21),
                               MaxPyraLevel,
                               track_level_);
        // std::vector<cv::Point2f> pre_temp;
        // cv::KeyPoint::convert(prev_pts,pre_temp);
        // cv::calcOpticalFlowPyrLK(img_pyr_->getPrePyrImg(0), img_pyr_->getCurrPyrImg(0), pre_temp, cur_temp, status, err, cv::Size(21, 21), 5);

        assert(cur_pts.size() == cur_temp.size());
        for (int i = 0; i < cur_temp.size(); i++)
        {
            if (status[i])
            {
                cur_pts[i].pt = cur_temp[i];
                cur_pts[i].response = prev_pts[i].response;

                if (!inBorder(cur_temp[i]))
                    status[i] = 0;
            }
        }
        assert(prev_pts.size() == cur_pts.size());
        assert(ids.size() == cur_pts.size());
        assert(ids.size() == track_cnt.size());
        assert(status.size() == track_cnt.size());
        reduceVector(prev_pts, status);
        reduceVector(cur_pts, status);
        reduceVector(ids, status);
        reduceVector(track_cnt, status);
        track_num = track_cnt.size();
    }

    rejectWithF();
    
    // 添加极线误差检查
    TicToc t_epipolar;
    rejectWithEpipolarError();
    std::cout << "极线误差检查耗时: " << t_epipolar.toc() << " ms" << std::endl;

    vector<uchar> status;
    deature_detector_->PutOldPtsInGrid(cur_pts, status);
    reduceVector(prev_pts, status);
    reduceVector(cur_pts, status);
    reduceVector(ids, status);
    reduceVector(track_cnt, status);

    for (auto &n : track_cnt)
        n++;

    TicToc t_t;
    int n_max_cnt = MAX_CNT - static_cast<int>(cur_pts.size());
    n_pts.clear();
    if (n_max_cnt > 0)
    {
        deature_detector_->DetectNewPts(img_pyr_->getCurrImgPyr(), cur_pts, n_pts, n_max_cnt);
        std::cout << "########xzg feature detect: " << t_t.toc() << " n_max_cnt: " << n_max_cnt << " n_pts.size(): " << n_pts.size() << std::endl;
    }

    TicToc t_a;
    addPoints(n_pts);

    img_pyr_->update_img_pyramids();
    prev_pts = cur_pts;

    return track_num;
}

// 5. 添加设置极线误差阈值的函数（可选）
void FeatureTracker::setEpipolarThreshold(double threshold)
{
    epipolar_threshold_ = threshold;
}
void FeatureTracker::rejectWithF()
{
    if (cur_pts.size() >= 8)
    {
        vector<uchar> status;

        TicToc t_f;
        vector<cv::Point2f> un_prev_pts(prev_pts.size()), un_forw_pts(cur_pts.size());
        for (unsigned int i = 0; i < prev_pts.size(); i++)
        {
            Eigen::Vector3d tmp_p;
            m_camera->liftProjective(Eigen::Vector2d(prev_pts[i].pt.x, prev_pts[i].pt.y), tmp_p);
            tmp_p.x() = FOCAL_LENGTH * tmp_p.x() / tmp_p.z() + COL / 2.0;
            tmp_p.y() = FOCAL_LENGTH * tmp_p.y() / tmp_p.z() + ROW / 2.0;
            un_prev_pts[i] = cv::Point2f(tmp_p.x(), tmp_p.y());

            m_camera->liftProjective(Eigen::Vector2d(cur_pts[i].pt.x, cur_pts[i].pt.y), tmp_p);
            tmp_p.x() = FOCAL_LENGTH * tmp_p.x() / tmp_p.z() + COL / 2.0;
            tmp_p.y() = FOCAL_LENGTH * tmp_p.y() / tmp_p.z() + ROW / 2.0;
            un_forw_pts[i] = cv::Point2f(tmp_p.x(), tmp_p.y());
        }

        // 计算基础矩阵并保存
        fundamental_matrix_ = cv::findFundamentalMat(un_prev_pts, un_forw_pts, cv::FM_RANSAC, F_THRESHOLD, 0.99, status);
        
        int size_a = prev_pts.size();
        assert(prev_pts.size() == cur_pts.size());
        assert(ids.size() == cur_pts.size());
        assert(ids.size() == track_cnt.size());
        reduceVector(prev_pts, status);
        reduceVector(cur_pts, status);
        reduceVector(ids, status);
        reduceVector(track_cnt, status);


    }
}

// 2. 实现计算单个点对极线误差的函数
double FeatureTracker::computeEpipolarError(const cv::Point2f& pt1, const cv::Point2f& pt2, const cv::Mat& F)
{
    // 将点转换为归一化平面坐标
    Eigen::Vector3d p1_3d, p2_3d;
    m_camera->liftProjective(Eigen::Vector2d(pt1.x, pt1.y), p1_3d);
    m_camera->liftProjective(Eigen::Vector2d(pt2.x, pt2.y), p2_3d);
    
    // 转换到虚拟归一化相机坐标
    cv::Point3f p1_norm(FOCAL_LENGTH * p1_3d.x() / p1_3d.z() + COL / 2.0,
                        FOCAL_LENGTH * p1_3d.y() / p1_3d.z() + ROW / 2.0, 1.0);
    cv::Point3f p2_norm(FOCAL_LENGTH * p2_3d.x() / p2_3d.z() + COL / 2.0,
                        FOCAL_LENGTH * p2_3d.y() / p2_3d.z() + ROW / 2.0, 1.0);
    
    // 计算极线 l = F * p1
    cv::Mat p1_mat = (cv::Mat_<double>(3, 1) << p1_norm.x, p1_norm.y, 1.0);
    cv::Mat l = F * p1_mat;
    
    // 计算点到极线的距离: |ax + by + c| / sqrt(a^2 + b^2)
    double a = l.at<double>(0);
    double b = l.at<double>(1);
    double c = l.at<double>(2);
    
    double dist = std::abs(a * p2_norm.x + b * p2_norm.y + c) / std::sqrt(a * a + b * b);
    
    return dist;
}

// 3. 实现极线误差检查函数
void FeatureTracker::rejectWithEpipolarError()
{
    if (fundamental_matrix_.empty() || cur_pts.size() < 8)
    {
        std::cout << "跳过极线误差检查：基础矩阵为空或点数不足" << std::endl;
        return;
    }
    
    vector<uchar> status(cur_pts.size(), 1);
    vector<double> epipolar_errors;
    epipolar_errors.reserve(cur_pts.size());
    
    // 计算每个点对的极线误差
    for (size_t i = 0; i < cur_pts.size(); i++)
    {
        double error = computeEpipolarError(prev_pts[i].pt, cur_pts[i].pt, fundamental_matrix_);
        epipolar_errors.push_back(error);
        
        // 如果误差超过阈值，标记为异常点
        if (error > epipolar_threshold_)
        {
            status[i] = 0;
        }
    }
    
    // 统计信息
    int rejected_count = 0;
    double sum_error = 0.0;
    double max_error = 0.0;
    for (size_t i = 0; i < status.size(); i++)
    {
        sum_error += epipolar_errors[i];
        max_error = std::max(max_error, epipolar_errors[i]);
        if (status[i] == 0) rejected_count++;
    }
    
    double avg_error = sum_error / epipolar_errors.size();
    
    // std::cout << "极线误差检查统计:" << std::endl;
    // std::cout << "  - 平均误差: " << avg_error << " 像素" << std::endl;
    // std::cout << "  - 最大误差: " << max_error << " 像素" << std::endl;
    // std::cout << "  - 误差阈值: " << epipolar_threshold_ << " 像素" << std::endl;
    // std::cout << "  - 剔除点数: " << rejected_count << "/" << cur_pts.size() 
            //   << " (" << (100.0 * rejected_count / cur_pts.size()) << "%)" << std::endl;
    
    // 剔除不满足极线约束的点
    if (rejected_count > 0)
    {
        reduceVector(prev_pts, status);
        reduceVector(cur_pts, status);
        reduceVector(ids, status);
        reduceVector(track_cnt, status);
    }
}

bool FeatureTracker::updateID(unsigned int i)
{
    if (i < ids.size())
    {
        if (ids[i] == -1)
            ids[i] = n_id++;
        return true;
    }
    else
        return false;
}

void FeatureTracker::readIntrinsicParameter(const string &calib_file)
{
  //  ROS_INFO("reading paramerter of camera %s", calib_file.c_str());
   cout << "reading paramerter of camera " <<  calib_file.c_str() <<endl;
    m_camera = CameraFactory::instance()->generateCameraFromYamlFile(calib_file);
}

void FeatureTracker::showUndistortion(const string &name)
{
    cv::Mat undistortedImg(ROW + 600, COL + 600, CV_8UC1, cv::Scalar(0));
    vector<Eigen::Vector2d> distortedp, undistortedp;
    for (int i = 0; i < COL; i++)
        for (int j = 0; j < ROW; j++)
        {
            Eigen::Vector2d a(i, j);
            Eigen::Vector3d b;
            m_camera->liftProjective(a, b);
            distortedp.push_back(a);
            undistortedp.push_back(Eigen::Vector2d(b.x() / b.z(), b.y() / b.z()));
            //printf("%f,%f->%f,%f,%f\n)\n", a.x(), a.y(), b.x(), b.y(), b.z());
        }
    for (int i = 0; i < int(undistortedp.size()); i++)
    {
        cv::Mat pp(3, 1, CV_32FC1);
        pp.at<float>(0, 0) = undistortedp[i].x() * FOCAL_LENGTH + COL / 2;
        pp.at<float>(1, 0) = undistortedp[i].y() * FOCAL_LENGTH + ROW / 2;
        pp.at<float>(2, 0) = 1.0;
        //cout << trackerData[0].K << endl;
        //printf("%lf %lf\n", p.at<float>(1, 0), p.at<float>(0, 0));
        //printf("%lf %lf\n", pp.at<float>(1, 0), pp.at<float>(0, 0));
        if (pp.at<float>(1, 0) + 300 >= 0 && pp.at<float>(1, 0) + 300 < ROW + 600 && pp.at<float>(0, 0) + 300 >= 0 && pp.at<float>(0, 0) + 300 < COL + 600)
        {
            undistortedImg.at<uchar>(pp.at<float>(1, 0) + 300, pp.at<float>(0, 0) + 300) = img_pyr_->getCurrPyrImg(0).at<uchar>(distortedp[i].y(), distortedp[i].x());
        }
        else
        {
            //ROS_ERROR("(%f %f) -> (%f %f)", distortedp[i].y, distortedp[i].x, pp.at<float>(1, 0), pp.at<float>(0, 0));
        }
    }
    cv::imshow(name, undistortedImg);
    cv::waitKey(0);
}

vector<cv::Point2f> FeatureTracker::undistortedPoints()
{
    vector<cv::Point2f> un_pts;
    //cv::undistortPoints(cur_pts, un_pts, K, cv::Mat());
    for (unsigned int i = 0; i < cur_pts.size(); i++)
    {
        Eigen::Vector2d a(cur_pts[i].pt.x, cur_pts[i].pt.y);
        Eigen::Vector3d b;
        m_camera->liftProjective(a, b);
        un_pts.push_back(cv::Point2f(b.x() / b.z(), b.y() / b.z()));
    }

    return un_pts;
}
