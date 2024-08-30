#include <Arduino.h>
#include <cmath>
#include <ESP32Servo.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <AccelStepper.h>

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
}*/

/*// TEST ACTION WITH SENSOR SHARP IR
#include <SharpIR.h>

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

// TEST CAPTEUR IR CLASSIQUE

/*// Pins connectées au A4988 driver pas à pas
#define DIR_PIN 12
#define STEP_PIN 14
// Pin connectée au capteur IR
#define irSensor 35

// Variable recevant l'information du capteur IR (0 ou 1)
int irReading;
// Variable qui prend la valeur qu'on a envoyer dans le moniteur série
String commande;

// Instance AccelStepper (AccelStepper.h)
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup()
{
  Serial.begin(9600);

  // Configureation broches motor + sensor IR
  pinMode(irSensor, INPUT);
}

void loop()
{
  irReading = digitalRead(irSensor);
  Serial.println(irReading);
  delay(500);
  if (Serial.available() > 0 )
  {
      commande = Serial.readString();
  }
  else
  {
    if (commande == "a")
    {
      irReading = digitalRead(irSensor); // lecture de la valeur du signal
      while (irReading == HIGH)
      {
        stepper.setMaxSpeed(1000); // Vitesse sens horaire (positive)
        stepper.setAcceleration(500); // Vitesse sens horaire (positive)
        stepper.setSpeed(200); // Vitesse sens horaire (positive)
      }
      stepper.stop();
    }
    else if (commande == "b")
    {
      stepper.stop();
    }
  }
}
*/

// TEST NEMA 17 DU 26/0724

// Pin connecte au A4988 driver pas à pas
#define DIR_PIN 12
#define STEP_PIN 14

// Pin connecte au sensor IR
#define IR_SENSOR_PIN 35

// Instance AccelStepper (AccelStepper.h)
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN); // On utilise un DRIVER qui contient 2 pins (DRIVER=1)

void setup()
{
  Serial.begin(115200);
  // Configuration broches motor + sensor IR
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(IR_SENSOR_PIN, INPUT);

  // Maximum speed & acceleration
  stepper.setMaxSpeed(1000); // vitesse maxi du moteur en pas par seconde
  // stepper.setAcceleration(50);     // accel du moteur en pas par seconde au carré. Permet au moteur de démarrer et de s'arrêter en douceur
  stepper.setSpeed(-400); // vitesse initiale du moteur en pas par seconde. (+ sens horaire / - sens trigo)
}

/*
void stop()
{
  stepper.setSpeed(0);
  delay(2000);
}

void restart()
{
  stepper.setSpeed(200);
  delay(5000);
}*/

/*
void loop() // MOTEUR OK ARRET AVEC UN TEMPS DONNE
{
  // TEST CAPTEUR INFRA
  // int irReading = digitalRead(IR_SENSOR_PIN);
  // Serial.print(irReading);
  // delay(500);
  // RESULTS : 1(HIGH) --> PAS D'OBSTACLE * 0(LOW) --> OBSTACLE

  // -- Variables statiques --
  // Enregistrer le dernier moment où l'état du moteur a changé (démarrage/arrêt). Utiliser pour mesurer le temps écoulé
  static unsigned long lastChangeTime = 0;
  // Moteur en marche ? Utiliser pour alterner entre les états marche et arrêt
  static bool motorRunning = true;

  // Faire avancer le moteur en continu si la vitesse n'est pas zéro
  // Doit être appelée aussi souvent que possible pour assurer un mouvement fluide du moteur
  stepper.runSpeed();

  // Intervalle de temps pour changer l'état du moteur (en millisecondes)
  // Si moteur en marche, intervalle = 5 secondes (5000 ms)
  // Si moteur à l'arrêt, intervalle = 2 secondes (2000 ms)
  unsigned long interval = motorRunning ? 5000 : 2000; // 5 secondes en marche, 2 secondes à l'arrêt

  // Fonction pour changer l'état du moteur à faire ! OK FINI ET FONCTIONNE

  // Le moteur tourne en continu à la vitesse définie par myStepper.setSpeed(200);
  // Après 5 secondes(interval = 5000), le moteur s'arrête en définissant setSpeed(0); Après 2 secondes(interval = 2000),
  // le moteur redémarre en définissant à nouveau setSpeed(200);

  // On vérifie si l'intervalle de temps défini s'est écoulé en comparant le temps actuel (en millisecondes) avec lastChangeTime
  if (millis() - lastChangeTime >= interval)
  {
    // Variables statiques
    // Enregistrer le dernier moment où l'état du moteur a changé
    // Utilisation de millis() = mesurer le temps écoulé et alterner entre démarrage et arrêt du moteur

    // On met à jour lastChangeTime avec le temps actuel
    lastChangeTime = millis();

    // Indiquer si le moteur en marche
    // Si OUI
    if (motorRunning)
    {
      // Arrêter le moteur avec la vitesse définie à 0 avec setSpeed();
      stepper.setSpeed(0);
    }
  }
  else
  {
    // Redémarrer le moteur dans le même sens avec la vitesse définie avec setSpeed();
    stepper.setSpeed(-200);
  }
  // On inverse l'état de motorRunning (marche <-> arrêt)
  motorRunning = !motorRunning;
}
*/

void loop()
{
  // TEST CAPTEUR INFRA
  // int irReading = digitalRead(IR_SENSOR_PIN);
  // Serial.print(irReading);
  // delay(500);
  // RESULTS : 1(HIGH) --> PAS D'OBSTACLE * 0(LOW) --> OBSTACLE

  int irReading = digitalRead(IR_SENSOR_PIN); // Variable pour avoir les états du capteur
  Serial.print(irReading);

  // Statique pour mémoriser le dernier temps de changement d'état
  static unsigned long stopStartTime = 0;
  static bool motorStopped = false;

  // Si le capteur détecte un obstacle (LOW), arrêter le moteur
  if (irReading == LOW)
  {
    if (!motorStopped)
    {
      stepper.setSpeed(0);
      // Enregistrer le temps actuel quand l'obstacle est détecté
      stopStartTime = millis();
      motorStopped = true;
    }
  }

  // Si 10 secondes se sont écoulées depuis l'arrêt, redémarrer le moteur
  if (motorStopped && (millis() - stopStartTime >= 10000))
  {
    stepper.setSpeed(-400); // Ajuste cette valeur selon tes besoins
    motorStopped = false;
  }

  // Faire avancer le moteur si la vitesse n'est pas zéro
  stepper.runSpeed();
}

/*
// On vérifie si l'intervalle de temps défini s'est écoulé en comparant le temps actuel (en millisecondes) avec lastChangeTime
if (millis() - lastChangeTime >= interval)
{
  // Variables statiques
  // Enregistrer le dernier moment où l'état du moteur a changé
  // Utilisation de millis() = mesurer le temps écoulé et alterner entre démarrage et arrêt du moteur

  // On met à jour lastChangeTime avec le temps actuel
  lastChangeTime = millis();

  // Indiquer si le moteur en marche
  // Si OUI
  if (motorRunning)
  {
    // Arrêter le moteur avec la vitesse définie à 0 avec setSpeed();
    stepper.setSpeed(0);
  }
}
else
{
  // Redémarrer le moteur dans le même sens avec la vitesse définie avec setSpeed();
  stepper.setSpeed(-200);
}
// On inverse l'état de motorRunning (marche <-> arrêt)
motorRunning = !motorRunning;
}*/

/*
stepper.runSpeed(); // Faire tourner le moteur
Serial.println("MOTOR RUN");
stop();
Serial.println("STOP");
restart();
Serial.println("RESTART");
// Serial.print("RUN");
// delay(5000);
// stop();
// Serial.print("STOP");
// delay(5000);*/

/*
// Lire l'état du sensor IR
int irState = digitalRead(IR_SENSOR_PIN);
Serial.println(irState);
// Si capteur détecte quelque chose alors on arrête le moteur
if (irState == HIGH)
{
  stepper.stop();
}
else
// Sinon on continue à faire tourner le moteur dans un sens donné
{
  stepper.setSpeed(200); // Vitesse sens horaire (positive)
  stepper.runSpeed();    // Faire tourner le moteur
}

// Attendre un certain temps avant la relecture du capteur IR
delay(1000);
}*/