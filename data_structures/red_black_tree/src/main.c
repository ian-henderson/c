#include "../include/red_black_tree.h"
#include <limits.h> // INT_MAX
#include <stdio.h>  // printf
#include <stdlib.h> // rand, srand
#include <time.h>   // time

int main(void) {
    srand(time(NIL)); // seeds random number generator
    rbt *t = rbt_create();
    int max_key_size = INT_MAX;
    int tree_size = 100000;
    int values[tree_size];

    for (int i = 0; i < tree_size; i++) {
        values[i] = rand() % max_key_size;
        rbt_insert(t, values[i]);
    }

    rbt_print_inorder(t);
    printf("delete code: %d\n", rbt_delete_node_by_key(t, 3000));
    rbt_free(t);
}
