#include "../include/binary_search_tree.h"

#include <stdio.h>
#include <stdlib.h>

// "public" functions

bst *bst_create(void) {
    bst *tree = malloc(sizeof(bst));
    tree->root = NULL;
    return tree;
}

int bst_delete(bst *tree, int key) {
    bst_node *n = tree->root, *parent = NULL;

    while (n != NULL && n->key != key) {
        parent = n;

        if (key < n->key) {
            n = n->left;
        } else {
            n = n->right;
        }
    }

    // node not found
    if (n == NULL) {
        return 1;
    }

    if (n->left == NULL) {
        _bst_transplant(tree, n, n->right);
    } else if (n->right == NULL) {
        _bst_transplant(tree, n, n->left);
    } else {
        parent = _bst_node_minimum(n->right);

        if (parent != n->right) {
            _bst_transplant(tree, parent, parent->right);
            parent->right = n->right;
            parent->right->parent = parent;
        }

        _bst_transplant(tree, n, parent);
        parent->left = n->left;
        parent->left->parent = parent;
    }

    return 0;
}

void bst_free(bst *tree) {
    _bst_free_helper(tree->root);
    free(tree);
}

int bst_height(bst *tree) { return _bst_node_height(tree->root) + 1; }

bst_node *bst_insert(bst *tree, int key) {
    bst_node *current = tree->root, *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (key == current->key) {
            return NULL;
        }
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    bst_node *new_node = _bst_create_node(key);
    new_node->parent = parent;

    if (parent == NULL) {
        tree->root = new_node;
    } else if (new_node->key < parent->key) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }

    return new_node;
}

void bst_print_inorder(bst *tree) { _bst_print_inorder_helper(tree->root); }

bst_node *bst_search(bst *tree, int key) {
    return _bst_search_helper(tree->root, key);
}

// "private" functions

bst_node *_bst_create_node(int key) {
    bst_node *n = malloc(sizeof(bst_node));
    n->key = key;
    n->parent = n->left = n->right = NULL;
    return n;
}

void _bst_free_helper(bst_node *n) {
    if (n == NULL) {
        return;
    }

    _bst_free_helper(n->left);
    _bst_free_helper(n->right);
    free(n);
}

int _bst_max(int x, int y) {
    if (x > y) {
        return x;
    }

    return y;
}

int _bst_node_height(bst_node *n) {
    if (n == NULL) {
        return -1;
    }

    int max = _bst_max(_bst_node_height(n->left), _bst_node_height(n->right));

    return max + 1;
}

bst_node *_bst_node_maximum(bst_node *x) {
    while (x->right != NULL) {
        x = x->right;
    }

    return x;
}

bst_node *_bst_node_minimum(bst_node *x) {
    while (x->left != NULL) {
        x = x->left;
    }

    return x;
}

bst_node *_bst_node_predecessor(bst_node *x) {
    if (x == NULL) {
        return NULL;
    }

    if (x->left != NULL) {
        return _bst_node_maximum(x->left);
    }

    bst_node *current = x, *parent = x->parent;

    while (parent != NULL && current == parent->left) {
        current = parent;
        parent = parent->parent;
    }

    return parent;
}

bst_node *_bst_node_successor(bst_node *x) {
    if (x == NULL) {
        return NULL;
    }

    if (x->right != NULL) {
        // left-most node in right subtree
        return _bst_node_minimum(x->right);
    }

    // find the lowest ancestor of x whose left child is an ancestor of x

    bst_node *current = x, *parent = x->parent;

    while (parent != NULL && current == parent->right) {
        current = parent;
        parent = parent->parent;
    }

    return parent;
}

void _bst_print_inorder_helper(bst_node *n) {
    if (n == NULL) {
        return;
    }

    _bst_print_inorder_helper(n->left);

    printf("%d\n", n->key);

    _bst_print_inorder_helper(n->right);
}

bst_node *_bst_search_helper(bst_node *n, int key) {
    if (n == NULL || n->key == key) {
        return n;
    }

    if (key < n->key) {
        return _bst_search_helper(n->left, key);
    }

    return _bst_search_helper(n->right, key);
}

void _bst_transplant(bst *tree, bst_node *u, bst_node *v) {
    if (u->parent == NULL) {
        tree->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }

    if (v != NULL) {
        v->parent = u->parent;
    }
}
