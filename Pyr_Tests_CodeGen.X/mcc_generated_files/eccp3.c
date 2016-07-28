/**
  ECCP3 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    eccp3.c

  @Summary
    This is the generated driver implementation file for the ECCP3 driver using MPLAB® Code Configurator

  @Description
    This header file provides implementations for driver APIs for ECCP3.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.25.2
        Device            :  PIC18F23K22
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X v2.35 or v3.00
 */

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 */

/**
  Section: Included Files
 */

#include <xc.h>
#include "eccp3.h"

/**
  Section: COMPARE Module APIs
 */

void ECCP3_Initialize(void) {
    // Set the ECCP3 to the options selected in the User Interface

    // P3M single; CCP3M off/reset; DC3B LSBs; 
    CCP3CON = 0x00;

    // CCPR3L 0x0; 
    CCPR3L = 0x00;

    // CCPR3H 0x0; 
    CCPR3H = 0x00;

    // Selecting Timer1
    CCPTMRS0bits.C3TSEL = 0x0;
}

void ECCP3_SetCompareCount(uint16_t compareCount) {
    CCP_PERIOD_REG_T module;

    // Write the 16-bit compare value
    module.ccpr3_16Bit = compareCount;

    CCPR3L = module.ccpr3l;
    CCPR3H = module.ccpr3h;
}

bool ECCP3_IsCompareComplete(void) {
    // Check if compare is complete by reading "CCPIF" flag.
    return (PIR4bits.CCP3IF);
}
/**
 End of File
 */