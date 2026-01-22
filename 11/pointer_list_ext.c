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
Node* take_list(Node* list, int n) {
    // TODO: a)
    if (list == NULL || n <= 0) {
        return NULL;
    }

    // Erster Knoten der neuen Liste
    Node* result = new_node(list->value, NULL);
    Node* current_new = result;
    Node* current_old = list->next;

    int count = 1;
    while (current_old != NULL && count < n) {
        current_new->next = new_node(current_old->value, NULL);
        current_new = current_new->next;
        current_old = current_old->next;
        count++;
    }

    return result;
}

// Create a list consisting of nodes of list, except the first n.
Node* drop_list(Node* list, int n) {
    // TODO: b)
    // n Elemente überspringen
    Node* current = list;
    while (current != NULL && n > 0) {
        current = current->next;
        n--;
    }

    // Falls nichts mehr übrig ist
    if (current == NULL) {
        return NULL;
    }

    // erste Node der neuen Liste
    Node* result = new_node(current->value, NULL);
    Node* current_new = result;
    current = current->next;

    // Rest kopieren
    while (current != NULL) {
        current_new->next = new_node(current->value, NULL);
        current_new = current_new->next;
        current = current->next;
    }

    return result;
}

// Take alternatingly from list1 and list2 until all data is collected in the result.
Node* interleave(Node* list1, Node* list2) {
    // TODO: c)
    Node* result = NULL;
    Node* tail = NULL;

    while (list1 != NULL || list2 != NULL) {

        if (list1 != NULL) {
            Node* n = new_node(list1->value, NULL);
            if (result == NULL) {
                result = n;
                tail = n;
            } else {
                tail->next = n;
                tail = n;
            }
            list1 = list1->next;
        }

        if (list2 != NULL) {
            Node* n = new_node(list2->value, NULL);
            if (result == NULL) {
                result = n;
                tail = n;
            } else {
                tail->next = n;
                tail = n;
            }
            list2 = list2->next;
        }
    }

    return result;
    return NULL;
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
    Node* groups = NULL;  // Liste von Gruppen

    for (Node* cur = list; cur != NULL; cur = cur->next) {
        bool found = false;

        // Suche passende Gruppe
        for (Node* g = groups; g != NULL; g = g->next) {
            Node* group = g->value;  // eine Gruppe (Liste)

            if (equivalent(cur->value, group->value)) {
                // Element zur Gruppe hinzufügen (vorne)
                g->value = new_node(cur->value, group);
                found = true;
                break;
            }
        }

        // Falls keine passende Gruppe existiert
        if (!found) {
            Node* new_group = new_node(cur->value, NULL);
            groups = new_node(new_group, groups);
        }
    }

    return groups;
    return NULL;
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
