/* 
 * File:   display.h
 * Author: Lucas
 *
 * Created on 14. April 2016, 13:17
 */

#ifndef DISPLAY_H
#define	DISPLAY_H
#include "main.h"

/***************************************************
 * Functionprototypes
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="Prototypes">
void Display(void);
void Evaluate_Display(unsigned int evaluate);
void Set_Display(unsigned char type, unsigned char target,
        unsigned char set_pixels);
// </editor-fold>

/***************************************************
 * Variables and constants
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="variables">
//#define COM_TEST
unsigned char pixels[57];
/** Description to pixels[]
 * First 3 Bytes: 7-segment displays
 *  Bit 7, MSB: empty
 *  Bit 6:      g, center
 *  Bit 5:      f, top left
 *  Bit 4:      e, bottom left
 *  Bit 3:      d, bottom
 *  Bit 2:      c, bottom right
 *  Bit 1:      b, top right
 *  Bit 0:      a, top
 * 
 * Following 4 Bytes: LED signals
 *  Bit 54 and 55 empty
 *  Bit 53 Led 25
 *  Bit 52 Led 26
 *  Bit 51 Led 27
 *  Bit 50 Led 28
 *  Bit 49 Led 29
 *  Bit 48 Led 30
 *  Bit 47 Led 17
 *  Bit 46 Led 18
 *  Bit 45 Led 19
 *  Bit 44 Led 20
 *  Bit 43 Led 21
 *  Bit 42 Led 22
 *  Bit 41 Led 23
 *  Bit 40 Led 24
 *  Bit 39 Led 9
 *  Bit 38 Led 10
 *  Bit 37 Led 11
 *  Bit 36 Led 12
 *  Bit 35 Led 13
 *  Bit 34 Led 14
 *  Bit 33 Led 15
 *  Bit 32 Led 16
 *  Bit 31 Led 1
 *  Bit 30 Led 2
 *  Bit 29 Led 3
 *  Bit 28 Led 4
 *  Bit 27 Led 5
 *  Bit 26 Led 6
 *  Bit 25 Led 7
 *  Bit 24 Led 8
 *  Bit 23 DP3
 *  Bit 22 g3
 *  Bit 21 f3
 *  Bit 20 e3
 *  Bit 19 d3
 *  Bit 18 c3
 *  Bit 17 b3
 *  Bit 16 a3
 *  Bit 15 DP2
 *  Bit 14 g2
 *  Bit 13 f2
 *  Bit 12 e2
 *  Bit 11 d2
 *  Bit 10 c2
 *  Bit 9  b2
 *  Bit 8  a2
 *  Bit 7  DP1
 *  Bit 6  g1
 *  Bit 5  f1
 *  Bit 4  e1
 *  Bit 3  d1
 *  Bit 2  c1
 *  Bit 1  b1
 *  Bit 0  a1
 */

//unsigned char reg0 = 0;     //Bit 7 to 1 Display left
//unsigned char reg1 = 0;     //Bit 7 to 1 Display mid
//unsigned char reg2 = 0;     //Bit 7 to 1 Display right
//unsigned char reg3 = 0;     //Bit 1 first led top left
//unsigned char reg4 = 0;
//unsigned char reg5 = 0;
//unsigned char reg6 = 0;     //6 & 7 unused
// </editor-fold>
#endif	/* DISPLAY_H */

