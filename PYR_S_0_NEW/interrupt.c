#include "main.h"

void interrupt Isr(void) {
    NOP();
    if(PIR1bits.RCIF == 1) {
        if(RCSTA1bits.RX9D == 1) {
            NOP();
            #ifdef DEBUG
            for(unsigned char c = 0; c < sizeof(received); c++) {
                received[c] = 0xff;
            }
            #endif
            receive_counter = 0;        // restart counting of reception
                                        // bytes
            received[receive_counter] = // store the received data in
                    Receive();          // the corresponding array
            receive_counter++;          // address next position in
                                        // array for the upcoming data
            if(received[0] == ADDRESS) {// the device is addressed
                slave_addressed = 1;    // set flag bit to acknowledge
            } else {
                slave_addressed = 0;    // clear flag bit
            }
        } else if(slave_addressed == 1) {
            NOP();
            received[receive_counter] = // Receive further data to
                    Receive();          // process
            receive_counter++;          // address next position in 
                                        // array for the upcoming data
            if(receive_counter > 3) {   // end of data string reached
                receive_counter = 0;    // clear counter
                slave_addressed = 0;    // terminate addressing of
                                        // device
                Evaluate_Reception();
            }
        } else {
            NOP();
            Receive_Dump();
        }
    }
    if (PIR1bits.CCP1IF == 1) {
        PIR1bits.CCP1IF = 0;
        T1CONbits.TMR1ON = 0;
        TMR1H = 0;
        TMR1L = 0;
        for (unsigned char c = 0; c < 10; c++) {
            Marker[c] = 0;
        }
    }
}
