#include "base.h"

int* col_prod(int* a, int rows, int cols) {
    //allokieren eines Arrays, weils in der Aufgabenstellung steht, auch trial & error 
    int* result = xmalloc(rows * sizeof(int));

    //ein loop der die positionen abgreift, keine Ahnung was ich da multipliziere,weil ich nicht weiß wie der Pointer ausgerichtet ist
    // es war literally trial & error  
    for (int i = 0; i < rows; i++){
        int produkt = 1; 
        for (int j = 0; j < cols; j++){
            produkt = produkt * a[j * cols + i]; 
        }

    result[i] = produkt; 
    }

    return result; 

}



void test(void) {

    int a[3][3] = {
        { 1, 2, 3 },
        { -1, -2, -3 },
        { 3, 4, 5 },
    };

    //danke an geeksforgeeks.org an dieser Stelle 
    //int* p_a = (int*)a; 

    int* test = col_prod((int*)a, 3, 3); 

    printialn(test, 3); 

    free(test); 

}


int main(){
    test(); 
    //der test sollte -3, -16, -45 ausgeben, was er auch tut

    report_memory_leaks(true); 

    return 0; 
}