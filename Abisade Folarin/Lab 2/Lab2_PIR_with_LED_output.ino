//The PIR reads motion and then activates the LED to go ON or OFF accordingly

int ledPin = LED_BUILTIN;          //Pin for the LED
int inputPin = D1;                 //data pin for PIR sensor
int pirState = LOW;                //initially assume no moiton detected
int val = 0;                       //variable for reading pin status

void setup() {
  pinMode(ledPin, OUTPUT);        //Declare LED as output
  pinMode(inputPin, INPUT);       //Declare the sensor data pin as input
  pinMode(D2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  val = digitalRead(inputPin);      //read input value 
  if (val == HIGH) {                //check if the input is HIGH  
    digitalWrite(ledPin, LOW);      //turn board LED ON
    digitalWrite(D2, HIGH);         //turn main LED ON
    if (pirState == HIGH) {
      Serial.println("Motion is Detected!");
      pirState = LOW;
    }
  } else {
    digitalWrite(ledPin, HIGH);    // turn board LED OFF
    digitalWrite(D2, LOW);         //turn main LED OFF
    if (pirState == LOW) {
      Serial.println("Motion has ended!");
      pirState = HIGH;
    }
  }
} 
