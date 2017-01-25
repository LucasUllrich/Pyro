#include "main.h"

/**
 * 
 * @param receiver      Who should receive the message
 *          0xAA == Master
 *          0x00 == Slave 0
 *          0x01 == Slave 1
 *          0x02 == Slave 2
 * @param operation     Which operation was performed
 *          'T' == Connection-test
 *          'I' == Ignition
 * @param port          The port on which the operation is performed
 * @param status        The status of the port
 *          0   == No connection
 *          1   == Connection
 */
void Transmit(unsigned char receiver, unsigned char operation, 
        unsigned char port, unsigned char con_status) {
    Transmit_En = 1;             //Enable RS485 module
    RCSTA1bits.CREN = 0;         //Disable receive to counteract
                                 //wrong receptions (RCIF)
    NOP();                       //Debugging
    while(PIR1bits.TXIF == 0);   //Checking for a clear TXREG
    TXSTA1bits.TX9D = 1;         //9th-Bit transmitted as 1 -> Address
    TXREG1 = receiver;           //Transmitting slave address
    while(PIR1bits.TXIF == 0);   //Checking for a clear TXREG
    TXREG1 = TRANSMITTER;        //Transmitting actual data
    while(PIR1bits.TXIF == 0);   //Checking for a clear TXREG    
    TXREG1 = operation;          //Transmitting actual data
    while(PIR1bits.TXIF == 0);   //Checking for a clear TXREG    
    TXREG1 = port;               //Transmitting actual data
    while(PIR1bits.TXIF == 0);   //Checking for a clear TXREG    
    TXREG1 = con_status;         //Transmitting actual data
    while(PIR1bits.TXIF == 0);   //Checking for a clear TXREG    
    TXREG1 = p_status;           //Transmitting actual data
    while(TXSTA1bits.TRMT == 0); //Checking for a clear TSR    
    Transmit_En = 0;             //Disable RS485 module for transmission
    RCSTA1bits.CREN = 1;         //Enabling receiver again
    NOP();                       //Debugging
}


unsigned char Receive(void) {
    if(RCSTA1bits.OERR == 1) {     //Overrun-Error! Restart
        RCSTA1bits.CREN = 0;
        RCSTA1bits.CREN = 1;
        overrun = 1;
    }
    return (RCREG1);
}
