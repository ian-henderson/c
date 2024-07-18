#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H
#define NIL NULL // null pointer or pointer to sentinel node
#define TRUE 1
#define FALSE 0

typedef int boolean;

enum color_t { BLACK, RED };

typedef struct rbt_node
{
  enum color_t color;
  int key;
  struct rbt_node *parent, *left, *right;
} rbt_node;

typedef struct rbt
{
  rbt_node *root;
} rbt;

// "public" functions

rbt *
rbt_create(void);

int
rbt_delete_node(rbt *tree, rbt_node *node);

int
rbt_delete_node_by_key(rbt *tree, int key);

void
rbt_free(rbt *tree);

rbt_node *
rbt_insert(rbt *tree, int key);

void
rbt_print_inorder(rbt *tree);

rbt_node *
rbt_search(rbt *tree, int key);

// "private" functions

rbt_node *
_rbt_bst_replace(rbt_node *node);

rbt_node *
_rbt_create_node(int key);

void
_rbt_fix_double_black(rbt *tree, rbt_node *node);

void
_rbt_free_helper(rbt_node *node);

rbt_node *
_rbt_get_sibling(rbt_node *node);

void
_rbt_insert_fix(rbt *tree, rbt_node *node);

boolean
_rbt_node_has_red_child(rbt_node *node);

boolean
_rbt_node_is_on_parent_left(rbt_node *node);

void
_rbt_print_inorder_helper(rbt *tree, rbt_node *node);

void
_rbt_rotate_left(rbt *tree, rbt_node *node);

void
_rbt_rotate_right(rbt *tree, rbt_node *node);

rbt_node *
_rbt_search_helper(rbt_node *node, int key);

rbt_node *
_rbt_successor(rbt_node *node);

void
_rbt_swap_node_values(rbt_node *u, rbt_node *v);

#endif
