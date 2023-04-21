#ifndef IMU_h
#define IMU_h

#include "Wire.h"       
#include "MPU6050_light.h" 

void IMU_Setup();
void Get_IMU();
// byte get_Z_axis();
// byte get_X_axis();
// void calibrate_IMU();
#endif