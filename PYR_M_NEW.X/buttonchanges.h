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
typedef struct Slave_Output
{
    unsigned char slave;
    unsigned char output;
    unsigned char address;  //equals pin_selected
    signed int time;
}sl_out;

sl_out pin[] =
{
    {0, 0,  0, },
    {0, 1,  1, },
    {0, 2,  2, },
    {0, 3,  3, },
    {0, 4,  4, },
    {0, 5,  5, },
    {0, 6,  6, },
    {0, 7,  7, },
    {0, 8,  8, },
    {0, 9,  9, },
    {1, 0, 10, },
    {1, 1, 11, },
    {1, 2, 12, },
    {1, 3, 13, },
    {1, 4, 14, },
    {1, 5, 15, },
    {1, 6, 16, },
    {1, 7, 17, },
    {1, 8, 18, },
    {1, 9, 19, },
    {2, 0, 20, },
    {2, 1, 21, },
    {2, 2, 22, },
    {2, 3, 23, },
    {2, 4, 24, },
    {2, 5, 25, },
    {2, 6, 26, },
    {2, 7, 27, },
    {2, 8, 28, },
    {2, 9, 29, },
};

unsigned char slave_selected = 0;
unsigned char pin_selected = 0;
// </editor-fold>

#endif	/* BUTTONCHANGES_H */

