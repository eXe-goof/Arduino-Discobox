#include "goofy.h"  // Header File umbenannt zu goofy, eigentlich "pitches"

int pin = 10; //Pin des Lautsprechers

void setup() {
  pinMode(pin, OUTPUT); //Pin setzen
  Serial.begin(9600); 

  while (!Serial) { //unnötig
    ;               //unnötig
  }                 //unnötig
}

int length = 600; // Länge einer ganzen Note in millisekunden, Je höher desto länger. 
int d = 12; // Normaler Notenabstand wenn kein Pause vorkommt


int noten[] = {NOTE_A3,NOTE_A4,NOTE_A5};          
int duration[] = {1,1,1}; 
int pause[] = {d,d,d};  

void loop() {
  for (int i = 0; i < (sizeof(noten)/sizeof(int)); i++) { // For Loop, der das ganze Lied spielt
    tone(pin, noten[i]);
    delay(length/duration[i]);
    noTone(pin);
    delay(length/pause[i]);
  }
  // Das Lied läuft mit diesem Programm in Dauerschleife
  delay(2000); // Da sich loop immer wiederholt, kurzes Delay damit das Lied nicht direkt wieder von vorne beginnt
}
