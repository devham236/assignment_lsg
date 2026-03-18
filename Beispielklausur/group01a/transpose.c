    
/*
Compile: make transpose
Run: ./transpose
make transpose && ./transpose
*/

#include "base.h"

typedef struct {
    double* data;
    int rows, cols;
} Matrix;

Matrix transpose(Matrix m) {
    // implement...
    return (Matrix){NULL, 0, 0};
}

void print_matrix(Matrix m) {
    int i = 0;
    for (int y = 0; y < m.rows; y++) {        
        for (int x = 0; x < m.cols; x++) {
            printf("%g ", m.data[i++]);
        }
        printf("\n");
    }
    printf("\n");
}

void f_test_equal_matrix(int line, Matrix a, Matrix b) {
    base_count_check();
    if (a.rows != b.rows || a.cols != b.cols) {
        fprintf(stderr, "%s, line %d: Test failed. Matrix dimensions not equal.\n", 
                __FILE__, line);
        return;
    }
    int i = 0;
    for (int y = 0; y < a.rows; y++) {
        for (int x = 0; x < a.cols; x++) {
            if (fabs(a.data[i] - b.data[i]) > 1e-10) {
                fprintf(stderr, "%s, line %d: Test failed. Matrices differ at row %d, column %d (%g != %g).\n", 
                __FILE__, line, y, x, a.data[i], b.data[i]);
                return;
            }
            i++;
        }
    }
    base_count_success();
}

#define test_equal_matrix(actual, expected) f_test_equal_matrix(__LINE__, actual, expected)

void test(void) {
    double a[2][3] = {
        { 1, 2, 3 }, 
        { 4, 5, 6 }, 
    };
    Matrix m = {(double*)a, 2, 3};
    print_matrix(m);

    double at[3][2] = {
        { 1, 4 }, 
        { 2, 5 }, 
        { 3, 6 }, 
    };
    Matrix mt = {(double*)at, 3, 2};
    print_matrix(mt);

    Matrix result = transpose(m);
    print_matrix(result);
    
    printf("%d rows, %d cols\n", result.rows, result.cols);
    test_equal_matrix(result, mt);
}

int main(void) {
    test();
    return 0;
}
