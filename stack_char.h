#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct _stack_char {
    int capacity;
    int top;
    char *data;
} stack_char;

//entêtes de fonctions
stack_char stack_create_char();
bool stack_is_empty_char(stack_char s);
void stack_destroy_char(stack_char *s);
int stack_push_char(stack_char *s, char val);
int stack_pop_char(stack_char *s, char *val);
int stack_peek_char(stack_char s, char *val);