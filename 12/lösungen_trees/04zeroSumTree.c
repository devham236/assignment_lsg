// Überprüft, ob Knotensumme im Baum == 0, also alle Knoten haben 0 als value oder komplett leer.

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

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

bool result = true;
bool zeroSumTree(IntTree *node)
{
    if (node != NULL)
    {
        if (node->left != NULL && node->right != NULL)
        {
            zeroSumTree(node->left);
            if (node->left->data != 0 || node->right->data != 0 || node->data != 0)
            {
                result = false;
            }
            zeroSumTree(node->right);
        }
    }
    return result;
}

int main()
{
    IntTree *root = newNode(0);
    int upperLimit = 18;
    int entries[upperLimit];
    int *results = malloc(sizeof(int));
    srand(time(NULL));
    int decider = 0;
    for (int i = 0; i < upperLimit; i++)
    {
        entries[i] = 0;
        // if (decider % 2 == 0)
        // {
        //     int randomEntry = rand() % 30;
        //     entries[i] = randomEntry;
        // }
        // else
        // {
        //     int randomEntry = 0 - (rand() % 30);
        //     entries[i] = randomEntry;
        // }
        // decider++;
    }
    root = createRandomTree(entries, root, 0, upperLimit);
    inOrderPrint(root);
    printf("\n");
    printf("%d\n", zeroSumTree(root));
}