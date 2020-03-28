#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "libTimer.h"
#include "lcdutils.h"

char switch_state_down, switch_state_changed;

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P1IES |= (p2val & SWITCHES);  /* if switch up, sense down */
  P1IES &= (p2val | ~SWITCHES); /* if switch down, sense up */
  return p2val;
}

void state_advance() {

    char p2val = switch_update_interrupt_sense();

      /* Initial State */
      if(p2val & SW1 && p2val & SW2 && p2val & SW3 && p2val & SW4){
        buzzer_set_period(0);
        switch_state_down = 0;
      }

      /* If switch 1 is pressed start playing La Bamba */
      else if(!(p2val & SW1)){
          //Play La Bamba
          laBamba();
          switch_state_down = 1;
      }

      /* If switch 2 is pressed start playing the Star Wars Theme */
      else if(!(p2val & SW2)){
          //Play Star Wars
          starWarsTheme();
          switch_state_down = 1;
      }

      /* If switch 3 is pressed start playing La Cucaracha */
      else if(!(p2val & SW3)){
          //Play La Cucaracha
          laCucaracha();
          switch_state_down = 1;
      }

      /* If switch 4 is pressed music stops and dim red led */
      else if(!(p2val & SW4)){
          //Stop music
          buzzer_set_period(0);
          switch_state_down = 0;
      }

      if(switch_state_down){
          switch_state_changed = 1;
          led_update();
      }
      else {
          switch_state_changed = 1;
          led_update();
          dim_led();
      }

}

void dim_led(){

        unsigned int j;

        for(j = 1; j < 1200; j++)    // Increasing Intensity
        {
            P1OUT |= LED_RED;         // LED ON
            delay(j);               // Delay for ON Time
            P1OUT &= ~LED_RED;        // LED OFF
            delay(1200-j);           // OFF Time = Period - ON Time
        }
        for(j = 1200; j > 1; j--)    // Decreasing Intensity
        {
            P1OUT |= LED_RED;         // LED ON
            delay(j);               // Delay for ON Time
            P1OUT &= ~LED_RED;        // LED OFF
            delay(1200-j);           // OFF Time = Period - ON Time
        }

        switch_state_changed = 0;
}

void delay(unsigned int t)          // Custom delay function
{
    unsigned int i;
    for(i = t; i > 0; i--)
        __delay_cycles(1);          // __delay_cycles accepts only constants !
}
