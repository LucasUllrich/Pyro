#include "main.h"

void Transmit(unsigned char trans_data) {
    
}


unsigned char Receive(void) {
    if(RCSTA1bits.OERR == 1) {     //Overrun-Error! Restart
        RCSTA1bits.CREN = 0;
        RCSTA1bits.CREN = 1;
        overrun = 1;
    }
    return (RCREG1);
}