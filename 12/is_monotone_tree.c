#include "base.h"
#include <limits.h>

typedef struct s_Node
{
    int value;
    struct s_Node *left;
    struct s_Node *right;
} Node;

Node *new_node(Node *left, int value, Node *right)
{
    Node *new = xmalloc(sizeof(Node));
    new->value = value;
    new->left = left;
    new->right = right;
    return new;
}

Node *leaf(int value)
{
    return new_node(NULL, value, NULL);
}

void print_tree(Node *node, int depth)
{
    if (node == NULL)
        return;
    for (int i = 0; i < depth; ++i)
    {
        printf(" ");
    }
    printf("%d\n", node->value);
    print_tree(node->left, depth + 1);
    print_tree(node->right, depth + 1);
}

// TODO: Die Funktion soll überprüfen, ob ein Baum monoton ist.
//  Ein Knoten ist monoton, wenn der Wert nicht größer ist, als die Werte der unmittelbaren Kinder.
//  Ein leerer Baum ist immer monoton.

bool is_monotone_tree_recursive(Node *node, int min)
{
    if (node == NULL)
    {
        return true;
    }

    bool left_is_ok = is_monotone_tree_recursive(node->left, node->value);
    bool right_is_ok = is_monotone_tree_recursive(node->right, node->value);

    if (node->value >= min && left_is_ok && right_is_ok)
    {
        return true;
    }
    else
    {
        return false;
    }

    return true;
}

bool is_monotone_tree(Node *node)
{
    return is_monotone_tree_recursive(node, INT_MIN);
}

int main()
{
    test_equal_b(is_monotone_tree(NULL), true);
    /*
    NULL
    */

    test_equal_b(is_monotone_tree(leaf(1)), true);
    /*
            1
           / \
          N   N
    */

    Node *t0 = new_node(leaf(6), 5, leaf(2));
    test_equal_b(is_monotone_tree(t0), false);
    /*
            5
           / \
          6   2
         / \ / \
        N  N N  N
    */

    Node *t1 = new_node(new_node(new_node(leaf(3), 5, leaf(2)), 10, new_node(leaf(1), 4, leaf(0))), 20, new_node(new_node(leaf(3), 5, leaf(2)), 8, new_node(leaf(6), 6, leaf(4))));
    test_equal_b(is_monotone_tree(t1), false);
    /*
                20
              /    \
            10      8
           /  \    / \
          5    4  5   6
         / \  / \ / \ / \
        3  2 1  0 3  2 6  4
       /\/\ /\/\ /\/\ /\/\
       N N N N N N N N N N N N N N N N
    */

    Node *t2 = new_node(new_node(new_node(leaf(3), 5, leaf(2)), 10, new_node(leaf(1), 4, leaf(8))), 20, new_node(new_node(leaf(3), 5, leaf(2)), 8, new_node(leaf(6), 6, leaf(4))));
    test_equal_b(is_monotone_tree(t2), false);
    /*
                20
              /    \
            10      8
           /  \    / \
          5    4  5   6
         / \  / \ / \ / \
        3  2 1  8 3  2 6  4
       /\/\ /\/\ /\/\ /\/\
       N N N N N N N N N N N N N N N N
    */

    Node *t3 = new_node(new_node(new_node(leaf(3), 5, leaf(2)), 10, new_node(leaf(1), 4, leaf(0))), 20, new_node(new_node(leaf(3), 5, leaf(2)), 6, new_node(leaf(6), 7, leaf(4))));
    test_equal_b(is_monotone_tree(t3), false);
    /*
                20
              /    \
            10      6
           /  \    / \
          5    4  5   7
         / \  / \ / \ / \
        3  2 1  0 3  2 6  4
       /\/\ /\/\ /\/\ /\/\
       N N N N N N N N N N N N N N N N
    */
}