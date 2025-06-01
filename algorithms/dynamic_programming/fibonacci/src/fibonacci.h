#ifndef FIBONACCI_H
#define FIBONACCI_H

void array_print(unsigned long long int a[], int length);

unsigned long long int fibonacci_memoized(int n);

unsigned long long int fibonacci_memoized_aux(int n,
                                              unsigned long long int *memo);

unsigned long long int fibonacci_naive(int n);

unsigned long long int fibonacci_tabulated(int n);

#endif
