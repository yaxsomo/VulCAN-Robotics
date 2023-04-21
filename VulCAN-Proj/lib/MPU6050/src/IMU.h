#ifndef IMU_h
#define IMU_h

#include "Wire.h"       
#include "MPU6050_light.h" 

void IMU_Setup();
void Get_IMU();

int get_Z_axis();
int get_Y_axis();
int get_X_axis();
// void calibrate_IMU();
#endif