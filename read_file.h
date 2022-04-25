#include <stdbool.h>
#include "stdio.h"
#include "stdlib.h"
#include <string.h>

char **creer_tab(int file_size, int nbChar);
void afficher_tab(char * string, int nbString);
char** lire_fichier(char * filename);
void detruire_tab(char ** tab, int file_size);