#pragma once
#include <Eigen/Dense>
#include <iostream>
#include "../factor/imu_factor.h"
#include "../utility/utility.h"
//#include <ros/ros.h>
#include <map>
#include "../feature_manager.h"
#include <iostream>

using namespace Eigen;
using namespace std;

class ImageFrame
{
    public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        ImageFrame(){};
        ImageFrame(const map<int, vector<pair<int, Vector3d>>>& _points, double _t):points{_points},t{_t},is_key_frame{false}
        {
        };
        map<int, vector<pair<int, Vector3d> > > points;
        double t;
        Matrix3d R;
        Vector3d T;
        IntegrationBase *pre_integration;
        bool is_key_frame;
};

bool VisualIMUAlignment(map<double, ImageFrame> &all_image_frame, Vector3d* Bgs, Vector3d &g, VectorXd &x);
