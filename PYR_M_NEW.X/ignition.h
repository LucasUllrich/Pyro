/* 
 * File:   ignition.h
 * Author: Lucas
 *
 * Created on 14. April 2016, 12:49
 */

#ifndef IGNITION_H
#define	IGNITION_H
#include "main.h"

/***************************************************
 * Functionprototypes
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Prototypes">
void Start_Timer(void);
void Check_Detonators(void);
void Ignite_Detonators(void);
// </editor-fold>

/***************************************************
 * Variables and constants
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="variables">
unsigned int current_time = 0;
unsigned char check_counter = 0;
// </editor-fold>
#endif	/* IGNITION_H */

