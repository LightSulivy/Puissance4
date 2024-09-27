/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Startmenu() {  //Menue du début
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

    void creditMenue() {
        printf("Cette merveille à été fait par les fabuleux :  ");
        printf("        Robin Palmier ! ");
        printf("        Bastien Teissiere ! ");
        printf("        Yohan Georgelin ! ");
        printf("Dites nous merci svp, sinon on vous while(1); ");
        char *answer=0;
        scanf("%c", &answer);
        while (answer!="merci") {
            printf("Tant qu'il y a pas de 'merci'...");
            scanf("%c", &answer);
        }
        printf("On vous remerci pourvotre sincérité :)");


    }

    int finishMenue() {

    }


*/