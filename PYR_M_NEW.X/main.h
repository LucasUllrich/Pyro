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
 * Variables and constants
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="variables">
#define _XTAL_FREQ  4000000
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

