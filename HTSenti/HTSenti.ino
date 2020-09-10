
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
float heat_index;
bool Fahrenheit = false;
bool DHTfail = false;
bool DHTupdate = true;

bool corrected_temperature;

//~~~~~~ BUTTON ~~~~~~~~~~~
byte Button = 0;
byte prev_Button = 0;
long button_time = 0;
long button_debounce = 50;

/*################## SETUP #############################################*/

void setup() 
{
  // initialize the serial communication:
  // Open terminal console: Ctrl + Shift + m
  Serial.begin(9600);
  Serial.println(F("~~~~~~~~~ HTSenti ~~~~~~~~~~~~"));

  //initialize DHT22
  dht.begin();

  //setup push-button
  pinMode(pinButton, INPUT);
  
}//END: setup

/*################## LOOP #############################################*/

void loop() 
{
  if(DEBUG) //DEBUG MODE
  {
    Serial.println(F("$$$$$$$$$$$$$$ DEBUG $$$$$$$$$$$$$$$$$$$$$"));
    debug();
  }
  
  else      //NORMAL OPERATION
  {
    checkButton();  // check push-button
    delay(2000);    // delay for sensor polling
    readDHT();      // read DHT22
    printDHT();     // print DHT22
  }
}//END: loop

/*################## FUNCTIONS ########################################*/
void debug()
{

}//END: debug

void checkButton()
{
  Button = digitalRead(pinButton);
  //Serial.println(Button);
  if(Button && !prev_Button && (millis() - button_time > button_debounce))
  {
    if(corrected_temperature)
    {
      Serial.println(F("Heat Index: OFF"));
      corrected_temperature = false;
    }
    else
    {
      Serial.println(F("Heat Index: ON"));
      corrected_temperature = true;
    }
  }
  
}//END: checkButton

void readDHT()
{
  prev_humidity = humidity;            //store last humidity reading
  humidity = dht.readHumidity();       //record new humidity value
  prev_temperature = temperature;      //store last temperatue reading
  temperature = dht.readTemperature(); //record new temperature value

/*
  //check for significant change in temperature or humidity
  if((abs(prev_humidity - humidity) > diff_humidity) || (abs(prev_temperature - temperature) > diff_temperature))
    DHTupdate = true;
  else
    DHTupdate = false;
*/
  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity)|| isnan(temperature)) 
  {
    DHTfail = true;
    return; //break
  }
  DHTfail = false;

  //TODO - check for max and min values
  
  prev_temperature = temperature;
  prev_humidity = humidity;

  // calculate heat index
  heat_index = dht.computeHeatIndex(temperature, humidity, Fahrenheit);
  
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
      if(corrected_temperature)
      {
        Serial.print(F("Heat Index C: "));
        Serial.println(heat_index);
      }
      Serial.println(F("----------------------------------------"));
  }
  
}//END: printDHT
