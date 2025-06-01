#include "optimal_binary_search_tree.h"
#include <limits.h> // INT_MAX
#include <stdio.h>  // EXIT_FAILURE, exit, fprintf, printf
#include <stdlib.h> // free, malloc
#include <string.h> // memset

void array_print(int a[], int n) {
    printf("[");

    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);

        if (i != n - 1)
            printf(", ");
    }

    printf("]\n");
}

int cost_of_optimal_bst_memoized(int p[], int n) {
    int **memo = memo_array_create(n);

    for (int i = 0; i < n; i++) {
        memo[i][i] = p[i];
    }

    int value = cost_of_optimal_bst_memoized_aux(memo, p, 0, n - 1);

    memo_array_free(memo, n);

    return value;
}

int cost_of_optimal_bst_memoized_aux(int **memo, int p[], int i, int j) {
    if (i > j) {
        return 0;
    }

    if (memo[i][j] != 0) {
        return memo[i][j];
    }

    int r_cost = subarray_sum(p, i, j); /* cost of making r head of bst */

    int min_cost = INT_MAX;

    for (int r = i; r <= j; r++) {
        int left_subtree_cost =
            cost_of_optimal_bst_memoized_aux(memo, p, i, r - 1);

        int right_subtree_cost =
            cost_of_optimal_bst_memoized_aux(memo, p, r + 1, j);

        int total_cost = r_cost + left_subtree_cost + right_subtree_cost;

        if (total_cost < min_cost) {
            min_cost = total_cost;
        }
    }

    return memo[i][j] = min_cost;
}

int cost_of_optimal_bst_naive(int p[], int n) {
    return cost_of_optimal_bst_naive_aux(p, 0, n - 1);
}

int cost_of_optimal_bst_naive_aux(int p[], int i, int j) {
    if (j < i) /* no elements in this subarray */
    {
        return 0;
    }

    if (j == i) /* one item in this subarray */
    {
        return p[i];
    }

    int min = INT_MAX;

    for (int r = i; r <= j; r++) {
        int cost = cost_of_optimal_bst_naive_aux(p, i, r - 1) +
                   cost_of_optimal_bst_naive_aux(p, r + 1, j);

        if (cost < min) {
            min = cost;
        }
    }

    return min + subarray_sum(p, i, j);
}

int **memo_array_create(int n) {
    /* create an array of n int pointers */
    int **memo = malloc(n * sizeof(int *));

    if (memo == NULL) {
        fprintf(stderr, "Failed to create LCS memo array.\n");

        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        memo[i] = malloc(n * sizeof(int));

        if (memo[i] == NULL) {
            fprintf(stderr, "Failed to create LCS memo array.\n");

            /* frees previously created rows */
            for (int j = 0; j < i; j++) {
                free(memo[j]);
            }

            free(memo);

            exit(EXIT_FAILURE);
        }

        /* zeros out array */
        memset(memo[i], 0, n * sizeof(int));
    }

    return memo;
}

void memo_array_free(int **memo, int n) {
    for (int i = 0; i < n; i++) {
        free(memo[i]);
    }

    free(memo);
}

void memo_array_print(int **memo, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d", memo[j][i]);
        }

        printf("\n");
    }
}

int subarray_sum(int p[], int i, int j) {
    int sum = 0;

    for (int k = i; k <= j; k++) {
        sum += p[k];
    }

    return sum;
}
