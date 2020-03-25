/**
 * Programmer: Lorenzo Martinez
 * Creation Date: 03/11/2020
 * Due date: 03/25/2020
 * Binary Counter 0 - 3
 * CS 3432 Computer Arch I
 **/
#include <msp430g2553.h>
#define LEDS (BIT0 | BIT6)

int main() {

    WDTCTL = WDTPW | WDTHOLD;                   // Stop Watchdog timer

    P1DIR |= LEDS;                              // Set P1DIR with P0 and P6 to high (1) output
                                                // The P1DIR registry knows which pins will be used as output (1) 0 = input, 1 = output.

    for (;;) {                                  // This empty for-loop will cause the lines of code within to loop infinitely

        P1OUT = ~LEDS;                          // 00
        __delay_cycles(1000000);
        P1OUT = BIT6;                           // 01
        __delay_cycles(1000000);
        P1OUT = BIT0;                           // 10
        __delay_cycles(1000000);
        P1OUT = LEDS;                           // 11
        __delay_cycles(1000000);                // 1000000 microseconds between each cycle (1 sec)*/

    }

    return 0;
}
