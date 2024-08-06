#ifndef MATRIX_CHAIN_MULTIPLICATION_H
#define MATRIX_CHAIN_MULTIPLICATION_H

int **
memo_array_create(int n);

void
memo_array_free(int **memo, int n);

void
memo_array_print(int **memo, int n);

int
min_number_of_multiplications_memoized(int p[], int n);

int
min_number_of_multiplications_memoized_aux(int **memo, int p[], int i, int j);

int
min_number_of_multiplications_naive(int p[], int i, int j);

int
min_number_of_multiplications_tabulated(int p[], int n);

#endif
