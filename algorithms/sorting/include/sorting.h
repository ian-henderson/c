#ifndef SORT_H
#define SORT_H

int *
bubble_sort(int array[], int array_length);

int *
heap_sort(int array[], int array_length);

int *
heapify(int array[], int heap_size, int root);

int *
insertion_sort(int array[], int array_length);

void
merge(int array[], int left, int mid, int right);

int *
merge_sort(int array[], int array_length);

void
merge_sort_r(int array[], int begin, int end);

int
partition(int array[], int low, int high);

int *
quick_sort(int array[], int array_length);

void
quick_sort_r(int array[], int low, int high);

int *
selection_sort(int array[], int array_length);

// utils

int
is_best_case_array(int array[], int array_length);

void
print_array(int array[], int array_length);

void
swap(int *a, int *b);

#endif
