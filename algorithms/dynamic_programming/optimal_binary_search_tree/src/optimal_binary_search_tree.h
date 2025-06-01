#ifndef OPTIMAL_BINARY_SEARCH_TREE_H
#define OPTIMAL_BINARY_SEARCH_TREE_H

void array_print(int a[], int n);

int cost_of_optimal_bst_memoized(int p[], int n);

int cost_of_optimal_bst_memoized_aux(int **memo, int p[], int i, int j);

int cost_of_optimal_bst_naive(int p[], int n);

int cost_of_optimal_bst_naive_aux(int p[], int i, int j);

int **memo_array_create(int n);

void memo_array_free(int **memo, int n);

void memo_array_print(int **memo, int n);

int subarray_sum(int frequencies[], int i, int j);

#endif
