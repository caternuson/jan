/****************************************************************************
 * @file neopixels.h
 * @author Carter Nelson
 * @brief NeoPixel related functions.
 ***************************************************************************/
#ifndef __neopixels_h__
#define __neopixels_h__

#include <avr/io.h>
#include <util/delay.h>

#include "light_ws2812.h"

#define NUM_PIXELS 5
struct cRGB pixels[NUM_PIXELS];

uint32_t color_wheel(uint8_t pos, float scale);
void pixels_fill(uint32_t color);
void pixel_set_color(uint8_t i, uint32_t color);
void light_dance();
void set_tentacles(uint32_t color);

#endif