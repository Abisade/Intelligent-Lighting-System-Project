#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS D1  //Data wire is plugged into D1 on the ESP8266

OneWire oneWire(ONE_WIRE_BUS);  //A onewire instance is created to communicate with the sensor.

DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Starting the Temperature.....");
  sensors.begin();
}

void loop(void)
{
  delay(10000);
  
  sensors.requestTemperatures();    //send the command to get the temperature
  

  

  if(sensors.getTempCByIndex(0)>35){
    Serial.println("WARNING!!");
    Serial.print("The Temperature is Above 35");
    Serial.print("\xC2\xB0"); // shows degree symbol
    Serial.println("C");
  }
  
  else{
    Serial.println("The Temperature is Below Warning Limit");
    
  }
}
