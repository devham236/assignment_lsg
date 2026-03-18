// 4. Aufgabe: (Original-Formulierung war sehr kompliziert und abschreckend,
// sinngemäß war folgendes gefordert): implementieren Sie die Funktion
// "void derive_polynoms(int *polynoms, int *results)", die Ableitung der Polynome
// aus dem polynoms-Array in das results-Array schreibt.

// Hört sich erstmal schrecklich kompliziert an - schauen wir uns an, was die
// eigentlich von uns wollen: ein Array { 1, 2, 3 } bspw. soll "übersetzt" bedeuten
// f(x) = 1 * x⁰ + 2 * x¹ + 3 * x². Leitet man das ab, erhält man
// f'(x) = 2 * x⁰ + 6 * x¹. Das results-Array soll also für results[0] die 2
// enthalten und für results[1] die 6. Angegeben waren noch weitere Testfälle, die
// allesamt aber ähnlich waren. Kann mich an keinen "komplizierten" Testfall
// erinnern. Im Endeffekt war das ein 3-Zeiler - wenn man sich von der
// zunächst kompliziert erscheinenden Aufgabenstellung nicht abschrecken ließ.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void derivePolynoms(int *polynoms, int *result)
{
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            result[i] = 1;
        }
        else
        {
            result[i] = 1 / (i + 1) * polynoms[i] + 1;
        }
    }
}

int main()
{
    int *polynoms = malloc(sizeof(int));
    int *result = malloc(sizeof(int));

    int upperLimit = 3;
    srand(time(NULL));
    printf("f(x) = ");

    for (int i = 0; i < upperLimit; i++)
    {
        polynoms[i] = i + 1; // rand() % upperLimit;
        if (i == upperLimit - 1)
        {
            printf("%d * x^%d ", polynoms[i], i);
        }
        else if (i < upperLimit)
        {
            printf("%d * x^%d + ", polynoms[i], i);
        }
    }
    printf("\n");
    derivePolynoms(polynoms, result);
    printf("F(x) = ");
    for (int i = 0; i < upperLimit; i++)
    {

        if (i == upperLimit - 1)
        {
            printf("%d * x^%d ", result[i], i + 1);
        }
        else if (i < upperLimit)
        {
            printf("%d * x^%d + ", result[i], i + 1);
        }
    }
    printf("\n");
}