// C++ code
//
#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"

// Initialisation de l'écran via I2C. 

Adafruit_LiquidCrystal lcd(0x27);
const int pingPin = 2;

float distanceActuelle = 0;

float distancePrecedente = 100;

int compteur = 0;

float mesurerDistance() {
  // Envoyer l'impulsion ultrasonique
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // Recevoir l'écho
  pinMode(pingPin, INPUT);
  long duree = pulseIn(pingPin, HIGH, 30000);

  // Vérifier si une mesure a été reçue
  if (duree == 0) {
    return -1;
  }

  // Calculer la distance en centimètres
  return duree * 0.0343 / 2;
}

void setup() {
  // Initialise l'écran avec ses dimensions (16 colonnes, 2 lignes)
  lcd.begin(16, 2);
  
  
  lcd.setBacklight(HIGH);
}
 void loop() {
   distanceActuelle = mesurerDistance();

  // Ignorer les mesures invalides
  if (distanceActuelle > 0) {

    // Détecter l'entrée dans la zone des 10 cm
    if (distancePrecedente > 10 && distanceActuelle <= 10) {
     compteur ++;
     lcd.setCursor(0, 0);
     lcd.print("Bonne priere!!");
     
  // Placement sur la deuxième ligne (colonne 0, ligne 1)
     lcd.setCursor(0, 1);
     lcd.print(" soudjoud"  );
     lcd.print(compteur);
    }

    // Mémoriser la distance actuelle
    distancePrecedente = distanceActuelle;
  }

  delay(100);
}

