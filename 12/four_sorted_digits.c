
/*
Compile: make four_sorted_digits
Run: ./four_sorted_digits
make four_sorted_digits && ./four_sorted_digits
*/

#include "base.h"

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool has_4_or_more_sorted_digits(char* s) {
    return false;
}

void test(void) {
    test_equal_b(has_4_or_more_sorted_digits(""), false);
    test_equal_b(has_4_or_more_sorted_digits("000"), false);
    test_equal_b(has_4_or_more_sorted_digits("xxxx"), false);
    test_equal_b(has_4_or_more_sorted_digits("aaaaa"), false);
    test_equal_b(has_4_or_more_sorted_digits("0a000"), false);
    test_equal_b(has_4_or_more_sorted_digits("000a00"), false);
    test_equal_b(has_4_or_more_sorted_digits("x123x"), false);
    test_equal_b(has_4_or_more_sorted_digits("x3333y"), false);
    test_equal_b(has_4_or_more_sorted_digits("1233"), false);
    test_equal_b(has_4_or_more_sorted_digits(" 1233"), false);

    test_equal_b(has_4_or_more_sorted_digits("1234"), true);
    test_equal_b(has_4_or_more_sorted_digits("1369"), true);
    test_equal_b(has_4_or_more_sorted_digits("abc3679xyz"), true);
    test_equal_b(has_4_or_more_sorted_digits("1679"), true);
    test_equal_b(has_4_or_more_sorted_digits("--1679---"), true);
    test_equal_b(has_4_or_more_sorted_digits("123456789"), true);
    test_equal_b(has_4_or_more_sorted_digits("24689"), true);
}

int main(void) {
    test();
    return 0;
}
