#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void array_print(unsigned long long int a[], int length) {
    printf("[");

    for (int i = 0; i < length; i++) {
        printf("%llu", a[i]);

        if (i < length - 1) {
            printf(", ");
        }
    }

    printf("]\n");
}

/*
  Memoization (Top-Down Dynamic Programming)
  Space Complexity: O(n)
  Time Complexity:  O(n)
*/
unsigned long long int fibonacci_memoized(int n) {
    unsigned long long int *memo =
        malloc((n + 1) * sizeof(unsigned long long int));

    if (memo == NULL) {
        fprintf(stderr, "Failed to create memo array.\n");

        exit(EXIT_FAILURE);
    }

    /* zeros out memo */
    memset(memo, 0U, (n + 1) * sizeof(unsigned long long int));

    unsigned long long int value = fibonacci_memoized_aux(n, memo);

    free(memo);

    return value;
}

unsigned long long int fibonacci_memoized_aux(int n,
                                              unsigned long long int *memo) {
    if (n <= 1) {
        return (unsigned long long)n;
    }

    if (memo[n] != 0U) {
        return memo[n];
    }

    memo[n] = fibonacci_memoized_aux(n - 1, memo) +
              fibonacci_memoized_aux(n - 2, memo);

    /* unsigned overflow check */
    if (memo[n] < memo[n - 1]) {
        fprintf(stderr,
                "unsigned long long int overflow at fibonacci(%d) = %llu\n",
                n - 1, memo[n - 1]);

        free(memo);

        exit(EXIT_FAILURE);
    }

    return memo[n];
}

/*
  Recursion (very bad)
  Space Complexity: O(n)
  Time Complexity:  O(2^n)
*/
unsigned long long int fibonacci_naive(int n) {
    if (n <= 1) {
        return (unsigned long long int)n;
    }

    unsigned long long int a = fibonacci_naive(n - 2),
                           b = fibonacci_naive(n - 1), c = a + b;

    /* unsigned overflow check */
    if (c < b) {
        fprintf(stderr,
                "unsigned long long int overflow at fibonacci(%d) = %llu\n",
                n - 1, b);

        exit(EXIT_FAILURE);
    }

    return c;
}

/*
  Tabulation (Bottom-Up Dynamic Programming)
  Space Complexity: O(n)
  Time Complexity:  O(n)

  Generally preferable to top-down approach since loops are faster than the
  stack.
*/
unsigned long long int fibonacci_tabulated(int n) {
    unsigned long long int *memo =
        malloc(sizeof(unsigned long long int) * (n + 1));

    memo[0] = 0U;
    memo[1] = 1U;

    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];

        /* unsigned overflow check */
        if (memo[i] < memo[i - 1]) {
            fprintf(stderr,
                    "unsigned long long int overflow at fibonacci(%d) = %llu\n",
                    i - 1, memo[i - 1]);

            free(memo);

            exit(EXIT_FAILURE);
        }
    }

    unsigned long long int value = memo[n];

    free(memo);

    return value;
}
