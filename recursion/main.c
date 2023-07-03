#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y) {
        if (x == 1) return y;

        // recursive step
        if (x > 1) return y + multiply(x - 1, y);

        return 0;
}

int main() {
        printf("30,000 times 50,000 is %d.\n", multiply(30000, 50000));

        return 0;
}
