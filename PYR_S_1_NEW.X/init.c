#include <pic18f44k22.h>

#include "main.h"

void Init(void) {
    InitPort();
    InitTris();
    InitAnsel();
    InitMiscellaneous();
    InitTransmission();
    InitADC();
    InitVar();
    InitInterrupt();
}

void InitPort(void) {
    PORTA = 0b00000000;
    PORTB = 0b00000000;
    PORTC = 0b00000000;
    PORTD = 0b00000000;
    PORTE = 0b00000000;
}

void InitTris(void) {
    TRISA = 0b00010101;
    TRISB = 0b00010001;
    TRISC = 0b00010100;
    TRISD = 0b00000101;
    TRISE = 0b00000101;
}

void InitAnsel(void) {
    ANSELA = 0b00000000;
    ANSELB = 0b00000001;
    ANSELC = 0b00000000;
    ANSELD = 0b00000000;
    ANSELE = 0b00000000;
}

void InitMiscellaneous(void) {
    OSCCON = 0b01010011;    //4 MHz
}

void InitTransmission(void) {
//UART
    TXSTA1bits.SYNC = 0;
    TXSTA1bits.BRGH = 1;
    BAUDCON1bits.BRG16 = 0; //Baudrate 9600
    SPBRG1 = 25;
    TRISCbits.RC6 = 1;      //TX
    TRISCbits.RC7 = 1;      //RX
    RCSTA1bits.SPEN = 1;
    TXSTA1bits.TX9 = 1;
    TXSTA1bits.TXEN = 1;
    RCSTA1bits.RC9 = 1;
    RCSTA1bits.CREN = 1;
    TRISCbits.RC6 = 0;
}

void InitADC(void) {
    //FVR
    VREFCON0 =  0b10100000;     //Enabled, 2.048 V
    //DAC
    VREFCON1 =  0b10001000;     //DAC on; no output; FVR and VSS
    VREFCON2bits.DACR = 16;     //With 2.048 V ref. output == 1.024 V
    //ADC-Module
    ADCON1 =    0b00000000;     //FVR as positive supply
    ADCON2 =    0b00000011;     //Left justify, dedicated osc.
    ADCON0 =    0b01111001;     //DAC as source, ADC on
}

void InitTimer(void) {
    CCP1CON = 0b00001011;       // Compare, special event, ADC is
                                // unaffected sincs CCP1 is used
    CCPTMRS0bits.C1TSEL = 0b00;
    T1CON = 0b00110000;         // FOSC/4, 1:8
    CCPR1H = 0b00000111;        // 15 ms
    CCPR1L = 0b01010011;
}

void InitInterrupt(void) {
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.RCIE = 1;
    PIE1bits.CCP1IE = 1;
}

void InitVar(void) {
    for(unsigned char c = 0; c < 10; c++) {
        Marker[c] = 0;
    }
}
