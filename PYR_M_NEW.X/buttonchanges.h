/* 
 * File:   buttonchanges.h
 * Author: Lucas
 *
 * Created on 14. April 2016, 12:49
 */

#ifndef BUTTONCHANGES_H
#define	BUTTONCHANGES_H
#include "main.h"

/***************************************************
 * Functionprototypes
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Prototypes">
void Check_Buttons(void);
// </editor-fold>

/***************************************************
 * Variables and constants
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="variables">
//#define COM_TEST
unsigned char slave_selected = 0;
unsigned char pin_selected = 0;
bit testflag = 0;                   // If set -> con. test of
                                    // dettonators is running
// </editor-fold>

#endif	/* BUTTONCHANGES_H */

