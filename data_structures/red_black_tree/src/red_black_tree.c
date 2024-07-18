#include <stdio.h>
#include <stdlib.h> // exit, EXIT_FAILURE, fprintf, malloc, rand
#include "../include/red_black_tree.h"

// "public" functions

rbt *
rbt_create(void)
{
  rbt *tree = malloc(sizeof(rbt));
  tree->root = NIL;
  return tree;
}

int
rbt_delete_node(rbt *tree, rbt_node *v)
{
  rbt_node *parent = v->parent,
            *u = _rbt_bst_replace(v);

  boolean uv_black = ((u == NIL || u->color == BLACK) && v->color == BLACK);

  if (u == NIL)
    {
      if (v == tree->root)
        {
          tree->root = NIL;
        }
      else
        {
          if (uv_black)
            {
              // u and v are both black
              // v is leaf, fix double black at v
              _rbt_fix_double_black(tree, v);
            }
          else
            {
              // u or v is red
              rbt_node *v_sibling = _rbt_get_sibling(v);
              if (v_sibling != NIL)
                {
                  v_sibling->color = RED;
                }
            }

          // delete v from the tree
          if (_rbt_node_is_on_parent_left(v))
            {
              parent->left = NIL;
            }
          else
            {
              parent->right = NIL;
            }
        }

      free(v);

      return 0;
    }

  if (v->left == NIL || v->right == NIL)
    {
      // v has 1 child
      if (v == tree->root)
        {
          // v is root, assign the value of u to v, then delete u
          v->key = u->key;
          v->left = v->right = NIL;
          free(u);
        }
      else
        {
          // Detach v from tree and move u up
          if (_rbt_node_is_on_parent_left(v))
            {
              parent->left = u;
            }
          else
            {
              parent->right = u;
            }

          free(v);
          u->parent = parent;

          if (uv_black)
            {
              // u and v both black, fix double black at u
              _rbt_fix_double_black(tree, u);
            }
          else
            {
              // u or v red, color u black
              u->color = BLACK;
            }
        }

      return 0;
    }

  // v has 2 children, swap values with successor and recurse
  _rbt_swap_node_values(u, v);

  return rbt_delete_node(tree, u);
}

int
rbt_delete_node_by_key(rbt *tree, int key)
{
  rbt_node *v = rbt_search(tree, key);

  if (v == NIL)
    {
      return 1;
    }

  return rbt_delete_node(tree, v);
}

void
rbt_free(rbt *tree)
{
  _rbt_free_helper(tree->root);
  free(tree);
}

rbt_node *
rbt_insert(rbt *tree, int key)
{
  rbt_node *current = tree->root, *parent = NIL;

  while (current != NIL)
    {
      parent = current;

      if (key == current->key)
        {
          return NIL;
        }

      if (key < current->key)
        {
          current = current->left;
        }
      else
        {
          current = current->right;
        }
    }

  rbt_node *new_node = _rbt_create_node(key);
  new_node->parent = parent;

  if (parent == NIL)
    {
      tree->root = new_node;
    }
  else if (new_node->key < parent->key)
    {
      parent->left = new_node;
    }
  else
    {
      parent->right = new_node;
    }

  if (new_node->parent == NIL)
    {
      new_node->color = BLACK;
      return new_node;
    }

  if (new_node->parent->parent == NIL)
    {
      return new_node;
    }

  _rbt_insert_fix(tree, new_node);

  return new_node;
}

void
rbt_print_inorder(rbt *tree)
{
  _rbt_print_inorder_helper(tree, tree->root);
}

rbt_node *
rbt_search(rbt *tree, int key)
{
  return _rbt_search_helper(tree->root, key);
}

// "private" functions

rbt_node *
_rbt_bst_replace(rbt_node *node)
{
  // when node has two children
  if (node->left != NIL && node->right != NIL)
    {
      return _rbt_successor(node->right);
    }

  // node is a leaf
  if (node->left == NIL && node->right == NIL)
    {
      return NIL;
    }

  // node has a single child
  if (node->left != NIL)
    {
      return node->left;
    }

  return node->right;
}

rbt_node *
_rbt_create_node(int key)
{
  rbt_node *new_node = malloc(sizeof(rbt_node));
  new_node->color = RED;
  new_node->key = key;
  new_node->left = new_node->right = NIL;
  return new_node;
}

void
_rbt_fix_double_black(rbt *tree, rbt_node *n)
{
  if (n == tree->root)
    {
      // reached root
      return;
    }

  rbt_node *parent = n->parent,
            *sibling = _rbt_get_sibling(n);

  if (sibling == NIL)
    {
      // No sibling, double black pushed up
      _rbt_fix_double_black(tree, parent);
    }
  else
    {
      if (sibling->color == RED)
        {
          // Sibling red
          parent->color = RED;
          sibling->color = BLACK;

          // if (sibling->isOnLeft())
          if (_rbt_node_is_on_parent_left(sibling))
            {
              // left case
              _rbt_rotate_right(tree, parent);
            }
          else
            {
              // right case
              _rbt_rotate_left(tree, parent);
            }

          _rbt_fix_double_black(tree, n);
        }
      else
        {
          // Sibling black
          if (_rbt_node_has_red_child(sibling))
            {
              // at least 1 red children
              if (sibling->left != NIL && sibling->left->color == RED)
                {
                  if (_rbt_node_is_on_parent_left(sibling))
                    {
                      // left left
                      sibling->left->color = sibling->color;
                      sibling->color = parent->color;
                      _rbt_rotate_right(tree, parent);
                    }
                  else
                    {
                      // right left
                      sibling->left->color = parent->color;
                      _rbt_rotate_right(tree, sibling);
                      _rbt_rotate_left(tree, parent);
                    }
                }
              else
                {
                  if (_rbt_node_is_on_parent_left(sibling))
                    {
                      // left right
                      sibling->right->color = parent->color;
                      _rbt_rotate_left(tree, sibling);
                      _rbt_rotate_right(tree, parent);
                    }
                  else
                    {
                      // right right
                      sibling->right->color = sibling->color;
                      sibling->color = parent->color;
                      _rbt_rotate_left(tree, parent);
                    }
                }
              parent->color = BLACK;
            }
          else
            {
              // 2 black children
              sibling->color = RED;
              if (parent->color == BLACK)
                {
                  _rbt_fix_double_black(tree, parent);
                }
              else
                {
                  parent->color = BLACK;
                }
            }
        }
    }
}

void
_rbt_free_helper(rbt_node *node)
{
  if (node == NIL)
    {
      return;
    }

  _rbt_free_helper(node->left);
  _rbt_free_helper(node->right);
  free(node);
}

rbt_node *
_rbt_get_sibling(rbt_node *u)
{
  if (u == NIL)
    {
      return NIL;
    }

  if (u->parent == NIL)
    {
      return NIL;
    }

  if (u->parent->left == u)
    {
      return u->parent->right;
    }

  return u->parent->left;
}

void
_rbt_insert_fix(rbt *tree, rbt_node *node)
{
  while (node != tree->root && node->parent->color == RED)
    {
      rbt_node *uncle;

      if (node->parent == node->parent->parent->left)
        {
          uncle = node->parent->parent->right;

          if (uncle != NIL && uncle->color == RED)
            {
              node->parent->color = BLACK;
              uncle->color = BLACK;
              node->parent->parent->color = RED;
              node = node->parent->parent;
            }
          else
            {
              if (node == node->parent->right)
                {
                  node = node->parent;
                  _rbt_rotate_left(tree, node);
                }
              node->parent->color = BLACK;
              node->parent->parent->color = RED;
              _rbt_rotate_right(tree, node->parent->parent);
            }
        }
      else
        {
          uncle = node->parent->parent->left;

          // uncle->color reference seg faults
          if (uncle != NIL && uncle->color == RED)
            {
              node->parent->color = BLACK;
              uncle->color = BLACK;
              node->parent->parent->color = RED;
              node = node->parent->parent;
            }
          else
            {
              if (node == node->parent->left)
                {
                  node = node->parent;
                  _rbt_rotate_right(tree, node);
                }
              node->parent->color = BLACK;
              node->parent->parent->color = RED;
              _rbt_rotate_left(tree, node->parent->parent);
            }
        }
    }

  tree->root->color = BLACK;
}

boolean
_rbt_node_has_red_child(rbt_node *n)
{
  if (n == NIL)
    {
      return FALSE;
    }

  if ((n->left != NIL && n->left->color == RED)
      || (n->right != NIL && n->right->color == RED))
    {
      return TRUE;
    }

  return FALSE;
}

boolean
_rbt_node_is_on_parent_left(rbt_node *n)
{
  if (n->parent == NIL)
    {
      return FALSE;
    }

  if (n->parent->left == n)
    {
      return TRUE;
    }

  return FALSE;
}

void
_rbt_print_inorder_helper(rbt *tree, rbt_node *node)
{
  if (node == NIL)
    {
      return;
    }

  _rbt_print_inorder_helper(tree, node->left);

  printf("{ ");
  printf("key: %d", node->key);
  if (node->parent != NIL)
    {
      printf(", parent_key: %d", node->parent->key);
    }
  printf(", color: %s", node->color == BLACK ? "Black" : "Red");
  printf(" }\n");

  _rbt_print_inorder_helper(tree, node->right);
}

void
_rbt_rotate_left(rbt *tree, rbt_node *x)
{
  rbt_node *y = x->right;

  x->right = y->left;

  if (y->left != NIL)
    {
      y->left->parent = x;
    }

  y->parent = x->parent;

  if (x->parent == NIL)
    {
      tree->root = y;
    }
  else if (x == x->parent->left)
    {
      x->parent->left = y;
    }
  else
    {
      x->parent->right = y;
    }

  y->left = x;
  x->parent = y;
}

void
_rbt_rotate_right(rbt *tree, rbt_node *x)
{
  rbt_node *y = x->left;

  x->left = y->right;

  if (y->right != NIL)
    {
      y->right->parent = x;
    }

  y->parent = x->parent;

  if (x->parent == NIL)
    {
      tree->root = y;
    }
  else if (x == x->parent->right)
    {
      x->parent->right = y;
    }
  else
    {
      x->parent->left = y;
    }

  y->right = x;
  x->parent = y;
}

rbt_node *
_rbt_search_helper(rbt_node *node, int key)
{
  if (node == NIL || node->key == key)
    {
      return node;
    }

  if (node->key > key)
    {
      return _rbt_search_helper(node->left, key);
    }

  return _rbt_search_helper(node->right, key);
}

rbt_node *
_rbt_successor(rbt_node *node)
{
  rbt_node *successor = node;

  while (successor->left != NIL)
    {
      successor = successor->left;
    }

  return successor;
}

void
_rbt_swap_node_values(rbt_node *u, rbt_node *v)
{
  int temp = u->key;
  u->key = v->key;
  v->key = temp;
}
