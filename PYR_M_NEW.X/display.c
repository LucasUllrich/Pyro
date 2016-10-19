#include "main.h"

void Evaluate_Display(unsigned int evaluate) {
    
}

void Set_Display(unsigned char type, unsigned char target,
        unsigned char set_pixels) {
    switch (type) {
        case 'S':
            
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
