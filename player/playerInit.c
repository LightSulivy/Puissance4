#include <stdio.h>//
#include <stdlib.h>
#include <string.h>
// Created by "Yohan" on 26/09/2024.
//

typedef struct {
    char *color;
    char token;
    int turn;
} Player ;

Player *createPlayer(const char *color, const char token, const int turn) {
    Player *player = malloc(sizeof(Player));
    player->color = malloc(strlen(color) + 1);
    strcpy(player->color, color);
    player->color[strlen(color)] = '\0';
    player->turn = turn;
    player->token = token;

    return player;
}

#include "playerInit.h"
