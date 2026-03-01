#include "base.h"

// (a)
bool ascending_numbers_in_string(char *s)
{
}

void test()
{
    // (a)
    test_equal_b(ascending_numbers_in_string("as5678e"), true);
    test_equal_b(ascending_numbers_in_string("123"), false);
    test_equal_b(ascending_numbers_in_string("6789"), true);
    test_equal_b(ascending_numbers_in_string("abcd"), false);
    test_equal_b(ascending_numbers_in_string("54321"), false);
    test_equal_b(ascending_numbers_in_string("abc 123 de 4567"), true);
    test_equal_b(ascending_numbers_in_string("abc 123 de 456"), false);
}

int main(void)
{
    test();
    return 0;
}