#include "main.h"

void Transmit(unsigned char slave, unsigned char trans_data) {
    while(PIR1bits.TXIF == 0);
    TXSTA1bits.TX9D = 1;
    TXREG1 = slave;
    while(PIR1bits.TXIF == 0);
    TXREG1 = trans_data;
}


unsigned char Receive(void) {
    unsigned char received = 0;
    return (received);
}