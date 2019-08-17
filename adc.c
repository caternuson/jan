/****************************************************************************
 * @file adc.c
 * @author Carter Nelson
 * @brief ADC related functions
 ***************************************************************************/

#include "adc.h"

/****************************************************************************
 * @brief Initialize ADC
 ***************************************************************************/
void init_ADC() {
  ADMUX = (0 << MUX3)  |     // MUX bit 3
          (0 << MUX2)  |     // MUX bit 2
          (0 << MUX1)  |     // MUX bit 1
          (0 << MUX0)  |     // MUX bit 0
          (0 << REFS2) |     // VRef bit 2
          (0 << REFS1) |     // VRef bit 1
          (0 << REFS0) |     // VRef bit 0
          (1 << ADLAR);      // left shift enable

  ADCSRA = (1 << ADEN)  |     // Enable ADC 
           (1 << ADPS2) |     // clock prescaler bit 2
           (1 << ADPS1) |     // clock prescaler bit 1
           (0 << ADPS0);      // clock prescaler bit 0
}

/****************************************************************************
 * @brief Read the supplied ADC channel.
 *
 * @param mux The ADC channel to read.
 * @return The ADC reading in raw counts.
 ***************************************************************************/
uint8_t read_ADC(uint8_t mux) {
  // set mux
  ADMUX |= mux;

  // start conversion
  ADCSRA |= (1 << ADSC);

  // wait for it to complete
  while (ADCSRA & (1 << ADSC)) {}

  // return value
  return ADCH;
}