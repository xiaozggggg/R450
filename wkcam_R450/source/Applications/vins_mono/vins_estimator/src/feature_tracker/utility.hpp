#ifndef UTILITY_HPP
#define UTILITY_HPP
#include <opencv2/opencv.hpp>

class IMGUtility
{

public:
    static void showImg(const cv::Mat &img, std::string name = "img", int deley = 1)
    {
        cv::namedWindow(name, cv::WINDOW_NORMAL);
        cv::imshow(name, img);
        cv::waitKey(deley);
    }

    static cv::Mat drawPoints(const cv::Mat &img, const std::vector<cv::KeyPoint> &pts, int line = 1)
    {
        cv::Mat bgrimg;
        if (img.channels() != 3)
            cv::cvtColor(img, bgrimg, cv::COLOR_GRAY2BGR);
        else
            bgrimg = img;

        cv::RNG rng(123);
        for (size_t i = 0; i < pts.size(); i++)
        {

            int b = rng.uniform(0, 255);
            int g = rng.uniform(0, 255);
            int r = rng.uniform(0, 255);
            cv::circle(bgrimg, pts[i].pt, 5, cv::Scalar(b, g, r), line);
        }

        return bgrimg;
    }

    static cv::Mat drawPoints(const cv::Mat &img, const std::vector<cv::Point2f> &pts, int line = 1)
    {
        cv::Mat bgrimg;
        if (img.channels() != 3)
            cv::cvtColor(img, bgrimg, cv::COLOR_GRAY2BGR);
        else
            bgrimg = img;

        cv::RNG rng(123);
        for (size_t i = 0; i < pts.size(); i++)
        {

            int b = rng.uniform(0, 255);
            int g = rng.uniform(0, 255);
            int r = rng.uniform(0, 255);
            cv::circle(bgrimg, pts[i], 5, cv::Scalar(b, g, r), line);
        }

        return bgrimg;
    }

    static void drawSortedMatchese(const cv::Mat &img1, const cv::Mat &img2, const std::vector<cv::KeyPoint> &pts1, const std::vector<cv::KeyPoint> &pts2, std::string name = "img", int deley = 1)
    {
        cv::Mat bgrimg1 = drawPoints(img1, pts1);
        cv::Mat bgrimg2 = drawPoints(img2, pts2);

        cv::Mat macthImg;
        cv::hconcat(bgrimg1, bgrimg2, macthImg);
        cv::RNG rng(5465);
        cv::Point2f off_set = cv::Point2f(img1.cols, 0);

        int j = 0;
        int i = 0;
        int nMatch = 0;
        while (i < pts1.size() && j < pts2.size())
        {
            if (pts1[i].class_id == pts2[j].class_id)
            {
                int b = rng.uniform(0, 255);
                int g = rng.uniform(0, 255);
                int r = rng.uniform(0, 255);
                cv::line(macthImg, pts1[i].pt, pts2[j].pt + off_set, cv::Scalar(b, g, r));
                i++;
                j++;
                nMatch++;
            }
            if (pts1[i].class_id > pts2[j].class_id)
                j++;
            if (pts1[i].class_id < pts2[j].class_id)
                i++;
        }
        std::cout << "matchse size " << nMatch << std::endl;
        showImg(macthImg, name, deley);
    }

    static void drawSortedMatchese(const cv::Mat &img1, const cv::Mat &img2, const std::vector<cv::Point2f> &pts1, const std::vector<cv::Point2f> &pts2, const std::vector<uchar> &status, std::string name = "img", int deley = 1)
    {
        cv::Mat bgrimg1 = drawPoints(img1, pts1);
        cv::Mat bgrimg2 = drawPoints(img2, pts2);

        cv::Mat macthImg;
        cv::hconcat(bgrimg1, bgrimg2, macthImg);
        cv::RNG rng(5465);
        cv::Point2f off_set = cv::Point2f(img1.cols, 0);
        int nMatch = 0;

        for (size_t i = 0; i < status.size(); i++)
        {
            if (!status[i])
                continue;
            int b = rng.uniform(0, 255);
            int g = rng.uniform(0, 255);
            int r = rng.uniform(0, 255);
            cv::line(macthImg, pts1[i], pts2[i] + off_set, cv::Scalar(b, g, r));
            nMatch++;
        }

        std::cout << "matchse size " << nMatch << std::endl;
        showImg(macthImg, name, deley);
    }

    static void drawGrid(const std::vector<cv::KeyPoint> &grid, int gr, int gc, std::string name, int deley)
    {
        cv::Mat imgGrid(gr, gc, CV_8UC1, cv::Scalar(0)); // Mat(int rows, int cols, int type, const Scalar& s);
        int sub = 0;
        for (size_t r = 0; r < gr; r++)
        {
            for (size_t c = 0; c < gc; c++)
            {
                int color = 0;
                if (grid[sub].class_id != -1)
                    color = 255;
                else if (grid[sub].response > 0)
                {
                    color = 128;
                }

                imgGrid.at<uchar>(r, c) = color;

                sub++;
            }
        }

        showImg(imgGrid, name, deley);
    }
    static void drawGrid(const std::vector<uchar> &grid, int gr, int gc, std::string name, int deley)
    {
        cv::Mat imgGrid(gr, gc, CV_8UC1, cv::Scalar(0)); // Mat(int rows, int cols, int type, const Scalar& s);
        int sub = 0;
        for (size_t r = 0; r < gr; r++)
        {
            for (size_t c = 0; c < gc; c++)
            {
                int color = 0;
                if (grid[sub])
                    imgGrid.at<uchar>(r, c) = 255;

                sub++;
            }
        }

        showImg(imgGrid, name, deley);
    }

    static void DrawGridInImg(int row, int col, int r_s, int c_s, cv::Mat &img, cv::Scalar color = cv::Scalar(255,0,0))
    {

        int width = col * c_s;
        int height = row * r_s;
        for (size_t r = 0; r < row; r++)
        {
            cv::Point2f start(0, r * r_s);
            cv::Point2f end(width, r * r_s);
            cv::line(img, start, end, color);
        }
        for (size_t c = 0; c < col; c++)
        {
            cv::Point2f start(c * c_s, 0);
            cv::Point2f end(c * c_s, height);
            cv::line(img, start, end, color);
        }
    }
};

#endif