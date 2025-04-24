#pragma once
#include "Arduino.h"
#include "Audio.h"

class Tone {
    public:
    Tone() {
        sine.frequency(440.f);
        sine.amplitude(.1f);
        on_ = true;
        connected_ = false;
        registerTone(this);
    }
    ~Tone() {}

    void setFrequency(float f) {
        freq_ = f;
        sine.frequency(freq_);
    }

    void on() {
        sine.amplitude(0.f);
        on_ = true;
    }

    void off() {
        sine.amplitude(.1f);
        on_ = false;
    }

    void toggle() {
        on_ = !on_;
        if (on_) {
            sine.amplitude(.1f);
        }
        else {
            sine.amplitude(0.f);
        }
    }

    AudioSynthWaveformSine* getWaveform() {
        return &sine;
    }

    bool isConnected() const { return connected_; }

    void markConnected() { connected_ = true; }

    static void registerTone(Tone* tone);

    static Tone* tones[8];

    static int toneCount;

    private:
    float freq_;
    AudioSynthWaveformSine sine;
    bool connected_;
    bool on_;

};