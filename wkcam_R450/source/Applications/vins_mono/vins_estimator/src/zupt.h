#pragma once

#include <memory>
#include <vector>
#include <map>
#include <Eigen/Dense>
#include <boost/math/distributions/chi_squared.hpp>
#include "parameters.h"

struct ImuData {
    double timestamp;
    Eigen::Vector3d am;  // 线性加速度测量值
    Eigen::Vector3d wm;  // 角速度测量值
    
    ImuData(double t, const Eigen::Vector3d& acc, const Eigen::Vector3d& gyr) 
        : timestamp(t), am(acc), wm(gyr) {}
};

class Estimator;

/**
 * @brief 零速更新检测和更新类
 * 
 * 当系统静止时检测零速状态并进行相应的状态更新
 * 主要用于车载等需要停车的场景
 */
class UpdaterZeroVelocity {
public:
    /**
     * @brief 构造函数
     * @param gravity_mag 重力加速度大小 (通常是9.81)
     * @param zupt_max_velocity 执行零速更新的最大速度阈值
     * @param zupt_noise_multiplier IMU噪声倍数 (默认1.0)
     * @param zupt_max_disparity 执行零速更新的最大视差阈值
     * @param chi2_multiplier 卡方检验倍数
     */
    UpdaterZeroVelocity(double gravity_mag = 9.81, 
                       double zupt_max_velocity = 0.5,
                       double zupt_noise_multiplier = 2.0, 
                       double zupt_max_disparity = 1.0,
                       double chi2_multiplier = 1.0);

    size_t getIMUDataSize() const { return imu_data.size(); }

    /**
     * @brief 输入IMU数据
     * @param timestamp 时间戳
     * @param linear_acceleration 线性加速度
     * @param angular_velocity 角速度
     */
    void feed_imu(double timestamp, const Eigen::Vector3d& linear_acceleration, 
                  const Eigen::Vector3d& angular_velocity);

    /**
     * @brief 尝试零速更新
     * @param estimator 估计器指针
     * @param timestamp 当前时间戳
     * @return 如果执行了零速更新返回true
     */
    bool try_update(Estimator* estimator, double timestamp);

    /**
     * @brief 清理旧的IMU数据
     * @param oldest_time 最早保留时间
     */
    void clean_old_imu_measurements(double oldest_time);

    /**
     * @brief 获取当前状态是否为零速
     */
    bool is_zero_velocity() const { return last_zupt_count > 0; }

    /**
     * @brief 重置零速检测状态
     */
    void reset_zupt_state() {
        last_zupt_count = 0;
        last_zupt_state_timestamp = 0.0;
    }

    /**
     * @brief 执行卡方一致性检验
     * @param estimator 估计器指针
     * @param imu_recent 最近的IMU数据
     * @param R_ItoG 当前旋转矩阵
     * @param bg 陀螺仪偏置
     * @param ba 加速度计偏置
     * @return 如果通过检验返回true
     */
    bool perform_chi2_test(Estimator* estimator,
                          const std::vector<ImuData>& imu_recent,
                          const Eigen::Matrix3d& R_ItoG,
                          const Eigen::Vector3d& bg,
                          const Eigen::Vector3d& ba);

private:
    /// 重力向量
    Eigen::Vector3d _gravity;

    /// 零速更新参数
    double _zupt_max_velocity;        // 最大速度阈值
    double _zupt_noise_multiplier;    // 噪声倍数
    double _zupt_max_disparity;       // 最大视差阈值
    double _chi2_multiplier;          // 卡方检验倍数

    /// IMU噪声参数
    double _sigma_w;   // 陀螺仪白噪声
    double _sigma_a;   // 加速度计白噪声
    double _sigma_wb;  // 陀螺仪随机游走
    double _sigma_ab;  // 加速度计随机游走

    /// 卡方分布查找表
    std::map<int, double> chi_squared_table;

    /// IMU数据历史
    std::vector<ImuData> imu_data;

    /// 状态变量
    double last_zupt_state_timestamp = 0.0;
    int last_zupt_count = 0;
    double last_prop_time_offset = 0.0;
    bool have_last_prop_time_offset = false;

    /**
     * @brief 初始化卡方分布表
     */
    void init_chi_squared_table();

    /**
     * @brief 选择IMU数据段
     */
    std::vector<ImuData> select_imu_readings(double time0, double time1);

    /**
     * @brief 计算视差统计
     */
    bool check_disparity(Estimator* estimator, double time0, double time1);

    /**
     * @brief 执行零速更新的核心逻辑
     */
    bool perform_zupt_update(Estimator* estimator, const std::vector<ImuData>& imu_recent, 
                           double dt_summed, double timestamp);

    /**
     * @brief 压缩测量矩阵（QR分解）
     */
    void measurement_compress(Eigen::MatrixXd& H, Eigen::VectorXd& res);
};