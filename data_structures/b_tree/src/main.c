#include "b_tree.h"

#include <stdio.h>  // printf
#include <stdlib.h> // rand, srand
#include <time.h>   // time

void result_print(int result, int key) {
    if (result == 0)
        printf("Found %d\n", key);
    else if (result == 1)
        printf("Did not find %d\n", key);
}

int main(void) {
    b_tree_t *tree = b_tree_create();

    // Check that search handles empty tree case
    result_print(b_tree_search(tree, 1), 1);
    result_print(b_tree_search(tree, 0), 0);
    result_print(b_tree_search(tree, -1), -1);

    // Populate tree with random numbers
    srand(time(NULL));
    int n = 100000;
    for (int i = 0; i < n; i++)
        b_tree_insert(tree, rand());
    printf("Added %d random keys\n", n);

    // Check that search works
    int keys[] = {-1, 666, 69, 420, 8675309};
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        b_tree_insert(tree, keys[i]);
        result_print(b_tree_search(tree, keys[i]), keys[i]);
    }

    printf("tree height: %d\n", b_tree_height(tree));
    printf("M: %d\n", M);

    b_tree_destroy(&tree);
}
