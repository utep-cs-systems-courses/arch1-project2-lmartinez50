/**
 * Programmer: Lorenzo Martinez
 * Creation Date: 03/14/2020
 * Due date: 03/25/2020
 * Program to "toggled" between the red and green LEDs each time the button is pressed.
 * CS 3432 Computer Arch I
 * Rev 1.0 03/14/2020 Modified to make LEDs "toggle"
 * Rev 2.0 03/16/2020 Adding comments.
 **/
#include <msp430.h>
#include "switches.h"
#include "led.h"

void switch_init()          /* setup switch */
{
  P1REN |= SWITCHES;        /* enables resistors for switches */
  P1IE = SWITCHES;          /* enable interrupts from switches */
  P1OUT |= SWITCHES;        /* pull-ups for switches */
  P1DIR &= ~SWITCHES;       /* set switches' bits for input */
}

void switch_interrupt_handler()
{
    P1OUT |= LED_GREEN;
    P1OUT &= ~LED_RED;
    while(1){                           // infinite loop
        if (!(P1IN & SW1)){             //conditional if button is pressed
            P1OUT ^= LEDS;              //xor switches
            __delay_cycles(200000);     // to avoid bouncing
        }
    }
}
