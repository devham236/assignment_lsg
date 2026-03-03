// Knoten auf der Konsole ausgeben, die sowohl über einen linken, als auch einen rechten
// Nachfolger verfügen und deren rechter Nachfolger größer ist als der linke Nachfolger.
// Nehmen Sie dabei an, dass der Baum unsortiert ist.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

void printSorted(IntTree *node)
{
    if (node != NULL)
    {
        printSorted(node->left);
        if (node->left != NULL && node->right != NULL && node->left->data < node->right->data)
        {
            printf("%d, ", node->data);
        }
        printSorted(node->right);
    }
}

int main()
{
    IntTree *root = newNode(0);
    int upperLimit = 18;
    int entries[upperLimit];
    int *results = malloc(sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < upperLimit; i++)
    {
        int randomEntry = rand() % (upperLimit);
        entries[i] = randomEntry;
    }
    root = createRandomTree(entries, root, 0, upperLimit);
    inOrderPrint(root);
    printf("\n");
    printSorted(root);
    printf("\n");
}