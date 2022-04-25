#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "stack_double.h"
#include "stack_char.h"
#include "read_file.h"

double op(char operator, double operand_1, double operand_2){
    double result;
    switch (operator) {
        case '+' :
            result = operand_1 + operand_2;
            break;
        case '-':
            result = operand_1 - operand_2;
            break;
        case 'x':
            result = operand_1 * operand_2;
            break;
        case '/':
            result = operand_1 / operand_2;
            break;
        default:
            result = 0;
    }
    return result;
}

int type_expression(char cara){
    if (cara =='i')
        return -1;
    else if (cara =='p')
        return 0;
    else if (cara =='f')
        return 2;
    return 1;
}

bool is_operand(char expression){
    if (expression >= '0' && expression<='9')
        //if (expression >= 48 && expression<=57)
        return true;
    return false;
}

bool is_operator(char expression){
    if (expression == '+'||expression == '-' ||expression == 'x'||expression == '/')
        return true;
    return false;
}

int nb_oper(char* expression){
    int nb_operator=0;
    int nb_operand=0;
    for (int i = 0; i < strlen(expression); ++i) {
        if(is_operator(expression[i]))
            nb_operator++;
        else if(is_operand(expression[i]))
            nb_operand++;
    }
    if (nb_operator==nb_operand-1)
        return 0;
    else
        return 1;
}

char *infix_to_postfix(char* infix){
    char valeur;
    char * postfix;
    int cpt=0;
    stack_char s = stack_create_char();
    postfix = malloc(sizeof (char) * strlen(infix));
    for(int i = 0; i < strlen(infix); i++){
        if(is_operand(infix[i])){
            //we just add operands in the new postfix string
            postfix[cpt]=infix[i];
            cpt++;
            postfix[cpt]=' ';
            cpt++;
        } else if (infix[i]=='('){
            //we push opening parenthesis into the stack
            stack_push_char(&s, infix[i]);
        } else if (infix[i]==')'){
            // we pop everything into the postfix
            while (!stack_is_empty_char(s)){
                stack_pop_char(&s, &postfix[cpt]);
                cpt++;
            }
        } else if(is_operator(infix[i])){
            // this is an operator. We add it to the postfix based on the priority of what is already in the stack and push it
            /*if (infix[i]=='x' || infix[i]=='/'){
                postfix[cpt]=infix[i];
                cpt++;
            }
            else*/
                stack_push_char(&s, infix[i]);
        }
    }
    //pop all the operators from the s at the end of postfix and end the postfix with '\0'
    int j=0;
    while(!stack_is_empty_char(s)){
            stack_pop_char(&s, &postfix[cpt]);
            j++;
            cpt++;
    }
    postfix[cpt]='\0';
    stack_destroy_char(&s);
    return postfix;
}

double evaluate_postfix(char* postfix, stack_double *s) {
    double rhs, lhs;
    if (nb_oper(postfix)==1){
        printf("impossible de traiter l'expression\n");
        return 1;
    };
    for (int i = 0; i < strlen(postfix); i++) {
        //printf("valeur = %c\n", postfix[i]);
        if (is_operand(postfix[i]))
            stack_push_double(s, atof(&postfix[i]));
        else if (is_operator(postfix[i])) {
            stack_pop_double(s, &rhs);
            //printf("%.2f\n", rhs);
            stack_pop_double(s, &lhs);
            //printf("%.2f\n", lhs);
            stack_push_double(s, op(postfix[i], lhs, rhs));
        }
    }
    free(postfix);
    return s->data[0];
}