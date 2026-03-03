// Aus einem Tree den Pfad mit dem größten Wert ausgeben

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

int treeLevels(TreeNode *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lDepth = treeLevels(node->left);
        int rDepth = treeLevels(node->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

// This function returns overall maximum path sum in 'res'
// And returns max path sum going through root.
int findMax(TreeNode *root, int res)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftValue = findMaxUtil(root->left, res);
    int rightValue = findMaxUtil(root->right, res);

    int max_single = max(max(leftValue, rightValue) + root->data, root->data);
    int max_top = max(max_single, leftValue + rightValue + root->data);

    if (root->left && root->right)
        printf("%d\n", max_top);

    return max_single;
}

int main()
{
    int upperLimit = 7;
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
    findMax(root, 0);
}