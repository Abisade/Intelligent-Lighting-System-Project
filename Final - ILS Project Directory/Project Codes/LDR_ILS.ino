// This is the code for LDR sensor of Intelligent lighting system. This code will receive data of RTC from cloud and send LDR data agian to cloud. 

//Calling the dweet library 
#include "dweetESP8266.h"
#define THIG_NAME "i4et-ilsp"  //Dweet name
const char* ssid="Cupletco";
const char* password="111111111";
dweet DweetClient; 
char *key1= "LightIntensity";          // Key to send data
char *key2="Time";                     // Key to receive data
int i=0;

int sensorpin=A0;
int sensorvalue=0;





void setup() {
  // Code for wifi connection
  Serial.begin(115000);       
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Conneting to");
  Serial.println(ssid);
  WiFi.begin(ssid, password); 
  while (WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print("."); 
  }
  Serial.println("");
  Serial.println("Wifi connected");
  Serial.println("IP address: "); 
  Serial.println(WiFi.localIP()); 
}

char val[16];
void loop() {
  sensorvalue=analogRead  (sensorpin);
  i=sensorvalue;
  String value=DweetClient.getDweet(THIG_NAME, key2);  // To receive information from RTC
  int intvalue=value.toInt();
  if (intvalue>=8 && intvalue<=20){   //The LDR sensor will send value, if the time is between 0008 to 2000. 
  itoa(i, val, 10);               //For sending the data to cloud. 
  DweetClient.add(key1, val);
  DweetClient.sendAll(THIG_NAME);
  
 
  delay(1000);
  
}
else {
  i=0;                            //The LDR sensor will send value 0, if the time is between 2000 to 0008
  itoa(i, val, 10);               //For sending the data to cloud. 
  DweetClient.add(key1, val);
  DweetClient.sendAll(THIG_NAME);
  delay(1000);
}
delay(3000);
}
