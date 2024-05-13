#include <InPin.h>

InPin::InPin(byte pin, int pinStartState)
{
    _pin = pin;
    Init(pinStartState);
}
void InPin::Init(int pinStartState)
{

    _lastPinState = pinStartState;
    if (pinStartState == HIGH)
        pinMode(_pin, INPUT_PULLUP);
    else
        pinMode(_pin, INPUT_PULLDOWN);
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