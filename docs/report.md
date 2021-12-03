# Table of Contents
* Abstract
* [Introduction](#1-introduction)
* [Related Work](#2-related-work)
* [Technical Approach](#3-technical-approach)
* [Evaluation and Results](#4-evaluation-and-results)
* [Discussion and Conclusions](#5-discussion-and-conclusions)
* [References](#6-references)

# Abstract

The Virtual Numeric Keyboard is a portable device designed to mimic keyboard functionality without having a physical keyboard. Our goal was to use only the Arduino and a keyboard layout to detect key presses from 1 through 5, using signal processing and machine learning. Our approach uses two Logistic Regression classifiers from SciKit Learn in tandem, one to identify the occurrence of key presses and one to predict the key press based on hand movement. Gyroscope and accelerometer data is fed into the classifiers, and they track motion in realtime to output the number identified when a press occurs. Our key press binary classifier is able to identify whether or not a press occurred within a given window with an accuracy of 98%, and our motion segment classifier labels hand motion with an accuracy of 92%. Combined, these two classifiers are able to correctly guess the number pressed on the numeric keyboard with an accuracy of 83%.

# 1. Introduction

## 1.1 Motivation & Objective

Smart devices such as Fitbit and Apple Watch are designed to be portable and convenient for users. However, due to size limitations, it is very difficult to write or type on these smart devices. Voice input was presented as a substitution for text input, but this method depends on the real world environment and the device's ability to recognize the user's voice, which can be impacted by speech and background noise. Additionally, voice input is slower compared to text input and it has poor privacy protection. Gesture recognition was also introduced as a replacement for text input, but it faces the same challenges of efficiency and stability as voice input. In this project, we present a human-computer interface that can overcome the challenges of gesture and voice input: the wearable virtual keyboard on smart devices. Accelerometer and gyroscope sensors from the Arduino Nano 33 BLE Sense board were used to measure and identify the virtual keystroke being pressed by users. This idea brings convenience to users with more efficiency and privacy. These sensors are integrated on most modern smart devices, which indicates that it could easily be implemented on commercial products. 

## 1.2 State of the Art & Its Limitations

Text input for small smart devices can be done in various ways, such as through voice on Apple watches. Other ways are through motions, gestures, etc.. The limitation of voice, motions and gestures are its accuracy, input latency, and privacy. 

## 1.3 Novelty & Rationale

Our new approach is to use the accelerometer and gyroscope on the Arduino Nano 33 BLE board to mimic the smart watch commercial products like Fitbit and Apple Watches, where these sensors are already integrated. We can utilize the accelerometer and gyroscope to sense the movement of the user's hand when typing virtual numeric keys numbered 1 through 5. Then, through learning the movements, keys typed by user can be identified and further processed by the system. This is especially useful for small smart devices due to the physical size limitation of the screen.

## 1.4 Potential Impact

Due to the size limitation of the small smart device like Fitbit, Apple watches, it is extremely inconvenient to input text. With this project, it can break many of these limitations like convenience, input latency, and privacy (i.e. voice input with Apple Watches). Small smart devices with these sensors integrated can implement typing easily which is necessary for them without physical screen size limitation. We believe our project idea will be implemented by other business in the future.

## 1.5 Challenges

Some of the challenges are real time interference between sensors and device, Arduino and real time synchronization during data collection, sample rate of the sensors, accuracy of the sensors, and accuracy of the models during training and usage.

## 1.6 Requirements for Success

In order to find success with this project, we needed to successfully implement machine learning in Python, translate the models to C code for the Arduino, and validate our approach with prior work.

## 1.7 Metrics of Success

Our success is measured by the accuracy of the classifiers, the latency of the device, and the ease of deployment and use.

# 2. Related Work

Currently, most of the small smart devices only support voice input for the text input. However, there are many restrictions by using voice input, such as difficulty to recognize user’s voice due to external environment like noise. Another issue with voice input is user’s privacy. Therefore, the concept of virtual keyboard was introduced.

iKey [1] was presented to allow users to type on the back of their hands. By using a small piezoelectric ceramic vibration sensor and vibration mechanism, iKey was able to recognize different tapping locations on the hand with strong resistance to sound noise. Sampling rate of 200Hz was used to make the product more cost and power efficient. During data processing, a 20Hz Butterworth high pass filter and a 300Hz low pass filter was applied to eliminate low frequency noise and potential high frequency harmonics. Then, random-subspace and class-center classification concepts were adopted for sample training. Over the 30 testing users, iKey achieved average accuracy of 92.4%.

Similar to iKey, Oinput [3] was introduced to utilize vibration sensors to detect vibration on both of the user's hands to achieve QWERTY keyboard recognition. Oinput used a notch and bandpass filter to mitigate noise, then process and train sensor data with RNN-LSTM machine learning model. Oinput achieved 93.3% average accuracy over 30 participants. Identical to Oinput, another paper presented virtual QWERTY keyboard recognition could be realized based on MEMS sensor [4] by utilizing accelerometer, gyroscope and magnetometer. Sensor data was collected by placing 4 MEMS sensors on 4 fingers. During data processing, a smoothing filter was used to remove mutation noise. Support Vector Machine was adopted to train the sample data. The overall recognition correct rate achieved 95.07%.

However, the techniques presented in these papers require additional hardware which can increase the product cost. In our project, we utilize the IMU that's already been integrated in the smart device like Apple Watch, Fitbit. Thus, our technique can be easily implement on existing product without requiring addtional hardware to achieve the virtual key presses in the air.

# 3. Technical Approach

## 3.1 System Overview

The Numeric Virtual Keyboard system can be seperated into several sections: data collection, data preprocessing, model training & conversion, and live prediction with Arduino. An overview for the entire system is shown in the figure below.

<img width="730" alt="Screen Shot 2021-11-30 at 6 07 41 PM" src="https://user-images.githubusercontent.com/91438818/144158799-096f15a2-a3a1-4197-8fe1-fd8c9b289b41.png">

## 3.2 Hardware

The hardware used this project is the Arduino NANO 33 BLE Sense board, this is a very power, cost efficient micro-controller which contains sensors that are capable to measure voice, gesture, motion, etc. For this project, we use the Inertial Measurement Unit (IMU) for 3-axis accelerometer and gyrocope measurement with maximum sampling rate of 110Hz.

<img width="467" alt="Screen Shot 2021-11-30 at 8 33 44 PM" src="https://user-images.githubusercontent.com/91438818/144172410-086f4efd-16a0-4d7c-80de-155cf3874a4b.png">


## 3.3 Data Collection

Initially, we drew our virtual keyboard on a notebook and used the Arduino to collect gyroscope and accelerometer data. However, this data did not have labeled ground truths for our button presses, so we needed a new solution. Our final data was collected using a webpage displayed horizontally on a phone. This provided a comparable size to the drawn keyboard, but allowed for us to include a JavaScript backend that logged and timestamped click events with each press. These timestamps were then used to label the collected data with key presses. The website for data collection is independently hosted at https://spencercz.github.io/M202A_Data/.

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

Below are the results for model training accuracy with each of the classifier:

For binary classifier to determine whether there's a keypress,

| Classifier        | KNN           | GaussianNB  | RandomForest  | DecisionTree  | LogisticRegression  | SVM  |
| ------------- |:-------------:| :-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
| Accuracy      | 97.1% | 92.0% | 98.8%  |  98.0% |  98.2%  |  97.0% |

For segment classifier to determine the unit moved between keypresses,

| Classifier        | KNN           | GaussianNB  | RandomForest  | DecisionTree  | LogisticRegression  | SVM  |
| ------------- |:-------------:| :-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
| Accuracy       | 90.4% | 66.8% | 96.4%  |  91.6% | 92.5%  |  N/A |

From the results shown above, Random Forest classifier has the best accuracy with feature of max_depth = 10. However, Random Forest classifier model is too large and will not be able to convert and fit into Arduino. Thus, Logistic Regression classifier model is choosen for the conversion and fit into Arduino. Below is the confusion matrices for Logistic Regression classifier for both binary and segment.

For binary classifier with Losgistic Regression shown below, number 1 indicates a press, and 0 indicates no press.

<img width="316" alt="Screen Shot 2021-11-30 at 8 14 54 PM" src="https://user-images.githubusercontent.com/91438818/144170808-6a3734ba-f4b8-46e6-92e6-a0e249f5aa0b.png">

For segment classifier with Losgistic Regression shown below, number -1 indicates one unit to the left and 1 indicates one unit to the right. Number 4 is not shown due to no testing data with four units to the right.

<img width="319" alt="Screen Shot 2021-11-30 at 8 15 14 PM" src="https://user-images.githubusercontent.com/91438818/144170827-eafb48f4-7378-4100-b105-e00b90168f9b.png">

Additionally, when testing real time data with Arduino, the accuracy on detecting the correct sequence of numbers is about 75% with testing and pressing 20 random sequences of numbers. The accuracy can be due to several factors, such as the noise from environment, error stacking with just one wrong keypress.

# 5. Discussion and Conclusions

In this project, a virtual numeric keyboard system is implemented with the classification machine learning model and Arduino. The Logistic Regression machine learning model is chosen due to its light size and high training accuracy. Preprocessing technique like data clipping and sliding window is used to better process the data in order to have a better ML model accuracy. After the ML model is chosen, we converted the model in to plain C code in order to fit into the Arduino. On the Arduino side, as we process real time data, sliding window technique is also used to feed into the pre-trained binary and segment models to make predictions. Post data processing is also performed to combine both binary and segment predictions to output the keypresses predictions. 

Overall, this project is very useful for smart devices like Apple Watch, Fitbit to make text input. The techniques and algorithms are not hard to be implemented onto the existing smart devices that has already an IMU integerated, which most wearable smart devices have. However, this project can be further extended in the future. First, the number of keypresses can be expanded to full 10 digits and even with all the keys on the keyboard. Second, only 80 samples are used to train the ML model, thus, more sensor data can be taken to further improve the robustness and accuracy of the system. Third, the classifier ML model can be further optimized to overcome the noise and other impefections. Fourth, the system assumes the user is facing the keyboard and typing with the right hand on one finger, so future direction can include typing with left hand and with multiple fingers. Lastly, using more sensors on the system could further increase the complexity to achieve better performence. 

# 6. References

1. Wenqiang Chen, Yanming Lian, Lu Wang, Rukhsana Ruby, Wen Hu, and Kaishun Wu. 2017. Virtual Keyboard for Wearable Wristbands. In Proceedings of the 15th ACM Conference on Embedded Network Sensor Systems (SenSys '17). Association for Computing Machinery, New York, NY, USA, Article 44, 1–2. DOI:https://doi.org/10.1145/3131672.3136984

2. Wenqiang Chen, Lin Chen, Kenneth Wan, and John Stankovic. 2020. A smartwatch product provides on-body tapping gestures recognition: demo abstract. In Proceedings of the 18th Conference on Embedded Networked Sensor Systems (SenSys '20). Association for Computing Machinery, New York, NY, USA, 589–590. DOI:https://doi.org/10.1145/3384419.3430444

3. Y. Huang, S. Cai, L. Wang and K. Wu, "Oinput: A Bone-Conductive QWERTY Keyboard Recognition for Wearable Device," 2018 IEEE 24th International Conference on Parallel and Distributed Systems (ICPADS), 2018, pp. 946-953, doi: 10.1109/PADSW.2018.8644590.

4. C. Lian, H. Wang, Y. Zhao, L. Liu, H. Sun and Z. Zhan, "Virtual Keyboard Based on MEMS Sensor Network and Fusion of Accelerometer and Gyroscope," 2018 IEEE 8th Annual International Conference on CYBER Technology in Automation, Control, and Intelligent Systems (CYBER), 2018, pp. 390-394, doi: 10.1109/CYBER.2018.8688194.

5. "Scikit-Learn: Machine Learning In Python — Scikit-Learn 0.23.2 Documentation". Scikit-Learn.Org, 2020, https://scikit-learn.org/stable/.
