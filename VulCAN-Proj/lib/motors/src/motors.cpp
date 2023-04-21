#include <Servo.h>
#include <Arduino.h>
#include <Wire.h>

#define SERVO_PIN_X 26
#define SERVO_PIN_Y 27

Servo servo_x; // create servo object to control a servo
Servo servo_y; // create servo object to control a servo


int init_pos = 0; // variable to store the servo position

void servo_setup()
{
    servo_x.attach(SERVO_PIN_X); // attaches the servo on pin 26 to the servo object
    servo_y.attach(SERVO_PIN_Y); // attaches the servo on pin 27 to the servo object

    servo_x.write(init_pos); // initializes the servo_x to idle position
    servo_y.write(init_pos); // initializes the servo_y to idle position
}

void turn_servos(float pos_Z, float pos_X)
{
    // moving servo_x according to pos_x
    servo_x.write((int)pos_Z);

    // moving servo_y according to pos_y
    servo_y.write((int)pos_X);
}

// Resets the servo motors to their initial position of 90 degrees
void resetServos() {
  servo_x.write(90);
  servo_y.write(90);
}

// Maps a value from one range to another
int mapValue(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}