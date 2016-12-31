#include "main.h"

/**
 * This timer works with two periods to reach a timing of 1 s with a
 * system clock of 4MHz.
 * The first period is accomplisched by the TMR1 and its overflow
 *  (2^16)
 * The second period by the remaining rest to 125.000 clockimpulses
 *  which is equivalent to a timer of 1 s is accomplisched by the
 *  Compare mode of the PWM unit and TMR3.
 */
void Start_Timer(void) {
    if(ignite_ready == 1) {
        TMR1L = 0;
        TMR1H = 0;
        TMR3L = 0;
        TMR3H = 0;
        PIR1bits.TMR1IF = 0;
        PIR2bits.TMR3IF = 0;
        T1CONbits.TMR1ON = 1;           //Starting first period
        /* 1 s is now signaled by an interrupt of the compare unit! */
    }
}

void Check_Detonators(void) {
    Transmit(pin[check_counter].slave, 'T', pin[check_counter].output);
}

void Ignite_Detonators(void) {
    for(unsigned char counter = 0; counter < 30; counter++) {
        if(pin[counter].time == current_time) {
            Transmit(pin[counter].slave, 'I', pin[counter].output);
        }
    }
}