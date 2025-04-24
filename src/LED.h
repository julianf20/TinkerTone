#pragma once
#include "Arduino.h"
#include "util.h"

class LED {
    public:
    LED(int color, int letter) {
        color_ = color;
        letter_ = letter;
        pin = pinMap[color_][letter_];
        pinMode(pin, OUTPUT);
    }

    ~LED() {}

    void on() {
        digitalWrite(pin, HIGH);
        state = true;
    }

    void off() {
        digitalWrite(pin, LOW);
        state = false;
    }

    void toggle() {
        state = !state;
        digitalWrite(pin, state);
    }

    void dim(int value) {
        analogWrite(pin, value);
    }

    private:
    int color_, letter_;
    int pin;
    bool state;
};