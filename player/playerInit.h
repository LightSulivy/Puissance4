//
// Created by yohan on 26/09/2024.
//

#ifndef PLAYERINIT_H
#define PLAYERINIT_H

typedef struct {
    char *color;
    char token;
    int turn;
} Player ;

Player *createPlayer(const char *color, const char token, const int turn);

#endif //PLAYERINIT_H
