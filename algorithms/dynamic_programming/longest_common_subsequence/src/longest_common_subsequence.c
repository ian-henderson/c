#include "longest_common_subsequence.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longest_common_subsequence(char *x, char *y, size_t m, size_t n) {
    int **memo = memo_array_create(x, y);

    for (int i = m - 1; i > -1; i--)
        for (int j = n - 1; j > -1; j--)
            if (x[i] == y[j])
                memo[i][j] = 1 + memo[i + 1][j + 1];
            else
                memo[i][j] = max(memo[i][j + 1], memo[i + 1][j]);

    memo_array_print(memo, m, n);

    int value = memo[0][0];

    memo_array_free(memo, m);

    return value;
}

int max(int x, int y) { return x > y ? x : y; }

int **memo_array_create(char *x, char *y) {
    size_t m = strlen(x), n = strlen(y);

    /* create an array of m + 1 int pointers */
    int **memo = malloc((m + 1) * sizeof(int *));

    if (memo == NULL) {
        fprintf(stderr, "Failed to create LCS memo array.\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i <= m; i++) {
        memo[i] = malloc((n + 1) * sizeof(int));

        if (memo[i] == NULL) {
            fprintf(stderr, "Failed to create LCS memo array.\n");

            /* frees previously created rows */
            for (size_t j = 0; j < i; j++) {
                free(memo[j]);
            }

            free(memo);
            exit(EXIT_FAILURE);
        }
    }

    for (size_t i = 0; i <= m; i++) {
        for (size_t j = 0; j <= n; j++) {
            memo[i][j] = 0;
        }
    }

    return memo;
}

void memo_array_free(int **memo, size_t m) {
    for (size_t i = 0; i <= m; i++) {
        free(memo[i]);
    }

    free(memo);
}

void memo_array_print(int **memo, size_t m, size_t n) {
    for (size_t j = 0; j <= n; j++) {
        for (size_t i = 0; i <= m; i++) {
            printf("%4d", memo[i][j]);
        }

        printf("\n");
    }
}
