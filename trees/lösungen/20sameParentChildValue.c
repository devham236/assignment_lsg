// Anzahl der Knoten in einem Baum die den selben Wert wie ihre Eltern haben

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *newNode(int data)
{
    TreeNode *temp = malloc(sizeof(TreeNode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inOrderPrint(TreeNode *node)
{
    if (node != NULL)
    {
        inOrderPrint(node->left);
        printf("%d ", node->data);
        inOrderPrint(node->right);
    }
}

void printAsTree(TreeNode *root, int space)
{
    int count = 10;

    if (root == NULL)
    {
        return;
    }

    space += count;
    printAsTree(root->right, space);

    printf("\n");

    for (int i = count; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);
    printAsTree(root->left, space);
}

TreeNode *createRandomTree(int treeEntries[], TreeNode *node, int index, int arrayLength)
{
    TreeNode *temp = NULL;
    if (index < arrayLength)
    {
        temp = newNode(treeEntries[index]);
        node = temp;
        node->left = createRandomTree(treeEntries, node->left, 2 * index + 1, arrayLength);
        node->right = createRandomTree(treeEntries, node->right, 2 * index + 2, arrayLength);
    }
    return temp;
}

int result = 0;
int amountSameParentChild(TreeNode *node)
{
    if (node != NULL && node->left != NULL && node->right != NULL)
    {
        amountSameParentChild(node->left);
        if (node->data == node->right->data || node->data == node->left->data)
        {
            result++;
            // printf("%d ", node->data);
        }
        amountSameParentChild(node->right);
    }
    return result;
}

int main()
{
    int upperLimit = 10;
    int entries[upperLimit];
    int *results = malloc(sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < upperLimit; i++)
    {
        int randomEntry = rand() % (upperLimit);
        entries[i] = randomEntry;
    }
    TreeNode *root = newNode(0);
    root = createRandomTree(entries, root, 0, upperLimit);
    printAsTree(root, 10);
    printf("%d\n", amountSameParentChild(root));
}