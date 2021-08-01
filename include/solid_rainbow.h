#include <Arduino.h>
#define FASTLED_INTERNAL
#include <FastLED.h>


void DrawSolidRainbow()
{
    const int deltaHue  = 4;
    static byte hue = HUE_RED;
    hue += deltaHue;
    static CRGB current_color;

    fill_solid(g_LEDs, NUM_LEDS, current_color.setHue(hue));
    delay(100);
}