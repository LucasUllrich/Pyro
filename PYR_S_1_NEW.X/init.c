#include "main.h"

void Init(void) {
    InitPort();
    InitTris();
    InitAnsel();
    InitMiscellaneous();
    InitTransmission();
    InitInterrupt();
    InitMiscellaneos();
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
    VREFCON0bits.FVREN = 1;
    VREFCON0bits.FVRS = 0b10;   //10 = 2,048V; 01 = 1,024V; 11 = 4,096V
    //ADC-Module
    ADCON0 = 0b00110001;    //AN12 as source, ADC on
    ADCON1 = 0b00001000;    //FVR as positive supply
    ADCON2 = 0b00000011;    //Left justify, dedicated osc.
}

void InitInterrupt(void) {
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.RCIE = 1;
    PIR1bits.RCIF= 0;
}

void InitMiscellaneos(void) {
    for(unsigned char c = 0; c < 10; c++) {
        Marker[c] = 0;
    }
}