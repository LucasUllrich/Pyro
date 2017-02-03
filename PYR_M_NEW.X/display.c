#include "main.h"




/**
 * Sets the beforehand evaluated bits and finishes a byte for the
 *  output
 * @param bits      pointer to the string which helds information about
 *                      the bits that need to be set
 */
void Set_Bits(const unsigned char *bits) {
    unsigned char Bitoutput = 0;
    for(unsigned char bitcount = 0; bits[bitcount] != '\0';
            bitcount++) {
        switch (bits[bitcount]) {
            case 'A':
                Bitoutput |= 0b00000001;
                break;
            case 'B':
                Bitoutput |= 0b00000010;
                break;
            case 'C':
                Bitoutput |= 0b00000100;
                break;
            case 'D':
                Bitoutput |= 0b00001000;
                break;
            case 'E':
                Bitoutput |= 0b00010000;
                break;
            case 'F':
                Bitoutput |= 0b00100000;
                break;
            case 'G':
                Bitoutput |= 0b01000000;
                break;
            default:
                break;
        }
    }
    pixels[display_counter] = Bitoutput;
}


/**
 * Receives information about the number of segments and the value
 *  which should be display on those.
 * @param size      number of segments (7-segment)
 * @param evaluate  Value that should be displayed as pointer on array
 */
void Evaluate_Display(unsigned char size, const unsigned char *evaluate) {
    for(display_counter = (size + 1); display_counter > 0;
            display_counter--) {
        NOP();
        switch (evaluate[(display_counter - 1)]) {
            case '0':
                Set_Bits("ABCDEF");
                break;
            case '1':
                Set_Bits("BC");
                break;
            case '2':
                Set_Bits("ABDEG");
                break;
            case '3':
                Set_Bits("ABCDG");
                break;
            case '4':
                Set_Bits("BCFG");
                break;
            case '5':
                Set_Bits("ACDFG");
                break;
            case '6':
                Set_Bits("ACDEFG");
                break;
            case '7':
                Set_Bits("ABC");
                break;
            case '8':
                Set_Bits("ABCDEFG");
                break;
            case '9':
                Set_Bits("ABCDFG");
                break;
            case 'A':
                Set_Bits("ABCEFG");
                break;
            case 'D':
                Set_Bits("ABCDEF");
                break;
            case 'E':
                Set_Bits("ADEFG");
                break;
            case 'L':
                Set_Bits("DEF");
                break;
            case 'O':
                Set_Bits("ABCDEF");
                break;
            case 'P':
                Set_Bits("ABEFG");
                break;
            case '-':
                Set_Bits("G");
                break;
            default:
                Set_Bits(0);
        }
    }
}


/**
 * Evaluates the multi digit value that should be displayed
 * @param evaluation_value  Tha value that should be evaluated
 */
void Evaluate_Signs(unsigned int evaluation_value) {
    for(unsigned char valuecounter = 0; valuecounter < sizeof(signs);
            valuecounter++) {
       signs[valuecounter] = evaluation_value % 10;
       signs[valuecounter] += 0x30;
       evaluation_value >>= 1;
    }
    NOP();
    Evaluate_Display(sizeof(signs), signs);
}

/**
 * Checks if 7-segment elements or LED's are addressed and forwards the
 *  data
 * @param type          7-segment or LED's
 * @param information   the information that should be displayed
 *                          if it equals '-' only the value should be
 *                          displayed
 * @param value         the value that should be displayed
 */
void Set_Display(unsigned char type, unsigned char information,
        unsigned int value) {
    switch (type) {
        case '7':       //The 7-segment displays should be addressed
            if(information != '-') {
                signs[0] = value;
                signs[0] += 0x30;
                signs[1] = '-';
                signs[2] = information;
                Evaluate_Display(sizeof(signs), signs);
            } else {
                Evaluate_Signs(value);
            }
            break;
        case 'L':
            
            break;
    }
    Write_Display_Byte(pixels);
}


/*
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
 * */
