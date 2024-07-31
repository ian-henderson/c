#include <limits.h> // INT_MAX
#include <stdio.h>  // printf
#include <stdlib.h> // rand, srand
#include <time.h>   // time
#include "../include/sorting.h"

int
main(void)
{
  int i, max_value = INT_MAX, n = 8, *array = malloc(sizeof(int) * n);
  srand(time(NULL)); // seed random number generator
  for (i = 0; i < n; i++)
    {
      array[i] = rand() % max_value;
    }
  print_array(array, n);
  selection_sort(array, n);
  print_array(array, n);
  free(array);
}
