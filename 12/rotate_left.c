// run make rotate_array_left && ./rotate_array_left
#include "base.h"

void rotate_array_left(int *a, int n)
{
    require_not_null(a);
    require("not negative", n >= 0);

    if (n == 1)
    {
        a[0] = *a;
    }

    int first_val = a[0];

    for (int i = 0; i <= n - 1; i++)
    {
        if (i == n - 1)
        {
            a[i] = first_val;
        }
        else
        {
            a[i] = a[i + 1];
        }

        printf("%d \n", a[i]);
    }
}

void test_rotate_array_left(void)
{
    {
        // Test case 1: single-element array (n = 1)
        int a[] = {9};
        int n = 1;
        rotate_array_left(a, n);
        test_equal_i(a[0], 9);
    }
    {
        // Test case 2: two-element array (n = 2)
        int b[] = {9, 1};
        int n = 2;
        rotate_array_left(b, n);
        test_equal_i(b[0], 1);
        test_equal_i(b[1], 9);
    }
    {
        // Test case 3: five-element array using distinct values
        int c[] = {10, 20, 30, 40, 50};
        /*
        int c[] = {20, 30, 40, 50, 10};
        */
        int n = 5;
        rotate_array_left(c, n);
        test_equal_i(c[0], 20);
        test_equal_i(c[1], 30);
        test_equal_i(c[2], 40);
        test_equal_i(c[3], 50);
        test_equal_i(c[4], 10);
    }
    {
        // Test case 4: five-element array with sequential values
        int d[] = {1, 2, 3, 4, 5};
        int n = 5;
        rotate_array_left(d, n);
        test_equal_i(d[0], 2);
        test_equal_i(d[1], 3);
        test_equal_i(d[2], 4);
        test_equal_i(d[3], 5);
        test_equal_i(d[4], 1);
    }
    {
        // Test case 5: ten-element array
        int e[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int n = 10;
        rotate_array_left(e, n);
        test_equal_i(e[0], 1);
        test_equal_i(e[1], 2);
        test_equal_i(e[2], 3);
        test_equal_i(e[3], 4);
        test_equal_i(e[4], 5);
        test_equal_i(e[5], 6);
        test_equal_i(e[6], 7);
        test_equal_i(e[7], 8);
        test_equal_i(e[8], 9);
        test_equal_i(e[9], 0);
    }
}

int main(void)
{
    test_rotate_array_left();
    report_memory_leaks(true);
    return 0;
}