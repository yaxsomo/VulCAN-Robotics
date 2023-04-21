#ifndef _ESP32_CAN_CTRL_H_
#define _ESP32_CAN_CTRL_H_

#include <Arduino.h>
#include <CAN.h>

void CAN_Setup(int rx, int tx);
void sendCommands(float Z, float X);
void CAN_Sender();
void CAN_Receiver();
void parseMessage(char* data);
uint8_t int_to_uint8(int valeur);
int cuint8_to_int(uint8_t valeur_uint8);


// void sendData(char* dataToSend);

#endif // _CAN_H_
