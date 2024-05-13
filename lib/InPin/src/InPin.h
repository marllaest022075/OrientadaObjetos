#ifndef InPin_h
#define InPin_h

#include <Arduino.h>

class InPin
{
private:
    byte _pin;
    int _pinState;
    int _lastPinState;
    unsigned long _lastDebounceTime = 0;
    unsigned long _debounceDelay = 50;
    void Init(int pinStartState);

public:
    InPin(byte pin, int pinStartState);
    void UpdateState();
    int GetPinState();
};

#endif