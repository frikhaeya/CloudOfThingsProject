// Pont en H L298N
//Ports de commande du moteur B
int motorPin3 = 10;
int motorPin4 = 11;
int enablePin0 = 6;
//Ports de commande du moteur B
int motorPin1 = 8;
int motorPin2 = 9;
int enablePin1 = 5;
 
// Vitesse du moteur
int state = 0;
void setup() {
    // Configuration des ports en mode "sortie" du moteur A
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(enablePin0, OUTPUT);
    // Configuration des ports en mode "sortie" du moteur B
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(enablePin1, OUTPUT);
    
    // Initialisation du port série
    Serial.begin(9600);
}
 
void loop() {
    if (Serial.available() > 0)
    {
      // Lecture de l'entier passé au port série
      state = Serial.parseInt();
      //
      // Sens du mouvement
      //
      if (state > 0) // avant
      {
        digitalWrite(motorPin1, HIGH); 
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, HIGH); 
        digitalWrite(motorPin4, LOW);
        Serial.print("Avant ");
        Serial.println(state);
      }
      else if (state < 0) // arrière
      {
        digitalWrite(motorPin1, LOW); 
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin3, LOW); 
        digitalWrite(motorPin4, HIGH);
        Serial.print("Arriere ");
        Serial.println(state);
      }
      else // Stop (freinage)
      {
        digitalWrite(motorPin1, HIGH); 
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin3, HIGH); 
        digitalWrite(motorPin4, HIGH);
        Serial.println("Stop");
      }
      //
      // Vitesse du mouvement
      //
      analogWrite(enablePin0, abs(state));
      analogWrite(enablePin1, abs(state));
    }
    delay(100);
}
