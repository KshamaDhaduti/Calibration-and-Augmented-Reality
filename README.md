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


Task 6: 
To design a virtual object comprised of lines and project it onto the chessboard so that it could move about while
maintaining its orientation. 
https://github.com/KshamaDhaduti/Calibration-and-Augmented-Reality/assets/103454385/2b61f9eb-824b-42d5-930f-221b3cc2e9a1



Task 7 : Harris Detection
https://github.com/KshamaDhaduti/Calibration-and-Augmented-Reality/assets/103454385/2f3c6fa5-fcd5-4877-9102-ee44e726bba3

Extension:
Here we are adding a virtual object with the target object altered.
![image](https://github.com/KshamaDhaduti/Calibration-and-Augmented-Reality/assets/103454385/4cc599da-8c7b-4338-ad1a-8263c794c09a)

