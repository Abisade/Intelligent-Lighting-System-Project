#include "dweetESP8266.h"
#include <DS3231.h>

#define THING_NAME  "i4et-ilsp"  // Put here your thing name

const char* ssid = "MyConnect-2";
const char* password = "111111111";

DS3231 RTCclock;
RTCDateTime dt;
const int OnHour = 20;
const int OnMin = 0;
const int OnSecond = 0;
const int OffHour = 8;
const int OffMin = 0;
const int OffSecond = 0;

dweet DweetClient;
int i = 0; // a random initial value
//float f = 30.1; //another random initial value


/*int Led = LED_BUILTIN; //define LED pin*/
int LED = D4; //define push button pin
int value; //define digital variable val

char *key = "Time";

/*

char *key = "temperature"; // this is the name of the parameter sent to Dweet.io 
char *key2 = "humidity";

*/

void setup() {

  Serial.println("Initializing RTC module....");
   RTCclock.begin();
   pinMode(D4, OUTPUT);
  digitalWrite(D4, LOW);
  digitalWrite(D4, HIGH);
  RTCclock.setDateTime(__DATE__, __TIME__);
  // Start serial
  Serial.begin(9600);      
  //a smalldelay is added to initialize the serial port
  //delay(1);

  // Connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    //delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

char val[24]; // it stores a number composed by up to 16 characters

void loop() {

  dt = RTCclock.getDateTime();

  Serial.print("Raw data: ");
  Serial.print(dt.year);    Serial.print("-");
  Serial.print(dt.month);   Serial.print("-");
  Serial.print(dt.day);     Serial.print(" ");
  Serial.print(dt.hour);    Serial.print(":");
  Serial.print(dt.minute);  Serial.print(":");
  Serial.print(dt.second);  Serial.println("");

  delay(1000);
  
   //String value=DweetClient.getDweet(THING_NAME, key);  //For receiving data 
  //Serial.println(value);
  
  // EXAMPLE 1: Sending an integer to Dweet.io
  itoa(i, val, 10); // to convert an integer value into a char array
   if(dt.hour == 0){
   digitalWrite(D4,LOW);
      i=0;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }

  if(dt.hour == 1){
   digitalWrite(D4,LOW);
      i=1;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }

     if(dt.hour == 2){
   digitalWrite(D4,LOW);
      i=2;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }

   if(dt.hour == 3){
   digitalWrite(D4,LOW);
      i=3;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }

  if(dt.hour == 4){
   digitalWrite(D4,LOW);
      i=4;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }

  if(dt.hour == 5){
   digitalWrite(D4,LOW);
      i=5;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }

   if(dt.hour == 6){
   digitalWrite(D4,LOW);
      i=6;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }

   if(dt.hour == 7){
   digitalWrite(D4,LOW);
      i=7;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }

   if(dt.hour == 8){
   digitalWrite(D4,HIGH);
      i=8;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }

   if(dt.hour == 9){
   digitalWrite(D4,HIGH);
      i=9;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }

   if(dt.hour == 10){
   digitalWrite(D4,HIGH);
      i=10;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }

   if(dt.hour == 11){
   digitalWrite(D4,HIGH);
      i=11;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }

   if(dt.hour == 12){
   digitalWrite(D4,HIGH);
      i=12;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }

   if(dt.hour == 13){
   digitalWrite(D4,HIGH);
      i=13;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }
  
   if(dt.hour == 14){
   digitalWrite(D4,HIGH);
      i=14;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }
   
   if(dt.hour == 15){
   digitalWrite(D4,HIGH);
      i=15;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }
  
   if(dt.hour == 16){
   digitalWrite(D4,HIGH);
      i=16;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    } 
    
   if(dt.hour == 17){
   digitalWrite(D4,HIGH);
      i=17;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }

   if(dt.hour == 18){
   digitalWrite(D4,HIGH);
      i=18;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }

   if(dt.hour == 19){
   digitalWrite(D4,HIGH);
      i=19;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }

   if(dt.hour == 20){
   digitalWrite(D4,LOW);
      i=20;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    } 
    
   if(dt.hour == 21){
   digitalWrite(D4,LOW);
      i=21;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }
    
   if(dt.hour == 22){
   digitalWrite(D4,LOW);
      i=22;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }
    
   if(dt.hour == 23){
   digitalWrite(D4,LOW);
      i=23;
    
   //Serial.println(i]);
   DweetClient.add(key, val);
   DweetClient.sendAll(THING_NAME);
    }
  
  /*

  // EXAMPLE 2: Sending a float to Dweet.io
   
  String temp = String(f,2); // 'f' is converted to String with 2 decimals
  temp.toCharArray(val, 16); // temp is converted to a char array
  Serial.println(val);
  DweetClient.add(key2,val);
  DweetClient.sendAll(THIG_NAME);
  f = f + 0.1;

  */

  // Every 5 seconds a new value is uploaded
  //delay(1000);

}
