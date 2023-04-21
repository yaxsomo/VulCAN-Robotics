#ifndef IMU_h
#define IMU_h

#include "Wire.h"       
#include "I2Cdev.h"     
#include "MPU6050.h" 

struct angles {
  float z_angle;
  float x_angle;
};

void IMU_Setup();
angles Get_IMU();
byte get_Z_axis();
byte get_X_axis();
void calibrate_IMU();
#endif
