/* task
Die beiden Satteltaschen eines Esels (auf der linken und rechten Seite des Eselrückens) sollen so mit Gegenständen (items) beladen werden, dass die Gesamtgewichte der Gegenstände in den Satteltaschen möglichst gut ausbalanciert sind. Schreiben Sie die Funktion balance\_donkey, die eine möglichst gute Ausbalancierung berechnet. Nehmen Sie an, dass die Gewichte der Gegenstände positiv sind. Hinweis: Probieren Sie einfach alle Möglichkeiten aus. Verwenden Sie dazu den bereitgestellten Iterator. 

Template-Datei: balance\_donkey.c.
*/

/*
Compile: make balance_donkey
Run: ./balance_donkey
make balance_donkey && ./balance_donkey
*/

#include <limits.h>
#include "base.h"

/**
Computes the sum of the items in the selection.
@param[in] items all items
@param[in] n the number of items
@param[in] selection boolean array (of length n) that indicates the selected items 
           (selection[i] == true means items[i] is selected)
@return the sum of the selected items
*/
int sum(int *items, int n, bool *selection) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (selection[i]) {
            result += items[i];
        }
    }
    return result;
}

/**
Computes the sum of the items.
@param[in] items the items
@param[in] n the number of items
@return the sum of the items
*/
int total_sum(int *items, int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += items[i];
    }
    return result;
}

/**
Print the selected items.
@param[in] items the items
@param[in] n the number of items
@param[in] selection boolean array (of length n) that indicates which items are selected
*/
void print_items(/*IN*/int* items, int n, /*IN*/bool* selection) {
    for (int i = 0; i < n; i++) {
        if (selection[i]) {
            printi(items[i]);
            printc(' ');
        }
    }
    println();
}

/**
Increments the selection, i.e., treats selection as a binary number that is incremented. In this way, all of the possible selections can be enumerated. Example: false, false, true --next_selection--> false, true, false. Modifies the selection array.
@param[in,out] selection array (of length n) that indicates which items are selected
@param[in] n the length of the array
*/
void next_selection(/*IN,OUT*/bool *selection, int n) {
    bool carry_bit = false;
    for (int i = n - 1; i >= 0; i--) {
        if (!selection[i] && !carry_bit) {
            selection[i] = true;
            return;
        }
        else if (selection[i] && !carry_bit) {
            selection[i] = false;
            carry_bit = true;
        }
        else if (!selection[i] && carry_bit) {
            selection[i] = true;
            return;
        }
        else if (selection[i] && carry_bit) {
            selection[i] = false;
            carry_bit = true;
        }
    }
}

/**
Checks whether there are more selections. Returns false, if all elements of selection are true.
@param[in,out] selection array that indicates which items are selected
@param[in] n the length of the array
@return true if there is a next selection, false otherwise
*/
bool has_next_selection(/*IN*/bool *selection, int n) {
    for (int i = 0; i < n; i++) {
        if (!selection[i]) {
            return true;
        }
    }
    return false;
}


/**
Todo: Implement.
Returns the best selection for the given parameters (see exercise definition).
@param[in] items the items
@param[in] n the number of items
@return the best selection
*/

bool *balance_donkey(int *items, int n) {
    int total = total_sum(items, n);
    // each stick may be selected or not, encode this by using a bit array
    bool *selection = xcalloc(n, sizeof(bool));
    bool *best_selection = xcalloc(n, sizeof(bool));
    int min_diff = INT_MAX;
    while (has_next_selection(selection, n)) {
        next_selection(selection, n);
//        printbaln((Byte*)selection, n);
        int left_sum = sum(items, n, selection);
        int right_sum = total - left_sum;
        int diff = abs(left_sum - right_sum);
        if (diff < min_diff) {
            min_diff = diff;
            memcpy(best_selection, selection, n * sizeof(bool));
        }
    }
    free(selection);
//    printiln(min_diff);
//    printbaln((Byte*)best_selection, n);
    return best_selection;
}

void test(void) {
    int items[] = { 1, 3, 5, 7 };
    int n = sizeof(items) / sizeof(int);
    bool* best_selection = balance_donkey(items, n);
    if(best_selection){
        printf("Actual:   ");printbaln((Byte*)best_selection, n);
        bool expected_selection[] = { false, true, true, false };
        printf("Expected: ");printbaln((Byte*)expected_selection, n);
        println();
        free(best_selection);
    }

    int items2[] = { 31, 32, 53, 74, 87 };
    int n2 = sizeof(items2) / sizeof(int);
    bool* best_selection2 = balance_donkey(items2, n2);
    if(best_selection2){
        printf("Actual:   ");printbaln((Byte*)best_selection2, n2);
        bool expected_selection2[] = { false, false, true, false, true };
        printf("Expected: ");printbaln((Byte*)expected_selection2, n2);
        println();
        free(best_selection2);
    }
}

int main(void) {
    test();
    return 0;
}
