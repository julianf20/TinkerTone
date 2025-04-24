#include "util.h"

const int pinMap[NumColors][NumLetters] = {
    {18, 19, 20, 21, 255},  // Red pins for A, B, C, D
    {25, 29, 5, 31, 34}, // Green pins for A, B, C, D, E
    {255, 14, 15, 16, 17}, // Yellow pins for B, C, D, E
    {0, 1, 30, 3, 24}, // Blue pins for A, B, C, D, E
    {28, 4, 2, 6, 35}, // Pink pins for A, B, C, D, E
    {19, 255, 255, 255, 255}  // Black pins for A, E
};

float mapToFrequency(int input, float minFreq, float maxFreq) {
    input = constrain(input, 0, 1024); // ensure it's within range
    float normalized = input / 1024.0f; // convert to 0.0 – 1.0
    return minFreq + normalized * (maxFreq - minFreq);
}