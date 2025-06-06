#pragma once

#include <Eigen/Dense>
#include "../estimator.h"
#include "../parameters.h"
#include "../../../include/Vector3.h"
#include "../../../include/Quaternion.h"
#include <fstream>


void pubOdometry(const Estimator &estimator, const std_msgs::Header &header, Eigen::Vector3d loop_correct_t,
                Eigen::Matrix3d loop_correct_r);
//#include <ros/ros.h>
#if 0
#include <std_msgs/Header.h>
#include <std_msgs/Float32.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/PointCloud.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PointStamped.h>
#include <visualization_msgs/Marker.h>
#include <tf/transform_broadcaster.h>
#include "CameraPoseVisualization.h"
#include <Eigen/Dense>
#include "../estimator.h"
#include "../parameters.h"
#include <fstream>

extern ros::Publisher pub_odometry;
extern ros::Publisher pub_path, pub_pose;
extern ros::Publisher pub_cloud, pub_map;
extern ros::Publisher pub_key_poses;

extern ros::Publisher pub_ref_pose, pub_cur_pose;

extern ros::Publisher pub_key;

extern nav_msgs::Path path;

extern ros::Publisher pub_pose_graph;

extern int IMAGE_ROW, IMAGE_COL;

void registerPub(ros::NodeHandle &n);

void pubLatestOdometry(const Eigen::Vector3d &P, const Eigen::Quaterniond &Q, const Eigen::Vector3d &V, const std_msgs::Header &header);

void printStatistics(const Estimator &estimator, double t);

void pubOdometry(const Estimator &estimator, const std_msgs::Header &header, Eigen::Vector3d loop_correct_t,
                Eigen::Matrix3d loop_correct_r);

void pubInitialGuess(const Estimator &estimator, const std_msgs::Header &header);

void pubKeyPoses(const Estimator &estimator, const std_msgs::Header &header, Eigen::Vector3d loop_correct_t,
				Eigen::Matrix3d loop_correct_r);

void pubCameraPose(const Estimator &estimator, const std_msgs::Header &header, Eigen::Vector3d loop_correct_t,
                   Eigen::Matrix3d loop_correct_r);

void pubPointCloud(const Estimator &estimator, const std_msgs::Header &header, Eigen::Vector3d loop_correct_t,
                   Eigen::Matrix3d loop_correct_r);

void pubPoseGraph(CameraPoseVisualization* posegraph, const std_msgs::Header &header);

void updateLoopPath(nav_msgs::Path _loop_path);

void pubTF(const Estimator &estimator, const std_msgs::Header &header, Eigen::Vector3d loop_correct_t,
                   Eigen::Matrix3d loop_correct_r);
#endif
