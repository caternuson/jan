/****************************************************************************
 * @file speaker.c
 * @author Carter Nelson
 * @brief Piezo buzzer speaker related functions.
 ***************************************************************************/
#include "speaker.h"

/****************************************************************************
 * @brief Initialize Timer/Counter
 ***************************************************************************/
void spk_init() {
  // enable OC0B toggle on compare match, set CTC mode
  TCCR0A = (0 << COM0A1) |     // Compare Match Output Mode A
           (0 << COM0A0) |     //    "      "      "     "
           (0 << COM0B1) |     // Compare Match Output Mode B
           (1 << COM0B0) |     //    "      "      "     "
           (1 << WGM01)  |     // Waveform Generation Mode
           (0 << WGM00);       //    "          "      "

  // select clock prescaler to clk/1024
  TCCR0B = (0 << FOC0A) |      // Force Output Compare A
           (0 << FOC0B) |      // Force Output Compare B
           (0 << WGM02) |      // Waveform Generation Mode
           (1 << CS02)  |      // Clock Select
           (0 << CS01)  |      //    "     "
           (1 << CS00);        //    "     "

  // set initial compare values
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
 * @brief Play tone of specified frequency and duration.
 * @param freq Tone frequency in Hz.
 * @param delay Tone duration in ms.
 ***************************************************************************/
void spk_play_tone(float freq, int delay) {
  // 8MHz / 1024 = 7812.5Hz
  // highest tone ~= 7812Hz
  // lowest tone = 7812.5 / 255 ~= 31Hz
  spk_on();
  spk_set(7812.5 / freq);
  _delay_ms(delay);
  spk_off();
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