#include <Arduino.h>
#include <cmath>
#include <ESP32Servo.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <SharpIR.h>

/* // TEST ROBOT SERVO MOTEURS

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
  DM996Servo2.write(0);
  DM996Servo3.write(0);
}

void loop()
{
  // ESSAIS SERV0 S90 - FT6335 - DM996

  SG90Servo.write(0);
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
  FT6335Servo.write(0);
  delay(10);
  sleep(5);
  DM996Servo.write(120);
  delay(10);
  sleep(5);

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

  sleep(0);

// TEST ROBOT V2 - FT6335 + DM996R
DM996Servo1.write(30);
delay(10);
sleep(3);
DM996Servo3.write(90);
delay(10);
sleep(3);
DM996Servo2.write(120);
delay(10);
sleep(3);
}*/

/* // TEST NEMMA WITH SENSOR SHARP IR

    const int DIR = 12;            // Pin G12 ESP32
    const int STEP = 14;           // Pin G14 ESP32
    const int steps_per_rev = 200; // nbre pas par tour
    #define PIN_SG90 33
    SharpIR sensor(SharpIR::GP2Y0A21YK0F, 35); // #define sensor 35 // Sharp IR GP2Y0A41SK0F (4-30cm, analog)
    Servo SG90Servo;

    void setup()
    {

      // put your setup code here, to run once:
      Serial.begin(9600); // start the serial port
      SG90Servo.attach(PIN_SG90);
      SG90Servo.write(0);
      // pinMode(sensor, INPUT);
      // pinMode(STEP, OUTPUT);
      // pinMode(DIR, OUTPUT);
      // sensor.setFilterRate(0.1f);
    }

    void loop()
    {
      int distance = sensor.getDistance(); // Calculate the distance in centimeters and store the value in a variable

      Serial.println(distance); // Print the value to the serial monitor

      if (distance == 9)
      {
        SG90Servo.write(60);
        delay(2000);
      }
    }
    */

/* // TEST CAPTEUR IR CLASSIQUE

    #define irSensor 35
    #define LED 33

    int irReading;

    void setup()
    {
      Serial.begin(9600);
      pinMode(irSensor, INPUT);
      pinMode(LED, OUTPUT);
    }

    void loop()
    {

      irReading = digitalRead(irSensor); // lecture de la valeur du signal
      Serial.print("State Sensor - ");
      Serial.println(irReading);

      if (irReading == LOW)
      {
        digitalWrite(LED, HIGH);
      }
      else
      {
        digitalWrite(LED, LOW);
      }
    }
    */

/* // TEST POMPE A VIDE

    #define PIN_ENABLE_POMPE 32
    #define PIN_PHASE_POMPE 33
    #define Valve 21 //(17)

    void setup()
    {
      pinMode(PIN_ENABLE_POMPE, OUTPUT);
      pinMode(PIN_PHASE_POMPE, OUTPUT);
      pinMode(Valve, OUTPUT);

      digitalWrite(PIN_PHASE_POMPE, HIGH);
      digitalWrite(Valve, HIGH);
    }

    void loop()
    {
      digitalWrite(PIN_ENABLE_POMPE, HIGH);
      delay(1000);

      digitalWrite(PIN_ENABLE_POMPE, LOW);
      delay(2500);
      digitalWrite(Valve, LOW);

    }
    */

/* // TEST NEMMA WITH SENSOR IR

const int DIR = 12;            // Pin G12 ESP32
const int STEP = 14;           // Pin G14 ESP32
const int steps_per_rev = 200; // nbre pas par tour
void setup()
{
  Serial.begin(9600); // start the serial port
  pinMode(STEP, OUTPUT);
}

void loop()
{

  // put your main code here, to run repeatedly:
  digitalWrite(DIR, HIGH);
  Serial.println("Tourne dans le sens horaire");

  for (int i = 0; i < steps_per_rev; i++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(3000);
    digitalWrite(STEP, LOW);
    delayMicroseconds(3000);
  }
  delay(1000);

  digitalWrite(DIR, LOW);
  Serial.println("Tour dans le sens trigo");

  for (int i = 0; i < steps_per_rev; i++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP, LOW);
    delayMicroseconds(1000);
  }
  delay(1000);
}*/

/* // TEST LAMBDA

#define PIN_IR 17
IRrecv irrecv(PIN_IR);
decode_results results;

void setup()
{
  irrecv.enableIRIn();
  Serial.begin(9600);
}*/