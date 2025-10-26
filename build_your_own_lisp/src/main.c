#include "evaluation.h"
#include "mpc.h"
#include <signal.h>  // signal, SIGINT
#include <stdbool.h> // true
#include <stdio.h>   // printf
#include <stdlib.h>  // free, malloc, exit
#include <string.h>  // strcpy, strlen

#ifdef _WIN32

static const int BUFFER_SIZE = 2048;
static char buffer[BUFFER_SIZE];

// Fake readline fn
char *readline(char *prompt) {
    fputs(prompt, stdout);
    fgets(buffer, BUFFER_SIZE, stdin);
    char *copy = malloc(strlen(buffer) + 1);
    strcpy(copy, buffer);
    copy[strlen(copy) - 1] = '\0';
    return copy;
}

// Fake add_history fn
void add_history(char *unused) {}

#else

#include <editline/readline.h> // readline, add_history

#endif

void signal_callback(int signal) {
    printf("\nCaught signal: %d\nExiting.\n", signal);
    exit(signal);
}

int main() {
    signal(SIGINT, signal_callback);
    puts("Lispy Version 0.0.1");
    puts("Press Ctrl+c to Exit\n");

    mpc_parser_t *Number = mpc_new("number");
    mpc_parser_t *Operator = mpc_new("operator");
    mpc_parser_t *Expr = mpc_new("expr");
    mpc_parser_t *Lispy = mpc_new("lispy");

    mpca_lang(MPCA_LANG_DEFAULT, "\
              number: /-?[0-9]+/ ;\
              operator: '+' | '-' | '*' | '/' ;\
              expr: <number> | '(' <operator> <expr>+ ')' ;\
              lispy: /^/ <operator> <expr>+ /$/ ;\
              ",
              Number, Operator, Expr, Lispy);

    while (true) {
        char *input = readline("lispy> ");
        add_history(input);

        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Lispy, &r)) {
            mpc_ast_print(r.output);
            long result = eval(r.output);
            printf("%li\n", result);
            printf("Branch count: %d\n", get_branch_count(r.output));
            printf("Leaf count: %d\n", get_leaf_count(r.output));
            mpc_ast_delete(r.output);
        } else {
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }

        free(input);
    }

    mpc_cleanup(4, Number, Operator, Expr, Lispy);
    return 0;
}
