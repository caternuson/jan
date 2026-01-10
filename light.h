/****************************************************************************
 * @file light.h
 * @author Carter Nelson
 * @brief Light sensor related functions
 *
 * @section light_info Info
 * Jan's light sensor is a CdS photoresistor (Adafruit PID 161) set up
 * with a 10kohm resistor as a voltage divider read by the ADC.
 * ```
 *       VCC 5V USB
 *        |
 *        $ photoresistor
 *  ADC --|
 *        $ 10 kohm
 *        |
 *       GND
 * ```
 * VCC is 5V from USB power.
 * ADC is 10 bit.
 * Photoresistor resistance decreases with increased light.
 * ADC counts increase with increased light.
 * ADC is configured for 8 bit resolution.
 * light ~300 -> ADC counts ~247
 * dark ~25k -> ADC counts ~70
 ***************************************************************************/
#ifndef __light_h__
#define __light_h__

#include <avr/io.h>
#include <util/delay.h>

#include "adc.h"

#define LIGHT_MUX 0x01  // ADC1 (PB2)

uint8_t read_light();

#endif