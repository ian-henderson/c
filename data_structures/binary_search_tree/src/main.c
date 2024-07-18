#include <limits.h> // INT_MAX
#include <stdio.h>  // printf
#include <stdlib.h> // rand, srand
#include <time.h>   // time
#include "../include/binary_search_tree.h"

int
main()
{
  srand(time(NULL)); // seeds random number generator
  bst *t = bst_create();
  int max_key_size = INT_MAX, tree_size = 100, values[tree_size];

  for (int i = 0; i < tree_size; i++)
    {
      values[i] = rand() % max_key_size;
      bst_insert(t, values[i]);
    }

  bst_print_inorder(t);

  // predecessor & successor testing
  bst_node *node, *p_node, *s_node;
  if ((node = bst_search(t, values[5])) != NULL)
    {
      printf("node: %d\n", node->key);
    }
  if ((p_node = _bst_node_predecessor(node)) != NULL)
    {
      printf("predecessor: %d\n", p_node->key);
    }
  if ((s_node = _bst_node_successor(node)) != NULL)
    {
      printf("successor: %d\n", s_node->key);
    }

  // tree height
  printf("height: %d\n", bst_height(t));

  // deletion
  for (int i = 0; i < tree_size; i++)
    {
      bst_delete(t, values[i]);
    }

  bst_free(t);
}
