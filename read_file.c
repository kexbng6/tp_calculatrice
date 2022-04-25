#include "stdio.h"
#include "stdlib.h"
#include <string.h>

char **creer_tab(int file_size, int nbChar){
    char **tab;
    tab = (char**) malloc(sizeof(char*)* file_size);
    for (int i = 0; i <= nbChar; ++i) {
        tab[i] = (char*) malloc(sizeof(char*)* nbChar);
    }
    return tab;
}

void afficher_tab(char ** string, int nbString){
    for(int i=0;i<=nbString;i++){
        printf("%d ",i+1);
        printf("%s\n",string[i]);
    }
}

void detruire_tab(char ** tab, int file_size){
    for (int i = 0; i < file_size; i++)
    {
        free(tab[i]);
    }
    free(tab);
}

char** lire_fichier(char * filename) {
    const int TAILLE_FICH = 20;
    const int MAX_CHAR = 80;
    FILE *fid;
    char **unStr = creer_tab(TAILLE_FICH, MAX_CHAR);
    int i;
    fid = fopen(filename, "r"); // ouverture du fichier
    for (i = 0; i < TAILLE_FICH; i++) {
        fscanf(fid, "%s", unStr[i]);
    }
    fclose(fid);// fermeture du fichier
    return unStr;
}