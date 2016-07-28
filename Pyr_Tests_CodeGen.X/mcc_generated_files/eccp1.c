/**
  ECCP1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    eccp1.c

  @Summary
    This is the generated driver implementation file for the ECCP1 driver using MPLAB® Code Configurator

  @Description
    This header file provides implementations for driver APIs for ECCP1.
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
#include "eccp1.h"

/**
  Section: COMPARE Module APIs
 */

void ECCP1_Initialize(void) {
    // Set the ECCP1 to the options selected in the User Interface

    // P1M single; CCP1M compare_softint; DC1B LSBs; 
    CCP1CON = 0x0A;

    // CCPR1L 0x0; 
    CCPR1L = 0x00;

    // CCPR1H 0x0; 
    CCPR1H = 0x00;

    // Enable the ECCP1 interrupt
    PIE1bits.CCP1IE = 1;

    // Selecting Timer3
    CCPTMRS0bits.C1TSEL = 0x1;
}

void ECCP1_SetCompareCount(uint16_t compareCount) {
    CCP_PERIOD_REG_T module;

    // Write the 16-bit compare value
    module.ccpr1_16Bit = compareCount;

    CCPR1L = module.ccpr1l;
    CCPR1H = module.ccpr1h;
}

void ECCP1_CompareISR(void) {
    // Clear the ECCP1 interrupt flag
    PIR1bits.CCP1IF = 0;
}
/**
 End of File
 */