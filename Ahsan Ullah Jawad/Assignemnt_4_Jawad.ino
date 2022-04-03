//Code for lab 4. This code will receive data of RTC from cloud and send LDR data agian to cloud. 

//Calling the dweet library 
#include "dweetESP8266.h"
#define THIG_NAME "i4et-ilsp"  //Dweet name. Change as yours
const char* ssid="V2027";
const char* password="12345432JJJ";
dweet DweetClient; 
char *key1= "LightIntensity";          // you know key. If required change. does not matter. 
char *key2="Time";
int i=0;

int sensorpin=A0;
int sensorvalue=0;





void setup() {
  //pinMode(D4, OUTPUT);      //From LED blink code. Change as yours 
  // put your setup code here, to run once:
  Serial.begin(115000);       //Once I kept it 115000 it did not work. so it might also cause issue. 
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
  String value=DweetClient.getDweet(THIG_NAME, key2); 
  int intvalue=value.toInt();
  if (intvalue>=8 && intvalue<=20){
  itoa(i, val, 10);               //For sending the data to cloud. 
  DweetClient.add(key1, val);
  DweetClient.sendAll(THIG_NAME);
  
 
  delay(1000);
  
}
else {
  i=0;
  itoa(i, val, 10);               //For sending the data to cloud. 
  DweetClient.add(key1, val);
  DweetClient.sendAll(THIG_NAME);
  delay(1000);
}
delay(4000);
}

  /*
  String distance=String(g,2);
  distance.toCharArray(val, 16);
  DweetClient.add(key, val);
  DweetClient.sendAll(THIG_NAME);
  //f=f+0.1;
  delay(5000);
}
*/
