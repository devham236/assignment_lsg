// nodes_equal_to_parent(Aus Assignment14)

#include <stdlib.h>
#include <stdio.h>
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *newNode(int data)
{
    TreeNode *new = malloc(sizeof(TreeNode));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
}

int equalNodes(TreeNode *head)
{
    int result = 0;
    if (head != NULL)
    {
        if (head->left != NULL)
        {
            if (head->data == head->left->data)
            {
                result++;
            }
            result += equalNodes(head->left);
        }
        if (head->right != NULL)
        {
            if (head->data == head->right->data)
            {
                result++;
            }
            result += equalNodes(head->left);
        }
    }
    return result;
}

int main()
{
    TreeNode *test = newNode(2);
    test->left = newNode(2);
    // test->right = newNode(2);
    // test->left->left = newNode(2);
    // test->left->left->left = newNode(2);
    printf("%d\n", equalNodes(test));
}