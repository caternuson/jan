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

