/****************************************************************************
 * @file init.c
 * @author Carter Nelson
 * @brief Board initialization
 ***************************************************************************/
#include "init.h"

/****************************************************************************
 * @brief Initialize pins
 * Pinout Summary:
 * ```
 *                +------------+
 *                |1 PB5  VCC 8|
 *                |2 PB3  PB2 7| - light
 *  temperature - |3 PB4  PB1 6| - speaker
 *                |4 GND  PB0 5| - neopixels
 *                +------------+
 * ```
 ***************************************************************************/
void init_pins() {
  // DDRx Data Direction, 0=in, 1=out
  DDRB = (0 << DDB5)  |  // PB5
         (0 << DDB4)  |  // PB4 temperature
         (0 << DDB3)  |  // PB3
         (0 << DDB2)  |  // PB2 light
         (0 << DDB1)  |  // PB1 speaker
         (1 << DDB0);    // PB0 neopixels


  // PORTx Data Register
  PORTB = (0 << PORTB5)  |  // PB5
          (0 << PORTB4)  |  // PB4 temperature
          (0 << PORTB3)  |  // PB3
          (0 << PORTB2)  |  // PB2 light
          (0 << PORTB1)  |  // PB1 speaker
          (0 << PORTB0);    // PB0 neopixels
}

