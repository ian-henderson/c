#include <stdio.h>
#include <threads.h>

int run(void *arg) {
    int *a = arg;
    printf("THREAD: Running with arg %d.\n", *a);
    return 12;
}

int main() {
    thrd_t t;
    int arg = 3490, res;

    printf("Launching a thread.\n");

    thrd_create(&t, run, &arg);

    printf("Doing other things while thread runs.\n"
           "Waiting for thread to complete...\n");

    thrd_join(t, &res);

    printf("Thread exited with return value %d.\n", res);
}
