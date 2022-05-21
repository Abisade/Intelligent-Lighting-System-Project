#include "dweetESP8266.h"

#define THIG_NAME  "i4et-ilsp"     // For further clarification, 'i4et' and "ilsp" stand for 'Industry 4.0 Enabling Technologies' and "Intelligent Lighting System Project", respectively.

const char* ssid = "MOVISTAR_CD5C";
const char* password = "32YFPDGmiwv4pi27m5gu";

dweet DweetClient;
int i = 0; // a random initial value
int Button = D1; // define push button pin
int value; // define digital variable

char *key1 = "LightInstentisy";   
char *key2 = "Motion";   
char *key3 = "RGBLEDStatus";   
char *key4 = "RedLEDStatus";   
char *key5 = "GreenLEDStatus";   
char *key6 = "BlueLEDStatus";   
char *key7 = "PushButton";   

void setup() {

  pinMode(Button, INPUT); // set the button pin as an input pin  

  // Start serial
  Serial.begin(115200);
  // a small delay is added to initialize the serial port
  delay(10);

  // Connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to");
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

char val[16]; // it stores a number composed by up to 16 characters

void loop() {

  value = digitalRead(Button); // we read the state of the button

  itoa(i, val, 10); // to convert an integer value into a char array
  
  if (value == LOW)           // if the button is pressed, we turn on the LED
  {
    i=1;
    // Serial.println(i);
    DweetClient.add(key7, val);    
    DweetClient.sendAll(THIG_NAME);
  }
  else
  {
    i=0;
    DweetClient.add(key7, val);       
    DweetClient.sendAll(THIG_NAME);
  } 

 // Every 5 seconds a new value is uploaded
 // delay(1000);

}
