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
    }
    if(PIR1bits.TMR1IF == 1) {
        PIR1bits.TMR1IF = 0;
        T3CONbits.TMR3ON = 1;
        T1CONbits.TMR1ON = 0;
        TMR1L = 0;
        TMR1H = 0;
    }
    if(PIR1bits.RCIF == 1) {            // detecting reception over UART
        NOP();
        if(RCSTAbits.RX9D == 1) {       // an address is sent
            receive_counter = 0;        // restart counting of reception
                                        // bytes
            received[receive_counter] = // store the received data in
                    Receive();          // the corresponding array
            receive_counter++;          // address next position in 
                                        // array for the upcoming data
            if(received[0] == ADDRESS) {// the device is addressed
                master_addressed = 1;   // set flag bit to acknowledge
            } else {
                master_addressed = 0;   // clear flag bit
            }
        } else if(master_addressed == 1) {
            received[receive_counter] = // Receive further data to
                    Receive();          // process
            receive_counter++;          // address next position in 
                                        // array for the upcoming data
            if(receive_counter > 5) {   // end of data string reached
                receive_counter = 0;    // clear counter
                master_addressed = 0;   // terminate addressing of
                                        // device
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
                    NOP();
                    pixel_index_bit = 
                            pin[search_index].led_address % 8;
                    NOP();
                    if(received[4] == '1'){
                        pixels[pixel_index_array] |= 
                                (1 << pixel_index_bit);
                    }else if(received[4] == '0') {
                        pixels[pixel_index_array] &= 
                                ~(1 << pixel_index_bit);
                    }
#ifdef CHECK_POWER
                    if(received[5] == '0') {
                        Set_Display('7', 'P', received[1]);
                        Delay_Routine(10);
                        Set_Display('7', 'T',0);
                    }
#endif
                    NOP();
                    if(check_counter < 30 && testflag == 1) {
                        check_counter++;
                        Check_Detonators();
                        if(check_counter > 29) {
                            Set_Display('7', 'T',0);
                            check_counter = 0;
                            testflag = 0;
                        }
                    }else {
                        check_counter = 0;
                        testflag = 0;
                    }
                }
            }
        } else {
            Receive_Dump();
        }
    }
}
