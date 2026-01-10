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

#define ADC_LIGHT_LO 70
#define ADC_LIGHT_HI 250

#define ADC_TEMP_LO 120
#define ADC_TEMP_HI 130

uint8_t light;
uint8_t temp;
float avg;

/****************************************************************************
 * @brief The main enty point.
 * @return exit status code
 ***************************************************************************/
int main() {
  init_pins();  // general pin setup
  init_ADC();   // for reading light and temperature
  spk_init();   // for making noise

  spk_play_tone(NOTE_D4, 500);
  spk_play_tone(NOTE_E4, 500);
  spk_play_tone(NOTE_C4, 500);
  spk_play_tone(NOTE_C3, 500);
  spk_play_tone(NOTE_G4, 2000);

  while (1) {
    avg = 0;
    for (uint8_t i=0; i<10; i++) {
      avg += read_light();
      _delay_ms(1);
    }
    light = avg / 10;
    light = light < ADC_LIGHT_LO ? ADC_LIGHT_LO : light;
    light = light > ADC_LIGHT_HI ? ADC_LIGHT_HI : light;
    light = (uint8_t)(255 * (light - ADC_LIGHT_LO) / (ADC_LIGHT_HI - ADC_LIGHT_LO));
    neo_set_tentacles(color_wheel(light));

    avg = 0;
    for (uint8_t i=0; i<10; i++) {
      avg += temp_get();
      _delay_ms(1);
    }
    temp = avg / 10;
    temp = temp < ADC_TEMP_LO ? ADC_TEMP_LO : temp;
    temp = temp > ADC_TEMP_HI ? ADC_TEMP_HI : temp;
    temp = 255 * (temp - ADC_TEMP_LO) / (ADC_TEMP_HI - ADC_TEMP_LO);
    neo_set_aura(color_wheel(temp));
  }

  return 0;
}