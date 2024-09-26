//
// Created by yohan on 26/09/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "../player/playerInit.h"
#include "gameInit.h"


Game *initGame(const int playerCount, int row, int col, int winCount) {
    Game *game = malloc(sizeof(Game));
    game->playerCount = playerCount;

    return game;
}
