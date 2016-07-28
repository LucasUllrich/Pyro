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
void Timer_Count(void) {
    TMR1L = 0;
    TMR1H = 0;
    PIR1bits.TMR1IF = 0;
    T1CONbits.TMR1ON = 1;           //Starting first period
    CCPR1L = 72;                    //Setting values for second timing
    CCPR1H = 232;                       //period
    while(PIR1bits.TMR1IF == 0);    //Polling till TMR1 runs over
    T3CONbits.TMR3ON = 1;
    T1CONbits.TMR1ON = 0;
    /* 1 s is now signaled by an interrupt of the compare unit! */
}