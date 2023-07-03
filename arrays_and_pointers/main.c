#include <stdio.h>
#include <stdlib.h>

int main() {
	int nRows = 2;
	int nCols = 5;
	int i, j;

	// allocate memory for nRows pointers
	char **pVowels = (char **) malloc(nRows * sizeof(char *));

	// for each row, allocate memory for nCols elements
	pVowels[0] = (char *) malloc(nCols * sizeof(char));
	pVowels[1] = (char *) malloc(nCols * sizeof(char));

	pVowels[0][0] = 'A';
	pVowels[0][1] = 'E';
	pVowels[0][2] = 'I';
	pVowels[0][3] = 'O';
	pVowels[0][4] = 'U';

	pVowels[1][0] = 'a';
	pVowels[1][1] = 'e';
	pVowels[1][2] = 'i';
	pVowels[1][3] = 'o';
	pVowels[1][4] = 'u';

	for (i = 0; i < nRows; i++) {
		for(j = 0; j < nCols; j++) 
			printf("%c ", pVowels[i][j]);

		printf("\n");
	}

	// free individual rows
	free(pVowels[0]);
	free(pVowels[1]);

	// free the top-level pointer
	free(pVowels);
}

