//Program allows for controlling the Relay and embedded LED through the Serial Monitor. 
//Thus, when the ESP8266 receives my “ON character - B” the embedded LED and Relay will be switched on, and, 
//when sending my “OFF character - E”, the embedded LED and Relay will be switched off.

int relayPin = D1;
byte recievedByte = 0;

void setup() {
// initialize digital pin D4 and D1 as an output
Serial.begin(230400);
pinMode(D4, OUTPUT);             //Declares D4 as output
pinMode (relayPin, OUTPUT);      //Declares D1 as output
}

// Loop function to run repeatedly:
void loop() {
  
  if(Serial.available()> 0)            // Is there any character coming through the serial port?
  { 
    recievedByte = Serial.read();      // If there is a character, read it.
    
    if(recievedByte=='E'){
      digitalWrite(D4, HIGH);           // turn OFF embedded LED
      digitalWrite(relayPin, LOW);      //turn OFF relay LED
      Serial.println("LED is switched OFF");
      //delay(3000);                    //if activated, will delay for 3 secs
    }    
    else if(recievedByte=='B'){
      digitalWrite(D4, LOW);            // turn ON embedded LED
      digitalWrite(relayPin, HIGH);     //turn ON relay LED
      Serial.println("LED is switched ON");
      //delay(2000);                    //if activated, will delay for another 2 secs
      
    }
  }
}
