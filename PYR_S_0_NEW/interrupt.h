/* 
 * File:   interrupt.h
 * Author: Lucas
 *
 * Created on 14. Juli 2016, 14:59
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H
#include "main.h"

/***************************************************
 * Functionprototypes
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Prototypes">
void interrupt Isr(void);
// </editor-fold>

/***************************************************
 * Variables and constants
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Variables">
unsigned char received[4];
unsigned char receive_counter = 0;
// </editor-fold>

#endif	/* INTERRUPT_H */

