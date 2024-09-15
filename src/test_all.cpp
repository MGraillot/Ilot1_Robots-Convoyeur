#include <Arduino.h>
#include <ESP32Servo.h>
#include <AccelStepper.h>

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

// Prehenseur ROBOT 1
const int pinPHASE = 14;
const int pinENABLE = 12;
const int pinTransistor = 25;

// Définition des broches pour le pilote du moteur pas à pas
#define DIR_PIN 2   // 12
#define STEP_PIN 15 // 14

// Définition des broches pour le capteur infrarouge
#define IR_SENSOR_PIN 13 // 35

// Création d'une instance de AccelStepper pour contrôler le moteur pas à pas
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

int irState;                   // Etat du capteur infrarouge
bool objectDetected = false;   // Flag pour indiquer si un objet a été détecté
bool conveyorRunning = false;  // Flag pour indiquer si le convoyeur tourne
bool robot1Sequence = false;   // Flag pour indiquer si la séquence du Robot 1 est en cours
bool robot2Sequence = false;   // Flag pour indiquer si la séquence du Robot 2 est en cours
bool waitingForRobot2 = false; // Flag pour indiquer qu'on attend la détection d'une pièce pour Robot 2

void setup()
{
    Serial.begin(115200);

    // ROBOT 1
    FT6335Servo1.attach(servo1Pin);
    DM996Servo1.attach(servo2Pin);
    DM996Servo2.attach(servo3Pin);
    DM996Servo3.attach(servo4Pin);
    // ROBOT 2
    FT6335Servo2.attach(servo5Pin);
    DM996Servo4.attach(servo6Pin);
    DM996Servo5.attach(servo7Pin);
    DM996Servo6.attach(servo8Pin);

    // Pose init robots
    FT6335Servo1.write(0);
    DM996Servo1.write(50);
    DM996Servo2.write(40);
    DM996Servo3.write(140);

    FT6335Servo2.write(0);
    DM996Servo4.write(50);
    DM996Servo5.write(50);
    DM996Servo6.write(140);

    // Configuration du capteur infrarouge et du moteur pas à pas
    pinMode(IR_SENSOR_PIN, INPUT);
    pinMode(DIR_PIN, OUTPUT);
    pinMode(STEP_PIN, OUTPUT);

    // Prehenseur robot 1
    pinMode(pinPHASE, OUTPUT);
    pinMode(pinENABLE, OUTPUT);
    pinMode(pinTransistor, OUTPUT);
    digitalWrite(pinPHASE, LOW); // Assurer que la pompe est désactivée au début
    digitalWrite(pinENABLE, LOW);
    // delay(1000);

    stepper.setMaxSpeed(1000);
    stepper.setSpeed(-200); // Définir la vitesse du convoyeur (sens antihoraire)

    while (!Serial)
    {
        ; // Attente de connexion série
    }

    Serial.println("Système initialisé. Entrez une lettre ou un chiffre pour lancer la séquence du Robot 1.");
}

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

// Fonction pour le mouvement du Robot 1
void moveRobotConv()
{
    // Activer la pompe
    digitalWrite(pinTransistor, LOW);
    digitalWrite(pinENABLE, HIGH);
    digitalWrite(pinPHASE, HIGH);

    Serial.println("Démarrage de la séquence du Robot 1");
    // MBASE
    moveSlowly(FT6335Servo1, 0, 1, 50);
    Serial.println("MBASE a 1 deg");
    // M3
    moveSlowly(DM996Servo3, 140, 115, 50);
    Serial.println("M3 a 87 deg");
    // M2
    moveSlowly(DM996Servo2, 40, 70, 50);
    Serial.println("M2 a 50 deg");
    // M1
    moveSlowly(DM996Servo1, 50, 105, 50);
    Serial.println("M1 a 100 deg");

    // Aller vers le convoyeur
    moveSlowly(DM996Servo1, 105, 50, 50);
    moveSlowly(FT6335Servo1, 1, 49, 50);
    moveSlowly(DM996Servo3, 115, 140, 50);
    moveSlowly(DM996Servo1, 50, 80, 50);
    delay(500);

    Serial.println("Fin de la séquence du Robot 1");
    robot1Sequence = false;
    waitingForRobot2 = true;
    Serial.println("En attente de détection de pièce pour Robot 2");

    // Désactiver la pompe
    digitalWrite(pinPHASE, LOW);
    digitalWrite(pinENABLE, LOW);

    // Activer le transistor
    digitalWrite(pinTransistor, HIGH);
    // delay(1000);
    conveyorRunning = true;
}

void moveRobotInit()
{
    // Aller vers nouvelle pièce
    moveSlowly(DM996Servo1, 80, 50, 50);
    moveSlowly(FT6335Servo1, 49, 1, 50);
    moveSlowly(DM996Servo2, 50, 40, 50);
}

// Fonction pour le mouvement du Robot 2
void moveRobot2()
{
    Serial.println("Démarrage de la séquence du Robot 2");
    // MBASE
    moveSlowly(FT6335Servo2, 0, -1, 50);
    Serial.println("MBASE a 1 deg");
    // M3
    moveSlowly(DM996Servo6, 140, 120, 50);
    Serial.println("M3 a 87 deg");
    // M2
    moveSlowly(DM996Servo5, 50, 60, 50);
    Serial.println("M2 a 50 deg");
    // M1
    moveSlowly(DM996Servo4, 50, 90, 50);
    Serial.println("M1 a 100 deg");

    // Retour à la position initiale
    moveSlowly(DM996Servo4, 90, 50, 50);
    moveSlowly(FT6335Servo2, -1, 0, 50);
    moveSlowly(DM996Servo6, 120, 140, 50);
    moveSlowly(DM996Servo5, 60, 50, 50);

    Serial.println("Fin de la séquence du Robot 2");
    robot2Sequence = false;
    conveyorRunning = true; // Redémarrer le convoyeur après la séquence du Robot 2
    stepper.setSpeed(-200); // Remettre la vitesse du convoyeur
    Serial.println("Convoyeur redémarré");
    Serial.println("Entrez une lettre ou un chiffre pour lancer la séquence du Robot 1.");
}

void loop()
{
    // Le convoyeur tourne en continu sauf si arrêté
    if (conveyorRunning)
    {
        stepper.runSpeed();
    }

    // Vérifier les commandes série pour lancer la séquence du Robot 1
    if (Serial.available() > 0 && !robot1Sequence && !robot2Sequence && !waitingForRobot2)
    {
        char input = Serial.read();
        if (isAlphaNumeric(input))
        {
            robot1Sequence = true;
            moveRobotConv();
            moveRobotInit();
        }
    }

    // Vérifier en continu si un objet est détecté
    irState = digitalRead(IR_SENSOR_PIN);
    if (irState == LOW && !objectDetected && waitingForRobot2)
    {
        Serial.println("Objet détecté, arrêt du convoyeur !");
        objectDetected = true;
        conveyorRunning = false;
        stepper.setSpeed(0); // Arrêter le convoyeur
        robot2Sequence = true;
        waitingForRobot2 = false;
        moveRobot2();
        objectDetected = false; // Réinitialiser le flag pour le prochain objet
    }
}