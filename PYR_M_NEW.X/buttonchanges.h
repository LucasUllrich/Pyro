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
    unsigned char led_address;
    signed int time;
}sl_out;

sl_out pin[] =
{
    {0, 0,  0, 31, },
    {0, 1,  1, 30, },
    {0, 2,  2, 29, },
    {0, 3,  3, 28, },
    {0, 4,  4, 27, },
    {0, 5,  5, 26, },
    {0, 6,  6, 25, },
    {0, 7,  7, 24, },
    {0, 8,  8, 39, },
    {0, 9,  9, 38, },
    {1, 0, 10, 37, },
    {1, 1, 11, 36, },
    {1, 2, 12, 35, },
    {1, 3, 13, 34, },
    {1, 4, 14, 33, },
    {1, 5, 15, 32, },
    {1, 6, 16, 47, },
    {1, 7, 17, 46, },
    {1, 8, 18, 45, },
    {1, 9, 19, 44, },
    {2, 0, 20, 43, },
    {2, 1, 21, 42, },
    {2, 2, 22, 41, },
    {2, 3, 23, 40, },
    {2, 4, 24, 53, },
    {2, 5, 25, 52, },
    {2, 6, 26, 51, },
    {2, 7, 27, 50, },
    {2, 8, 28, 49, },
    {2, 9, 29, 48, },
};

unsigned char slave_selected = 0;
unsigned char pin_selected = 0;
// </editor-fold>

#endif	/* BUTTONCHANGES_H */

