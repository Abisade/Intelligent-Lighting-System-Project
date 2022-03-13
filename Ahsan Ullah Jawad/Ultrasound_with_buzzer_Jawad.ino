//This code use the Ultrasound and buzzer to work together. Depending on the distance of object from senser buzzer will play 
//different alarm. At this moment program can detect three stage of distances. This program also displays the distance on serial monitor.  

#include <NewPingESP8266.h>
#include "pitches.h"
#define Triggerpin D1
#define Echopin D2
#define Maxdistance 200                   //Max distance we want to ping for in cm 
int melody[]={ NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C5};
int duration=500;

NewPingESP8266 sonar(Triggerpin, Echopin, Maxdistance);   //Initialization of sonar 
void setup() {
  pinMode(D3,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  delay(500);    //Wait 500 ms between pings
  unsigned int us= sonar.ping();
  if (us/US_ROUNDTRIP_CM<50){                           //First Check 
    Serial.println("Object is closer than 50 cm");   
    tone (D3, NOTE_C5, duration);        //Play sound
    delay(500);
  }
  else if (us/US_ROUNDTRIP_CM>50 && us/US_ROUNDTRIP_CM <150){   //Second Check
    Serial.println("Object is in between 50 cm and 150 cm");
    tone (D3, NOTE_D5, duration);        //Play sound
    delay(500);  
    
  }
  else {
    Serial.println("Object is far way");
    tone (D3, NOTE_E5, duration);
    delay(500);
  }

}
