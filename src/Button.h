#pragma once
#include "Arduino.h"
#include "util.h"

class Button{
    public:
    Button(int color, int letter) {
        color_ = color;
        letter_ = letter;
        pin = pinMap[color_][letter_];
        pinMode(pin, INPUT_PULLUP);
        buttons[numButtons++] = this;
    }
    ~Button() {}

    bool Pressed() {
        state = !digitalRead(pin);
        return state;
    }

    void update() {
        bool reading = digitalRead(pin);
        unsigned long currentTime = millis();

        if (reading != lastReading) {
            lastDebounceTime = currentTime;
        }

        if ((currentTime - lastDebounceTime) > debounceDelay) {
            if (state == HIGH && reading == LOW && callback_) {
                callback_();
            }
            state = reading;
        }

        lastReading = reading;
    }

    void onPress(void (*callback)()) {
        callback_ = callback;
    }

    static void updateAll() {
        for (int i = 0; i < numButtons; ++i) {
            buttons[i]->update();
        }
    }

    private:

    int color_, letter_;
    int pin;
    bool state;
    void (*callback_)() = nullptr;
    static Button* buttons[16]; // support up to 16 buttons
    static int numButtons;
    unsigned long lastDebounceTime = 0;
    const unsigned long debounceDelay = 20; // milliseconds
    bool lastReading = HIGH; // last raw pin reading
};