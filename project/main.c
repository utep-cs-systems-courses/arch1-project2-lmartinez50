/**
 * Programmer: Lorenzo Martinez
 * Creation Date: 03/04/2020
 * Due date: 03/25/2020
 * Project 2 My Buzzer - Piano
 * CS 3432 Computer Arch I
 * Rev. 1 03/04/2020 Initial approach. Playing with leds.
 * Rev. 2 03/06/2020 Playing with switches and buzzer.
 * Rev. 3 03/07/2020 Putting it all together, leds, switches and buzzer. Starting buzzer - piano project.
 * Rev. 4 03/08/2020 Translating notes song to frequencies using periods. Adding functionality.
 * Rev. 5 03/09/2020 Playing with display. Adding functionality
 * Rev. 6 04/14/2020 Adding assembly file 
 **/

#include <lcdutils.h>
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcddraw.h"

int main(void)
{

    configureClocks();
    switch_init();  //Initialize switches
    lcd_init();     //Initialize LCD display
    clearScreen(COLOR_BLUE);
    drawRectOutline(0, 0, 127, 158,COLOR_WHITE);
    int colw = 15;
    int colb = 22;
    for(int i= 0; i < 7; i++){
    fillRectangle(colw,10,7,30,COLOR_WHITE); //col, row, width, height
    drawRectOutline(colw, 10, 7, 30,COLOR_BLACK);
    colw += 14;
    }

    for(int i= 0; i < 7; i++){
    fillRectangle(colb,10,7,20,COLOR_BLACK); //col, row, width, height
    fillRectangle(colb,30,7,10,COLOR_WHITE); //col, row, width, height
    colb += 14;
    }
    drawString5x7(19,32, "C", COLOR_BLACK,COLOR_WHITE);
    drawString5x7(33,32, "D", COLOR_BLACK,COLOR_WHITE);
    drawString5x7(47,32, "E", COLOR_BLACK,COLOR_WHITE);
    drawString5x7(61,32, "F", COLOR_BLACK,COLOR_WHITE);
    drawString5x7(75,32, "G", COLOR_BLACK,COLOR_WHITE);
    drawString5x7(89,32, "A", COLOR_BLACK,COLOR_WHITE);
    drawString5x7(103,32, "B", COLOR_BLACK,COLOR_WHITE);
    drawString5x7(10,50, "My Blink - Piano", COLOR_WHITE, COLOR_BLUE);
    drawString5x7(10,70, "SW 1. Counter 0-3", COLOR_WHITE, COLOR_BLUE);
    drawString5x7(10,80, "SW 2. Stars Wars", COLOR_WHITE, COLOR_BLUE);
    drawString5x7(10,90, "SW 3. La Cucaracha", COLOR_WHITE, COLOR_BLUE);
    drawString5x7(10,100, "SW 4. Stop/Dim LED", COLOR_WHITE, COLOR_BLUE);
    buzzer_init();        //Initialize buzzer
    led_init();           //Initialize leds

    or_sr(0x18);          // CPU off, GIE on

    return 0;
}
