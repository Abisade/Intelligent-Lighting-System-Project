//Blink code by Bisade

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
      digitalWrite(D4, HIGH);           // turn OFF ESP8266 LED
      digitalWrite(relayPin, LOW);      //turn OFF relay LED
      Serial.println("LED is switched OFF");
      //delay(3000);                    //if activated, will delay for 3 secs
    }    
    else if(recievedByte=='B'){
      digitalWrite(D4, LOW);            // turn ON ESP8266 LED
      digitalWrite(relayPin, HIGH);     //turn ON relay LED
      Serial.println("LED is switched ON");
      //delay(2000);                    //if activated, will delay for another 2 secs
      
    }
  }
}
