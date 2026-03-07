
/*
Compile: make center_or_zero
Run: ./center_or_zero
make center_or_zero && ./center_or_zero
*/

#include "base.h"

// A list node.
typedef struct IntList {
    int value;
    struct IntList *next;
} IntList;

// Prepend value to the front of the given list.
IntList* cons(int value, IntList* next) {
    IntList* node = xcalloc(1, sizeof(IntList));
    node->value = value;
    node->next = next;
    return node;
}

int center_or_zero(IntList* list) {
    return -1;
}

void test(void) {
    test_equal_i(center_or_zero(NULL), 0);
    test_equal_i(center_or_zero(cons(-10, NULL)), -10);

    test_equal_i(center_or_zero(cons(1, cons(10, NULL))), 0);

    test_equal_i(center_or_zero(cons(2, cons(1, cons(-2, NULL)))), 1);
    test_equal_i(center_or_zero(cons(2, cons(-1, cons(2, NULL)))), -1);

    test_equal_i(center_or_zero(cons(1, cons(-1, cons(9, cons(-2, cons(2, NULL)))))), 9);
    test_equal_i(center_or_zero(cons(1, cons(2, cons(-3, cons(-4, NULL))))), 0);
}

int main(void) {
    test();
    return 0;
}
