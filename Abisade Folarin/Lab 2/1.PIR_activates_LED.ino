//The Passive Infrared (PIR) sensor (HC SR501) detects motion and then activates the seven-colour blink LED to go either ON or OFF according to motion detected.

int ledPin = LED_BUILTIN;          //Pin for the LED
int inputPin = D1;                 //data pin for PIR sensor
int pirState = LOW;                //initially assume no moiton detected
int val = 0;                       //variable for reading pin status

void setup() {
  pinMode(ledPin, OUTPUT);        //Declare ESP8266 LED as output
  pinMode(inputPin, INPUT);       //Declare the PIR sensor data pin D1 as input
  pinMode(D2, OUTPUT);            //Declare the LED light D2 as output

  Serial.begin(9600);
}

void loop() {
  val = digitalRead(inputPin);      //read input value 
  if (val == HIGH) {                //check if the input is HIGH  
    digitalWrite(ledPin, LOW);      //turn ON embedded LED
    digitalWrite(D2, HIGH);         //turn ON LED light D2
    if (pirState == HIGH) {
      Serial.println("Motion is Detected!");
      pirState = LOW;
    }
  } else {
    digitalWrite(ledPin, HIGH);    // turn OFF embedded LED
    digitalWrite(D2, LOW);         //turn OFF LED light D2
    if (pirState == LOW) {
      Serial.println("Motion has ended!");
      pirState = HIGH;
    }
  }
} 
