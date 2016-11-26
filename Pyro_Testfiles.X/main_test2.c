/*
 * File:   main_test2.c
 * Author: Lucas
 *
 * Created on 26. November 2016, 22:56
 */


#include <xc.h>



void main(void) {
        while(1) {
        unsigned char test[3];
        unsigned char size = sizeof(test);
        test[--size] = 'a';
        unsigned char var = test[2];
        NOP();
    }
}
