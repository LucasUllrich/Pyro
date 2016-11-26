#include "main.h"

/**
 * 
 * @param store
 * @param store_address
 */
void Save_Data(unsigned int store, 
            unsigned char store_address) {
    EEADR = store_address;  //Storing lower 8 bits
    EEDATA = store;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    INTCONbits.GIE = 0;
    EECON1bits.WREN = 1;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    while(PIR2bits.EEIF == 0);
    PIR2bits.EEIF = 0;
    store >>= 8;            //Preparing to store upper 8 bits
    store_address += 50;
    EEADR = store_address;
    EEDATA = store;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.WREN = 1;
    INTCONbits.GIE = 0;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    while(PIR2bits.EEIF == 0);
    PIR2bits.EEIF = 0;
    EECON1bits.WREN = 0;
    INTCONbits.GIE = 1;
}


/**
 * 
 * @param read_address
 * @return 
 */
unsigned int Read_Data(unsigned char read_address) {
    unsigned int data_read = 0;
    read_address += 50;
    EEADR = read_address;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.RD = 1;
    data_read = EEDATA;
    read_address -= 50;
    data_read <<= 8;
    EEADR = read_address;
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.RD = 1;
    data_read |= EEDATA;
    return data_read;
}
