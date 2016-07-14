#include "main.h"

void interrupt Isr(void) {
    if(PIR1bits.RCIF == 1) {
        PIR1bits.RCIF = 0;
        unsigned char received = 0;
        received = Receive();
        if(received == 1 || received == 'L') {
            Led = 1;
        }
    }
}
