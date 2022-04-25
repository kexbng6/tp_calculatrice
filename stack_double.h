#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct _stack_double {
    int capacity;
    int top;
    double *data;
} stack_double;

//entêtes de fonctions
stack_double stack_create_double();
bool stack_is_empty_double(stack_double s);
void stack_destroy_double(stack_double *s);
int stack_push_double(stack_double *s, double val);
int stack_pop_double(stack_double *s, double *val);
int stack_peek_double(stack_double s, double *val);
