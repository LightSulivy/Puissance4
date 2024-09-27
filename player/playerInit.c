#include <stdlib.h>
#include "playerInit.h"

Player **createPlayer(const char token, const int turn, int playerCount) {
    Player **players = malloc(playerCount * sizeof(Player *));
    for (int i = 0; i < playerCount; i++) {
        players[i] = malloc(sizeof(Player));
        players[i]->token = token;
        players[i]->turn = turn;
        free(players[i]);
    }

    return players;
} 