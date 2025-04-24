#include <SonicCircuits.h>

Button myButton(Green, D);
LED myLED(Green, B);
Knob myKnob(Yellow, C);

Tone tone1;

void setup() {
  // put your setup code here, to run once:
  setupBoard();

  myButton.onPress(toggleLED);
  myLED.on();
}

void loop() {
  // put your main code here, to run repeatedly:
  updateBoard();
  tone1.setFrequency(myKnob.read());
}

void toggleLED() {
  myLED.toggle();
  tone1.toggle();
}