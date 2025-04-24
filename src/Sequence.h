#pragma once
#include "Tone.h"

class Sequence{
    public:
    Sequence(int l) {
        tone_ = t;
        length_ = l;
        tempo_ = 120;
        idx = 0;
        intervalCounter = millis();
        changeTempo(tempo_);
    }
    ~Sequence() {}

    void changeTempo() {
        unsigned long m = millis();
        if (m - intervalCounter > curInterval) {
            idx++;
        }
    }

    void onStep(void (*callback)()) {
        callback_ = callback;
    }

    private:
    void (*callback_)() = nullptr;
    int length_;
    int tempo_;
    int idx;
    unsigned long curInterval;
    unsigned long intervalCounter;
};