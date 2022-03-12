int ledPin = LED_BUILTIN;                // the pin that the LED is atteched to
int inputPin = D1;                   // the pin that the PIR sensor is atteched to
int pirState = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as an output
  pinMode(inputPin, INPUT);    // declare the  sensor as an input
  Serial.begin(9600);           // initialize serial
}

void loop(){
  val = digitalRead(inputPin);   // read sensor input value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(ledPin, HIGH);   // turn LED ON
    delay(500);                // delay 100 milliseconds 
    
    if (pirState == LOW) {
      Serial.println("Motion detected!"); 
      pirState = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(ledPin, LOW); // turn LED OFF
     
      
      if (pirState == HIGH){
        Serial.println("Motion stopped!");
        pirState = LOW;       // update variable state to LOW
    }
  }
}
