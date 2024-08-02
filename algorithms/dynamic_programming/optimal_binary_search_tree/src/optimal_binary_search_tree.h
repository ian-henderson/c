#ifndef OPTIMAL_BINARY_SEARCH_TREE_H
#define OPTIMAL_BINARY_SEARCH_TREE_H

int
cost_of_optimal_bst_naive(int frequencies[], int n);

int
cost_of_optimal_bst_naive_aux(int frequencies[], int i, int j);

int
subarray_sum(int frequencies[], int i, int j);

#endif
