/*
 * File:   main_test1.c
 * Author: Lucas
 *
 * Created on 26. November 2016, 21:13
 */


#include <xc.h>

void function(const unsigned char *pointer) {
    unsigned char var;
    for(unsigned char counter = 0; counter < 5; counter++) {
        var = pointer[counter];
        NOP();
    }
    var = 1;
    NOP();
    var = '\0';
    NOP();
}

void main(void) {
    unsigned char test[3];
    test[0] = '1';
    test[1] = '2';
    test[2] = '3';
    function(test);
    return;
}
