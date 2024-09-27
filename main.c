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
    Game* game = initGame( playerCount, plateau, winCount);
    Player **player = game->player;
    display (height,width, plateau);
    victoire (plateau,i, j, **player, width, height);

    return 0;
}
