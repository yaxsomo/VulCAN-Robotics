#ifndef IMU_h
#define IMU_h

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

void IMU_Setup();
int* Get_IMU();
float get_Y_axis();

#endif
