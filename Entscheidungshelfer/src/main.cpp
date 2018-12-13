#include <Arduino.h>

#define ROTER_LED_PIN 11
#define BLAUER_LED_PIN 12

#define FERTIG 1
#define UNFERTIG 0
int zustandEntscheidungshelfer=UNFERTIG;

#define MAX_BLINK_RYTHMUS 2000
#define BLINK_RHYTMUS_Schritweite 100
int BlinkRhytmus = 50;

void setup() 
{
  pinMode(ROTER_LED_PIN, OUTPUT);
  pinMode(BLAUER_LED_PIN, OUTPUT); 
}

void loop() 
{
 if (zustandEntscheidungshelfer==UNFERTIG)
 {
   while (BlinkRhytmus<MAX_BLINK_RYTHMUS)
    {
      digitalWrite(ROTER_LED_PIN, HIGH);
      delay(BlinkRhytmus);
      digitalWrite(ROTER_LED_PIN,LOW);
      digitalWrite(BLAUER_LED_PIN, HIGH);
      delay(BlinkRhytmus);
      digitalWrite(BLAUER_LED_PIN, LOW);
      BlinkRhytmus += BLINK_RHYTMUS_Schritweite;
 }
    zustandEntscheidungshelfer=FERTIG;
  }
}