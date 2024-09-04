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

// ROBOT1
Servo FT6335Servo1;
Servo DM996Servo1;
Servo DM996Servo2;
Servo DM996Servo3;

// ROBOT2
Servo FT6335Servo2;
Servo DM996Servo4;
Servo DM996Servo5;
Servo DM996Servo6;

// ROBOT1
int servo1Pin = 23; // Servo Base (19)
int servo2Pin = 22; // Servo 1 (22)
int servo3Pin = 21; // Servo 2 (21)
int servo4Pin = 19; // Servo 3 (bout de bras) (23)

// ROBOT2
int servo5Pin = 18; // Servo Base
int servo6Pin = 5;  // Servo 1
int servo7Pin = 17; // Servo 2
int servo8Pin = 16; // Servo 3 (bout de bras)

void setup()
{
    Serial.begin(115200);

    // ROBOT 1
    FT6335Servo1.attach(servo1Pin);
    DM996Servo1.attach(servo2Pin);
    DM996Servo2.attach(servo3Pin);
    DM996Servo3.attach(servo4Pin);
    // Pose init robot 1
    DM996Servo2.write(40);
    FT6335Servo1.write(0);
    DM996Servo1.write(50);
    DM996Servo3.write(140);

    // ROBOT 2
    FT6335Servo2.attach(servo5Pin);
    DM996Servo4.attach(servo6Pin);
    DM996Servo5.attach(servo7Pin);
    DM996Servo6.attach(servo8Pin);
    // Pose init robot 2
    /*DM996Servo5.write(40);
    FT6335Servo2.write(0);
    DM996Servo4.write(50);
    DM996Servo6.write(140);*/

    while (!Serial)
    {
        ; // Attente de connexion série
    }
}

/*
void moveSlowlyBase1(int startAngle, int endAngle, int delay_ms)
{
    int step = (startAngle < endAngle) ? 1 : -1;

    for (int angle = startAngle; angle != endAngle; angle += step)
    {
        FT6335Servo1.write(angle);
        delay(delay_ms);
    }
    FT6335Servo1.write(endAngle); // Assurez-vous d'atteindre l'angle final
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

// ROBOT 2
void moveSlowlyBase2(int startAngle, int endAngle, int delay_ms)
{
    int step = (startAngle < endAngle) ? 1 : -1;

    for (int angle = startAngle; angle != endAngle; angle += step)
    {
        FT6335Servo2.write(angle);
        delay(delay_ms);
    }
    FT6335Servo2.write(endAngle); // Assurez-vous d'atteindre l'angle final
}

void moveSlowly4(int startAngle, int endAngle, int delay_ms)
{
    int step = (startAngle < endAngle) ? 1 : -1;

    for (int angle = startAngle; angle != endAngle; angle += step)
    {
        DM996Servo4.write(angle);
        delay(delay_ms);
    }
    DM996Servo4.write(endAngle); // Assurez-vous d'atteindre l'angle final
}

void moveSlowly5(int startAngle, int endAngle, int delay_ms)
{
    int step = (startAngle < endAngle) ? 1 : -1;

    for (int angle = startAngle; angle != endAngle; angle += step)
    {
        DM996Servo5.write(angle);
        delay(delay_ms);
    }
    DM996Servo5.write(endAngle); // Assurez-vous d'atteindre l'angle final
}

void moveSlowly6(int startAngle, int endAngle, int delay_ms)
{
    int step = (startAngle < endAngle) ? 1 : -1;

    for (int angle = startAngle; angle != endAngle; angle += step)
    {
        DM996Servo6.write(angle);
        delay(delay_ms);
    }
    DM996Servo6.write(endAngle); // Assurez-vous d'atteindre l'angle final
}*/

// Fonction générique pour déplacer lentement n'importe quel servo
void moveSlowly(Servo &servo, int startAngle, int endAngle, int delay_ms)
{
    int step = (startAngle < endAngle) ? 1 : -1;

    for (int angle = startAngle; angle != endAngle; angle += step)
    {
        servo.write(angle);
        delay(delay_ms);
    }
    servo.write(endAngle); // Assurez-vous d'atteindre l'angle final
}

void loop()
{
    //  Vérification de la dispo des données sur le port série
    if (Serial.available() > 0)
    {
        char cmd_test = Serial.read();
        // Entrée par l'utilisateur = simulation d'un mot envoyé par un robot
        // ROBOT 1
        if (cmd_test == '0')
        {
            // MBASE
            moveSlowly(FT6335Servo1, 0, 1, 50); // Déplace de 0° à 90° avec un délai de 50ms entre chaque degré
            Serial.println("MBASE a 1 deg");
            // M3
            moveSlowly(DM996Servo3, 140, 87, 50); // Déplace de 140° à 70° avec un délai de 50ms entre chaque degré
            Serial.println("M3 a 87 deg");
            // M2
            moveSlowly(DM996Servo2, 40, 50, 50); // Déplace de 40° à 20° avec un délai de 50ms entre chaque degré
            Serial.println("M2 a 50 deg");
            // M1
            moveSlowly(DM996Servo1, 50, 110, 50); // Déplace de 0° à 30° avec un délai de 50ms entre chaque degré
            Serial.println("M1 a 100 deg");
        }
        if (cmd_test == '1')
        {
            // M1
            moveSlowly(DM996Servo1, 110, 20, 50); // Déplace de 0° à 30° avec un délai de 50ms entre chaque degré
            Serial.println("M1 a 20 deg");
            // MBASE
            moveSlowly(FT6335Servo1, 1, 49, 50); // Déplace de 0° à 90° avec un délai de 50ms entre chaque degré
            Serial.println("MBASE a 90 deg");
            // M3
            moveSlowly(DM996Servo3, 87, 120, 50); // Déplace de 140° à 70° avec un délai de 50ms entre chaque degré
            Serial.println("M3 a 120 deg");
            // M1
            moveSlowly(DM996Servo1, 20, 57, 50); // Déplace de 0° à 30° avec un délai de 50ms entre chaque degré
            Serial.println("M1 a 55 deg");
        }
        // ROBOT 2
        if (cmd_test == '2')
        {
            // MBASE
            moveSlowly(FT6335Servo2, 0, 1, 50); // Déplace de 0° à 90° avec un délai de 50ms entre chaque degré
            Serial.println("MBASE a 1 deg");
            // M3
            moveSlowly(DM996Servo6, 140, 87, 50); // Déplace de 140° à 70° avec un délai de 50ms entre chaque degré
            Serial.println("M3 a 87 deg");
            // M2
            moveSlowly(DM996Servo5, 40, 50, 50); // Déplace de 40° à 20° avec un délai de 50ms entre chaque degré
            Serial.println("M2 a 50 deg");
            // M1
            moveSlowly(DM996Servo4, 50, 110, 50); // Déplace de 0° à 30° avec un délai de 50ms entre chaque degré
            Serial.println("M1 a 100 deg");
        }
        if (cmd_test == '3')
        {
            // M1
            moveSlowly(DM996Servo4, 110, 20, 50); // Déplace de 0° à 30° avec un délai de 50ms entre chaque degré
            Serial.println("M1 a 20 deg");
            // MBASE
            moveSlowly(FT6335Servo2, 1, 49, 50); // Déplace de 0° à 90° avec un délai de 50ms entre chaque degré
            Serial.println("MBASE a 90 deg");
            // M3
            moveSlowly(DM996Servo6, 87, 120, 50); // Déplace de 140° à 70° avec un délai de 50ms entre chaque degré
            Serial.println("M3 a 120 deg");
            // M1
            moveSlowly(DM996Servo4, 20, 57, 50); // Déplace de 0° à 30° avec un délai de 50ms entre chaque degré
            Serial.println("M1 a 55 deg");
        }

        // UNIQUEMENT POUR LES TESTS
        if (cmd_test == 'b')
        // M1
        {
        }
        if (cmd_test == '9')
        // M1
        {
        }
    }
}