/**
 * Programmer: Lorenzo Martinez
 * Creation Date: 03/14/2020
 * Due date: 03/25/2020
 * Program to "toggled" between the red and green LEDs each time the button is pressed.
 * CS 3432 Computer Arch I
 **/
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"

int main(void)
{
  configureClocks();
  switch_init();
  led_init();

  or_sr(0x18);  // CPU off, GIE on

  return 0;
}
