#include "base.h"

// (1)
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

// (4)

bool first_equals_last(char *s)
{
    return s[0] == s[s_length(s) - 1];
}

// (7)
char *remove_letters(char *s)
{
    int count = 0;

    if (s[0] == '\0')
    {
        return "";
    }

    for (int i = 0; i < s_length(s); i++)
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

    return new_string;
}

void test()
{
    // (1)
    // test_equal_b(ascending_numbers_in_string("as5678e"), true);
    // test_equal_b(ascending_numbers_in_string("as58bb1234ett"), true);
    // test_equal_b(ascending_numbers_in_string("123"), false);
    // test_equal_b(ascending_numbers_in_string("2468"), true);
    // test_equal_b(ascending_numbers_in_string("6789"), true);
    // test_equal_b(ascending_numbers_in_string("abcd"), false);
    // test_equal_b(ascending_numbers_in_string("54321"), false);
    // test_equal_b(ascending_numbers_in_string("abc 123 de 4567"), true);
    // test_equal_b(ascending_numbers_in_string("abc 123 de 645"), false);

    // (4)
    // test_equal_b(first_equals_last("abba"), true);
    // test_equal_b(first_equals_last("1997"), false);
    // test_equal_b(first_equals_last("a        a"), true);
    // test_equal_b(first_equals_last("!caution!"), true);
    // test_equal_b(first_equals_last("x00abcdefg...00x"), true);

    // (7)
    test_equal_s(remove_letters(""), "");

    char *r2 = remove_letters("x");
    test_equal_s(r2, "");
    free(r2);

    char *r3 = remove_letters("12hello24");
    test_equal_s(r3, "1224");
    free(r3);

    char *r4 = remove_letters("aaaa200aaaa");
    test_equal_s(r4, "200");
    free(r4);

    char *r5 = remove_letters("x      2      x");
    test_equal_s(r5, "2");
    free(r5);
}

int main(void)
{
    test();
    report_memory_leaks(true);
    return 0;
}