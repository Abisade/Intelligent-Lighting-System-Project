//Blink code by Bisade

byte recievedByte = 0;
void setup() {

// initialize digital pin D4 as an output
Serial.begin(230400);
pinMode(D4, OUTPUT);
}

// Loop finction to run repeatedly:
void loop() {
  
  if(Serial.available()> 0)            // Is there any character coming through the serial port?
  { 
    recievedByte = Serial.read();      // If there is a character, read it.
    
    if(recievedByte=='E'){
      digitalWrite(D4, HIGH);         // turn off LED
      Serial.println("LED is switched OFF");
    }    
    else if(recievedByte=='B'){
      digitalWrite(D4, LOW);          // turn on LED
      Serial.println("LED is switched ON");
      
    }
  }
}
