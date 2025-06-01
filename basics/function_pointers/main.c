#include <stdio.h>

void f1(int var) { printf("this is f1 and var is: %d\n", var); }

void f2(int var) { printf("this is f2 and var is: %d\n", var); }

void f3(int var) { printf("this is f3 and var is: %d\n", var); }

int main() {
    void (*pf[])(int) = {f1, f2, f3};

    for (int i = 0; i < 3; i++)
        pf[i](i);
}
