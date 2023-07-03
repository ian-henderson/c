#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct node {
  int value;
  struct node *left;
  struct node *right;
} node_t;

node_t *create_tree(int value);

void insert(node_t *tree, int value);

void print_tree(node_t *current);

void printDFS(node_t *current);

#endif