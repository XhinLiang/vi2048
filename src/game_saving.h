#ifndef VI_2048_GAME_SAVING_H
#define VI_2048_GAME_SAVING_H

#include "game.h"

#define N 4

void game_save(int SaveNum, Game *game);

int load_game(int LoadNum, Game *game);

#endif
