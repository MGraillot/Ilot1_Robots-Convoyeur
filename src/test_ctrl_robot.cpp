/*
#include <Arduino.h>
#include <cmath>
#include <ESP32Servo.h>

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

  /*
  // Position pose robot
  FT6335Servo.write(0);
  DM996Servo1.write(0);
  DM996Servo2.write(30);
  DM996Servo3.write(30);
}

/* void pose_init() // A COMMENTER SI DANS LE SETUP POUR TEST
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
}*/

#include <ESP32Servo.h>

Servo FT6335Servo;
Servo DM996Servo1;
Servo DM996Servo2;
Servo DM996Servo3;

int servoPin = 19;  // Servo Base
int servo1Pin = 22; // Servo 1
int servo2Pin = 21; // Servo 2
int servo3Pin = 23; // Servo 3 (bout de bras)

void setup()
{
  Serial.begin(115200);

  FT6335Servo.attach(servoPin);
  DM996Servo1.attach(servo1Pin);
  DM996Servo2.attach(servo2Pin);
  DM996Servo3.attach(servo3Pin);

  DM996Servo2.write(40);
  FT6335Servo.write(0);
  DM996Servo1.write(0);
  DM996Servo3.write(140);

  while (!Serial)
  {
    ; // Attente de connexion série
  }
}

/*void moveSlowlyBase(int startAngle, int endAngle, int delay_ms)
{
  int totalRotation;
  if (startAngle <= endAngle)
  {
    totalRotation = endAngle - startAngle;
    if (totalRotation > 97) // 180 deg du servo moteur
    {
      totalRotation = -(194 - totalRotation); // 360 deg du servo moteur
    }
  }
  else
  {
    totalRotation = -(startAngle - endAngle);
    if (totalRotation < -97)
    {
      totalRotation = 194 + totalRotation;
    }
  }

  int step = (totalRotation > 0) ? 1 : -1;
  int currentAngle = startAngle;

  for (int i = 0; i != totalRotation; i += step)
  {
    currentAngle = (currentAngle + step + 194) % 194;
    FT6335Servo.write(currentAngle);
    delay(delay_ms);
  }

  FT6335Servo.write(endAngle); // Assurez-vous d'atteindre l'angle final
}*/

void moveSlowlyBase(int startAngle, int endAngle, int delay_ms)
{
  int step = (startAngle < endAngle) ? 1 : -1;

  for (int angle = startAngle; angle != endAngle; angle += step)
  {
    FT6335Servo.write(angle);
    delay(delay_ms);
  }
  FT6335Servo.write(endAngle); // Assurez-vous d'atteindre l'angle final
}

void moveSlowly1(int startAngle, int endAngle, int delay_ms)
{
  int step = (startAngle < endAngle) ? 1 : -1;

  for (int angle = startAngle; angle != endAngle; angle += step)
  {
    DM996Servo1.write(angle);
    delay(delay_ms);
  }
  DM996Servo1.write(endAngle); // Assurez-vous d'atteindre l'angle final
}

void moveSlowly2(int startAngle, int endAngle, int delay_ms)
{
  int step = (startAngle < endAngle) ? 1 : -1;

  for (int angle = startAngle; angle != endAngle; angle += step)
  {
    DM996Servo2.write(angle);
    delay(delay_ms);
  }
  DM996Servo2.write(endAngle); // Assurez-vous d'atteindre l'angle final
}

void moveSlowly3(int startAngle, int endAngle, int delay_ms)
{
  int step = (startAngle < endAngle) ? 1 : -1;

  for (int angle = startAngle; angle != endAngle; angle += step)
  {
    DM996Servo3.write(angle);
    delay(delay_ms);
  }
  DM996Servo3.write(endAngle); // Assurez-vous d'atteindre l'angle final
}

void loop()
{
  //  Vérification de la dispo des données sur le port série
  if (Serial.available() > 0)
  {
    char cmd_test = Serial.read();
    // Entrée par l'utilisateur = simulation d'un mot envoyé par un robot
    if (cmd_test == 'b')
    {
      moveSlowlyBase(0, 49, 50); // Déplace de 0° à 90° avec un délai de 50ms entre chaque degré
      Serial.println("je suis a la pose 97");
    }
    if (cmd_test == '1')
    {
      moveSlowly1(0, 30, 50); // Déplace de 0° à 30° avec un délai de 50ms entre chaque degré
      Serial.println("je suis a la pose 97");
    }
    if (cmd_test == '2')
    {
      moveSlowly2(40, 20, 50); // Déplace de 40° à 20° avec un délai de 50ms entre chaque degré
      Serial.println("je suis a la pose 97");
    }
    if (cmd_test == '3')
    {
      moveSlowly3(140, 70, 50); // Déplace de 140° à 70° avec un délai de 50ms entre chaque degré
      Serial.println("je suis a la pose 97");
    }

    if (cmd_test == 'c')
    {
      moveSlowlyBase(0, 49, 50); // Déplace de 0° à 90° avec un délai de 50ms entre chaque degré
      Serial.println("je suis a la pose 97");
    }
    if (cmd_test == '4')
    {
      moveSlowly1(30, 5, 50); // Déplace de 30° à 5° avec un délai de 50ms entre chaque degré
      Serial.println("je suis a la pose 97");
    }
    if (cmd_test == '5')
    {
      moveSlowly2(20, 80, 50); // Déplace de 20° à 80° avec un délai de 50ms entre chaque degré
      Serial.println("je suis a la pose 97");
    }
    if (cmd_test == '6')
    {
      moveSlowly3(70, 140, 50); // Déplace de 70° à 140° avec un délai de 50ms entre chaque degré
      Serial.println("je suis a la pose 97");
    }
    if (cmd_test == '7')
    {
      moveSlowly1(30, 15, 50); // Déplace de 30° à 15° avec un délai de 50ms entre chaque degré
      Serial.println("je suis a la pose 97");
    }

    // Serial.println("servo 3 a 20 deg");
    // delay(1000);

    /*moveSlowlyBase(98, 0, 50); // Retourne de 180° à 0°
    Serial.println("je suis a la pose 0 (init)");
    delay(1000);*/

    /*moveSlowlyServo1(0, -30, 25); // Déplace de 0° à 180° avec un délai de 50ms entre chaque degré
    delay(1000);
    moveSlowlyServo2(0, 30, 25); // Déplace de 0° à 180° avec un délai de 50ms entre chaque degré
    delay(1000);
    moveSlowlyServo3(0, 10, 25); // Déplace de 0° à 180° avec un délai de 50ms entre chaque degré
    delay(1000);


    moveSlowlyServo1(-30, 0, 25); // Déplace de 0° à 180° avec un délai de 50ms entre chaque degré
    delay(1000);
    moveSlowlyServo2(30, 0, 25); // Déplace de 0° à 180° avec un délai de 50ms entre chaque degré
    delay(1000);
    moveSlowlyServo3(10, 0, 25); // Déplace de 0° à 180° avec un délai de 50ms entre chaque degré
    delay(1000);*/
  }
}