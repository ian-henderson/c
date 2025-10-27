#include <stdio.h>
#include <stdlib.h>

unsigned long long int factorial(int m) {
    unsigned long long int value = m;
    while (m > 1)
        value *= --m;
    return value;
}

int main(int argc, char *argv[]) {
    printf("Enter a number: ");
    int m;
    scanf("%d", &m);
    unsigned long long int n = factorial(m);
    printf("The factorial of %d is %llu.\n", m, n);
    exit(0);
}
