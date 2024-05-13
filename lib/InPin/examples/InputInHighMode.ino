#include <InPin.h>

// Object delaration

InPin button(2, LOW); // On esp32 the LOW means pulldown resistor and activates with HIGH

void setup()
{
    Serial0.begin(9600);
    // Do not need Init
}

void loop()
{
    if (button.GetPinState() == HIGH) // get if the button is pressed
    {
        Serial.println("Button is Pressed");
    }
}