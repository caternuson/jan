/****************************************************************************
 * @file speaker.c
 * @author Carter Nelson
 * @brief Piezo buzzer speaker related functions.
 ***************************************************************************/
#include "speaker.h"

/****************************************************************************
 * @brief Initialize OCR
 ***************************************************************************/
void spk_init() {
  // enable OC0B toggle on compare match, set CTC mode
  TCCR0A |= (1 << COM0B0) | (1 << WGM01);

  // select prescaler clock
  TCCR0B |= (1 << CS02) | (1 << CS00);

  // set compare value
  OCR0A = 0;  // use to change freq
  OCR0B = 1;  // use to change phase
}

/****************************************************************************
 * @brief Set buzzer to specified value.
 * @param value The buzzer value, 0-255.
 ***************************************************************************/
void spk_set(uint8_t value) {
  OCR0A = value;
}

/****************************************************************************
 * @brief Turn buzzer on.
 ***************************************************************************/
void spk_on() {
  // set speaker pin to output
  DDRB |= (1 << PB1);
}

/****************************************************************************
 * @brief Turn buzzer off.
 ***************************************************************************/
void spk_off() {
  // set speaker pin to input
  DDRB &= ~(1 << PB1);
}