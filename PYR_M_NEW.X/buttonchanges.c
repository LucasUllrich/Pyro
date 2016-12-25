#include "main.h"


/**
 * 6 Buttons are available to press
 *  - Ignite    -> Starts the timer and ignition of the detonators
 *  - Slave_Up  -> Increases the currently selected slave, 3 available
 *  - Port_Up   -> Increases the currently selected port, 10 available
 *  - Time_Up   -> Increases the time for the selected port on the
 *                  selected slave
 *  - Time_Down -> Decreases the time for the selected port on the
 *                  selected slave
 *  - Time_Upup -> Increases the time for the selected port on the
 *                  selected slave by 10
 * 
 * Functions accessed by combinations
 *  - Connection-test
 *      Port_Up + Slave_Up
 *      -> Tests if a connection to the detonators is available and
 *          displays the result on the LED matrix
 *  - Clear Storage
 *      TimeUp + TimeDown
 *      -> Clears the whole EEPROM register by wirting 0 to all
 *          accessed addresses
 */
void Check_Buttons(void) {
    if(Ignite == 1) {
        Delay_Routine(3);
        if(Ignite == 1) {
            ignite_ready = 1;
            NOP();
            return;             //End of Subroutine! No further actions
                                // need to be possible and ignition is
                                // prioritized
        }
    } else if(Time_Up == 1) {
        Delay_Routine(3);
        if(Time_Up == 1) {
            if(Time_Down == 1) {
                Delay_Routine(3);
                if(Time_Down == 1) {
                    Del_Data();
                    return;             // End of function due to other
                                        // desired operation
                }
            }
            pin[pin_selected].time++;
            if(pin[pin_selected].time > 999) {
                pin[pin_selected].time = 0;
            }
            NOP();
            Set_Display('7', '-', pin[pin_selected].time);
            NOP();
        }
    } else if(Time_Down == 1) {
        Delay_Routine(3);
        if(Time_Down == 1) {
            if(Time_Up == 1) {
                Delay_Routine(3);
                if(Time_Up == 1) {
                    Del_Data();
                    return;             // End of function due to other
                                        // desired operation
                }
            }
            pin[pin_selected].time--;
            if(pin[pin_selected].time < 0) {
                pin[pin_selected].time = 999;
            }
            NOP();
            Set_Display('7', '-', pin[pin_selected].time);
            NOP();
        }
    } else if(Time_Upup == 1) {
        Delay_Routine(3);
        if(Time_Upup == 1) {
            pin[pin_selected].time += 10;
            if(pin[pin_selected].time > 999) {
                pin[pin_selected].time = 0;
            }
            NOP();
            Set_Display('7', '-', pin[pin_selected].time);
            NOP();
        }
    } else if(Port_Up == 1) {
        Delay_Routine(3);
        if(Port_Up == 1) {
            if(Slave_Up == 1) {
                Delay_Routine(3);
                if(Slave_Up == 1) {
                    testflag = 1;
                    return;             // End of function due to other
                                        // desired operation
                }
            }
            Save_Data(pin[pin_selected].time, pin[pin_selected].address);
            pin_selected++;
            switch (slave_selected) {
                case 0:
                    if(pin_selected > 9) {
                        pin_selected = 0;
                    }
                    break;
                case 1:
                    if(pin_selected > 19) {
                        pin_selected = 10;
                    }
                    break;
                case 2:
                    if(pin_selected > 29) {
                        pin_selected = 20;
                    }
                    break;
            }
            pin[pin_selected].time = Read_Data(pin[pin_selected].address);
            NOP();
            Set_Display('7', 'A', pin[pin_selected].output);
            Delay_Routine(30);
            Set_Display('7', '-', pin[pin_selected].time);
            Delay_Routine(30);
            NOP();
        }
    } else if(Slave_Up == 1) {
        Delay_Routine(3);
        if(Slave_Up == 1) {
            if(Port_Up == 1) {
                Delay_Routine(3);
                if(Port_Up == 1) {
                    testflag = 1;
                    return;             // End of function due to other
                                        // desired operation
                }
            }
            Save_Data(pin[pin_selected].time, pin[pin_selected].address);
            slave_selected++;
            if(slave_selected > 2) {
                slave_selected = 0;
            }
            pin_selected = slave_selected * 10;
            pin[pin_selected].time = Read_Data(pin[pin_selected].address);
            NOP();
            Set_Display('7', 'E', pin[pin_selected].slave);
            //Displays 'E' = Empfänger and selected receiver
            Delay_Routine(30);
            Set_Display('7', 'A', pin[pin_selected].output);
            Delay_Routine(30);
            Set_Display('7', '-', pin[pin_selected].time);
            Delay_Routine(30);
            NOP();
        }
    }
}