#include "zupt.h"
#include "estimator.h"
#include <iostream>
#include <algorithm>

UpdaterZeroVelocity::UpdaterZeroVelocity(double gravity_mag, 
                                       double zupt_max_velocity,
                                       double zupt_noise_multiplier, 
                                       double zupt_max_disparity,
                                       double chi2_multiplier)
    : _zupt_max_velocity(zupt_max_velocity)
    , _zupt_noise_multiplier(zupt_noise_multiplier)
    , _zupt_max_disparity(zupt_max_disparity)
    , _chi2_multiplier(chi2_multiplier)
{
    // 设置重力向量
    _gravity << 0.0, 0.0, gravity_mag;

    // 设置IMU噪声参数 (从全局参数获取)
    _sigma_w = GYR_N;
    _sigma_a = ACC_N;
    _sigma_wb = GYR_W;
    _sigma_ab = ACC_W;

    // 初始化卡方分布表
    init_chi_squared_table();

    std::cout << "[ZUPT] 零速更新模块初始化完成" << std::endl;
    std::cout << "[ZUPT] 最大速度阈值: " << _zupt_max_velocity << " m/s" << std::endl;
    std::cout << "[ZUPT] 最大视差阈值: " << _zupt_max_disparity << " pixels" << std::endl;
}

void UpdaterZeroVelocity::init_chi_squared_table() {
    // 初始化卡方分布表，置信度95%
    for (int i = 1; i < 1000; i++) {
        boost::math::chi_squared chi_squared_dist(i);
        chi_squared_table[i] = boost::math::quantile(chi_squared_dist, 0.95);
    }
}

void UpdaterZeroVelocity::feed_imu(double timestamp, const Eigen::Vector3d& linear_acceleration, 
                                  const Eigen::Vector3d& angular_velocity) {
    imu_data.emplace_back(timestamp, linear_acceleration, angular_velocity);
    
    // 保留合理的历史数据（3秒）
    clean_old_imu_measurements(timestamp - 3.0);
}

void UpdaterZeroVelocity::clean_old_imu_measurements(double oldest_time) {
    if (oldest_time < 0) return;
    
    auto it = imu_data.begin();
    while (it != imu_data.end()) {
        if (it->timestamp < oldest_time) {
            it = imu_data.erase(it);
        } else {
            ++it;
        }
    }
}

std::vector<ImuData> UpdaterZeroVelocity::select_imu_readings(double time0, double time1) {
    std::vector<ImuData> selected;
    
    for (const auto& data : imu_data) {
        if (data.timestamp >= time0 && data.timestamp <= time1) {
            selected.push_back(data);
        }
    }
    
    // 按时间排序
    std::sort(selected.begin(), selected.end(), 
              [](const ImuData& a, const ImuData& b) {
                  return a.timestamp < b.timestamp;
              });
    
    return selected;
}
// 新增：单独的卡方检验函数
bool UpdaterZeroVelocity::perform_chi2_test(Estimator* estimator,
                                           const std::vector<ImuData>& imu_recent,
                                           const Eigen::Matrix3d& R_ItoG,
                                           const Eigen::Vector3d& bg,
                                           const Eigen::Vector3d& ba) {
    
    // 构建检验统计量
    int m_size = 6 * ((int)imu_recent.size() - 1);
    Eigen::VectorXd res = Eigen::VectorXd::Zero(m_size);
    
    // 在零速假设下，计算残差
    for (size_t i = 0; i < imu_recent.size() - 1; i++) {
        double dt = imu_recent[i + 1].timestamp - imu_recent[i].timestamp;
        
        // 角速度残差：测量值应该等于偏置
        Eigen::Vector3d w_res = (imu_recent[i].wm - bg) / (_sigma_w / std::sqrt(dt));
        
        // 加速度残差：测量值应该等于旋转后的重力加偏置
        Eigen::Vector3d expected_acc = R_ItoG.transpose() * _gravity;
        Eigen::Vector3d a_res = (imu_recent[i].am - ba - expected_acc) / (_sigma_a / std::sqrt(dt));
        
        res.segment<3>(6*i) = w_res;
        res.segment<3>(6*i + 3) = a_res;
    }
    
    // 计算卡方统计量
    double chi2 = res.squaredNorm();
    
    // 获取阈值
    int dof = res.size();
    double chi2_threshold = chi_squared_table[std::min(dof, 999)] * _chi2_multiplier;
    
    // std::cout << "[ZUPT] 卡方检验: chi2 = " << chi2 
    //           << ", 阈值 = " << chi2_threshold 
    //           << " (自由度: " << dof << ")" << std::endl;
    
    return (chi2 < chi2_threshold);
}

// 改进的视差检查
bool UpdaterZeroVelocity::check_disparity(Estimator* estimator, double time0, double time1) {
    // 获取当前跟踪的特征点数量
    int tracked_features = estimator->f_manager.last_track_num;
    
    // std::cout << "[ZUPT] 跟踪特征点数: " << tracked_features << std::endl;
    
    // 如果特征点太少，依赖IMU判断
    if (tracked_features < 10) {
        // std::cout << "[ZUPT] 特征点不足，仅依赖IMU判断" << std::endl;
        return true;  // 交给IMU判断
    }
    
    // 计算特征点运动统计
    std::vector<double> parallax_values;
    double max_parallax = 0.0;
    
    for (auto& feature : estimator->f_manager.feature) {
        if (feature.feature_per_frame.size() >= 2) {
            size_t n = feature.feature_per_frame.size();
            
            // 计算最近两帧的视差
            Eigen::Vector3d p1 = feature.feature_per_frame[n-2].point;
            Eigen::Vector3d p2 = feature.feature_per_frame[n-1].point;
            
            double parallax = (p1.head<2>() - p2.head<2>()).norm() * FOCAL_LENGTH;
            parallax_values.push_back(parallax);
            max_parallax = std::max(max_parallax, parallax);
        }
    }
    
    if (parallax_values.empty()) {
        return true;  // 没有可用特征，交给IMU判断
    }
    
    // 排序并取中位数
    std::sort(parallax_values.begin(), parallax_values.end());
    double median_parallax = parallax_values[parallax_values.size() / 2];
    
    // 基于中位数和最大值判断
    bool median_check = (median_parallax < _zupt_max_disparity);
    
    // std::cout << "[ZUPT] 视差统计 - 中位数: " << median_parallax 
    //           << ", 最大值: " << max_parallax 
    //           << " pixels" << std::endl;
    
    return median_check;
}

bool UpdaterZeroVelocity::try_update(Estimator* estimator, double timestamp) {
    
    // 检查IMU数据是否足够
    if (imu_data.empty()) {
        // std::cout << "[ZUPT] IMU数据为空，跳过零速检测" << std::endl;
        last_zupt_state_timestamp = 0.0;
        return false;
    }

    double current_time = timestamp;
    
    // 时间窗口选择
    double time_window = 0.5;  // 500ms窗口
    double time1 = current_time;
    double time0 = time1 - time_window;

    // 获取IMU数据
    std::vector<ImuData> imu_recent = select_imu_readings(time0, time1);
    
    // std::cout << "[ZUPT] 时间窗口 [" << time0 << ", " << time1 
    //           << "], IMU数据点数: " << imu_recent.size() << std::endl;
    
    if (imu_recent.size() < 10) {
        // std::cout << "[ZUPT] IMU数据不足，需要至少10个点" << std::endl;
        last_zupt_state_timestamp = 0.0;
        return false;
    }

    // =============================================================
    // 1. 基于IMU原始测量的零速检测（主要判据）
    // =============================================================
    
    // 获取当前偏置估计
    Eigen::Vector3d bg = estimator->Bgs[WINDOW_SIZE];
    Eigen::Vector3d ba = estimator->Bas[WINDOW_SIZE];
    Eigen::Matrix3d R_ItoG = estimator->Rs[WINDOW_SIZE];
    
    // 计算IMU测量统计
    Eigen::Vector3d acc_mean = Eigen::Vector3d::Zero();
    Eigen::Vector3d gyr_mean = Eigen::Vector3d::Zero();
    
    for (const auto& imu : imu_recent) {
        acc_mean += imu.am;
        gyr_mean += imu.wm;
    }
    acc_mean /= imu_recent.size();
    gyr_mean /= imu_recent.size();
    
    // 计算标准差
    double acc_var = 0.0;
    double gyr_var = 0.0;
    
    for (const auto& imu : imu_recent) {
        acc_var += (imu.am - acc_mean).squaredNorm();
        gyr_var += (imu.wm - gyr_mean).squaredNorm();
    }
    acc_var /= (imu_recent.size() - 1);
    gyr_var /= (imu_recent.size() - 1);
    
    double acc_std = std::sqrt(acc_var);
    double gyr_std = std::sqrt(gyr_var);
    
    // std::cout << "[ZUPT] IMU统计 - 加速度: 均值=" << acc_mean.norm() 
    //           << " m/s^2, 标准差=" << acc_std << " m/s^2" << std::endl;
    // std::cout << "[ZUPT] IMU统计 - 角速度: 均值=" << gyr_mean.norm() 
    //           << " rad/s, 标准差=" << gyr_std << " rad/s" << std::endl;
    
    // 静止时的判断条件
    // 1) 角速度应该接近偏置值
    double gyr_norm_corrected = (gyr_mean - bg).norm();
    bool gyr_check = (gyr_norm_corrected < 0.05) && (gyr_std < 0.02);  // rad/s
    
    // 2) 加速度应该接近重力（考虑旋转）
    Eigen::Vector3d expected_acc = R_ItoG.transpose() * _gravity + ba;
    double acc_error = (acc_mean - expected_acc).norm();
    bool acc_check = (acc_error < 0.3) && (acc_std < 0.1);  // m/s^2
    
    // std::cout << "[ZUPT] 角速度偏差: " << gyr_norm_corrected 
    //           << " rad/s (阈值: 0.05)" << std::endl;
    // std::cout << "[ZUPT] 加速度偏差: " << acc_error 
    //           << " m/s^2 (阈值: 0.3)" << std::endl;
    
    if (!gyr_check || !acc_check) {
        std::cout << "[ZUPT] IMU检测失败 - 角速度检查: " << (gyr_check ? "通过" : "失败")
                  << ", 加速度检查: " << (acc_check ? "通过" : "失败") << std::endl;
        reset_zupt_state();
        return false;
    }

    // =============================================================
    // 2. 基于视觉特征的运动检测（辅助判据）
    // =============================================================
    
    // bool vision_check = check_disparity(estimator, time0, time1);
    // if (!vision_check) {
    //     std::cout << "[ZUPT] 视觉检测到运动，不执行零速更新" << std::endl;
    //     reset_zupt_state();
    //     return false;
    // }

    // =============================================================
    // 3. 基于零速假设的卡方一致性检验
    // =============================================================
    
    // 在零速假设下，检验IMU测量是否一致
    bool chi2_check = perform_chi2_test(estimator, imu_recent, R_ItoG, bg, ba);
    
    if (!chi2_check) {
        std::cout << "[ZUPT] 卡方检验失败，测量不符合零速假设" << std::endl;
        reset_zupt_state();
        return false;
    }

    // =============================================================
    // 4. 速度参考（仅作为辅助，不作为主要判据）
    // =============================================================
    
    Eigen::Vector3d current_velocity = estimator->Vs[WINDOW_SIZE];
    double velocity_norm = current_velocity.norm();
    
    // 如果速度很大，增加额外的确认
    if (velocity_norm > 2.0) {  // 2 m/s
        std::cout << "[ZUPT] 警告：当前速度较大 (" << velocity_norm 
                  << " m/s)，但IMU显示静止" << std::endl;
        
        // 需要更多连续检测
        if (last_zupt_count < 5) {
            last_zupt_count++;
            std::cout << "[ZUPT] 需要更多连续检测，当前次数: " << last_zupt_count << std::endl;
            return false;
        }
    } else {
        // 正常情况下需要3次连续检测
        if (last_zupt_count < 3) {
            last_zupt_count++;
            std::cout << "[ZUPT] 零速检测通过，连续次数: " << last_zupt_count << std::endl;
            return false;
        }
    }

    // =============================================================
    // 5. 执行零速更新
    // =============================================================
    
    std::cout << "[ZUPT] ========== 执行零速更新 ==========" << std::endl;
    std::cout << "[ZUPT] 更新前速度: " << velocity_norm << " m/s" << std::endl;
    
    // 设置速度为零
    estimator->Vs[WINDOW_SIZE].setZero();
    
    // 基于静止假设更新偏置
    // 静止时：角速度测量 = 偏置
    //        加速度测量 = 旋转后的重力 + 偏置
    Eigen::Vector3d bg_update = 0.1 * (gyr_mean - bg);  // 10%增益
    Eigen::Vector3d expected_acc_in_imu = R_ItoG.transpose() * _gravity;
    Eigen::Vector3d ba_update = 0.1 * (acc_mean - expected_acc_in_imu - ba);
    
    estimator->Bgs[WINDOW_SIZE] += bg_update;
    estimator->Bas[WINDOW_SIZE] += ba_update;
    
    // 限制偏置范围
    if (estimator->Bgs[WINDOW_SIZE].norm() > BIAS_GYR_THRESHOLD) {
        estimator->Bgs[WINDOW_SIZE] = estimator->Bgs[WINDOW_SIZE].normalized() * BIAS_GYR_THRESHOLD;
    }
    
    if (estimator->Bas[WINDOW_SIZE].norm() > BIAS_ACC_THRESHOLD) {
        estimator->Bas[WINDOW_SIZE] = estimator->Bas[WINDOW_SIZE].normalized() * BIAS_ACC_THRESHOLD;
    }
    
    // 更新预积分
    for (int i = 0; i <= WINDOW_SIZE; i++) {
        if (estimator->pre_integrations[i] != nullptr) {
            estimator->pre_integrations[i]->repropagate(
                estimator->Bas[WINDOW_SIZE], 
                estimator->Bgs[WINDOW_SIZE]
            );
        }
    }
    
    last_zupt_state_timestamp = timestamp;
    
    std::cout << "[ZUPT] 偏置更新 - 陀螺: " << bg_update.transpose() 
              << ", 加速度: " << ba_update.transpose() << std::endl;
    std::cout << "[ZUPT] 零速更新完成" << std::endl;
    
    return true;
}

void UpdaterZeroVelocity::measurement_compress(Eigen::MatrixXd& H, Eigen::VectorXd& res) {
    // 使用QR分解压缩
    if (H.rows() > H.cols()) {
        Eigen::HouseholderQR<Eigen::MatrixXd> qr(H);
        Eigen::MatrixXd Q = qr.householderQ();
        Eigen::MatrixXd R = qr.matrixQR().triangularView<Eigen::Upper>();
        
        // 压缩到状态维度
        H = R.topRows(H.cols());
        res = Q.transpose() * res;
        res = res.head(H.cols());
    }
}

bool UpdaterZeroVelocity::perform_zupt_update(Estimator* estimator, 
                                            const std::vector<ImuData>& imu_recent, 
                                            double dt_summed,
                                            double timestamp) {
    
    // 获取当前状态
    Eigen::Matrix3d R_ItoG = estimator->Rs[WINDOW_SIZE];
    Eigen::Vector3d bg = estimator->Bgs[WINDOW_SIZE];
    Eigen::Vector3d ba = estimator->Bas[WINDOW_SIZE];
    Eigen::Vector3d velocity = estimator->Vs[WINDOW_SIZE];
    
    // 额外检查：IMU测量值的方差
    Eigen::Vector3d acc_mean = Eigen::Vector3d::Zero();
    Eigen::Vector3d gyr_mean = Eigen::Vector3d::Zero();
    
    for (const auto& imu : imu_recent) {
        acc_mean += imu.am;
        gyr_mean += imu.wm;
    }
    acc_mean /= imu_recent.size();
    gyr_mean /= imu_recent.size();
    
    // 计算加速度和角速度的方差
    double acc_var = 0.0;
    double gyr_var = 0.0;
    
    for (const auto& imu : imu_recent) {
        acc_var += (imu.am - acc_mean).squaredNorm();
        gyr_var += (imu.wm - gyr_mean).squaredNorm();
    }
    acc_var /= imu_recent.size();
    gyr_var /= imu_recent.size();
    
    // 如果IMU方差太大，说明有运动
    double acc_std = std::sqrt(acc_var);
    double gyr_std = std::sqrt(gyr_var);
    
    std::cout << "[ZUPT] IMU方差 - 加速度标准差: " << acc_std 
              << " m/s^2, 角速度标准差: " << gyr_std << " rad/s" << std::endl;
    
    if (acc_std > 0.5 || gyr_std > 0.1) {  // 阈值可调
        std::cout << "[ZUPT] IMU方差过大，存在运动" << std::endl;
        return false;
    }
    
    // 构建卡方检验系统
    int m_size = 6 * ((int)imu_recent.size() - 1);
    Eigen::MatrixXd H = Eigen::MatrixXd::Zero(m_size, 9);
    Eigen::VectorXd res = Eigen::VectorXd::Zero(m_size);
    
    // 遍历所有IMU测量构建残差
    for (size_t i = 0; i < imu_recent.size() - 1; i++) {
        double dt = imu_recent[i + 1].timestamp - imu_recent[i].timestamp;
        
        Eigen::Vector3d w_hat = imu_recent[i].wm - bg;
        Eigen::Vector3d a_hat = imu_recent[i].am - ba;
        
        double w_omega = std::sqrt(dt) / _sigma_w;
        double w_accel = std::sqrt(dt) / _sigma_a;
        
        res.block(6*i + 0, 0, 3, 1) = -w_omega * w_hat;
        res.block(6*i + 3, 0, 3, 1) = -w_accel * (a_hat - R_ItoG.transpose() * _gravity);
        
        H.block(6*i + 0, 3, 3, 3) = -w_omega * Eigen::Matrix3d::Identity();
        H.block(6*i + 3, 0, 3, 3) = -w_accel * Utility::skewSymmetric(R_ItoG.transpose() * _gravity);
        H.block(6*i + 3, 6, 3, 3) = -w_accel * Eigen::Matrix3d::Identity();
    }
    
    // 测量噪声协方差
    Eigen::MatrixXd R = _zupt_noise_multiplier * Eigen::MatrixXd::Identity(res.rows(), res.rows());
    
    // 状态协方差矩阵
    Eigen::MatrixXd P = Eigen::MatrixXd::Zero(9, 9);
    P.block(0, 0, 3, 3) = 0.01 * Eigen::Matrix3d::Identity();
    P.block(3, 3, 3, 3) = dt_summed * _sigma_wb * _sigma_wb * Eigen::Matrix3d::Identity();
    P.block(6, 6, 3, 3) = dt_summed * _sigma_ab * _sigma_ab * Eigen::Matrix3d::Identity();
    
    // 计算新息协方差和卡方统计量
    Eigen::MatrixXd S = H * P * H.transpose() + R;
    double chi2 = res.dot(S.llt().solve(res));
    
    // 获取卡方阈值
    double chi2_check = (res.rows() < 1000) ? chi_squared_table[res.rows()] : 
                        boost::math::quantile(boost::math::chi_squared(res.rows()), 0.95);
    double chi2_threshold = _chi2_multiplier * chi2_check;
    
    std::cout << "[ZUPT] 卡方检验: chi2 = " << chi2 
              << ", 阈值 = " << chi2_threshold 
              << " (自由度: " << res.rows() << ")" << std::endl;
    
    bool chi2_passed = (chi2 < chi2_threshold);
    
    if (!chi2_passed) {
        std::cout << "[ZUPT] 卡方检验失败" << std::endl;
        last_zupt_state_timestamp = 0.0;
        last_zupt_count = 0;
        return false;
    }
    
    // 需要连续多次检测到零速才执行更新
    if (last_zupt_count < 3) {
        last_zupt_count++;
        std::cout << "[ZUPT] 零速检测通过，但需要连续检测，当前次数: " << last_zupt_count << std::endl;
        return false;
    }
    
    std::cout << "[ZUPT] 执行零速更新！" << std::endl;
    
    // 执行零速更新
    // 1. 设置速度为零
    estimator->Vs[WINDOW_SIZE].setZero();
    
    // 2. 微调偏置
    Eigen::Vector3d g_in_imu = R_ItoG.transpose() * _gravity;
    Eigen::Vector3d ba_update = 0.005 * (acc_mean - ba - g_in_imu);  // 使用更小的增益
    Eigen::Vector3d bg_update = 0.005 * (gyr_mean - bg);
    
    estimator->Bas[WINDOW_SIZE] += ba_update;
    estimator->Bgs[WINDOW_SIZE] += bg_update;
    
    // 限制偏置范围
    if (estimator->Bgs[WINDOW_SIZE].norm() > BIAS_GYR_THRESHOLD) {
        estimator->Bgs[WINDOW_SIZE] = estimator->Bgs[WINDOW_SIZE].normalized() * BIAS_GYR_THRESHOLD;
    }
    
    if (estimator->Bas[WINDOW_SIZE].norm() > BIAS_ACC_THRESHOLD) {
        estimator->Bas[WINDOW_SIZE] = estimator->Bas[WINDOW_SIZE].normalized() * BIAS_ACC_THRESHOLD;
    }
    
    // 3. 更新预积分
    if (estimator->pre_integrations[WINDOW_SIZE] != nullptr) {
        estimator->pre_integrations[WINDOW_SIZE]->repropagate(
            estimator->Bas[WINDOW_SIZE], 
            estimator->Bgs[WINDOW_SIZE]
        );
    }
    
    last_zupt_state_timestamp = timestamp;
    
    std::cout << "[ZUPT] 零速更新成功完成" << std::endl;
    
    return true;
}