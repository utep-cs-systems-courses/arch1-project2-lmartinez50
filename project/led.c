#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "switches.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;
unsigned char dim_on = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output

  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if (switch_state_changed  | led_changed | dim_on) {

      char ledFlags = greenVal[green_on] | redVal[red_on];

      P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
      P1OUT |= ledFlags;     // set bit for on leds
    }
    switch_state_changed = 0;
    led_changed = 0;
    dim_on = 0;
}


