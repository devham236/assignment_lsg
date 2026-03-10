// Schreiben Sie eine Methode, die überprüft, ob ein Child-Node
// in einem Binärbaum den gleichen Wert hat wie sein Parent-Node.
// Sie dürfen dazu eine Hilfsmethode schreiben.
// (Restliche Funktionalität des Binärbaums und Tests gegeben)

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "base.h"
#include <limits.h>

typedef struct IntTree
{
    int data;
    struct IntTree *left;
    struct IntTree *right;
} IntTree;

IntTree *newNode(int data)
{
    IntTree *temp = malloc(sizeof(IntTree));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void inOrderPrint(IntTree *head)
{
    if (head != NULL)
    {
        inOrderPrint(head->left);
        printf("%d,", head->data);
        inOrderPrint(head->right);
    }
}

IntTree *createRandomTree(int treeEntries[], IntTree *node, int index, int arrayLength)
{
    IntTree *temp = NULL;
    if (index < arrayLength)
    {
        temp = newNode(treeEntries[index]);
        node = temp;
        node->left = createRandomTree(treeEntries, node->left, 2 * index + 1, arrayLength);
        node->right = createRandomTree(treeEntries, node->right, 2 * index + 2, arrayLength);
    }
    return temp;
}

bool checkParentChild(IntTree *node)
{
    if (node == NULL)
    {
        return false;
    }

    if (node->left != NULL && node->left->data == node->data)
    {
        return true;
    }

    if (node->right != NULL && node->right->data == node->data)
    {
        return true;
    }

    return checkParentChild(node->left) || checkParentChild(node->right);
}

void test()
{
    // Fall 1: Leerer Baum
    test_equal_b(checkParentChild(NULL), false);

    // Fall 2: Nur ein Knoten (keine Kinder, also keine Übereinstimmung möglich)
    IntTree *single = newNode(5);
    test_equal_b(checkParentChild(single), false);

    // Fall 3: Baum ohne Übereinstimmung
    //      10
    //     /  \
    //    5    15
    IntTree *noMatch = newNode(10);
    noMatch->left = newNode(5);
    noMatch->right = newNode(15);
    test_equal_b(checkParentChild(noMatch), false);

    // Fall 4: Übereinstimmung direkt an der Wurzel (links)
    //      10
    //     /  \
    //    10   15
    IntTree *matchRoot = newNode(10);
    matchRoot->left = newNode(10);
    matchRoot->right = newNode(15);
    test_equal_b(checkParentChild(matchRoot), true);
}

int main()
{
    test();
    return 0;
}