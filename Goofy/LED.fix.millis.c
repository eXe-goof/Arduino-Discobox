#include "goofy.h" // pitches.h
unsigned long long int time;
float defaultBreakTime = 1.3f;
float accentBreakTime = 2.4f;
float breakTime;
int noten[] = { NOTE_A4, NOTE_D5, NOTE_A4, NOTE_D5, NOTE_A4, NOTE_D5, NOTE_A4, 0, NOTE_GS4, NOTE_A4, NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_G4, 0, NOTE_FS4, NOTE_G4,
                NOTE_F4, NOTE_D4, NOTE_A4, NOTE_D5, NOTE_A4, NOTE_D5, NOTE_A4, NOTE_D5, NOTE_A4, 0, NOTE_GS4, NOTE_A4, NOTE_G4, NOTE_G4, 0, NOTE_FS4, NOTE_G4,
                NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_D5, NOTE_A4, NOTE_D5, NOTE_A4, NOTE_D5, NOTE_A4, 0, NOTE_GS4, NOTE_A4, NOTE_C5, NOTE_C5, 0, NOTE_A4, NOTE_G4,
                NOTE_F4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_DS5, NOTE_D5, NOTE_GS4, NOTE_A4, 0, NOTE_F4,
                NOTE_A5, NOTE_F5, NOTE_A5, 0, NOTE_A5, NOTE_F5, NOTE_A5, 0, NOTE_A5, NOTE_F5, NOTE_GS5, NOTE_A5, NOTE_F5, NOTE_D5 };
int dauer[] = { 4, 4, 4, 4, 8, 4, 8, 8 /*Pause*/, 8, 4, 8, 8, 8, 8, 8 /*Pause*/, 8, 4,
                2, 2, 4, 4, 4, 4, 8, 4, 8, 8 /*Pause*/, 8, 4, 4, 4, 8 /*Pause*/, 8, 4,
                4, 4, 4, 4, 4, 4, 4, 4, 8, 4, 8, 8 /*Pause*/, 8, 4, 4, 4, 8 /*Pause*/, 8, 4,
                2, 2, 2, 2, 2, 2, 4, 4, 8, 8, 4 /*Pause*/, 1,
                8, 8, 4, 4 /*Pause*/, 8, 8, 4, 4 /*Pause*/, 8, 8, 8, 4, 2, 1.5 };
int speed = 900;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
}
int pin = 10;
int a = 0;
int b = 0;
int length = sizeof(noten) / sizeof(int);
int i = 0;
bool r = true;
void loop() {
  while (i < length) {
    int d = speed / dauer[i];
    int pause = d * defaultBreakTime;
    
    /*Program:          */
    if (millis() >= a && r) {
      noTone(pin);
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("a");
      r = false;
    }
    if (millis() >= b) {
      Serial.println("b");
      digitalWrite(LED_BUILTIN, HIGH);
      tone(pin, noten[i]);
      i++;
      r = true;
      b = millis() + pause;
      a = millis() + d;
    }
  }
  i = 0;
  noTone(pin);
  delay(2000);
}
