//========================================================================
// neopixel stuff
//========================================================================
#include "neopixels.h"

uint8_t auto_write = 0;


//------------------------------------------------------------------------
//------------------------------------------------------------------------
uint32_t color_wheel(uint8_t pos, float scale) {
  uint32_t r, g, b;
  pos = 255 - pos;
  if (pos < 85) {
    r = scale*(255 - pos * 3);
    g = 0;
    b = scale*(pos * 3);
  } else if (pos < 170) {
    pos -= 85;
    r = 0;
    g = scale*(pos * 3);
    b = scale*(255 - pos * 3);
  } else {
    pos -= 170;
    r = scale*(pos * 3);
    g = scale*(255 - pos * 3);
    b = 0;
  }

  return r << 16 | g << 8 | b;
}

void pixels_fill(uint32_t color) {
  for (int i=0; i<NUM_PIXELS; i++) {
    // jan's neopixels are GRB
    pixels[i].g = color >> 16 & 0xff;
    pixels[i].r = color >>  8 & 0xff;
    pixels[i].b = color       & 0xff;
  }
  if (auto_write) ws2812_setleds(pixels, NUM_PIXELS);
}

void pixel_set_color(uint8_t i, uint32_t color) {
  pixels[i].g = color >> 16 & 0xff;
  pixels[i].r = color >>  8 & 0xff;
  pixels[i].b = color       & 0xff;
  if (auto_write) ws2812_setleds(pixels, NUM_PIXELS);
}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
void light_dance() {
  uint8_t current = auto_write;
  auto_write = 1;
  pixels_fill(0);
  for (int i=0; i<NUM_PIXELS; i++) {
    pixel_set_color(i, 0xff0000);
    _delay_ms(100);
    pixels_fill(0);
  }
  for (int i=NUM_PIXELS; i>0; i--) {
    pixel_set_color(i, 0x00ff00);
    _delay_ms(100);
    pixels_fill(0);
  }
  for (int i=0; i<NUM_PIXELS; i++) {
    pixel_set_color(i, 0x0000ff);
    _delay_ms(100);
    pixels_fill(0);
  }
  auto_write = current;
}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
void set_tentacles(uint32_t color) {
  uint8_t current = auto_write;
  auto_write = 0;  
  pixel_set_color(0, color);
  pixel_set_color(1, color);
  pixel_set_color(3, color);
  pixel_set_color(4, color);
  ws2812_setleds(pixels, NUM_PIXELS);
  auto_write = current;
}