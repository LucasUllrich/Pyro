#include "main.h"
#include "interrupt.h"

void interrupt Isr(void) {
    if(PIR1bits.RCIF == 1) {
        PIR1bits.RCIF = 0;
        if(RCSTAbits.RX9D == 1) {
            receive_counter = 0;
            if(received[0] == 0xFF) {       /////Needs fixing, position wrong
                master_addressed = 1;
            }
        }
        if(master_addressed == 1) {
            received[receive_counter] = Receive();
            receive_counter++;
            if(receive_counter > 3) {
                receive_counter = 0;
                master_addressed = 0;
                if(received[2] == 'T') {
                    unsigned char search_index = 0xFF;
                    unsigned char pixel_index_array = 0;
                    unsigned char pixel_index_bit = 0;
                    search_index = (received[1] * 10);
                    search_index += received[3];
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
//        if(received == '1' || received == 'L') {
//            Led = 1;
//        }else {
//            Led = 0;
//        }
    }if(PIR1bits.CCP1IF == 1) {
        PIR1bits.CCP1IF = 0;
        current_time++;
    }
}
