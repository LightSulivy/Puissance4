#include <stdio.h>

#include "tableau.h"
#include "victorycheck.h"
#include "victorycheck.h"
#include "tableau.h"
#include "menu.h"
#include "./game/gameInit.h"
#include "./player/playerInit.h"


int main(void) {

    //scanf menuInit
    int height = 6;
    int width = 7;
    int playerCount = 4;
    int winCount = 4;

    // ?
    int i = 0, j = 0;

    char** plateau = createTab (height, width);

    //menuInit();
    //Game* game = initGame( playerCount, plateau, winCount);
    //Player **player = game->player;
    display (height,width, plateau);

    int key=0;
    int victory = 0;
    char pion = 'X';
    while (!victory) {
        int column;
        if(key) {
            pion = 'X';
        }else {
            pion = 'O';
        }
        scanf(("%d", &column));
        printf("%d", column);
        int *xy = addToken(plateau,pion, height, column);
        printf("je fou ma merde");
        display(height, width, plateau);

        victory =victoire (plateau,xy[0], xy[1],pion, width, height);
        key= !key;
    }

    return 0;
}
