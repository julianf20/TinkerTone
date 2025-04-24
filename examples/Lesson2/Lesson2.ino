#include <SonicCircuits.h>

Button tempo(Red, B);
Knob knob1(Yellow, B);
Knob knob2(Yellow, C);
Knob knob3(Yellow, D);
Knob knob4(Yellow, E);

LED led1(Pink, B);
LED led2(Green, C);
LED led3(Pink, D);
LED led4(Blue, E);

Sequence mySequence(4);

Tone tone1;

Knob myKnobs[4] = {knob1, knob2, knob3, knob4};
LED myLEDS[4] = {led1, led2, led3, led4;}

void setup() {
  // put your setup code here, to run once:
  setupBoard();
  mySequence.onStep(step) {

  }
}

void loop() {
  // put your main code here, to run repeatedly:
  updateBoard();
}

void step() {
  myLEDS[mySequence.laststep].toggle();
  myLEDS[mySequence.step].toggle();
  tone1.setFrequency(myKnobs[mySequence.step].read());
}