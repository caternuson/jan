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
  init_pins();      // general pin setup
  init_ADC();       // for reading light and temperature
  spk_init();   // for making noise

  spk_on();
  spk_set(10);
  _delay_ms(500);
  spk_set(20);
  _delay_ms(500);
  spk_set(30);
  _delay_ms(500);
  spk_set(40);
  _delay_ms(500);
  spk_set(50);
  _delay_ms(500);  
  spk_off();

  while (1) {
    for (int i=0; i<256; i++) {
      neo_set_tentacles(color_wheel(255-i));
      _delay_ms(10);

      neo_set_aura(color_wheel( 
                                4 * (temp_get() - 100)
                              ));
      _delay_ms(10);      
    }

  }

  return 0;
}