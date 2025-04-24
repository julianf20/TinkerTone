#pragma once
#include "Arduino.h"
#include "util.h"
#include "LED.h"
#include "Button.h"
#include "Knob.h"
#include "Tone.h"
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

extern AudioOutputI2S i2s1;

void setupBoard();

void updateBoard();