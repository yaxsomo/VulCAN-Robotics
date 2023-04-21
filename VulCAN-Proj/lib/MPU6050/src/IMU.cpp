#include "Wire.h"
#include <MPU6050_light.h>
#include <math.h>

MPU6050 mpu(Wire);
unsigned long timer = 0;

void IMU_Setup() {
  Serial.begin(115200);
  Wire.begin();
  
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ } // stop everything if could not connect to MPU6050
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  delay(1000);

  Serial.println("Done!\n");
}

void Get_IMU() {
  mpu.update();
  
  if((millis()-timer)>10){ // print data every 10ms
	Serial.print("X : ");
	Serial.print((int)round(mpu.getAngleX()));
	Serial.print("\tY : ");
	Serial.print((int)round(mpu.getAngleY()));
	Serial.print("\tZ : ");
	Serial.println((int)round(mpu.getAngleZ()));
	timer = millis();  
  }
}


// the functions to get the 3 axis positions : 

int get_X_axis() {
  mpu.update();
    delay(10);
    return (int)round(mpu.getAngleX());
}

int get_Y_axis() {
  mpu.update();
    delay(10);
    return (int)round(mpu.getAngleY());
}

int get_Z_axis() {
  mpu.update();
    delay(10);
    return (int)round(mpu.getAngleZ());
}
