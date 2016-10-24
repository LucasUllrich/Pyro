#include "main.h"


void Set_Bits(unsigned char *bits) {
    
}

void Evaluate_Display(unsigned char size, unsigned int *evaluate) {
    for(unsigned char counter = 0; counter < size; counter++)
    switch (evaluate[counter]) {
        case '0':
            Set_Bits();
            break;
        case '1':

            break;
        case '2':

            break;
        case '3':

            break;
        case '4':

            break;
        case '5':

            break;
        case '6':

            break;
        case '7':

            break;
        case '8':

            break;
        case '9':

            break;
        case 'E':
            
            break;
        case 'A':
            
            break;
    }
}

void Set_Display(unsigned char type, unsigned char information,
        unsigned int value) {
    switch (type) {
        case '7':
            unsigned char signs[3];
            if(information != '-') {
                
            }else {
                signs[0] = information;
                signs[1] = '-';
                signs[2] = value;
                Evaluate_Display(sizeof(signs), signs);
            }
            break;
        case 'L':
            
            break;
    }
}

void Display(void) {
    unsigned char write_reg = 0;
    unsigned char write_counter = 0;
    for(unsigned char pin_counter = 0; pin_counter < 
            ELEMENTS(pixels); pin_counter ++) {
        if(pixels[pin_counter] & 0x01) {
            write_reg |= 0x01;
        }
        write_reg >>= 1;
        write_counter ++;
        if(write_counter > 7) {
            Write_Display(write_reg);
            write_counter = 0;
            write_reg = 0;
        }
    }
}
