#include <Arduino.h>

#define ROTER_LED_PIN 11
#define BLAUER_LED_PIN 12

#define FERTIG 1
#define UNFERTIG 0
int zustandEntscheidungshelfer = UNFERTIG;

#define MAX_BLINK_RYTHMUS 1000
#define BLINK_RHYTMUS_Schritweite 100
#define BLINK_STARTWERT 50
#define BLINK_FUNKTION_A 10

int BlinkRhytmus = 50;

int ledPins[] = {13,12,11};
int anzahlDerEntscheidungen = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() 
{
  for (int i =0; i < anzahlDerEntscheidungen; i++){
    //int aktuellerPin = ledPins[i];
    //pinMode(aktuellerPin, OUTPUT);
    pinMode(ledPins[i], OUTPUT);
  } 
}

void loop() {
  if (zustandEntscheidungshelfer==UNFERTIG){
    for (int x = 0; BlinkRhytmus<MAX_BLINK_RYTHMUS; x++){
      BlinkRhytmus = x * x * BLINK_FUNKTION_A + BLINK_STARTWERT;
      for (int i = 0; i < anzahlDerEntscheidungen; i++){
        digitalWrite(ledPins[i], HIGH);
        delay(BlinkRhytmus);
        digitalWrite(ledPins[i], LOW);
      }

      // In Version 1.0 sah das noch so aus:
      // digitalWrite(ROTER_LED_PIN, HIGH);
      // delay(BlinkRhytmus);
      // digitalWrite(ROTER_LED_PIN,LOW);
      // digitalWrite(BLAUER_LED_PIN, HIGH);
      // delay(BlinkRhytmus);
      // digitalWrite(BLAUER_LED_PIN, LOW);
      BlinkRhytmus += BLINK_RHYTMUS_Schritweite;
    }
  
    int startWert = analogRead(1); // kann jeder nicht genutzte Pin sein.
    randomSeed(startWert);
    int ergebnis = random();
    if (ergebnis <0) {
        ergebnis *= -1;
    }

    int indexImArray = ergebnis % anzahlDerEntscheidungen;
    digitalWrite(ledPins[indexImArray], HIGH);

    // In Version 1.0 sah das noch so aus:
    // if (ergebnis %2 == 0){
    //   digitalWrite(ROTER_LED_PIN, HIGH);
    // }
    // else{
    //   digitalWrite(BLAUER_LED_PIN, HIGH);
    // }

    zustandEntscheidungshelfer=FERTIG;
  }
}