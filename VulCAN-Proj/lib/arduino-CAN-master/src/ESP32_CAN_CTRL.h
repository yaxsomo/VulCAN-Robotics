#ifndef _ESP32_CAN_CTRL_H_
#define _ESP32_CAN_CTRL_H_

#include <Arduino.h>
#include <CAN.h>

void canSender();
void canReceiver();
void parseMessage(char* data);
// void sendData(char* dataToSend);

#endif // _CAN_H_
