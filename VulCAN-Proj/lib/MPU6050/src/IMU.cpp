#include "Wire.h"       
#include "I2Cdev.h"     
#include "MPU6050.h"    

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

struct MyData {
  byte X;
  byte Y;
  byte Z;
};

MyData data;

struct angles {
  float z_angle;
  float x_angle;
};

angles Get_IMU() {
  angles result;
  
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  float accel_x = ax/16384.0f;
  float accel_y = ay/16384.0f;
  float accel_z = az/16384.0f;

  float gyro_x = gx/131.0f;
  float gyro_y = gy/131.0f;
  float gyro_z = gz/131.0f;

  result.z_angle = atan2(-accel_x, sqrt(accel_y * accel_y + accel_z * accel_z)) * 180.0 / M_PI;
  result.x_angle = atan2(accel_y, accel_z) * 180.0 / M_PI;
  Serial.print(result.z_angle);
  Serial.print(", ");

  Serial.println(result.x_angle);

  return result;
}


byte get_Z_axis() {
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    data.Z = map(az, -17000, 17000, 0, 255);
    return data.Z;
}

byte get_X_axis() {
      mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    data.X = map(ax, -17000, 17000, 0, 255);
    return data.X;
}
void calibrate_IMU() {

}

void IMU_Setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();
  mpu.CalibrateGyro(6);
  mpu.CalibrateAccel(6);
  mpu.reset();
  mpu.setSleepEnabled(false);
}