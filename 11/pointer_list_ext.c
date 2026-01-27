/*
    Compile: make pointer_list_ext
    Run: ./pointer_list_ext
    make pointer_list_ext && ./pointer_list_ext
*/

#include "pointer_list.h"

// String -> String
// Copies a string for printing (and later release).
String string_to_string(void* x) {
    return s_copy(x);
}

// String -> voidtake_list
// Releases a string.
void free_string(void* x) {
    free(x);
}

// Create a list consisting of the first n nodes of list.
// Zum Beispiel: 
// list = ["a" -> "bb" -> "ccc" -> "dd" -> "e"]
// take_list(list, 3)
// Ausgabe -> ["a" -> "bb" -> "ccc"]
Node* take_list(Node* list, int n) {
    // TODO: a)
    if (n <= 0 || list == NULL) return NULL;

    Node* result = NULL; // Anfang der neuen Liste
    Node* tail = NULL; // letztes Element der neuen Liste zum Anhängen

    while (list != NULL && n-- > 0) { // Prüfe erstmal ob n < 0 und danach n = n - 1
        Node* node = new_node(list->value, NULL); // neues Listenelement wird erstellt
        if (result == NULL) {
            result = node; // wenn es die erste Node ist, dann ist der Wert "node"
        } else {
            tail->next = node; // sonst an next ranhängen
        }
        tail = node; // danach tail auf das neue Ende setzen
        list = list->next; // in der Originalliste weitergehen
    }

    return result;
}

// Create a list consisting of nodes of list, except the first n.
/*
Beispiel:
list = [ "a" -> "bb" -> "ccc" -> "dd" -> "e" ]
drop_list(list, 3)
Ausgabe -> [ "dd" -> "e" ]
*/
Node* drop_list(Node* list, int n) {
    // TODO: b)
    // Überspringe die ersten n Elemente

    // erster while loop positioniert den Pointer, also überspringt die ersten n Elemente
    while (list != NULL && n-- > 0) {
        list = list->next; // Listen pointer wird weiter bewegt bis zur gewünschten Stelle und da macht der zweite loop dann weiter(dadurch ist value dann der nächste Eintrag und der nächste Eintrag dann ein weiter)
    }

    if (list == NULL) return NULL;

    Node* result = NULL; // wieder start der neuen Liste
    Node* tail = NULL; // und Ende

    // zweiter while loop erzeugt die neuen Nodes, hängt sie an result und läuft bis zum Ende der Liste
    while (list != NULL) {
        Node* node = new_node(list->value, NULL);
        if (result == NULL) {
            result = node;
        } else {
            tail->next = node;
        }
        tail = node;
        list = list->next;
    }

    return result;
}

// Take alternatingly from list1 and list2 until all data is collected in the result.
/*
Beispiel:
list1 = a -> bb -> ccc
list2 = dd -> e
interleave(list1, list2)
Ausgabe: a -> dd -> bb -> e -> ccc
*/
Node* interleave(Node* list1, Node* list2) {
    // TODO: c)
    Node* result = NULL;
    Node* tail = NULL;

    while (list1 != NULL || list2 != NULL) { // Läuft solange Liste 1 oder Liste 2 Elemente hat
        Node* lists[2] = {list1, list2}; // Array mit den zwei Listen
        for (int i = 0; i < 2; i++) {
            if (lists[i] != NULL) {
                Node* node = new_node(lists[i]->value, NULL);
                if (result == NULL) {
                    result = node;
                } else {
                    tail->next = node;
                }
                tail = node;

                // Richtige Liste vorwärts bewegen
                if (i == 0) list1 = list1->next;
                else list2 = list2->next;
            }
        }
    }

    return result;
}

// typedef bool (*EqualFun)(void* element1, void* element2);

bool group_by_length(void* element1, void* element2) {
    String s1 = element1;
    String s2 = element2;
    return s_length(s1) == s_length(s2);
}

// Group elements in list. Equivalent elements (for which equivalent is true) are put
// in the same group. The result is a list of groups. Each group is itself a list.
// Each group contains items that are equivalent.
Node* group_list(Node* list, EqualFun equivalent) {
    // TODO: d)
    Node* groups = NULL;

    for (Node* cur = list; cur != NULL; cur = cur->next) {
        Node* matching_group = NULL;

        // Suche passende Gruppe
        for (Node* g = groups; g != NULL; g = g->next) {
            Node* group = g->value;
            if (equivalent(cur->value, group->value)) {
                matching_group = group;
                break;
            }
        }

        if (matching_group) {
            // Element ans Ende der Gruppe anhängen
            Node* tail = matching_group;
            while (tail->next != NULL) tail = tail->next;
            tail->next = new_node(cur->value, NULL);
        } else {
            // Neue Gruppe erstellen
            Node* new_group = new_node(cur->value, NULL);
            groups = new_node(new_group, groups);
        }
    }

    return groups;
}

void free_group(void* x) {
    Node* list = x;
    free_list(list, NULL);
}

int main(void) {
    report_memory_leaks(true);

    Node* list = new_node("a", new_node("bb", new_node("ccc", new_node("dd", new_node("e", NULL)))));
    println_list(list, string_to_string);

    prints("take_list: ");
    Node* list2 = take_list(list, 3);
    println_list(list2, string_to_string);

    prints("drop_list: ");
    Node* list3 = drop_list(list, 3);
    println_list(list3, string_to_string);

    prints("interleave: ");
    Node* list4 = interleave(list2, list3);
    println_list(list4, string_to_string);
    free_list(list2, NULL);
    free_list(list3, NULL);
    free_list(list4, NULL);

    Node* groups = group_list(list, group_by_length);
    printf("%d groups:\n", length_list(groups));
    for (Node* n = groups; n != NULL; n = n->next) {
        println_list(n->value, string_to_string);
    }

    free_list(groups, free_group);
    free_list(list, NULL);

    return 0;
}
