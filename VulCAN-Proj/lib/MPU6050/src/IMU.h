#ifndef IMU_h
#define IMU_h

#include "Wire.h"       
#include "MPU6050_light.h" 

void IMU_Setup();
void Get_IMU();

char *get_Z_axis();
char *get_Y_axis();
char *get_X_axis();
char* int_to_char_with_sign(int value);
// char *get_Y_axis2();
// void calibrate_IMU();
#endif