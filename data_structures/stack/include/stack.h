#ifndef STACK_H
#define STACK_H

typedef struct stack {
    int *buffer, buffer_size, cursor;
} stack;

// "public" functions

stack *stack_create(void);

void stack_free(stack *);

int stack_pop(stack *, int *);

void stack_print(stack *);

int stack_push(stack *, int);

#endif
