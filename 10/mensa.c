/*
    Compile: make mensa
    Run: ./mensa
    Compile & run: make mensa && ./mensa
*/

#include "base.h"

/**
Represents a single list node. The string value is dynamically allocated. 
The node is the owner of the value and has to free it when released.
*/
struct Node {
    String value; // dynamically allocated string, release memory!
    struct Node* next; // self-reference
};
typedef struct Node Node;

/**
Create a list node. Copies the value (into dynamically allocated storage).
*/
Node* new_node(String value, Node* next) {
    Node* node = xcalloc(1, sizeof(Node));
    node->value = s_copy(value); // s_copy performs dynamic allocation
    node->next = next;
    return node;
}

/**
Prints the components of the given list.
*/
void print_list(Node* list) {
    if (list == NULL) {
        printf("[]");
    } else {
        printf("[%s", list->value);
        for (Node* n = list->next; n != NULL; n = n->next) {
            printf(", %s", n->value);
        }
        printf("]");
    }
}

/**
Print list followed by a newline.
*/
void println_list(Node* list) {
    print_list(list);
    printsln("");
}

/**
Return the number of elements in the list.
*/
int length_list(Node* list) {

int count = 0;
// wenn der Knotenpunkt nicht leer ist +1 count
while (list != NULL) {
    count++;
    // geht auf den nächsten Knotenpunkt
    list = list->next;
}
return count;
}

/**
Return the element at position.
*/
String get_list(Node* list, int position) {

int i = 0;

// Geht auf die gewünschte position in der Liste
while (list != NULL && i < position) {
    list = list->next;
    i++;
}

// Stelle existiert nicht
if (list == NULL) {
    return NULL;
}
// Gibt den Wert in der gewünschten position der Liste wieder
return list->value;
}

/**
Free all nodes of the list, including the values it contains.
*/
void free_list(Node* list) {
    Node* current = list;
    while (current != NULL) {
        Node* next_node = current->next; // Nachfolger merken
        
        // Den String löschen (behebt s_copy Leaks)
        if (current->value != NULL) {
            free(current->value); 
        }
        
        // Den Knoten löschen (behebt new_node Leaks)
        free(current); 
        
        current = next_node; // Zum nächsten Element
    }
}

/**
Adds an element to the end of the list. Modifies the existing list.
*/

Node* last_node(Node* list) {
    if (list == NULL) return NULL;
    while (list->next != NULL) {
        list = list->next;
    }
    return list;
}

Node* append_list(Node* list, String value) {    

if (list == NULL) { // wenn die Liste leer ist
    return new_node(value, NULL); 
    } else { // springt zum letzten punkt und zeigt auf einen knoten weiter
        last_node(list)->next = new_node(value, NULL);
        return list;
    }
}

// Remove element at position index from list. The element at index has to be deleted.
Node* remove_list(Node* list, int index) {
    if (list == NULL || index < 0) return list;
    if (index == 0) { // remove first element of non-empty list
        Node* n = list->next;
        free(list->value);
        free(list);
        return n;
    }
    // return second or later element of non-empty list
    int i = 0;
    // Wenn die Stelle der Liste nicht leer ist, spring ein weiter
    for (Node* node = list; node != NULL; node = node->next) {
        // hält ein punkt vorm ende an und löscht den nächsten (letzen) punkt
        if (i + 1 == index) {
            Node* to_remove = node->next;
            if (to_remove == NULL) return list;
            Node* n = to_remove->next;
            free(to_remove->value);
            free(to_remove);
            node->next = n;
            return list;
        }
        i++;
    }
    return list;
}

/**
Today's menu.
*/
const String menu[] = { "Schnitzel", "Pasta", "Veggie", "Dessert", "Salat" };

/**
The number of items on the menu.
*/
const int menu_count = sizeof(menu) / sizeof(char*);

/**
The list of completed food from the kitchen, waiting to be served. Each time a food item is served, the kitchen prepares a new food item randomly from the menu.
*/
Node* food; // List(String)

/**
The list of students standing in line and waiting for food. Each entry contains a string for the food that this student wants.
*/
Node* students; // List(String)

/**
The reputation of the mensa. The player is a staff member of the mensa. The goal of the player is to maximize the reputation of the mensa. Actually serving a dish that was asked for increases the reputation of the mensa by 1. Serving the wrong dish decreases the reputation by 1. If a student asks for a dish that is on the menu but not ready to be served, the reputation of the mensa decreases by 2.
*/
int reputation = 0;

/**
Example output:
fertige Essen: [Pasta, Veggie, Salat, Salat, Veggie]
nächster Essenswunsch: Schnitzel (3 hungrige Studierende warten)
Reputation der Mensa: 0
> 
*/
void print_situation() {
    printf("fertige Essen: ");
    print_list(food); // Nutzt deine fertige print_list Funktion
    printf("\n");

    if (students != NULL) {
        printf("nächster Essenswunsch: %s (%d hungrige Studierende warten)\n", 
                students->value, length_list(students));
    } else {
        printf("Keine wartenden Studierenden.\n");
    }

    printf("Reputation der Mensa: %d\n", reputation);
    printf("> ");
}

/**
Print final message, release all dynamically allocated memory, and exit the program.
Fertig für heute. Die Mensa schließt.
Finale Reputation der Mensa: 3
*/
// Hilfsfunktion zum Freigeben der Liste

void finish(void) { // 'void' in den Klammern bedeutet: keine Parameter
    printf("Fertig für heute. Die Mensa schließt.\n");
    printf("Finale Reputation der Mensa: %d\n", reputation);
    
    // Wir räumen die globalen Listen auf
    free_list(food);
    free_list(students);
    
    exit(0);
}

/**
Run the mensa simulation.

The mensa person then enters the (0-based) index from the list of food. -1 stands for "not available". -2 ends the program. 

Here is an example dialog:

fertige Essen: [Salat, Veggie, Veggie, Pasta, Dessert]
nächster Essenswunsch: Pasta (3 hungrige Studierende warten)
Reputation der Mensa: 0
> 3
Vielen Dank! Ich liebe die Mensa!
fertige Essen: [Salat, Veggie, Veggie, Dessert, Dessert]
nächster Essenswunsch: Pasta (3 hungrige Studierende warten)
Reputation der Mensa: 1
> -1
Pasta ist nicht da? Schade.
fertige Essen: [Salat, Veggie, Veggie, Dessert, Dessert]
nächster Essenswunsch: Salat (2 hungrige Studierende warten)
Reputation der Mensa: -1
> 0
Vielen Dank! Ich liebe die Mensa!
fertige Essen: [Veggie, Veggie, Dessert, Dessert, Dessert]
nächster Essenswunsch: Dessert (2 hungrige Studierende warten)
Reputation der Mensa: 0
> 1
Veggie möchte ich nicht! Ich möchte Dessert!
fertige Essen: [Veggie, Veggie, Dessert, Dessert, Dessert]
nächster Essenswunsch: Schnitzel (1 hungrige Studierende warten)
Reputation der Mensa: -1
> 1
Veggie möchte ich nicht! Ich möchte Schnitzel!
Fertig für heute. Die Mensa schließt.
Reputation der Mensa: -2
*/
void run_mensa() {
    // 1. Initialisierung: 5 zufällige Essen kochen
    for (int i = 0; i < 5; i++) {
        food = append_list(food, menu[i_rnd(menu_count)]);
    }
    // 2. Initialisierung: 3 wartende Studenten mit Wünschen
    for (int i = 0; i < 3; i++) {
        students = append_list(students, menu[i_rnd(menu_count)]);
    }

    while (true) {
        print_situation(); // Zeigt Essen, nächsten Wunsch und Reputation an
        
        int input = i_input(); // Eingabe des Index

        if (input == -2) {
            finish(); // Beendet Simulation
            return;
        }

        // Falls keine Studenten mehr da sind (Sicherheitsabfrage)
        if (students == NULL) {
            printf("Keine Studierenden mehr in der Schlange.\n");
            break;
        }

        String wunsch = students->value;

        if (input == -1) {
            // Wunsch kann nicht erfüllt werden
            printf("%s ist nicht da? Schade.\n", wunsch);
            reputation -= 2;
            // Student verlässt die Schlange enttäuscht
            students = remove_list(students, 0);
        } else {
            // Ein Gericht wird ausgewählt
            String serviert = get_list(food, input);
            
            if (serviert == NULL) {
                printf("Dieses Essen existiert nicht an Index %d!\n", input);
                continue;
            }

            if (s_equals(serviert, wunsch)) {
                // ERFOLG: Richtiger Wunsch
                printf("Vielen Dank! Ich liebe die Mensa!\n");
                reputation += 1;
                
                // Essen wird aus der Küche genommen und ein neues gekocht
                food = remove_list(food, input);
                food = append_list(food, menu[i_rnd(menu_count)]);
                
                // Student verlässt zufrieden die Schlange
                students = remove_list(students, 0);
                
                // Belohnung: Ein neuer Student kommt dazu
                students = append_list(students, menu[i_rnd(menu_count)]);
            } else {
                // FEHLER: Falsches Essen
                printf("%s möchte ich nicht! Ich möchte %s!\n", serviert, wunsch);
                reputation -= 1;
                // Das Essen wird zurückgenommen (bleibt also in der Liste 'food')
                // Der Student bleibt in der Schlange (wird nicht entfernt)
            }
        }

        // Wenn die Schlange leer sein sollte (theoretisch)
        if (students == NULL) break;
    }
    finish();
}

int main(void) {
    report_memory_leaks(true);
    run_mensa();
    return 0;
}
