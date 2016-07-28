#include "main.h"
/**
 * The different transmission and reception routines are written in
 * this file.
 * One routine for transmission with 2 transmitted bytes, one for the
 *  selected slave and one for the actual data.
 * 
 * One routine for the reception, receiving only one byte and the
 *  possibillity to react on an overrun.
 * @param slave
 * @param trans_data
 */


void Transmit(unsigned char slave, unsigned char trans_data) {
    Transmit_En = 1;            //Enable RS485 module
    RCSTA1bits.CREN = 0;        //Disable receive to counteract
                                //wrong receptions (RCIF)
    NOP();                      //Debugging
    while(PIR1bits.TXIF == 0);  //Checking for a clear TXREG
    TXSTA1bits.TX9D = 1;        //9-Bit transmission enabled
    TXREG1 = slave;             //Transmitting slave address
    while(PIR1bits.TXIF == 0);  //Checking for a clear TXREG
    TXREG1 = trans_data;        //Transmitting actual data
    while(PIR1bits.TXIF == 0);  //Checking for a clear TXREG
    Transmit_En = 0;            //Disable RS485 module for transmission
    RCSTA1bits.CREN = 1;        //Enabling receiver again
    NOP();                      //Debugging
}


unsigned char Receive(void) {
    if(RCSTA1bits.OERR == 1) {  //Overrun-Error! Restart
        RCSTA1bits.CREN = 0;
        RCSTA1bits.CREN = 1;
        overrun = 1;            //Setting a status bit to react
    }
#ifdef COM_TEST
    else {
        overrun = 0;
    }
#endif
    return (RCREG1);
}