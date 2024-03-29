/****************************************************************************
 * @file temperature.c
 * @author Carter Nelson
 * @brief Temperature sensor related functions.
 ***************************************************************************/
#include "temperature.h"

/****************************************************************************
 * @brief Read the temperature sensor value.
 * @return Raw ADC reading from temperature.
 ***************************************************************************/
uint8_t temp_get() {
  return read_ADC(TEMPERATURE_MUX);
}