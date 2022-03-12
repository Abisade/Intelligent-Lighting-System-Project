//Program allows for controlling the LED through the Serial Monitor. 
//Thus, when the ESP8266 receives my “ON character - B” the LED will be switched on, and, 
//when sending my “OFF character - E”, the LED will be switched off

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
      //digitalWrite(D4, HIGH);         // turn OFF embedded LED
      digitalWrite(D2, LOW);           //turn OFF main LED
      Serial.println("LED is switched OFF");
    }    
    else if(recievedByte=='B'){
      //digitalWrite(D4, LOW);          // turn ON embedded LED
      digitalWrite(D2, HIGH);          //turn ON main LED
      Serial.println("LED is switched ON");
      
    }
  }
}
