#ifndef FIBONACCI_H
#define FIBONACCI_H

unsigned long long int
fibonacci_memoized(int n);

unsigned long long int
fibonacci_memoized_aux(int n, unsigned long long int *memo);

unsigned long long int
fibonacci_naive(int n);

unsigned long long int
fibonacci_tabulated(int n);

void
print_array(unsigned long long int a[], int length);

#endif
