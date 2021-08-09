//+--------------------------------------------------------------------------
//
// NightDriver - (c) 2020 Dave Plummer.  All Rights Reserved.
//
// File:        
//
// Description:
//
//   
//
// History:     Sep-15-2020     davepl      Created
//
//---------------------------------------------------------------------------

#include <Arduino.h>
#define FASTLED_INTERNAL
#include <FastLED.h>

#include "ledgfx.h"

static const CRGB TwinkleColors [] = 
{
    CRGB::Red,
    CRGB::Blue,
    CRGB::Purple,
    CRGB::Green,
    CRGB::Yellow,
    CRGB::Orange
};

void DrawTwinkle()
{
    const int fadeAmt = 32;
    EVERY_N_MILLISECONDS(250)
    {
        FastLED.leds()[random(NUM_LEDS)] = TwinkleColors[random(0, ARRAYSIZE(TwinkleColors))];
        fadeToBlackBy(FastLED.leds(), NUM_LEDS, fadeAmt);
    }      
}

void DrawTwinkleTails() //This most certainly does not work.
{
    const int fadeAmt = 32;
    EVERY_N_MILLISECONDS(250)
    {
        FastLED.leds()[random(NUM_LEDS)] = TwinkleColors[random(0, ARRAYSIZE(TwinkleColors))];
        for(int i = NUM_LEDS-1; i == 1; i--) {
            FastLED.leds()[i] = FastLED.leds()[i-1];
        }
        fadeToBlackBy(FastLED.leds(), NUM_LEDS, fadeAmt);
    }      
}