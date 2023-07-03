#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

int 
main() 
{
	node_t *head = create_node(1);
	printf("created node with value of %d.\n", head->value);
	print_list(head);

	push_to_end(head, 8);
	printf("pushed 8 to end.\n");
	print_list(head);

	push_to_start(&head, 2);
	printf("pushed 2 to start.\n");
	print_list(head);

	push_to_end(head, 9);
	printf("pushed 9 to end.\n");
	print_list(head);

	remove_by_index(&head, 2);
	printf("removed node from index 2.\n");
	print_list(head);

	remove_last(head);
	printf("removed last node.\n");
	print_list(head);

	for (int i = 0; i < 50; i++)
		push_to_start(&head, i);
	printf("added 50 nodes.\n");
	print_list(head);

	for (int i = 0; i < 50; i++)
		remove_last(head);
	printf("removed the last node 50 times.\n");
	print_list(head);

	printf("popped the first node (%d).\n", pop(&head));
	print_list(head);

	free(head);
}
