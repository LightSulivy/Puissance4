cmake_minimum_required(VERSION 3.29)
project(Puissance4 C)

set(CMAKE_C_STANDARD 11)

add_executable(Puissance4 main.c
        game/gameInit.c
        player/playerInit.c
)
