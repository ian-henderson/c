#include <stdio.h>
#include <string.h>
#include "longest_common_subsequence.h"

int
main(void)
{
  char *x = "abcde", *y = "ace";
  size_t m = strlen(x), n = strlen(y);
  printf("subsequence a: %s\n", x);
  printf("subsequence b: %s\n", y);
  printf("longest common subsequence: ???\n");
  longest_common_subsequence(x, y, m, n);
}
