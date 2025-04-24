#include "Tone.h"

Tone* Tone::tones[8];
int Tone::toneCount = 0;

void Tone::registerTone(Tone* tone) {
    if (toneCount < 8) {
        tones[toneCount++] = tone;
    }
}