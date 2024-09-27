#include <stdio.h>
#include <stdlib.h>
#include "player/playerInit.h"


int* addToken(char** tab , char token,int hauteur , int column){
    for (int h = 0; h < hauteur-1; h++){
        if(tab[h+1][column*4+2]!=' '){
            tab[h][column*4+2]=token;

            int* xy = (int*)malloc(sizeof(int)*2);
            xy[0]=h;
            xy[1]=(column*4+2);
            return xy;
        }
        else if (h+2==hauteur && tab[h+1][column*4+2]==' ') {
            tab[h+1][column*4+2]=token;
            int* xy = (int*)malloc(sizeof(int)*2);
            xy[0]=(h+1);
            xy[1]=(column*4+2);
            return xy;
        }
    }
    return NULL;
}

char** createTab (int height, int width){


    //+1 pour le \0
    unsigned int hauteur = height;
    unsigned int largeur = (4*width)+2;

    char *ligne = (char*)malloc(largeur*sizeof(char));
    char **plateau = (char**)malloc(hauteur*sizeof(ligne));

    for (int h = 0; h < hauteur; h++) {
        char *temp = (char*)malloc(largeur*sizeof(char));
        plateau[h] = temp;
    }
    free(ligne);
    for (int h = 0; h < hauteur; h++) {
        for (int l = 0; l < largeur; l++) {
            plateau[h][l] = ' ';
            if(l%4==0) plateau[h][l] = '|';
            if(l==largeur-1) plateau[h][l] = '\0';
        }
    } return plateau;
}

void display(int height, int width , char **plateau) {


    for (int h = 0; h < height; h++) {
        int l = 0;
        while (plateau[h][l]!='\0'){
            if (plateau[h][l]=='X') {
                printf("\033[0;34m");
                printf("%c", plateau[h][l]);
                printf("\033[0m");
            }
            else if (plateau[h][l]=='O') {
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
    for (int i = 0; i < width; i++) {
        printf(" ");
        printf("\033[1;33m");
        printf("%03d", i);
        printf("\033[0m");
    }



    //Afficher les éléments
    /*for (int h = 0; h < height; h++) {
        int l = 0;
        while (plateau[h][l]!='\0'){
            switch (plateau[h][l]) {
                case 'X':
                    printf("\033[0;33m");
                    printf("%c", plateau[h][l]);
                    printf("\033[0m");
                    l++;
                    break;
                case 'O':
                    printf("\033[1;31m");
                    printf("%c", plateau[h][l]);
                    printf("\033[0m");
                    l++;
                    break;
                default:
                    printf("%c", plateau[h][l]);
                    l++;
                    break;
            }
            printf("\n");
        }

        //Afficher les colonnes
        for (int i = 0; i < width; i++) {
            printf(" ");
            printf("\033[0;36m");
            printf("%03d", i);
            printf("\033[0m");
        }
    }*/
    printf("\n");
}
#include "tableau.h"
