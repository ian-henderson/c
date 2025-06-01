#include <stdio.h>
#include <stdlib.h>

struct Person {
    char *name;
    int age;
};

int main(void) {
    struct Person *person_ptr;

    // malloc
    person_ptr = malloc(sizeof(struct Person));
    if (person_ptr == NULL) {
        printf("Error allocating memory for Person.\n");
        return 1;
    }
    person_ptr->name = "Ian";
    person_ptr->age = 31;
    printf("name: %s\nage: %d\n", person_ptr->name, person_ptr->age);
    free(person_ptr);

    // calloc
    person_ptr = calloc(1, sizeof(struct Person));
    if (person_ptr == NULL) {
        printf("Error allocating memory for Person.\n");
        return 1;
    }
    person_ptr->name = "Sean";
    person_ptr->age = 29;
    printf("name: %s\nage: %d\n", person_ptr->name, person_ptr->age);
    free(person_ptr);

    // array example using calloc and realloc
    int array_length = 10;
    int *array_ptr = calloc(array_length, sizeof(int));
    if (array_ptr == NULL) {
        printf("Error allocating memory for array.\n");
        return 1;
    }
    for (int i = 0; i < array_length; i++) {
        array_ptr[i] = i * 5;
        printf("%d\n", array_ptr[i]);
    }
    printf("Doubling array size...\n");
    array_length *= 2;
    int *new_array_ptr = realloc(array_ptr, sizeof(*array_ptr) * array_length);
    if (new_array_ptr == NULL) {
        printf("Error allocating memory for array.\n");
        return 1;
    }
    array_ptr = new_array_ptr;
    for (int i = 10; i < array_length; i++) {
        array_ptr[i] = i * 5;
    }
    for (int i = 0; i < array_length; i++) {
        printf("%d\n", array_ptr[i]);
    }
    free(array_ptr);
}
