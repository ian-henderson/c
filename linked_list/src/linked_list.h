#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct node {
	int value;
	struct node *next;
} node_t;

node_t *create_node(int);

int pop(node_t **);

void print_list(node_t *);

void push_to_end(node_t *, int);

void push_to_start(node_t **, int);

int remove_by_index(node_t **, int);

int remove_last(node_t *);

#endif