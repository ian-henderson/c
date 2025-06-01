#include "../include/hash_table.h"
#include <stdio.h>

int main() {
    hash_table *t = hash_table_create();

    char *key_value_pairs[][2] = {{"foo", "bar"},    {"baz", "qux"},
                                  {"quux", "corge"}, {"grault", "garply"},
                                  {"waldo", "fred"}, {"plugh", "fred"}};

    for (unsigned long i = 0;
         i < (sizeof(key_value_pairs) / sizeof(key_value_pairs[0])); i++)
        hash_table_insert(t, key_value_pairs[i][0], key_value_pairs[i][1]);

    char *search_result = hash_table_search(t, "foo");
    if (search_result != NULL)
        printf("search_result: %s\n", search_result);

    hash_table_delete(t, "foo");

    search_result = hash_table_search(t, "foo");
    if (search_result != NULL)
        printf("search_result: %s\n", search_result);

    hash_table_free(t);
}
