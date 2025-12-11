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
    test_equal_i(det_park_house_state(0), VOLLES_PARKHAUS);
    test_equal_i(det_park_house_state(1), FAST_VOLLES_PARKHAUS);
    test_equal_i(det_park_house_state(20), FREIES_PARKHAUS);
}
//a) TODO
ParkHouseState det_park_house_state(int free_spots) {
    if(free_spots == 0) {
        return VOLLES_PARKHAUS;
    }
    else if(free_spots < 10) {
        return FAST_VOLLES_PARKHAUS;
    }
    else if(free_spots > 10) {
        return FREIES_PARKHAUS;
    }
    return 0;
}

// b) TODO
String print_park_house_state(ParkHouseState state) {
    switch(state) {
        case VOLLES_PARKHAUS:
            return "Es gibt keine freien Parkplätze";
            break;
        case FAST_VOLLES_PARKHAUS:
            return "Es gibt weniger als 10 freie Parkplätze";
            break;
        case FREIES_PARKHAUS:
            return "Es gibt mehr als 10 freie Parkplätze";
            break;
    }
    return "";
}


int main(void) {
    det_park_house_state_test();
    printsln(print_park_house_state(det_park_house_state(0)));
    printsln(print_park_house_state(det_park_house_state(8)));
    printsln(print_park_house_state(det_park_house_state(21)));
    return 0;
}

