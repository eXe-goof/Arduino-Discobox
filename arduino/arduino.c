#include "goofy.h"

int pin = 2;

void setup() {
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
  while(!Serial) {
    ;
  }
}

int length = 250;


int notes[] = {NOTE_A4,NOTE_A3,NOTE_A5};
int toneLength[] = {1,2,1};
int breakLength[] = {1,1,1};

int i = 0;

void loop() {
  tone(pin, notes[i]);
  delay(length*toneLength[i]);
  noTone(pin);
  delay(length*breakLength[i]);
  i++;
}
