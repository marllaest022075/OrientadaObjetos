#include <OutPin.h>

#include <Arduino.h>

OutPin::OutPin(byte pin)
{
    _pin = pin;
}
void OutPin::Init()
{
    pinMode(_pin, OUTPUT);
    Off();
}
void OutPin::On()
{
    digitalWrite(_pin, LOW);
}
void OutPin::Off()
{
    digitalWrite(_pin, HIGH);
}
void OutPin::Toggle(unsigned long time)
{
    static unsigned long lastTime = 0;
    unsigned long actual = millis();
    if (actual - lastTime > time)
        digitalWrite(_pin, !digitalRead(_pin));
}