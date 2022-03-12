//Program allows for controlling the Buzzer through the Serial Monitor. 
//Thus, when the ESP8266 receives my “ON character - B” the Buzzer will be switched on, and, 
//when sending my “OFF character - E”, the Buzzer will be switched off.

#include "pitches.h"

byte recievedByte = 0;

//notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int duration = 100; //500 miliseconds

void setup() {
  // initialize digital pin D4 as an output
  Serial.begin(230400);
  pinMode(D4, OUTPUT);
}

// Loop function to run repeatedly:
void loop() {
  if (Serial.available() > 0)          // Is there any character coming through the serial port?
  {
    recievedByte = Serial.read();      // If there is a character, read it.

    if (recievedByte == 'E') {
      digitalWrite(D4, HIGH);         // turn OFF LED
      Serial.println("LED is switched OFF");
      for (int thisNote = 0;
           thisNote < 1; thisNote++) {
        // pin D1 controls the sound, emmiting each note every 'duration' milliseconds
        tone(D1, melody[thisNote], duration);
      }
    }
    else if (recievedByte == 'B') {
      digitalWrite(D4, LOW);          // turn ON LED
      Serial.println("LED is switched ON");
      for (int thisNote = 0;
           thisNote < 3; thisNote++) {
        // pin D1 controls teh sound, emmiting each note every 'duration' milliseconds
        tone(D1, melody[thisNote], duration);
      }
    }
  }
}
