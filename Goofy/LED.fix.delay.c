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

int pin = 10;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pin, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  Serial.begin(9600);
  
  while (!Serial) {
    ;
  }
}

/*Altes Programm: */
void a() {
 for (size_t i = 0; i < (sizeof(noten) / sizeof(int)); i++) {
    int d = speed / dauer[i];
    tone(pin, noten[i], d);
    int pause = d * defaultBreakTime;
    for (int j = 0; j < pause; j++) {
      delay(1);
    }
    noTone(pin);
  }
}

/*neues Programm: */
void b() {
  for (size_t j = 0; j < (sizeof(noten) / sizeof(int)); j++) {
    /*Noten spielen + LED*/
    int d = speed / dauer[j];
    tone(pin, noten[j]);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(d);
    int pause = d * defaultBreakTime;
    noTone(pin);
    digitalWrite(LED_BUILTIN, LOW);
    delay(pause-d);
  }
}

void loop() {
  b();
  delay(2000);
}
