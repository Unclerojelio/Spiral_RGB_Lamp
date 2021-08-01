#include <Arduino.h>
#define FASTLED_INTERNAL
#include <FastLED.h>


void DrawSolidRainbow()
{
    byte hue = beat8(8);
    fill_solid(g_LEDs, NUM_LEDS, CHSV(hue,255,255));
}