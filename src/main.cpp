#include <Arduino.h>
#include <ESP32Servo.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>

// #define PIN_SERVO1 4
// #define PIN_IR 17

// #define PIN_SERVO2 0
// #define PIN_SERVO3 16
#define PIN_ENABLE_POMPE 32
#define PIN_PHASE_POMPE 33
#define Valve 17
// Servo SG90Servo;
// Servo FT6335Servo;
// Servo DM996Servo;
//  IRrecv irrecv(PIN_IR);

// decode_results results;

// #define irSensor 17
// #define LED 33

// int irReading;

void setup()
{
  /*irrecv.enableIRIn();
  Serial.begin(9600);*/

  // SG90Servo.attach(PIN_SERVO1);
  // FT6335Servo.attach(PIN_SERVO1);
  // DM996Servo.attach(PIN_SERVO3);

  /*Serial.begin(9600);
  pinMode(irSensor, INPUT);
  pinMode(LED, OUTPUT);*/

  // TEST POMPE A VIDE //
  pinMode(PIN_ENABLE_POMPE, OUTPUT);
  pinMode(PIN_PHASE_POMPE, OUTPUT);
  digitalWrite(PIN_PHASE_POMPE, HIGH);
  pinMode(Valve, OUTPUT);
}

void loop()
{

  // ESSAIS CAPTEUR IR SENSOR (5 à 25mm)
  /*irReading = digitalRead(irSensor); // lecture de la valeur du signal
  Serial.print("State Sensor - ");
  Serial.println(irReading);

  if (irReading == LOW)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }*/

  // ESSAIS SERV0 S90 - FT6335 - DM996

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
  sleep(5);*/
  /*SG90Servo.write(60);
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
  FT6335Servo.write(0);
  delay(10);
  sleep(5);
  DM996Servo.write(120);
  delay(10);
  sleep(5);*/

  /*for (int i = 0; i <= 150; i++)
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

  // TEST POMPE A VIDE //
  digitalWrite(PIN_ENABLE_POMPE, HIGH);
  delay(500);
  digitalWrite(PIN_ENABLE_POMPE, LOW);
  digitalWrite(Valve, HIGH);
  delay(2500);
  digitalWrite(Valve, LOW);
  delay(1000);
}