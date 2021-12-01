# Table of Contents
* Abstract
* [Introduction](#1-introduction)
* [Related Work](#2-related-work)
* [Technical Approach](#3-technical-approach)
* [Evaluation and Results](#4-evaluation-and-results)
* [Discussion and Conclusions](#5-discussion-and-conclusions)
* [References](#6-references)

# Abstract

Provide a brief overview of the project objhectives, approach, and results.

# 1. Introduction

This section should cover the following items:

* Motivation & Objective: What are you trying to do and why? (plain English without jargon)
* State of the Art & Its Limitations: How is it done today, and what are the limits of current practice?
* Novelty & Rationale: What is new in your approach and why do you think it will be successful?
* Potential Impact: If the project is successful, what difference will it make, both technically and broadly?
* Challenges: What are the challenges and risks?
* Requirements for Success: What skills and resources are necessary to perform the project?
* Metrics of Success: What are metrics by which you would check for success?

# 2. Related Work

Currently, most of the small smart devices only support voice input for the text input. However, there are many restrictions by using voice input, such as difficulty to recognize user’s voice due to external environment like noise. Another issue with voice input is user’s privacy. Therefore, the concept of virtual keyboard was introduced.

iKey [1] was presented to allow users to type on the back of their hands. By using a small piezoelectric ceramic vibration sensor and vibration mechanism, iKey was able to recognize different tapping locations on the hand with strong resistance to sound noise. Sampling rate of 200Hz was used to make the product more cost and power efficient. During data processing, a 20Hz Butterworth high pass filter and a 300Hz low pass filter was applied to eliminate low frequency noise and potential high frequency harmonics. Then, random-subspace and class-center classification concepts were adopted for sample training. Over the 30 testing users, iKey achieved average accuracy of 92.4%.

Similar to iKey, Oinput [3] was introduced to utilize vibration sensors to detect vibration on both of the user's hands to achieve QWERTY keyboard recognition. Oinput used a notch and bandpass filter to mitigate noise, then process and train sensor data with RNN-LSTM machine learning model. Oinput achieved 93.3% average accuracy over 30 participants. Identical to Oinput, another paper presented virtual QWERTY keyboard recognition could be realized based on MEMS sensor [4] by utilizing accelerometer, gyroscope and magnetometer. Sensor data was collected by placing 4 MEMS sensors on 4 fingers. During data processing, a smoothing filter was used to remove mutation noise. Support Vector Machine was adopted to train the sample data. The overall recognition correct rate achieved 95.07%.

However, the techniques presented in these papers require additional hardware which can increase the product cost. In our project, we utilize the IMU that's already been integrated in the smart device like Apple Watch, Fitbit. Thus, our technique can be easily implement on existing product without requiring addtional hardware to achieve the virtual key presses in the air.

# 3. Technical Approach

## 3.1 System Overview

The Numeric Virtual Keyboard system can be seperated into several sections, data collection, data preprocessing, model training & conversion, live prediction with Arduino. An overview for the entire system is shown in the figure below.

<img width="730" alt="Screen Shot 2021-11-30 at 6 07 41 PM" src="https://user-images.githubusercontent.com/91438818/144158799-096f15a2-a3a1-4197-8fe1-fd8c9b289b41.png">

## 3.2 Hardware

The hardware used this project is the Arduino NANO 33 BLE Sense board, this is a very power, cost efficient micro-controller which contains sensors that are capable to measure voice, gesture, motion, etc. For this project, we use the Inertial Measurement Unit (IMU) for 3-axis accelerometer and gyrocope measurement with maximum sampling rate of 110Hz.

<img width="842" alt="Arduino" src="https://user-images.githubusercontent.com/91438818/144158117-23ac8d55-6e71-4300-aace-5a6ac298ae06.png">

## 3.3 Data Collection

<img width="634" alt="Screen Shot 2021-11-30 at 6 16 51 PM" src="https://user-images.githubusercontent.com/91438818/144159823-a5957af2-c249-4bf6-9e79-68590b817ce2.png">

## 3.4 Data Preprocessing

<img width="455" alt="Screen Shot 2021-11-30 at 6 18 58 PM" src="https://user-images.githubusercontent.com/91438818/144160041-a97e9cf2-0c4a-4846-bdb9-b941c301d7d5.png">

The sampling rate for sensor data is about 100 samples/second. After the data is loaded from csv files, the data is then loaded in to pandas format and clip out unneccessary data to achieve better training. Sliding window approach is used to split data into fixed size windows. To achieve best training accuracy and precision performance, a sliding window of 0.4 second (40 samples) and a stride of 0.01 second (1 samples) is used. 

## 3.5 Model Training & Conversion

Multiple classification models were experimented for the project, such as KNN, Gaussian Naive Bayes, Random forest, Decision tree, Logistic regression, and Support Vector Machine from [Scikit Learn library](https://scikit-learn.org/stable/index.html). Below are the specific parameters that were used for each of the classifiers.

| Classifier        | KNN           | GaussianNB  | RandomForest  | DecisionTree  | LogisticRegression  | SVM  |
| ------------- |:-------------:| :-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
| Parameters      | Default | Default | max_depth=10  |  Default |max_iter=1000, random_state=0  |  Default |

There are 80% of data (64 samples) used for model training and 20% of data (16 samples) used for model testing. After we finished training each of these models, we choose the model that has the best accuracy for later model conversion and use in live prediction with Arduino. For model conversion, we used [micromlgen library](https://github.com/eloquentarduino/micromlgen) to convert the model to plain C code which it can be interpreted by Arduino for real time prediction.

## 3.6 Live Prediction with Arduino

Live processing and prediction with Arduino consists of three main parts, data collection & preprocessing, trained models predict binary press & segment unit, and output post processing for predictions. An overview for the Arduino system is shown in the figure below.

<img width="480" alt="Screen Shot 2021-11-30 at 6 20 58 PM" src="https://user-images.githubusercontent.com/91438818/144160302-7a70ca34-bc09-4f03-bec7-9c1daa25f3c6.png">

* Live sensor data is collected using the 6 DoF IMU (Accelerometer & Gyroscope). Then we use sliding window to split sensor data into 40 samples with a stride of 1 sample to be able to repeat the data preprocessing steps for model training.
* Preprocessed data then loaded into both binary model and segement model. Output of binary model is either 0 or 1 to determine whether a key is pressed. Output of segment model is number ranging from {-4,-3,-2,-1,0,1,2,3,4} to determine the segment unit between presses (where -1 indicates one unit to the left and 1 indicates one unit to the right).
* Finally, output post precessing combines the binary and segment predictions to determine the keypress and sequence of keypresses.

# 4. Evaluation and Results

# 5. Discussion and Conclusions

# 6. References

1. Wenqiang Chen, Yanming Lian, Lu Wang, Rukhsana Ruby, Wen Hu, and Kaishun Wu. 2017. Virtual Keyboard for Wearable Wristbands. In Proceedings of the 15th ACM Conference on Embedded Network Sensor Systems (SenSys '17). Association for Computing Machinery, New York, NY, USA, Article 44, 1–2. DOI:https://doi.org/10.1145/3131672.3136984

2. Wenqiang Chen, Lin Chen, Kenneth Wan, and John Stankovic. 2020. A smartwatch product provides on-body tapping gestures recognition: demo abstract. In Proceedings of the 18th Conference on Embedded Networked Sensor Systems (SenSys '20). Association for Computing Machinery, New York, NY, USA, 589–590. DOI:https://doi.org/10.1145/3384419.3430444

3. Y. Huang, S. Cai, L. Wang and K. Wu, "Oinput: A Bone-Conductive QWERTY Keyboard Recognition for Wearable Device," 2018 IEEE 24th International Conference on Parallel and Distributed Systems (ICPADS), 2018, pp. 946-953, doi: 10.1109/PADSW.2018.8644590.

4. C. Lian, H. Wang, Y. Zhao, L. Liu, H. Sun and Z. Zhan, "Virtual Keyboard Based on MEMS Sensor Network and Fusion of Accelerometer and Gyroscope," 2018 IEEE 8th Annual International Conference on CYBER Technology in Automation, Control, and Intelligent Systems (CYBER), 2018, pp. 390-394, doi: 10.1109/CYBER.2018.8688194.
