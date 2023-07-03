#include "./linked_list.h"

#include <stdio.h>
#include <stdlib.h>

node_t* create_node(int value) {
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->next = NULL;
  node->value = value;

  return node;
}

int pop(node_t** head) {
  int returnValue = -1;
  node_t* next_node = NULL;

  if (*head == NULL) return -1;

  next_node = (*head)->next;
  returnValue = (*head)->value;
  free(*head);
  *head = next_node;

  return returnValue;
}

void print_list(node_t* head) {
  node_t* current = head;

  printf("linked list: ");

  while (current != NULL) {
    printf("%d", current->value);
    if (current->next != NULL)
      printf(" => ");
    else
      printf("\n");
    current = current->next;
  }
}

void push_to_end(node_t* head, int value) {
  node_t* current = head;

  while (current->next != NULL) current = current->next;

  current->next = create_node(value);
}

void push_to_start(node_t** head, int value) {
  node_t* new_node = create_node(value);

  new_node->next = *head;
  *head = new_node;
}

int remove_by_index(node_t** head, int n) {
  int i = 0, returnValue = -1;
  node_t *current = *head, *temp_node = NULL;

  if (n == 0) return pop(head);

  for (i = 0; i < n - 1; i++) {
    if (current->next == NULL) return -1;
    current = current->next;
  }

  if (current->next == NULL) return -1;

  temp_node = current->next;
  returnValue = temp_node->value;
  current->next = temp_node->next;
  free(temp_node);

  return returnValue;
}

int remove_last(node_t* head) {
  int returnValue = 0;

  if (head->next == NULL) {
    returnValue = head->value;
    free(head);

    return returnValue;
  }

  node_t* current = head;
  while (current->next->next != NULL) current = current->next;

  returnValue = current->next->value;
  free(current->next);
  current->next = NULL;

  return returnValue;
}
