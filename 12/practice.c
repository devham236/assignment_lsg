#include "base.h"

// (a)
bool ascending_numbers_in_string(char *s)
{
    if (s_length(s) < 4)
    {
        return false;
    }

    int count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isdigit(s[i]))
        {
            count++;
        }
    }

    char *new_string = xmalloc(count + 1);
    new_string[count] = '\0';

    for (int i = 0, j = 0; s[i] != '\0'; i++)
    {
        if (isdigit(s[i]))
        {
            new_string[j] = s[i];
            j++;
        }
    }

    if (s_length(new_string) < 4)
    {
        return false;
    }

    for (int i = 0; i < s_length(new_string) - 1; i++)
    {
        printf("%c \n", new_string[i]);
        if (new_string[i] > new_string[i + 1])
        {
            return false;
        }
    }

    return true;
}

void test()
{
    // (a)
    test_equal_b(ascending_numbers_in_string("as5678e"), true);
    test_equal_b(ascending_numbers_in_string("123"), false);
    test_equal_b(ascending_numbers_in_string("6789"), true);
    test_equal_b(ascending_numbers_in_string("abcd"), false);
    test_equal_b(ascending_numbers_in_string("54321"), false);
    test_equal_b(ascending_numbers_in_string("abc 123 de 456"), false);
}

int main(void)
{
    test();
    return 0;
}