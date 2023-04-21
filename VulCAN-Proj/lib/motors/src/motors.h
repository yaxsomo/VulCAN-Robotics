#ifndef MOTORS_H
#define MOTORS_H

#include <Servo.h>
#include <Arduino.h>
#include <Wire.h>

#define SERVO_PIN_X 26
#define SERVO_PIN_Y 27

extern Servo servo_x; // declare the servo_x object as external
extern Servo servo_y; // declare the servo_y object as external

void servo_setup(); // function prototype for servo setup

void turn_servos(int pos_Z, int pos_X) // function prototype for turning the servos

#endif /* MOTORS_H */