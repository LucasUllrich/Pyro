/* 
 * File:   main.h
 * Author: Lucas
 *
 * Created on 14. April 2016, 12:49
 */

#ifndef MAIN_H
#define	MAIN_H

/***************************************************
 * Included Files
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Includes">
#include <xc.h>
#include "init.h"
#include "buttonchanges.h"
#include "ignition.h"
#include "storage.h"
#include "display.h"
#include "communication.h"
// </editor-fold>

/***************************************************
 * Defenitions
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Defenitions">
#define ELEMENTS(x) (sizeof(x) / sizeof(x[0]))
#define TRANSMITTER 0xAA
#define ADDRESS 0xAA
// </editor-fold>


/***************************************************
 * Variables and constants
 ***************************************************/
// <editor-fold defaultstate="expanded" desc="variables">
//#define COM_TEST
#define _XTAL_FREQ  4000000

bit ignite_ready = 0;

typedef struct Slave_Output
{
    unsigned char slave;
    unsigned char output;
    unsigned char address;  //equals pin_selected
    unsigned char led_address;
    signed int time;
}sl_out;

sl_out pin[] =
{
    {0, 0,  0, 31, },
    {0, 1,  1, 30, },
    {0, 2,  2, 29, },
    {0, 3,  3, 28, },
    {0, 4,  4, 27, },
    {0, 5,  5, 26, },
    {0, 6,  6, 25, },
    {0, 7,  7, 24, },
    {0, 8,  8, 39, },
    {0, 9,  9, 38, },
    {1, 0, 10, 37, },
    {1, 1, 11, 36, },
    {1, 2, 12, 35, },
    {1, 3, 13, 34, },
    {1, 4, 14, 33, },
    {1, 5, 15, 32, },
    {1, 6, 16, 47, },
    {1, 7, 17, 46, },
    {1, 8, 18, 45, },
    {1, 9, 19, 44, },
    {2, 0, 20, 43, },
    {2, 1, 21, 42, },
    {2, 2, 22, 41, },
    {2, 3, 23, 40, },
    {2, 4, 24, 53, },
    {2, 5, 25, 52, },
    {2, 6, 26, 51, },
    {2, 7, 27, 50, },
    {2, 8, 28, 49, },
    {2, 9, 29, 48, },
};
// </editor-fold>

/***************************************************
 * Pins
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Pins">
#define Led         PORTAbits.RA0       //Status LED
#define Slave_Up    PORTBbits.RB0       //Increase slave
#define Port_Up     PORTBbits.RB1       //Increase port of 
                                            //selected slave
#define Time_Up     PORTBbits.RB2       //Increase time at selected port
#define Time_Down   PORTBbits.RB3       //Decrease time at selected port
#define Time_Upup   PORTBbits.RB4       //Increase time at selected
                                            //port by 10
#define Transmit_En PORTBbits.RB5       //Enable transmission
#define Show_Write  PORTCbits.RC0       //Enable and latch to output
                                            //of shift registers
#define Ignite      PORTCbits.RC1       //Ignition signal
#define Disp_Res    PORTCbits.RC2       //Reset the displays
// </editor-fold>

/***************************************************
 * Functionprototypes
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Prototypes">
void Delay_Routine(unsigned char delay_multiplyer);
// </editor-fold>

#endif	/* MAIN_H */

