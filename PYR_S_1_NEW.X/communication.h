/* 
 * File:   communication.h
 * Author: Lucas
 *
 * Created on 13. Juli 2016, 20:06
 */

#ifndef COMMUNICATION_H
#define	COMMUNICATION_H
#include "main.h"

/***************************************************
 * Functionprototypes
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Prototypes">
void Transmit(unsigned char trans_data);
unsigned char Receive(void);
// </editor-fold>

/***************************************************
 * Variables and constants
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Variables">
unsigned char overrun = 0;
// </editor-fold>


#endif	/* COMMUNICATION_H */

