#include "base.h"

// (a)
bool ascending_numbers_in_string(char *s)
{
    int count = 0;
    int len = s_length(s);

    if (len < 4)
    {
        return false;
    }

    for (int i = 0; i < len; i++)
    {
        if (isdigit(s[i]) && i > 0 && isdigit(s[i - 1]) && (s[i] >= s[i - 1] + 1))
        {
            count++;
        }
        else if (isdigit(s[i]))
        {
            count = 1;
        }
        else
        {
            count = 0;
        }

        if (count >= 4)
        {
            return true;
        }
    }

    return false;
}

/*
"as5678e"

i = 0
"a" ist kein digit, count = 0

i = 1
"s" ist kein digit, count = 0

i = 2
"5" ist ein digit, i ist größer als 0, s[i-1] ist aber kein digit,
count = 1

i = 3
"6" ist ein digit, i ist größer als 0, s[i-1] ist ein digit, 6 == s[i-1] + 1
count = 2

i = 4
"7" ist ein digit, i ist größer als 0, s[i-1] ist ein digit, 7 == s[i-1] + 1
count = 3

i = 5
"8" ist ein digit, i ist größer als 0, s[i-1] ist ein digit, 8 == s[i-1] + 1
count = 4

i = 6
"e" ist kein digit
count = 0
*/

void test()
{
    // (a)
    test_equal_b(ascending_numbers_in_string("as5678e"), true);
    test_equal_b(ascending_numbers_in_string("as58bb1234ett"), true);
    test_equal_b(ascending_numbers_in_string("123"), false);
    test_equal_b(ascending_numbers_in_string("2468"), true);
    test_equal_b(ascending_numbers_in_string("6789"), true);
    test_equal_b(ascending_numbers_in_string("abcd"), false);
    test_equal_b(ascending_numbers_in_string("54321"), false);
    test_equal_b(ascending_numbers_in_string("abc 123 de 4567"), true);
    test_equal_b(ascending_numbers_in_string("abc 123 de 645"), false);
}

int main(void)
{
    test();
    return 0;
}