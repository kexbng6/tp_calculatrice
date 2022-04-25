#include "calculatrice.h"


int main(int args, char** kwargs) {
    if(args <3){
        printf("Le nombre d'arguments est insuffisant\n");
        return 1;
    }
    int type = type_expression(*kwargs[1]);
    stack_double s1 = stack_create_double();
    char* postfix_exp;
    if (type==2){
         //-parcourir tableau -> chaque ligne du tableau = le même traitement que le switch l.27
        char**lig = lire_fichier(*kwargs + 2);
        for (int i = 0; i < 5/*strlen(&lig)*/; ++i) {//valeur de la borne max en dur pour tester
            if (nb_oper(lig[i])==1)
                printf("%s : impossible de traiter l'expression", lig[i]);
            if (lig[i][0]==-1){
                printf("%s= %.2f\n", lig[i], evaluate_postfix(infix_to_postfix(lig[i]), &s1));
            }
            else if(lig[i][0]==0){
                printf("%s= %.2f\n", lig[i], evaluate_postfix(lig[i], &s1));
            }
        }
        detruire_tab(&postfix_exp,5);//valeur du paramètre en dur pour tester
    }
    switch (type) {
        case -1://opération infix
            postfix_exp = infix_to_postfix(kwargs[2]);
            if (nb_oper(postfix_exp)==1){
                printf("impossible de traiter l'expression\n");
                return 1;
            };
            printf("résulat de l'opération infixe %.2f\n", evaluate_postfix(postfix_exp,&s1));
            stack_destroy_double(&s1);
            break;
        case 0://opération postfix
            printf("résulat de l'opération postfixe %.2f\n",evaluate_postfix(infix_to_postfix(kwargs[2]), &s1));
            stack_destroy_double(&s1);
            break;
        case 1:
            printf("Veuillez passer en paramètre la lettre 'i' pour infixe, la lettre 'p' pour postfixe ou 'f' suivi d'un nom de fichier.");
            break;
        default:
            printf("Erreur inconnue");
    }
    //printf("résulat de l'opération %f\n", evaluate_postfix(infix_to_postfix("2x2-3+4"),&s1));
    return 0;
}