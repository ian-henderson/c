#include "longest_common_subsequence.h"
#include <stdio.h>
#include <string.h>

int main(void) {
    char *x = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA",
         *y = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";

    size_t m = strlen(x), n = strlen(y);

    printf("longest common subsequence: %d\n",
           longest_common_subsequence(x, y, m, n));
}
