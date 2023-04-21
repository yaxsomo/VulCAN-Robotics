#include <motors.h>
#include <ESP32_CAN_CTRL.h>
#include <IMU.h>


#define RX_GPIO_NUM 33 // Connects to CAN RX
#define TX_GPIO_NUM 32 // Connects to CAN TX

#define SDA 21
#define SCL 22

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  while (!Serial)
    ;
  delay(1000);
  servo_setup();
  CAN_Setup(RX_GPIO_NUM, TX_GPIO_NUM);
  IMU_Setup();
}

void loop()
{
  CAN_Sender();
  // Get_IMU();
  get_Z_axis();
  get_X_axis();
  // canReceiver();
  delay(1000);
}