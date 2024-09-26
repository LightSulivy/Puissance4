#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(void) {

    FILE *gameconf = fopen("gameconfig.txt", "r");
    if (gameconf == NULL) {
        printf("Error opening file");
    }
    char line[80] = {0};
    fscanf(gameconf, "%s", line);
    printf("%s", line);

    fclose(gameconf);
   /* //Values pour la grille

    unsigned int tailleHauteur = 6;
    unsigned int tailleLarger = 20;

    //+1 pour le \0
    unsigned int hauteur = tailleHauteur;
    unsigned int largeur = (4*tailleLarger)+2;

    char *ligne = (char*)malloc(largeur*sizeof(char));
    char **plateau = (char**)malloc(hauteur*sizeof(ligne));

    for (int h = 0; h < hauteur; h++) {
        char *temp = (char*)malloc(largeur*sizeof(char));
        plateau[h] = temp;
    }

    for (int h = 0; h < hauteur; h++) {
        for (int l = 0; l < largeur; l++) {
            plateau[h][l] = ' ';
            if(l%4==0) plateau[h][l] = '|';
            if(l==largeur-1) plateau[h][l] = '\0';
        }
    }


    //Afficher les éléments
    for (int h = 0; h < hauteur; h++) {
        int l = 0;
        while (plateau[h][l]!='\0'){
            if (plateau[h][l]=='x') {
                printf("\033[0;34m");
                printf("%c", plateau[h][l]);
                printf("\033[0m");
            }
            else if (plateau[h][l]=='o') {
                printf("\033[0;31m");
                printf("%c", plateau[h][l]);
                printf("\033[0m");
            }
            else {
                printf("%c", plateau[h][l]);
            }

            l++;
        }
        printf("\n");
    }

    //Afficher les colonnes
    for (int i = 0; i < tailleLarger; i++) {
        printf(" ");
        printf("\033[1;33m");
        printf("%03d", i);
        printf("\033[0m");
    }
    */
    return 0;
}
