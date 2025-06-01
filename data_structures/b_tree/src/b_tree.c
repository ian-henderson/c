#include "b_tree.h"
#include "b_tree_node.h"

#include <stdio.h>  // perror, printf
#include <stdlib.h> // calloc, exit, EXIT_FAILURE

b_tree_t *b_tree_create() {
    b_tree_t *tree = calloc(1, sizeof(*tree));

    if (!tree) {
        perror("b_tree memory allocation failed");
        exit(EXIT_FAILURE);
    }

    return tree;
}

int b_tree_delete(b_tree_t *tree, int key) {
    if (!tree)
        return 1;

    return b_tree_node_delete(tree->head, key);
}

void b_tree_destroy(b_tree_t **tree) {
    b_tree_node_destroy(&((*tree)->head));
    free(*tree);
    *tree = NULL;
}

int b_tree_height(b_tree_t *tree) {
    if (!tree) {
        perror("Tree is null.");
        return -1;
    }

    return b_tree_node_height(tree->head);
}

int b_tree_insert(b_tree_t *tree, int key) {
    if (!tree)
        return 1;

    b_tree_node_insert(&tree->head, key);

    return 0;
}

void b_tree_print(b_tree_t *tree) {
    if (!tree->head) {
        perror("Tree is empty");
        return;
    }

    b_tree_node_print_inorder(tree->head);

    printf("\n");
}

int b_tree_search(b_tree_t *tree, int key) {
    if (!tree)
        return 1;

    return b_tree_node_search(tree->head, key);
}
