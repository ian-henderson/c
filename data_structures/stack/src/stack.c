#include "stdio.h"
#include "stdlib.h" // exit, realloc
#include "../include/stack.h"

// "public" functions

stack *
stack_create(void)
{
  stack *s = malloc(sizeof(stack));
  s->buffer_size = 100;
  s->buffer = malloc(sizeof(int) * s->buffer_size);
  s->cursor = 0;
  return s;
}

void
stack_free(stack *s)
{
  free(s->buffer);
  free(s);
}

int
stack_pop(stack *s, int *value)
{
  if (s->cursor == 0)
    {
      return 1;
    }

  s->cursor--;

  // Gives half of buffer memory back if buffer size is greater than 100 and the
  // stack is using less than a quarter of the allocated memory.
  if (s->cursor > 100 && s->cursor < (s->buffer_size / 4))
    {
      s->buffer_size /= 2;
      int *new_buffer = realloc(s->buffer, sizeof(int) * s->buffer_size);
      if (new_buffer == NULL)
        {
          fprintf(stderr, "Failed to decrease stack size.\n");
          stack_free(s);
          exit(1);
        }
      s->buffer = new_buffer;
    }

  if (value != NULL)
    {
      *value = s->buffer[s->cursor];
    }

  return 0;
}

void
stack_print(stack *s)
{
  printf("[");

  for (int i = 0; i < s->cursor; i++)
    {
      printf("%d", s->buffer[i]);

      if (i != (s->cursor - 1))
        {
          printf(", ");
        }
    }

  printf("]\n");
}

int
stack_push(stack *s, int x)
{
  if (s->cursor == (s->buffer_size - 1))
    {
      // double buffer memory
      s->buffer_size *= 2;
      int *new_buffer = realloc(s->buffer, sizeof(int) * s->buffer_size);
      if (new_buffer == NULL)
        {
          fprintf(stderr, "Failed to increase stack size.\n");
          stack_free(s);
          exit(1);
        }
      s->buffer = new_buffer;
    }

  s->buffer[s->cursor++] = x;

  return 0;
}
