#include "main.h"
#include "interrupt.h"

void interrupt Isr(void) {
    if(PIR1bits.CCP1IF == 1) {
        // TMR3 is NOT reset by special event of the CCP unit
        PIR1bits.CCP1IF = 0;
        T1CONbits.TMR1ON = 1;
        T3CONbits.TMR3ON = 0;
        TMR3L = 0;
        TMR3H = 0;
        current_time++;
        Ignite_Detonators();
    }if(PIR1bits.TMR1IF == 1) {
        PIR1bits.TMR1IF = 0;
        T3CONbits.TMR3ON = 1;
        T1CONbits.TMR1ON = 0;
        TMR1L = 0;
        TMR1H = 0;
    }
    if(PIR1bits.RCIF == 1) {
        PIR1bits.RCIF = 0;
        if(RCSTAbits.RX9D == 1) {
            receive_counter = 0;
            received[receive_counter] = Receive();
            receive_counter++;
            if(received[0] == 0xAA) {
                master_addressed = 1;
            } else {
                master_addressed = 0;
            }
        } else if(master_addressed == 1) {
            received[receive_counter] = Receive();
            receive_counter++;
            if(receive_counter > 4) {
                receive_counter = 0;
                master_addressed = 0;
                if(received[2] == 'T') {
                    unsigned char search_index = 0xFF;
                    unsigned char pixel_index_array = 0;
                    unsigned char pixel_index_bit = 0;
                    search_index = (received[1] * 10);  
                            // To address the slave
                    search_index += received[3];        
                            // To address the port
                    pixel_index_array = 
                            pin[search_index].led_address / 8;
                    pixel_index_bit = 
                            pin[search_index].led_address % 8;
                    if(received[4] == 1){
                        pixels[pixel_index_array] |= 
                                (1 << pixel_index_bit);
                    }else if(received[4] == 0) {
                        pixels[pixel_index_array] &= 
                                ~(1 << pixel_index_bit);
                    }
                }
            }
        }
        NOP();
        if(check_counter < 30 && testflag == 1) {
            check_counter++;
            Check_Detonators();
        }else {
            check_counter = 0;
            testflag = 0;
        }
//        if(received == '1' || received == 'L') {
//            Led = 1;
//        }else {
//            Led = 0;
//        }
    }
}
