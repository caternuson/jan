/****************************************************************************
 * @file neopixels.h
 * @author Carter Nelson
 * @brief NeoPixel related functions.
 ***************************************************************************/
#ifndef __neopixels_h__
#define __neopixels_h__

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#include "light_ws2812.h"

#define AURA 2
#define TENTACLE_1 0
#define TENTACLE_2 1
#define TENTACLE_3 3
#define TENTACLE_4 4

#define NUM_PIXELS 5            //!< The number of NeoPixels

void neo_set_autowrite(bool value);
bool neo_get_autowrite();
void neo_set_brightness(float brightness);
void neo_fill(uint32_t color);
void neo_set_tentacles(uint32_t color);
void neo_set_aura(uint32_t color);
void neo_set_pixel(uint8_t i, uint32_t color);
void neo_show();
uint32_t color_wheel(uint8_t pos);
void light_dance();

#endif