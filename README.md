This project was an exciting and enjoyable endeavor as it allowed for the creation of virtual objects in a scene using camera calibration. It provided a hands-on experience with tasks such as detecting and extracting corners of a checkerboard pattern, selecting calibration images, and saving corner locations and corresponding 3D world points. The camera was calibrated using the OpenCV function `calibrateCamera`, and the resulting calibration parameters and reprojection error were printed. The program was capable of determining the camera's current position by detecting the chessboard and estimating its pose. The implementation also facilitated the projection of virtual objects onto the scene, which could be drawn in the image. Additionally, the project explored the detection of robust features and their potential utilization for augmented reality. Overall, this project was both educational and entertaining, providing opportunities for experimentation and further enhancements, such as modifying the target image and exploring different virtual object designs.

----Video:

https://northeastern-my.sharepoint.com/:f:/g/personal/dhaduti_k_northeastern_edu/Ehc2_flRy75Esuc1r8YtPNQBl9ARCeKmiCZETfuxVpn7vw?e=oSz5xL

----Wiki report:

https://wiki.khoury.northeastern.edu/display/~dhadutik/Project+4%3A+Calibration+and+Augmented+Reality

.pdf copy of the report has also been submitted on Gradescope.

----Operating System: Windows
    IDE: Visual Studio

----Instructions for Execution
	
	Task 1-Task 6: Camera calibration & drawing 3D objects > main.cpp
        Task 7     : Harris corner Detection                 > harris.cpp

Task 1:Detecting and extracting corners of the chessboard

![image](https://github.com/KshamaDhaduti/Calibration-and-Augmented-Reality/assets/103454385/d1fa8209-bd39-48ed-b234-d288158d5a16)
![image](https://github.com/KshamaDhaduti/Calibration-and-Augmented-Reality/assets/103454385/d14999b3-06e4-4202-adb4-7f30117bbce2)


Task 2:Calibration image selection

![image](https://github.com/KshamaDhaduti/Calibration-and-Augmented-Reality/assets/103454385/eecd0a08-7010-4045-84c1-2c2ee7efb5cb)

Task 3:Calibrating the camera

![image](https://github.com/KshamaDhaduti/Calibration-and-Augmented-Reality/assets/103454385/e70f7cb8-02ba-431f-93d8-92cee946f963)
![image](https://github.com/KshamaDhaduti/Calibration-and-Augmented-Reality/assets/103454385/555778e1-9097-4f7e-b225-5edf3b8c14bd)
![image](https://github.com/KshamaDhaduti/Calibration-and-Augmented-Reality/assets/103454385/e41e9cf3-fa8f-4edf-a17f-4a4317ccf158)

Task 4:Calculating Current Position of the Camera

![image](https://github.com/KshamaDhaduti/Calibration-and-Augmented-Reality/assets/103454385/b4d9e86f-3071-4bdf-b517-40f560bd85c4)

Task 5: Project Outside Corners or 3D Axes
3D world points using the projectPoints() function.

![image](https://github.com/KshamaDhaduti/Calibration-and-Augmented-Reality/assets/103454385/5a8e2a28-c390-4f1a-a134-f674d59dc703)

Task 6: 
To design a virtual object comprised of lines and project it onto the chessboard so that it could move about while
maintaining its orientation. 

https://github.com/KshamaDhaduti/Calibration-and-Augmented-Reality/assets/103454385/2b61f9eb-824b-42d5-930f-221b3cc2e9a1

Task 7 : Harris Detection

https://github.com/KshamaDhaduti/Calibration-and-Augmented-Reality/assets/103454385/2f3c6fa5-fcd5-4877-9102-ee44e726bba3

Extension:
Here we are adding a virtual object with the target object altered.
![image](https://github.com/KshamaDhaduti/Calibration-and-Augmented-Reality/assets/103454385/4cc599da-8c7b-4338-ad1a-8263c794c09a)

