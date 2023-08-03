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


Extension:

Harris Detection
https://northeastern-my.sharepoint.com/:v:/r/personal/dhaduti_k_northeastern_edu/Documents/Calibration%20and%20AR/Harris.mp4?csf=1&web=1&e=IZQsxI&nav=eyJyZWZlcnJhbEluZm8iOnsicmVmZXJyYWxBcHAiOiJTdHJlYW1XZWJBcHAiLCJyZWZlcnJhbFZpZXciOiJTaGFyZURpYWxvZyIsInJlZmVycmFsQXBwUGxhdGZvcm0iOiJXZWIiLCJyZWZlcnJhbE1vZGUiOiJ2aWV3In19

Here we are adding a virtual object with the target object altered.
![image](https://github.com/KshamaDhaduti/Calibration-and-Augmented-Reality/assets/103454385/4cc599da-8c7b-4338-ad1a-8263c794c09a)

