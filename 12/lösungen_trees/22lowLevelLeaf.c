// Das Leaf mit dem niedrigsten Level in einer Baumstruktur berechnen

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void countLeavesPerLevel(TreeNode *node, int level, int *results)
{
    if (node == NULL)
    {
        return;
    }
    if (level == 1)
    {
        if (node->left == NULL && node->right == NULL)
        {
            results[level] = node->data;
            printf("%d, ", results[level]);
        }
    }
    else if (level > 1)
    {
        countLeavesPerLevel(node->left, level - 1, results);
        countLeavesPerLevel(node->right, level - 1, results);
    }
}

int main()
{
    int upperLimit = 18;
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
    printf("tree height: %d\n", treeLevels(root));
    for (int i = treeLevels(root); i < treeLevels(root) + 1; i++)
    {
        printf("%d. level: ", i);
        countLeavesPerLevel(root, i, results);
        printf("\n");
    }
}