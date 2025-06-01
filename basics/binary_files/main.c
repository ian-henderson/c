#include <stdio.h>

int main(void) {
    FILE *fp;
    unsigned char bytes[] = {5, 37, 0, 88, 255, 12};

    // write bytes
    fp = fopen("output.bin", "wb");
    fwrite(bytes, sizeof(char), 6, fp);
    fclose(fp);

    // read bytes
    fp = fopen("output.bin", "rb");
    unsigned char c;
    while (fread(&c, sizeof(char), 1, fp) > 0)
        printf("%d\n", c);
    fclose(fp);
}
