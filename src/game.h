#ifndef VI_2048_GAME_H
#define VI_2048_GAME_H

#define N 4

typedef struct {
    int numbers[N][N];
    int score;
} Game;

Game *game_init();

void game_start(Game *game);

void game_reset(Game *game);

#endif
