#include <stdio.h>
#include "optimal_binary_search_tree.h"

int
main(void)
{
  int keys[] = {10, 12, 20};
  int frequencies[] = {34,  8, 50};
  int n = sizeof(keys) / sizeof(keys[0]);

  printf("Cost of optimal BST is: %d.\n",
         cost_of_optimal_bst_naive(frequencies, n));
}
