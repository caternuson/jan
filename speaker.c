//========================================================================
// speaker stuff
//========================================================================
#include "speaker.h"

//------------------------------------------------------------------------
//------------------------------------------------------------------------
void set_buzzer(uint8_t value) {
  OCR0A = value;
}

void buzzer_on() {
  // set speaker pin to output
  DDRB |= (1 << PB1);
}

void buzzer_off() {
  // set speaker pin to input
  DDRB &= ~(1 << PB1);
}