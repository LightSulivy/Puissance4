#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {

    //Values pour la grille

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

    return 0;
}

#include <stdio.h>

void Startmenue() {  //Menue du début
    char answer=0;
    printf("______________________________________________");
    printf("                                               ");
    printf("__/\\\\\\\\\\\\\___        ____________/\\\____");
    printf(" _\/\\\/////////\\\_        __________/\\\\\____");
    printf("  _\/\\\_______\/\\\_        ________/\\\/\\\____");
    printf("   _\/\\\\\\\\\\\\\/__        ______/\\\/\/\\\____");
    printf("    _\/\\\/////////____        ____/\\\/__\/\\\____");
    printf("     _\/\\\_____________        __/\\\\\\\\\\\\\\\\_");
    printf("      _\/\\\_____________        _\///////////\\\//__");
    printf("       _\/\\\_____________        ___________\/\\\____");
    printf("        _\///______________        ___________\///_____");
    printf("                                                        ");
    do {
        printf("_________________________________________________________");
        printf("         1-Commencer                    2-Option         ");
        printf("          3-Crédit                       4-Help          ");
        scanf("%c", &answer);

        //Renvoie la reponse à un switch pour entrer dans un menue ou jeu

        switch (answer) {
            case '1':
                startGame();
                break;
            case '2':
                optionMenue();
                break;
            case '3':
                creditMenue();
                break;
            case '4':
                helpMenue();
                break;
            default:
                printf("           Une erreur de saisie est survenue\0    Veuillez sélectionner une VRAI valeur maintenant ");
                //printf("    Veuillez sélectionner une VRAI valeur maintenant ");
        }
    }while(answer!='1' || answer!='4');        //revenir aux choix de menue tant que aucune réponse valable est donné
}


void optionMenue() {
    printf("/!| en cour de maintenance");
}


int winMenu(char playerWin, char playerLoss) {
    printf("    :::       ::: ::::::::::: ::::    ::: ");
    printf("   :+:       :+:     :+:     :+:+:   :+:  ");
    printf("  +:+       +:+     +:+     :+:+:+  +:+   ");
    printf(" +#+  +:+  +#+     +#+     +#+ +:+ +#+    ");
    printf("+#+ +#+#+ +#+     +#+     +#+  +#+#+#     ");
    printf("#+#+# #+#+#      #+#     #+#   #+#+#      ");
    printf("###   ###   ########### ###    ####       ");

    printf("%c est vraiment trop fort", playerWin);
    printf("%c t'est juste très NULL (ou ASCII = '0' )", playerLoss);
}




#define Case 4;
#define f

int victoiryHorizontal(int **tab, int i, int j, int player,int longTab) {  //Victoire selon l'horirontal

                            //on enregistre l'emplacement du joueur pour vérifier les case à coté de lui
                            //on rajoute Case pour déplacer le "curseur" sur les côtés jouables
    int mouvement = i +Case;
    int inARow=1;           //Le nombre de point actuelle pour valider la victoire, on le met à 1 car on le compte

    while(tab[mouvement][j]==player && mouvement < longTab) { //tant que le "curseur" tombe sur le même joueur ou ne dépasse pas le tableau de jeu
        //if (tab[i][j]==player) {
            inARow++;
       // }
        mouvement+=Case;    //on augmente le "curseur" vers une case jouable
    }


    mouvement = i - Case;   //on déplace le curseur vers la position d'origine en direction de l'autre côté

    while(tab[mouvement][j]==player && mouvement > 0) {  //same que avant, mais on refarde si le "curseur" ne dépace pas le tableau
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

int victoiryVertical(int **tab, int i, int j, int player,int tabHeight) {  //same que la victoire Horizontale mais en hauteur
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

int victoiryDiagonalDH(int **tab, int i, int j, int player,int tabHeight, int longTab) {//same que la victoire Horizontale mais en diagonale avec un peu plus de calcul
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

int victoiryDiagonalGH(int **tab, int i, int j, int player,int tabHeight, int longTab) { //same que la victoire Horizontale mais en diagonale avec un peu plus de calcul
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

    while(tab[mouvementI][mouvementJ]==player && mouvementI < longTab && mouvementJ > 0) {
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

int victoire(int **tab, int i, int j, Player player, int longTab, int tabHeight) {
    if(victoiryHorizontal(&&tab, i, j, player, longTab) || victoiryVertical(&&tab, i, j, player, tabHeight) || victoiryDiagonalDH(&&tab, i, j, player, tabHeight, longTab) || victoiryDiagonalGH(&&tab, i, j, player, tabHeight, longTab)) {
        return 1;
    }
    return 0;
}

int equality() {
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
                startGame();
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
}






int main(void) {
    printf("Hello, World!\n");
    return 0;
}