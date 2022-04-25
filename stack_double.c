#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack_double.h"

stack_double stack_create_double(){
    stack_double s;
    s.capacity = 4;
    s.top=-1;
    s.data = (double*)malloc(sizeof (double)*s.capacity);

    return s;
}

int stack_push_double(stack_double *s, double val){
    if(s->top >= s->capacity){
        s->capacity *=2;
        s->data = (double *) realloc(s->data, s->capacity);
        if (s->data==NULL)
            return 1;
    }
    s->top+=1;
    s->data[s->top]=val;
    return 0;
}

bool stack_is_empty_double(stack_double s){
    return s.top==-1;
}

int stack_pop_double(stack_double *s, double *val){
    if (stack_is_empty_double(*s))
        return 1;
    *val = s->data[s->top];
    s->top-=1;

    return 0;
}

int stack_peek_double(stack_double s, double *val){
    if (stack_is_empty_double(s))
        return 1;
    *val = s.data[s.top];
    return 0;
}

//désalloue la mémoire de la pile et met data à NULL, ainsi que la capacity et le sommet à -1.
void stack_destroy_double(stack_double *s){
    s->data=NULL;
    free(s->data);
    s->capacity = -1;
    s->top = -1;
};