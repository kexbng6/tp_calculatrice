#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack_char.h"

stack_char stack_create_char(){
    stack_char s;
    s.capacity = 4;
    s.top=-1;
    s.data = (char*)malloc(sizeof (char)*s.capacity);

    return s;
}

int stack_push_char(stack_char *s, char val){
    if(s->top >= s->capacity){
        s->capacity *=2;
        s->data = (char *) realloc(s->data, s->capacity);
        if (s->data==NULL)
            return 1;
    }
    s->top+=1;
    s->data[s->top]=val;
    return 0;
}

bool stack_is_empty_char(stack_char s){
    return s.top==-1;
}

int stack_pop_char(stack_char *s, char *val){
    if (stack_is_empty_char(*s))
        return 1;
    *val = s->data[s->top];
    s->top-=1;

    return 0;
}

int stack_peek_char(stack_char s, char *val){
    if (stack_is_empty_char(s))
        return 1;
    *val = s.data[s.top];
    return 0;
}

//désalloue la mémoire de la pile et met data à NULL, ainsi que la capacity et le sommet à -1.
void stack_destroy_char(stack_char *s){
    s->data=NULL;
    s->capacity =-1;
    s->top = -1;
    free(s->data);
};