#include <Servo.h>
#include <Arduino.h>
#include <Wire.h>

#define SERVO_PIN_X 26
#define SERVO_PIN_Y 27

Servo servo_x; // create servo object to control a servo
Servo servo_y; // create servo object to control a servo

// twelve servo objects can be created on most boards

int init_pos = 0; // variable to store the servo position

void servo_setup()
{
    servo_x.attach(SERVO_PIN_X); // attaches the servo on pin 26 to the servo object
    servo_y.attach(SERVO_PIN_Y); // attaches the servo on pin 27 to the servo object

    servo_x.write(init_pos); // initializes the servo_x to idle position
    servo_y.write(init_pos); // initializes the servo_y to idle position
}

void turn_servos(int pos_x, int pos_y)
{
    // moving servo_x according to pos_x
    servo_x.write(pos_x);

    // moving servo_y according to pos_y
    servo_y.write(pos_y);
}