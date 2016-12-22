/* 
 * File:   interrupt.h
 * Author: Lucas
 *
 * Created on 14. Juli 2016, 19:56
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
unsigned char received[5];
unsigned char receive_counter = 0;
bit master_addressed = 0;
// </editor-fold>

#endif	/* INTERRUPT_H */

