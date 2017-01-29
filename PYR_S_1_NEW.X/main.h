/* 
 * File:   main.h
 * Author: Lucas
 *
 * Created on 13. Juli 2016, 20:05
 */

#ifndef MAIN_H
#define	MAIN_H

/***************************************************
 * Included Files
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Includes">
#include <xc.h>
#include "init.h"
#include "ignition.h"
#include "communication.h"
#include "interrupt.h"
// </editor-fold>

/***************************************************
 * Variables and constants
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="variables">
#define _XTAL_FREQ  4000000
#define ADDRESS     0x01
#define TRANSMITTER 0x01
#define OPERATION   2
#define PORT        3
#define U_FVR       2.048
#define MIN_VOLTAGE 16.8
bit slave_addressed = 0;
// </editor-fold>

/***************************************************
 * Pins
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Pins">
#define Probe_0     PORTCbits.RC4
#define Probe_1     PORTDbits.RD2
#define Probe_2     PORTDbits.RD0
#define Probe_3     PORTCbits.RC2
#define Probe_4     PORTEbits.RE2
#define Probe_5     PORTEbits.RE0
#define Probe_6     PORTAbits.RA4
#define Probe_7     PORTBbits.RB4
#define Probe_8     PORTAbits.RA2
#define Probe_9     PORTAbits.RA0
#define Nr_0        PORTCbits.RC5
#define Nr_1        PORTDbits.RD3
#define Nr_2        PORTDbits.RD1
#define Nr_3        PORTCbits.RC3
#define Nr_4        PORTCbits.RC1
#define Nr_5        PORTEbits.RE1
#define Nr_6        PORTAbits.RA5
#define Nr_7        PORTBbits.RB5
#define Nr_8        PORTAbits.RA3
#define Nr_9        PORTAbits.RA1
#define Led         PORTBbits.RB3
#define Transmit_En PORTDbits.RD4
// </editor-fold>

/***************************************************
 * Functionprototypes
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Prototypes">

// </editor-fold>

#endif	/* MAIN_H */

