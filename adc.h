/****************************************************************************
 * @file adc.h
 * @author Carter Nelson
 * @brief ADC related functions
 ***************************************************************************/
#ifndef __adc__h_
#define __adc__h_

#include <avr/io.h>

#define ADC_SE_CHAN0 0b0000
#define ADC_SE_CHAN1 0b0001
#define ADC_SE_CHAN2 0b0010
#define ADC_SE_CHAN3 0b0011

void init_ADC();
uint8_t read_ADC(uint8_t mux);

#endif