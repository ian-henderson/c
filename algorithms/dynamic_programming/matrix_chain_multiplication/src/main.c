#include "matrix_chain_multiplication.h"
#include <stdio.h>

int main(void) {
    /* 4 matrices of dimensions 40x20, 20x30, 30x10, and 10x30 */
    int p[] = {40, 20, 30, 10, 30};
    int n = sizeof(p) / sizeof(p[0]);

    printf("Minimum number of multiplications (naive): %d\n",
           min_number_of_multiplications_naive(p, 1, n - 1));

    printf("Minimum number of multiplications (memoized): %d\n",
           min_number_of_multiplications_memoized(p, n));

    printf("Minimum number of multiplications (tabulated): %d\n",
           min_number_of_multiplications_tabulated(p, n));
}
