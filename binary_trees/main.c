#include "lib/binary_tree.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
        node_t *tree = create_tree(0);

        insert(tree, 5);
        insert(tree, 8);
        insert(tree, 4);
        insert(tree, 3);

        printDFS(tree);
        printf("\n");

        return 0;
}
