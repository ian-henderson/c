#include "../include/stack.h"
#include <stdio.h>  // fprintf, printf, stderr
#include <stdlib.h> // atoi, exit

int main(int argc, char *argv[]) {
    printf("Creating stack array.\n");

    stack *s = stack_create();
    int i, n = 10000, popped_value;

    if (argc > 1) {
        n = atoi(argv[1]);
    }

    if (n == 0) {
        fprintf(stderr,
                "Invalid 'n' value provided.\nEnter a non-zero integer.\n");
        stack_free(s);
        exit(1);
    }

    printf("Pushing %d values to stack.\n", n);

    for (i = 0; i < n; i++) {
        stack_push(s, i);
    }

    printf("Popping %d values off stack.\n", n);

    for (i = 0; i < n; i++) {
        if (stack_pop(s, &popped_value) == 1) {
            fprintf(stderr, "Pop error received.\n");
        }
    }

    printf("Freeing stack.\n");

    stack_free(s);
}
