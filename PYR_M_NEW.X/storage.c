#include "main.h"

/**
 * 
 * @param store         Data to be stored
 * @param store_address Address where the data should be stored
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
    NOP();
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

/**
 * Initial data retrievement from storage
 */
void Load_Data(void) {
    string_load[0] = 'L';
    string_load[1] = 'O';
    string_load[2] = 'A';
    
    Evaluate_Display(3, string_load);
    Delay_Routine(30);
    for(unsigned char counter = 0; counter < 30; counter++) {
        pin[counter].time = Read_Data(counter);
    }
    slave_selected = 0;
    pin_selected = 0;
    Set_Display('7', 'E', pin[pin_selected].slave);
    //Displays 'E' = Empfänger and selected receiver
    Delay_Routine(20);
    Set_Display('7', 'A', pin[pin_selected].output);
    Delay_Routine(20);
    Set_Display('7', '-', pin[pin_selected].time);
    Delay_Routine(20);
}

/**
 * Erasing data from the storage to get a fresh start at 0
 */
void Del_Data(void) {
    string_delete[0] = 'D';
    string_delete[1] = 'E';
    string_delete[2] = 'L';
    
    Evaluate_Display(3, string_delete);
    Delay_Routine(30);
    for(unsigned char counter = 0; counter < 30; counter++) {
        Save_Data(0, counter);
    }
    Load_Data();
    NOP();
}