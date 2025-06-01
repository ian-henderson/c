#pragma once

#include "stdbool.h"

#define M 32

typedef struct b_tree_node {
        struct b_tree_node *children[M];
        bool is_leaf;
        int keys[M - 1];
        int num_keys;
} b_tree_node_t;

b_tree_node_t *b_tree_node_create(bool is_leaf);

int b_tree_node_delete(b_tree_node_t *node, int key);

void b_tree_node_destroy(b_tree_node_t **node);

int b_tree_node_height(b_tree_node_t *node);

void b_tree_node_insert(b_tree_node_t **root, int key);

void b_tree_node_insert_non_full(b_tree_node_t *node, int key);

void b_tree_node_print_inorder(b_tree_node_t *node);

int b_tree_node_search(b_tree_node_t *node, int key);

void b_tree_node_split_child(b_tree_node_t *node, int index);
