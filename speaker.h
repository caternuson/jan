/****************************************************************************
 * @file speaker.h
 * @author Carter Nelson
 * @brief Piezo buzzer speaker related functions.
 ***************************************************************************/
#ifndef __speaker_h__
#define __speaker_h__

#include <avr/io.h>

void spk_init();
void spk_set(uint8_t value);
void spk_on();
void spk_off();

#endif