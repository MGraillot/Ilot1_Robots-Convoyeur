#include <Arduino.h>
#include <ESP32Servo.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>

#define PIN_SERVO1 4
#define PIN_IR 17

#define START_AMR 0x000000 // Button ON-OFF
#define STOP_AMR 0x000000  // Button MENU
// #define PIN_SERVO2 0
// #define PIN_SERVO3 16
Servo SG90Servo;
// Servo FT6335Servo;
// Servo DM996Servo;
IRrecv irrecv(PIN_IR);

decode_results results;

void setup()
{
  irrecv.enableIRIn();
  Serial.begin(9600);

  SG90Servo.attach(PIN_SERVO1);
  // FT6335Servo.attach(PIN_SERVO2);
  // DM996Servo.attach(PIN_SERVO3);
}

void loop()
{
  /*SG90Servo.write(0);
  delay(10);
  SG90Servo.write(180);
  delay(10);
  sleep(2);
  sleep(5);
FT6335Servo.write(0);
delay(10);
sleep(5);
DM996Servo.write(0);
delay(10);
sleep(5);
SG90Servo.write(60);
delay(10);
sleep(5);
FT6335Servo.write(120);
delay(10);
sleep(5);
DM996Servo.write(60);
delay(10);
sleep(5);

SG90Servo.write(180);
delay(10);
FT6335Servo.write(360);
delay(10);
sleep(5);
DM996Servo.write(120);
delay(10);
sleep(5);*/
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    if (results.value == START_AMR)
    {
      SG90Servo.write(150);
      delay(10);
    }
    else if (results.value == STOP_AMR)
    {
      SG90Servo.write(0);
      delay(10);
    }
    delay(1000);
    irrecv.resume();

    /*
    for (int i = 0; i <= 150; i++)
      {
        SG90Servo.write(i);
        delay(10);
      }

      for (int i = 150; i >= 0; i--)
      {
        SG90Servo.write(i);
        delay(10);
      }

      sleep(0);*/
  }
}