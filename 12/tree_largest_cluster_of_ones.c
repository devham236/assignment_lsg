/*
make tree_largest_cluster_of_ones && ./tree_largest_cluster_of_ones
*/
#include "base.h"

typedef struct Tree
{
    int value;
    struct Tree *left;
    struct Tree *right;
} Tree;

Tree *new_tree(Tree *left, int value, Tree *right)
{
    Tree *tree = malloc(sizeof(Tree));

    *tree = (Tree){
        .value = value,
        .left = left,
        .right = right,
    };

    return tree;
}

int largest_cluster_of_ones_recursive(Tree *tree, int count)
{
    if (tree == NULL)
    {
        return count;
    }

    if (tree->value == 0)
    {
        return 0;
    }

    if (tree->value == 1)
    {
        count++;
    }

    int left_tree = largest_cluster_of_ones_recursive(tree->left, count);

    return left_tree;
}

// <purpose statement>
int largest_cluster_of_ones(Tree *root)
{
    // todo: implement
    return largest_cluster_of_ones_recursive(root, 0);
}

void test(void)
{
    Tree *t1 = new_tree(NULL, 1, NULL);
    test_equal_i(largest_cluster_of_ones(t1), 1);
    /*
        1
    */

    Tree *t2 = new_tree(new_tree(NULL, 1, NULL), 1, NULL);
    test_equal_i(largest_cluster_of_ones(t2), 2);
    /*
          1
         /
        1
    */

    // Tree *t3 = new_tree(
    //     new_tree(
    //         new_tree(
    //             new_tree(NULL, 1, NULL),
    //             1,
    //             new_tree(NULL, 1, NULL)),
    //         1,
    //         new_tree(NULL, 0, NULL)),
    //     0,
    //     new_tree(
    //         NULL,
    //         0,
    //         new_tree(
    //             new_tree(NULL, 1, NULL),
    //             1,
    //             new_tree(NULL, 1, NULL))));
    // test_equal_i(largest_cluster_of_ones(t3), 0);
    /*
                0
               / \
              1   0
             / \   \
            1   0   0
           / \     / \
          1   1   1   1
                 / \
                1   1
    */

    // Tree *t4 = new_tree(
    //     new_tree(
    //         new_tree(NULL, 1, NULL),
    //         0,
    //         new_tree(NULL, 1, NULL)),
    //     1,
    //     new_tree(
    //         new_tree(NULL, 1, NULL),
    //         1,
    //         new_tree(NULL, 1, NULL)));
    // test_equal_i(largest_cluster_of_ones(t4), 4);
    /*
                1 (Wurzel)
               / \
              0   1
             / \ / \
            1  1 1  1
    */

    // Tree *t5 = new_tree(
    //     new_tree(
    //         new_tree(NULL, 0, NULL),
    //         1,
    //         new_tree(NULL, 1, NULL)),
    //     1,
    //     new_tree(
    //         new_tree(NULL, 1, NULL),
    //         0,
    //         new_tree(NULL, 1, NULL)));
    // test_equal_i(largest_cluster_of_ones(t5), 3);
    /*
                1
               / \
              1   0
             / \ / \
            0  1 1  1
    */

    // Tree *t6 = new_tree(
    //     new_tree(
    //         new_tree(NULL, 0, NULL),
    //         1,
    //         new_tree(NULL, 1, NULL)),
    //     1,
    //     new_tree(
    //         new_tree(NULL, 1, NULL),
    //         1,
    //         new_tree(NULL, 0, NULL)));
    // test_equal_i(largest_cluster_of_ones(t6), 5);
    /*
                1
               / \
              1   1
             / \ / \
            0  1 1  0
    */

    // Tree *t7 = new_tree(
    //     new_tree(
    //         new_tree(
    //             new_tree(NULL, 1, NULL),
    //             0,
    //             new_tree(NULL, 1, NULL)),
    //         1,
    //         new_tree(NULL, 0, NULL)),
    //     1,
    //     new_tree(
    //         NULL,
    //         0,
    //         new_tree(
    //             new_tree(NULL, 1, NULL),
    //             1,
    //             new_tree(NULL, 1, NULL))));
    // test_equal_i(largest_cluster_of_ones(t7), 2);
    /*
                1
               / \
              1   0
             / \   \
            0   0   1
           / \     / \
          1   1   1   1
    */
}

int main(void)
{
    test();
    return 0;
}