#include "main.h"

void Test_Port(void) {
    switch(received[PORT]) {
        case 0:
            if(Probe_0 == 1) {
                Transmit(0xAA, 'T', 0, 1);
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 0, 0);
            }
            break;
        case 1:
            if(Probe_0 == 1) {
                Transmit(0xAA, 'T', 1, 1);
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 1, 0);
            }
            break;
        case 2:
            if(Probe_0 == 1) {
                Transmit(0xAA, 'T', 2, 1);
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 2, 0);
            }
            break;
        case 3:
            if(Probe_0 == 1) {
                Transmit(0xAA, 'T', 3, 1);
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 3, 0);
            }
            break;
        case 4:
            if(Probe_0 == 1) {
                Transmit(0xAA, 'T', 4, 1);
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 4, 0);
            }
            break;
        case 5:
            if(Probe_0 == 1) {
                Transmit(0xAA, 'T', 5, 1);
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 5, 0);
            }
            break;
        case 6:
            if(Probe_0 == 1) {
                Transmit(0xAA, 'T', 6, 1);
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 6, 0);
            }
            break;
        case 7:
            if(Probe_0 == 1) {
                Transmit(0xAA, 'T', 7, 1);
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 7, 0);
            }
            break;
        case 8:
            if(Probe_0 == 1) {
                Transmit(0xAA, 'T', 8, 1);
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 8, 0);
            }
            break;
        case 9:
            if(Probe_0 == 1) {
                Transmit(0xAA, 'T', 9, 1);
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 9, 0);
            }
            break;
    }
}

void Ignite_Port(void) {
    
}

void Evaluate_Reception(void) {
    /**
     * Second and third byte are interesting
     *  2nd: Operation T || I
     *  3rd: Port 0 to 9
     */
    if(received[OPERATION] == 'T') {
        Test_Port();
    }else if(received[OPERATION] == 'I') {
        Ignite_Port();
    }
    
}