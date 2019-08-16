#ifndef __speaker_h__
#define __speaker_h__

#include <avr/io.h>

void set_buzzer(uint8_t value);
void buzzer_on();
void buzzer_off();

#endif