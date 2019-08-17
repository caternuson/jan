/****************************************************************************
 * @file jan.c
 * @author Carter Nelson
 *
 *
  * @section intro_sec Overview
 * 
 * Jan's Brains
 * Coded for 2019 PCB Just 4 Fun
 * https://github.com/caternuson/2019-PCBs-Just-4-Fun
 * 
 * Pinout Summary:
 * ```
 *                +------------+
 *                |1 PB5  VCC 8|
 *                |2 PB3  PB2 7| - light
 *  temperature - |3 PB4  PB1 6| - speaker
 *                |4 GND  PB0 5| - neopixels
 *                +------------+
 * ```
 * 
 * @section author Author
 * 
 * Written by Carter Nelson
  ***************************************************************************/

#include "jan.h"

/****************************************************************************
 * @brief The main enty point.
 * @return exit status code
 ***************************************************************************/
int main() {
  init_pins();  // general pin setup
  init_ADC();   // for reading light and temperature
  init_OCR();   // for making noise

  light_dance();
  set_tentacles(0x050505);

  while (1) {
    for (int i=0; i<256; i++) {
      set_tentacles(color_wheel(i, 0.1));
      _delay_ms(50);
    }

  }

  return 0;
}