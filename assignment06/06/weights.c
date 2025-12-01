/*
Compile: make weights
Run: ./weights
make weights && ./weights
*/

#include "base.h"

// 1 lb = 0.45359237 kg

typedef enum unit_e {
    G,
    KG,
    T,
    LB
} Unit;

typedef struct weight_s {
    double amount;
    Unit unit;
} Weight;

Weight make_weight(double amount, Unit unit) {
    // todo
    Weight w;
    w.amount = amount;
    w.unit = unit;

    return w;
}

bool test_within_weight(int line, Weight a, Weight e, double tolerance) {
    bool x = base_test_within_d(__FILE__, line, a.amount, e.amount, tolerance);
    bool u = base_test_equal_i(__FILE__, line, a.unit, e.unit);
    return x && u;
}

void print_weight(Weight w) {
    // todo
    String unit = w.unit == 0 ? "g" : 
           w.unit == 1 ? "kg" : 
           w.unit == 2 ? "t" : 
           w.unit == 3 ? "lb" : "invalid unit";

    printf("\t%.2f %s\n", w.amount, unit);
}

void print_weight_test() {
    print_weight(make_weight(1234, G));
    print_weight(make_weight(4.749, KG));
    print_weight(make_weight(3.1001, T));
    print_weight(make_weight(5.40006, LB));
}

// Weight, Unit -> Weight
// Convert weight to the given target unit.
Weight to_unit(Weight w, Unit target_unit) {
    // todo
    Weight newWeight;
    newWeight.unit = target_unit;
    switch(target_unit) {
        // convert to grams (g)
        case G: {
            if(w.unit == KG) newWeight.amount = w.amount * 1000;
            if(w.unit == T) newWeight.amount = w.amount / 1e6;
            if(w.unit == LB) newWeight.amount = w.amount / 453.6;
            else newWeight.amount = w.amount;
            break;
        }

        // convert to kilograms (kg)
        case KG: {
            if(w.unit == T) newWeight.amount = w.amount / 1000;
            if(w.unit == LB) newWeight.amount = w.amount * 2.205;
            if(w.unit == G) newWeight.amount = w.amount * 1000;
            else newWeight.amount = w.amount;
            break;
        }

        // convert to tons (t)
        case T: {
            if(w.unit == KG) newWeight.amount = w.amount * 1000;
            if(w.unit == LB) newWeight.amount = w.amount * 2205;
            if(w.unit == G) newWeight.amount = w.amount * 1e6;
            else newWeight.amount = w.amount;
            break;
        }

        // convert to pounds (lbs)
        case LB: {
            if(w.unit == KG) newWeight.amount = w.amount / 2.205;
            if(w.unit == T) newWeight.amount = w.amount / 2205;
            if(w.unit == G) newWeight.amount = w.amount * 453.6;
            else newWeight.amount = w.amount;
            break;
        }
    }
    
    return newWeight;
}

void to_unit_test(void) {
    // todo: add tests (at least 5)
    test_within_weight(__LINE__, to_unit(make_weight(1, KG), G), make_weight(1000, G), 1e6);
    test_within_weight(__LINE__, to_unit(make_weight(1, LB), KG), make_weight(0.453592, KG), 1e6);
    test_within_weight(__LINE__, to_unit(make_weight(1, G), T), make_weight(9.9999918429e-7, T), 1e6);
    test_within_weight(__LINE__, to_unit(make_weight(1, T), LB), make_weight(2204.62, LB), 1e6);
    test_within_weight(__LINE__, to_unit(make_weight(1, KG), KG), make_weight(1, KG), 1e6);
}

// Weight, Weight -> int
// Compares two weights. Returns 0 if the two weights are equal, 
// -1 if w is smaller than v and +1 otherwise.
int compare(Weight w, Weight v) {
    // todo
    return 0;
}

void compare_test(void) {
    test_equal_i(compare(make_weight(1000, G), make_weight(1, KG)), 0);
    // todo: add tests (at least 5)
}

int main(void) {
    // print_weight_test();
    to_unit_test();
    compare_test();
    return 0;
}
