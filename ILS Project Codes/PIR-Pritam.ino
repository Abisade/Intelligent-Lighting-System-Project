#include "dweetESP8266.h"

#define THIG_NAME "i4et-ilsp" //put here thing name here

const char* ssid = "OnePlus Nord2 5G";
const char* password = "pritam.11";

dweet DweetClient;
int ledPin = LED_BUILTIN;                   //Pin for the LED
int inputPin = D1;                 //data pin for PIR sensor
int pirState = LOW;               //initially assume no moiton detected
int kk = 0;                       //variable for reading pin status
char *key1 = "LightIntensity";             //this is the name of the parameter sent to Dweet.io
char *key2 = "Motion";         //this is the name of the parameter sent to Dweet.io
int i=0;

void setup() {
  pinMode(ledPin, OUTPUT);        //Declare LED as output
  pinMode(inputPin, INPUT);       //Declare the sensor data pin as input

  Serial.begin(115200);
  delay(10);

  //Connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
char val[16];                  //it stores a number composed by up to 16 characters

void loop() {

  String value = DweetClient.getDweet(THIG_NAME, key1);
  int intvalue=value.toInt();
  Serial.println(value);

  if (intvalue<500){
    
  
  itoa(i,val,10);
  kk = digitalRead(inputPin);      //read input value
  if (kk == HIGH) {                //check if the input is HIGH
    digitalWrite(ledPin, LOW);     //turn LED ON
    delay(5);
    
    if (pirState == HIGH) {
      Serial.println("Motion Detected!");
      i=1;
      pirState = LOW;
      DweetClient.add(key2, val);
      DweetClient.sendAll(THIG_NAME);
    }
  } 
  
  else {
    digitalWrite(ledPin, HIGH); // turn LED OFF
    if (pirState == LOW) {
      Serial.println("Motion has ended!");
      i=0;
      pirState = HIGH;
      DweetClient.add(key2, val);
      DweetClient.sendAll(THIG_NAME);
    }
  }
}
}
