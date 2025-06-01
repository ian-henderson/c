#include "../include/queue.h"
#include <stdio.h>  // printf
#include <stdlib.h> // exit, realloc
#include <string.h> // memmove

// "public" functions

queue *queue_create(void) {
    queue *q = malloc(sizeof(queue));
    q->head = q->tail = NULL;
    return q;
}

int queue_dequeue(queue *q, int *value) {
    if (q->head == NULL) {
        return 1;
    }

    queue_node *n = q->head;

    if (value != NULL) {
        *value = n->key;
    }

    q->head = q->head->next;

    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(n);

    return 0;
}

int queue_enqueue(queue *q, int key) {
    queue_node *new_node = _queue_create_node(key);

    if (new_node == NULL) {
        fprintf(stderr, "Failed to create node\n");
        queue_free(q);
        exit(1);
    }

    // base case: empty queue
    if (q->tail == NULL) {
        q->head = q->tail = new_node;
        return 0;
    }

    // only one element in queue
    if (q->head == q->tail) {
        q->head->next = q->tail = new_node;
        q->tail->previous = q->head;
        return 0;
    }

    // more than one element is present - add element
    // to end of list and make it the tail
    new_node->previous = q->tail;
    q->tail->next = new_node;
    q->tail = new_node;

    return 0;
}

void queue_free(queue *q) {
    _queue_free_helper(q->head);
    free(q);
}

void queue_print(queue *q) {
    printf("[");
    _queue_print_helper(q->head);
    printf("]\n");
}

// "private" functions

queue_node *_queue_create_node(int key) {
    queue_node *n = malloc(sizeof(queue_node));

    if (n == NULL) {
        return NULL;
    }

    n->previous = n->next = NULL;
    n->key = key;

    return n;
}

void _queue_free_helper(queue_node *n) {
    if (n == NULL) {
        return;
    }

    _queue_free_helper(n->next);

    free(n);
}

void _queue_print_helper(queue_node *n) {
    if (n == NULL) {
        return;
    }

    printf("%d", n->key);

    if (n->next != NULL) {
        printf(", ");
    }

    _queue_print_helper(n->next);
}
