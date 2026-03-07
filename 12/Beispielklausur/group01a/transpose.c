
/*
Compile: make transpose
Run: ./transpose
make transpose && ./transpose
*/

#include "base.h"

/*
Das struct hat einen double Pointer "data", der die Adresse im Speicher, der ersten Zahl der Matrix, speichert.
Und zwei int Werte für die Zeilen und Spalten.
2D Arrays werden in C immer zeilenweise gespeichert. Das heißt wenn du diese 2D Array hast;

double m[2][2] = {
    {1, 2}
    {3, 4}
}

Dann wird diese Matrix so gespeichert: [1, 2, 3, 4]

*/
typedef struct
{
    double *data;
    int rows, cols;
} Matrix;

/*
Transponieren kennst du ja schon, Zeilen werden zu Spalten und Spalten werden zu Zeilen.

1 2 3  ---> 1 4
4 5 6       2 5
            3 6

Die Funktion erstellt erstmal eine "Matrix" Instanz und vertasucht dann rows und cols.
Das heißt wenn du eine 2x3 Matrix übergeben bekommst soll eine 3x2 Matrix zurückgegeben werden.

Dann wird Speicher reserviert für die transponierte Matrix. Die transponierte Matrix hat 3 Zeilen und 2 Spalten, und in jedes
Feld kommt ein double rein. Also musst du die Zeilenanzahl mit der Spaltenanzahl multiplizieren und das Ergebnis dann mit der Größe eines doubles (8 Bytes).
In C wird dieser Speicher nicht als Matrix oder Tabelle angelegt sondern als ein langes Speicherband: [?, ?, ?, ?, ?, ?]

Jetzt gehen wir mit zwei verschachtelten Schleifen durch die Originalmatrix. Das i geht durch die Zeilen und das j durch die Spalten.
m hat zwei Zeilen, also geht i von 0 bis 1 und drei Spalten, also geht j von 0 bis 2
Im j loop speichern wir immer den double Wert in eine Variable und setzten dann diese gleich mit dem aktuellen index der result Matrix.
i erhöht sich erst um 1, wenn j durch alle Spalten durchlaufen ist, also j=0, j=1, und j=2

1) i=0, j=0
double value = m.data[0 * 3 + 0] = m.data[0] = 1
result.data[0 * 2 + 0] = result.data[0] = value

2) i=0, j=1
double value = m.data[0 * 3 + 1] = m.data[1] = 2
result.data[1 * 2 + 0] = result.data[2] = value
- Die zwei kommt an erster Stell der zweiten Zeile der transponierten Matrix

3) i=0, j=2
double value = m.data[0 * 3 + 2] = m.data[2] = 3
result.data[2 * 2 + 0] = result.data[4] = value

3) i=1, j=0
double value = m.data[1 * 3 + 0] = m.data[3] = 4
result.data[0 * 2 + 1] = result.data[1] = value

i * m.cols bringt dich an den Anfang Zeile die du benötigst und + j geht innerhalb der aktuellen Zeile die Schritte nach rechts,
um die richtige Spalte zu finden

Und weil wir ja die Matrix transponieren wollen, vertauschen wir i und j in der Berechnung des Index von result.
*/
Matrix transpose(Matrix m)
{
    Matrix result;
    result.rows = m.cols;
    result.cols = m.rows;
    result.data = xmalloc(result.rows * result.cols * sizeof(double));

    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.cols; j++)
        {
            double value = m.data[i * m.cols + j];

            result.data[j * result.cols + i] = value;
        }
    }

    return result;
}

void print_matrix(Matrix m)
{
    int i = 0;
    for (int y = 0; y < m.rows; y++)
    {
        for (int x = 0; x < m.cols; x++)
        {
            printf("%g ", m.data[i++]);
        }
        printf("\n");
    }
    printf("\n");
}

void f_test_equal_matrix(int line, Matrix a, Matrix b)
{
    base_count_check();
    if (a.rows != b.rows || a.cols != b.cols)
    {
        fprintf(stderr, "%s, line %d: Test failed. Matrix dimensions not equal.\n",
                __FILE__, line);
        return;
    }
    int i = 0;
    for (int y = 0; y < a.rows; y++)
    {
        for (int x = 0; x < a.cols; x++)
        {
            if (fabs(a.data[i] - b.data[i]) > 1e-10)
            {
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

void test(void)
{
    double a[2][3] = {
        {1, 2, 3},
        {4, 5, 6},
    };
    Matrix m = {(double *)a, 2, 3};
    print_matrix(m);

    double at[3][2] = {
        {1, 4},
        {2, 5},
        {3, 6},
    };
    Matrix mt = {(double *)at, 3, 2};
    print_matrix(mt);

    Matrix result = transpose(m);
    print_matrix(result);

    printf("%d rows, %d cols\n", result.rows, result.cols);
    test_equal_matrix(result, mt);
}

int main(void)
{
    test();
    return 0;
}
