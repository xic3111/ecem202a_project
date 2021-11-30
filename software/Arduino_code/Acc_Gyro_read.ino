#include <Arduino_LSM9DS1.h>

const int numSamples = 900;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  
}

void loop() {
  float acc_x, acc_y, acc_z, gyro_x, gyro_y, gyro_z;
  int samplesRead = 0;

  // To capture sensor data until the sample is reaching limit
  while(samplesRead < numSamples) {
    if (IMU.accelerationAvailable()&&IMU.gyroscopeAvailable()) {
      IMU.readAcceleration(acc_x, acc_y, acc_z);
      IMU.readGyroscope(gyro_x, gyro_y, gyro_z);

      Serial.print(acc_x,6);
      Serial.print(',');
      Serial.print(acc_y,6);
      Serial.print(',');
      Serial.print(acc_z,6);
      Serial.print(',');
      Serial.print(gyro_x,6);
      Serial.print(',');
      Serial.print(gyro_y,6);
      Serial.print(',');
      Serial.print(gyro_z,6);
      Serial.println();
    }
    samplesRead++;
    
  }
  
  delay(60000);
}
