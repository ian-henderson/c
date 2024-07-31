#ifndef ROD_CUTTING_H
#define ROD_CUTTING_H

int
bottom_up_cut_rod(int p[], int n);

int
max(int, int);

int
memoized_cut_rod(int p[], int n);

int
memoized_cut_rod_aux(int p[], int n, int r[]);

int
naively_cut_rod(int p[], int n);

void
print_array(int [], int length);

#endif
