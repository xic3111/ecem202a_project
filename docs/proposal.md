# Project Proposal

## 1. Motivation & Objective

Smart devices were evolving very quickly and played a significant role in our daily life. They are designed to be portable and convenient for users, such as Fitbit and Apple watches. Due the limitation of size, it is very difficult to write or type on these smart devices. Thus, voice input was presented as a substitution for text input. However, voice input extremely depends on real world environment and user’s voice recognition such as accent. Additionally, voice input is relatively much slower compared to text input and it has poor privacy protection. Gesture recognition was also introduced as a replacement for text input, however, it faces the same challenges of efficiency and stability as voice input. In this project, we are going to present a human-computer interaction technology that can overcome the challenges of gesture and voice input, which is wearable virtual keyboard on smart devices. Accelerometer and gyroscope sensors from the Arduino Nano 33 BLE Sense board was used to measure and identify the virtual keystroke being pressed by users. This idea brings convenience to users with much more efficiency and privacy. These sensors are integrated on most of the modern smart device which indicates that it could easily be implemented on commercial products. 

## 2. State of the Art & Its Limitations

Text input for small smart devices can be done in various ways, for example, through voice on Apple watches. Other ways can through motions, gestures, etc. The limitation of voice, motions and gestures can be its accuracy, input latency and privacy. 

## 3. Novelty & Rationale

Our new approach is to use the accelerometer and gyroscope on the Arduino Nano 33 BLE board to mimic the smart watch commercial products like Fitbit and Apple watches which these sensors are already integrated. We can utilize the accelerometer and gyroscope to sense the movement of user's hand when typing certain virtual numeric keys like number 1, 2, 3, 4, 5... Then, through learning the movements, keys typed by user can be identified and further process by the system. Which it can be very useful for small smart devices due to the physical size limitation of the screen.

## 4. Potential Impact

Due to the size limitation of the small smart device like Fitbit, Apple watches, it is extremely unconvenient to input text. With this project, it can break many of limitations like convenience, input latency, and privacy (i.e. voice input with Apple watches). Small smart devices with these sensors integrated can implement typing easily which is necessary for them without physical screen size limitation. And we believe our project idea will be implemented by other business in the future.

## 5. Challenges

Some of the challenges can be real time interference between sensors and device, Arduino and real time synchronization during data collection, sample rate of the sensors, accuracy of the sensors, machine learning model training accuracy etc.

## 6. Requirements for Success

Skills like machine learning, coding in C and Python is necessary for the project. Resources like Arduino Nano 33 BLE board documents, prior related papers and researches  is needed.

## 7. Metrics of Success

Metrics like accuracy, latency, convience is very important for success. Perhap cost and power consumption are other metrics to be considered.

## 8. Execution Plan

Week 5: Prior papers & research, define project

Week 6: Data collection

Week 7: Data collection and preprocessing

Week 8: Preliminary trained model, midterm presentation prepration

Week 9: Optimize trained model

Week 10: Test and validate, final presentation prepration

## 9. Related Work

### 9.a. Papers

Currently, most of the small smart devices only support voice input for the text input. However, there are many restrictions by using voice input, such as difficulty to recognize user’s voice due to external environment like noise. Another issue with voice input is user’s privacy. Therefore, the concept of virtual keyboard was introduced.

iKey [1] was presented to allow users to type on the back of their hands. By using a small piezoelectric ceramic vibration sensor and vibration mechanism, iKey was able to recognize different tapping locations on the hand with strong resistance to sound noise. Sampling rate of 200Hz was used to make the product more cost and power efficient. During data processing, a 20Hz Butterworth high pass filter and a 300Hz low pass filter was applied to eliminate low frequency noise and potential high frequency harmonics. Then, random-subspace and class-center classification concepts were adopted for sample training. Over the 30 testing users, iKey achieved average accuracy of 92.4%.

Similar to iKey, Oinput [3] was introduced to utilize vibration sensors to detect vibration on both of the user's hands to achieve QWERTY keyboard recognition. Oinput used a notch and bandpass filter to mitigate noise, then process and train sensor data with RNN-LSTM machine learning model. Oinput achieved 93.3% average accuracy over 30 participants. Identical to Oinput, another paper presented virtual QWERTY keyboard recognition could be realized based on MEMS sensor [4] by utilizing accelerometer, gyroscope and magnetometer. Sensor data was collected by placing 4 MEMS sensors on 4 fingers. During data processing, a smoothing filter was used to remove mutation noise. Support Vector Machine was adopted to train the sample data. The overall recognition correct rate achieved 95.07%.

### 9.b. Datasets

We are going to collect data from people by using the Arduino Nano 33 BLE board for this project.

### 9.c. Software

Google Colab, Tensorflow, Arduino.

## 10. References

1. Wenqiang Chen, Yanming Lian, Lu Wang, Rukhsana Ruby, Wen Hu, and Kaishun Wu. 2017. Virtual Keyboard for Wearable Wristbands. In Proceedings of the 15th ACM Conference on Embedded Network Sensor Systems (SenSys '17). Association for Computing Machinery, New York, NY, USA, Article 44, 1–2. DOI:https://doi.org/10.1145/3131672.3136984

2. Wenqiang Chen, Lin Chen, Kenneth Wan, and John Stankovic. 2020. A smartwatch product provides on-body tapping gestures recognition: demo abstract. In Proceedings of the 18th Conference on Embedded Networked Sensor Systems (SenSys '20). Association for Computing Machinery, New York, NY, USA, 589–590. DOI:https://doi.org/10.1145/3384419.3430444

3. Y. Huang, S. Cai, L. Wang and K. Wu, "Oinput: A Bone-Conductive QWERTY Keyboard Recognition for Wearable Device," 2018 IEEE 24th International Conference on Parallel and Distributed Systems (ICPADS), 2018, pp. 946-953, doi: 10.1109/PADSW.2018.8644590.

4. C. Lian, H. Wang, Y. Zhao, L. Liu, H. Sun and Z. Zhan, "Virtual Keyboard Based on MEMS Sensor Network and Fusion of Accelerometer and Gyroscope," 2018 IEEE 8th Annual International Conference on CYBER Technology in Automation, Control, and Intelligent Systems (CYBER), 2018, pp. 390-394, doi: 10.1109/CYBER.2018.8688194.
