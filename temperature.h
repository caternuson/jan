/****************************************************************************
 * @file temperature.h
 * @author Carter Nelson
 * @brief Temperature sensor related functions.
 *
 * @section temp_info Info
 * Jan's temperature sensor is a Vishay NTCLE100E3103JB0 NTC thermistor
 * set up with a 10kohm resistor as a voltage divider read by the ADC.
 * ```
 *       VCC 5V USB
 *        |
 *        $ thermistor
 *  ADC --|
 *        $ 10 kohm
 *        |
 *       GND
 * ```
 * Thermistor resistance is 10kohm @ 25degC.
 * Thermistor resistance goes down with increasing temperature.
 * ADC counts go up with increasing temperature.
 * Datasheet has table of values.
 *  0 degC -> 32544 ohm -> 32k -> 1.18V ->  60 counts
 * 25 degC -> 10000 ohm -> 10k -> 2.5V  -> 127 counts
 * 30 degC -> 8059 ohm  ->  8K -> 2.77V -> 142 counts
 ***************************************************************************/
#ifndef __temperature_h__
#define __temperature_h__

#include <avr/io.h>
#include "adc.h"

#define TEMP_ADC_CHAN ADC_SE_CHAN2

uint8_t temp_get();

#endif