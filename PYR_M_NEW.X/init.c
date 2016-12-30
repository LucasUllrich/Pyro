#include "main.h"

void Init(void) {
    InitPort();
    InitTris();
    InitAnsel();
    InitMiscellaneous();
    InitTransmission();
    InitTimer();
    InitInterrupt();
}

void InitPort(void) {
    PORTA = 0b00000000;
    PORTB = 0b00000000;
    PORTC = 0b00000001;
    PORTE = 0;
}

void InitTris(void) {
    TRISA = 0b00000000;
    TRISB = 0b00011111;
    TRISC = 0b10000010;
    TRISE = 0;
}

void InitAnsel(void) {
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
}

void InitMiscellaneous(void) {
    OSCCON = 0b01010011;    //4 MHz
}

void InitTransmission(void) {
//SPI
    SSP1STAT = 0b01000000;
    SSP1CON1 = 0b00100010;
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

void InitTimer(void) {
//TMR1
    T1CONbits.TMR1CS = 0b00;    //FOSC/4 as source
    T1CONbits.T1CKPS = 0b11;    //Prescaler 1:8
    T1CONbits.nT1SYNC = 0;      //Synchron
//TMR3
    T3CONbits.TMR3CS = 0b00;    //FOSC/4 as source
    T3CONbits.T3CKPS = 0b11;    //Prescaler 1:8
    T3CONbits.nT3SYNC = 0;      //Synchron
//Comp1
    CCP1CONbits.CCP1M = 0b1011; //Software interrupt, special event
                                    // -> TMR3 cleared
    CCPTMRS0bits.C1TSEL = 0b01; //TMR3 as source
    CCPR1L = 72;                //Setting values for second timing
    CCPR1H = 232;                   //period
}

void InitInterrupt(void) {
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.RCIE = 1;
    PIE1bits.CCP1IE = 1;
    PIE1bits.TMR1IE = 1;
}