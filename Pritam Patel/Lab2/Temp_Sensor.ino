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
  delay(3000);
  Serial.print("Requesting Temperature.....");
  sensors.requestTemperatures();    //send the command to get the temperature
  Serial.println("DONE");
  Serial.print("Temperature is: ");

  // Print the temperature in Celsius in the Serial Monitor:
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print(" \xC2\xB0"); // shows degree symbol
  Serial.print("C  |  ");


  //print the temperature in Fahrenheit
  Serial.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
  Serial.print(" \xC2\xB0"); // shows degree symbol
  Serial.print("F ");

  if(sensors.getTempCByIndex(0)<10){
    Serial.println(" :The Temperature is Low");
  }
  else if(sensors.getTempCByIndex(0)<20){
    Serial.println(" :The Temperature is Medium");
  }
  else if(sensors.getTempCByIndex(0)<30){
    Serial.println(" :The Temperature is High");
  }
  else{
    Serial.println(" :The Temperature is Too High");
  }
}
