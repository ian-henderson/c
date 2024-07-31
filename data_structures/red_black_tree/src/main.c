#include <limits.h> // INT_MAX
#include <stdio.h>  // printf
#include <stdlib.h> // rand, srand
#include <time.h>   // time
#include "../include/red_black_tree.h"

int
main(void)
{
  srand(time(NIL)); // seeds random number generator
  rbt *t = rbt_create();
  int max_key_size = INT_MAX, tree_size = 100, values[tree_size];

  for (int i = 0; i < tree_size; i++)
    {
      values[i] = rand() % max_key_size;
      rbt_insert(t, values[i]);
    }

  rbt_print_inorder(t);

  printf("delete code: %d\n", rbt_delete_node_by_key(t, 3000));

  rbt_free(t);
}
