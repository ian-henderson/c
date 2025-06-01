#include "b_tree_node.h"

#include <stdbool.h> // bool
#include <stdio.h>   // perror, printf
#include <stdlib.h>  // calloc, exit, EXIT_FAILURE

int max(int a, int b) { return a > b ? a : b; }

b_tree_node_t *b_tree_node_create(bool is_leaf) {
    b_tree_node_t *node = calloc(1, sizeof(*node));

    if (!node) {
        perror("b_tree_node memory allocation failed");
        exit(EXIT_FAILURE);
    }

    node->is_leaf = is_leaf;

    return node;
}

// TODO: Implement
int b_tree_node_delete(b_tree_node_t *node, int key) { return 0; }

void b_tree_node_destroy(b_tree_node_t **node) {
    if (!(*node))
        return;

    for (int i = 0; i < (*node)->num_keys + 1; i++) {
        b_tree_node_destroy(&((*node)->children[i]));
        (*node)->children[i] = NULL;
    }

    free(*node);
    *node = NULL;
}

int b_tree_node_height(b_tree_node_t *node) {
    if (!node)
        return 0;

    int h = 0;

    for (int i = 0; i < node->num_keys + 1; i++)
        h = max(h, b_tree_node_height(node->children[i]));

    return h + 1;
}

void b_tree_node_insert(b_tree_node_t **root, int key) {
    b_tree_node_t *node = *root;

    if (!node) {
        *root = b_tree_node_create(true);
        (*root)->keys[0] = key;
        (*root)->num_keys = 1;
        return;
    }

    // Split the root if it's full
    if (node->num_keys == M - 1) {
        b_tree_node_t *new_root = b_tree_node_create(false);
        new_root->children[0] = node;
        b_tree_node_split_child(new_root, 0);
        *root = new_root;
    }

    b_tree_node_insert_non_full(*root, key);
}

void b_tree_node_insert_non_full(b_tree_node_t *node, int key) {
    int i = node->num_keys - 1;

    if (node->is_leaf) {
        // Insert key into sorted order
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->num_keys++;
        return;
    }

    // Find the child to insert the key
    while (i >= 0 && node->keys[i] > key)
        i--;
    i++;

    if (node->children[i]->num_keys == M - 1) {
        b_tree_node_split_child(node, i);

        if (node->keys[i] < key)
            i++;
    }

    b_tree_node_insert_non_full(node->children[i], key);
}

void b_tree_node_print_inorder(b_tree_node_t *node) {
    if (!node)
        return;

    int i;

    for (i = 0; i < node->num_keys; i++) {
        b_tree_node_print_inorder(node->children[i]);
        printf("%d ", node->keys[i]);
    }

    b_tree_node_print_inorder(node->children[i]);
}

int b_tree_node_search(b_tree_node_t *node, int key) {
    if (!node)
        return 1;

    int i = 0;

    // Find the first key greater than or equal to the target key
    while (i < node->num_keys && key > node->keys[i])
        i++;

    // If the key is found in the current node, return with success code
    if (i < node->num_keys && key == node->keys[i])
        return 0;

    // If node is a leaf, the key is not in the tree
    if (node->is_leaf)
        return 1;

    return b_tree_node_search(node->children[i], key);
}

void b_tree_node_split_child(b_tree_node_t *parent, int index) {
    b_tree_node_t *child = parent->children[index];
    b_tree_node_t *new_node = b_tree_node_create(child->is_leaf);

    new_node->num_keys = M / 2 - 1;

    // Move keys and children to new node
    for (int i = 0; i < M / 2 - 1; i++)
        new_node->keys[i] = child->keys[i + M / 2];

    if (!child->is_leaf)
        for (int i = 0; i < M / 2; i++)
            new_node->children[i] = child->children[i + M / 2];

    child->num_keys = M / 2 - 1;

    // Shift parent's children to make space for the new node
    for (int i = parent->num_keys; i > index; i--)
        parent->children[i + 1] = parent->children[i];

    parent->children[index + 1] = new_node;

    // Shift parent's keys to insert the middle key from the child
    for (int i = parent->num_keys - 1; i >= index; i--)
        parent->keys[i + 1] = parent->keys[i];

    parent->keys[index] = child->keys[M / 2 - 1];
    parent->num_keys++;
}
