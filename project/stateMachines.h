#ifndef stateMachine_included
#define stateMachine_included

extern char switch_state_down, switch_state_changed; /* effectively boolean */


void state_advance();
void reset_state();
void dim_led();         /* dim red led */
void dim_green_led();  /* dim green led*/
void delay();

#endif // included
