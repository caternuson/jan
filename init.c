/****************************************************************************
 * @file init.c
 * @author Carter Nelson
 * @brief Board initialization
 ***************************************************************************/
#include "init.h"

/****************************************************************************
 * @brief Initialize pins
 ***************************************************************************/
void init_pins() {
  // DDRx Data Direction, 0=in, 1=out
  DDRB = (0 << DDB5)  |  // PB5
         (0 << DDB4)  |  // PB4
         (0 << DDB3)  |  // PB3
         (0 << DDB2)  |  // PB2
         (0 << DDB1)  |  // PB1
         (1 << DDB0);    // PB0


  // PORTx Data Register
  PORTB = (0 << PORTB5)  |  // PB5
          (0 << PORTB4)  |  // PB4
          (0 << PORTB3)  |  // PB3
          (0 << PORTB2)  |  // PB2
          (0 << PORTB1)  |  // PB1
          (0 << PORTB0);    // PB0
}

/****************************************************************************
 * @brief Initialize ADC
 ***************************************************************************/
void init_ADC() {
  ADMUX = (0 << MUX3)  |     // MUX bit 3
          (0 << MUX2)  |     // MUX bit 2
          (0 << MUX1)  |     // MUX bit 1
          (0 << MUX0)  |     // MUX bit 0
          (0 << REFS2) |     // VRef bit 2
          (0 << REFS1) |     // VRef bit 1
          (0 << REFS0) |     // VRef bit 0
          (1 << ADLAR);      // left shift enable

  ADCSRA = (1 << ADEN)  |     // Enable ADC 
           (1 << ADPS2) |     // clock prescaler bit 2
           (1 << ADPS1) |     // clock prescaler bit 1
           (0 << ADPS0);      // clock prescaler bit 0
}

/****************************************************************************
 * @brief Initialize OCR
 ***************************************************************************/
void init_OCR() {
  // set to output and initially low
  //DDRB |= (1 << PB1);
  //PORTB &= ~(1 << PB1);

  // enable OC0B toggle on compare match, set CTC mode
  TCCR0A |= (1 << COM0B0) | (1 << WGM01);

  // select prescaler clock
  TCCR0B |= (1 << CS02) | (1 << CS00);

  // set compare value
  OCR0A = 0;  // use to change freq
  OCR0B = 1;  // use to change phase
}