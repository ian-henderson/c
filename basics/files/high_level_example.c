#include <stdio.h>

int main(void) {
    char *filename = "high_level_example.txt";
    FILE *fp;

    // write mode
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Not able to read %s\n", filename);
        return 1;
    }
    fprintf(fp, "some text\n");
    fclose(fp);

    // append mode
    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Not able to read %s\n", filename);
        return 1;
    }
    fprintf(fp, "some more text\n");
    fclose(fp);

    // read mode
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Not able to read %s\n", filename);
        return 1;
    }
    char buffer[1024];
    while (fgets(buffer, sizeof buffer, fp))
        printf("%s", buffer);
    fclose(fp);
}
