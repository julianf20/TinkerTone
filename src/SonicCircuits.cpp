#include "SonicCircuits.h"

AudioControlSGTL5000     sgtl5000_1;
AudioOutputI2S i2s1;
AudioMixer4 mixer_;
AudioSynthWaveformSine sine1, sine2;
// AudioConnection patchCord1(sine1, 0, mixer_, 0);
// AudioConnection patchCord2(mixer_, 0, i2s1, 0);
// AudioConnection patchCord3(mixer_, 0, i2s1, 1);
AudioConnection* patchCord[12];
Tone* tones[4];
int pci;

void setupBoard() {

    AudioMemory(8);
    sgtl5000_1.enable();
    sgtl5000_1.volume(0.5);

    pci = 0;
    // patchCord[pci++] = new AudioConnection(sine1, 0, i2s1, 0);
    patchCord[pci++] = new AudioConnection(mixer_, 0, i2s1, 0);
    patchCord[pci++] = new AudioConnection(mixer_, 0, i2s1, 1);

    // sine1.frequency(220.f);
    // sine2.frequency(330.f);
    // sine2.amplitude(.1f);
    // sine2.amplitude(.1f);
}

void updateTones() {
    for (int i = 0; i < Tone::toneCount; i++) {
        Tone* tone = Tone::tones[i];
        if (!tone->isConnected()) {
            patchCord[pci++] = new AudioConnection(*tone->getWaveform(), 0, mixer_, i);
            tone->markConnected();
        }
    }
}

void updateBoard() {
    Button::updateAll();
    Knob::updateAll();
    updateTones();
}