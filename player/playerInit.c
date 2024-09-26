#include <stdio.h>//
#include <stdlib.h>
#include <string.h>
// Created by "yohan" on 26/09/2024.
//

typedef struct {
    char *color;
    char token;
    int turn;
} Player ;

Player *createPlayer(const char *color, char token, int turn) {
    Player *players = malloc(sizeof(Player));
    players->color = malloc(strlen(color) + 1);
    strcpy(players->color, color);
    players->color[strlen(color)] = '\0';
    players->turn = turn;
    players->token = token;
}

#include "playerInit.h"
