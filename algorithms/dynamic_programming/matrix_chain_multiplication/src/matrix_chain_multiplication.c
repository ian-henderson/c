#include "matrix_chain_multiplication.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* creates an (n - 1) x (n - 1) array. */
int **memo_array_create(int n) {
    int **memo = malloc((n - 1) * sizeof(int *));

    if (memo == NULL) {
        fprintf(stderr, "Failed to create memo array\n");

        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n - 1; i++) {
        memo[i] = malloc((n - 1) * sizeof(int));

        if (memo[i] == NULL) {
            fprintf(stderr, "Failed to create memo array\n");

            /* frees previously created rows */
            for (int j = 0; j < i; j++)
                free(memo[j]);

            free(memo);

            exit(EXIT_FAILURE);
        }

        /* zeros out array */
        memset(memo[i], 0, (n - 1) * sizeof(int));
    }

    return memo;
}

void memo_array_free(int **memo, int n) {
    for (int i = 0; i < n - 1; i++)
        free(memo[i]);

    free(memo);
}

void memo_array_print(int **memo, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++)
            printf("%8d", memo[i][j]);

        printf("\n");
    }
}

int min_number_of_multiplications_memoized(int p[], int n) {
    int **memo = memo_array_create(n);

    int value = min_number_of_multiplications_memoized_aux(memo, p, 1, n - 1);

    memo_array_free(memo, n);

    return value;
}

int min_number_of_multiplications_memoized_aux(int **memo, int p[], int i,
                                               int j) {
    if (i == j)
        return 0;

    if (memo[i - 1][j - 1] != 0)
        return memo[i - 1][j - 1];

    int min = INT_MAX;

    for (int k = i; k < j; k++) {
        int count =
            p[i - 1] * p[k] * p[j] +
            min_number_of_multiplications_memoized_aux(memo, p, i, k) +
            min_number_of_multiplications_memoized_aux(memo, p, k + 1, j);

        if (count < min)
            min = count;
    }

    return memo[i - 1][j - 1] = min;
}

int min_number_of_multiplications_naive(int p[], int i, int j) {
    if (i == j)
        return 0;

    int count, min = INT_MAX;

    /* Place parenthesis at different places between first and last matrix,
       recursively caclulate count of multiplications for each parenthesis
       placement and return the min count */
    for (int k = i; k < j; k++) {
        count = p[i - 1] * p[k] * p[j] +
                min_number_of_multiplications_naive(p, i, k) +
                min_number_of_multiplications_naive(p, k + 1, j);

        if (count < min)
            min = count;
    }

    return min;
}

int min_number_of_multiplications_tabulated(int p[], int n) {
    int **memo = memo_array_create(n);

    /* L is chain length */
    for (int L = 2; L < n; L++)
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1, min = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int count = p[i - 1] * p[k] * p[j] + memo[i - 1][k - 1] +
                            memo[k][j - 1];

                if (count < min)
                    min = count;
            }

            memo[i - 1][j - 1] = min;
        }

    int value = memo[0][n - 2];

    memo_array_free(memo, n);

    return value;
}
