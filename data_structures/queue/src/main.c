#include "../include/queue.h"
#include <stdio.h>  // fprintf, printf, stderr
#include <stdlib.h> // atoi, exit

int main(int argc, char *argv[]) {
    printf("Creating queue.\n");

    queue *q = queue_create();
    int dequeued_value, i, n = 10000;

    if (argc > 1) {
        n = atoi(argv[1]);
    }

    if (n == 0) {
        fprintf(stderr,
                "Invalid 'n' value provided.\nEnter a non-zero integer.\n");
        queue_free(q);
        exit(1);
    }

    printf("Enqueueing %d values.\n", n);

    for (i = 0; i < n; i++) {
        queue_enqueue(q, i);
    }

    printf("Dequeueing %d values.\n", n);

    for (i = 0; i < n; i++) {
        if (queue_dequeue(q, &dequeued_value) == 1) {
            fprintf(stderr, "Dequeue error received.\n");
        }
    }

    printf("Freeing queue.\n");

    queue_free(q);
}
