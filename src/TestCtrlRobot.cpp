#include <Arduino.h>
#include <cmath>
#include <ESP32Servo.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <AccelStepper.h>

// TEST ROBOT SERVO MOTEURS

#define PIN_SERVO1 19 // SERVO BASE (0)
#define PIN_SERVO2 22 // SERVO COUDE 1 (4)
#define PIN_SERVO3 21 // SERVO COUDE 2 (15)
#define PIN_SERVO4 23 // SERVO COUDE 3 (17)

Servo FT6335Servo;
Servo DM996Servo1;
Servo DM996Servo2;
Servo DM996Servo3;

void setup()
{

  FT6335Servo.attach(PIN_SERVO1);
  DM996Servo1.attach(PIN_SERVO2);
  DM996Servo2.attach(PIN_SERVO3);
  DM996Servo3.attach(PIN_SERVO4);

  // Position pose robot
  FT6335Servo.write(0);
  DM996Servo1.write(0);
  DM996Servo2.write(30);
  DM996Servo3.write(30);
}

void pose_init() // A COMMENTER SI DANS LE SETUP POUR TEST
{
  FT6335Servo.write(0);
  delay(10);

  DM996Servo1.write(0);
  delay(10);

  DM996Servo2.write(30);
  delay(10);

  DM996Servo3.write(30);
  delay(10);
  delay(1000);
}

void loop()
{
  // INIT POSITION -- A COMMENTER SI DANS LE SETUP
  FT6335Servo.write(0);
  delay(10);
  DM996Servo1.write(0);
  delay(10);
  DM996Servo2.write(5);
  delay(10);
  DM996Servo3.write(0);
  delay(10);
  sleep(3);

  // MOVE ROBOT PRISE PIECE
  DM996Servo1.write(20);
  delay(50);
  delay(1000);
  DM996Servo3.write(0);
  delay(50);
  delay(1000);
  DM996Servo2.write(20);
  delay(50);
  delay(1000);
  DM996Servo2.write(30);
  delay(50);
  delay(1000);
  FT6335Servo.write(48);
  delay(50);
  delay(1000);
  DM996Servo2.write(20);
  delay(50);
  sleep(3);
  DM996Servo2.write(30);
  delay(50);
  sleep(3);

  FT6335Servo.write(0);
  delay(50);
  sleep(1);

  // moveSmooth(FT6335Servo, 48);
  FT6335Servo.write(48);
  delay(10);
  sleep(3);

  FT6335Servo.write(48); // 90° robot
  delay(10);
  sleep(3);

  // moveSmooth(DM996Servo2, 25);
  DM996Servo1.write(25);
  delay(10);
  sleep(3);
  // moveSmooth(DM996Servo2, 50);
  DM996Servo1.write(50);
  delay(10);
  sleep(3);

  // TEST BOUCLE FOR
  for (int i = 0; i <= 150; i++)
  {
    DM996Servo1.write(i);
    delay(10);
  }

  for (int i = 150; i >= 0; i--)
  {
    DM996Servo1.write(i);
    delay(10);
  }

  sleep(0);
}