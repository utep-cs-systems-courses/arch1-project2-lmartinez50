#include <lcdutils.h>
#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "libTimer.h"
#include "lcdutils.h"


char switch_state_down, switch_state_changed, tempo; /* effectively boolean */

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P1IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P1IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE = SWITCHES;		    /* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
}

/*
  The switch_interrupt_handler is a method that reads the
  four switches from Port 2 in the MSP430. Every switch has
  a different song so that when one of them is pressed,
  a song starts playing on the buzzer of the MSP430.
  Also, when any of the switches is pressed, the
  green LED turns on. If any switch ain't pressed, then the red
  LED is on and the MSP430 makes no sound.
*/

void switch_interrupt_handler()
{

  char p2val = switch_update_interrupt_sense();

  /* Initial State */
  if(p2val & SW1 && p2val & SW2 && p2val & SW3 && p2val & SW4){
    buzzer_set_period(0);
    switch_state_down = 0;
  }
  /* If switch 1 is pressed start playing La Bamba */
  else if(!(p2val & SW1)){
    //Play La Bamba
    //tempo = 110;
    laBamba();
    switch_state_down = 1;
  }

  else if(!(p2val & SW2)){
    //Play Star Wars
    //tempo = 120;
    starWarsTheme();
    switch_state_down = 1;
  }

  else if(!(p2val & SW3)){
    //Play La Cucaracha
    //tempo = 110;
    //drawString5x7(20,50, "La Cucaracha", COLOR_WHITE, COLOR_BLUE);
    laCucaracha();
    switch_state_down = 1;
  }
  else if(!(p2val & SW4)){
    //Stop music
    buzzer_set_period(0);
    switch_state_down = 0;
  }

  switch_state_changed = 1;
  led_update();

}
