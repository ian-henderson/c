#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

void addOne(int *n) { (*n)++; }

void move(Point *p) {
    p->x++;
    p->y++;
}

int main() {
    int a = 0;
    addOne(&a);
    printf("%d\n", a);

    Point p = {0, 0};
    move(&p);
    printf("(%d, %d)\n", p.x, p.y);
}
