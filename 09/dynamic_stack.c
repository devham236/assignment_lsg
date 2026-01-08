/*
    Compile: make dynamic_stack
    Run: ./dynamic_stack
    make dynamic_stack && ./dynamic_stack
*/

#include "base.h"
#include "stdlib.h"

typedef struct DynamicStack {
    int* data;        // Zeiger des Stacks
    int size;         // Aktuelle Größe des Stacks
    int capacity;     // Kapazität des Stacks
} DynamicStack;

DynamicStack* stack_new(void) {
    // Wir initialisieren einen neuen Stack der leer ist und keine Kapazität hat
    struct DynamicStack* stack = malloc(sizeof(DynamicStack));
    if (stack == NULL) {
        return NULL;
    }
    stack->data = NULL;
    stack->size = 0;
    stack->capacity = 0;
    return stack;
}

void stack_free(DynamicStack* stack) {
    if (stack == NULL) {
        return;
    }
    // Stack frei geben 
    free (stack->data);
    // Pointer resetten
    stack->data = NULL; 
    stack->size = 0;
    stack->capacity = 0;

}

void stack_push(DynamicStack* stack, int value) {

if (stack->size >= stack->capacity) {
        // Stack ist voll, wir müssen die Kapazität erhöhen
        int new_capacity = (stack->capacity == 0) ? 1 : stack->capacity * 2;
        int* new_data = realloc(stack->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            // Fehler bei der Speicherzuweisung
            return;
        }
        stack->data = new_data;
        stack->capacity = new_capacity;
    }
    // Füge den neuen Wert oben auf den Stack
    stack->data[stack->size] = value;
    stack->size++;
}

int stack_pop(DynamicStack* stack) {
    
    if (stack->size == 0) {
        // Stack ist leer
        printf("der Stack ist leer, man kann nichts wiedergeben!\n"); 
        return 0;
    }
    // auf den obersten Wert des Stacks zufreifen
    int value = stack->data[stack->size - 1];
    // Den Size operator um einen veringern
    stack->size--;
    // Den obersten Wert des Stacks zurückgeben
    return value;
}

void test_stack_ops(DynamicStack* stack) {
    stack_push(stack, 42);
    stack_push(stack, 1);
    stack_push(stack, 13);
    test_equal_i(stack_pop(stack), 13);
    test_equal_i(stack_pop(stack), 1);
    stack_push(stack, 400);
    stack_push(stack, 500);
    stack_push(stack, 600);
    stack_push(stack, 700);
    test_equal_i(stack_pop(stack), 700);
    test_equal_i(stack_pop(stack), 600);
    test_equal_i(stack_pop(stack), 500);
    test_equal_i(stack_pop(stack), 400);
    test_equal_i(stack_pop(stack), 42);
    test_equal_i(stack_pop(stack), 0);
}

int main(void) {
    DynamicStack* stack = stack_new();
    test_stack_ops(stack);

    stack_free(stack);

    DynamicStack* stack2 = stack_new();
    stack_free(stack2);
}
