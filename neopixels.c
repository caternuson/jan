/****************************************************************************
 * @file neopixels.c
 * @author Carter Nelson
 * @brief NeoPixel related functions.
 ***************************************************************************/
#include "neopixels.h"

bool auto_write = true; //!< Control auto writing of NeoPixel data
float brightness = 0.1; //!< NeoPixel brightness

/****************************************************************************
 * @brief Set auto write state.
 ***************************************************************************/
void neo_set_autowrite(bool value) {
  auto_write = value;
}

/****************************************************************************
 * @brief Get auto write state.
 * @return Current auto write state.
 ***************************************************************************/
bool neo_get_autowrite() {
  return auto_write;
}

/****************************************************************************
 * @brief Fill all pixels with the specified color.
 * @param color The 32 bit color value.
 ***************************************************************************/
void neo_fill(uint32_t color) {
  bool current = auto_write;
  auto_write = false;
  for (int i=0; i<NUM_PIXELS; i++) {
    neo_set_pixel(i, color);
  }
  auto_write = current;
  if (auto_write) neo_show();
}
/****************************************************************************
 * @brief Set specified pixel to specified color.
 * @param i The 0 based pixel index.
 * @param color The 32 bit color value.
 ***************************************************************************/
void neo_set_pixel(uint8_t i, uint32_t color) {
  // jan's neopixels are GRB
  pixel_rgb[i].g = color >> 16 & 0xff;
  pixel_rgb[i].r = color >>  8 & 0xff;
  pixel_rgb[i].b = color       & 0xff;
  if (auto_write) neo_show();
}

/****************************************************************************
 * @brief Set the four "tentacles" to specified color.
 * @param color The 32 bit color value.
 ***************************************************************************/
void neo_set_tentacles(uint32_t color) {
  bool current = auto_write;
  auto_write = false;  
  neo_set_pixel(TENTACLE_1, color);
  neo_set_pixel(TENTACLE_2, color);
  neo_set_pixel(TENTACLE_3, color);
  neo_set_pixel(TENTACLE_4, color);
  auto_write = current;
  neo_show();
}

/****************************************************************************
 * @brief Set the "aura" to specified color.
 * @param color The 32 bit color value.
 ***************************************************************************/
void neo_set_aura(uint32_t color) {
  neo_set_pixel(AURA, color);
  if (!auto_write) neo_show();
}

/****************************************************************************
 * @brief Set brightness.
  ***************************************************************************/
void neo_set_brightness(float value) {
  brightness = value;
}

/****************************************************************************
 * @brief Write out current NeoPixel data.
  ***************************************************************************/
void neo_show() {
  for (int i=0; i<NUM_PIXELS; i++) {
    pixel_buf[i].r = brightness * pixel_rgb[i].r;
    pixel_buf[i].g = brightness * pixel_rgb[i].g;
    pixel_buf[i].b = brightness * pixel_rgb[i].b;
  }
  ws2812_setleds(pixel_buf, NUM_PIXELS);  
}

/****************************************************************************
 * @brief Circular color value generator.
 * @param pos The wheel position, 0-255.
 * @param scale Brightness, 0 to 1.
 * @return The 32 bit color value.
 ***************************************************************************/
uint32_t color_wheel(uint8_t pos) {
  uint32_t r, g, b;
  pos = 255 - pos;
  if (pos < 85) {
    r = 255 - pos * 3;
    g = 0;
    b = pos * 3;
  } else if (pos < 170) {
    pos -= 85;
    r = 0;
    g = pos * 3;
    b = 255 - pos * 3;
  } else {
    pos -= 170;
    r = pos * 3;
    g = 255 - pos * 3;
    b = 0;
  }
  return r << 16 | g << 8 | b;
}

/****************************************************************************
 * @brief A dance light pattern
 ***************************************************************************/
void light_dance() {
/*
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
*/
}