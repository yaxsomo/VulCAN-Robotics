#include "Wire.h"
#include <MPU6050_light.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

MPU6050 mpu(Wire);

unsigned long timer = 0;

void IMU_Setup()
{
  Serial.begin(115200);
  Wire.begin();

  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  
  while (status != 0)
  {
  } // stop everything if could not connect to MPU6050

  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  // delay(1000);

  Serial.println("Done!\n");
}

void Get_IMU()
{
  mpu.update();

  if ((millis() - timer) > 10)
  { // print data every 10ms
    Serial.print("X : ");
    Serial.print((int)round(mpu.getAngleX()));
    Serial.print("\tY : ");
    Serial.print((int)round(mpu.getAngleY()));
    Serial.print("\tZ : ");
    Serial.println((int)round(mpu.getAngleZ()));
    timer = millis();
  }
}


char* int_to_char_with_sign(int value) {
    char* result = (char*) malloc(4); // allocate memory for the result, including an extra byte
    snprintf(result, 4, "%+d", value); // format the string with the sign
    if (result[0] == '+') {
        // if the sign is positive, shift the string by one byte to skip over the sign character
        for (int i = 0; i < 5; i++) {
            result[i] = result[i + 1];
        }
    }
    return result;
}



// the functions to get the 3 axis positions :

char *get_X_axis()
{
    mpu.update();
  int X = round(mpu.getAngleX());
  return int_to_char_with_sign(X);
}

char *get_Y_axis()
{  
  mpu.update();
  int Y = round(mpu.getAngleY());
  return int_to_char_with_sign(Y);
}

char *get_Z_axis()
{
    mpu.update();
  int Z = round(mpu.getAngleZ());
  return int_to_char_with_sign(Z);
}



// char *get_Y_axis2()
// {
//   char buffer[5] = {};
//   mpu.update();
//   int new_Y = round(mpu.getAngleY());

//   itoa(new_Y, buffer, 10);

//   Serial.print("Buffer size for Y : ");
//   Serial.print(new_Y);

//   delay(10);
//   return buffer;
// }

// char *get_Y_axis()
// {
//   int new_Y = round(mpu.getAngleY());

//   char *result = NULL;
//   int length = snprintf(NULL, 0, "%d", new_Y); // get the length of the resulting string

//   result = (char *)malloc(length + 1);       // allocate memory for the string
//   snprintf(result, length + 1, "%d", new_Y); // convert the integer to a string

//   return result;
// }

// char *get_Z_axis()
// {
//   int new_Z = round(mpu.getAngleZ());

//   char *result = NULL;
//   int length = snprintf(NULL, 0, "%d", new_Z); // get the length of the resulting string

//   result = (char *)malloc(length + 1);       // allocate memory for the string
//   snprintf(result, length + 1, "%d", new_Z); // convert the integer to a string

//   return result;
// }