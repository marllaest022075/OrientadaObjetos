#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <InPin.h>
#include <OutPin.h>

// put global variables here:
bool flag = false;

// put pin declarations here:
const byte boton01 = 14;
const byte boton02 = 21;
const byte boton03 = 46;
const byte boton04 = 10;
const byte boton05 = 11;

// Constantes
const int Duration = 500;
const byte Led = 48;
const byte MaxLeds = 1;
const int Lag = 1000;
const byte Brightness = 50;

// put pin objects here:

InPin button01(boton01, HIGH);
InPin button02(boton02, HIGH);
InPin button03(boton03, HIGH);
InPin button04(boton04, HIGH);
InPin button05(boton05, HIGH);
Adafruit_NeoPixel pixels(MaxLeds, Led, NEO_BGR + NEO_KHZ800);

// put function declarations here:
void colorWipe(uint32_t color, int wait);
void SetBlueLed();
void SetRedLed();
void SetGreenLed();
void SetPinkLed();
void SetCianLed();
void SetOffLed();

void setup()
{
  // put your setup code here, to run once:
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (button01.GetPinState() == LOW && !flag)
  {
    flag = true;
    SetBlueLed();
    SetOffLed();
  }
  if (button02.GetPinState() == LOW && !flag)
  {
    flag = true;
    SetRedLed();
    SetOffLed();
  }
  if (button03.GetPinState() == LOW && !flag)
  {
    flag = true;
    SetGreenLed();
    SetOffLed();
  }
  if (button04.GetPinState() == LOW && !flag)
  {
    flag = true;
    SetPinkLed();
    SetOffLed();
  }
  if (button05.GetPinState() == LOW && !flag)
  {
    flag = true;
    SetCianLed();
    SetOffLed();
  }
  flag = false;
}

// put function definitions here:
void colorWipe(uint32_t color, int wait)
{
  for (int i = 0; i < pixels.numPixels(); i++) // For each pixel in strip...
  {
    pixels.setBrightness(Brightness); // Set pixel's brillo
    pixels.setPixelColor(i, color);   //  Set pixel's color (in RAM)
    pixels.show();                    //  Update strip to match
    delay(wait);                      //  Pause for a moment
  }
}

void SetBlueLed() { colorWipe(pixels.Color(255, 0, 0), Duration); }
void SetRedLed() { colorWipe(pixels.Color(0, 255, 0), Duration); }
void SetGreenLed() { colorWipe(pixels.Color(0, 0, 255), Duration); }
void SetPinkLed() { colorWipe(pixels.Color(255, 255, 0), Duration); }
void SetCianLed() { colorWipe(pixels.Color(255, 0, 255), Duration); }
void SetOffLed() { colorWipe(pixels.Color(0, 0, 0), 0); }