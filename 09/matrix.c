/*
    Compile: make matrix
    Run: ./matrix
    make matrix && ./matrix
*/

#include "base.h" // http://hci.uni-hannover.de/files/prog1lib/base_8h.html
#include <stdlib.h> // for malloc, free

struct Matrix {
    int rows; // number of rows
    int cols; // number of columns
    double** data; // a pointer to an array of n_rows pointers to rows; a row is an array of n_cols doubles 
};
typedef struct Matrix Matrix;

/**
Creates a zero-initialized matrix of rows and columns matrix.
@param[in] n_rows number of rows
@param[in] n_cols number of columns
@return a pointer to an array of n_rows pointers to rows; a row is an array of n_cols doubles 
*/
Matrix* make_matrix(int n_rows, int n_cols) {

// Speicher für Matrix-Struktur anfordern
Matrix *m = xmalloc(sizeof(Matrix));

// setzt die werte für rows und cols in den m Pointer
m->rows = n_rows;
m->cols = n_cols;

// Speicher für row pointer
m->data = xmalloc(n_rows * sizeof(double*));

// reserviert zeile mal spalte speicher für die matrix
for (int i = 0; i < n_rows; i ++) {
    m->data[i] = xmalloc(n_cols * sizeof(double));

for (int j = 0; j < n_cols; j ++) {
    m->data[i][j] = 0.0;
        }
    }
    return m;
}

/**
Creates a zero-initialized matrix of rows and columns matrix.
@param[in] data an array of doubles, ordered row-wise
@param[in] n_rows number of rows
@param[in] n_cols number of columns
@return a pointer to an array of n_rows pointers to rows; a row is an array of n_cols doubles 
*/
Matrix* copy_matrix(double* data, int n_rows, int n_cols) {

// unsere mit 0 gefüllter Matrix
Matrix *m = make_matrix(n_rows, n_cols);

// unser data array
int k = 0;

// füllt die matrix mit den werten aus dem data array
for (int i = 0; i < n_rows; i ++ ) {
    for (int j = 0; j < n_cols; j ++ ) {
        m->data[i][j] = data[k];
        k++;
    }
}

    return m;
}

/**
Print a matrix.
@param[in] m the matrix to print
*/
void print_matrix(Matrix* m) {

// Zur Sicherheit prüfen ob m NULL ist
if (m == NULL) {
    printf("NULL matrix\n");
    return;}

for (int i = 0; i < m->rows; i ++) {
    for (int j = 0; j < m->cols; j ++) {
        printf("%6.2f ", m->data[i][j]);
    }
    printf("\n");

    }
}

/**
Add two matrices.
@param[in] a the first operand
@param[in] b the second operand
@return a new matrix whose elements are the element-wise sums of a and b
*/
Matrix* add_matrices(/*in*/ Matrix* a, /*in*/ Matrix* b) {

    // Prüfen ob die Dimensionen der Matrizen übereinstimmen
if (a->rows != b->rows || a->cols != b->cols) {
    printf("Die Matrizen haben verschiedene Dimensionen und können nicht addiert werden.\n");
    return NULL;
}

    // Neue Matrix für das Ergebnis erstellen
Matrix* result = make_matrix(a->rows, a->cols);

for (int i = 0; i < a->rows; i ++) {
    for (int j = 0; j < a->cols; j ++) {
        // Elementweise Addition
        result->data[i][j] = a->data[i][j] + b->data[i][j];
    }
}
return result;

}

/**
Free a matrix.
@param[in] m the matrix to free
*/
void free_matrix(Matrix* m) {

    for (int i = 0; i < m->rows; i ++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

void matrix_test(void) {
    double a[] = { 
        1, 2, 3, 
        4, 5, 6, 
        7, 8, 9 };
    Matrix* m1 = copy_matrix(a, 3, 3);
    print_matrix(m1);
    printf("\n");

    double a2[] = { 
        1, 2, 3, 
        4, 5, 6 };
    Matrix* m2 = copy_matrix(a2, 2, 3);
    print_matrix(m2);
    printf("\n");

    double a3[] = { 
        1, 2, 
        3, 4, 
        5, 6 };
    Matrix* m3 = copy_matrix(a3, 3, 2);
    print_matrix(m3);
    printf("\n");

    double a4[] = { 
        10, 20, 
        30, 40, 
        50, 60 };
    Matrix* m4 = copy_matrix(a4, 3, 2);
    print_matrix(m4);
    printf("\n");

    Matrix* m5 = add_matrices(m3, m4);
    print_matrix(m5);
    printf("\n");
    
    free_matrix(m1);
    free_matrix(m2);
    free_matrix(m3);
    free_matrix(m4);
    free_matrix(m5);
}

int main(void) {
    report_memory_leaks(true);
    matrix_test();
    return 0;
}
