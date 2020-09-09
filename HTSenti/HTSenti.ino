
/*************************************************************************
 *  HTSenti
 *  Tristan Cool, Mark Cool
 *  2020
 ************************************************************************/

/*################## LIBRARIES #########################################*/
#include "defs.h"
#include <DHT.h>
#include <DHT_U.h>

/*################## VARIABLES #########################################*/

//~~~~~~ DHT22 ~~~~~~~~~~~
DHT dht(pinDHT, DHTTYPE);
float temperature;
float prev_temperature;
float diff_temperature = 0.5; 
float humidity;
float prev_humidity;
float diff_humidity = 0.75;
bool DHTfail = false;
bool DHTupdate = true;

/*################## SETUP #############################################*/

void setup() 
{
  // initialize the serial communication:
  // Open terminal console: Ctrl + Shift + m
  Serial.begin(9600);
  Serial.println(F("~~~~~~~~~ HTSenti ~~~~~~~~~~~~"));

  //initialize DHT22
  dht.begin();
  
}//END: setup

/*################## LOOP #############################################*/

void loop() 
{
  delay(2000);
  readDHT();    // read DHT22
  printDHT();   // print DHT22

}//END: loop

/*################## FUNCTIONS ########################################*/

void readDHT()
{
  prev_humidity = humidity;            //store last humidity reading
  humidity = dht.readHumidity();       //record new humidity value
  prev_temperature = temperature;      //store last temperatue reading
  temperature = dht.readTemperature(); //record new temperature value

  //check for significant change in temperature or humidity
  if((abs(prev_humidity - humidity) > diff_humidity) || (abs(prev_temperature - temperature) > diff_temperature))
    DHTupdate = true;
  else
    DHTupdate = false;

   // Check if any reads failed and exit early (to try again).
  if (isnan(humidity)|| isnan(temperature)) 
  {
    DHTfail = true;
    return; //retry sensor
  }
  DHTfail = false;

  prev_temperature = temperature;
  prev_humidity = humidity;
  
}//END: readDHT

void printDHT()
{
  if (DHTfail)
  {
    Serial.println(F("Failed to read from DHT sensor!"));
  }
  else if (DHTupdate)
  {
      Serial.println(F("------------ DHT 22 -------------------"));
      Serial.print(F("Humidity %: "));
      Serial.println(humidity);
      Serial.print(F("Temperature C: "));
      Serial.println(temperature);
      Serial.println(F("----------------------------------------"));
  }
  
}//END: printDHT
