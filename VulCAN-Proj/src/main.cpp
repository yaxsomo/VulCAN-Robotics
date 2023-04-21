#include <motors.h>
#include <ESP32_CAN_CTRL.h>
#include <IMU.h>
#include <Arduino.h>

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
  CAN_Setup(RX_GPIO_NUM, TX_GPIO_NUM);

  // IF SENDER
  // IMU_Setup();

  // IF RECEIVER
  servo_setup();
}

void loop()
{

  // IF SENDER
  // CAN_Sender();

  // IF RECEIVER 
  CAN_Receiver();

  delay(1000);
}