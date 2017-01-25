/* 
 * File:   ignition.h
 * Author: Lucas
 *
 * Created on 13. Juli 2016, 20:06
 */

#ifndef IGNITION_H
#define	IGNITION_H
#include "main.h"

/***************************************************
 * Functionprototypes
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Prototypes">
void Ignite_Port(unsigned char ignite_number);
void Check_Ignition(void);
void Mark_Ignite(void);
void Check_Power(void);
void Evaluate_Reception(void);
// </editor-fold>

/***************************************************
 * Variables
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Variables">
unsigned char Marker[10];
unsigned char p_status = 0x15;      // NAK
// </editor-fold>

#endif	/* IGNITION_H */

