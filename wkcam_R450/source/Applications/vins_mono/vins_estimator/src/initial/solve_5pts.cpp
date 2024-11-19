#include "solve_5pts.h"


namespace cv {
    void decomposeEssentialMat( InputArray _E, OutputArray _R1, OutputArray _R2, OutputArray _t )
    {

        Mat E = _E.getMat().reshape(1, 3);
        CV_Assert(E.cols == 3 && E.rows == 3);

        Mat D, U, Vt;
        SVD::compute(E, D, U, Vt);

        if (determinant(U) < 0) U *= -1.;
        if (determinant(Vt) < 0) Vt *= -1.;

        Mat W = (Mat_<double>(3, 3) << 0, 1, 0, -1, 0, 0, 0, 0, 1);
        W.convertTo(W, E.type());

        Mat R1, R2, t;
        R1 = U * W * Vt;
        R2 = U * W.t() * Vt;
        t = U.col(2) * 1.0;

        R1.copyTo(_R1);
        R2.copyTo(_R2);
        t.copyTo(_t);
    }

    int recoverPose( InputArray E, InputArray _points1, InputArray _points2, InputArray _cameraMatrix,
                         OutputArray _R, OutputArray _t, InputOutputArray _mask)
    {

        Mat points1, points2, cameraMatrix;
        _points1.getMat().convertTo(points1, CV_64F);
        _points2.getMat().convertTo(points2, CV_64F);
        _cameraMatrix.getMat().convertTo(cameraMatrix, CV_64F);

        int npoints = points1.checkVector(2);
        CV_Assert( npoints >= 0 && points2.checkVector(2) == npoints &&
                                  points1.type() == points2.type());

        CV_Assert(cameraMatrix.rows == 3 && cameraMatrix.cols == 3 && cameraMatrix.channels() == 1);

        if (points1.channels() > 1)
        {
            points1 = points1.reshape(1, npoints);
            points2 = points2.reshape(1, npoints);
        }

        double fx = cameraMatrix.at<double>(0,0);
        double fy = cameraMatrix.at<double>(1,1);
        double cx = cameraMatrix.at<double>(0,2);
        double cy = cameraMatrix.at<double>(1,2);

        points1.col(0) = (points1.col(0) - cx) / fx;
        points2.col(0) = (points2.col(0) - cx) / fx;
        points1.col(1) = (points1.col(1) - cy) / fy;
        points2.col(1) = (points2.col(1) - cy) / fy;

        points1 = points1.t();
        points2 = points2.t();

        Mat R1, R2, t;
        decomposeEssentialMat(E, R1, R2, t);
        Mat P0 = Mat::eye(3, 4, R1.type());
        Mat P1(3, 4, R1.type()), P2(3, 4, R1.type()), P3(3, 4, R1.type()), P4(3, 4, R1.type());
        P1(Range::all(), Range(0, 3)) = R1 * 1.0; P1.col(3) = t * 1.0;
        P2(Range::all(), Range(0, 3)) = R2 * 1.0; P2.col(3) = t * 1.0;
        P3(Range::all(), Range(0, 3)) = R1 * 1.0; P3.col(3) = -t * 1.0;
        P4(Range::all(), Range(0, 3)) = R2 * 1.0; P4.col(3) = -t * 1.0;

        // Do the cheirality check.
        // Notice here a threshold dist is used to filter
        // out far away points (i.e. infinite points) since
        // there depth may vary between postive and negtive.
        double dist = 50.0;
        Mat Q;
        triangulatePoints(P0, P1, points1, points2, Q);
        Mat mask1 = Q.row(2).mul(Q.row(3)) > 0;
        Q.row(0) /= Q.row(3);
        Q.row(1) /= Q.row(3);
        Q.row(2) /= Q.row(3);
        Q.row(3) /= Q.row(3);
        mask1 = (Q.row(2) < dist) & mask1;
        Q = P1 * Q;
        mask1 = (Q.row(2) > 0) & mask1;
        mask1 = (Q.row(2) < dist) & mask1;

        triangulatePoints(P0, P2, points1, points2, Q);
        Mat mask2 = Q.row(2).mul(Q.row(3)) > 0;
        Q.row(0) /= Q.row(3);
        Q.row(1) /= Q.row(3);
        Q.row(2) /= Q.row(3);
        Q.row(3) /= Q.row(3);
        mask2 = (Q.row(2) < dist) & mask2;
        Q = P2 * Q;
        mask2 = (Q.row(2) > 0) & mask2;
        mask2 = (Q.row(2) < dist) & mask2;

        triangulatePoints(P0, P3, points1, points2, Q);
        Mat mask3 = Q.row(2).mul(Q.row(3)) > 0;
        Q.row(0) /= Q.row(3);
        Q.row(1) /= Q.row(3);
        Q.row(2) /= Q.row(3);
        Q.row(3) /= Q.row(3);
        mask3 = (Q.row(2) < dist) & mask3;
        Q = P3 * Q;
        mask3 = (Q.row(2) > 0) & mask3;
        mask3 = (Q.row(2) < dist) & mask3;

        triangulatePoints(P0, P4, points1, points2, Q);
        Mat mask4 = Q.row(2).mul(Q.row(3)) > 0;
        Q.row(0) /= Q.row(3);
        Q.row(1) /= Q.row(3);
        Q.row(2) /= Q.row(3);
        Q.row(3) /= Q.row(3);
        mask4 = (Q.row(2) < dist) & mask4;
        Q = P4 * Q;
        mask4 = (Q.row(2) > 0) & mask4;
        mask4 = (Q.row(2) < dist) & mask4;

        mask1 = mask1.t();
        mask2 = mask2.t();
        mask3 = mask3.t();
        mask4 = mask4.t();

        // If _mask is given, then use it to filter outliers.
        if (!_mask.empty())
        {
            Mat mask = _mask.getMat();
            CV_Assert(mask.size() == mask1.size());
            bitwise_and(mask, mask1, mask1);
            bitwise_and(mask, mask2, mask2);
            bitwise_and(mask, mask3, mask3);
            bitwise_and(mask, mask4, mask4);
        }
        if (_mask.empty() && _mask.needed())
        {
            _mask.create(mask1.size(), CV_8U);
        }

        CV_Assert(_R.needed() && _t.needed());
        _R.create(3, 3, R1.type());
        _t.create(3, 1, t.type());

        int good1 = countNonZero(mask1);
        int good2 = countNonZero(mask2);
        int good3 = countNonZero(mask3);
        int good4 = countNonZero(mask4);

        if (good1 >= good2 && good1 >= good3 && good1 >= good4)
        {
            R1.copyTo(_R);
            t.copyTo(_t);
            if (_mask.needed()) mask1.copyTo(_mask);
            return good1;
        }
        else if (good2 >= good1 && good2 >= good3 && good2 >= good4)
        {
            R2.copyTo(_R);
            t.copyTo(_t);
            if (_mask.needed()) mask2.copyTo(_mask);
            return good2;
        }
        else if (good3 >= good1 && good3 >= good2 && good3 >= good4)
        {
            t = -t;
            R1.copyTo(_R);
            t.copyTo(_t);
            if (_mask.needed()) mask3.copyTo(_mask);
            return good3;
        }
        else
        {
            t = -t;
            R2.copyTo(_R);
            t.copyTo(_t);
            if (_mask.needed()) mask4.copyTo(_mask);
            return good4;
        }
    }

    int recoverPose( InputArray E, InputArray _points1, InputArray _points2, OutputArray _R,
                         OutputArray _t, double focal, Point2d pp, InputOutputArray _mask)
    {
        Mat cameraMatrix = (Mat_<double>(3,3) << focal, 0, pp.x, 0, focal, pp.y, 0, 0, 1);
        return cv::recoverPose(E, _points1, _points2, cameraMatrix, _R, _t, _mask);
    }
}

void Triangulate(const cv::Point2f &kp1, const cv::Point2f &kp2, const cv::Mat &P1, const cv::Mat &P2, cv::Mat &x3D)
{  


    // 原理
    // Trianularization: 已知匹配特征点对{x x'} 和 各自相机矩阵{P P'}, 估计三维点 X
    // x' = P'X  x = PX
    // 它们都属于 x = aPX模型
    //                         |X|
    // |x|     |p1 p2  p3  p4 ||Y|     |x|    |--p0--||.|
    // |y| = a |p5 p6  p7  p8 ||Z| ===>|y| = a|--p1--||X|
    // |z|     |p9 p10 p11 p12||1|     |z|    |--p2--||.|
    // 采用DLT的方法：x叉乘PX = 0
    // |yp2 -  p1|     |0|
    // |p0 -  xp2| X = |0|
    // |xp1 - yp0|     |0|
    // 两个点:
    // |yp2   -  p1  |     |0|
    // |p0    -  xp2 | X = |0| ===> AX = 0
    // |y'p2' -  p1' |     |0|
    // |p0'   - x'p2'|     |0|
    // 变成程序中的形式：
    // |xp2  - p0 |     |0|
    // |yp2  - p1 | X = |0| ===> AX = 0
    // |x'p2'- p0'|     |0|
    // |y'p2'- p1'|     |0|
    // 然后就组成了一个四元一次正定方程组，SVD求解，右奇异矩阵的最后一行就是最终的解.

	//这个就是上面注释中的矩阵A
    cv::Mat A(4,4,CV_32F);

    A.row(0) = kp1.x*P1.row(2)-P1.row(0);
    A.row(1) = kp1.y*P1.row(2)-P1.row(1);
    A.row(2) = kp2.x*P2.row(2)-P2.row(0);
    A.row(3) = kp2.y*P2.row(2)-P2.row(1);

    cv::Mat u,w,vt;
    cv::SVD::compute(A,w,u,vt,cv::SVD::MODIFY_A| cv::SVD::FULL_UV);
    x3D = vt.row(3).t();
    x3D = x3D.rowRange(0,3)/x3D.at<float>(3);

}
int CheckRT(const cv::Mat &R, const cv::Mat &t, const std::vector<cv::Point2f> &vKeys1, const std::vector<cv::Point2f> &vKeys2,
                       const cv::Mat &K, std::vector<cv::Point3f> &vP3D, float th2, std::vector<bool> &vbGood, float &parallax)
{

    // 对给出的特征点对及其R t , 通过三角化检查解的有效性，也称为 cheirality check  
	//从相机内参数矩阵获取相机的校正参数
    const float fx = K.at<float>(0,0);
    const float fy = K.at<float>(1,1);
    const float cx = K.at<float>(0,2);
    const float cy = K.at<float>(1,2);


//特征点是否是good点的标记，也就是可以被三角化的点
//这里的特征点指的是参考帧中的特征点
    vbGood = std::vector<bool>(vKeys1.size(),false);

    //重设存储空间坐标的点的大小
    vP3D.resize(vKeys1.size());

	//存储计算出来的每对特征点的视差
    std::vector<float> vCosParallax;
    vCosParallax.reserve(vKeys1.size());


   // Step 1：计算相机的投影矩阵  
    // 投影矩阵P是一个 3x4 的矩阵，可以将空间中的一个点投影到平面上，获得其平面坐标，这里均指的是齐次坐标。
    // 对于第一个相机是 P1=K*[I|0]  //! 一开始第一帧的时候；R就是单位阵I,T就是零矩阵
    // 以第一个相机的光心作为世界坐标系, 定义相机的投影矩阵
    cv::Mat P1(3,4,	//矩阵的大小是3x4
    CV_32F,
    cv::Scalar(0)//初始的数值是0
    );
    	//将整个K矩阵拷贝到P1矩阵的左侧3x3矩阵，因为 K*I = K
    K.copyTo(P1.rowRange(0,3).colRange(0,3));


    // 第一个相机的光心设置为世界坐标系下的原点
    cv::Mat O1 = cv::Mat::zeros(3,1,CV_32F);


        // Camera 2 Projection Matrix K[R|t]
    // 计算第二个相机的投影矩阵 P2=K*[R|t]//! 第二帧的时候就出现了旋转矩阵和平移矩阵
    cv::Mat P2(3,4,CV_32F);
    R.copyTo(P2.rowRange(0,3).colRange(0,3));
    t.copyTo(P2.rowRange(0,3).col(3));
    	//最终结果是K*[R|t]
    P2 = K*P2; 
    
    // 第二个相机的光心在世界坐标系下的坐标
    cv::Mat O2 = -R.t()*t; //! 02是由01平移过去的，所以只求一个平移量即可？
  //只有是在01坐标系，也就是世界坐标系下才能向量相减
    int nGood=0;


    for(size_t i=0; i< vKeys1.size();i++)
    { 

        // Step 2 获取特征点对，调用Triangulate() 函数进行三角化，得到三角化测量之后的3D点坐标
        // kp1和kp2是匹配好的有效特征点
        const cv::Point2f &kp1 = vKeys1[i];
        const cv::Point2f &kp2 = vKeys2[i];
        	//存储三维点的的坐标
        cv::Mat p3dC1;




   // 利用三角法恢复三维点p3dC1
        Triangulate(kp1,kp2,//特征点
        P1,P2, //投影矩阵
        p3dC1//输出，三角化测量之后特征点的空间坐标	
        );

        // Step 3 开始进行三维点的筛选：
        // STEP 第一关：检查三角化的三维点坐标是否合法（非无穷值）
        // 只要三角测量的结果中有一个是无穷大的就说明三角化失败，跳过对当前点的处理，进行下一对特征点的遍历
        if (!isfinite(p3dC1.at<float>(0)) || !isfinite(p3dC1.at<float>(1)) || !isfinite(p3dC1.at<float>(2)))
        {
            // 其实这里就算是不这样写也没问题，因为默认的匹配点对就不是good点
            vbGood[i] = false;
            continue;
        }

   // Step 4 第二关：通过三维点深度值正负、两相机光心视差角大小来检查是否合法 

        //得到向量PO1
        // Check parallax
        cv::Mat normal1 = p3dC1 - O1;  //!这个就是三维点和第一帧坐标系下原点组成的向量
        //求取模长，其实就是距离
        float dist1 = cv::norm(normal1);

        cv::Mat normal2 = p3dC1 - O2; 
        	//求模长
        float dist2 = cv::norm(normal2);

		//根据公式：a.*b=|a||b|cos_theta 可以推导出来下面的式子  余弦值求夹角 
        float cosParallax = normal1.dot(normal2)/(dist1*dist2);

    // 如果深度值为负值，为非法三维点跳过该匹配点对
        // ?视差比较小时，重投影误差比较大。这里0.99998 对应的角度为0.36°,这里不应该是 cosParallax>0.99998 吗？
        // ?因为后面判断vbGood 点时的条件也是 cosParallax<0.99998  
        // !可能导致初始化不稳定?
        if(p3dC1.at<float>(2)<=0 && cosParallax<0.99998)
            continue;






 // 讲空间点p3dC1变换到第2个相机坐标系下变为p3dC2 //! 为啥还要放在第二个坐标系下计算夹角？？？？两次检验
        cv::Mat p3dC2 = R*p3dC1+t; 
	//判断过程和上面的相同
        if(p3dC2.at<float>(2)<=0 && cosParallax<0.99998)
            continue;


   // Step 5 第三关：计算空间点在参考帧和当前帧上的重投影误差，如果大于阈值则舍弃
        // Check reprojection error in first image
    // 计算3D点在第一个图像上的投影误差
		//投影到参考帧图像上的点的坐标x,y 


        float im1x, im1y;
        float invZ1 = 1.0/p3dC1.at<float>(2);


//投影到参考帧图像上。因为参考帧下的相机坐标系和世界坐标系重合，因此这里就直接进行投影就可以了 

//其实p3dC1这还是相机的坐标，根据之前求出来的z也就是深度信息，求出在像素平面上的特征点坐标 然后利用这个理论点坐标
//和实际的特征点坐标来进行重投影误差的计算 
 //!转换的公式fx，fy,cx,cy都是内参中的参数,这里的公式是 相机坐标系= z分之一 *内参*相机坐标系        
        im1x = fx*p3dC1.at<float>(0)*invZ1+cx;

        im1y = fy*p3dC1.at<float>(1)*invZ1+cy;

		//参考帧上的重投影误差，这个的确就是按照定义来的

        float squareError1 = (im1x-kp1.x)*(im1x-kp1.x)+(im1y-kp1.y)*(im1y-kp1.y);
        // 重投影误差太大，跳过淘汰

        if(squareError1>th2)
            continue;

        // Check reprojection error in second image
        // 计算3D点在第二个图像上的投影误差，计算过程和第一个图像类似

        float im2x, im2y;
                // 注意这里的p3dC2已经是第二个相机坐标系下的三维点了

        float invZ2 = 1.0/p3dC2.at<float>(2);
        im2x = fx*p3dC2.at<float>(0)*invZ2+cx;
        im2y = fy*p3dC2.at<float>(1)*invZ2+cy;

        float squareError2 = (im2x-kp2.x)*(im2x-kp2.x)+(im2y-kp2.y)*(im2y-kp2.y);

        if(squareError2>th2)
            continue;

      // Step 6 统计经过检验的3D点个数，记录3D点视差角 
        // 如果运行到这里就说明当前遍历的这个特征点对靠谱，经过了重重检验，说明是一个合格的点，称之为good点 
        vCosParallax.push_back(cosParallax);

    //存储这个三角化测量后的3D点在世界坐标系下的坐标
        vP3D[i] = cv::Point3f(p3dC1.at<float>(0),p3dC1.at<float>(1),p3dC1.at<float>(2));
        nGood++; 


	//判断视差角，只有视差角稍稍大一丢丢的才会给打good点标记
		//? bug 我觉得这个写的位置不太对。你的good点计数都++了然后才判断，不是会让good点标志和good点计数不一样吗
        if(cosParallax<0.99998)
            vbGood[i]=true;
    }


    // Step 7 得到3D点中较小的视差角，并且转换成为角度制表示
    if(nGood>0)
    {

                // 从小到大排序，注意vCosParallax值越大，视差越小
        sort(vCosParallax.begin(),vCosParallax.end());
       // !排序后并没有取最小的视差角，而是取一个较小的视差角
		// 作者的做法：如果经过检验过后的有效3D点小于50个，那么就取最后那个最小的视差角(cos值最大)
		// 如果大于50个，就取排名第50个的较小的视差角即可，为了避免3D点太多时出现太小的视差角 
        size_t idx = min(50,int(vCosParallax.size()-1));
              //将这个选中的角弧度制转换为角度制
        parallax = acos(vCosParallax[idx])*180/CV_PI;
  
    }
    else
        parallax=0;

    return nGood;
}

bool MotionEstimator::solveRelativeRTH(const std::vector<pair<Vector3d, Vector3d>> &corres, Matrix3d &Rotation, Vector3d &Translation)
{
    if (corres.size() >= 15)
    {
        vector<cv::Point2f> ll, rr;
        for (int i = 0; i < int(corres.size()); i++)
        {
            ll.push_back(cv::Point2f(corres[i].first(0), corres[i].first(1)));
            rr.push_back(cv::Point2f(corres[i].second(0), corres[i].second(1)));
        }
        cv::Mat cameraMatrix = (cv::Mat_<float>(3, 3) << 1, 0, 0, 0, 1, 0, 0, 0, 1);
        std::vector<cv::Mat> rotations, vR, vT, vN;
        cv::Mat H = cv::findHomography(ll, rr, cv::RANSAC);
        cv::decomposeHomographyMat(H, cameraMatrix, vR, vT, vN);

        std::vector<cv::Point3f> vP3D;
        float th2;
        std::vector<bool> vbGood;
        float parallax;
        vector<bool> vbTriangulatedi;
        int bestGoodId = -1;
        int bestGood = -1;
        for (size_t i = 0; i < vN.size(); i++)
        {
            cv::Mat r, t;
            vR[i].convertTo(r, CV_32F);
            vT[i].convertTo(t, CV_32F);
            int nGood = CheckRT(r, t,            // 当前组解的旋转矩阵和平移向量
                                ll, rr,          // 特征点
                                cameraMatrix,    // 相机的内参数矩阵
                                vP3D,            // 存储三角化测量之后的特征点空间坐标的
                                4.0,             // 三角化过程中允许的最大重投影误差
                                vbTriangulatedi, // 特征点是否被成功进行三角测量的标记
                                parallax);       // 这组解在三角化测量的时候的比较大的视差角
            if (nGood > bestGood)
            {
                bestGood = nGood;
                bestGoodId = i;
            }
        }

        cv::Mat rot, trans;
        rot = vR[bestGoodId];
        trans = vT[bestGoodId];
        
        Eigen::Matrix3d R;
        Eigen::Vector3d T;
        for (int i = 0; i < 3; i++)
        {
            T(i) = trans.at<double>(i, 0);
            for (int j = 0; j < 3; j++)
                R(i, j) = rot.at<double>(i, j);
        }

        Rotation = R.transpose();
        Translation = -R.transpose() * T;
        if (bestGood > 12)
            return true;
        else
            return false;
    }
    return false;
}

bool MotionEstimator::solveRelativeRT(const std::vector<pair<Vector3d, Vector3d>> &corres, Matrix3d &Rotation, Vector3d &Translation)
{
    if (corres.size() >= 15)
    {
        vector<cv::Point2f> ll, rr;
        for (int i = 0; i < int(corres.size()); i++)
        {
            ll.push_back(cv::Point2f(corres[i].first(0), corres[i].first(1)));
            rr.push_back(cv::Point2f(corres[i].second(0), corres[i].second(1)));
        }
        cv::Mat mask;
        cv::Mat E = cv::findFundamentalMat(ll, rr, cv::FM_RANSAC, 0.3 / 460, 0.99, mask);
        cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3) << 1, 0, 0, 0, 1, 0, 0, 0, 1);
        cv::Mat rot, trans;
        int inlier_cnt = cv::recoverPose(E, ll, rr, cameraMatrix, rot, trans, mask);
        //cout << "inlier_cnt " << inlier_cnt << endl;

        Eigen::Matrix3d R;
        Eigen::Vector3d T;
        for (int i = 0; i < 3; i++)
        {   
            T(i) = trans.at<double>(i, 0);
            for (int j = 0; j < 3; j++)
                R(i, j) = rot.at<double>(i, j);
        }

        Rotation = R.transpose();
        Translation = -R.transpose() * T;
        if(inlier_cnt > 12)
            return true;
        else
            return false;
    }
    return false;
}



