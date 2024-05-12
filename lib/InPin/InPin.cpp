#include <InPin.h>

InPin::InPin(byte pin, int pinStartState)
{
    _pin = pin;
    Init(pinStartState);
}
void InPin::Init(int pinStartState)
{

    _lastPinState = pinStartState;

    pinMode(_pin, _pinState == HIGH ? INPUT_PULLDOWN : INPUT_PULLUP);
    UpdateState();
}

void InPin::UpdateState()
{
    int reading = digitalRead(_pin);
    if (reading != _lastPinState)
        _lastDebounceTime = millis();
    if ((millis() - _lastDebounceTime) > _debounceDelay)
        _pinState = reading;
    _lastPinState = reading;
}
int InPin::GetPinState()
{
    UpdateState();
    return _pinState;
}