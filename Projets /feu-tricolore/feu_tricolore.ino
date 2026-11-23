// Broches des feux : voie 1
int LedR = 12;
int LedO = 9;
int LedV = 4;
// Broches des feux : voie 2
int Led2B = 2;
int Led2V = 8;
int Led2R = 5;
// Durées des feux (en secondes)
int tempsVert = 6;
int tempsOrange = 3;
// Broches de l'afficheur : A, B, C, D, E, F, G
int segments[] = {10, 11, 6, 7, 3, 13, A0};
// Configuration des chiffres de 0 à 9
const byte chiffres[10][7] = {
  
   {1,1,1,1,1,1,0}, // 0
   {0,1,1,0,0,0,0}, // 1
   {1,1,0,1,1,0,1}, // 2
   {1,1,1,1,0,0,1}, // 3
   {0,1,1,0,0,1,1}, // 4
   {1,0,1,1,0,1,1}, // 5
   {1,0,1,1,1,1,1}, // 6
   {1,1,1,0,0,0,0}, // 7
   {1,1,1,1,1,1,1}, // 8
   {1,1,1,1,0,1,1}  // 9
};
// Initialisation
void setup() {

  pinMode(LedR, OUTPUT);
  pinMode(LedO, OUTPUT);
  pinMode(LedV, OUTPUT);

  pinMode(Led2B, OUTPUT);
  pinMode(Led2V, OUTPUT);
  pinMode(Led2R, OUTPUT);

  for (int i = 0; i < 7; i++) {
    pinMode(segments[i], OUTPUT);
  }
// Au démarrage, les deux voies sont rouges
  digitalWrite(LedR, HIGH);
  digitalWrite(Led2R, HIGH);
}
// Fonction d'affichage
void afficherNombre(int nombre) {

  for (int i = 0; i < 7; i++) {
    digitalWrite(segments[i], chiffres[nombre][i]);
  }

}
// Fonction compte à rebours
void compteARebours(int temps) {

  for (int i = temps; i > 0; i--) {

    afficherNombre(i);

    delay(1000);
  }

}
// Programme principal
void loop() {

  // ===== VOIE 1 : FEU VERT =====

  digitalWrite(LedR, LOW);
  digitalWrite(LedV, HIGH);
  delay(1000);
  digitalWrite(Led2R, HIGH);
  digitalWrite(Led2V, LOW);

  compteARebours(tempsVert);
// ===== VOIE 1 : FEU ORANGE =====

  digitalWrite(LedV, LOW);
  digitalWrite(LedO, HIGH);

  compteARebours(tempsOrange);
// ===== VOIE 2 : FEU VERT =====

  digitalWrite(LedO, LOW);
  digitalWrite(LedR, HIGH);
  delay(1000);
  digitalWrite(Led2R, LOW);
  digitalWrite(Led2V, HIGH);

  compteARebours(tempsVert);
 // ===== VOIE 2 : FEU ORANGE =====

  digitalWrite(Led2V, LOW);
  digitalWrite(Led2B, HIGH);

  compteARebours(tempsOrange);
// Retour à la situation initiale
  digitalWrite(Led2B, LOW);
  digitalWrite(Led2R, HIGH);
  delay(1000);
  digitalWrite(LedR, LOW);
  digitalWrite(LedV, HIGH);

}
