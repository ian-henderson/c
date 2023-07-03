#include <stdio.h>

FILE *fptr;

int main() {
	// write mode
	fptr = fopen("filename.txt", "w");
	if (fptr == NULL) {
		printf("Not able to read filename.txt\n");
		return 1;
	}
	fprintf(fptr, "some text\n");
	fclose(fptr);

	// append mode
	fptr = fopen("filename.txt", "a");
	if (fptr == NULL) {
		printf("Not able to read filename.txt\n");
		return 1;
	}
	fprintf(fptr, "some more text\n");
	fclose(fptr);

	// read mode
	fptr = fopen("filename.txt", "r");
	if (fptr == NULL) {
		printf("Not able to read filename.txt\n");
		return 1;
	}
	char contents[100];
	while (fgets(contents, 100, fptr)) 
		printf("%s", contents);
	fclose(fptr);

	return 0;
}
