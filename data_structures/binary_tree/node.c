#include "node.h"
#include "utils.h"

#include "stdio.h"
#include "stdlib.h"

node_t *node_create(int value, node_t *parent_n) {
    node_t *n = malloc(sizeof(*n));
    n->value = value;
    n->parent = parent_n;
    n->left = n->right = NULL;
    return n;
}

void node_destroy(node_t *n) {
    if (!n)
        return;

    node_destroy(n->left);
    node_destroy(n->right);

    free(n);
}

int node_has_value(node_t *n, int val) {
    if (!n)
        return 1;

    if (n->value == val || node_has_value(n->left, val) == 0 ||
        node_has_value(n->right, val) == 0)
        return 0;

    return 1;
}

int node_height(node_t *n) {
    if (!n)
        return 0;

    return 1 + max(node_height(n->left), node_height(n->right));
}

void node_insert(node_t *n, int val) {
    if (n->value == val)
        return;

    if (val < n->value) {
        if (n->left)
            node_insert(n->left, val);
        else
            n->left = node_create(val, n);
    } else {
        if (n->right)
            node_insert(n->right, val);
        else
            n->right = node_create(val, n);
    }
}

void node_print_inorder(node_t *n) {
    if (!n)
        return;

    node_print_inorder(n->left);

    printf("%d", n->value);

    if (node_successor(n))
        printf(", ");

    node_print_inorder(n->right);
}

node_t *node_successor(node_t *n) {
    if (n->right)
        return n->right;

    node_t *parent_n = n->parent;

    while (parent_n && parent_n->right == n) {
        n = parent_n;
        parent_n = parent_n->parent;
    }

    return parent_n;
}
