/****************************************************************************
 * @file adc.h
 * @author Carter Nelson
 * @brief ADC related functions
 ***************************************************************************/
#ifndef __adc__h_
#define __adc__h_

#include <avr/io.h>

uint8_t read_ADC(uint8_t mux);

#endif