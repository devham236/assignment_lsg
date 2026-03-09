#include "base.h"

int *col_prod(int *a, int rows, int cols)
{
    int *result = xmalloc(cols * sizeof(int));

    for (int i = 0; i < cols; i++)
    {
        int product = 1;

        for (int j = 0; j < rows; j++)
        {
            product *= a[j * cols + i];
        }

        result[i] = product;
    }

    return result;
}

void test(void)
{
    int a[3][3] = {
        {1, 2, 3},
        {-1, -2, -3},
        {3, 4, 5},
    };

    int *test = col_prod((int *)a, 3, 3);

    printialn(test, 3);

    free(test);
}

int main(void)
{
    test();
    // der test sollte -3, -16, -45 ausgeben, was er auch tut
    return 0;
}