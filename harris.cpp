
/*
 TASK 7:harris.cpp
 created by Kshama Dhaduti

          a.Keypress 's': saves 
          b.Keypress 'q' : quit
 
*/

#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//function to detect harris corners and draw them on the frame
int harris(int threshold, Mat& grey, Mat& frame) {

    //set harris corner detection parameters
    int size = 2;
    int aptr = 3;
    double k = 0.04;

    //initialize destination matrix
    Mat destination = Mat::zeros(grey.size(), CV_32FC1);

    //apply Harris corner detection to gray image
    cornerHarris(grey, destination, size, aptr, k);

    //initialize matrices for normalization and scaling
    Mat destination_n, scaled_distance_n;

    //normalize destination image for display 
    normalize(destination, destination_n, 0, 255, cv::NORM_MINMAX, CV_32FC1, cv::Mat());

    //convert normalized image to unsigned char for display
    convertScaleAbs(destination_n, scaled_distance_n);

    //draw circles around detected corners on original image
    for (int i = 0; i < destination_n.rows; i++)
    {
        for (int j = 0; j < destination_n.cols; j++)
        {
            if ((int)destination_n.at<float>(i, j) > threshold)
            {
                cv::circle(frame, cv::Point(j, i), 5, cv::Scalar(255), 2, 8, 0);
            }
        }
    }
    return 0;
}

int main(int, char**) {

    //initialize variables
    int count = 1;
    Mat frame;
    int threshold = 200;

    //initialize video capture
    VideoCapture* capdev;

    // open the video device
    capdev = new VideoCapture(0);
    if (!capdev->isOpened()) {
        printf("Unable to open video device\n");
        return(-1);
    }

    //create window for display
    namedWindow("Detection", 1);
    for (;;) {
        //capture frame from video
        *capdev >> frame; 
        if (frame.empty()) {
            printf("frame is empty\n");
            break;
        }

        //convert frame to grayscale
        Mat grey;
        cvtColor(frame, grey, COLOR_BGR2GRAY);

        //apply Harris corner detection to grayscale frame
        harris(threshold, grey, frame);

        //display frame with detected corners
        imshow("Detection", frame);

        //wait for key press and check for quit or save command
        char key = cv::waitKey(10);
        //Key input 
        if (key == 'q') {
            break;
        }
        //save frame to file
        if (key == 's') {
            string str = "C:/Users/ksham/OneDrive/Desktop/PRCV/Project4/harrison" + to_string(count) + ".jpg";
            imwrite(str, frame);
            count++;
        }

    }
    //release video capture device
    delete capdev;
    return 0;
}

