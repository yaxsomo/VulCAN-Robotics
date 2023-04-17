#include <ESP32_CAN_CTRL.h>

#define TX_GPIO_NUM 32  // Connects to CTX
#define RX_GPIO_NUM 33  // Connects to CRX



void setup() {
  Serial.begin(115200);
  while (!Serial)
    ;
  delay(1000);

  Serial.println("CAN Receiver/Receiver");

  // Set the pins
  CAN.setPins(RX_GPIO_NUM, TX_GPIO_NUM);

  // start the CAN bus at 500 kbps
  if (!CAN.begin(500E3)) {
    Serial.println("Starting CAN failed!");
    while (1)
      ;
  } else {
    Serial.println("CAN Initialized");
  }
}

void loop() {
    canSender();
    delay(1000);
}