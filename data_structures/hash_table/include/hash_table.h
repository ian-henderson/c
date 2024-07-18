#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct hash_table_node
{
  struct hash_table_node *next, *previous;
  char *key, *value;
} hash_table_node;

typedef struct hash_table
{
  hash_table_node **buffer;
  int node_count, capacity;
} hash_table;

// "public" functions

hash_table *
hash_table_create(void);

int
hash_table_delete(hash_table *, char *key);

void
hash_table_free(hash_table *);

int
hash_table_insert(hash_table *, char *key, char *value);

char *
hash_table_search(hash_table *, char *key);

// "private" functions

void
_hash_table_free_node_list(hash_table_node *);

int
_hash_table_hash(hash_table *, char *);

hash_table_node *
_hash_table_node_create(char *key, char *value);

#endif
