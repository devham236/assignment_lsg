/*
Compile: make park_house
Run: ./park_house
make park_house && ./park_house
*/

#include "base.h"

/* Design a function that returns the state of a park house given the number
of free parking spots */

typedef enum ParkHouseState {
	// TODO
    VOLLES_PARKHAUS,
    FAST_VOLLES_PARKHAUS,
    FREIES_PARKHAUS
} ParkHouseState;

ParkHouseState det_park_house_state(int free_spots);

String print_park_house_state(ParkHouseState state);

static void det_park_house_state_test() {
    //a) TODO

}
//a) TODO
ParkHouseState det_park_house_state(int free_spots) {
    return VOLLES_PARKHAUS;
}

// b) TODO
String print_park_house_state(ParkHouseState state) {
    return "";
}


int main(void) {
    det_park_house_state_test();
    printsln(print_park_house_state(det_park_house_state(0)));
    printsln(print_park_house_state(det_park_house_state(8)));
    printsln(print_park_house_state(det_park_house_state(21)));
    return 0;
}

