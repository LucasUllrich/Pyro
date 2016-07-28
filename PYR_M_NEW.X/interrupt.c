#include "main.h"

void interrupt Isr(void) {
    if(PIR1bits.RCIF == 1) {
        PIR1bits.RCIF = 0;
        unsigned char received = 0;
        received = Receive();
        NOP();
        if(received == '1' || received == 'L') {
            Led = 1;
        }else {
            Led = 0;
        }
    }if(PIR1bits.CCP1IF == 1) {
        PIR1bits.CCP1IF = 0;
        current_time++;
    }
}
