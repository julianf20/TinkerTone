#pragma once
#include "Arduino.h"

enum Color {
    Red,
    Green,
    Yellow,
    Blue,
    Pink,
    Black,
    NumColors
};

enum Letter {
    A,
    B,
    C,
    D,
    E,
    NumLetters
};

extern const int pinMap[NumColors][NumLetters];

float mapToFrequency(int input, float minFreq, float maxFreq);