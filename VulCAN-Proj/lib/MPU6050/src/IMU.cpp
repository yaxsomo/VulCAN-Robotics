// A demo of the sleep modes for the Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Arduino.h>

Adafruit_MPU6050 mpu;

sensors_event_t a, g, temp;

void IMU_Setup() {
  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
      delay(100);
  }
  
  Serial.println("MPU6050 Found!");
  // mpu.enableSleep(false);
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  // mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void Get_IMU() {
  
  /* Create new sensor events */
  sensors_event_t a, g, temp;

  /* Allocate memory for the data array */
  float* data = new float[2];

  /* Populate the sensor events with the readings*/
  mpu.getEvent(&a, &g, &temp);

  // data[0] = g.gyro.x;
  // data[1] = g.gyro.y;

  /* Print out acceleration data in a plotter-friendly format */
  Serial.print("X:\t");
  Serial.print(g.gyro.x);
  Serial.print(",");
  Serial.print("Y:\t");
  Serial.print(g.gyro.y);
  Serial.print("Z:\t");
  Serial.print(g.gyro.z);
  Serial.println("");

  /* Return the pointer to the data array */
  // return data;
}

float get_Y_axis() {
  mpu.getEvent(&a, &g, &temp);
  float res = g.gyro.y;
  Serial.print("Y : ");
  Serial.println(res);
  return res;
}
