#pragma once

#include "node.h"

typedef struct tree {
    node_t *head;
} tree_t;

tree_t *tree_create();

void tree_destroy(tree_t *t);

int tree_has_value(tree_t *t, int val);

int tree_height(tree_t *t);

void tree_insert(tree_t *t, int val);

void tree_print(tree_t *t);
