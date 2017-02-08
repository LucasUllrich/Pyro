#include "main.h"
#include "interrupt.h"
/**
 * The different transmission and reception routines are written in
 * this file.
 * One routine for transmission with 2 transmitted bytes, one for the
 *  selected slave and one for the actual data.
 * 
 * One routine for the reception, receiving only one byte and the
 *  possibillity to react on an overrun.
 * @param slave         contains the address of the recepient
 * @param trans_data0   
 * @param trans_data1
 */
void Transmit(unsigned char receiver, unsigned char operation, 
        unsigned char port) {
    Transmit_En = 1;             //Enable RS485 module
    RCSTA1bits.CREN = 0;         //Disable receive to counteract
                                 //wrong receptions (RCIF)
    NOP();                       //Debugging
    while(PIR1bits.TXIF == 0);   //Checking for a clear TXREG
    TXSTA1bits.TX9D = 1;         //9th-Bit transmitted as 1 -> Address
    TXREG1 = receiver;              //Transmitting slave address
    while(PIR1bits.TXIF == 0);   //Checking for a clear TXREG
    TXREG1 = TRANSMITTER;        //Transmitting actual data
    while(PIR1bits.TXIF == 0);   //Checking for a clear TXREG    
    TXREG1 = operation;          //Transmitting actual data
    while(PIR1bits.TXIF == 0);   //Checking for a clear TXREG    
    TXREG1 = port;               //Transmitting actual data
    while(TXSTA1bits.TRMT == 0); //Checking for a clear TSR    
    Transmit_En = 0;             //Disable RS485 module for transmission
    RCSTA1bits.CREN = 1;         //Enabling receiver again
    NOP();                       //Debugging
}


unsigned char Receive(void) {
    if(RCSTA1bits.OERR == 1) {  //Overrun-Error! Restart
        RCSTA1bits.CREN = 0;
        RCSTA1bits.CREN = 1;
        overrun = 1;            //Setting a status bit to react
    }
    return (RCREG1);
}

void Receive_Dump(void) {
    unsigned char dump;
    if(RCSTA1bits.OERR == 1) {  //Overrun-Error! Restart
        RCSTA1bits.CREN = 0;
        RCSTA1bits.CREN = 1;
        overrun = 1;            //Setting a status bit to react
    }
    dump = RCREG1;
}

void Write_Display_Byte(unsigned char *write_data) {
    for(unsigned char counter = sizeof(pixels); counter > 0;
            counter--) {
        if(SSP1IF = 1) {
            SSP1IF = 0;
        }
        SSP1BUF = write_data[counter - 1];
//        while (SSP1IF == 0);      !!!!!!!!!!!!!!!!!!!!!!!!!!!!! remove comment when not in sim
        SSP1IF = 0;
        Show_Write = 0;
        Show_Write = 1;
        Show_Write = 0;
    }
}
