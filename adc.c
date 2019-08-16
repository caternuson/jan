/**************************************************************************/
/*!
    ADC related
 */
/**************************************************************************/
#include "adc.h"

/**************************************************************************/
/*!
    Read the supplied ADC channel.

    @param mux
           The ADC channel to read.
    @return The ADC reading in raw counts.
 */
/**************************************************************************/
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