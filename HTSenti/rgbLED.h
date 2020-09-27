/*************************************************************************
 *  HTSenti
 *  Tristan Cool, Mark Cool
 *  2020
 *  rgbLED.h
 ************************************************************************/

#ifndef rgbLED_h
#define rgbLED_h

#include <inttypes.h>

class rgbLED{
	
	public:
	
	//Constructor
		rgbLED();
		rgbLED(uint8_t R_pin, uint8_t G_pin, uint8_t B_pin);
		
	//Variables
    int red, green, blue = 255; //0-255
	
	//Functions
		void init();
    void print_values();
    void off();
    void colour(int red, int green, int blue);
    void go_white(bool hold);
    void flash_white();
    void go_red(bool hold);
    void flash_red();
    void go_green(bool hold);
    void flash_green();
    void go_blue(bool hold);
    void flash_blue();
    void rainbow();
    void reverse_rainbow();
    void error();
    void start_sequence();
    
	
	private:
	
	//pins
		uint8_t pin_R;
		uint8_t pin_G;
		uint8_t pin_B;
	
};

#endif
