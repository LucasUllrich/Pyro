#include "main.h"

void Check_Buttons(void) {
    if(Ignite == 1) {
        Delay_Routine(3);
        if(Ignite == 1) {
            ignite_ready = 1;
            return;             //End of Subroutine! No further actions
                                // need to be possible and ignition is
                                // prioritized
        }
    } else if(Time_Up == 1) {
        Delay_Routine(3);
        if(Time_Up == 1) {
            pin[pin_selected].time++;
            if(pin[pin_selected].time > 999) {
                pin[pin_selected].time = 0;
            }
        }
    } else if(Time_Down == 1) {
        Delay_Routine(3);
        if(Time_Down == 1) {
            pin[pin_selected].time--;
            if(pin[pin_selected].time < 0) {
                pin[pin_selected].time = 999;
            }
        }
    } else if(Time_Upup == 1) {
        Delay_Routine(3);
        if(Time_Upup == 1) {
            pin[pin_selected].time += 10;
            if(pin[pin_selected].time > 999) {
                pin[pin_selected].time = 0;
            }
        }
    } else if(Port_Up == 1) {
        Delay_Routine(3);
        if(Port_Up == 1) {
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
        }
    } else if(Slave_Up == 1) {
        Delay_Routine(3);
        if(Slave_Up == 1) {
            Save_Data(pin[pin_selected].time, pin[pin_selected].address);
            slave_selected++;
            if(slave_selected > 2) {
                slave_selected = 0;
            }
        }
    }
}