// Summe aller rechten Nachfolger
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

int leftWeight = 0;
int rightWeight = 0;
int getWeight(IntTree *node)
{
    if (node != NULL)
    {
        leftWeight += getWeight(node->left);
        rightWeight += getWeight(node->right);
        return node->data;
    }
}

IntTree *weightBalancedTree(IntTree *node, IntTree *result)
{
    if (node != NULL)
    {
        leftWeight += getWeight(node->left);
        rightWeight += getWeight(node->right);
        if (leftWeight <= rightWeight)
        {
            result->left = newNode(node->data);
        }
        else
        {
            result->right = newNode(node->data);
        }
        printf("right: %d <--> left: %d\n", rightWeight, leftWeight);
        return result;
    }
}

int main()
{
    IntTree *root = newNode(0);
    IntTree *result = newNode(0);
    int upperLimit = 10;
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

    // printf("%d\n", weightBalancedTree(root, result));
    inOrderPrint(weightBalancedTree(root, result));
    printf("\n");
}