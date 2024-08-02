#include <limits.h>
#include "optimal_binary_search_tree.h"

int
cost_of_optimal_bst_naive(int frequencies[], int n)
{
  return cost_of_optimal_bst_naive_aux(frequencies, 0, n - 1);
}

int
cost_of_optimal_bst_naive_aux(int frequencies[], int i, int j)
{
  if (j < i) // no elements in this subarray
    {
      return 0;
    }

  if (j == i) // one item in this subarray
    {
      return frequencies[i];
    }

  int min = INT_MAX;

  for (int r = i; r <= j; r++)
    {
      int cost = cost_of_optimal_bst_naive_aux(frequencies, i, r - 1)
                 + cost_of_optimal_bst_naive_aux(frequencies, r + 1, j);

      if (cost < min)
        {
          min = cost;
        }
    }

  return min + subarray_sum(frequencies, i, j);
}

int
subarray_sum(int frequencies[], int i, int j)
{
  int sum = 0;

  for (int k = i; k <= j; k++)
    {
      sum += frequencies[k];
    }

  return sum;
}
