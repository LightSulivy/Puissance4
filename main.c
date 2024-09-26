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
    }while(answer!='1' || answer!='2' || answer!='3' || answer!='4');        //revenir aux choix de menue tant que aucune réponse valable est donné
}


void optionMenue() {
    printf("/!| en cour de maintenance");
}

int finishMenue() {

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







int main(void) {
    printf("Hello, World!\n");
    return 0;
}