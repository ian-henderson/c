#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_node
{
  struct queue_node *previous, *next;
  int key;
} queue_node;

typedef struct queue
{
  queue_node *head, *tail;
} queue;

// "public" functions

queue *
queue_create(void);

int
queue_dequeue(queue *, int *value);

int
queue_enqueue(queue *, int);

void
queue_free(queue *);

void
queue_print(queue *);

// "private" functions

queue_node *
_queue_create_node(int key);

void
_queue_free_helper(queue_node *);

void
_queue_print_helper(queue_node *);

#endif
