//+--------------------------------------------------------------------------
//
// NightDriver - (c) 2018 Dave Plummer.  All Rights Reserved.
//
// File:        LED Episode 08
//
// Description:
//
//   Draws sample effects on a an addressable strip using FastLED
//
// History:     Sep-15-2020     davepl      Created
//              Oct-05-2020     davepl      Revised for Episode 07
//              Oct-11-2020     davepl      Revised for Episode 08
//              Oct-16-2020     davepl      Revised for Episode 09
//---------------------------------------------------------------------------

#include <Arduino.h>            // Arduino Framework
#define FASTLED_INTERNAL        // Suppress build banner
#include <FastLED.h>

// FastLED definitions
#define NUM_LEDS    260         // Total number of LEDS in the strip
#define LED_PIN     12          // Microprocessor pin that LED strip data pin is connected to

int g_Brightness = 200;         // 0-255 LED brightness scale
int g_PowerLimit = 3000;        // Power Limit in milliwatts

CRGB g_LEDs[NUM_LEDS] = {0};    // Frame buffer for FastLED

#include "comet.h"
#include "solid_rainbow.h"
#include "twinkle.h"

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);
  while (!Serial) { }
  Serial.println("ESP32 Startup");

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(g_LEDs, NUM_LEDS);               // Add our LED strip to the FastLED library
  FastLED.setBrightness(g_Brightness);                                    // Set default brightness
  set_max_power_indicator_LED(LED_BUILTIN);                               // Light the builtin LED if we power throttle
  FastLED.setMaxPowerInMilliWatts(g_PowerLimit);                          // Set the power limit, above which brightness will be throttled
}

void loop() 
{
  //DrawComet();
  //DrawSolidRainbow();
  //DrawTwinkle();
  DrawTwinkleTails();
  FastLED.show(g_Brightness);                          // Show at selected brightness
  FastLED.delay(33);                                   // Delay for system tasks
}