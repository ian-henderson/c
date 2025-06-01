#ifndef LONGEST_COMMON_SUBSEQUENCE_H
#define LONGEST_COMMON_SUBSEQUENCE_H

#include <string.h>

int longest_common_subsequence(char *x, char *y, size_t m, size_t n);

int max(int, int);

int **memo_array_create(char *, char *);

void memo_array_free(int **memo, size_t m);

void memo_array_print(int **memo, size_t m, size_t n);

#endif
