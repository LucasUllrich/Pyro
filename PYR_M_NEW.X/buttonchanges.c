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
        
    } else if(Time_Down == 1) {
        
    } else if(Time_Upup == 1) {
        
    }
}