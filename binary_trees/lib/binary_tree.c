#include <stdio.h>
#include <stdlib.h>
#include "./binary_tree.h"

node_t *create_tree(int value) {
        node_t *tree = (node_t *) malloc(sizeof(node_t));
        tree->value = value;
        tree->left = NULL;
        tree->right = NULL;

        return tree;
}

void insert(node_t *tree, int value) {
	if (tree->value == 0) {
		// insert on current (empty) position
		tree->value = value;
		return;
	}

	if (value < tree->value) {
		// insert left
		if (tree->left != NULL)	{
			insert(tree->left, value);
                        return;
		}

                tree->left = create_tree(value);
                return;
	}

        if (value >= tree->value) {
                // insert right
                if (tree->right != NULL) {
                        insert(tree->right,value);
                        return;
                }

                tree->right = create_tree(value);
        }
}

/* depth-first search */
void printDFS(node_t * current) {
        // The operations performed on trees requires searching in one of two
        // main ways: Depth First Search and Breadth-first search.
        // Depth-first search (DFS) is an algorithm for traversing or
        // searching tree or graph data structures. One starts at the root
        // and explores as far as possible along each branch before
        // backtracking. There are three types of depth first search
        // traversal: pre-order visit, left, right, in-order left, visit,
        // right, post-order left, right, visit. Breadth-first search (BFS)
        // is an algorithm for traversing or searching tree or graph
        // structures. In level-order, where we visit every node on a level
        // before going to a lower level.

	if (current == NULL) return;   /* security measure */

	if (current != NULL) printf("%d ", current->value);

	if (current->left != NULL) printDFS(current->left);

	if (current->right != NULL) printDFS(current->right);
}
