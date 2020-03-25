#include "libTimer.h"
#include "buzzer.h"
#include <msp430.h>

static int counterLaBamba = 0;    //Counter to keep track of the notes in La Bamba song
static int counterForSWTheme = 0;   //Counter to keep track of the notes in the Star Wars Theme song
static int counterForLaCucaracha = 0;   //Counter to keep track of the notes in La Cucaracha song

void buzzer_init(){
  /*
    Direct timer A output "TA0.1" to P2.6.
    According to table 21 from data sheet:
    P2SEL2.6, P2SEL2.7, and P2SEL.7 must be zero
    P2SEL.6 must be 1
    Also: P2.6 direction must be output
  */
  timerAUpmode(); //used to drive speaker
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6; //enable output to speaker (P2.6)
}

/*
  starWarsTheme is a method which calls the buzzer_set_period method
  from the buzzer.h file to produce the sound of the frequency specified on
  each case. When the method is called, the song from the Star Wars
  movie is played on the MSP430's speaker.
*/
void starWarsTheme(){
  switch(counterForSWTheme){
  case 0: buzzer_set_period(950); counterForSWTheme++; break; //Lower C note 950 (1/ fef)/2
  case 1:
  case 6:
  case 11: buzzer_set_period(637); counterForSWTheme++; break; //G note 630
  case 2:
  case 7:
  case 12:
  case 14: buzzer_set_period(710); counterForSWTheme++; break; //F note 710
  case 3:
  case 8:
  case 13: buzzer_set_period(750); counterForSWTheme++; break; //E note 750
  case 4:
  case 9:
  case 15: buzzer_set_period(840); if(counterForSWTheme==15){counterForSWTheme = 0;} else{counterForSWTheme++;}; break;//D note 840
  case 5:
  case 10: buzzer_set_period(475); counterForSWTheme++; break; //C6 note 475 period Fq 1046.5
  }
}

/*
  laBamba is a method which calls the buzzer_set_period method
  from the buzzer.h file to produce the sound of the frequency specified on
  each case. When the method is called, the song La Bamba
  is played on the MSP430's speaker.
*/
void laBamba(){
  switch(counterLaBamba){
  case 0:
  case 9: buzzer_set_period(637); counterLaBamba++; break; //G5 note Fq 783.99
  case 1: buzzer_set_period(568); counterLaBamba++; break;  //A5 note Fq 880
  case 2:
  case 10: buzzer_set_period(506); counterLaBamba++; break; //B5 note Fq 987.77
  case 3:
  case 16: buzzer_set_period(478); counterLaBamba++; break; //C6 note Fq 1046 0r C5
  case 4:
  case 14:
  case 17:
  case 27:
  case 35: buzzer_set_period(379); counterLaBamba++; break; //E6 note Fq 1318.51
  case 5:
  case 8:
  case 18:
  case 21: buzzer_set_period(318); counterLaBamba++; break; //G6 note  Fq 1567.98
  case 6:
  case 12:
  case 13:
  case 19:
  case 22:
  case 23:
  case 24:
  case 25:
  case 26:
  case 30:
  case 31:
  case 32:
  case 33:
  case 34: buzzer_set_period(357); counterLaBamba++; break; // F6 note 1396.91
  case 7:
  case 20: buzzer_set_period(284); counterLaBamba++; break;  // A6 note Fq 1760
  case 11:
  case 15:
  case 29: buzzer_set_period(425); counterLaBamba++; break; //D6 note Fq 1174.66
  case 28:
  case 36: buzzer_set_period(478); if(counterLaBamba==36){counterLaBamba = 0;} else{counterLaBamba++;}; break; //C
  }
}

/*
  laCucaracha is a method which calls the buzzer_set_period method
  from the buzzer.h file to produce the sound of the frequency specified on
  each case. When the method is called, the song La Cucaracha
  is played on the MSP430's speaker.
*/
void laCucaracha(){
    switch(counterForLaCucaracha){
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
    case 7:
    case 16:
    case 17:
    case 18:
    case 19:
    case 22:
    case 23:
    case 24: buzzer_set_period(950); counterForLaCucaracha++;break; //C
    case 3:
    case 8:
    case 10:
    case 11:
    case 33: buzzer_set_period(710);if(counterForLaCucaracha==33){counterForLaCucaracha = 0;} else{counterForLaCucaracha++;}; break; //F
    case 4:
    case 9:
    case 31: buzzer_set_period(560);counterForLaCucaracha++;break;  //A
    case 12:
    case 13:
    case 20:
    case 25: buzzer_set_period(750);counterForLaCucaracha++;break;  //E
    case 14:
    case 15: buzzer_set_period(840);counterForLaCucaracha++;break;  //D
    case 21:
    case 26:
    case 32: buzzer_set_period(630);counterForLaCucaracha++;break;  //G
    case 27:
    case 29: buzzer_set_period(475);counterForLaCucaracha++;break;  //C+
    case 28: buzzer_set_period(385);counterForLaCucaracha++;break;  //D+
    case 30: buzzer_set_period(530);counterForLaCucaracha++;break;  //A#
    }
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1; //one half cycle
}
