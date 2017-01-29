#include <pic18f44k22.h>

#include "main.h"

void Test_Port(void) {
    switch(received[PORT]) {
        case 0:
            if(Probe_0 == 1) {
                Transmit(0xAA, 'T', 0, '1');
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 0, '0');
            }
            break;
        case 1:
            if(Probe_1 == 1) {
                Transmit(0xAA, 'T', 1, '1');
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 1, '0');
            }
            break;
        case 2:
            if(Probe_2 == 1) {
                Transmit(0xAA, 'T', 2, '1');
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 2, '0');
            }
            break;
        case 3:
            if(Probe_3 == 1) {
                Transmit(0xAA, 'T', 3, '1');
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 3, '0');
            }
            break;
        case 4:
            if(Probe_4 == 1) {
                Transmit(0xAA, 'T', 4, '1');
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 4, '0');
            }
            break;
        case 5:
            if(Probe_5 == 1) {
                Transmit(0xAA, 'T', 5, '1');
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 5, '0');
            }
            break;
        case 6:
            if(Probe_6 == 1) {
                Transmit(0xAA, 'T', 6, '1');
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 6, '0');
            }
            break;
        case 7:
            if(Probe_7 == 1) {
                Transmit(0xAA, 'T', 7, '1');
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 7, '0');
            }
            break;
        case 8:
            if(Probe_8 == 1) {
                Transmit(0xAA, 'T', 8, '1');
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 8, '0');
            }
            break;
        case 9:
            if(Probe_9 == 1) {
                Transmit(0xAA, 'T', 9, '1');
            }else if(Probe_0 == 0) {
                Transmit(0xAA, 'T', 9, '0');
            }
            break;
    }
}

void Ignite_Port(unsigned char ignite_number) {
    switch(Marker[ignite_number]) {
        case 0:
            Nr_0 = 1;
            break;
        case 1:
            Nr_1 = 1;
            break;
        case 2:
            Nr_2 = 1;
            break;
        case 3:
            Nr_3 = 1;
            break;
        case 4:
            Nr_4 = 1;
            break;
        case 5:
            Nr_5 = 1;
            break;
        case 6:
            Nr_6 = 1;
            break;
        case 7:
            Nr_7 = 1;
            break;
        case 8:
            Nr_8 = 1;
            break;
        case 9:
            Nr_9 = 1;
            break;
    }
}

void Check_Ignition(void) {
    for(unsigned char c = 0; c < 10; c++) {
        if(Marker[c] == 1) {
            Ignite_Port(c);
            __delay_ms(15);
            Marker[c] = 0;
        }
    }
}

void Mark_Ignite(void) {
    Marker[received[PORT]] = 1;
}

void Check_Power(void) {
    // U = Upart * R / Rpart
    // U = Upart * 22 / 6.8
    // Upart = U_FVR * ADRESH / 255
    float source_power = 0;
    float voltage = 0;
    float DAC_out = 1.024;
    float supply = 0;
    //*******DAC-Module
    ADCON0bits.CHS = 0b11110;
    ADCON0bits.GO_nDONE = 1;
    while (ADCON0bits.GO_nDONE == 1);
    supply = ((DAC_out * 255) / ADRESH);
    
    //*******AN12
    ADCON0bits.CHS = 0b01100;
    ADCON0bits.GO_nDONE = 1;
    while (ADCON0bits.GO_nDONE == 1);
    voltage = ((ADRESH * supply) / 255);
    source_power = (4.2353 * voltage);
    
    if (source_power < MIN_VOLTAGE) {
        p_status = '0';
    } else if (source_power >= MIN_VOLTAGE) {
        p_status = '1';
    }
}

void Evaluate_Reception(void) {
    /**
     * Second and third byte are interesting
     *  2nd: Operation T || I
     *  3rd: Port 0 to 9
     */
    if (received[OPERATION] == 'T') {
        Check_Power();
        Test_Port();
    } else if (received[OPERATION] == 'I') {
        Mark_Ignite();
    }
}