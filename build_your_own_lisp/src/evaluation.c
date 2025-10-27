#include "evaluation.h"
#include "mpc.h"    // mpc_ast_t
#include <math.h>   // pow
#include <stdlib.h> // atoi
#include <string.h> // strcmp, strstr

int get_branch_count(mpc_ast_t *t) {
    int total = 0;

    if (strcmp(t->tag, "expr|>") == 0)
        total++;

    for (int i = 0; i < t->children_num; i++)
        total += get_branch_count(t->children[i]);

    return total;
}

int get_leaf_count(mpc_ast_t *t) {
    if (strstr(t->tag, "number") || strstr(t->tag, "operator"))
        return 1;

    int total = 0;
    for (int i = 0; i < t->children_num; i++)
        total += get_leaf_count(t->children[i]);

    return total;
}

long eval(mpc_ast_t *t) {
    if (strstr(t->tag, "number"))
        return atoi(t->contents);

    char *op = t->children[1]->contents;

    long x = eval(t->children[2]);

    int i = 3;
    while (strstr(t->children[i]->tag, "expr")) {
        x = eval_op(x, op, eval(t->children[i]));
        i++;
    }

    return x;
}

long eval_op(long x, char *op, long y) {
    if (strcmp(op, "+") == 0)
        return x + y;
    if (strcmp(op, "-") == 0)
        return x - y;
    if (strcmp(op, "*") == 0)
        return x * y;
    if (strcmp(op, "/") == 0)
        return x / y;
    if (strcmp(op, "%") == 0)
        return x % y;
    if (strcmp(op, "^") == 0)
        return pow(x, y);
    return 0;
}
