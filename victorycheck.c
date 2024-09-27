#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player/playerInit.h"
#include "game/gameInit.h"

    #define Case 4;

    int victoiryHorizontal(char **tab, int i, int j, char token,int longTab) {  //Victoire selon l'horirontal

                                //on enregistre l'emplacement du joueur pour vérifier les case à coté de lui
                                //on rajoute Case pour déplacer le "curseur" sur les côtés jouables
        int mouvement = i +Case;
        int inARow=1;           //Le nombre de point actuelle pour valider la victoire, on le met à 1 car on le compte

        while(tab[mouvement][j]== token && mouvement < longTab) { //tant que le "curseur" tombe sur le même joueur ou ne dépasse pas le tableau de jeu
            //if (tab[i][j]==player) {
                inARow++;
           // }
            mouvement+=Case;    //on augmente le "curseur" vers une case jouable
        }


        mouvement = i - Case;   //on déplace le curseur vers la position d'origine en direction de l'autre côté

        while(tab[mouvement][j]==token && mouvement > 0) {  //same que avant, mais on refarde si le "curseur" ne dépace pas le tableau
            //if (tab[i][j]==player) {
                inARow++;
            //}
            mouvement-=Case;
        }
        if (inARow>=4) {
            return 1;
        }
        return 0;
    }

    int victoiryVertical(char **tab, int i, int j, char player,int tabHeight) {  //same que la victoire Horizontale mais en hauteur
        int mouvement = j +1;
        int inARow=1;

        while(tab[i][mouvement]==player && mouvement < tabHeight) {
            //if (tab[i][j]==player) {
            inARow++;
            // }
            mouvement++;
        }


        mouvement = j - 1;

        while(tab[i][mouvement]==player && mouvement > 0) {
            //if (tab[i][j]==player) {
            inARow++;
            //}
            mouvement--;
        }
        if (inARow>=4) {
            return 1;
        }
        return 0;
    }

    int victoiryDiagonalDH(char **tab, int i, int j, char player,int tabHeight, int longTab) {//same que la victoire Horizontale mais en diagonale avec un peu plus de calcul
        int mouvementI = i +Case;
        int mouvementJ = j +1;

        int inARow=1;

        while(tab[mouvementI][mouvementJ]==player && mouvementJ < tabHeight && mouvementI > longTab) {
            //if (tab[i][j]==player) {
            inARow++;
            // }
            mouvementI+= Case;
            mouvementJ++;
        }


        mouvementI = i - Case;
        mouvementJ=j - 1;

        while(tab[mouvementI][mouvementJ]==player && mouvementI > 0 && mouvementJ > 0) {
            //if (tab[i][j]==player) {
            inARow++;
            //}
            mouvementI-= Case;
            mouvementJ--;
        }
        if (inARow>=4) {
            return 1;
        }
        return 0;
    }

    int victoiryDiagonalGH(char **tab, int i, int j, char player,int tabHeight, int longTab) { //same que la victoire Horizontale mais en diagonale avec un peu plus de calcul
        int mouvementI = i -Case;
        int mouvementJ = j +1;

        int inARow=1;

        while(tab[mouvementI][mouvementJ]==player && mouvementJ < tabHeight && mouvementI > 0) {
            //if (tab[i][j]==player) {
            inARow++;
            // }
            mouvementI-= Case;
            mouvementJ++;
        }


        mouvementI = i + Case;
        mouvementJ=j - 1;

        while(tab[mouvementI][mouvementJ] == player && mouvementI < longTab && mouvementJ > 0) {
            //if (tab[i][j]==player) {
            inARow++;
            //}
            mouvementI+= Case;
            mouvementJ--;
        }
        if (inARow>=4) {
            return 1;
        }
        return 0;
    }

/*    int equality() {
        char answer = 0;
        printf("                    ___ __     ");
        printf("  ___  ____ _____ _/ (_) /____ ");
        printf(" / _ \/ __ `/ __ `/ / / __/ _ \ ");
        printf("/  __/ /_/ / /_/ / / / /_/  __/");
        printf("\___/\__, /\__,_/_/_/\__/\___/ ");
        printf("    /____/                     ");
        do{
            printf("1-Rejouer   2-Menue   3-arrêté");
            scanf("%c", &answer);
            switch (answer) {
                case '1':
                    initGame(game->playerCount, game->plateau, game->winCount);
                break;
                case '2':
                    Startmenue();
                break;
                case '3':
                    return 0;
                default:
                    printf("           Une erreur de saisie est survenue\0    Veuillez sélectionner une VRAI valeur maintenant ");
                //printf("    Veuillez sélectionner une VRAI valeur maintenant ");
            }
        }while(answer!='1' || answer!='4');        //revenir aux choix de menue tant que aucune réponse valable est donné:
        return 0;
    } */
    int equality() {return 0;};



    int victoire(char **tab, int i, int j, char player, int longTab, int tabHeight) {
        if(victoiryHorizontal(tab, i, j, player, longTab) || victoiryVertical(tab, i, j, player, tabHeight) || victoiryDiagonalDH(tab, i, j, player, tabHeight, longTab) || victoiryDiagonalGH(tab, i, j, player, tabHeight, longTab)) {
            return 1;
        }
        return 0;
    }