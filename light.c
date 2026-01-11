/****************************************************************************
 * @file light.c
 * @author Carter Nelson
 * @brief Light sensor related functions
 ***************************************************************************/
#include "light.h"

/****************************************************************************
 * @brief Read the light sensor value.
 *
 * @return The raw ADC counts.
 ***************************************************************************/
uint8_t read_light() {
  return read_ADC(LIGHT_ADC_CHAN);
}
