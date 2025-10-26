#ifndef evaluation_h
#define evaluation_h

#include "mpc.h" // mpc_ast_t

int get_branch_count(mpc_ast_t *t);

int get_leaf_count(mpc_ast_t *t);

long eval(mpc_ast_t *t);

long eval_op(long x, char *op, long y);

#endif
