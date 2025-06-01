#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct bst_node {
    struct bst_node *parent, *left, *right;
    int key;
} bst_node;

typedef struct bst {
    bst_node *root;
} bst;

// "public" functions

bst *bst_create(void);

int bst_delete(bst *, int key);

void bst_free(bst *);

int bst_height(bst *);

bst_node *bst_insert(bst *, int key);

void bst_print_inorder(bst *);

bst_node *bst_search(bst *, int key);

// "private" functions

bst_node *_bst_create_node(int key);

void _bst_free_helper(bst_node *);

int _bst_max(int, int);

int _bst_node_height(bst_node *);

bst_node *_bst_node_maximum(bst_node *);

bst_node *_bst_node_minimum(bst_node *);

bst_node *_bst_node_predecessor(bst_node *);

bst_node *_bst_node_successor(bst_node *);

void _bst_print_inorder_helper(bst_node *);

bst_node *_bst_search_helper(bst_node *, int key);

void _bst_transplant(bst *, bst_node *, bst_node *);

#endif
