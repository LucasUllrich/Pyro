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
void Evaluate_Display(unsigned char size, unsigned char *evaluate);
void Evaluate_Signs(unsigned int evaluation_value);
void Set_Display(unsigned char type, unsigned char information,
        unsigned int value);
// </editor-fold>

/***************************************************
 * Variables and constants
 ***************************************************/
// <editor-fold defaultstate="collapsed" desc="variables">
//#define COM_TEST
unsigned char pixels[7];
unsigned char signs[3];
unsigned char display_counter = 0;
/** Description to pixels[]
 * 
 * Array Nr. 6 is shifted out first, 0 last
 * 
 * First 3 Bytes (0...2): 7-segment displays
 *  Bit 7, MSB: empty
 *  Bit 6:      g, center
 *  Bit 5:      f, top left
 *  Bit 4:      e, bottom left
 *  Bit 3:      d, bottom
 *  Bit 2:      c, bottom right
 *  Bit 1:      b, top right
 *  Bit 0:      a, top
 * 
 * Following 4 Bytes (3...6): LED signals
 * /////// Array 6
 *  Bit 54 and 55 empty
 *  Bit 53 Led 24
 *  Bit 52 Led 25
 *  Bit 51 Led 26
 *  Bit 50 Led 27
 *  Bit 49 Led 28
 *  Bit 48 Led 29
 * /////// Array 5
 *  Bit 47 Led 16
 *  Bit 46 Led 17
 *  Bit 45 Led 18
 *  Bit 44 Led 19
 *  Bit 43 Led 20
 *  Bit 42 Led 21
 *  Bit 41 Led 22
 *  Bit 40 Led 23
 * /////// Array 4
 *  Bit 39 Led 8
 *  Bit 38 Led 9
 *  Bit 37 Led 10
 *  Bit 36 Led 11
 *  Bit 35 Led 12
 *  Bit 34 Led 13
 *  Bit 33 Led 14
 *  Bit 32 Led 15
 * /////// Array 3
 *  Bit 31 Led 0
 *  Bit 30 Led 1
 *  Bit 29 Led 2
 *  Bit 28 Led 3
 *  Bit 27 Led 4
 *  Bit 26 Led 5
 *  Bit 25 Led 6
 *  Bit 24 Led 7
 * /////// 7-Segment
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

