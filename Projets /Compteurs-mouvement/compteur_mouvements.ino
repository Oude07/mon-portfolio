// C++ code
//
#include "Wire.h"
#include "LiquidCrystal_I2C.h"

// Initialisation de l'écran via I2C. 
// Le "0" correspond à l'adresse par défaut (A0, A1, A2 non pontés)
LiquidCrystal_I2C lcd(0x27 , 16,2);
const int TrigPin = 9;
const int echoPin=10 ;


float distanceActuelle = 0;

float distancePrecedente = 100;

int compteur = 0;

float mesurerDistance() {
  // Envoyer l'impulsion ultrasonique
  pinMode(TrigPin, OUTPUT);
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(TrigPin, LOW);

  // Recevoir l'écho
  pinMode(echoPin, INPUT);
  long duree = pulseIn(echoPin, HIGH, 30000);

  // Vérifier si une mesure a été reçue
  if (duree == 0) {
    return -1;
  }

  // Calculer la distance en centimètres
  return duree * 0.0343 / 2;
}

void setup() {
  // Initialise l'écran avec ses dimensions (16 colonnes, 2 lignes)
  lcd.init();
  
  // Active le rétroéclairage
  lcd.backlight();
}
 void loop() {
   distanceActuelle = mesurerDistance();

  // Ignorer les mesures invalides
  if (distanceActuelle > 0) {

    // Détecter l'entrée dans la zone des 10 cm
    if (distancePrecedente > 10 && distanceActuelle <= 10) {
     compteur ++;
     lcd.setCursor(0, 0);
     lcd.print("Bonne exercice!!");
     
  // Placement sur la deuxième ligne (colonne 0, ligne 1)
     lcd.setCursor(0, 1);
     lcd.print("repetition:"  );
     lcd.print(compteur);
    }

    // Mémoriser la distance actuelle
    distancePrecedente = distanceActuelle;
  }

  delay(100);
}
