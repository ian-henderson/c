#include <stdio.h>

enum Level
{
  LOW,
  MEDIUM,
  HIGH
};

int
main(void)
{
  enum Level myVar = MEDIUM;

  switch (myVar)
    {
    case 0:
      printf("Low Level\n");
      break;
    case 1:
      printf("Medium Level\n");
      break;
    case 2:
      printf("High Level\n");
      break;
    }
}
