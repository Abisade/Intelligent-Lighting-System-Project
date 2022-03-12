// Lab 2

int relayPin = D1;
byte recievedByte = 0;
void setup() {

// initialize digital pin  as an output
Serial.begin(230400);
pinMode(relayPin, OUTPUT);
}

// Loop finction to run repeatedly:
void loop() {
  
  if(Serial.available()> 0)            // Is there any character coming through the serial port?
  { 
    recievedByte = Serial.read();      // If there is a character, read it.
    
    if(recievedByte=='Y'){
      digitalWrite(relayPin, HIGH);         // trigger off the Relay
      Serial.println("Relay is triggered OFF");
    }    
    else if(recievedByte=='S'){
      digitalWrite(relayPin, LOW);          // trigger on Relay
      Serial.println("Relay is triggered ON");
      
    }
  }
}
