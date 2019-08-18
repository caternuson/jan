/****************************************************************************
 * @file temperature.h
 * @author Carter Nelson
 * @brief Temperature sensor related functions.
 ***************************************************************************/
#ifndef __temperature_h__
#define __temperature_h__

#include <avr/io.h>
#include "adc.h"

#define TEMPERATURE_MUX 0x02

uint8_t temp_get();

#endif