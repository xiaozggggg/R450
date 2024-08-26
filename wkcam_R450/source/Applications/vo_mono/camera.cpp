#include "myslam/camera.h"

namespace myslam {

Camera::Camera() {
}

cv::Mat Camera::world2camera(const cv::Mat &p_w, const cv::Mat &R_c_w, const cv::Mat &t_c_w) {
    return R_c_w * p_w + t_c_w;
}

cv::Mat Camera::camera2world(const cv::Mat &p_c, const cv::Mat &R_c_w, const cv::Mat &t_c_w)
{
    cv::Mat t_w_c = -R_c_w.t()*t_c_w;
    cv::Mat R_w_c = R_c_w.inv();

    return R_w_c * p_c + t_w_c;
}

cv::Mat Camera::camera2pixel(const cv::Mat &p_c)
{
    cv::Mat pi = (cv::Mat_<float>(2, 1) << fx_ * p_c.at<float>(0, 0) / p_c.at<float>(2, 0) + cx_,
                                            fy_ * p_c.at<float>(1, 0) / p_c.at<float>(2, 0) + cy_);
    return pi;
}

cv::Mat Camera::pixel2camera(const cv::Mat &p_p, float depth)
{
    cv::Mat pc = (cv::Mat_<float>(3, 1) << (p_p.at<float>(0) - cx_) * depth / fx_,
                                            (p_p.at<float>(1) - cy_) * depth / fy_,
                                            depth);
    return pc;
}

cv::Mat Camera::world2pixel(const cv::Mat &p_w, const cv::Mat &R_c_w, const cv::Mat &t_c_w) {
    return camera2pixel(world2camera(p_w, R_c_w, t_c_w));
}

cv::Mat Camera::pixel2world(const cv::Mat &p_p, const cv::Mat &R_c_w, const cv::Mat &t_c_w, float depth) {
    return camera2world(pixel2camera(p_p, depth), R_c_w, t_c_w);
}

}
