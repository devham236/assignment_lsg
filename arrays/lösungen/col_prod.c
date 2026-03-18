
#include "base.h"

int* col_prod(int* a, int rows, int cols) {
    //erzeuge dynamisch einen Array mit der Reihengröße
    int* produkt = xmalloc(rows * sizeof(int));
    for(int i = 0; i < rows; i++) {
        produkt[i] = 1;
    }
    int p = 0;
    int* k = a;
    for(int r = 0; r < rows; r++) {
        for( int c = 0; c < cols; c++) {
            produkt[p] = produkt[p] * k[r+(c*rows)];
        }
        p++;
    }
    return produkt;
}

void test(void) {
    int a[3][3] = {
        { 1, 2, 3 },
        { -1, -2, -3 },
        { 3, 4, 5 },
    };

    int test[3] = {-3, -16, -45};
    printialn(col_prod(a, 3, 3), 3);
}

int main(void) {
    test();
    return 0;
}
