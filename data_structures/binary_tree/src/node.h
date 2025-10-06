#pragma once

typedef struct node {
    int value;
    struct node *parent, *left, *right;
} node_t;

node_t *node_create(int value, node_t *parent_n);

void node_destroy(node_t *n);

int node_has_value(node_t *n, int val);

int node_height(node_t *n);

void node_insert(node_t *n, int val);

void node_print_inorder(node_t *n);

node_t *node_successor(node_t *n);
