#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* fake readline function */
char *
readline(char *prompt)
{
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char *copy = malloc(strlen(buffer) + 1);
  strcpy(copy, buffer);
  copy[strlen(copy) - 1] = '\0';
  return copy;
}

/* fake add_history function */
void
add_history(char *unused) {}

#else
#include <editline/history.h>
#include <editline/readline.h>
#endif

int
main(int argc, char **argv)
{
  puts("Lispy Version 0.1");
  puts("Press Ctrl+c to Exit\n");

  while (1)
    {
      char *input = readline("lisp> ");
      add_history(input);
      printf("No, you're a %s\n", input);
      free(input);
    }
}
