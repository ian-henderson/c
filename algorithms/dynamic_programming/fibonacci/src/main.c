#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n;

    /* Note: a return value of 0 from atoi is interpreted as an error, which
       prevents 0 from being considered a valid input. */
    if (argc > 1) {
        n = atoi(argv[1]);
    } else {
        fprintf(stderr, "Enter fibonacci sequence index.\n");

        return EXIT_FAILURE;
    }

    if (n == 0) {
        fprintf(stderr,
                "Invalid 'n' value provided. Enter a non-zero integer.\n");

        return EXIT_FAILURE;
    }

    printf("fibonacci_naive(%d) = %llu\n", n, fibonacci_naive(n));
    printf("fibonacci_memoized(%d) = %llu\n", n, fibonacci_memoized(n));
    printf("fibonacci_tabulated(%d) = %llu\n", n, fibonacci_tabulated(n));
}
