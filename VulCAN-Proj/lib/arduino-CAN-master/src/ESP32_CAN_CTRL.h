#ifndef _ESP32_CAN_CTRL_H_
#define _ESP32_CAN_CTRL_H_

#include <Arduino.h>
#include <CAN.h>

void CAN_Setup(int rx, int tx);
void sendCommands(float Z, float X);
void CAN_Sender();
void CAN_Receiver();
void parseMessage(char* data);
// void sendData(char* dataToSend);

#endif // _CAN_H_
