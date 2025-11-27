/*
Compile: make dam_control
Run: ./dam_control
make dam_control && ./dam_control
*/

#include "base.h"

typedef enum {
    DM_IDLE,
    DM_OPEN_SMALL,
    DM_OPEN_LARGE,
    DM_EMERGENCY_OPEN
}dam_mode_e; 
/*integriert die 4 Modul Namen, ob die Talsperre:
- Leerlauf hat
- Nur eine Pumpe laufen lässt
- 2 Pumpen laufen hat
- oder 2 Pumpen und das Notfallventil laufen lässt */

dam_mode_e DamMode(double water_level) {
        if (water_level < 20) {
            return DM_IDLE;
        } else if (water_level >= 20 && water_level < 40) {
            return DM_OPEN_SMALL;
        } else if (water_level >= 40 && water_level < 67.5) {
            return DM_OPEN_LARGE;
        } else {
            return DM_EMERGENCY_OPEN;
        }
}
/*Hier werden die unterschiedlichen Wasser Level den zugehörigen Modis zugewiesen*/

void dam_control_test(void) {
test_equal_i(DamMode (0), DM_IDLE);
test_equal_i(DamMode (23), DM_OPEN_SMALL);
test_equal_i(DamMode (47.5), DM_OPEN_LARGE);
test_equal_i(DamMode (100), DM_EMERGENCY_OPEN);
}
/*Test durchläufe von Unterschiedlichen Wassel Leveln*/

int main(void) {
    dam_control_test();
    return 0;
}
