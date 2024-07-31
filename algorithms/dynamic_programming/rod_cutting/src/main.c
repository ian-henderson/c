/*
  Serling Enterprises buys long steel rods and cuts them into shorter rods,
  which it then sells. Each cut is free. The management of Serling
  Enterprises wants to know the best way to cut up the rods.

  Serling Enterprises has a table giving, for i = 1, 2, ..., the price pi in
  dollars that they charge for a rod of length i inches. The length of each rod
  in inches is always an integer.

  Given a rod of length n inches and a table of prices pi for i = 1, 2, ..., n,
  determine the maximum revenue rn obtainable by cutting up the rod and selling
  the pieces. If the price pn for a rod of length n is large enough, an optimal
  solution might require no cutting at all.

  Serling Enterprises can cut up a rod of length n in 2 ^ (n - 1) different
  ways, since they have an independent option of cutting, or not cutting, at a
  distance i inches from the left end, for i = 1, 2, ..., n - 1.
*/

#include <stdio.h>  // fprintf, printf, stderr
#include <stdlib.h> // EXIT_FAILURE
#include "rod_cutting.h"

int
main(void)
{
  int p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  int p_length = sizeof(p) / sizeof(p[0]);
  int n = 9;

  if (n > p_length)
    {
      fprintf(stderr, "n is larger than prices array\n");
      return EXIT_FAILURE;
    }

  printf("prices: ");
  print_array(p, p_length);
  printf("n: %d\n", n);
  printf("naive solution: %d\n", naively_cut_rod(p, n));
  printf("memoized solution: %d\n", memoized_cut_rod(p, n));
  printf("bottom-up solution: %d\n", bottom_up_cut_rod(p, n));
}
