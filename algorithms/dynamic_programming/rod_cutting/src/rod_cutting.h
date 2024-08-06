#ifndef ROD_CUTTING_H
#define ROD_CUTTING_H

int
cut_rod_memoized(int p[], int n);

int
cut_rod_memoized_aux(int p[], int n, int r[]);

int
cut_rod_naive(int p[], int n);

int
cut_rod_tabulated(int p[], int n);

int
max(int, int);

void
print_array(int [], int length);

#endif
