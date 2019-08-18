/****************************************************************************
 * @file speaker.h
 * @author Carter Nelson
 * @brief Piezo buzzer speaker related functions.
 ***************************************************************************/
#ifndef __speaker_h__
#define __speaker_h__

#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

#define NOTE_C3 130.81
#define NOTE_C4 261.64
#define NOTE_D4 293.66
#define NOTE_E4 329.63
#define NOTE_F4 349.23
#define NOTE_G4 392.00
#define NOTE_A4 440.00
#define NOTE_B4 493.88

void spk_init();
void spk_set(uint8_t value);
void spk_play_tone(float freq, int delay);
void spk_on();
void spk_off();

#endif