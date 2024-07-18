#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
  char *badchar;
  char *s = "3490";

  unsigned long int x = strtoul(s, &badchar, 10);

  if (*badchar != '\0')
    {
      printf("Partial conversion: %lu\n", x);
      printf("Invalid character: %c\n", *badchar);
      return 1;
    }

  printf("Success! %lu\n", x);
}
