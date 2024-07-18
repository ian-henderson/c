#include <stdio.h>
#include "../include/hash_table.h"

int
main()
{
  hash_table *t = hash_table_create();
  hash_table_insert(t, "foo", "bar");
  hash_table_insert(t, "baz", "qux");
  hash_table_insert(t, "quux", "corge");
  hash_table_insert(t, "grault", "garply");
  hash_table_insert(t, "waldo", "fred");
  hash_table_insert(t, "plugh", "fred");

  char *search_result = hash_table_search(t, "foo");

  if (search_result != NULL)
    {
      printf("search_result: %s\n", search_result);
    }

  hash_table_delete(t, "foo");

  search_result = hash_table_search(t, "foo");
  if (search_result != NULL)
    {
      printf("search_result: %s\n", search_result);
    }

  hash_table_free(t);
}
