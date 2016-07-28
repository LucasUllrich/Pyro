#include "main.h"

void interrupt Isr(void) {
    unsigned char received = 0;
    if(PIR1bits.RCIF == 1) {
        PIR1bits.RCIF = 0;
    received = Receive();
        if(RCSTA1bits.RX9D == 1) {
            addressed = 1;
            if(Receive() != ADDRESS) {
                addressed = 0;
            }
        }else if(RCSTA1bits.RX9D != 1 && addressed == 1) {
            Led ^= 1;
        }
    }
}
