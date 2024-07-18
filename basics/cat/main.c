#include <stdio.h>
#include <stdlib.h>  // exit

void
filecopy(FILE *input_fp, FILE *output_fp);

int
main(int argc, char *argv[])
{
  char *prog = argv[0];
  FILE *fp;

  // no args, copy standard input
  if (argc == 1)
    {
      filecopy(stdin, stdout);
    }

  while (--argc > 0)
    {
      if ((fp = fopen( *++argv, "r")) == NULL)
        {
          fprintf(stderr, "%s: can't open %s\n", prog, *argv);
          exit(1);
        }

      filecopy(fp, stdout);
      fclose(fp);
    }

  if (ferror(stdout))
    {
      fprintf(stderr, "%s: error writing stdout\n", prog);
      exit(2);
    }

  exit(0);
}

void
filecopy(FILE *input_fp, FILE *output_fp)
{
  int c;
  while ((c = getc(input_fp)) != EOF)
    {
      putc(c, output_fp);
    }
}
