#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char * name;
	int age;
} Person;

int main() {
	Person *p = (Person *) malloc(sizeof(Person));

	p->name = "Ian";
	p->age = 30;
	printf("name: %s\nage: %d\n", p->name, p->age);

	free(p);

	return 0;
}
