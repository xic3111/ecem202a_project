#include <Arduino_LSM9DS1.h>
#include "model_binary_microml.h"
#include "model_segment_microml.h"

#define SAMPLES 240

Eloquent::ML::Port::LogisticRegression_binary model_binary;
Eloquent::ML::Port::LogisticRegression_segment model_segment;

const int numSamples = 500;

void setup () {
  Serial.begin(115200);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

}

void loop () { 
  float acc_x, acc_y, acc_z, gyro_x, gyro_y, gyro_z;
  float features[SAMPLES];
  int samplesRead = numSamples;
  int c = 0;  
  int s,b;
  int c_b = 0;
  int presses = 0;
  int num = 1;
  int arr_s[9] = {0,0,0,0,1,0,0,0,0};
  int t = 0;
  bool notpress_flag = false;
  
  // Initial condition to trigger sensoring
  if (samplesRead == numSamples) {
    if (IMU.gyroscopeAvailable()) {
      IMU.readGyroscope(gyro_x, gyro_y, gyro_z);
      if(gyro_y < -10) samplesRead = 0;
    }
  }
  
  while (samplesRead < numSamples) {
    if (c < SAMPLES - 1) {                                          // Get sensor data to features array until it reaches 240 samples for the sliding window
      if (IMU.accelerationAvailable()&&IMU.gyroscopeAvailable()) {
        IMU.readAcceleration(acc_x, acc_y, acc_z);
        IMU.readGyroscope(gyro_x, gyro_y, gyro_z);
        
        features[c] = acc_x;
        features[c+1] = acc_y;
        features[c+2] = acc_z;
        features[c+3] = gyro_x;
        features[c+4] = gyro_y;
        features[c+5] = gyro_z;
        
        c = c + 6;
        samplesRead++;
      }  
    }
    else {     
      s = model_segment.predict(features);                  // Motion prediction  3->-1, 4->0, 5->1

      if (model_binary.predict(features) == 1) b = 0;       // Binary prediction
      else b = 1;
      
      if (s == 4 && presses == 0 && b == 1) {               // If press is detected (b=1)
        c_b++;
        if (c_b > 3) {                                      // If 3 presses from the window is detected, then press=1
          presses = 1;
          c_b = 0;

          int m = 0;
          for (int i=0; i < 9; i++) {                       // Find most frequent motion count
            if (arr_s[i] > arr_s[m]) m = i;
          }
          memset(arr_s, 0, sizeof(arr_s));

          num = num + m - 4;
          if (num > 5) num = 5;                             // Bounding to avoid exceeding 1 and 5
          if (num < 1) num = 1;

          Serial.print(num);
          Serial.print(',');
        }
      }
      else if (b == 0 && presses == 1) {                    // If motion is detected (b=1)
        arr_s[s]++;                                         // Increase motion counts to arr_s
        notpress_flag = true;
      }
      else if (notpress_flag && b == 1 && presses == 1) {   // Trigger condition to end the motion counts
        t++;
        if (t > 2) {
          presses = 0;
          t = 0;
          notpress_flag = false;
        }
        
      }

      int temp1 = 0;
      int temp2 = 6;
      while (temp2 < SAMPLES) {             //Shift left by 6 index if array is full
        features[temp1] = features[temp2];
        temp1++;
        temp2++;
      }
      
      c = c - 6;
    }
  }

}
