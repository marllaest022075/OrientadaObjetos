#ifndef InPin_h
#define InPin_h

#include "Arduino.h"

class OutPin
{
private:
    byte _pin;

public:
    OutPin(byte pin);
    void Init();
    void On();
    void Off();
    void Toggle(unsigned long time);
};

#endif