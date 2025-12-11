/*
Compile: make loops
Run: ./loops
make loops && ./loops
*/

#include "base.h"


void loops_a(int n) {
    for (int i= 1; i <= n; i++) { // funktion um durch zu zählen
        for (int j= 1; j <= i; j++) { // erstellt die einzelnen Zeilen
                printf("%d ", j);
            }
        for (int o= 0; o < (n - i) *2; o++) {
                printf(" "); // erstellt die Leerzeichen
            }
        printf("\n");
       }
}

void loops_b(int n) { 
    for (int i= 1; i <= n; i++) { // funktion um durch zu zählen
            for (int o= 0; o < (n -i) * 2; o++) { // erstellt die Leerzeichen
                printf(" ");
            }
            for (int j= 1; j <= i; j++) { // erstellt die einzelnen Zeilen
                printf("%d ", j);
            }
                printf("\n");
            }
    
}

void loops_c(int n) {
    for (int i= 1; i <= n; i++) { // funktion um durch zu zählen
        for (int o= 0; o < (n - i); o++) { // Lerzeichen links
            printf(" ");
        }
        for (int j= 1; j <= i; j++){ // erstellt die einzelnen Zeilen
            printf("%d ", j);
        }
        for (int o= 0; o < (n - i); o ++) { // Leerzeichen rechts
            printf(" ");
        }
        printf("\n");
    }
}
// obere Hälfte
void loops_d(int n) {
    if (n % 2 == 0 ) {
        printf("n muss ungerade sein\n");
        return;
    }
    for (int i= 0; i < n / 2 + 1; ++i) {

        for ( int o= 0; o < i * 2; o++) {
            printf(" "); // Leerzeichen leinks
        }
        printf("%d", i); // Zahl links

        for (int o= 0; o < (n * 2) - i * 4 - 3; o ++) {
            printf(" "); // Leerzeichen in der Mitte
        }
        if (i != n / 2) {
        printf("%d", i); // Zahl rechts
        }    
        printf("\n");
    }
    // untere Hälfte
for (int i= n / 2 - 1; i >= 0; --i) {

        for ( int o= 0; o < i * 2; o++) {
            printf(" "); // Leerzeichen leinks
        }
        printf("%d", i); // Zahl links

        for (int o= 0; o < (n * 2) - i * 4 - 3; o ++) {
            printf(" "); // Leerzeichen in der Mitte
        }
        if (i != n / 2) {
        printf("%d", i); // Zahl rechts
        }    
        printf("\n");
    }
}

// todo: implement helper functions for loops_e (recommended)
void gerade_linie(int n, int space) {
    for (int o= 0; o < space; o++) {
        printf(" ");
    }
    printf("+");
    for (int j= 0; j < n + 3; j++) {
        printf("-");
    }
    printf("+\n");
}

void loops_e(int n) {
    if (n < 3) { // prüft ob n grösser gleich 3 ist
        printf("n muss grösser gleich 3 sein\n");
        return;
    }
    int space = n - 2;
    gerade_linie(n, space); // druckt obere Linie

    for (int i= 0; i < n - 2; i++) {  // leerzeichen links
        for (int j= 0; j < space - i; j++) {
            printf(" ");
        }
        printf("/"); // linke Seite
        for (int o= 0; o < n + 3; o++) { // innenraum
            printf(" ");
        }
        printf("/\n"); // rechte Seite
    }

    gerade_linie(n, 0); // druckt untere Linie
}

// todo: implement helper functions for loops_f (recommended)

void loops_f(int n) {
    // todo: implement
} 

int main(void) {
    loops_a(5);
    loops_b(5);
    loops_c(5);
    loops_d(5);
    loops_a(9);
    loops_b(9);
    loops_c(9);
    loops_d(9);
    loops_e(3);
    loops_e(4);
    loops_e(5);
    loops_e(9);
    loops_e(12);
    loops_f(5);
    loops_f(9);
    return 0;
} 
