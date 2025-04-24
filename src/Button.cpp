#include "Button.h"
#include "Arduino.h"

Button* Button::buttons[16];   // allocate storage for the static array
int Button::numButtons = 0;    // initialize the static counter