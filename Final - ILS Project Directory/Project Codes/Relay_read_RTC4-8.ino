#include "dweetESP8266.h"

#define THIG_NAME "i4et-ilsp"       //put here thing name here

const char* ssid = "Cupletco";
const char* password = "111111111";

dweet DweetClient;
int ledPin = LED_BUILTIN;           //Pin for the LED
int i = 0 ;                           //a random initial value
int relayPin = D1;                   //data pin for Relay sensor

char *key2 = "Time";                 //Shofly Dweet.io
char *key8 = "Relay4";               //Bisade Dweet.io

void setup() {
  Serial.begin(115200);
  pinMode (D4, OUTPUT);
  pinMode (relayPin, OUTPUT);

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
char val[16];    //it stores a number composed by up to 16 characters

void loop() {
  //codes should read dweet output here
  String value2 = DweetClient.getDweet(THIG_NAME, key2);
  int intvalue2 = value2.toInt();
  Serial.println("RTC time between 4:00am and 8:00am");

  itoa(i, val, 10);
  Serial.println(value2);

  if (intvalue2 >=4 && intvalue2 <= 8) {
 
    digitalWrite(relayPin, HIGH);       //turn the relay on
    digitalWrite(D4, LOW);              //turn the ESP LED on

    i = 0;
    Serial.println(i);
    //Serial.println(intvalue2);

    DweetClient.add(key8, val);
    DweetClient.sendAll(THIG_NAME);
    delay(1000);

  }
  else {                             //False Statement. Switch off LED
    digitalWrite(relayPin, LOW);     //turn the relay off
    digitalWrite(D4, HIGH);          //turn the ESP LED OFF

    i = 1;
    Serial.println(i);

    DweetClient.add(key8, val);
    DweetClient.sendAll(THIG_NAME);
    //delay(1000);
  }
}
