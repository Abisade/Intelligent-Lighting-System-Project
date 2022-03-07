/*

LAB 1 Exercise:
By making use of the knowledge acquired by testing the examples provided in this lab, create a program that allows for controlling through the Serial Monitor when the embedded LED should be switched on and off.
Thus, when the ESP8266 receives your own “ON character” (indicated in the table below), the LED will be switched on, while, when sending the “OFF character” (in the table below), the LED will be switched off.

Student: Saeid / ON Character: S / OFF Character: D
 
*/

byte recievedByte = 0;

void setup() {
  // initialize digital pin D4 as an output
  Serial.begin(230400);
  pinMode(D4, OUTPUT);
}

// the loop function runs over and over again perpetually
void loop() {
  
  if(Serial.available()> 0)             // get the character(s) available for reading from the serial port
  { 
    recievedByte = Serial.read();       // reads incoming serial data
    
    if(recievedByte=='D'){
      digitalWrite(D4, HIGH);           // turn the LED off
      Serial.println("LED is switched OFF");
    }    
    else if(recievedByte=='S'){
      digitalWrite(D4, LOW);            // turn the LED on
      Serial.println("LED is switched ON");
      
    }
  }
}
