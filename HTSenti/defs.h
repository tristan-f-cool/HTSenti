/*************************************************************************
 *  HTSenti
 *  Tristan Cool, Mark Cool
 *  2020
 *  defs.h
 ************************************************************************/

#define DEBUG 0         // 1 = Debug mode ; 0 = Normal mode

//~~~~~~~~~~~~ DHT22 Temperature Humidity Sensor ~~~~~~~~~~~~
#define pinDHT 2        // Digital pin D2
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

#define MAX_TEMPERATURE 85
#define MIN_TEMPERATURE -25
#define MAX_HUMIDTY 80
#define MIN_HUMIDITY 0

//~~~~~~~~~~~~ Push Button ~~~~~~~~~~~~
#define pinButton A5    // Analog pin A5

//~~~~~~~~~~~~ RGB LED ~~~~~~~~~~~~
#define pinLED_R  6    // LED RGB red   Digital pin D6
#define pinLED_G  5    // LED RGB blue  Digital pin D5
#define pinLED_B  9    // LED RGB green Digital pin D9

#define VERY_COLD   18 //degrees celsius limit
#define COLD        20 //degrees celsius limit
#define IDEAL       22 //degrees celsius limit
#define HOT         25 //degrees celsius limit
#define VERY_HOT    27 //degrees celsius limit
