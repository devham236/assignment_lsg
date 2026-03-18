
/*
Compile: make is_search_tree
Run: ./is_search_tree
make is_search_tree && ./is_search_tree
*/

#include "base.h"

typedef struct Tree Tree;

struct Tree {
    int value;
    Tree* left;
    Tree* right;
};

Tree* new_tree(Tree* left, int value, Tree* right) {
    Tree* n = xcalloc(1, sizeof(Tree));
    n->left = left;
    n->value = value;
    n->right = right;
    return n;
}

bool is_search_tree(Tree* t) {
    // implement...
    return false;
}

Tree* leaf(int value) {
    return new_tree(NULL, value, NULL);
}

Tree* node(Tree* left, int value, Tree* right) {
    return new_tree(left, value, right);
}

void test(void) {
    Tree* t;

    // empty tree
    t = NULL;
    test_equal_b(is_search_tree(t), true);
    
    // one-element tree
    t = leaf(100);
    test_equal_b(is_search_tree(t), true);
    
    // one-element tree
    t = leaf(-100);
    test_equal_b(is_search_tree(t), true);

    //   1000
    // 124  110
    t = node(leaf(124), 1000, leaf(110));
    test_equal_b(is_search_tree(t), false);

    //   1000
    // 1240  110
    t = node(leaf(1240), 1000, leaf(110));
    test_equal_b(is_search_tree(t), false);

    //    100
    // -10   110
    t = node(leaf(-10), 100, leaf(110));
    test_equal_b(is_search_tree(t), true);
    
    //   1000
    // 124  
    t = node(leaf(124), 1000, NULL);
    test_equal_b(is_search_tree(t), true);

    //   1000
    // 1240  
    t = node(leaf(1240), 1000, NULL);
    test_equal_b(is_search_tree(t), false);

    //    2 
    //       3
    t = node(NULL, 2, leaf(3));
    test_equal_b(is_search_tree(t), true);
    
    //    2 
    //       2
    t = node(NULL, 2, leaf(2));
    test_equal_b(is_search_tree(t), false);
    
    //  -101
    //  2   5
    // 2 3 4 6
    t = node(node(leaf(2), 2, leaf(3)), -101, node(leaf(4), 5, leaf(6)));
    test_equal_b(is_search_tree(t), false);

    //    4
    //  2   6
    // 1 3 5 7
    t = node(node(leaf(1), 2, leaf(3)), 4, node(leaf(5), 6, leaf(7)));
    test_equal_b(is_search_tree(t), true);

    //            4
    //       2        6
    //     0    3   5   7
    //  -1  1
    t = node(node(node(leaf(-1), 0, leaf(1)), 2, leaf(3)), 4, node(leaf(5), 6, leaf(7)));
    test_equal_b(is_search_tree(t), true);

    //            4
    //       2        6
    //     0    3   5   7
    //  -1  0
    t = node(node(node(leaf(-1), 0, leaf(0)), 2, leaf(3)), 4, node(leaf(5), 6, leaf(7)));
    test_equal_b(is_search_tree(t), false);

}

int main(void) {
    test();
    return 0;
}
