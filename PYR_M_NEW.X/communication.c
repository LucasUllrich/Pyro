#include "main.h"

void Transmit(unsigned char slave, unsigned char trans_data) {
    Transmit_En = 1;
    while(PIR1bits.TXIF == 0);
    TXSTA1bits.TX9D = 1;
    TXREG1 = slave;
    while(PIR1bits.TXIF == 0);
    TXREG1 = trans_data;
    while(PIR1bits.TXIF == 0);
    Transmit_En = 0;
}


unsigned char Receive(void) {
    unsigned char received = 0;
    return (received);
}