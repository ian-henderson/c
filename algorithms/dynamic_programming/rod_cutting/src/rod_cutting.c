#include "rod_cutting.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int cut_rod_memoized(int p[], int n) {
    int *r = malloc(sizeof(int) * n);

    if (r == NULL) {
        fprintf(stderr,
                "Failed to create cut_rod_memoized memoization array.\n");

        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
        r[i] = INT_MIN;

    int value = cut_rod_memoized_aux(p, n, r);

    free(r);

    return value;
}

int cut_rod_memoized_aux(int p[], int n, int r[]) {
    if (n == 0)
        return 0;

    int index = n - 1;

    if (r[index] != INT_MIN)
        return r[index];

    int max_profit = INT_MIN;

    for (int i = 1; i <= n; i++)
        max_profit =
            max(max_profit, p[i - 1] + cut_rod_memoized_aux(p, n - i, r));

    return r[index] = max_profit;
}

int cut_rod_naive(int p[], int n) {
    if (n == 0)
        return 0;

    int max_profit = INT_MIN; /* -Infinity */

    for (int i = 1; i <= n; i++)
        max_profit = max(max_profit, p[i - 1] + cut_rod_naive(p, n - i));

    return max_profit;
}

int cut_rod_tabulated(int p[], int n) {
    // An extra int is required for 1-based indexing
    int *r = malloc(sizeof(int) * (n + 1));

    if (r == NULL) {
        fprintf(stderr,
                "Failed to create cut_rod_tabulated memoization array.\n");

        exit(EXIT_FAILURE);
    }

    r[0] = 0;

    for (int j = 1; j <= n; j++) {
        int max_profit = INT_MIN;

        for (int i = 1; i <= j; i++)
            max_profit = max(max_profit, p[i - 1] + r[j - i]);

        r[j] = max_profit;
    }

    int value = r[n];

    free(r);

    return value;
}

int max(int a, int b) { return a > b ? a : b; }

void print_array(int a[], int length) {
    printf("[");

    for (int i = 0; i < length; i++) {
        printf("%d", a[i]);

        if (i != length - 1)
            printf(", ");
    }

    printf("]\n");
}
