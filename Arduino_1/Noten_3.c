#include "goofy.h"  // Header File umbenannt zu goofy, eigentlich "pitches"

int pin = 10; //Pin des Lautsprechers

void setup() {
  pinMode(pin, OUTPUT); //Pin setzen
  Serial.begin(9600); 

  while (!Serial) { //unnötig
    ;               //unnötig
  }                 //unnötig
}



int i = 0; // Array index

int length = 600; // Länge einer ganzen Note in millisekunden, Je höher desto länger. 
int d = 12; // Normaler Notenabstand wenn kein Pause vorkommt

// Werte des Liedes, von Links nach Rechts:
int noten[] = {NOTE_A4,NOTE_A5,NOTE_A6};          // List aller Noten.
int duration[] = {1,1,1}; // Liste der Notenlängen.
int pause[] = {d,d,d};   // Liste der Pausen zwischen der Noten, d = normaler Notenabstand.

void loop() {
  tone(pin, noten[i]);        // Ton an
  delay(length/duration[i]);  // Tonlänge abwarten
  noTone(pin);                // Ton aus
  delay(length/pause[i]);     // Pausenlänge abwarten
  i++;                        // Index Update
}
