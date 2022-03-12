#include <DS3231.h>

int relayPin = D1;

DS3231 RTCclock;
RTCDateTime dt;

const int OnHour = 22;
const int OnMin = 28;
const int OnSecond = 0;
const int OffHour =22;
const int OffMin = 28;
const int OffSecond = 30;

void setup() {
  Serial.begin(230400);
   RTCclock.begin();
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);
}

void loop()
{
  dt = RTCclock.getDateTime();

  Serial.print("Raw data: ");
  Serial.print(dt.year);    Serial.print("-");
  Serial.print(dt.month);   Serial.print("-");
  Serial.print(dt.day);     Serial.print(" ");
  Serial.print(dt.hour);    Serial.print(":");
  Serial.print(dt.minute);  Serial.print(":");
  Serial.print(dt.second);  Serial.println("");

  delay(1000);

  if(dt.hour == OnHour && dt.minute == OnMin && dt.second == OnSecond){
    digitalWrite(relayPin,HIGH);
    Serial.println("LIGHT ON");
    }
    
  else if(dt.hour == OffHour && dt.minute == OffMin && dt.second == OffSecond){
    digitalWrite(relayPin,LOW);
    Serial.println("LIGHT OFF");  
    }
}
