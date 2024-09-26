//
// Created by yohan on 26/09/2024.
//
#include <stdio.h>
#include "gameInit.h"
#include <stdlib.h>
#include "../player/playerInit.h"

typedef struct {
    Player **player;
    int playerCount;
    char **plateau;
} Game;

Game *initGame(const int playerCount, int row, int col, int winCount) {
    Game *game = malloc(sizeof(Game));
    game->playerCount = playerCount;

    return game;
}
