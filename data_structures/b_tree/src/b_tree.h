#pragma once

#include "b_tree_node.h"

typedef struct b_tree {
        b_tree_node_t *head;
} b_tree_t;

b_tree_t *b_tree_create();

int b_tree_delete(b_tree_t *tree, int key);

void b_tree_destroy(b_tree_t **tree);

int b_tree_height(b_tree_t *tree);

int b_tree_insert(b_tree_t *tree, int key);

int b_tree_search(b_tree_t *tree, int key);

void b_tree_print(b_tree_t *tree);
