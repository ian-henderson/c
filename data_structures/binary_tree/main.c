#include "tree.h"

#include "stdio.h"
#include "stdlib.h"

int main(void) {
    tree_t *t = tree_create();

    int vals[] = {50, 25, 75, 12, 37, 62, 87, 6,  18, 31, 43, 56, 68, 81, 93,
                  3,  9,  15, 21, 28, 34, 40, 46, 53, 59, 65, 71, 78, 84, 90,
                  96, 1,  4,  7,  10, 13, 16, 19, 22, 26, 29, 32, 35, 38, 41,
                  44, 47, 51, 54, 57, 60, 63, 66, 69, 72, 76, 79, 82, 85, 88,
                  91, 94, 97, 0,  2,  5,  8,  11, 14, 17, 20, 23, 24, 27, 30,
                  33, 36, 39, 42, 45, 48, 49, 52, 55, 58, 61, 64, 67, 70, 73,
                  74, 77, 80, 83, 86, 89, 92, 95, 98, 99};

    for (int i = 0; i < sizeof(vals) / sizeof(vals[0]); i++)
        tree_insert(t, vals[i]);

    printf("tree height: %d\n", tree_height(t));

    tree_print(t);

    tree_destroy(t);
}
