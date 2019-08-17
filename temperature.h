/****************************************************************************
 * @file temperature.h
 * @author Carter Nelson
 * @brief Temperature sensor related functions.
 ***************************************************************************/
#ifndef __temperature_h__
#define __temperature_h__

#include <avr/io.h>
#include "adc.h"

uint8_t read_temperature();

#endif