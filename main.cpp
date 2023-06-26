//
//Project 4 : Calibration and Augmented Reality 
// Created by Kshama Dhaduti
// 
// Tasks 1-3 a.Keypress 's': saves the calibration image
//           b.Keypress 'c' : camera calibration
//

#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d.hpp>

using namespace cv;
using namespace std;

int main()
{
    int count = 1;
    Mat frame, gray, save_img;
    char key;
    vector<Point2f> corner_set;
    vector<vector<Point2f>> corner_list;
    vector<Point3f> point_set;
    vector<vector<Point3f>> point_list;
    Size boardSize = Size(9, 6);
    std::vector<cv::Mat> C_img;
    cv::VideoCapture* capdev;

    //Initialize point set
    for (int y = 0; y > -6; y--) {
        for (int x = 0; x < 9; x++) {
            point_set.push_back(Point3f(x, y, 0));

        }
    }

    //TASK 1: Detect and Extract Chessboard Corners
    // open the video device
    capdev = new cv::VideoCapture(0);
    //EXTENSION : Test out several different cameras and compare the calibrations and quality of the results.
    //0->webcam 1->phone camera

    if (!capdev ->isOpened()) {
        
        std::cout << "Error opening camera stream" << std::endl;
        return -1;
    }


    while (true)
    {
        *capdev >> frame;
        if (frame.empty()) {
            printf("Image is empty\n");
            break;
        }
        //imshow("Frame", frame);

        key = waitKey(30);

        //Convert  to grayscale
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        //check for a chessboard pattern i
        bool flag = findChessboardCorners(gray, boardSize, corner_set);

        if (flag) {
            save_img = frame.clone();

            // refine the corner locations
            cornerSubPix(gray, corner_set, Size(11, 11), Size(-1, -1),
                TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 30, 0.001));

            //Uncomment for co-ordinates for all the corners detected
            /*Print the number of cornersand their coordinates
            std::cout << "Number of corners: " << corners.size() << std::endl;
            for (int i = 0; i < corners.size(); i++) {
              std::cout << "Corner " << i << " x: " << corners[i].x << ", y: " << corners[i].y << std::endl;
            }*/

        }
        // draw the corners on the image
        drawChessboardCorners(frame, boardSize, Mat(corner_set), flag);
        imshow("Chessboard Corners", frame);

        //TASK 2: Select Calibration Images 
        key = waitKey(10);
        if (key == 's')
        {
            std::string str = "Calibrated_frame" + std::to_string(count) + ".jpg";
            std::string savePath = "C:/Users/ksham/OneDrive/Desktop/PRCV/prcv_4/Images/Calib_frame"; // set the directory path to save images

            imwrite(savePath + str, save_img);
            C_img.push_back(cv::imread(savePath + str));
            cout << "\nFrame saved" << std::to_string(count) << ".jpg\n";
            imshow("Frame saved.!", cv::imread(savePath + str));
            ++count;
        }
        if (key == 'c' || key == 27)
            break;

    }

    // Loop over the calibration images and find the corners
    for (int i = 0; i < C_img.size(); i++) {

        // Convert the image to grayscale
        cv::cvtColor(C_img[i], gray, cv::COLOR_BGR2GRAY);

        //Function to find chessboard corners
        std::vector<cv::Point2f> corners;
        bool found = cv::findChessboardCorners(gray, boardSize, corners);

        if (found) {
            corner_list.push_back(corners);
            point_list.push_back(point_set);
        }

        //check for chessboard again
        found = findChessboardCorners(gray, boardSize, corners, CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_FAST_CHECK | CALIB_CB_NORMALIZE_IMAGE);

        // Draw the corners on the image and save it
        cv::drawChessboardCorners(C_img[i], boardSize, corners, found);

        std::string fs = "Update_C_frame" + std::to_string(i + 1) + ".jpg";
        cv::imwrite(fs, C_img[i]);

      
    }

    //TASK 3: Calibrate the Camera
    // 
    //Define variables
    cv::Mat Camera_matrix, distortion_coeff;
    std::vector<cv::Mat> rotations, translations;

    // Calibrate the camera
    double error = cv::calibrateCamera(point_list, corner_list, C_img[0].size(), Camera_matrix, distortion_coeff, rotations, translations);

    // Save the 3D world points and corresponding image points in a single vector
    for (int i = 0; i < corner_list.size(); i++) {
        for (int j = 0; j < corner_list[i].size(); j++) {
            point_set.push_back(cv::Vec3f(corner_list[i][j].x, corner_list[i][j].y, 0));
        }
    }
    cout << "Camera_Matrix: " << Camera_matrix << "\n" << "Distortion_coefficient: " << distortion_coeff;
    cout << "re-projection error: " << error << "\n";

    cout << "\nRotation vectors: " << endl;
    for (int i = 0; i < rotations.size(); i++) {
        cout << rotations[i] << endl;
    }

    cout << "\nTranslation vectors: " << endl;
    for (int i = 0; i < translations.size(); i++) {
        cout << translations[i] << endl;
    }

    // specify the path to save the file
    std::string filepath = "C:\\Users\\ksham\\OneDrive\\Desktop\\PRCV\\prcv_4\\data.txt";
    std::ofstream outfile(filepath);
    // write the camera matrix to the file
    outfile << "Camera matrix:" << std::endl << Camera_matrix << std::endl;
    // write the distortion coefficient to the file
    outfile << "Distortion coefficient:" << std::endl << distortion_coeff << std::endl;
    // close the file
    outfile.close();

    std::cout << "Saved camera calibration data to file: " << filepath << std::endl;

    //TASK 4-6:
    // Create a video capture object to capture frames from the camera
    //VideoCapture cap(0);
    if (!capdev->isOpened()) {

        std::cout << "Error opening camera stream" << std::endl;
        return -1;
    }
    // Set the size of the chessboard
    Size board_size(9, 6);

    // Create vectors to hold the detected corners and object points
    vector<Point2f> corners;
    vector<Point3f> object_points;

    // Create the object points corresponding to the corners of the chessboard
    for (int i = 0; i < board_size.height; i++) {
        for (int j = 0; j < board_size.width; j++) {
            object_points.push_back(Point3f(j, i, 0));
        }
    }

    // Define the termination criteria for corner detection
    TermCriteria criteria(TermCriteria::EPS + TermCriteria::MAX_ITER, 30, 0.001);

    // Start the video loop
    while (true) {
        // Capture a frame from the camera
        Mat frame;
        *capdev >> frame;

        // Convert the frame to grayscale
        Mat gray_n;
        cvtColor(frame, gray_n, COLOR_BGR2GRAY);

        // Detect the corners of the chessboard
        bool found = findChessboardCorners(gray_n, board_size, corners,
            CALIB_CB_ADAPTIVE_THRESH + CALIB_CB_NORMALIZE_IMAGE + CALIB_CB_FAST_CHECK);


        if (found) {
            // Refine the corner locations
            cornerSubPix(gray_n, corners, Size(11, 11), Size(-1, -1), criteria);

            // Get the pose of the chessboard
            Mat rvec, tvec;
            solvePnP(object_points, corners, Camera_matrix, distortion_coeff, rvec, tvec);

            // Print out the rotation and translation data
            cout << "Rotation vector:" << endl << rvec << endl;
            cout << "Translation vector:" << endl << tvec << endl;

            // Draw the chessboard and its axes
            drawChessboardCorners(frame, board_size, corners, found);

            //TASK 5:Draw 3D axis
            vector<Point3f> axes_points;
            axes_points.push_back(Point3f(0, 0, 0));
            axes_points.push_back(Point3f(3, 0, 0));
            axes_points.push_back(Point3f(0, 3, 0));
            axes_points.push_back(Point3f(0, 0, 3));

            vector<Point2f> image_points;
            //3D projections
            projectPoints(axes_points, rvec, tvec, Camera_matrix, distortion_coeff, image_points);

            //Draw axis
            line(frame, image_points[0], image_points[1], Scalar(255, 0, 0), 4, LINE_8);
            line(frame, image_points[0], image_points[2], Scalar(0, 255, 0), 4, LINE_8);
            line(frame, image_points[0], image_points[3], Scalar(0, 0, 255), 4, LINE_8);

          
                //EXTENSION: Change of target 
                // 
                // Loading the image to be used as a replacement for the target
                Mat img_src = imread("C:/Users/ksham/OneDrive/Desktop/PRCV/prcv_4/photos/Wall-E.jpeg");

                // Defining the corners of the target on the chessboard to be replaced
                vector<Point> points_dst;
                points_dst.push_back(corners[0]);
                points_dst.push_back(corners[8]);
                points_dst.push_back(corners[53]);
                points_dst.push_back(corners[45]);

                // Defining the corners of the replacement image to be mapped to the corners of the target
                vector<Point> points_src;
                points_src.push_back(Point(0, 0));
                points_src.push_back(Point(img_src.cols, 0));
                points_src.push_back(Point(img_src.cols, img_src.rows));
                points_src.push_back(Point(0, img_src.rows));

                // Computing the homography matrix that maps the corners of the replacement image to the target corners
                Mat Homography = cv::findHomography(points_src, points_dst);

                // Warping the replacement image to fit the target using the homography matrix
                Mat warped_img;
                warpPerspective(img_src, warped_img, Homography, frame.size(), INTER_CUBIC);

                // Creating a mask that represents the region where the warped image will be placed in the target image
                Mat mask = Mat::zeros(frame.rows, frame.cols, CV_8UC1);
                fillConvexPoly(mask, points_dst, Scalar(255, 255, 255), LINE_AA);

                // Eroding the mask to avoid copying boundary effects from the wrapping
                Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
                erode(mask, mask, element);

                // Copying the warped image to the target image in the mask region 
                Mat imOut = frame.clone();
                warped_img.copyTo(imOut, mask);
                imOut.copyTo(frame);

            //TASK 6: Create a Virtual Object
            vector<Point3f> cuboid_points;
            cuboid_points.push_back(Point3f(0, 0, 0));
            cuboid_points.push_back(Point3f(0, 5, 0));
            cuboid_points.push_back(Point3f(8, 5, 0));
            cuboid_points.push_back(Point3f(8, 0, 0));
            cuboid_points.push_back(Point3f(0, 0, -4));
            cuboid_points.push_back(Point3f(0, 5, -4));
            cuboid_points.push_back(Point3f(8, 5, -4));
            cuboid_points.push_back(Point3f(8, 0, -4));
            cuboid_points.push_back(Point3f(3.5, 2, -7));
            

            vector<Point2f> image_points_cuboid;
            //3D projections
            projectPoints(cuboid_points, rvec, tvec, Camera_matrix, distortion_coeff, image_points_cuboid);

            //Draw shape
            line(frame, image_points_cuboid[0], image_points_cuboid[1], Scalar(255, 0, 0), 4, LINE_8);
            line(frame, image_points_cuboid[1], image_points_cuboid[2], Scalar(255, 0, 0), 4, LINE_8);
            line(frame, image_points_cuboid[2], image_points_cuboid[3], Scalar(255, 0, 0), 4, LINE_8);
            line(frame, image_points_cuboid[3], image_points_cuboid[0], Scalar(255, 0, 0), 4, LINE_8);

            line(frame, image_points_cuboid[4], image_points_cuboid[5], Scalar(255, 0, 0), 4, LINE_8);
            line(frame, image_points_cuboid[5], image_points_cuboid[6], Scalar(255, 0, 0), 4, LINE_8);
            line(frame, image_points_cuboid[6], image_points_cuboid[7], Scalar(255, 0, 0), 4, LINE_8);
            line(frame, image_points_cuboid[7], image_points_cuboid[4], Scalar(255, 0, 0), 4, LINE_8);

            line(frame, image_points_cuboid[0], image_points_cuboid[4], Scalar(255, 0, 0), 4, LINE_8);
            line(frame, image_points_cuboid[1], image_points_cuboid[5], Scalar(255, 0, 0), 4, LINE_8);
            line(frame, image_points_cuboid[2], image_points_cuboid[6], Scalar(255, 0, 0), 4, LINE_8);
            line(frame, image_points_cuboid[3], image_points_cuboid[7], Scalar(255, 0, 0), 4, LINE_8);


            line(frame, image_points_cuboid[8], image_points_cuboid[4], Scalar(0, 0, 255), 4, LINE_8);
            line(frame, image_points_cuboid[8], image_points_cuboid[5], Scalar(255, 0, 0), 4, LINE_8);
            line(frame, image_points_cuboid[8], image_points_cuboid[6], Scalar(0, 0, 255), 4, LINE_8);
            line(frame, image_points_cuboid[8], image_points_cuboid[7], Scalar(255, 0, 0), 4, LINE_8);


        }

        imshow("Projection", frame);

        // Wait for a key press
      char key = waitKey(1);


    }

    cv::destroyAllWindows();
    return 0;

}
