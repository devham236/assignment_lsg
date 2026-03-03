// a) Implementieren Sie die Funktion "int levels(Tree *tree)", die zurückgibt, wie
// hoch ein Baum ist. Dabei hat ein leerer Baum (tree == NULL) die Höhe 0, ein Baum
// ohne Nachfolger (tree->left == NULL && tree->right == NULL) die Höhe 1 usw.
// Die Implementierung sollte auch für asymmetrische Bäume gelten. Wenn ich mich
// richtig erinnere, gab es keine min/max stack/queue Hilfsfunktionen - die musste
// man ggf. selbst implementieren.
// b) (Nicht mehr ganz sicher, ungefähr so): implementieren Sie eine Funktion
// "void count_leaves_per_level(Tree *tree, int level, int *results)", die die
// Anzahl an Blättern einer n-ten Ebene zählt und diesen Wert dann in das n-te
// Element des übergebenen results-Arrays schreibt. Als Blatt zählen Knoten, die
// keine Nachfolger haben.

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

// a) Implementieren Sie die Funktion "int levels(Tree *tree)", die zurückgibt, wie
// hoch ein Baum ist. Dabei hat ein leerer Baum (tree == NULL) die Höhe 0, ein Baum
// ohne Nachfolger (tree->left == NULL && tree->right == NULL) die Höhe 1 usw.
// Die Implementierung sollte auch für asymmetrische Bäume gelten. Wenn ich mich
// richtig erinnere, gab es keine min/max stack/queue Hilfsfunktionen - die musste
// man ggf. selbst implementieren.

int treeLevels(TreeNode *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = treeLevels(node->left);
        int rDepth = treeLevels(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

// b) (Nicht mehr ganz sicher, ungefähr so): implementieren Sie eine Funktion
// "void count_leaves_per_level(Tree *tree, int level, int *results)", die die
// Anzahl an Blättern einer n-ten Ebene zählt und diesen Wert dann in das n-te
// Element des übergebenen results-Arrays schreibt. Als Blatt zählen Knoten, die
// keine Nachfolger haben.

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
    int upperLimit = 15;
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
    for (int i = 0; i < treeLevels(root) + 1; i++)
    {
        printf("%d. level: ", i);
        countLeavesPerLevel(root, i, results);
        printf("\n");
    }
}