//B and E Letters activate the LED code

byte recievedByte = 0;

void setup() {
Serial.begin(230400);
//pinMode(D4, OUTPUT);          //declare D4 as output
pinMode(D2, OUTPUT);            //declare D2 as output
}

// Loop function to run repeatedly:
void loop() {
  if(Serial.available()> 0)            // Is there any character coming through the serial port?
  { 
    recievedByte = Serial.read();      // If there is a character, read it.
    
    if(recievedByte=='E'){
      //digitalWrite(D4, HIGH);         // turn OFF ESP8266 LED
      digitalWrite(D2, LOW);           //turn OFF main LED
      Serial.println("LED is switched OFF");
    }    
    else if(recievedByte=='B'){
      //digitalWrite(D4, LOW);          // turn ON ESP8266 LED
      digitalWrite(D2, HIGH);          //turn ON main LED
      Serial.println("LED is switched ON");
      
    }
  }
}
