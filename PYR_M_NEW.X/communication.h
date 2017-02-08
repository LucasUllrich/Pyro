/* 
 * File:   communication.h
 * Author: Lucas
 *
 * Created on 12. Juli 2016, 16:54
 */

#ifndef COMMUNICATION_H
#define	COMMUNICATION_H
#include "main.h"

/***************************************************
 * Functionprototypes
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Prototypes">
void Transmit(unsigned char receiver, unsigned char operation, 
        unsigned char port);
unsigned char Receive(void);
void Receive_Dump(void);
void Write_Display_Byte(unsigned char *write_data);
// </editor-fold>

/***************************************************
 * Variables and constants
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Variables">
bit overrun = 0;
// </editor-fold>



#endif	/* COMMUNICATION_H */

