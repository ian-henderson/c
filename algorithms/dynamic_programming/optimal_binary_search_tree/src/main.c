#include <stdio.h>
#include "optimal_binary_search_tree.h"

int
main(void)
{
  int k[] = {10, 12, 20, 35, 36, 40, 48, 50, 52, 55};
  int m = sizeof(k) / sizeof(k[0]);
  printf("int k[] = ");
  array_print(k, m);

  int p[] = {34, 8, 50, 17, 11, 99, 31, 49, 10, 73};
  int n = sizeof(p) / sizeof(p[0]);
  printf("int p[] = ");
  array_print(p, n);

  printf("Cost of optimal BST is: %d\n",
         cost_of_optimal_bst_memoized(p, n));
}
