#include "main.h"

void Transmit(unsigned char slave, unsigned char trans_data) {
    Transmit_En = 1;
    RCSTA1bits.CREN = 0;            // Disabled reception to counteract
                                    // interferences by a simultanious
                                    // reception while sending
    while(PIR1bits.TXIF == 0);
    TXSTA1bits.TX9D = 1;
    TXREG1 = slave;
    while(PIR1bits.TXIF == 0);
    TXREG1 = trans_data;
    while(TXSTA1bits.TRMT == 0);    // Verry important to be TRMT
                                    // This bit indicates an empty
                                    // Transmit register, not an
                                    // empty buffer
    Transmit_En = 0;
#ifdef COM_TEST
    RCSTA1bits.CREN = 0;
#endif
#ifndef COM_TEST
    RCSTA1bits.CREN = 1;
#endif
}


unsigned char Receive(void) {
    unsigned char received = 0;
    return (received);
}