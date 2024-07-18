#include <stdio.h>   // fprintf, printf, stderr
#include <stdlib.h>  // malloc, __INT16_MAX__
#include <string.h>  // strcmp, strlen
#include "../include/hash_table.h"

hash_table *
hash_table_create(void)
{
  hash_table *t = malloc(sizeof(hash_table));
  t->capacity = 100;
  t->buffer = malloc(sizeof(hash_table_node) * t->capacity);
  t->node_count = 0;

  return t;
}

int
hash_table_delete(hash_table *t, char *key)
{
  int index = _hash_table_hash(t, key);

  hash_table_node *current_node = t->buffer[index],
                   *previous_node = NULL;

  while (current_node != NULL)
    {
      if (strcmp(key, current_node->key) == 0)
        {
          // head of list
          if (current_node == t->buffer[index])
            {
              t->buffer[index] = current_node->next;
            }
          else
            {
              previous_node->next = current_node->next;
            }

          free(current_node);
          break;
        }

      previous_node = current_node;
      current_node = current_node->next;
    }

  t->node_count--;

  return 0;
}

void
hash_table_free(hash_table *t)
{
  for (int i = 0; i < t->capacity; i++)
    {
      _hash_table_free_node_list(t->buffer[i]);
    }

  free(t->buffer);

  free(t);
}

int
hash_table_insert(hash_table *t, char *key, char *value)
{
  // Duplicate key/value pair case
  if ((hash_table_search(t, key)) == value)
    {
      return 0;
    }

  hash_table_node *n = _hash_table_node_create(key, value);

  if (n == NULL)
    {
      fprintf(stderr, "Failed to create node.\n");

      return 1;
    }

  int index = _hash_table_hash(t, key);

  if (t->buffer[index] == NULL)
    {
      t->buffer[index] = n;
    }
  else
    {
      n->next = t->buffer[index];
      t->buffer[index] = n;
    }

  t->node_count++;

  return 0;
}

char *
hash_table_search(hash_table *t, char *key)
{
  int index = _hash_table_hash(t, key);
  hash_table_node *n = t->buffer[index];

  while (n != NULL)
    {
      if (n->key == key)
        {
          return n->value;
        }

      n = n->next;
    }

  return NULL;
}

// "private" functions

void
_hash_table_free_node_list(hash_table_node *n)
{
  if (n == NULL)
    {
      return;
    }

  _hash_table_free_node_list(n->next);

  free(n);
}

int
_hash_table_hash(hash_table *t, char *key)
{
  int factor = 31, hash = 0, i, max = __INT16_MAX__;

  for (i = 0; i < (int)strlen(key); i++)
    {
      hash = ((hash % t->capacity)
              + (((int)key[i]) * factor) % t->capacity)
             % t->capacity;

      factor = ((factor % max) * (31 % max)) % max;
    }

  return hash;
}

hash_table_node *
_hash_table_node_create(char *key, char *value)
{
  hash_table_node *n = malloc(sizeof(hash_table_node));
  n->next = n->previous = NULL;
  n->key = key;
  n->value = value;

  return n;
}
