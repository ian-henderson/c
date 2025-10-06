#include "tree.h"

#include "stdio.h"
#include "stdlib.h"

tree_t *tree_create() {
    tree_t *t = malloc(sizeof(*t));
    t->head = NULL;
    return t;
}

void tree_destroy(tree_t *t) {
    node_destroy(t->head);
    free(t);
}

int tree_has_value(tree_t *t, int val) {
    if (!t->head)
        return 1;

    return node_has_value(t->head, val);
}

int tree_height(tree_t *t) {
    if (!t->head)
        return 0;

    return node_height(t->head);
}

void tree_insert(tree_t *t, int val) {
    if (!t->head) {
        t->head = node_create(val, NULL);
        return;
    }

    node_insert(t->head, val);
}

void tree_print(tree_t *t) {
    printf("[");
    node_print_inorder(t->head);
    printf("]\n");
}
