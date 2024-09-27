//
// Created by yohan on 26/09/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "../player/playerInit.h"
#include "gameInit.h"


/*Game *initGame(const int playerCount, char** plateau , int winCount) {
    Game *game = malloc(sizeof(Game));
    game->playerCount = playerCount;
    game->player = malloc(sizeof(playerCount));
    for(int i = 0; i < game->playerCount; i++) {

        if(i == 0) {
            game->player[i] = createPlayer('O', 1);
        }
        else if(i == 1) {
            game->player[i] = createPlayer('X', 1);
        }
        else if(i == 2) {
            game->player[i] = createPlayer('#', 1);
        }
        else if(i == 3) {
            game->player[i] = createPlayer('&', 1);
        }
    }
    game->plateau = malloc(sizeof(plateau));
    return game;
}*/