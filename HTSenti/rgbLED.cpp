/*************************************************************************
 *  HTSenti
 *  Tristan Cool, Mark Cool
 *  2020
 *  rgbLED.cpp
 ************************************************************************/
 
#include "rgbLED.h"
#include <stdio.h>
#include <string.h>
#include "Arduino.h"

rgbLED::rgbLED()
{
	//default constructor
}

rgbLED::rgbLED(uint8_t R_pin, uint8_t G_pin, uint8_t B_pin)
{
	pin_R = R_pin;
	pin_G = G_pin;
	pin_B = B_pin;
}

void rgbLED::init()
{
	pinMode(pin_R, OUTPUT);
	pinMode(pin_G, OUTPUT);
	pinMode(pin_B, OUTPUT);
}

void rgbLED::print_values()
{
  Serial.println(F("-- R --- G --- B -"));
  Serial.print(F("  "));
  Serial.print(red);
  Serial.print(F("    "));
  Serial.print(green);
  Serial.print(F("    "));
  Serial.println(blue);
}

void rgbLED::colour(int r, int g, int b)
{
  
  if(r > 255)
    red = 255;
  else if(r < 0)
    red = 0;
  else
    red = r;

  if(g > 255)
    green = 255;
  else if(g < 0)
    green = 0;
  else
    green = g;

  if(b > 255)
    blue = 255;
  else if(b < 0)
    blue = 0;
  else
    blue = b;
    
  analogWrite(pin_R, red);
  analogWrite(pin_G, green);
  analogWrite(pin_B, blue);
}

void rgbLED::off()
{
  colour(0,0,0);
}

void rgbLED::go_white(bool hold)
{
  colour(255,255,255);
  if(!hold)
  {
    delay(500);
    off();
    delay(500);
  }
}

void rgbLED::flash_white()
{
  go_white(false);
  go_white(false);
  go_white(false);
}

void rgbLED::go_red(bool hold)
{
  colour(255,0,0); 
  if(!hold)
  {
    delay(500);
    off();
    delay(500);
  }
}

void rgbLED::flash_red()
{
  go_red(false);
  go_red(false);
  go_red(false);
}

void rgbLED::go_green(bool hold)
{
  colour(0,255,0); 
  if(!hold)
  {
    delay(500);
    off();
    delay(500);
  }
}

void rgbLED::flash_green()
{
  go_green(false);
  go_green(false);
  go_green(false);
}

void rgbLED::go_blue(bool hold)
{
  colour(0,0,255);
  if(!hold)
  {
    delay(500);
    off();
    delay(500);
  }
}

void rgbLED::flash_blue()
{
  go_blue(false);
  go_blue(false);
  go_blue(false);
}

void rgbLED::rainbow()
{
//  //reset white
//  colour(255,255,255);
//  delay(50);
  
  //R-O-Y-G-B-I-V
  //R
  colour(255,0,0);
  delay(50);
  //R-O-Y (255,0,0 --> 255,255,0)
  for(int g=0; g <256; g++)
  {
    colour(255,g,0);
    delay(5);
    //print_values();
  }
  //G (255,255,0 --> 0,255,0)
  for(int r=255; r>0; r--)
  {
    colour(r,255,0);
    delay(5);
    //print_values();
  }
  //B-I-V (0,255,0 --> 0,255,255)
  for(int b=0; b<256; b++)
  {
    colour(0,255,b);
    delay(5);
    //print_values();
  }
  //V (0,255,255 --> 0,0,255)
   for(int g=255; g>0; g--)
  {
    colour(0,g,255);
    delay(5);
    //print_values();
  }
  //V --> R (0,0,255 --> 255,0,255)
  for(int r=0; r<256; r++)
  {
    colour(r,0,255);
    delay(5);
    //print_values();
  }
  //V --> R (255,0,255 --> 255,0,0)
  for(int b=0; b>0; b--)
  {
    colour(255,0,b);
    delay(5);
    //print_values();
  }
  delay(50);
}

void rgbLED::reverse_rainbow()
{
//  //reset white
//  colour(255,255,255);
//  delay(50);
  
  //V-I-B-G-Y-O-R
  //R
  colour(255,0,0);
  delay(50);
  //R --> V (255,0,0 --> 255,0,255)
  for(int b=0; b <256; b++)
  {
    colour(255,0,b);
    delay(5);
    //print_values();
  }
  //V (255,0,255 --> 0,0,255)
  for(int r=255; r>0; r--)
  {
    colour(r,0,255);
    delay(5);
    //print_values();
  }
  //V-I-B (0,0,255 --> 0,255,255)
  for(int g=0; g<256; g++)
  {
    colour(0,g,255);
    delay(5);
    //print_values();
  }
  //G (0,255,255 --> 0,255,0)
   for(int b=255; b>0; b--)
  {
    colour(0,255,b);
    delay(5);
    //print_values();
  }
  //Y-O-R (0,255,0 --> 255,255,0)
  for(int r=0; r<256; r++)
  {
    colour(r,255,0);
    delay(5);
    //print_values();
  }
  //R (255,255,0 --> 255,0,0)
  for(int g=255; g>0; g--)
  {
    colour(255,g,0);
    delay(5);
    //print_values();
  }
  delay(50);
}

void rgbLED::error()
{
  for(int i = 0 ; i<4; i++)
  {
    colour(255,0,255); 
    delay(200);
    colour(0,255,255); 
    delay(200);
  }
  off();
}

void rgbLED::start_sequence()
{
  go_white(false);
  flash_red();
  flash_green();
  flash_blue();
  go_white(false);  
}
