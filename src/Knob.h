#pragma once
#include "Arduino.h"
#include "util.h"

class Knob {
    public:
    Knob(int color, int letter) {
        color_ = color;
        letter_ = letter;
        pin = pinMap[color_][letter_];
        knobs[numKnobs++] = this;
    }
    ~Knob() {}

    int read() {
        value = analogRead(pin);
        return value;
    }

    void update() {
        value = analogRead(pin);
    }

    static void updateAll() {
        for (int i = 0; i < numKnobs; ++i) {
            knobs[i]->update();
        }
    }

    private:
    int color_, letter_;
    int pin;
    int value;
    static Knob* knobs[8];
    static int numKnobs;

};