#include <InPin.h>

// Object delaration

InPin button(2, HIGH); // On esp32 the LOW means pullup resistor and activates with LOW

void setup()
{
    Serial0.begin(9600);
    // Do not need Init
}

void loop()
{
    if (button.GetPinState() == LOW) // get if the button is pressed
    {
        Serial.println("Button is Pressed");
    }
}